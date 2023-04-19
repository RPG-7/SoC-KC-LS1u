/*ALU Opcode list
0x00 A+B
0x01 A-B
0x02 A+B CARRY
0x03 A-B CARRY
0x04 A==B -> CARRY
0x05 A&B
0x06 A|B
0x07 A!
0x08 A^B
0x09 {A[6:0],B[7]}
0x0a {A[0],B[7:1]}
0x0b A RCS
0x0c A>>1
0x0d A<<1
0x0e B<<1
0x0f (A*B) [7:0]
0x10 (A*B) [15:8]
0x11 A DIV B
0x12 A MOD B
0x13 A+1
0x14 A-1
0x15 A+1 CARRY
0x16 A-1 CARRY
0x17 A
0x18 B
*/
module Glow_v1_ALU(
    input clk,rst,
    input AluSel,
    input [7:0]DSrcA,
    input [7:0]DSrcB,
    input [4:0]Opcode,
    output OpFinish,
    output [7:0]Dato
);

wire multycycle_finish;
reg [15:0] muldiv_sft;

assign OpFinish=((Opcode==5'h0f)|(Opcode==5'h10)|
    (Opcode==5'h11)|(Opcode==5'h12)|)?multycycle_finish:1'b1;
    

endmodule 