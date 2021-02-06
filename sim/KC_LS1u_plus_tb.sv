`timescale 1ns/100ps
//`include "uvm_macros.svh"

module KC_LS1u_plus_tb();
    //import uvm_pkg::*;
    bit clk,rst,dwrite,INT,WAIT=0;
    bit known_WAIT;
    logic [23:0]iaddr,daddr,IVT_ADDR;
    wire [7:0]ddata_i,ddata_o;
    logic [15:0]instr;
    reg [7:0]testspm[255:0];
    //clock generation
    always #5 clk = ~clk;
    initial //INIT BLOCK
    begin
        $dumpfile("./temp/KC_LS1u_plus_tb.vcd"); // 指定用作dumpfile的文件
        $dumpvars; // dump all vars
        #0 clk = 0;WAIT=0; rst=0;IVT_ADDR=24'hff0000;INT=0;known_WAIT=0;
        #10 rst=1;
        #20 rst=0;
        #1000 known_WAIT=1;
        #20 INT=1;
        #20 known_WAIT=0;
        #10000 $display("FATAL: SIMULATION TIME OUT!");
        #10 $finish;
    end
    assign ddata_i=testspm[daddr[7:0]];
    always@(posedge clk)
    begin
        if(dwrite)testspm[daddr[7:0]]<=ddata_o;
    end
    always@(posedge clk)
    begin
        //ddata_i<=$random;
        //WAIT<=$random;
    end
    KC_LS1u_plus DUT
    (
        .clk(clk),
        .rst(rst),
        .INT(INT),
        .WAIT(WAIT|known_WAIT),
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
