/*************************************************
//SYSCTRL Module Mem map:
//0x00 CKSET: {SYSLEEP PLLEN REFCLKSEL MAINCLK[1:0]}
//0x01 SCALL: {SCALL_EN SCALL_CLR RSVD[5:0]}
//0x02 SCNUM: System call number    //READ ONLY
//0X03 CINFO: System call info      //READ ONLY
//0x04 FSBMOD:{SYNC_FSB ASYNC_WAITCNT[6:0]}
//0x05 MMUMOD:{PAE_ENABLE,SVMOD RSVD[5:0]}
//0x06 DMATRG:{DIR,BLKNUM}
//0x07 DMA
//0x08 HPADR0:Huge Page Address [31:24]
//0x09 HPADR1:Huge Page Address [23:21]
//0x0A IPTE  :
//0x0B IPAE0 :
//0x0C IPAE1 :
//0x0D DPTE  :
//0x0E DPAE0 :
//0x0F DPAE1 :
//Huge Page is for Supervisor(Only in case MMU enabled and in supervisor access)
*************************************************/
`include "VENDOR.vh"
module sys_ctrl
(
    input clki,rsti,//Low-speed CLK& RST input
    input reset_req,
    output clk,lclk,//SYSTEM GLOBAL SIGNAL
    output reg rst,
    //-----------Syscall wire-----------
    output SYSCALL_clr,
    input MNMX,
    input [7:0]SYSCALL_num,
    input [7:0]SYSCALL_info,
    //-----------Bus Control-----------
    output SYNC_MODE,
    output [6:0]ASYNC_WAITCYCLE,
    //-----------MMU SIGNALS-----------
    output reg[10:0]HPAGE_BASEADDR,
    output PAE_ENABLE,
    //1=Always at Supervisor mode, use hugepage,no TLB 
    //0=ISP in supervisor mode,RET to user level TLB
    output ALWAYS_SVM, 
    output [15:0]ipae_h16,//From MMU control regs
    output [15:0]dpae_h16,
    output [7:0]ipte_h8,
    output [7:0]dpte_h8,
    //-----------Wishbone BUS-----------
    input wire [3:0]WB_ADRi,
    output reg [7:0]WB_DATo,
    input wire [7:0]WB_DATi,
    input wire WB_WEi,
    input wire WB_CYCi,
    input wire WB_STBi,
    output wire WB_ACKo
);
//reg [6:0]CKSET;
reg [7:0]FSBMOD;
reg [1:0]MMUMOD;
reg [7:0]ipae0,ipae1,ipte;
reg [7:0]dpae0,dpae1,dpte;
assign ipae_h16={ipae1,ipae0};
assign dpae_h16={dpae1,dpae0};
assign ipte_h8=ipte;
assign dpte_h8=dpte;
reg scall_en;
wire pll_lock;
wire lclk_div;
wire sys_rst;
wire wb_write;
assign wb_write=(WB_CYCi & WB_STBi & WB_WEi);
//SYSTEM Reset management
assign sys_rst=rsti|reset_req;
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
always@(posedge clk or posedge rst)begin
    if(rst)begin
        //CKSET<=8'h00;
        scall_en <= 0;
        FSBMOD<={MNMX,7'h7f};
        MMUMOD<=2'h0;
    end
    else if(WB_CYCi & WB_STBi & WB_WEi)
    begin
        case(WB_ADRi[3:0])
        //4'h0    :   CKSET<={WB_DATi[7],WB_DATi[5:0]} ;
        4'h1    :   scall_en<=WB_DATi[7];   
        4'h4    :   FSBMOD<=WB_DATi;
        4'h5    :   MMUMOD<=WB_DATi[7:6];
        4'h8    :   HPAGE_BASEADDR[10:8]<=WB_DATi[2:0];
        4'h9    :   HPAGE_BASEADDR[7:0]<=WB_DATi;
        4'ha    :   ipte <=WB_DATi;
        4'hb    :   ipae0<=WB_DATi;   
        4'hc    :   ipae1<=WB_DATi;
        4'hd    :   dpte <=WB_DATi;
        4'he    :   dpae0<=WB_DATi;
        4'hf    :   dpae1<=WB_DATi;
        endcase
    end
    else 
    begin
        //CKSET<=CKSET ;
        scall_en<=scall_en;
        FSBMOD<=FSBMOD;
        MMUMOD<=MMUMOD;
        HPAGE_BASEADDR<=HPAGE_BASEADDR;
        ipte <=ipte;
        ipae0<=ipae0;   
        ipae1<=ipae1;
        dpte <=dpte;
        dpae0<=dpae0;
        dpae1<=dpae1;
    end
end

//-----------DATA READ-----------
always@(*)begin
    case(WB_ADRi[3:0])
        //4'h0    :   WB_DATo <= {CKSET[6],1'b0,CKSET[5:0]};
        4'h1    :   WB_DATo <= {scall_en,7'hxx};
        4'h2    :   WB_DATo <= SYSCALL_num;
        4'h3    :   WB_DATo <= SYSCALL_info;
        4'h4    :   WB_DATo <= FSBMOD;
        4'h5    :   WB_DATo <= {MMUMOD,6'hxx};
        4'h8    :   WB_DATo <= {6'hxx,HPAGE_BASEADDR[10:8]};
        4'h9    :   WB_DATo <= HPAGE_BASEADDR[7:0];
        4'ha    :   WB_DATo <= ipte;
        4'hb    :   WB_DATo <= ipae0;
        4'hc    :   WB_DATo <= ipae1;
        4'hd    :   WB_DATo <= dpte;
        4'he    :   WB_DATo <= dpae0;
        4'hf    :   WB_DATo <= dpae1;
        default :   WB_DATo <= 8'hxx;
    endcase
end
//----------ACK----------------
assign WB_ACKo = 1'b1;
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
`elsif VENDOR_ASIC
asic_pll ASIC_PLL
(
    .clki(clki),
    .rsti(rsti),
    .forediv(),
    .loopdiv(),
    .postdiv(),
    .fout(clk),
    .lock(pll_lock)
);
`elsif VENDOR_SIMU
    reg delay;
    initial 
    begin
        delay=0;
        #100 delay=1;
    end
    assign pll_lock=delay;
    assign clk=clki;
`endif
 
//Output ports
assign SYNC_MODE=FSBMOD[7];
assign ASYNC_WAITCYCLE=FSBMOD[6:0];
assign PAE_ENABLE=MMUMOD[1];
assign ALWAYS_SVM=MMUMOD[0];

assign lclk=clk;

endmodule