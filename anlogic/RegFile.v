module regfile_test(input clk,rst,output j);
reg [64:0]lfsr_65;
reg [4:0]lfsra,lfsrb,cnt;
always@(posedge clk or posedge rst)
if(rst)
begin
lfsr_65<=1;
lfsra<=1;
lfsrb<=1;
cnt<=0;
end
else
begin
lfsr_65<={lfsr_65[63:0],lfsr_65[0]^lfsr_65[15]};
lfsra<={lfsra[3:0],lfsra[1]^lfsra[0]};
lfsrb<={lfsrb[3:0],lfsrb[2]^lfsrb[4]};
cnt<=cnt+1;

end

RegFile regfile
(
	.addra(lfsra),
	.addrb(lfsrb),	
	.addrw(cnt),	
	.clk(clk),	
	.we(lfsr_65[64]),
	.di(lfsr_65[63:0]),	
	.doa(),	
	.dob(),	
	.j(j) 
	
);

endmodule

module RegFile
(
	input [4:0]addra,addrb,addrw,
	input clk,we,
	input [63:0]di,	
	output [63:0]doa,dob,	
	output j 
	
);	
reg [63:0]regmem[31:0];//synthesis ram_style=dram
assign doa=regmem[addra];	
assign dob=regmem[addrb];
assign j=doa>=dob;
always@(posedge clk)
begin
	if(we)regmem[addrw]<=di;
end
endmodule