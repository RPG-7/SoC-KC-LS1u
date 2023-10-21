module CPU_LS1u
#(
    parameter //CPU_TYPE = "WITHDEBUG", //CLASSIC / PLUS / WITHDEBUG
    CACHE_TYP = 2'b00,
    CACHE_DEPTH=2048,
    CACHE_WIDTH=16,
    ENTRY_NUM=32,
    MMU_ENABLE=1'b1,
    JTAG_ENABLE=1'b1,
    cDMA_ENABLE=1'b0
)
(
    input sys_por,
    input clk,rst,
    output jrst_out,
    input jtck,jtms,jtdi,
    output jtdo,

    input [7:0]INT_ARR,
    //Shrinked AHB
    output wire [BUS_ADDRWID-1:0]haddr,
    output wire hwrite,
    output wire hburst,
    output wire htrans,
    output wire [7:0]hwdata,
    input wire hready,
    input wire hresp,
    //input wire hreset_n,
    input wire [7:0]hrdata
);
wire [23:0]iaddr;
wire [15:0]instr;
wire [23:0]daddr;
wire dwrite;
wire dread;
wire [7:0]ddata_i;
wire [7:0]ddata_o;
wire READY,DREADY;
wire INSTR_HOLD;
wire cache_flush;//当存在MMU，切换页表须冲刷cache
localparam BUS_ADDRWID =(MMU_ENABLE)?32:24;
wire [BUS_ADDRWID-1:0]pa;
//eXternal Control Register 
wire [7:0]XCRi;
wire [7:0]XCRo;
wire[7:0]XCRa;
wire XCRwe;
wire XCRcs;
//Interrupt
wire INT_Req;
wire [23:0]IVEC_addr;//中断向量表基址
wire IN_ISP;//在中断服务程序中
wire [7:0]XCP_ARR;//eXCePtion array
//debug wires
wire step_mode;//Also act as halt
wire inject_req;
wire [1:0]dbg_cmd;
wire [15:0]inject_instr;
wire  [7:0]dbus_out;
wire  jflag;
wire  cflag;
wire  tflag;
wire  prio;
wire  inject_ack;

//MMU inputs
wire [15:0]ipae_h16;//From MMU control regs
wire [15:0]dpae_h16;
wire [7:0]ipte_h8;
wire [7:0]dpte_h8;
wire [10:0]hugepage_ptr; //for OS working in pure physical address mode 
wire mmu_enable;
wire force_svpriv;

KC_LS1u_dbg CORE
(
    .clk(clk),
    .rst(rst),
    .INT(INT_Req),
    .WAIT(!READY),
    .IVEC_addr(IVEC_addr),//中断向量地址
    .IN_ISP(IN_ISP),//注意:这里的取值是字编址的！
    .XCRi(XCRi),
    .XCRo(XCRo),
    .XCRa(XCRa),
    .XCRwe(XCRwe),
    .XCRcs(XCRcs),
    .step_mode(step_mode),
    .inject_req(inject_req),
    .dbg_cmd(dbg_cmd),
    .inject_instr(inject_instr),
    .dbus_out(dbus_out),
    .jflag(jflag),
    .cflag(cflag),
    .tflag(tflag),
    .prio(prio),
    .inject_ack(inject_ack),
    .iaddr(iaddr),
    .instr(instr),
    .daddr(daddr),
    .dwrite(dwrite),
    .dread(dread),
    .WAIT_DATA(!DREADY),
    .INSTR_HOLD(INSTR_HOLD),
    .ddata_i(ddata_i),
    .ddata_o(ddata_o)
);

xcr_top #(.MMU_ENABLE(MMU_ENABLE),
    .cDMA_ENABLE(cDMA_ENABLE))
eXternalCtrlRegs(
    .clk(clk),
    .rst(rst),
    .cr_din(XCRo),
    .cr_dout(XCRi),
    .cr_adr(XCRa),
    .cr_we(XCRwe),
	.cr_cs(XCRcs),
    
    .INT_ARR(INT_ARR),
    .XCP_ARR(XCP_ARR),
    .IVEC_ADDR(IVEC_addr),
    .INT(INT_Req),

    .ipae_h16(ipae_h16),//From MMU control regs
	.dpae_h16(dpae_h16),
	.ipte_h8(ipte_h8),
	.dpte_h8(dpte_h8),
	.hugepage_ptr(hugepage_ptr), //for OS working in pure physical address mode 
	.mmu_enable(mmu_enable),
    .supervisor_mode(force_svpriv)
);

jtagbridge jtag_bridge
(
    //JTAG ports
    .sys_por(sys_por),
    .jtms(jtms),
    .jtck(jtck),
    .jtdi(jtdi),
    .jtdo(jtdo),

    .sys_clk(clk),
    .reset_out(jrst_out),
    .step_mode(step_mode), //Also act as halt
    .inject_req(inject_req),
    .dbg_cmd(dbg_cmd),
    .inject_instr(inject_instr),
    //
    .dbus_in(dbus_out),
    .jflag(jflag),
    .cflag(cflag),
    .tflag(tflag),
    .prio(prio),
    .inject_ack(inject_ack)//Also act as cmd ready

);

