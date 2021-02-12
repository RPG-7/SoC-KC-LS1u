module CPU_LS1u
#(
    parameter CACHE_TYP = 2'b00,
    CACHE_DEPTH=2048,
    CACHE_WIDTH=16,
    ENTRY_NUM=16,
    MMU_ENABLE=1'b0
)
(
    input clk,rst,
    //Interrupt
	input INT,XCP,
    input [23:0]IVEC_addr,//中断向量表基址
    output IN_ISP,//在中断服务程序中
    output [7:0]XCP_ARR,//eXCePtion array
    //Shrinked AHB
    output wire [BUS_ADDRWID-1:0]haddr,
    output wire hwrite,
    output wire hburst,
    output wire htrans,
    output wire [7:0]hwdata,
    input wire hready,
    input wire hresp,
    input wire hreset_n,
    input wire [7:0]hrdata
);
wire [23:0]iaddr;
wire [15:0]instr;
wire [23:0]daddr;
wire dwrite;
wire dread;
wire [7:0]ddata_i;
wire [7:0]ddata_o;
wire READY,dop_finish;
wire cache_flush;//当存在MMU，切换页表须冲刷cache
localparam BUS_ADDRWID =(MMU_ENABLE)?32:24;
wire [BUS_ADDRWID-1:0]pa;
KC_LS1u_plus CORE
(
    .clk(clk),
    .rst(rst),
    .INT(INT),
    .WAIT(!READY),
    .IVEC_addr(IVEC_addr),//中断向量地址
    .IN_ISP(IN_ISP),//注意:这里的取值是字编址的！
    .iaddr(),//如果使用异步SRAM(ASRAM)，用这个
    .iaddr_next(iaddr),//但是基于FPGA中多见同步SRAM(SSRAM)，必须用PC_NEXT输出才保证取指正确
    .instr(instr),
    .daddr(daddr),
    .dwrite(dwrite),
    .dread(dread),
    .dop_finish(dop_finish),
    .ddata_i(ddata_i),
    .ddata_o(ddata_o)
);

wire load_acc_fault;
wire store_acc_fault;
wire ins_acc_fault;
wire write_through_req_l1;	//请求写穿
wire read_req_l1;			//请求读一次
wire read_line_req_l1;		//请求读一行
wire [23:0]pa_l1;			//
wire [7:0]wt_data_l1;
wire [7:0]line_data_l1;
wire [6:0]addr_count_l1;
wire line_write_l1;			//cache写
wire cache_entry_refill_l1;	//更新缓存entry
wire trans_rdy_l1;			//传输完成
wire bus_error_l1;			//访问失败
//Since KC-LS1U is not and never a data access intensive core, 
//seprate I$ D$ is NEVER in consideration
generate
case (CACHE_TYP)
    2'b00 : begin : L1_I_Only
            l1_ionly L1CX(
            .clk(clk),//Since Code always executes from RAMs,
            .rst(rst),//it's user's responsibility to guarantee PC won't read
            .read(dread),//uncacheable peripherals
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
            .uncache_data_ready(dop_finish),
            //.access_ready(READY),
            //cache控制器逻辑 
            .write_through_req(write_through_req_l1),	//请求写穿
            .read_req(read_req_l1),			//请求读一次
            .read_line_req(read_line_req_l1),		//请求读一行
            .pa(pa_l1),			//
            .wt_data(wt_data_l1),
            .line_data(line_data_l1),
            .addr_count(addr_count_l1),
            .line_write(line_write_l1),			//cache写
            .cache_entry_refill(cache_entry_refill_l1),	//更新缓存entry
            .trans_rdy(trans_rdy_l1),			//传输完成
            .bus_error(bus_error_l1)			//访问失败
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
            .uncache_data_ready(dop_finish),
            //cache控制器逻辑
            .write_through_req(write_through_req_l1),	//请求写穿
            .read_req(read_req_l1),			//请求读一次
            .read_line_req(read_line_req_l1),		//请求读一行
            .pa(pa_l1),			//
            .wt_data(wt_data_l1),
            .line_data(line_data_l1),
            .addr_count(addr_count_l1),
            .line_write(line_write_l1),			//cache写
            .cache_entry_refill(cache_entry_refill_l1),	//更新缓存entry
            .trans_rdy(trans_rdy_l1),			//传输完成
            .bus_error(bus_error_l1)			//访问失败
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
wire write_through_req;
wire read_req;
wire read_line_req;		//请求读一行
wire [7:0]wt_data;
wire [7:0]line_data;
wire [6:0]addr_count;
wire line_write;			//cache写
wire cache_entry_refill;	//更新缓存entry
wire trans_rdy;			//传输完成
wire bus_error;			//访问失败
assign XCP_ARR[0]=ins_acc_fault;
assign XCP_ARR[1]=load_acc_fault;
assign XCP_ARR[2]=store_acc_fault;
generate 
if(MMU_ENABLE == 1'b1) 
    begin : PAE32_MMU //Only L1 will trigger WT/RT
        	
        
        //always@(*) STILL_WORK_IN_PROGRESS<=1'b1; //When finished, remove this line
    end
else 
    begin : NO_MMU
        //wire [23:0]pa;	
        assign pa=pa_l1;
        assign write_through_req=write_through_req_l1;
        assign read_req=read_req_l1;
        assign read_line_req=read_line_req_l1;		//请求读一行
        assign wt_data=wt_data_l1;
        assign line_data_l1=line_data;
        assign addr_count_l1=addr_count;
        assign line_write_l1=line_write;			//cache写
        assign cache_entry_refill_l1=cache_entry_refill;	//更新缓存entry
        assign trans_rdy_l1=trans_rdy;			//传输完成
        assign bus_error_l1=bus_error;			//访问失败
        assign cache_flush=1'b0;//不额外冲刷cache
        assign XCP_ARR[7:3]=0;
    end
endgenerate
defparam AHB_INTERFACE.BUS_ADDR=BUS_ADDRWID;
bus_unit AHB_INTERFACE
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
.cache_entry_refill(cache_entry_refill),	//更新缓存entry
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
.bus_ack(1'b1)	//总线允许使用
//.bus_req(bus_req)		//总线请求使用

);

endmodule
