// Verilog netlist created by TD v5.0.25341
// Mon Feb 22 16:44:21 2021

`timescale 1ns / 1ps
module ASYNC_DPBRAM  // ASYNC_DPBRAM.v(14)
  (
  addra,
  addrb,
  cea,
  ceb,
  clka,
  clkb,
  dia,
  dib,
  ocea,
  rsta,
  wea,
  web,
  doa,
  dob
  );

  input [10:0] addra;  // ASYNC_DPBRAM.v(37)
  input [10:0] addrb;  // ASYNC_DPBRAM.v(38)
  input cea;  // ASYNC_DPBRAM.v(41)
  input ceb;  // ASYNC_DPBRAM.v(42)
  input clka;  // ASYNC_DPBRAM.v(43)
  input clkb;  // ASYNC_DPBRAM.v(44)
  input [7:0] dia;  // ASYNC_DPBRAM.v(35)
  input [7:0] dib;  // ASYNC_DPBRAM.v(36)
  input ocea;  // ASYNC_DPBRAM.v(46)
  input rsta;  // ASYNC_DPBRAM.v(45)
  input wea;  // ASYNC_DPBRAM.v(39)
  input web;  // ASYNC_DPBRAM.v(40)
  output [7:0] doa;  // ASYNC_DPBRAM.v(31)
  output [7:0] dob;  // ASYNC_DPBRAM.v(32)

  parameter ADDR_WIDTH_A = 11;
  parameter ADDR_WIDTH_B = 11;
  parameter DATA_DEPTH_A = 2048;
  parameter DATA_DEPTH_B = 2048;
  parameter DATA_WIDTH_A = 8;
  parameter DATA_WIDTH_B = 8;
  parameter REGMODE_A = "OUTREG";
  parameter REGMODE_B = "NOREG";
  parameter WRITEMODE_A = "NORMAL";
  parameter WRITEMODE_B = "NORMAL";

  // address_offset=0;data_offset=0;depth=2048;width=4;num_section=1;width_per_section=4;section_size=8;working_depth=2048;working_width=4;mode_ecc=0;address_step=1;bytes_in_per_section=1;
  AL_PHY_BRAM #(
    .CSA0("1"),
    .CSA1("1"),
    .CSA2("1"),
    .CSB0("1"),
    .CSB1("1"),
    .CSB2("1"),
    .DATA_WIDTH_A("4"),
    .DATA_WIDTH_B("4"),
    .MODE("DP8K"),
    .OCEBMUX("0"),
    .REGMODE_A("OUTREG"),
    .REGMODE_B("NOREG"),
    .RESETMODE("SYNC"),
    .RSTBMUX("0"),
    .WRITEMODE_A("NORMAL"),
    .WRITEMODE_B("NORMAL"))
    inst_2048x8_sub_000000_000 (
    .addra({addra,2'b11}),
    .addrb({addrb,2'b11}),
    .cea(cea),
    .ceb(ceb),
    .clka(clka),
    .clkb(clkb),
    .dia({open_n6,open_n7,open_n8,open_n9,open_n10,dia[3:0]}),
    .dib({open_n11,open_n12,open_n13,open_n14,open_n15,dib[3:0]}),
    .ocea(ocea),
    .rsta(rsta),
    .wea(wea),
    .web(web),
    .doa({open_n18,open_n19,open_n20,open_n21,open_n22,doa[3:0]}),
    .dob({open_n23,open_n24,open_n25,open_n26,open_n27,dob[3:0]}));
  // address_offset=0;data_offset=4;depth=2048;width=4;num_section=1;width_per_section=4;section_size=8;working_depth=2048;working_width=4;mode_ecc=0;address_step=1;bytes_in_per_section=1;
  AL_PHY_BRAM #(
    .CSA0("1"),
    .CSA1("1"),
    .CSA2("1"),
    .CSB0("1"),
    .CSB1("1"),
    .CSB2("1"),
    .DATA_WIDTH_A("4"),
    .DATA_WIDTH_B("4"),
    .MODE("DP8K"),
    .OCEBMUX("0"),
    .REGMODE_A("OUTREG"),
    .REGMODE_B("NOREG"),
    .RESETMODE("SYNC"),
    .RSTBMUX("0"),
    .WRITEMODE_A("NORMAL"),
    .WRITEMODE_B("NORMAL"))
    inst_2048x8_sub_000000_004 (
    .addra({addra,2'b11}),
    .addrb({addrb,2'b11}),
    .cea(cea),
    .ceb(ceb),
    .clka(clka),
    .clkb(clkb),
    .dia({open_n34,open_n35,open_n36,open_n37,open_n38,dia[7:4]}),
    .dib({open_n39,open_n40,open_n41,open_n42,open_n43,dib[7:4]}),
    .ocea(ocea),
    .rsta(rsta),
    .wea(wea),
    .web(web),
    .doa({open_n46,open_n47,open_n48,open_n49,open_n50,doa[7:4]}),
    .dob({open_n51,open_n52,open_n53,open_n54,open_n55,dob[7:4]}));

endmodule 

