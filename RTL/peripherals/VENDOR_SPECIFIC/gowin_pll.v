//Copyright (C)2014-2020 Gowin Semiconductor Corporation.
//All rights reserved.
//File Title: IP file
//GOWIN Version: V1.9.7Beta
//Part Number: GW1N-LV1QN48C6/I5
//Device: GW1N-1
//Created Time: Mon Feb 15 15:36:43 2021

module gowin_pll (clkout, clkoutp, clkoutd, reset, reset_p, clkin, fbdsel, idsel, odsel, psda, dutyda, fdly);

output clkout;
output clkoutp;
output clkoutd;
input reset;
input reset_p;
input clkin;
input [5:0] fbdsel;
input [5:0] idsel;
input [5:0] odsel;
input [3:0] psda;
input [3:0] dutyda;
input [3:0] fdly;

wire lock_o;
wire clkoutd3_o;
wire gw_gnd;

assign gw_gnd = 1'b0;

rPLL rpll_inst (
    .CLKOUT(clkout),
    .LOCK(lock_o),
    .CLKOUTP(clkoutp),
    .CLKOUTD(clkoutd),
    .CLKOUTD3(clkoutd3_o),
    .RESET(reset),
    .RESET_P(reset_p),
    .CLKIN(clkin),
    .CLKFB(gw_gnd),
    .FBDSEL(fbdsel),
    .IDSEL(idsel),
    .ODSEL(odsel),
    .PSDA(psda),
    .DUTYDA(dutyda),
    .FDLY(fdly)
);

defparam rpll_inst.FCLKIN = "24";
defparam rpll_inst.DYN_IDIV_SEL = "true";
defparam rpll_inst.IDIV_SEL = 2;
defparam rpll_inst.DYN_FBDIV_SEL = "true";
defparam rpll_inst.FBDIV_SEL = 11;
defparam rpll_inst.DYN_ODIV_SEL = "true";
defparam rpll_inst.ODIV_SEL = 8;
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
defparam rpll_inst.CLKOUTD_SRC = "CLKOUTP";
defparam rpll_inst.CLKOUTD3_SRC = "CLKOUT";
defparam rpll_inst.DEVICE = "GW1N-1";

endmodule //gowin_pll
