module Glow_v1Plus
(
    input clk,rst,INT,WAIT,
    input [23:0]IVEC_addr,//中断向量地址
    output IN_ISP,
    //--------XCR Bus--------
    input [7:0]XCRi,
    output [7:0]XCRo,
    output [7:0]XCRa,
    output reg XCRwe,
    output reg XCRcs,
    //--------I/D Bus
    output [23:0]iaddr,
    input [15:0]instr,
    output [23:0]daddr,
    output dread,
    output dwrite,
    input WAIT_DATA,
    output INSTR_HOLD,
    input [7:0]ddata_i,
    output [7:0]ddata_o
);



endmodule