wire [23:0]pa_l1;			//L1 PA
wire load_acc_fault;
wire store_acc_fault;
wire ins_acc_fault;
wire write_through_req;	//请求写穿
wire read_req;			//请求读一次
wire read_line_req;		//请求读一行
wire [7:0]wt_data;
wire [7:0]line_data;
wire [7:0]addr_count;
wire line_write;			//cache写
wire cache_entry_refill;	//更新缓存entry
wire trans_rdy;			//传输完成
wire bus_error;			//访问失败
//Since KC-LS1U is not and never a data access intensive core, 
//seprate I$ D$ is NEVER in consideration
generate
case (CACHE_TYP)
    2'b00 : begin : L1_I_Only
            l1_ionly 
            #(.CACHE_DEPTH(CACHE_DEPTH),
              .ENTRY_NUM(ENTRY_NUM))
            L1CX(
            .clk(clk),//Since Code always executes from RAMs,
            .rst(rst),//it's user's responsibility to guarantee PC won't read
            .read(dread),//uncacheable peripherals
            .write(dwrite),
            .execute(1'b1),
            .L1_clear(cache_flush),
            .cwait(INSTR_HOLD),
            .addr_pa_d(daddr),
            .addr_pa_i(iaddr[22:0]),
            .host_wdata(ddata_o),
            .host_rdata(ddata_i),
            .instr_read(instr),
            .load_acc_fault(load_acc_fault),
            .store_acc_fault(store_acc_fault),
            .ins_acc_fault(ins_acc_fault),
            .cache_data_ready(READY),
            .uncache_data_ready(DREADY),
            //.access_ready(READY),
            //cache控制器逻辑 
            .write_through_req(write_through_req),	//请求写穿
            .read_req(read_req),			//请求读一次
            .read_line_req(read_line_req),		//请求读一行
            .bus_pa(pa_l1),			//
            .bus_wdata(wt_data),
            .bus_rdata(line_data),
            .addr_count(addr_count),
            .line_write(line_write),			//cache写
            .bus_trans_finish(trans_rdy),			//传输完成
            .bus_error(bus_error)			//访问失败
            );
            end
    2'b01:  begin : Unified_L1
            l1_unified L1CX
            (//64K peripheral space@0xC0xxxx
            .cacheable((iaddr[23:16]!=8'hC0)&(daddr[23:16]!=8'hC0)),
            .clk(clk),
            .rst(rst),
            .read(dread),
            .write(dwrite),
            .execute(1'b1),
            .L1_clear(cache_flush),
            .addr_pa_d(daddr),
            .addr_pa_i(iaddr[22:0]),
            .data_write(ddata_o),
            .data_read(ddata_i),
            .instr_read(instr),
            .load_acc_fault(load_acc_fault),
            .store_acc_fault(store_acc_fault),
            .ins_acc_fault(ins_acc_fault),
            .cache_data_ready(READY),
            .uncache_data_ready(DREADY),
            //cache控制器逻辑
            .write_through_req(write_through_req),	//请求写穿
            .read_req(read_req),			//请求读一次
            .read_line_req(read_line_req),		//请求读一行
            .pa(pa_l1),			//
            .wt_data(wt_data),
            .line_data(line_data),
            .addr_count(addr_count),
            .line_write(line_write),			//cache写
            .trans_rdy(trans_rdy),			//传输完成
            .bus_error(bus_error)			//访问失败
            );
            end
    default:begin : NO_CACHE
                always@(*)//If you managed to finish this function
                begin
                    $display("Too lazy to do, plz DIY");
                    //THIS_LINE_IS_TO_GENERATE_ERROR_IN_ORDER_TO_STOP_WORKFLOW<=1'b1;
                end//Delete or comment this block 
            end
    endcase
endgenerate
assign XCP_ARR[0]=ins_acc_fault;
assign XCP_ARR[1]=load_acc_fault;
assign XCP_ARR[2]=store_acc_fault;
generate 
if(MMU_ENABLE == 1'b1) 
    begin : PAE32_MMU //Only L1 will trigger WT/RT
        pae32_mmu MMU
        (
            .clk(clk),
            .ipae_h16(ipae_h16),//From MMU control regs
            .dpae_h16(dpae_h16),
            .ipte_h8(ipte_h8),
            .dpte_h8(dpte_h8),
            .hugepage_ptr(hugepage_ptr), //for OS working in pure physical address mode 
            .mmu_enable(mmu_enable),
            .supervisor_mode(IN_ISP|force_svpriv),//IN_ISP
            .req_type(write_through_req|read_req),//0=INSTR 1=DATA
            .vai(pa_l1),//Word incr
            .pao(pa),
            .xcp_iptemiss(XCP_ARR[3]),
            .xcp_dptemiss(XCP_ARR[4]),
            .cache_flush(cache_flush)
        );
        assign XCP_ARR[7:5]=0;
    end
else 
    begin : NO_MMU
        assign pa=pa_l1;
        assign cache_flush=1'b0;//不额外冲刷cache
        assign XCP_ARR[7:3]=0;
    end
endgenerate

bus_unit #(
    .BUS_ADDR(BUS_ADDRWID),
    .MAX_BURST(256))
AHB_Interface
(
    .clk(clk),
    .rst(rst),

    .write_through_req(write_through_req),	//请求写穿
    .read_req(read_req),			//请求读一次
    .read_line_req(read_line_req),		//请求读一行
    .pa(pa),			//
    .wt_data(wt_data),
    .line_data(line_data),
    .addr_count(addr_count),
    .line_write(line_write),			//cache写
    .trans_rdy(trans_rdy),			//传输完成
    .bus_error(bus_error),			//访问失败
    //AHB总线
    //ahb
    .haddr(haddr),
    .hwrite(hwrite),
    .hburst(hburst),
    .htrans(htrans),
    .hwdata(hwdata),
    .hready(hready),
    .hresp(hresp),
    .hreset_n(hreset_n),
    .hrdata(hrdata),
    .bus_ack(1'b1),	//总线允许使用
    .bus_req()		//总线请求使用

);

endmodule
