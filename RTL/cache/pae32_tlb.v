//This "MMU" only translates VA to PA, 
module pae32_mmu
(
	input clk,rst,
	input [15:0]ipae_h16,//From MMU control regs
	input [15:0]dpae_h16,
	input [7:0]ipte_h8,
	input [7:0]dpte_h8,
	input [11:0]os_largepage_ptr, //for OS working in pure physical address mode 
	input mmu_enable,
	input supervisor_mode,
	input [7:0]iva_h8,
	input [7:0]dva_h8,
	output reg [15:0]ipa_h16,
	output reg [15:0]dpa_h16,
	output reg exp_iptemiss,
	output reg exp_dptemiss,
	output reg cpu_savexp

);
always @(*) 
begin
	
end
endmodule
