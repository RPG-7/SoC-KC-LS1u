module CPLD_LS1u 
#(parameter RAM_AWIDTH=17,
            CPU_TYPE = "PLUS", //CLASSIC / PLUS / WITHDEBUG
            MMU_ENABLE=1'b0
)(
    input clk,rstn,
    //ROM(Flash)Interface
    //or SRAM
    output [RAM_AWIDTH-1:0] ram_addr,
    output ram_cen,
    output ram_oen,
    output ram_wen,
    output [1:0]ram_wstrbn,
    inout [15:0]ram_data,
    //Maybe add FSB8 here?

    //UART,
    input UART_RX,
    output UART_TX,
    //QSPI
    output QSPI_CLK,
    output QSPI_CSN,
    inout [3:0]QSPI_DIO,
    //WS2812
    output WS2812_PULSE,
    //BTN
    input button
);

wire [BUS_AWIDTH-1:0]cpu_iaddr;
wire [15:0]instr;
wire WAIT_INSTR;
wire [BUS_AWIDTH-1:0]cpu_daddr;
wire dread;
wire dwrite;
wire WAIT_DATA;
wire [7:0]ddata_i;
wire [7:0]ddata_o;
wire [7:0]INT_ARR;

localparam BUS_AWIDTH=(MMU_ENABLE?32:24) ;
CPU_LS1u_Lite #(
    .CPU_TYPE(CPU_TYPE), //CLASSIC / PLUS / WITHDEBUG
    .MMU_ENABLE(MMU_ENABLE))
CPU(
    .sys_por(sys_por),
    .clk(clk),
    .rst(rst),

    .cpu_iaddr(cpu_iaddr),
    .instr(instr),
    .WAIT_INSTR(WAIT_INSTR),
    .cpu_daddr(cpu_daddr),
    .dread(dread),
    .dwrite(dwrite),
    .WAIT_DATA(WAIT_DATA),
    .ddata_i(ddata_i),
    .ddata_o(ddata_o),
    .INT_ARR(INT_ARR)
);
wire ram_isel=!(|cpu_iaddr[BUS_AWIDTH-1:RAM_AWIDTH]);
wire ram_dsel=!(|cpu_daddr[BUS_AWIDTH-1:RAM_AWIDTH]);
asram16_intf #(.RAM_AWIDTH(RAM_AWIDTH))
ram_ctl(
    //CPU interface
    .clk(clk),
    .rst(rst),
    .instr_sel(ram_isel),
    .cpu_iaddr(cpu_iaddr),
    .instr(instr),
    .WAIT_INSTR(WAIT_INSTR),
    .cpu_daddr(cpu_daddr),
    .dread(dread & ram_dsel),
    .dwrite(dwrite & ram_dsel),
    .WAIT_DATA(WAIT_DATA),
    .ddata_i(ddata_i),
    .ddata_o(ddata_o),
    //ASRAM interface
    .ram_addr(ram_addr),
    .ram_cen(ram_cen),
    .ram_oen(ram_oen),
    .ram_wen(ram_wen),
    .ram_wstrbn(ram_wstrbn),
    .ram_data(ram_data)

);

endmodule