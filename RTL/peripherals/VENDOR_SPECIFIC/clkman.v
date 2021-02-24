`include "VENDOR.vh"
module clkman
#(parameter LCLK_ENABLE=1'b0,
        TURBO_ENABLE=1'b0,
        ASYNC_CBIF=1'b0,
        TUNABLE_LDIV_ENABLE=1'b0,
        FIXED_LDIV_DIV2RATIO=4
)
(
    input clki,rsti,
    output cclko,lclko,pclko,pll_lock,
    input ldiv_src,
    input LDIV_ENABLE,
    input [5:0]LDIV_RATIO,
    input xtnlclk_sel,
    input [1:0]cclk_sel

);
wire onchipclk,pllclkh,pllclkd,pllref;
wire ldivo;
generate 
if(LCLK_ENABLE)
begin
    if( TUNABLE_LDIV_ENABLE ) 
    begin : PGMABLE_LDIV
        FDIV LCLK_Divider
        (
            .CLK(clki),
            .RST_N(!rst&LDIV_ENABLE),
            .CDIV(LDIV_RATIO),
            .COUT(ldivo)
        );
    end
    else 
    begin :FIXED_LDIV
        genvar i;
        reg [FIXED_LDIV_DIV2RATIO:0]divarr;
        always@(*)divarr[0]=ldiv_src;
        generate 
            for(i=0;i<FIXED_LDIV_DIV2RATIO;i=i+1) 
            begin : LDIV_DIV2DFF
                always@(posedge divarr[i] or posedge rst)
                    if(rst)divarr[i+1]=0;
                    else divarr[i+1]=~divarr[i+1];
            end
            assign ldivo=divarr[FIXED_LDIV_DIV2RATIO];
        endgenerate
    end
end
else assign lclko=clko;
endgenerate

//PLL Generate
`ifdef VENDOR_GOWIN
    reg [3:0]cclk_dec;
    always @(*) 
    begin
        case(cclk_sel)
            2'b00:cclk_dec=4'b0001;
            2'b01:cclk_dec=4'b0010;
            2'b10:cclk_dec=4'b0100;
            2'b11:cclk_dec=4'b1000;
            default:cclk_dec=4'hx;
        endcase
    end
    gowin_pll CFGABLE_PLL
        (
            .clkout(pllclkh), //output clkout
            .clkoutp(clkoutp_o), //output clkoutp
            .clkoutd(pllclkd), //output clkoutd
            .reset(reset_i), //input reset
            .reset_p(reset_p_i), //input reset_p
            .clkin(clkin_i), //input clkin
            .fbdsel(fbdsel_i), //input [5:0] fbdsel
            .idsel(idsel_i), //input [5:0] idsel
            .odsel(odsel_i), //input [5:0] odsel
            .psda(psda_i), //input [3:0] psda
            .dutyda(dutyda_i), //input [3:0] dutyda
            .fdly(fdly_i) //input [3:0] fdly
        );
    OSCH OnChipOSC
        (
            .OSCOUT(onchipclk)
        );
    defparam OnChipOSC.FREQ_DIV=10;
    DCS CKI_SEL 
    (
        .CLK0(onchipclk), 
        .CLK1(clki),
        .CLK2(),
        .CLK3(),
        .CLKSEL({2'b00,xtnlclk_sel,!xtnlclk_sel}),
        .SELFORCE(1'b0),
        .CLKOUT(pllref)
    );
    defparam CKI_SEL.DCS_MODE=“RISING”;
    DCS CCLK_SEL 
    (
        .CLK0(pllref), //INPUT ALWAYS-ON CLK
        .CLK1(pllclkd),//SLOW PLL CLOCK
        .CLK2(pllclkh),//FAST PLL CLOCK
        .CLK3(1'b1),//CLKOFF for WFI
        .CLKSEL(cclk_sel),
        .SELFORCE(1'b0),
        .CLKOUT(clkout)
    );
    defparam CCLK_SEL.DCS_MODE=“RISING”;

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
    assign pll_lock=1'b1;
    assign clk=clki;
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
