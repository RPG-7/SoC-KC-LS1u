module xcr_cdma
#(
    parameter   ADDR_WID=24
)(
    input clk,rst,
	//XCR Bus
	input [7:0]cr_din,
    output reg[7:0]cr_dout,
    input [2:0]cr_adr,
    input cr_we,
	input cr_cs,

	output [ADDR_WID-1:0]SrcAddr,//From MMU control regs
	output [ADDR_WID-1:0]DstAddr,
	output [7:0]BurstLen, //Length for single burst, shorter than a cache line
    output cDmaReq,
    input cDmaDone
	
);



endmodule
