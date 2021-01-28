`timescale 1ns/1ps
//`include "uvm_macros.svh"

module KC_LS1u_plus_tb();
    //import uvm_pkg::*;
    bit clk,rst,dwrite,INT,WAIT=0;
    logic [23:0]iaddr,daddr,IVT_ADDR;
    logic [7:0]ddata_i,ddata_o;
    logic [15:0]instr;
    //clock generation
    always #5 clk = ~clk;
    initial //INIT BLOCK
    begin
        $dumpfile("./temp/KC_LS1u_plus_tb.vcd"); // 指定用作dumpfile的文件
        $dumpvars; // dump all vars
        #0 clk = 0; rst=0;IVT_ADDR=24'hff0000;INT=0;
        #10 rst=1;
        #20 rst=0;
        #1000 INT=1;
        #10000 $display("FATAL: SIMULATION TIME OUT!");
        #10 $finish;
    end
    always@(posedge clk)
    begin
        ddata_i<=$random;
        WAIT<=$random;
    end
    KC_LS1u_plus DUT
    (
        .clk(clk),
        .rst(rst),
        .INT(INT),
        .WAIT(WAIT),
        //.INTCODE(INTCODE),//中断源编码
        .IVEC_addr(IVT_ADDR),//中断向量表基址
        .iaddr(iaddr),
        .instr(instr),
        .daddr(daddr),
        .dwrite(dwrite),
        .ddata_i(ddata_i),
        .ddata_o(ddata_o)
    );
    KC_LS1u_instr_mem TEST_MEM
    (
        .addr(iaddr),
        .instr(instr)
    );

endmodule
