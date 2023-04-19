module sdram_buffer
#(
    parameter BUF_TYPE="BRAM",
			  SYS_BUSWIDTH=8,
              SDR_BUSWIDTH=32,
              BUF_DEPTH=4096
)
(
    input sys_clk,sdr_clk,sys_rst,
    input [SYS_BUSWIDTH-1:0]sys_datai,
    output [SYS_BUSWIDTH-1:0]sys_datao,
    input [SDR_BUSWIDTH-1:0]sdr_datai,
    output [SDR_BUSWIDTH-1:0]sdr_datao,
    input [SYS_ADRWID-1:0]sys_addr,
    input [SDR_ADRWID-1:0]sdr_addr,
    input sys_we,sdr_we,sys_ce,sdr_ce
);
localparam SYS_ADRWID = $clog2(BUF_DEPTH/(SYS_BUSWIDTH/8));
localparam SDR_ADRWID = $clog2(BUF_DEPTH/(SDR_BUSWIDTH/8));
`ifdef VENDOR_ANLOGIC
generate if(BUF_TYPE == "BRAM") 
begin : BRAM
	AL_LOGIC_BRAM #(.DATA_WIDTH_A(SYS_BUSWIDTH),
					.DATA_WIDTH_B(SDR_BUSWIDTH),
					.ADDR_WIDTH_A(SYS_ADRWID),
					.ADDR_WIDTH_B(SDR_ADRWID),
					.DATA_DEPTH_A(BUF_DEPTH),
					.DATA_DEPTH_B(BUF_DEPTH),
					.MODE("DP"),
					.REGMODE_A("OUTREG"),
					.REGMODE_B("OUTREG"),
					.WRITEMODE_A("NORMAL"),
					.WRITEMODE_B("NORMAL"),
					.RESETMODE("SYNC"),
					.IMPLEMENT("9K"),
					.INIT_FILE("NONE"),
					.FILL_ALL("NONE"))
		SDR_BUFFER (.dia(sys_datai),
					.dib(sdr_datai),
					.addra(sys_addr),
					.addrb(sdr_addr),
					.cea(sys_ce),
					.ceb(sdr_ce),
					.ocea(1'b1),
					.oceb(1'b1),
					.clka(sys_clk),
					.clkb(sdr_clk),
					.wea(sys_we),
					.web(sdr_we),
					.bea(1'b0),
					.beb(1'b0),
					.rsta(sys_rst),
					.rstb(sys_rst),
					.doa(sys_datao),
					.dob(sdr_datao));
end
else begin : LUTRAM_BUF 
	AL_LOGIC_DRAM #(
 			.INIT_FILE("NONE"),
			.DATA_WIDTH_W(DATA_WIDTH_W),
			.ADDR_WIDTH_W(ADDR_WIDTH_W),
			.DATA_DEPTH_W(DATA_DEPTH_W),
			.DATA_WIDTH_R(DATA_WIDTH_R),
			.ADDR_WIDTH_R(ADDR_WIDTH_R),
			.DATA_DEPTH_R(DATA_DEPTH_R))
	LUTRAM_BUFa(
			.di(di),
			.waddr(waddr),
			.wclk(wclk),
			.we(we),
			.do(do),
			.raddr(raddr));
		AL_LOGIC_DRAM #(
 			.INIT_FILE("NONE"),
			.DATA_WIDTH_W(DATA_WIDTH_W),
			.ADDR_WIDTH_W(ADDR_WIDTH_W),
			.DATA_DEPTH_W(DATA_DEPTH_W),
			.DATA_WIDTH_R(DATA_WIDTH_R),
			.ADDR_WIDTH_R(ADDR_WIDTH_R),
			.DATA_DEPTH_R(DATA_DEPTH_R))
	LUTRAM_BUFb(
			.di(di),
			.waddr(waddr),
			.wclk(wclk),
			.we(we),
			.do(do),
			.raddr(raddr));
end
endgenerate


`endif

endmodule