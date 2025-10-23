
module cachemem
#
(
    parameter datawidth=64,
    cache_depth=2048,
    cswidth=datawidth/8,
    addr_wid =$clog2(cache_depth),
    addr_lsb=$clog2(cswidth)
)
(
    input cwait,
    input [addr_wid-1:0]raddr,
    input [addr_wid-1:0]waddr,
    input [datawidth-1:0]di,
    input we,
    input [cswidth-1:0]bsel,
    output [datawidth-1:0]dato,
    input rclk,
    input wclk
);

genvar i;
generate 
    for(i=0;i<cswidth;i=i+1) 
    begin : cacheblk
        //defparam cacheblk[i].cacheunit.memdepth=cache_depth;
        cachemem8 #(.memdepth(cache_depth)) cacheunit//
        (
            .cwait(cwait),
            .rclk(rclk),
            .wclk(wclk),
            .raddr(raddr),//[addr_wid+addr_lsb-1:addr_lsb]
            .waddr(waddr),//[addr_wid+addr_lsb-1:addr_lsb]
            .di(di[7+8*i:0+8*i]),
            .dato(dato[7+8*i:0+8*i]),
            .we(we&bsel[i])
        );
    end
endgenerate
endmodule

module cachemem8
#(
    parameter memdepth = 1024,
    memaddr=$clog2(memdepth)
)
(
    input cwait,
    input rclk,
    input wclk,
    input [memaddr-1:0]raddr,
    input [memaddr-1:0]waddr,
    input [7:0]di,
    output reg[7:0]dato,
    input we
 );
reg [7:0]memcell[memdepth-1:0];
//begin //: GENERIC_SSRAM
always @(posedge rclk)
begin
    if(cwait)dato<=dato;
    else dato<=memcell[raddr];
    
end
always @(posedge wclk)
    if(we)memcell[waddr]<=di;
endmodule
