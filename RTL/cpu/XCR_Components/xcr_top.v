/******************
    Memory Mapping:
    0x00~0x0F Interrupt controller
    0x10~0x1F PAE32 MMU
    0x20~0x2F cDMA controller
*****************/
module xcr_top 
#(parameter MMU_ENABLE=1'b1,
    cDMA_ENABLE=1'b0)
(
    input wire clk,
    input wire rst,
    
    input [7:0]cr_din,
    output reg[7:0]cr_dout,
    input [7:0]cr_adr,
    input cr_we,
	input cr_cs,
    
    input [7:0]INT_ARR,
    input [7:0]XCP_ARR,
    output [23:0]IVEC_ADDR,
    output INT,

    output [15:0]ipae_h16,//From MMU control regs
	output [15:0]dpae_h16,
	output [7:0]ipte_h8,
	output [7:0]dpte_h8,
	output [10:0]hugepage_ptr, //for OS working in pure physical address mode 
	output mmu_enable,
    output supervisor_mode
);
wire [7:0]ecp_dout,mmuc_dout,cdma_dout;
wire ecp_cs,mmuc_cs;
xcr_ecp_lite Interrupt_Controller
(
    .clk(clk),
    .rst(rst),
    .INT_ARR(INT_ARR),
    .XCP_ARR(XCP_ARR),
    .IVEC_ADDR(IVEC_ADDR),
    .INT(INT),
    .cr_din(cr_din),
    .cr_dout(ecp_dout),
    .cr_adr(cr_adr[2:0]),
    .cr_we(cr_we),
	.cr_cs(ecp_cs)

);
generate 
if(MMU_ENABLE)
begin
    xcr_pae32_ctrl MMU_Control
    (
        .clk(clk),
        .rst(rst),
        .cr_din(cr_din),
        .cr_dout(mmuc_dout),
        .cr_adr(cr_adr[2:0]),
        .cr_we(cr_we),
        .cr_cs(mmuc_cs),
        .ipae_h16(ipae_h16),
        .dpae_h16(dpae_h16),
        .ipte_h8(ipte_h8),
        .dpte_h8(dpte_h8),
        .hugepage_ptr(hugepage_ptr), 
        .mmu_enable(mmu_enable),
        .supervisor_mode(supervisor_mode)
    );
    assign mmuc_cs = cr_adr[7:4]==4'h1 & cr_cs;
end
else
begin
    assign mmuc_dout=8'h00;
    assign ipae_h16=16'h0000;//From MMU control regs
	assign dpae_h16=16'h0000;
	assign ipte_h8=8'h00;
	assign dpte_h8=8'h00;
	assign hugepage_ptr=10'h000;
	assign mmu_enable=0;
    assign mmuc_cs = 1'h0;
end
endgenerate


assign ecp_cs = cr_adr[7:4]==4'h0 & cr_cs;
always@(*)
    case(cr_adr[7:4])
        4'h0:cr_dout=ecp_dout;
        4'h1:if(MMU_ENABLE)cr_dout=mmuc_dout;
                else cr_dout=8'h00;
        default:cr_dout=8'h00;
    endcase


endmodule