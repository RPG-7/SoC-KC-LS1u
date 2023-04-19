//This "MMU" only translates VA to PA, check if addr is within boundry
//and generate exceptions
//Instruction is 32K Word/Page
//Data is 64K Byte/Page
//0x00 MMUMOD:{PAE_ENABLE,SVMOD,Huge Page Address [31:29]}
//0x01 HPADR0:Huge Page Address [28:21]
//0x02 IPTE  :Instr VA [23:16]
//0x03 IPAE0 :Instr PA [23:16]
//0x04 IPAE1 :Instr PA [31:24]
//0x05 DPTE  :Data VA [23:16]
//0x06 DPAE0 :Data PA [23:16]
//0x07 DPAE1 :Data PA [31:24]
module xcr_pae32_ctrl
(
	input clk,rst,
	//XCR Bus
	input [7:0]cr_din,
    output reg[7:0]cr_dout,
    input [2:0]cr_adr,
    input cr_we,
	input cr_cs,

//Translated Physical Address
	output reg [15:0]ipae_h16,//From MMU control regs
	output reg [15:0]dpae_h16,
//High 8Bit Virtual Address as Tag Entry
	output reg [7:0]ipte_h8,
	output reg [7:0]dpte_h8,
//for OS working in pure physical address mode 
//High Memory accessed as HugePage
	output reg [10:0]hugepage_ptr, 
//1=Enable MMU, work at HPM(Suppervisor)/ATM(User)
//0=Classic 24bit flat KC-LS1u mode
	output reg mmu_enable,
//1=Always at Supervisor mode, use hugepage,no TLB 
//0=ISP in supervisor mode,RET to user level TLB
	output reg supervisor_mode

);
always@(*)
begin
	case({(cr_cs&(!cr_we)),cr_adr})
	4'h8:cr_dout={mmu_enable,supervisor_mode,3'b00,hugepage_ptr[10:8]};
	4'h9:cr_dout=hugepage_ptr[7:0];
	4'hA:cr_dout=ipte_h8;
	4'hB:cr_dout=ipae_h16[15:8];
	4'hC:cr_dout=ipae_h16[7:0];
	4'hD:cr_dout=dpte_h8;
	4'hE:cr_dout=dpae_h16[15:8];
	4'hF:cr_dout=dpae_h16[7:0];
	default:cr_dout=8'hzz;
	endcase
end

always@(posedge clk or posedge rst)
if(rst)
	{mmu_enable,supervisor_mode}<=2'b00;
else if(cr_cs&cr_we&cr_adr==3'h0)
	{mmu_enable,supervisor_mode}<=cr_din[7:6];
else
	{mmu_enable,supervisor_mode}<={mmu_enable,supervisor_mode};

always@(posedge clk)
if(cr_cs&cr_we)
	case (cr_adr)
		3'h0: hugepage_ptr[10:8]<=cr_din[2:0];
		3'h1: hugepage_ptr[7:0]<=cr_din;
		3'h2: ipte_h8<=cr_din;
		3'h3: ipae_h16[15:8]<=cr_din;
		3'h4: ipae_h16[7:0]<=cr_din;
		3'h5: dpte_h8<=cr_din;
		3'h6: dpae_h16[15:8]<=cr_din;
		3'h7: dpae_h16[7:0]<=cr_din;
	endcase




endmodule
