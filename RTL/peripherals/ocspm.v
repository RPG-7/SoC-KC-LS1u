module ocspm
#(parameter SPM_DEPTH=1024,
            SPM_AWID=$clog2(SPM_DEPTH))
(
//------------cDMA-IO signals--------    
    // input [7:0]dat_i,
    // output reg[7:0]dat_o,
    // input dma_req,
    // input dma_dir,
    // input [9:0]raddr,
    // input [9:0]waddr,
    // input we,
//------------Global signals--------
    input wire clk,
    input wire rst,
//-----------Wishbone BUS-----------
    input wire [SPM_AWID-1:0]WB_ADRi,
    output reg [7:0]WB_DATo,
    input wire [7:0]WB_DATi,
    input wire WB_WEi,
    input wire WB_CYCi,
    input wire WB_STBi,
    output wire WB_ACKo
);
reg [7:0]SPMEM[SPM_DEPTH-1:0];
reg ack;
//---------------wishbone signals------------
//---------------REG WRITE------------------
always@(posedge clk)begin
    if(WB_CYCi & WB_STBi & WB_WEi)
    begin
        SPMEM[WB_ADRi]<=WB_DATi;
    end
end
//-----------DATA READ-----------
always@(posedge clk)
begin
    WB_DATo <= SPMEM[WB_ADRi];
    ack<=WB_STBi;
end
//----------ACK----------------
assign WB_ACKo = ack&WB_CYCi;
endmodule