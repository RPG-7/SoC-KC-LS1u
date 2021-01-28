//原版LS1U应用系统升级版
//目标塞入AL3S10
module SoC_LS1u
(
    input clki,
    input rsti,
    output qsel,
    inout [3:0]qspi,
    inout [2:0]gpio,
    output [3:0]spi_devsel,
    output spi_cs,
    output mosi,
    output mclk,
    input miso

);
wire clk,rst;
wire INT;
wire [5:0]INTCODE;//中断源编码
wire [23:0]IVT_addr;//中断向量表基址
//Shrinked AHB
wire [23:0]haddr;
wire hwrite;
wire [2:0]hburst;
wire [1:0]htrans;
wire [7:0]hwdata;
wire hready;
wire hresp;
wire hreset_n;
wire [7:0]hrdata;

CPU_LS1u CPU1
(
    .clk(clk),
    .rst(rst),

    .cache_flush(1'b0),//当存在MMU，切换页表须冲刷cache
    //Interrupt
	.INT(INT),
    //.INTCODE(INTCODE),//中断源编码
    .IVEC_addr(IVT_addr),//中断向量表基址
    //Shrinked AHB
    .haddr(haddr),
    .hwrite(hwrite),
    .hburst(hburst),
    .htrans(htrans),
    .hwdata(hwdata),
    .hready(hready),
    .hresp(hresp),
    .hreset_n(hreset_n),
    .hrdata(hrdata)
);

endmodule
