/*************************************************
//SYSCALL Module Mem map:
//0x00~0xFF write SYSCALL_info to specific memory address
//will generate specific syscall;
//Read out/clear in SYSCTRL registers
//This module is Write Only
*************************************************/
module syscall
(
    input SYSCALL_clr,
    output reg SYSCALL_trig,
    output reg [7:0]SYSCALL_num,
    output reg [7:0]SYSCALL_info,
    //-----------System Signals----------
    input clk,rst,
    //-----------Wishbone BUS-----------
    input wire [7:0]WB_ADRi,
    output [7:0]WB_DATo,
    input wire [7:0]WB_DATi,
    input wire WB_WEi,
    input wire WB_CYCi,
    input wire WB_STBi,
    output wire WB_ACKo
);
always@(posedge clk or posedge (SYSCALL_clr))
begin
    if(SYSCALL_clr)
    begin
        SYSCALL_trig<=0;
    end
    else if(WB_CYCi & WB_STBi & WB_WEi)
    begin
        SYSCALL_num<=WB_ADRi;
        SYSCALL_info<=WB_DATi;
        SYSCALL_trig<=1;
    end
    else 
    begin
        SYSCALL_num<=SYSCALL_num;
        SYSCALL_info<=SYSCALL_info;
        SYSCALL_trig<=SYSCALL_trig;
    end
end
assign WB_DATo=0;
assign WB_ACKo=1;
endmodule
