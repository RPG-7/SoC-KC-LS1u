/*
字节选择模块
*/
module byte_sel
#(
    parameter BYTE_NUM = 8
    ,ADDR_WIDTH=((BYTE_NUM > 1) ? $clog2(BYTE_NUM) : 1)
    ,SIZE_ADDR=(BYTE_NUM/2)
)
(
input wire [ADDR_WIDTH-1:0]addr,	//address
input wire [SIZE_ADDR-1:0]size,	//0001=1Byte;0010=2Byte;0100=4Byte;1000=8Byte
input wire mask,
output wire [BYTE_NUM-1:0]bsel
);
genvar i;integer j;
wire [BYTE_NUM-1:0]bsel_source[SIZE_ADDR-1:0];
reg [BYTE_NUM-1:0]shiftin;
reg [BYTE_NUM-1:0]shift[ADDR_WIDTH:0];
//assign shift[0]=shiftin;
assign bsel=shift[ADDR_WIDTH];
generate 
for(i=0;i<SIZE_ADDR;i=i+1) 
    begin : BSELSRC_GEN
        assign bsel_source[i]={{(BYTE_NUM-2**i){1'b0}},{2**i{size[i]}}};
    end
endgenerate
always@(*)//SHIFT IN GEN
begin
    shiftin=bsel_source[0];
	 shift[0]=shiftin;
    for(j=1;j<SIZE_ADDR;j=j+1)
    begin
        shiftin=shiftin|bsel_source[j];
    end
    for(j=0;j<ADDR_WIDTH;j=j+1) 
    begin 
        if(addr[j])shift[j+1]= (shift[j]<<(2**(j)));
        else shift[j+1]=shift[j];
    end
end
//assign bsel			=	mask ? 8'b11111111 : addr[2] ? {shift2[7:4],4'b0} : shift2;

endmodule
