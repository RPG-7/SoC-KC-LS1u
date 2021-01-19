`timescale 1ns/1ps
`include "uvm_macros.svh"

module KC_LS1u_plus_tb();
    import uvm_pkg::*;
    bit clk,rst,dwrite,INT,WAIT;
    logic [23:0]iaddr,daddr,IVT_ADDR;
    logic [7:0]ddata_i,ddata_o;
    logic [15:0]instr;
    //clock generation
    always #5 clk = ~clk;
    initial //INIT BLOCK
    begin
        #0 clk = 0; rst=0;IVT_ADDR=24'hff0000;
        #10 rst=1;
    end
    KC_LS1u_plus DUT
    (
        .clk(clk),
        .rst(rst),
        .INT(INT),
        .WAIT(WAIT),
        .INTCODE(INTCODE),//中断源编码
        .IVT_addr(IVT_ADDR),//中断向量表基址
        .iaddr(iaddr),
        .instr(instr),
        .daddr(daddr),
        .dwrite(dwrite),
        .ddata_i(ddata_i),
        .ddata_o(ddata_o)
    );


endmodule
