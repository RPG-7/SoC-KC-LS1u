/*************************************************
//SYSCTRL Module Mem map:
//0x00 CKSET: {LCLK_EN SYSRST LCKDIV[5:0]}
//0x01 SCALL: {SCALL_EN SCALL_CLR RSVD[5:0]}
//0x02 SCNUM: System call number    //READ ONLY
//0X03 CINFO: System call info      //READ ONLY
//0x04 FSBMOD:{SYNC_FSB ASYNC_WAITCNT[6:0]}
//0x05 MMUMOD:{PAE_ENABLE,SVMOD}
//0x06 HPADR0:Huge Page Address [31:24]
//0x07 HPADR1:Huge Page Address [23:21]
//Huge Page is for Supervisor(Only in case MMU enabled and in supervisor access)
*************************************************/
`include "VENDOR.vh"

module sys_ctrl
(
    input clki,rsti,//Low-speed CLK& RST input
    input wdt_reset,
    output clk,lclk,//SYSTEM GLOBAL SIGNAL
    output reg rst,
    //-----------Syscall wire-----------
    output SYSCALL_clr,
    input [7:0]SYSCALL_num,
    input [7:0]SYSCALL_info,
    //-----------Bus Control-----------
    output SYNC_MODE,
    output [6:0]ASYNC_WAITCYCLE,
    //-----------MMU SIGNALS-----------
    output reg[9:0]HPAGE_BASEADDR,
    output PAE_ENABLE,
    //1=Always at Supervisor mode, use hugepage,no TLB 
    //0=ISP in supervisor mode,RET to user level TLB
    output ALWAYS_SVM, 
    //-----------Wishbone BUS-----------
    input wire [2:0]WB_ADRi,
    output reg [7:0]WB_DATo,
    input wire [7:0]WB_DATi,
    input wire WB_WEi,
    input wire WB_CYCi,
    input wire WB_STBi,
    output wire WB_ACKo
);
reg [6:0]CKSET;
reg [7:0]FSBMOD;
reg [1:0]MMUMOD;
reg scall_en;
wire pll_lock;
wire lclk_div;
wire sys_rst;
wire wb_write;
assign lclk=(!CKSET[6])?1'b0:
                        (CKSET[5:0]==0)?clki:lclk_div;
assign wb_write=(WB_CYCi & WB_STBi & WB_WEi);
//SYSTEM Reset management
assign sys_rst=rsti|(wb_write&(WB_ADRi==3'h0)&WB_DATi[6])|wdt_reset;
assign SYSCALL_clr=rst|(wb_write&(WB_ADRi==3'h1)&WB_DATi[6]);
always@(posedge clki or posedge sys_rst)
begin
    if(sys_rst)
        rst<=1'b1;
    else if(!pll_lock)rst<=1'b1;
	 else rst<=1'b0;
end
//---------------wishbone signals------------
//---------------REG WRITE------------------
always@(posedge clk)begin
    if(rst)begin
        CKSET<=8'h00;
        scall_en <= 0;
        FSBMOD<=8'h7f;
        MMUMOD<=2'h0;
    end
    else if(WB_CYCi & WB_STBi & WB_WEi)
    begin
        case(WB_ADRi[2:0])
        4'h0    :   CKSET<={WB_DATi[7],WB_DATi[5:0]} ;
        4'h1    :   scall_en<=WB_DATi[7];   
        4'h4    :   FSBMOD<=WB_DATi;
        4'h5    :   MMUMOD<=WB_DATi[7:6];
        4'h6    :   HPAGE_BASEADDR[9:2]<=WB_DATi;
        4'h7    :   HPAGE_BASEADDR[1:0]<=WB_DATi;
        endcase
    end
    else 
    begin
        CKSET<=CKSET ;
        scall_en<=scall_en;
        FSBMOD<=FSBMOD;
        MMUMOD<=MMUMOD;
        HPAGE_BASEADDR<=HPAGE_BASEADDR;
    end
end

//-----------DATA READ-----------
always@(*)begin
    case(WB_ADRi[2:0])
        4'h0    :   WB_DATo <= {CKSET[6],1'b0,CKSET[5:0]};
        4'h1    :   WB_DATo <= {scall_en,7'hxx};
        4'h2    :   WB_DATo <= SYSCALL_num;
        4'h3    :   WB_DATo <= SYSCALL_info;
        4'h4    :   WB_DATo <= FSBMOD;
        4'h5    :   WB_DATo <= {MMUMOD,6'hxx};
        4'h6    :   WB_DATo <= HPAGE_BASEADDR[9:2];
        4'h7    :   WB_DATo <= {6'hxx,HPAGE_BASEADDR[1:0]};
        default :   WB_DATo <= 8'hxx;
    endcase
end
//----------ACK----------------
assign WB_ACKo = 1'b1;
//Clock management start
FDIV LCLK_Divider
(
    .CLK(clki),
    .RST_N(!rst&CKSET[6]),
    .CDIV(CKSET[5:0]),
    .COUT(lclk_div)
);
//PLL Generate
`ifdef VENDOR_GOWIN
assign gw_gnd = 1'b0;
rPLL rpll_inst (
    .CLKOUT(clk),
    .LOCK(pll_lock),
    .CLKOUTP(clkoutp_o),
    .CLKOUTD(clkoutd_o),
    .CLKOUTD3(clkoutd3_o),
    .RESET(rsti),
    .RESET_P(gw_gnd),
    .CLKIN(clki),
    .CLKFB(gw_gnd),
    .FBDSEL({gw_gnd,gw_gnd,gw_gnd,gw_gnd,gw_gnd,gw_gnd}),
    .IDSEL({gw_gnd,gw_gnd,gw_gnd,gw_gnd,gw_gnd,gw_gnd}),
    .ODSEL({gw_gnd,gw_gnd,gw_gnd,gw_gnd,gw_gnd,gw_gnd}),
    .PSDA({gw_gnd,gw_gnd,gw_gnd,gw_gnd}),
    .DUTYDA({gw_gnd,gw_gnd,gw_gnd,gw_gnd}),
    .FDLY({gw_gnd,gw_gnd,gw_gnd,gw_gnd})
);
defparam rpll_inst.FCLKIN = "24";
defparam rpll_inst.DYN_IDIV_SEL = "false";
defparam rpll_inst.IDIV_SEL = 0;
defparam rpll_inst.DYN_FBDIV_SEL = "false";
defparam rpll_inst.FBDIV_SEL = 1;
defparam rpll_inst.DYN_ODIV_SEL = "false";
defparam rpll_inst.ODIV_SEL = 16;
defparam rpll_inst.PSDA_SEL = "0000";
defparam rpll_inst.DYN_DA_EN = "true";
defparam rpll_inst.DUTYDA_SEL = "1000";
defparam rpll_inst.CLKOUT_FT_DIR = 1'b1;
defparam rpll_inst.CLKOUTP_FT_DIR = 1'b1;
defparam rpll_inst.CLKOUT_DLY_STEP = 0;
defparam rpll_inst.CLKOUTP_DLY_STEP = 0;
defparam rpll_inst.CLKFB_SEL = "internal";
defparam rpll_inst.CLKOUT_BYPASS = "false";
defparam rpll_inst.CLKOUTP_BYPASS = "false";
defparam rpll_inst.CLKOUTD_BYPASS = "false";
defparam rpll_inst.DYN_SDIV_SEL = 2;
defparam rpll_inst.CLKOUTD_SRC = "CLKOUT";
defparam rpll_inst.CLKOUTD3_SRC = "CLKOUT";
defparam rpll_inst.DEVICE = "GW1N-1";
`elsif VENDOR_ANLOGIC
pll ANLOGIC_SYSPLL
		(.refclk(clki),
		.reset(rsti),
		.extlock(pll_lock),
		.clk0_out(clk));

`elsif VENDOR_ALTERA
syspll ALTERA_SYSPLL(
	.areset(!rsti),
	.inclk0(clki),
	.c0(clk),
	.locked(pll_lock)
);
`endif 
//Output ports
assign SYNC_MODE=FSBMOD[7];
assign ASYNC_WAITCYCLE=FSBMOD[6:0];
assign PAE_ENABLE=MMUMOD[1];
assign ALWAYS_SVM=MMUMOD[0];

endmodule

module FDIV
(
    input CLK,
    input RST_N,
    input [5:0]CDIV,
    output COUT
);
wire COUTC;
reg COUT1,COUT2;
reg [5:0]m,n;
assign COUT=COUT1|COUTC;
assign COUTC=COUT2&CDIV[0];
always@(posedge CLK or negedge RST_N)
begin
    if(!RST_N)
    begin
        m<=0;
    end
    else if(m==(CDIV-1))
        m<=0;
    else m<=m+1;
end
always@(posedge CLK)
begin
    if(m==(CDIV>>1)-1)
        COUT1<=1;
    else if(m==(CDIV-2))
        COUT1<=0;
    else COUT1<=COUT1;
end
always@(negedge CLK or negedge RST_N)
begin
    if(!RST_N)
    begin
        n<=0;
    end
    else if(n==(CDIV-1))
        n<=0;
    else n<=n+1;
end
always@(negedge CLK)
begin
    if(n==(CDIV>>1)-1)COUT2<=1;
    else if(n==(CDIV-2))
        COUT2<=0;
    else COUT2<=COUT2;
end
endmodule