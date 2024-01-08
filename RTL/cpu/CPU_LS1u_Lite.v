module CPU_LS1u_Lite
#(
    parameter CPU_TYPE = "PLUS", //CLASSIC / PLUS / WITHDEBUG
    MMU_ENABLE=1'b0,
    BUS_AWIDTH=(MMU_ENABLE?32:24)
)
(
    input sys_por,
    input clk,rst,
    output jrst_out,
    input jtck,jtms,jtdi,
    output jtdo,

    output [BUS_AWIDTH-1:0]cpu_iaddr,
    input [15:0]instr,
    input WAIT_INSTR,
    output [BUS_AWIDTH-1:0]cpu_daddr,
    output dread,
    output dwrite,
    input WAIT_DATA,
    output INSTR_HOLD,
    input [7:0]ddata_i,
    output [7:0]ddata_o,
    input [7:0]INT_ARR
);
wire [23:0]iaddr;
wire [15:0]instr;
wire [23:0]daddr;
wire dwrite;
wire dread;
wire [7:0]ddata_i;
wire [7:0]ddata_o;
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
//MMU inputs
wire [15:0]ipae_h16;//From MMU control regs
wire [15:0]dpae_h16;
wire [7:0]ipte_h8;
wire [7:0]dpte_h8;
wire [10:0]hugepage_ptr; //for OS working in pure physical address mode 
wire mmu_enable;
wire force_svpriv;
generate case(CPU_TYPE)
    "WITHDEBUG":begin:GEN_DBG_CORE
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
        KC_LS1u_dbg CORE
        (
            .clk(clk),
            .rst(rst),
            .INT(INT_Req),
            .WAIT(WAIT_INSTR),
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
            .WAIT_DATA(WAIT_DATA),
            .INSTR_HOLD(),
            .ddata_i(ddata_i),
            .ddata_o(ddata_o)
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
    end
    "PLUS":begin:GEN_PLUS_CORE
        KC_LS1u_plus CORE
        (
            .clk(clk),
            .rst(rst),
            .INT(INT_Req),
            .WAIT(WAIT_INSTR),
            .IVEC_addr(IVEC_addr),//中断向量地址
            .IN_ISP(IN_ISP),//注意:这里的取值是字编址的！
            .XCRi(XCRi),
            .XCRo(XCRo),
            .XCRa(XCRa),
            .XCRwe(XCRwe),
            .XCRcs(XCRcs),
            .iaddr(iaddr),
            .instr(instr),
            .daddr(daddr),
            .dwrite(dwrite),
            .dread(dread),
            .WAIT_DATA(WAIT_DATA),
            .INSTR_HOLD(),
            .ddata_i(ddata_i),
            .ddata_o(ddata_o)
        );

        end
    default:begin:GEN_CLASSIC_CORE
        KC_LS1u CORE
        (
            .clk(clk),
            .rst(rst),
            .WAIT(!READY),
            .iaddr(iaddr),
            .instr(instr),
            .daddr(daddr),
            .dwrite(dwrite),
            .ddata_i(ddata_i),
            .ddata_o(ddata_o)
        );
        end
    endcase
endgenerate

generate if((CPU_TYPE == "WITHDEBUG") | (CPU_TYPE == "PLUS"))
begin:GEN_XCR

    xcr_top #(.MMU_ENABLE(MMU_ENABLE),
    .cDMA_ENABLE(1'b0))
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
end
endgenerate

generate 
    if(MMU_ENABLE == 1'b1 && ((CPU_TYPE == "WITHDEBUG") | (CPU_TYPE == "PLUS"))) 
    begin : PAE32_MMU //Only L1 will trigger WT/RT
        wire access_is_data;
        assign access_is_data = dread|dwrite;
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
            .req_type(access_is_data),//0=INSTR 1=DATA
            .vai({access_is_data?iaddr[22:15]:daddr[23:16],16'h0000}),//Word incr
            .pao(pa),
            .xcp_iptemiss(XCP_ARR[3]),
            .xcp_dptemiss(XCP_ARR[4]),
            .cache_flush(cache_flush)
        );
        assign cpu_iaddr = {ipae_h16,iaddr[14:0],1'b0};
        assign cpu_daddr = {dpae_h16,daddr[15:0]};
    end
    else 
    begin : NO_MMU
        assign XCP_ARR[4:3]=0;

        assign cpu_iaddr = {iaddr[22:0],1'b0};
        assign cpu_daddr = daddr[15:0];
    end
    endgenerate
    assign XCP_ARR[7:5]=0;



endmodule