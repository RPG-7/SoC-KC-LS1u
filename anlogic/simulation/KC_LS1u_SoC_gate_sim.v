// Verilog netlist created by TD v5.0.25341
// Sun Jul 18 23:08:01 2021

`timescale 1ns / 1ps
module regfile_test  // RegFile.v(1)
  (
  clk,
  rst,
  j
  );

  input clk;  // RegFile.v(1)
  input rst;  // RegFile.v(1)
  output j;  // RegFile.v(1)

  wire [4:0] cnt;  // RegFile.v(3)
  wire [64:0] lfsr_65;  // RegFile.v(2)
  wire [4:0] lfsra;  // RegFile.v(3)
  wire [4:0] lfsrb;  // RegFile.v(3)
  wire [4:0] n3;
  wire clk_pad;  // RegFile.v(1)
  wire j_pad;  // RegFile.v(1)
  wire n0;
  wire n1;
  wire n2;
  wire rst_neg;
  wire rst_pad;  // RegFile.v(1)

  AL_PHY_PAD #(
    //.PCICLAMP("OFF"),
    //.PULLMODE("PULLUP"),
    .GSR("DISABLE"),
    .IOTYPE("LVCMOS25"),
    .MODE("IN"),
    .TSMUX("1"))
    _al_u0 (
    .ipad(clk),
    .di(clk_pad));  // RegFile.v(1)
  AL_PHY_PAD #(
    //.PCICLAMP("OFF"),
    //.PULLMODE("NONE"),
    //.SLEWRATE("SLOW"),
    .DRIVE("8"),
    .GSR("DISABLE"),
    .IOTYPE("LVCMOS25"),
    .MODE("OUT"),
    .TSMUX("0"))
    _al_u1 (
    .otrue(j_pad),
    .opad(j));  // RegFile.v(1)
  AL_MAP_LUT1 #(
    .EQN("(~A)"),
    .INIT(2'h1))
    _al_u10 (
    .a(rst_pad),
    .o(rst_neg));
  AL_MAP_LUT1 #(
    .EQN("(~A)"),
    .INIT(2'h1))
    _al_u11 (
    .a(cnt[0]),
    .o(n3[0]));
  AL_PHY_PAD #(
    //.PCICLAMP("OFF"),
    //.PULLMODE("PULLUP"),
    .GSR("DISABLE"),
    .IOTYPE("LVCMOS25"),
    .MODE("IN"),
    .TSMUX("1"))
    _al_u2 (
    .ipad(rst),
    .di(rst_pad));  // RegFile.v(1)
  AL_MAP_LUT2 #(
    .EQN("(B@A)"),
    .INIT(4'h6))
    _al_u3 (
    .a(lfsra[0]),
    .b(lfsra[1]),
    .o(n1));
  AL_MAP_LUT2 #(
    .EQN("(B@A)"),
    .INIT(4'h6))
    _al_u4 (
    .a(lfsrb[2]),
    .b(lfsrb[4]),
    .o(n2));
  AL_MAP_LUT2 #(
    .EQN("(B@A)"),
    .INIT(4'h6))
    _al_u5 (
    .a(cnt[0]),
    .b(cnt[1]),
    .o(n3[1]));
  AL_MAP_LUT2 #(
    .EQN("(B@A)"),
    .INIT(4'h6))
    _al_u6 (
    .a(lfsr_65[0]),
    .b(lfsr_65[15]),
    .o(n0));
  AL_MAP_LUT3 #(
    .EQN("(C@(B*A))"),
    .INIT(8'h78))
    _al_u7 (
    .a(cnt[0]),
    .b(cnt[1]),
    .c(cnt[2]),
    .o(n3[2]));
  AL_MAP_LUT4 #(
    .EQN("(D@(C*B*A))"),
    .INIT(16'h7f80))
    _al_u8 (
    .a(cnt[0]),
    .b(cnt[1]),
    .c(cnt[2]),
    .d(cnt[3]),
    .o(n3[3]));
  AL_MAP_LUT5 #(
    .EQN("(E@(D*C*B*A))"),
    .INIT(32'h7fff8000))
    _al_u9 (
    .a(cnt[0]),
    .b(cnt[1]),
    .c(cnt[2]),
    .d(cnt[3]),
    .e(cnt[4]),
    .o(n3[4]));
  AL_PHY_CONFIG #(
    .USR_GSRN_EN("ENABLE"))
    config_inst (
    .usr_gsrn(rst_neg));
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("SET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b0 (
    .clk(clk_pad),
    .d(n1),
    .q(lfsra[0]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b1 (
    .clk(clk_pad),
    .d(lfsra[0]),
    .q(lfsra[1]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b2 (
    .clk(clk_pad),
    .d(lfsra[1]),
    .q(lfsra[2]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b3 (
    .clk(clk_pad),
    .d(lfsra[2]),
    .q(lfsra[3]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b4 (
    .clk(clk_pad),
    .d(lfsra[3]),
    .q(lfsra[4]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("SET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg1_b0 (
    .clk(clk_pad),
    .d(n2),
    .q(lfsrb[0]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg1_b1 (
    .clk(clk_pad),
    .d(lfsrb[0]),
    .q(lfsrb[1]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg1_b2 (
    .clk(clk_pad),
    .d(lfsrb[1]),
    .q(lfsrb[2]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg1_b3 (
    .clk(clk_pad),
    .d(lfsrb[2]),
    .q(lfsrb[3]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg1_b4 (
    .clk(clk_pad),
    .d(lfsrb[3]),
    .q(lfsrb[4]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg2_b0 (
    .clk(clk_pad),
    .d(n3[0]),
    .q(cnt[0]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg2_b1 (
    .clk(clk_pad),
    .d(n3[1]),
    .q(cnt[1]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg2_b2 (
    .clk(clk_pad),
    .d(n3[2]),
    .q(cnt[2]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg2_b3 (
    .clk(clk_pad),
    .d(n3[3]),
    .q(cnt[3]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg2_b4 (
    .clk(clk_pad),
    .d(n3[4]),
    .q(cnt[4]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("SET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b0 (
    .clk(clk_pad),
    .d(n0),
    .q(lfsr_65[0]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b1 (
    .clk(clk_pad),
    .d(lfsr_65[0]),
    .q(lfsr_65[1]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b10 (
    .clk(clk_pad),
    .d(lfsr_65[9]),
    .q(lfsr_65[10]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b11 (
    .clk(clk_pad),
    .d(lfsr_65[10]),
    .q(lfsr_65[11]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b12 (
    .clk(clk_pad),
    .d(lfsr_65[11]),
    .q(lfsr_65[12]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b13 (
    .clk(clk_pad),
    .d(lfsr_65[12]),
    .q(lfsr_65[13]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b14 (
    .clk(clk_pad),
    .d(lfsr_65[13]),
    .q(lfsr_65[14]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b15 (
    .clk(clk_pad),
    .d(lfsr_65[14]),
    .q(lfsr_65[15]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b16 (
    .clk(clk_pad),
    .d(lfsr_65[15]),
    .q(lfsr_65[16]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b17 (
    .clk(clk_pad),
    .d(lfsr_65[16]),
    .q(lfsr_65[17]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b18 (
    .clk(clk_pad),
    .d(lfsr_65[17]),
    .q(lfsr_65[18]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b19 (
    .clk(clk_pad),
    .d(lfsr_65[18]),
    .q(lfsr_65[19]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b2 (
    .clk(clk_pad),
    .d(lfsr_65[1]),
    .q(lfsr_65[2]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b20 (
    .clk(clk_pad),
    .d(lfsr_65[19]),
    .q(lfsr_65[20]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b21 (
    .clk(clk_pad),
    .d(lfsr_65[20]),
    .q(lfsr_65[21]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b22 (
    .clk(clk_pad),
    .d(lfsr_65[21]),
    .q(lfsr_65[22]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b23 (
    .clk(clk_pad),
    .d(lfsr_65[22]),
    .q(lfsr_65[23]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b24 (
    .clk(clk_pad),
    .d(lfsr_65[23]),
    .q(lfsr_65[24]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b25 (
    .clk(clk_pad),
    .d(lfsr_65[24]),
    .q(lfsr_65[25]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b26 (
    .clk(clk_pad),
    .d(lfsr_65[25]),
    .q(lfsr_65[26]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b27 (
    .clk(clk_pad),
    .d(lfsr_65[26]),
    .q(lfsr_65[27]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b28 (
    .clk(clk_pad),
    .d(lfsr_65[27]),
    .q(lfsr_65[28]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b29 (
    .clk(clk_pad),
    .d(lfsr_65[28]),
    .q(lfsr_65[29]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b3 (
    .clk(clk_pad),
    .d(lfsr_65[2]),
    .q(lfsr_65[3]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b30 (
    .clk(clk_pad),
    .d(lfsr_65[29]),
    .q(lfsr_65[30]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b31 (
    .clk(clk_pad),
    .d(lfsr_65[30]),
    .q(lfsr_65[31]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b32 (
    .clk(clk_pad),
    .d(lfsr_65[31]),
    .q(lfsr_65[32]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b33 (
    .clk(clk_pad),
    .d(lfsr_65[32]),
    .q(lfsr_65[33]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b34 (
    .clk(clk_pad),
    .d(lfsr_65[33]),
    .q(lfsr_65[34]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b35 (
    .clk(clk_pad),
    .d(lfsr_65[34]),
    .q(lfsr_65[35]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b36 (
    .clk(clk_pad),
    .d(lfsr_65[35]),
    .q(lfsr_65[36]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b37 (
    .clk(clk_pad),
    .d(lfsr_65[36]),
    .q(lfsr_65[37]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b38 (
    .clk(clk_pad),
    .d(lfsr_65[37]),
    .q(lfsr_65[38]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b39 (
    .clk(clk_pad),
    .d(lfsr_65[38]),
    .q(lfsr_65[39]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b4 (
    .clk(clk_pad),
    .d(lfsr_65[3]),
    .q(lfsr_65[4]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b40 (
    .clk(clk_pad),
    .d(lfsr_65[39]),
    .q(lfsr_65[40]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b41 (
    .clk(clk_pad),
    .d(lfsr_65[40]),
    .q(lfsr_65[41]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b42 (
    .clk(clk_pad),
    .d(lfsr_65[41]),
    .q(lfsr_65[42]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b43 (
    .clk(clk_pad),
    .d(lfsr_65[42]),
    .q(lfsr_65[43]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b44 (
    .clk(clk_pad),
    .d(lfsr_65[43]),
    .q(lfsr_65[44]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b45 (
    .clk(clk_pad),
    .d(lfsr_65[44]),
    .q(lfsr_65[45]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b46 (
    .clk(clk_pad),
    .d(lfsr_65[45]),
    .q(lfsr_65[46]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b47 (
    .clk(clk_pad),
    .d(lfsr_65[46]),
    .q(lfsr_65[47]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b48 (
    .clk(clk_pad),
    .d(lfsr_65[47]),
    .q(lfsr_65[48]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b49 (
    .clk(clk_pad),
    .d(lfsr_65[48]),
    .q(lfsr_65[49]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b5 (
    .clk(clk_pad),
    .d(lfsr_65[4]),
    .q(lfsr_65[5]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b50 (
    .clk(clk_pad),
    .d(lfsr_65[49]),
    .q(lfsr_65[50]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b51 (
    .clk(clk_pad),
    .d(lfsr_65[50]),
    .q(lfsr_65[51]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b52 (
    .clk(clk_pad),
    .d(lfsr_65[51]),
    .q(lfsr_65[52]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b53 (
    .clk(clk_pad),
    .d(lfsr_65[52]),
    .q(lfsr_65[53]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b54 (
    .clk(clk_pad),
    .d(lfsr_65[53]),
    .q(lfsr_65[54]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b55 (
    .clk(clk_pad),
    .d(lfsr_65[54]),
    .q(lfsr_65[55]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b56 (
    .clk(clk_pad),
    .d(lfsr_65[55]),
    .q(lfsr_65[56]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b57 (
    .clk(clk_pad),
    .d(lfsr_65[56]),
    .q(lfsr_65[57]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b58 (
    .clk(clk_pad),
    .d(lfsr_65[57]),
    .q(lfsr_65[58]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b59 (
    .clk(clk_pad),
    .d(lfsr_65[58]),
    .q(lfsr_65[59]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b6 (
    .clk(clk_pad),
    .d(lfsr_65[5]),
    .q(lfsr_65[6]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b60 (
    .clk(clk_pad),
    .d(lfsr_65[59]),
    .q(lfsr_65[60]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b61 (
    .clk(clk_pad),
    .d(lfsr_65[60]),
    .q(lfsr_65[61]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b62 (
    .clk(clk_pad),
    .d(lfsr_65[61]),
    .q(lfsr_65[62]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b63 (
    .clk(clk_pad),
    .d(lfsr_65[62]),
    .q(lfsr_65[63]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b64 (
    .clk(clk_pad),
    .d(lfsr_65[63]),
    .q(lfsr_65[64]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b7 (
    .clk(clk_pad),
    .d(lfsr_65[6]),
    .q(lfsr_65[7]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b8 (
    .clk(clk_pad),
    .d(lfsr_65[7]),
    .q(lfsr_65[8]));  // RegFile.v(19)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b9 (
    .clk(clk_pad),
    .d(lfsr_65[8]),
    .q(lfsr_65[9]));  // RegFile.v(19)
  RegFile regfile (
    .addra(lfsra),
    .addrb(lfsrb),
    .addrw(cnt),
    .clk(clk_pad),
    .di(lfsr_65[63:0]),
    .we(lfsr_65[64]),
    .j(j_pad));  // RegFile.v(21)

endmodule 

module RegFile  // RegFile.v(37)
  (
  addra,
  addrb,
  addrw,
  clk,
  di,
  we,
  doa,
  dob,
  j
  );

  input [4:0] addra;  // RegFile.v(39)
  input [4:0] addrb;  // RegFile.v(39)
  input [4:0] addrw;  // RegFile.v(39)
  input clk;  // RegFile.v(40)
  input [63:0] di;  // RegFile.v(41)
  input we;  // RegFile.v(40)
  output [63:0] doa;  // RegFile.v(42)
  output [63:0] dob;  // RegFile.v(42)
  output j;  // RegFile.v(43)

  wire [3:0] al_ram_regmem_al_u0_r0_c0_di;
  wire [3:0] al_ram_regmem_al_u0_r0_c0_waddr;
  wire [3:0] al_ram_regmem_al_u0_r0_c10_di;
  wire [3:0] al_ram_regmem_al_u0_r0_c10_waddr;
  wire [3:0] al_ram_regmem_al_u0_r0_c11_di;
  wire [3:0] al_ram_regmem_al_u0_r0_c11_waddr;
  wire [3:0] al_ram_regmem_al_u0_r0_c12_di;
  wire [3:0] al_ram_regmem_al_u0_r0_c12_waddr;
  wire [3:0] al_ram_regmem_al_u0_r0_c13_di;
  wire [3:0] al_ram_regmem_al_u0_r0_c13_waddr;
  wire [3:0] al_ram_regmem_al_u0_r0_c14_di;
  wire [3:0] al_ram_regmem_al_u0_r0_c14_waddr;
  wire [3:0] al_ram_regmem_al_u0_r0_c15_di;
  wire [3:0] al_ram_regmem_al_u0_r0_c15_waddr;
  wire [3:0] al_ram_regmem_al_u0_r0_c1_di;
  wire [3:0] al_ram_regmem_al_u0_r0_c1_waddr;
  wire [3:0] al_ram_regmem_al_u0_r0_c2_di;
  wire [3:0] al_ram_regmem_al_u0_r0_c2_waddr;
  wire [3:0] al_ram_regmem_al_u0_r0_c3_di;
  wire [3:0] al_ram_regmem_al_u0_r0_c3_waddr;
  wire [3:0] al_ram_regmem_al_u0_r0_c4_di;
  wire [3:0] al_ram_regmem_al_u0_r0_c4_waddr;
  wire [3:0] al_ram_regmem_al_u0_r0_c5_di;
  wire [3:0] al_ram_regmem_al_u0_r0_c5_waddr;
  wire [3:0] al_ram_regmem_al_u0_r0_c6_di;
  wire [3:0] al_ram_regmem_al_u0_r0_c6_waddr;
  wire [3:0] al_ram_regmem_al_u0_r0_c7_di;
  wire [3:0] al_ram_regmem_al_u0_r0_c7_waddr;
  wire [3:0] al_ram_regmem_al_u0_r0_c8_di;
  wire [3:0] al_ram_regmem_al_u0_r0_c8_waddr;
  wire [3:0] al_ram_regmem_al_u0_r0_c9_di;
  wire [3:0] al_ram_regmem_al_u0_r0_c9_waddr;
  wire [3:0] al_ram_regmem_al_u0_r1_c0_di;
  wire [3:0] al_ram_regmem_al_u0_r1_c0_waddr;
  wire [3:0] al_ram_regmem_al_u0_r1_c10_di;
  wire [3:0] al_ram_regmem_al_u0_r1_c10_waddr;
  wire [3:0] al_ram_regmem_al_u0_r1_c11_di;
  wire [3:0] al_ram_regmem_al_u0_r1_c11_waddr;
  wire [3:0] al_ram_regmem_al_u0_r1_c12_di;
  wire [3:0] al_ram_regmem_al_u0_r1_c12_waddr;
  wire [3:0] al_ram_regmem_al_u0_r1_c13_di;
  wire [3:0] al_ram_regmem_al_u0_r1_c13_waddr;
  wire [3:0] al_ram_regmem_al_u0_r1_c14_di;
  wire [3:0] al_ram_regmem_al_u0_r1_c14_waddr;
  wire [3:0] al_ram_regmem_al_u0_r1_c15_di;
  wire [3:0] al_ram_regmem_al_u0_r1_c15_waddr;
  wire [3:0] al_ram_regmem_al_u0_r1_c1_di;
  wire [3:0] al_ram_regmem_al_u0_r1_c1_waddr;
  wire [3:0] al_ram_regmem_al_u0_r1_c2_di;
  wire [3:0] al_ram_regmem_al_u0_r1_c2_waddr;
  wire [3:0] al_ram_regmem_al_u0_r1_c3_di;
  wire [3:0] al_ram_regmem_al_u0_r1_c3_waddr;
  wire [3:0] al_ram_regmem_al_u0_r1_c4_di;
  wire [3:0] al_ram_regmem_al_u0_r1_c4_waddr;
  wire [3:0] al_ram_regmem_al_u0_r1_c5_di;
  wire [3:0] al_ram_regmem_al_u0_r1_c5_waddr;
  wire [3:0] al_ram_regmem_al_u0_r1_c6_di;
  wire [3:0] al_ram_regmem_al_u0_r1_c6_waddr;
  wire [3:0] al_ram_regmem_al_u0_r1_c7_di;
  wire [3:0] al_ram_regmem_al_u0_r1_c7_waddr;
  wire [3:0] al_ram_regmem_al_u0_r1_c8_di;
  wire [3:0] al_ram_regmem_al_u0_r1_c8_waddr;
  wire [3:0] al_ram_regmem_al_u0_r1_c9_di;
  wire [3:0] al_ram_regmem_al_u0_r1_c9_waddr;
  wire [3:0] al_ram_regmem_r0_c0_di;
  wire [3:0] al_ram_regmem_r0_c0_waddr;
  wire [3:0] al_ram_regmem_r0_c10_di;
  wire [3:0] al_ram_regmem_r0_c10_waddr;
  wire [3:0] al_ram_regmem_r0_c11_di;
  wire [3:0] al_ram_regmem_r0_c11_waddr;
  wire [3:0] al_ram_regmem_r0_c12_di;
  wire [3:0] al_ram_regmem_r0_c12_waddr;
  wire [3:0] al_ram_regmem_r0_c13_di;
  wire [3:0] al_ram_regmem_r0_c13_waddr;
  wire [3:0] al_ram_regmem_r0_c14_di;
  wire [3:0] al_ram_regmem_r0_c14_waddr;
  wire [3:0] al_ram_regmem_r0_c15_di;
  wire [3:0] al_ram_regmem_r0_c15_waddr;
  wire [3:0] al_ram_regmem_r0_c1_di;
  wire [3:0] al_ram_regmem_r0_c1_waddr;
  wire [3:0] al_ram_regmem_r0_c2_di;
  wire [3:0] al_ram_regmem_r0_c2_waddr;
  wire [3:0] al_ram_regmem_r0_c3_di;
  wire [3:0] al_ram_regmem_r0_c3_waddr;
  wire [3:0] al_ram_regmem_r0_c4_di;
  wire [3:0] al_ram_regmem_r0_c4_waddr;
  wire [3:0] al_ram_regmem_r0_c5_di;
  wire [3:0] al_ram_regmem_r0_c5_waddr;
  wire [3:0] al_ram_regmem_r0_c6_di;
  wire [3:0] al_ram_regmem_r0_c6_waddr;
  wire [3:0] al_ram_regmem_r0_c7_di;
  wire [3:0] al_ram_regmem_r0_c7_waddr;
  wire [3:0] al_ram_regmem_r0_c8_di;
  wire [3:0] al_ram_regmem_r0_c8_waddr;
  wire [3:0] al_ram_regmem_r0_c9_di;
  wire [3:0] al_ram_regmem_r0_c9_waddr;
  wire [3:0] al_ram_regmem_r1_c0_di;
  wire [3:0] al_ram_regmem_r1_c0_waddr;
  wire [3:0] al_ram_regmem_r1_c10_di;
  wire [3:0] al_ram_regmem_r1_c10_waddr;
  wire [3:0] al_ram_regmem_r1_c11_di;
  wire [3:0] al_ram_regmem_r1_c11_waddr;
  wire [3:0] al_ram_regmem_r1_c12_di;
  wire [3:0] al_ram_regmem_r1_c12_waddr;
  wire [3:0] al_ram_regmem_r1_c13_di;
  wire [3:0] al_ram_regmem_r1_c13_waddr;
  wire [3:0] al_ram_regmem_r1_c14_di;
  wire [3:0] al_ram_regmem_r1_c14_waddr;
  wire [3:0] al_ram_regmem_r1_c15_di;
  wire [3:0] al_ram_regmem_r1_c15_waddr;
  wire [3:0] al_ram_regmem_r1_c1_di;
  wire [3:0] al_ram_regmem_r1_c1_waddr;
  wire [3:0] al_ram_regmem_r1_c2_di;
  wire [3:0] al_ram_regmem_r1_c2_waddr;
  wire [3:0] al_ram_regmem_r1_c3_di;
  wire [3:0] al_ram_regmem_r1_c3_waddr;
  wire [3:0] al_ram_regmem_r1_c4_di;
  wire [3:0] al_ram_regmem_r1_c4_waddr;
  wire [3:0] al_ram_regmem_r1_c5_di;
  wire [3:0] al_ram_regmem_r1_c5_waddr;
  wire [3:0] al_ram_regmem_r1_c6_di;
  wire [3:0] al_ram_regmem_r1_c6_waddr;
  wire [3:0] al_ram_regmem_r1_c7_di;
  wire [3:0] al_ram_regmem_r1_c7_waddr;
  wire [3:0] al_ram_regmem_r1_c8_di;
  wire [3:0] al_ram_regmem_r1_c8_waddr;
  wire [3:0] al_ram_regmem_r1_c9_di;
  wire [3:0] al_ram_regmem_r1_c9_waddr;
  wire al_ram_regmem_al_u0_do_i0_000;
  wire al_ram_regmem_al_u0_do_i0_001;
  wire al_ram_regmem_al_u0_do_i0_002;
  wire al_ram_regmem_al_u0_do_i0_003;
  wire al_ram_regmem_al_u0_do_i0_004;
  wire al_ram_regmem_al_u0_do_i0_005;
  wire al_ram_regmem_al_u0_do_i0_006;
  wire al_ram_regmem_al_u0_do_i0_007;
  wire al_ram_regmem_al_u0_do_i0_008;
  wire al_ram_regmem_al_u0_do_i0_009;
  wire al_ram_regmem_al_u0_do_i0_010;
  wire al_ram_regmem_al_u0_do_i0_011;
  wire al_ram_regmem_al_u0_do_i0_012;
  wire al_ram_regmem_al_u0_do_i0_013;
  wire al_ram_regmem_al_u0_do_i0_014;
  wire al_ram_regmem_al_u0_do_i0_015;
  wire al_ram_regmem_al_u0_do_i0_016;
  wire al_ram_regmem_al_u0_do_i0_017;
  wire al_ram_regmem_al_u0_do_i0_018;
  wire al_ram_regmem_al_u0_do_i0_019;
  wire al_ram_regmem_al_u0_do_i0_020;
  wire al_ram_regmem_al_u0_do_i0_021;
  wire al_ram_regmem_al_u0_do_i0_022;
  wire al_ram_regmem_al_u0_do_i0_023;
  wire al_ram_regmem_al_u0_do_i0_024;
  wire al_ram_regmem_al_u0_do_i0_025;
  wire al_ram_regmem_al_u0_do_i0_026;
  wire al_ram_regmem_al_u0_do_i0_027;
  wire al_ram_regmem_al_u0_do_i0_028;
  wire al_ram_regmem_al_u0_do_i0_029;
  wire al_ram_regmem_al_u0_do_i0_030;
  wire al_ram_regmem_al_u0_do_i0_031;
  wire al_ram_regmem_al_u0_do_i0_032;
  wire al_ram_regmem_al_u0_do_i0_033;
  wire al_ram_regmem_al_u0_do_i0_034;
  wire al_ram_regmem_al_u0_do_i0_035;
  wire al_ram_regmem_al_u0_do_i0_036;
  wire al_ram_regmem_al_u0_do_i0_037;
  wire al_ram_regmem_al_u0_do_i0_038;
  wire al_ram_regmem_al_u0_do_i0_039;
  wire al_ram_regmem_al_u0_do_i0_040;
  wire al_ram_regmem_al_u0_do_i0_041;
  wire al_ram_regmem_al_u0_do_i0_042;
  wire al_ram_regmem_al_u0_do_i0_043;
  wire al_ram_regmem_al_u0_do_i0_044;
  wire al_ram_regmem_al_u0_do_i0_045;
  wire al_ram_regmem_al_u0_do_i0_046;
  wire al_ram_regmem_al_u0_do_i0_047;
  wire al_ram_regmem_al_u0_do_i0_048;
  wire al_ram_regmem_al_u0_do_i0_049;
  wire al_ram_regmem_al_u0_do_i0_050;
  wire al_ram_regmem_al_u0_do_i0_051;
  wire al_ram_regmem_al_u0_do_i0_052;
  wire al_ram_regmem_al_u0_do_i0_053;
  wire al_ram_regmem_al_u0_do_i0_054;
  wire al_ram_regmem_al_u0_do_i0_055;
  wire al_ram_regmem_al_u0_do_i0_056;
  wire al_ram_regmem_al_u0_do_i0_057;
  wire al_ram_regmem_al_u0_do_i0_058;
  wire al_ram_regmem_al_u0_do_i0_059;
  wire al_ram_regmem_al_u0_do_i0_060;
  wire al_ram_regmem_al_u0_do_i0_061;
  wire al_ram_regmem_al_u0_do_i0_062;
  wire al_ram_regmem_al_u0_do_i0_063;
  wire al_ram_regmem_al_u0_do_i1_000;
  wire al_ram_regmem_al_u0_do_i1_001;
  wire al_ram_regmem_al_u0_do_i1_002;
  wire al_ram_regmem_al_u0_do_i1_003;
  wire al_ram_regmem_al_u0_do_i1_004;
  wire al_ram_regmem_al_u0_do_i1_005;
  wire al_ram_regmem_al_u0_do_i1_006;
  wire al_ram_regmem_al_u0_do_i1_007;
  wire al_ram_regmem_al_u0_do_i1_008;
  wire al_ram_regmem_al_u0_do_i1_009;
  wire al_ram_regmem_al_u0_do_i1_010;
  wire al_ram_regmem_al_u0_do_i1_011;
  wire al_ram_regmem_al_u0_do_i1_012;
  wire al_ram_regmem_al_u0_do_i1_013;
  wire al_ram_regmem_al_u0_do_i1_014;
  wire al_ram_regmem_al_u0_do_i1_015;
  wire al_ram_regmem_al_u0_do_i1_016;
  wire al_ram_regmem_al_u0_do_i1_017;
  wire al_ram_regmem_al_u0_do_i1_018;
  wire al_ram_regmem_al_u0_do_i1_019;
  wire al_ram_regmem_al_u0_do_i1_020;
  wire al_ram_regmem_al_u0_do_i1_021;
  wire al_ram_regmem_al_u0_do_i1_022;
  wire al_ram_regmem_al_u0_do_i1_023;
  wire al_ram_regmem_al_u0_do_i1_024;
  wire al_ram_regmem_al_u0_do_i1_025;
  wire al_ram_regmem_al_u0_do_i1_026;
  wire al_ram_regmem_al_u0_do_i1_027;
  wire al_ram_regmem_al_u0_do_i1_028;
  wire al_ram_regmem_al_u0_do_i1_029;
  wire al_ram_regmem_al_u0_do_i1_030;
  wire al_ram_regmem_al_u0_do_i1_031;
  wire al_ram_regmem_al_u0_do_i1_032;
  wire al_ram_regmem_al_u0_do_i1_033;
  wire al_ram_regmem_al_u0_do_i1_034;
  wire al_ram_regmem_al_u0_do_i1_035;
  wire al_ram_regmem_al_u0_do_i1_036;
  wire al_ram_regmem_al_u0_do_i1_037;
  wire al_ram_regmem_al_u0_do_i1_038;
  wire al_ram_regmem_al_u0_do_i1_039;
  wire al_ram_regmem_al_u0_do_i1_040;
  wire al_ram_regmem_al_u0_do_i1_041;
  wire al_ram_regmem_al_u0_do_i1_042;
  wire al_ram_regmem_al_u0_do_i1_043;
  wire al_ram_regmem_al_u0_do_i1_044;
  wire al_ram_regmem_al_u0_do_i1_045;
  wire al_ram_regmem_al_u0_do_i1_046;
  wire al_ram_regmem_al_u0_do_i1_047;
  wire al_ram_regmem_al_u0_do_i1_048;
  wire al_ram_regmem_al_u0_do_i1_049;
  wire al_ram_regmem_al_u0_do_i1_050;
  wire al_ram_regmem_al_u0_do_i1_051;
  wire al_ram_regmem_al_u0_do_i1_052;
  wire al_ram_regmem_al_u0_do_i1_053;
  wire al_ram_regmem_al_u0_do_i1_054;
  wire al_ram_regmem_al_u0_do_i1_055;
  wire al_ram_regmem_al_u0_do_i1_056;
  wire al_ram_regmem_al_u0_do_i1_057;
  wire al_ram_regmem_al_u0_do_i1_058;
  wire al_ram_regmem_al_u0_do_i1_059;
  wire al_ram_regmem_al_u0_do_i1_060;
  wire al_ram_regmem_al_u0_do_i1_061;
  wire al_ram_regmem_al_u0_do_i1_062;
  wire al_ram_regmem_al_u0_do_i1_063;
  wire al_ram_regmem_al_u0_r0_c0_mode;
  wire al_ram_regmem_al_u0_r0_c0_wclk;
  wire al_ram_regmem_al_u0_r0_c0_we;
  wire al_ram_regmem_al_u0_r0_c10_mode;
  wire al_ram_regmem_al_u0_r0_c10_wclk;
  wire al_ram_regmem_al_u0_r0_c10_we;
  wire al_ram_regmem_al_u0_r0_c11_mode;
  wire al_ram_regmem_al_u0_r0_c11_wclk;
  wire al_ram_regmem_al_u0_r0_c11_we;
  wire al_ram_regmem_al_u0_r0_c12_mode;
  wire al_ram_regmem_al_u0_r0_c12_wclk;
  wire al_ram_regmem_al_u0_r0_c12_we;
  wire al_ram_regmem_al_u0_r0_c13_mode;
  wire al_ram_regmem_al_u0_r0_c13_wclk;
  wire al_ram_regmem_al_u0_r0_c13_we;
  wire al_ram_regmem_al_u0_r0_c14_mode;
  wire al_ram_regmem_al_u0_r0_c14_wclk;
  wire al_ram_regmem_al_u0_r0_c14_we;
  wire al_ram_regmem_al_u0_r0_c15_mode;
  wire al_ram_regmem_al_u0_r0_c15_wclk;
  wire al_ram_regmem_al_u0_r0_c15_we;
  wire al_ram_regmem_al_u0_r0_c1_mode;
  wire al_ram_regmem_al_u0_r0_c1_wclk;
  wire al_ram_regmem_al_u0_r0_c1_we;
  wire al_ram_regmem_al_u0_r0_c2_mode;
  wire al_ram_regmem_al_u0_r0_c2_wclk;
  wire al_ram_regmem_al_u0_r0_c2_we;
  wire al_ram_regmem_al_u0_r0_c3_mode;
  wire al_ram_regmem_al_u0_r0_c3_wclk;
  wire al_ram_regmem_al_u0_r0_c3_we;
  wire al_ram_regmem_al_u0_r0_c4_mode;
  wire al_ram_regmem_al_u0_r0_c4_wclk;
  wire al_ram_regmem_al_u0_r0_c4_we;
  wire al_ram_regmem_al_u0_r0_c5_mode;
  wire al_ram_regmem_al_u0_r0_c5_wclk;
  wire al_ram_regmem_al_u0_r0_c5_we;
  wire al_ram_regmem_al_u0_r0_c6_mode;
  wire al_ram_regmem_al_u0_r0_c6_wclk;
  wire al_ram_regmem_al_u0_r0_c6_we;
  wire al_ram_regmem_al_u0_r0_c7_mode;
  wire al_ram_regmem_al_u0_r0_c7_wclk;
  wire al_ram_regmem_al_u0_r0_c7_we;
  wire al_ram_regmem_al_u0_r0_c8_mode;
  wire al_ram_regmem_al_u0_r0_c8_wclk;
  wire al_ram_regmem_al_u0_r0_c8_we;
  wire al_ram_regmem_al_u0_r0_c9_mode;
  wire al_ram_regmem_al_u0_r0_c9_wclk;
  wire al_ram_regmem_al_u0_r0_c9_we;
  wire al_ram_regmem_al_u0_r1_c0_mode;
  wire al_ram_regmem_al_u0_r1_c0_wclk;
  wire al_ram_regmem_al_u0_r1_c0_we;
  wire al_ram_regmem_al_u0_r1_c10_mode;
  wire al_ram_regmem_al_u0_r1_c10_wclk;
  wire al_ram_regmem_al_u0_r1_c10_we;
  wire al_ram_regmem_al_u0_r1_c11_mode;
  wire al_ram_regmem_al_u0_r1_c11_wclk;
  wire al_ram_regmem_al_u0_r1_c11_we;
  wire al_ram_regmem_al_u0_r1_c12_mode;
  wire al_ram_regmem_al_u0_r1_c12_wclk;
  wire al_ram_regmem_al_u0_r1_c12_we;
  wire al_ram_regmem_al_u0_r1_c13_mode;
  wire al_ram_regmem_al_u0_r1_c13_wclk;
  wire al_ram_regmem_al_u0_r1_c13_we;
  wire al_ram_regmem_al_u0_r1_c14_mode;
  wire al_ram_regmem_al_u0_r1_c14_wclk;
  wire al_ram_regmem_al_u0_r1_c14_we;
  wire al_ram_regmem_al_u0_r1_c15_mode;
  wire al_ram_regmem_al_u0_r1_c15_wclk;
  wire al_ram_regmem_al_u0_r1_c15_we;
  wire al_ram_regmem_al_u0_r1_c1_mode;
  wire al_ram_regmem_al_u0_r1_c1_wclk;
  wire al_ram_regmem_al_u0_r1_c1_we;
  wire al_ram_regmem_al_u0_r1_c2_mode;
  wire al_ram_regmem_al_u0_r1_c2_wclk;
  wire al_ram_regmem_al_u0_r1_c2_we;
  wire al_ram_regmem_al_u0_r1_c3_mode;
  wire al_ram_regmem_al_u0_r1_c3_wclk;
  wire al_ram_regmem_al_u0_r1_c3_we;
  wire al_ram_regmem_al_u0_r1_c4_mode;
  wire al_ram_regmem_al_u0_r1_c4_wclk;
  wire al_ram_regmem_al_u0_r1_c4_we;
  wire al_ram_regmem_al_u0_r1_c5_mode;
  wire al_ram_regmem_al_u0_r1_c5_wclk;
  wire al_ram_regmem_al_u0_r1_c5_we;
  wire al_ram_regmem_al_u0_r1_c6_mode;
  wire al_ram_regmem_al_u0_r1_c6_wclk;
  wire al_ram_regmem_al_u0_r1_c6_we;
  wire al_ram_regmem_al_u0_r1_c7_mode;
  wire al_ram_regmem_al_u0_r1_c7_wclk;
  wire al_ram_regmem_al_u0_r1_c7_we;
  wire al_ram_regmem_al_u0_r1_c8_mode;
  wire al_ram_regmem_al_u0_r1_c8_wclk;
  wire al_ram_regmem_al_u0_r1_c8_we;
  wire al_ram_regmem_al_u0_r1_c9_mode;
  wire al_ram_regmem_al_u0_r1_c9_wclk;
  wire al_ram_regmem_al_u0_r1_c9_we;
  wire al_ram_regmem_do_i0_000;
  wire al_ram_regmem_do_i0_001;
  wire al_ram_regmem_do_i0_002;
  wire al_ram_regmem_do_i0_003;
  wire al_ram_regmem_do_i0_004;
  wire al_ram_regmem_do_i0_005;
  wire al_ram_regmem_do_i0_006;
  wire al_ram_regmem_do_i0_007;
  wire al_ram_regmem_do_i0_008;
  wire al_ram_regmem_do_i0_009;
  wire al_ram_regmem_do_i0_010;
  wire al_ram_regmem_do_i0_011;
  wire al_ram_regmem_do_i0_012;
  wire al_ram_regmem_do_i0_013;
  wire al_ram_regmem_do_i0_014;
  wire al_ram_regmem_do_i0_015;
  wire al_ram_regmem_do_i0_016;
  wire al_ram_regmem_do_i0_017;
  wire al_ram_regmem_do_i0_018;
  wire al_ram_regmem_do_i0_019;
  wire al_ram_regmem_do_i0_020;
  wire al_ram_regmem_do_i0_021;
  wire al_ram_regmem_do_i0_022;
  wire al_ram_regmem_do_i0_023;
  wire al_ram_regmem_do_i0_024;
  wire al_ram_regmem_do_i0_025;
  wire al_ram_regmem_do_i0_026;
  wire al_ram_regmem_do_i0_027;
  wire al_ram_regmem_do_i0_028;
  wire al_ram_regmem_do_i0_029;
  wire al_ram_regmem_do_i0_030;
  wire al_ram_regmem_do_i0_031;
  wire al_ram_regmem_do_i0_032;
  wire al_ram_regmem_do_i0_033;
  wire al_ram_regmem_do_i0_034;
  wire al_ram_regmem_do_i0_035;
  wire al_ram_regmem_do_i0_036;
  wire al_ram_regmem_do_i0_037;
  wire al_ram_regmem_do_i0_038;
  wire al_ram_regmem_do_i0_039;
  wire al_ram_regmem_do_i0_040;
  wire al_ram_regmem_do_i0_041;
  wire al_ram_regmem_do_i0_042;
  wire al_ram_regmem_do_i0_043;
  wire al_ram_regmem_do_i0_044;
  wire al_ram_regmem_do_i0_045;
  wire al_ram_regmem_do_i0_046;
  wire al_ram_regmem_do_i0_047;
  wire al_ram_regmem_do_i0_048;
  wire al_ram_regmem_do_i0_049;
  wire al_ram_regmem_do_i0_050;
  wire al_ram_regmem_do_i0_051;
  wire al_ram_regmem_do_i0_052;
  wire al_ram_regmem_do_i0_053;
  wire al_ram_regmem_do_i0_054;
  wire al_ram_regmem_do_i0_055;
  wire al_ram_regmem_do_i0_056;
  wire al_ram_regmem_do_i0_057;
  wire al_ram_regmem_do_i0_058;
  wire al_ram_regmem_do_i0_059;
  wire al_ram_regmem_do_i0_060;
  wire al_ram_regmem_do_i0_061;
  wire al_ram_regmem_do_i0_062;
  wire al_ram_regmem_do_i0_063;
  wire al_ram_regmem_do_i1_000;
  wire al_ram_regmem_do_i1_001;
  wire al_ram_regmem_do_i1_002;
  wire al_ram_regmem_do_i1_003;
  wire al_ram_regmem_do_i1_004;
  wire al_ram_regmem_do_i1_005;
  wire al_ram_regmem_do_i1_006;
  wire al_ram_regmem_do_i1_007;
  wire al_ram_regmem_do_i1_008;
  wire al_ram_regmem_do_i1_009;
  wire al_ram_regmem_do_i1_010;
  wire al_ram_regmem_do_i1_011;
  wire al_ram_regmem_do_i1_012;
  wire al_ram_regmem_do_i1_013;
  wire al_ram_regmem_do_i1_014;
  wire al_ram_regmem_do_i1_015;
  wire al_ram_regmem_do_i1_016;
  wire al_ram_regmem_do_i1_017;
  wire al_ram_regmem_do_i1_018;
  wire al_ram_regmem_do_i1_019;
  wire al_ram_regmem_do_i1_020;
  wire al_ram_regmem_do_i1_021;
  wire al_ram_regmem_do_i1_022;
  wire al_ram_regmem_do_i1_023;
  wire al_ram_regmem_do_i1_024;
  wire al_ram_regmem_do_i1_025;
  wire al_ram_regmem_do_i1_026;
  wire al_ram_regmem_do_i1_027;
  wire al_ram_regmem_do_i1_028;
  wire al_ram_regmem_do_i1_029;
  wire al_ram_regmem_do_i1_030;
  wire al_ram_regmem_do_i1_031;
  wire al_ram_regmem_do_i1_032;
  wire al_ram_regmem_do_i1_033;
  wire al_ram_regmem_do_i1_034;
  wire al_ram_regmem_do_i1_035;
  wire al_ram_regmem_do_i1_036;
  wire al_ram_regmem_do_i1_037;
  wire al_ram_regmem_do_i1_038;
  wire al_ram_regmem_do_i1_039;
  wire al_ram_regmem_do_i1_040;
  wire al_ram_regmem_do_i1_041;
  wire al_ram_regmem_do_i1_042;
  wire al_ram_regmem_do_i1_043;
  wire al_ram_regmem_do_i1_044;
  wire al_ram_regmem_do_i1_045;
  wire al_ram_regmem_do_i1_046;
  wire al_ram_regmem_do_i1_047;
  wire al_ram_regmem_do_i1_048;
  wire al_ram_regmem_do_i1_049;
  wire al_ram_regmem_do_i1_050;
  wire al_ram_regmem_do_i1_051;
  wire al_ram_regmem_do_i1_052;
  wire al_ram_regmem_do_i1_053;
  wire al_ram_regmem_do_i1_054;
  wire al_ram_regmem_do_i1_055;
  wire al_ram_regmem_do_i1_056;
  wire al_ram_regmem_do_i1_057;
  wire al_ram_regmem_do_i1_058;
  wire al_ram_regmem_do_i1_059;
  wire al_ram_regmem_do_i1_060;
  wire al_ram_regmem_do_i1_061;
  wire al_ram_regmem_do_i1_062;
  wire al_ram_regmem_do_i1_063;
  wire al_ram_regmem_r0_c0_mode;
  wire al_ram_regmem_r0_c0_wclk;
  wire al_ram_regmem_r0_c0_we;
  wire al_ram_regmem_r0_c10_mode;
  wire al_ram_regmem_r0_c10_wclk;
  wire al_ram_regmem_r0_c10_we;
  wire al_ram_regmem_r0_c11_mode;
  wire al_ram_regmem_r0_c11_wclk;
  wire al_ram_regmem_r0_c11_we;
  wire al_ram_regmem_r0_c12_mode;
  wire al_ram_regmem_r0_c12_wclk;
  wire al_ram_regmem_r0_c12_we;
  wire al_ram_regmem_r0_c13_mode;
  wire al_ram_regmem_r0_c13_wclk;
  wire al_ram_regmem_r0_c13_we;
  wire al_ram_regmem_r0_c14_mode;
  wire al_ram_regmem_r0_c14_wclk;
  wire al_ram_regmem_r0_c14_we;
  wire al_ram_regmem_r0_c15_mode;
  wire al_ram_regmem_r0_c15_wclk;
  wire al_ram_regmem_r0_c15_we;
  wire al_ram_regmem_r0_c1_mode;
  wire al_ram_regmem_r0_c1_wclk;
  wire al_ram_regmem_r0_c1_we;
  wire al_ram_regmem_r0_c2_mode;
  wire al_ram_regmem_r0_c2_wclk;
  wire al_ram_regmem_r0_c2_we;
  wire al_ram_regmem_r0_c3_mode;
  wire al_ram_regmem_r0_c3_wclk;
  wire al_ram_regmem_r0_c3_we;
  wire al_ram_regmem_r0_c4_mode;
  wire al_ram_regmem_r0_c4_wclk;
  wire al_ram_regmem_r0_c4_we;
  wire al_ram_regmem_r0_c5_mode;
  wire al_ram_regmem_r0_c5_wclk;
  wire al_ram_regmem_r0_c5_we;
  wire al_ram_regmem_r0_c6_mode;
  wire al_ram_regmem_r0_c6_wclk;
  wire al_ram_regmem_r0_c6_we;
  wire al_ram_regmem_r0_c7_mode;
  wire al_ram_regmem_r0_c7_wclk;
  wire al_ram_regmem_r0_c7_we;
  wire al_ram_regmem_r0_c8_mode;
  wire al_ram_regmem_r0_c8_wclk;
  wire al_ram_regmem_r0_c8_we;
  wire al_ram_regmem_r0_c9_mode;
  wire al_ram_regmem_r0_c9_wclk;
  wire al_ram_regmem_r0_c9_we;
  wire al_ram_regmem_r1_c0_mode;
  wire al_ram_regmem_r1_c0_wclk;
  wire al_ram_regmem_r1_c0_we;
  wire al_ram_regmem_r1_c10_mode;
  wire al_ram_regmem_r1_c10_wclk;
  wire al_ram_regmem_r1_c10_we;
  wire al_ram_regmem_r1_c11_mode;
  wire al_ram_regmem_r1_c11_wclk;
  wire al_ram_regmem_r1_c11_we;
  wire al_ram_regmem_r1_c12_mode;
  wire al_ram_regmem_r1_c12_wclk;
  wire al_ram_regmem_r1_c12_we;
  wire al_ram_regmem_r1_c13_mode;
  wire al_ram_regmem_r1_c13_wclk;
  wire al_ram_regmem_r1_c13_we;
  wire al_ram_regmem_r1_c14_mode;
  wire al_ram_regmem_r1_c14_wclk;
  wire al_ram_regmem_r1_c14_we;
  wire al_ram_regmem_r1_c15_mode;
  wire al_ram_regmem_r1_c15_wclk;
  wire al_ram_regmem_r1_c15_we;
  wire al_ram_regmem_r1_c1_mode;
  wire al_ram_regmem_r1_c1_wclk;
  wire al_ram_regmem_r1_c1_we;
  wire al_ram_regmem_r1_c2_mode;
  wire al_ram_regmem_r1_c2_wclk;
  wire al_ram_regmem_r1_c2_we;
  wire al_ram_regmem_r1_c3_mode;
  wire al_ram_regmem_r1_c3_wclk;
  wire al_ram_regmem_r1_c3_we;
  wire al_ram_regmem_r1_c4_mode;
  wire al_ram_regmem_r1_c4_wclk;
  wire al_ram_regmem_r1_c4_we;
  wire al_ram_regmem_r1_c5_mode;
  wire al_ram_regmem_r1_c5_wclk;
  wire al_ram_regmem_r1_c5_we;
  wire al_ram_regmem_r1_c6_mode;
  wire al_ram_regmem_r1_c6_wclk;
  wire al_ram_regmem_r1_c6_we;
  wire al_ram_regmem_r1_c7_mode;
  wire al_ram_regmem_r1_c7_wclk;
  wire al_ram_regmem_r1_c7_we;
  wire al_ram_regmem_r1_c8_mode;
  wire al_ram_regmem_r1_c8_wclk;
  wire al_ram_regmem_r1_c8_we;
  wire al_ram_regmem_r1_c9_mode;
  wire al_ram_regmem_r1_c9_wclk;
  wire al_ram_regmem_r1_c9_we;
  wire lt0_c1;
  wire lt0_c11;
  wire lt0_c13;
  wire lt0_c15;
  wire lt0_c17;
  wire lt0_c19;
  wire lt0_c21;
  wire lt0_c23;
  wire lt0_c25;
  wire lt0_c27;
  wire lt0_c29;
  wire lt0_c3;
  wire lt0_c31;
  wire lt0_c33;
  wire lt0_c35;
  wire lt0_c37;
  wire lt0_c39;
  wire lt0_c41;
  wire lt0_c43;
  wire lt0_c45;
  wire lt0_c47;
  wire lt0_c49;
  wire lt0_c5;
  wire lt0_c51;
  wire lt0_c53;
  wire lt0_c55;
  wire lt0_c57;
  wire lt0_c59;
  wire lt0_c61;
  wire lt0_c63;
  wire lt0_c7;
  wire lt0_c9;
  wire we_0_al_n0;
  wire we_1_al_n1;

  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u10 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_004),
    .c(al_ram_regmem_al_u0_do_i1_004),
    .o(dob[4]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u100 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_010),
    .c(al_ram_regmem_do_i1_010),
    .o(doa[10]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u101 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_009),
    .c(al_ram_regmem_do_i1_009),
    .o(doa[9]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u102 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_008),
    .c(al_ram_regmem_do_i1_008),
    .o(doa[8]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u103 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_015),
    .c(al_ram_regmem_do_i1_015),
    .o(doa[15]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u104 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_014),
    .c(al_ram_regmem_do_i1_014),
    .o(doa[14]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u105 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_013),
    .c(al_ram_regmem_do_i1_013),
    .o(doa[13]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u106 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_012),
    .c(al_ram_regmem_do_i1_012),
    .o(doa[12]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u107 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_019),
    .c(al_ram_regmem_do_i1_019),
    .o(doa[19]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u108 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_018),
    .c(al_ram_regmem_do_i1_018),
    .o(doa[18]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u109 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_017),
    .c(al_ram_regmem_do_i1_017),
    .o(doa[17]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u11 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_043),
    .c(al_ram_regmem_al_u0_do_i1_043),
    .o(dob[43]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u110 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_016),
    .c(al_ram_regmem_do_i1_016),
    .o(doa[16]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u111 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_023),
    .c(al_ram_regmem_do_i1_023),
    .o(doa[23]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u112 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_022),
    .c(al_ram_regmem_do_i1_022),
    .o(doa[22]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u113 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_021),
    .c(al_ram_regmem_do_i1_021),
    .o(doa[21]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u114 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_020),
    .c(al_ram_regmem_do_i1_020),
    .o(doa[20]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u115 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_027),
    .c(al_ram_regmem_do_i1_027),
    .o(doa[27]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u116 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_026),
    .c(al_ram_regmem_do_i1_026),
    .o(doa[26]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u117 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_025),
    .c(al_ram_regmem_do_i1_025),
    .o(doa[25]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u118 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_024),
    .c(al_ram_regmem_do_i1_024),
    .o(doa[24]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u119 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_031),
    .c(al_ram_regmem_do_i1_031),
    .o(doa[31]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u12 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_042),
    .c(al_ram_regmem_al_u0_do_i1_042),
    .o(dob[42]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u120 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_030),
    .c(al_ram_regmem_do_i1_030),
    .o(doa[30]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u121 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_029),
    .c(al_ram_regmem_do_i1_029),
    .o(doa[29]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u122 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_028),
    .c(al_ram_regmem_do_i1_028),
    .o(doa[28]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u123 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_035),
    .c(al_ram_regmem_do_i1_035),
    .o(doa[35]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u124 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_034),
    .c(al_ram_regmem_do_i1_034),
    .o(doa[34]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u125 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_033),
    .c(al_ram_regmem_do_i1_033),
    .o(doa[33]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u126 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_032),
    .c(al_ram_regmem_do_i1_032),
    .o(doa[32]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u127 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_039),
    .c(al_ram_regmem_do_i1_039),
    .o(doa[39]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u128 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_038),
    .c(al_ram_regmem_do_i1_038),
    .o(doa[38]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u129 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_037),
    .c(al_ram_regmem_do_i1_037),
    .o(doa[37]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u13 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_041),
    .c(al_ram_regmem_al_u0_do_i1_041),
    .o(dob[41]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u130 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_036),
    .c(al_ram_regmem_do_i1_036),
    .o(doa[36]));
  AL_MAP_LUT2 #(
    .EQN("(B*~A)"),
    .INIT(4'h4))
    _al_u131 (
    .a(addrw[4]),
    .b(we),
    .o(we_0_al_n0));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u14 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_040),
    .c(al_ram_regmem_al_u0_do_i1_040),
    .o(dob[40]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u15 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_047),
    .c(al_ram_regmem_al_u0_do_i1_047),
    .o(dob[47]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u16 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_046),
    .c(al_ram_regmem_al_u0_do_i1_046),
    .o(dob[46]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u17 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_045),
    .c(al_ram_regmem_al_u0_do_i1_045),
    .o(dob[45]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u18 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_044),
    .c(al_ram_regmem_al_u0_do_i1_044),
    .o(dob[44]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u19 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_051),
    .c(al_ram_regmem_al_u0_do_i1_051),
    .o(dob[51]));
  AL_MAP_LUT2 #(
    .EQN("(B*A)"),
    .INIT(4'h8))
    _al_u2 (
    .a(addrw[4]),
    .b(we),
    .o(we_1_al_n1));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u20 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_050),
    .c(al_ram_regmem_al_u0_do_i1_050),
    .o(dob[50]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u21 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_049),
    .c(al_ram_regmem_al_u0_do_i1_049),
    .o(dob[49]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u22 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_048),
    .c(al_ram_regmem_al_u0_do_i1_048),
    .o(dob[48]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u23 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_055),
    .c(al_ram_regmem_al_u0_do_i1_055),
    .o(dob[55]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u24 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_054),
    .c(al_ram_regmem_al_u0_do_i1_054),
    .o(dob[54]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u25 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_053),
    .c(al_ram_regmem_al_u0_do_i1_053),
    .o(dob[53]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u26 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_052),
    .c(al_ram_regmem_al_u0_do_i1_052),
    .o(dob[52]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u27 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_059),
    .c(al_ram_regmem_al_u0_do_i1_059),
    .o(dob[59]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u28 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_058),
    .c(al_ram_regmem_al_u0_do_i1_058),
    .o(dob[58]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u29 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_057),
    .c(al_ram_regmem_al_u0_do_i1_057),
    .o(dob[57]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u3 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_003),
    .c(al_ram_regmem_al_u0_do_i1_003),
    .o(dob[3]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u30 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_056),
    .c(al_ram_regmem_al_u0_do_i1_056),
    .o(dob[56]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u31 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_063),
    .c(al_ram_regmem_al_u0_do_i1_063),
    .o(dob[63]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u32 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_062),
    .c(al_ram_regmem_al_u0_do_i1_062),
    .o(dob[62]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u33 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_061),
    .c(al_ram_regmem_al_u0_do_i1_061),
    .o(dob[61]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u34 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_060),
    .c(al_ram_regmem_al_u0_do_i1_060),
    .o(dob[60]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u35 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_011),
    .c(al_ram_regmem_al_u0_do_i1_011),
    .o(dob[11]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u36 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_010),
    .c(al_ram_regmem_al_u0_do_i1_010),
    .o(dob[10]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u37 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_009),
    .c(al_ram_regmem_al_u0_do_i1_009),
    .o(dob[9]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u38 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_008),
    .c(al_ram_regmem_al_u0_do_i1_008),
    .o(dob[8]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u39 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_015),
    .c(al_ram_regmem_al_u0_do_i1_015),
    .o(dob[15]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u4 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_002),
    .c(al_ram_regmem_al_u0_do_i1_002),
    .o(dob[2]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u40 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_014),
    .c(al_ram_regmem_al_u0_do_i1_014),
    .o(dob[14]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u41 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_013),
    .c(al_ram_regmem_al_u0_do_i1_013),
    .o(dob[13]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u42 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_012),
    .c(al_ram_regmem_al_u0_do_i1_012),
    .o(dob[12]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u43 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_019),
    .c(al_ram_regmem_al_u0_do_i1_019),
    .o(dob[19]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u44 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_018),
    .c(al_ram_regmem_al_u0_do_i1_018),
    .o(dob[18]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u45 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_017),
    .c(al_ram_regmem_al_u0_do_i1_017),
    .o(dob[17]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u46 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_016),
    .c(al_ram_regmem_al_u0_do_i1_016),
    .o(dob[16]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u47 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_023),
    .c(al_ram_regmem_al_u0_do_i1_023),
    .o(dob[23]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u48 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_022),
    .c(al_ram_regmem_al_u0_do_i1_022),
    .o(dob[22]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u49 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_021),
    .c(al_ram_regmem_al_u0_do_i1_021),
    .o(dob[21]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u5 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_001),
    .c(al_ram_regmem_al_u0_do_i1_001),
    .o(dob[1]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u50 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_020),
    .c(al_ram_regmem_al_u0_do_i1_020),
    .o(dob[20]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u51 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_027),
    .c(al_ram_regmem_al_u0_do_i1_027),
    .o(dob[27]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u52 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_026),
    .c(al_ram_regmem_al_u0_do_i1_026),
    .o(dob[26]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u53 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_025),
    .c(al_ram_regmem_al_u0_do_i1_025),
    .o(dob[25]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u54 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_024),
    .c(al_ram_regmem_al_u0_do_i1_024),
    .o(dob[24]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u55 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_031),
    .c(al_ram_regmem_al_u0_do_i1_031),
    .o(dob[31]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u56 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_030),
    .c(al_ram_regmem_al_u0_do_i1_030),
    .o(dob[30]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u57 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_029),
    .c(al_ram_regmem_al_u0_do_i1_029),
    .o(dob[29]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u58 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_028),
    .c(al_ram_regmem_al_u0_do_i1_028),
    .o(dob[28]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u59 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_035),
    .c(al_ram_regmem_al_u0_do_i1_035),
    .o(dob[35]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u6 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_000),
    .c(al_ram_regmem_al_u0_do_i1_000),
    .o(dob[0]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u60 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_034),
    .c(al_ram_regmem_al_u0_do_i1_034),
    .o(dob[34]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u61 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_033),
    .c(al_ram_regmem_al_u0_do_i1_033),
    .o(dob[33]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u62 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_032),
    .c(al_ram_regmem_al_u0_do_i1_032),
    .o(dob[32]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u63 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_039),
    .c(al_ram_regmem_al_u0_do_i1_039),
    .o(dob[39]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u64 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_038),
    .c(al_ram_regmem_al_u0_do_i1_038),
    .o(dob[38]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u65 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_037),
    .c(al_ram_regmem_al_u0_do_i1_037),
    .o(dob[37]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u66 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_036),
    .c(al_ram_regmem_al_u0_do_i1_036),
    .o(dob[36]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u67 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_003),
    .c(al_ram_regmem_do_i1_003),
    .o(doa[3]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u68 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_002),
    .c(al_ram_regmem_do_i1_002),
    .o(doa[2]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u69 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_001),
    .c(al_ram_regmem_do_i1_001),
    .o(doa[1]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u7 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_007),
    .c(al_ram_regmem_al_u0_do_i1_007),
    .o(dob[7]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u70 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_000),
    .c(al_ram_regmem_do_i1_000),
    .o(doa[0]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u71 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_007),
    .c(al_ram_regmem_do_i1_007),
    .o(doa[7]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u72 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_006),
    .c(al_ram_regmem_do_i1_006),
    .o(doa[6]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u73 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_005),
    .c(al_ram_regmem_do_i1_005),
    .o(doa[5]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u74 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_004),
    .c(al_ram_regmem_do_i1_004),
    .o(doa[4]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u75 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_043),
    .c(al_ram_regmem_do_i1_043),
    .o(doa[43]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u76 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_042),
    .c(al_ram_regmem_do_i1_042),
    .o(doa[42]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u77 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_041),
    .c(al_ram_regmem_do_i1_041),
    .o(doa[41]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u78 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_040),
    .c(al_ram_regmem_do_i1_040),
    .o(doa[40]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u79 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_047),
    .c(al_ram_regmem_do_i1_047),
    .o(doa[47]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u8 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_006),
    .c(al_ram_regmem_al_u0_do_i1_006),
    .o(dob[6]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u80 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_046),
    .c(al_ram_regmem_do_i1_046),
    .o(doa[46]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u81 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_045),
    .c(al_ram_regmem_do_i1_045),
    .o(doa[45]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u82 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_044),
    .c(al_ram_regmem_do_i1_044),
    .o(doa[44]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u83 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_051),
    .c(al_ram_regmem_do_i1_051),
    .o(doa[51]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u84 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_050),
    .c(al_ram_regmem_do_i1_050),
    .o(doa[50]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u85 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_049),
    .c(al_ram_regmem_do_i1_049),
    .o(doa[49]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u86 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_048),
    .c(al_ram_regmem_do_i1_048),
    .o(doa[48]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u87 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_055),
    .c(al_ram_regmem_do_i1_055),
    .o(doa[55]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u88 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_054),
    .c(al_ram_regmem_do_i1_054),
    .o(doa[54]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u89 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_053),
    .c(al_ram_regmem_do_i1_053),
    .o(doa[53]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u9 (
    .a(addrb[4]),
    .b(al_ram_regmem_al_u0_do_i0_005),
    .c(al_ram_regmem_al_u0_do_i1_005),
    .o(dob[5]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u90 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_052),
    .c(al_ram_regmem_do_i1_052),
    .o(doa[52]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u91 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_059),
    .c(al_ram_regmem_do_i1_059),
    .o(doa[59]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u92 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_058),
    .c(al_ram_regmem_do_i1_058),
    .o(doa[58]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u93 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_057),
    .c(al_ram_regmem_do_i1_057),
    .o(doa[57]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u94 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_056),
    .c(al_ram_regmem_do_i1_056),
    .o(doa[56]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u95 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_063),
    .c(al_ram_regmem_do_i1_063),
    .o(doa[63]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u96 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_062),
    .c(al_ram_regmem_do_i1_062),
    .o(doa[62]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u97 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_061),
    .c(al_ram_regmem_do_i1_061),
    .o(doa[61]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u98 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_060),
    .c(al_ram_regmem_do_i1_060),
    .o(doa[60]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u99 (
    .a(addra[4]),
    .b(al_ram_regmem_do_i0_011),
    .c(al_ram_regmem_do_i1_011),
    .o(doa[11]));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c0_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r0_c0_l (
    .a({di[0],addrw[0]}),
    .b({di[1],addrw[1]}),
    .c({di[2],addrw[2]}),
    .clk(clk),
    .d({di[3],addrw[3]}),
    .e({open_n1,we_0_al_n0}),
    .dpram_di(al_ram_regmem_al_u0_r0_c0_di),
    .dpram_mode(al_ram_regmem_al_u0_r0_c0_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c0_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c0_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c0_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c0_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c0_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c0_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c0_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c0_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c0_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c0_we),
    .f({al_ram_regmem_al_u0_do_i0_001,al_ram_regmem_al_u0_do_i0_000}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c0_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c0_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c0_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c0_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c0_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c0_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c0_we),
    .f({al_ram_regmem_al_u0_do_i0_003,al_ram_regmem_al_u0_do_i0_002}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c10_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r0_c10_l (
    .a({di[40],addrw[0]}),
    .b({di[41],addrw[1]}),
    .c({di[42],addrw[2]}),
    .clk(clk),
    .d({di[43],addrw[3]}),
    .e({open_n36,we_0_al_n0}),
    .dpram_di(al_ram_regmem_al_u0_r0_c10_di),
    .dpram_mode(al_ram_regmem_al_u0_r0_c10_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c10_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c10_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c10_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c10_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c10_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c10_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c10_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c10_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c10_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c10_we),
    .f({al_ram_regmem_al_u0_do_i0_041,al_ram_regmem_al_u0_do_i0_040}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c10_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c10_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c10_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c10_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c10_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c10_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c10_we),
    .f({al_ram_regmem_al_u0_do_i0_043,al_ram_regmem_al_u0_do_i0_042}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c11_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r0_c11_l (
    .a({di[44],addrw[0]}),
    .b({di[45],addrw[1]}),
    .c({di[46],addrw[2]}),
    .clk(clk),
    .d({di[47],addrw[3]}),
    .e({open_n71,we_0_al_n0}),
    .dpram_di(al_ram_regmem_al_u0_r0_c11_di),
    .dpram_mode(al_ram_regmem_al_u0_r0_c11_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c11_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c11_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c11_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c11_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c11_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c11_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c11_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c11_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c11_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c11_we),
    .f({al_ram_regmem_al_u0_do_i0_045,al_ram_regmem_al_u0_do_i0_044}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c11_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c11_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c11_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c11_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c11_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c11_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c11_we),
    .f({al_ram_regmem_al_u0_do_i0_047,al_ram_regmem_al_u0_do_i0_046}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c12_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r0_c12_l (
    .a({di[48],addrw[0]}),
    .b({di[49],addrw[1]}),
    .c({di[50],addrw[2]}),
    .clk(clk),
    .d({di[51],addrw[3]}),
    .e({open_n106,we_0_al_n0}),
    .dpram_di(al_ram_regmem_al_u0_r0_c12_di),
    .dpram_mode(al_ram_regmem_al_u0_r0_c12_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c12_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c12_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c12_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c12_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c12_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c12_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c12_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c12_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c12_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c12_we),
    .f({al_ram_regmem_al_u0_do_i0_049,al_ram_regmem_al_u0_do_i0_048}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c12_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c12_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c12_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c12_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c12_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c12_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c12_we),
    .f({al_ram_regmem_al_u0_do_i0_051,al_ram_regmem_al_u0_do_i0_050}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c13_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r0_c13_l (
    .a({di[52],addrw[0]}),
    .b({di[53],addrw[1]}),
    .c({di[54],addrw[2]}),
    .clk(clk),
    .d({di[55],addrw[3]}),
    .e({open_n141,we_0_al_n0}),
    .dpram_di(al_ram_regmem_al_u0_r0_c13_di),
    .dpram_mode(al_ram_regmem_al_u0_r0_c13_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c13_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c13_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c13_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c13_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c13_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c13_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c13_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c13_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c13_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c13_we),
    .f({al_ram_regmem_al_u0_do_i0_053,al_ram_regmem_al_u0_do_i0_052}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c13_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c13_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c13_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c13_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c13_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c13_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c13_we),
    .f({al_ram_regmem_al_u0_do_i0_055,al_ram_regmem_al_u0_do_i0_054}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c14_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r0_c14_l (
    .a({di[56],addrw[0]}),
    .b({di[57],addrw[1]}),
    .c({di[58],addrw[2]}),
    .clk(clk),
    .d({di[59],addrw[3]}),
    .e({open_n176,we_0_al_n0}),
    .dpram_di(al_ram_regmem_al_u0_r0_c14_di),
    .dpram_mode(al_ram_regmem_al_u0_r0_c14_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c14_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c14_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c14_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c14_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c14_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c14_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c14_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c14_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c14_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c14_we),
    .f({al_ram_regmem_al_u0_do_i0_057,al_ram_regmem_al_u0_do_i0_056}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c14_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c14_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c14_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c14_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c14_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c14_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c14_we),
    .f({al_ram_regmem_al_u0_do_i0_059,al_ram_regmem_al_u0_do_i0_058}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c15_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r0_c15_l (
    .a({di[60],addrw[0]}),
    .b({di[61],addrw[1]}),
    .c({di[62],addrw[2]}),
    .clk(clk),
    .d({di[63],addrw[3]}),
    .e({open_n211,we_0_al_n0}),
    .dpram_di(al_ram_regmem_al_u0_r0_c15_di),
    .dpram_mode(al_ram_regmem_al_u0_r0_c15_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c15_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c15_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c15_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c15_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c15_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c15_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c15_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c15_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c15_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c15_we),
    .f({al_ram_regmem_al_u0_do_i0_061,al_ram_regmem_al_u0_do_i0_060}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c15_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c15_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c15_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c15_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c15_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c15_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c15_we),
    .f({al_ram_regmem_al_u0_do_i0_063,al_ram_regmem_al_u0_do_i0_062}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c1_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r0_c1_l (
    .a({di[4],addrw[0]}),
    .b({di[5],addrw[1]}),
    .c({di[6],addrw[2]}),
    .clk(clk),
    .d({di[7],addrw[3]}),
    .e({open_n246,we_0_al_n0}),
    .dpram_di(al_ram_regmem_al_u0_r0_c1_di),
    .dpram_mode(al_ram_regmem_al_u0_r0_c1_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c1_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c1_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c1_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c1_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c1_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c1_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c1_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c1_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c1_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c1_we),
    .f({al_ram_regmem_al_u0_do_i0_005,al_ram_regmem_al_u0_do_i0_004}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c1_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c1_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c1_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c1_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c1_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c1_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c1_we),
    .f({al_ram_regmem_al_u0_do_i0_007,al_ram_regmem_al_u0_do_i0_006}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c2_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r0_c2_l (
    .a({di[8],addrw[0]}),
    .b({di[9],addrw[1]}),
    .c({di[10],addrw[2]}),
    .clk(clk),
    .d({di[11],addrw[3]}),
    .e({open_n281,we_0_al_n0}),
    .dpram_di(al_ram_regmem_al_u0_r0_c2_di),
    .dpram_mode(al_ram_regmem_al_u0_r0_c2_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c2_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c2_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c2_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c2_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c2_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c2_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c2_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c2_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c2_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c2_we),
    .f({al_ram_regmem_al_u0_do_i0_009,al_ram_regmem_al_u0_do_i0_008}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c2_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c2_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c2_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c2_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c2_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c2_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c2_we),
    .f({al_ram_regmem_al_u0_do_i0_011,al_ram_regmem_al_u0_do_i0_010}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c3_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r0_c3_l (
    .a({di[12],addrw[0]}),
    .b({di[13],addrw[1]}),
    .c({di[14],addrw[2]}),
    .clk(clk),
    .d({di[15],addrw[3]}),
    .e({open_n316,we_0_al_n0}),
    .dpram_di(al_ram_regmem_al_u0_r0_c3_di),
    .dpram_mode(al_ram_regmem_al_u0_r0_c3_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c3_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c3_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c3_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c3_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c3_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c3_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c3_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c3_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c3_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c3_we),
    .f({al_ram_regmem_al_u0_do_i0_013,al_ram_regmem_al_u0_do_i0_012}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c3_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c3_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c3_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c3_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c3_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c3_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c3_we),
    .f({al_ram_regmem_al_u0_do_i0_015,al_ram_regmem_al_u0_do_i0_014}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c4_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r0_c4_l (
    .a({di[16],addrw[0]}),
    .b({di[17],addrw[1]}),
    .c({di[18],addrw[2]}),
    .clk(clk),
    .d({di[19],addrw[3]}),
    .e({open_n351,we_0_al_n0}),
    .dpram_di(al_ram_regmem_al_u0_r0_c4_di),
    .dpram_mode(al_ram_regmem_al_u0_r0_c4_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c4_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c4_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c4_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c4_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c4_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c4_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c4_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c4_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c4_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c4_we),
    .f({al_ram_regmem_al_u0_do_i0_017,al_ram_regmem_al_u0_do_i0_016}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c4_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c4_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c4_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c4_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c4_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c4_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c4_we),
    .f({al_ram_regmem_al_u0_do_i0_019,al_ram_regmem_al_u0_do_i0_018}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c5_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r0_c5_l (
    .a({di[20],addrw[0]}),
    .b({di[21],addrw[1]}),
    .c({di[22],addrw[2]}),
    .clk(clk),
    .d({di[23],addrw[3]}),
    .e({open_n386,we_0_al_n0}),
    .dpram_di(al_ram_regmem_al_u0_r0_c5_di),
    .dpram_mode(al_ram_regmem_al_u0_r0_c5_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c5_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c5_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c5_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c5_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c5_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c5_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c5_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c5_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c5_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c5_we),
    .f({al_ram_regmem_al_u0_do_i0_021,al_ram_regmem_al_u0_do_i0_020}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c5_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c5_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c5_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c5_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c5_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c5_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c5_we),
    .f({al_ram_regmem_al_u0_do_i0_023,al_ram_regmem_al_u0_do_i0_022}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c6_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r0_c6_l (
    .a({di[24],addrw[0]}),
    .b({di[25],addrw[1]}),
    .c({di[26],addrw[2]}),
    .clk(clk),
    .d({di[27],addrw[3]}),
    .e({open_n421,we_0_al_n0}),
    .dpram_di(al_ram_regmem_al_u0_r0_c6_di),
    .dpram_mode(al_ram_regmem_al_u0_r0_c6_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c6_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c6_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c6_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c6_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c6_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c6_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c6_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c6_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c6_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c6_we),
    .f({al_ram_regmem_al_u0_do_i0_025,al_ram_regmem_al_u0_do_i0_024}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c6_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c6_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c6_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c6_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c6_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c6_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c6_we),
    .f({al_ram_regmem_al_u0_do_i0_027,al_ram_regmem_al_u0_do_i0_026}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c7_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r0_c7_l (
    .a({di[28],addrw[0]}),
    .b({di[29],addrw[1]}),
    .c({di[30],addrw[2]}),
    .clk(clk),
    .d({di[31],addrw[3]}),
    .e({open_n456,we_0_al_n0}),
    .dpram_di(al_ram_regmem_al_u0_r0_c7_di),
    .dpram_mode(al_ram_regmem_al_u0_r0_c7_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c7_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c7_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c7_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c7_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c7_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c7_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c7_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c7_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c7_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c7_we),
    .f({al_ram_regmem_al_u0_do_i0_029,al_ram_regmem_al_u0_do_i0_028}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c7_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c7_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c7_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c7_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c7_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c7_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c7_we),
    .f({al_ram_regmem_al_u0_do_i0_031,al_ram_regmem_al_u0_do_i0_030}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c8_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r0_c8_l (
    .a({di[32],addrw[0]}),
    .b({di[33],addrw[1]}),
    .c({di[34],addrw[2]}),
    .clk(clk),
    .d({di[35],addrw[3]}),
    .e({open_n491,we_0_al_n0}),
    .dpram_di(al_ram_regmem_al_u0_r0_c8_di),
    .dpram_mode(al_ram_regmem_al_u0_r0_c8_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c8_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c8_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c8_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c8_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c8_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c8_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c8_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c8_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c8_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c8_we),
    .f({al_ram_regmem_al_u0_do_i0_033,al_ram_regmem_al_u0_do_i0_032}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c8_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c8_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c8_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c8_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c8_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c8_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c8_we),
    .f({al_ram_regmem_al_u0_do_i0_035,al_ram_regmem_al_u0_do_i0_034}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c9_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r0_c9_l (
    .a({di[36],addrw[0]}),
    .b({di[37],addrw[1]}),
    .c({di[38],addrw[2]}),
    .clk(clk),
    .d({di[39],addrw[3]}),
    .e({open_n526,we_0_al_n0}),
    .dpram_di(al_ram_regmem_al_u0_r0_c9_di),
    .dpram_mode(al_ram_regmem_al_u0_r0_c9_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c9_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c9_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c9_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c9_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c9_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c9_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c9_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c9_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c9_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c9_we),
    .f({al_ram_regmem_al_u0_do_i0_037,al_ram_regmem_al_u0_do_i0_036}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r0_c9_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r0_c9_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r0_c9_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r0_c9_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r0_c9_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r0_c9_wclk),
    .dpram_we(al_ram_regmem_al_u0_r0_c9_we),
    .f({al_ram_regmem_al_u0_do_i0_039,al_ram_regmem_al_u0_do_i0_038}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c0_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r1_c0_l (
    .a({di[0],addrw[0]}),
    .b({di[1],addrw[1]}),
    .c({di[2],addrw[2]}),
    .clk(clk),
    .d({di[3],addrw[3]}),
    .e({open_n561,we_1_al_n1}),
    .dpram_di(al_ram_regmem_al_u0_r1_c0_di),
    .dpram_mode(al_ram_regmem_al_u0_r1_c0_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c0_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c0_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c0_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c0_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c0_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c0_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c0_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c0_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c0_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c0_we),
    .f({al_ram_regmem_al_u0_do_i1_001,al_ram_regmem_al_u0_do_i1_000}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c0_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c0_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c0_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c0_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c0_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c0_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c0_we),
    .f({al_ram_regmem_al_u0_do_i1_003,al_ram_regmem_al_u0_do_i1_002}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c10_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r1_c10_l (
    .a({di[40],addrw[0]}),
    .b({di[41],addrw[1]}),
    .c({di[42],addrw[2]}),
    .clk(clk),
    .d({di[43],addrw[3]}),
    .e({open_n596,we_1_al_n1}),
    .dpram_di(al_ram_regmem_al_u0_r1_c10_di),
    .dpram_mode(al_ram_regmem_al_u0_r1_c10_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c10_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c10_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c10_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c10_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c10_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c10_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c10_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c10_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c10_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c10_we),
    .f({al_ram_regmem_al_u0_do_i1_041,al_ram_regmem_al_u0_do_i1_040}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c10_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c10_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c10_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c10_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c10_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c10_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c10_we),
    .f({al_ram_regmem_al_u0_do_i1_043,al_ram_regmem_al_u0_do_i1_042}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c11_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r1_c11_l (
    .a({di[44],addrw[0]}),
    .b({di[45],addrw[1]}),
    .c({di[46],addrw[2]}),
    .clk(clk),
    .d({di[47],addrw[3]}),
    .e({open_n631,we_1_al_n1}),
    .dpram_di(al_ram_regmem_al_u0_r1_c11_di),
    .dpram_mode(al_ram_regmem_al_u0_r1_c11_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c11_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c11_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c11_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c11_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c11_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c11_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c11_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c11_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c11_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c11_we),
    .f({al_ram_regmem_al_u0_do_i1_045,al_ram_regmem_al_u0_do_i1_044}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c11_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c11_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c11_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c11_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c11_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c11_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c11_we),
    .f({al_ram_regmem_al_u0_do_i1_047,al_ram_regmem_al_u0_do_i1_046}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c12_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r1_c12_l (
    .a({di[48],addrw[0]}),
    .b({di[49],addrw[1]}),
    .c({di[50],addrw[2]}),
    .clk(clk),
    .d({di[51],addrw[3]}),
    .e({open_n666,we_1_al_n1}),
    .dpram_di(al_ram_regmem_al_u0_r1_c12_di),
    .dpram_mode(al_ram_regmem_al_u0_r1_c12_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c12_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c12_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c12_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c12_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c12_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c12_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c12_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c12_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c12_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c12_we),
    .f({al_ram_regmem_al_u0_do_i1_049,al_ram_regmem_al_u0_do_i1_048}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c12_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c12_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c12_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c12_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c12_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c12_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c12_we),
    .f({al_ram_regmem_al_u0_do_i1_051,al_ram_regmem_al_u0_do_i1_050}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c13_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r1_c13_l (
    .a({di[52],addrw[0]}),
    .b({di[53],addrw[1]}),
    .c({di[54],addrw[2]}),
    .clk(clk),
    .d({di[55],addrw[3]}),
    .e({open_n701,we_1_al_n1}),
    .dpram_di(al_ram_regmem_al_u0_r1_c13_di),
    .dpram_mode(al_ram_regmem_al_u0_r1_c13_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c13_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c13_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c13_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c13_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c13_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c13_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c13_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c13_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c13_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c13_we),
    .f({al_ram_regmem_al_u0_do_i1_053,al_ram_regmem_al_u0_do_i1_052}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c13_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c13_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c13_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c13_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c13_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c13_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c13_we),
    .f({al_ram_regmem_al_u0_do_i1_055,al_ram_regmem_al_u0_do_i1_054}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c14_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r1_c14_l (
    .a({di[56],addrw[0]}),
    .b({di[57],addrw[1]}),
    .c({di[58],addrw[2]}),
    .clk(clk),
    .d({di[59],addrw[3]}),
    .e({open_n736,we_1_al_n1}),
    .dpram_di(al_ram_regmem_al_u0_r1_c14_di),
    .dpram_mode(al_ram_regmem_al_u0_r1_c14_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c14_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c14_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c14_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c14_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c14_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c14_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c14_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c14_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c14_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c14_we),
    .f({al_ram_regmem_al_u0_do_i1_057,al_ram_regmem_al_u0_do_i1_056}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c14_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c14_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c14_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c14_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c14_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c14_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c14_we),
    .f({al_ram_regmem_al_u0_do_i1_059,al_ram_regmem_al_u0_do_i1_058}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c15_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r1_c15_l (
    .a({di[60],addrw[0]}),
    .b({di[61],addrw[1]}),
    .c({di[62],addrw[2]}),
    .clk(clk),
    .d({di[63],addrw[3]}),
    .e({open_n771,we_1_al_n1}),
    .dpram_di(al_ram_regmem_al_u0_r1_c15_di),
    .dpram_mode(al_ram_regmem_al_u0_r1_c15_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c15_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c15_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c15_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c15_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c15_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c15_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c15_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c15_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c15_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c15_we),
    .f({al_ram_regmem_al_u0_do_i1_061,al_ram_regmem_al_u0_do_i1_060}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c15_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c15_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c15_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c15_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c15_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c15_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c15_we),
    .f({al_ram_regmem_al_u0_do_i1_063,al_ram_regmem_al_u0_do_i1_062}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c1_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r1_c1_l (
    .a({di[4],addrw[0]}),
    .b({di[5],addrw[1]}),
    .c({di[6],addrw[2]}),
    .clk(clk),
    .d({di[7],addrw[3]}),
    .e({open_n806,we_1_al_n1}),
    .dpram_di(al_ram_regmem_al_u0_r1_c1_di),
    .dpram_mode(al_ram_regmem_al_u0_r1_c1_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c1_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c1_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c1_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c1_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c1_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c1_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c1_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c1_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c1_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c1_we),
    .f({al_ram_regmem_al_u0_do_i1_005,al_ram_regmem_al_u0_do_i1_004}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c1_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c1_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c1_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c1_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c1_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c1_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c1_we),
    .f({al_ram_regmem_al_u0_do_i1_007,al_ram_regmem_al_u0_do_i1_006}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c2_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r1_c2_l (
    .a({di[8],addrw[0]}),
    .b({di[9],addrw[1]}),
    .c({di[10],addrw[2]}),
    .clk(clk),
    .d({di[11],addrw[3]}),
    .e({open_n841,we_1_al_n1}),
    .dpram_di(al_ram_regmem_al_u0_r1_c2_di),
    .dpram_mode(al_ram_regmem_al_u0_r1_c2_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c2_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c2_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c2_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c2_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c2_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c2_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c2_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c2_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c2_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c2_we),
    .f({al_ram_regmem_al_u0_do_i1_009,al_ram_regmem_al_u0_do_i1_008}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c2_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c2_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c2_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c2_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c2_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c2_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c2_we),
    .f({al_ram_regmem_al_u0_do_i1_011,al_ram_regmem_al_u0_do_i1_010}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c3_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r1_c3_l (
    .a({di[12],addrw[0]}),
    .b({di[13],addrw[1]}),
    .c({di[14],addrw[2]}),
    .clk(clk),
    .d({di[15],addrw[3]}),
    .e({open_n876,we_1_al_n1}),
    .dpram_di(al_ram_regmem_al_u0_r1_c3_di),
    .dpram_mode(al_ram_regmem_al_u0_r1_c3_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c3_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c3_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c3_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c3_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c3_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c3_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c3_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c3_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c3_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c3_we),
    .f({al_ram_regmem_al_u0_do_i1_013,al_ram_regmem_al_u0_do_i1_012}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c3_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c3_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c3_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c3_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c3_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c3_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c3_we),
    .f({al_ram_regmem_al_u0_do_i1_015,al_ram_regmem_al_u0_do_i1_014}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c4_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r1_c4_l (
    .a({di[16],addrw[0]}),
    .b({di[17],addrw[1]}),
    .c({di[18],addrw[2]}),
    .clk(clk),
    .d({di[19],addrw[3]}),
    .e({open_n911,we_1_al_n1}),
    .dpram_di(al_ram_regmem_al_u0_r1_c4_di),
    .dpram_mode(al_ram_regmem_al_u0_r1_c4_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c4_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c4_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c4_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c4_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c4_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c4_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c4_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c4_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c4_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c4_we),
    .f({al_ram_regmem_al_u0_do_i1_017,al_ram_regmem_al_u0_do_i1_016}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c4_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c4_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c4_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c4_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c4_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c4_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c4_we),
    .f({al_ram_regmem_al_u0_do_i1_019,al_ram_regmem_al_u0_do_i1_018}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c5_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r1_c5_l (
    .a({di[20],addrw[0]}),
    .b({di[21],addrw[1]}),
    .c({di[22],addrw[2]}),
    .clk(clk),
    .d({di[23],addrw[3]}),
    .e({open_n946,we_1_al_n1}),
    .dpram_di(al_ram_regmem_al_u0_r1_c5_di),
    .dpram_mode(al_ram_regmem_al_u0_r1_c5_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c5_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c5_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c5_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c5_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c5_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c5_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c5_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c5_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c5_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c5_we),
    .f({al_ram_regmem_al_u0_do_i1_021,al_ram_regmem_al_u0_do_i1_020}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c5_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c5_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c5_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c5_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c5_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c5_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c5_we),
    .f({al_ram_regmem_al_u0_do_i1_023,al_ram_regmem_al_u0_do_i1_022}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c6_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r1_c6_l (
    .a({di[24],addrw[0]}),
    .b({di[25],addrw[1]}),
    .c({di[26],addrw[2]}),
    .clk(clk),
    .d({di[27],addrw[3]}),
    .e({open_n981,we_1_al_n1}),
    .dpram_di(al_ram_regmem_al_u0_r1_c6_di),
    .dpram_mode(al_ram_regmem_al_u0_r1_c6_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c6_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c6_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c6_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c6_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c6_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c6_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c6_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c6_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c6_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c6_we),
    .f({al_ram_regmem_al_u0_do_i1_025,al_ram_regmem_al_u0_do_i1_024}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c6_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c6_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c6_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c6_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c6_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c6_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c6_we),
    .f({al_ram_regmem_al_u0_do_i1_027,al_ram_regmem_al_u0_do_i1_026}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c7_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r1_c7_l (
    .a({di[28],addrw[0]}),
    .b({di[29],addrw[1]}),
    .c({di[30],addrw[2]}),
    .clk(clk),
    .d({di[31],addrw[3]}),
    .e({open_n1016,we_1_al_n1}),
    .dpram_di(al_ram_regmem_al_u0_r1_c7_di),
    .dpram_mode(al_ram_regmem_al_u0_r1_c7_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c7_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c7_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c7_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c7_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c7_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c7_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c7_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c7_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c7_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c7_we),
    .f({al_ram_regmem_al_u0_do_i1_029,al_ram_regmem_al_u0_do_i1_028}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c7_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c7_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c7_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c7_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c7_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c7_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c7_we),
    .f({al_ram_regmem_al_u0_do_i1_031,al_ram_regmem_al_u0_do_i1_030}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c8_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r1_c8_l (
    .a({di[32],addrw[0]}),
    .b({di[33],addrw[1]}),
    .c({di[34],addrw[2]}),
    .clk(clk),
    .d({di[35],addrw[3]}),
    .e({open_n1051,we_1_al_n1}),
    .dpram_di(al_ram_regmem_al_u0_r1_c8_di),
    .dpram_mode(al_ram_regmem_al_u0_r1_c8_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c8_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c8_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c8_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c8_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c8_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c8_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c8_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c8_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c8_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c8_we),
    .f({al_ram_regmem_al_u0_do_i1_033,al_ram_regmem_al_u0_do_i1_032}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c8_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c8_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c8_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c8_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c8_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c8_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c8_we),
    .f({al_ram_regmem_al_u0_do_i1_035,al_ram_regmem_al_u0_do_i1_034}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c9_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_al_u0_r1_c9_l (
    .a({di[36],addrw[0]}),
    .b({di[37],addrw[1]}),
    .c({di[38],addrw[2]}),
    .clk(clk),
    .d({di[39],addrw[3]}),
    .e({open_n1086,we_1_al_n1}),
    .dpram_di(al_ram_regmem_al_u0_r1_c9_di),
    .dpram_mode(al_ram_regmem_al_u0_r1_c9_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c9_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c9_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c9_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c9_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c9_m0 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c9_di[1:0]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c9_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c9_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c9_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c9_we),
    .f({al_ram_regmem_al_u0_do_i1_037,al_ram_regmem_al_u0_do_i1_036}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_al_u0_r1_c9_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_al_u0_r1_c9_m1 (
    .a({addrb[0],addrb[0]}),
    .b({addrb[1],addrb[1]}),
    .c({addrb[2],addrb[2]}),
    .d({addrb[3],addrb[3]}),
    .dpram_di(al_ram_regmem_al_u0_r1_c9_di[3:2]),
    .dpram_mode(al_ram_regmem_al_u0_r1_c9_mode),
    .dpram_waddr(al_ram_regmem_al_u0_r1_c9_waddr),
    .dpram_wclk(al_ram_regmem_al_u0_r1_c9_wclk),
    .dpram_we(al_ram_regmem_al_u0_r1_c9_we),
    .f({al_ram_regmem_al_u0_do_i1_039,al_ram_regmem_al_u0_do_i1_038}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r0_c0_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r0_c0_l (
    .a({di[0],addrw[0]}),
    .b({di[1],addrw[1]}),
    .c({di[2],addrw[2]}),
    .clk(clk),
    .d({di[3],addrw[3]}),
    .e({open_n1121,we_0_al_n0}),
    .dpram_di(al_ram_regmem_r0_c0_di),
    .dpram_mode(al_ram_regmem_r0_c0_mode),
    .dpram_waddr(al_ram_regmem_r0_c0_waddr),
    .dpram_wclk(al_ram_regmem_r0_c0_wclk),
    .dpram_we(al_ram_regmem_r0_c0_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c0_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c0_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c0_di[1:0]),
    .dpram_mode(al_ram_regmem_r0_c0_mode),
    .dpram_waddr(al_ram_regmem_r0_c0_waddr),
    .dpram_wclk(al_ram_regmem_r0_c0_wclk),
    .dpram_we(al_ram_regmem_r0_c0_we),
    .f({al_ram_regmem_do_i0_001,al_ram_regmem_do_i0_000}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c0_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c0_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c0_di[3:2]),
    .dpram_mode(al_ram_regmem_r0_c0_mode),
    .dpram_waddr(al_ram_regmem_r0_c0_waddr),
    .dpram_wclk(al_ram_regmem_r0_c0_wclk),
    .dpram_we(al_ram_regmem_r0_c0_we),
    .f({al_ram_regmem_do_i0_003,al_ram_regmem_do_i0_002}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r0_c10_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r0_c10_l (
    .a({di[40],addrw[0]}),
    .b({di[41],addrw[1]}),
    .c({di[42],addrw[2]}),
    .clk(clk),
    .d({di[43],addrw[3]}),
    .e({open_n1156,we_0_al_n0}),
    .dpram_di(al_ram_regmem_r0_c10_di),
    .dpram_mode(al_ram_regmem_r0_c10_mode),
    .dpram_waddr(al_ram_regmem_r0_c10_waddr),
    .dpram_wclk(al_ram_regmem_r0_c10_wclk),
    .dpram_we(al_ram_regmem_r0_c10_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c10_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c10_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c10_di[1:0]),
    .dpram_mode(al_ram_regmem_r0_c10_mode),
    .dpram_waddr(al_ram_regmem_r0_c10_waddr),
    .dpram_wclk(al_ram_regmem_r0_c10_wclk),
    .dpram_we(al_ram_regmem_r0_c10_we),
    .f({al_ram_regmem_do_i0_041,al_ram_regmem_do_i0_040}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c10_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c10_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c10_di[3:2]),
    .dpram_mode(al_ram_regmem_r0_c10_mode),
    .dpram_waddr(al_ram_regmem_r0_c10_waddr),
    .dpram_wclk(al_ram_regmem_r0_c10_wclk),
    .dpram_we(al_ram_regmem_r0_c10_we),
    .f({al_ram_regmem_do_i0_043,al_ram_regmem_do_i0_042}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r0_c11_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r0_c11_l (
    .a({di[44],addrw[0]}),
    .b({di[45],addrw[1]}),
    .c({di[46],addrw[2]}),
    .clk(clk),
    .d({di[47],addrw[3]}),
    .e({open_n1191,we_0_al_n0}),
    .dpram_di(al_ram_regmem_r0_c11_di),
    .dpram_mode(al_ram_regmem_r0_c11_mode),
    .dpram_waddr(al_ram_regmem_r0_c11_waddr),
    .dpram_wclk(al_ram_regmem_r0_c11_wclk),
    .dpram_we(al_ram_regmem_r0_c11_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c11_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c11_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c11_di[1:0]),
    .dpram_mode(al_ram_regmem_r0_c11_mode),
    .dpram_waddr(al_ram_regmem_r0_c11_waddr),
    .dpram_wclk(al_ram_regmem_r0_c11_wclk),
    .dpram_we(al_ram_regmem_r0_c11_we),
    .f({al_ram_regmem_do_i0_045,al_ram_regmem_do_i0_044}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c11_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c11_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c11_di[3:2]),
    .dpram_mode(al_ram_regmem_r0_c11_mode),
    .dpram_waddr(al_ram_regmem_r0_c11_waddr),
    .dpram_wclk(al_ram_regmem_r0_c11_wclk),
    .dpram_we(al_ram_regmem_r0_c11_we),
    .f({al_ram_regmem_do_i0_047,al_ram_regmem_do_i0_046}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r0_c12_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r0_c12_l (
    .a({di[48],addrw[0]}),
    .b({di[49],addrw[1]}),
    .c({di[50],addrw[2]}),
    .clk(clk),
    .d({di[51],addrw[3]}),
    .e({open_n1226,we_0_al_n0}),
    .dpram_di(al_ram_regmem_r0_c12_di),
    .dpram_mode(al_ram_regmem_r0_c12_mode),
    .dpram_waddr(al_ram_regmem_r0_c12_waddr),
    .dpram_wclk(al_ram_regmem_r0_c12_wclk),
    .dpram_we(al_ram_regmem_r0_c12_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c12_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c12_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c12_di[1:0]),
    .dpram_mode(al_ram_regmem_r0_c12_mode),
    .dpram_waddr(al_ram_regmem_r0_c12_waddr),
    .dpram_wclk(al_ram_regmem_r0_c12_wclk),
    .dpram_we(al_ram_regmem_r0_c12_we),
    .f({al_ram_regmem_do_i0_049,al_ram_regmem_do_i0_048}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c12_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c12_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c12_di[3:2]),
    .dpram_mode(al_ram_regmem_r0_c12_mode),
    .dpram_waddr(al_ram_regmem_r0_c12_waddr),
    .dpram_wclk(al_ram_regmem_r0_c12_wclk),
    .dpram_we(al_ram_regmem_r0_c12_we),
    .f({al_ram_regmem_do_i0_051,al_ram_regmem_do_i0_050}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r0_c13_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r0_c13_l (
    .a({di[52],addrw[0]}),
    .b({di[53],addrw[1]}),
    .c({di[54],addrw[2]}),
    .clk(clk),
    .d({di[55],addrw[3]}),
    .e({open_n1261,we_0_al_n0}),
    .dpram_di(al_ram_regmem_r0_c13_di),
    .dpram_mode(al_ram_regmem_r0_c13_mode),
    .dpram_waddr(al_ram_regmem_r0_c13_waddr),
    .dpram_wclk(al_ram_regmem_r0_c13_wclk),
    .dpram_we(al_ram_regmem_r0_c13_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c13_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c13_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c13_di[1:0]),
    .dpram_mode(al_ram_regmem_r0_c13_mode),
    .dpram_waddr(al_ram_regmem_r0_c13_waddr),
    .dpram_wclk(al_ram_regmem_r0_c13_wclk),
    .dpram_we(al_ram_regmem_r0_c13_we),
    .f({al_ram_regmem_do_i0_053,al_ram_regmem_do_i0_052}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c13_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c13_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c13_di[3:2]),
    .dpram_mode(al_ram_regmem_r0_c13_mode),
    .dpram_waddr(al_ram_regmem_r0_c13_waddr),
    .dpram_wclk(al_ram_regmem_r0_c13_wclk),
    .dpram_we(al_ram_regmem_r0_c13_we),
    .f({al_ram_regmem_do_i0_055,al_ram_regmem_do_i0_054}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r0_c14_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r0_c14_l (
    .a({di[56],addrw[0]}),
    .b({di[57],addrw[1]}),
    .c({di[58],addrw[2]}),
    .clk(clk),
    .d({di[59],addrw[3]}),
    .e({open_n1296,we_0_al_n0}),
    .dpram_di(al_ram_regmem_r0_c14_di),
    .dpram_mode(al_ram_regmem_r0_c14_mode),
    .dpram_waddr(al_ram_regmem_r0_c14_waddr),
    .dpram_wclk(al_ram_regmem_r0_c14_wclk),
    .dpram_we(al_ram_regmem_r0_c14_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c14_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c14_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c14_di[1:0]),
    .dpram_mode(al_ram_regmem_r0_c14_mode),
    .dpram_waddr(al_ram_regmem_r0_c14_waddr),
    .dpram_wclk(al_ram_regmem_r0_c14_wclk),
    .dpram_we(al_ram_regmem_r0_c14_we),
    .f({al_ram_regmem_do_i0_057,al_ram_regmem_do_i0_056}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c14_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c14_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c14_di[3:2]),
    .dpram_mode(al_ram_regmem_r0_c14_mode),
    .dpram_waddr(al_ram_regmem_r0_c14_waddr),
    .dpram_wclk(al_ram_regmem_r0_c14_wclk),
    .dpram_we(al_ram_regmem_r0_c14_we),
    .f({al_ram_regmem_do_i0_059,al_ram_regmem_do_i0_058}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r0_c15_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r0_c15_l (
    .a({di[60],addrw[0]}),
    .b({di[61],addrw[1]}),
    .c({di[62],addrw[2]}),
    .clk(clk),
    .d({di[63],addrw[3]}),
    .e({open_n1331,we_0_al_n0}),
    .dpram_di(al_ram_regmem_r0_c15_di),
    .dpram_mode(al_ram_regmem_r0_c15_mode),
    .dpram_waddr(al_ram_regmem_r0_c15_waddr),
    .dpram_wclk(al_ram_regmem_r0_c15_wclk),
    .dpram_we(al_ram_regmem_r0_c15_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c15_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c15_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c15_di[1:0]),
    .dpram_mode(al_ram_regmem_r0_c15_mode),
    .dpram_waddr(al_ram_regmem_r0_c15_waddr),
    .dpram_wclk(al_ram_regmem_r0_c15_wclk),
    .dpram_we(al_ram_regmem_r0_c15_we),
    .f({al_ram_regmem_do_i0_061,al_ram_regmem_do_i0_060}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c15_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c15_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c15_di[3:2]),
    .dpram_mode(al_ram_regmem_r0_c15_mode),
    .dpram_waddr(al_ram_regmem_r0_c15_waddr),
    .dpram_wclk(al_ram_regmem_r0_c15_wclk),
    .dpram_we(al_ram_regmem_r0_c15_we),
    .f({al_ram_regmem_do_i0_063,al_ram_regmem_do_i0_062}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r0_c1_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r0_c1_l (
    .a({di[4],addrw[0]}),
    .b({di[5],addrw[1]}),
    .c({di[6],addrw[2]}),
    .clk(clk),
    .d({di[7],addrw[3]}),
    .e({open_n1366,we_0_al_n0}),
    .dpram_di(al_ram_regmem_r0_c1_di),
    .dpram_mode(al_ram_regmem_r0_c1_mode),
    .dpram_waddr(al_ram_regmem_r0_c1_waddr),
    .dpram_wclk(al_ram_regmem_r0_c1_wclk),
    .dpram_we(al_ram_regmem_r0_c1_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c1_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c1_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c1_di[1:0]),
    .dpram_mode(al_ram_regmem_r0_c1_mode),
    .dpram_waddr(al_ram_regmem_r0_c1_waddr),
    .dpram_wclk(al_ram_regmem_r0_c1_wclk),
    .dpram_we(al_ram_regmem_r0_c1_we),
    .f({al_ram_regmem_do_i0_005,al_ram_regmem_do_i0_004}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c1_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c1_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c1_di[3:2]),
    .dpram_mode(al_ram_regmem_r0_c1_mode),
    .dpram_waddr(al_ram_regmem_r0_c1_waddr),
    .dpram_wclk(al_ram_regmem_r0_c1_wclk),
    .dpram_we(al_ram_regmem_r0_c1_we),
    .f({al_ram_regmem_do_i0_007,al_ram_regmem_do_i0_006}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r0_c2_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r0_c2_l (
    .a({di[8],addrw[0]}),
    .b({di[9],addrw[1]}),
    .c({di[10],addrw[2]}),
    .clk(clk),
    .d({di[11],addrw[3]}),
    .e({open_n1401,we_0_al_n0}),
    .dpram_di(al_ram_regmem_r0_c2_di),
    .dpram_mode(al_ram_regmem_r0_c2_mode),
    .dpram_waddr(al_ram_regmem_r0_c2_waddr),
    .dpram_wclk(al_ram_regmem_r0_c2_wclk),
    .dpram_we(al_ram_regmem_r0_c2_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c2_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c2_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c2_di[1:0]),
    .dpram_mode(al_ram_regmem_r0_c2_mode),
    .dpram_waddr(al_ram_regmem_r0_c2_waddr),
    .dpram_wclk(al_ram_regmem_r0_c2_wclk),
    .dpram_we(al_ram_regmem_r0_c2_we),
    .f({al_ram_regmem_do_i0_009,al_ram_regmem_do_i0_008}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c2_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c2_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c2_di[3:2]),
    .dpram_mode(al_ram_regmem_r0_c2_mode),
    .dpram_waddr(al_ram_regmem_r0_c2_waddr),
    .dpram_wclk(al_ram_regmem_r0_c2_wclk),
    .dpram_we(al_ram_regmem_r0_c2_we),
    .f({al_ram_regmem_do_i0_011,al_ram_regmem_do_i0_010}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r0_c3_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r0_c3_l (
    .a({di[12],addrw[0]}),
    .b({di[13],addrw[1]}),
    .c({di[14],addrw[2]}),
    .clk(clk),
    .d({di[15],addrw[3]}),
    .e({open_n1436,we_0_al_n0}),
    .dpram_di(al_ram_regmem_r0_c3_di),
    .dpram_mode(al_ram_regmem_r0_c3_mode),
    .dpram_waddr(al_ram_regmem_r0_c3_waddr),
    .dpram_wclk(al_ram_regmem_r0_c3_wclk),
    .dpram_we(al_ram_regmem_r0_c3_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c3_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c3_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c3_di[1:0]),
    .dpram_mode(al_ram_regmem_r0_c3_mode),
    .dpram_waddr(al_ram_regmem_r0_c3_waddr),
    .dpram_wclk(al_ram_regmem_r0_c3_wclk),
    .dpram_we(al_ram_regmem_r0_c3_we),
    .f({al_ram_regmem_do_i0_013,al_ram_regmem_do_i0_012}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c3_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c3_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c3_di[3:2]),
    .dpram_mode(al_ram_regmem_r0_c3_mode),
    .dpram_waddr(al_ram_regmem_r0_c3_waddr),
    .dpram_wclk(al_ram_regmem_r0_c3_wclk),
    .dpram_we(al_ram_regmem_r0_c3_we),
    .f({al_ram_regmem_do_i0_015,al_ram_regmem_do_i0_014}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r0_c4_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r0_c4_l (
    .a({di[16],addrw[0]}),
    .b({di[17],addrw[1]}),
    .c({di[18],addrw[2]}),
    .clk(clk),
    .d({di[19],addrw[3]}),
    .e({open_n1471,we_0_al_n0}),
    .dpram_di(al_ram_regmem_r0_c4_di),
    .dpram_mode(al_ram_regmem_r0_c4_mode),
    .dpram_waddr(al_ram_regmem_r0_c4_waddr),
    .dpram_wclk(al_ram_regmem_r0_c4_wclk),
    .dpram_we(al_ram_regmem_r0_c4_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c4_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c4_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c4_di[1:0]),
    .dpram_mode(al_ram_regmem_r0_c4_mode),
    .dpram_waddr(al_ram_regmem_r0_c4_waddr),
    .dpram_wclk(al_ram_regmem_r0_c4_wclk),
    .dpram_we(al_ram_regmem_r0_c4_we),
    .f({al_ram_regmem_do_i0_017,al_ram_regmem_do_i0_016}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c4_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c4_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c4_di[3:2]),
    .dpram_mode(al_ram_regmem_r0_c4_mode),
    .dpram_waddr(al_ram_regmem_r0_c4_waddr),
    .dpram_wclk(al_ram_regmem_r0_c4_wclk),
    .dpram_we(al_ram_regmem_r0_c4_we),
    .f({al_ram_regmem_do_i0_019,al_ram_regmem_do_i0_018}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r0_c5_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r0_c5_l (
    .a({di[20],addrw[0]}),
    .b({di[21],addrw[1]}),
    .c({di[22],addrw[2]}),
    .clk(clk),
    .d({di[23],addrw[3]}),
    .e({open_n1506,we_0_al_n0}),
    .dpram_di(al_ram_regmem_r0_c5_di),
    .dpram_mode(al_ram_regmem_r0_c5_mode),
    .dpram_waddr(al_ram_regmem_r0_c5_waddr),
    .dpram_wclk(al_ram_regmem_r0_c5_wclk),
    .dpram_we(al_ram_regmem_r0_c5_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c5_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c5_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c5_di[1:0]),
    .dpram_mode(al_ram_regmem_r0_c5_mode),
    .dpram_waddr(al_ram_regmem_r0_c5_waddr),
    .dpram_wclk(al_ram_regmem_r0_c5_wclk),
    .dpram_we(al_ram_regmem_r0_c5_we),
    .f({al_ram_regmem_do_i0_021,al_ram_regmem_do_i0_020}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c5_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c5_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c5_di[3:2]),
    .dpram_mode(al_ram_regmem_r0_c5_mode),
    .dpram_waddr(al_ram_regmem_r0_c5_waddr),
    .dpram_wclk(al_ram_regmem_r0_c5_wclk),
    .dpram_we(al_ram_regmem_r0_c5_we),
    .f({al_ram_regmem_do_i0_023,al_ram_regmem_do_i0_022}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r0_c6_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r0_c6_l (
    .a({di[24],addrw[0]}),
    .b({di[25],addrw[1]}),
    .c({di[26],addrw[2]}),
    .clk(clk),
    .d({di[27],addrw[3]}),
    .e({open_n1541,we_0_al_n0}),
    .dpram_di(al_ram_regmem_r0_c6_di),
    .dpram_mode(al_ram_regmem_r0_c6_mode),
    .dpram_waddr(al_ram_regmem_r0_c6_waddr),
    .dpram_wclk(al_ram_regmem_r0_c6_wclk),
    .dpram_we(al_ram_regmem_r0_c6_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c6_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c6_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c6_di[1:0]),
    .dpram_mode(al_ram_regmem_r0_c6_mode),
    .dpram_waddr(al_ram_regmem_r0_c6_waddr),
    .dpram_wclk(al_ram_regmem_r0_c6_wclk),
    .dpram_we(al_ram_regmem_r0_c6_we),
    .f({al_ram_regmem_do_i0_025,al_ram_regmem_do_i0_024}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c6_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c6_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c6_di[3:2]),
    .dpram_mode(al_ram_regmem_r0_c6_mode),
    .dpram_waddr(al_ram_regmem_r0_c6_waddr),
    .dpram_wclk(al_ram_regmem_r0_c6_wclk),
    .dpram_we(al_ram_regmem_r0_c6_we),
    .f({al_ram_regmem_do_i0_027,al_ram_regmem_do_i0_026}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r0_c7_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r0_c7_l (
    .a({di[28],addrw[0]}),
    .b({di[29],addrw[1]}),
    .c({di[30],addrw[2]}),
    .clk(clk),
    .d({di[31],addrw[3]}),
    .e({open_n1576,we_0_al_n0}),
    .dpram_di(al_ram_regmem_r0_c7_di),
    .dpram_mode(al_ram_regmem_r0_c7_mode),
    .dpram_waddr(al_ram_regmem_r0_c7_waddr),
    .dpram_wclk(al_ram_regmem_r0_c7_wclk),
    .dpram_we(al_ram_regmem_r0_c7_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c7_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c7_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c7_di[1:0]),
    .dpram_mode(al_ram_regmem_r0_c7_mode),
    .dpram_waddr(al_ram_regmem_r0_c7_waddr),
    .dpram_wclk(al_ram_regmem_r0_c7_wclk),
    .dpram_we(al_ram_regmem_r0_c7_we),
    .f({al_ram_regmem_do_i0_029,al_ram_regmem_do_i0_028}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c7_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c7_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c7_di[3:2]),
    .dpram_mode(al_ram_regmem_r0_c7_mode),
    .dpram_waddr(al_ram_regmem_r0_c7_waddr),
    .dpram_wclk(al_ram_regmem_r0_c7_wclk),
    .dpram_we(al_ram_regmem_r0_c7_we),
    .f({al_ram_regmem_do_i0_031,al_ram_regmem_do_i0_030}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r0_c8_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r0_c8_l (
    .a({di[32],addrw[0]}),
    .b({di[33],addrw[1]}),
    .c({di[34],addrw[2]}),
    .clk(clk),
    .d({di[35],addrw[3]}),
    .e({open_n1611,we_0_al_n0}),
    .dpram_di(al_ram_regmem_r0_c8_di),
    .dpram_mode(al_ram_regmem_r0_c8_mode),
    .dpram_waddr(al_ram_regmem_r0_c8_waddr),
    .dpram_wclk(al_ram_regmem_r0_c8_wclk),
    .dpram_we(al_ram_regmem_r0_c8_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c8_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c8_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c8_di[1:0]),
    .dpram_mode(al_ram_regmem_r0_c8_mode),
    .dpram_waddr(al_ram_regmem_r0_c8_waddr),
    .dpram_wclk(al_ram_regmem_r0_c8_wclk),
    .dpram_we(al_ram_regmem_r0_c8_we),
    .f({al_ram_regmem_do_i0_033,al_ram_regmem_do_i0_032}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c8_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c8_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c8_di[3:2]),
    .dpram_mode(al_ram_regmem_r0_c8_mode),
    .dpram_waddr(al_ram_regmem_r0_c8_waddr),
    .dpram_wclk(al_ram_regmem_r0_c8_wclk),
    .dpram_we(al_ram_regmem_r0_c8_we),
    .f({al_ram_regmem_do_i0_035,al_ram_regmem_do_i0_034}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r0_c9_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r0_c9_l (
    .a({di[36],addrw[0]}),
    .b({di[37],addrw[1]}),
    .c({di[38],addrw[2]}),
    .clk(clk),
    .d({di[39],addrw[3]}),
    .e({open_n1646,we_0_al_n0}),
    .dpram_di(al_ram_regmem_r0_c9_di),
    .dpram_mode(al_ram_regmem_r0_c9_mode),
    .dpram_waddr(al_ram_regmem_r0_c9_waddr),
    .dpram_wclk(al_ram_regmem_r0_c9_wclk),
    .dpram_we(al_ram_regmem_r0_c9_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c9_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c9_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c9_di[1:0]),
    .dpram_mode(al_ram_regmem_r0_c9_mode),
    .dpram_waddr(al_ram_regmem_r0_c9_waddr),
    .dpram_wclk(al_ram_regmem_r0_c9_wclk),
    .dpram_we(al_ram_regmem_r0_c9_we),
    .f({al_ram_regmem_do_i0_037,al_ram_regmem_do_i0_036}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r0_c9_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r0_c9_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r0_c9_di[3:2]),
    .dpram_mode(al_ram_regmem_r0_c9_mode),
    .dpram_waddr(al_ram_regmem_r0_c9_waddr),
    .dpram_wclk(al_ram_regmem_r0_c9_wclk),
    .dpram_we(al_ram_regmem_r0_c9_we),
    .f({al_ram_regmem_do_i0_039,al_ram_regmem_do_i0_038}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r1_c0_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r1_c0_l (
    .a({di[0],addrw[0]}),
    .b({di[1],addrw[1]}),
    .c({di[2],addrw[2]}),
    .clk(clk),
    .d({di[3],addrw[3]}),
    .e({open_n1681,we_1_al_n1}),
    .dpram_di(al_ram_regmem_r1_c0_di),
    .dpram_mode(al_ram_regmem_r1_c0_mode),
    .dpram_waddr(al_ram_regmem_r1_c0_waddr),
    .dpram_wclk(al_ram_regmem_r1_c0_wclk),
    .dpram_we(al_ram_regmem_r1_c0_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c0_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c0_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c0_di[1:0]),
    .dpram_mode(al_ram_regmem_r1_c0_mode),
    .dpram_waddr(al_ram_regmem_r1_c0_waddr),
    .dpram_wclk(al_ram_regmem_r1_c0_wclk),
    .dpram_we(al_ram_regmem_r1_c0_we),
    .f({al_ram_regmem_do_i1_001,al_ram_regmem_do_i1_000}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c0_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c0_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c0_di[3:2]),
    .dpram_mode(al_ram_regmem_r1_c0_mode),
    .dpram_waddr(al_ram_regmem_r1_c0_waddr),
    .dpram_wclk(al_ram_regmem_r1_c0_wclk),
    .dpram_we(al_ram_regmem_r1_c0_we),
    .f({al_ram_regmem_do_i1_003,al_ram_regmem_do_i1_002}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r1_c10_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r1_c10_l (
    .a({di[40],addrw[0]}),
    .b({di[41],addrw[1]}),
    .c({di[42],addrw[2]}),
    .clk(clk),
    .d({di[43],addrw[3]}),
    .e({open_n1716,we_1_al_n1}),
    .dpram_di(al_ram_regmem_r1_c10_di),
    .dpram_mode(al_ram_regmem_r1_c10_mode),
    .dpram_waddr(al_ram_regmem_r1_c10_waddr),
    .dpram_wclk(al_ram_regmem_r1_c10_wclk),
    .dpram_we(al_ram_regmem_r1_c10_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c10_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c10_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c10_di[1:0]),
    .dpram_mode(al_ram_regmem_r1_c10_mode),
    .dpram_waddr(al_ram_regmem_r1_c10_waddr),
    .dpram_wclk(al_ram_regmem_r1_c10_wclk),
    .dpram_we(al_ram_regmem_r1_c10_we),
    .f({al_ram_regmem_do_i1_041,al_ram_regmem_do_i1_040}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c10_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c10_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c10_di[3:2]),
    .dpram_mode(al_ram_regmem_r1_c10_mode),
    .dpram_waddr(al_ram_regmem_r1_c10_waddr),
    .dpram_wclk(al_ram_regmem_r1_c10_wclk),
    .dpram_we(al_ram_regmem_r1_c10_we),
    .f({al_ram_regmem_do_i1_043,al_ram_regmem_do_i1_042}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r1_c11_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r1_c11_l (
    .a({di[44],addrw[0]}),
    .b({di[45],addrw[1]}),
    .c({di[46],addrw[2]}),
    .clk(clk),
    .d({di[47],addrw[3]}),
    .e({open_n1751,we_1_al_n1}),
    .dpram_di(al_ram_regmem_r1_c11_di),
    .dpram_mode(al_ram_regmem_r1_c11_mode),
    .dpram_waddr(al_ram_regmem_r1_c11_waddr),
    .dpram_wclk(al_ram_regmem_r1_c11_wclk),
    .dpram_we(al_ram_regmem_r1_c11_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c11_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c11_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c11_di[1:0]),
    .dpram_mode(al_ram_regmem_r1_c11_mode),
    .dpram_waddr(al_ram_regmem_r1_c11_waddr),
    .dpram_wclk(al_ram_regmem_r1_c11_wclk),
    .dpram_we(al_ram_regmem_r1_c11_we),
    .f({al_ram_regmem_do_i1_045,al_ram_regmem_do_i1_044}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c11_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c11_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c11_di[3:2]),
    .dpram_mode(al_ram_regmem_r1_c11_mode),
    .dpram_waddr(al_ram_regmem_r1_c11_waddr),
    .dpram_wclk(al_ram_regmem_r1_c11_wclk),
    .dpram_we(al_ram_regmem_r1_c11_we),
    .f({al_ram_regmem_do_i1_047,al_ram_regmem_do_i1_046}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r1_c12_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r1_c12_l (
    .a({di[48],addrw[0]}),
    .b({di[49],addrw[1]}),
    .c({di[50],addrw[2]}),
    .clk(clk),
    .d({di[51],addrw[3]}),
    .e({open_n1786,we_1_al_n1}),
    .dpram_di(al_ram_regmem_r1_c12_di),
    .dpram_mode(al_ram_regmem_r1_c12_mode),
    .dpram_waddr(al_ram_regmem_r1_c12_waddr),
    .dpram_wclk(al_ram_regmem_r1_c12_wclk),
    .dpram_we(al_ram_regmem_r1_c12_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c12_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c12_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c12_di[1:0]),
    .dpram_mode(al_ram_regmem_r1_c12_mode),
    .dpram_waddr(al_ram_regmem_r1_c12_waddr),
    .dpram_wclk(al_ram_regmem_r1_c12_wclk),
    .dpram_we(al_ram_regmem_r1_c12_we),
    .f({al_ram_regmem_do_i1_049,al_ram_regmem_do_i1_048}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c12_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c12_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c12_di[3:2]),
    .dpram_mode(al_ram_regmem_r1_c12_mode),
    .dpram_waddr(al_ram_regmem_r1_c12_waddr),
    .dpram_wclk(al_ram_regmem_r1_c12_wclk),
    .dpram_we(al_ram_regmem_r1_c12_we),
    .f({al_ram_regmem_do_i1_051,al_ram_regmem_do_i1_050}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r1_c13_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r1_c13_l (
    .a({di[52],addrw[0]}),
    .b({di[53],addrw[1]}),
    .c({di[54],addrw[2]}),
    .clk(clk),
    .d({di[55],addrw[3]}),
    .e({open_n1821,we_1_al_n1}),
    .dpram_di(al_ram_regmem_r1_c13_di),
    .dpram_mode(al_ram_regmem_r1_c13_mode),
    .dpram_waddr(al_ram_regmem_r1_c13_waddr),
    .dpram_wclk(al_ram_regmem_r1_c13_wclk),
    .dpram_we(al_ram_regmem_r1_c13_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c13_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c13_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c13_di[1:0]),
    .dpram_mode(al_ram_regmem_r1_c13_mode),
    .dpram_waddr(al_ram_regmem_r1_c13_waddr),
    .dpram_wclk(al_ram_regmem_r1_c13_wclk),
    .dpram_we(al_ram_regmem_r1_c13_we),
    .f({al_ram_regmem_do_i1_053,al_ram_regmem_do_i1_052}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c13_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c13_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c13_di[3:2]),
    .dpram_mode(al_ram_regmem_r1_c13_mode),
    .dpram_waddr(al_ram_regmem_r1_c13_waddr),
    .dpram_wclk(al_ram_regmem_r1_c13_wclk),
    .dpram_we(al_ram_regmem_r1_c13_we),
    .f({al_ram_regmem_do_i1_055,al_ram_regmem_do_i1_054}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r1_c14_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r1_c14_l (
    .a({di[56],addrw[0]}),
    .b({di[57],addrw[1]}),
    .c({di[58],addrw[2]}),
    .clk(clk),
    .d({di[59],addrw[3]}),
    .e({open_n1856,we_1_al_n1}),
    .dpram_di(al_ram_regmem_r1_c14_di),
    .dpram_mode(al_ram_regmem_r1_c14_mode),
    .dpram_waddr(al_ram_regmem_r1_c14_waddr),
    .dpram_wclk(al_ram_regmem_r1_c14_wclk),
    .dpram_we(al_ram_regmem_r1_c14_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c14_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c14_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c14_di[1:0]),
    .dpram_mode(al_ram_regmem_r1_c14_mode),
    .dpram_waddr(al_ram_regmem_r1_c14_waddr),
    .dpram_wclk(al_ram_regmem_r1_c14_wclk),
    .dpram_we(al_ram_regmem_r1_c14_we),
    .f({al_ram_regmem_do_i1_057,al_ram_regmem_do_i1_056}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c14_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c14_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c14_di[3:2]),
    .dpram_mode(al_ram_regmem_r1_c14_mode),
    .dpram_waddr(al_ram_regmem_r1_c14_waddr),
    .dpram_wclk(al_ram_regmem_r1_c14_wclk),
    .dpram_we(al_ram_regmem_r1_c14_we),
    .f({al_ram_regmem_do_i1_059,al_ram_regmem_do_i1_058}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r1_c15_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r1_c15_l (
    .a({di[60],addrw[0]}),
    .b({di[61],addrw[1]}),
    .c({di[62],addrw[2]}),
    .clk(clk),
    .d({di[63],addrw[3]}),
    .e({open_n1891,we_1_al_n1}),
    .dpram_di(al_ram_regmem_r1_c15_di),
    .dpram_mode(al_ram_regmem_r1_c15_mode),
    .dpram_waddr(al_ram_regmem_r1_c15_waddr),
    .dpram_wclk(al_ram_regmem_r1_c15_wclk),
    .dpram_we(al_ram_regmem_r1_c15_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c15_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c15_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c15_di[1:0]),
    .dpram_mode(al_ram_regmem_r1_c15_mode),
    .dpram_waddr(al_ram_regmem_r1_c15_waddr),
    .dpram_wclk(al_ram_regmem_r1_c15_wclk),
    .dpram_we(al_ram_regmem_r1_c15_we),
    .f({al_ram_regmem_do_i1_061,al_ram_regmem_do_i1_060}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c15_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c15_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c15_di[3:2]),
    .dpram_mode(al_ram_regmem_r1_c15_mode),
    .dpram_waddr(al_ram_regmem_r1_c15_waddr),
    .dpram_wclk(al_ram_regmem_r1_c15_wclk),
    .dpram_we(al_ram_regmem_r1_c15_we),
    .f({al_ram_regmem_do_i1_063,al_ram_regmem_do_i1_062}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r1_c1_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r1_c1_l (
    .a({di[4],addrw[0]}),
    .b({di[5],addrw[1]}),
    .c({di[6],addrw[2]}),
    .clk(clk),
    .d({di[7],addrw[3]}),
    .e({open_n1926,we_1_al_n1}),
    .dpram_di(al_ram_regmem_r1_c1_di),
    .dpram_mode(al_ram_regmem_r1_c1_mode),
    .dpram_waddr(al_ram_regmem_r1_c1_waddr),
    .dpram_wclk(al_ram_regmem_r1_c1_wclk),
    .dpram_we(al_ram_regmem_r1_c1_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c1_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c1_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c1_di[1:0]),
    .dpram_mode(al_ram_regmem_r1_c1_mode),
    .dpram_waddr(al_ram_regmem_r1_c1_waddr),
    .dpram_wclk(al_ram_regmem_r1_c1_wclk),
    .dpram_we(al_ram_regmem_r1_c1_we),
    .f({al_ram_regmem_do_i1_005,al_ram_regmem_do_i1_004}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c1_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c1_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c1_di[3:2]),
    .dpram_mode(al_ram_regmem_r1_c1_mode),
    .dpram_waddr(al_ram_regmem_r1_c1_waddr),
    .dpram_wclk(al_ram_regmem_r1_c1_wclk),
    .dpram_we(al_ram_regmem_r1_c1_we),
    .f({al_ram_regmem_do_i1_007,al_ram_regmem_do_i1_006}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r1_c2_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r1_c2_l (
    .a({di[8],addrw[0]}),
    .b({di[9],addrw[1]}),
    .c({di[10],addrw[2]}),
    .clk(clk),
    .d({di[11],addrw[3]}),
    .e({open_n1961,we_1_al_n1}),
    .dpram_di(al_ram_regmem_r1_c2_di),
    .dpram_mode(al_ram_regmem_r1_c2_mode),
    .dpram_waddr(al_ram_regmem_r1_c2_waddr),
    .dpram_wclk(al_ram_regmem_r1_c2_wclk),
    .dpram_we(al_ram_regmem_r1_c2_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c2_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c2_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c2_di[1:0]),
    .dpram_mode(al_ram_regmem_r1_c2_mode),
    .dpram_waddr(al_ram_regmem_r1_c2_waddr),
    .dpram_wclk(al_ram_regmem_r1_c2_wclk),
    .dpram_we(al_ram_regmem_r1_c2_we),
    .f({al_ram_regmem_do_i1_009,al_ram_regmem_do_i1_008}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c2_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c2_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c2_di[3:2]),
    .dpram_mode(al_ram_regmem_r1_c2_mode),
    .dpram_waddr(al_ram_regmem_r1_c2_waddr),
    .dpram_wclk(al_ram_regmem_r1_c2_wclk),
    .dpram_we(al_ram_regmem_r1_c2_we),
    .f({al_ram_regmem_do_i1_011,al_ram_regmem_do_i1_010}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r1_c3_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r1_c3_l (
    .a({di[12],addrw[0]}),
    .b({di[13],addrw[1]}),
    .c({di[14],addrw[2]}),
    .clk(clk),
    .d({di[15],addrw[3]}),
    .e({open_n1996,we_1_al_n1}),
    .dpram_di(al_ram_regmem_r1_c3_di),
    .dpram_mode(al_ram_regmem_r1_c3_mode),
    .dpram_waddr(al_ram_regmem_r1_c3_waddr),
    .dpram_wclk(al_ram_regmem_r1_c3_wclk),
    .dpram_we(al_ram_regmem_r1_c3_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c3_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c3_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c3_di[1:0]),
    .dpram_mode(al_ram_regmem_r1_c3_mode),
    .dpram_waddr(al_ram_regmem_r1_c3_waddr),
    .dpram_wclk(al_ram_regmem_r1_c3_wclk),
    .dpram_we(al_ram_regmem_r1_c3_we),
    .f({al_ram_regmem_do_i1_013,al_ram_regmem_do_i1_012}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c3_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c3_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c3_di[3:2]),
    .dpram_mode(al_ram_regmem_r1_c3_mode),
    .dpram_waddr(al_ram_regmem_r1_c3_waddr),
    .dpram_wclk(al_ram_regmem_r1_c3_wclk),
    .dpram_we(al_ram_regmem_r1_c3_we),
    .f({al_ram_regmem_do_i1_015,al_ram_regmem_do_i1_014}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r1_c4_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r1_c4_l (
    .a({di[16],addrw[0]}),
    .b({di[17],addrw[1]}),
    .c({di[18],addrw[2]}),
    .clk(clk),
    .d({di[19],addrw[3]}),
    .e({open_n2031,we_1_al_n1}),
    .dpram_di(al_ram_regmem_r1_c4_di),
    .dpram_mode(al_ram_regmem_r1_c4_mode),
    .dpram_waddr(al_ram_regmem_r1_c4_waddr),
    .dpram_wclk(al_ram_regmem_r1_c4_wclk),
    .dpram_we(al_ram_regmem_r1_c4_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c4_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c4_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c4_di[1:0]),
    .dpram_mode(al_ram_regmem_r1_c4_mode),
    .dpram_waddr(al_ram_regmem_r1_c4_waddr),
    .dpram_wclk(al_ram_regmem_r1_c4_wclk),
    .dpram_we(al_ram_regmem_r1_c4_we),
    .f({al_ram_regmem_do_i1_017,al_ram_regmem_do_i1_016}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c4_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c4_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c4_di[3:2]),
    .dpram_mode(al_ram_regmem_r1_c4_mode),
    .dpram_waddr(al_ram_regmem_r1_c4_waddr),
    .dpram_wclk(al_ram_regmem_r1_c4_wclk),
    .dpram_we(al_ram_regmem_r1_c4_we),
    .f({al_ram_regmem_do_i1_019,al_ram_regmem_do_i1_018}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r1_c5_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r1_c5_l (
    .a({di[20],addrw[0]}),
    .b({di[21],addrw[1]}),
    .c({di[22],addrw[2]}),
    .clk(clk),
    .d({di[23],addrw[3]}),
    .e({open_n2066,we_1_al_n1}),
    .dpram_di(al_ram_regmem_r1_c5_di),
    .dpram_mode(al_ram_regmem_r1_c5_mode),
    .dpram_waddr(al_ram_regmem_r1_c5_waddr),
    .dpram_wclk(al_ram_regmem_r1_c5_wclk),
    .dpram_we(al_ram_regmem_r1_c5_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c5_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c5_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c5_di[1:0]),
    .dpram_mode(al_ram_regmem_r1_c5_mode),
    .dpram_waddr(al_ram_regmem_r1_c5_waddr),
    .dpram_wclk(al_ram_regmem_r1_c5_wclk),
    .dpram_we(al_ram_regmem_r1_c5_we),
    .f({al_ram_regmem_do_i1_021,al_ram_regmem_do_i1_020}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c5_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c5_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c5_di[3:2]),
    .dpram_mode(al_ram_regmem_r1_c5_mode),
    .dpram_waddr(al_ram_regmem_r1_c5_waddr),
    .dpram_wclk(al_ram_regmem_r1_c5_wclk),
    .dpram_we(al_ram_regmem_r1_c5_we),
    .f({al_ram_regmem_do_i1_023,al_ram_regmem_do_i1_022}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r1_c6_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r1_c6_l (
    .a({di[24],addrw[0]}),
    .b({di[25],addrw[1]}),
    .c({di[26],addrw[2]}),
    .clk(clk),
    .d({di[27],addrw[3]}),
    .e({open_n2101,we_1_al_n1}),
    .dpram_di(al_ram_regmem_r1_c6_di),
    .dpram_mode(al_ram_regmem_r1_c6_mode),
    .dpram_waddr(al_ram_regmem_r1_c6_waddr),
    .dpram_wclk(al_ram_regmem_r1_c6_wclk),
    .dpram_we(al_ram_regmem_r1_c6_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c6_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c6_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c6_di[1:0]),
    .dpram_mode(al_ram_regmem_r1_c6_mode),
    .dpram_waddr(al_ram_regmem_r1_c6_waddr),
    .dpram_wclk(al_ram_regmem_r1_c6_wclk),
    .dpram_we(al_ram_regmem_r1_c6_we),
    .f({al_ram_regmem_do_i1_025,al_ram_regmem_do_i1_024}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c6_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c6_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c6_di[3:2]),
    .dpram_mode(al_ram_regmem_r1_c6_mode),
    .dpram_waddr(al_ram_regmem_r1_c6_waddr),
    .dpram_wclk(al_ram_regmem_r1_c6_wclk),
    .dpram_we(al_ram_regmem_r1_c6_we),
    .f({al_ram_regmem_do_i1_027,al_ram_regmem_do_i1_026}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r1_c7_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r1_c7_l (
    .a({di[28],addrw[0]}),
    .b({di[29],addrw[1]}),
    .c({di[30],addrw[2]}),
    .clk(clk),
    .d({di[31],addrw[3]}),
    .e({open_n2136,we_1_al_n1}),
    .dpram_di(al_ram_regmem_r1_c7_di),
    .dpram_mode(al_ram_regmem_r1_c7_mode),
    .dpram_waddr(al_ram_regmem_r1_c7_waddr),
    .dpram_wclk(al_ram_regmem_r1_c7_wclk),
    .dpram_we(al_ram_regmem_r1_c7_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c7_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c7_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c7_di[1:0]),
    .dpram_mode(al_ram_regmem_r1_c7_mode),
    .dpram_waddr(al_ram_regmem_r1_c7_waddr),
    .dpram_wclk(al_ram_regmem_r1_c7_wclk),
    .dpram_we(al_ram_regmem_r1_c7_we),
    .f({al_ram_regmem_do_i1_029,al_ram_regmem_do_i1_028}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c7_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c7_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c7_di[3:2]),
    .dpram_mode(al_ram_regmem_r1_c7_mode),
    .dpram_waddr(al_ram_regmem_r1_c7_waddr),
    .dpram_wclk(al_ram_regmem_r1_c7_wclk),
    .dpram_we(al_ram_regmem_r1_c7_we),
    .f({al_ram_regmem_do_i1_031,al_ram_regmem_do_i1_030}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r1_c8_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r1_c8_l (
    .a({di[32],addrw[0]}),
    .b({di[33],addrw[1]}),
    .c({di[34],addrw[2]}),
    .clk(clk),
    .d({di[35],addrw[3]}),
    .e({open_n2171,we_1_al_n1}),
    .dpram_di(al_ram_regmem_r1_c8_di),
    .dpram_mode(al_ram_regmem_r1_c8_mode),
    .dpram_waddr(al_ram_regmem_r1_c8_waddr),
    .dpram_wclk(al_ram_regmem_r1_c8_wclk),
    .dpram_we(al_ram_regmem_r1_c8_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c8_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c8_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c8_di[1:0]),
    .dpram_mode(al_ram_regmem_r1_c8_mode),
    .dpram_waddr(al_ram_regmem_r1_c8_waddr),
    .dpram_wclk(al_ram_regmem_r1_c8_wclk),
    .dpram_we(al_ram_regmem_r1_c8_we),
    .f({al_ram_regmem_do_i1_033,al_ram_regmem_do_i1_032}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c8_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c8_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c8_di[3:2]),
    .dpram_mode(al_ram_regmem_r1_c8_mode),
    .dpram_waddr(al_ram_regmem_r1_c8_waddr),
    .dpram_wclk(al_ram_regmem_r1_c8_wclk),
    .dpram_we(al_ram_regmem_r1_c8_we),
    .f({al_ram_regmem_do_i1_035,al_ram_regmem_do_i1_034}));
  AL_PHY_LSLICE #(
    //.MACRO("al_ram_regmem_r1_c9_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    al_ram_regmem_r1_c9_l (
    .a({di[36],addrw[0]}),
    .b({di[37],addrw[1]}),
    .c({di[38],addrw[2]}),
    .clk(clk),
    .d({di[39],addrw[3]}),
    .e({open_n2206,we_1_al_n1}),
    .dpram_di(al_ram_regmem_r1_c9_di),
    .dpram_mode(al_ram_regmem_r1_c9_mode),
    .dpram_waddr(al_ram_regmem_r1_c9_waddr),
    .dpram_wclk(al_ram_regmem_r1_c9_wclk),
    .dpram_we(al_ram_regmem_r1_c9_we));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c9_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c9_m0 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c9_di[1:0]),
    .dpram_mode(al_ram_regmem_r1_c9_mode),
    .dpram_waddr(al_ram_regmem_r1_c9_waddr),
    .dpram_wclk(al_ram_regmem_r1_c9_wclk),
    .dpram_we(al_ram_regmem_r1_c9_we),
    .f({al_ram_regmem_do_i1_037,al_ram_regmem_do_i1_036}));
  AL_PHY_MSLICE #(
    //.MACRO("al_ram_regmem_r1_c9_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    al_ram_regmem_r1_c9_m1 (
    .a({addra[0],addra[0]}),
    .b({addra[1],addra[1]}),
    .c({addra[2],addra[2]}),
    .d({addra[3],addra[3]}),
    .dpram_di(al_ram_regmem_r1_c9_di[3:2]),
    .dpram_mode(al_ram_regmem_r1_c9_mode),
    .dpram_waddr(al_ram_regmem_r1_c9_waddr),
    .dpram_wclk(al_ram_regmem_r1_c9_wclk),
    .dpram_we(al_ram_regmem_r1_c9_we),
    .f({al_ram_regmem_do_i1_039,al_ram_regmem_do_i1_038}));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y0Z0"),
    .ALUTYPE("A_LE_B_CARRY"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b0000000000001010),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_0|lt0_cin  (
    .a({dob[0],1'b1}),
    .b({doa[0],open_n2240}),
    .fco(lt0_c1));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y2Z1"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_10|lt0_9  (
    .a(dob[10:9]),
    .b(doa[10:9]),
    .fci(lt0_c9),
    .fco(lt0_c11));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y3Z0"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_12|lt0_11  (
    .a(dob[12:11]),
    .b(doa[12:11]),
    .fci(lt0_c11),
    .fco(lt0_c13));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y3Z1"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_14|lt0_13  (
    .a(dob[14:13]),
    .b(doa[14:13]),
    .fci(lt0_c13),
    .fco(lt0_c15));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y4Z0"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_16|lt0_15  (
    .a(dob[16:15]),
    .b(doa[16:15]),
    .fci(lt0_c15),
    .fco(lt0_c17));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y4Z1"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_18|lt0_17  (
    .a(dob[18:17]),
    .b(doa[18:17]),
    .fci(lt0_c17),
    .fco(lt0_c19));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y5Z0"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_20|lt0_19  (
    .a(dob[20:19]),
    .b(doa[20:19]),
    .fci(lt0_c19),
    .fco(lt0_c21));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y5Z1"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_22|lt0_21  (
    .a(dob[22:21]),
    .b(doa[22:21]),
    .fci(lt0_c21),
    .fco(lt0_c23));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y6Z0"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_24|lt0_23  (
    .a(dob[24:23]),
    .b(doa[24:23]),
    .fci(lt0_c23),
    .fco(lt0_c25));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y6Z1"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_26|lt0_25  (
    .a(dob[26:25]),
    .b(doa[26:25]),
    .fci(lt0_c25),
    .fco(lt0_c27));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y7Z0"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_28|lt0_27  (
    .a(dob[28:27]),
    .b(doa[28:27]),
    .fci(lt0_c27),
    .fco(lt0_c29));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y0Z1"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_2|lt0_1  (
    .a(dob[2:1]),
    .b(doa[2:1]),
    .fci(lt0_c1),
    .fco(lt0_c3));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y7Z1"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_30|lt0_29  (
    .a(dob[30:29]),
    .b(doa[30:29]),
    .fci(lt0_c29),
    .fco(lt0_c31));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y8Z0"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_32|lt0_31  (
    .a(dob[32:31]),
    .b(doa[32:31]),
    .fci(lt0_c31),
    .fco(lt0_c33));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y8Z1"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_34|lt0_33  (
    .a(dob[34:33]),
    .b(doa[34:33]),
    .fci(lt0_c33),
    .fco(lt0_c35));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y9Z0"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_36|lt0_35  (
    .a(dob[36:35]),
    .b(doa[36:35]),
    .fci(lt0_c35),
    .fco(lt0_c37));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y9Z1"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_38|lt0_37  (
    .a(dob[38:37]),
    .b(doa[38:37]),
    .fci(lt0_c37),
    .fco(lt0_c39));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y10Z0"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_40|lt0_39  (
    .a(dob[40:39]),
    .b(doa[40:39]),
    .fci(lt0_c39),
    .fco(lt0_c41));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y10Z1"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_42|lt0_41  (
    .a(dob[42:41]),
    .b(doa[42:41]),
    .fci(lt0_c41),
    .fco(lt0_c43));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y11Z0"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_44|lt0_43  (
    .a(dob[44:43]),
    .b(doa[44:43]),
    .fci(lt0_c43),
    .fco(lt0_c45));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y11Z1"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_46|lt0_45  (
    .a(dob[46:45]),
    .b(doa[46:45]),
    .fci(lt0_c45),
    .fco(lt0_c47));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y12Z0"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_48|lt0_47  (
    .a(dob[48:47]),
    .b(doa[48:47]),
    .fci(lt0_c47),
    .fco(lt0_c49));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y1Z0"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_4|lt0_3  (
    .a(dob[4:3]),
    .b(doa[4:3]),
    .fci(lt0_c3),
    .fco(lt0_c5));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y12Z1"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_50|lt0_49  (
    .a(dob[50:49]),
    .b(doa[50:49]),
    .fci(lt0_c49),
    .fco(lt0_c51));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y13Z0"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_52|lt0_51  (
    .a(dob[52:51]),
    .b(doa[52:51]),
    .fci(lt0_c51),
    .fco(lt0_c53));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y13Z1"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_54|lt0_53  (
    .a(dob[54:53]),
    .b(doa[54:53]),
    .fci(lt0_c53),
    .fco(lt0_c55));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y14Z0"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_56|lt0_55  (
    .a(dob[56:55]),
    .b(doa[56:55]),
    .fci(lt0_c55),
    .fco(lt0_c57));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y14Z1"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_58|lt0_57  (
    .a(dob[58:57]),
    .b(doa[58:57]),
    .fci(lt0_c57),
    .fco(lt0_c59));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y15Z0"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_60|lt0_59  (
    .a(dob[60:59]),
    .b(doa[60:59]),
    .fci(lt0_c59),
    .fco(lt0_c61));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y15Z1"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_62|lt0_61  (
    .a(dob[62:61]),
    .b(doa[62:61]),
    .fci(lt0_c61),
    .fco(lt0_c63));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y1Z1"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_6|lt0_5  (
    .a(dob[6:5]),
    .b(doa[6:5]),
    .fci(lt0_c5),
    .fco(lt0_c7));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y2Z0"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_8|lt0_7  (
    .a(dob[8:7]),
    .b(doa[8:7]),
    .fci(lt0_c7),
    .fco(lt0_c9));
  AL_PHY_MSLICE #(
    //.MACRO("lt0_0|lt0_cin"),
    //.R_POSITION("X0Y16Z0"),
    .ALUTYPE("A_LE_B"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011100),
    .INIT_LUT1(16'b1001100110011100),
    .MODE("RIPPLE"))
    \lt0_cout|lt0_63  (
    .a({1'b0,dob[63]}),
    .b({1'b1,doa[63]}),
    .fci(lt0_c63),
    .f({j,open_n3028}));

endmodule 

