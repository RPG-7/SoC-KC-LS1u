module ocspm
#(parameter SPM_DEPTH=1024,
            SPM_AWID=$clog2(SPM_DEPTH),
            DMA_PRESENT=1'b0)
(
//------------cDMA-IO signals--------    
     input [7:0]dat_i,
     output reg[7:0]dat_o,
     input dma_req,
     input [SPM_AWID-1:0]dmaaddr,
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
reg [7:0]writedat;
reg [SPM_AWID-1:0]ramaddr;
reg ramwe;
//---------------wishbone signals------------
generate 
    if(DMA_PRESENT) 
    begin : cDMA_SPM
        always@(*)
        begin
            dat_o=WB_DATo;
            if(dma_req)
            begin
                writedat=dat_i;
                ramaddr=dmaaddr;
                ramwe=we;
                
            end
            else 
            begin
                writedat=WB_DATi;
                ramaddr=WB_ADRi;
                ramwe=WB_CYCi & WB_STBi & WB_WEi;
            end
        end
    end
    else 
    begin : NORM_SPM
        always @(*) 
        begin
            writedat=WB_DATi;
            ramaddr=WB_ADRi;
            dat_o=0;
            ramwe=WB_CYCi & WB_STBi & WB_WEi;    
        end
    end
endgenerate

always@(posedge clk)
begin
//---------------REG WRITE------------------
    if(ramwe)
    begin
        SPMEM[ramaddr]<=writedat;
    end
//-----------DATA READ-----------    
    WB_DATo <= SPMEM[ramaddr];
    ack<=WB_STBi;
end
    

//----------ACK----------------
assign WB_ACKo = ack&WB_CYCi&(!dma_req);
endmodule