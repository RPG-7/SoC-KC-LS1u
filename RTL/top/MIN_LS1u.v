//配备FSB8的“最小化”KC-LS1u应用处理器
//i8088风格
//目标器件GW1N-1
`define UNIFIED 2'b01
`define L1IONLY 2'b00
`define TRUE 1'b1
`define FALSE 1'b0
module MIN_LS1u
(
    //FSB8 bus
    input sysclk,//let bus reset system
    input sysrst_n,

    input jtck,jtms,jtdi,
    output jtdo,

    output busclk,
    output busrst_n,
    output ale_n,
    output cs_n,
    output cmd_n,
    output typ,//SINGLE#/BLOCK
    output wr_n,
    input rdy_n,//Also MN#/MX
    input irq_n,
    inout [7:0]AD8,
    output [7:0]AAH8
);
localparam MMU_SETTING = `TRUE;
localparam cDMA_SETTING = `FALSE;
localparam cSPM_SETTING = `TRUE;
localparam BUS_ADDRWID =(MMU_SETTING)?32:24;

wire ADdir;
wire [7:0]AD_in,AD_out;
assign AD8=(ADdir)?AD_out:8'hzz;
assign AD_in=AD8;
wire clk,rst,dbg_rsto;
wire  SYNC_MODE;
wire  [6:0]ASYNC_WAITCYCLE;
//Shrinked AHB
wire [BUS_ADDRWID-1:0]haddr;
wire hwrite;
wire hburst;
wire htrans;
wire [7:0]hwdata;
wire hready;
wire hresp;
wire hreset_n;
wire [7:0]hrdata;
wire hresp_fsb;
wire hsel_fsb;
wire [7:0]hrdata_fsb;
wire hready_fsb;
wire hsel_ocf;//OCF are on-chip 1T functions, no need to have hready
wire [7:0]hrdata_ocf;
wire FSB_IRQ,systick_int,syscall_int;
assign hreset_n=~rst;
defparam CPU1.CACHE_TYP =`L1IONLY;
defparam CPU1.CACHE_DEPTH=2048;
defparam CPU1.ENTRY_NUM=32;
defparam CPU1.MMU_ENABLE=MMU_SETTING;
CPU_LS1u CPU1
(
    .sys_por(!sysrst_n),
    .clk(clk),
    .rst(rst),
    .jrst_out(dbg_rsto),
    .jtck(jtck),
    .jtms(jtms),
    .jtdi(jtdi),
    .jtdo(jtdo),
    //Interrupt
    .INT_ARR({FSB_IRQ,systick_int,syscall_int}),
    //Shrinked AHB
    .haddr(haddr),
    .hwrite(hwrite),
    .hburst(hburst),
    .htrans(htrans),
    .hwdata(hwdata),
    .hready(hready),
    .hresp(hresp),
    //.hreset_n(hreset_n),
    .hrdata(hrdata)
);
defparam FSB8_CONTROLLER.PAE_ENABLE=MMU_SETTING;
fsb8 FSB8_CONTROLLER
(
    //FSB config
    .SYNC_MODE(SYNC_MODE),
    .ASYNC_WAITCYCLE(ASYNC_WAITCYCLE),
    //ahb 接口
    .hclk(clk),
    .hreset_n(hreset_n),
    .hsel(hsel_fsb),
    .hsel_cmd(1'b0),
    .htrans(htrans),
    .hburst(hburst),
    .hwrite(hwrite),
    .haddr(haddr),	
    .hwdata(hwdata),
    .hrdata(hrdata_fsb),
    .hresp(hresp_fsb),
    .hready(hready_fsb),
    //fsb8信号
    .clk(busclk),
    .rst_n(busrst_n),
    .ale_n(ale_n),
    .cs_n(cs_n),
    .cmd_n(cmd_n),
    .typ(typ),//SINGLE#/BLOCK
    .wr_n(wr_n),
    .rdy_n(rdy_n),
    .irq_n(irq_n),
    .err_n(1'b1),
    .ADdir(ADdir),	//0表示高阻态
    .AAH8(AAH8),
    .AD_out(AD_out),
    .AD_in(AD_in),
    //对内部中断控制器信号
    .FSB_irq(FSB_IRQ)

);

min_pbus OC_PERIPHERALS
(
//------------SYSTEM CONTROL-------
    .SYST_PAUSE(IN_ISP),
    .SYNC_MODE(SYNC_MODE),
    .ASYNC_WAITCYCLE(ASYNC_WAITCYCLE),
    .MNMX(rdy_n),
//------------Interrupts   --------
    .SYSTICK_INT(systick_int),
    .SYSCALL(syscall_int),
//------------Global signals--------
    .clki(sysclk),
    .rsti(~sysrst_n),
    .clk(clk),
    .rst(rst),//SYSTEM CORE CLK/RST
//-----------Wishbone BUS-----------
    .WB_ADRi(haddr[11:0]),
    .WB_DATo(hrdata_ocf),
    .WB_DATi(hwdata),
    .WB_WEi(hwrite),
    .WB_CYCi(htrans),
    .WB_STBi(hsel_ocf),
    .WB_ACKo()
);
assign hsel_ocf=(haddr[23:16]==8'hC0)&(haddr[11:8]>=4'h5);
assign hsel_fsb=!hsel_ocf;
assign hrdata=(hsel_ocf)?hrdata_ocf:hrdata_fsb;
assign hready=(hsel_ocf)?1'b1:hready_fsb;
assign hresp=(hsel_ocf)?1'b0:hresp_fsb;
endmodule 