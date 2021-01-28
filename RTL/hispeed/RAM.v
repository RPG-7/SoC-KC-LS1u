//RAM on wishbone
module RAM(
    input wire clk,
    input wire rst,
    input wire [9:0]WB_ADRi,
    output reg [7:0]WB_DATo,
    input wire [7:0]WB_DATi,
    input wire WB_WEi,
    input wire WB_CYCi,
    input wire WB_STBi,
    output wire WB_ACKo

);
reg Delay;
reg [7:0]BRAM[1023:0];

always@(posedge clk)begin
    if(WB_CYCi & WB_STBi & WB_WEi)begin
        BRAM[WB_ADRi] <= WB_DATi;
    end
    else begin
        WB_DATo <= BRAM[WB_ADRi];
    end
end

always@(posedge clk)begin
    if(rst)begin
        Delay <= 1'b0;
    end
    else begin
        Delay <= (WB_STBi & WB_CYCi);
    end
end
//                           NOTE
// In wishbone bus, data always appera at the same edge of ACK signal. because here we use the SYNC RAM, so
// we need a delay to make data appera at the same edge of ACK
//

assign WB_ACKo = Delay & WB_STBi & WB_CYCi;


endmodule