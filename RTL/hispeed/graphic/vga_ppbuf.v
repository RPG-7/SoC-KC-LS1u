module vga_ppbuf
(
    input sys_clk,pix_clk,rst,
    input [11:0]sys_addr,pix_addr,
    input [7:0]sysdati,
    output[7:0]sysdato,pixdato,
    input sys_we,sys_ce
);

`ifdef VENDOR_ANLOGIC
AL_LOGIC_BRAM #( .DATA_WIDTH_A(8),
				.DATA_WIDTH_B(8),
				.ADDR_WIDTH_A(11),
				.ADDR_WIDTH_B(11),
				.DATA_DEPTH_A(2048),
				.DATA_DEPTH_B(2048),
				.MODE("DP"),
				.REGMODE_A("OUTREG"),
				.REGMODE_B("NOREG"),
				.WRITEMODE_A("NORMAL"),
				.WRITEMODE_B("NORMAL"),
				.RESETMODE("SYNC"),
				.IMPLEMENT("9K"),
				.INIT_FILE("NONE"),
				.FILL_ALL("NONE"))
			BRAM_PPBUF(
				.dia(sysdati),
				.dib(),
				.addra(sys_addr),
				.addrb(pix_addr),
				.cea(cea),
				.ceb(ceb),
				.ocea(ocea),
				.oceb(1'b0),
				.clka(sys_clk),
				.clkb(pix_clk),
				.wea(sys_we),
				.web(1'b0),
				.bea(1'b0),
				.beb(1'b0),
				.rsta(rst),
				.rstb(1'b0),
				.doa(sysdato),
				.dob(pixdato));
`elsif VENDOR_GOWIN

`elsif VENDOR_ALTERA


`else 
	reg [7:0]sysdobuf;
	reg [7:0]vga_buf[2047:0];
	always@(posedge sys_clk)
	begin
		if(sys_ce)
		begin
			if(sys_we)vga_buf[sys_addr]<=sysdati;
			sysdobuf<=vga_buf[sys_addr];
		end
	end
	assign pixdato=vga_buf[pix_addr];
`endif 

endmodule