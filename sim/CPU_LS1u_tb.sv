`timescale 1ns/100ps
module CPU_LS1u_tb();
    bit clk,rst,INT;
    wire [23:0]haddr;
    wire [7:0]hrdata;
    wire [7:0]hwdata;
    wire hburst,hready;
    wire hresp,htrans;
    logic [23:0]IVT_ADDR;
    //clock generation
    always #5 clk = ~clk;
    //always #10 $display("SYSTICKS");
    initial //INIT BLOCK
    begin

        $dumpfile("./temp/CPU_LS1u_tb.vcd"); // 指定用作dumpfile的文件
        $dumpvars; // dump all vars
        #0 clk = 0;rst=0;IVT_ADDR=24'hff0000;INT=0;
        #10 rst=1;
        #20 rst=0;
        #10000 INT=1;
        #100000 $display("FATAL: SIMULATION TIME OUT!");
        #10 $finish;
    end

CPU_LS1u DUT
(
    .clk(clk),
    .rst(rst),
    .INT(INT),
    .IVEC_addr(IVT_ADDR),//中断向量表基址
    //Shrinked AHB
    .haddr(haddr),
    .hwrite(hwrite),
    .hburst(hburst),
    .htrans(htrans),
    .hwdata(hwdata),
    .hready(1'b1),
    .hresp(1'b0),
    //.hreset_n,
    .hrdata(hrdata)
    //input bus_ack,//this is for DMA as 2nd master
    //output bus_req
);
 testspm TEST_BUSMEM
 (
     .clk(clk),
     .rst(rst),
 //-----------Wishbone BUS-----------
     .WB_ADRi(haddr),
     .WB_DATo(hrdata),
     .WB_DATi(hwdata),
     .WB_WEi(hwrite),
     .WB_CYCi(htrans),
     .WB_STBi(1'b1),
     .WB_ACKo(hready)
 );
endmodule
