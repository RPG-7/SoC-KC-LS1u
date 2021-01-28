//things in page 0xC00000
module pbus_top
(
//------------SYSTEM CONTROL-------

//------------Misc signals--------
    output	  MOSI,
    output	  SCLK,
    input	  MISO,
    output [7:0]GPIOo,//RGB+SPI CS+SPI DEVSEL
    output [7:0]GPIOdir,
    input [7:0]GPIOi,

    input SYST_PAUSE,
//------------INT signals--------   
    output [5:0]INT_CODE,
    output [23:0]IVT_ADDR,
//------------Global signals--------
    input wire clki,
    input wire rsti,
    output clk,rst,//SYSTEM CORE CLK/RST
//-----------Wishbone BUS-----------
    input wire [9:0]WB_ADRi,
    output reg [7:0]WB_DATo,
    input wire [7:0]WB_DATi,
    input wire WB_WEi,
    input wire WB_CYCi,
    input wire WB_STBi,
    output wire WB_ACKo
);
//INTERRUPTS
wire SYSTICK_INT,TIM_INT,
     SPI_INT,UART_INT,
     SYSCALL,P8080_INT,
     XTNL_INT;
wire STB_GPIO,STB_TIMER,
     STB_SPI,STB_INTC,
     STB_CLKC;
wire [7:0]GPIO_SFi,GPIO_SFo;//second func
tiny_spi SPI1( //4 Regs

   .rst_i(rst),
   .clk_i(clk),
   // memory mapped
   .stb_i(STB_SPI),
   .we_i(WB_WEi),
   .dat_o(DATo_SPI),
   .dat_i(WB_DATi),
   .int_o(SPI_INT),
   .adr_i(WB_ADRi),
   .cyc_i(WB_CYCi), // comment out for avalon
   .ack_o(), // comment out for avalon
   .MOSI(MOSI),
   .SCLK(SCLK),
   .MISO(MISO)
);
GPIO GPIO1( //8 Regs

//-------------GPIO port------------
    .P_in(GPIOi),
    .D_out(GPIOo),
    .P_dir(GPIOdir),
//-----------2nd Function-----------
    .sec_func_i(GPIO_SFi),
    .sec_func_o(GPIO_SFo),
    .XTNL_INT(XTNL_INT),
    .clk(clk),
    .rst(rst),    
    .WB_ADRi(WB_ADRi),
    .WB_DATo(DATo_GPIO),
    .WB_DATi(WB_DATi),
    .WB_WEi(WB_WEi),
    .WB_CYCi(WB_CYCi),
    .WB_STBi(STB_GPIO)
);

timer TIMER1( //8 Regs

    .SYSTICK_INT(SYSTICK_INT),
    .TIM_INT(TIM_INT),
    .PWMo(PWMo),
    .SYST_PAUSE(SYST_PAUSE),
    .clk(clk),
    .rst(rst),
    .WB_ADRi(WB_ADRi),
    .WB_DATo(DATo_TIMER),
    .WB_DATi(WB_DATi),
    .WB_WEi(WB_WEi),
    .WB_CYCi(WB_CYCi),
    .WB_STBi(STB_TIMER),
    .WB_ACKo()

);

int_ctrl INTERRUPT_CONTROLLER1( //8Regs

    .INT_CODE(INT_CODE),
    .IVT_ADDR(IVT_ADDR),
    .INT_ARR({SYSCALL,SYSTICK_INT,XTNL_INT,TIM_INT,P8080_INT,SPI_INT,UART_INT,1'b0}),
    .INT(INT),
    .clk(clk),
    .rst(rst),
    .WB_ADRi(WB_ADRi),
    .WB_DATo(DATo_INTC),
    .WB_DATi(WB_DATi),
    .WB_WEi(WB_WEi),
    .WB_CYCi(WB_CYCi),
    .WB_STBi(STB_INTC),
    .WB_ACKo()

);

endmodule
