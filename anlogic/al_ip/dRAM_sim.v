// Verilog netlist created by TD v5.0.25341
// Sun Feb 28 16:07:13 2021

`timescale 1ns / 1ps
module dRAM  // dRAM.v(14)
  (
  di,
  raddr,
  waddr,
  wclk,
  we,
  do
  );

  input [31:0] di;  // dRAM.v(23)
  input [5:0] raddr;  // dRAM.v(25)
  input [3:0] waddr;  // dRAM.v(24)
  input wclk;  // dRAM.v(26)
  input we;  // dRAM.v(26)
  output [7:0] do;  // dRAM.v(28)

  parameter ADDR_WIDTH_R = 6;
  parameter ADDR_WIDTH_W = 4;
  parameter DATA_DEPTH_R = 64;
  parameter DATA_DEPTH_W = 16;
  parameter DATA_WIDTH_R = 8;
  parameter DATA_WIDTH_W = 32;
  wire  \dram_do_mux_b0/B0_0 ;
  wire  \dram_do_mux_b0/B0_1 ;
  wire  \dram_do_mux_b1/B0_0 ;
  wire  \dram_do_mux_b1/B0_1 ;
  wire  \dram_do_mux_b2/B0_0 ;
  wire  \dram_do_mux_b2/B0_1 ;
  wire  \dram_do_mux_b3/B0_0 ;
  wire  \dram_do_mux_b3/B0_1 ;
  wire  \dram_do_mux_b4/B0_0 ;
  wire  \dram_do_mux_b4/B0_1 ;
  wire  \dram_do_mux_b5/B0_0 ;
  wire  \dram_do_mux_b5/B0_1 ;
  wire  \dram_do_mux_b6/B0_0 ;
  wire  \dram_do_mux_b6/B0_1 ;
  wire  \dram_do_mux_b7/B0_0 ;
  wire  \dram_do_mux_b7/B0_1 ;
  wire dram_do_i0_000;
  wire dram_do_i0_001;
  wire dram_do_i0_002;
  wire dram_do_i0_003;
  wire dram_do_i0_004;
  wire dram_do_i0_005;
  wire dram_do_i0_006;
  wire dram_do_i0_007;
  wire dram_do_i1_000;
  wire dram_do_i1_001;
  wire dram_do_i1_002;
  wire dram_do_i1_003;
  wire dram_do_i1_004;
  wire dram_do_i1_005;
  wire dram_do_i1_006;
  wire dram_do_i1_007;
  wire dram_do_i2_000;
  wire dram_do_i2_001;
  wire dram_do_i2_002;
  wire dram_do_i2_003;
  wire dram_do_i2_004;
  wire dram_do_i2_005;
  wire dram_do_i2_006;
  wire dram_do_i2_007;
  wire dram_do_i3_000;
  wire dram_do_i3_001;
  wire dram_do_i3_002;
  wire dram_do_i3_003;
  wire dram_do_i3_004;
  wire dram_do_i3_005;
  wire dram_do_i3_006;
  wire dram_do_i3_007;

  AL_MUX \dram_do_mux_b0/al_mux_b0_0_0  (
    .i0(dram_do_i0_000),
    .i1(dram_do_i1_000),
    .sel(raddr[0]),
    .o(\dram_do_mux_b0/B0_0 ));
  AL_MUX \dram_do_mux_b0/al_mux_b0_0_1  (
    .i0(dram_do_i2_000),
    .i1(dram_do_i3_000),
    .sel(raddr[0]),
    .o(\dram_do_mux_b0/B0_1 ));
  AL_MUX \dram_do_mux_b0/al_mux_b0_1_0  (
    .i0(\dram_do_mux_b0/B0_0 ),
    .i1(\dram_do_mux_b0/B0_1 ),
    .sel(raddr[1]),
    .o(do[0]));
  AL_MUX \dram_do_mux_b1/al_mux_b0_0_0  (
    .i0(dram_do_i0_001),
    .i1(dram_do_i1_001),
    .sel(raddr[0]),
    .o(\dram_do_mux_b1/B0_0 ));
  AL_MUX \dram_do_mux_b1/al_mux_b0_0_1  (
    .i0(dram_do_i2_001),
    .i1(dram_do_i3_001),
    .sel(raddr[0]),
    .o(\dram_do_mux_b1/B0_1 ));
  AL_MUX \dram_do_mux_b1/al_mux_b0_1_0  (
    .i0(\dram_do_mux_b1/B0_0 ),
    .i1(\dram_do_mux_b1/B0_1 ),
    .sel(raddr[1]),
    .o(do[1]));
  AL_MUX \dram_do_mux_b2/al_mux_b0_0_0  (
    .i0(dram_do_i0_002),
    .i1(dram_do_i1_002),
    .sel(raddr[0]),
    .o(\dram_do_mux_b2/B0_0 ));
  AL_MUX \dram_do_mux_b2/al_mux_b0_0_1  (
    .i0(dram_do_i2_002),
    .i1(dram_do_i3_002),
    .sel(raddr[0]),
    .o(\dram_do_mux_b2/B0_1 ));
  AL_MUX \dram_do_mux_b2/al_mux_b0_1_0  (
    .i0(\dram_do_mux_b2/B0_0 ),
    .i1(\dram_do_mux_b2/B0_1 ),
    .sel(raddr[1]),
    .o(do[2]));
  AL_MUX \dram_do_mux_b3/al_mux_b0_0_0  (
    .i0(dram_do_i0_003),
    .i1(dram_do_i1_003),
    .sel(raddr[0]),
    .o(\dram_do_mux_b3/B0_0 ));
  AL_MUX \dram_do_mux_b3/al_mux_b0_0_1  (
    .i0(dram_do_i2_003),
    .i1(dram_do_i3_003),
    .sel(raddr[0]),
    .o(\dram_do_mux_b3/B0_1 ));
  AL_MUX \dram_do_mux_b3/al_mux_b0_1_0  (
    .i0(\dram_do_mux_b3/B0_0 ),
    .i1(\dram_do_mux_b3/B0_1 ),
    .sel(raddr[1]),
    .o(do[3]));
  AL_MUX \dram_do_mux_b4/al_mux_b0_0_0  (
    .i0(dram_do_i0_004),
    .i1(dram_do_i1_004),
    .sel(raddr[0]),
    .o(\dram_do_mux_b4/B0_0 ));
  AL_MUX \dram_do_mux_b4/al_mux_b0_0_1  (
    .i0(dram_do_i2_004),
    .i1(dram_do_i3_004),
    .sel(raddr[0]),
    .o(\dram_do_mux_b4/B0_1 ));
  AL_MUX \dram_do_mux_b4/al_mux_b0_1_0  (
    .i0(\dram_do_mux_b4/B0_0 ),
    .i1(\dram_do_mux_b4/B0_1 ),
    .sel(raddr[1]),
    .o(do[4]));
  AL_MUX \dram_do_mux_b5/al_mux_b0_0_0  (
    .i0(dram_do_i0_005),
    .i1(dram_do_i1_005),
    .sel(raddr[0]),
    .o(\dram_do_mux_b5/B0_0 ));
  AL_MUX \dram_do_mux_b5/al_mux_b0_0_1  (
    .i0(dram_do_i2_005),
    .i1(dram_do_i3_005),
    .sel(raddr[0]),
    .o(\dram_do_mux_b5/B0_1 ));
  AL_MUX \dram_do_mux_b5/al_mux_b0_1_0  (
    .i0(\dram_do_mux_b5/B0_0 ),
    .i1(\dram_do_mux_b5/B0_1 ),
    .sel(raddr[1]),
    .o(do[5]));
  AL_MUX \dram_do_mux_b6/al_mux_b0_0_0  (
    .i0(dram_do_i0_006),
    .i1(dram_do_i1_006),
    .sel(raddr[0]),
    .o(\dram_do_mux_b6/B0_0 ));
  AL_MUX \dram_do_mux_b6/al_mux_b0_0_1  (
    .i0(dram_do_i2_006),
    .i1(dram_do_i3_006),
    .sel(raddr[0]),
    .o(\dram_do_mux_b6/B0_1 ));
  AL_MUX \dram_do_mux_b6/al_mux_b0_1_0  (
    .i0(\dram_do_mux_b6/B0_0 ),
    .i1(\dram_do_mux_b6/B0_1 ),
    .sel(raddr[1]),
    .o(do[6]));
  AL_MUX \dram_do_mux_b7/al_mux_b0_0_0  (
    .i0(dram_do_i0_007),
    .i1(dram_do_i1_007),
    .sel(raddr[0]),
    .o(\dram_do_mux_b7/B0_0 ));
  AL_MUX \dram_do_mux_b7/al_mux_b0_0_1  (
    .i0(dram_do_i2_007),
    .i1(dram_do_i3_007),
    .sel(raddr[0]),
    .o(\dram_do_mux_b7/B0_1 ));
  AL_MUX \dram_do_mux_b7/al_mux_b0_1_0  (
    .i0(\dram_do_mux_b7/B0_0 ),
    .i1(\dram_do_mux_b7/B0_1 ),
    .sel(raddr[1]),
    .o(do[7]));
  AL_LOGIC_DRAM16X4 dram_r0_c0 (
    .di(di[3:0]),
    .raddr(raddr[5:2]),
    .waddr(waddr),
    .wclk(wclk),
    .we(we),
    .do({dram_do_i0_003,dram_do_i0_002,dram_do_i0_001,dram_do_i0_000}));
  AL_LOGIC_DRAM16X4 dram_r0_c1 (
    .di(di[7:4]),
    .raddr(raddr[5:2]),
    .waddr(waddr),
    .wclk(wclk),
    .we(we),
    .do({dram_do_i0_007,dram_do_i0_006,dram_do_i0_005,dram_do_i0_004}));
  AL_LOGIC_DRAM16X4 dram_r1_c0 (
    .di(di[11:8]),
    .raddr(raddr[5:2]),
    .waddr(waddr),
    .wclk(wclk),
    .we(we),
    .do({dram_do_i1_003,dram_do_i1_002,dram_do_i1_001,dram_do_i1_000}));
  AL_LOGIC_DRAM16X4 dram_r1_c1 (
    .di(di[15:12]),
    .raddr(raddr[5:2]),
    .waddr(waddr),
    .wclk(wclk),
    .we(we),
    .do({dram_do_i1_007,dram_do_i1_006,dram_do_i1_005,dram_do_i1_004}));
  AL_LOGIC_DRAM16X4 dram_r2_c0 (
    .di(di[19:16]),
    .raddr(raddr[5:2]),
    .waddr(waddr),
    .wclk(wclk),
    .we(we),
    .do({dram_do_i2_003,dram_do_i2_002,dram_do_i2_001,dram_do_i2_000}));
  AL_LOGIC_DRAM16X4 dram_r2_c1 (
    .di(di[23:20]),
    .raddr(raddr[5:2]),
    .waddr(waddr),
    .wclk(wclk),
    .we(we),
    .do({dram_do_i2_007,dram_do_i2_006,dram_do_i2_005,dram_do_i2_004}));
  AL_LOGIC_DRAM16X4 dram_r3_c0 (
    .di(di[27:24]),
    .raddr(raddr[5:2]),
    .waddr(waddr),
    .wclk(wclk),
    .we(we),
    .do({dram_do_i3_003,dram_do_i3_002,dram_do_i3_001,dram_do_i3_000}));
  AL_LOGIC_DRAM16X4 dram_r3_c1 (
    .di(di[31:28]),
    .raddr(raddr[5:2]),
    .waddr(waddr),
    .wclk(wclk),
    .we(we),
    .do({dram_do_i3_007,dram_do_i3_006,dram_do_i3_005,dram_do_i3_004}));

endmodule 

module AL_MUX
  (
  input i0,
  input i1,
  input sel,
  output o
  );

  wire not_sel, sel_i0, sel_i1;
  not u0 (not_sel, sel);
  and u1 (sel_i1, sel, i1);
  and u2 (sel_i0, not_sel, i0);
  or u3 (o, sel_i1, sel_i0);

endmodule

