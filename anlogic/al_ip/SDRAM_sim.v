// Verilog netlist created by TD v5.0.25341
// Wed Jan 20 11:03:24 2021

`timescale 1ns / 1ps
module SDRAM  // SDRAM.v(14)
  (
  addr,
  ba,
  cas_n,
  cke,
  clk,
  dm,
  dm0,
  ras_n,
  we_n,
  dq
  );

  input [10:0] addr;  // SDRAM.v(19)
  input [1:0] ba;  // SDRAM.v(20)
  input cas_n;  // SDRAM.v(17)
  input cke;  // SDRAM.v(24)
  input clk;  // SDRAM.v(15)
  input dm;  // SDRAM.v(22)
  input dm0;  // SDRAM.v(23)
  input ras_n;  // SDRAM.v(16)
  input we_n;  // SDRAM.v(18)
  inout [31:0] dq;  // SDRAM.v(21)


  AL_PHY_SDRAM_2M_32 sdram (
    .addr(addr),
    .ba(ba),
    .cas_n(cas_n),
    .cke(cke),
    .clk(clk),
    .dm(dm),
    .dm0(dm0),
    .ras_n(ras_n),
    .we_n(we_n),
    .dq(dq));  // SDRAM.v(26)

endmodule 

