module sys_ctrl
(
    input clki,rsti,//Low-speed CLK& RST input
    output clk,rst,lclk,//SYSTEM GLOBAL SIGNAL
    output 
    //-----------Wishbone BUS-----------
    input wire [2:0]WB_ADRi,
    output reg [7:0]WB_DATo,
    input wire [7:0]WB_DATi,
    input wire WB_WEi,
    input wire WB_CYCi,
    input wire WB_STBi,
    output wire WB_ACKo
);



endmodule
