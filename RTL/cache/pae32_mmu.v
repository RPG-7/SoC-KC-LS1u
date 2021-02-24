//This "MMU" only translates VA to PA, check if addr is within boundry
//and generate exceptions
//Instruction is 32K Word/Page
//Data is 64K Byte/Page

module pae32_mmu
(
	input clk,
	input [15:0]ipae_h16,//From MMU control regs
	input [15:0]dpae_h16,
	input [7:0]ipte_h8,
	input [7:0]dpte_h8,
	input [10:0]hugepage_ptr, //for OS working in pure physical address mode 
	input mmu_enable,
	input supervisor_mode,//IN_ISP
	input req_type,//0=INSTR 1=DATA
	input [23:0]vai,//Word incr
	output [31:0]pao,
	output xcp_iptemiss,
	output xcp_dptemiss,
	output cache_flush

);
reg mode_dly;
wire [31:0]svmod_dpa,ipa,dpa;
assign pao=(req_type)?dpa:ipa;
assign ipa=(mmu_enable&(!supervisor_mode))?{ipae_h16,vai[15:0]}:{8'h00,vai[23:0]};
assign dpa=(mmu_enable)?((supervisor_mode)?svmod_dpa:{dpae_h16,vai[15:0]}):{8'h00,vai};
assign svmod_dpa=(vai[23:21]==3'b111)?{hugepage_ptr,vai[20:0]}:{8'h00,vai};
assign xcp_dptemiss=(mmu_enable&(!supervisor_mode))&(dpte_h8!=vai[23:16])&(req_type);
assign xcp_iptemiss=(mmu_enable&(!supervisor_mode))&(ipte_h8!=vai[23:16])&(!req_type);
assign cache_flush=(mode_dly^supervisor_mode)&mmu_enable;
always@(posedge clk)
begin
	if(mmu_enable)mode_dly<=supervisor_mode;
	else mode_dly<=1'b1;
end
endmodule
