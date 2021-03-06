module ocspm
#(parameter SPM_DEPTH=1024,
            SPM_AWID=$clog2(SPM_DEPTH))
(
//------------cDMA-IO signals--------    
     input [7:0]dat_i,
     output reg[7:0]dat_o,
     input dma_req,
     input [9:0]raddr,
     input [9:0]waddr,
     input we,
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

always@(posedge clk)begin
if(dma_req)//cDMA process
begin
    if(we)SPMEM[waddr]<=dat_i;
    dat_o<=SPMEM[raddr];
    WB_DATo<=WB_DATo;
end
else 
begin
//---------------REG WRITE------------------
    if(WB_CYCi & WB_STBi & WB_WEi)
    begin
        SPMEM[WB_ADRi]<=WB_DATi;
    end
//-----------DATA READ-----------    
    WB_DATo <= SPMEM[WB_ADRi];
    ack<=WB_STBi;
    dat_o<=dat_o;
end
    
end

//----------ACK----------------
assign WB_ACKo = ack&WB_CYCi&(!dma_req);
endmodule