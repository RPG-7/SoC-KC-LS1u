module asram16_intf#(
    parameter RAM_AWIDTH=17

)(
    //CPU interface
    input clk,rst,
    input instr_sel,
    input [RAM_AWIDTH-1:0]cpu_iaddr,
    output reg [15:0]instr,
    output reg WAIT_INSTR,
    input [RAM_AWIDTH:0]cpu_daddr,
    input dread,
    input dwrite,
    output WAIT_DATA,
    output reg[7:0]ddata_i,
    input[7:0]ddata_o,
    //ASRAM interface
    output [RAM_AWIDTH-1:0] ram_addr,
    output ram_cen,
    output ram_oen,
    output ram_wen,
    output [1:0]ram_wstrbn,
    inout [15:0]ram_data

);
wire access_data = dread | dwrite;

assign ram_addr = (access_data)?cpu_daddr[RAM_AWIDTH:1]:cpu_iaddr;
assign ram_cen = !(instr_sel| access_data);
assign ram_wen = !dwrite;
assign ram_oen = !ram_wen;
assign ram_wstrbn = {!cpu_daddr[0],cpu_daddr[0]};
assign ram_data = (dwrite)?{ddata_o,ddata_o}:16'hzzzz;
always@(posedge clk)
begin
    if(instr_sel & !access_data)
        instr<=ram_data;
    if(dread)
        ddata_i <= (cpu_daddr[0])?ram_data[15:8]:ram_data[7:0];
end
reg wait_data_hold;

always @(posedge clk or posedge rst) 
if(rst)
begin
    wait_data_hold<=1'b1;
    WAIT_INSTR<=1'b1;    
end
else
begin
    wait_data_hold<=access_data;
    WAIT_INSTR<=!(instr_sel & !access_data);  
end
assign WAIT_DATA = access_data & (!wait_data_hold);
endmodule