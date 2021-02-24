// Verilog netlist created by TD v5.0.25341
// Fri Feb 19 14:32:20 2021

`timescale 1ns / 1ps
module MIN_LS1u  // ../RTL/top/MIN_LS1u.v(8)
  (
  irq_n,
  rdy_n,
  sysclk,
  sysrst_n,
  AAH8,
  ale_n,
  busclk,
  busrst_n,
  cmd_n,
  cs_n,
  typ,
  wr_n,
  AD8
  );

  input irq_n;  // ../RTL/top/MIN_LS1u.v(21)
  input rdy_n;  // ../RTL/top/MIN_LS1u.v(20)
  input sysclk;  // ../RTL/top/MIN_LS1u.v(11)
  input sysrst_n;  // ../RTL/top/MIN_LS1u.v(12)
  output [7:0] AAH8;  // ../RTL/top/MIN_LS1u.v(23)
  output ale_n;  // ../RTL/top/MIN_LS1u.v(15)
  output busclk;  // ../RTL/top/MIN_LS1u.v(13)
  output busrst_n;  // ../RTL/top/MIN_LS1u.v(14)
  output cmd_n;  // ../RTL/top/MIN_LS1u.v(17)
  output cs_n;  // ../RTL/top/MIN_LS1u.v(16)
  output typ;  // ../RTL/top/MIN_LS1u.v(18)
  output wr_n;  // ../RTL/top/MIN_LS1u.v(19)
  inout [7:0] AD8;  // ../RTL/top/MIN_LS1u.v(22)

  // localparam BUS_ADDRWID = 32;
  // localparam MMU_SETTING = 1'b1;
  // localparam cDMA_SETTING = 1'b0;
  wire [7:0] AAH8_pad;  // ../RTL/top/MIN_LS1u.v(23)
  wire [7:0] AD_out;  // ../RTL/top/MIN_LS1u.v(29)
  wire [6:0] ASYNC_WAITCYCLE;  // ../RTL/top/MIN_LS1u.v(36)
  wire [15:0] DPAE;  // ../RTL/top/MIN_LS1u.v(41)
  wire [6:0] \FSB8_CONTROLLER/async_cnt ;  // ../RTL/hispeed/fsb8.v(62)
  wire [2:0] \FSB8_CONTROLLER/n17 ;
  wire [6:0] \FSB8_CONTROLLER/n7 ;
  wire [2:0] \FSB8_CONTROLLER/state ;  // ../RTL/hispeed/fsb8.v(55)
  wire [10:0] HPAGE_BASEADDR;  // ../RTL/top/MIN_LS1u.v(38)
  wire [15:0] IPAE;  // ../RTL/top/MIN_LS1u.v(41)
  wire [23:0] IVEC_addr;  // ../RTL/top/MIN_LS1u.v(34)
  wire [31:0] haddr;  // ../RTL/top/MIN_LS1u.v(44)
  wire [7:0] hrdata;  // ../RTL/top/MIN_LS1u.v(52)
  wire [7:0] hrdata_fsb;  // ../RTL/top/MIN_LS1u.v(55)
  wire [7:0] hrdata_ocf;  // ../RTL/top/MIN_LS1u.v(58)
  wire [7:0] hwdata;  // ../RTL/top/MIN_LS1u.v(48)
  wire ADdir;  // ../RTL/top/MIN_LS1u.v(28)
  wire ALWAYS_SVM;  // ../RTL/top/MIN_LS1u.v(40)
  wire \FSB8_CONTROLLER/add0/c3 ;  // ../RTL/hispeed/fsb8.v(75)
  wire \FSB8_CONTROLLER/eq3/or_xor_i0[0]_i1[0]_o_o ;  // ../RTL/hispeed/fsb8.v(134)
  wire \FSB8_CONTROLLER/eq4/or_xor_i0[0]_i1[0]_o_o ;  // ../RTL/hispeed/fsb8.v(134)
  wire \FSB8_CONTROLLER/eq5/or_xor_i0[0]_i1[0]_o_o ;  // ../RTL/hispeed/fsb8.v(134)
  wire \FSB8_CONTROLLER/n15_lutinv ;
  wire \FSB8_CONTROLLER/n24 ;
  wire \FSB8_CONTROLLER/n29 ;
  wire \FSB8_CONTROLLER/n2_lutinv ;
  wire \FSB8_CONTROLLER/n3 ;
  wire \FSB8_CONTROLLER/n4 ;
  wire \FSB8_CONTROLLER/n6 ;
  wire \FSB8_CONTROLLER/rwsel ;  // ../RTL/hispeed/fsb8.v(60)
  wire \FSB8_CONTROLLER/u17_sel_is_2_o ;
  wire FSB_IRQ;  // ../RTL/top/MIN_LS1u.v(60)
  wire INT;  // ../RTL/top/MIN_LS1u.v(33)
  wire IN_ISP;  // ../RTL/top/MIN_LS1u.v(33)
  wire PAE_ENABLE;  // ../RTL/top/MIN_LS1u.v(39)
  wire SYNC_MODE;  // ../RTL/top/MIN_LS1u.v(35)
  wire _al_u33_o;
  wire _al_u42_o;
  wire _al_u43_o;
  wire _al_u44_o;
  wire _al_u48_o;
  wire _al_u49_o;
  wire _al_u50_o;
  wire _al_u51_o;
  wire _al_u61_o;
  wire _al_u70_o;
  wire _al_u71_o;
  wire _al_u74_o;
  wire _al_u75_o;
  wire _al_u76_o;
  wire _al_u78_o;
  wire _al_u80_o;
  wire _al_u81_o;
  wire _al_u83_o;
  wire clk;  // ../RTL/top/MIN_LS1u.v(32)
  wire cs_n_pad;  // ../RTL/top/MIN_LS1u.v(16)
  wire hburst;  // ../RTL/top/MIN_LS1u.v(46)
  wire hready;  // ../RTL/top/MIN_LS1u.v(49)
  wire hsel_ocf;  // ../RTL/top/MIN_LS1u.v(57)
  wire htrans;  // ../RTL/top/MIN_LS1u.v(47)
  wire hwrite;  // ../RTL/top/MIN_LS1u.v(45)
  wire irq_n_pad;  // ../RTL/top/MIN_LS1u.v(21)
  wire n0;
  wire \net_FSB8_CONTROLLER/ADdir_reg_reset_q0 ;
  wire \net_FSB8_CONTROLLER/ADdir_reg_sel0 ;
  wire rdy_n_pad;  // ../RTL/top/MIN_LS1u.v(20)
  wire rst;  // ../RTL/top/MIN_LS1u.v(32)
  wire rst_neg;
  wire sysrst_n_pad;  // ../RTL/top/MIN_LS1u.v(12)

  CPU_LS1u CPU1 (
    .INT(INT),
    .IVEC_addr({open_n0,IVEC_addr[22:0]}),
    .clk(clk),
    .dpae_h16(DPAE),
    .force_svpriv(ALWAYS_SVM),
    .hrdata(hrdata),
    .hready(hready),
    .hreset_n(rst_neg),
    .hresp(1'b0),
    .hugepage_ptr({1'b0,HPAGE_BASEADDR[9:0]}),
    .ipae_h16(IPAE),
    .mmu_enable(PAE_ENABLE),
    .rst(rst),
    .IN_ISP(IN_ISP),
    .haddr(haddr),
    .hburst(hburst),
    .htrans(htrans),
    .hwdata(hwdata),
    .hwrite(hwrite));  // ../RTL/top/MIN_LS1u.v(66)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("INV"),
    .DFFMODE("LATCH"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \FSB8_CONTROLLER/ADdir_reg  (
    .clk(\FSB8_CONTROLLER/n29 ),
    .d(1'b1),
    .sr(\FSB8_CONTROLLER/n24 ),
    .q(\net_FSB8_CONTROLLER/ADdir_reg_reset_q0 ));  // ../RTL/hispeed/fsb8.v(138)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \FSB8_CONTROLLER/ADdir_reg_bistable0  (
    .clk(\FSB8_CONTROLLER/n29 ),
    .d(1'b1),
    .sr(\FSB8_CONTROLLER/n24 ),
    .q(\net_FSB8_CONTROLLER/ADdir_reg_sel0 ));
  AL_PHY_LSLICE #(
    //.MACRO("FSB8_CONTROLLER/add0/ucin_al_u88"),
    //.R_POSITION("X0Y0Z1"),
    .DEMUX0("E"),
    .DEMUX1("E"),
    .GSR("DISABLE"),
    .INIT_LUTF0(16'hA55A),
    .INIT_LUTF1(16'hA55A),
    .INIT_LUTG0(16'hC33C),
    .INIT_LUTG1(16'hC33C),
    .LSFMUX0("SUM"),
    .LSFMUX1("SUM"),
    .LSFXMUX0("SUM"),
    .LSFXMUX1("SUM"),
    .MODE("RIPPLE"))
    \FSB8_CONTROLLER/add0/u3_al_u89  (
    .a({\FSB8_CONTROLLER/async_cnt [5],\FSB8_CONTROLLER/async_cnt [3]}),
    .b({\FSB8_CONTROLLER/async_cnt [6],\FSB8_CONTROLLER/async_cnt [4]}),
    .c(2'b00),
    .d(2'b00),
    .e(2'b00),
    .fci(\FSB8_CONTROLLER/add0/c3 ),
    .f({\FSB8_CONTROLLER/n7 [5],\FSB8_CONTROLLER/n7 [3]}),
    .fx({\FSB8_CONTROLLER/n7 [6],\FSB8_CONTROLLER/n7 [4]}));
  AL_PHY_LSLICE #(
    //.MACRO("FSB8_CONTROLLER/add0/ucin_al_u88"),
    //.R_POSITION("X0Y0Z0"),
    .DEMUX0("E"),
    .DEMUX1("E"),
    .GSR("DISABLE"),
    .INIT_LUTF0(16'h000A),
    .INIT_LUTF1(16'hA55A),
    .INIT_LUTG0(16'hC33C),
    .INIT_LUTG1(16'hC33C),
    .LSFMUX0("SUM"),
    .LSFMUX1("SUM"),
    .LSFXMUX0("SUM"),
    .LSFXMUX1("SUM"),
    .MODE("RIPPLE"))
    \FSB8_CONTROLLER/add0/ucin_al_u88  (
    .a({\FSB8_CONTROLLER/async_cnt [1],1'b0}),
    .b({\FSB8_CONTROLLER/async_cnt [2],\FSB8_CONTROLLER/async_cnt [0]}),
    .c(2'b00),
    .d(2'b01),
    .e(2'b01),
    .f({\FSB8_CONTROLLER/n7 [1],open_n63}),
    .fco(\FSB8_CONTROLLER/add0/c3 ),
    .fx({\FSB8_CONTROLLER/n7 [2],\FSB8_CONTROLLER/n7 [0]}));
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \FSB8_CONTROLLER/reg0_b0  (
    .clk(clk),
    .d(\FSB8_CONTROLLER/n17 [0]),
    .sr(rst),
    .q(\FSB8_CONTROLLER/state [0]));  // ../RTL/hispeed/fsb8.v(112)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \FSB8_CONTROLLER/reg0_b1  (
    .clk(clk),
    .d(\FSB8_CONTROLLER/n17 [1]),
    .sr(rst),
    .q(\FSB8_CONTROLLER/state [1]));  // ../RTL/hispeed/fsb8.v(112)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \FSB8_CONTROLLER/reg0_b2  (
    .clk(clk),
    .d(\FSB8_CONTROLLER/n17 [2]),
    .sr(rst),
    .q(\FSB8_CONTROLLER/state [2]));  // ../RTL/hispeed/fsb8.v(112)
  AL_PHY_PAD #(
    //.CLKSRC("CLK"),
    //.PCICLAMP("OFF"),
    //.PULLMODE("PULLUP"),
    //.SLEWRATE("SLOW"),
    .DRIVE("8"),
    .GSR("DISABLE"),
    .INCEMUX("INV"),
    .INCLKMUX("CLK"),
    .INRSTMUX("0"),
    .IN_DFFMODE("FF"),
    .IN_REGSET("RESET"),
    .IOTYPE("LVCMOS25"),
    .MODE("BI"),
    .SRMODE("ASYNC"),
    .TSMUX("INV"))
    \FSB8_CONTROLLER/reg1_b0_IN  (
    .ce(rdy_n_pad),
    .clk(clk),
    .otrue(AD_out[0]),
    .ts(ADdir),
    .itrue(hrdata_fsb[0]),
    .bpad(AD8[0]));  // ../RTL/top/MIN_LS1u.v(30)
  AL_PHY_PAD #(
    //.CLKSRC("CLK"),
    //.PCICLAMP("OFF"),
    //.PULLMODE("PULLUP"),
    //.SLEWRATE("SLOW"),
    .DRIVE("8"),
    .GSR("DISABLE"),
    .INCEMUX("INV"),
    .INCLKMUX("CLK"),
    .INRSTMUX("0"),
    .IN_DFFMODE("FF"),
    .IN_REGSET("RESET"),
    .IOTYPE("LVCMOS25"),
    .MODE("BI"),
    .SRMODE("ASYNC"),
    .TSMUX("INV"))
    \FSB8_CONTROLLER/reg1_b1_IN  (
    .ce(rdy_n_pad),
    .clk(clk),
    .otrue(AD_out[1]),
    .ts(ADdir),
    .itrue(hrdata_fsb[1]),
    .bpad(AD8[1]));  // ../RTL/top/MIN_LS1u.v(30)
  AL_PHY_PAD #(
    //.CLKSRC("CLK"),
    //.PCICLAMP("OFF"),
    //.PULLMODE("PULLUP"),
    //.SLEWRATE("SLOW"),
    .DRIVE("8"),
    .GSR("DISABLE"),
    .INCEMUX("INV"),
    .INCLKMUX("CLK"),
    .INRSTMUX("0"),
    .IN_DFFMODE("FF"),
    .IN_REGSET("RESET"),
    .IOTYPE("LVCMOS25"),
    .MODE("BI"),
    .SRMODE("ASYNC"),
    .TSMUX("INV"))
    \FSB8_CONTROLLER/reg1_b2_IN  (
    .ce(rdy_n_pad),
    .clk(clk),
    .otrue(AD_out[2]),
    .ts(ADdir),
    .itrue(hrdata_fsb[2]),
    .bpad(AD8[2]));  // ../RTL/top/MIN_LS1u.v(30)
  AL_PHY_PAD #(
    //.CLKSRC("CLK"),
    //.PCICLAMP("OFF"),
    //.PULLMODE("PULLUP"),
    //.SLEWRATE("SLOW"),
    .DRIVE("8"),
    .GSR("DISABLE"),
    .INCEMUX("INV"),
    .INCLKMUX("CLK"),
    .INRSTMUX("0"),
    .IN_DFFMODE("FF"),
    .IN_REGSET("RESET"),
    .IOTYPE("LVCMOS25"),
    .MODE("BI"),
    .SRMODE("ASYNC"),
    .TSMUX("INV"))
    \FSB8_CONTROLLER/reg1_b3_IN  (
    .ce(rdy_n_pad),
    .clk(clk),
    .otrue(AD_out[3]),
    .ts(ADdir),
    .itrue(hrdata_fsb[3]),
    .bpad(AD8[3]));  // ../RTL/top/MIN_LS1u.v(30)
  AL_PHY_PAD #(
    //.CLKSRC("CLK"),
    //.PCICLAMP("OFF"),
    //.PULLMODE("PULLUP"),
    //.SLEWRATE("SLOW"),
    .DRIVE("8"),
    .GSR("DISABLE"),
    .INCEMUX("INV"),
    .INCLKMUX("CLK"),
    .INRSTMUX("0"),
    .IN_DFFMODE("FF"),
    .IN_REGSET("RESET"),
    .IOTYPE("LVCMOS25"),
    .MODE("BI"),
    .SRMODE("ASYNC"),
    .TSMUX("INV"))
    \FSB8_CONTROLLER/reg1_b4_IN  (
    .ce(rdy_n_pad),
    .clk(clk),
    .otrue(AD_out[4]),
    .ts(ADdir),
    .itrue(hrdata_fsb[4]),
    .bpad(AD8[4]));  // ../RTL/top/MIN_LS1u.v(30)
  AL_PHY_PAD #(
    //.CLKSRC("CLK"),
    //.PCICLAMP("OFF"),
    //.PULLMODE("PULLUP"),
    //.SLEWRATE("SLOW"),
    .DRIVE("8"),
    .GSR("DISABLE"),
    .INCEMUX("INV"),
    .INCLKMUX("CLK"),
    .INRSTMUX("0"),
    .IN_DFFMODE("FF"),
    .IN_REGSET("RESET"),
    .IOTYPE("LVCMOS25"),
    .MODE("BI"),
    .SRMODE("ASYNC"),
    .TSMUX("INV"))
    \FSB8_CONTROLLER/reg1_b5_IN  (
    .ce(rdy_n_pad),
    .clk(clk),
    .otrue(AD_out[5]),
    .ts(ADdir),
    .itrue(hrdata_fsb[5]),
    .bpad(AD8[5]));  // ../RTL/top/MIN_LS1u.v(30)
  AL_PHY_PAD #(
    //.CLKSRC("CLK"),
    //.PCICLAMP("OFF"),
    //.PULLMODE("PULLUP"),
    //.SLEWRATE("SLOW"),
    .DRIVE("8"),
    .GSR("DISABLE"),
    .INCEMUX("INV"),
    .INCLKMUX("CLK"),
    .INRSTMUX("0"),
    .IN_DFFMODE("FF"),
    .IN_REGSET("RESET"),
    .IOTYPE("LVCMOS25"),
    .MODE("BI"),
    .SRMODE("ASYNC"),
    .TSMUX("INV"))
    \FSB8_CONTROLLER/reg1_b6_IN  (
    .ce(rdy_n_pad),
    .clk(clk),
    .otrue(AD_out[6]),
    .ts(ADdir),
    .itrue(hrdata_fsb[6]),
    .bpad(AD8[6]));  // ../RTL/top/MIN_LS1u.v(30)
  AL_PHY_PAD #(
    //.CLKSRC("CLK"),
    //.PCICLAMP("OFF"),
    //.PULLMODE("PULLUP"),
    //.SLEWRATE("SLOW"),
    .DRIVE("8"),
    .GSR("DISABLE"),
    .INCEMUX("INV"),
    .INCLKMUX("CLK"),
    .INRSTMUX("0"),
    .IN_DFFMODE("FF"),
    .IN_REGSET("RESET"),
    .IOTYPE("LVCMOS25"),
    .MODE("BI"),
    .SRMODE("ASYNC"),
    .TSMUX("INV"))
    \FSB8_CONTROLLER/reg1_b7_IN  (
    .ce(rdy_n_pad),
    .clk(clk),
    .otrue(AD_out[7]),
    .ts(ADdir),
    .itrue(hrdata_fsb[7]),
    .bpad(AD8[7]));  // ../RTL/top/MIN_LS1u.v(30)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \FSB8_CONTROLLER/reg2_b0  (
    .ce(\FSB8_CONTROLLER/n6 ),
    .clk(clk),
    .d(\FSB8_CONTROLLER/n7 [0]),
    .sr(\FSB8_CONTROLLER/n3 ),
    .q(\FSB8_CONTROLLER/async_cnt [0]));  // ../RTL/hispeed/fsb8.v(77)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \FSB8_CONTROLLER/reg2_b1  (
    .ce(\FSB8_CONTROLLER/n6 ),
    .clk(clk),
    .d(\FSB8_CONTROLLER/n7 [1]),
    .sr(\FSB8_CONTROLLER/n3 ),
    .q(\FSB8_CONTROLLER/async_cnt [1]));  // ../RTL/hispeed/fsb8.v(77)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \FSB8_CONTROLLER/reg2_b2  (
    .ce(\FSB8_CONTROLLER/n6 ),
    .clk(clk),
    .d(\FSB8_CONTROLLER/n7 [2]),
    .sr(\FSB8_CONTROLLER/n3 ),
    .q(\FSB8_CONTROLLER/async_cnt [2]));  // ../RTL/hispeed/fsb8.v(77)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \FSB8_CONTROLLER/reg2_b3  (
    .ce(\FSB8_CONTROLLER/n6 ),
    .clk(clk),
    .d(\FSB8_CONTROLLER/n7 [3]),
    .sr(\FSB8_CONTROLLER/n3 ),
    .q(\FSB8_CONTROLLER/async_cnt [3]));  // ../RTL/hispeed/fsb8.v(77)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \FSB8_CONTROLLER/reg2_b4  (
    .ce(\FSB8_CONTROLLER/n6 ),
    .clk(clk),
    .d(\FSB8_CONTROLLER/n7 [4]),
    .sr(\FSB8_CONTROLLER/n3 ),
    .q(\FSB8_CONTROLLER/async_cnt [4]));  // ../RTL/hispeed/fsb8.v(77)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \FSB8_CONTROLLER/reg2_b5  (
    .ce(\FSB8_CONTROLLER/n6 ),
    .clk(clk),
    .d(\FSB8_CONTROLLER/n7 [5]),
    .sr(\FSB8_CONTROLLER/n3 ),
    .q(\FSB8_CONTROLLER/async_cnt [5]));  // ../RTL/hispeed/fsb8.v(77)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \FSB8_CONTROLLER/reg2_b6  (
    .ce(\FSB8_CONTROLLER/n6 ),
    .clk(clk),
    .d(\FSB8_CONTROLLER/n7 [6]),
    .sr(\FSB8_CONTROLLER/n3 ),
    .q(\FSB8_CONTROLLER/async_cnt [6]));  // ../RTL/hispeed/fsb8.v(77)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \FSB8_CONTROLLER/rwsel_reg  (
    .ce(\FSB8_CONTROLLER/u17_sel_is_2_o ),
    .clk(clk),
    .d(hwrite),
    .q(\FSB8_CONTROLLER/rwsel ));  // ../RTL/hispeed/fsb8.v(112)
  AL_PHY_PAD #(
    //.CLKSRC("CLK"),
    //.PCICLAMP("OFF"),
    //.PULLMODE("NONE"),
    //.SLEWRATE("SLOW"),
    .DO_DFFMODE("FF"),
    .DO_REGSET("RESET"),
    .DRIVE("8"),
    .GSR("DISABLE"),
    .IOTYPE("LVCMOS25"),
    .MODE("OUT"),
    .OUTCEMUX("CE"),
    .OUTCLKMUX("CLK"),
    .OUTRSTMUX("0"),
    .SRMODE("ASYNC"),
    .TSMUX("0"))
    \FSB8_CONTROLLER/typ_reg_DO  (
    .ce(\FSB8_CONTROLLER/n4 ),
    .clk(clk),
    .otrue(hburst),
    .opad(typ));  // ../RTL/hispeed/fsb8.v(126)
  \min_pbus(MMU_ENABLE=1'b1)  OC_PERIPHERALS (
    .MNMX(rdy_n_pad),
    .SYST_PAUSE(IN_ISP),
    .WB_ADRi(haddr[11:0]),
    .WB_CYCi(htrans),
    .WB_DATi(hwdata),
    .WB_STBi(hsel_ocf),
    .WB_WEi(hwrite),
    .XTNL_INT(FSB_IRQ),
    .clki(sysclk),
    .rsti(n0),
    .ALWAYS_SVM(ALWAYS_SVM),
    .ASYNC_WAITCYCLE(ASYNC_WAITCYCLE),
    .HPAGE_BASEADDR(HPAGE_BASEADDR[9:0]),
    .INT(INT),
    .IVEC_ADDR({open_n143,IVEC_addr[22:0]}),
    .PAE_ENABLE(PAE_ENABLE),
    .SYNC_MODE(SYNC_MODE),
    .WB_DATo(hrdata_ocf),
    .clk(clk),
    .dpae_h16(DPAE),
    .ipae_h16(IPAE),
    .rst(rst));  // ../RTL/top/MIN_LS1u.v(133)
  AL_PHY_PAD #(
    //.PCICLAMP("OFF"),
    //.PULLMODE("NONE"),
    //.SLEWRATE("SLOW"),
    .DRIVE("8"),
    .GSR("DISABLE"),
    .IOTYPE("LVCMOS25"),
    .MODE("OUT"),
    .TSMUX("0"))
    _al_u0 (
    .otrue(AAH8_pad[7]),
    .opad(AAH8[7]));  // ../RTL/top/MIN_LS1u.v(23)
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
    .otrue(AAH8_pad[6]),
    .opad(AAH8[6]));  // ../RTL/top/MIN_LS1u.v(23)
  AL_PHY_PAD #(
    //.PCICLAMP("OFF"),
    //.PULLMODE("NONE"),
    //.SLEWRATE("SLOW"),
    .DRIVE("8"),
    .GSR("DISABLE"),
    .IOTYPE("LVCMOS25"),
    .MODE("OUT"),
    .TSMUX("0"))
    _al_u10 (
    .otrue(rst_neg),
    .opad(busrst_n));  // ../RTL/top/MIN_LS1u.v(14)
  AL_PHY_PAD #(
    //.PCICLAMP("OFF"),
    //.PULLMODE("NONE"),
    //.SLEWRATE("SLOW"),
    .DRIVE("8"),
    .GSR("DISABLE"),
    .IOTYPE("LVCMOS25"),
    .MODE("OUT"),
    .TSMUX("0"))
    _al_u11 (
    .otrue(\FSB8_CONTROLLER/eq4/or_xor_i0[0]_i1[0]_o_o ),
    .opad(cmd_n));  // ../RTL/top/MIN_LS1u.v(17)
  AL_PHY_PAD #(
    //.PCICLAMP("OFF"),
    //.PULLMODE("NONE"),
    //.SLEWRATE("SLOW"),
    .DRIVE("8"),
    .GSR("DISABLE"),
    .IOTYPE("LVCMOS25"),
    .MODE("OUT"),
    .TSMUX("0"))
    _al_u12 (
    .otrue(cs_n_pad),
    .opad(cs_n));  // ../RTL/top/MIN_LS1u.v(16)
  AL_PHY_PAD #(
    //.PCICLAMP("OFF"),
    //.PULLMODE("PULLUP"),
    .GSR("DISABLE"),
    .IOTYPE("LVCMOS25"),
    .MODE("IN"),
    .TSMUX("1"))
    _al_u13 (
    .ipad(irq_n),
    .di(irq_n_pad));  // ../RTL/top/MIN_LS1u.v(21)
  AL_PHY_PAD #(
    //.PCICLAMP("OFF"),
    //.PULLMODE("PULLUP"),
    .GSR("DISABLE"),
    .IOTYPE("LVCMOS25"),
    .MODE("IN"),
    .TSMUX("1"))
    _al_u14 (
    .ipad(rdy_n),
    .di(rdy_n_pad));  // ../RTL/top/MIN_LS1u.v(20)
  AL_PHY_PAD #(
    //.PCICLAMP("OFF"),
    //.PULLMODE("PULLUP"),
    .GSR("DISABLE"),
    .IOTYPE("LVCMOS25"),
    .MODE("IN"),
    .TSMUX("1"))
    _al_u15 (
    .ipad(sysrst_n),
    .di(sysrst_n_pad));  // ../RTL/top/MIN_LS1u.v(12)
  AL_PHY_PAD #(
    //.PCICLAMP("OFF"),
    //.PULLMODE("NONE"),
    //.SLEWRATE("SLOW"),
    .DRIVE("8"),
    .GSR("DISABLE"),
    .IOTYPE("LVCMOS25"),
    .MODE("OUT"),
    .TSMUX("0"))
    _al_u16 (
    .otrue(\FSB8_CONTROLLER/eq5/or_xor_i0[0]_i1[0]_o_o ),
    .opad(wr_n));  // ../RTL/top/MIN_LS1u.v(19)
  AL_PHY_PAD #(
    //.PCICLAMP("OFF"),
    //.PULLMODE("NONE"),
    //.SLEWRATE("SLOW"),
    .DRIVE("8"),
    .GSR("DISABLE"),
    .IOTYPE("LVCMOS25"),
    .MODE("OUT"),
    .TSMUX("0"))
    _al_u2 (
    .otrue(AAH8_pad[5]),
    .opad(AAH8[5]));  // ../RTL/top/MIN_LS1u.v(23)
  AL_MAP_LUT2 #(
    .EQN("~(~B*~A)"),
    .INIT(4'he))
    _al_u25 (
    .a(\net_FSB8_CONTROLLER/ADdir_reg_reset_q0 ),
    .b(\net_FSB8_CONTROLLER/ADdir_reg_sel0 ),
    .o(ADdir));
  AL_MAP_LUT2 #(
    .EQN("(~B*~A)"),
    .INIT(4'h1))
    _al_u26 (
    .a(\FSB8_CONTROLLER/state [0]),
    .b(\FSB8_CONTROLLER/state [2]),
    .o(\FSB8_CONTROLLER/n24 ));
  AL_MAP_LUT2 #(
    .EQN("~(~B*A)"),
    .INIT(4'hd))
    _al_u27 (
    .a(\FSB8_CONTROLLER/n24 ),
    .b(\FSB8_CONTROLLER/state [1]),
    .o(\FSB8_CONTROLLER/n4 ));
  AL_MAP_LUT3 #(
    .EQN("~(~C*~B*A)"),
    .INIT(8'hfd))
    _al_u28 (
    .a(\FSB8_CONTROLLER/state [0]),
    .b(\FSB8_CONTROLLER/state [1]),
    .c(\FSB8_CONTROLLER/state [2]),
    .o(\FSB8_CONTROLLER/eq3/or_xor_i0[0]_i1[0]_o_o ));
  AL_MAP_LUT2 #(
    .EQN("(~B*A)"),
    .INIT(4'h2))
    _al_u29 (
    .a(\FSB8_CONTROLLER/n4 ),
    .b(SYNC_MODE),
    .o(\FSB8_CONTROLLER/n6 ));
  AL_PHY_PAD #(
    //.PCICLAMP("OFF"),
    //.PULLMODE("NONE"),
    //.SLEWRATE("SLOW"),
    .DRIVE("8"),
    .GSR("DISABLE"),
    .IOTYPE("LVCMOS25"),
    .MODE("OUT"),
    .TSMUX("0"))
    _al_u3 (
    .otrue(AAH8_pad[4]),
    .opad(AAH8[4]));  // ../RTL/top/MIN_LS1u.v(23)
  AL_MAP_LUT2 #(
    .EQN("(~B*~A)"),
    .INIT(4'h1))
    _al_u30 (
    .a(\FSB8_CONTROLLER/n4 ),
    .b(rst),
    .o(\FSB8_CONTROLLER/u17_sel_is_2_o ));
  AL_MAP_LUT3 #(
    .EQN("~(C*~B*~A)"),
    .INIT(8'hef))
    _al_u31 (
    .a(\FSB8_CONTROLLER/state [0]),
    .b(\FSB8_CONTROLLER/state [1]),
    .c(\FSB8_CONTROLLER/state [2]),
    .o(\FSB8_CONTROLLER/eq5/or_xor_i0[0]_i1[0]_o_o ));
  AL_MAP_LUT3 #(
    .EQN("~(C*B*A)"),
    .INIT(8'h7f))
    _al_u32 (
    .a(\FSB8_CONTROLLER/state [0]),
    .b(\FSB8_CONTROLLER/state [1]),
    .c(\FSB8_CONTROLLER/state [2]),
    .o(\FSB8_CONTROLLER/eq4/or_xor_i0[0]_i1[0]_o_o ));
  AL_MAP_LUT2 #(
    .EQN("(~B*A)"),
    .INIT(4'h2))
    _al_u33 (
    .a(\FSB8_CONTROLLER/state [1]),
    .b(\FSB8_CONTROLLER/state [2]),
    .o(_al_u33_o));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+A*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*~(B)*C*~(D)*E+A*B*C*~(D)*E+~(A)*~(B)*~(C)*D*E+~(A)*B*~(C)*D*E+A*B*~(C)*D*E+~(A)*~(B)*C*D*E+A*~(B)*C*D*E+~(A)*B*C*D*E+A*B*C*D*E)"),
    .INIT(32'hfdb87530))
    _al_u34 (
    .a(\FSB8_CONTROLLER/eq3/or_xor_i0[0]_i1[0]_o_o ),
    .b(\FSB8_CONTROLLER/eq4/or_xor_i0[0]_i1[0]_o_o ),
    .c(haddr[31]),
    .d(haddr[23]),
    .e(haddr[7]),
    .o(AAH8_pad[7]));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+A*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*~(B)*C*~(D)*E+A*B*C*~(D)*E+~(A)*~(B)*~(C)*D*E+~(A)*B*~(C)*D*E+A*B*~(C)*D*E+~(A)*~(B)*C*D*E+A*~(B)*C*D*E+~(A)*B*C*D*E+A*B*C*D*E)"),
    .INIT(32'hfdb87530))
    _al_u35 (
    .a(\FSB8_CONTROLLER/eq3/or_xor_i0[0]_i1[0]_o_o ),
    .b(\FSB8_CONTROLLER/eq4/or_xor_i0[0]_i1[0]_o_o ),
    .c(haddr[30]),
    .d(haddr[22]),
    .e(haddr[6]),
    .o(AAH8_pad[6]));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+A*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*~(B)*C*~(D)*E+A*B*C*~(D)*E+~(A)*~(B)*~(C)*D*E+~(A)*B*~(C)*D*E+A*B*~(C)*D*E+~(A)*~(B)*C*D*E+A*~(B)*C*D*E+~(A)*B*C*D*E+A*B*C*D*E)"),
    .INIT(32'hfdb87530))
    _al_u36 (
    .a(\FSB8_CONTROLLER/eq3/or_xor_i0[0]_i1[0]_o_o ),
    .b(\FSB8_CONTROLLER/eq4/or_xor_i0[0]_i1[0]_o_o ),
    .c(haddr[29]),
    .d(haddr[21]),
    .e(haddr[5]),
    .o(AAH8_pad[5]));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+A*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*~(B)*C*~(D)*E+A*B*C*~(D)*E+~(A)*~(B)*~(C)*D*E+~(A)*B*~(C)*D*E+A*B*~(C)*D*E+~(A)*~(B)*C*D*E+A*~(B)*C*D*E+~(A)*B*C*D*E+A*B*C*D*E)"),
    .INIT(32'hfdb87530))
    _al_u37 (
    .a(\FSB8_CONTROLLER/eq3/or_xor_i0[0]_i1[0]_o_o ),
    .b(\FSB8_CONTROLLER/eq4/or_xor_i0[0]_i1[0]_o_o ),
    .c(haddr[28]),
    .d(haddr[20]),
    .e(haddr[4]),
    .o(AAH8_pad[4]));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+A*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*~(B)*C*~(D)*E+A*B*C*~(D)*E+~(A)*~(B)*~(C)*D*E+~(A)*B*~(C)*D*E+A*B*~(C)*D*E+~(A)*~(B)*C*D*E+A*~(B)*C*D*E+~(A)*B*C*D*E+A*B*C*D*E)"),
    .INIT(32'hfdb87530))
    _al_u38 (
    .a(\FSB8_CONTROLLER/eq3/or_xor_i0[0]_i1[0]_o_o ),
    .b(\FSB8_CONTROLLER/eq4/or_xor_i0[0]_i1[0]_o_o ),
    .c(haddr[27]),
    .d(haddr[19]),
    .e(haddr[3]),
    .o(AAH8_pad[3]));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+A*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*~(B)*C*~(D)*E+A*B*C*~(D)*E+~(A)*~(B)*~(C)*D*E+~(A)*B*~(C)*D*E+A*B*~(C)*D*E+~(A)*~(B)*C*D*E+A*~(B)*C*D*E+~(A)*B*C*D*E+A*B*C*D*E)"),
    .INIT(32'hfdb87530))
    _al_u39 (
    .a(\FSB8_CONTROLLER/eq3/or_xor_i0[0]_i1[0]_o_o ),
    .b(\FSB8_CONTROLLER/eq4/or_xor_i0[0]_i1[0]_o_o ),
    .c(haddr[26]),
    .d(haddr[18]),
    .e(haddr[2]),
    .o(AAH8_pad[2]));
  AL_PHY_PAD #(
    //.PCICLAMP("OFF"),
    //.PULLMODE("NONE"),
    //.SLEWRATE("SLOW"),
    .DRIVE("8"),
    .GSR("DISABLE"),
    .IOTYPE("LVCMOS25"),
    .MODE("OUT"),
    .TSMUX("0"))
    _al_u4 (
    .otrue(AAH8_pad[3]),
    .opad(AAH8[3]));  // ../RTL/top/MIN_LS1u.v(23)
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+A*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*~(B)*C*~(D)*E+A*B*C*~(D)*E+~(A)*~(B)*~(C)*D*E+~(A)*B*~(C)*D*E+A*B*~(C)*D*E+~(A)*~(B)*C*D*E+A*~(B)*C*D*E+~(A)*B*C*D*E+A*B*C*D*E)"),
    .INIT(32'hfdb87530))
    _al_u40 (
    .a(\FSB8_CONTROLLER/eq3/or_xor_i0[0]_i1[0]_o_o ),
    .b(\FSB8_CONTROLLER/eq4/or_xor_i0[0]_i1[0]_o_o ),
    .c(haddr[25]),
    .d(haddr[17]),
    .e(haddr[1]),
    .o(AAH8_pad[1]));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+A*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*~(B)*C*~(D)*E+A*B*C*~(D)*E+~(A)*~(B)*~(C)*D*E+~(A)*B*~(C)*D*E+A*B*~(C)*D*E+~(A)*~(B)*C*D*E+A*~(B)*C*D*E+~(A)*B*C*D*E+A*B*C*D*E)"),
    .INIT(32'hfdb87530))
    _al_u41 (
    .a(\FSB8_CONTROLLER/eq3/or_xor_i0[0]_i1[0]_o_o ),
    .b(\FSB8_CONTROLLER/eq4/or_xor_i0[0]_i1[0]_o_o ),
    .c(haddr[24]),
    .d(haddr[16]),
    .e(haddr[0]),
    .o(AAH8_pad[0]));
  AL_MAP_LUT3 #(
    .EQN("(~C*B*A)"),
    .INIT(8'h08))
    _al_u42 (
    .a(haddr[23]),
    .b(haddr[22]),
    .c(haddr[21]),
    .o(_al_u42_o));
  AL_MAP_LUT5 #(
    .EQN("(~E*~D*~C*~B*~A)"),
    .INIT(32'h00000001))
    _al_u43 (
    .a(haddr[20]),
    .b(haddr[19]),
    .c(haddr[18]),
    .d(haddr[17]),
    .e(haddr[16]),
    .o(_al_u43_o));
  AL_MAP_LUT4 #(
    .EQN("(~A*~(B*~(~D*~C)))"),
    .INIT(16'h1115))
    _al_u44 (
    .a(haddr[11]),
    .b(haddr[10]),
    .c(haddr[9]),
    .d(haddr[8]),
    .o(_al_u44_o));
  AL_MAP_LUT3 #(
    .EQN("(C*~B*A)"),
    .INIT(8'h20))
    _al_u45 (
    .a(_al_u43_o),
    .b(_al_u44_o),
    .c(_al_u42_o),
    .o(hsel_ocf));
  AL_MAP_LUT3 #(
    .EQN("(~(A)*~(B)*~(C)+A*~(B)*~(C)+~(A)*B*~(C)+A*~(B)*C+~(A)*B*C+A*B*C)"),
    .INIT(8'he7))
    _al_u46 (
    .a(\FSB8_CONTROLLER/state [0]),
    .b(\FSB8_CONTROLLER/state [1]),
    .c(\FSB8_CONTROLLER/state [2]),
    .o(cs_n_pad));
  AL_MAP_LUT3 #(
    .EQN("(A*~(B)*~(C)+~(A)*~(B)*C+A*B*C)"),
    .INIT(8'h92))
    _al_u47 (
    .a(\FSB8_CONTROLLER/state [0]),
    .b(\FSB8_CONTROLLER/state [1]),
    .c(\FSB8_CONTROLLER/state [2]),
    .o(\FSB8_CONTROLLER/n29 ));
  AL_MAP_LUT2 #(
    .EQN("~(B@A)"),
    .INIT(4'h9))
    _al_u48 (
    .a(\FSB8_CONTROLLER/async_cnt [2]),
    .b(ASYNC_WAITCYCLE[2]),
    .o(_al_u48_o));
  AL_MAP_LUT4 #(
    .EQN("(~(C@B)*~(D@A))"),
    .INIT(16'h8241))
    _al_u49 (
    .a(\FSB8_CONTROLLER/async_cnt [1]),
    .b(\FSB8_CONTROLLER/async_cnt [4]),
    .c(ASYNC_WAITCYCLE[4]),
    .d(ASYNC_WAITCYCLE[1]),
    .o(_al_u49_o));
  AL_PHY_PAD #(
    //.PCICLAMP("OFF"),
    //.PULLMODE("NONE"),
    //.SLEWRATE("SLOW"),
    .DRIVE("8"),
    .GSR("DISABLE"),
    .IOTYPE("LVCMOS25"),
    .MODE("OUT"),
    .TSMUX("0"))
    _al_u5 (
    .otrue(AAH8_pad[2]),
    .opad(AAH8[2]));  // ../RTL/top/MIN_LS1u.v(23)
  AL_MAP_LUT4 #(
    .EQN("(~(C@B)*~(D@A))"),
    .INIT(16'h8241))
    _al_u50 (
    .a(\FSB8_CONTROLLER/async_cnt [0]),
    .b(\FSB8_CONTROLLER/async_cnt [6]),
    .c(ASYNC_WAITCYCLE[6]),
    .d(ASYNC_WAITCYCLE[0]),
    .o(_al_u50_o));
  AL_MAP_LUT4 #(
    .EQN("(~(C@B)*~(D@A))"),
    .INIT(16'h8241))
    _al_u51 (
    .a(\FSB8_CONTROLLER/async_cnt [3]),
    .b(\FSB8_CONTROLLER/async_cnt [5]),
    .c(ASYNC_WAITCYCLE[5]),
    .d(ASYNC_WAITCYCLE[3]),
    .o(_al_u51_o));
  AL_MAP_LUT5 #(
    .EQN("~(~E*~(D*C*B*A))"),
    .INIT(32'hffff8000))
    _al_u52 (
    .a(_al_u49_o),
    .b(_al_u50_o),
    .c(_al_u51_o),
    .d(_al_u48_o),
    .e(rst),
    .o(\FSB8_CONTROLLER/n3 ));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u53 (
    .a(hsel_ocf),
    .b(hrdata_fsb[7]),
    .c(hrdata_ocf[7]),
    .o(hrdata[7]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u54 (
    .a(hsel_ocf),
    .b(hrdata_fsb[6]),
    .c(hrdata_ocf[6]),
    .o(hrdata[6]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u55 (
    .a(hsel_ocf),
    .b(hrdata_fsb[5]),
    .c(hrdata_ocf[5]),
    .o(hrdata[5]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u56 (
    .a(hsel_ocf),
    .b(hrdata_fsb[4]),
    .c(hrdata_ocf[4]),
    .o(hrdata[4]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u57 (
    .a(hsel_ocf),
    .b(hrdata_fsb[3]),
    .c(hrdata_ocf[3]),
    .o(hrdata[3]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u58 (
    .a(hsel_ocf),
    .b(hrdata_fsb[2]),
    .c(hrdata_ocf[2]),
    .o(hrdata[2]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u59 (
    .a(hsel_ocf),
    .b(hrdata_fsb[1]),
    .c(hrdata_ocf[1]),
    .o(hrdata[1]));
  AL_PHY_PAD #(
    //.PCICLAMP("OFF"),
    //.PULLMODE("NONE"),
    //.SLEWRATE("SLOW"),
    .DRIVE("8"),
    .GSR("DISABLE"),
    .IOTYPE("LVCMOS25"),
    .MODE("OUT"),
    .TSMUX("0"))
    _al_u6 (
    .otrue(AAH8_pad[1]),
    .opad(AAH8[1]));  // ../RTL/top/MIN_LS1u.v(23)
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u60 (
    .a(hsel_ocf),
    .b(hrdata_fsb[0]),
    .c(hrdata_ocf[0]),
    .o(hrdata[0]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(~C*~A))"),
    .INIT(8'hc8))
    _al_u61 (
    .a(hsel_ocf),
    .b(\FSB8_CONTROLLER/eq3/or_xor_i0[0]_i1[0]_o_o ),
    .c(\FSB8_CONTROLLER/eq4/or_xor_i0[0]_i1[0]_o_o ),
    .o(_al_u61_o));
  AL_MAP_LUT4 #(
    .EQN("~(~(C*~B)*~(D*A))"),
    .INIT(16'hba30))
    _al_u62 (
    .a(_al_u61_o),
    .b(\FSB8_CONTROLLER/eq3/or_xor_i0[0]_i1[0]_o_o ),
    .c(haddr[15]),
    .d(hwdata[7]),
    .o(AD_out[7]));
  AL_MAP_LUT4 #(
    .EQN("~(~(C*~B)*~(D*A))"),
    .INIT(16'hba30))
    _al_u63 (
    .a(_al_u61_o),
    .b(\FSB8_CONTROLLER/eq3/or_xor_i0[0]_i1[0]_o_o ),
    .c(haddr[14]),
    .d(hwdata[6]),
    .o(AD_out[6]));
  AL_MAP_LUT4 #(
    .EQN("~(~(C*~B)*~(D*A))"),
    .INIT(16'hba30))
    _al_u64 (
    .a(_al_u61_o),
    .b(\FSB8_CONTROLLER/eq3/or_xor_i0[0]_i1[0]_o_o ),
    .c(haddr[13]),
    .d(hwdata[5]),
    .o(AD_out[5]));
  AL_MAP_LUT4 #(
    .EQN("~(~(C*~B)*~(D*A))"),
    .INIT(16'hba30))
    _al_u65 (
    .a(_al_u61_o),
    .b(\FSB8_CONTROLLER/eq3/or_xor_i0[0]_i1[0]_o_o ),
    .c(haddr[12]),
    .d(hwdata[4]),
    .o(AD_out[4]));
  AL_MAP_LUT4 #(
    .EQN("~(~(C*~B)*~(D*A))"),
    .INIT(16'hba30))
    _al_u66 (
    .a(_al_u61_o),
    .b(\FSB8_CONTROLLER/eq3/or_xor_i0[0]_i1[0]_o_o ),
    .c(haddr[11]),
    .d(hwdata[3]),
    .o(AD_out[3]));
  AL_MAP_LUT4 #(
    .EQN("~(~(C*~B)*~(D*A))"),
    .INIT(16'hba30))
    _al_u67 (
    .a(_al_u61_o),
    .b(\FSB8_CONTROLLER/eq3/or_xor_i0[0]_i1[0]_o_o ),
    .c(haddr[10]),
    .d(hwdata[2]),
    .o(AD_out[2]));
  AL_MAP_LUT4 #(
    .EQN("~(~(C*~B)*~(D*A))"),
    .INIT(16'hba30))
    _al_u68 (
    .a(_al_u61_o),
    .b(\FSB8_CONTROLLER/eq3/or_xor_i0[0]_i1[0]_o_o ),
    .c(haddr[9]),
    .d(hwdata[1]),
    .o(AD_out[1]));
  AL_MAP_LUT4 #(
    .EQN("~(~(C*~B)*~(D*A))"),
    .INIT(16'hba30))
    _al_u69 (
    .a(_al_u61_o),
    .b(\FSB8_CONTROLLER/eq3/or_xor_i0[0]_i1[0]_o_o ),
    .c(haddr[8]),
    .d(hwdata[0]),
    .o(AD_out[0]));
  AL_PHY_PAD #(
    //.PCICLAMP("OFF"),
    //.PULLMODE("NONE"),
    //.SLEWRATE("SLOW"),
    .DRIVE("8"),
    .GSR("DISABLE"),
    .IOTYPE("LVCMOS25"),
    .MODE("OUT"),
    .TSMUX("0"))
    _al_u7 (
    .otrue(AAH8_pad[0]),
    .opad(AAH8[0]));  // ../RTL/top/MIN_LS1u.v(23)
  AL_MAP_LUT3 #(
    .EQN("(~C*B*A)"),
    .INIT(8'h08))
    _al_u70 (
    .a(\FSB8_CONTROLLER/n24 ),
    .b(htrans),
    .c(\FSB8_CONTROLLER/state [1]),
    .o(_al_u70_o));
  AL_MAP_LUT4 #(
    .EQN("(A*~(D*~C*B))"),
    .INIT(16'ha2aa))
    _al_u71 (
    .a(_al_u70_o),
    .b(_al_u43_o),
    .c(_al_u44_o),
    .d(_al_u42_o),
    .o(_al_u71_o));
  AL_MAP_LUT5 #(
    .EQN("(~E*~(D*C*B*A))"),
    .INIT(32'h00007fff))
    _al_u72 (
    .a(_al_u49_o),
    .b(_al_u50_o),
    .c(_al_u51_o),
    .d(_al_u48_o),
    .e(SYNC_MODE),
    .o(\FSB8_CONTROLLER/n2_lutinv ));
  AL_MAP_LUT2 #(
    .EQN("(~B*~A)"),
    .INIT(4'h1))
    _al_u73 (
    .a(\FSB8_CONTROLLER/n2_lutinv ),
    .b(rdy_n_pad),
    .o(\FSB8_CONTROLLER/n15_lutinv ));
  AL_MAP_LUT5 #(
    .EQN("(~(B)*~(C)*~(D)*~((~E*~A))+B*~(C)*~(D)*~((~E*~A))+~(B)*C*~(D)*~((~E*~A))+B*C*~(D)*~((~E*~A))+~(B)*C*D*~((~E*~A))+~(B)*~(C)*~(D)*(~E*~A)+~(B)*C*~(D)*(~E*~A)+~(B)*C*D*(~E*~A))"),
    .INIT(32'h30ff30bb))
    _al_u74 (
    .a(\FSB8_CONTROLLER/n2_lutinv ),
    .b(hsel_ocf),
    .c(_al_u70_o),
    .d(\FSB8_CONTROLLER/eq4/or_xor_i0[0]_i1[0]_o_o ),
    .e(rdy_n_pad),
    .o(_al_u74_o));
  AL_MAP_LUT4 #(
    .EQN("(D*~(C*~(B*~A)))"),
    .INIT(16'h4f00))
    _al_u75 (
    .a(hsel_ocf),
    .b(hburst),
    .c(\FSB8_CONTROLLER/state [0]),
    .d(\FSB8_CONTROLLER/state [1]),
    .o(_al_u75_o));
  AL_MAP_LUT3 #(
    .EQN("(~C*~(B*~A))"),
    .INIT(8'h0b))
    _al_u76 (
    .a(hsel_ocf),
    .b(hburst),
    .c(rdy_n_pad),
    .o(_al_u76_o));
  AL_MAP_LUT5 #(
    .EQN("~(~B*~(~E*(D*~(C)*~(A)+D*C*~(A)+~(D)*C*A+D*C*A)))"),
    .INIT(32'hccccfdec))
    _al_u77 (
    .a(\FSB8_CONTROLLER/n15_lutinv ),
    .b(_al_u74_o),
    .c(_al_u75_o),
    .d(\FSB8_CONTROLLER/state [0]),
    .e(\FSB8_CONTROLLER/state [2]),
    .o(\FSB8_CONTROLLER/n17 [0]));
  AL_MAP_LUT5 #(
    .EQN("~(~C*~((D*~B))*~((~E*~A))+~C*(D*~B)*~((~E*~A))+~(~C)*(D*~B)*(~E*~A)+~C*(D*~B)*(~E*~A))"),
    .INIT(32'hf0f0e4f5))
    _al_u78 (
    .a(\FSB8_CONTROLLER/n2_lutinv ),
    .b(\FSB8_CONTROLLER/eq3/or_xor_i0[0]_i1[0]_o_o ),
    .c(\FSB8_CONTROLLER/eq4/or_xor_i0[0]_i1[0]_o_o ),
    .d(\FSB8_CONTROLLER/rwsel ),
    .e(rdy_n_pad),
    .o(_al_u78_o));
  AL_MAP_LUT5 #(
    .EQN("~(~C*A*~(~E*~(~D*B)))"),
    .INIT(32'hf5f5fff7))
    _al_u79 (
    .a(_al_u78_o),
    .b(_al_u76_o),
    .c(_al_u71_o),
    .d(\FSB8_CONTROLLER/n2_lutinv ),
    .e(\FSB8_CONTROLLER/eq5/or_xor_i0[0]_i1[0]_o_o ),
    .o(\FSB8_CONTROLLER/n17 [2]));
  AL_PHY_PAD #(
    //.PCICLAMP("OFF"),
    //.PULLMODE("NONE"),
    //.SLEWRATE("SLOW"),
    .DRIVE("8"),
    .GSR("DISABLE"),
    .IOTYPE("LVCMOS25"),
    .MODE("OUT"),
    .TSMUX("0"))
    _al_u8 (
    .otrue(\FSB8_CONTROLLER/eq3/or_xor_i0[0]_i1[0]_o_o ),
    .opad(ale_n));  // ../RTL/top/MIN_LS1u.v(15)
  AL_MAP_LUT4 #(
    .EQN("(B*~(~D*~(C*~A)))"),
    .INIT(16'hcc40))
    _al_u80 (
    .a(hsel_ocf),
    .b(\FSB8_CONTROLLER/n24 ),
    .c(htrans),
    .d(\FSB8_CONTROLLER/state [1]),
    .o(_al_u80_o));
  AL_MAP_LUT5 #(
    .EQN("~(~C*~((~D*~B))*~((~E*~A))+~C*(~D*~B)*~((~E*~A))+~(~C)*(~D*~B)*(~E*~A)+~C*(~D*~B)*(~E*~A))"),
    .INIT(32'hf0f0f5e4))
    _al_u81 (
    .a(\FSB8_CONTROLLER/n2_lutinv ),
    .b(\FSB8_CONTROLLER/eq3/or_xor_i0[0]_i1[0]_o_o ),
    .c(\FSB8_CONTROLLER/eq4/or_xor_i0[0]_i1[0]_o_o ),
    .d(\FSB8_CONTROLLER/rwsel ),
    .e(rdy_n_pad),
    .o(_al_u81_o));
  AL_MAP_LUT5 #(
    .EQN("~(~C*A*~(E*~(~D*B)))"),
    .INIT(32'hfff7f5f5))
    _al_u82 (
    .a(_al_u81_o),
    .b(_al_u76_o),
    .c(_al_u80_o),
    .d(\FSB8_CONTROLLER/n2_lutinv ),
    .e(_al_u33_o),
    .o(\FSB8_CONTROLLER/n17 [1]));
  AL_MAP_LUT4 #(
    .EQN("(A*~(B)*~(C)*~(D)+~(A)*B*~(C)*~(D)+A*B*~(C)*~(D)+~(A)*~(B)*C*~(D)+A*~(B)*C*~(D)+~(A)*B*~(C)*D+A*B*~(C)*D+~(A)*~(B)*C*D+A*~(B)*C*D+~(A)*B*C*D+A*B*C*D)"),
    .INIT(16'hfc3e))
    _al_u83 (
    .a(htrans),
    .b(\FSB8_CONTROLLER/state [0]),
    .c(\FSB8_CONTROLLER/state [1]),
    .d(\FSB8_CONTROLLER/state [2]),
    .o(_al_u83_o));
  AL_MAP_LUT3 #(
    .EQN("~(~B*~(~C*A))"),
    .INIT(8'hce))
    _al_u84 (
    .a(\FSB8_CONTROLLER/n15_lutinv ),
    .b(hsel_ocf),
    .c(_al_u83_o),
    .o(hready));
  AL_MAP_LUT1 #(
    .EQN("(~A)"),
    .INIT(2'h1))
    _al_u85 (
    .a(rst),
    .o(rst_neg));
  AL_MAP_LUT1 #(
    .EQN("(~A)"),
    .INIT(2'h1))
    _al_u86 (
    .a(irq_n_pad),
    .o(FSB_IRQ));
  AL_MAP_LUT1 #(
    .EQN("(~A)"),
    .INIT(2'h1))
    _al_u87 (
    .a(sysrst_n_pad),
    .o(n0));
  AL_PHY_PAD #(
    //.PCICLAMP("OFF"),
    //.PULLMODE("NONE"),
    //.SLEWRATE("SLOW"),
    .DRIVE("8"),
    .GSR("DISABLE"),
    .IOTYPE("LVCMOS25"),
    .MODE("OUT"),
    .TSMUX("0"))
    _al_u9 (
    .otrue(clk),
    .opad(busclk));  // ../RTL/top/MIN_LS1u.v(13)

endmodule 

module CPU_LS1u  // ../RTL/cpu/CPU_LS1u.v(1)
  (
  INT,
  IVEC_addr,
  clk,
  dpae_h16,
  dpte_h8,
  force_svpriv,
  hrdata,
  hready,
  hreset_n,
  hresp,
  hugepage_ptr,
  ipae_h16,
  ipte_h8,
  mmu_enable,
  rst,
  IN_ISP,
  XCP_ARR,
  haddr,
  hburst,
  htrans,
  hwdata,
  hwrite
  );

  input INT;  // ../RTL/cpu/CPU_LS1u.v(13)
  input [23:0] IVEC_addr;  // ../RTL/cpu/CPU_LS1u.v(14)
  input clk;  // ../RTL/cpu/CPU_LS1u.v(11)
  input [15:0] dpae_h16;  // ../RTL/cpu/CPU_LS1u.v(19)
  input [7:0] dpte_h8;  // ../RTL/cpu/CPU_LS1u.v(21)
  input force_svpriv;  // ../RTL/cpu/CPU_LS1u.v(24)
  input [7:0] hrdata;  // ../RTL/cpu/CPU_LS1u.v(34)
  input hready;  // ../RTL/cpu/CPU_LS1u.v(31)
  input hreset_n;  // ../RTL/cpu/CPU_LS1u.v(33)
  input hresp;  // ../RTL/cpu/CPU_LS1u.v(32)
  input [10:0] hugepage_ptr;  // ../RTL/cpu/CPU_LS1u.v(22)
  input [15:0] ipae_h16;  // ../RTL/cpu/CPU_LS1u.v(18)
  input [7:0] ipte_h8;  // ../RTL/cpu/CPU_LS1u.v(20)
  input mmu_enable;  // ../RTL/cpu/CPU_LS1u.v(23)
  input rst;  // ../RTL/cpu/CPU_LS1u.v(11)
  output IN_ISP;  // ../RTL/cpu/CPU_LS1u.v(15)
  output [7:0] XCP_ARR;  // ../RTL/cpu/CPU_LS1u.v(16)
  output [31:0] haddr;  // ../RTL/cpu/CPU_LS1u.v(26)
  output hburst;  // ../RTL/cpu/CPU_LS1u.v(28)
  output htrans;  // ../RTL/cpu/CPU_LS1u.v(29)
  output [7:0] hwdata;  // ../RTL/cpu/CPU_LS1u.v(30)
  output hwrite;  // ../RTL/cpu/CPU_LS1u.v(27)

  parameter CACHE_DEPTH = 2048;
  parameter CACHE_TYP = 2'b00;
  parameter CACHE_WIDTH = 16;
  parameter ENTRY_NUM = 16;
  parameter MMU_ENABLE = 1'b1;
  parameter cDMA_ENABLE = 1'b0;
  // localparam BUS_ADDRWID = 32;
  wire [6:0] \AHB_INTERFACE/addr_counter ;  // ../RTL/cache/bus_unit.v(72)
  wire [31:0] \AHB_INTERFACE/haddr_temp ;  // ../RTL/cache/bus_unit.v(73)
  wire [7:0] \AHB_INTERFACE/last_addr ;  // ../RTL/cache/bus_unit.v(74)
  wire  \AHB_INTERFACE/mux6_b0/B2_0 ;  // ../RTL/cache/bus_unit.v(116)
  wire [3:0] \AHB_INTERFACE/n14 ;
  wire [6:0] \AHB_INTERFACE/n22 ;
  wire [6:0] \AHB_INTERFACE/n25 ;
  wire [3:0] \AHB_INTERFACE/statu ;  // ../RTL/cache/bus_unit.v(71)
  wire [6:0] addr_count;  // ../RTL/cpu/CPU_LS1u.v(75)
  wire [23:0] daddr;  // ../RTL/cpu/CPU_LS1u.v(38)
  wire [7:0] ddata_i;  // ../RTL/cpu/CPU_LS1u.v(41)
  wire [7:0] ddata_o;  // ../RTL/cpu/CPU_LS1u.v(42)
  wire [23:0] iaddr;  // ../RTL/cpu/CPU_LS1u.v(36)
  wire [15:0] instr;  // ../RTL/cpu/CPU_LS1u.v(37)
  wire [31:0] pa;  // ../RTL/cpu/CPU_LS1u.v(47)
  wire [23:0] pa_l1;  // ../RTL/cpu/CPU_LS1u.v(66)
  wire [7:0] wt_data;  // ../RTL/cpu/CPU_LS1u.v(73)
  wire \AHB_INTERFACE/add0/c3 ;  // ../RTL/cache/bus_unit.v(130)
  wire \AHB_INTERFACE/mux1_b0_sel_is_0_o ;
  wire \AHB_INTERFACE/mux9_b0_sel_is_3_o ;
  wire \AHB_INTERFACE/n17 ;
  wire \AHB_INTERFACE/n20 ;
  wire \AHB_INTERFACE/n27_lutinv ;
  wire \AHB_INTERFACE/n35 ;
  wire \AHB_INTERFACE/sub0/c1 ;  // ../RTL/cache/bus_unit.v(133)
  wire \AHB_INTERFACE/sub0/c3 ;  // ../RTL/cache/bus_unit.v(133)
  wire \AHB_INTERFACE/sub0/c5 ;  // ../RTL/cache/bus_unit.v(133)
  wire DREADY;  // ../RTL/cpu/CPU_LS1u.v(43)
  wire INSTR_HOLD;  // ../RTL/cpu/CPU_LS1u.v(44)
  wire \PAE32_MMU$MMU/mode_dly ;  // ../RTL/cache/pae32_mmu.v(24)
  wire \PAE32_MMU$MMU/mux2_b16_sel_is_1_o ;
  wire \PAE32_MMU$MMU/n3_lutinv ;
  wire READY;  // ../RTL/cpu/CPU_LS1u.v(43)
  wire _al_u100_o;
  wire _al_u101_o;
  wire _al_u30_o;
  wire _al_u34_o;
  wire _al_u55_o;
  wire _al_u57_o;
  wire _al_u58_o;
  wire _al_u59_o;
  wire _al_u69_o;
  wire _al_u70_o;
  wire _al_u71_o;
  wire _al_u73_o;
  wire _al_u75_o;
  wire _al_u77_o;
  wire _al_u79_o;
  wire _al_u81_o;
  wire _al_u83_o;
  wire _al_u85_o;
  wire _al_u86_o;
  wire _al_u88_o;
  wire _al_u89_o;
  wire _al_u91_o;
  wire _al_u92_o;
  wire _al_u94_o;
  wire _al_u96_o;
  wire _al_u97_o;
  wire bus_error;  // ../RTL/cpu/CPU_LS1u.v(79)
  wire cache_flush;  // ../RTL/cpu/CPU_LS1u.v(45)
  wire dread;  // ../RTL/cpu/CPU_LS1u.v(40)
  wire dwrite;  // ../RTL/cpu/CPU_LS1u.v(39)
  wire line_write;  // ../RTL/cpu/CPU_LS1u.v(76)
  wire n0;
  wire n1;
  wire n2;
  wire read_line_req;  // ../RTL/cpu/CPU_LS1u.v(72)
  wire read_req;  // ../RTL/cpu/CPU_LS1u.v(71)
  wire trans_rdy;  // ../RTL/cpu/CPU_LS1u.v(78)
  wire write_through_req;  // ../RTL/cpu/CPU_LS1u.v(70)

  assign XCP_ARR[7] = 1'b0;
  assign XCP_ARR[6] = 1'b0;
  assign XCP_ARR[5] = 1'b0;
  assign hburst = \AHB_INTERFACE/n20 ;
  assign htrans = \AHB_INTERFACE/n35 ;
  AL_PHY_LSLICE #(
    //.MACRO("AHB_INTERFACE/add0/ucin_al_u105"),
    //.R_POSITION("X0Y0Z1"),
    .DEMUX0("E"),
    .DEMUX1("E"),
    .GSR("DISABLE"),
    .INIT_LUTF0(16'hA55A),
    .INIT_LUTF1(16'hA55A),
    .INIT_LUTG0(16'hC33C),
    .INIT_LUTG1(16'hC33C),
    .LSFMUX0("SUM"),
    .LSFMUX1("SUM"),
    .LSFXMUX0("SUM"),
    .LSFXMUX1("SUM"),
    .MODE("RIPPLE"))
    \AHB_INTERFACE/add0/u3_al_u106  (
    .a({\AHB_INTERFACE/addr_counter [5],\AHB_INTERFACE/addr_counter [3]}),
    .b({\AHB_INTERFACE/addr_counter [6],\AHB_INTERFACE/addr_counter [4]}),
    .c(2'b00),
    .d(2'b00),
    .e(2'b00),
    .fci(\AHB_INTERFACE/add0/c3 ),
    .f({\AHB_INTERFACE/n22 [5],\AHB_INTERFACE/n22 [3]}),
    .fx({\AHB_INTERFACE/n22 [6],\AHB_INTERFACE/n22 [4]}));
  AL_PHY_LSLICE #(
    //.MACRO("AHB_INTERFACE/add0/ucin_al_u105"),
    //.R_POSITION("X0Y0Z0"),
    .DEMUX0("E"),
    .DEMUX1("E"),
    .GSR("DISABLE"),
    .INIT_LUTF0(16'h000A),
    .INIT_LUTF1(16'hA55A),
    .INIT_LUTG0(16'hC33C),
    .INIT_LUTG1(16'hC33C),
    .LSFMUX0("SUM"),
    .LSFMUX1("SUM"),
    .LSFXMUX0("SUM"),
    .LSFXMUX1("SUM"),
    .MODE("RIPPLE"))
    \AHB_INTERFACE/add0/ucin_al_u105  (
    .a({\AHB_INTERFACE/addr_counter [1],1'b0}),
    .b({\AHB_INTERFACE/addr_counter [2],\AHB_INTERFACE/addr_counter [0]}),
    .c(2'b00),
    .d(2'b01),
    .e(2'b01),
    .f({\AHB_INTERFACE/n22 [1],open_n36}),
    .fco(\AHB_INTERFACE/add0/c3 ),
    .fx({\AHB_INTERFACE/n22 [2],\AHB_INTERFACE/n22 [0]}));
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg0_b0  (
    .clk(clk),
    .d(\AHB_INTERFACE/n25 [0]),
    .sr(\AHB_INTERFACE/n17 ),
    .q(\AHB_INTERFACE/addr_counter [0]));  // ../RTL/cache/bus_unit.v(132)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg0_b1  (
    .clk(clk),
    .d(\AHB_INTERFACE/n25 [1]),
    .sr(\AHB_INTERFACE/n17 ),
    .q(\AHB_INTERFACE/addr_counter [1]));  // ../RTL/cache/bus_unit.v(132)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg0_b2  (
    .clk(clk),
    .d(\AHB_INTERFACE/n25 [2]),
    .sr(\AHB_INTERFACE/n17 ),
    .q(\AHB_INTERFACE/addr_counter [2]));  // ../RTL/cache/bus_unit.v(132)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg0_b3  (
    .clk(clk),
    .d(\AHB_INTERFACE/n25 [3]),
    .sr(\AHB_INTERFACE/n17 ),
    .q(\AHB_INTERFACE/addr_counter [3]));  // ../RTL/cache/bus_unit.v(132)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg0_b4  (
    .clk(clk),
    .d(\AHB_INTERFACE/n25 [4]),
    .sr(\AHB_INTERFACE/n17 ),
    .q(\AHB_INTERFACE/addr_counter [4]));  // ../RTL/cache/bus_unit.v(132)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg0_b5  (
    .clk(clk),
    .d(\AHB_INTERFACE/n25 [5]),
    .sr(\AHB_INTERFACE/n17 ),
    .q(\AHB_INTERFACE/addr_counter [5]));  // ../RTL/cache/bus_unit.v(132)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg0_b6  (
    .clk(clk),
    .d(\AHB_INTERFACE/n25 [6]),
    .sr(\AHB_INTERFACE/n17 ),
    .q(\AHB_INTERFACE/addr_counter [6]));  // ../RTL/cache/bus_unit.v(132)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg1_b0  (
    .clk(clk),
    .d(wt_data[0]),
    .sr(rst),
    .q(hwdata[0]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg1_b1  (
    .clk(clk),
    .d(wt_data[1]),
    .sr(rst),
    .q(hwdata[1]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg1_b2  (
    .clk(clk),
    .d(wt_data[2]),
    .sr(rst),
    .q(hwdata[2]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg1_b3  (
    .clk(clk),
    .d(wt_data[3]),
    .sr(rst),
    .q(hwdata[3]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg1_b4  (
    .clk(clk),
    .d(wt_data[4]),
    .sr(rst),
    .q(hwdata[4]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg1_b5  (
    .clk(clk),
    .d(wt_data[5]),
    .sr(rst),
    .q(hwdata[5]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg1_b6  (
    .clk(clk),
    .d(wt_data[6]),
    .sr(rst),
    .q(hwdata[6]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg1_b7  (
    .clk(clk),
    .d(wt_data[7]),
    .sr(rst),
    .q(hwdata[7]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b0  (
    .clk(clk),
    .d(pa_l1[0]),
    .sr(rst),
    .q(\AHB_INTERFACE/haddr_temp [0]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b1  (
    .clk(clk),
    .d(pa_l1[1]),
    .sr(rst),
    .q(\AHB_INTERFACE/haddr_temp [1]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b10  (
    .clk(clk),
    .d(pa_l1[10]),
    .sr(rst),
    .q(haddr[10]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b11  (
    .clk(clk),
    .d(pa_l1[11]),
    .sr(rst),
    .q(haddr[11]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b12  (
    .clk(clk),
    .d(pa_l1[12]),
    .sr(rst),
    .q(haddr[12]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b13  (
    .clk(clk),
    .d(pa_l1[13]),
    .sr(rst),
    .q(haddr[13]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b14  (
    .clk(clk),
    .d(pa_l1[14]),
    .sr(rst),
    .q(haddr[14]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b15  (
    .clk(clk),
    .d(pa_l1[15]),
    .sr(rst),
    .q(haddr[15]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b16  (
    .clk(clk),
    .d(pa[16]),
    .sr(rst),
    .q(haddr[16]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b17  (
    .clk(clk),
    .d(pa[17]),
    .sr(rst),
    .q(haddr[17]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b18  (
    .clk(clk),
    .d(pa[18]),
    .sr(rst),
    .q(haddr[18]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b19  (
    .clk(clk),
    .d(pa[19]),
    .sr(rst),
    .q(haddr[19]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b2  (
    .clk(clk),
    .d(pa_l1[2]),
    .sr(rst),
    .q(\AHB_INTERFACE/haddr_temp [2]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b20  (
    .clk(clk),
    .d(pa[20]),
    .sr(rst),
    .q(haddr[20]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b21  (
    .clk(clk),
    .d(pa[21]),
    .sr(rst),
    .q(haddr[21]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b22  (
    .clk(clk),
    .d(pa[22]),
    .sr(rst),
    .q(haddr[22]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b23  (
    .clk(clk),
    .d(pa[23]),
    .sr(rst),
    .q(haddr[23]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b24  (
    .clk(clk),
    .d(pa[24]),
    .sr(rst),
    .q(haddr[24]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b25  (
    .clk(clk),
    .d(pa[25]),
    .sr(rst),
    .q(haddr[25]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b26  (
    .clk(clk),
    .d(pa[26]),
    .sr(rst),
    .q(haddr[26]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b27  (
    .clk(clk),
    .d(pa[27]),
    .sr(rst),
    .q(haddr[27]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b28  (
    .clk(clk),
    .d(pa[28]),
    .sr(rst),
    .q(haddr[28]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b29  (
    .clk(clk),
    .d(pa[29]),
    .sr(rst),
    .q(haddr[29]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b3  (
    .clk(clk),
    .d(pa_l1[3]),
    .sr(rst),
    .q(\AHB_INTERFACE/haddr_temp [3]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b30  (
    .clk(clk),
    .d(pa[30]),
    .sr(rst),
    .q(haddr[30]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b31  (
    .clk(clk),
    .d(pa[31]),
    .sr(rst),
    .q(haddr[31]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b4  (
    .clk(clk),
    .d(pa_l1[4]),
    .sr(rst),
    .q(\AHB_INTERFACE/haddr_temp [4]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b5  (
    .clk(clk),
    .d(pa_l1[5]),
    .sr(rst),
    .q(\AHB_INTERFACE/haddr_temp [5]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b6  (
    .clk(clk),
    .d(pa_l1[6]),
    .sr(rst),
    .q(\AHB_INTERFACE/haddr_temp [6]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b7  (
    .clk(clk),
    .d(pa_l1[7]),
    .sr(rst),
    .q(haddr[7]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b8  (
    .clk(clk),
    .d(pa_l1[8]),
    .sr(rst),
    .q(haddr[8]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg2_b9  (
    .clk(clk),
    .d(pa_l1[9]),
    .sr(rst),
    .q(haddr[9]));  // ../RTL/cache/bus_unit.v(150)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg3_b0  (
    .clk(clk),
    .d(\AHB_INTERFACE/n14 [0]),
    .sr(rst),
    .q(\AHB_INTERFACE/statu [0]));  // ../RTL/cache/bus_unit.v(118)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg3_b1  (
    .clk(clk),
    .d(\AHB_INTERFACE/n14 [1]),
    .sr(rst),
    .q(\AHB_INTERFACE/statu [1]));  // ../RTL/cache/bus_unit.v(118)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg3_b2  (
    .clk(clk),
    .d(\AHB_INTERFACE/n14 [2]),
    .sr(rst),
    .q(\AHB_INTERFACE/statu [2]));  // ../RTL/cache/bus_unit.v(118)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \AHB_INTERFACE/reg3_b3  (
    .clk(clk),
    .d(\AHB_INTERFACE/n14 [3]),
    .sr(rst),
    .q(\AHB_INTERFACE/statu [3]));  // ../RTL/cache/bus_unit.v(118)
  AL_PHY_MSLICE #(
    //.MACRO("AHB_INTERFACE/sub0/u0|AHB_INTERFACE/sub0/ucin"),
    //.R_POSITION("X0Y0Z0"),
    .ALUTYPE("SUB_CARRY"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b0000000000000101),
    .INIT_LUT1(16'b1001100110011010),
    .MODE("RIPPLE"))
    \AHB_INTERFACE/sub0/u0|AHB_INTERFACE/sub0/ucin  (
    .a({\AHB_INTERFACE/addr_counter [0],1'b0}),
    .b({1'b1,open_n90}),
    .f({\AHB_INTERFACE/last_addr [0],open_n110}),
    .fco(\AHB_INTERFACE/sub0/c1 ));
  AL_PHY_MSLICE #(
    //.MACRO("AHB_INTERFACE/sub0/u0|AHB_INTERFACE/sub0/ucin"),
    //.R_POSITION("X0Y0Z1"),
    .ALUTYPE("SUB"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011010),
    .INIT_LUT1(16'b1001100110011010),
    .MODE("RIPPLE"))
    \AHB_INTERFACE/sub0/u2|AHB_INTERFACE/sub0/u1  (
    .a(\AHB_INTERFACE/addr_counter [2:1]),
    .b(2'b00),
    .fci(\AHB_INTERFACE/sub0/c1 ),
    .f(\AHB_INTERFACE/last_addr [2:1]),
    .fco(\AHB_INTERFACE/sub0/c3 ));
  AL_PHY_MSLICE #(
    //.MACRO("AHB_INTERFACE/sub0/u0|AHB_INTERFACE/sub0/ucin"),
    //.R_POSITION("X0Y1Z0"),
    .ALUTYPE("SUB"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011010),
    .INIT_LUT1(16'b1001100110011010),
    .MODE("RIPPLE"))
    \AHB_INTERFACE/sub0/u4|AHB_INTERFACE/sub0/u3  (
    .a(\AHB_INTERFACE/addr_counter [4:3]),
    .b(2'b00),
    .fci(\AHB_INTERFACE/sub0/c3 ),
    .f(\AHB_INTERFACE/last_addr [4:3]),
    .fco(\AHB_INTERFACE/sub0/c5 ));
  AL_PHY_MSLICE #(
    //.MACRO("AHB_INTERFACE/sub0/u0|AHB_INTERFACE/sub0/ucin"),
    //.R_POSITION("X0Y1Z1"),
    .ALUTYPE("SUB"),
    .GSR("DISABLE"),
    .INIT_LUT0(16'b1001100110011010),
    .INIT_LUT1(16'b1001100110011010),
    .MODE("RIPPLE"))
    \AHB_INTERFACE/sub0/u6|AHB_INTERFACE/sub0/u5  (
    .a(\AHB_INTERFACE/addr_counter [6:5]),
    .b(2'b00),
    .fci(\AHB_INTERFACE/sub0/c5 ),
    .f(\AHB_INTERFACE/last_addr [6:5]));
  KC_LS1u_plus CORE (
    .INT(INT),
    .IVEC_addr({1'b0,IVEC_addr[22:0]}),
    .WAIT(n0),
    .WAIT_DATA(n1),
    .clk(clk),
    .ddata_i(ddata_i),
    .instr(instr),
    .rst(rst),
    .INSTR_HOLD(INSTR_HOLD),
    .IN_ISP(IN_ISP),
    .daddr(daddr),
    .ddata_o(ddata_o),
    .dread(dread),
    .dwrite(dwrite),
    .iaddr({open_n182,iaddr[22:0]}));  // ../RTL/cpu/CPU_LS1u.v(48)
  \l1_ionly(ENTRY_NUM=16,CACHE_DEPTH=2048)  L1_I_Only$L1CX (
    .L1_clear(cache_flush),
    .addr_count({1'b0,addr_count}),
    .addr_pa_d(daddr),
    .addr_pa_i(iaddr[22:0]),
    .bclk(1'b0),
    .bus_error(bus_error),
    .bus_rdata(hrdata),
    .bus_trans_finish(trans_rdy),
    .clk(clk),
    .cwait(INSTR_HOLD),
    .execute(1'b1),
    .host_wdata(ddata_o),
    .line_write(line_write),
    .read(dread),
    .rst(rst),
    .write(dwrite),
    .bus_pa(pa_l1),
    .bus_wdata(wt_data),
    .cache_data_ready(READY),
    .host_rdata(ddata_i),
    .instr_read(instr),
    .read_line_req(read_line_req),
    .read_req(read_req),
    .uncache_data_ready(DREADY),
    .write_through_req(write_through_req));  // ../RTL/cpu/CPU_LS1u.v(88)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("SET"),
    .SRMODE("SYNC"),
    .SRMUX("INV"))
    \PAE32_MMU$MMU/mode_dly_reg  (
    .clk(clk),
    .d(n2),
    .sr(mmu_enable),
    .q(\PAE32_MMU$MMU/mode_dly ));  // ../RTL/cache/pae32_mmu.v(37)
  AL_MAP_LUT4 #(
    .EQN("(D*A*~(C*B))"),
    .INIT(16'h2a00))
    _al_u100 (
    .a(_al_u34_o),
    .b(hready),
    .c(\AHB_INTERFACE/statu [0]),
    .d(\AHB_INTERFACE/statu [1]),
    .o(_al_u100_o));
  AL_MAP_LUT5 #(
    .EQN("(E*D*C*B*A)"),
    .INIT(32'h80000000))
    _al_u101 (
    .a(_al_u57_o),
    .b(_al_u58_o),
    .c(hready),
    .d(\AHB_INTERFACE/addr_counter [4]),
    .e(\AHB_INTERFACE/addr_counter [6]),
    .o(_al_u101_o));
  AL_MAP_LUT5 #(
    .EQN("~(~(~E*C)*~(B*~(~D*~A)))"),
    .INIT(32'hcc88fcf8))
    _al_u102 (
    .a(_al_u101_o),
    .b(_al_u100_o),
    .c(\AHB_INTERFACE/mux6_b0/B2_0 ),
    .d(\AHB_INTERFACE/statu [0]),
    .e(\AHB_INTERFACE/statu [3]),
    .o(\AHB_INTERFACE/n14 [0]));
  AL_MAP_LUT1 #(
    .EQN("(~A)"),
    .INIT(2'h1))
    _al_u103 (
    .a(READY),
    .o(n0));
  AL_MAP_LUT1 #(
    .EQN("(~A)"),
    .INIT(2'h1))
    _al_u104 (
    .a(DREADY),
    .o(n1));
  AL_MAP_LUT2 #(
    .EQN("~(~B*~A)"),
    .INIT(4'he))
    _al_u21 (
    .a(force_svpriv),
    .b(IN_ISP),
    .o(n2));
  AL_MAP_LUT3 #(
    .EQN("(B*~(A)*~(C)+B*A*~(C)+~(B)*A*C+B*A*C)"),
    .INIT(8'hac))
    _al_u22 (
    .a(\AHB_INTERFACE/addr_counter [6]),
    .b(\AHB_INTERFACE/haddr_temp [6]),
    .c(read_line_req),
    .o(haddr[6]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(A)*~(C)+B*A*~(C)+~(B)*A*C+B*A*C)"),
    .INIT(8'hac))
    _al_u23 (
    .a(\AHB_INTERFACE/addr_counter [5]),
    .b(\AHB_INTERFACE/haddr_temp [5]),
    .c(read_line_req),
    .o(haddr[5]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(A)*~(C)+B*A*~(C)+~(B)*A*C+B*A*C)"),
    .INIT(8'hac))
    _al_u24 (
    .a(\AHB_INTERFACE/addr_counter [4]),
    .b(\AHB_INTERFACE/haddr_temp [4]),
    .c(read_line_req),
    .o(haddr[4]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(A)*~(C)+B*A*~(C)+~(B)*A*C+B*A*C)"),
    .INIT(8'hac))
    _al_u25 (
    .a(\AHB_INTERFACE/addr_counter [3]),
    .b(\AHB_INTERFACE/haddr_temp [3]),
    .c(read_line_req),
    .o(haddr[3]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(A)*~(C)+B*A*~(C)+~(B)*A*C+B*A*C)"),
    .INIT(8'hac))
    _al_u26 (
    .a(\AHB_INTERFACE/addr_counter [2]),
    .b(\AHB_INTERFACE/haddr_temp [2]),
    .c(read_line_req),
    .o(haddr[2]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(A)*~(C)+B*A*~(C)+~(B)*A*C+B*A*C)"),
    .INIT(8'hac))
    _al_u27 (
    .a(\AHB_INTERFACE/addr_counter [1]),
    .b(\AHB_INTERFACE/haddr_temp [1]),
    .c(read_line_req),
    .o(haddr[1]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(A)*~(C)+B*A*~(C)+~(B)*A*C+B*A*C)"),
    .INIT(8'hac))
    _al_u28 (
    .a(\AHB_INTERFACE/addr_counter [0]),
    .b(\AHB_INTERFACE/haddr_temp [0]),
    .c(read_line_req),
    .o(haddr[0]));
  AL_MAP_LUT3 #(
    .EQN("(B*(C@A))"),
    .INIT(8'h48))
    _al_u29 (
    .a(n2),
    .b(mmu_enable),
    .c(\PAE32_MMU$MMU/mode_dly ),
    .o(cache_flush));
  AL_MAP_LUT2 #(
    .EQN("(~B*~A)"),
    .INIT(4'h1))
    _al_u30 (
    .a(\AHB_INTERFACE/statu [0]),
    .b(\AHB_INTERFACE/statu [3]),
    .o(_al_u30_o));
  AL_MAP_LUT3 #(
    .EQN("(~C*B*A)"),
    .INIT(8'h08))
    _al_u31 (
    .a(_al_u30_o),
    .b(\AHB_INTERFACE/statu [1]),
    .c(\AHB_INTERFACE/statu [2]),
    .o(hwrite));
  AL_MAP_LUT4 #(
    .EQN("(D*C*B*A)"),
    .INIT(16'h8000))
    _al_u32 (
    .a(\AHB_INTERFACE/statu [0]),
    .b(\AHB_INTERFACE/statu [1]),
    .c(\AHB_INTERFACE/statu [2]),
    .d(\AHB_INTERFACE/statu [3]),
    .o(bus_error));
  AL_MAP_LUT4 #(
    .EQN("~(~B*~(~D*~C*A))"),
    .INIT(16'hccce))
    _al_u33 (
    .a(_al_u30_o),
    .b(rst),
    .c(\AHB_INTERFACE/statu [1]),
    .d(\AHB_INTERFACE/statu [2]),
    .o(\AHB_INTERFACE/n17 ));
  AL_MAP_LUT2 #(
    .EQN("(B*~A)"),
    .INIT(4'h4))
    _al_u34 (
    .a(\AHB_INTERFACE/statu [2]),
    .b(\AHB_INTERFACE/statu [3]),
    .o(_al_u34_o));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u35 (
    .a(_al_u34_o),
    .b(\AHB_INTERFACE/statu [0]),
    .c(\AHB_INTERFACE/statu [1]),
    .o(\AHB_INTERFACE/n27_lutinv ));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u36 (
    .a(\AHB_INTERFACE/n27_lutinv ),
    .b(\AHB_INTERFACE/addr_counter [6]),
    .c(\AHB_INTERFACE/last_addr [6]),
    .o(addr_count[6]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u37 (
    .a(\AHB_INTERFACE/n27_lutinv ),
    .b(\AHB_INTERFACE/addr_counter [5]),
    .c(\AHB_INTERFACE/last_addr [5]),
    .o(addr_count[5]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u38 (
    .a(\AHB_INTERFACE/n27_lutinv ),
    .b(\AHB_INTERFACE/addr_counter [4]),
    .c(\AHB_INTERFACE/last_addr [4]),
    .o(addr_count[4]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u39 (
    .a(\AHB_INTERFACE/n27_lutinv ),
    .b(\AHB_INTERFACE/addr_counter [3]),
    .c(\AHB_INTERFACE/last_addr [3]),
    .o(addr_count[3]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u40 (
    .a(\AHB_INTERFACE/n27_lutinv ),
    .b(\AHB_INTERFACE/addr_counter [2]),
    .c(\AHB_INTERFACE/last_addr [2]),
    .o(addr_count[2]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u41 (
    .a(\AHB_INTERFACE/n27_lutinv ),
    .b(\AHB_INTERFACE/addr_counter [1]),
    .c(\AHB_INTERFACE/last_addr [1]),
    .o(addr_count[1]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u42 (
    .a(\AHB_INTERFACE/n27_lutinv ),
    .b(\AHB_INTERFACE/addr_counter [0]),
    .c(\AHB_INTERFACE/last_addr [0]),
    .o(addr_count[0]));
  AL_MAP_LUT3 #(
    .EQN("(A*(C@B))"),
    .INIT(8'h28))
    _al_u43 (
    .a(_al_u34_o),
    .b(\AHB_INTERFACE/statu [0]),
    .c(\AHB_INTERFACE/statu [1]),
    .o(\AHB_INTERFACE/n20 ));
  AL_MAP_LUT3 #(
    .EQN("(~C*B*~A)"),
    .INIT(8'h04))
    _al_u44 (
    .a(force_svpriv),
    .b(mmu_enable),
    .c(IN_ISP),
    .o(\PAE32_MMU$MMU/mux2_b16_sel_is_1_o ));
  AL_MAP_LUT2 #(
    .EQN("(~B*~A)"),
    .INIT(4'h1))
    _al_u45 (
    .a(read_req),
    .b(write_through_req),
    .o(\AHB_INTERFACE/mux1_b0_sel_is_0_o ));
  AL_MAP_LUT4 #(
    .EQN("(A*(C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B))"),
    .INIT(16'ha820))
    _al_u46 (
    .a(\PAE32_MMU$MMU/mux2_b16_sel_is_1_o ),
    .b(\AHB_INTERFACE/mux1_b0_sel_is_0_o ),
    .c(dpae_h16[15]),
    .d(ipae_h16[15]),
    .o(pa[31]));
  AL_MAP_LUT5 #(
    .EQN("(E*~((C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B))*~(A)+E*(C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B)*~(A)+~(E)*(C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B)*A+E*(C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B)*A)"),
    .INIT(32'hfd75a820))
    _al_u47 (
    .a(\PAE32_MMU$MMU/mux2_b16_sel_is_1_o ),
    .b(\AHB_INTERFACE/mux1_b0_sel_is_0_o ),
    .c(dpae_h16[4]),
    .d(ipae_h16[4]),
    .e(pa_l1[20]),
    .o(pa[20]));
  AL_MAP_LUT5 #(
    .EQN("(E*~((C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B))*~(A)+E*(C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B)*~(A)+~(E)*(C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B)*A+E*(C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B)*A)"),
    .INIT(32'hfd75a820))
    _al_u48 (
    .a(\PAE32_MMU$MMU/mux2_b16_sel_is_1_o ),
    .b(\AHB_INTERFACE/mux1_b0_sel_is_0_o ),
    .c(dpae_h16[3]),
    .d(ipae_h16[3]),
    .e(pa_l1[19]),
    .o(pa[19]));
  AL_MAP_LUT5 #(
    .EQN("(E*~((C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B))*~(A)+E*(C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B)*~(A)+~(E)*(C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B)*A+E*(C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B)*A)"),
    .INIT(32'hfd75a820))
    _al_u49 (
    .a(\PAE32_MMU$MMU/mux2_b16_sel_is_1_o ),
    .b(\AHB_INTERFACE/mux1_b0_sel_is_0_o ),
    .c(dpae_h16[2]),
    .d(ipae_h16[2]),
    .e(pa_l1[18]),
    .o(pa[18]));
  AL_MAP_LUT5 #(
    .EQN("(E*~((C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B))*~(A)+E*(C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B)*~(A)+~(E)*(C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B)*A+E*(C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B)*A)"),
    .INIT(32'hfd75a820))
    _al_u50 (
    .a(\PAE32_MMU$MMU/mux2_b16_sel_is_1_o ),
    .b(\AHB_INTERFACE/mux1_b0_sel_is_0_o ),
    .c(dpae_h16[1]),
    .d(ipae_h16[1]),
    .e(pa_l1[17]),
    .o(pa[17]));
  AL_MAP_LUT5 #(
    .EQN("(E*~((C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B))*~(A)+E*(C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B)*~(A)+~(E)*(C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B)*A+E*(C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B)*A)"),
    .INIT(32'hfd75a820))
    _al_u51 (
    .a(\PAE32_MMU$MMU/mux2_b16_sel_is_1_o ),
    .b(\AHB_INTERFACE/mux1_b0_sel_is_0_o ),
    .c(dpae_h16[0]),
    .d(ipae_h16[0]),
    .e(pa_l1[16]),
    .o(pa[16]));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u52 (
    .a(_al_u34_o),
    .b(hready),
    .c(\AHB_INTERFACE/statu [1]),
    .o(line_write));
  AL_MAP_LUT5 #(
    .EQN("(B*A*(C*~(D)*~(E)+~(C)*D*~(E)+C*~(D)*E))"),
    .INIT(32'h00800880))
    _al_u53 (
    .a(hready),
    .b(\AHB_INTERFACE/statu [0]),
    .c(\AHB_INTERFACE/statu [1]),
    .d(\AHB_INTERFACE/statu [2]),
    .e(\AHB_INTERFACE/statu [3]),
    .o(trans_rdy));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*B*~(C)*~(D)+~(A)*~(B)*C*~(D)+A*~(B)*~(C)*D+~(A)*B*~(C)*D)"),
    .INIT(16'h0614))
    _al_u54 (
    .a(\AHB_INTERFACE/statu [0]),
    .b(\AHB_INTERFACE/statu [1]),
    .c(\AHB_INTERFACE/statu [2]),
    .d(\AHB_INTERFACE/statu [3]),
    .o(\AHB_INTERFACE/n35 ));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~((E*~D))+A*~(B)*~(C)*~((E*~D))+~(A)*B*~(C)*~((E*~D))+A*B*~(C)*~((E*~D))+A*B*C*~((E*~D))+~(A)*B*~(C)*(E*~D)+A*B*~(C)*(E*~D)+A*B*C*(E*~D))"),
    .INIT(32'h8f8c8f8f))
    _al_u55 (
    .a(hready),
    .b(\AHB_INTERFACE/statu [0]),
    .c(\AHB_INTERFACE/statu [2]),
    .d(read_line_req),
    .e(read_req),
    .o(_al_u55_o));
  AL_MAP_LUT3 #(
    .EQN("(~C*~B*~A)"),
    .INIT(8'h01))
    _al_u56 (
    .a(_al_u55_o),
    .b(\AHB_INTERFACE/statu [1]),
    .c(\AHB_INTERFACE/statu [3]),
    .o(\AHB_INTERFACE/n14 [2]));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u57 (
    .a(\AHB_INTERFACE/addr_counter [2]),
    .b(\AHB_INTERFACE/addr_counter [3]),
    .c(\AHB_INTERFACE/addr_counter [5]),
    .o(_al_u57_o));
  AL_MAP_LUT2 #(
    .EQN("(B*A)"),
    .INIT(4'h8))
    _al_u58 (
    .a(\AHB_INTERFACE/addr_counter [0]),
    .b(\AHB_INTERFACE/addr_counter [1]),
    .o(_al_u58_o));
  AL_MAP_LUT4 #(
    .EQN("(D*C*B*A)"),
    .INIT(16'h8000))
    _al_u59 (
    .a(_al_u57_o),
    .b(_al_u58_o),
    .c(\AHB_INTERFACE/addr_counter [4]),
    .d(\AHB_INTERFACE/addr_counter [6]),
    .o(_al_u59_o));
  AL_MAP_LUT4 #(
    .EQN("(B*A*(D@C))"),
    .INIT(16'h0880))
    _al_u60 (
    .a(_al_u34_o),
    .b(hready),
    .c(\AHB_INTERFACE/statu [0]),
    .d(\AHB_INTERFACE/statu [1]),
    .o(\AHB_INTERFACE/mux9_b0_sel_is_3_o ));
  AL_MAP_LUT4 #(
    .EQN("~(~A*~(D*~(C)*~(B)+D*C*~(B)+~(D)*C*B+D*C*B))"),
    .INIT(16'hfbea))
    _al_u61 (
    .a(_al_u59_o),
    .b(\AHB_INTERFACE/mux9_b0_sel_is_3_o ),
    .c(\AHB_INTERFACE/n22 [6]),
    .d(\AHB_INTERFACE/addr_counter [6]),
    .o(\AHB_INTERFACE/n25 [6]));
  AL_MAP_LUT4 #(
    .EQN("~(~A*~(D*~(C)*~(B)+D*C*~(B)+~(D)*C*B+D*C*B))"),
    .INIT(16'hfbea))
    _al_u62 (
    .a(_al_u59_o),
    .b(\AHB_INTERFACE/mux9_b0_sel_is_3_o ),
    .c(\AHB_INTERFACE/n22 [5]),
    .d(\AHB_INTERFACE/addr_counter [5]),
    .o(\AHB_INTERFACE/n25 [5]));
  AL_MAP_LUT4 #(
    .EQN("~(~A*~(D*~(C)*~(B)+D*C*~(B)+~(D)*C*B+D*C*B))"),
    .INIT(16'hfbea))
    _al_u63 (
    .a(_al_u59_o),
    .b(\AHB_INTERFACE/mux9_b0_sel_is_3_o ),
    .c(\AHB_INTERFACE/n22 [4]),
    .d(\AHB_INTERFACE/addr_counter [4]),
    .o(\AHB_INTERFACE/n25 [4]));
  AL_MAP_LUT4 #(
    .EQN("~(~A*~(D*~(C)*~(B)+D*C*~(B)+~(D)*C*B+D*C*B))"),
    .INIT(16'hfbea))
    _al_u64 (
    .a(_al_u59_o),
    .b(\AHB_INTERFACE/mux9_b0_sel_is_3_o ),
    .c(\AHB_INTERFACE/n22 [3]),
    .d(\AHB_INTERFACE/addr_counter [3]),
    .o(\AHB_INTERFACE/n25 [3]));
  AL_MAP_LUT4 #(
    .EQN("~(~A*~(D*~(C)*~(B)+D*C*~(B)+~(D)*C*B+D*C*B))"),
    .INIT(16'hfbea))
    _al_u65 (
    .a(_al_u59_o),
    .b(\AHB_INTERFACE/mux9_b0_sel_is_3_o ),
    .c(\AHB_INTERFACE/n22 [2]),
    .d(\AHB_INTERFACE/addr_counter [2]),
    .o(\AHB_INTERFACE/n25 [2]));
  AL_MAP_LUT4 #(
    .EQN("~(~A*~(D*~(C)*~(B)+D*C*~(B)+~(D)*C*B+D*C*B))"),
    .INIT(16'hfbea))
    _al_u66 (
    .a(_al_u59_o),
    .b(\AHB_INTERFACE/mux9_b0_sel_is_3_o ),
    .c(\AHB_INTERFACE/n22 [1]),
    .d(\AHB_INTERFACE/addr_counter [1]),
    .o(\AHB_INTERFACE/n25 [1]));
  AL_MAP_LUT4 #(
    .EQN("~(~A*~(D*~(C)*~(B)+D*C*~(B)+~(D)*C*B+D*C*B))"),
    .INIT(16'hfbea))
    _al_u67 (
    .a(_al_u59_o),
    .b(\AHB_INTERFACE/mux9_b0_sel_is_3_o ),
    .c(\AHB_INTERFACE/n22 [0]),
    .d(\AHB_INTERFACE/addr_counter [0]),
    .o(\AHB_INTERFACE/n25 [0]));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u68 (
    .a(pa_l1[23]),
    .b(pa_l1[22]),
    .c(pa_l1[21]),
    .o(\PAE32_MMU$MMU/n3_lutinv ));
  AL_MAP_LUT4 #(
    .EQN("(~D*~C*B*~A)"),
    .INIT(16'h0004))
    _al_u69 (
    .a(n2),
    .b(mmu_enable),
    .c(read_req),
    .d(write_through_req),
    .o(_al_u69_o));
  AL_MAP_LUT3 #(
    .EQN("(A*~(~C*~B))"),
    .INIT(8'ha8))
    _al_u70 (
    .a(mmu_enable),
    .b(read_req),
    .c(write_through_req),
    .o(_al_u70_o));
  AL_MAP_LUT4 #(
    .EQN("~(C*~((D*A))*~(B)+C*(D*A)*~(B)+~(C)*(D*A)*B+C*(D*A)*B)"),
    .INIT(16'h47cf))
    _al_u71 (
    .a(\PAE32_MMU$MMU/n3_lutinv ),
    .b(n2),
    .c(dpae_h16[14]),
    .d(hugepage_ptr[9]),
    .o(_al_u71_o));
  AL_MAP_LUT4 #(
    .EQN("~(~(D*B)*~(C*~A))"),
    .INIT(16'hdc50))
    _al_u72 (
    .a(_al_u71_o),
    .b(_al_u69_o),
    .c(_al_u70_o),
    .d(ipae_h16[14]),
    .o(pa[30]));
  AL_MAP_LUT4 #(
    .EQN("~(C*~((D*A))*~(B)+C*(D*A)*~(B)+~(C)*(D*A)*B+C*(D*A)*B)"),
    .INIT(16'h47cf))
    _al_u73 (
    .a(\PAE32_MMU$MMU/n3_lutinv ),
    .b(n2),
    .c(dpae_h16[13]),
    .d(hugepage_ptr[8]),
    .o(_al_u73_o));
  AL_MAP_LUT4 #(
    .EQN("~(~(D*B)*~(C*~A))"),
    .INIT(16'hdc50))
    _al_u74 (
    .a(_al_u73_o),
    .b(_al_u69_o),
    .c(_al_u70_o),
    .d(ipae_h16[13]),
    .o(pa[29]));
  AL_MAP_LUT4 #(
    .EQN("~(C*~((D*A))*~(B)+C*(D*A)*~(B)+~(C)*(D*A)*B+C*(D*A)*B)"),
    .INIT(16'h47cf))
    _al_u75 (
    .a(\PAE32_MMU$MMU/n3_lutinv ),
    .b(n2),
    .c(dpae_h16[12]),
    .d(hugepage_ptr[7]),
    .o(_al_u75_o));
  AL_MAP_LUT4 #(
    .EQN("~(~(D*B)*~(C*~A))"),
    .INIT(16'hdc50))
    _al_u76 (
    .a(_al_u75_o),
    .b(_al_u69_o),
    .c(_al_u70_o),
    .d(ipae_h16[12]),
    .o(pa[28]));
  AL_MAP_LUT4 #(
    .EQN("~(C*~((D*A))*~(B)+C*(D*A)*~(B)+~(C)*(D*A)*B+C*(D*A)*B)"),
    .INIT(16'h47cf))
    _al_u77 (
    .a(\PAE32_MMU$MMU/n3_lutinv ),
    .b(n2),
    .c(dpae_h16[11]),
    .d(hugepage_ptr[6]),
    .o(_al_u77_o));
  AL_MAP_LUT4 #(
    .EQN("~(~(D*B)*~(C*~A))"),
    .INIT(16'hdc50))
    _al_u78 (
    .a(_al_u77_o),
    .b(_al_u69_o),
    .c(_al_u70_o),
    .d(ipae_h16[11]),
    .o(pa[27]));
  AL_MAP_LUT4 #(
    .EQN("~(C*~((D*A))*~(B)+C*(D*A)*~(B)+~(C)*(D*A)*B+C*(D*A)*B)"),
    .INIT(16'h47cf))
    _al_u79 (
    .a(\PAE32_MMU$MMU/n3_lutinv ),
    .b(n2),
    .c(dpae_h16[10]),
    .d(hugepage_ptr[5]),
    .o(_al_u79_o));
  AL_MAP_LUT4 #(
    .EQN("~(~(D*B)*~(C*~A))"),
    .INIT(16'hdc50))
    _al_u80 (
    .a(_al_u79_o),
    .b(_al_u69_o),
    .c(_al_u70_o),
    .d(ipae_h16[10]),
    .o(pa[26]));
  AL_MAP_LUT4 #(
    .EQN("~(C*~((D*A))*~(B)+C*(D*A)*~(B)+~(C)*(D*A)*B+C*(D*A)*B)"),
    .INIT(16'h47cf))
    _al_u81 (
    .a(\PAE32_MMU$MMU/n3_lutinv ),
    .b(n2),
    .c(dpae_h16[9]),
    .d(hugepage_ptr[4]),
    .o(_al_u81_o));
  AL_MAP_LUT4 #(
    .EQN("~(~(D*B)*~(C*~A))"),
    .INIT(16'hdc50))
    _al_u82 (
    .a(_al_u81_o),
    .b(_al_u69_o),
    .c(_al_u70_o),
    .d(ipae_h16[9]),
    .o(pa[25]));
  AL_MAP_LUT4 #(
    .EQN("~(C*~((D*A))*~(B)+C*(D*A)*~(B)+~(C)*(D*A)*B+C*(D*A)*B)"),
    .INIT(16'h47cf))
    _al_u83 (
    .a(\PAE32_MMU$MMU/n3_lutinv ),
    .b(n2),
    .c(dpae_h16[8]),
    .d(hugepage_ptr[3]),
    .o(_al_u83_o));
  AL_MAP_LUT4 #(
    .EQN("~(~(D*B)*~(C*~A))"),
    .INIT(16'hdc50))
    _al_u84 (
    .a(_al_u83_o),
    .b(_al_u69_o),
    .c(_al_u70_o),
    .d(ipae_h16[8]),
    .o(pa[24]));
  AL_MAP_LUT5 #(
    .EQN("~(~B*~((E*D*~C))*~(A)+~B*(E*D*~C)*~(A)+~(~B)*(E*D*~C)*A+~B*(E*D*~C)*A)"),
    .INIT(32'he4eeeeee))
    _al_u85 (
    .a(n2),
    .b(dpae_h16[7]),
    .c(hugepage_ptr[2]),
    .d(pa_l1[22]),
    .e(pa_l1[21]),
    .o(_al_u85_o));
  AL_MAP_LUT4 #(
    .EQN("~(~D*~((~C*B))*~(A)+~D*(~C*B)*~(A)+~(~D)*(~C*B)*A+~D*(~C*B)*A)"),
    .INIT(16'hf7a2))
    _al_u86 (
    .a(\PAE32_MMU$MMU/mux2_b16_sel_is_1_o ),
    .b(\AHB_INTERFACE/mux1_b0_sel_is_0_o ),
    .c(ipae_h16[7]),
    .d(pa_l1[23]),
    .o(_al_u86_o));
  AL_MAP_LUT3 #(
    .EQN("(A*~(C*~B))"),
    .INIT(8'h8a))
    _al_u87 (
    .a(_al_u86_o),
    .b(_al_u85_o),
    .c(_al_u70_o),
    .o(pa[23]));
  AL_MAP_LUT5 #(
    .EQN("~(~B*~((E*D*~C))*~(A)+~B*(E*D*~C)*~(A)+~(~B)*(E*D*~C)*A+~B*(E*D*~C)*A)"),
    .INIT(32'he4eeeeee))
    _al_u88 (
    .a(n2),
    .b(dpae_h16[6]),
    .c(hugepage_ptr[1]),
    .d(pa_l1[23]),
    .e(pa_l1[21]),
    .o(_al_u88_o));
  AL_MAP_LUT4 #(
    .EQN("~(~D*~((~C*B))*~(A)+~D*(~C*B)*~(A)+~(~D)*(~C*B)*A+~D*(~C*B)*A)"),
    .INIT(16'hf7a2))
    _al_u89 (
    .a(\PAE32_MMU$MMU/mux2_b16_sel_is_1_o ),
    .b(\AHB_INTERFACE/mux1_b0_sel_is_0_o ),
    .c(ipae_h16[6]),
    .d(pa_l1[22]),
    .o(_al_u89_o));
  AL_MAP_LUT3 #(
    .EQN("(A*~(C*~B))"),
    .INIT(8'h8a))
    _al_u90 (
    .a(_al_u89_o),
    .b(_al_u88_o),
    .c(_al_u70_o),
    .o(pa[22]));
  AL_MAP_LUT5 #(
    .EQN("~(~B*~((E*D*~C))*~(A)+~B*(E*D*~C)*~(A)+~(~B)*(E*D*~C)*A+~B*(E*D*~C)*A)"),
    .INIT(32'he4eeeeee))
    _al_u91 (
    .a(n2),
    .b(dpae_h16[5]),
    .c(hugepage_ptr[0]),
    .d(pa_l1[23]),
    .e(pa_l1[22]),
    .o(_al_u91_o));
  AL_MAP_LUT4 #(
    .EQN("~(~D*~((~C*B))*~(A)+~D*(~C*B)*~(A)+~(~D)*(~C*B)*A+~D*(~C*B)*A)"),
    .INIT(16'hf7a2))
    _al_u92 (
    .a(\PAE32_MMU$MMU/mux2_b16_sel_is_1_o ),
    .b(\AHB_INTERFACE/mux1_b0_sel_is_0_o ),
    .c(ipae_h16[5]),
    .d(pa_l1[21]),
    .o(_al_u92_o));
  AL_MAP_LUT3 #(
    .EQN("(A*~(C*~B))"),
    .INIT(8'h8a))
    _al_u93 (
    .a(_al_u92_o),
    .b(_al_u91_o),
    .c(_al_u70_o),
    .o(pa[21]));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+A*B*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+A*~(B)*~(C)*D*~(E)+A*B*C*D*~(E)+~(A)*B*~(C)*~(D)*E+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*~(B)*C*~(D)*E+~(A)*B*C*~(D)*E+A*B*C*~(D)*E+~(A)*~(B)*~(C)*D*E+A*~(B)*~(C)*D*E+A*B*C*D*E)"),
    .INIT(32'h83fc83ff))
    _al_u94 (
    .a(hready),
    .b(\AHB_INTERFACE/statu [0]),
    .c(\AHB_INTERFACE/statu [1]),
    .d(\AHB_INTERFACE/statu [3]),
    .e(read_line_req),
    .o(_al_u94_o));
  AL_MAP_LUT2 #(
    .EQN("(~B*~A)"),
    .INIT(4'h1))
    _al_u95 (
    .a(_al_u94_o),
    .b(\AHB_INTERFACE/statu [2]),
    .o(\AHB_INTERFACE/n14 [3]));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)+A*~(B)*~(C)*~(D)+~(A)*B*~(C)*~(D)+A*B*~(C)*~(D)+A*B*C*~(D)+~(A)*~(B)*~(C)*D+A*~(B)*~(C)*D+A*B*C*D)"),
    .INIT(16'h838f))
    _al_u96 (
    .a(hready),
    .b(\AHB_INTERFACE/statu [0]),
    .c(\AHB_INTERFACE/statu [1]),
    .d(\AHB_INTERFACE/statu [3]),
    .o(_al_u96_o));
  AL_MAP_LUT3 #(
    .EQN("(C*~B*~A)"),
    .INIT(8'h10))
    _al_u97 (
    .a(read_line_req),
    .b(read_req),
    .c(write_through_req),
    .o(_al_u97_o));
  AL_MAP_LUT4 #(
    .EQN("(~D*~(A*~(C*B)))"),
    .INIT(16'h00d5))
    _al_u98 (
    .a(_al_u96_o),
    .b(_al_u97_o),
    .c(_al_u30_o),
    .d(\AHB_INTERFACE/statu [2]),
    .o(\AHB_INTERFACE/n14 [1]));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+A*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+~(A)*~(B)*~(C)*~(D)*E+A*~(B)*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*~(B)*C*~(D)*E+~(A)*B*C*~(D)*E+~(A)*~(B)*~(C)*D*E+A*~(B)*~(C)*D*E+~(A)*B*~(C)*D*E)"),
    .INIT(32'h07730770))
    _al_u99 (
    .a(hready),
    .b(\AHB_INTERFACE/statu [0]),
    .c(\AHB_INTERFACE/statu [1]),
    .d(\AHB_INTERFACE/statu [2]),
    .e(read_line_req),
    .o(\AHB_INTERFACE/mux6_b0/B2_0 ));

endmodule 

module \min_pbus(MMU_ENABLE=1'b1)   // ../RTL/peripherals/min_pbus.v(7)
  (
  MNMX,
  SYST_PAUSE,
  WB_ADRi,
  WB_CYCi,
  WB_DATi,
  WB_STBi,
  WB_WEi,
  XCP_ARR,
  XTNL_INT,
  clki,
  rsti,
  ALWAYS_SVM,
  ASYNC_WAITCYCLE,
  HPAGE_BASEADDR,
  INT,
  IVEC_ADDR,
  PAE_ENABLE,
  SYNC_MODE,
  WB_ACKo,
  WB_DATo,
  clk,
  dpae_h16,
  dpte_h8,
  ipae_h16,
  ipte_h8,
  rst
  );

  input MNMX;  // ../RTL/peripherals/min_pbus.v(13)
  input SYST_PAUSE;  // ../RTL/peripherals/min_pbus.v(12)
  input [11:0] WB_ADRi;  // ../RTL/peripherals/min_pbus.v(34)
  input WB_CYCi;  // ../RTL/peripherals/min_pbus.v(38)
  input [7:0] WB_DATi;  // ../RTL/peripherals/min_pbus.v(36)
  input WB_STBi;  // ../RTL/peripherals/min_pbus.v(39)
  input WB_WEi;  // ../RTL/peripherals/min_pbus.v(37)
  input [7:0] XCP_ARR;  // ../RTL/peripherals/min_pbus.v(26)
  input XTNL_INT;  // ../RTL/peripherals/min_pbus.v(25)
  input clki;  // ../RTL/peripherals/min_pbus.v(30)
  input rsti;  // ../RTL/peripherals/min_pbus.v(31)
  output ALWAYS_SVM;  // ../RTL/peripherals/min_pbus.v(19)
  output [6:0] ASYNC_WAITCYCLE;  // ../RTL/peripherals/min_pbus.v(15)
  output [9:0] HPAGE_BASEADDR;  // ../RTL/peripherals/min_pbus.v(17)
  output INT;  // ../RTL/peripherals/min_pbus.v(27)
  output [23:0] IVEC_ADDR;  // ../RTL/peripherals/min_pbus.v(28)
  output PAE_ENABLE;  // ../RTL/peripherals/min_pbus.v(18)
  output SYNC_MODE;  // ../RTL/peripherals/min_pbus.v(14)
  output WB_ACKo;  // ../RTL/peripherals/min_pbus.v(40)
  output [7:0] WB_DATo;  // ../RTL/peripherals/min_pbus.v(35)
  output clk;  // ../RTL/peripherals/min_pbus.v(32)
  output [15:0] dpae_h16;  // ../RTL/peripherals/min_pbus.v(21)
  output [7:0] dpte_h8;  // ../RTL/peripherals/min_pbus.v(23)
  output [15:0] ipae_h16;  // ../RTL/peripherals/min_pbus.v(20)
  output [7:0] ipte_h8;  // ../RTL/peripherals/min_pbus.v(22)
  output rst;  // ../RTL/peripherals/min_pbus.v(32)

  parameter MMU_ENABLE = 1'b1;
  parameter cDMA_ENABLE = 1'b0;
  wire [7:0] DATo_ITC;  // ../RTL/peripherals/min_pbus.v(46)
  wire [7:0] DATo_SPM;  // ../RTL/peripherals/min_pbus.v(47)
  wire [7:0] DATo_STK;  // ../RTL/peripherals/min_pbus.v(46)
  wire [7:0] DATo_SYC;  // ../RTL/peripherals/min_pbus.v(47)
  wire [7:0] SYSCALL_info;  // ../RTL/peripherals/min_pbus.v(86)
  wire [7:0] SYSCALL_num;  // ../RTL/peripherals/min_pbus.v(85)
  wire [7:0] \SYSTICK/STK0 ;  // ../RTL/peripherals/systick.v(23)
  wire [7:0] \SYSTICK/STK1 ;  // ../RTL/peripherals/systick.v(23)
  wire [7:0] \SYSTICK/STK2 ;  // ../RTL/peripherals/systick.v(23)
  wire [3:0] \SYSTICK/TIMC ;  // ../RTL/peripherals/systick.v(22)
  wire [23:0] \SYSTICK/n10 ;
  wire [23:0] \SYSTICK/systick_cnt ;  // ../RTL/peripherals/systick.v(25)
  wire \DATA_SPM/ramwe ;  // ../RTL/peripherals/ocspm.v(28)
  wire STBi_ITC;  // ../RTL/peripherals/min_pbus.v(49)
  wire STBi_STK_lutinv;  // ../RTL/peripherals/min_pbus.v(49)
  wire STBi_SYC;  // ../RTL/peripherals/min_pbus.v(50)
  wire SYSCALL;  // ../RTL/peripherals/min_pbus.v(43)
  wire \SYSCALL_UNIT/mux2_b0_sel_is_2_o ;
  wire \SYSCALL_UNIT/n1 ;
  wire SYSCALL_clr;  // ../RTL/peripherals/min_pbus.v(97)
  wire \SYSTICK/add0/c11 ;  // ../RTL/peripherals/systick.v(52)
  wire \SYSTICK/add0/c15 ;  // ../RTL/peripherals/systick.v(52)
  wire \SYSTICK/add0/c19 ;  // ../RTL/peripherals/systick.v(52)
  wire \SYSTICK/add0/c23 ;  // ../RTL/peripherals/systick.v(52)
  wire \SYSTICK/add0/c3 ;  // ../RTL/peripherals/systick.v(52)
  wire \SYSTICK/add0/c7 ;  // ../RTL/peripherals/systick.v(52)
  wire \SYSTICK/mux10_b0_sel_is_2_o ;
  wire \SYSTICK/mux11_b0_sel_is_2_o ;
  wire \SYSTICK/mux3_b0_sel_is_1_o ;
  wire \SYSTICK/mux8_b0_sel_is_3_o ;
  wire \SYSTICK/mux9_b0_sel_is_2_o ;
  wire \SYSTICK/n12 ;
  wire \SYSTICK/n6 ;
  wire \SYSTICK/n9 ;
  wire \SYSTICK/stint_clr ;  // ../RTL/peripherals/systick.v(33)
  wire \SYSTICK/stint_set ;  // ../RTL/peripherals/systick.v(30)
  wire \SYSTICK/systick_clr ;  // ../RTL/peripherals/systick.v(33)
  wire \SYSTICK/systick_pause ;  // ../RTL/peripherals/systick.v(47)
  wire SYSTICK_INT;  // ../RTL/peripherals/min_pbus.v(54)
  wire _al_u100_o;
  wire _al_u102_o;
  wire _al_u104_o;
  wire _al_u106_o;
  wire _al_u107_o;
  wire _al_u110_o;
  wire _al_u111_o;
  wire _al_u112_o;
  wire _al_u113_o;
  wire _al_u114_o;
  wire _al_u115_o;
  wire _al_u116_o;
  wire _al_u117_o;
  wire _al_u118_o;
  wire _al_u119_o;
  wire _al_u120_o;
  wire _al_u121_o;
  wire _al_u122_o;
  wire _al_u123_o;
  wire _al_u124_o;
  wire _al_u125_o;
  wire _al_u126_o;
  wire _al_u127_o;
  wire _al_u128_o;
  wire _al_u129_o;
  wire _al_u130_o;
  wire _al_u131_o;
  wire _al_u72_o;
  wire _al_u73_o;
  wire _al_u74_o;
  wire _al_u75_o;
  wire _al_u80_o;
  wire _al_u82_o;
  wire _al_u83_o;
  wire _al_u85_o;
  wire _al_u86_o;
  wire _al_u88_o;
  wire _al_u89_o;
  wire _al_u91_o;
  wire _al_u92_o;
  wire _al_u94_o;
  wire _al_u96_o;
  wire _al_u98_o;

  // address_offset=0;data_offset=0;depth=2048;width=4;num_section=1;width_per_section=4;section_size=8;working_depth=2048;working_width=4;mode_ecc=0;address_step=1;bytes_in_per_section=1;
  AL_PHY_BRAM #(
    //.RID("0x0008"),
    //.WID("0x0008"),
    .CEAMUX("1"),
    .CEBMUX("0"),
    .CLKBMUX("0"),
    .CSA0("1"),
    .CSA1("1"),
    .CSA2("1"),
    .CSB0("1"),
    .CSB1("1"),
    .CSB2("1"),
    .DATA_WIDTH_A("4"),
    .DATA_WIDTH_B("4"),
    .GSR("DISABLE"),
    .MODE("SP8K"),
    .OCEAMUX("1"),
    .OCEBMUX("0"),
    .READBACK("ON"),
    .REGMODE_A("NOREG"),
    .REGMODE_B("NOREG"),
    .RESETMODE("ASYNC"),
    .RSTAMUX("0"),
    .RSTBMUX("0"),
    .WEBMUX("0"),
    .WRITEMODE_A("READBEFOREWRITE"),
    .WRITEMODE_B("NORMAL"))
    \DATA_SPM/ram_SPMEM0_2048x8_sub_000000_000  (
    .addra({WB_ADRi[10:0],2'b11}),
    .clka(clk),
    .dia({open_n22,open_n23,open_n24,open_n25,open_n26,WB_DATi[3:0]}),
    .wea(\DATA_SPM/ramwe ),
    .doa({open_n41,open_n42,open_n43,open_n44,open_n45,DATo_SPM[3:0]}));
  // address_offset=0;data_offset=4;depth=2048;width=4;num_section=1;width_per_section=4;section_size=8;working_depth=2048;working_width=4;mode_ecc=0;address_step=1;bytes_in_per_section=1;
  AL_PHY_BRAM #(
    //.RID("0x0009"),
    //.WID("0x0009"),
    .CEAMUX("1"),
    .CEBMUX("0"),
    .CLKBMUX("0"),
    .CSA0("1"),
    .CSA1("1"),
    .CSA2("1"),
    .CSB0("1"),
    .CSB1("1"),
    .CSB2("1"),
    .DATA_WIDTH_A("4"),
    .DATA_WIDTH_B("4"),
    .GSR("DISABLE"),
    .MODE("SP8K"),
    .OCEAMUX("1"),
    .OCEBMUX("0"),
    .READBACK("ON"),
    .REGMODE_A("NOREG"),
    .REGMODE_B("NOREG"),
    .RESETMODE("ASYNC"),
    .RSTAMUX("0"),
    .RSTBMUX("0"),
    .WEBMUX("0"),
    .WRITEMODE_A("READBEFOREWRITE"),
    .WRITEMODE_B("NORMAL"))
    \DATA_SPM/ram_SPMEM0_2048x8_sub_000000_004  (
    .addra({WB_ADRi[10:0],2'b11}),
    .clka(clk),
    .dia({open_n77,open_n78,open_n79,open_n80,open_n81,WB_DATi[7:4]}),
    .wea(\DATA_SPM/ramwe ),
    .doa({open_n96,open_n97,open_n98,open_n99,open_n100,DATo_SPM[7:4]}));
  int_ctrl INTERRUPT_CONTROLLER1 (
    .INT_ARR({SYSCALL,SYSTICK_INT,XTNL_INT,5'b00000}),
    .WB_ADRi(WB_ADRi[2:0]),
    .WB_CYCi(WB_CYCi),
    .WB_DATi(WB_DATi),
    .WB_STBi(STBi_ITC),
    .WB_WEi(WB_WEi),
    .XCP_ARR(8'b00000000),
    .clk(clk),
    .rst(rst),
    .INT(INT),
    .IVEC_ADDR({open_n110,IVEC_ADDR[22:0]}),
    .WB_DATo(DATo_ITC));  // ../RTL/peripherals/min_pbus.v(68)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSCALL_UNIT/SYSCALL_trig_reg  (
    .ce(\SYSCALL_UNIT/n1 ),
    .clk(clk),
    .d(1'b1),
    .sr(SYSCALL_clr),
    .q(SYSCALL));  // ../RTL/peripherals/syscall.v(42)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSCALL_UNIT/reg0_b0  (
    .ce(\SYSCALL_UNIT/mux2_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_ADRi[0]),
    .q(SYSCALL_num[0]));  // ../RTL/peripherals/syscall.v(42)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSCALL_UNIT/reg0_b1  (
    .ce(\SYSCALL_UNIT/mux2_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_ADRi[1]),
    .q(SYSCALL_num[1]));  // ../RTL/peripherals/syscall.v(42)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSCALL_UNIT/reg0_b2  (
    .ce(\SYSCALL_UNIT/mux2_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_ADRi[2]),
    .q(SYSCALL_num[2]));  // ../RTL/peripherals/syscall.v(42)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSCALL_UNIT/reg0_b3  (
    .ce(\SYSCALL_UNIT/mux2_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_ADRi[3]),
    .q(SYSCALL_num[3]));  // ../RTL/peripherals/syscall.v(42)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSCALL_UNIT/reg0_b4  (
    .ce(\SYSCALL_UNIT/mux2_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_ADRi[4]),
    .q(SYSCALL_num[4]));  // ../RTL/peripherals/syscall.v(42)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSCALL_UNIT/reg0_b5  (
    .ce(\SYSCALL_UNIT/mux2_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_ADRi[5]),
    .q(SYSCALL_num[5]));  // ../RTL/peripherals/syscall.v(42)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSCALL_UNIT/reg0_b6  (
    .ce(\SYSCALL_UNIT/mux2_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_ADRi[6]),
    .q(SYSCALL_num[6]));  // ../RTL/peripherals/syscall.v(42)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSCALL_UNIT/reg0_b7  (
    .ce(\SYSCALL_UNIT/mux2_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_ADRi[7]),
    .q(SYSCALL_num[7]));  // ../RTL/peripherals/syscall.v(42)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSCALL_UNIT/reg1_b0  (
    .ce(\SYSCALL_UNIT/mux2_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[0]),
    .q(SYSCALL_info[0]));  // ../RTL/peripherals/syscall.v(42)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSCALL_UNIT/reg1_b1  (
    .ce(\SYSCALL_UNIT/mux2_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[1]),
    .q(SYSCALL_info[1]));  // ../RTL/peripherals/syscall.v(42)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSCALL_UNIT/reg1_b2  (
    .ce(\SYSCALL_UNIT/mux2_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[2]),
    .q(SYSCALL_info[2]));  // ../RTL/peripherals/syscall.v(42)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSCALL_UNIT/reg1_b3  (
    .ce(\SYSCALL_UNIT/mux2_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[3]),
    .q(SYSCALL_info[3]));  // ../RTL/peripherals/syscall.v(42)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSCALL_UNIT/reg1_b4  (
    .ce(\SYSCALL_UNIT/mux2_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[4]),
    .q(SYSCALL_info[4]));  // ../RTL/peripherals/syscall.v(42)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSCALL_UNIT/reg1_b5  (
    .ce(\SYSCALL_UNIT/mux2_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[5]),
    .q(SYSCALL_info[5]));  // ../RTL/peripherals/syscall.v(42)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSCALL_UNIT/reg1_b6  (
    .ce(\SYSCALL_UNIT/mux2_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[6]),
    .q(SYSCALL_info[6]));  // ../RTL/peripherals/syscall.v(42)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSCALL_UNIT/reg1_b7  (
    .ce(\SYSCALL_UNIT/mux2_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[7]),
    .q(SYSCALL_info[7]));  // ../RTL/peripherals/syscall.v(42)
  sys_ctrl SYSCTRL (
    .MNMX(MNMX),
    .SYSCALL_info(SYSCALL_info),
    .SYSCALL_num(SYSCALL_num),
    .WB_ADRi(WB_ADRi[3:0]),
    .WB_CYCi(WB_CYCi),
    .WB_DATi(WB_DATi),
    .WB_STBi(STBi_SYC),
    .WB_WEi(WB_WEi),
    .clki(clki),
    .reset_req(1'b0),
    .rsti(rsti),
    .ALWAYS_SVM(ALWAYS_SVM),
    .ASYNC_WAITCYCLE(ASYNC_WAITCYCLE),
    .HPAGE_BASEADDR({open_n128,HPAGE_BASEADDR}),
    .PAE_ENABLE(PAE_ENABLE),
    .SYNC_MODE(SYNC_MODE),
    .SYSCALL_clr(SYSCALL_clr),
    .WB_DATo(DATo_SYC),
    .clk(clk),
    .dpae_h16(dpae_h16),
    .ipae_h16(ipae_h16),
    .rst(rst));  // ../RTL/peripherals/min_pbus.v(89)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSTICK/SYSTICK_INT_reg  (
    .clk(\SYSTICK/stint_set ),
    .d(1'b1),
    .sr(\SYSTICK/stint_clr ),
    .q(SYSTICK_INT));  // ../RTL/peripherals/systick.v(44)
  AL_PHY_LSLICE #(
    //.MACRO("SYSTICK/add0/ucin_al_u141"),
    //.R_POSITION("X0Y1Z1"),
    .DEMUX0("E"),
    .DEMUX1("E"),
    .GSR("DISABLE"),
    .INIT_LUTF0(16'hA55A),
    .INIT_LUTF1(16'hA55A),
    .INIT_LUTG0(16'hC33C),
    .INIT_LUTG1(16'hC33C),
    .LSFMUX0("SUM"),
    .LSFMUX1("SUM"),
    .LSFXMUX0("SUM"),
    .LSFXMUX1("SUM"),
    .MODE("RIPPLE"))
    \SYSTICK/add0/u11_al_u144  (
    .a({\SYSTICK/systick_cnt [13],\SYSTICK/systick_cnt [11]}),
    .b({\SYSTICK/systick_cnt [14],\SYSTICK/systick_cnt [12]}),
    .c(2'b00),
    .d(2'b00),
    .e(2'b00),
    .fci(\SYSTICK/add0/c11 ),
    .f({\SYSTICK/n10 [13],\SYSTICK/n10 [11]}),
    .fco(\SYSTICK/add0/c15 ),
    .fx({\SYSTICK/n10 [14],\SYSTICK/n10 [12]}));
  AL_PHY_LSLICE #(
    //.MACRO("SYSTICK/add0/ucin_al_u141"),
    //.R_POSITION("X0Y2Z0"),
    .DEMUX0("E"),
    .DEMUX1("E"),
    .GSR("DISABLE"),
    .INIT_LUTF0(16'hA55A),
    .INIT_LUTF1(16'hA55A),
    .INIT_LUTG0(16'hC33C),
    .INIT_LUTG1(16'hC33C),
    .LSFMUX0("SUM"),
    .LSFMUX1("SUM"),
    .LSFXMUX0("SUM"),
    .LSFXMUX1("SUM"),
    .MODE("RIPPLE"))
    \SYSTICK/add0/u15_al_u145  (
    .a({\SYSTICK/systick_cnt [17],\SYSTICK/systick_cnt [15]}),
    .b({\SYSTICK/systick_cnt [18],\SYSTICK/systick_cnt [16]}),
    .c(2'b00),
    .d(2'b00),
    .e(2'b00),
    .fci(\SYSTICK/add0/c15 ),
    .f({\SYSTICK/n10 [17],\SYSTICK/n10 [15]}),
    .fco(\SYSTICK/add0/c19 ),
    .fx({\SYSTICK/n10 [18],\SYSTICK/n10 [16]}));
  AL_PHY_LSLICE #(
    //.MACRO("SYSTICK/add0/ucin_al_u141"),
    //.R_POSITION("X0Y2Z1"),
    .DEMUX0("E"),
    .DEMUX1("E"),
    .GSR("DISABLE"),
    .INIT_LUTF0(16'hA55A),
    .INIT_LUTF1(16'hA55A),
    .INIT_LUTG0(16'hC33C),
    .INIT_LUTG1(16'hC33C),
    .LSFMUX0("SUM"),
    .LSFMUX1("SUM"),
    .LSFXMUX0("SUM"),
    .LSFXMUX1("SUM"),
    .MODE("RIPPLE"))
    \SYSTICK/add0/u19_al_u146  (
    .a({\SYSTICK/systick_cnt [21],\SYSTICK/systick_cnt [19]}),
    .b({\SYSTICK/systick_cnt [22],\SYSTICK/systick_cnt [20]}),
    .c(2'b00),
    .d(2'b00),
    .e(2'b00),
    .fci(\SYSTICK/add0/c19 ),
    .f({\SYSTICK/n10 [21],\SYSTICK/n10 [19]}),
    .fco(\SYSTICK/add0/c23 ),
    .fx({\SYSTICK/n10 [22],\SYSTICK/n10 [20]}));
  AL_PHY_LSLICE #(
    //.MACRO("SYSTICK/add0/ucin_al_u141"),
    //.R_POSITION("X0Y3Z0"),
    .DEMUX0("E"),
    .DEMUX1("E"),
    .GSR("DISABLE"),
    .INIT_LUTF0(16'hA55A),
    .INIT_LUTF1(16'hA55A),
    .INIT_LUTG0(16'hC33C),
    .INIT_LUTG1(16'hC33C),
    .LSFMUX0("SUM"),
    .LSFMUX1("SUM"),
    .LSFXMUX0("SUM"),
    .LSFXMUX1("SUM"),
    .MODE("RIPPLE"))
    \SYSTICK/add0/u23_al_u147  (
    .a({open_n202,\SYSTICK/systick_cnt [23]}),
    .c(2'b00),
    .d({open_n207,1'b0}),
    .fci(\SYSTICK/add0/c23 ),
    .f({open_n224,\SYSTICK/n10 [23]}));
  AL_PHY_LSLICE #(
    //.MACRO("SYSTICK/add0/ucin_al_u141"),
    //.R_POSITION("X0Y0Z1"),
    .DEMUX0("E"),
    .DEMUX1("E"),
    .GSR("DISABLE"),
    .INIT_LUTF0(16'hA55A),
    .INIT_LUTF1(16'hA55A),
    .INIT_LUTG0(16'hC33C),
    .INIT_LUTG1(16'hC33C),
    .LSFMUX0("SUM"),
    .LSFMUX1("SUM"),
    .LSFXMUX0("SUM"),
    .LSFXMUX1("SUM"),
    .MODE("RIPPLE"))
    \SYSTICK/add0/u3_al_u142  (
    .a({\SYSTICK/systick_cnt [5],\SYSTICK/systick_cnt [3]}),
    .b({\SYSTICK/systick_cnt [6],\SYSTICK/systick_cnt [4]}),
    .c(2'b00),
    .d(2'b00),
    .e(2'b00),
    .fci(\SYSTICK/add0/c3 ),
    .f({\SYSTICK/n10 [5],\SYSTICK/n10 [3]}),
    .fco(\SYSTICK/add0/c7 ),
    .fx({\SYSTICK/n10 [6],\SYSTICK/n10 [4]}));
  AL_PHY_LSLICE #(
    //.MACRO("SYSTICK/add0/ucin_al_u141"),
    //.R_POSITION("X0Y1Z0"),
    .DEMUX0("E"),
    .DEMUX1("E"),
    .GSR("DISABLE"),
    .INIT_LUTF0(16'hA55A),
    .INIT_LUTF1(16'hA55A),
    .INIT_LUTG0(16'hC33C),
    .INIT_LUTG1(16'hC33C),
    .LSFMUX0("SUM"),
    .LSFMUX1("SUM"),
    .LSFXMUX0("SUM"),
    .LSFXMUX1("SUM"),
    .MODE("RIPPLE"))
    \SYSTICK/add0/u7_al_u143  (
    .a({\SYSTICK/systick_cnt [9],\SYSTICK/systick_cnt [7]}),
    .b({\SYSTICK/systick_cnt [10],\SYSTICK/systick_cnt [8]}),
    .c(2'b00),
    .d(2'b00),
    .e(2'b00),
    .fci(\SYSTICK/add0/c7 ),
    .f({\SYSTICK/n10 [9],\SYSTICK/n10 [7]}),
    .fco(\SYSTICK/add0/c11 ),
    .fx({\SYSTICK/n10 [10],\SYSTICK/n10 [8]}));
  AL_PHY_LSLICE #(
    //.MACRO("SYSTICK/add0/ucin_al_u141"),
    //.R_POSITION("X0Y0Z0"),
    .DEMUX0("E"),
    .DEMUX1("E"),
    .GSR("DISABLE"),
    .INIT_LUTF0(16'h000A),
    .INIT_LUTF1(16'hA55A),
    .INIT_LUTG0(16'hC33C),
    .INIT_LUTG1(16'hC33C),
    .LSFMUX0("SUM"),
    .LSFMUX1("SUM"),
    .LSFXMUX0("SUM"),
    .LSFXMUX1("SUM"),
    .MODE("RIPPLE"))
    \SYSTICK/add0/ucin_al_u141  (
    .a({\SYSTICK/systick_cnt [1],1'b0}),
    .b({\SYSTICK/systick_cnt [2],\SYSTICK/systick_cnt [0]}),
    .c(2'b00),
    .d(2'b01),
    .e(2'b01),
    .f({\SYSTICK/n10 [1],open_n283}),
    .fco(\SYSTICK/add0/c3 ),
    .fx({\SYSTICK/n10 [2],\SYSTICK/n10 [0]}));
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSTICK/reg0_b0  (
    .ce(\SYSTICK/systick_pause ),
    .clk(clk),
    .d(\SYSTICK/n10 [0]),
    .sr(\SYSTICK/systick_clr ),
    .q(\SYSTICK/systick_cnt [0]));  // ../RTL/peripherals/systick.v(53)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSTICK/reg0_b1  (
    .ce(\SYSTICK/systick_pause ),
    .clk(clk),
    .d(\SYSTICK/n10 [1]),
    .sr(\SYSTICK/systick_clr ),
    .q(\SYSTICK/systick_cnt [1]));  // ../RTL/peripherals/systick.v(53)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSTICK/reg0_b10  (
    .ce(\SYSTICK/systick_pause ),
    .clk(clk),
    .d(\SYSTICK/n10 [10]),
    .sr(\SYSTICK/systick_clr ),
    .q(\SYSTICK/systick_cnt [10]));  // ../RTL/peripherals/systick.v(53)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSTICK/reg0_b11  (
    .ce(\SYSTICK/systick_pause ),
    .clk(clk),
    .d(\SYSTICK/n10 [11]),
    .sr(\SYSTICK/systick_clr ),
    .q(\SYSTICK/systick_cnt [11]));  // ../RTL/peripherals/systick.v(53)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSTICK/reg0_b12  (
    .ce(\SYSTICK/systick_pause ),
    .clk(clk),
    .d(\SYSTICK/n10 [12]),
    .sr(\SYSTICK/systick_clr ),
    .q(\SYSTICK/systick_cnt [12]));  // ../RTL/peripherals/systick.v(53)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSTICK/reg0_b13  (
    .ce(\SYSTICK/systick_pause ),
    .clk(clk),
    .d(\SYSTICK/n10 [13]),
    .sr(\SYSTICK/systick_clr ),
    .q(\SYSTICK/systick_cnt [13]));  // ../RTL/peripherals/systick.v(53)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSTICK/reg0_b14  (
    .ce(\SYSTICK/systick_pause ),
    .clk(clk),
    .d(\SYSTICK/n10 [14]),
    .sr(\SYSTICK/systick_clr ),
    .q(\SYSTICK/systick_cnt [14]));  // ../RTL/peripherals/systick.v(53)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSTICK/reg0_b15  (
    .ce(\SYSTICK/systick_pause ),
    .clk(clk),
    .d(\SYSTICK/n10 [15]),
    .sr(\SYSTICK/systick_clr ),
    .q(\SYSTICK/systick_cnt [15]));  // ../RTL/peripherals/systick.v(53)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSTICK/reg0_b16  (
    .ce(\SYSTICK/systick_pause ),
    .clk(clk),
    .d(\SYSTICK/n10 [16]),
    .sr(\SYSTICK/systick_clr ),
    .q(\SYSTICK/systick_cnt [16]));  // ../RTL/peripherals/systick.v(53)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSTICK/reg0_b17  (
    .ce(\SYSTICK/systick_pause ),
    .clk(clk),
    .d(\SYSTICK/n10 [17]),
    .sr(\SYSTICK/systick_clr ),
    .q(\SYSTICK/systick_cnt [17]));  // ../RTL/peripherals/systick.v(53)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSTICK/reg0_b18  (
    .ce(\SYSTICK/systick_pause ),
    .clk(clk),
    .d(\SYSTICK/n10 [18]),
    .sr(\SYSTICK/systick_clr ),
    .q(\SYSTICK/systick_cnt [18]));  // ../RTL/peripherals/systick.v(53)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSTICK/reg0_b19  (
    .ce(\SYSTICK/systick_pause ),
    .clk(clk),
    .d(\SYSTICK/n10 [19]),
    .sr(\SYSTICK/systick_clr ),
    .q(\SYSTICK/systick_cnt [19]));  // ../RTL/peripherals/systick.v(53)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSTICK/reg0_b2  (
    .ce(\SYSTICK/systick_pause ),
    .clk(clk),
    .d(\SYSTICK/n10 [2]),
    .sr(\SYSTICK/systick_clr ),
    .q(\SYSTICK/systick_cnt [2]));  // ../RTL/peripherals/systick.v(53)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSTICK/reg0_b20  (
    .ce(\SYSTICK/systick_pause ),
    .clk(clk),
    .d(\SYSTICK/n10 [20]),
    .sr(\SYSTICK/systick_clr ),
    .q(\SYSTICK/systick_cnt [20]));  // ../RTL/peripherals/systick.v(53)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSTICK/reg0_b21  (
    .ce(\SYSTICK/systick_pause ),
    .clk(clk),
    .d(\SYSTICK/n10 [21]),
    .sr(\SYSTICK/systick_clr ),
    .q(\SYSTICK/systick_cnt [21]));  // ../RTL/peripherals/systick.v(53)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSTICK/reg0_b22  (
    .ce(\SYSTICK/systick_pause ),
    .clk(clk),
    .d(\SYSTICK/n10 [22]),
    .sr(\SYSTICK/systick_clr ),
    .q(\SYSTICK/systick_cnt [22]));  // ../RTL/peripherals/systick.v(53)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSTICK/reg0_b23  (
    .ce(\SYSTICK/systick_pause ),
    .clk(clk),
    .d(\SYSTICK/n10 [23]),
    .sr(\SYSTICK/systick_clr ),
    .q(\SYSTICK/systick_cnt [23]));  // ../RTL/peripherals/systick.v(53)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSTICK/reg0_b3  (
    .ce(\SYSTICK/systick_pause ),
    .clk(clk),
    .d(\SYSTICK/n10 [3]),
    .sr(\SYSTICK/systick_clr ),
    .q(\SYSTICK/systick_cnt [3]));  // ../RTL/peripherals/systick.v(53)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSTICK/reg0_b4  (
    .ce(\SYSTICK/systick_pause ),
    .clk(clk),
    .d(\SYSTICK/n10 [4]),
    .sr(\SYSTICK/systick_clr ),
    .q(\SYSTICK/systick_cnt [4]));  // ../RTL/peripherals/systick.v(53)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSTICK/reg0_b5  (
    .ce(\SYSTICK/systick_pause ),
    .clk(clk),
    .d(\SYSTICK/n10 [5]),
    .sr(\SYSTICK/systick_clr ),
    .q(\SYSTICK/systick_cnt [5]));  // ../RTL/peripherals/systick.v(53)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSTICK/reg0_b6  (
    .ce(\SYSTICK/systick_pause ),
    .clk(clk),
    .d(\SYSTICK/n10 [6]),
    .sr(\SYSTICK/systick_clr ),
    .q(\SYSTICK/systick_cnt [6]));  // ../RTL/peripherals/systick.v(53)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSTICK/reg0_b7  (
    .ce(\SYSTICK/systick_pause ),
    .clk(clk),
    .d(\SYSTICK/n10 [7]),
    .sr(\SYSTICK/systick_clr ),
    .q(\SYSTICK/systick_cnt [7]));  // ../RTL/peripherals/systick.v(53)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSTICK/reg0_b8  (
    .ce(\SYSTICK/systick_pause ),
    .clk(clk),
    .d(\SYSTICK/n10 [8]),
    .sr(\SYSTICK/systick_clr ),
    .q(\SYSTICK/systick_cnt [8]));  // ../RTL/peripherals/systick.v(53)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSTICK/reg0_b9  (
    .ce(\SYSTICK/systick_pause ),
    .clk(clk),
    .d(\SYSTICK/n10 [9]),
    .sr(\SYSTICK/systick_clr ),
    .q(\SYSTICK/systick_cnt [9]));  // ../RTL/peripherals/systick.v(53)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSTICK/reg1_b0  (
    .ce(\SYSTICK/mux8_b0_sel_is_3_o ),
    .clk(clk),
    .d(WB_DATi[0]),
    .sr(rst),
    .q(\SYSTICK/TIMC [0]));  // ../RTL/peripherals/systick.v(80)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSTICK/reg1_b1  (
    .ce(\SYSTICK/mux8_b0_sel_is_3_o ),
    .clk(clk),
    .d(WB_DATi[1]),
    .sr(rst),
    .q(\SYSTICK/TIMC [1]));  // ../RTL/peripherals/systick.v(80)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSTICK/reg1_b2  (
    .ce(\SYSTICK/mux8_b0_sel_is_3_o ),
    .clk(clk),
    .d(WB_DATi[2]),
    .sr(rst),
    .q(\SYSTICK/TIMC [2]));  // ../RTL/peripherals/systick.v(80)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    \SYSTICK/reg1_b3  (
    .ce(\SYSTICK/mux8_b0_sel_is_3_o ),
    .clk(clk),
    .d(WB_DATi[3]),
    .sr(rst),
    .q(\SYSTICK/TIMC [3]));  // ../RTL/peripherals/systick.v(80)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSTICK/reg2_b0  (
    .ce(\SYSTICK/mux9_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[0]),
    .q(\SYSTICK/STK2 [0]));  // ../RTL/peripherals/systick.v(80)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSTICK/reg2_b1  (
    .ce(\SYSTICK/mux9_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[1]),
    .q(\SYSTICK/STK2 [1]));  // ../RTL/peripherals/systick.v(80)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSTICK/reg2_b2  (
    .ce(\SYSTICK/mux9_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[2]),
    .q(\SYSTICK/STK2 [2]));  // ../RTL/peripherals/systick.v(80)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSTICK/reg2_b3  (
    .ce(\SYSTICK/mux9_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[3]),
    .q(\SYSTICK/STK2 [3]));  // ../RTL/peripherals/systick.v(80)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSTICK/reg2_b4  (
    .ce(\SYSTICK/mux9_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[4]),
    .q(\SYSTICK/STK2 [4]));  // ../RTL/peripherals/systick.v(80)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSTICK/reg2_b5  (
    .ce(\SYSTICK/mux9_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[5]),
    .q(\SYSTICK/STK2 [5]));  // ../RTL/peripherals/systick.v(80)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSTICK/reg2_b6  (
    .ce(\SYSTICK/mux9_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[6]),
    .q(\SYSTICK/STK2 [6]));  // ../RTL/peripherals/systick.v(80)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSTICK/reg2_b7  (
    .ce(\SYSTICK/mux9_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[7]),
    .q(\SYSTICK/STK2 [7]));  // ../RTL/peripherals/systick.v(80)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSTICK/reg3_b0  (
    .ce(\SYSTICK/mux10_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[0]),
    .q(\SYSTICK/STK1 [0]));  // ../RTL/peripherals/systick.v(80)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSTICK/reg3_b1  (
    .ce(\SYSTICK/mux10_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[1]),
    .q(\SYSTICK/STK1 [1]));  // ../RTL/peripherals/systick.v(80)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSTICK/reg3_b2  (
    .ce(\SYSTICK/mux10_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[2]),
    .q(\SYSTICK/STK1 [2]));  // ../RTL/peripherals/systick.v(80)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSTICK/reg3_b3  (
    .ce(\SYSTICK/mux10_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[3]),
    .q(\SYSTICK/STK1 [3]));  // ../RTL/peripherals/systick.v(80)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSTICK/reg3_b4  (
    .ce(\SYSTICK/mux10_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[4]),
    .q(\SYSTICK/STK1 [4]));  // ../RTL/peripherals/systick.v(80)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSTICK/reg3_b5  (
    .ce(\SYSTICK/mux10_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[5]),
    .q(\SYSTICK/STK1 [5]));  // ../RTL/peripherals/systick.v(80)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSTICK/reg3_b6  (
    .ce(\SYSTICK/mux10_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[6]),
    .q(\SYSTICK/STK1 [6]));  // ../RTL/peripherals/systick.v(80)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSTICK/reg3_b7  (
    .ce(\SYSTICK/mux10_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[7]),
    .q(\SYSTICK/STK1 [7]));  // ../RTL/peripherals/systick.v(80)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSTICK/reg4_b0  (
    .ce(\SYSTICK/mux11_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[0]),
    .q(\SYSTICK/STK0 [0]));  // ../RTL/peripherals/systick.v(80)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSTICK/reg4_b1  (
    .ce(\SYSTICK/mux11_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[1]),
    .q(\SYSTICK/STK0 [1]));  // ../RTL/peripherals/systick.v(80)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSTICK/reg4_b2  (
    .ce(\SYSTICK/mux11_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[2]),
    .q(\SYSTICK/STK0 [2]));  // ../RTL/peripherals/systick.v(80)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSTICK/reg4_b3  (
    .ce(\SYSTICK/mux11_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[3]),
    .q(\SYSTICK/STK0 [3]));  // ../RTL/peripherals/systick.v(80)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSTICK/reg4_b4  (
    .ce(\SYSTICK/mux11_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[4]),
    .q(\SYSTICK/STK0 [4]));  // ../RTL/peripherals/systick.v(80)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSTICK/reg4_b5  (
    .ce(\SYSTICK/mux11_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[5]),
    .q(\SYSTICK/STK0 [5]));  // ../RTL/peripherals/systick.v(80)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSTICK/reg4_b6  (
    .ce(\SYSTICK/mux11_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[6]),
    .q(\SYSTICK/STK0 [6]));  // ../RTL/peripherals/systick.v(80)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSTICK/reg4_b7  (
    .ce(\SYSTICK/mux11_b0_sel_is_2_o ),
    .clk(clk),
    .d(WB_DATi[7]),
    .q(\SYSTICK/STK0 [7]));  // ../RTL/peripherals/systick.v(80)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSTICK/stint_clr_reg  (
    .clk(clk),
    .d(\SYSTICK/n9 ),
    .q(\SYSTICK/stint_clr ));  // ../RTL/peripherals/systick.v(38)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    \SYSTICK/systick_clr_reg  (
    .clk(clk),
    .d(\SYSTICK/n6 ),
    .q(\SYSTICK/systick_clr ));  // ../RTL/peripherals/systick.v(38)
  AL_MAP_LUT4 #(
    .EQN("(~(C*B)*~(D*A))"),
    .INIT(16'h153f))
    _al_u100 (
    .a(STBi_ITC),
    .b(WB_ADRi[11]),
    .c(DATo_SPM[2]),
    .d(DATo_ITC[2]),
    .o(_al_u100_o));
  AL_MAP_LUT5 #(
    .EQN("~(A*~(D*C)*~(E*B))"),
    .INIT(32'hfdddf555))
    _al_u101 (
    .a(_al_u100_o),
    .b(STBi_SYC),
    .c(STBi_STK_lutinv),
    .d(DATo_STK[2]),
    .e(DATo_SYC[2]),
    .o(WB_DATo[2]));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)+A*~(B)*~(C)*~(D)+~(A)*B*~(C)*~(D)+A*B*~(C)*~(D)+~(A)*~(B)*~(C)*D+A*~(B)*~(C)*D+~(A)*~(B)*C*D+~(A)*B*C*D)"),
    .INIT(16'h530f))
    _al_u102 (
    .a(\SYSTICK/STK2 [1]),
    .b(\SYSTICK/STK0 [1]),
    .c(WB_ADRi[1]),
    .d(WB_ADRi[0]),
    .o(_al_u102_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*B*~(C)*~(D)+A*B*~(C)*~(D)+A*~(B)*C*~(D)+A*B*C*~(D)+~(A)*~(B)*~(C)*D+A*~(B)*~(C)*D+~(A)*B*~(C)*D+A*B*~(C)*D)"),
    .INIT(16'h0fac))
    _al_u103 (
    .a(\SYSTICK/TIMC [1]),
    .b(\SYSTICK/STK1 [1]),
    .c(_al_u102_o),
    .d(WB_ADRi[0]),
    .o(DATo_STK[1]));
  AL_MAP_LUT4 #(
    .EQN("(~(C*B)*~(D*A))"),
    .INIT(16'h153f))
    _al_u104 (
    .a(STBi_ITC),
    .b(WB_ADRi[11]),
    .c(DATo_SPM[1]),
    .d(DATo_ITC[1]),
    .o(_al_u104_o));
  AL_MAP_LUT5 #(
    .EQN("~(A*~(D*C)*~(E*B))"),
    .INIT(32'hfdddf555))
    _al_u105 (
    .a(_al_u104_o),
    .b(STBi_SYC),
    .c(STBi_STK_lutinv),
    .d(DATo_STK[1]),
    .e(DATo_SYC[1]),
    .o(WB_DATo[1]));
  AL_MAP_LUT5 #(
    .EQN("(~(D*C)*~(E*B*A))"),
    .INIT(32'h07770fff))
    _al_u106 (
    .a(_al_u75_o),
    .b(_al_u73_o),
    .c(WB_ADRi[11]),
    .d(DATo_SPM[0]),
    .e(DATo_SYC[0]),
    .o(_al_u106_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)+A*~(B)*~(C)*~(D)+~(A)*B*~(C)*~(D)+A*B*~(C)*~(D)+~(A)*~(B)*~(C)*D+A*~(B)*~(C)*D+~(A)*~(B)*C*D+~(A)*B*C*D)"),
    .INIT(16'h530f))
    _al_u107 (
    .a(\SYSTICK/STK2 [0]),
    .b(\SYSTICK/STK0 [0]),
    .c(WB_ADRi[1]),
    .d(WB_ADRi[0]),
    .o(_al_u107_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*B*~(C)*~(D)+A*B*~(C)*~(D)+A*~(B)*C*~(D)+A*B*C*~(D)+~(A)*~(B)*~(C)*D+A*~(B)*~(C)*D+~(A)*B*~(C)*D+A*B*~(C)*D)"),
    .INIT(16'h0fac))
    _al_u108 (
    .a(\SYSTICK/TIMC [0]),
    .b(\SYSTICK/STK1 [0]),
    .c(_al_u107_o),
    .d(WB_ADRi[0]),
    .o(DATo_STK[0]));
  AL_MAP_LUT5 #(
    .EQN("~(A*~(D*C)*~(E*B))"),
    .INIT(32'hfdddf555))
    _al_u109 (
    .a(_al_u106_o),
    .b(STBi_ITC),
    .c(STBi_STK_lutinv),
    .d(DATo_STK[0]),
    .e(DATo_ITC[0]),
    .o(WB_DATo[0]));
  AL_MAP_LUT2 #(
    .EQN("(B*~A)"),
    .INIT(4'h4))
    _al_u110 (
    .a(\SYSTICK/systick_cnt [2]),
    .b(\SYSTICK/STK0 [2]),
    .o(_al_u110_o));
  AL_MAP_LUT5 #(
    .EQN("(~A*~(D@C)*~(E*~B))"),
    .INIT(32'h40045005))
    _al_u111 (
    .a(_al_u110_o),
    .b(\SYSTICK/systick_cnt [14]),
    .c(\SYSTICK/systick_cnt [20]),
    .d(\SYSTICK/STK2 [4]),
    .e(\SYSTICK/STK1 [6]),
    .o(_al_u111_o));
  AL_MAP_LUT4 #(
    .EQN("(~(~C*B)*~(~D*A))"),
    .INIT(16'hf351))
    _al_u112 (
    .a(\SYSTICK/systick_cnt [15]),
    .b(\SYSTICK/systick_cnt [17]),
    .c(\SYSTICK/STK2 [1]),
    .d(\SYSTICK/STK1 [7]),
    .o(_al_u112_o));
  AL_MAP_LUT4 #(
    .EQN("(~(D*~B)*~(~C*A))"),
    .INIT(16'hc4f5))
    _al_u113 (
    .a(\SYSTICK/systick_cnt [13]),
    .b(\SYSTICK/systick_cnt [5]),
    .c(\SYSTICK/STK1 [5]),
    .d(\SYSTICK/STK0 [5]),
    .o(_al_u113_o));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u114 (
    .a(_al_u111_o),
    .b(_al_u112_o),
    .c(_al_u113_o),
    .o(_al_u114_o));
  AL_MAP_LUT4 #(
    .EQN("(~(~D*B)*~(~C*A))"),
    .INIT(16'hf531))
    _al_u115 (
    .a(\SYSTICK/systick_cnt [19]),
    .b(\SYSTICK/systick_cnt [8]),
    .c(\SYSTICK/STK2 [3]),
    .d(\SYSTICK/STK1 [0]),
    .o(_al_u115_o));
  AL_MAP_LUT4 #(
    .EQN("(~(C*~B)*~(~D*A))"),
    .INIT(16'hcf45))
    _al_u116 (
    .a(\SYSTICK/systick_cnt [0]),
    .b(\SYSTICK/systick_cnt [22]),
    .c(\SYSTICK/STK2 [6]),
    .d(\SYSTICK/STK0 [0]),
    .o(_al_u116_o));
  AL_MAP_LUT3 #(
    .EQN("(B*~(~C*A))"),
    .INIT(8'hc4))
    _al_u117 (
    .a(\SYSTICK/systick_cnt [2]),
    .b(\SYSTICK/TIMC [3]),
    .c(\SYSTICK/STK0 [2]),
    .o(_al_u117_o));
  AL_MAP_LUT5 #(
    .EQN("(C*B*A*~(E@D))"),
    .INIT(32'h80000080))
    _al_u118 (
    .a(_al_u115_o),
    .b(_al_u116_o),
    .c(_al_u117_o),
    .d(\SYSTICK/systick_cnt [4]),
    .e(\SYSTICK/STK0 [4]),
    .o(_al_u118_o));
  AL_MAP_LUT4 #(
    .EQN("(~(C*~B)*~(D*~A))"),
    .INIT(16'h8acf))
    _al_u119 (
    .a(\SYSTICK/systick_cnt [0]),
    .b(\SYSTICK/systick_cnt [17]),
    .c(\SYSTICK/STK2 [1]),
    .d(\SYSTICK/STK0 [0]),
    .o(_al_u119_o));
  AL_MAP_LUT4 #(
    .EQN("(~(~D*B)*~(C*~A))"),
    .INIT(16'haf23))
    _al_u120 (
    .a(\SYSTICK/systick_cnt [19]),
    .b(\SYSTICK/systick_cnt [22]),
    .c(\SYSTICK/STK2 [3]),
    .d(\SYSTICK/STK2 [6]),
    .o(_al_u120_o));
  AL_MAP_LUT5 #(
    .EQN("(A*~(D*~C)*~(~E*B))"),
    .INIT(32'ha0aa2022))
    _al_u121 (
    .a(_al_u120_o),
    .b(\SYSTICK/systick_cnt [5]),
    .c(\SYSTICK/systick_cnt [8]),
    .d(\SYSTICK/STK1 [0]),
    .e(\SYSTICK/STK0 [5]),
    .o(_al_u121_o));
  AL_MAP_LUT4 #(
    .EQN("(B*A*~(D@C))"),
    .INIT(16'h8008))
    _al_u122 (
    .a(_al_u121_o),
    .b(_al_u119_o),
    .c(\SYSTICK/systick_cnt [9]),
    .d(\SYSTICK/STK1 [1]),
    .o(_al_u122_o));
  AL_MAP_LUT4 #(
    .EQN("(~(D@B)*~(C@A))"),
    .INIT(16'h8421))
    _al_u123 (
    .a(\SYSTICK/systick_cnt [1]),
    .b(\SYSTICK/systick_cnt [3]),
    .c(\SYSTICK/STK0 [1]),
    .d(\SYSTICK/STK0 [3]),
    .o(_al_u123_o));
  AL_MAP_LUT4 #(
    .EQN("(~(D@B)*~(C@A))"),
    .INIT(16'h8421))
    _al_u124 (
    .a(\SYSTICK/systick_cnt [10]),
    .b(\SYSTICK/systick_cnt [12]),
    .c(\SYSTICK/STK1 [2]),
    .d(\SYSTICK/STK1 [4]),
    .o(_al_u124_o));
  AL_MAP_LUT4 #(
    .EQN("(~(D@B)*~(C@A))"),
    .INIT(16'h8421))
    _al_u125 (
    .a(\SYSTICK/systick_cnt [23]),
    .b(\SYSTICK/systick_cnt [6]),
    .c(\SYSTICK/STK2 [7]),
    .d(\SYSTICK/STK0 [6]),
    .o(_al_u125_o));
  AL_MAP_LUT4 #(
    .EQN("(~(C@B)*~(D@A))"),
    .INIT(16'h8241))
    _al_u126 (
    .a(\SYSTICK/systick_cnt [11]),
    .b(\SYSTICK/systick_cnt [18]),
    .c(\SYSTICK/STK2 [2]),
    .d(\SYSTICK/STK1 [3]),
    .o(_al_u126_o));
  AL_MAP_LUT4 #(
    .EQN("(D*C*B*A)"),
    .INIT(16'h8000))
    _al_u127 (
    .a(_al_u123_o),
    .b(_al_u124_o),
    .c(_al_u125_o),
    .d(_al_u126_o),
    .o(_al_u127_o));
  AL_MAP_LUT4 #(
    .EQN("(~(D*~B)*~(C*~A))"),
    .INIT(16'h8caf))
    _al_u128 (
    .a(\SYSTICK/systick_cnt [13]),
    .b(\SYSTICK/systick_cnt [15]),
    .c(\SYSTICK/STK1 [5]),
    .d(\SYSTICK/STK1 [7]),
    .o(_al_u128_o));
  AL_MAP_LUT4 #(
    .EQN("(~(D@B)*~(C@A))"),
    .INIT(16'h8421))
    _al_u129 (
    .a(\SYSTICK/systick_cnt [16]),
    .b(\SYSTICK/systick_cnt [7]),
    .c(\SYSTICK/STK2 [0]),
    .d(\SYSTICK/STK0 [7]),
    .o(_al_u129_o));
  AL_MAP_LUT2 #(
    .EQN("~(B@A)"),
    .INIT(4'h9))
    _al_u130 (
    .a(\SYSTICK/systick_cnt [21]),
    .b(\SYSTICK/STK2 [5]),
    .o(_al_u130_o));
  AL_MAP_LUT5 #(
    .EQN("(C*B*A*~(~E*D))"),
    .INIT(32'h80800080))
    _al_u131 (
    .a(_al_u128_o),
    .b(_al_u129_o),
    .c(_al_u130_o),
    .d(\SYSTICK/systick_cnt [14]),
    .e(\SYSTICK/STK1 [6]),
    .o(_al_u131_o));
  AL_MAP_LUT5 #(
    .EQN("(E*D*C*B*A)"),
    .INIT(32'h80000000))
    _al_u132 (
    .a(_al_u122_o),
    .b(_al_u114_o),
    .c(_al_u127_o),
    .d(_al_u118_o),
    .e(_al_u131_o),
    .o(\SYSTICK/stint_set ));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u133 (
    .a(STBi_STK_lutinv),
    .b(WB_CYCi),
    .c(WB_WEi),
    .o(\SYSTICK/n12 ));
  AL_MAP_LUT3 #(
    .EQN("(~C*~B*A)"),
    .INIT(8'h02))
    _al_u134 (
    .a(\SYSTICK/n12 ),
    .b(WB_ADRi[1]),
    .c(WB_ADRi[0]),
    .o(\SYSTICK/mux8_b0_sel_is_3_o ));
  AL_MAP_LUT2 #(
    .EQN("(B*~A)"),
    .INIT(4'h4))
    _al_u135 (
    .a(WB_ADRi[1]),
    .b(WB_ADRi[0]),
    .o(\SYSTICK/mux3_b0_sel_is_1_o ));
  AL_MAP_LUT3 #(
    .EQN("(~C*B*A)"),
    .INIT(8'h08))
    _al_u136 (
    .a(\SYSTICK/n12 ),
    .b(\SYSTICK/mux3_b0_sel_is_1_o ),
    .c(rst),
    .o(\SYSTICK/mux11_b0_sel_is_2_o ));
  AL_MAP_LUT4 #(
    .EQN("(~D*~C*B*A)"),
    .INIT(16'h0008))
    _al_u137 (
    .a(\SYSTICK/n12 ),
    .b(WB_ADRi[1]),
    .c(WB_ADRi[0]),
    .d(rst),
    .o(\SYSTICK/mux10_b0_sel_is_2_o ));
  AL_MAP_LUT4 #(
    .EQN("(~D*C*B*A)"),
    .INIT(16'h0080))
    _al_u138 (
    .a(\SYSTICK/n12 ),
    .b(WB_ADRi[1]),
    .c(WB_ADRi[0]),
    .d(rst),
    .o(\SYSTICK/mux9_b0_sel_is_2_o ));
  AL_MAP_LUT5 #(
    .EQN("~(~E*~(B*A*~(~D*~C)))"),
    .INIT(32'hffff8880))
    _al_u139 (
    .a(\SYSTICK/n12 ),
    .b(\SYSTICK/mux3_b0_sel_is_1_o ),
    .c(WB_DATi[7]),
    .d(WB_DATi[5]),
    .e(rst),
    .o(\SYSTICK/n6 ));
  AL_MAP_LUT5 #(
    .EQN("~(~E*~(B*A*~(~D*~C)))"),
    .INIT(32'hffff8880))
    _al_u140 (
    .a(\SYSTICK/n12 ),
    .b(\SYSTICK/mux3_b0_sel_is_1_o ),
    .c(WB_DATi[7]),
    .d(WB_DATi[3]),
    .e(rst),
    .o(\SYSTICK/n9 ));
  AL_MAP_LUT2 #(
    .EQN("(B*A)"),
    .INIT(4'h8))
    _al_u70 (
    .a(SYST_PAUSE),
    .b(\SYSTICK/TIMC [1]),
    .o(\SYSTICK/systick_pause ));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u71 (
    .a(WB_ADRi[11]),
    .b(WB_CYCi),
    .c(WB_WEi),
    .o(\DATA_SPM/ramwe ));
  AL_MAP_LUT3 #(
    .EQN("(C*B*~A)"),
    .INIT(8'h40))
    _al_u72 (
    .a(WB_ADRi[11]),
    .b(WB_ADRi[10]),
    .c(WB_ADRi[9]),
    .o(_al_u72_o));
  AL_MAP_LUT4 #(
    .EQN("(~D*C*B*~A)"),
    .INIT(16'h0040))
    _al_u73 (
    .a(WB_ADRi[11]),
    .b(WB_ADRi[10]),
    .c(WB_ADRi[9]),
    .d(WB_ADRi[8]),
    .o(_al_u73_o));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u74 (
    .a(WB_ADRi[7]),
    .b(WB_ADRi[6]),
    .c(WB_ADRi[5]),
    .o(_al_u74_o));
  AL_MAP_LUT2 #(
    .EQN("(B*A)"),
    .INIT(4'h8))
    _al_u75 (
    .a(_al_u74_o),
    .b(WB_ADRi[4]),
    .o(_al_u75_o));
  AL_MAP_LUT2 #(
    .EQN("(B*A)"),
    .INIT(4'h8))
    _al_u76 (
    .a(_al_u75_o),
    .b(_al_u73_o),
    .o(STBi_SYC));
  AL_MAP_LUT4 #(
    .EQN("(~D*~C*B*A)"),
    .INIT(16'h0008))
    _al_u77 (
    .a(_al_u73_o),
    .b(_al_u74_o),
    .c(WB_ADRi[4]),
    .d(WB_ADRi[3]),
    .o(STBi_ITC));
  AL_MAP_LUT4 #(
    .EQN("(D*C*B*A)"),
    .INIT(16'h8000))
    _al_u78 (
    .a(_al_u72_o),
    .b(WB_ADRi[8]),
    .c(WB_CYCi),
    .d(WB_WEi),
    .o(\SYSCALL_UNIT/n1 ));
  AL_MAP_LUT2 #(
    .EQN("(~B*A)"),
    .INIT(4'h2))
    _al_u79 (
    .a(\SYSCALL_UNIT/n1 ),
    .b(SYSCALL_clr),
    .o(\SYSCALL_UNIT/mux2_b0_sel_is_2_o ));
  AL_MAP_LUT4 #(
    .EQN("(~D*~C*~B*~A)"),
    .INIT(16'h0001))
    _al_u80 (
    .a(WB_ADRi[7]),
    .b(WB_ADRi[6]),
    .c(WB_ADRi[5]),
    .d(WB_ADRi[2]),
    .o(_al_u80_o));
  AL_MAP_LUT5 #(
    .EQN("(~E*~D*~C*B*A)"),
    .INIT(32'h00000008))
    _al_u81 (
    .a(_al_u80_o),
    .b(_al_u72_o),
    .c(WB_ADRi[8]),
    .d(WB_ADRi[4]),
    .e(WB_ADRi[3]),
    .o(STBi_STK_lutinv));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+A*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+~(A)*~(B)*~(C)*~(D)*E+A*~(B)*~(C)*~(D)*E+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*~(B)*C*~(D)*E+~(A)*~(B)*~(C)*D*E+A*B*~(C)*D*E+~(A)*~(B)*C*D*E)"),
    .INIT(32'h193b5d7f))
    _al_u82 (
    .a(WB_ADRi[1]),
    .b(WB_ADRi[0]),
    .c(\SYSTICK/STK2 [7]),
    .d(\SYSTICK/STK1 [7]),
    .e(\SYSTICK/STK0 [7]),
    .o(_al_u82_o));
  AL_MAP_LUT4 #(
    .EQN("(~(C*B)*~(D*A))"),
    .INIT(16'h153f))
    _al_u83 (
    .a(STBi_ITC),
    .b(WB_ADRi[11]),
    .c(DATo_SPM[7]),
    .d(DATo_ITC[7]),
    .o(_al_u83_o));
  AL_MAP_LUT5 #(
    .EQN("~(A*~(~D*C)*~(E*B))"),
    .INIT(32'hddfd55f5))
    _al_u84 (
    .a(_al_u83_o),
    .b(STBi_SYC),
    .c(STBi_STK_lutinv),
    .d(_al_u82_o),
    .e(DATo_SYC[7]),
    .o(WB_DATo[7]));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+A*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+~(A)*~(B)*~(C)*~(D)*E+A*~(B)*~(C)*~(D)*E+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*~(B)*C*~(D)*E+~(A)*~(B)*~(C)*D*E+A*B*~(C)*D*E+~(A)*~(B)*C*D*E)"),
    .INIT(32'h193b5d7f))
    _al_u85 (
    .a(WB_ADRi[1]),
    .b(WB_ADRi[0]),
    .c(\SYSTICK/STK2 [6]),
    .d(\SYSTICK/STK1 [6]),
    .e(\SYSTICK/STK0 [6]),
    .o(_al_u85_o));
  AL_MAP_LUT4 #(
    .EQN("(~(C*B)*~(D*A))"),
    .INIT(16'h153f))
    _al_u86 (
    .a(STBi_ITC),
    .b(WB_ADRi[11]),
    .c(DATo_SPM[6]),
    .d(DATo_ITC[6]),
    .o(_al_u86_o));
  AL_MAP_LUT5 #(
    .EQN("~(A*~(~D*C)*~(E*B))"),
    .INIT(32'hddfd55f5))
    _al_u87 (
    .a(_al_u86_o),
    .b(STBi_SYC),
    .c(STBi_STK_lutinv),
    .d(_al_u85_o),
    .e(DATo_SYC[6]),
    .o(WB_DATo[6]));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+A*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+~(A)*~(B)*~(C)*~(D)*E+A*~(B)*~(C)*~(D)*E+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*~(B)*C*~(D)*E+~(A)*~(B)*~(C)*D*E+A*B*~(C)*D*E+~(A)*~(B)*C*D*E)"),
    .INIT(32'h193b5d7f))
    _al_u88 (
    .a(WB_ADRi[1]),
    .b(WB_ADRi[0]),
    .c(\SYSTICK/STK2 [5]),
    .d(\SYSTICK/STK1 [5]),
    .e(\SYSTICK/STK0 [5]),
    .o(_al_u88_o));
  AL_MAP_LUT4 #(
    .EQN("(~(C*B)*~(D*A))"),
    .INIT(16'h153f))
    _al_u89 (
    .a(STBi_ITC),
    .b(WB_ADRi[11]),
    .c(DATo_SPM[5]),
    .d(DATo_ITC[5]),
    .o(_al_u89_o));
  AL_MAP_LUT5 #(
    .EQN("~(A*~(~D*C)*~(E*B))"),
    .INIT(32'hddfd55f5))
    _al_u90 (
    .a(_al_u89_o),
    .b(STBi_SYC),
    .c(STBi_STK_lutinv),
    .d(_al_u88_o),
    .e(DATo_SYC[5]),
    .o(WB_DATo[5]));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+A*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+~(A)*~(B)*~(C)*~(D)*E+A*~(B)*~(C)*~(D)*E+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*~(B)*C*~(D)*E+~(A)*~(B)*~(C)*D*E+A*B*~(C)*D*E+~(A)*~(B)*C*D*E)"),
    .INIT(32'h193b5d7f))
    _al_u91 (
    .a(WB_ADRi[1]),
    .b(WB_ADRi[0]),
    .c(\SYSTICK/STK2 [4]),
    .d(\SYSTICK/STK1 [4]),
    .e(\SYSTICK/STK0 [4]),
    .o(_al_u91_o));
  AL_MAP_LUT4 #(
    .EQN("(~(C*B)*~(D*A))"),
    .INIT(16'h153f))
    _al_u92 (
    .a(STBi_ITC),
    .b(WB_ADRi[11]),
    .c(DATo_SPM[4]),
    .d(DATo_ITC[4]),
    .o(_al_u92_o));
  AL_MAP_LUT5 #(
    .EQN("~(A*~(~D*C)*~(E*B))"),
    .INIT(32'hddfd55f5))
    _al_u93 (
    .a(_al_u92_o),
    .b(STBi_SYC),
    .c(STBi_STK_lutinv),
    .d(_al_u91_o),
    .e(DATo_SYC[4]),
    .o(WB_DATo[4]));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)+A*~(B)*~(C)*~(D)+~(A)*B*~(C)*~(D)+A*B*~(C)*~(D)+~(A)*~(B)*~(C)*D+A*~(B)*~(C)*D+~(A)*~(B)*C*D+~(A)*B*C*D)"),
    .INIT(16'h530f))
    _al_u94 (
    .a(\SYSTICK/STK2 [3]),
    .b(\SYSTICK/STK0 [3]),
    .c(WB_ADRi[1]),
    .d(WB_ADRi[0]),
    .o(_al_u94_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*B*~(C)*~(D)+A*B*~(C)*~(D)+A*~(B)*C*~(D)+A*B*C*~(D)+~(A)*~(B)*~(C)*D+A*~(B)*~(C)*D+~(A)*B*~(C)*D+A*B*~(C)*D)"),
    .INIT(16'h0fac))
    _al_u95 (
    .a(\SYSTICK/TIMC [3]),
    .b(\SYSTICK/STK1 [3]),
    .c(_al_u94_o),
    .d(WB_ADRi[0]),
    .o(DATo_STK[3]));
  AL_MAP_LUT4 #(
    .EQN("(~(C*B)*~(D*A))"),
    .INIT(16'h153f))
    _al_u96 (
    .a(STBi_ITC),
    .b(WB_ADRi[11]),
    .c(DATo_SPM[3]),
    .d(DATo_ITC[3]),
    .o(_al_u96_o));
  AL_MAP_LUT5 #(
    .EQN("~(A*~(D*C)*~(E*B))"),
    .INIT(32'hfdddf555))
    _al_u97 (
    .a(_al_u96_o),
    .b(STBi_SYC),
    .c(STBi_STK_lutinv),
    .d(DATo_STK[3]),
    .e(DATo_SYC[3]),
    .o(WB_DATo[3]));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)+A*~(B)*~(C)*~(D)+~(A)*B*~(C)*~(D)+A*B*~(C)*~(D)+~(A)*~(B)*~(C)*D+A*~(B)*~(C)*D+~(A)*~(B)*C*D+~(A)*B*C*D)"),
    .INIT(16'h530f))
    _al_u98 (
    .a(\SYSTICK/STK2 [2]),
    .b(\SYSTICK/STK0 [2]),
    .c(WB_ADRi[1]),
    .d(WB_ADRi[0]),
    .o(_al_u98_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*B*~(C)*~(D)+A*B*~(C)*~(D)+A*~(B)*C*~(D)+A*B*C*~(D)+~(A)*~(B)*~(C)*D+A*~(B)*~(C)*D+~(A)*B*~(C)*D+A*B*~(C)*D)"),
    .INIT(16'h0fac))
    _al_u99 (
    .a(\SYSTICK/TIMC [2]),
    .b(\SYSTICK/STK1 [2]),
    .c(_al_u98_o),
    .d(WB_ADRi[0]),
    .o(DATo_STK[2]));

endmodule 

module KC_LS1u_plus  // ../RTL/cpu/KC_LS1u_plus.v(1)
  (
  INT,
  IVEC_addr,
  WAIT,
  WAIT_DATA,
  clk,
  ddata_i,
  instr,
  rst,
  INSTR_HOLD,
  IN_ISP,
  daddr,
  ddata_o,
  dread,
  dwrite,
  iaddr
  );

  input INT;  // ../RTL/cpu/KC_LS1u_plus.v(3)
  input [23:0] IVEC_addr;  // ../RTL/cpu/KC_LS1u_plus.v(4)
  input WAIT;  // ../RTL/cpu/KC_LS1u_plus.v(3)
  input WAIT_DATA;  // ../RTL/cpu/KC_LS1u_plus.v(11)
  input clk;  // ../RTL/cpu/KC_LS1u_plus.v(3)
  input [7:0] ddata_i;  // ../RTL/cpu/KC_LS1u_plus.v(13)
  input [15:0] instr;  // ../RTL/cpu/KC_LS1u_plus.v(7)
  input rst;  // ../RTL/cpu/KC_LS1u_plus.v(3)
  output INSTR_HOLD;  // ../RTL/cpu/KC_LS1u_plus.v(12)
  output IN_ISP;  // ../RTL/cpu/KC_LS1u_plus.v(5)
  output [23:0] daddr;  // ../RTL/cpu/KC_LS1u_plus.v(8)
  output [7:0] ddata_o;  // ../RTL/cpu/KC_LS1u_plus.v(14)
  output dread;  // ../RTL/cpu/KC_LS1u_plus.v(9)
  output dwrite;  // ../RTL/cpu/KC_LS1u_plus.v(10)
  output [23:0] iaddr;  // ../RTL/cpu/KC_LS1u_plus.v(6)

  wire [7:0] A;  // ../RTL/cpu/KC_LS1u_plus.v(92)
  wire [7:0] ALU_out;  // ../RTL/cpu/KC_LS1u_plus.v(208)
  wire [7:0] B;  // ../RTL/cpu/KC_LS1u_plus.v(92)
  wire [7:0] C;  // ../RTL/cpu/KC_LS1u_plus.v(92)
  wire [7:0] D;  // ../RTL/cpu/KC_LS1u_plus.v(92)
  wire [23:0] PCP1;  // ../RTL/cpu/KC_LS1u_plus.v(35)
  wire [7:0] RET0;  // ../RTL/cpu/KC_LS1u_plus.v(19)
  wire [7:0] RET1;  // ../RTL/cpu/KC_LS1u_plus.v(19)
  wire [7:0] RET2;  // ../RTL/cpu/KC_LS1u_plus.v(19)
  wire [7:0] RTA0;  // ../RTL/cpu/KC_LS1u_plus.v(20)
  wire [7:0] RTA1;  // ../RTL/cpu/KC_LS1u_plus.v(20)
  wire [7:0] RTA2;  // ../RTL/cpu/KC_LS1u_plus.v(20)
  wire [7:0] XREGr;  // ../RTL/cpu/KC_LS1u_plus.v(188)
  wire [3:0] dbsrc_addr;  // ../RTL/cpu/KC_LS1u_plus.v(146)
  wire [23:0] jaddr;  // ../RTL/cpu/KC_LS1u_plus.v(23)
  wire  \mux55_b0/B1_1 ;  // ../RTL/cpu/KC_LS1u_plus.v(199)
  wire  \mux55_b1/B1_1 ;  // ../RTL/cpu/KC_LS1u_plus.v(199)
  wire  \mux55_b2/B1_0 ;  // ../RTL/cpu/KC_LS1u_plus.v(199)
  wire  \mux55_b3/B0_2 ;  // ../RTL/cpu/KC_LS1u_plus.v(199)
  wire  \mux55_b3/B1_0 ;  // ../RTL/cpu/KC_LS1u_plus.v(199)
  wire  \mux55_b4/B0_2 ;  // ../RTL/cpu/KC_LS1u_plus.v(199)
  wire  \mux55_b4/B1_0 ;  // ../RTL/cpu/KC_LS1u_plus.v(199)
  wire  \mux55_b5/B1_1 ;  // ../RTL/cpu/KC_LS1u_plus.v(199)
  wire  \mux55_b6/B1_1 ;  // ../RTL/cpu/KC_LS1u_plus.v(199)
  wire  \mux55_b7/B1_0 ;  // ../RTL/cpu/KC_LS1u_plus.v(199)
  wire  \mux58_b0/B0_2 ;  // ../RTL/cpu/KC_LS1u_plus.v(277)
  wire [7:0] n35;
  wire [7:0] n36;
  wire [7:0] n37;
  wire [7:0] n38;
  wire [7:0] n39;
  wire [7:0] n40;
  wire [7:0] n42;
  wire [7:0] n43;
  wire [7:0] n44;
  wire [7:0] n65;
  wire [7:0] n66;
  wire [7:0] n67;
  wire [23:0] n7;
  wire \ALU_H4/SYNTHESIZED_WIRE_101_lutinv ;  // ../RTL/cpu/alu74181.v(65)
  wire \ALU_H4/SYNTHESIZED_WIRE_103_lutinv ;  // ../RTL/cpu/alu74181.v(67)
  wire \ALU_H4/SYNTHESIZED_WIRE_105_lutinv ;  // ../RTL/cpu/alu74181.v(69)
  wire \ALU_H4/SYNTHESIZED_WIRE_10_lutinv ;  // ../RTL/cpu/alu74181.v(18)
  wire \ALU_H4/SYNTHESIZED_WIRE_115_lutinv ;  // ../RTL/cpu/alu74181.v(79)
  wire \ALU_H4/SYNTHESIZED_WIRE_25_lutinv ;  // ../RTL/cpu/alu74181.v(33)
  wire \ALU_H4/SYNTHESIZED_WIRE_6_lutinv ;  // ../RTL/cpu/alu74181.v(14)
  wire \ALU_H4/SYNTHESIZED_WIRE_8_lutinv ;  // ../RTL/cpu/alu74181.v(16)
  wire \ALU_H4/SYNTHESIZED_WIRE_94_lutinv ;  // ../RTL/cpu/alu74181.v(59)
  wire \ALU_H4/SYNTHESIZED_WIRE_99 ;  // ../RTL/cpu/alu74181.v(64)
  wire \ALU_H4/n23 ;
  wire \ALU_H4/n31 ;
  wire \ALU_H4/n40_lutinv ;
  wire \ALU_H4/n45 ;
  wire \ALU_L4/SYNTHESIZED_WIRE_10_lutinv ;  // ../RTL/cpu/alu74181.v(18)
  wire \ALU_L4/SYNTHESIZED_WIRE_25_lutinv ;  // ../RTL/cpu/alu74181.v(33)
  wire \ALU_L4/SYNTHESIZED_WIRE_6_lutinv ;  // ../RTL/cpu/alu74181.v(14)
  wire \ALU_L4/SYNTHESIZED_WIRE_8_lutinv ;  // ../RTL/cpu/alu74181.v(16)
  wire \ALU_L4/SYNTHESIZED_WIRE_94_lutinv ;  // ../RTL/cpu/alu74181.v(59)
  wire \ALU_L4/n19 ;
  wire _al_u355_o;
  wire _al_u356_o;
  wire _al_u361_o;
  wire _al_u367_o;
  wire _al_u369_o;
  wire _al_u372_o;
  wire _al_u374_o;
  wire _al_u378_o;
  wire _al_u381_o;
  wire _al_u382_o;
  wire _al_u383_o;
  wire _al_u385_o;
  wire _al_u387_o;
  wire _al_u388_o;
  wire _al_u389_o;
  wire _al_u390_o;
  wire _al_u392_o;
  wire _al_u393_o;
  wire _al_u394_o;
  wire _al_u396_o;
  wire _al_u397_o;
  wire _al_u398_o;
  wire _al_u399_o;
  wire _al_u400_o;
  wire _al_u403_o;
  wire _al_u404_o;
  wire _al_u407_o;
  wire _al_u409_o;
  wire _al_u411_o;
  wire _al_u412_o;
  wire _al_u413_o;
  wire _al_u414_o;
  wire _al_u416_o;
  wire _al_u417_o;
  wire _al_u418_o;
  wire _al_u419_o;
  wire _al_u420_o;
  wire _al_u421_o;
  wire _al_u431_o;
  wire _al_u452_o;
  wire _al_u453_o;
  wire _al_u454_o;
  wire _al_u457_o;
  wire _al_u458_o;
  wire _al_u459_o;
  wire _al_u460_o;
  wire _al_u461_o;
  wire _al_u462_o;
  wire _al_u463_o;
  wire _al_u467_o;
  wire _al_u468_o;
  wire _al_u469_o;
  wire _al_u472_o;
  wire _al_u474_o;
  wire _al_u475_o;
  wire _al_u476_o;
  wire _al_u477_o;
  wire _al_u478_o;
  wire _al_u479_o;
  wire _al_u480_o;
  wire _al_u481_o;
  wire _al_u490_o;
  wire _al_u495_o;
  wire _al_u496_o;
  wire _al_u497_o;
  wire _al_u498_o;
  wire _al_u501_o;
  wire _al_u502_o;
  wire _al_u503_o;
  wire _al_u504_o;
  wire _al_u512_o;
  wire _al_u514_o;
  wire _al_u517_o;
  wire _al_u518_o;
  wire _al_u519_o;
  wire _al_u520_o;
  wire _al_u523_o;
  wire _al_u524_o;
  wire _al_u525_o;
  wire _al_u526_o;
  wire _al_u541_o;
  wire _al_u542_o;
  wire _al_u544_o;
  wire _al_u546_o;
  wire _al_u547_o;
  wire _al_u548_o;
  wire _al_u550_o;
  wire _al_u551_o;
  wire _al_u552_o;
  wire _al_u553_o;
  wire _al_u554_o;
  wire _al_u555_o;
  wire _al_u556_o;
  wire _al_u564_o;
  wire _al_u565_o;
  wire _al_u566_o;
  wire _al_u567_o;
  wire _al_u568_o;
  wire _al_u569_o;
  wire _al_u571_o;
  wire _al_u573_o;
  wire _al_u574_o;
  wire _al_u582_o;
  wire _al_u588_o;
  wire _al_u589_o;
  wire _al_u593_o;
  wire _al_u596_o;
  wire _al_u597_o;
  wire _al_u611_o;
  wire _al_u612_o;
  wire _al_u615_o;
  wire _al_u616_o;
  wire _al_u645_o;
  wire _al_u649_o;
  wire _al_u652_o;
  wire _al_u653_o;
  wire _al_u666_o;
  wire \add0/c11 ;  // ../RTL/cpu/KC_LS1u_plus.v(36)
  wire \add0/c15 ;  // ../RTL/cpu/KC_LS1u_plus.v(36)
  wire \add0/c19 ;  // ../RTL/cpu/KC_LS1u_plus.v(36)
  wire \add0/c3 ;  // ../RTL/cpu/KC_LS1u_plus.v(36)
  wire \add0/c7 ;  // ../RTL/cpu/KC_LS1u_plus.v(36)
  wire int_filter;  // ../RTL/cpu/KC_LS1u_plus.v(28)
  wire jmp_en;  // ../RTL/cpu/KC_LS1u_plus.v(129)
  wire jmp_lutinv;  // ../RTL/cpu/KC_LS1u_plus.v(25)
  wire jmp_wait;  // ../RTL/cpu/KC_LS1u_plus.v(24)
  wire mux13_b0_sel_is_3_o;
  wire mux14_b0_sel_is_3_o;
  wire mux15_b0_sel_is_3_o;
  wire mux16_b0_sel_is_3_o;
  wire mux17_b0_sel_is_3_o;
  wire mux18_b0_sel_is_3_o;
  wire mux3_b0_sel_is_0_o;
  wire mux41_b0_sel_is_3_o;
  wire mux42_b0_sel_is_3_o;
  wire mux43_b0_sel_is_3_o;
  wire mux44_b0_sel_is_3_o;
  wire mux45_b0_sel_is_3_o;
  wire mux46_b0_sel_is_3_o;
  wire mux47_b0_sel_is_3_o;
  wire n100;
  wire n110;
  wire n12_lutinv;
  wire n18;
  wire n2;
  wire n41;
  wire regwrite_lutinv;  // ../RTL/cpu/KC_LS1u_plus.v(89)
  wire rst_neg;
  wire sel0_b1_sel_o_lutinv;  // ../RTL/cpu/KC_LS1u_plus.v(186)
  wire sel0_b2_sel_o_lutinv;  // ../RTL/cpu/KC_LS1u_plus.v(186)
  wire u45_sel_is_3_o;

  assign dwrite = n110;
  AL_MAP_LUT2 #(
    .EQN("(~B*~A)"),
    .INIT(4'h1))
    _al_u355 (
    .a(instr[15]),
    .b(instr[12]),
    .o(_al_u355_o));
  AL_MAP_LUT2 #(
    .EQN("(~B*A)"),
    .INIT(4'h2))
    _al_u356 (
    .a(_al_u355_o),
    .b(instr[11]),
    .o(_al_u356_o));
  AL_MAP_LUT3 #(
    .EQN("(C*~B*A)"),
    .INIT(8'h20))
    _al_u357 (
    .a(_al_u356_o),
    .b(instr[14]),
    .c(instr[13]),
    .o(dread));
  AL_MAP_LUT5 #(
    .EQN("(E*~D*~C*~B*~A)"),
    .INIT(32'h00010000))
    _al_u358 (
    .a(instr[15]),
    .b(instr[14]),
    .c(instr[13]),
    .d(instr[12]),
    .e(instr[11]),
    .o(jmp_en));
  AL_MAP_LUT2 #(
    .EQN("(~B*A)"),
    .INIT(4'h2))
    _al_u359 (
    .a(INT),
    .b(IN_ISP),
    .o(int_filter));
  AL_MAP_LUT2 #(
    .EQN("(~B*~A)"),
    .INIT(4'h1))
    _al_u360 (
    .a(WAIT),
    .b(jmp_wait),
    .o(n12_lutinv));
  AL_MAP_LUT2 #(
    .EQN("(B*A)"),
    .INIT(4'h8))
    _al_u361 (
    .a(int_filter),
    .b(n12_lutinv),
    .o(_al_u361_o));
  AL_MAP_LUT4 #(
    .EQN("(~D*~C*~B*A)"),
    .INIT(16'h0002))
    _al_u362 (
    .a(jmp_en),
    .b(instr[10]),
    .c(instr[9]),
    .d(instr[8]),
    .o(u45_sel_is_3_o));
  AL_MAP_LUT3 #(
    .EQN("~(~B*~(C*~A))"),
    .INIT(8'hdc))
    _al_u363 (
    .a(u45_sel_is_3_o),
    .b(_al_u361_o),
    .c(IN_ISP),
    .o(n41));
  AL_MAP_LUT5 #(
    .EQN("(A*~(B)*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+A*B*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+A*~(B)*~(C)*D*~(E)+A*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+A*~(B)*C*D*~(E)+~(A)*~(B)*C*~(D)*E+~(A)*B*C*~(D)*E+~(A)*~(B)*~(C)*D*E+~(A)*~(B)*C*D*E)"),
    .INIT(32'h11503bba))
    _al_u364 (
    .a(instr[15]),
    .b(instr[14]),
    .c(instr[13]),
    .d(instr[12]),
    .e(instr[11]),
    .o(regwrite_lutinv));
  AL_MAP_LUT4 #(
    .EQN("(D*C*B*A)"),
    .INIT(16'h8000))
    _al_u365 (
    .a(regwrite_lutinv),
    .b(instr[10]),
    .c(instr[9]),
    .d(instr[8]),
    .o(n2));
  AL_MAP_LUT2 #(
    .EQN("(B*A)"),
    .INIT(4'h8))
    _al_u366 (
    .a(n2),
    .b(n12_lutinv),
    .o(n110));
  AL_MAP_LUT3 #(
    .EQN("(~C*B*A)"),
    .INIT(8'h08))
    _al_u367 (
    .a(regwrite_lutinv),
    .b(n12_lutinv),
    .c(instr[10]),
    .o(_al_u367_o));
  AL_MAP_LUT3 #(
    .EQN("(~C*~B*A)"),
    .INIT(8'h02))
    _al_u368 (
    .a(_al_u367_o),
    .b(instr[9]),
    .c(instr[8]),
    .o(mux47_b0_sel_is_3_o));
  AL_MAP_LUT2 #(
    .EQN("(B*~A)"),
    .INIT(4'h4))
    _al_u369 (
    .a(instr[9]),
    .b(instr[8]),
    .o(_al_u369_o));
  AL_MAP_LUT2 #(
    .EQN("(B*A)"),
    .INIT(4'h8))
    _al_u370 (
    .a(_al_u367_o),
    .b(_al_u369_o),
    .o(mux46_b0_sel_is_3_o));
  AL_MAP_LUT3 #(
    .EQN("(~C*B*A)"),
    .INIT(8'h08))
    _al_u371 (
    .a(_al_u367_o),
    .b(instr[9]),
    .c(instr[8]),
    .o(mux45_b0_sel_is_3_o));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u372 (
    .a(regwrite_lutinv),
    .b(n12_lutinv),
    .c(instr[10]),
    .o(_al_u372_o));
  AL_MAP_LUT3 #(
    .EQN("(~C*B*A)"),
    .INIT(8'h08))
    _al_u373 (
    .a(_al_u372_o),
    .b(instr[9]),
    .c(instr[8]),
    .o(mux41_b0_sel_is_3_o));
  AL_MAP_LUT5 #(
    .EQN("(~A*(B*~(C)*~(D)*~(E)+~(B)*C*~(D)*~(E)+~(B)*~(C)*D*~(E)+~(B)*C*D*~(E)+~(B)*C*~(D)*E+B*C*~(D)*E+~(B)*~(C)*D*E+~(B)*C*D*E))"),
    .INIT(32'h11501114))
    _al_u374 (
    .a(instr[15]),
    .b(instr[14]),
    .c(instr[13]),
    .d(instr[12]),
    .e(instr[11]),
    .o(_al_u374_o));
  AL_MAP_LUT4 #(
    .EQN("(A*~(B)*~(C)*~(D)+~(A)*B*~(C)*~(D)+~(A)*B*C*~(D)+A*B*C*~(D)+~(A)*~(B)*~(C)*D+A*~(B)*~(C)*D+~(A)*B*~(C)*D+A*B*~(C)*D+~(A)*~(B)*C*D+~(A)*B*C*D+A*B*C*D)"),
    .INIT(16'hdfc6))
    _al_u375 (
    .a(_al_u355_o),
    .b(instr[14]),
    .c(instr[13]),
    .d(instr[11]),
    .o(sel0_b2_sel_o_lutinv));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+A*B*C*~(D)*~(E)+~(A)*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+A*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+A*B*C*D*~(E)+~(A)*~(B)*~(C)*~(D)*E+A*~(B)*~(C)*~(D)*E+~(A)*B*~(C)*~(D)*E+A*B*~(C)*~(D)*E+A*~(B)*C*~(D)*E+~(A)*B*C*~(D)*E+A*B*C*~(D)*E+A*~(B)*~(C)*D*E+~(A)*B*~(C)*D*E+A*B*~(C)*D*E+A*~(B)*C*D*E+~(A)*B*C*D*E+A*B*C*D*E)"),
    .INIT(32'heeeff4f1))
    _al_u376 (
    .a(instr[15]),
    .b(instr[14]),
    .c(instr[13]),
    .d(instr[12]),
    .e(instr[11]),
    .o(sel0_b1_sel_o_lutinv));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~((C*~B))*~(D)*~(E)+~(A)*~((C*~B))*D*~(E)+A*~((C*~B))*D*~(E)+~(A)*(C*~B)*D*~(E)+A*(C*~B)*D*~(E)+~(A)*~((C*~B))*~(D)*E+A*~((C*~B))*~(D)*E+A*(C*~B)*~(D)*E+~(A)*~((C*~B))*D*E+A*~((C*~B))*D*E+A*(C*~B)*D*E)"),
    .INIT(32'hefefff45))
    _al_u377 (
    .a(instr[15]),
    .b(instr[14]),
    .c(instr[13]),
    .d(instr[12]),
    .e(instr[11]),
    .o(dbsrc_addr[0]));
  AL_MAP_LUT4 #(
    .EQN("(D*(B*~(A)*~(C)+B*A*~(C)+~(B)*A*C+B*A*C))"),
    .INIT(16'hac00))
    _al_u378 (
    .a(instr[7]),
    .b(instr[6]),
    .c(B[0]),
    .d(A[0]),
    .o(_al_u378_o));
  AL_MAP_LUT4 #(
    .EQN("(~D*~(A*~(B)*~(C)+A*B*~(C)+~(A)*B*C+A*B*C))"),
    .INIT(16'h0035))
    _al_u379 (
    .a(instr[5]),
    .b(instr[4]),
    .c(B[0]),
    .d(A[0]),
    .o(\ALU_L4/SYNTHESIZED_WIRE_6_lutinv ));
  AL_MAP_LUT4 #(
    .EQN("~((D*~C)@(~B*~A))"),
    .INIT(16'he1ee))
    _al_u380 (
    .a(_al_u378_o),
    .b(\ALU_L4/SYNTHESIZED_WIRE_6_lutinv ),
    .c(instr[3]),
    .d(instr[2]),
    .o(ALU_out[0]));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*B*~(C)*~(D)+A*~(B)*C*~(D)+~(A)*B*C*~(D)+~(A)*~(B)*~(C)*D+~(A)*B*~(C)*D+~(A)*~(B)*C*D+A*~(B)*C*D+~(A)*B*C*D)"),
    .INIT(16'h7564))
    _al_u381 (
    .a(sel0_b1_sel_o_lutinv),
    .b(dbsrc_addr[0]),
    .c(ddata_i[0]),
    .d(C[0]),
    .o(_al_u381_o));
  AL_MAP_LUT5 #(
    .EQN("(~C*(A*~(B)*~(D)*~(E)+A*B*~(D)*~(E)+A*B*D*~(E)+A*~(B)*~(D)*E+A*B*~(D)*E+~(A)*~(B)*D*E+~(A)*B*D*E+A*B*D*E))"),
    .INIT(32'h0d0a080a))
    _al_u382 (
    .a(_al_u381_o),
    .b(ALU_out[0]),
    .c(sel0_b2_sel_o_lutinv),
    .d(dbsrc_addr[0]),
    .e(instr[0]),
    .o(_al_u382_o));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+A*B*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+A*B*~(C)*D*~(E)+A*B*C*D*~(E)+~(A)*~(B)*~(C)*~(D)*E+A*~(B)*~(C)*~(D)*E+~(A)*B*~(C)*~(D)*E+A*~(B)*C*~(D)*E+~(A)*B*C*~(D)*E+~(A)*~(B)*~(C)*D*E)"),
    .INIT(32'h016789ef))
    _al_u383 (
    .a(instr[1]),
    .b(instr[0]),
    .c(RET0[0]),
    .d(RET1[0]),
    .e(RTA0[0]),
    .o(_al_u383_o));
  AL_MAP_LUT4 #(
    .EQN("(~A*(C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B))"),
    .INIT(16'h5410))
    _al_u384 (
    .a(instr[1]),
    .b(instr[0]),
    .c(RTA1[0]),
    .d(RTA2[0]),
    .o(\mux55_b0/B1_1 ));
  AL_MAP_LUT2 #(
    .EQN("(~B*A)"),
    .INIT(4'h2))
    _al_u385 (
    .a(instr[2]),
    .b(instr[1]),
    .o(_al_u385_o));
  AL_MAP_LUT5 #(
    .EQN("(E*~((~B*~(C)*~(D)+~B*C*~(D)+~(~B)*C*D+~B*C*D))*~(A)+E*(~B*~(C)*~(D)+~B*C*~(D)+~(~B)*C*D+~B*C*D)*~(A)+~(E)*(~B*~(C)*~(D)+~B*C*~(D)+~(~B)*C*D+~B*C*D)*A+E*(~B*~(C)*~(D)+~B*C*~(D)+~(~B)*C*D+~B*C*D)*A)"),
    .INIT(32'hf577a022))
    _al_u386 (
    .a(dbsrc_addr[0]),
    .b(_al_u383_o),
    .c(\mux55_b0/B1_1 ),
    .d(instr[2]),
    .e(D[0]),
    .o(\mux58_b0/B0_2 ));
  AL_MAP_LUT4 #(
    .EQN("(~A*~(~D*C*B))"),
    .INIT(16'h5515))
    _al_u387 (
    .a(_al_u382_o),
    .b(\mux58_b0/B0_2 ),
    .c(sel0_b2_sel_o_lutinv),
    .d(sel0_b1_sel_o_lutinv),
    .o(_al_u387_o));
  AL_MAP_LUT5 #(
    .EQN("(A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+A*B*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+A*~(B)*~(C)*D*~(E)+A*B*~(C)*D*~(E)+~(A)*~(B)*C*~(D)*E+~(A)*~(B)*~(C)*D*E+~(A)*~(B)*C*D*E)"),
    .INIT(32'h11100bbe))
    _al_u388 (
    .a(instr[15]),
    .b(instr[14]),
    .c(instr[13]),
    .d(instr[12]),
    .e(instr[11]),
    .o(_al_u388_o));
  AL_MAP_LUT2 #(
    .EQN("(~B*~A)"),
    .INIT(4'h1))
    _al_u389 (
    .a(sel0_b1_sel_o_lutinv),
    .b(dbsrc_addr[0]),
    .o(_al_u389_o));
  AL_MAP_LUT5 #(
    .EQN("((E*~(D)*~(A)+E*D*~(A)+~(E)*D*A+E*D*A)*~(C)*~(B)+(E*~(D)*~(A)+E*D*~(A)+~(E)*D*A+E*D*A)*C*~(B)+~((E*~(D)*~(A)+E*D*~(A)+~(E)*D*A+E*D*A))*C*B+(E*~(D)*~(A)+E*D*~(A)+~(E)*D*A+E*D*A)*C*B)"),
    .INIT(32'hf3d1e2c0))
    _al_u390 (
    .a(_al_u389_o),
    .b(sel0_b2_sel_o_lutinv),
    .c(B[1]),
    .d(B[7]),
    .e(A[1]),
    .o(_al_u390_o));
  AL_MAP_LUT4 #(
    .EQN("~(~(D*B)*~(A)*~(C)+~(D*B)*A*~(C)+~(~(D*B))*A*C+~(D*B)*A*C)"),
    .INIT(16'h5c50))
    _al_u391 (
    .a(_al_u387_o),
    .b(_al_u390_o),
    .c(_al_u374_o),
    .d(_al_u388_o),
    .o(ddata_o[0]));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)+~(A)*B*~(C)*~(D)+~(A)*~(B)*C*~(D)+A*~(B)*C*~(D)+~(A)*~(B)*~(C)*D+A*~(B)*~(C)*D+~(A)*B*~(C)*D+A*B*~(C)*D)"),
    .INIT(16'h0f35))
    _al_u392 (
    .a(instr[5]),
    .b(instr[4]),
    .c(B[1]),
    .d(A[1]),
    .o(_al_u392_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*C*~(D)+A*~(B)*C*~(D)+~(A)*B*C*~(D)+A*B*C*~(D)+A*~(B)*~(C)*D+A*B*~(C)*D+~(A)*B*C*D+A*B*C*D)"),
    .INIT(16'hcaf0))
    _al_u393 (
    .a(instr[7]),
    .b(instr[6]),
    .c(_al_u392_o),
    .d(A[1]),
    .o(_al_u393_o));
  AL_MAP_LUT3 #(
    .EQN("(~B*~(C*~A))"),
    .INIT(8'h23))
    _al_u394 (
    .a(_al_u378_o),
    .b(\ALU_L4/SYNTHESIZED_WIRE_6_lutinv ),
    .c(instr[2]),
    .o(_al_u394_o));
  AL_MAP_LUT5 #(
    .EQN("(A@(~D*~(~C*~(E*~B))))"),
    .INIT(32'haa59aa5a))
    _al_u395 (
    .a(_al_u393_o),
    .b(_al_u378_o),
    .c(\ALU_L4/SYNTHESIZED_WIRE_6_lutinv ),
    .d(instr[3]),
    .e(instr[2]),
    .o(ALU_out[1]));
  AL_MAP_LUT2 #(
    .EQN("(B*~A)"),
    .INIT(4'h4))
    _al_u396 (
    .a(sel0_b1_sel_o_lutinv),
    .b(dbsrc_addr[0]),
    .o(_al_u396_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)+A*~(B)*~(C)*~(D)+~(A)*B*~(C)*~(D)+~(A)*B*C*~(D)+~(A)*~(B)*~(C)*D+A*~(B)*~(C)*D+~(A)*~(B)*C*D+A*~(B)*C*D)"),
    .INIT(16'h3347))
    _al_u397 (
    .a(ddata_i[1]),
    .b(sel0_b1_sel_o_lutinv),
    .c(C[1]),
    .d(dbsrc_addr[0]),
    .o(_al_u397_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*C*~(D)+A*~(B)*C*~(D)+~(A)*B*C*~(D)+A*B*C*~(D)+~(A)*~(B)*~(C)*D+A*~(B)*~(C)*D+~(A)*~(B)*C*D+~(A)*B*C*D)"),
    .INIT(16'h53f0))
    _al_u398 (
    .a(ALU_out[1]),
    .b(instr[1]),
    .c(_al_u397_o),
    .d(dbsrc_addr[0]),
    .o(_al_u398_o));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+A*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+A*B*~(C)*D*~(E)+A*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+~(A)*~(B)*~(C)*~(D)*E+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*B*~(C)*D*E)"),
    .INIT(32'h08196e7f))
    _al_u399 (
    .a(sel0_b1_sel_o_lutinv),
    .b(dbsrc_addr[0]),
    .c(B[0]),
    .d(A[0]),
    .e(A[2]),
    .o(_al_u399_o));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+A*B*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+A*B*~(C)*D*~(E)+A*B*C*D*~(E)+~(A)*~(B)*~(C)*~(D)*E+A*~(B)*~(C)*~(D)*E+~(A)*B*~(C)*~(D)*E+A*~(B)*C*~(D)*E+~(A)*B*C*~(D)*E+~(A)*~(B)*~(C)*D*E)"),
    .INIT(32'h016789ef))
    _al_u400 (
    .a(instr[1]),
    .b(instr[0]),
    .c(RET0[1]),
    .d(RET1[1]),
    .e(RTA0[1]),
    .o(_al_u400_o));
  AL_MAP_LUT4 #(
    .EQN("(~A*(C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B))"),
    .INIT(16'h5410))
    _al_u401 (
    .a(instr[1]),
    .b(instr[0]),
    .c(RTA1[1]),
    .d(RTA2[1]),
    .o(\mux55_b1/B1_1 ));
  AL_MAP_LUT3 #(
    .EQN("(~A*~(B)*~(C)+~A*B*~(C)+~(~A)*B*C+~A*B*C)"),
    .INIT(8'hc5))
    _al_u402 (
    .a(_al_u400_o),
    .b(\mux55_b1/B1_1 ),
    .c(instr[2]),
    .o(XREGr[1]));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+~(A)*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+A*B*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+A*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+A*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+~(A)*B*~(C)*~(D)*E+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+~(A)*B*C*~(D)*E+A*B*C*~(D)*E+~(A)*B*~(C)*D*E+A*B*~(C)*D*E+~(A)*~(B)*C*D*E)"),
    .INIT(32'h1cdc1fdf))
    _al_u403 (
    .a(XREGr[1]),
    .b(sel0_b1_sel_o_lutinv),
    .c(dbsrc_addr[0]),
    .d(A[0]),
    .e(D[1]),
    .o(_al_u403_o));
  AL_MAP_LUT4 #(
    .EQN("~(~A*~((D*C))*~(B)+~A*(D*C)*~(B)+~(~A)*(D*C)*B+~A*(D*C)*B)"),
    .INIT(16'h2eee))
    _al_u404 (
    .a(_al_u399_o),
    .b(sel0_b2_sel_o_lutinv),
    .c(_al_u388_o),
    .d(B[2]),
    .o(_al_u404_o));
  AL_MAP_LUT5 #(
    .EQN("~(B*~((A*~(C)*~(D)+A*C*~(D)+~(A)*C*D+A*C*D))*~(E)+B*(A*~(C)*~(D)+A*C*~(D)+~(A)*C*D+A*C*D)*~(E)+~(B)*(A*~(C)*~(D)+A*C*~(D)+~(A)*C*D+A*C*D)*E+B*(A*~(C)*~(D)+A*C*~(D)+~(A)*C*D+A*C*D)*E)"),
    .INIT(32'h0f553333))
    _al_u405 (
    .a(_al_u398_o),
    .b(_al_u404_o),
    .c(_al_u403_o),
    .d(sel0_b2_sel_o_lutinv),
    .e(_al_u374_o),
    .o(ddata_o[1]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(~B*~A))"),
    .INIT(8'he0))
    _al_u406 (
    .a(dread),
    .b(n2),
    .c(WAIT_DATA),
    .o(INSTR_HOLD));
  AL_MAP_LUT4 #(
    .EQN("(D*(B*~(A)*~(C)+B*A*~(C)+~(B)*A*C+B*A*C))"),
    .INIT(16'hac00))
    _al_u407 (
    .a(instr[7]),
    .b(instr[6]),
    .c(B[2]),
    .d(A[2]),
    .o(_al_u407_o));
  AL_MAP_LUT4 #(
    .EQN("(~D*~(A*~(B)*~(C)+A*B*~(C)+~(A)*B*C+A*B*C))"),
    .INIT(16'h0035))
    _al_u408 (
    .a(instr[5]),
    .b(instr[4]),
    .c(B[2]),
    .d(A[2]),
    .o(\ALU_L4/SYNTHESIZED_WIRE_10_lutinv ));
  AL_MAP_LUT4 #(
    .EQN("(D*(B*~(A)*~(C)+B*A*~(C)+~(B)*A*C+B*A*C))"),
    .INIT(16'hac00))
    _al_u409 (
    .a(instr[7]),
    .b(instr[6]),
    .c(B[1]),
    .d(A[1]),
    .o(_al_u409_o));
  AL_MAP_LUT4 #(
    .EQN("(~D*~(A*~(B)*~(C)+A*B*~(C)+~(A)*B*C+A*B*C))"),
    .INIT(16'h0035))
    _al_u410 (
    .a(instr[5]),
    .b(instr[4]),
    .c(B[1]),
    .d(A[1]),
    .o(\ALU_L4/SYNTHESIZED_WIRE_8_lutinv ));
  AL_MAP_LUT3 #(
    .EQN("(~C*~(~B*~A))"),
    .INIT(8'h0e))
    _al_u411 (
    .a(_al_u394_o),
    .b(_al_u409_o),
    .c(\ALU_L4/SYNTHESIZED_WIRE_8_lutinv ),
    .o(_al_u411_o));
  AL_MAP_LUT5 #(
    .EQN("(B*~((~E*~A)@(~D*~C)))"),
    .INIT(32'hccc08884))
    _al_u412 (
    .a(_al_u411_o),
    .b(_al_u396_o),
    .c(_al_u407_o),
    .d(\ALU_L4/SYNTHESIZED_WIRE_10_lutinv ),
    .e(instr[3]),
    .o(_al_u412_o));
  AL_MAP_LUT4 #(
    .EQN("(A*(C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B))"),
    .INIT(16'ha820))
    _al_u413 (
    .a(sel0_b1_sel_o_lutinv),
    .b(dbsrc_addr[0]),
    .c(ddata_i[2]),
    .d(instr[2]),
    .o(_al_u413_o));
  AL_MAP_LUT4 #(
    .EQN("(~C*~B*~(D*A))"),
    .INIT(16'h0103))
    _al_u414 (
    .a(_al_u389_o),
    .b(_al_u413_o),
    .c(sel0_b2_sel_o_lutinv),
    .d(C[2]),
    .o(_al_u414_o));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*C*~(D)*~(E)+A*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+A*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*B*C*~(D)*E+A*~(B)*~(C)*D*E+~(A)*B*~(C)*D*E+A*B*~(C)*D*E+~(A)*~(B)*C*D*E+A*~(B)*C*D*E+~(A)*B*C*D*E+A*B*C*D*E)"),
    .INIT(32'hfe987610))
    _al_u415 (
    .a(instr[1]),
    .b(instr[0]),
    .c(RET0[2]),
    .d(RET1[2]),
    .e(RTA0[2]),
    .o(\mux55_b2/B1_0 ));
  AL_MAP_LUT2 #(
    .EQN("(~B*A)"),
    .INIT(4'h2))
    _al_u416 (
    .a(\mux55_b2/B1_0 ),
    .b(instr[2]),
    .o(_al_u416_o));
  AL_MAP_LUT4 #(
    .EQN("(A*(C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B))"),
    .INIT(16'ha820))
    _al_u417 (
    .a(_al_u385_o),
    .b(instr[0]),
    .c(RTA1[2]),
    .d(RTA2[2]),
    .o(_al_u417_o));
  AL_MAP_LUT5 #(
    .EQN("(~C*~(~E*~((~B*~A))*~(D)+~E*(~B*~A)*~(D)+~(~E)*(~B*~A)*D+~E*(~B*~A)*D))"),
    .INIT(32'h0e0f0e00))
    _al_u418 (
    .a(_al_u416_o),
    .b(_al_u417_o),
    .c(sel0_b1_sel_o_lutinv),
    .d(dbsrc_addr[0]),
    .e(D[2]),
    .o(_al_u418_o));
  AL_MAP_LUT4 #(
    .EQN("(B*~A*~(D*~C))"),
    .INIT(16'h4044))
    _al_u419 (
    .a(_al_u418_o),
    .b(sel0_b2_sel_o_lutinv),
    .c(_al_u388_o),
    .d(A[1]),
    .o(_al_u419_o));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+A*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+A*B*~(C)*D*~(E)+A*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+~(A)*~(B)*~(C)*~(D)*E+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*B*~(C)*D*E)"),
    .INIT(32'h08196e7f))
    _al_u420 (
    .a(sel0_b1_sel_o_lutinv),
    .b(dbsrc_addr[0]),
    .c(B[1]),
    .d(A[1]),
    .e(A[3]),
    .o(_al_u420_o));
  AL_MAP_LUT4 #(
    .EQN("~(~A*~((D*C))*~(B)+~A*(D*C)*~(B)+~(~A)*(D*C)*B+~A*(D*C)*B)"),
    .INIT(16'h2eee))
    _al_u421 (
    .a(_al_u420_o),
    .b(sel0_b2_sel_o_lutinv),
    .c(_al_u388_o),
    .d(B[3]),
    .o(_al_u421_o));
  AL_MAP_LUT5 #(
    .EQN("(~D*~((~B*~(C*~A)))*~(E)+~D*(~B*~(C*~A))*~(E)+~(~D)*(~B*~(C*~A))*E+~D*(~B*~(C*~A))*E)"),
    .INIT(32'h232300ff))
    _al_u422 (
    .a(_al_u412_o),
    .b(_al_u419_o),
    .c(_al_u414_o),
    .d(_al_u421_o),
    .e(_al_u374_o),
    .o(ddata_o[2]));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u423 (
    .a(_al_u367_o),
    .b(instr[9]),
    .c(instr[8]),
    .o(mux44_b0_sel_is_3_o));
  AL_MAP_LUT5 #(
    .EQN("((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*~(D)*~(C)+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*~(C)+~((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B))*D*C+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*C)"),
    .INIT(32'hfb0bf808))
    _al_u424 (
    .a(ddata_o[0]),
    .b(mux44_b0_sel_is_3_o),
    .c(u45_sel_is_3_o),
    .d(RTA0[0]),
    .e(daddr[0]),
    .o(n65[0]));
  AL_MAP_LUT3 #(
    .EQN("(~C*~B*A)"),
    .INIT(8'h02))
    _al_u425 (
    .a(_al_u372_o),
    .b(instr[9]),
    .c(instr[8]),
    .o(mux43_b0_sel_is_3_o));
  AL_MAP_LUT5 #(
    .EQN("((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*~(D)*~(C)+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*~(C)+~((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B))*D*C+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*C)"),
    .INIT(32'hfb0bf808))
    _al_u426 (
    .a(ddata_o[0]),
    .b(mux43_b0_sel_is_3_o),
    .c(u45_sel_is_3_o),
    .d(RTA1[0]),
    .e(daddr[8]),
    .o(n66[0]));
  AL_MAP_LUT2 #(
    .EQN("(B*A)"),
    .INIT(4'h8))
    _al_u427 (
    .a(_al_u372_o),
    .b(_al_u369_o),
    .o(mux42_b0_sel_is_3_o));
  AL_MAP_LUT5 #(
    .EQN("((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*~(D)*~(C)+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*~(C)+~((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B))*D*C+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*C)"),
    .INIT(32'hfb0bf808))
    _al_u428 (
    .a(ddata_o[0]),
    .b(mux42_b0_sel_is_3_o),
    .c(u45_sel_is_3_o),
    .d(RTA2[0]),
    .e(daddr[16]),
    .o(n67[0]));
  AL_MAP_LUT4 #(
    .EQN("(~D*C*B*A)"),
    .INIT(16'h0080))
    _al_u429 (
    .a(_al_u356_o),
    .b(n12_lutinv),
    .c(instr[14]),
    .d(instr[13]),
    .o(n18));
  AL_MAP_LUT4 #(
    .EQN("(D*C*~B*A)"),
    .INIT(16'h2000))
    _al_u430 (
    .a(n18),
    .b(instr[2]),
    .c(instr[1]),
    .d(instr[0]),
    .o(mux15_b0_sel_is_3_o));
  AL_MAP_LUT5 #(
    .EQN("(~E*~D*C*B*A)"),
    .INIT(32'h00000080))
    _al_u431 (
    .a(_al_u356_o),
    .b(n12_lutinv),
    .c(instr[14]),
    .d(instr[13]),
    .e(instr[2]),
    .o(_al_u431_o));
  AL_MAP_LUT5 #(
    .EQN("((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*~(E)*~(C)+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*~(C)+~((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B))*E*C+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*C)"),
    .INIT(32'hfbf80b08))
    _al_u432 (
    .a(ddata_o[0]),
    .b(mux15_b0_sel_is_3_o),
    .c(_al_u361_o),
    .d(RTA0[0]),
    .e(daddr[0]),
    .o(n42[0]));
  AL_MAP_LUT3 #(
    .EQN("(~C*B*A)"),
    .INIT(8'h08))
    _al_u433 (
    .a(n18),
    .b(_al_u385_o),
    .c(instr[0]),
    .o(mux14_b0_sel_is_3_o));
  AL_MAP_LUT5 #(
    .EQN("((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*~(E)*~(C)+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*~(C)+~((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B))*E*C+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*C)"),
    .INIT(32'hfbf80b08))
    _al_u434 (
    .a(ddata_o[0]),
    .b(mux14_b0_sel_is_3_o),
    .c(_al_u361_o),
    .d(RTA1[0]),
    .e(daddr[8]),
    .o(n43[0]));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u435 (
    .a(n18),
    .b(_al_u385_o),
    .c(instr[0]),
    .o(mux13_b0_sel_is_3_o));
  AL_MAP_LUT5 #(
    .EQN("((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*~(E)*~(C)+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*~(C)+~((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B))*E*C+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*C)"),
    .INIT(32'hfbf80b08))
    _al_u436 (
    .a(ddata_o[0]),
    .b(mux13_b0_sel_is_3_o),
    .c(_al_u361_o),
    .d(RTA2[0]),
    .e(daddr[16]),
    .o(n44[0]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*~(D)*~(C)+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*~(C)+~((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B))*D*C+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*C)"),
    .INIT(32'hfb0bf808))
    _al_u437 (
    .a(ddata_o[1]),
    .b(mux44_b0_sel_is_3_o),
    .c(u45_sel_is_3_o),
    .d(RTA0[1]),
    .e(daddr[1]),
    .o(n65[1]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*~(D)*~(C)+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*~(C)+~((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B))*D*C+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*C)"),
    .INIT(32'hfb0bf808))
    _al_u438 (
    .a(ddata_o[1]),
    .b(mux43_b0_sel_is_3_o),
    .c(u45_sel_is_3_o),
    .d(RTA1[1]),
    .e(daddr[9]),
    .o(n66[1]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*~(D)*~(C)+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*~(C)+~((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B))*D*C+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*C)"),
    .INIT(32'hfb0bf808))
    _al_u439 (
    .a(ddata_o[1]),
    .b(mux42_b0_sel_is_3_o),
    .c(u45_sel_is_3_o),
    .d(RTA2[1]),
    .e(daddr[17]),
    .o(n67[1]));
  AL_MAP_LUT5 #(
    .EQN("((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*~(E)*~(C)+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*~(C)+~((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B))*E*C+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*C)"),
    .INIT(32'hfbf80b08))
    _al_u440 (
    .a(ddata_o[1]),
    .b(mux15_b0_sel_is_3_o),
    .c(_al_u361_o),
    .d(RTA0[1]),
    .e(daddr[1]),
    .o(n42[1]));
  AL_MAP_LUT5 #(
    .EQN("((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*~(E)*~(C)+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*~(C)+~((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B))*E*C+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*C)"),
    .INIT(32'hfbf80b08))
    _al_u441 (
    .a(ddata_o[1]),
    .b(mux14_b0_sel_is_3_o),
    .c(_al_u361_o),
    .d(RTA1[1]),
    .e(daddr[9]),
    .o(n43[1]));
  AL_MAP_LUT5 #(
    .EQN("((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*~(E)*~(C)+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*~(C)+~((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B))*E*C+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*C)"),
    .INIT(32'hfbf80b08))
    _al_u442 (
    .a(ddata_o[1]),
    .b(mux13_b0_sel_is_3_o),
    .c(_al_u361_o),
    .d(RTA2[1]),
    .e(daddr[17]),
    .o(n44[1]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*~(D)*~(C)+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*~(C)+~((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B))*D*C+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*C)"),
    .INIT(32'hfb0bf808))
    _al_u443 (
    .a(ddata_o[2]),
    .b(mux44_b0_sel_is_3_o),
    .c(u45_sel_is_3_o),
    .d(RTA0[2]),
    .e(daddr[2]),
    .o(n65[2]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*~(D)*~(C)+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*~(C)+~((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B))*D*C+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*C)"),
    .INIT(32'hfb0bf808))
    _al_u444 (
    .a(ddata_o[2]),
    .b(mux43_b0_sel_is_3_o),
    .c(u45_sel_is_3_o),
    .d(RTA1[2]),
    .e(daddr[10]),
    .o(n66[2]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*~(D)*~(C)+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*~(C)+~((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B))*D*C+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*C)"),
    .INIT(32'hfb0bf808))
    _al_u445 (
    .a(ddata_o[2]),
    .b(mux42_b0_sel_is_3_o),
    .c(u45_sel_is_3_o),
    .d(RTA2[2]),
    .e(daddr[18]),
    .o(n67[2]));
  AL_MAP_LUT5 #(
    .EQN("((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*~(E)*~(C)+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*~(C)+~((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B))*E*C+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*C)"),
    .INIT(32'hfbf80b08))
    _al_u446 (
    .a(ddata_o[2]),
    .b(mux15_b0_sel_is_3_o),
    .c(_al_u361_o),
    .d(RTA0[2]),
    .e(daddr[2]),
    .o(n42[2]));
  AL_MAP_LUT5 #(
    .EQN("((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*~(E)*~(C)+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*~(C)+~((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B))*E*C+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*C)"),
    .INIT(32'hfbf80b08))
    _al_u447 (
    .a(ddata_o[2]),
    .b(mux14_b0_sel_is_3_o),
    .c(_al_u361_o),
    .d(RTA1[2]),
    .e(daddr[10]),
    .o(n43[2]));
  AL_MAP_LUT5 #(
    .EQN("((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*~(E)*~(C)+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*~(C)+~((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B))*E*C+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*C)"),
    .INIT(32'hfbf80b08))
    _al_u448 (
    .a(ddata_o[2]),
    .b(mux13_b0_sel_is_3_o),
    .c(_al_u361_o),
    .d(RTA2[2]),
    .e(daddr[18]),
    .o(n44[2]));
  AL_MAP_LUT2 #(
    .EQN("(B*~A)"),
    .INIT(4'h4))
    _al_u449 (
    .a(INSTR_HOLD),
    .b(n12_lutinv),
    .o(mux3_b0_sel_is_0_o));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*C*~(D)*~(E)+A*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+A*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*B*C*~(D)*E+A*~(B)*~(C)*D*E+~(A)*B*~(C)*D*E+A*B*~(C)*D*E+~(A)*~(B)*C*D*E+A*~(B)*C*D*E+~(A)*B*C*D*E+A*B*C*D*E)"),
    .INIT(32'hfe987610))
    _al_u450 (
    .a(instr[1]),
    .b(instr[0]),
    .c(RET0[3]),
    .d(RET1[3]),
    .e(RTA0[3]),
    .o(\mux55_b3/B1_0 ));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u451 (
    .a(instr[0]),
    .b(RTA1[3]),
    .c(RTA2[3]),
    .o(\mux55_b3/B0_2 ));
  AL_MAP_LUT4 #(
    .EQN("~(A*~((~D*B))*~(C)+A*(~D*B)*~(C)+~(A)*(~D*B)*C+A*(~D*B)*C)"),
    .INIT(16'hf535))
    _al_u452 (
    .a(\mux55_b3/B1_0 ),
    .b(\mux55_b3/B0_2 ),
    .c(instr[2]),
    .d(instr[1]),
    .o(_al_u452_o));
  AL_MAP_LUT4 #(
    .EQN("(~B*~(~D*~(A)*~(C)+~D*A*~(C)+~(~D)*A*C+~D*A*C))"),
    .INIT(16'h1310))
    _al_u453 (
    .a(_al_u452_o),
    .b(sel0_b1_sel_o_lutinv),
    .c(dbsrc_addr[0]),
    .d(D[3]),
    .o(_al_u453_o));
  AL_MAP_LUT4 #(
    .EQN("(D*(B*~(A)*~(C)+B*A*~(C)+~(B)*A*C+B*A*C))"),
    .INIT(16'hac00))
    _al_u454 (
    .a(instr[7]),
    .b(instr[6]),
    .c(B[3]),
    .d(A[3]),
    .o(_al_u454_o));
  AL_MAP_LUT4 #(
    .EQN("(~D*~(A*~(B)*~(C)+A*B*~(C)+~(A)*B*C+A*B*C))"),
    .INIT(16'h0035))
    _al_u455 (
    .a(instr[5]),
    .b(instr[4]),
    .c(B[3]),
    .d(A[3]),
    .o(\ALU_L4/SYNTHESIZED_WIRE_25_lutinv ));
  AL_MAP_LUT2 #(
    .EQN("(~B*~A)"),
    .INIT(4'h1))
    _al_u456 (
    .a(_al_u454_o),
    .b(\ALU_L4/SYNTHESIZED_WIRE_25_lutinv ),
    .o(\ALU_L4/SYNTHESIZED_WIRE_94_lutinv ));
  AL_MAP_LUT4 #(
    .EQN("(~B*~(~D*~(~C*~A)))"),
    .INIT(16'h3301))
    _al_u457 (
    .a(_al_u394_o),
    .b(_al_u407_o),
    .c(_al_u409_o),
    .d(\ALU_L4/SYNTHESIZED_WIRE_8_lutinv ),
    .o(_al_u457_o));
  AL_MAP_LUT5 #(
    .EQN("(~C*~(~B*~(~E*~(~D*~A))))"),
    .INIT(32'h0c0c0f0e))
    _al_u458 (
    .a(_al_u394_o),
    .b(_al_u407_o),
    .c(\ALU_L4/SYNTHESIZED_WIRE_10_lutinv ),
    .d(_al_u409_o),
    .e(\ALU_L4/SYNTHESIZED_WIRE_8_lutinv ),
    .o(_al_u458_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*B*~(C)*~(D)+A*~(B)*C*~(D)+~(A)*B*C*~(D)+~(A)*~(B)*~(C)*D+~(A)*B*~(C)*D+~(A)*~(B)*C*D+A*~(B)*C*D+~(A)*B*C*D)"),
    .INIT(16'h7564))
    _al_u459 (
    .a(sel0_b1_sel_o_lutinv),
    .b(dbsrc_addr[0]),
    .c(ddata_i[3]),
    .d(C[3]),
    .o(_al_u459_o));
  AL_MAP_LUT5 #(
    .EQN("(B*~(D*(C@(~E*~A))))"),
    .INIT(32'h0ccc48cc))
    _al_u460 (
    .a(_al_u458_o),
    .b(_al_u459_o),
    .c(\ALU_L4/SYNTHESIZED_WIRE_94_lutinv ),
    .d(dbsrc_addr[0]),
    .e(instr[3]),
    .o(_al_u460_o));
  AL_MAP_LUT5 #(
    .EQN("(B*~(~C*(D*~(E)*~(A)+D*E*~(A)+~(D)*E*A+D*E*A)))"),
    .INIT(32'hc0c4c8cc))
    _al_u461 (
    .a(sel0_b2_sel_o_lutinv),
    .b(_al_u374_o),
    .c(_al_u388_o),
    .d(instr[3]),
    .e(A[2]),
    .o(_al_u461_o));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+A*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+A*B*~(C)*D*~(E)+A*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+~(A)*~(B)*~(C)*~(D)*E+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*B*~(C)*D*E)"),
    .INIT(32'h08196e7f))
    _al_u462 (
    .a(sel0_b1_sel_o_lutinv),
    .b(dbsrc_addr[0]),
    .c(B[2]),
    .d(A[2]),
    .e(A[4]),
    .o(_al_u462_o));
  AL_MAP_LUT5 #(
    .EQN("(~C*~(~A*~((E*D))*~(B)+~A*(E*D)*~(B)+~(~A)*(E*D)*B+~A*(E*D)*B))"),
    .INIT(32'h020e0e0e))
    _al_u463 (
    .a(_al_u462_o),
    .b(sel0_b2_sel_o_lutinv),
    .c(_al_u374_o),
    .d(_al_u388_o),
    .e(B[4]),
    .o(_al_u463_o));
  AL_MAP_LUT5 #(
    .EQN("(~B*~(D*~(A*~(C)*~(E)+A*C*~(E)+~(A)*C*E+A*C*E)))"),
    .INIT(32'h30332233))
    _al_u464 (
    .a(_al_u460_o),
    .b(_al_u463_o),
    .c(_al_u453_o),
    .d(_al_u461_o),
    .e(sel0_b2_sel_o_lutinv),
    .o(ddata_o[3]));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*C*~(D)*~(E)+A*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+A*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*B*C*~(D)*E+A*~(B)*~(C)*D*E+~(A)*B*~(C)*D*E+A*B*~(C)*D*E+~(A)*~(B)*C*D*E+A*~(B)*C*D*E+~(A)*B*C*D*E+A*B*C*D*E)"),
    .INIT(32'hfe987610))
    _al_u465 (
    .a(instr[1]),
    .b(instr[0]),
    .c(RET0[4]),
    .d(RET1[4]),
    .e(RTA0[4]),
    .o(\mux55_b4/B1_0 ));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u466 (
    .a(instr[0]),
    .b(RTA1[4]),
    .c(RTA2[4]),
    .o(\mux55_b4/B0_2 ));
  AL_MAP_LUT4 #(
    .EQN("~(A*~((~D*B))*~(C)+A*(~D*B)*~(C)+~(A)*(~D*B)*C+A*(~D*B)*C)"),
    .INIT(16'hf535))
    _al_u467 (
    .a(\mux55_b4/B1_0 ),
    .b(\mux55_b4/B0_2 ),
    .c(instr[2]),
    .d(instr[1]),
    .o(_al_u467_o));
  AL_MAP_LUT4 #(
    .EQN("(~B*~(~D*~(A)*~(C)+~D*A*~(C)+~(~D)*A*C+~D*A*C))"),
    .INIT(16'h1310))
    _al_u468 (
    .a(_al_u467_o),
    .b(sel0_b1_sel_o_lutinv),
    .c(dbsrc_addr[0]),
    .d(D[4]),
    .o(_al_u468_o));
  AL_MAP_LUT4 #(
    .EQN("(D*(B*~(A)*~(C)+B*A*~(C)+~(B)*A*C+B*A*C))"),
    .INIT(16'hac00))
    _al_u469 (
    .a(instr[7]),
    .b(instr[6]),
    .c(B[4]),
    .d(A[4]),
    .o(_al_u469_o));
  AL_MAP_LUT4 #(
    .EQN("(~D*~(A*~(B)*~(C)+A*B*~(C)+~(A)*B*C+A*B*C))"),
    .INIT(16'h0035))
    _al_u470 (
    .a(instr[5]),
    .b(instr[4]),
    .c(B[4]),
    .d(A[4]),
    .o(\ALU_H4/SYNTHESIZED_WIRE_6_lutinv ));
  AL_MAP_LUT2 #(
    .EQN("(~B*~A)"),
    .INIT(4'h1))
    _al_u471 (
    .a(_al_u469_o),
    .b(\ALU_H4/SYNTHESIZED_WIRE_6_lutinv ),
    .o(\ALU_H4/SYNTHESIZED_WIRE_101_lutinv ));
  AL_MAP_LUT3 #(
    .EQN("(~C*~(~B*A))"),
    .INIT(8'h0d))
    _al_u472 (
    .a(\ALU_L4/SYNTHESIZED_WIRE_10_lutinv ),
    .b(_al_u454_o),
    .c(\ALU_L4/SYNTHESIZED_WIRE_25_lutinv ),
    .o(_al_u472_o));
  AL_MAP_LUT2 #(
    .EQN("(~B*~A)"),
    .INIT(4'h1))
    _al_u473 (
    .a(_al_u407_o),
    .b(_al_u454_o),
    .o(\ALU_L4/n19 ));
  AL_MAP_LUT4 #(
    .EQN("(B*~(~D*~(~C*~A)))"),
    .INIT(16'hcc04))
    _al_u474 (
    .a(_al_u394_o),
    .b(\ALU_L4/n19 ),
    .c(_al_u409_o),
    .d(\ALU_L4/SYNTHESIZED_WIRE_8_lutinv ),
    .o(_al_u474_o));
  AL_MAP_LUT5 #(
    .EQN("(A*~(C*~(~E*~(~D*~B))))"),
    .INIT(32'h0a0aaa8a))
    _al_u475 (
    .a(_al_u472_o),
    .b(_al_u394_o),
    .c(\ALU_L4/n19 ),
    .d(_al_u409_o),
    .e(\ALU_L4/SYNTHESIZED_WIRE_8_lutinv ),
    .o(_al_u475_o));
  AL_MAP_LUT5 #(
    .EQN("(C@(~E*~(B*~(~D*A))))"),
    .INIT(32'hf0f0c34b))
    _al_u476 (
    .a(_al_u457_o),
    .b(_al_u472_o),
    .c(\ALU_H4/SYNTHESIZED_WIRE_101_lutinv ),
    .d(_al_u454_o),
    .e(instr[3]),
    .o(_al_u476_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*B*~(C)*~(D)+A*~(B)*C*~(D)+~(A)*B*C*~(D)+~(A)*~(B)*~(C)*D+~(A)*B*~(C)*D+~(A)*~(B)*C*D+A*~(B)*C*D+~(A)*B*C*D)"),
    .INIT(16'h7564))
    _al_u477 (
    .a(sel0_b1_sel_o_lutinv),
    .b(dbsrc_addr[0]),
    .c(ddata_i[4]),
    .d(C[4]),
    .o(_al_u477_o));
  AL_MAP_LUT5 #(
    .EQN("((C*~(E*A))*~(B)*~(D)+(C*~(E*A))*B*~(D)+~((C*~(E*A)))*B*D+(C*~(E*A))*B*D)"),
    .INIT(32'hcc50ccf0))
    _al_u478 (
    .a(_al_u476_o),
    .b(_al_u468_o),
    .c(_al_u477_o),
    .d(sel0_b2_sel_o_lutinv),
    .e(dbsrc_addr[0]),
    .o(_al_u478_o));
  AL_MAP_LUT4 #(
    .EQN("(~B*(C*~(D)*~(A)+C*D*~(A)+~(C)*D*A+C*D*A))"),
    .INIT(16'h3210))
    _al_u479 (
    .a(sel0_b2_sel_o_lutinv),
    .b(_al_u388_o),
    .c(instr[4]),
    .d(A[3]),
    .o(_al_u479_o));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+A*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+A*B*~(C)*D*~(E)+A*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+~(A)*~(B)*~(C)*~(D)*E+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*B*~(C)*D*E)"),
    .INIT(32'h08196e7f))
    _al_u480 (
    .a(sel0_b1_sel_o_lutinv),
    .b(dbsrc_addr[0]),
    .c(B[3]),
    .d(A[3]),
    .e(A[5]),
    .o(_al_u480_o));
  AL_MAP_LUT4 #(
    .EQN("~(~A*~((D*C))*~(B)+~A*(D*C)*~(B)+~(~A)*(D*C)*B+~A*(D*C)*B)"),
    .INIT(16'h2eee))
    _al_u481 (
    .a(_al_u480_o),
    .b(sel0_b2_sel_o_lutinv),
    .c(_al_u388_o),
    .d(B[5]),
    .o(_al_u481_o));
  AL_MAP_LUT4 #(
    .EQN("~(B*~((~C*~A))*~(D)+B*(~C*~A)*~(D)+~(B)*(~C*~A)*D+B*(~C*~A)*D)"),
    .INIT(16'hfa33))
    _al_u482 (
    .a(_al_u478_o),
    .b(_al_u481_o),
    .c(_al_u479_o),
    .d(_al_u374_o),
    .o(ddata_o[4]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*~(D)*~(C)+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*~(C)+~((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B))*D*C+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*C)"),
    .INIT(32'hfb0bf808))
    _al_u483 (
    .a(ddata_o[3]),
    .b(mux44_b0_sel_is_3_o),
    .c(u45_sel_is_3_o),
    .d(RTA0[3]),
    .e(daddr[3]),
    .o(n65[3]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*~(D)*~(C)+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*~(C)+~((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B))*D*C+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*C)"),
    .INIT(32'hfb0bf808))
    _al_u484 (
    .a(ddata_o[3]),
    .b(mux43_b0_sel_is_3_o),
    .c(u45_sel_is_3_o),
    .d(RTA1[3]),
    .e(daddr[11]),
    .o(n66[3]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*~(D)*~(C)+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*~(C)+~((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B))*D*C+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*C)"),
    .INIT(32'hfb0bf808))
    _al_u485 (
    .a(ddata_o[3]),
    .b(mux42_b0_sel_is_3_o),
    .c(u45_sel_is_3_o),
    .d(RTA2[3]),
    .e(daddr[19]),
    .o(n67[3]));
  AL_MAP_LUT5 #(
    .EQN("((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*~(E)*~(C)+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*~(C)+~((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B))*E*C+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*C)"),
    .INIT(32'hfbf80b08))
    _al_u486 (
    .a(ddata_o[3]),
    .b(mux15_b0_sel_is_3_o),
    .c(_al_u361_o),
    .d(RTA0[3]),
    .e(daddr[3]),
    .o(n42[3]));
  AL_MAP_LUT5 #(
    .EQN("((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*~(E)*~(C)+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*~(C)+~((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B))*E*C+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*C)"),
    .INIT(32'hfbf80b08))
    _al_u487 (
    .a(ddata_o[3]),
    .b(mux14_b0_sel_is_3_o),
    .c(_al_u361_o),
    .d(RTA1[3]),
    .e(daddr[11]),
    .o(n43[3]));
  AL_MAP_LUT5 #(
    .EQN("((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*~(E)*~(C)+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*~(C)+~((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B))*E*C+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*C)"),
    .INIT(32'hfbf80b08))
    _al_u488 (
    .a(ddata_o[3]),
    .b(mux13_b0_sel_is_3_o),
    .c(_al_u361_o),
    .d(RTA2[3]),
    .e(daddr[19]),
    .o(n44[3]));
  AL_MAP_LUT4 #(
    .EQN("(~D*~(A*~(B)*~(C)+A*B*~(C)+~(A)*B*C+A*B*C))"),
    .INIT(16'h0035))
    _al_u489 (
    .a(instr[5]),
    .b(instr[4]),
    .c(B[5]),
    .d(A[5]),
    .o(\ALU_H4/SYNTHESIZED_WIRE_8_lutinv ));
  AL_MAP_LUT4 #(
    .EQN("(D*(B*~(A)*~(C)+B*A*~(C)+~(B)*A*C+B*A*C))"),
    .INIT(16'hac00))
    _al_u490 (
    .a(instr[7]),
    .b(instr[6]),
    .c(B[5]),
    .d(A[5]),
    .o(_al_u490_o));
  AL_MAP_LUT2 #(
    .EQN("(~B*~A)"),
    .INIT(4'h1))
    _al_u491 (
    .a(\ALU_H4/SYNTHESIZED_WIRE_8_lutinv ),
    .b(_al_u490_o),
    .o(\ALU_H4/SYNTHESIZED_WIRE_103_lutinv ));
  AL_MAP_LUT2 #(
    .EQN("(~B*A)"),
    .INIT(4'h2))
    _al_u492 (
    .a(\ALU_H4/SYNTHESIZED_WIRE_6_lutinv ),
    .b(instr[3]),
    .o(\ALU_H4/SYNTHESIZED_WIRE_99 ));
  AL_MAP_LUT2 #(
    .EQN("(~B*~A)"),
    .INIT(4'h1))
    _al_u493 (
    .a(_al_u469_o),
    .b(instr[3]),
    .o(\ALU_H4/n31 ));
  AL_MAP_LUT5 #(
    .EQN("(~C*~(D*~(B*~(~E*A))))"),
    .INIT(32'h0c0f040f))
    _al_u494 (
    .a(_al_u457_o),
    .b(_al_u472_o),
    .c(\ALU_H4/SYNTHESIZED_WIRE_99 ),
    .d(\ALU_H4/n31 ),
    .e(_al_u454_o),
    .o(\ALU_H4/SYNTHESIZED_WIRE_115_lutinv ));
  AL_MAP_LUT5 #(
    .EQN("(B@(~E*~(~D*~(~C*~A))))"),
    .INIT(32'hcccc33c9))
    _al_u495 (
    .a(_al_u475_o),
    .b(\ALU_H4/SYNTHESIZED_WIRE_103_lutinv ),
    .c(_al_u469_o),
    .d(\ALU_H4/SYNTHESIZED_WIRE_6_lutinv ),
    .e(instr[3]),
    .o(_al_u495_o));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+A*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+A*B*~(C)*D*~(E)+A*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+~(A)*~(B)*~(C)*~(D)*E+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*B*~(C)*D*E)"),
    .INIT(32'h08196e7f))
    _al_u496 (
    .a(sel0_b1_sel_o_lutinv),
    .b(dbsrc_addr[0]),
    .c(B[4]),
    .d(A[4]),
    .e(A[6]),
    .o(_al_u496_o));
  AL_MAP_LUT5 #(
    .EQN("(~C*(~A*~((E*D))*~(B)+~A*(E*D)*~(B)+~(~A)*(E*D)*B+~A*(E*D)*B))"),
    .INIT(32'h0d010101))
    _al_u497 (
    .a(_al_u496_o),
    .b(sel0_b2_sel_o_lutinv),
    .c(_al_u374_o),
    .d(_al_u388_o),
    .e(B[6]),
    .o(_al_u497_o));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+A*B*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+A*B*~(C)*D*~(E)+A*B*C*D*~(E)+~(A)*~(B)*~(C)*~(D)*E+A*~(B)*~(C)*~(D)*E+~(A)*B*~(C)*~(D)*E+A*~(B)*C*~(D)*E+~(A)*B*C*~(D)*E+~(A)*~(B)*~(C)*D*E)"),
    .INIT(32'h016789ef))
    _al_u498 (
    .a(instr[1]),
    .b(instr[0]),
    .c(RET0[5]),
    .d(RET1[5]),
    .e(RTA0[5]),
    .o(_al_u498_o));
  AL_MAP_LUT4 #(
    .EQN("(~A*(C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B))"),
    .INIT(16'h5410))
    _al_u499 (
    .a(instr[1]),
    .b(instr[0]),
    .c(RTA1[5]),
    .d(RTA2[5]),
    .o(\mux55_b5/B1_1 ));
  AL_MAP_LUT3 #(
    .EQN("(~A*~(B)*~(C)+~A*B*~(C)+~(~A)*B*C+~A*B*C)"),
    .INIT(8'hc5))
    _al_u500 (
    .a(_al_u498_o),
    .b(\mux55_b5/B1_1 ),
    .c(instr[2]),
    .o(XREGr[5]));
  AL_MAP_LUT4 #(
    .EQN("(~B*(D*~(A)*~(C)+D*A*~(C)+~(D)*A*C+D*A*C))"),
    .INIT(16'h2320))
    _al_u501 (
    .a(XREGr[5]),
    .b(sel0_b1_sel_o_lutinv),
    .c(dbsrc_addr[0]),
    .d(D[5]),
    .o(_al_u501_o));
  AL_MAP_LUT5 #(
    .EQN("(~A*~(B*(D*~(E)*~(C)+D*E*~(C)+~(D)*E*C+D*E*C)))"),
    .INIT(32'h11155155))
    _al_u502 (
    .a(sel0_b2_sel_o_lutinv),
    .b(sel0_b1_sel_o_lutinv),
    .c(dbsrc_addr[0]),
    .d(ddata_i[5]),
    .e(instr[5]),
    .o(_al_u502_o));
  AL_MAP_LUT5 #(
    .EQN("(~C*(E*~((B@A))*~(D)+E*(B@A)*~(D)+~(E)*(B@A)*D+E*(B@A)*D))"),
    .INIT(32'h060f0600))
    _al_u503 (
    .a(\ALU_H4/SYNTHESIZED_WIRE_115_lutinv ),
    .b(\ALU_H4/SYNTHESIZED_WIRE_103_lutinv ),
    .c(sel0_b1_sel_o_lutinv),
    .d(dbsrc_addr[0]),
    .e(C[5]),
    .o(_al_u503_o));
  AL_MAP_LUT5 #(
    .EQN("(C*~(B*~A*~(E*~D)))"),
    .INIT(32'hb0f0b0b0))
    _al_u504 (
    .a(_al_u501_o),
    .b(sel0_b2_sel_o_lutinv),
    .c(_al_u374_o),
    .d(_al_u388_o),
    .e(A[4]),
    .o(_al_u504_o));
  AL_MAP_LUT4 #(
    .EQN("~(~C*~(B*~(D*~A)))"),
    .INIT(16'hf8fc))
    _al_u505 (
    .a(_al_u503_o),
    .b(_al_u504_o),
    .c(_al_u497_o),
    .d(_al_u502_o),
    .o(ddata_o[5]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*~(D)*~(C)+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*~(C)+~((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B))*D*C+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*C)"),
    .INIT(32'hfb0bf808))
    _al_u506 (
    .a(ddata_o[4]),
    .b(mux44_b0_sel_is_3_o),
    .c(u45_sel_is_3_o),
    .d(RTA0[4]),
    .e(daddr[4]),
    .o(n65[4]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*~(D)*~(C)+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*~(C)+~((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B))*D*C+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*C)"),
    .INIT(32'hfb0bf808))
    _al_u507 (
    .a(ddata_o[4]),
    .b(mux43_b0_sel_is_3_o),
    .c(u45_sel_is_3_o),
    .d(RTA1[4]),
    .e(daddr[12]),
    .o(n66[4]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*~(D)*~(C)+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*~(C)+~((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B))*D*C+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*C)"),
    .INIT(32'hfb0bf808))
    _al_u508 (
    .a(ddata_o[4]),
    .b(mux42_b0_sel_is_3_o),
    .c(u45_sel_is_3_o),
    .d(RTA2[4]),
    .e(daddr[20]),
    .o(n67[4]));
  AL_MAP_LUT5 #(
    .EQN("((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*~(E)*~(C)+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*~(C)+~((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B))*E*C+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*C)"),
    .INIT(32'hfbf80b08))
    _al_u509 (
    .a(ddata_o[4]),
    .b(mux15_b0_sel_is_3_o),
    .c(_al_u361_o),
    .d(RTA0[4]),
    .e(daddr[4]),
    .o(n42[4]));
  AL_MAP_LUT5 #(
    .EQN("((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*~(E)*~(C)+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*~(C)+~((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B))*E*C+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*C)"),
    .INIT(32'hfbf80b08))
    _al_u510 (
    .a(ddata_o[4]),
    .b(mux14_b0_sel_is_3_o),
    .c(_al_u361_o),
    .d(RTA1[4]),
    .e(daddr[12]),
    .o(n43[4]));
  AL_MAP_LUT5 #(
    .EQN("((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*~(E)*~(C)+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*~(C)+~((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B))*E*C+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*C)"),
    .INIT(32'hfbf80b08))
    _al_u511 (
    .a(ddata_o[4]),
    .b(mux13_b0_sel_is_3_o),
    .c(_al_u361_o),
    .d(RTA2[4]),
    .e(daddr[20]),
    .o(n44[4]));
  AL_MAP_LUT3 #(
    .EQN("(~C*~B*~A)"),
    .INIT(8'h01))
    _al_u512 (
    .a(_al_u469_o),
    .b(_al_u490_o),
    .c(instr[3]),
    .o(_al_u512_o));
  AL_MAP_LUT4 #(
    .EQN("(~D*~(~B*~(~C*A)))"),
    .INIT(16'h00ce))
    _al_u513 (
    .a(\ALU_H4/SYNTHESIZED_WIRE_6_lutinv ),
    .b(\ALU_H4/SYNTHESIZED_WIRE_8_lutinv ),
    .c(_al_u490_o),
    .d(instr[3]),
    .o(\ALU_H4/n40_lutinv ));
  AL_MAP_LUT4 #(
    .EQN("(D*(B*~(A)*~(C)+B*A*~(C)+~(B)*A*C+B*A*C))"),
    .INIT(16'hac00))
    _al_u514 (
    .a(instr[7]),
    .b(instr[6]),
    .c(B[6]),
    .d(A[6]),
    .o(_al_u514_o));
  AL_MAP_LUT4 #(
    .EQN("(~D*~(A*~(B)*~(C)+A*B*~(C)+~(A)*B*C+A*B*C))"),
    .INIT(16'h0035))
    _al_u515 (
    .a(instr[5]),
    .b(instr[4]),
    .c(B[6]),
    .d(A[6]),
    .o(\ALU_H4/SYNTHESIZED_WIRE_10_lutinv ));
  AL_MAP_LUT2 #(
    .EQN("(~B*~A)"),
    .INIT(4'h1))
    _al_u516 (
    .a(_al_u514_o),
    .b(\ALU_H4/SYNTHESIZED_WIRE_10_lutinv ),
    .o(\ALU_H4/SYNTHESIZED_WIRE_105_lutinv ));
  AL_MAP_LUT5 #(
    .EQN("~(E@(~C*~(D*~(B*~A))))"),
    .INIT(32'h040ffbf0))
    _al_u517 (
    .a(_al_u474_o),
    .b(_al_u472_o),
    .c(\ALU_H4/n40_lutinv ),
    .d(_al_u512_o),
    .e(\ALU_H4/SYNTHESIZED_WIRE_105_lutinv ),
    .o(_al_u517_o));
  AL_MAP_LUT4 #(
    .EQN("(A*(C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B))"),
    .INIT(16'ha820))
    _al_u518 (
    .a(sel0_b1_sel_o_lutinv),
    .b(dbsrc_addr[0]),
    .c(ddata_i[6]),
    .d(instr[6]),
    .o(_al_u518_o));
  AL_MAP_LUT4 #(
    .EQN("(~C*~B*~(D*A))"),
    .INIT(16'h0103))
    _al_u519 (
    .a(_al_u389_o),
    .b(_al_u518_o),
    .c(sel0_b2_sel_o_lutinv),
    .d(C[6]),
    .o(_al_u519_o));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+A*B*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+A*B*~(C)*D*~(E)+A*B*C*D*~(E)+~(A)*~(B)*~(C)*~(D)*E+A*~(B)*~(C)*~(D)*E+~(A)*B*~(C)*~(D)*E+A*~(B)*C*~(D)*E+~(A)*B*C*~(D)*E+~(A)*~(B)*~(C)*D*E)"),
    .INIT(32'h016789ef))
    _al_u520 (
    .a(instr[1]),
    .b(instr[0]),
    .c(RET0[6]),
    .d(RET1[6]),
    .e(RTA0[6]),
    .o(_al_u520_o));
  AL_MAP_LUT4 #(
    .EQN("(~A*(C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B))"),
    .INIT(16'h5410))
    _al_u521 (
    .a(instr[1]),
    .b(instr[0]),
    .c(RTA1[6]),
    .d(RTA2[6]),
    .o(\mux55_b6/B1_1 ));
  AL_MAP_LUT3 #(
    .EQN("(~A*~(B)*~(C)+~A*B*~(C)+~(~A)*B*C+~A*B*C)"),
    .INIT(8'hc5))
    _al_u522 (
    .a(_al_u520_o),
    .b(\mux55_b6/B1_1 ),
    .c(instr[2]),
    .o(XREGr[6]));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+~(A)*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+A*B*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+A*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+A*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+~(A)*B*~(C)*~(D)*E+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+~(A)*B*C*~(D)*E+A*B*C*~(D)*E+~(A)*B*~(C)*D*E+A*B*~(C)*D*E+~(A)*~(B)*C*D*E)"),
    .INIT(32'h1cdc1fdf))
    _al_u523 (
    .a(XREGr[6]),
    .b(sel0_b1_sel_o_lutinv),
    .c(dbsrc_addr[0]),
    .d(A[5]),
    .e(D[6]),
    .o(_al_u523_o));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+A*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+A*B*~(C)*D*~(E)+A*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+~(A)*~(B)*~(C)*~(D)*E+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*B*~(C)*D*E)"),
    .INIT(32'h08196e7f))
    _al_u524 (
    .a(sel0_b1_sel_o_lutinv),
    .b(dbsrc_addr[0]),
    .c(B[5]),
    .d(A[5]),
    .e(A[7]),
    .o(_al_u524_o));
  AL_MAP_LUT5 #(
    .EQN("(~C*(~A*~((E*D))*~(B)+~A*(E*D)*~(B)+~(~A)*(E*D)*B+~A*(E*D)*B))"),
    .INIT(32'h0d010101))
    _al_u525 (
    .a(_al_u524_o),
    .b(sel0_b2_sel_o_lutinv),
    .c(_al_u374_o),
    .d(_al_u388_o),
    .e(B[7]),
    .o(_al_u525_o));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B*A))"),
    .INIT(8'h70))
    _al_u526 (
    .a(_al_u523_o),
    .b(sel0_b2_sel_o_lutinv),
    .c(_al_u374_o),
    .o(_al_u526_o));
  AL_MAP_LUT5 #(
    .EQN("~(~D*~(B*~(C*~(E*~A))))"),
    .INIT(32'hff4cff0c))
    _al_u527 (
    .a(_al_u517_o),
    .b(_al_u526_o),
    .c(_al_u519_o),
    .d(_al_u525_o),
    .e(_al_u396_o),
    .o(ddata_o[6]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*~(D)*~(C)+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*~(C)+~((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B))*D*C+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*C)"),
    .INIT(32'hfb0bf808))
    _al_u528 (
    .a(ddata_o[5]),
    .b(mux44_b0_sel_is_3_o),
    .c(u45_sel_is_3_o),
    .d(RTA0[5]),
    .e(daddr[5]),
    .o(n65[5]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*~(D)*~(C)+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*~(C)+~((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B))*D*C+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*C)"),
    .INIT(32'hfb0bf808))
    _al_u529 (
    .a(ddata_o[5]),
    .b(mux43_b0_sel_is_3_o),
    .c(u45_sel_is_3_o),
    .d(RTA1[5]),
    .e(daddr[13]),
    .o(n66[5]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*~(D)*~(C)+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*~(C)+~((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B))*D*C+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*C)"),
    .INIT(32'hfb0bf808))
    _al_u530 (
    .a(ddata_o[5]),
    .b(mux42_b0_sel_is_3_o),
    .c(u45_sel_is_3_o),
    .d(RTA2[5]),
    .e(daddr[21]),
    .o(n67[5]));
  AL_MAP_LUT5 #(
    .EQN("((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*~(E)*~(C)+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*~(C)+~((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B))*E*C+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*C)"),
    .INIT(32'hfbf80b08))
    _al_u531 (
    .a(ddata_o[5]),
    .b(mux15_b0_sel_is_3_o),
    .c(_al_u361_o),
    .d(RTA0[5]),
    .e(daddr[5]),
    .o(n42[5]));
  AL_MAP_LUT5 #(
    .EQN("((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*~(E)*~(C)+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*~(C)+~((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B))*E*C+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*C)"),
    .INIT(32'hfbf80b08))
    _al_u532 (
    .a(ddata_o[5]),
    .b(mux14_b0_sel_is_3_o),
    .c(_al_u361_o),
    .d(RTA1[5]),
    .e(daddr[13]),
    .o(n43[5]));
  AL_MAP_LUT5 #(
    .EQN("((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*~(E)*~(C)+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*~(C)+~((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B))*E*C+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*C)"),
    .INIT(32'hfbf80b08))
    _al_u533 (
    .a(ddata_o[5]),
    .b(mux13_b0_sel_is_3_o),
    .c(_al_u361_o),
    .d(RTA2[5]),
    .e(daddr[21]),
    .o(n44[5]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*~(D)*~(C)+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*~(C)+~((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B))*D*C+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*C)"),
    .INIT(32'hfb0bf808))
    _al_u534 (
    .a(ddata_o[6]),
    .b(mux44_b0_sel_is_3_o),
    .c(u45_sel_is_3_o),
    .d(RTA0[6]),
    .e(daddr[6]),
    .o(n65[6]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*~(D)*~(C)+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*~(C)+~((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B))*D*C+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*C)"),
    .INIT(32'hfb0bf808))
    _al_u535 (
    .a(ddata_o[6]),
    .b(mux43_b0_sel_is_3_o),
    .c(u45_sel_is_3_o),
    .d(RTA1[6]),
    .e(daddr[14]),
    .o(n66[6]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*~(D)*~(C)+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*~(C)+~((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B))*D*C+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*C)"),
    .INIT(32'hfb0bf808))
    _al_u536 (
    .a(ddata_o[6]),
    .b(mux42_b0_sel_is_3_o),
    .c(u45_sel_is_3_o),
    .d(RTA2[6]),
    .e(daddr[22]),
    .o(n67[6]));
  AL_MAP_LUT5 #(
    .EQN("((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*~(E)*~(C)+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*~(C)+~((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B))*E*C+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*C)"),
    .INIT(32'hfbf80b08))
    _al_u537 (
    .a(ddata_o[6]),
    .b(mux15_b0_sel_is_3_o),
    .c(_al_u361_o),
    .d(RTA0[6]),
    .e(daddr[6]),
    .o(n42[6]));
  AL_MAP_LUT5 #(
    .EQN("((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*~(E)*~(C)+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*~(C)+~((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B))*E*C+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*C)"),
    .INIT(32'hfbf80b08))
    _al_u538 (
    .a(ddata_o[6]),
    .b(mux14_b0_sel_is_3_o),
    .c(_al_u361_o),
    .d(RTA1[6]),
    .e(daddr[14]),
    .o(n43[6]));
  AL_MAP_LUT5 #(
    .EQN("((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*~(E)*~(C)+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*~(C)+~((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B))*E*C+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*C)"),
    .INIT(32'hfbf80b08))
    _al_u539 (
    .a(ddata_o[6]),
    .b(mux13_b0_sel_is_3_o),
    .c(_al_u361_o),
    .d(RTA2[6]),
    .e(daddr[22]),
    .o(n44[6]));
  AL_MAP_LUT3 #(
    .EQN("(~C*~B*~A)"),
    .INIT(8'h01))
    _al_u540 (
    .a(_al_u469_o),
    .b(_al_u490_o),
    .c(_al_u514_o),
    .o(\ALU_H4/n23 ));
  AL_MAP_LUT5 #(
    .EQN("(~E*~(~D*~(~B*~(~C*A))))"),
    .INIT(32'h0000ff31))
    _al_u541 (
    .a(\ALU_H4/SYNTHESIZED_WIRE_6_lutinv ),
    .b(\ALU_H4/SYNTHESIZED_WIRE_8_lutinv ),
    .c(_al_u490_o),
    .d(_al_u514_o),
    .e(\ALU_H4/SYNTHESIZED_WIRE_10_lutinv ),
    .o(_al_u541_o));
  AL_MAP_LUT5 #(
    .EQN("(B*~(D*~(C*~(~E*A))))"),
    .INIT(32'hc0cc40cc))
    _al_u542 (
    .a(_al_u457_o),
    .b(_al_u541_o),
    .c(_al_u472_o),
    .d(\ALU_H4/n23 ),
    .e(_al_u454_o),
    .o(_al_u542_o));
  AL_MAP_LUT4 #(
    .EQN("(~D*~(A*~(B)*~(C)+A*B*~(C)+~(A)*B*C+A*B*C))"),
    .INIT(16'h0035))
    _al_u543 (
    .a(instr[5]),
    .b(instr[4]),
    .c(B[7]),
    .d(A[7]),
    .o(\ALU_H4/SYNTHESIZED_WIRE_25_lutinv ));
  AL_MAP_LUT4 #(
    .EQN("(D*(B*~(A)*~(C)+B*A*~(C)+~(B)*A*C+B*A*C))"),
    .INIT(16'hac00))
    _al_u544 (
    .a(instr[7]),
    .b(instr[6]),
    .c(B[7]),
    .d(A[7]),
    .o(_al_u544_o));
  AL_MAP_LUT2 #(
    .EQN("(~B*~A)"),
    .INIT(4'h1))
    _al_u545 (
    .a(\ALU_H4/SYNTHESIZED_WIRE_25_lutinv ),
    .b(_al_u544_o),
    .o(\ALU_H4/SYNTHESIZED_WIRE_94_lutinv ));
  AL_MAP_LUT4 #(
    .EQN("(A*(C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B))"),
    .INIT(16'ha820))
    _al_u546 (
    .a(sel0_b1_sel_o_lutinv),
    .b(dbsrc_addr[0]),
    .c(ddata_i[7]),
    .d(instr[7]),
    .o(_al_u546_o));
  AL_MAP_LUT4 #(
    .EQN("(~C*~B*~(D*A))"),
    .INIT(16'h0103))
    _al_u547 (
    .a(_al_u389_o),
    .b(_al_u546_o),
    .c(sel0_b2_sel_o_lutinv),
    .d(C[7]),
    .o(_al_u547_o));
  AL_MAP_LUT5 #(
    .EQN("(B*~(C*~(D@(~E*~A))))"),
    .INIT(32'hcc0c8c4c))
    _al_u548 (
    .a(_al_u542_o),
    .b(_al_u547_o),
    .c(_al_u396_o),
    .d(\ALU_H4/SYNTHESIZED_WIRE_94_lutinv ),
    .e(instr[3]),
    .o(_al_u548_o));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*C*~(D)*~(E)+A*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+A*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*B*C*~(D)*E+A*~(B)*~(C)*D*E+~(A)*B*~(C)*D*E+A*B*~(C)*D*E+~(A)*~(B)*C*D*E+A*~(B)*C*D*E+~(A)*B*C*D*E+A*B*C*D*E)"),
    .INIT(32'hfe987610))
    _al_u549 (
    .a(instr[1]),
    .b(instr[0]),
    .c(RET0[7]),
    .d(RET1[7]),
    .e(RTA0[7]),
    .o(\mux55_b7/B1_0 ));
  AL_MAP_LUT4 #(
    .EQN("(A*(C*~(D)*~(B)+C*D*~(B)+~(C)*D*B+C*D*B))"),
    .INIT(16'ha820))
    _al_u550 (
    .a(_al_u385_o),
    .b(instr[0]),
    .c(RTA1[7]),
    .d(RTA2[7]),
    .o(_al_u550_o));
  AL_MAP_LUT5 #(
    .EQN("(~E*~((~A*~(~D*C)))*~(B)+~E*(~A*~(~D*C))*~(B)+~(~E)*(~A*~(~D*C))*B+~E*(~A*~(~D*C))*B)"),
    .INIT(32'h44047737))
    _al_u551 (
    .a(_al_u550_o),
    .b(dbsrc_addr[0]),
    .c(\mux55_b7/B1_0 ),
    .d(instr[2]),
    .e(D[7]),
    .o(_al_u551_o));
  AL_MAP_LUT3 #(
    .EQN("(A*~(C*~B))"),
    .INIT(8'h8a))
    _al_u552 (
    .a(sel0_b2_sel_o_lutinv),
    .b(_al_u388_o),
    .c(A[6]),
    .o(_al_u552_o));
  AL_MAP_LUT4 #(
    .EQN("(C*~(B*~(~D*~A)))"),
    .INIT(16'h3070))
    _al_u553 (
    .a(_al_u551_o),
    .b(_al_u552_o),
    .c(_al_u374_o),
    .d(sel0_b1_sel_o_lutinv),
    .o(_al_u553_o));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+A*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+A*B*~(C)*D*~(E)+A*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+~(A)*~(B)*~(C)*~(D)*E+~(A)*B*~(C)*~(D)*E+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+~(A)*B*C*~(D)*E+~(A)*B*~(C)*D*E+A*B*~(C)*D*E+~(A)*B*C*D*E)"),
    .INIT(32'h4c5d6e7f))
    _al_u554 (
    .a(sel0_b1_sel_o_lutinv),
    .b(dbsrc_addr[0]),
    .c(B[6]),
    .d(A[6]),
    .e(A[7]),
    .o(_al_u554_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)+A*~(B)*~(C)*~(D)+~(A)*B*~(C)*~(D)+A*B*~(C)*~(D)+~(A)*~(B)*C*~(D)+A*~(B)*C*~(D)+A*B*C*~(D)+~(A)*~(B)*~(C)*D+~(A)*B*~(C)*D+A*B*~(C)*D+~(A)*~(B)*C*D+A*B*C*D)"),
    .INIT(16'h9dbf))
    _al_u555 (
    .a(sel0_b1_sel_o_lutinv),
    .b(dbsrc_addr[0]),
    .c(B[7]),
    .d(A[0]),
    .o(_al_u555_o));
  AL_MAP_LUT4 #(
    .EQN("(~D*~(A*~(B)*~(C)+A*B*~(C)+~(A)*B*C+A*B*C))"),
    .INIT(16'h0035))
    _al_u556 (
    .a(_al_u554_o),
    .b(_al_u555_o),
    .c(sel0_b2_sel_o_lutinv),
    .d(_al_u374_o),
    .o(_al_u556_o));
  AL_MAP_LUT3 #(
    .EQN("~(~C*~(B*~A))"),
    .INIT(8'hf4))
    _al_u557 (
    .a(_al_u548_o),
    .b(_al_u553_o),
    .c(_al_u556_o),
    .o(ddata_o[7]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*~(D)*~(C)+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*~(C)+~((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B))*D*C+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*C)"),
    .INIT(32'hfb0bf808))
    _al_u558 (
    .a(ddata_o[7]),
    .b(mux44_b0_sel_is_3_o),
    .c(u45_sel_is_3_o),
    .d(RTA0[7]),
    .e(daddr[7]),
    .o(n65[7]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*~(D)*~(C)+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*~(C)+~((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B))*D*C+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*C)"),
    .INIT(32'hfb0bf808))
    _al_u559 (
    .a(ddata_o[7]),
    .b(mux43_b0_sel_is_3_o),
    .c(u45_sel_is_3_o),
    .d(RTA1[7]),
    .e(daddr[15]),
    .o(n66[7]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*~(D)*~(C)+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*~(C)+~((E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B))*D*C+(E*~(A)*~(B)+E*A*~(B)+~(E)*A*B+E*A*B)*D*C)"),
    .INIT(32'hfb0bf808))
    _al_u560 (
    .a(ddata_o[7]),
    .b(mux42_b0_sel_is_3_o),
    .c(u45_sel_is_3_o),
    .d(RTA2[7]),
    .e(daddr[23]),
    .o(n67[7]));
  AL_MAP_LUT5 #(
    .EQN("((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*~(E)*~(C)+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*~(C)+~((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B))*E*C+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*C)"),
    .INIT(32'hfbf80b08))
    _al_u561 (
    .a(ddata_o[7]),
    .b(mux15_b0_sel_is_3_o),
    .c(_al_u361_o),
    .d(RTA0[7]),
    .e(daddr[7]),
    .o(n42[7]));
  AL_MAP_LUT5 #(
    .EQN("((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*~(E)*~(C)+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*~(C)+~((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B))*E*C+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*C)"),
    .INIT(32'hfbf80b08))
    _al_u562 (
    .a(ddata_o[7]),
    .b(mux14_b0_sel_is_3_o),
    .c(_al_u361_o),
    .d(RTA1[7]),
    .e(daddr[15]),
    .o(n43[7]));
  AL_MAP_LUT5 #(
    .EQN("((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*~(E)*~(C)+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*~(C)+~((D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B))*E*C+(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B)*E*C)"),
    .INIT(32'hfbf80b08))
    _al_u563 (
    .a(ddata_o[7]),
    .b(mux13_b0_sel_is_3_o),
    .c(_al_u361_o),
    .d(RTA2[7]),
    .e(daddr[23]),
    .o(n44[7]));
  AL_MAP_LUT4 #(
    .EQN("(~D*~(~B*~(~C*~A)))"),
    .INIT(16'h00cd))
    _al_u564 (
    .a(_al_u542_o),
    .b(\ALU_H4/SYNTHESIZED_WIRE_25_lutinv ),
    .c(_al_u544_o),
    .d(instr[8]),
    .o(_al_u564_o));
  AL_MAP_LUT2 #(
    .EQN("(~B*A)"),
    .INIT(4'h2))
    _al_u565 (
    .a(instr[10]),
    .b(instr[8]),
    .o(_al_u565_o));
  AL_MAP_LUT4 #(
    .EQN("~((D*B)*~(A)*~(C)+(D*B)*A*~(C)+~((D*B))*A*C+(D*B)*A*C)"),
    .INIT(16'h535f))
    _al_u566 (
    .a(_al_u564_o),
    .b(_al_u369_o),
    .c(instr[10]),
    .d(A[7]),
    .o(_al_u566_o));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u567 (
    .a(ALU_out[1]),
    .b(ALU_out[0]),
    .c(instr[8]),
    .o(_al_u567_o));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+A*~(B)*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+~(A)*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+A*B*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+A*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+~(A)*~(B)*~(C)*~(D)*E+A*~(B)*~(C)*~(D)*E+~(A)*B*~(C)*~(D)*E+A*B*~(C)*~(D)*E+~(A)*B*C*~(D)*E+A*B*C*~(D)*E+~(A)*B*~(C)*D*E+A*B*~(C)*D*E+~(A)*B*C*D*E+A*B*C*D*E)"),
    .INIT(32'hcccf57db))
    _al_u568 (
    .a(_al_u411_o),
    .b(\ALU_L4/SYNTHESIZED_WIRE_94_lutinv ),
    .c(_al_u407_o),
    .d(\ALU_L4/SYNTHESIZED_WIRE_10_lutinv ),
    .e(instr[3]),
    .o(_al_u568_o));
  AL_MAP_LUT4 #(
    .EQN("(D*~C*~B*~A)"),
    .INIT(16'h0100))
    _al_u569 (
    .a(_al_u495_o),
    .b(_al_u476_o),
    .c(_al_u568_o),
    .d(_al_u567_o),
    .o(_al_u569_o));
  AL_MAP_LUT4 #(
    .EQN("(~A*~(C@(~D*~B)))"),
    .INIT(16'h0514))
    _al_u570 (
    .a(_al_u517_o),
    .b(_al_u542_o),
    .c(\ALU_H4/SYNTHESIZED_WIRE_94_lutinv ),
    .d(instr[3]),
    .o(\ALU_H4/n45 ));
  AL_MAP_LUT3 #(
    .EQN("(~A*~(C*~B))"),
    .INIT(8'h45))
    _al_u571 (
    .a(instr[10]),
    .b(instr[8]),
    .c(B[7]),
    .o(_al_u571_o));
  AL_MAP_LUT5 #(
    .EQN("(A*~(E*~(D*~(C*B))))"),
    .INIT(32'h2a00aaaa))
    _al_u572 (
    .a(_al_u566_o),
    .b(_al_u569_o),
    .c(\ALU_H4/n45 ),
    .d(_al_u571_o),
    .e(instr[9]),
    .o(n100));
  AL_MAP_LUT4 #(
    .EQN("(A*~(D*~C*B))"),
    .INIT(16'ha2aa))
    _al_u573 (
    .a(jmp_en),
    .b(_al_u369_o),
    .c(instr[10]),
    .d(A[7]),
    .o(_al_u573_o));
  AL_MAP_LUT5 #(
    .EQN("(B*~(E*~(~C*~(~D*~A))))"),
    .INIT(32'h0c08cccc))
    _al_u574 (
    .a(_al_u542_o),
    .b(_al_u573_o),
    .c(\ALU_H4/SYNTHESIZED_WIRE_25_lutinv ),
    .d(_al_u544_o),
    .e(_al_u565_o),
    .o(_al_u574_o));
  AL_MAP_LUT5 #(
    .EQN("(C*~(E*~(D*~(B*A))))"),
    .INIT(32'h7000f0f0))
    _al_u575 (
    .a(_al_u569_o),
    .b(\ALU_H4/n45 ),
    .c(_al_u574_o),
    .d(_al_u571_o),
    .e(instr[9]),
    .o(jmp_lutinv));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u576 (
    .a(u45_sel_is_3_o),
    .b(RET1[1]),
    .c(daddr[9]),
    .o(jaddr[9]));
  AL_MAP_LUT4 #(
    .EQN("(D*~C*~B*A)"),
    .INIT(16'h0200))
    _al_u577 (
    .a(n18),
    .b(instr[2]),
    .c(instr[1]),
    .d(instr[0]),
    .o(mux17_b0_sel_is_3_o));
  AL_MAP_LUT3 #(
    .EQN("(C*~(A)*~(B)+C*A*~(B)+~(C)*A*B+C*A*B)"),
    .INIT(8'hb8))
    _al_u578 (
    .a(ddata_o[1]),
    .b(mux17_b0_sel_is_3_o),
    .c(RET1[1]),
    .o(n36[1]));
  AL_MAP_LUT5 #(
    .EQN("(B*~((E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A))*~(D)+B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*~(D)+~(B)*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D+B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D)"),
    .INIT(32'hf5cca0cc))
    _al_u579 (
    .a(jmp_lutinv),
    .b(n36[1]),
    .c(jaddr[9]),
    .d(_al_u361_o),
    .e(PCP1[9]),
    .o(n39[1]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*~(D)*~(C)+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*~(C)+~((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A))*D*C+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*C)"),
    .INIT(32'hfd0df808))
    _al_u580 (
    .a(jmp_lutinv),
    .b(jaddr[9]),
    .c(int_filter),
    .d(IVEC_addr[9]),
    .e(PCP1[9]),
    .o(n7[9]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u581 (
    .a(u45_sel_is_3_o),
    .b(RET1[0]),
    .c(daddr[8]),
    .o(jaddr[8]));
  AL_MAP_LUT3 #(
    .EQN("(C*~B*A)"),
    .INIT(8'h20))
    _al_u582 (
    .a(_al_u431_o),
    .b(instr[1]),
    .c(instr[0]),
    .o(_al_u582_o));
  AL_MAP_LUT3 #(
    .EQN("(C*~(A)*~(B)+C*A*~(B)+~(C)*A*B+C*A*B)"),
    .INIT(8'hb8))
    _al_u583 (
    .a(ddata_o[0]),
    .b(mux17_b0_sel_is_3_o),
    .c(RET1[0]),
    .o(n36[0]));
  AL_MAP_LUT5 #(
    .EQN("(B*~((E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A))*~(D)+B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*~(D)+~(B)*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D+B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D)"),
    .INIT(32'hf5cca0cc))
    _al_u584 (
    .a(jmp_lutinv),
    .b(n36[0]),
    .c(jaddr[8]),
    .d(_al_u361_o),
    .e(PCP1[8]),
    .o(n39[0]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*~(D)*~(C)+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*~(C)+~((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A))*D*C+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*C)"),
    .INIT(32'hfd0df808))
    _al_u585 (
    .a(jmp_lutinv),
    .b(jaddr[8]),
    .c(int_filter),
    .d(IVEC_addr[8]),
    .e(PCP1[8]),
    .o(n7[8]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u586 (
    .a(u45_sel_is_3_o),
    .b(RET0[7]),
    .c(daddr[7]),
    .o(jaddr[7]));
  AL_MAP_LUT4 #(
    .EQN("(~D*~C*~B*A)"),
    .INIT(16'h0002))
    _al_u587 (
    .a(n18),
    .b(instr[2]),
    .c(instr[1]),
    .d(instr[0]),
    .o(mux18_b0_sel_is_3_o));
  AL_MAP_LUT5 #(
    .EQN("(~E*~((~C*~(B*~A)))*~(D)+~E*(~C*~(B*~A))*~(D)+~(~E)*(~C*~(B*~A))*D+~E*(~C*~(B*~A))*D)"),
    .INIT(32'h0b000bff))
    _al_u588 (
    .a(_al_u548_o),
    .b(_al_u553_o),
    .c(_al_u556_o),
    .d(mux18_b0_sel_is_3_o),
    .e(RET0[7]),
    .o(_al_u588_o));
  AL_MAP_LUT3 #(
    .EQN("(~C*~B*A)"),
    .INIT(8'h02))
    _al_u589 (
    .a(_al_u431_o),
    .b(instr[1]),
    .c(instr[0]),
    .o(_al_u589_o));
  AL_MAP_LUT5 #(
    .EQN("(~B*~((E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A))*~(D)+~B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*~(D)+~(~B)*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D+~B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D)"),
    .INIT(32'hf533a033))
    _al_u590 (
    .a(jmp_lutinv),
    .b(_al_u588_o),
    .c(jaddr[7]),
    .d(_al_u361_o),
    .e(PCP1[7]),
    .o(n38[7]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*~(D)*~(C)+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*~(C)+~((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A))*D*C+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*C)"),
    .INIT(32'hfd0df808))
    _al_u591 (
    .a(jmp_lutinv),
    .b(jaddr[7]),
    .c(int_filter),
    .d(IVEC_addr[7]),
    .e(PCP1[7]),
    .o(n7[7]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u592 (
    .a(u45_sel_is_3_o),
    .b(RET0[6]),
    .c(daddr[6]),
    .o(jaddr[6]));
  AL_MAP_LUT4 #(
    .EQN("(~C*(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B))"),
    .INIT(16'h0b08))
    _al_u593 (
    .a(ddata_o[6]),
    .b(mux18_b0_sel_is_3_o),
    .c(_al_u361_o),
    .d(RET0[6]),
    .o(_al_u593_o));
  AL_MAP_LUT5 #(
    .EQN("~(~B*~(D*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)))"),
    .INIT(32'hfdcceccc))
    _al_u594 (
    .a(jmp_lutinv),
    .b(_al_u593_o),
    .c(jaddr[6]),
    .d(_al_u361_o),
    .e(PCP1[6]),
    .o(n38[6]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*~(D)*~(C)+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*~(C)+~((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A))*D*C+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*C)"),
    .INIT(32'hfd0df808))
    _al_u595 (
    .a(jmp_lutinv),
    .b(jaddr[6]),
    .c(int_filter),
    .d(IVEC_addr[6]),
    .e(PCP1[6]),
    .o(n7[6]));
  AL_MAP_LUT3 #(
    .EQN("(~B*~(~C*~A))"),
    .INIT(8'h32))
    _al_u596 (
    .a(mux18_b0_sel_is_3_o),
    .b(_al_u361_o),
    .c(RET0[5]),
    .o(_al_u596_o));
  AL_MAP_LUT5 #(
    .EQN("(B*~(D*~(C*~(E*~A))))"),
    .INIT(32'h80ccc0cc))
    _al_u597 (
    .a(_al_u503_o),
    .b(_al_u596_o),
    .c(_al_u504_o),
    .d(_al_u589_o),
    .e(_al_u502_o),
    .o(_al_u597_o));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u598 (
    .a(u45_sel_is_3_o),
    .b(RET0[5]),
    .c(daddr[5]),
    .o(jaddr[5]));
  AL_MAP_LUT5 #(
    .EQN("~(~B*~(D*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)))"),
    .INIT(32'hfdcceccc))
    _al_u599 (
    .a(jmp_lutinv),
    .b(_al_u597_o),
    .c(jaddr[5]),
    .d(_al_u361_o),
    .e(PCP1[5]),
    .o(n38[5]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*~(D)*~(C)+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*~(C)+~((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A))*D*C+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*C)"),
    .INIT(32'hfd0df808))
    _al_u600 (
    .a(jmp_lutinv),
    .b(jaddr[5]),
    .c(int_filter),
    .d(IVEC_addr[5]),
    .e(PCP1[5]),
    .o(n7[5]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u601 (
    .a(u45_sel_is_3_o),
    .b(RET0[4]),
    .c(daddr[4]),
    .o(jaddr[4]));
  AL_MAP_LUT5 #(
    .EQN("~(~E*~((D*~C*~A))*~(B)+~E*(D*~C*~A)*~(B)+~(~E)*(D*~C*~A)*B+~E*(D*~C*~A)*B)"),
    .INIT(32'hfbffc8cc))
    _al_u602 (
    .a(_al_u478_o),
    .b(mux18_b0_sel_is_3_o),
    .c(_al_u479_o),
    .d(_al_u374_o),
    .e(RET0[4]),
    .o(n37[4]));
  AL_MAP_LUT5 #(
    .EQN("(B*~((E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A))*~(D)+B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*~(D)+~(B)*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D+B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D)"),
    .INIT(32'hf5cca0cc))
    _al_u603 (
    .a(jmp_lutinv),
    .b(n37[4]),
    .c(jaddr[4]),
    .d(_al_u361_o),
    .e(PCP1[4]),
    .o(n38[4]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*~(D)*~(C)+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*~(C)+~((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A))*D*C+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*C)"),
    .INIT(32'hfd0df808))
    _al_u604 (
    .a(jmp_lutinv),
    .b(jaddr[4]),
    .c(int_filter),
    .d(IVEC_addr[4]),
    .e(PCP1[4]),
    .o(n7[4]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u605 (
    .a(u45_sel_is_3_o),
    .b(RET0[3]),
    .c(daddr[3]),
    .o(jaddr[3]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(A)*~(B)+C*A*~(B)+~(C)*A*B+C*A*B)"),
    .INIT(8'hb8))
    _al_u606 (
    .a(ddata_o[3]),
    .b(mux18_b0_sel_is_3_o),
    .c(RET0[3]),
    .o(n37[3]));
  AL_MAP_LUT5 #(
    .EQN("(B*~((E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A))*~(D)+B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*~(D)+~(B)*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D+B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D)"),
    .INIT(32'hf5cca0cc))
    _al_u607 (
    .a(jmp_lutinv),
    .b(n37[3]),
    .c(jaddr[3]),
    .d(_al_u361_o),
    .e(PCP1[3]),
    .o(n38[3]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*~(D)*~(C)+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*~(C)+~((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A))*D*C+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*C)"),
    .INIT(32'hfd0df808))
    _al_u608 (
    .a(jmp_lutinv),
    .b(jaddr[3]),
    .c(int_filter),
    .d(IVEC_addr[3]),
    .e(PCP1[3]),
    .o(n7[3]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u609 (
    .a(u45_sel_is_3_o),
    .b(RET2[6]),
    .c(daddr[22]),
    .o(jaddr[22]));
  AL_MAP_LUT4 #(
    .EQN("(~D*C*~B*A)"),
    .INIT(16'h0020))
    _al_u610 (
    .a(n18),
    .b(instr[2]),
    .c(instr[1]),
    .d(instr[0]),
    .o(mux16_b0_sel_is_3_o));
  AL_MAP_LUT3 #(
    .EQN("(~C*B*A)"),
    .INIT(8'h08))
    _al_u611 (
    .a(_al_u431_o),
    .b(instr[1]),
    .c(instr[0]),
    .o(_al_u611_o));
  AL_MAP_LUT4 #(
    .EQN("(~C*(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B))"),
    .INIT(16'h0b08))
    _al_u612 (
    .a(ddata_o[6]),
    .b(mux16_b0_sel_is_3_o),
    .c(_al_u361_o),
    .d(RET2[6]),
    .o(_al_u612_o));
  AL_MAP_LUT5 #(
    .EQN("~(~B*~(D*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)))"),
    .INIT(32'hfdcceccc))
    _al_u613 (
    .a(jmp_lutinv),
    .b(_al_u612_o),
    .c(jaddr[22]),
    .d(_al_u361_o),
    .e(PCP1[22]),
    .o(n40[6]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*~(D)*~(C)+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*~(C)+~((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A))*D*C+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*C)"),
    .INIT(32'hfd0df808))
    _al_u614 (
    .a(jmp_lutinv),
    .b(jaddr[22]),
    .c(int_filter),
    .d(IVEC_addr[22]),
    .e(PCP1[22]),
    .o(n7[22]));
  AL_MAP_LUT3 #(
    .EQN("(~B*~(~C*~A))"),
    .INIT(8'h32))
    _al_u615 (
    .a(mux16_b0_sel_is_3_o),
    .b(_al_u361_o),
    .c(RET2[5]),
    .o(_al_u615_o));
  AL_MAP_LUT5 #(
    .EQN("(B*~(D*~(C*~(E*~A))))"),
    .INIT(32'h80ccc0cc))
    _al_u616 (
    .a(_al_u503_o),
    .b(_al_u615_o),
    .c(_al_u504_o),
    .d(_al_u611_o),
    .e(_al_u502_o),
    .o(_al_u616_o));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u617 (
    .a(u45_sel_is_3_o),
    .b(RET2[5]),
    .c(daddr[21]),
    .o(jaddr[21]));
  AL_MAP_LUT5 #(
    .EQN("~(~B*~(D*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)))"),
    .INIT(32'hfdcceccc))
    _al_u618 (
    .a(jmp_lutinv),
    .b(_al_u616_o),
    .c(jaddr[21]),
    .d(_al_u361_o),
    .e(PCP1[21]),
    .o(n40[5]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*~(D)*~(C)+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*~(C)+~((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A))*D*C+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*C)"),
    .INIT(32'hfd0df808))
    _al_u619 (
    .a(jmp_lutinv),
    .b(jaddr[21]),
    .c(int_filter),
    .d(IVEC_addr[21]),
    .e(PCP1[21]),
    .o(n7[21]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u620 (
    .a(u45_sel_is_3_o),
    .b(RET2[4]),
    .c(daddr[20]),
    .o(jaddr[20]));
  AL_MAP_LUT5 #(
    .EQN("~(~E*~((D*~C*~A))*~(B)+~E*(D*~C*~A)*~(B)+~(~E)*(D*~C*~A)*B+~E*(D*~C*~A)*B)"),
    .INIT(32'hfbffc8cc))
    _al_u621 (
    .a(_al_u478_o),
    .b(mux16_b0_sel_is_3_o),
    .c(_al_u479_o),
    .d(_al_u374_o),
    .e(RET2[4]),
    .o(n35[4]));
  AL_MAP_LUT5 #(
    .EQN("(B*~((E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A))*~(D)+B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*~(D)+~(B)*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D+B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D)"),
    .INIT(32'hf5cca0cc))
    _al_u622 (
    .a(jmp_lutinv),
    .b(n35[4]),
    .c(jaddr[20]),
    .d(_al_u361_o),
    .e(PCP1[20]),
    .o(n40[4]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*~(D)*~(C)+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*~(C)+~((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A))*D*C+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*C)"),
    .INIT(32'hfd0df808))
    _al_u623 (
    .a(jmp_lutinv),
    .b(jaddr[20]),
    .c(int_filter),
    .d(IVEC_addr[20]),
    .e(PCP1[20]),
    .o(n7[20]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u624 (
    .a(u45_sel_is_3_o),
    .b(RET0[2]),
    .c(daddr[2]),
    .o(jaddr[2]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(A)*~(B)+C*A*~(B)+~(C)*A*B+C*A*B)"),
    .INIT(8'hb8))
    _al_u625 (
    .a(ddata_o[2]),
    .b(mux18_b0_sel_is_3_o),
    .c(RET0[2]),
    .o(n37[2]));
  AL_MAP_LUT5 #(
    .EQN("(B*~((E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A))*~(D)+B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*~(D)+~(B)*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D+B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D)"),
    .INIT(32'hf5cca0cc))
    _al_u626 (
    .a(jmp_lutinv),
    .b(n37[2]),
    .c(jaddr[2]),
    .d(_al_u361_o),
    .e(PCP1[2]),
    .o(n38[2]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*~(D)*~(C)+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*~(C)+~((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A))*D*C+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*C)"),
    .INIT(32'hfd0df808))
    _al_u627 (
    .a(jmp_lutinv),
    .b(jaddr[2]),
    .c(int_filter),
    .d(IVEC_addr[2]),
    .e(PCP1[2]),
    .o(n7[2]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u628 (
    .a(u45_sel_is_3_o),
    .b(RET2[3]),
    .c(daddr[19]),
    .o(jaddr[19]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(A)*~(B)+C*A*~(B)+~(C)*A*B+C*A*B)"),
    .INIT(8'hb8))
    _al_u629 (
    .a(ddata_o[3]),
    .b(mux16_b0_sel_is_3_o),
    .c(RET2[3]),
    .o(n35[3]));
  AL_MAP_LUT5 #(
    .EQN("(B*~((E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A))*~(D)+B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*~(D)+~(B)*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D+B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D)"),
    .INIT(32'hf5cca0cc))
    _al_u630 (
    .a(jmp_lutinv),
    .b(n35[3]),
    .c(jaddr[19]),
    .d(_al_u361_o),
    .e(PCP1[19]),
    .o(n40[3]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*~(D)*~(C)+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*~(C)+~((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A))*D*C+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*C)"),
    .INIT(32'hfd0df808))
    _al_u631 (
    .a(jmp_lutinv),
    .b(jaddr[19]),
    .c(int_filter),
    .d(IVEC_addr[19]),
    .e(PCP1[19]),
    .o(n7[19]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u632 (
    .a(u45_sel_is_3_o),
    .b(RET2[2]),
    .c(daddr[18]),
    .o(jaddr[18]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(A)*~(B)+C*A*~(B)+~(C)*A*B+C*A*B)"),
    .INIT(8'hb8))
    _al_u633 (
    .a(ddata_o[2]),
    .b(mux16_b0_sel_is_3_o),
    .c(RET2[2]),
    .o(n35[2]));
  AL_MAP_LUT5 #(
    .EQN("(B*~((E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A))*~(D)+B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*~(D)+~(B)*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D+B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D)"),
    .INIT(32'hf5cca0cc))
    _al_u634 (
    .a(jmp_lutinv),
    .b(n35[2]),
    .c(jaddr[18]),
    .d(_al_u361_o),
    .e(PCP1[18]),
    .o(n40[2]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*~(D)*~(C)+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*~(C)+~((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A))*D*C+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*C)"),
    .INIT(32'hfd0df808))
    _al_u635 (
    .a(jmp_lutinv),
    .b(jaddr[18]),
    .c(int_filter),
    .d(IVEC_addr[18]),
    .e(PCP1[18]),
    .o(n7[18]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u636 (
    .a(u45_sel_is_3_o),
    .b(RET2[1]),
    .c(daddr[17]),
    .o(jaddr[17]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(A)*~(B)+C*A*~(B)+~(C)*A*B+C*A*B)"),
    .INIT(8'hb8))
    _al_u637 (
    .a(ddata_o[1]),
    .b(mux16_b0_sel_is_3_o),
    .c(RET2[1]),
    .o(n35[1]));
  AL_MAP_LUT5 #(
    .EQN("(B*~((E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A))*~(D)+B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*~(D)+~(B)*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D+B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D)"),
    .INIT(32'hf5cca0cc))
    _al_u638 (
    .a(jmp_lutinv),
    .b(n35[1]),
    .c(jaddr[17]),
    .d(_al_u361_o),
    .e(PCP1[17]),
    .o(n40[1]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*~(D)*~(C)+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*~(C)+~((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A))*D*C+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*C)"),
    .INIT(32'hfd0df808))
    _al_u639 (
    .a(jmp_lutinv),
    .b(jaddr[17]),
    .c(int_filter),
    .d(IVEC_addr[17]),
    .e(PCP1[17]),
    .o(n7[17]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u640 (
    .a(u45_sel_is_3_o),
    .b(RET2[0]),
    .c(daddr[16]),
    .o(jaddr[16]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(A)*~(B)+C*A*~(B)+~(C)*A*B+C*A*B)"),
    .INIT(8'hb8))
    _al_u641 (
    .a(ddata_o[0]),
    .b(mux16_b0_sel_is_3_o),
    .c(RET2[0]),
    .o(n35[0]));
  AL_MAP_LUT5 #(
    .EQN("(B*~((E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A))*~(D)+B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*~(D)+~(B)*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D+B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D)"),
    .INIT(32'hf5cca0cc))
    _al_u642 (
    .a(jmp_lutinv),
    .b(n35[0]),
    .c(jaddr[16]),
    .d(_al_u361_o),
    .e(PCP1[16]),
    .o(n40[0]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*~(D)*~(C)+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*~(C)+~((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A))*D*C+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*C)"),
    .INIT(32'hfd0df808))
    _al_u643 (
    .a(jmp_lutinv),
    .b(jaddr[16]),
    .c(int_filter),
    .d(IVEC_addr[16]),
    .e(PCP1[16]),
    .o(n7[16]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u644 (
    .a(u45_sel_is_3_o),
    .b(RET1[7]),
    .c(daddr[15]),
    .o(jaddr[15]));
  AL_MAP_LUT5 #(
    .EQN("(~E*~((~C*~(B*~A)))*~(D)+~E*(~C*~(B*~A))*~(D)+~(~E)*(~C*~(B*~A))*D+~E*(~C*~(B*~A))*D)"),
    .INIT(32'h0b000bff))
    _al_u645 (
    .a(_al_u548_o),
    .b(_al_u553_o),
    .c(_al_u556_o),
    .d(mux17_b0_sel_is_3_o),
    .e(RET1[7]),
    .o(_al_u645_o));
  AL_MAP_LUT5 #(
    .EQN("(~B*~((E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A))*~(D)+~B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*~(D)+~(~B)*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D+~B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D)"),
    .INIT(32'hf533a033))
    _al_u646 (
    .a(jmp_lutinv),
    .b(_al_u645_o),
    .c(jaddr[15]),
    .d(_al_u361_o),
    .e(PCP1[15]),
    .o(n39[7]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*~(D)*~(C)+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*~(C)+~((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A))*D*C+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*C)"),
    .INIT(32'hfd0df808))
    _al_u647 (
    .a(jmp_lutinv),
    .b(jaddr[15]),
    .c(int_filter),
    .d(IVEC_addr[15]),
    .e(PCP1[15]),
    .o(n7[15]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u648 (
    .a(u45_sel_is_3_o),
    .b(RET1[6]),
    .c(daddr[14]),
    .o(jaddr[14]));
  AL_MAP_LUT4 #(
    .EQN("(~C*(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B))"),
    .INIT(16'h0b08))
    _al_u649 (
    .a(ddata_o[6]),
    .b(mux17_b0_sel_is_3_o),
    .c(_al_u361_o),
    .d(RET1[6]),
    .o(_al_u649_o));
  AL_MAP_LUT5 #(
    .EQN("~(~B*~(D*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)))"),
    .INIT(32'hfdcceccc))
    _al_u650 (
    .a(jmp_lutinv),
    .b(_al_u649_o),
    .c(jaddr[14]),
    .d(_al_u361_o),
    .e(PCP1[14]),
    .o(n39[6]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*~(D)*~(C)+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*~(C)+~((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A))*D*C+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*C)"),
    .INIT(32'hfd0df808))
    _al_u651 (
    .a(jmp_lutinv),
    .b(jaddr[14]),
    .c(int_filter),
    .d(IVEC_addr[14]),
    .e(PCP1[14]),
    .o(n7[14]));
  AL_MAP_LUT3 #(
    .EQN("(~B*~(~C*~A))"),
    .INIT(8'h32))
    _al_u652 (
    .a(mux17_b0_sel_is_3_o),
    .b(_al_u361_o),
    .c(RET1[5]),
    .o(_al_u652_o));
  AL_MAP_LUT5 #(
    .EQN("(B*~(D*~(C*~(E*~A))))"),
    .INIT(32'h80ccc0cc))
    _al_u653 (
    .a(_al_u503_o),
    .b(_al_u652_o),
    .c(_al_u504_o),
    .d(_al_u582_o),
    .e(_al_u502_o),
    .o(_al_u653_o));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u654 (
    .a(u45_sel_is_3_o),
    .b(RET1[5]),
    .c(daddr[13]),
    .o(jaddr[13]));
  AL_MAP_LUT5 #(
    .EQN("~(~B*~(D*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)))"),
    .INIT(32'hfdcceccc))
    _al_u655 (
    .a(jmp_lutinv),
    .b(_al_u653_o),
    .c(jaddr[13]),
    .d(_al_u361_o),
    .e(PCP1[13]),
    .o(n39[5]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*~(D)*~(C)+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*~(C)+~((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A))*D*C+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*C)"),
    .INIT(32'hfd0df808))
    _al_u656 (
    .a(jmp_lutinv),
    .b(jaddr[13]),
    .c(int_filter),
    .d(IVEC_addr[13]),
    .e(PCP1[13]),
    .o(n7[13]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u657 (
    .a(u45_sel_is_3_o),
    .b(RET1[4]),
    .c(daddr[12]),
    .o(jaddr[12]));
  AL_MAP_LUT5 #(
    .EQN("~(~E*~((D*~C*~A))*~(B)+~E*(D*~C*~A)*~(B)+~(~E)*(D*~C*~A)*B+~E*(D*~C*~A)*B)"),
    .INIT(32'hfbffc8cc))
    _al_u658 (
    .a(_al_u478_o),
    .b(mux17_b0_sel_is_3_o),
    .c(_al_u479_o),
    .d(_al_u374_o),
    .e(RET1[4]),
    .o(n36[4]));
  AL_MAP_LUT5 #(
    .EQN("(B*~((E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A))*~(D)+B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*~(D)+~(B)*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D+B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D)"),
    .INIT(32'hf5cca0cc))
    _al_u659 (
    .a(jmp_lutinv),
    .b(n36[4]),
    .c(jaddr[12]),
    .d(_al_u361_o),
    .e(PCP1[12]),
    .o(n39[4]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*~(D)*~(C)+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*~(C)+~((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A))*D*C+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*C)"),
    .INIT(32'hfd0df808))
    _al_u660 (
    .a(jmp_lutinv),
    .b(jaddr[12]),
    .c(int_filter),
    .d(IVEC_addr[12]),
    .e(PCP1[12]),
    .o(n7[12]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u661 (
    .a(u45_sel_is_3_o),
    .b(RET1[3]),
    .c(daddr[11]),
    .o(jaddr[11]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(A)*~(B)+C*A*~(B)+~(C)*A*B+C*A*B)"),
    .INIT(8'hb8))
    _al_u662 (
    .a(ddata_o[3]),
    .b(mux17_b0_sel_is_3_o),
    .c(RET1[3]),
    .o(n36[3]));
  AL_MAP_LUT5 #(
    .EQN("(B*~((E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A))*~(D)+B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*~(D)+~(B)*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D+B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D)"),
    .INIT(32'hf5cca0cc))
    _al_u663 (
    .a(jmp_lutinv),
    .b(n36[3]),
    .c(jaddr[11]),
    .d(_al_u361_o),
    .e(PCP1[11]),
    .o(n39[3]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*~(D)*~(C)+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*~(C)+~((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A))*D*C+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*C)"),
    .INIT(32'hfd0df808))
    _al_u664 (
    .a(jmp_lutinv),
    .b(jaddr[11]),
    .c(int_filter),
    .d(IVEC_addr[11]),
    .e(PCP1[11]),
    .o(n7[11]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u665 (
    .a(u45_sel_is_3_o),
    .b(RET1[2]),
    .c(daddr[10]),
    .o(jaddr[10]));
  AL_MAP_LUT4 #(
    .EQN("(~C*(D*~(A)*~(B)+D*A*~(B)+~(D)*A*B+D*A*B))"),
    .INIT(16'h0b08))
    _al_u666 (
    .a(ddata_o[2]),
    .b(mux17_b0_sel_is_3_o),
    .c(_al_u361_o),
    .d(RET1[2]),
    .o(_al_u666_o));
  AL_MAP_LUT5 #(
    .EQN("~(~B*~(D*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)))"),
    .INIT(32'hfdcceccc))
    _al_u667 (
    .a(jmp_lutinv),
    .b(_al_u666_o),
    .c(jaddr[10]),
    .d(_al_u361_o),
    .e(PCP1[10]),
    .o(n39[2]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*~(D)*~(C)+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*~(C)+~((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A))*D*C+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*C)"),
    .INIT(32'hfd0df808))
    _al_u668 (
    .a(jmp_lutinv),
    .b(jaddr[10]),
    .c(int_filter),
    .d(IVEC_addr[10]),
    .e(PCP1[10]),
    .o(n7[10]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u669 (
    .a(u45_sel_is_3_o),
    .b(RET0[1]),
    .c(daddr[1]),
    .o(jaddr[1]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(A)*~(B)+C*A*~(B)+~(C)*A*B+C*A*B)"),
    .INIT(8'hb8))
    _al_u670 (
    .a(ddata_o[1]),
    .b(mux18_b0_sel_is_3_o),
    .c(RET0[1]),
    .o(n37[1]));
  AL_MAP_LUT5 #(
    .EQN("(B*~((E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A))*~(D)+B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*~(D)+~(B)*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D+B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D)"),
    .INIT(32'hf5cca0cc))
    _al_u671 (
    .a(jmp_lutinv),
    .b(n37[1]),
    .c(jaddr[1]),
    .d(_al_u361_o),
    .e(PCP1[1]),
    .o(n38[1]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*~(D)*~(C)+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*~(C)+~((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A))*D*C+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*C)"),
    .INIT(32'hfd0df808))
    _al_u672 (
    .a(jmp_lutinv),
    .b(jaddr[1]),
    .c(int_filter),
    .d(IVEC_addr[1]),
    .e(PCP1[1]),
    .o(n7[1]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u673 (
    .a(u45_sel_is_3_o),
    .b(RET0[0]),
    .c(daddr[0]),
    .o(jaddr[0]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(A)*~(B)+C*A*~(B)+~(C)*A*B+C*A*B)"),
    .INIT(8'hb8))
    _al_u674 (
    .a(ddata_o[0]),
    .b(mux18_b0_sel_is_3_o),
    .c(RET0[0]),
    .o(n37[0]));
  AL_MAP_LUT5 #(
    .EQN("(B*~((E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A))*~(D)+B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*~(D)+~(B)*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D+B*(E*~(C)*~(A)+E*C*~(A)+~(E)*C*A+E*C*A)*D)"),
    .INIT(32'hf5cca0cc))
    _al_u675 (
    .a(jmp_lutinv),
    .b(n37[0]),
    .c(jaddr[0]),
    .d(_al_u361_o),
    .e(PCP1[0]),
    .o(n38[0]));
  AL_MAP_LUT5 #(
    .EQN("((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*~(D)*~(C)+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*~(C)+~((E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A))*D*C+(E*~(B)*~(A)+E*B*~(A)+~(E)*B*A+E*B*A)*D*C)"),
    .INIT(32'hfd0df808))
    _al_u676 (
    .a(jmp_lutinv),
    .b(jaddr[0]),
    .c(int_filter),
    .d(IVEC_addr[0]),
    .e(PCP1[0]),
    .o(n7[0]));
  AL_MAP_LUT1 #(
    .EQN("(~A)"),
    .INIT(2'h1))
    _al_u677 (
    .a(rst),
    .o(rst_neg));
  AL_PHY_LSLICE #(
    //.MACRO("add0/ucin_al_u678"),
    //.R_POSITION("X0Y1Z1"),
    .DEMUX0("E"),
    .DEMUX1("E"),
    .GSR("DISABLE"),
    .INIT_LUTF0(16'hA55A),
    .INIT_LUTF1(16'hA55A),
    .INIT_LUTG0(16'hC33C),
    .INIT_LUTG1(16'hC33C),
    .LSFMUX0("SUM"),
    .LSFMUX1("SUM"),
    .LSFXMUX0("SUM"),
    .LSFXMUX1("SUM"),
    .MODE("RIPPLE"))
    \add0/u11_al_u681  (
    .a({iaddr[13],iaddr[11]}),
    .b({iaddr[14],iaddr[12]}),
    .c(2'b00),
    .d(2'b00),
    .e(2'b00),
    .fci(\add0/c11 ),
    .f({PCP1[13],PCP1[11]}),
    .fco(\add0/c15 ),
    .fx({PCP1[14],PCP1[12]}));
  AL_PHY_LSLICE #(
    //.MACRO("add0/ucin_al_u678"),
    //.R_POSITION("X0Y2Z0"),
    .DEMUX0("E"),
    .DEMUX1("E"),
    .GSR("DISABLE"),
    .INIT_LUTF0(16'hA55A),
    .INIT_LUTF1(16'hA55A),
    .INIT_LUTG0(16'hC33C),
    .INIT_LUTG1(16'hC33C),
    .LSFMUX0("SUM"),
    .LSFMUX1("SUM"),
    .LSFXMUX0("SUM"),
    .LSFXMUX1("SUM"),
    .MODE("RIPPLE"))
    \add0/u15_al_u682  (
    .a({iaddr[17],iaddr[15]}),
    .b({iaddr[18],iaddr[16]}),
    .c(2'b00),
    .d(2'b00),
    .e(2'b00),
    .fci(\add0/c15 ),
    .f({PCP1[17],PCP1[15]}),
    .fco(\add0/c19 ),
    .fx({PCP1[18],PCP1[16]}));
  AL_PHY_LSLICE #(
    //.MACRO("add0/ucin_al_u678"),
    //.R_POSITION("X0Y2Z1"),
    .DEMUX0("E"),
    .DEMUX1("E"),
    .GSR("DISABLE"),
    .INIT_LUTF0(16'hA55A),
    .INIT_LUTF1(16'hA55A),
    .INIT_LUTG0(16'hC33C),
    .INIT_LUTG1(16'hC33C),
    .LSFMUX0("SUM"),
    .LSFMUX1("SUM"),
    .LSFXMUX0("SUM"),
    .LSFXMUX1("SUM"),
    .MODE("RIPPLE"))
    \add0/u19_al_u683  (
    .a({iaddr[21],iaddr[19]}),
    .b({iaddr[22],iaddr[20]}),
    .c(2'b00),
    .d(2'b00),
    .e(2'b00),
    .fci(\add0/c19 ),
    .f({PCP1[21],PCP1[19]}),
    .fx({PCP1[22],PCP1[20]}));
  AL_PHY_LSLICE #(
    //.MACRO("add0/ucin_al_u678"),
    //.R_POSITION("X0Y0Z1"),
    .DEMUX0("E"),
    .DEMUX1("E"),
    .GSR("DISABLE"),
    .INIT_LUTF0(16'hA55A),
    .INIT_LUTF1(16'hA55A),
    .INIT_LUTG0(16'hC33C),
    .INIT_LUTG1(16'hC33C),
    .LSFMUX0("SUM"),
    .LSFMUX1("SUM"),
    .LSFXMUX0("SUM"),
    .LSFXMUX1("SUM"),
    .MODE("RIPPLE"))
    \add0/u3_al_u679  (
    .a({iaddr[5],iaddr[3]}),
    .b({iaddr[6],iaddr[4]}),
    .c(2'b00),
    .d(2'b00),
    .e(2'b00),
    .fci(\add0/c3 ),
    .f({PCP1[5],PCP1[3]}),
    .fco(\add0/c7 ),
    .fx({PCP1[6],PCP1[4]}));
  AL_PHY_LSLICE #(
    //.MACRO("add0/ucin_al_u678"),
    //.R_POSITION("X0Y1Z0"),
    .DEMUX0("E"),
    .DEMUX1("E"),
    .GSR("DISABLE"),
    .INIT_LUTF0(16'hA55A),
    .INIT_LUTF1(16'hA55A),
    .INIT_LUTG0(16'hC33C),
    .INIT_LUTG1(16'hC33C),
    .LSFMUX0("SUM"),
    .LSFMUX1("SUM"),
    .LSFXMUX0("SUM"),
    .LSFXMUX1("SUM"),
    .MODE("RIPPLE"))
    \add0/u7_al_u680  (
    .a({iaddr[9],iaddr[7]}),
    .b({iaddr[10],iaddr[8]}),
    .c(2'b00),
    .d(2'b00),
    .e(2'b00),
    .fci(\add0/c7 ),
    .f({PCP1[9],PCP1[7]}),
    .fco(\add0/c11 ),
    .fx({PCP1[10],PCP1[8]}));
  AL_PHY_LSLICE #(
    //.MACRO("add0/ucin_al_u678"),
    //.R_POSITION("X0Y0Z0"),
    .DEMUX0("E"),
    .DEMUX1("E"),
    .GSR("DISABLE"),
    .INIT_LUTF0(16'h000A),
    .INIT_LUTF1(16'hA55A),
    .INIT_LUTG0(16'hC33C),
    .INIT_LUTG1(16'hC33C),
    .LSFMUX0("SUM"),
    .LSFMUX1("SUM"),
    .LSFXMUX0("SUM"),
    .LSFXMUX1("SUM"),
    .MODE("RIPPLE"))
    \add0/ucin_al_u678  (
    .a({iaddr[1],1'b0}),
    .b({iaddr[2],iaddr[0]}),
    .c(2'b00),
    .d(2'b01),
    .e(2'b01),
    .f({PCP1[1],open_n108}),
    .fco(\add0/c3 ),
    .fx({PCP1[2],PCP1[0]}));
  AL_PHY_CONFIG #(
    .USR_GSRN_EN("ENABLE"))
    config_inst (
    .usr_gsrn(rst_neg));
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    int_service_reg (
    .clk(clk),
    .d(n41),
    .q(IN_ISP));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("INV"))
    jmp_wait_reg (
    .clk(clk),
    .d(n100),
    .sr(jmp_en),
    .q(jmp_wait));  // ../RTL/cpu/KC_LS1u_plus.v(257)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b0 (
    .clk(clk),
    .d(n38[0]),
    .q(RET0[0]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b1 (
    .clk(clk),
    .d(n38[1]),
    .q(RET0[1]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b2 (
    .clk(clk),
    .d(n38[2]),
    .q(RET0[2]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b3 (
    .clk(clk),
    .d(n38[3]),
    .q(RET0[3]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b4 (
    .clk(clk),
    .d(n38[4]),
    .q(RET0[4]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b5 (
    .clk(clk),
    .d(n38[5]),
    .q(RET0[5]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b6 (
    .clk(clk),
    .d(n38[6]),
    .q(RET0[6]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b7 (
    .clk(clk),
    .d(n38[7]),
    .q(RET0[7]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg10_b0 (
    .ce(mux45_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[0]),
    .q(B[0]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg10_b1 (
    .ce(mux45_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[1]),
    .q(B[1]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg10_b2 (
    .ce(mux45_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[2]),
    .q(B[2]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg10_b3 (
    .ce(mux45_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[3]),
    .q(B[3]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg10_b4 (
    .ce(mux45_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[4]),
    .q(B[4]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg10_b5 (
    .ce(mux45_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[5]),
    .q(B[5]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg10_b6 (
    .ce(mux45_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[6]),
    .q(B[6]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg10_b7 (
    .ce(mux45_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[7]),
    .q(B[7]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg11_b0 (
    .ce(mux46_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[0]),
    .q(A[0]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg11_b1 (
    .ce(mux46_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[1]),
    .q(A[1]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg11_b2 (
    .ce(mux46_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[2]),
    .q(A[2]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg11_b3 (
    .ce(mux46_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[3]),
    .q(A[3]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg11_b4 (
    .ce(mux46_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[4]),
    .q(A[4]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg11_b5 (
    .ce(mux46_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[5]),
    .q(A[5]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg11_b6 (
    .ce(mux46_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[6]),
    .q(A[6]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg11_b7 (
    .ce(mux46_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[7]),
    .q(A[7]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg12_b0 (
    .ce(mux47_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[0]),
    .q(C[0]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg12_b1 (
    .ce(mux47_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[1]),
    .q(C[1]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg12_b2 (
    .ce(mux47_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[2]),
    .q(C[2]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg12_b3 (
    .ce(mux47_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[3]),
    .q(C[3]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg12_b4 (
    .ce(mux47_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[4]),
    .q(C[4]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg12_b5 (
    .ce(mux47_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[5]),
    .q(C[5]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg12_b6 (
    .ce(mux47_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[6]),
    .q(C[6]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg12_b7 (
    .ce(mux47_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[7]),
    .q(C[7]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg13_b0 (
    .ce(mux3_b0_sel_is_0_o),
    .clk(clk),
    .d(n7[0]),
    .q(iaddr[0]));  // ../RTL/cpu/KC_LS1u_plus.v(49)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg13_b1 (
    .ce(mux3_b0_sel_is_0_o),
    .clk(clk),
    .d(n7[1]),
    .q(iaddr[1]));  // ../RTL/cpu/KC_LS1u_plus.v(49)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg13_b10 (
    .ce(mux3_b0_sel_is_0_o),
    .clk(clk),
    .d(n7[10]),
    .q(iaddr[10]));  // ../RTL/cpu/KC_LS1u_plus.v(49)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg13_b11 (
    .ce(mux3_b0_sel_is_0_o),
    .clk(clk),
    .d(n7[11]),
    .q(iaddr[11]));  // ../RTL/cpu/KC_LS1u_plus.v(49)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg13_b12 (
    .ce(mux3_b0_sel_is_0_o),
    .clk(clk),
    .d(n7[12]),
    .q(iaddr[12]));  // ../RTL/cpu/KC_LS1u_plus.v(49)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg13_b13 (
    .ce(mux3_b0_sel_is_0_o),
    .clk(clk),
    .d(n7[13]),
    .q(iaddr[13]));  // ../RTL/cpu/KC_LS1u_plus.v(49)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg13_b14 (
    .ce(mux3_b0_sel_is_0_o),
    .clk(clk),
    .d(n7[14]),
    .q(iaddr[14]));  // ../RTL/cpu/KC_LS1u_plus.v(49)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg13_b15 (
    .ce(mux3_b0_sel_is_0_o),
    .clk(clk),
    .d(n7[15]),
    .q(iaddr[15]));  // ../RTL/cpu/KC_LS1u_plus.v(49)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg13_b16 (
    .ce(mux3_b0_sel_is_0_o),
    .clk(clk),
    .d(n7[16]),
    .q(iaddr[16]));  // ../RTL/cpu/KC_LS1u_plus.v(49)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg13_b17 (
    .ce(mux3_b0_sel_is_0_o),
    .clk(clk),
    .d(n7[17]),
    .q(iaddr[17]));  // ../RTL/cpu/KC_LS1u_plus.v(49)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg13_b18 (
    .ce(mux3_b0_sel_is_0_o),
    .clk(clk),
    .d(n7[18]),
    .q(iaddr[18]));  // ../RTL/cpu/KC_LS1u_plus.v(49)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg13_b19 (
    .ce(mux3_b0_sel_is_0_o),
    .clk(clk),
    .d(n7[19]),
    .q(iaddr[19]));  // ../RTL/cpu/KC_LS1u_plus.v(49)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg13_b2 (
    .ce(mux3_b0_sel_is_0_o),
    .clk(clk),
    .d(n7[2]),
    .q(iaddr[2]));  // ../RTL/cpu/KC_LS1u_plus.v(49)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg13_b20 (
    .ce(mux3_b0_sel_is_0_o),
    .clk(clk),
    .d(n7[20]),
    .q(iaddr[20]));  // ../RTL/cpu/KC_LS1u_plus.v(49)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg13_b21 (
    .ce(mux3_b0_sel_is_0_o),
    .clk(clk),
    .d(n7[21]),
    .q(iaddr[21]));  // ../RTL/cpu/KC_LS1u_plus.v(49)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg13_b22 (
    .ce(mux3_b0_sel_is_0_o),
    .clk(clk),
    .d(n7[22]),
    .q(iaddr[22]));  // ../RTL/cpu/KC_LS1u_plus.v(49)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg13_b3 (
    .ce(mux3_b0_sel_is_0_o),
    .clk(clk),
    .d(n7[3]),
    .q(iaddr[3]));  // ../RTL/cpu/KC_LS1u_plus.v(49)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg13_b4 (
    .ce(mux3_b0_sel_is_0_o),
    .clk(clk),
    .d(n7[4]),
    .q(iaddr[4]));  // ../RTL/cpu/KC_LS1u_plus.v(49)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg13_b5 (
    .ce(mux3_b0_sel_is_0_o),
    .clk(clk),
    .d(n7[5]),
    .q(iaddr[5]));  // ../RTL/cpu/KC_LS1u_plus.v(49)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg13_b6 (
    .ce(mux3_b0_sel_is_0_o),
    .clk(clk),
    .d(n7[6]),
    .q(iaddr[6]));  // ../RTL/cpu/KC_LS1u_plus.v(49)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg13_b7 (
    .ce(mux3_b0_sel_is_0_o),
    .clk(clk),
    .d(n7[7]),
    .q(iaddr[7]));  // ../RTL/cpu/KC_LS1u_plus.v(49)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg13_b8 (
    .ce(mux3_b0_sel_is_0_o),
    .clk(clk),
    .d(n7[8]),
    .q(iaddr[8]));  // ../RTL/cpu/KC_LS1u_plus.v(49)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg13_b9 (
    .ce(mux3_b0_sel_is_0_o),
    .clk(clk),
    .d(n7[9]),
    .q(iaddr[9]));  // ../RTL/cpu/KC_LS1u_plus.v(49)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg1_b0 (
    .clk(clk),
    .d(n39[0]),
    .q(RET1[0]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg1_b1 (
    .clk(clk),
    .d(n39[1]),
    .q(RET1[1]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg1_b2 (
    .clk(clk),
    .d(n39[2]),
    .q(RET1[2]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg1_b3 (
    .clk(clk),
    .d(n39[3]),
    .q(RET1[3]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg1_b4 (
    .clk(clk),
    .d(n39[4]),
    .q(RET1[4]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg1_b5 (
    .clk(clk),
    .d(n39[5]),
    .q(RET1[5]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg1_b6 (
    .clk(clk),
    .d(n39[6]),
    .q(RET1[6]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg1_b7 (
    .clk(clk),
    .d(n39[7]),
    .q(RET1[7]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg2_b0 (
    .clk(clk),
    .d(n40[0]),
    .q(RET2[0]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg2_b1 (
    .clk(clk),
    .d(n40[1]),
    .q(RET2[1]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg2_b2 (
    .clk(clk),
    .d(n40[2]),
    .q(RET2[2]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg2_b3 (
    .clk(clk),
    .d(n40[3]),
    .q(RET2[3]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg2_b4 (
    .clk(clk),
    .d(n40[4]),
    .q(RET2[4]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg2_b5 (
    .clk(clk),
    .d(n40[5]),
    .q(RET2[5]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .GSR("ENABLE"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg2_b6 (
    .clk(clk),
    .d(n40[6]),
    .q(RET2[6]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b0 (
    .ce(rst),
    .clk(clk),
    .d(n42[0]),
    .q(RTA0[0]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b1 (
    .ce(rst),
    .clk(clk),
    .d(n42[1]),
    .q(RTA0[1]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b2 (
    .ce(rst),
    .clk(clk),
    .d(n42[2]),
    .q(RTA0[2]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b3 (
    .ce(rst),
    .clk(clk),
    .d(n42[3]),
    .q(RTA0[3]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b4 (
    .ce(rst),
    .clk(clk),
    .d(n42[4]),
    .q(RTA0[4]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b5 (
    .ce(rst),
    .clk(clk),
    .d(n42[5]),
    .q(RTA0[5]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b6 (
    .ce(rst),
    .clk(clk),
    .d(n42[6]),
    .q(RTA0[6]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b7 (
    .ce(rst),
    .clk(clk),
    .d(n42[7]),
    .q(RTA0[7]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg4_b0 (
    .ce(rst),
    .clk(clk),
    .d(n43[0]),
    .q(RTA1[0]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg4_b1 (
    .ce(rst),
    .clk(clk),
    .d(n43[1]),
    .q(RTA1[1]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg4_b2 (
    .ce(rst),
    .clk(clk),
    .d(n43[2]),
    .q(RTA1[2]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg4_b3 (
    .ce(rst),
    .clk(clk),
    .d(n43[3]),
    .q(RTA1[3]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg4_b4 (
    .ce(rst),
    .clk(clk),
    .d(n43[4]),
    .q(RTA1[4]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg4_b5 (
    .ce(rst),
    .clk(clk),
    .d(n43[5]),
    .q(RTA1[5]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg4_b6 (
    .ce(rst),
    .clk(clk),
    .d(n43[6]),
    .q(RTA1[6]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg4_b7 (
    .ce(rst),
    .clk(clk),
    .d(n43[7]),
    .q(RTA1[7]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg5_b0 (
    .ce(rst),
    .clk(clk),
    .d(n44[0]),
    .q(RTA2[0]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg5_b1 (
    .ce(rst),
    .clk(clk),
    .d(n44[1]),
    .q(RTA2[1]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg5_b2 (
    .ce(rst),
    .clk(clk),
    .d(n44[2]),
    .q(RTA2[2]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg5_b3 (
    .ce(rst),
    .clk(clk),
    .d(n44[3]),
    .q(RTA2[3]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg5_b4 (
    .ce(rst),
    .clk(clk),
    .d(n44[4]),
    .q(RTA2[4]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg5_b5 (
    .ce(rst),
    .clk(clk),
    .d(n44[5]),
    .q(RTA2[5]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg5_b6 (
    .ce(rst),
    .clk(clk),
    .d(n44[6]),
    .q(RTA2[6]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("INV"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg5_b7 (
    .ce(rst),
    .clk(clk),
    .d(n44[7]),
    .q(RTA2[7]));  // ../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg6_b0 (
    .clk(clk),
    .d(n65[0]),
    .q(daddr[0]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg6_b1 (
    .clk(clk),
    .d(n65[1]),
    .q(daddr[1]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg6_b2 (
    .clk(clk),
    .d(n65[2]),
    .q(daddr[2]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg6_b3 (
    .clk(clk),
    .d(n65[3]),
    .q(daddr[3]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg6_b4 (
    .clk(clk),
    .d(n65[4]),
    .q(daddr[4]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg6_b5 (
    .clk(clk),
    .d(n65[5]),
    .q(daddr[5]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg6_b6 (
    .clk(clk),
    .d(n65[6]),
    .q(daddr[6]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg6_b7 (
    .clk(clk),
    .d(n65[7]),
    .q(daddr[7]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg7_b0 (
    .clk(clk),
    .d(n66[0]),
    .q(daddr[8]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg7_b1 (
    .clk(clk),
    .d(n66[1]),
    .q(daddr[9]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg7_b2 (
    .clk(clk),
    .d(n66[2]),
    .q(daddr[10]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg7_b3 (
    .clk(clk),
    .d(n66[3]),
    .q(daddr[11]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg7_b4 (
    .clk(clk),
    .d(n66[4]),
    .q(daddr[12]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg7_b5 (
    .clk(clk),
    .d(n66[5]),
    .q(daddr[13]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg7_b6 (
    .clk(clk),
    .d(n66[6]),
    .q(daddr[14]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg7_b7 (
    .clk(clk),
    .d(n66[7]),
    .q(daddr[15]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg8_b0 (
    .clk(clk),
    .d(n67[0]),
    .q(daddr[16]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg8_b1 (
    .clk(clk),
    .d(n67[1]),
    .q(daddr[17]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg8_b2 (
    .clk(clk),
    .d(n67[2]),
    .q(daddr[18]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg8_b3 (
    .clk(clk),
    .d(n67[3]),
    .q(daddr[19]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg8_b4 (
    .clk(clk),
    .d(n67[4]),
    .q(daddr[20]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg8_b5 (
    .clk(clk),
    .d(n67[5]),
    .q(daddr[21]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg8_b6 (
    .clk(clk),
    .d(n67[6]),
    .q(daddr[22]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg8_b7 (
    .clk(clk),
    .d(n67[7]),
    .q(daddr[23]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg9_b0 (
    .ce(mux41_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[0]),
    .q(D[0]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg9_b1 (
    .ce(mux41_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[1]),
    .q(D[1]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg9_b2 (
    .ce(mux41_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[2]),
    .q(D[2]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg9_b3 (
    .ce(mux41_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[3]),
    .q(D[3]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg9_b4 (
    .ce(mux41_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[4]),
    .q(D[4]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg9_b5 (
    .ce(mux41_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[5]),
    .q(D[5]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg9_b6 (
    .ce(mux41_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[6]),
    .q(D[6]));  // ../RTL/cpu/KC_LS1u_plus.v(126)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg9_b7 (
    .ce(mux41_b0_sel_is_3_o),
    .clk(clk),
    .d(ddata_o[7]),
    .q(D[7]));  // ../RTL/cpu/KC_LS1u_plus.v(126)

endmodule 

module \l1_ionly(ENTRY_NUM=16,CACHE_DEPTH=2048)   // ../RTL/cache/l1_ionly.v(4)
  (
  L1_clear,
  addr_count,
  addr_pa_d,
  addr_pa_i,
  bclk,
  bus_error,
  bus_rdata,
  bus_trans_finish,
  clk,
  cwait,
  execute,
  host_wdata,
  line_write,
  read,
  rst,
  write,
  bus_pa,
  bus_wdata,
  cache_data_ready,
  host_rdata,
  ins_acc_fault,
  instr_read,
  load_acc_fault,
  read_line_req,
  read_req,
  store_acc_fault,
  uncache_data_ready,
  write_through_req
  );

  input L1_clear;  // ../RTL/cache/l1_ionly.v(24)
  input [7:0] addr_count;  // ../RTL/cache/l1_ionly.v(45)
  input [23:0] addr_pa_d;  // ../RTL/cache/l1_ionly.v(28)
  input [23:1] addr_pa_i;  // ../RTL/cache/l1_ionly.v(27)
  input bclk;  // ../RTL/cache/l1_ionly.v(17)
  input bus_error;  // ../RTL/cache/l1_ionly.v(48)
  input [7:0] bus_rdata;  // ../RTL/cache/l1_ionly.v(44)
  input bus_trans_finish;  // ../RTL/cache/l1_ionly.v(47)
  input clk;  // ../RTL/cache/l1_ionly.v(16)
  input cwait;  // ../RTL/cache/l1_ionly.v(25)
  input execute;  // ../RTL/cache/l1_ionly.v(23)
  input [7:0] host_wdata;  // ../RTL/cache/l1_ionly.v(29)
  input line_write;  // ../RTL/cache/l1_ionly.v(46)
  input read;  // ../RTL/cache/l1_ionly.v(21)
  input rst;  // ../RTL/cache/l1_ionly.v(18)
  input write;  // ../RTL/cache/l1_ionly.v(22)
  output [23:0] bus_pa;  // ../RTL/cache/l1_ionly.v(42)
  output [7:0] bus_wdata;  // ../RTL/cache/l1_ionly.v(43)
  output cache_data_ready;  // ../RTL/cache/l1_ionly.v(36)
  output [7:0] host_rdata;  // ../RTL/cache/l1_ionly.v(30)
  output ins_acc_fault;  // ../RTL/cache/l1_ionly.v(35)
  output [15:0] instr_read;  // ../RTL/cache/l1_ionly.v(31)
  output load_acc_fault;  // ../RTL/cache/l1_ionly.v(33)
  output read_line_req;  // ../RTL/cache/l1_ionly.v(41)
  output read_req;  // ../RTL/cache/l1_ionly.v(40)
  output store_acc_fault;  // ../RTL/cache/l1_ionly.v(34)
  output uncache_data_ready;  // ../RTL/cache/l1_ionly.v(37)
  output write_through_req;  // ../RTL/cache/l1_ionly.v(39)

  parameter ADDR_WIDTH = 24;
  parameter ASYNC_BUS_ENABLE = 0;
  parameter CACHE_DEPTH = 2048;
  parameter DATA_WIDTH = 8;
  parameter ENTRY_NUM = 16;
  parameter INSTR_WIDTH = 16;
  // localparam CADR_WIDTH = 11;
  // localparam ENTRYSEL_WIDTH = 4;
  // localparam LINE_SIZE = 128;
  // localparam LINE_WID = 7;
  // localparam TAG_WID = 13;
  // localparam access_fault = 4'b0111;
  // localparam read_line = 4'b0001;
  // localparam read_singal = 4'b0010;
  // localparam stb = 4'b0000;
  // localparam write_singal = 4'b0011;
  wire [3:0] main_state;  // ../RTL/cache/l1_ionly.v(63)
  wire [3:0] \tag_manager/al_ram_entry_tag_c0_di ;
  wire [3:0] \tag_manager/al_ram_entry_tag_c0_waddr ;
  wire [3:0] \tag_manager/al_ram_entry_tag_c1_di ;
  wire [3:0] \tag_manager/al_ram_entry_tag_c1_waddr ;
  wire [3:0] \tag_manager/al_ram_entry_tag_c2_di ;
  wire [3:0] \tag_manager/al_ram_entry_tag_c2_waddr ;
  wire [3:0] \tag_manager/al_ram_entry_tag_c3_di ;
  wire [3:0] \tag_manager/al_ram_entry_tag_c3_waddr ;
  wire [15:0] \tag_manager/line_valid ;  // ../RTL/cache/tag_arbiter_dm.v(27)
  wire  \tag_manager/mux0/B1_0 ;  // ../RTL/cache/tag_arbiter_dm.v(32)
  wire  \tag_manager/mux0/B1_1 ;  // ../RTL/cache/tag_arbiter_dm.v(32)
  wire  \tag_manager/mux0/B1_2 ;  // ../RTL/cache/tag_arbiter_dm.v(32)
  wire  \tag_manager/mux0/B1_3 ;  // ../RTL/cache/tag_arbiter_dm.v(32)
  wire [13:0] \tag_manager/n3 ;
  wire [15:0] \tag_manager/n41 ;
  wire _al_u100_o;
  wire _al_u102_o;
  wire _al_u103_o;
  wire _al_u105_o;
  wire _al_u106_o;
  wire _al_u108_o;
  wire _al_u109_o;
  wire _al_u111_o;
  wire _al_u112_o;
  wire _al_u114_o;
  wire _al_u115_o;
  wire _al_u117_o;
  wire _al_u118_o;
  wire _al_u120_o;
  wire _al_u121_o;
  wire _al_u123_o;
  wire _al_u124_o;
  wire _al_u125_o;
  wire _al_u127_o;
  wire _al_u128_o;
  wire _al_u45_o;
  wire _al_u46_o;
  wire _al_u48_o;
  wire _al_u49_o;
  wire _al_u50_o;
  wire _al_u52_o;
  wire _al_u53_o;
  wire _al_u54_o;
  wire _al_u55_o;
  wire _al_u57_o;
  wire _al_u58_o;
  wire _al_u60_o;
  wire _al_u61_o;
  wire _al_u62_o;
  wire _al_u63_o;
  wire _al_u64_o;
  wire _al_u65_o;
  wire _al_u66_o;
  wire _al_u67_o;
  wire _al_u68_o;
  wire _al_u71_o;
  wire _al_u73_o;
  wire _al_u74_o;
  wire _al_u76_o;
  wire _al_u77_o;
  wire _al_u78_o;
  wire _al_u80_o;
  wire _al_u81_o;
  wire _al_u83_o;
  wire _al_u84_o;
  wire _al_u85_o;
  wire _al_u87_o;
  wire _al_u88_o;
  wire _al_u90_o;
  wire _al_u91_o;
  wire _al_u93_o;
  wire _al_u94_o;
  wire _al_u96_o;
  wire _al_u97_o;
  wire _al_u99_o;
  wire cachemem_we_lutinv;  // ../RTL/cache/l1_ionly.v(78)
  wire \l1_ram/n0 ;
  wire \l1_ram/n1 ;
  wire mux4_b0_sel_is_0_o;
  wire sel0_b0_var_o;
  wire sel0_b1_var_o;
  wire sel0_b2_var_o;
  wire \tag_manager/al_ram_entry_tag_c0_mode ;
  wire \tag_manager/al_ram_entry_tag_c0_wclk ;
  wire \tag_manager/al_ram_entry_tag_c0_we ;
  wire \tag_manager/al_ram_entry_tag_c1_mode ;
  wire \tag_manager/al_ram_entry_tag_c1_wclk ;
  wire \tag_manager/al_ram_entry_tag_c1_we ;
  wire \tag_manager/al_ram_entry_tag_c2_mode ;
  wire \tag_manager/al_ram_entry_tag_c2_wclk ;
  wire \tag_manager/al_ram_entry_tag_c2_we ;
  wire \tag_manager/al_ram_entry_tag_c3_mode ;
  wire \tag_manager/al_ram_entry_tag_c3_wclk ;
  wire \tag_manager/al_ram_entry_tag_c3_we ;
  wire \tag_manager/entry_hit ;  // ../RTL/cache/tag_arbiter_dm.v(29)
  wire \tag_manager/n23 ;
  wire \tag_manager/n4_lutinv ;

  assign host_rdata[7] = bus_rdata[7];
  assign host_rdata[6] = bus_rdata[6];
  assign host_rdata[5] = bus_rdata[5];
  assign host_rdata[4] = bus_rdata[4];
  assign host_rdata[3] = bus_rdata[3];
  assign host_rdata[2] = bus_rdata[2];
  assign host_rdata[1] = bus_rdata[1];
  assign host_rdata[0] = bus_rdata[0];
  assign bus_wdata[7] = host_wdata[7];
  assign bus_wdata[6] = host_wdata[6];
  assign bus_wdata[5] = host_wdata[5];
  assign bus_wdata[4] = host_wdata[4];
  assign bus_wdata[3] = host_wdata[3];
  assign bus_wdata[2] = host_wdata[2];
  assign bus_wdata[1] = host_wdata[1];
  assign bus_wdata[0] = host_wdata[0];
  assign cache_data_ready = \tag_manager/entry_hit ;
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u100 (
    .a(_al_u48_o),
    .b(_al_u54_o),
    .c(_al_u71_o),
    .o(_al_u100_o));
  AL_MAP_LUT5 #(
    .EQN("~(~E*~(D*~(A*~(C*B))))"),
    .INIT(32'hffffd500))
    _al_u101 (
    .a(\tag_manager/n4_lutinv ),
    .b(_al_u53_o),
    .c(_al_u60_o),
    .d(_al_u100_o),
    .e(_al_u99_o),
    .o(\tag_manager/n41 [1]));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u102 (
    .a(_al_u52_o),
    .b(_al_u57_o),
    .c(_al_u71_o),
    .o(_al_u102_o));
  AL_MAP_LUT4 #(
    .EQN("(D*~(C*B*A))"),
    .INIT(16'h7f00))
    _al_u103 (
    .a(_al_u52_o),
    .b(_al_u57_o),
    .c(L1_clear),
    .d(\tag_manager/line_valid [15]),
    .o(_al_u103_o));
  AL_MAP_LUT5 #(
    .EQN("~(~E*~(D*~(A*~(C*B))))"),
    .INIT(32'hffffd500))
    _al_u104 (
    .a(\tag_manager/n4_lutinv ),
    .b(_al_u53_o),
    .c(_al_u60_o),
    .d(_al_u102_o),
    .e(_al_u103_o),
    .o(\tag_manager/n41 [15]));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u105 (
    .a(_al_u57_o),
    .b(_al_u71_o),
    .c(_al_u83_o),
    .o(_al_u105_o));
  AL_MAP_LUT4 #(
    .EQN("(D*~(C*B*A))"),
    .INIT(16'h7f00))
    _al_u106 (
    .a(_al_u57_o),
    .b(_al_u83_o),
    .c(L1_clear),
    .d(\tag_manager/line_valid [14]),
    .o(_al_u106_o));
  AL_MAP_LUT5 #(
    .EQN("~(~E*~(D*~(A*~(C*B))))"),
    .INIT(32'hffffd500))
    _al_u107 (
    .a(\tag_manager/n4_lutinv ),
    .b(_al_u53_o),
    .c(_al_u60_o),
    .d(_al_u105_o),
    .e(_al_u106_o),
    .o(\tag_manager/n41 [14]));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u108 (
    .a(_al_u48_o),
    .b(_al_u57_o),
    .c(_al_u71_o),
    .o(_al_u108_o));
  AL_MAP_LUT4 #(
    .EQN("(D*~(C*B*A))"),
    .INIT(16'h7f00))
    _al_u109 (
    .a(_al_u48_o),
    .b(_al_u57_o),
    .c(L1_clear),
    .d(\tag_manager/line_valid [13]),
    .o(_al_u109_o));
  AL_MAP_LUT5 #(
    .EQN("~(~E*~(D*~(A*~(C*B))))"),
    .INIT(32'hffffd500))
    _al_u110 (
    .a(\tag_manager/n4_lutinv ),
    .b(_al_u53_o),
    .c(_al_u60_o),
    .d(_al_u108_o),
    .e(_al_u109_o),
    .o(\tag_manager/n41 [13]));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u111 (
    .a(_al_u57_o),
    .b(_al_u71_o),
    .c(_al_u76_o),
    .o(_al_u111_o));
  AL_MAP_LUT4 #(
    .EQN("(D*~(C*B*A))"),
    .INIT(16'h7f00))
    _al_u112 (
    .a(_al_u57_o),
    .b(_al_u76_o),
    .c(L1_clear),
    .d(\tag_manager/line_valid [12]),
    .o(_al_u112_o));
  AL_MAP_LUT5 #(
    .EQN("~(~E*~(D*~(A*~(C*B))))"),
    .INIT(32'hffffd500))
    _al_u113 (
    .a(\tag_manager/n4_lutinv ),
    .b(_al_u53_o),
    .c(_al_u60_o),
    .d(_al_u111_o),
    .e(_al_u112_o),
    .o(\tag_manager/n41 [12]));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u114 (
    .a(_al_u49_o),
    .b(_al_u52_o),
    .c(_al_u71_o),
    .o(_al_u114_o));
  AL_MAP_LUT4 #(
    .EQN("(D*~(C*B*A))"),
    .INIT(16'h7f00))
    _al_u115 (
    .a(_al_u49_o),
    .b(_al_u52_o),
    .c(L1_clear),
    .d(\tag_manager/line_valid [11]),
    .o(_al_u115_o));
  AL_MAP_LUT5 #(
    .EQN("~(~E*~(D*~(A*~(C*B))))"),
    .INIT(32'hffffd500))
    _al_u116 (
    .a(\tag_manager/n4_lutinv ),
    .b(_al_u53_o),
    .c(_al_u60_o),
    .d(_al_u114_o),
    .e(_al_u115_o),
    .o(\tag_manager/n41 [11]));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u117 (
    .a(_al_u49_o),
    .b(_al_u71_o),
    .c(_al_u83_o),
    .o(_al_u117_o));
  AL_MAP_LUT4 #(
    .EQN("(D*~(C*B*A))"),
    .INIT(16'h7f00))
    _al_u118 (
    .a(_al_u49_o),
    .b(_al_u83_o),
    .c(L1_clear),
    .d(\tag_manager/line_valid [10]),
    .o(_al_u118_o));
  AL_MAP_LUT5 #(
    .EQN("~(~E*~(D*~(A*~(C*B))))"),
    .INIT(32'hffffd500))
    _al_u119 (
    .a(\tag_manager/n4_lutinv ),
    .b(_al_u53_o),
    .c(_al_u60_o),
    .d(_al_u117_o),
    .e(_al_u118_o),
    .o(\tag_manager/n41 [10]));
  AL_MAP_LUT4 #(
    .EQN("(D*~(C*B*A))"),
    .INIT(16'h7f00))
    _al_u120 (
    .a(_al_u54_o),
    .b(_al_u76_o),
    .c(L1_clear),
    .d(\tag_manager/line_valid [0]),
    .o(_al_u120_o));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u121 (
    .a(_al_u54_o),
    .b(_al_u71_o),
    .c(_al_u76_o),
    .o(_al_u121_o));
  AL_MAP_LUT5 #(
    .EQN("~(~E*~(D*~(A*~(C*B))))"),
    .INIT(32'hffffd500))
    _al_u122 (
    .a(\tag_manager/n4_lutinv ),
    .b(_al_u53_o),
    .c(_al_u60_o),
    .d(_al_u121_o),
    .e(_al_u120_o),
    .o(\tag_manager/n41 [0]));
  AL_MAP_LUT5 #(
    .EQN("(~E*~(~A*(C*~(B)*~(D)+C*B*~(D)+~(C)*B*D+C*B*D)))"),
    .INIT(32'h0000bbaf))
    _al_u123 (
    .a(bus_error),
    .b(bus_trans_finish),
    .c(main_state[0]),
    .d(main_state[1]),
    .e(main_state[2]),
    .o(_al_u123_o));
  AL_MAP_LUT2 #(
    .EQN("(~B*~A)"),
    .INIT(4'h1))
    _al_u124 (
    .a(main_state[0]),
    .b(main_state[1]),
    .o(_al_u124_o));
  AL_MAP_LUT5 #(
    .EQN("(C*B*A*~(~E*~D))"),
    .INIT(32'h80808000))
    _al_u125 (
    .a(_al_u68_o),
    .b(_al_u62_o),
    .c(_al_u64_o),
    .d(read),
    .e(write),
    .o(_al_u125_o));
  AL_MAP_LUT5 #(
    .EQN("(D*~(E*~(A*~(C*B))))"),
    .INIT(32'h2a00ff00))
    _al_u126 (
    .a(_al_u125_o),
    .b(_al_u53_o),
    .c(_al_u60_o),
    .d(_al_u123_o),
    .e(_al_u124_o),
    .o(sel0_b1_var_o));
  AL_MAP_LUT5 #(
    .EQN("(~E*~(~A*(D*~(B)*~(C)+D*B*~(C)+~(D)*B*C+D*B*C)))"),
    .INIT(32'h0000babf))
    _al_u127 (
    .a(bus_error),
    .b(bus_trans_finish),
    .c(main_state[0]),
    .d(main_state[1]),
    .e(main_state[2]),
    .o(_al_u127_o));
  AL_MAP_LUT3 #(
    .EQN("(A*~(C*~B))"),
    .INIT(8'h8a))
    _al_u128 (
    .a(_al_u124_o),
    .b(read),
    .c(write),
    .o(_al_u128_o));
  AL_MAP_LUT5 #(
    .EQN("(E*~(D*A*~(C*B)))"),
    .INIT(32'hd5ff0000))
    _al_u129 (
    .a(\tag_manager/n4_lutinv ),
    .b(_al_u53_o),
    .c(_al_u60_o),
    .d(_al_u128_o),
    .e(_al_u127_o),
    .o(sel0_b0_var_o));
  AL_MAP_LUT3 #(
    .EQN("(~C*B*~A)"),
    .INIT(8'h04))
    _al_u130 (
    .a(_al_u124_o),
    .b(bus_error),
    .c(main_state[2]),
    .o(sel0_b2_var_o));
  AL_MAP_LUT1 #(
    .EQN("(~A)"),
    .INIT(2'h1))
    _al_u131 (
    .a(rst),
    .o(mux4_b0_sel_is_0_o));
  AL_MAP_LUT3 #(
    .EQN("(~C*~B*A)"),
    .INIT(8'h02))
    _al_u14 (
    .a(main_state[0]),
    .b(main_state[1]),
    .c(main_state[2]),
    .o(read_line_req));
  AL_MAP_LUT3 #(
    .EQN("(~C*B*A)"),
    .INIT(8'h08))
    _al_u15 (
    .a(main_state[0]),
    .b(main_state[1]),
    .c(main_state[2]),
    .o(write_through_req));
  AL_MAP_LUT3 #(
    .EQN("(~C*B*~A)"),
    .INIT(8'h04))
    _al_u16 (
    .a(main_state[0]),
    .b(main_state[1]),
    .c(main_state[2]),
    .o(read_req));
  AL_MAP_LUT2 #(
    .EQN("(B*A)"),
    .INIT(4'h8))
    _al_u17 (
    .a(read_line_req),
    .b(line_write),
    .o(cachemem_we_lutinv));
  AL_MAP_LUT2 #(
    .EQN("(B*A)"),
    .INIT(4'h8))
    _al_u18 (
    .a(cachemem_we_lutinv),
    .b(addr_count[0]),
    .o(\l1_ram/n1 ));
  AL_MAP_LUT2 #(
    .EQN("(~B*A)"),
    .INIT(4'h2))
    _al_u19 (
    .a(cachemem_we_lutinv),
    .b(addr_count[0]),
    .o(\l1_ram/n0 ));
  AL_MAP_LUT3 #(
    .EQN("~(~B*~(C*A))"),
    .INIT(8'hec))
    _al_u20 (
    .a(write_through_req),
    .b(read_req),
    .c(bus_trans_finish),
    .o(uncache_data_ready));
  AL_MAP_LUT4 #(
    .EQN("(B*~(A)*~((~D*C))+B*A*~((~D*C))+~(B)*A*(~D*C)+B*A*(~D*C))"),
    .INIT(16'hccac))
    _al_u21 (
    .a(addr_pa_d[9]),
    .b(addr_pa_i[9]),
    .c(main_state[1]),
    .d(main_state[2]),
    .o(bus_pa[9]));
  AL_MAP_LUT4 #(
    .EQN("(B*~(A)*~((~D*C))+B*A*~((~D*C))+~(B)*A*(~D*C)+B*A*(~D*C))"),
    .INIT(16'hccac))
    _al_u22 (
    .a(addr_pa_d[8]),
    .b(addr_pa_i[8]),
    .c(main_state[1]),
    .d(main_state[2]),
    .o(bus_pa[8]));
  AL_MAP_LUT4 #(
    .EQN("(B*~(A)*~((~D*C))+B*A*~((~D*C))+~(B)*A*(~D*C)+B*A*(~D*C))"),
    .INIT(16'hccac))
    _al_u23 (
    .a(addr_pa_d[7]),
    .b(addr_pa_i[7]),
    .c(main_state[1]),
    .d(main_state[2]),
    .o(bus_pa[7]));
  AL_MAP_LUT4 #(
    .EQN("(B*~(A)*~((~D*C))+B*A*~((~D*C))+~(B)*A*(~D*C)+B*A*(~D*C))"),
    .INIT(16'hccac))
    _al_u24 (
    .a(addr_pa_d[6]),
    .b(addr_pa_i[6]),
    .c(main_state[1]),
    .d(main_state[2]),
    .o(bus_pa[6]));
  AL_MAP_LUT4 #(
    .EQN("(B*~(A)*~((~D*C))+B*A*~((~D*C))+~(B)*A*(~D*C)+B*A*(~D*C))"),
    .INIT(16'hccac))
    _al_u25 (
    .a(addr_pa_d[5]),
    .b(addr_pa_i[5]),
    .c(main_state[1]),
    .d(main_state[2]),
    .o(bus_pa[5]));
  AL_MAP_LUT4 #(
    .EQN("(B*~(A)*~((~D*C))+B*A*~((~D*C))+~(B)*A*(~D*C)+B*A*(~D*C))"),
    .INIT(16'hccac))
    _al_u26 (
    .a(addr_pa_d[4]),
    .b(addr_pa_i[4]),
    .c(main_state[1]),
    .d(main_state[2]),
    .o(bus_pa[4]));
  AL_MAP_LUT4 #(
    .EQN("(B*~(A)*~((~D*C))+B*A*~((~D*C))+~(B)*A*(~D*C)+B*A*(~D*C))"),
    .INIT(16'hccac))
    _al_u27 (
    .a(addr_pa_d[3]),
    .b(addr_pa_i[3]),
    .c(main_state[1]),
    .d(main_state[2]),
    .o(bus_pa[3]));
  AL_MAP_LUT4 #(
    .EQN("(B*~(A)*~((~D*C))+B*A*~((~D*C))+~(B)*A*(~D*C)+B*A*(~D*C))"),
    .INIT(16'hccac))
    _al_u28 (
    .a(addr_pa_d[23]),
    .b(addr_pa_i[23]),
    .c(main_state[1]),
    .d(main_state[2]),
    .o(bus_pa[23]));
  AL_MAP_LUT4 #(
    .EQN("(B*~(A)*~((~D*C))+B*A*~((~D*C))+~(B)*A*(~D*C)+B*A*(~D*C))"),
    .INIT(16'hccac))
    _al_u29 (
    .a(addr_pa_d[22]),
    .b(addr_pa_i[22]),
    .c(main_state[1]),
    .d(main_state[2]),
    .o(bus_pa[22]));
  AL_MAP_LUT4 #(
    .EQN("(B*~(A)*~((~D*C))+B*A*~((~D*C))+~(B)*A*(~D*C)+B*A*(~D*C))"),
    .INIT(16'hccac))
    _al_u30 (
    .a(addr_pa_d[21]),
    .b(addr_pa_i[21]),
    .c(main_state[1]),
    .d(main_state[2]),
    .o(bus_pa[21]));
  AL_MAP_LUT4 #(
    .EQN("(B*~(A)*~((~D*C))+B*A*~((~D*C))+~(B)*A*(~D*C)+B*A*(~D*C))"),
    .INIT(16'hccac))
    _al_u31 (
    .a(addr_pa_d[20]),
    .b(addr_pa_i[20]),
    .c(main_state[1]),
    .d(main_state[2]),
    .o(bus_pa[20]));
  AL_MAP_LUT4 #(
    .EQN("(B*~(A)*~((~D*C))+B*A*~((~D*C))+~(B)*A*(~D*C)+B*A*(~D*C))"),
    .INIT(16'hccac))
    _al_u32 (
    .a(addr_pa_d[2]),
    .b(addr_pa_i[2]),
    .c(main_state[1]),
    .d(main_state[2]),
    .o(bus_pa[2]));
  AL_MAP_LUT4 #(
    .EQN("(B*~(A)*~((~D*C))+B*A*~((~D*C))+~(B)*A*(~D*C)+B*A*(~D*C))"),
    .INIT(16'hccac))
    _al_u33 (
    .a(addr_pa_d[19]),
    .b(addr_pa_i[19]),
    .c(main_state[1]),
    .d(main_state[2]),
    .o(bus_pa[19]));
  AL_MAP_LUT4 #(
    .EQN("(B*~(A)*~((~D*C))+B*A*~((~D*C))+~(B)*A*(~D*C)+B*A*(~D*C))"),
    .INIT(16'hccac))
    _al_u34 (
    .a(addr_pa_d[18]),
    .b(addr_pa_i[18]),
    .c(main_state[1]),
    .d(main_state[2]),
    .o(bus_pa[18]));
  AL_MAP_LUT4 #(
    .EQN("(B*~(A)*~((~D*C))+B*A*~((~D*C))+~(B)*A*(~D*C)+B*A*(~D*C))"),
    .INIT(16'hccac))
    _al_u35 (
    .a(addr_pa_d[17]),
    .b(addr_pa_i[17]),
    .c(main_state[1]),
    .d(main_state[2]),
    .o(bus_pa[17]));
  AL_MAP_LUT4 #(
    .EQN("(B*~(A)*~((~D*C))+B*A*~((~D*C))+~(B)*A*(~D*C)+B*A*(~D*C))"),
    .INIT(16'hccac))
    _al_u36 (
    .a(addr_pa_d[16]),
    .b(addr_pa_i[16]),
    .c(main_state[1]),
    .d(main_state[2]),
    .o(bus_pa[16]));
  AL_MAP_LUT4 #(
    .EQN("(B*~(A)*~((~D*C))+B*A*~((~D*C))+~(B)*A*(~D*C)+B*A*(~D*C))"),
    .INIT(16'hccac))
    _al_u37 (
    .a(addr_pa_d[15]),
    .b(addr_pa_i[15]),
    .c(main_state[1]),
    .d(main_state[2]),
    .o(bus_pa[15]));
  AL_MAP_LUT4 #(
    .EQN("(B*~(A)*~((~D*C))+B*A*~((~D*C))+~(B)*A*(~D*C)+B*A*(~D*C))"),
    .INIT(16'hccac))
    _al_u38 (
    .a(addr_pa_d[14]),
    .b(addr_pa_i[14]),
    .c(main_state[1]),
    .d(main_state[2]),
    .o(bus_pa[14]));
  AL_MAP_LUT4 #(
    .EQN("(B*~(A)*~((~D*C))+B*A*~((~D*C))+~(B)*A*(~D*C)+B*A*(~D*C))"),
    .INIT(16'hccac))
    _al_u39 (
    .a(addr_pa_d[13]),
    .b(addr_pa_i[13]),
    .c(main_state[1]),
    .d(main_state[2]),
    .o(bus_pa[13]));
  AL_MAP_LUT4 #(
    .EQN("(B*~(A)*~((~D*C))+B*A*~((~D*C))+~(B)*A*(~D*C)+B*A*(~D*C))"),
    .INIT(16'hccac))
    _al_u40 (
    .a(addr_pa_d[12]),
    .b(addr_pa_i[12]),
    .c(main_state[1]),
    .d(main_state[2]),
    .o(bus_pa[12]));
  AL_MAP_LUT4 #(
    .EQN("(B*~(A)*~((~D*C))+B*A*~((~D*C))+~(B)*A*(~D*C)+B*A*(~D*C))"),
    .INIT(16'hccac))
    _al_u41 (
    .a(addr_pa_d[11]),
    .b(addr_pa_i[11]),
    .c(main_state[1]),
    .d(main_state[2]),
    .o(bus_pa[11]));
  AL_MAP_LUT4 #(
    .EQN("(B*~(A)*~((~D*C))+B*A*~((~D*C))+~(B)*A*(~D*C)+B*A*(~D*C))"),
    .INIT(16'hccac))
    _al_u42 (
    .a(addr_pa_d[10]),
    .b(addr_pa_i[10]),
    .c(main_state[1]),
    .d(main_state[2]),
    .o(bus_pa[10]));
  AL_MAP_LUT4 #(
    .EQN("(B*~(A)*~((~D*C))+B*A*~((~D*C))+~(B)*A*(~D*C)+B*A*(~D*C))"),
    .INIT(16'hccac))
    _al_u43 (
    .a(addr_pa_d[1]),
    .b(addr_pa_i[1]),
    .c(main_state[1]),
    .d(main_state[2]),
    .o(bus_pa[1]));
  AL_MAP_LUT3 #(
    .EQN("(~C*B*A)"),
    .INIT(8'h08))
    _al_u44 (
    .a(addr_pa_d[0]),
    .b(main_state[1]),
    .c(main_state[2]),
    .o(bus_pa[0]));
  AL_MAP_LUT2 #(
    .EQN("(B*~A)"),
    .INIT(4'h4))
    _al_u45 (
    .a(addr_pa_i[10]),
    .b(addr_pa_i[9]),
    .o(_al_u45_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)+~(A)*B*~(C)*~(D)+~(A)*~(B)*C*~(D)+~(A)*B*C*~(D)+~(A)*~(B)*~(C)*D+A*~(B)*~(C)*D+~(A)*B*~(C)*D+A*~(B)*C*D)"),
    .INIT(16'h2755))
    _al_u46 (
    .a(addr_pa_i[7]),
    .b(\tag_manager/line_valid [7]),
    .c(\tag_manager/line_valid [6]),
    .d(addr_pa_i[8]),
    .o(_al_u46_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*B*~(C)*~(D)+A*B*~(C)*~(D)+A*~(B)*C*~(D)+A*B*C*~(D)+~(A)*~(B)*~(C)*D+A*~(B)*~(C)*D+~(A)*B*~(C)*D+A*B*~(C)*D)"),
    .INIT(16'h0fac))
    _al_u47 (
    .a(\tag_manager/line_valid [4]),
    .b(\tag_manager/line_valid [5]),
    .c(_al_u46_o),
    .d(addr_pa_i[8]),
    .o(\tag_manager/mux0/B1_1 ));
  AL_MAP_LUT2 #(
    .EQN("(B*~A)"),
    .INIT(4'h4))
    _al_u48 (
    .a(addr_pa_i[8]),
    .b(addr_pa_i[7]),
    .o(_al_u48_o));
  AL_MAP_LUT2 #(
    .EQN("(~B*A)"),
    .INIT(4'h2))
    _al_u49 (
    .a(addr_pa_i[10]),
    .b(addr_pa_i[9]),
    .o(_al_u49_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)+A*~(B)*~(C)*~(D)+~(A)*B*~(C)*~(D)+A*~(B)*C*~(D)+~(A)*~(B)*~(C)*D+~(A)*B*~(C)*D+~(A)*~(B)*C*D+~(A)*B*C*D)"),
    .INIT(16'h5527))
    _al_u50 (
    .a(addr_pa_i[7]),
    .b(\tag_manager/line_valid [9]),
    .c(\tag_manager/line_valid [8]),
    .d(addr_pa_i[8]),
    .o(_al_u50_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)+A*~(B)*~(C)*~(D)+~(A)*B*~(C)*~(D)+A*B*~(C)*~(D)+~(A)*B*~(C)*D+A*B*~(C)*D+A*~(B)*C*D+A*B*C*D)"),
    .INIT(16'hac0f))
    _al_u51 (
    .a(\tag_manager/line_valid [10]),
    .b(\tag_manager/line_valid [11]),
    .c(_al_u50_o),
    .d(addr_pa_i[8]),
    .o(\tag_manager/mux0/B1_2 ));
  AL_MAP_LUT2 #(
    .EQN("(B*A)"),
    .INIT(4'h8))
    _al_u52 (
    .a(addr_pa_i[8]),
    .b(addr_pa_i[7]),
    .o(_al_u52_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)+A*~(B)*~(C)*~(D)+~(A)*B*~(C)*~(D)+A*B*~(C)*~(D)+~(A)*~(B)*C*~(D)+A*~(B)*C*~(D)+~(A)*~(B)*~(C)*D+~(A)*B*~(C)*D+~(A)*~(B)*C*D+A*~(B)*C*D+~(A)*B*C*D+A*B*C*D)"),
    .INIT(16'hf53f))
    _al_u53 (
    .a(\tag_manager/mux0/B1_1 ),
    .b(\tag_manager/mux0/B1_2 ),
    .c(addr_pa_i[10]),
    .d(addr_pa_i[9]),
    .o(_al_u53_o));
  AL_MAP_LUT2 #(
    .EQN("(~B*~A)"),
    .INIT(4'h1))
    _al_u54 (
    .a(addr_pa_i[10]),
    .b(addr_pa_i[9]),
    .o(_al_u54_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)+~(A)*B*~(C)*~(D)+~(A)*~(B)*C*~(D)+~(A)*B*C*~(D)+~(A)*~(B)*~(C)*D+A*~(B)*~(C)*D+~(A)*B*~(C)*D+A*~(B)*C*D)"),
    .INIT(16'h2755))
    _al_u55 (
    .a(addr_pa_i[7]),
    .b(\tag_manager/line_valid [3]),
    .c(\tag_manager/line_valid [2]),
    .d(addr_pa_i[8]),
    .o(_al_u55_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*B*~(C)*~(D)+A*B*~(C)*~(D)+A*~(B)*C*~(D)+A*B*C*~(D)+~(A)*~(B)*~(C)*D+A*~(B)*~(C)*D+~(A)*B*~(C)*D+A*B*~(C)*D)"),
    .INIT(16'h0fac))
    _al_u56 (
    .a(\tag_manager/line_valid [0]),
    .b(\tag_manager/line_valid [1]),
    .c(_al_u55_o),
    .d(addr_pa_i[8]),
    .o(\tag_manager/mux0/B1_0 ));
  AL_MAP_LUT2 #(
    .EQN("(B*A)"),
    .INIT(4'h8))
    _al_u57 (
    .a(addr_pa_i[10]),
    .b(addr_pa_i[9]),
    .o(_al_u57_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)+~(A)*B*~(C)*~(D)+~(A)*~(B)*C*~(D)+~(A)*B*C*~(D)+~(A)*~(B)*~(C)*D+A*~(B)*~(C)*D+~(A)*B*~(C)*D+A*~(B)*C*D)"),
    .INIT(16'h2755))
    _al_u58 (
    .a(addr_pa_i[7]),
    .b(\tag_manager/line_valid [15]),
    .c(\tag_manager/line_valid [14]),
    .d(addr_pa_i[8]),
    .o(_al_u58_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*B*~(C)*~(D)+A*B*~(C)*~(D)+A*~(B)*C*~(D)+A*B*C*~(D)+~(A)*~(B)*~(C)*D+A*~(B)*~(C)*D+~(A)*B*~(C)*D+A*B*~(C)*D)"),
    .INIT(16'h0fac))
    _al_u59 (
    .a(\tag_manager/line_valid [12]),
    .b(\tag_manager/line_valid [13]),
    .c(_al_u58_o),
    .d(addr_pa_i[8]),
    .o(\tag_manager/mux0/B1_3 ));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)+~(A)*B*~(C)*~(D)+~(A)*~(B)*C*~(D)+A*~(B)*C*~(D)+~(A)*B*C*~(D)+A*B*C*~(D)+~(A)*~(B)*~(C)*D+A*~(B)*~(C)*D+~(A)*B*~(C)*D+A*B*~(C)*D+~(A)*~(B)*C*D+A*~(B)*C*D)"),
    .INIT(16'h3ff5))
    _al_u60 (
    .a(\tag_manager/mux0/B1_0 ),
    .b(\tag_manager/mux0/B1_3 ),
    .c(addr_pa_i[10]),
    .d(addr_pa_i[9]),
    .o(_al_u60_o));
  AL_MAP_LUT4 #(
    .EQN("(~(D@B)*~(C@A))"),
    .INIT(16'h8421))
    _al_u61 (
    .a(addr_pa_i[22]),
    .b(addr_pa_i[21]),
    .c(\tag_manager/n3 [11]),
    .d(\tag_manager/n3 [10]),
    .o(_al_u61_o));
  AL_MAP_LUT5 #(
    .EQN("(A*~(E@C)*~(D@B))"),
    .INIT(32'h80200802))
    _al_u62 (
    .a(_al_u61_o),
    .b(addr_pa_i[17]),
    .c(addr_pa_i[16]),
    .d(\tag_manager/n3 [6]),
    .e(\tag_manager/n3 [5]),
    .o(_al_u62_o));
  AL_MAP_LUT4 #(
    .EQN("(~(C@B)*~(D@A))"),
    .INIT(16'h8241))
    _al_u63 (
    .a(addr_pa_i[23]),
    .b(addr_pa_i[14]),
    .c(\tag_manager/n3 [3]),
    .d(\tag_manager/n3 [12]),
    .o(_al_u63_o));
  AL_MAP_LUT4 #(
    .EQN("(~D*A*~(C@B))"),
    .INIT(16'h0082))
    _al_u64 (
    .a(_al_u63_o),
    .b(addr_pa_i[15]),
    .c(\tag_manager/n3 [4]),
    .d(\tag_manager/n3 [13]),
    .o(_al_u64_o));
  AL_MAP_LUT4 #(
    .EQN("(~(C@B)*~(D@A))"),
    .INIT(16'h8241))
    _al_u65 (
    .a(addr_pa_i[18]),
    .b(addr_pa_i[11]),
    .c(\tag_manager/n3 [0]),
    .d(\tag_manager/n3 [7]),
    .o(_al_u65_o));
  AL_MAP_LUT4 #(
    .EQN("(~(C@B)*~(D@A))"),
    .INIT(16'h8241))
    _al_u66 (
    .a(addr_pa_i[20]),
    .b(addr_pa_i[13]),
    .c(\tag_manager/n3 [2]),
    .d(\tag_manager/n3 [9]),
    .o(_al_u66_o));
  AL_MAP_LUT4 #(
    .EQN("(~(C@B)*~(D@A))"),
    .INIT(16'h8241))
    _al_u67 (
    .a(addr_pa_i[19]),
    .b(addr_pa_i[12]),
    .c(\tag_manager/n3 [1]),
    .d(\tag_manager/n3 [8]),
    .o(_al_u67_o));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u68 (
    .a(_al_u65_o),
    .b(_al_u66_o),
    .c(_al_u67_o),
    .o(_al_u68_o));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u69 (
    .a(_al_u68_o),
    .b(_al_u62_o),
    .c(_al_u64_o),
    .o(\tag_manager/n4_lutinv ));
  AL_MAP_LUT3 #(
    .EQN("(A*~(C*B))"),
    .INIT(8'h2a))
    _al_u70 (
    .a(\tag_manager/n4_lutinv ),
    .b(_al_u53_o),
    .c(_al_u60_o),
    .o(\tag_manager/entry_hit ));
  AL_MAP_LUT2 #(
    .EQN("(B*~A)"),
    .INIT(4'h4))
    _al_u71 (
    .a(L1_clear),
    .b(bus_trans_finish),
    .o(_al_u71_o));
  AL_MAP_LUT5 #(
    .EQN("(~E*D*~(A*~(C*B)))"),
    .INIT(32'h0000d500))
    _al_u72 (
    .a(\tag_manager/n4_lutinv ),
    .b(_al_u53_o),
    .c(_al_u60_o),
    .d(_al_u71_o),
    .e(rst),
    .o(\tag_manager/n23 ));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u73 (
    .a(_al_u48_o),
    .b(_al_u49_o),
    .c(_al_u71_o),
    .o(_al_u73_o));
  AL_MAP_LUT4 #(
    .EQN("(D*~(C*B*A))"),
    .INIT(16'h7f00))
    _al_u74 (
    .a(_al_u48_o),
    .b(_al_u49_o),
    .c(L1_clear),
    .d(\tag_manager/line_valid [9]),
    .o(_al_u74_o));
  AL_MAP_LUT5 #(
    .EQN("~(~E*~(D*~(A*~(C*B))))"),
    .INIT(32'hffffd500))
    _al_u75 (
    .a(\tag_manager/n4_lutinv ),
    .b(_al_u53_o),
    .c(_al_u60_o),
    .d(_al_u73_o),
    .e(_al_u74_o),
    .o(\tag_manager/n41 [9]));
  AL_MAP_LUT2 #(
    .EQN("(~B*~A)"),
    .INIT(4'h1))
    _al_u76 (
    .a(addr_pa_i[8]),
    .b(addr_pa_i[7]),
    .o(_al_u76_o));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u77 (
    .a(_al_u49_o),
    .b(_al_u71_o),
    .c(_al_u76_o),
    .o(_al_u77_o));
  AL_MAP_LUT4 #(
    .EQN("(D*~(C*B*A))"),
    .INIT(16'h7f00))
    _al_u78 (
    .a(_al_u49_o),
    .b(_al_u76_o),
    .c(L1_clear),
    .d(\tag_manager/line_valid [8]),
    .o(_al_u78_o));
  AL_MAP_LUT5 #(
    .EQN("~(~E*~(D*~(A*~(C*B))))"),
    .INIT(32'hffffd500))
    _al_u79 (
    .a(\tag_manager/n4_lutinv ),
    .b(_al_u53_o),
    .c(_al_u60_o),
    .d(_al_u77_o),
    .e(_al_u78_o),
    .o(\tag_manager/n41 [8]));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u80 (
    .a(_al_u45_o),
    .b(_al_u52_o),
    .c(_al_u71_o),
    .o(_al_u80_o));
  AL_MAP_LUT4 #(
    .EQN("(D*~(C*B*A))"),
    .INIT(16'h7f00))
    _al_u81 (
    .a(_al_u45_o),
    .b(_al_u52_o),
    .c(L1_clear),
    .d(\tag_manager/line_valid [7]),
    .o(_al_u81_o));
  AL_MAP_LUT5 #(
    .EQN("~(~E*~(D*~(A*~(C*B))))"),
    .INIT(32'hffffd500))
    _al_u82 (
    .a(\tag_manager/n4_lutinv ),
    .b(_al_u53_o),
    .c(_al_u60_o),
    .d(_al_u80_o),
    .e(_al_u81_o),
    .o(\tag_manager/n41 [7]));
  AL_MAP_LUT2 #(
    .EQN("(~B*A)"),
    .INIT(4'h2))
    _al_u83 (
    .a(addr_pa_i[8]),
    .b(addr_pa_i[7]),
    .o(_al_u83_o));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u84 (
    .a(_al_u45_o),
    .b(_al_u71_o),
    .c(_al_u83_o),
    .o(_al_u84_o));
  AL_MAP_LUT4 #(
    .EQN("(D*~(C*B*A))"),
    .INIT(16'h7f00))
    _al_u85 (
    .a(_al_u45_o),
    .b(_al_u83_o),
    .c(L1_clear),
    .d(\tag_manager/line_valid [6]),
    .o(_al_u85_o));
  AL_MAP_LUT5 #(
    .EQN("~(~E*~(D*~(A*~(C*B))))"),
    .INIT(32'hffffd500))
    _al_u86 (
    .a(\tag_manager/n4_lutinv ),
    .b(_al_u53_o),
    .c(_al_u60_o),
    .d(_al_u84_o),
    .e(_al_u85_o),
    .o(\tag_manager/n41 [6]));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u87 (
    .a(_al_u45_o),
    .b(_al_u48_o),
    .c(_al_u71_o),
    .o(_al_u87_o));
  AL_MAP_LUT4 #(
    .EQN("(D*~(C*B*A))"),
    .INIT(16'h7f00))
    _al_u88 (
    .a(_al_u45_o),
    .b(_al_u48_o),
    .c(L1_clear),
    .d(\tag_manager/line_valid [5]),
    .o(_al_u88_o));
  AL_MAP_LUT5 #(
    .EQN("~(~E*~(D*~(A*~(C*B))))"),
    .INIT(32'hffffd500))
    _al_u89 (
    .a(\tag_manager/n4_lutinv ),
    .b(_al_u53_o),
    .c(_al_u60_o),
    .d(_al_u87_o),
    .e(_al_u88_o),
    .o(\tag_manager/n41 [5]));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u90 (
    .a(_al_u45_o),
    .b(_al_u71_o),
    .c(_al_u76_o),
    .o(_al_u90_o));
  AL_MAP_LUT4 #(
    .EQN("(D*~(C*B*A))"),
    .INIT(16'h7f00))
    _al_u91 (
    .a(_al_u45_o),
    .b(_al_u76_o),
    .c(L1_clear),
    .d(\tag_manager/line_valid [4]),
    .o(_al_u91_o));
  AL_MAP_LUT5 #(
    .EQN("~(~E*~(D*~(A*~(C*B))))"),
    .INIT(32'hffffd500))
    _al_u92 (
    .a(\tag_manager/n4_lutinv ),
    .b(_al_u53_o),
    .c(_al_u60_o),
    .d(_al_u90_o),
    .e(_al_u91_o),
    .o(\tag_manager/n41 [4]));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u93 (
    .a(_al_u52_o),
    .b(_al_u54_o),
    .c(_al_u71_o),
    .o(_al_u93_o));
  AL_MAP_LUT4 #(
    .EQN("(D*~(C*B*A))"),
    .INIT(16'h7f00))
    _al_u94 (
    .a(_al_u52_o),
    .b(_al_u54_o),
    .c(L1_clear),
    .d(\tag_manager/line_valid [3]),
    .o(_al_u94_o));
  AL_MAP_LUT5 #(
    .EQN("~(~E*~(D*~(A*~(C*B))))"),
    .INIT(32'hffffd500))
    _al_u95 (
    .a(\tag_manager/n4_lutinv ),
    .b(_al_u53_o),
    .c(_al_u60_o),
    .d(_al_u93_o),
    .e(_al_u94_o),
    .o(\tag_manager/n41 [3]));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u96 (
    .a(_al_u54_o),
    .b(_al_u71_o),
    .c(_al_u83_o),
    .o(_al_u96_o));
  AL_MAP_LUT4 #(
    .EQN("(D*~(C*B*A))"),
    .INIT(16'h7f00))
    _al_u97 (
    .a(_al_u54_o),
    .b(_al_u83_o),
    .c(L1_clear),
    .d(\tag_manager/line_valid [2]),
    .o(_al_u97_o));
  AL_MAP_LUT5 #(
    .EQN("~(~E*~(D*~(A*~(C*B))))"),
    .INIT(32'hffffd500))
    _al_u98 (
    .a(\tag_manager/n4_lutinv ),
    .b(_al_u53_o),
    .c(_al_u60_o),
    .d(_al_u96_o),
    .e(_al_u97_o),
    .o(\tag_manager/n41 [2]));
  AL_MAP_LUT4 #(
    .EQN("(D*~(C*B*A))"),
    .INIT(16'h7f00))
    _al_u99 (
    .a(_al_u48_o),
    .b(_al_u54_o),
    .c(L1_clear),
    .d(\tag_manager/line_valid [1]),
    .o(_al_u99_o));
  // address_offset=0;data_offset=0;depth=2048;width=4;num_section=1;width_per_section=4;section_size=8;working_depth=2048;working_width=4;mode_ecc=0;address_step=1;bytes_in_per_section=1;
  AL_PHY_BRAM #(
    //.RID("0x0004"),
    //.WID("0x0004"),
    .CEAMUX("1"),
    .CEBMUX("INV"),
    .CSA0("1"),
    .CSA1("1"),
    .CSA2("1"),
    .CSB0("1"),
    .CSB1("1"),
    .CSB2("1"),
    .DATA_WIDTH_A("4"),
    .DATA_WIDTH_B("4"),
    .GSR("DISABLE"),
    .MODE("DP8K"),
    .OCEAMUX("1"),
    .OCEBMUX("1"),
    .READBACK("OFF"),
    .REGMODE_A("NOREG"),
    .REGMODE_B("NOREG"),
    .RESETMODE("ASYNC"),
    .RSTAMUX("0"),
    .RSTBMUX("0"),
    .WEBMUX("0"),
    .WRITEMODE_A("NORMAL"),
    .WRITEMODE_B("NORMAL"))
    \l1_ram/cacheblk[0]$cacheunit/ram_memcell0_2048x8_sub_000000_000  (
    .addra({addr_pa_i[10:7],1'b0,addr_count[6:1],2'b11}),
    .addrb({addr_pa_i[10:7],addr_pa_i[7:1],2'b11}),
    .ceb(cwait),
    .clka(clk),
    .clkb(clk),
    .dia({open_n7,open_n8,open_n9,open_n10,open_n11,host_rdata[3:0]}),
    .wea(\l1_ram/n0 ),
    .dob({open_n35,open_n36,open_n37,open_n38,open_n39,instr_read[3:0]}));
  // address_offset=0;data_offset=4;depth=2048;width=4;num_section=1;width_per_section=4;section_size=8;working_depth=2048;working_width=4;mode_ecc=0;address_step=1;bytes_in_per_section=1;
  AL_PHY_BRAM #(
    //.RID("0x0005"),
    //.WID("0x0005"),
    .CEAMUX("1"),
    .CEBMUX("INV"),
    .CSA0("1"),
    .CSA1("1"),
    .CSA2("1"),
    .CSB0("1"),
    .CSB1("1"),
    .CSB2("1"),
    .DATA_WIDTH_A("4"),
    .DATA_WIDTH_B("4"),
    .GSR("DISABLE"),
    .MODE("DP8K"),
    .OCEAMUX("1"),
    .OCEBMUX("1"),
    .READBACK("OFF"),
    .REGMODE_A("NOREG"),
    .REGMODE_B("NOREG"),
    .RESETMODE("ASYNC"),
    .RSTAMUX("0"),
    .RSTBMUX("0"),
    .WEBMUX("0"),
    .WRITEMODE_A("NORMAL"),
    .WRITEMODE_B("NORMAL"))
    \l1_ram/cacheblk[0]$cacheunit/ram_memcell0_2048x8_sub_000000_004  (
    .addra({addr_pa_i[10:7],1'b0,addr_count[6:1],2'b11}),
    .addrb({addr_pa_i[10:7],addr_pa_i[7:1],2'b11}),
    .ceb(cwait),
    .clka(clk),
    .clkb(clk),
    .dia({open_n47,open_n48,open_n49,open_n50,open_n51,host_rdata[7:4]}),
    .wea(\l1_ram/n0 ),
    .dob({open_n75,open_n76,open_n77,open_n78,open_n79,instr_read[7:4]}));
  // address_offset=0;data_offset=0;depth=2048;width=4;num_section=1;width_per_section=4;section_size=8;working_depth=2048;working_width=4;mode_ecc=0;address_step=1;bytes_in_per_section=1;
  AL_PHY_BRAM #(
    //.RID("0x0006"),
    //.WID("0x0006"),
    .CEAMUX("1"),
    .CEBMUX("INV"),
    .CSA0("1"),
    .CSA1("1"),
    .CSA2("1"),
    .CSB0("1"),
    .CSB1("1"),
    .CSB2("1"),
    .DATA_WIDTH_A("4"),
    .DATA_WIDTH_B("4"),
    .GSR("DISABLE"),
    .MODE("DP8K"),
    .OCEAMUX("1"),
    .OCEBMUX("1"),
    .READBACK("OFF"),
    .REGMODE_A("NOREG"),
    .REGMODE_B("NOREG"),
    .RESETMODE("ASYNC"),
    .RSTAMUX("0"),
    .RSTBMUX("0"),
    .WEBMUX("0"),
    .WRITEMODE_A("NORMAL"),
    .WRITEMODE_B("NORMAL"))
    \l1_ram/cacheblk[1]$cacheunit/ram_memcell0_2048x8_sub_000000_000  (
    .addra({addr_pa_i[10:7],1'b0,addr_count[6:1],2'b11}),
    .addrb({addr_pa_i[10:7],addr_pa_i[7:1],2'b11}),
    .ceb(cwait),
    .clka(clk),
    .clkb(clk),
    .dia({open_n87,open_n88,open_n89,open_n90,open_n91,host_rdata[3:0]}),
    .wea(\l1_ram/n1 ),
    .dob({open_n115,open_n116,open_n117,open_n118,open_n119,instr_read[11:8]}));
  // address_offset=0;data_offset=4;depth=2048;width=4;num_section=1;width_per_section=4;section_size=8;working_depth=2048;working_width=4;mode_ecc=0;address_step=1;bytes_in_per_section=1;
  AL_PHY_BRAM #(
    //.RID("0x0007"),
    //.WID("0x0007"),
    .CEAMUX("1"),
    .CEBMUX("INV"),
    .CSA0("1"),
    .CSA1("1"),
    .CSA2("1"),
    .CSB0("1"),
    .CSB1("1"),
    .CSB2("1"),
    .DATA_WIDTH_A("4"),
    .DATA_WIDTH_B("4"),
    .GSR("DISABLE"),
    .MODE("DP8K"),
    .OCEAMUX("1"),
    .OCEBMUX("1"),
    .READBACK("OFF"),
    .REGMODE_A("NOREG"),
    .REGMODE_B("NOREG"),
    .RESETMODE("ASYNC"),
    .RSTAMUX("0"),
    .RSTBMUX("0"),
    .WEBMUX("0"),
    .WRITEMODE_A("NORMAL"),
    .WRITEMODE_B("NORMAL"))
    \l1_ram/cacheblk[1]$cacheunit/ram_memcell0_2048x8_sub_000000_004  (
    .addra({addr_pa_i[10:7],1'b0,addr_count[6:1],2'b11}),
    .addrb({addr_pa_i[10:7],addr_pa_i[7:1],2'b11}),
    .ceb(cwait),
    .clka(clk),
    .clkb(clk),
    .dia({open_n127,open_n128,open_n129,open_n130,open_n131,host_rdata[7:4]}),
    .wea(\l1_ram/n1 ),
    .dob({open_n155,open_n156,open_n157,open_n158,open_n159,instr_read[15:12]}));
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("INV"))
    reg0_b0 (
    .clk(clk),
    .d(sel0_b0_var_o),
    .sr(mux4_b0_sel_is_0_o),
    .q(main_state[0]));  // ../RTL/cache/l1_ionly.v(98)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("INV"))
    reg0_b1 (
    .clk(clk),
    .d(sel0_b1_var_o),
    .sr(mux4_b0_sel_is_0_o),
    .q(main_state[1]));  // ../RTL/cache/l1_ionly.v(98)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("INV"))
    reg0_b2 (
    .clk(clk),
    .d(sel0_b2_var_o),
    .sr(mux4_b0_sel_is_0_o),
    .q(main_state[2]));  // ../RTL/cache/l1_ionly.v(98)
  AL_PHY_LSLICE #(
    //.MACRO("tag_manager/al_ram_entry_tag_c0_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    \tag_manager/al_ram_entry_tag_c0_l  (
    .a({addr_pa_i[11],addr_pa_i[7]}),
    .b({addr_pa_i[12],addr_pa_i[8]}),
    .c({addr_pa_i[13],addr_pa_i[9]}),
    .clk(clk),
    .d({addr_pa_i[14],addr_pa_i[10]}),
    .e({open_n164,\tag_manager/n23 }),
    .dpram_di(\tag_manager/al_ram_entry_tag_c0_di ),
    .dpram_mode(\tag_manager/al_ram_entry_tag_c0_mode ),
    .dpram_waddr(\tag_manager/al_ram_entry_tag_c0_waddr ),
    .dpram_wclk(\tag_manager/al_ram_entry_tag_c0_wclk ),
    .dpram_we(\tag_manager/al_ram_entry_tag_c0_we ));
  AL_PHY_MSLICE #(
    //.MACRO("tag_manager/al_ram_entry_tag_c0_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    \tag_manager/al_ram_entry_tag_c0_m0  (
    .a({addr_pa_i[7],addr_pa_i[7]}),
    .b({addr_pa_i[8],addr_pa_i[8]}),
    .c({addr_pa_i[9],addr_pa_i[9]}),
    .d({addr_pa_i[10],addr_pa_i[10]}),
    .dpram_di(\tag_manager/al_ram_entry_tag_c0_di [1:0]),
    .dpram_mode(\tag_manager/al_ram_entry_tag_c0_mode ),
    .dpram_waddr(\tag_manager/al_ram_entry_tag_c0_waddr ),
    .dpram_wclk(\tag_manager/al_ram_entry_tag_c0_wclk ),
    .dpram_we(\tag_manager/al_ram_entry_tag_c0_we ),
    .f(\tag_manager/n3 [1:0]));
  AL_PHY_MSLICE #(
    //.MACRO("tag_manager/al_ram_entry_tag_c0_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    \tag_manager/al_ram_entry_tag_c0_m1  (
    .a({addr_pa_i[7],addr_pa_i[7]}),
    .b({addr_pa_i[8],addr_pa_i[8]}),
    .c({addr_pa_i[9],addr_pa_i[9]}),
    .d({addr_pa_i[10],addr_pa_i[10]}),
    .dpram_di(\tag_manager/al_ram_entry_tag_c0_di [3:2]),
    .dpram_mode(\tag_manager/al_ram_entry_tag_c0_mode ),
    .dpram_waddr(\tag_manager/al_ram_entry_tag_c0_waddr ),
    .dpram_wclk(\tag_manager/al_ram_entry_tag_c0_wclk ),
    .dpram_we(\tag_manager/al_ram_entry_tag_c0_we ),
    .f(\tag_manager/n3 [3:2]));
  AL_PHY_LSLICE #(
    //.MACRO("tag_manager/al_ram_entry_tag_c1_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    \tag_manager/al_ram_entry_tag_c1_l  (
    .a({addr_pa_i[15],addr_pa_i[7]}),
    .b({addr_pa_i[16],addr_pa_i[8]}),
    .c({addr_pa_i[17],addr_pa_i[9]}),
    .clk(clk),
    .d({addr_pa_i[18],addr_pa_i[10]}),
    .e({open_n199,\tag_manager/n23 }),
    .dpram_di(\tag_manager/al_ram_entry_tag_c1_di ),
    .dpram_mode(\tag_manager/al_ram_entry_tag_c1_mode ),
    .dpram_waddr(\tag_manager/al_ram_entry_tag_c1_waddr ),
    .dpram_wclk(\tag_manager/al_ram_entry_tag_c1_wclk ),
    .dpram_we(\tag_manager/al_ram_entry_tag_c1_we ));
  AL_PHY_MSLICE #(
    //.MACRO("tag_manager/al_ram_entry_tag_c1_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    \tag_manager/al_ram_entry_tag_c1_m0  (
    .a({addr_pa_i[7],addr_pa_i[7]}),
    .b({addr_pa_i[8],addr_pa_i[8]}),
    .c({addr_pa_i[9],addr_pa_i[9]}),
    .d({addr_pa_i[10],addr_pa_i[10]}),
    .dpram_di(\tag_manager/al_ram_entry_tag_c1_di [1:0]),
    .dpram_mode(\tag_manager/al_ram_entry_tag_c1_mode ),
    .dpram_waddr(\tag_manager/al_ram_entry_tag_c1_waddr ),
    .dpram_wclk(\tag_manager/al_ram_entry_tag_c1_wclk ),
    .dpram_we(\tag_manager/al_ram_entry_tag_c1_we ),
    .f(\tag_manager/n3 [5:4]));
  AL_PHY_MSLICE #(
    //.MACRO("tag_manager/al_ram_entry_tag_c1_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    \tag_manager/al_ram_entry_tag_c1_m1  (
    .a({addr_pa_i[7],addr_pa_i[7]}),
    .b({addr_pa_i[8],addr_pa_i[8]}),
    .c({addr_pa_i[9],addr_pa_i[9]}),
    .d({addr_pa_i[10],addr_pa_i[10]}),
    .dpram_di(\tag_manager/al_ram_entry_tag_c1_di [3:2]),
    .dpram_mode(\tag_manager/al_ram_entry_tag_c1_mode ),
    .dpram_waddr(\tag_manager/al_ram_entry_tag_c1_waddr ),
    .dpram_wclk(\tag_manager/al_ram_entry_tag_c1_wclk ),
    .dpram_we(\tag_manager/al_ram_entry_tag_c1_we ),
    .f(\tag_manager/n3 [7:6]));
  AL_PHY_LSLICE #(
    //.MACRO("tag_manager/al_ram_entry_tag_c2_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    \tag_manager/al_ram_entry_tag_c2_l  (
    .a({addr_pa_i[19],addr_pa_i[7]}),
    .b({addr_pa_i[20],addr_pa_i[8]}),
    .c({addr_pa_i[21],addr_pa_i[9]}),
    .clk(clk),
    .d({addr_pa_i[22],addr_pa_i[10]}),
    .e({open_n234,\tag_manager/n23 }),
    .dpram_di(\tag_manager/al_ram_entry_tag_c2_di ),
    .dpram_mode(\tag_manager/al_ram_entry_tag_c2_mode ),
    .dpram_waddr(\tag_manager/al_ram_entry_tag_c2_waddr ),
    .dpram_wclk(\tag_manager/al_ram_entry_tag_c2_wclk ),
    .dpram_we(\tag_manager/al_ram_entry_tag_c2_we ));
  AL_PHY_MSLICE #(
    //.MACRO("tag_manager/al_ram_entry_tag_c2_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    \tag_manager/al_ram_entry_tag_c2_m0  (
    .a({addr_pa_i[7],addr_pa_i[7]}),
    .b({addr_pa_i[8],addr_pa_i[8]}),
    .c({addr_pa_i[9],addr_pa_i[9]}),
    .d({addr_pa_i[10],addr_pa_i[10]}),
    .dpram_di(\tag_manager/al_ram_entry_tag_c2_di [1:0]),
    .dpram_mode(\tag_manager/al_ram_entry_tag_c2_mode ),
    .dpram_waddr(\tag_manager/al_ram_entry_tag_c2_waddr ),
    .dpram_wclk(\tag_manager/al_ram_entry_tag_c2_wclk ),
    .dpram_we(\tag_manager/al_ram_entry_tag_c2_we ),
    .f(\tag_manager/n3 [9:8]));
  AL_PHY_MSLICE #(
    //.MACRO("tag_manager/al_ram_entry_tag_c2_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    \tag_manager/al_ram_entry_tag_c2_m1  (
    .a({addr_pa_i[7],addr_pa_i[7]}),
    .b({addr_pa_i[8],addr_pa_i[8]}),
    .c({addr_pa_i[9],addr_pa_i[9]}),
    .d({addr_pa_i[10],addr_pa_i[10]}),
    .dpram_di(\tag_manager/al_ram_entry_tag_c2_di [3:2]),
    .dpram_mode(\tag_manager/al_ram_entry_tag_c2_mode ),
    .dpram_waddr(\tag_manager/al_ram_entry_tag_c2_waddr ),
    .dpram_wclk(\tag_manager/al_ram_entry_tag_c2_wclk ),
    .dpram_we(\tag_manager/al_ram_entry_tag_c2_we ),
    .f(\tag_manager/n3 [11:10]));
  AL_PHY_LSLICE #(
    //.MACRO("tag_manager/al_ram_entry_tag_c3_l"),
    //.R_POSITION("X0Y0Z2"),
    .GSR("DISABLE"),
    .MODE("RAMW"))
    \tag_manager/al_ram_entry_tag_c3_l  (
    .a({addr_pa_i[23],addr_pa_i[7]}),
    .b({1'b0,addr_pa_i[8]}),
    .c({1'b0,addr_pa_i[9]}),
    .clk(clk),
    .d({1'b0,addr_pa_i[10]}),
    .e({open_n269,\tag_manager/n23 }),
    .dpram_di(\tag_manager/al_ram_entry_tag_c3_di ),
    .dpram_mode(\tag_manager/al_ram_entry_tag_c3_mode ),
    .dpram_waddr(\tag_manager/al_ram_entry_tag_c3_waddr ),
    .dpram_wclk(\tag_manager/al_ram_entry_tag_c3_wclk ),
    .dpram_we(\tag_manager/al_ram_entry_tag_c3_we ));
  AL_PHY_MSLICE #(
    //.MACRO("tag_manager/al_ram_entry_tag_c3_l"),
    //.R_POSITION("X0Y0Z0"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    \tag_manager/al_ram_entry_tag_c3_m0  (
    .a({addr_pa_i[7],addr_pa_i[7]}),
    .b({addr_pa_i[8],addr_pa_i[8]}),
    .c({addr_pa_i[9],addr_pa_i[9]}),
    .d({addr_pa_i[10],addr_pa_i[10]}),
    .dpram_di(\tag_manager/al_ram_entry_tag_c3_di [1:0]),
    .dpram_mode(\tag_manager/al_ram_entry_tag_c3_mode ),
    .dpram_waddr(\tag_manager/al_ram_entry_tag_c3_waddr ),
    .dpram_wclk(\tag_manager/al_ram_entry_tag_c3_wclk ),
    .dpram_we(\tag_manager/al_ram_entry_tag_c3_we ),
    .f(\tag_manager/n3 [13:12]));
  AL_PHY_MSLICE #(
    //.MACRO("tag_manager/al_ram_entry_tag_c3_l"),
    //.R_POSITION("X0Y0Z1"),
    .GSR("DISABLE"),
    .MODE("DPRAM"))
    \tag_manager/al_ram_entry_tag_c3_m1  (
    .a({addr_pa_i[7],addr_pa_i[7]}),
    .b({addr_pa_i[8],addr_pa_i[8]}),
    .c({addr_pa_i[9],addr_pa_i[9]}),
    .d({addr_pa_i[10],addr_pa_i[10]}),
    .dpram_di(\tag_manager/al_ram_entry_tag_c3_di [3:2]),
    .dpram_mode(\tag_manager/al_ram_entry_tag_c3_mode ),
    .dpram_waddr(\tag_manager/al_ram_entry_tag_c3_waddr ),
    .dpram_wclk(\tag_manager/al_ram_entry_tag_c3_wclk ),
    .dpram_we(\tag_manager/al_ram_entry_tag_c3_we ));
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \tag_manager/reg0_b0  (
    .clk(clk),
    .d(\tag_manager/n41 [0]),
    .sr(rst),
    .q(\tag_manager/line_valid [0]));  // ../RTL/cache/tag_arbiter_dm.v(53)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \tag_manager/reg0_b1  (
    .clk(clk),
    .d(\tag_manager/n41 [1]),
    .sr(rst),
    .q(\tag_manager/line_valid [1]));  // ../RTL/cache/tag_arbiter_dm.v(53)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \tag_manager/reg0_b10  (
    .clk(clk),
    .d(\tag_manager/n41 [10]),
    .sr(rst),
    .q(\tag_manager/line_valid [10]));  // ../RTL/cache/tag_arbiter_dm.v(53)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \tag_manager/reg0_b11  (
    .clk(clk),
    .d(\tag_manager/n41 [11]),
    .sr(rst),
    .q(\tag_manager/line_valid [11]));  // ../RTL/cache/tag_arbiter_dm.v(53)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \tag_manager/reg0_b12  (
    .clk(clk),
    .d(\tag_manager/n41 [12]),
    .sr(rst),
    .q(\tag_manager/line_valid [12]));  // ../RTL/cache/tag_arbiter_dm.v(53)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \tag_manager/reg0_b13  (
    .clk(clk),
    .d(\tag_manager/n41 [13]),
    .sr(rst),
    .q(\tag_manager/line_valid [13]));  // ../RTL/cache/tag_arbiter_dm.v(53)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \tag_manager/reg0_b14  (
    .clk(clk),
    .d(\tag_manager/n41 [14]),
    .sr(rst),
    .q(\tag_manager/line_valid [14]));  // ../RTL/cache/tag_arbiter_dm.v(53)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \tag_manager/reg0_b15  (
    .clk(clk),
    .d(\tag_manager/n41 [15]),
    .sr(rst),
    .q(\tag_manager/line_valid [15]));  // ../RTL/cache/tag_arbiter_dm.v(53)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \tag_manager/reg0_b2  (
    .clk(clk),
    .d(\tag_manager/n41 [2]),
    .sr(rst),
    .q(\tag_manager/line_valid [2]));  // ../RTL/cache/tag_arbiter_dm.v(53)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \tag_manager/reg0_b3  (
    .clk(clk),
    .d(\tag_manager/n41 [3]),
    .sr(rst),
    .q(\tag_manager/line_valid [3]));  // ../RTL/cache/tag_arbiter_dm.v(53)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \tag_manager/reg0_b4  (
    .clk(clk),
    .d(\tag_manager/n41 [4]),
    .sr(rst),
    .q(\tag_manager/line_valid [4]));  // ../RTL/cache/tag_arbiter_dm.v(53)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \tag_manager/reg0_b5  (
    .clk(clk),
    .d(\tag_manager/n41 [5]),
    .sr(rst),
    .q(\tag_manager/line_valid [5]));  // ../RTL/cache/tag_arbiter_dm.v(53)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \tag_manager/reg0_b6  (
    .clk(clk),
    .d(\tag_manager/n41 [6]),
    .sr(rst),
    .q(\tag_manager/line_valid [6]));  // ../RTL/cache/tag_arbiter_dm.v(53)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \tag_manager/reg0_b7  (
    .clk(clk),
    .d(\tag_manager/n41 [7]),
    .sr(rst),
    .q(\tag_manager/line_valid [7]));  // ../RTL/cache/tag_arbiter_dm.v(53)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \tag_manager/reg0_b8  (
    .clk(clk),
    .d(\tag_manager/n41 [8]),
    .sr(rst),
    .q(\tag_manager/line_valid [8]));  // ../RTL/cache/tag_arbiter_dm.v(53)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("SYNC"),
    .SRMUX("SR"))
    \tag_manager/reg0_b9  (
    .clk(clk),
    .d(\tag_manager/n41 [9]),
    .sr(rst),
    .q(\tag_manager/line_valid [9]));  // ../RTL/cache/tag_arbiter_dm.v(53)

endmodule 

module int_ctrl  // ../RTL/peripherals/int_ctrl.v(10)
  (
  INT_ARR,
  WB_ADRi,
  WB_CYCi,
  WB_DATi,
  WB_STBi,
  WB_WEi,
  XCP_ARR,
  clk,
  rst,
  INT,
  IVEC_ADDR,
  WB_ACKo,
  WB_DATo
  );

  input [7:0] INT_ARR;  // ../RTL/peripherals/int_ctrl.v(13)
  input [2:0] WB_ADRi;  // ../RTL/peripherals/int_ctrl.v(21)
  input WB_CYCi;  // ../RTL/peripherals/int_ctrl.v(25)
  input [7:0] WB_DATi;  // ../RTL/peripherals/int_ctrl.v(23)
  input WB_STBi;  // ../RTL/peripherals/int_ctrl.v(26)
  input WB_WEi;  // ../RTL/peripherals/int_ctrl.v(24)
  input [7:0] XCP_ARR;  // ../RTL/peripherals/int_ctrl.v(14)
  input clk;  // ../RTL/peripherals/int_ctrl.v(18)
  input rst;  // ../RTL/peripherals/int_ctrl.v(19)
  output INT;  // ../RTL/peripherals/int_ctrl.v(16)
  output [23:0] IVEC_ADDR;  // ../RTL/peripherals/int_ctrl.v(15)
  output WB_ACKo;  // ../RTL/peripherals/int_ctrl.v(27)
  output [7:0] WB_DATo;  // ../RTL/peripherals/int_ctrl.v(22)

  // localparam EXCEPTION_CATCHER[0].j = 0;
  // localparam EXCEPTION_CATCHER[1].j = 1;
  // localparam EXCEPTION_CATCHER[2].j = 2;
  // localparam EXCEPTION_CATCHER[3].j = 3;
  // localparam EXCEPTION_CATCHER[4].j = 4;
  // localparam EXCEPTION_CATCHER[5].j = 5;
  // localparam EXCEPTION_CATCHER[6].j = 6;
  // localparam EXCEPTION_CATCHER[7].j = 7;
  wire [7:0] EXPE0;  // ../RTL/peripherals/int_ctrl.v(36)
  wire [2:0] INTC;  // ../RTL/peripherals/int_ctrl.v(34)
  wire [7:0] INTE0;  // ../RTL/peripherals/int_ctrl.v(36)
  wire [7:0] \IVE_SIZE_SHIFTER/shift_stages[2] ;  // ../RTL/peripherals/left_bshifter.v(12)
  wire [7:0] IVT0;  // ../RTL/peripherals/int_ctrl.v(35)
  wire [7:0] IVT1;  // ../RTL/peripherals/int_ctrl.v(35)
  wire [7:0] IVT2;  // ../RTL/peripherals/int_ctrl.v(35)
  wire [7:0] int_masked;  // ../RTL/peripherals/int_ctrl.v(37)
  wire  \mux31_b0/B0_0 ;  // ../RTL/peripherals/int_ctrl.v(135)
  wire  \mux31_b0/B0_1 ;  // ../RTL/peripherals/int_ctrl.v(135)
  wire  \mux31_b0/B0_2 ;  // ../RTL/peripherals/int_ctrl.v(135)
  wire  \mux31_b1/B0_0 ;  // ../RTL/peripherals/int_ctrl.v(135)
  wire  \mux31_b1/B0_1 ;  // ../RTL/peripherals/int_ctrl.v(135)
  wire  \mux31_b1/B0_2 ;  // ../RTL/peripherals/int_ctrl.v(135)
  wire  \mux31_b2/B0_0 ;  // ../RTL/peripherals/int_ctrl.v(135)
  wire  \mux31_b2/B0_1 ;  // ../RTL/peripherals/int_ctrl.v(135)
  wire  \mux31_b2/B0_2 ;  // ../RTL/peripherals/int_ctrl.v(135)
  wire  \mux31_b3/B1_1 ;  // ../RTL/peripherals/int_ctrl.v(135)
  wire  \mux31_b4/B1_1 ;  // ../RTL/peripherals/int_ctrl.v(135)
  wire  \mux31_b5/B1_1 ;  // ../RTL/peripherals/int_ctrl.v(135)
  wire  \mux31_b6/B1_1 ;  // ../RTL/peripherals/int_ctrl.v(135)
  wire  \mux31_b7/B1_1 ;  // ../RTL/peripherals/int_ctrl.v(135)
  wire [21:0] n5;
  wire _al_u137_o;
  wire _al_u139_o;
  wire _al_u140_o;
  wire _al_u143_o;
  wire _al_u146_o;
  wire _al_u159_o;
  wire _al_u162_o;
  wire _al_u165_o;
  wire _al_u168_o;
  wire _al_u171_o;
  wire \add0/c11 ;  // ../RTL/peripherals/int_ctrl.v(80)
  wire \add0/c15 ;  // ../RTL/peripherals/int_ctrl.v(80)
  wire \add0/c19 ;  // ../RTL/peripherals/int_ctrl.v(80)
  wire \add0/c3 ;  // ../RTL/peripherals/int_ctrl.v(80)
  wire \add0/c7 ;  // ../RTL/peripherals/int_ctrl.v(80)
  wire mux13_b0_sel_is_2_o;
  wire mux25_b0_sel_is_3_o;
  wire mux26_b0_sel_is_2_o;
  wire mux27_b0_sel_is_2_o;
  wire mux28_b0_sel_is_2_o;
  wire mux29_b0_sel_is_2_o;
  wire mux30_b0_sel_is_2_o;
  wire n4;
  wire n9;

  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    INT_reg (
    .ce(INTC[2]),
    .clk(clk),
    .d(n4),
    .sr(rst),
    .q(INT));  // ../RTL/peripherals/int_ctrl.v(86)
  AL_MAP_LUT2 #(
    .EQN("(B*~A)"),
    .INIT(4'h4))
    _al_u136 (
    .a(rst),
    .b(INTC[2]),
    .o(mux13_b0_sel_is_2_o));
  AL_MAP_LUT2 #(
    .EQN("(B*A)"),
    .INIT(4'h8))
    _al_u137 (
    .a(INT_ARR[7]),
    .b(INTE0[7]),
    .o(_al_u137_o));
  AL_MAP_LUT2 #(
    .EQN("(B*A)"),
    .INIT(4'h8))
    _al_u138 (
    .a(INT_ARR[5]),
    .b(INTE0[5]),
    .o(int_masked[5]));
  AL_MAP_LUT2 #(
    .EQN("(B*A)"),
    .INIT(4'h8))
    _al_u139 (
    .a(INT_ARR[6]),
    .b(INTE0[6]),
    .o(_al_u139_o));
  AL_MAP_LUT4 #(
    .EQN("(~(C*B)*~(D*A))"),
    .INIT(16'h153f))
    _al_u140 (
    .a(INT_ARR[7]),
    .b(INT_ARR[6]),
    .c(INTE0[6]),
    .d(INTE0[7]),
    .o(_al_u140_o));
  AL_MAP_LUT2 #(
    .EQN("~(~B*A)"),
    .INIT(4'hd))
    _al_u141 (
    .a(_al_u140_o),
    .b(int_masked[5]),
    .o(n4));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u142 (
    .a(WB_CYCi),
    .b(WB_STBi),
    .c(WB_WEi),
    .o(n9));
  AL_MAP_LUT4 #(
    .EQN("(D*C*B*~A)"),
    .INIT(16'h4000))
    _al_u143 (
    .a(WB_ADRi[2]),
    .b(WB_CYCi),
    .c(WB_STBi),
    .d(WB_WEi),
    .o(_al_u143_o));
  AL_MAP_LUT3 #(
    .EQN("(~C*~B*A)"),
    .INIT(8'h02))
    _al_u144 (
    .a(_al_u143_o),
    .b(WB_ADRi[1]),
    .c(WB_ADRi[0]),
    .o(mux25_b0_sel_is_3_o));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u145 (
    .a(WB_ADRi[0]),
    .b(EXPE0[0]),
    .c(INTE0[0]),
    .o(\mux31_b0/B0_2 ));
  AL_MAP_LUT2 #(
    .EQN("(~B*A)"),
    .INIT(4'h2))
    _al_u146 (
    .a(WB_ADRi[2]),
    .b(WB_ADRi[1]),
    .o(_al_u146_o));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u147 (
    .a(WB_ADRi[0]),
    .b(IVT2[0]),
    .c(IVT1[0]),
    .o(\mux31_b0/B0_1 ));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u148 (
    .a(WB_ADRi[0]),
    .b(INTC[0]),
    .c(IVT0[0]),
    .o(\mux31_b0/B0_0 ));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+A*B*C*~(D)*~(E)+A*~(B)*~(C)*D*~(E)+A*B*~(C)*D*~(E)+A*~(B)*C*D*~(E)+A*B*C*D*~(E)+~(A)*B*~(C)*~(D)*E+A*B*~(C)*~(D)*E+~(A)*B*C*~(D)*E+A*B*C*~(D)*E)"),
    .INIT(32'h00ccaaf0))
    _al_u149 (
    .a(\mux31_b0/B0_2 ),
    .b(\mux31_b0/B0_1 ),
    .c(\mux31_b0/B0_0 ),
    .d(WB_ADRi[2]),
    .e(WB_ADRi[1]),
    .o(WB_DATo[0]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u150 (
    .a(WB_ADRi[0]),
    .b(EXPE0[1]),
    .c(INTE0[1]),
    .o(\mux31_b1/B0_2 ));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u151 (
    .a(WB_ADRi[0]),
    .b(IVT2[1]),
    .c(IVT1[1]),
    .o(\mux31_b1/B0_1 ));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u152 (
    .a(WB_ADRi[0]),
    .b(INTC[1]),
    .c(IVT0[1]),
    .o(\mux31_b1/B0_0 ));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+A*B*C*~(D)*~(E)+A*~(B)*~(C)*D*~(E)+A*B*~(C)*D*~(E)+A*~(B)*C*D*~(E)+A*B*C*D*~(E)+~(A)*B*~(C)*~(D)*E+A*B*~(C)*~(D)*E+~(A)*B*C*~(D)*E+A*B*C*~(D)*E)"),
    .INIT(32'h00ccaaf0))
    _al_u153 (
    .a(\mux31_b1/B0_2 ),
    .b(\mux31_b1/B0_1 ),
    .c(\mux31_b1/B0_0 ),
    .d(WB_ADRi[2]),
    .e(WB_ADRi[1]),
    .o(WB_DATo[1]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u154 (
    .a(WB_ADRi[0]),
    .b(EXPE0[2]),
    .c(INTE0[2]),
    .o(\mux31_b2/B0_2 ));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u155 (
    .a(WB_ADRi[0]),
    .b(IVT2[2]),
    .c(IVT1[2]),
    .o(\mux31_b2/B0_1 ));
  AL_MAP_LUT3 #(
    .EQN("(B*~(C)*~(A)+B*C*~(A)+~(B)*C*A+B*C*A)"),
    .INIT(8'he4))
    _al_u156 (
    .a(WB_ADRi[0]),
    .b(INTC[2]),
    .c(IVT0[2]),
    .o(\mux31_b2/B0_0 ));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+A*B*C*~(D)*~(E)+A*~(B)*~(C)*D*~(E)+A*B*~(C)*D*~(E)+A*~(B)*C*D*~(E)+A*B*C*D*~(E)+~(A)*B*~(C)*~(D)*E+A*B*~(C)*~(D)*E+~(A)*B*C*~(D)*E+A*B*C*~(D)*E)"),
    .INIT(32'h00ccaaf0))
    _al_u157 (
    .a(\mux31_b2/B0_2 ),
    .b(\mux31_b2/B0_1 ),
    .c(\mux31_b2/B0_0 ),
    .d(WB_ADRi[2]),
    .e(WB_ADRi[1]),
    .o(WB_DATo[2]));
  AL_MAP_LUT4 #(
    .EQN("(~A*(D*~(C)*~(B)+D*C*~(B)+~(D)*C*B+D*C*B))"),
    .INIT(16'h5140))
    _al_u158 (
    .a(WB_ADRi[1]),
    .b(WB_ADRi[0]),
    .c(EXPE0[3]),
    .d(INTE0[3]),
    .o(\mux31_b3/B1_1 ));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+A*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+~(A)*~(B)*~(C)*~(D)*E+A*~(B)*~(C)*~(D)*E+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*~(B)*C*~(D)*E+~(A)*~(B)*~(C)*D*E+A*B*~(C)*D*E+~(A)*~(B)*C*D*E)"),
    .INIT(32'h193b5d7f))
    _al_u159 (
    .a(WB_ADRi[1]),
    .b(WB_ADRi[0]),
    .c(IVT2[3]),
    .d(IVT1[3]),
    .e(IVT0[3]),
    .o(_al_u159_o));
  AL_MAP_LUT3 #(
    .EQN("(~A*~(B)*~(C)+~A*B*~(C)+~(~A)*B*C+~A*B*C)"),
    .INIT(8'hc5))
    _al_u160 (
    .a(_al_u159_o),
    .b(\mux31_b3/B1_1 ),
    .c(WB_ADRi[2]),
    .o(WB_DATo[3]));
  AL_MAP_LUT4 #(
    .EQN("(~A*(D*~(C)*~(B)+D*C*~(B)+~(D)*C*B+D*C*B))"),
    .INIT(16'h5140))
    _al_u161 (
    .a(WB_ADRi[1]),
    .b(WB_ADRi[0]),
    .c(EXPE0[4]),
    .d(INTE0[4]),
    .o(\mux31_b4/B1_1 ));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+A*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+~(A)*~(B)*~(C)*~(D)*E+A*~(B)*~(C)*~(D)*E+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*~(B)*C*~(D)*E+~(A)*~(B)*~(C)*D*E+A*B*~(C)*D*E+~(A)*~(B)*C*D*E)"),
    .INIT(32'h193b5d7f))
    _al_u162 (
    .a(WB_ADRi[1]),
    .b(WB_ADRi[0]),
    .c(IVT2[4]),
    .d(IVT1[4]),
    .e(IVT0[4]),
    .o(_al_u162_o));
  AL_MAP_LUT3 #(
    .EQN("(~A*~(B)*~(C)+~A*B*~(C)+~(~A)*B*C+~A*B*C)"),
    .INIT(8'hc5))
    _al_u163 (
    .a(_al_u162_o),
    .b(\mux31_b4/B1_1 ),
    .c(WB_ADRi[2]),
    .o(WB_DATo[4]));
  AL_MAP_LUT4 #(
    .EQN("(~A*(D*~(C)*~(B)+D*C*~(B)+~(D)*C*B+D*C*B))"),
    .INIT(16'h5140))
    _al_u164 (
    .a(WB_ADRi[1]),
    .b(WB_ADRi[0]),
    .c(EXPE0[5]),
    .d(INTE0[5]),
    .o(\mux31_b5/B1_1 ));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+A*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+~(A)*~(B)*~(C)*~(D)*E+A*~(B)*~(C)*~(D)*E+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*~(B)*C*~(D)*E+~(A)*~(B)*~(C)*D*E+A*B*~(C)*D*E+~(A)*~(B)*C*D*E)"),
    .INIT(32'h193b5d7f))
    _al_u165 (
    .a(WB_ADRi[1]),
    .b(WB_ADRi[0]),
    .c(IVT2[5]),
    .d(IVT1[5]),
    .e(IVT0[5]),
    .o(_al_u165_o));
  AL_MAP_LUT3 #(
    .EQN("(~A*~(B)*~(C)+~A*B*~(C)+~(~A)*B*C+~A*B*C)"),
    .INIT(8'hc5))
    _al_u166 (
    .a(_al_u165_o),
    .b(\mux31_b5/B1_1 ),
    .c(WB_ADRi[2]),
    .o(WB_DATo[5]));
  AL_MAP_LUT4 #(
    .EQN("(~A*(D*~(C)*~(B)+D*C*~(B)+~(D)*C*B+D*C*B))"),
    .INIT(16'h5140))
    _al_u167 (
    .a(WB_ADRi[1]),
    .b(WB_ADRi[0]),
    .c(EXPE0[6]),
    .d(INTE0[6]),
    .o(\mux31_b6/B1_1 ));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+A*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+~(A)*~(B)*~(C)*~(D)*E+A*~(B)*~(C)*~(D)*E+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*~(B)*C*~(D)*E+~(A)*~(B)*~(C)*D*E+A*B*~(C)*D*E+~(A)*~(B)*C*D*E)"),
    .INIT(32'h193b5d7f))
    _al_u168 (
    .a(WB_ADRi[1]),
    .b(WB_ADRi[0]),
    .c(IVT2[6]),
    .d(IVT1[6]),
    .e(IVT0[6]),
    .o(_al_u168_o));
  AL_MAP_LUT3 #(
    .EQN("(~A*~(B)*~(C)+~A*B*~(C)+~(~A)*B*C+~A*B*C)"),
    .INIT(8'hc5))
    _al_u169 (
    .a(_al_u168_o),
    .b(\mux31_b6/B1_1 ),
    .c(WB_ADRi[2]),
    .o(WB_DATo[6]));
  AL_MAP_LUT4 #(
    .EQN("(~A*(D*~(C)*~(B)+D*C*~(B)+~(D)*C*B+D*C*B))"),
    .INIT(16'h5140))
    _al_u170 (
    .a(WB_ADRi[1]),
    .b(WB_ADRi[0]),
    .c(EXPE0[7]),
    .d(INTE0[7]),
    .o(\mux31_b7/B1_1 ));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+A*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+~(A)*~(B)*~(C)*~(D)*E+A*~(B)*~(C)*~(D)*E+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*~(B)*C*~(D)*E+~(A)*~(B)*~(C)*D*E+A*B*~(C)*D*E+~(A)*~(B)*C*D*E)"),
    .INIT(32'h193b5d7f))
    _al_u171 (
    .a(WB_ADRi[1]),
    .b(WB_ADRi[0]),
    .c(IVT2[7]),
    .d(IVT1[7]),
    .e(IVT0[7]),
    .o(_al_u171_o));
  AL_MAP_LUT3 #(
    .EQN("(~A*~(B)*~(C)+~A*B*~(C)+~(~A)*B*C+~A*B*C)"),
    .INIT(8'hc5))
    _al_u172 (
    .a(_al_u171_o),
    .b(\mux31_b7/B1_1 ),
    .c(WB_ADRi[2]),
    .o(WB_DATo[7]));
  AL_MAP_LUT4 #(
    .EQN("(~D*C*~B*A)"),
    .INIT(16'h0020))
    _al_u173 (
    .a(_al_u143_o),
    .b(WB_ADRi[1]),
    .c(WB_ADRi[0]),
    .d(rst),
    .o(mux30_b0_sel_is_2_o));
  AL_MAP_LUT4 #(
    .EQN("(~D*~C*B*A)"),
    .INIT(16'h0008))
    _al_u174 (
    .a(_al_u143_o),
    .b(WB_ADRi[1]),
    .c(WB_ADRi[0]),
    .d(rst),
    .o(mux29_b0_sel_is_2_o));
  AL_MAP_LUT4 #(
    .EQN("(~D*C*B*A)"),
    .INIT(16'h0080))
    _al_u175 (
    .a(_al_u143_o),
    .b(WB_ADRi[1]),
    .c(WB_ADRi[0]),
    .d(rst),
    .o(mux28_b0_sel_is_2_o));
  AL_MAP_LUT4 #(
    .EQN("(~D*~C*B*A)"),
    .INIT(16'h0008))
    _al_u176 (
    .a(n9),
    .b(_al_u146_o),
    .c(WB_ADRi[0]),
    .d(rst),
    .o(mux27_b0_sel_is_2_o));
  AL_MAP_LUT4 #(
    .EQN("(~D*C*B*A)"),
    .INIT(16'h0080))
    _al_u177 (
    .a(n9),
    .b(_al_u146_o),
    .c(WB_ADRi[0]),
    .d(rst),
    .o(mux26_b0_sel_is_2_o));
  AL_MAP_LUT4 #(
    .EQN("(D*C*~(~B*A))"),
    .INIT(16'hd000))
    _al_u178 (
    .a(_al_u140_o),
    .b(int_masked[5]),
    .c(INTC[0]),
    .d(INTC[1]),
    .o(\IVE_SIZE_SHIFTER/shift_stages[2] [5]));
  AL_MAP_LUT4 #(
    .EQN("(D*~(A*~(~C*B)))"),
    .INIT(16'h5d00))
    _al_u179 (
    .a(_al_u140_o),
    .b(int_masked[5]),
    .c(INTC[0]),
    .d(INTC[1]),
    .o(\IVE_SIZE_SHIFTER/shift_stages[2] [4]));
  AL_MAP_LUT5 #(
    .EQN("(A*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+A*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+A*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+A*B*C*D*~(E)+A*~(B)*~(C)*~(D)*E+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*~(B)*C*~(D)*E+~(A)*B*C*~(D)*E+A*B*C*~(D)*E+A*~(B)*~(C)*D*E+~(A)*B*~(C)*D*E+A*B*~(C)*D*E+A*~(B)*C*D*E+A*B*C*D*E)"),
    .INIT(32'haefafe00))
    _al_u180 (
    .a(_al_u137_o),
    .b(int_masked[5]),
    .c(_al_u139_o),
    .d(INTC[0]),
    .e(INTC[1]),
    .o(\IVE_SIZE_SHIFTER/shift_stages[2] [3]));
  AL_MAP_LUT5 #(
    .EQN("(~E*~(~A*(~(B)*~(C)*~(D)+B*~(C)*~(D)+~(B)*~(C)*D+~(B)*C*D+B*C*D)))"),
    .INIT(32'h0000aefa))
    _al_u181 (
    .a(_al_u137_o),
    .b(int_masked[5]),
    .c(_al_u139_o),
    .d(INTC[0]),
    .e(INTC[1]),
    .o(\IVE_SIZE_SHIFTER/shift_stages[2] [1]));
  AL_MAP_LUT5 #(
    .EQN("(A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+A*B*C*~(D)*~(E)+A*~(B)*~(C)*D*~(E)+A*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+A*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+A*B*C*D*~(E)+A*~(B)*~(C)*~(D)*E+~(A)*B*~(C)*~(D)*E+A*B*~(C)*~(D)*E+A*~(B)*C*~(D)*E+A*B*C*~(D)*E)"),
    .INIT(32'h00aefafe))
    _al_u182 (
    .a(_al_u137_o),
    .b(int_masked[5]),
    .c(_al_u139_o),
    .d(INTC[0]),
    .e(INTC[1]),
    .o(\IVE_SIZE_SHIFTER/shift_stages[2] [2]));
  AL_MAP_LUT5 #(
    .EQN("(~E*~D*~(~A*~(~C*B)))"),
    .INIT(32'h000000ae))
    _al_u183 (
    .a(_al_u137_o),
    .b(int_masked[5]),
    .c(_al_u139_o),
    .d(INTC[0]),
    .e(INTC[1]),
    .o(\IVE_SIZE_SHIFTER/shift_stages[2] [0]));
  AL_PHY_LSLICE #(
    //.MACRO("add0/ucin_al_u184"),
    //.R_POSITION("X0Y1Z1"),
    .DEMUX0("E"),
    .DEMUX1("E"),
    .GSR("DISABLE"),
    .INIT_LUTF0(16'hA55A),
    .INIT_LUTF1(16'hA55A),
    .INIT_LUTG0(16'hC33C),
    .INIT_LUTG1(16'hC33C),
    .LSFMUX0("SUM"),
    .LSFMUX1("SUM"),
    .LSFXMUX0("SUM"),
    .LSFXMUX1("SUM"),
    .MODE("RIPPLE"))
    \add0/u11_al_u187  (
    .a({IVT1[7],IVT1[5]}),
    .b({IVT2[0],IVT1[6]}),
    .c(2'b00),
    .d(2'b00),
    .e(2'b00),
    .fci(\add0/c11 ),
    .f({n5[13],n5[11]}),
    .fco(\add0/c15 ),
    .fx({n5[14],n5[12]}));
  AL_PHY_LSLICE #(
    //.MACRO("add0/ucin_al_u184"),
    //.R_POSITION("X0Y2Z0"),
    .DEMUX0("E"),
    .DEMUX1("E"),
    .GSR("DISABLE"),
    .INIT_LUTF0(16'hA55A),
    .INIT_LUTF1(16'hA55A),
    .INIT_LUTG0(16'hC33C),
    .INIT_LUTG1(16'hC33C),
    .LSFMUX0("SUM"),
    .LSFMUX1("SUM"),
    .LSFXMUX0("SUM"),
    .LSFXMUX1("SUM"),
    .MODE("RIPPLE"))
    \add0/u15_al_u188  (
    .a({IVT2[3],IVT2[1]}),
    .b({IVT2[4],IVT2[2]}),
    .c(2'b00),
    .d(2'b00),
    .e(2'b00),
    .fci(\add0/c15 ),
    .f({n5[17],n5[15]}),
    .fco(\add0/c19 ),
    .fx({n5[18],n5[16]}));
  AL_PHY_LSLICE #(
    //.MACRO("add0/ucin_al_u184"),
    //.R_POSITION("X0Y2Z1"),
    .DEMUX0("E"),
    .DEMUX1("E"),
    .GSR("DISABLE"),
    .INIT_LUTF0(16'hA55A),
    .INIT_LUTF1(16'hA55A),
    .INIT_LUTG0(16'hC33C),
    .INIT_LUTG1(16'hC33C),
    .LSFMUX0("SUM"),
    .LSFMUX1("SUM"),
    .LSFXMUX0("SUM"),
    .LSFXMUX1("SUM"),
    .MODE("RIPPLE"))
    \add0/u19_al_u189  (
    .a({open_n36,IVT2[5]}),
    .b({open_n37,IVT2[6]}),
    .c(2'b00),
    .d({open_n40,1'b0}),
    .e({open_n41,1'b0}),
    .fci(\add0/c19 ),
    .f({open_n56,n5[19]}),
    .fx({open_n58,n5[20]}));
  AL_PHY_LSLICE #(
    //.MACRO("add0/ucin_al_u184"),
    //.R_POSITION("X0Y0Z1"),
    .DEMUX0("E"),
    .DEMUX1("E"),
    .GSR("DISABLE"),
    .INIT_LUTF0(16'hA55A),
    .INIT_LUTF1(16'hA55A),
    .INIT_LUTG0(16'hC33C),
    .INIT_LUTG1(16'hC33C),
    .LSFMUX0("SUM"),
    .LSFMUX1("SUM"),
    .LSFXMUX0("SUM"),
    .LSFXMUX1("SUM"),
    .MODE("RIPPLE"))
    \add0/u3_al_u185  (
    .a({IVT0[7],IVT0[5]}),
    .b({IVT1[0],IVT0[6]}),
    .c(2'b00),
    .d({\IVE_SIZE_SHIFTER/shift_stages[2] [5],\IVE_SIZE_SHIFTER/shift_stages[2] [3]}),
    .e({1'b0,\IVE_SIZE_SHIFTER/shift_stages[2] [4]}),
    .fci(\add0/c3 ),
    .f({n5[5],n5[3]}),
    .fco(\add0/c7 ),
    .fx({n5[6],n5[4]}));
  AL_PHY_LSLICE #(
    //.MACRO("add0/ucin_al_u184"),
    //.R_POSITION("X0Y1Z0"),
    .DEMUX0("E"),
    .DEMUX1("E"),
    .GSR("DISABLE"),
    .INIT_LUTF0(16'hA55A),
    .INIT_LUTF1(16'hA55A),
    .INIT_LUTG0(16'hC33C),
    .INIT_LUTG1(16'hC33C),
    .LSFMUX0("SUM"),
    .LSFMUX1("SUM"),
    .LSFXMUX0("SUM"),
    .LSFXMUX1("SUM"),
    .MODE("RIPPLE"))
    \add0/u7_al_u186  (
    .a({IVT1[3],IVT1[1]}),
    .b({IVT1[4],IVT1[2]}),
    .c(2'b00),
    .d(2'b00),
    .e(2'b00),
    .fci(\add0/c7 ),
    .f({n5[9],n5[7]}),
    .fco(\add0/c11 ),
    .fx({n5[10],n5[8]}));
  AL_PHY_LSLICE #(
    //.MACRO("add0/ucin_al_u184"),
    //.R_POSITION("X0Y0Z0"),
    .DEMUX0("E"),
    .DEMUX1("E"),
    .GSR("DISABLE"),
    .INIT_LUTF0(16'h000A),
    .INIT_LUTF1(16'hA55A),
    .INIT_LUTG0(16'hC33C),
    .INIT_LUTG1(16'hC33C),
    .LSFMUX0("SUM"),
    .LSFMUX1("SUM"),
    .LSFXMUX0("SUM"),
    .LSFXMUX1("SUM"),
    .MODE("RIPPLE"))
    \add0/ucin_al_u184  (
    .a({IVT0[3],1'b0}),
    .b({IVT0[4],IVT0[2]}),
    .c(2'b00),
    .d({\IVE_SIZE_SHIFTER/shift_stages[2] [1],1'b1}),
    .e({\IVE_SIZE_SHIFTER/shift_stages[2] [2],\IVE_SIZE_SHIFTER/shift_stages[2] [0]}),
    .f({n5[1],open_n114}),
    .fco(\add0/c3 ),
    .fx({n5[2],n5[0]}));
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b0 (
    .ce(mux13_b0_sel_is_2_o),
    .clk(clk),
    .d(IVT0[0]),
    .q(IVEC_ADDR[0]));  // ../RTL/peripherals/int_ctrl.v(86)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b1 (
    .ce(mux13_b0_sel_is_2_o),
    .clk(clk),
    .d(IVT0[1]),
    .q(IVEC_ADDR[1]));  // ../RTL/peripherals/int_ctrl.v(86)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b10 (
    .ce(mux13_b0_sel_is_2_o),
    .clk(clk),
    .d(n5[8]),
    .q(IVEC_ADDR[10]));  // ../RTL/peripherals/int_ctrl.v(86)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b11 (
    .ce(mux13_b0_sel_is_2_o),
    .clk(clk),
    .d(n5[9]),
    .q(IVEC_ADDR[11]));  // ../RTL/peripherals/int_ctrl.v(86)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b12 (
    .ce(mux13_b0_sel_is_2_o),
    .clk(clk),
    .d(n5[10]),
    .q(IVEC_ADDR[12]));  // ../RTL/peripherals/int_ctrl.v(86)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b13 (
    .ce(mux13_b0_sel_is_2_o),
    .clk(clk),
    .d(n5[11]),
    .q(IVEC_ADDR[13]));  // ../RTL/peripherals/int_ctrl.v(86)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b14 (
    .ce(mux13_b0_sel_is_2_o),
    .clk(clk),
    .d(n5[12]),
    .q(IVEC_ADDR[14]));  // ../RTL/peripherals/int_ctrl.v(86)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b15 (
    .ce(mux13_b0_sel_is_2_o),
    .clk(clk),
    .d(n5[13]),
    .q(IVEC_ADDR[15]));  // ../RTL/peripherals/int_ctrl.v(86)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b16 (
    .ce(mux13_b0_sel_is_2_o),
    .clk(clk),
    .d(n5[14]),
    .q(IVEC_ADDR[16]));  // ../RTL/peripherals/int_ctrl.v(86)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b17 (
    .ce(mux13_b0_sel_is_2_o),
    .clk(clk),
    .d(n5[15]),
    .q(IVEC_ADDR[17]));  // ../RTL/peripherals/int_ctrl.v(86)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b18 (
    .ce(mux13_b0_sel_is_2_o),
    .clk(clk),
    .d(n5[16]),
    .q(IVEC_ADDR[18]));  // ../RTL/peripherals/int_ctrl.v(86)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b19 (
    .ce(mux13_b0_sel_is_2_o),
    .clk(clk),
    .d(n5[17]),
    .q(IVEC_ADDR[19]));  // ../RTL/peripherals/int_ctrl.v(86)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b2 (
    .ce(mux13_b0_sel_is_2_o),
    .clk(clk),
    .d(n5[0]),
    .q(IVEC_ADDR[2]));  // ../RTL/peripherals/int_ctrl.v(86)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b20 (
    .ce(mux13_b0_sel_is_2_o),
    .clk(clk),
    .d(n5[18]),
    .q(IVEC_ADDR[20]));  // ../RTL/peripherals/int_ctrl.v(86)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b21 (
    .ce(mux13_b0_sel_is_2_o),
    .clk(clk),
    .d(n5[19]),
    .q(IVEC_ADDR[21]));  // ../RTL/peripherals/int_ctrl.v(86)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b22 (
    .ce(mux13_b0_sel_is_2_o),
    .clk(clk),
    .d(n5[20]),
    .q(IVEC_ADDR[22]));  // ../RTL/peripherals/int_ctrl.v(86)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b3 (
    .ce(mux13_b0_sel_is_2_o),
    .clk(clk),
    .d(n5[1]),
    .q(IVEC_ADDR[3]));  // ../RTL/peripherals/int_ctrl.v(86)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b4 (
    .ce(mux13_b0_sel_is_2_o),
    .clk(clk),
    .d(n5[2]),
    .q(IVEC_ADDR[4]));  // ../RTL/peripherals/int_ctrl.v(86)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b5 (
    .ce(mux13_b0_sel_is_2_o),
    .clk(clk),
    .d(n5[3]),
    .q(IVEC_ADDR[5]));  // ../RTL/peripherals/int_ctrl.v(86)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b6 (
    .ce(mux13_b0_sel_is_2_o),
    .clk(clk),
    .d(n5[4]),
    .q(IVEC_ADDR[6]));  // ../RTL/peripherals/int_ctrl.v(86)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b7 (
    .ce(mux13_b0_sel_is_2_o),
    .clk(clk),
    .d(n5[5]),
    .q(IVEC_ADDR[7]));  // ../RTL/peripherals/int_ctrl.v(86)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b8 (
    .ce(mux13_b0_sel_is_2_o),
    .clk(clk),
    .d(n5[6]),
    .q(IVEC_ADDR[8]));  // ../RTL/peripherals/int_ctrl.v(86)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg0_b9 (
    .ce(mux13_b0_sel_is_2_o),
    .clk(clk),
    .d(n5[7]),
    .q(IVEC_ADDR[9]));  // ../RTL/peripherals/int_ctrl.v(86)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    reg1_b0 (
    .ce(mux25_b0_sel_is_3_o),
    .clk(clk),
    .d(WB_DATi[0]),
    .sr(rst),
    .q(INTC[0]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    reg1_b1 (
    .ce(mux25_b0_sel_is_3_o),
    .clk(clk),
    .d(WB_DATi[1]),
    .sr(rst),
    .q(INTC[1]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    reg1_b2 (
    .ce(mux25_b0_sel_is_3_o),
    .clk(clk),
    .d(WB_DATi[7]),
    .sr(rst),
    .q(INTC[2]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg2_b0 (
    .ce(mux26_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[0]),
    .q(EXPE0[0]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg2_b1 (
    .ce(mux26_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[1]),
    .q(EXPE0[1]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg2_b2 (
    .ce(mux26_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[2]),
    .q(EXPE0[2]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg2_b3 (
    .ce(mux26_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[3]),
    .q(EXPE0[3]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg2_b4 (
    .ce(mux26_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[4]),
    .q(EXPE0[4]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg2_b5 (
    .ce(mux26_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[5]),
    .q(EXPE0[5]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg2_b6 (
    .ce(mux26_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[6]),
    .q(EXPE0[6]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg2_b7 (
    .ce(mux26_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[7]),
    .q(EXPE0[7]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b0 (
    .ce(mux27_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[0]),
    .q(INTE0[0]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b1 (
    .ce(mux27_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[1]),
    .q(INTE0[1]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b2 (
    .ce(mux27_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[2]),
    .q(INTE0[2]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b3 (
    .ce(mux27_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[3]),
    .q(INTE0[3]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b4 (
    .ce(mux27_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[4]),
    .q(INTE0[4]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b5 (
    .ce(mux27_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[5]),
    .q(INTE0[5]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b6 (
    .ce(mux27_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[6]),
    .q(INTE0[6]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b7 (
    .ce(mux27_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[7]),
    .q(INTE0[7]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg4_b0 (
    .ce(mux28_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[0]),
    .q(IVT2[0]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg4_b1 (
    .ce(mux28_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[1]),
    .q(IVT2[1]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg4_b2 (
    .ce(mux28_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[2]),
    .q(IVT2[2]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg4_b3 (
    .ce(mux28_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[3]),
    .q(IVT2[3]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg4_b4 (
    .ce(mux28_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[4]),
    .q(IVT2[4]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg4_b5 (
    .ce(mux28_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[5]),
    .q(IVT2[5]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg4_b6 (
    .ce(mux28_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[6]),
    .q(IVT2[6]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg4_b7 (
    .ce(mux28_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[7]),
    .q(IVT2[7]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg5_b0 (
    .ce(mux29_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[0]),
    .q(IVT1[0]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg5_b1 (
    .ce(mux29_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[1]),
    .q(IVT1[1]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg5_b2 (
    .ce(mux29_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[2]),
    .q(IVT1[2]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg5_b3 (
    .ce(mux29_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[3]),
    .q(IVT1[3]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg5_b4 (
    .ce(mux29_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[4]),
    .q(IVT1[4]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg5_b5 (
    .ce(mux29_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[5]),
    .q(IVT1[5]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg5_b6 (
    .ce(mux29_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[6]),
    .q(IVT1[6]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg5_b7 (
    .ce(mux29_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[7]),
    .q(IVT1[7]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg6_b0 (
    .ce(mux30_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[0]),
    .q(IVT0[0]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg6_b1 (
    .ce(mux30_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[1]),
    .q(IVT0[1]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg6_b2 (
    .ce(mux30_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[2]),
    .q(IVT0[2]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg6_b3 (
    .ce(mux30_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[3]),
    .q(IVT0[3]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg6_b4 (
    .ce(mux30_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[4]),
    .q(IVT0[4]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg6_b5 (
    .ce(mux30_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[5]),
    .q(IVT0[5]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg6_b6 (
    .ce(mux30_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[6]),
    .q(IVT0[6]));  // ../RTL/peripherals/int_ctrl.v(120)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg6_b7 (
    .ce(mux30_b0_sel_is_2_o),
    .clk(clk),
    .d(WB_DATi[7]),
    .q(IVT0[7]));  // ../RTL/peripherals/int_ctrl.v(120)

endmodule 

module sys_ctrl  // ../RTL/peripherals/sys_ctrl.v(22)
  (
  MNMX,
  SYSCALL_info,
  SYSCALL_num,
  WB_ADRi,
  WB_CYCi,
  WB_DATi,
  WB_STBi,
  WB_WEi,
  clki,
  reset_req,
  rsti,
  ALWAYS_SVM,
  ASYNC_WAITCYCLE,
  HPAGE_BASEADDR,
  PAE_ENABLE,
  SYNC_MODE,
  SYSCALL_clr,
  WB_ACKo,
  WB_DATo,
  clk,
  dpae_h16,
  dpte_h8,
  ipae_h16,
  ipte_h8,
  lclk,
  rst
  );

  input MNMX;  // ../RTL/peripherals/sys_ctrl.v(30)
  input [7:0] SYSCALL_info;  // ../RTL/peripherals/sys_ctrl.v(32)
  input [7:0] SYSCALL_num;  // ../RTL/peripherals/sys_ctrl.v(31)
  input [3:0] WB_ADRi;  // ../RTL/peripherals/sys_ctrl.v(47)
  input WB_CYCi;  // ../RTL/peripherals/sys_ctrl.v(51)
  input [7:0] WB_DATi;  // ../RTL/peripherals/sys_ctrl.v(49)
  input WB_STBi;  // ../RTL/peripherals/sys_ctrl.v(52)
  input WB_WEi;  // ../RTL/peripherals/sys_ctrl.v(50)
  input clki;  // ../RTL/peripherals/sys_ctrl.v(24)
  input reset_req;  // ../RTL/peripherals/sys_ctrl.v(25)
  input rsti;  // ../RTL/peripherals/sys_ctrl.v(24)
  output ALWAYS_SVM;  // ../RTL/peripherals/sys_ctrl.v(41)
  output [6:0] ASYNC_WAITCYCLE;  // ../RTL/peripherals/sys_ctrl.v(35)
  output [10:0] HPAGE_BASEADDR;  // ../RTL/peripherals/sys_ctrl.v(37)
  output PAE_ENABLE;  // ../RTL/peripherals/sys_ctrl.v(38)
  output SYNC_MODE;  // ../RTL/peripherals/sys_ctrl.v(34)
  output SYSCALL_clr;  // ../RTL/peripherals/sys_ctrl.v(29)
  output WB_ACKo;  // ../RTL/peripherals/sys_ctrl.v(53)
  output [7:0] WB_DATo;  // ../RTL/peripherals/sys_ctrl.v(48)
  output clk;  // ../RTL/peripherals/sys_ctrl.v(26)
  output [15:0] dpae_h16;  // ../RTL/peripherals/sys_ctrl.v(43)
  output [7:0] dpte_h8;  // ../RTL/peripherals/sys_ctrl.v(45)
  output [15:0] ipae_h16;  // ../RTL/peripherals/sys_ctrl.v(42)
  output [7:0] ipte_h8;  // ../RTL/peripherals/sys_ctrl.v(44)
  output lclk;  // ../RTL/peripherals/sys_ctrl.v(26)
  output rst;  // ../RTL/peripherals/sys_ctrl.v(27)

  wire  \mux26_b0/B0_1 ;  // ../RTL/peripherals/sys_ctrl.v(140)
  wire  \mux26_b1/B0_1 ;  // ../RTL/peripherals/sys_ctrl.v(140)
  wire  \mux26_b2/B0_1 ;  // ../RTL/peripherals/sys_ctrl.v(140)
  wire  \mux26_b3/B0_1 ;  // ../RTL/peripherals/sys_ctrl.v(140)
  wire  \mux26_b3/B0_6 ;  // ../RTL/peripherals/sys_ctrl.v(140)
  wire  \mux26_b3/B0_7 ;  // ../RTL/peripherals/sys_ctrl.v(140)
  wire  \mux26_b5/B0_1 ;  // ../RTL/peripherals/sys_ctrl.v(140)
  wire  \mux26_b6/B0_1 ;  // ../RTL/peripherals/sys_ctrl.v(140)
  wire  \mux26_b6/B0_2 ;  // ../RTL/peripherals/sys_ctrl.v(140)
  wire  \mux26_b7/B0_1 ;  // ../RTL/peripherals/sys_ctrl.v(140)
  wire [7:0] n24;
  wire \ANLOGIC_SYSPLL/clk0_buf ;  // al_ip/pll.v(32)
  wire _al_u172_o;
  wire _al_u178_o;
  wire _al_u179_o;
  wire _al_u184_o;
  wire _al_u185_o;
  wire _al_u190_o;
  wire _al_u192_o;
  wire _al_u193_o;
  wire _al_u194_o;
  wire _al_u195_o;
  wire _al_u196_o;
  wire _al_u199_o;
  wire _al_u200_o;
  wire _al_u201_o;
  wire _al_u202_o;
  wire _al_u203_o;
  wire _al_u206_o;
  wire _al_u207_o;
  wire _al_u208_o;
  wire _al_u209_o;
  wire _al_u210_o;
  wire _al_u214_o;
  wire _al_u215_o;
  wire _al_u217_o;
  wire _al_u219_o;
  wire _al_u220_o;
  wire _al_u221_o;
  wire _al_u222_o;
  wire _al_u223_o;
  wire _al_u226_o;
  wire _al_u227_o;
  wire _al_u228_o;
  wire _al_u229_o;
  wire _al_u232_o;
  wire _al_u233_o;
  wire _al_u235_o;
  wire _al_u236_o;
  wire _al_u237_o;
  wire _al_u241_o;
  wire _al_u242_o;
  wire _al_u243_o;
  wire _al_u245_o;
  wire _al_u246_o;
  wire _al_u247_o;
  wire clki_pad;  // ../RTL/peripherals/sys_ctrl.v(24)
  wire mux17_b0_sel_is_3_o;
  wire mux18_b0_sel_is_3_o;
  wire mux19_b0_sel_is_2_o;
  wire mux20_b0_sel_is_2_o;
  wire mux21_b0_sel_is_2_o;
  wire mux22_b0_sel_is_2_o;
  wire mux23_b0_sel_is_2_o;
  wire mux24_b0_sel_is_2_o;
  wire mux25_b0_sel_is_2_o;
  wire mux25_b10_sel_is_2_o;
  wire mux8_b0_sel_is_4_o;
  wire n1;
  wire n26;
  wire n5;
  wire net_reg8_b7_d0;
  wire net_reg8_b7_reset_q0;
  wire net_reg8_b7_sel0;
  wire net_reg8_b7_set_q0;
  wire pll_lock;  // ../RTL/peripherals/sys_ctrl.v(65)
  wire scall_en;  // ../RTL/peripherals/sys_ctrl.v(64)
  wire u19_sel_is_3_o;
  wire wb_write;  // ../RTL/peripherals/sys_ctrl.v(68)

  assign WB_ACKo = 1'b1;
  assign clk = lclk;
  AL_PHY_GCLK \ANLOGIC_SYSPLL/bufg_feedback  (
    .clki(\ANLOGIC_SYSPLL/clk0_buf ),
    .clko(lclk));  // al_ip/pll.v(34)
  AL_PHY_PLL #(
    .CLKC0_CPHASE(20),
    .CLKC0_DIV(21),
    .CLKC0_ENABLE("ENABLE"),
    .CLKC0_FPHASE("0"),
    .CLKC1_CPHASE(1),
    .CLKC1_DIV(1),
    .CLKC1_ENABLE("DISABLE"),
    .CLKC1_FPHASE("0"),
    .CLKC2_CPHASE(1),
    .CLKC2_DIV(1),
    .CLKC2_ENABLE("DISABLE"),
    .CLKC2_FPHASE("0"),
    .CLKC3_CPHASE(1),
    .CLKC3_DIV(1),
    .CLKC3_ENABLE("DISABLE"),
    .CLKC3_FPHASE("0"),
    .CLKC4_CPHASE(1),
    .CLKC4_DIV(1),
    .CLKC4_ENABLE("DISABLE"),
    .CLKC4_FPHASE("0"),
    .DERIVE_PLL_CLOCKS("DISABLE"),
    .DPHASE_SOURCE("DISABLE"),
    .FBCLK_DIV(2),
    .FEEDBK_MODE("NORMAL"),
    .FEEDBK_PATH("CLKC0_EXT"),
    .FIN("24.000"),
    .FREQ_LOCK_ACCURACY("2"),
    .GEN_BASIC_CLOCK("DISABLE"),
    .GMC_GAIN("2"),
    .GMC_TEST("14"),
    .ICP_CURRENT(9),
    .INTFB_WAKE("DISABLE"),
    .INT_FEEDBK_PATH("VCO_PHASE_0"),
    .KVCO("2"),
    .LPF_CAPACITOR("1"),
    .LPF_RESISTOR(8),
    .NORESET("DISABLE"),
    .ODIV_MUXC0("DIV"),
    .ODIV_MUXC1("DIV"),
    .ODIV_MUXC2("DIV"),
    .ODIV_MUXC3("DIV"),
    .ODIV_MUXC4("DIV"),
    .PLLC2RST_ENA("DISABLE"),
    .PLLC34RST_ENA("DISABLE"),
    .PLLMRST_ENA("DISABLE"),
    .PLLRST_ENA("ENABLE"),
    .PLL_LOCK_MODE("0"),
    .PREDIV_MUXC0("VCO"),
    .PREDIV_MUXC1("VCO"),
    .PREDIV_MUXC2("VCO"),
    .PREDIV_MUXC3("VCO"),
    .PREDIV_MUXC4("VCO"),
    .REFCLK_DIV(1),
    .REFCLK_SEL("INTERNAL"),
    .STDBY_ENABLE("DISABLE"),
    .STDBY_VCO_ENA("DISABLE"),
    .SYNC_ENABLE("DISABLE"),
    .VCO_NORESET("DISABLE"))
    \ANLOGIC_SYSPLL/pll_inst  (
    .fbclk(lclk),
    .load_reg(1'b0),
    .phasestep(1'b0),
    .phaseupdown(1'b0),
    .phcntsel(3'b000),
    .pllreset(rsti),
    .refclk(clki_pad),
    .scanclk(1'b0),
    .stdby(1'b0),
    .clkc({open_n0,open_n1,open_n2,open_n3,\ANLOGIC_SYSPLL/clk0_buf }),
    .ext_lock(pll_lock));  // al_ip/pll.v(56)
  AL_PHY_PAD #(
    //.PCICLAMP("OFF"),
    //.PULLMODE("PULLUP"),
    .GSR("DISABLE"),
    .IOTYPE("LVCMOS25"),
    .MODE("IN"),
    .TSMUX("1"))
    _al_u166 (
    .ipad(clki),
    .di(clki_pad));  // ../RTL/peripherals/sys_ctrl.v(24)
  AL_MAP_LUT3 #(
    .EQN("(A*~(C)*~(B)+A*C*~(B)+~(A)*C*B+A*C*B)"),
    .INIT(8'he2))
    _al_u168 (
    .a(net_reg8_b7_reset_q0),
    .b(net_reg8_b7_sel0),
    .c(net_reg8_b7_set_q0),
    .o(SYNC_MODE));
  AL_MAP_LUT2 #(
    .EQN("(B*A)"),
    .INIT(4'h8))
    _al_u169 (
    .a(MNMX),
    .b(rst),
    .o(n1));
  AL_MAP_LUT2 #(
    .EQN("(B*~A)"),
    .INIT(4'h4))
    _al_u170 (
    .a(MNMX),
    .b(rst),
    .o(n26));
  AL_MAP_LUT3 #(
    .EQN("(C*B*A)"),
    .INIT(8'h80))
    _al_u171 (
    .a(WB_CYCi),
    .b(WB_STBi),
    .c(WB_WEi),
    .o(wb_write));
  AL_MAP_LUT2 #(
    .EQN("(B*~A)"),
    .INIT(4'h4))
    _al_u172 (
    .a(WB_ADRi[1]),
    .b(WB_ADRi[0]),
    .o(_al_u172_o));
  AL_MAP_LUT4 #(
    .EQN("(~D*~C*B*A)"),
    .INIT(16'h0008))
    _al_u173 (
    .a(wb_write),
    .b(_al_u172_o),
    .c(WB_ADRi[3]),
    .d(WB_ADRi[2]),
    .o(u19_sel_is_3_o));
  AL_MAP_LUT4 #(
    .EQN("(~D*~C*B*~A)"),
    .INIT(16'h0004))
    _al_u174 (
    .a(WB_ADRi[3]),
    .b(WB_ADRi[2]),
    .c(WB_ADRi[1]),
    .d(WB_ADRi[0]),
    .o(mux8_b0_sel_is_4_o));
  AL_MAP_LUT2 #(
    .EQN("(B*A)"),
    .INIT(4'h8))
    _al_u175 (
    .a(mux8_b0_sel_is_4_o),
    .b(wb_write),
    .o(mux18_b0_sel_is_3_o));
  AL_MAP_LUT4 #(
    .EQN("(D*~C*B*A)"),
    .INIT(16'h0800))
    _al_u176 (
    .a(wb_write),
    .b(_al_u172_o),
    .c(WB_ADRi[3]),
    .d(WB_ADRi[2]),
    .o(mux17_b0_sel_is_3_o));
  AL_MAP_LUT4 #(
    .EQN("(B*~(D)*~((C*A))+B*D*~((C*A))+~(B)*D*(C*A)+B*D*(C*A))"),
    .INIT(16'hec4c))
    _al_u177 (
    .a(mux8_b0_sel_is_4_o),
    .b(SYNC_MODE),
    .c(wb_write),
    .d(WB_DATi[7]),
    .o(n24[7]));
  AL_MAP_LUT2 #(
    .EQN("(~B*A)"),
    .INIT(4'h2))
    _al_u178 (
    .a(WB_ADRi[3]),
    .b(WB_ADRi[2]),
    .o(_al_u178_o));
  AL_MAP_LUT2 #(
    .EQN("(B*A)"),
    .INIT(4'h8))
    _al_u179 (
    .a(wb_write),
    .b(_al_u178_o),
    .o(_al_u179_o));
  AL_MAP_LUT4 #(
    .EQN("(~D*~C*~B*A)"),
    .INIT(16'h0002))
    _al_u180 (
    .a(_al_u179_o),
    .b(WB_ADRi[1]),
    .c(WB_ADRi[0]),
    .d(rst),
    .o(mux25_b10_sel_is_2_o));
  AL_MAP_LUT3 #(
    .EQN("(~C*B*A)"),
    .INIT(8'h08))
    _al_u181 (
    .a(_al_u179_o),
    .b(_al_u172_o),
    .c(rst),
    .o(mux25_b0_sel_is_2_o));
  AL_MAP_LUT4 #(
    .EQN("(~D*~C*B*A)"),
    .INIT(16'h0008))
    _al_u182 (
    .a(_al_u179_o),
    .b(WB_ADRi[1]),
    .c(WB_ADRi[0]),
    .d(rst),
    .o(mux24_b0_sel_is_2_o));
  AL_MAP_LUT4 #(
    .EQN("(~D*C*B*A)"),
    .INIT(16'h0080))
    _al_u183 (
    .a(_al_u179_o),
    .b(WB_ADRi[1]),
    .c(WB_ADRi[0]),
    .d(rst),
    .o(mux23_b0_sel_is_2_o));
  AL_MAP_LUT2 #(
    .EQN("(B*A)"),
    .INIT(4'h8))
    _al_u184 (
    .a(WB_ADRi[3]),
    .b(WB_ADRi[2]),
    .o(_al_u184_o));
  AL_MAP_LUT2 #(
    .EQN("(B*A)"),
    .INIT(4'h8))
    _al_u185 (
    .a(wb_write),
    .b(_al_u184_o),
    .o(_al_u185_o));
  AL_MAP_LUT4 #(
    .EQN("(~D*~C*~B*A)"),
    .INIT(16'h0002))
    _al_u186 (
    .a(_al_u185_o),
    .b(WB_ADRi[1]),
    .c(WB_ADRi[0]),
    .d(rst),
    .o(mux22_b0_sel_is_2_o));
  AL_MAP_LUT3 #(
    .EQN("(~C*B*A)"),
    .INIT(8'h08))
    _al_u187 (
    .a(_al_u185_o),
    .b(_al_u172_o),
    .c(rst),
    .o(mux21_b0_sel_is_2_o));
  AL_MAP_LUT4 #(
    .EQN("(~D*~C*B*A)"),
    .INIT(16'h0008))
    _al_u188 (
    .a(_al_u185_o),
    .b(WB_ADRi[1]),
    .c(WB_ADRi[0]),
    .d(rst),
    .o(mux20_b0_sel_is_2_o));
  AL_MAP_LUT4 #(
    .EQN("(~D*C*B*A)"),
    .INIT(16'h0080))
    _al_u189 (
    .a(_al_u185_o),
    .b(WB_ADRi[1]),
    .c(WB_ADRi[0]),
    .d(rst),
    .o(mux19_b0_sel_is_2_o));
  AL_MAP_LUT3 #(
    .EQN("(C*~B*~A)"),
    .INIT(8'h10))
    _al_u190 (
    .a(WB_ADRi[3]),
    .b(WB_ADRi[2]),
    .c(WB_ADRi[1]),
    .o(_al_u190_o));
  AL_MAP_LUT3 #(
    .EQN("(B*~(A)*~(C)+B*A*~(C)+~(B)*A*C+B*A*C)"),
    .INIT(8'hac))
    _al_u191 (
    .a(SYSCALL_info[0]),
    .b(SYSCALL_num[0]),
    .c(WB_ADRi[0]),
    .o(\mux26_b0/B0_1 ));
  AL_MAP_LUT4 #(
    .EQN("(~(C*B)*~(D*A))"),
    .INIT(16'h153f))
    _al_u192 (
    .a(mux8_b0_sel_is_4_o),
    .b(_al_u190_o),
    .c(\mux26_b0/B0_1 ),
    .d(ASYNC_WAITCYCLE[0]),
    .o(_al_u192_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)+A*~(B)*~(C)*~(D)+A*B*~(C)*~(D)+~(A)*~(B)*C*~(D)+~(A)*~(B)*~(C)*D+~(A)*B*~(C)*D+~(A)*~(B)*C*D+~(A)*B*C*D)"),
    .INIT(16'h551b))
    _al_u193 (
    .a(WB_ADRi[0]),
    .b(ipae_h16[8]),
    .c(dpte_h8[0]),
    .d(WB_ADRi[1]),
    .o(_al_u193_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*C*~(D)+A*~(B)*C*~(D)+~(A)*B*C*~(D)+A*B*C*~(D)+~(A)*~(B)*~(C)*D+~(A)*B*~(C)*D+~(A)*~(B)*C*D+A*~(B)*C*D)"),
    .INIT(16'h35f0))
    _al_u194 (
    .a(dpae_h16[8]),
    .b(dpae_h16[0]),
    .c(_al_u193_o),
    .d(WB_ADRi[1]),
    .o(_al_u194_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)+A*~(B)*~(C)*~(D)+A*B*~(C)*~(D)+~(A)*~(B)*C*~(D)+~(A)*~(B)*~(C)*D+~(A)*B*~(C)*D+~(A)*~(B)*C*D+~(A)*B*C*D)"),
    .INIT(16'h551b))
    _al_u195 (
    .a(WB_ADRi[0]),
    .b(HPAGE_BASEADDR[8]),
    .c(HPAGE_BASEADDR[0]),
    .d(WB_ADRi[1]),
    .o(_al_u195_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*C*~(D)+A*~(B)*C*~(D)+~(A)*B*C*~(D)+A*B*C*~(D)+~(A)*~(B)*~(C)*D+~(A)*B*~(C)*D+~(A)*~(B)*C*D+A*~(B)*C*D)"),
    .INIT(16'h35f0))
    _al_u196 (
    .a(ipae_h16[0]),
    .b(ipte_h8[0]),
    .c(_al_u195_o),
    .d(WB_ADRi[1]),
    .o(_al_u196_o));
  AL_MAP_LUT5 #(
    .EQN("~(A*~(D*~(C*~(B)*~(E)+C*B*~(E)+~(C)*B*E+C*B*E)))"),
    .INIT(32'h77555f55))
    _al_u197 (
    .a(_al_u192_o),
    .b(_al_u194_o),
    .c(_al_u196_o),
    .d(WB_ADRi[3]),
    .e(WB_ADRi[2]),
    .o(WB_DATo[0]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(A)*~(C)+B*A*~(C)+~(B)*A*C+B*A*C)"),
    .INIT(8'hac))
    _al_u198 (
    .a(SYSCALL_info[1]),
    .b(SYSCALL_num[1]),
    .c(WB_ADRi[0]),
    .o(\mux26_b1/B0_1 ));
  AL_MAP_LUT4 #(
    .EQN("(~(C*B)*~(D*A))"),
    .INIT(16'h153f))
    _al_u199 (
    .a(mux8_b0_sel_is_4_o),
    .b(_al_u190_o),
    .c(\mux26_b1/B0_1 ),
    .d(ASYNC_WAITCYCLE[1]),
    .o(_al_u199_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)+A*~(B)*~(C)*~(D)+A*B*~(C)*~(D)+~(A)*~(B)*C*~(D)+~(A)*~(B)*~(C)*D+~(A)*B*~(C)*D+~(A)*~(B)*C*D+~(A)*B*C*D)"),
    .INIT(16'h551b))
    _al_u200 (
    .a(WB_ADRi[0]),
    .b(ipae_h16[9]),
    .c(dpte_h8[1]),
    .d(WB_ADRi[1]),
    .o(_al_u200_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*C*~(D)+A*~(B)*C*~(D)+~(A)*B*C*~(D)+A*B*C*~(D)+~(A)*~(B)*~(C)*D+~(A)*B*~(C)*D+~(A)*~(B)*C*D+A*~(B)*C*D)"),
    .INIT(16'h35f0))
    _al_u201 (
    .a(dpae_h16[9]),
    .b(dpae_h16[1]),
    .c(_al_u200_o),
    .d(WB_ADRi[1]),
    .o(_al_u201_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)+A*~(B)*~(C)*~(D)+A*B*~(C)*~(D)+~(A)*~(B)*C*~(D)+~(A)*~(B)*~(C)*D+~(A)*B*~(C)*D+~(A)*~(B)*C*D+~(A)*B*C*D)"),
    .INIT(16'h551b))
    _al_u202 (
    .a(WB_ADRi[0]),
    .b(HPAGE_BASEADDR[9]),
    .c(HPAGE_BASEADDR[1]),
    .d(WB_ADRi[1]),
    .o(_al_u202_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*C*~(D)+A*~(B)*C*~(D)+~(A)*B*C*~(D)+A*B*C*~(D)+~(A)*~(B)*~(C)*D+~(A)*B*~(C)*D+~(A)*~(B)*C*D+A*~(B)*C*D)"),
    .INIT(16'h35f0))
    _al_u203 (
    .a(ipae_h16[1]),
    .b(ipte_h8[1]),
    .c(_al_u202_o),
    .d(WB_ADRi[1]),
    .o(_al_u203_o));
  AL_MAP_LUT5 #(
    .EQN("~(A*~(D*~(C*~(B)*~(E)+C*B*~(E)+~(C)*B*E+C*B*E)))"),
    .INIT(32'h77555f55))
    _al_u204 (
    .a(_al_u199_o),
    .b(_al_u201_o),
    .c(_al_u203_o),
    .d(WB_ADRi[3]),
    .e(WB_ADRi[2]),
    .o(WB_DATo[1]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(A)*~(C)+B*A*~(C)+~(B)*A*C+B*A*C)"),
    .INIT(8'hac))
    _al_u205 (
    .a(SYSCALL_info[2]),
    .b(SYSCALL_num[2]),
    .c(WB_ADRi[0]),
    .o(\mux26_b2/B0_1 ));
  AL_MAP_LUT4 #(
    .EQN("(~(C*B)*~(D*A))"),
    .INIT(16'h153f))
    _al_u206 (
    .a(mux8_b0_sel_is_4_o),
    .b(_al_u190_o),
    .c(\mux26_b2/B0_1 ),
    .d(ASYNC_WAITCYCLE[2]),
    .o(_al_u206_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)+A*~(B)*~(C)*~(D)+A*B*~(C)*~(D)+~(A)*~(B)*C*~(D)+~(A)*~(B)*~(C)*D+~(A)*B*~(C)*D+~(A)*~(B)*C*D+~(A)*B*C*D)"),
    .INIT(16'h551b))
    _al_u207 (
    .a(WB_ADRi[0]),
    .b(ipae_h16[10]),
    .c(dpte_h8[2]),
    .d(WB_ADRi[1]),
    .o(_al_u207_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*C*~(D)+A*~(B)*C*~(D)+~(A)*B*C*~(D)+A*B*C*~(D)+~(A)*~(B)*~(C)*D+~(A)*B*~(C)*D+~(A)*~(B)*C*D+A*~(B)*C*D)"),
    .INIT(16'h35f0))
    _al_u208 (
    .a(dpae_h16[10]),
    .b(dpae_h16[2]),
    .c(_al_u207_o),
    .d(WB_ADRi[1]),
    .o(_al_u208_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)+A*~(B)*~(C)*~(D)+~(A)*B*~(C)*~(D)+A*~(B)*C*~(D)+~(A)*~(B)*~(C)*D+~(A)*B*~(C)*D+~(A)*~(B)*C*D+~(A)*B*C*D)"),
    .INIT(16'h5527))
    _al_u209 (
    .a(WB_ADRi[0]),
    .b(HPAGE_BASEADDR[2]),
    .c(HPAGE_BASEADDR[10]),
    .d(WB_ADRi[1]),
    .o(_al_u209_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*C*~(D)+A*~(B)*C*~(D)+~(A)*B*C*~(D)+A*B*C*~(D)+~(A)*~(B)*~(C)*D+~(A)*B*~(C)*D+~(A)*~(B)*C*D+A*~(B)*C*D)"),
    .INIT(16'h35f0))
    _al_u210 (
    .a(ipae_h16[2]),
    .b(ipte_h8[2]),
    .c(_al_u209_o),
    .d(WB_ADRi[1]),
    .o(_al_u210_o));
  AL_MAP_LUT5 #(
    .EQN("~(A*~(D*~(C*~(B)*~(E)+C*B*~(E)+~(C)*B*E+C*B*E)))"),
    .INIT(32'h77555f55))
    _al_u211 (
    .a(_al_u206_o),
    .b(_al_u208_o),
    .c(_al_u210_o),
    .d(WB_ADRi[3]),
    .e(WB_ADRi[2]),
    .o(WB_DATo[2]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u212 (
    .a(WB_ADRi[0]),
    .b(dpae_h16[11]),
    .c(dpae_h16[3]),
    .o(\mux26_b3/B0_7 ));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u213 (
    .a(WB_ADRi[0]),
    .b(dpte_h8[3]),
    .c(ipae_h16[11]),
    .o(\mux26_b3/B0_6 ));
  AL_MAP_LUT4 #(
    .EQN("(C*(B*~(A)*~(D)+B*A*~(D)+~(B)*A*D+B*A*D))"),
    .INIT(16'ha0c0))
    _al_u214 (
    .a(\mux26_b3/B0_7 ),
    .b(\mux26_b3/B0_6 ),
    .c(_al_u184_o),
    .d(WB_ADRi[1]),
    .o(_al_u214_o));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+A*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+~(A)*~(B)*~(C)*~(D)*E+A*~(B)*~(C)*~(D)*E+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*~(B)*C*~(D)*E+~(A)*~(B)*~(C)*D*E+A*B*~(C)*D*E+~(A)*~(B)*C*D*E)"),
    .INIT(32'h193b5d7f))
    _al_u215 (
    .a(WB_ADRi[1]),
    .b(WB_ADRi[0]),
    .c(ipae_h16[3]),
    .d(ipte_h8[3]),
    .e(HPAGE_BASEADDR[3]),
    .o(_al_u215_o));
  AL_MAP_LUT3 #(
    .EQN("(B*~(A)*~(C)+B*A*~(C)+~(B)*A*C+B*A*C)"),
    .INIT(8'hac))
    _al_u216 (
    .a(SYSCALL_info[3]),
    .b(SYSCALL_num[3]),
    .c(WB_ADRi[0]),
    .o(\mux26_b3/B0_1 ));
  AL_MAP_LUT4 #(
    .EQN("(~(C*B)*~(D*A))"),
    .INIT(16'h153f))
    _al_u217 (
    .a(mux8_b0_sel_is_4_o),
    .b(_al_u190_o),
    .c(\mux26_b3/B0_1 ),
    .d(ASYNC_WAITCYCLE[3]),
    .o(_al_u217_o));
  AL_MAP_LUT4 #(
    .EQN("~(~B*A*~(D*~C))"),
    .INIT(16'hdfdd))
    _al_u218 (
    .a(_al_u217_o),
    .b(_al_u214_o),
    .c(_al_u215_o),
    .d(_al_u178_o),
    .o(WB_DATo[3]));
  AL_MAP_LUT4 #(
    .EQN("(A*(C*~(B)*~(D)+C*B*~(D)+~(C)*B*D+C*B*D))"),
    .INIT(16'h88a0))
    _al_u219 (
    .a(_al_u190_o),
    .b(SYSCALL_info[4]),
    .c(SYSCALL_num[4]),
    .d(WB_ADRi[0]),
    .o(_al_u219_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)+A*~(B)*~(C)*~(D)+A*B*~(C)*~(D)+~(A)*~(B)*C*~(D)+~(A)*~(B)*~(C)*D+~(A)*B*~(C)*D+~(A)*~(B)*C*D+~(A)*B*C*D)"),
    .INIT(16'h551b))
    _al_u220 (
    .a(WB_ADRi[0]),
    .b(ipae_h16[12]),
    .c(dpte_h8[4]),
    .d(WB_ADRi[1]),
    .o(_al_u220_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*C*~(D)+A*~(B)*C*~(D)+~(A)*B*C*~(D)+A*B*C*~(D)+~(A)*~(B)*~(C)*D+~(A)*B*~(C)*D+~(A)*~(B)*C*D+A*~(B)*C*D)"),
    .INIT(16'h35f0))
    _al_u221 (
    .a(dpae_h16[12]),
    .b(dpae_h16[4]),
    .c(_al_u220_o),
    .d(WB_ADRi[1]),
    .o(_al_u221_o));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+A*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+~(A)*~(B)*~(C)*~(D)*E+A*~(B)*~(C)*~(D)*E+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*~(B)*C*~(D)*E+~(A)*~(B)*~(C)*D*E+A*B*~(C)*D*E+~(A)*~(B)*C*D*E)"),
    .INIT(32'h193b5d7f))
    _al_u222 (
    .a(WB_ADRi[1]),
    .b(WB_ADRi[0]),
    .c(ipae_h16[4]),
    .d(ipte_h8[4]),
    .e(HPAGE_BASEADDR[4]),
    .o(_al_u222_o));
  AL_MAP_LUT4 #(
    .EQN("(~(D*B)*~(C*~A))"),
    .INIT(16'h23af))
    _al_u223 (
    .a(_al_u222_o),
    .b(mux8_b0_sel_is_4_o),
    .c(_al_u178_o),
    .d(ASYNC_WAITCYCLE[4]),
    .o(_al_u223_o));
  AL_MAP_LUT4 #(
    .EQN("~(~B*A*~(D*~C))"),
    .INIT(16'hdfdd))
    _al_u224 (
    .a(_al_u223_o),
    .b(_al_u219_o),
    .c(_al_u221_o),
    .d(_al_u184_o),
    .o(WB_DATo[4]));
  AL_MAP_LUT3 #(
    .EQN("(B*~(A)*~(C)+B*A*~(C)+~(B)*A*C+B*A*C)"),
    .INIT(8'hac))
    _al_u225 (
    .a(SYSCALL_info[5]),
    .b(SYSCALL_num[5]),
    .c(WB_ADRi[0]),
    .o(\mux26_b5/B0_1 ));
  AL_MAP_LUT4 #(
    .EQN("(~A*~(D*~(C)*~(B)+D*C*~(B)+~(D)*C*B+D*C*B))"),
    .INIT(16'h0415))
    _al_u226 (
    .a(WB_ADRi[1]),
    .b(WB_ADRi[0]),
    .c(dpte_h8[5]),
    .d(ipae_h16[13]),
    .o(_al_u226_o));
  AL_MAP_LUT4 #(
    .EQN("(A*~(D*~(C)*~(B)+D*C*~(B)+~(D)*C*B+D*C*B))"),
    .INIT(16'h082a))
    _al_u227 (
    .a(WB_ADRi[1]),
    .b(WB_ADRi[0]),
    .c(dpae_h16[13]),
    .d(dpae_h16[5]),
    .o(_al_u227_o));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+A*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+~(A)*~(B)*~(C)*~(D)*E+A*~(B)*~(C)*~(D)*E+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*~(B)*C*~(D)*E+~(A)*~(B)*~(C)*D*E+A*B*~(C)*D*E+~(A)*~(B)*C*D*E)"),
    .INIT(32'h193b5d7f))
    _al_u228 (
    .a(WB_ADRi[1]),
    .b(WB_ADRi[0]),
    .c(ipae_h16[5]),
    .d(ipte_h8[5]),
    .e(HPAGE_BASEADDR[5]),
    .o(_al_u228_o));
  AL_MAP_LUT5 #(
    .EQN("(D*(~A*~((~C*~B))*~(E)+~A*(~C*~B)*~(E)+~(~A)*(~C*~B)*E+~A*(~C*~B)*E))"),
    .INIT(32'h03005500))
    _al_u229 (
    .a(_al_u228_o),
    .b(_al_u226_o),
    .c(_al_u227_o),
    .d(WB_ADRi[3]),
    .e(WB_ADRi[2]),
    .o(_al_u229_o));
  AL_MAP_LUT5 #(
    .EQN("~(~A*~(D*C)*~(E*B))"),
    .INIT(32'hfeeefaaa))
    _al_u230 (
    .a(_al_u229_o),
    .b(mux8_b0_sel_is_4_o),
    .c(_al_u190_o),
    .d(\mux26_b5/B0_1 ),
    .e(ASYNC_WAITCYCLE[5]),
    .o(WB_DATo[5]));
  AL_MAP_LUT3 #(
    .EQN("(C*~(B)*~(A)+C*B*~(A)+~(C)*B*A+C*B*A)"),
    .INIT(8'hd8))
    _al_u231 (
    .a(WB_ADRi[0]),
    .b(ALWAYS_SVM),
    .c(ASYNC_WAITCYCLE[6]),
    .o(\mux26_b6/B0_2 ));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)+A*~(B)*~(C)*~(D)+A*B*~(C)*~(D)+~(A)*~(B)*C*~(D)+~(A)*~(B)*~(C)*D+~(A)*B*~(C)*D+~(A)*~(B)*C*D+~(A)*B*C*D)"),
    .INIT(16'h551b))
    _al_u232 (
    .a(WB_ADRi[0]),
    .b(ipae_h16[14]),
    .c(dpte_h8[6]),
    .d(WB_ADRi[1]),
    .o(_al_u232_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*C*~(D)+A*~(B)*C*~(D)+~(A)*B*C*~(D)+A*B*C*~(D)+~(A)*~(B)*~(C)*D+~(A)*B*~(C)*D+~(A)*~(B)*C*D+A*~(B)*C*D)"),
    .INIT(16'h35f0))
    _al_u233 (
    .a(dpae_h16[14]),
    .b(dpae_h16[6]),
    .c(_al_u232_o),
    .d(WB_ADRi[1]),
    .o(_al_u233_o));
  AL_MAP_LUT3 #(
    .EQN("(B*~(A)*~(C)+B*A*~(C)+~(B)*A*C+B*A*C)"),
    .INIT(8'hac))
    _al_u234 (
    .a(SYSCALL_info[6]),
    .b(SYSCALL_num[6]),
    .c(WB_ADRi[0]),
    .o(\mux26_b6/B0_1 ));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+A*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+A*B*C*D*~(E)+~(A)*~(B)*~(C)*~(D)*E+A*~(B)*~(C)*~(D)*E+~(A)*~(B)*~(C)*D*E+A*~(B)*~(C)*D*E+~(A)*B*~(C)*D*E+A*B*~(C)*D*E+~(A)*~(B)*C*D*E+A*~(B)*C*D*E+~(A)*B*C*D*E+A*B*C*D*E)"),
    .INIT(32'hff03f50f))
    _al_u235 (
    .a(\mux26_b6/B0_2 ),
    .b(\mux26_b6/B0_1 ),
    .c(WB_ADRi[3]),
    .d(WB_ADRi[2]),
    .e(WB_ADRi[1]),
    .o(_al_u235_o));
  AL_MAP_LUT4 #(
    .EQN("(A*(D*~(C)*~(B)+D*C*~(B)+~(D)*C*B+D*C*B))"),
    .INIT(16'ha280))
    _al_u236 (
    .a(WB_ADRi[1]),
    .b(WB_ADRi[0]),
    .c(ipae_h16[6]),
    .d(ipte_h8[6]),
    .o(_al_u236_o));
  AL_MAP_LUT4 #(
    .EQN("(C*~A*~(D*B))"),
    .INIT(16'h1050))
    _al_u237 (
    .a(_al_u236_o),
    .b(_al_u172_o),
    .c(_al_u178_o),
    .d(HPAGE_BASEADDR[6]),
    .o(_al_u237_o));
  AL_MAP_LUT4 #(
    .EQN("(~B*~(A*~(D*~C)))"),
    .INIT(16'h1311))
    _al_u238 (
    .a(_al_u235_o),
    .b(_al_u237_o),
    .c(_al_u233_o),
    .d(WB_ADRi[3]),
    .o(WB_DATo[6]));
  AL_MAP_LUT3 #(
    .EQN("~(~C*~(B*A))"),
    .INIT(8'hf8))
    _al_u239 (
    .a(u19_sel_is_3_o),
    .b(WB_DATi[6]),
    .c(rst),
    .o(SYSCALL_clr));
  AL_MAP_LUT2 #(
    .EQN("~(~B*~A)"),
    .INIT(4'he))
    _al_u240 (
    .a(n24[7]),
    .b(n1),
    .o(net_reg8_b7_d0));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)+A*~(B)*~(C)*~(D)+A*B*~(C)*~(D)+~(A)*~(B)*C*~(D)+~(A)*~(B)*~(C)*D+~(A)*B*~(C)*D+~(A)*~(B)*C*D+~(A)*B*C*D)"),
    .INIT(16'h551b))
    _al_u241 (
    .a(WB_ADRi[0]),
    .b(ipae_h16[15]),
    .c(dpte_h8[7]),
    .d(WB_ADRi[1]),
    .o(_al_u241_o));
  AL_MAP_LUT4 #(
    .EQN("(~(A)*~(B)*C*~(D)+A*~(B)*C*~(D)+~(A)*B*C*~(D)+A*B*C*~(D)+~(A)*~(B)*~(C)*D+~(A)*B*~(C)*D+~(A)*~(B)*C*D+A*~(B)*C*D)"),
    .INIT(16'h35f0))
    _al_u242 (
    .a(dpae_h16[15]),
    .b(dpae_h16[7]),
    .c(_al_u241_o),
    .d(WB_ADRi[1]),
    .o(_al_u242_o));
  AL_MAP_LUT5 #(
    .EQN("(~(A)*~(B)*~(C)*~(D)*~(E)+A*~(B)*~(C)*~(D)*~(E)+~(A)*B*~(C)*~(D)*~(E)+A*B*~(C)*~(D)*~(E)+~(A)*~(B)*C*~(D)*~(E)+A*~(B)*C*~(D)*~(E)+~(A)*B*C*~(D)*~(E)+~(A)*~(B)*~(C)*D*~(E)+~(A)*B*~(C)*D*~(E)+A*B*~(C)*D*~(E)+~(A)*~(B)*C*D*~(E)+~(A)*B*C*D*~(E)+~(A)*~(B)*~(C)*~(D)*E+A*~(B)*~(C)*~(D)*E+A*B*~(C)*~(D)*E+~(A)*~(B)*C*~(D)*E+A*~(B)*C*~(D)*E+~(A)*~(B)*~(C)*D*E+A*B*~(C)*D*E+~(A)*~(B)*C*D*E)"),
    .INIT(32'h193b5d7f))
    _al_u243 (
    .a(WB_ADRi[1]),
    .b(WB_ADRi[0]),
    .c(ipae_h16[7]),
    .d(ipte_h8[7]),
    .e(HPAGE_BASEADDR[7]),
    .o(_al_u243_o));
  AL_MAP_LUT3 #(
    .EQN("(B*~(A)*~(C)+B*A*~(C)+~(B)*A*C+B*A*C)"),
    .INIT(8'hac))
    _al_u244 (
    .a(SYSCALL_info[7]),
    .b(SYSCALL_num[7]),
    .c(WB_ADRi[0]),
    .o(\mux26_b7/B0_1 ));
  AL_MAP_LUT4 #(
    .EQN("(~A*(D*~(C)*~(B)+D*C*~(B)+~(D)*C*B+D*C*B))"),
    .INIT(16'h5140))
    _al_u245 (
    .a(WB_ADRi[3]),
    .b(WB_ADRi[2]),
    .c(PAE_ENABLE),
    .d(scall_en),
    .o(_al_u245_o));
  AL_MAP_LUT4 #(
    .EQN("(~(C*B)*~(D*A))"),
    .INIT(16'h153f))
    _al_u246 (
    .a(_al_u245_o),
    .b(_al_u190_o),
    .c(\mux26_b7/B0_1 ),
    .d(_al_u172_o),
    .o(_al_u246_o));
  AL_MAP_LUT4 #(
    .EQN("(~(C*B)*~(D*~A))"),
    .INIT(16'h2a3f))
    _al_u247 (
    .a(_al_u243_o),
    .b(mux8_b0_sel_is_4_o),
    .c(SYNC_MODE),
    .d(_al_u178_o),
    .o(_al_u247_o));
  AL_MAP_LUT4 #(
    .EQN("~(B*A*~(D*~C))"),
    .INIT(16'h7f77))
    _al_u248 (
    .a(_al_u246_o),
    .b(_al_u247_o),
    .c(_al_u242_o),
    .d(_al_u184_o),
    .o(WB_DATo[7]));
  AL_MAP_LUT1 #(
    .EQN("(~A)"),
    .INIT(2'h1))
    _al_u249 (
    .a(pll_lock),
    .o(n5));
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    reg0_b0 (
    .ce(mux17_b0_sel_is_3_o),
    .clk(lclk),
    .d(WB_DATi[6]),
    .sr(rst),
    .q(ALWAYS_SVM));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    reg0_b1 (
    .ce(mux17_b0_sel_is_3_o),
    .clk(lclk),
    .d(WB_DATi[7]),
    .sr(rst),
    .q(PAE_ENABLE));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg1_b0 (
    .ce(mux19_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[0]),
    .q(dpae_h16[8]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg1_b1 (
    .ce(mux19_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[1]),
    .q(dpae_h16[9]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg1_b2 (
    .ce(mux19_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[2]),
    .q(dpae_h16[10]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg1_b3 (
    .ce(mux19_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[3]),
    .q(dpae_h16[11]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg1_b4 (
    .ce(mux19_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[4]),
    .q(dpae_h16[12]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg1_b5 (
    .ce(mux19_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[5]),
    .q(dpae_h16[13]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg1_b6 (
    .ce(mux19_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[6]),
    .q(dpae_h16[14]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg1_b7 (
    .ce(mux19_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[7]),
    .q(dpae_h16[15]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg2_b0 (
    .ce(mux20_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[0]),
    .q(dpae_h16[0]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg2_b1 (
    .ce(mux20_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[1]),
    .q(dpae_h16[1]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg2_b2 (
    .ce(mux20_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[2]),
    .q(dpae_h16[2]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg2_b3 (
    .ce(mux20_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[3]),
    .q(dpae_h16[3]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg2_b4 (
    .ce(mux20_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[4]),
    .q(dpae_h16[4]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg2_b5 (
    .ce(mux20_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[5]),
    .q(dpae_h16[5]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg2_b6 (
    .ce(mux20_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[6]),
    .q(dpae_h16[6]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg2_b7 (
    .ce(mux20_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[7]),
    .q(dpae_h16[7]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b0 (
    .ce(mux21_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[0]),
    .q(dpte_h8[0]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b1 (
    .ce(mux21_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[1]),
    .q(dpte_h8[1]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b2 (
    .ce(mux21_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[2]),
    .q(dpte_h8[2]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b3 (
    .ce(mux21_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[3]),
    .q(dpte_h8[3]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b4 (
    .ce(mux21_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[4]),
    .q(dpte_h8[4]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b5 (
    .ce(mux21_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[5]),
    .q(dpte_h8[5]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b6 (
    .ce(mux21_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[6]),
    .q(dpte_h8[6]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg3_b7 (
    .ce(mux21_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[7]),
    .q(dpte_h8[7]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg4_b0 (
    .ce(mux22_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[0]),
    .q(ipae_h16[8]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg4_b1 (
    .ce(mux22_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[1]),
    .q(ipae_h16[9]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg4_b2 (
    .ce(mux22_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[2]),
    .q(ipae_h16[10]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg4_b3 (
    .ce(mux22_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[3]),
    .q(ipae_h16[11]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg4_b4 (
    .ce(mux22_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[4]),
    .q(ipae_h16[12]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg4_b5 (
    .ce(mux22_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[5]),
    .q(ipae_h16[13]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg4_b6 (
    .ce(mux22_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[6]),
    .q(ipae_h16[14]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg4_b7 (
    .ce(mux22_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[7]),
    .q(ipae_h16[15]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg5_b0 (
    .ce(mux23_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[0]),
    .q(ipae_h16[0]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg5_b1 (
    .ce(mux23_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[1]),
    .q(ipae_h16[1]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg5_b2 (
    .ce(mux23_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[2]),
    .q(ipae_h16[2]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg5_b3 (
    .ce(mux23_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[3]),
    .q(ipae_h16[3]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg5_b4 (
    .ce(mux23_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[4]),
    .q(ipae_h16[4]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg5_b5 (
    .ce(mux23_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[5]),
    .q(ipae_h16[5]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg5_b6 (
    .ce(mux23_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[6]),
    .q(ipae_h16[6]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg5_b7 (
    .ce(mux23_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[7]),
    .q(ipae_h16[7]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg6_b0 (
    .ce(mux24_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[0]),
    .q(ipte_h8[0]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg6_b1 (
    .ce(mux24_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[1]),
    .q(ipte_h8[1]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg6_b2 (
    .ce(mux24_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[2]),
    .q(ipte_h8[2]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg6_b3 (
    .ce(mux24_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[3]),
    .q(ipte_h8[3]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg6_b4 (
    .ce(mux24_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[4]),
    .q(ipte_h8[4]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg6_b5 (
    .ce(mux24_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[5]),
    .q(ipte_h8[5]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg6_b6 (
    .ce(mux24_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[6]),
    .q(ipte_h8[6]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg6_b7 (
    .ce(mux24_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[7]),
    .q(ipte_h8[7]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg7_b0 (
    .ce(mux25_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[0]),
    .q(HPAGE_BASEADDR[0]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg7_b1 (
    .ce(mux25_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[1]),
    .q(HPAGE_BASEADDR[1]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg7_b10 (
    .ce(mux25_b10_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[2]),
    .q(HPAGE_BASEADDR[10]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg7_b2 (
    .ce(mux25_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[2]),
    .q(HPAGE_BASEADDR[2]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg7_b3 (
    .ce(mux25_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[3]),
    .q(HPAGE_BASEADDR[3]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg7_b4 (
    .ce(mux25_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[4]),
    .q(HPAGE_BASEADDR[4]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg7_b5 (
    .ce(mux25_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[5]),
    .q(HPAGE_BASEADDR[5]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg7_b6 (
    .ce(mux25_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[6]),
    .q(HPAGE_BASEADDR[6]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg7_b7 (
    .ce(mux25_b0_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[7]),
    .q(HPAGE_BASEADDR[7]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg7_b8 (
    .ce(mux25_b10_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[0]),
    .q(HPAGE_BASEADDR[8]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("0"))
    reg7_b9 (
    .ce(mux25_b10_sel_is_2_o),
    .clk(lclk),
    .d(WB_DATi[1]),
    .q(HPAGE_BASEADDR[9]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("SET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    reg8_b0 (
    .ce(mux18_b0_sel_is_3_o),
    .clk(lclk),
    .d(WB_DATi[0]),
    .sr(rst),
    .q(ASYNC_WAITCYCLE[0]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("SET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    reg8_b1 (
    .ce(mux18_b0_sel_is_3_o),
    .clk(lclk),
    .d(WB_DATi[1]),
    .sr(rst),
    .q(ASYNC_WAITCYCLE[1]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("SET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    reg8_b2 (
    .ce(mux18_b0_sel_is_3_o),
    .clk(lclk),
    .d(WB_DATi[2]),
    .sr(rst),
    .q(ASYNC_WAITCYCLE[2]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("SET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    reg8_b3 (
    .ce(mux18_b0_sel_is_3_o),
    .clk(lclk),
    .d(WB_DATi[3]),
    .sr(rst),
    .q(ASYNC_WAITCYCLE[3]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("SET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    reg8_b4 (
    .ce(mux18_b0_sel_is_3_o),
    .clk(lclk),
    .d(WB_DATi[4]),
    .sr(rst),
    .q(ASYNC_WAITCYCLE[4]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("SET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    reg8_b5 (
    .ce(mux18_b0_sel_is_3_o),
    .clk(lclk),
    .d(WB_DATi[5]),
    .sr(rst),
    .q(ASYNC_WAITCYCLE[5]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("SET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    reg8_b6 (
    .ce(mux18_b0_sel_is_3_o),
    .clk(lclk),
    .d(WB_DATi[6]),
    .sr(rst),
    .q(ASYNC_WAITCYCLE[6]));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    reg8_b7 (
    .clk(lclk),
    .d(net_reg8_b7_d0),
    .sr(n26),
    .q(net_reg8_b7_reset_q0));  // ../RTL/peripherals/sys_ctrl.v(119)
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    reg8_b7_bistable0 (
    .clk(n1),
    .d(1'b1),
    .sr(n26),
    .q(net_reg8_b7_sel0));
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("SET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    reg8_b7_set0 (
    .clk(lclk),
    .d(n24[7]),
    .sr(n1),
    .q(net_reg8_b7_set_q0));
  AL_MAP_SEQ #(
    .CEMUX("1"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("SET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    rst_reg (
    .clk(clki_pad),
    .d(n5),
    .sr(rsti),
    .q(rst));  // ../RTL/peripherals/sys_ctrl.v(78)
  AL_MAP_SEQ #(
    .CEMUX("CE"),
    .CLKMUX("CLK"),
    .DFFMODE("FF"),
    .REGSET("RESET"),
    .SRMODE("ASYNC"),
    .SRMUX("SR"))
    scall_en_reg (
    .ce(u19_sel_is_3_o),
    .clk(lclk),
    .d(WB_DATi[7]),
    .sr(rst),
    .q(scall_en));  // ../RTL/peripherals/sys_ctrl.v(119)

endmodule 

