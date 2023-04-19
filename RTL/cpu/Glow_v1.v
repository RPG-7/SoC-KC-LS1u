module Glow_v1
(
    input  clk,rst,
    input  WAIT,
    input  [7:0]IO0_i,
    output [7:0]IO0_o,
    input  [7:0]IO1_i,
    output [7:0]IO1_o,
    output [23:0]iaddr,
    input  [15:0]instr,
    output [23:0]daddr,
    input  [7:0]ddata_i,
    output [7:0]ddata_o,    
	output dwrite
);

reg [7:0] RA,RB,
    RA0,RA1,RA2,
    RFAddr,Data_oreg,
    IO0_oreg,IO1_oreg;

reg [7:0]RegFile[255:0];


endmodule



