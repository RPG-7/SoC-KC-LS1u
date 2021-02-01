
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
    input [addr_wid+addr_lsb-1:0]raddr,
    input [addr_wid+addr_lsb-1:0]waddr,
    input [datawidth-1:0]di,
    input we,
    input [cswidth-1:0]bsel,
    output [datawidth-1:0]dato,
    input clk
);

genvar i;
generate 
    for(i=0;i<cswidth;i=i+1) 
    begin : cacheblk
        defparam cacheunit.memdepth=cache_depth;
        cachemem8 cacheunit
        (   .clk(clk),
            .raddr(raddr[addr_wid+addr_lsb-1:addr_lsb]),
            .waddr(waddr[addr_wid+addr_lsb-1:addr_lsb]),
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
    input clk,
    input [memaddr-1:0]raddr,
    input [memaddr-1:0]waddr,
    input [7:0]di,
    output reg[7:0]dato,
    input we
 );
// generate 
// if(VENDOR=`VENDOR_ALTERA)
//     begin : ASRAM_ALTERA
    

//     end
// else if(VENDOR=`VENDOR_ANLOGIC)
//     begin : ASRAM_ANLOGIC
        
//     end
// else if(VENDOR=`VENDOR_GOWIN)
//     begin : ASRAM_GOWIN
        
//     end
// else 
reg [7:0]memcell[memdepth-1:0];
//begin //: GENERIC_SSRAM
always @(posedge clk)
begin
    dato<=memcell[raddr];
    if(we)memcell[waddr]<=di;
end
//end
//endgenerate
endmodule
