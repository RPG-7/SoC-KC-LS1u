// Verilog netlist created by TD v4.6.64949
// Mon Jan  1 03:40:18 2024

`timescale 1ns / 1ps
module KC_LS1u  // ../../RTL/cpu/KC_LS1u.v(1)
  (
  WAIT,
  clk,
  ddata_i,
  instr,
  rst,
  daddr,
  ddata_o,
  dwrite,
  iaddr
  );

  input WAIT;  // ../../RTL/cpu/KC_LS1u.v(4)
  input clk;  // ../../RTL/cpu/KC_LS1u.v(3)
  input [7:0] ddata_i;  // ../../RTL/cpu/KC_LS1u.v(8)
  input [15:0] instr;  // ../../RTL/cpu/KC_LS1u.v(6)
  input rst;  // ../../RTL/cpu/KC_LS1u.v(3)
  output [23:0] daddr;  // ../../RTL/cpu/KC_LS1u.v(7)
  output [7:0] ddata_o;  // ../../RTL/cpu/KC_LS1u.v(9)
  output dwrite;  // ../../RTL/cpu/KC_LS1u.v(10)
  output [23:0] iaddr;  // ../../RTL/cpu/KC_LS1u.v(5)

  wire [7:0] A;  // ../../RTL/cpu/KC_LS1u.v(40)
  wire [1:0] ALU_eq;  // ../../RTL/cpu/KC_LS1u.v(131)
  wire [7:0] ALU_out;  // ../../RTL/cpu/KC_LS1u.v(130)
  wire [7:0] B;  // ../../RTL/cpu/KC_LS1u.v(40)
  wire [7:0] C;  // ../../RTL/cpu/KC_LS1u.v(40)
  wire [7:0] D;  // ../../RTL/cpu/KC_LS1u.v(40)
  wire [7:0] DB8w;  // ../../RTL/cpu/KC_LS1u.v(14)
  wire [3:0] dbsrc_addr;  // ../../RTL/cpu/KC_LS1u.v(82)
  wire [4:0] funct5;  // ../../RTL/cpu/KC_LS1u.v(85)
  wire [23:0] n10;
  wire [23:0] n9;
  wire \ALU_H4/SYNTHESIZED_WIRE_10 ;  // ../../RTL/cpu/alu74181.v(18)
  wire \ALU_H4/SYNTHESIZED_WIRE_101 ;  // ../../RTL/cpu/alu74181.v(56)
  wire \ALU_H4/SYNTHESIZED_WIRE_102 ;  // ../../RTL/cpu/alu74181.v(57)
  wire \ALU_H4/SYNTHESIZED_WIRE_103 ;  // ../../RTL/cpu/alu74181.v(58)
  wire \ALU_H4/SYNTHESIZED_WIRE_105 ;  // ../../RTL/cpu/alu74181.v(59)
  wire \ALU_H4/SYNTHESIZED_WIRE_11 ;  // ../../RTL/cpu/alu74181.v(19)
  wire \ALU_H4/SYNTHESIZED_WIRE_115 ;  // ../../RTL/cpu/alu74181.v(65)
  wire \ALU_H4/SYNTHESIZED_WIRE_116 ;  // ../../RTL/cpu/alu74181.v(60)
  wire \ALU_H4/SYNTHESIZED_WIRE_117 ;  // ../../RTL/cpu/alu74181.v(11)
  wire \ALU_H4/SYNTHESIZED_WIRE_118 ;  // ../../RTL/cpu/alu74181.v(12)
  wire \ALU_H4/SYNTHESIZED_WIRE_119 ;  // ../../RTL/cpu/alu74181.v(13)
  wire \ALU_H4/SYNTHESIZED_WIRE_12 ;  // ../../RTL/cpu/alu74181.v(20)
  wire \ALU_H4/SYNTHESIZED_WIRE_128 ;  // ../../RTL/cpu/alu74181.v(41)
  wire \ALU_H4/SYNTHESIZED_WIRE_129 ;  // ../../RTL/cpu/alu74181.v(42)
  wire \ALU_H4/SYNTHESIZED_WIRE_13 ;  // ../../RTL/cpu/alu74181.v(21)
  wire \ALU_H4/SYNTHESIZED_WIRE_14 ;  // ../../RTL/cpu/alu74181.v(22)
  wire \ALU_H4/SYNTHESIZED_WIRE_15 ;  // ../../RTL/cpu/alu74181.v(23)
  wire \ALU_H4/SYNTHESIZED_WIRE_16 ;  // ../../RTL/cpu/alu74181.v(24)
  wire \ALU_H4/SYNTHESIZED_WIRE_17 ;  // ../../RTL/cpu/alu74181.v(25)
  wire \ALU_H4/SYNTHESIZED_WIRE_18 ;  // ../../RTL/cpu/alu74181.v(26)
  wire \ALU_H4/SYNTHESIZED_WIRE_19 ;  // ../../RTL/cpu/alu74181.v(27)
  wire \ALU_H4/SYNTHESIZED_WIRE_20 ;  // ../../RTL/cpu/alu74181.v(28)
  wire \ALU_H4/SYNTHESIZED_WIRE_21 ;  // ../../RTL/cpu/alu74181.v(29)
  wire \ALU_H4/SYNTHESIZED_WIRE_22 ;  // ../../RTL/cpu/alu74181.v(30)
  wire \ALU_H4/SYNTHESIZED_WIRE_23 ;  // ../../RTL/cpu/alu74181.v(31)
  wire \ALU_H4/SYNTHESIZED_WIRE_24 ;  // ../../RTL/cpu/alu74181.v(32)
  wire \ALU_H4/SYNTHESIZED_WIRE_25 ;  // ../../RTL/cpu/alu74181.v(33)
  wire \ALU_H4/SYNTHESIZED_WIRE_26 ;  // ../../RTL/cpu/alu74181.v(34)
  wire \ALU_H4/SYNTHESIZED_WIRE_27 ;  // ../../RTL/cpu/alu74181.v(35)
  wire \ALU_H4/SYNTHESIZED_WIRE_28 ;  // ../../RTL/cpu/alu74181.v(36)
  wire \ALU_H4/SYNTHESIZED_WIRE_29 ;  // ../../RTL/cpu/alu74181.v(37)
  wire \ALU_H4/SYNTHESIZED_WIRE_56 ;  // ../../RTL/cpu/alu74181.v(38)
  wire \ALU_H4/SYNTHESIZED_WIRE_57 ;  // ../../RTL/cpu/alu74181.v(39)
  wire \ALU_H4/SYNTHESIZED_WIRE_58 ;  // ../../RTL/cpu/alu74181.v(40)
  wire \ALU_H4/SYNTHESIZED_WIRE_6 ;  // ../../RTL/cpu/alu74181.v(14)
  wire \ALU_H4/SYNTHESIZED_WIRE_7 ;  // ../../RTL/cpu/alu74181.v(15)
  wire \ALU_H4/SYNTHESIZED_WIRE_8 ;  // ../../RTL/cpu/alu74181.v(16)
  wire \ALU_H4/SYNTHESIZED_WIRE_86 ;  // ../../RTL/cpu/alu74181.v(43)
  wire \ALU_H4/SYNTHESIZED_WIRE_87 ;  // ../../RTL/cpu/alu74181.v(44)
  wire \ALU_H4/SYNTHESIZED_WIRE_88 ;  // ../../RTL/cpu/alu74181.v(45)
  wire \ALU_H4/SYNTHESIZED_WIRE_89 ;  // ../../RTL/cpu/alu74181.v(46)
  wire \ALU_H4/SYNTHESIZED_WIRE_9 ;  // ../../RTL/cpu/alu74181.v(17)
  wire \ALU_H4/SYNTHESIZED_WIRE_90 ;  // ../../RTL/cpu/alu74181.v(47)
  wire \ALU_H4/SYNTHESIZED_WIRE_91 ;  // ../../RTL/cpu/alu74181.v(48)
  wire \ALU_H4/SYNTHESIZED_WIRE_92 ;  // ../../RTL/cpu/alu74181.v(49)
  wire \ALU_H4/SYNTHESIZED_WIRE_93 ;  // ../../RTL/cpu/alu74181.v(50)
  wire \ALU_H4/SYNTHESIZED_WIRE_94 ;  // ../../RTL/cpu/alu74181.v(51)
  wire \ALU_H4/SYNTHESIZED_WIRE_97 ;  // ../../RTL/cpu/alu74181.v(53)
  wire \ALU_H4/SYNTHESIZED_WIRE_98 ;  // ../../RTL/cpu/alu74181.v(54)
  wire \ALU_H4/SYNTHESIZED_WIRE_99 ;  // ../../RTL/cpu/alu74181.v(55)
  wire \ALU_H4/g ;  // ../../RTL/cpu/alu74181.v(8)
  wire \ALU_H4/n0 ;
  wire \ALU_H4/n1 ;
  wire \ALU_H4/n10 ;
  wire \ALU_H4/n11 ;
  wire \ALU_H4/n12 ;
  wire \ALU_H4/n13 ;
  wire \ALU_H4/n14 ;
  wire \ALU_H4/n15 ;
  wire \ALU_H4/n16 ;
  wire \ALU_H4/n17 ;
  wire \ALU_H4/n18 ;
  wire \ALU_H4/n19 ;
  wire \ALU_H4/n2 ;
  wire \ALU_H4/n20 ;
  wire \ALU_H4/n22 ;
  wire \ALU_H4/n23 ;
  wire \ALU_H4/n24 ;
  wire \ALU_H4/n25 ;
  wire \ALU_H4/n26 ;
  wire \ALU_H4/n27 ;
  wire \ALU_H4/n28 ;
  wire \ALU_H4/n29 ;
  wire \ALU_H4/n3 ;
  wire \ALU_H4/n30 ;
  wire \ALU_H4/n31 ;
  wire \ALU_H4/n32 ;
  wire \ALU_H4/n33 ;
  wire \ALU_H4/n34 ;
  wire \ALU_H4/n35 ;
  wire \ALU_H4/n36 ;
  wire \ALU_H4/n37 ;
  wire \ALU_H4/n38 ;
  wire \ALU_H4/n39 ;
  wire \ALU_H4/n4 ;
  wire \ALU_H4/n40 ;
  wire \ALU_H4/n41 ;
  wire \ALU_H4/n42 ;
  wire \ALU_H4/n43 ;
  wire \ALU_H4/n44 ;
  wire \ALU_H4/n45 ;
  wire \ALU_H4/n46 ;
  wire \ALU_H4/n47 ;
  wire \ALU_H4/n5 ;
  wire \ALU_H4/n6 ;
  wire \ALU_H4/n7 ;
  wire \ALU_H4/n8 ;
  wire \ALU_H4/n9 ;
  wire \ALU_L4/SYNTHESIZED_WIRE_10 ;  // ../../RTL/cpu/alu74181.v(18)
  wire \ALU_L4/SYNTHESIZED_WIRE_101 ;  // ../../RTL/cpu/alu74181.v(56)
  wire \ALU_L4/SYNTHESIZED_WIRE_103 ;  // ../../RTL/cpu/alu74181.v(58)
  wire \ALU_L4/SYNTHESIZED_WIRE_105 ;  // ../../RTL/cpu/alu74181.v(59)
  wire \ALU_L4/SYNTHESIZED_WIRE_11 ;  // ../../RTL/cpu/alu74181.v(19)
  wire \ALU_L4/SYNTHESIZED_WIRE_115 ;  // ../../RTL/cpu/alu74181.v(65)
  wire \ALU_L4/SYNTHESIZED_WIRE_116 ;  // ../../RTL/cpu/alu74181.v(60)
  wire \ALU_L4/SYNTHESIZED_WIRE_117 ;  // ../../RTL/cpu/alu74181.v(11)
  wire \ALU_L4/SYNTHESIZED_WIRE_118 ;  // ../../RTL/cpu/alu74181.v(12)
  wire \ALU_L4/SYNTHESIZED_WIRE_119 ;  // ../../RTL/cpu/alu74181.v(13)
  wire \ALU_L4/SYNTHESIZED_WIRE_12 ;  // ../../RTL/cpu/alu74181.v(20)
  wire \ALU_L4/SYNTHESIZED_WIRE_129 ;  // ../../RTL/cpu/alu74181.v(42)
  wire \ALU_L4/SYNTHESIZED_WIRE_13 ;  // ../../RTL/cpu/alu74181.v(21)
  wire \ALU_L4/SYNTHESIZED_WIRE_14 ;  // ../../RTL/cpu/alu74181.v(22)
  wire \ALU_L4/SYNTHESIZED_WIRE_15 ;  // ../../RTL/cpu/alu74181.v(23)
  wire \ALU_L4/SYNTHESIZED_WIRE_16 ;  // ../../RTL/cpu/alu74181.v(24)
  wire \ALU_L4/SYNTHESIZED_WIRE_17 ;  // ../../RTL/cpu/alu74181.v(25)
  wire \ALU_L4/SYNTHESIZED_WIRE_18 ;  // ../../RTL/cpu/alu74181.v(26)
  wire \ALU_L4/SYNTHESIZED_WIRE_19 ;  // ../../RTL/cpu/alu74181.v(27)
  wire \ALU_L4/SYNTHESIZED_WIRE_20 ;  // ../../RTL/cpu/alu74181.v(28)
  wire \ALU_L4/SYNTHESIZED_WIRE_21 ;  // ../../RTL/cpu/alu74181.v(29)
  wire \ALU_L4/SYNTHESIZED_WIRE_22 ;  // ../../RTL/cpu/alu74181.v(30)
  wire \ALU_L4/SYNTHESIZED_WIRE_23 ;  // ../../RTL/cpu/alu74181.v(31)
  wire \ALU_L4/SYNTHESIZED_WIRE_24 ;  // ../../RTL/cpu/alu74181.v(32)
  wire \ALU_L4/SYNTHESIZED_WIRE_25 ;  // ../../RTL/cpu/alu74181.v(33)
  wire \ALU_L4/SYNTHESIZED_WIRE_26 ;  // ../../RTL/cpu/alu74181.v(34)
  wire \ALU_L4/SYNTHESIZED_WIRE_27 ;  // ../../RTL/cpu/alu74181.v(35)
  wire \ALU_L4/SYNTHESIZED_WIRE_28 ;  // ../../RTL/cpu/alu74181.v(36)
  wire \ALU_L4/SYNTHESIZED_WIRE_29 ;  // ../../RTL/cpu/alu74181.v(37)
  wire \ALU_L4/SYNTHESIZED_WIRE_6 ;  // ../../RTL/cpu/alu74181.v(14)
  wire \ALU_L4/SYNTHESIZED_WIRE_7 ;  // ../../RTL/cpu/alu74181.v(15)
  wire \ALU_L4/SYNTHESIZED_WIRE_8 ;  // ../../RTL/cpu/alu74181.v(16)
  wire \ALU_L4/SYNTHESIZED_WIRE_86 ;  // ../../RTL/cpu/alu74181.v(43)
  wire \ALU_L4/SYNTHESIZED_WIRE_87 ;  // ../../RTL/cpu/alu74181.v(44)
  wire \ALU_L4/SYNTHESIZED_WIRE_88 ;  // ../../RTL/cpu/alu74181.v(45)
  wire \ALU_L4/SYNTHESIZED_WIRE_89 ;  // ../../RTL/cpu/alu74181.v(46)
  wire \ALU_L4/SYNTHESIZED_WIRE_9 ;  // ../../RTL/cpu/alu74181.v(17)
  wire \ALU_L4/SYNTHESIZED_WIRE_90 ;  // ../../RTL/cpu/alu74181.v(47)
  wire \ALU_L4/SYNTHESIZED_WIRE_91 ;  // ../../RTL/cpu/alu74181.v(48)
  wire \ALU_L4/SYNTHESIZED_WIRE_92 ;  // ../../RTL/cpu/alu74181.v(49)
  wire \ALU_L4/SYNTHESIZED_WIRE_93 ;  // ../../RTL/cpu/alu74181.v(50)
  wire \ALU_L4/SYNTHESIZED_WIRE_94 ;  // ../../RTL/cpu/alu74181.v(51)
  wire \ALU_L4/SYNTHESIZED_WIRE_98 ;  // ../../RTL/cpu/alu74181.v(54)
  wire \ALU_L4/SYNTHESIZED_WIRE_99 ;  // ../../RTL/cpu/alu74181.v(55)
  wire \ALU_L4/n0 ;
  wire \ALU_L4/n1 ;
  wire \ALU_L4/n10 ;
  wire \ALU_L4/n11 ;
  wire \ALU_L4/n12 ;
  wire \ALU_L4/n13 ;
  wire \ALU_L4/n14 ;
  wire \ALU_L4/n15 ;
  wire \ALU_L4/n16 ;
  wire \ALU_L4/n17 ;
  wire \ALU_L4/n2 ;
  wire \ALU_L4/n22 ;
  wire \ALU_L4/n3 ;
  wire \ALU_L4/n31 ;
  wire \ALU_L4/n32 ;
  wire \ALU_L4/n33 ;
  wire \ALU_L4/n34 ;
  wire \ALU_L4/n35 ;
  wire \ALU_L4/n36 ;
  wire \ALU_L4/n37 ;
  wire \ALU_L4/n38 ;
  wire \ALU_L4/n39 ;
  wire \ALU_L4/n4 ;
  wire \ALU_L4/n40 ;
  wire \ALU_L4/n41 ;
  wire \ALU_L4/n43 ;
  wire \ALU_L4/n44 ;
  wire \ALU_L4/n45 ;
  wire \ALU_L4/n46 ;
  wire \ALU_L4/n47 ;
  wire \ALU_L4/n5 ;
  wire \ALU_L4/n6 ;
  wire \ALU_L4/n7 ;
  wire \ALU_L4/n8 ;
  wire \ALU_L4/n9 ;
  wire ALU_eqo;  // ../../RTL/cpu/KC_LS1u.v(132)
  wire \instr[10]_neg ;
  wire \instr[8]_neg ;
  wire \instr[9]_neg ;
  wire jmp;  // ../../RTL/cpu/KC_LS1u.v(15)
  wire jmp_en;  // ../../RTL/cpu/KC_LS1u.v(75)
  wire mux10_b0_sel_is_3_o;
  wire mux11_b0_sel_is_3_o;
  wire mux12_b0_sel_is_3_o;
  wire mux13_b0_sel_is_3_o;
  wire mux14_b0_sel_is_3_o;
  wire mux15_b0_sel_is_3_o;
  wire mux16_b0_sel_is_3_o;
  wire mux17_b0_sel_is_3_o;
  wire mux2_b0_sel_is_7_o;
  wire mux3_b0_sel_is_6_o;
  wire mux4_b0_sel_is_5_o;
  wire mux5_b0_sel_is_4_o;
  wire mux6_b0_sel_is_3_o;
  wire mux7_b0_sel_is_2_o;
  wire mux8_b0_sel_is_1_o;
  wire mux9_b0_sel_is_0_o;
  wire n0;
  wire n1;
  wire n12;
  wire n2;
  wire n21;
  wire n3;
  wire n30;
  wire n31;
  wire n32;
  wire n33;
  wire n34;
  wire n35;
  wire n36;
  wire n37;
  wire n38;
  wire n39;
  wire n4;
  wire n40;
  wire n41;
  wire n42;
  wire n43;
  wire n44;
  wire n45;
  wire n46;
  wire n47;
  wire n48;
  wire n49;
  wire n5;
  wire n51;
  wire n53;
  wire n55;
  wire n6;
  wire n7;
  wire n8;
  wire regwrite;  // ../../RTL/cpu/KC_LS1u.v(37)
  wire rst_neg;
  wire sel0_b0_sel_o;  // ../../RTL/cpu/KC_LS1u.v(121)
  wire sel0_b1_sel_o;  // ../../RTL/cpu/KC_LS1u.v(121)
  wire sel0_b2_sel_o;  // ../../RTL/cpu/KC_LS1u.v(121)
  wire sel0_b3_sel_o;  // ../../RTL/cpu/KC_LS1u.v(121)

  and \ALU_H4/u1  (\ALU_H4/SYNTHESIZED_WIRE_14 , instr[4], B[5]);  // ../../RTL/cpu/alu74181.v(73)
  and \ALU_H4/u10  (\ALU_H4/SYNTHESIZED_WIRE_23 , \ALU_H4/n2 , A[6]);  // ../../RTL/cpu/alu74181.v(85)
  and \ALU_H4/u100  (\ALU_H4/n44 , \ALU_H4/SYNTHESIZED_WIRE_129 , instr[6]);  // ../../RTL/cpu/alu74181.v(175)
  and \ALU_H4/u101  (\ALU_H4/SYNTHESIZED_WIRE_19 , \ALU_H4/n44 , A[4]);  // ../../RTL/cpu/alu74181.v(175)
  xor \ALU_H4/u102  (ALU_out[4], \ALU_H4/SYNTHESIZED_WIRE_101 , \ALU_H4/SYNTHESIZED_WIRE_102 );  // ../../RTL/cpu/alu74181.v(177)
  xor \ALU_H4/u103  (ALU_out[5], \ALU_H4/SYNTHESIZED_WIRE_103 , \ALU_H4/SYNTHESIZED_WIRE_115 );  // ../../RTL/cpu/alu74181.v(179)
  xor \ALU_H4/u104  (ALU_out[6], \ALU_H4/SYNTHESIZED_WIRE_105 , \ALU_H4/SYNTHESIZED_WIRE_116 );  // ../../RTL/cpu/alu74181.v(181)
  and \ALU_H4/u105  (\ALU_H4/n45 , ALU_out[7], ALU_out[6]);  // ../../RTL/cpu/alu74181.v(183)
  and \ALU_H4/u106  (\ALU_H4/n46 , \ALU_H4/n45 , ALU_out[5]);  // ../../RTL/cpu/alu74181.v(183)
  and \ALU_H4/u107  (ALU_eq[1], \ALU_H4/n46 , ALU_out[4]);  // ../../RTL/cpu/alu74181.v(183)
  and \ALU_H4/u108  (\ALU_H4/n47 , A[4], instr[7]);  // ../../RTL/cpu/alu74181.v(185)
  and \ALU_H4/u109  (\ALU_H4/SYNTHESIZED_WIRE_18 , \ALU_H4/n47 , B[4]);  // ../../RTL/cpu/alu74181.v(185)
  and \ALU_H4/u11  (\ALU_H4/n3 , A[6], instr[7]);  // ../../RTL/cpu/alu74181.v(87)
  not \ALU_H4/u110  (\ALU_H4/SYNTHESIZED_WIRE_128 , instr[3]);  // ../../RTL/cpu/alu74181.v(187)
  and \ALU_H4/u12  (\ALU_H4/SYNTHESIZED_WIRE_22 , \ALU_H4/n3 , B[6]);  // ../../RTL/cpu/alu74181.v(87)
  and \ALU_H4/u13  (\ALU_H4/SYNTHESIZED_WIRE_26 , instr[4], B[7]);  // ../../RTL/cpu/alu74181.v(89)
  and \ALU_H4/u14  (\ALU_H4/SYNTHESIZED_WIRE_27 , \ALU_H4/SYNTHESIZED_WIRE_119 , instr[5]);  // ../../RTL/cpu/alu74181.v(91)
  and \ALU_H4/u15  (\ALU_H4/n4 , \ALU_H4/SYNTHESIZED_WIRE_119 , instr[6]);  // ../../RTL/cpu/alu74181.v(93)
  and \ALU_H4/u16  (\ALU_H4/SYNTHESIZED_WIRE_29 , \ALU_H4/n4 , A[7]);  // ../../RTL/cpu/alu74181.v(93)
  and \ALU_H4/u17  (\ALU_H4/n5 , A[7], instr[7]);  // ../../RTL/cpu/alu74181.v(95)
  and \ALU_H4/u18  (\ALU_H4/SYNTHESIZED_WIRE_28 , \ALU_H4/n5 , B[7]);  // ../../RTL/cpu/alu74181.v(95)
  not \ALU_H4/u19  (\ALU_H4/SYNTHESIZED_WIRE_119 , B[7]);  // ../../RTL/cpu/alu74181.v(97)
  and \ALU_H4/u2  (\ALU_H4/SYNTHESIZED_WIRE_15 , \ALU_H4/SYNTHESIZED_WIRE_117 , instr[5]);  // ../../RTL/cpu/alu74181.v(75)
  not \ALU_H4/u20  (\ALU_H4/SYNTHESIZED_WIRE_129 , B[4]);  // ../../RTL/cpu/alu74181.v(99)
  not \ALU_H4/u21  (\ALU_H4/SYNTHESIZED_WIRE_117 , B[5]);  // ../../RTL/cpu/alu74181.v(101)
  not \ALU_H4/u22  (\ALU_H4/SYNTHESIZED_WIRE_118 , B[6]);  // ../../RTL/cpu/alu74181.v(103)
  or \ALU_H4/u23  (\ALU_H4/n6 , A[4], \ALU_H4/SYNTHESIZED_WIRE_12 );  // ../../RTL/cpu/alu74181.v(105)
  or \ALU_H4/u24  (\ALU_H4/n7 , \ALU_H4/n6 , \ALU_H4/SYNTHESIZED_WIRE_13 );  // ../../RTL/cpu/alu74181.v(105)
  not \ALU_H4/u25  (\ALU_H4/SYNTHESIZED_WIRE_6 , \ALU_H4/n7 );  // ../../RTL/cpu/alu74181.v(105)
  or \ALU_H4/u26  (\ALU_H4/n8 , A[5], \ALU_H4/SYNTHESIZED_WIRE_14 );  // ../../RTL/cpu/alu74181.v(107)
  or \ALU_H4/u27  (\ALU_H4/n9 , \ALU_H4/n8 , \ALU_H4/SYNTHESIZED_WIRE_15 );  // ../../RTL/cpu/alu74181.v(107)
  not \ALU_H4/u28  (\ALU_H4/SYNTHESIZED_WIRE_8 , \ALU_H4/n9 );  // ../../RTL/cpu/alu74181.v(107)
  or \ALU_H4/u29  (\ALU_H4/n10 , A[6], \ALU_H4/SYNTHESIZED_WIRE_16 );  // ../../RTL/cpu/alu74181.v(109)
  and \ALU_H4/u3  (\ALU_H4/n0 , \ALU_H4/SYNTHESIZED_WIRE_117 , instr[6]);  // ../../RTL/cpu/alu74181.v(77)
  or \ALU_H4/u30  (\ALU_H4/n11 , \ALU_H4/n10 , \ALU_H4/SYNTHESIZED_WIRE_17 );  // ../../RTL/cpu/alu74181.v(109)
  not \ALU_H4/u31  (\ALU_H4/SYNTHESIZED_WIRE_10 , \ALU_H4/n11 );  // ../../RTL/cpu/alu74181.v(109)
  or \ALU_H4/u32  (\ALU_H4/n12 , \ALU_H4/SYNTHESIZED_WIRE_18 , \ALU_H4/SYNTHESIZED_WIRE_19 );  // ../../RTL/cpu/alu74181.v(111)
  not \ALU_H4/u33  (\ALU_H4/SYNTHESIZED_WIRE_7 , \ALU_H4/n12 );  // ../../RTL/cpu/alu74181.v(111)
  or \ALU_H4/u34  (\ALU_H4/n13 , \ALU_H4/SYNTHESIZED_WIRE_20 , \ALU_H4/SYNTHESIZED_WIRE_21 );  // ../../RTL/cpu/alu74181.v(113)
  not \ALU_H4/u35  (\ALU_H4/SYNTHESIZED_WIRE_9 , \ALU_H4/n13 );  // ../../RTL/cpu/alu74181.v(113)
  or \ALU_H4/u36  (\ALU_H4/n14 , \ALU_H4/SYNTHESIZED_WIRE_22 , \ALU_H4/SYNTHESIZED_WIRE_23 );  // ../../RTL/cpu/alu74181.v(115)
  not \ALU_H4/u37  (\ALU_H4/SYNTHESIZED_WIRE_11 , \ALU_H4/n14 );  // ../../RTL/cpu/alu74181.v(115)
  or \ALU_H4/u38  (\ALU_H4/n15 , A[7], \ALU_H4/SYNTHESIZED_WIRE_26 );  // ../../RTL/cpu/alu74181.v(117)
  or \ALU_H4/u39  (\ALU_H4/n16 , \ALU_H4/n15 , \ALU_H4/SYNTHESIZED_WIRE_27 );  // ../../RTL/cpu/alu74181.v(117)
  and \ALU_H4/u4  (\ALU_H4/SYNTHESIZED_WIRE_21 , \ALU_H4/n0 , A[5]);  // ../../RTL/cpu/alu74181.v(77)
  not \ALU_H4/u40  (\ALU_H4/SYNTHESIZED_WIRE_25 , \ALU_H4/n16 );  // ../../RTL/cpu/alu74181.v(117)
  or \ALU_H4/u41  (\ALU_H4/n17 , \ALU_H4/SYNTHESIZED_WIRE_28 , \ALU_H4/SYNTHESIZED_WIRE_29 );  // ../../RTL/cpu/alu74181.v(119)
  not \ALU_H4/u42  (\ALU_H4/SYNTHESIZED_WIRE_24 , \ALU_H4/n17 );  // ../../RTL/cpu/alu74181.v(119)
  xor \ALU_H4/u43  (\ALU_H4/SYNTHESIZED_WIRE_101 , \ALU_H4/SYNTHESIZED_WIRE_7 , \ALU_H4/SYNTHESIZED_WIRE_6 );  // ../../RTL/cpu/alu74181.v(121)
  xor \ALU_H4/u44  (\ALU_H4/SYNTHESIZED_WIRE_103 , \ALU_H4/SYNTHESIZED_WIRE_9 , \ALU_H4/SYNTHESIZED_WIRE_8 );  // ../../RTL/cpu/alu74181.v(123)
  xor \ALU_H4/u45  (\ALU_H4/SYNTHESIZED_WIRE_105 , \ALU_H4/SYNTHESIZED_WIRE_11 , \ALU_H4/SYNTHESIZED_WIRE_10 );  // ../../RTL/cpu/alu74181.v(125)
  xor \ALU_H4/u46  (\ALU_H4/SYNTHESIZED_WIRE_94 , \ALU_H4/SYNTHESIZED_WIRE_24 , \ALU_H4/SYNTHESIZED_WIRE_25 );  // ../../RTL/cpu/alu74181.v(127)
  and \ALU_H4/u47  (\ALU_H4/SYNTHESIZED_WIRE_56 , \ALU_H4/SYNTHESIZED_WIRE_24 , \ALU_H4/SYNTHESIZED_WIRE_10 );  // ../../RTL/cpu/alu74181.v(129)
  and \ALU_H4/u48  (\ALU_H4/n18 , \ALU_H4/SYNTHESIZED_WIRE_8 , \ALU_H4/SYNTHESIZED_WIRE_11 );  // ../../RTL/cpu/alu74181.v(131)
  and \ALU_H4/u49  (\ALU_H4/SYNTHESIZED_WIRE_57 , \ALU_H4/n18 , \ALU_H4/SYNTHESIZED_WIRE_24 );  // ../../RTL/cpu/alu74181.v(131)
  and \ALU_H4/u5  (\ALU_H4/n1 , A[5], instr[7]);  // ../../RTL/cpu/alu74181.v(79)
  and \ALU_H4/u50  (\ALU_H4/SYNTHESIZED_WIRE_12 , instr[4], B[4]);  // ../../RTL/cpu/alu74181.v(133)
  and \ALU_H4/u51  (\ALU_H4/n19 , \ALU_H4/SYNTHESIZED_WIRE_24 , \ALU_H4/SYNTHESIZED_WIRE_11 );  // ../../RTL/cpu/alu74181.v(135)
  and \ALU_H4/u52  (\ALU_H4/n20 , \ALU_H4/n19 , \ALU_H4/SYNTHESIZED_WIRE_9 );  // ../../RTL/cpu/alu74181.v(135)
  and \ALU_H4/u55  (\ALU_H4/n22 , \ALU_H4/SYNTHESIZED_WIRE_11 , \ALU_H4/SYNTHESIZED_WIRE_9 );  // ../../RTL/cpu/alu74181.v(137)
  and \ALU_H4/u56  (\ALU_H4/n23 , \ALU_H4/n22 , \ALU_H4/SYNTHESIZED_WIRE_7 );  // ../../RTL/cpu/alu74181.v(137)
  and \ALU_H4/u57  (\ALU_H4/n24 , \ALU_H4/n23 , \ALU_H4/SYNTHESIZED_WIRE_24 );  // ../../RTL/cpu/alu74181.v(137)
  and \ALU_H4/u58  (\ALU_H4/n25 , \ALU_H4/n24 , instr[2]);  // ../../RTL/cpu/alu74181.v(137)
  and \ALU_H4/u59  (\ALU_H4/n26 , \ALU_H4/n25 , instr[2]);  // ../../RTL/cpu/alu74181.v(137)
  and \ALU_H4/u6  (\ALU_H4/SYNTHESIZED_WIRE_20 , \ALU_H4/n1 , B[5]);  // ../../RTL/cpu/alu74181.v(79)
  not \ALU_H4/u60  (\ALU_H4/SYNTHESIZED_WIRE_97 , \ALU_H4/n26 );  // ../../RTL/cpu/alu74181.v(137)
  and \ALU_H4/u61  (\ALU_H4/SYNTHESIZED_WIRE_58 , \ALU_H4/n20 , \ALU_H4/SYNTHESIZED_WIRE_6 );  // ../../RTL/cpu/alu74181.v(139)
  or \ALU_H4/u62  (\ALU_H4/n27 , \ALU_H4/SYNTHESIZED_WIRE_25 , \ALU_H4/SYNTHESIZED_WIRE_56 );  // ../../RTL/cpu/alu74181.v(141)
  or \ALU_H4/u63  (\ALU_H4/n28 , \ALU_H4/n27 , \ALU_H4/SYNTHESIZED_WIRE_57 );  // ../../RTL/cpu/alu74181.v(141)
  or \ALU_H4/u64  (\ALU_H4/n29 , \ALU_H4/n28 , \ALU_H4/SYNTHESIZED_WIRE_58 );  // ../../RTL/cpu/alu74181.v(141)
  not \ALU_H4/u65  (\ALU_H4/g , \ALU_H4/n29 );  // ../../RTL/cpu/alu74181.v(141)
  and \ALU_H4/u66  (\ALU_H4/n30 , instr[2], \ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(143)
  not \ALU_H4/u67  (\ALU_H4/SYNTHESIZED_WIRE_102 , \ALU_H4/n30 );  // ../../RTL/cpu/alu74181.v(143)
  and \ALU_H4/u68  (\ALU_H4/SYNTHESIZED_WIRE_99 , \ALU_H4/SYNTHESIZED_WIRE_6 , \ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(145)
  and \ALU_H4/u69  (\ALU_H4/n31 , \ALU_H4/SYNTHESIZED_WIRE_128 , \ALU_H4/SYNTHESIZED_WIRE_7 );  // ../../RTL/cpu/alu74181.v(147)
  and \ALU_H4/u7  (\ALU_H4/SYNTHESIZED_WIRE_16 , instr[4], B[6]);  // ../../RTL/cpu/alu74181.v(81)
  and \ALU_H4/u70  (\ALU_H4/SYNTHESIZED_WIRE_98 , \ALU_H4/n31 , instr[2]);  // ../../RTL/cpu/alu74181.v(147)
  and \ALU_H4/u71  (\ALU_H4/SYNTHESIZED_WIRE_90 , \ALU_H4/SYNTHESIZED_WIRE_8 , \ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(149)
  and \ALU_H4/u72  (\ALU_H4/SYNTHESIZED_WIRE_91 , \ALU_H4/SYNTHESIZED_WIRE_99 , \ALU_H4/SYNTHESIZED_WIRE_9 );  // ../../RTL/cpu/alu74181.v(151)
  and \ALU_H4/u73  (\ALU_H4/n32 , instr[2], \ALU_H4/SYNTHESIZED_WIRE_7 );  // ../../RTL/cpu/alu74181.v(153)
  and \ALU_H4/u74  (\ALU_H4/n33 , \ALU_H4/n32 , \ALU_H4/SYNTHESIZED_WIRE_9 );  // ../../RTL/cpu/alu74181.v(153)
  and \ALU_H4/u75  (\ALU_H4/SYNTHESIZED_WIRE_92 , \ALU_H4/n33 , \ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(153)
  and \ALU_H4/u76  (\ALU_H4/SYNTHESIZED_WIRE_13 , \ALU_H4/SYNTHESIZED_WIRE_129 , instr[5]);  // ../../RTL/cpu/alu74181.v(155)
  and \ALU_H4/u77  (\ALU_H4/SYNTHESIZED_WIRE_89 , \ALU_H4/SYNTHESIZED_WIRE_10 , \ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(157)
  and \ALU_H4/u79  (\ALU_H4/SYNTHESIZED_WIRE_88 , \ALU_H4/SYNTHESIZED_WIRE_90 , \ALU_H4/SYNTHESIZED_WIRE_11 );  // ../../RTL/cpu/alu74181.v(159)
  and \ALU_H4/u8  (\ALU_H4/SYNTHESIZED_WIRE_17 , \ALU_H4/SYNTHESIZED_WIRE_118 , instr[5]);  // ../../RTL/cpu/alu74181.v(83)
  and \ALU_H4/u81  (\ALU_H4/n34 , \ALU_H4/n22 , \ALU_H4/SYNTHESIZED_WIRE_6 );  // ../../RTL/cpu/alu74181.v(161)
  and \ALU_H4/u82  (\ALU_H4/SYNTHESIZED_WIRE_87 , \ALU_H4/n34 , \ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(161)
  and \ALU_H4/u85  (\ALU_H4/n35 , \ALU_H4/n33 , instr[2]);  // ../../RTL/cpu/alu74181.v(163)
  and \ALU_H4/u86  (\ALU_H4/n36 , \ALU_H4/n35 , \ALU_H4/SYNTHESIZED_WIRE_11 );  // ../../RTL/cpu/alu74181.v(163)
  and \ALU_H4/u87  (\ALU_H4/SYNTHESIZED_WIRE_86 , \ALU_H4/n36 , \ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(163)
  or \ALU_H4/u88  (\ALU_H4/n37 , \ALU_H4/SYNTHESIZED_WIRE_86 , \ALU_H4/SYNTHESIZED_WIRE_87 );  // ../../RTL/cpu/alu74181.v(165)
  or \ALU_H4/u89  (\ALU_H4/n38 , \ALU_H4/n37 , \ALU_H4/SYNTHESIZED_WIRE_88 );  // ../../RTL/cpu/alu74181.v(165)
  and \ALU_H4/u9  (\ALU_H4/n2 , \ALU_H4/SYNTHESIZED_WIRE_118 , instr[6]);  // ../../RTL/cpu/alu74181.v(85)
  or \ALU_H4/u90  (\ALU_H4/n39 , \ALU_H4/n38 , \ALU_H4/SYNTHESIZED_WIRE_89 );  // ../../RTL/cpu/alu74181.v(165)
  not \ALU_H4/u91  (\ALU_H4/SYNTHESIZED_WIRE_93 , \ALU_H4/n39 );  // ../../RTL/cpu/alu74181.v(165)
  or \ALU_H4/u92  (\ALU_H4/n40 , \ALU_H4/SYNTHESIZED_WIRE_90 , \ALU_H4/SYNTHESIZED_WIRE_91 );  // ../../RTL/cpu/alu74181.v(167)
  or \ALU_H4/u93  (\ALU_H4/n41 , \ALU_H4/n40 , \ALU_H4/SYNTHESIZED_WIRE_92 );  // ../../RTL/cpu/alu74181.v(167)
  not \ALU_H4/u94  (\ALU_H4/SYNTHESIZED_WIRE_116 , \ALU_H4/n41 );  // ../../RTL/cpu/alu74181.v(167)
  xor \ALU_H4/u95  (ALU_out[7], \ALU_H4/SYNTHESIZED_WIRE_94 , \ALU_H4/SYNTHESIZED_WIRE_93 );  // ../../RTL/cpu/alu74181.v(169)
  and \ALU_H4/u96  (\ALU_H4/n42 , \ALU_H4/g , \ALU_H4/SYNTHESIZED_WIRE_97 );  // ../../RTL/cpu/alu74181.v(171)
  or \ALU_H4/u98  (\ALU_H4/n43 , \ALU_H4/SYNTHESIZED_WIRE_98 , \ALU_H4/SYNTHESIZED_WIRE_99 );  // ../../RTL/cpu/alu74181.v(173)
  not \ALU_H4/u99  (\ALU_H4/SYNTHESIZED_WIRE_115 , \ALU_H4/n43 );  // ../../RTL/cpu/alu74181.v(173)
  and \ALU_L4/u1  (\ALU_L4/SYNTHESIZED_WIRE_14 , instr[4], B[1]);  // ../../RTL/cpu/alu74181.v(73)
  and \ALU_L4/u10  (\ALU_L4/SYNTHESIZED_WIRE_23 , \ALU_L4/n2 , A[2]);  // ../../RTL/cpu/alu74181.v(85)
  and \ALU_L4/u100  (\ALU_L4/n44 , \ALU_L4/SYNTHESIZED_WIRE_129 , instr[6]);  // ../../RTL/cpu/alu74181.v(175)
  and \ALU_L4/u101  (\ALU_L4/SYNTHESIZED_WIRE_19 , \ALU_L4/n44 , A[0]);  // ../../RTL/cpu/alu74181.v(175)
  xor \ALU_L4/u102  (ALU_out[0], \ALU_L4/SYNTHESIZED_WIRE_101 , \ALU_H4/SYNTHESIZED_WIRE_102 );  // ../../RTL/cpu/alu74181.v(177)
  xor \ALU_L4/u103  (ALU_out[1], \ALU_L4/SYNTHESIZED_WIRE_103 , \ALU_L4/SYNTHESIZED_WIRE_115 );  // ../../RTL/cpu/alu74181.v(179)
  xor \ALU_L4/u104  (ALU_out[2], \ALU_L4/SYNTHESIZED_WIRE_105 , \ALU_L4/SYNTHESIZED_WIRE_116 );  // ../../RTL/cpu/alu74181.v(181)
  and \ALU_L4/u105  (\ALU_L4/n45 , ALU_out[3], ALU_out[2]);  // ../../RTL/cpu/alu74181.v(183)
  and \ALU_L4/u106  (\ALU_L4/n46 , \ALU_L4/n45 , ALU_out[1]);  // ../../RTL/cpu/alu74181.v(183)
  and \ALU_L4/u107  (ALU_eq[0], \ALU_L4/n46 , ALU_out[0]);  // ../../RTL/cpu/alu74181.v(183)
  and \ALU_L4/u108  (\ALU_L4/n47 , A[0], instr[7]);  // ../../RTL/cpu/alu74181.v(185)
  and \ALU_L4/u109  (\ALU_L4/SYNTHESIZED_WIRE_18 , \ALU_L4/n47 , B[0]);  // ../../RTL/cpu/alu74181.v(185)
  and \ALU_L4/u11  (\ALU_L4/n3 , A[2], instr[7]);  // ../../RTL/cpu/alu74181.v(87)
  and \ALU_L4/u12  (\ALU_L4/SYNTHESIZED_WIRE_22 , \ALU_L4/n3 , B[2]);  // ../../RTL/cpu/alu74181.v(87)
  and \ALU_L4/u13  (\ALU_L4/SYNTHESIZED_WIRE_26 , instr[4], B[3]);  // ../../RTL/cpu/alu74181.v(89)
  and \ALU_L4/u14  (\ALU_L4/SYNTHESIZED_WIRE_27 , \ALU_L4/SYNTHESIZED_WIRE_119 , instr[5]);  // ../../RTL/cpu/alu74181.v(91)
  and \ALU_L4/u15  (\ALU_L4/n4 , \ALU_L4/SYNTHESIZED_WIRE_119 , instr[6]);  // ../../RTL/cpu/alu74181.v(93)
  and \ALU_L4/u16  (\ALU_L4/SYNTHESIZED_WIRE_29 , \ALU_L4/n4 , A[3]);  // ../../RTL/cpu/alu74181.v(93)
  and \ALU_L4/u17  (\ALU_L4/n5 , A[3], instr[7]);  // ../../RTL/cpu/alu74181.v(95)
  and \ALU_L4/u18  (\ALU_L4/SYNTHESIZED_WIRE_28 , \ALU_L4/n5 , B[3]);  // ../../RTL/cpu/alu74181.v(95)
  not \ALU_L4/u19  (\ALU_L4/SYNTHESIZED_WIRE_119 , B[3]);  // ../../RTL/cpu/alu74181.v(97)
  and \ALU_L4/u2  (\ALU_L4/SYNTHESIZED_WIRE_15 , \ALU_L4/SYNTHESIZED_WIRE_117 , instr[5]);  // ../../RTL/cpu/alu74181.v(75)
  not \ALU_L4/u20  (\ALU_L4/SYNTHESIZED_WIRE_129 , B[0]);  // ../../RTL/cpu/alu74181.v(99)
  not \ALU_L4/u21  (\ALU_L4/SYNTHESIZED_WIRE_117 , B[1]);  // ../../RTL/cpu/alu74181.v(101)
  not \ALU_L4/u22  (\ALU_L4/SYNTHESIZED_WIRE_118 , B[2]);  // ../../RTL/cpu/alu74181.v(103)
  or \ALU_L4/u23  (\ALU_L4/n6 , A[0], \ALU_L4/SYNTHESIZED_WIRE_12 );  // ../../RTL/cpu/alu74181.v(105)
  or \ALU_L4/u24  (\ALU_L4/n7 , \ALU_L4/n6 , \ALU_L4/SYNTHESIZED_WIRE_13 );  // ../../RTL/cpu/alu74181.v(105)
  not \ALU_L4/u25  (\ALU_L4/SYNTHESIZED_WIRE_6 , \ALU_L4/n7 );  // ../../RTL/cpu/alu74181.v(105)
  or \ALU_L4/u26  (\ALU_L4/n8 , A[1], \ALU_L4/SYNTHESIZED_WIRE_14 );  // ../../RTL/cpu/alu74181.v(107)
  or \ALU_L4/u27  (\ALU_L4/n9 , \ALU_L4/n8 , \ALU_L4/SYNTHESIZED_WIRE_15 );  // ../../RTL/cpu/alu74181.v(107)
  not \ALU_L4/u28  (\ALU_L4/SYNTHESIZED_WIRE_8 , \ALU_L4/n9 );  // ../../RTL/cpu/alu74181.v(107)
  or \ALU_L4/u29  (\ALU_L4/n10 , A[2], \ALU_L4/SYNTHESIZED_WIRE_16 );  // ../../RTL/cpu/alu74181.v(109)
  and \ALU_L4/u3  (\ALU_L4/n0 , \ALU_L4/SYNTHESIZED_WIRE_117 , instr[6]);  // ../../RTL/cpu/alu74181.v(77)
  or \ALU_L4/u30  (\ALU_L4/n11 , \ALU_L4/n10 , \ALU_L4/SYNTHESIZED_WIRE_17 );  // ../../RTL/cpu/alu74181.v(109)
  not \ALU_L4/u31  (\ALU_L4/SYNTHESIZED_WIRE_10 , \ALU_L4/n11 );  // ../../RTL/cpu/alu74181.v(109)
  or \ALU_L4/u32  (\ALU_L4/n12 , \ALU_L4/SYNTHESIZED_WIRE_18 , \ALU_L4/SYNTHESIZED_WIRE_19 );  // ../../RTL/cpu/alu74181.v(111)
  not \ALU_L4/u33  (\ALU_L4/SYNTHESIZED_WIRE_7 , \ALU_L4/n12 );  // ../../RTL/cpu/alu74181.v(111)
  or \ALU_L4/u34  (\ALU_L4/n13 , \ALU_L4/SYNTHESIZED_WIRE_20 , \ALU_L4/SYNTHESIZED_WIRE_21 );  // ../../RTL/cpu/alu74181.v(113)
  not \ALU_L4/u35  (\ALU_L4/SYNTHESIZED_WIRE_9 , \ALU_L4/n13 );  // ../../RTL/cpu/alu74181.v(113)
  or \ALU_L4/u36  (\ALU_L4/n14 , \ALU_L4/SYNTHESIZED_WIRE_22 , \ALU_L4/SYNTHESIZED_WIRE_23 );  // ../../RTL/cpu/alu74181.v(115)
  not \ALU_L4/u37  (\ALU_L4/SYNTHESIZED_WIRE_11 , \ALU_L4/n14 );  // ../../RTL/cpu/alu74181.v(115)
  or \ALU_L4/u38  (\ALU_L4/n15 , A[3], \ALU_L4/SYNTHESIZED_WIRE_26 );  // ../../RTL/cpu/alu74181.v(117)
  or \ALU_L4/u39  (\ALU_L4/n16 , \ALU_L4/n15 , \ALU_L4/SYNTHESIZED_WIRE_27 );  // ../../RTL/cpu/alu74181.v(117)
  and \ALU_L4/u4  (\ALU_L4/SYNTHESIZED_WIRE_21 , \ALU_L4/n0 , A[1]);  // ../../RTL/cpu/alu74181.v(77)
  not \ALU_L4/u40  (\ALU_L4/SYNTHESIZED_WIRE_25 , \ALU_L4/n16 );  // ../../RTL/cpu/alu74181.v(117)
  or \ALU_L4/u41  (\ALU_L4/n17 , \ALU_L4/SYNTHESIZED_WIRE_28 , \ALU_L4/SYNTHESIZED_WIRE_29 );  // ../../RTL/cpu/alu74181.v(119)
  not \ALU_L4/u42  (\ALU_L4/SYNTHESIZED_WIRE_24 , \ALU_L4/n17 );  // ../../RTL/cpu/alu74181.v(119)
  xor \ALU_L4/u43  (\ALU_L4/SYNTHESIZED_WIRE_101 , \ALU_L4/SYNTHESIZED_WIRE_7 , \ALU_L4/SYNTHESIZED_WIRE_6 );  // ../../RTL/cpu/alu74181.v(121)
  xor \ALU_L4/u44  (\ALU_L4/SYNTHESIZED_WIRE_103 , \ALU_L4/SYNTHESIZED_WIRE_9 , \ALU_L4/SYNTHESIZED_WIRE_8 );  // ../../RTL/cpu/alu74181.v(123)
  xor \ALU_L4/u45  (\ALU_L4/SYNTHESIZED_WIRE_105 , \ALU_L4/SYNTHESIZED_WIRE_11 , \ALU_L4/SYNTHESIZED_WIRE_10 );  // ../../RTL/cpu/alu74181.v(125)
  xor \ALU_L4/u46  (\ALU_L4/SYNTHESIZED_WIRE_94 , \ALU_L4/SYNTHESIZED_WIRE_24 , \ALU_L4/SYNTHESIZED_WIRE_25 );  // ../../RTL/cpu/alu74181.v(127)
  and \ALU_L4/u5  (\ALU_L4/n1 , A[1], instr[7]);  // ../../RTL/cpu/alu74181.v(79)
  and \ALU_L4/u50  (\ALU_L4/SYNTHESIZED_WIRE_12 , instr[4], B[0]);  // ../../RTL/cpu/alu74181.v(133)
  and \ALU_L4/u55  (\ALU_L4/n22 , \ALU_L4/SYNTHESIZED_WIRE_11 , \ALU_L4/SYNTHESIZED_WIRE_9 );  // ../../RTL/cpu/alu74181.v(137)
  and \ALU_L4/u6  (\ALU_L4/SYNTHESIZED_WIRE_20 , \ALU_L4/n1 , B[1]);  // ../../RTL/cpu/alu74181.v(79)
  and \ALU_L4/u68  (\ALU_L4/SYNTHESIZED_WIRE_99 , \ALU_L4/SYNTHESIZED_WIRE_6 , \ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(145)
  and \ALU_L4/u69  (\ALU_L4/n31 , \ALU_H4/SYNTHESIZED_WIRE_128 , \ALU_L4/SYNTHESIZED_WIRE_7 );  // ../../RTL/cpu/alu74181.v(147)
  and \ALU_L4/u7  (\ALU_L4/SYNTHESIZED_WIRE_16 , instr[4], B[2]);  // ../../RTL/cpu/alu74181.v(81)
  and \ALU_L4/u70  (\ALU_L4/SYNTHESIZED_WIRE_98 , \ALU_L4/n31 , instr[2]);  // ../../RTL/cpu/alu74181.v(147)
  and \ALU_L4/u71  (\ALU_L4/SYNTHESIZED_WIRE_90 , \ALU_L4/SYNTHESIZED_WIRE_8 , \ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(149)
  and \ALU_L4/u72  (\ALU_L4/SYNTHESIZED_WIRE_91 , \ALU_L4/SYNTHESIZED_WIRE_99 , \ALU_L4/SYNTHESIZED_WIRE_9 );  // ../../RTL/cpu/alu74181.v(151)
  and \ALU_L4/u73  (\ALU_L4/n32 , instr[2], \ALU_L4/SYNTHESIZED_WIRE_7 );  // ../../RTL/cpu/alu74181.v(153)
  and \ALU_L4/u74  (\ALU_L4/n33 , \ALU_L4/n32 , \ALU_L4/SYNTHESIZED_WIRE_9 );  // ../../RTL/cpu/alu74181.v(153)
  and \ALU_L4/u75  (\ALU_L4/SYNTHESIZED_WIRE_92 , \ALU_L4/n33 , \ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(153)
  and \ALU_L4/u76  (\ALU_L4/SYNTHESIZED_WIRE_13 , \ALU_L4/SYNTHESIZED_WIRE_129 , instr[5]);  // ../../RTL/cpu/alu74181.v(155)
  and \ALU_L4/u77  (\ALU_L4/SYNTHESIZED_WIRE_89 , \ALU_L4/SYNTHESIZED_WIRE_10 , \ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(157)
  and \ALU_L4/u79  (\ALU_L4/SYNTHESIZED_WIRE_88 , \ALU_L4/SYNTHESIZED_WIRE_90 , \ALU_L4/SYNTHESIZED_WIRE_11 );  // ../../RTL/cpu/alu74181.v(159)
  and \ALU_L4/u8  (\ALU_L4/SYNTHESIZED_WIRE_17 , \ALU_L4/SYNTHESIZED_WIRE_118 , instr[5]);  // ../../RTL/cpu/alu74181.v(83)
  and \ALU_L4/u81  (\ALU_L4/n34 , \ALU_L4/n22 , \ALU_L4/SYNTHESIZED_WIRE_6 );  // ../../RTL/cpu/alu74181.v(161)
  and \ALU_L4/u82  (\ALU_L4/SYNTHESIZED_WIRE_87 , \ALU_L4/n34 , \ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(161)
  and \ALU_L4/u85  (\ALU_L4/n35 , \ALU_L4/n33 , instr[2]);  // ../../RTL/cpu/alu74181.v(163)
  and \ALU_L4/u86  (\ALU_L4/n36 , \ALU_L4/n35 , \ALU_L4/SYNTHESIZED_WIRE_11 );  // ../../RTL/cpu/alu74181.v(163)
  and \ALU_L4/u87  (\ALU_L4/SYNTHESIZED_WIRE_86 , \ALU_L4/n36 , \ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(163)
  or \ALU_L4/u88  (\ALU_L4/n37 , \ALU_L4/SYNTHESIZED_WIRE_86 , \ALU_L4/SYNTHESIZED_WIRE_87 );  // ../../RTL/cpu/alu74181.v(165)
  or \ALU_L4/u89  (\ALU_L4/n38 , \ALU_L4/n37 , \ALU_L4/SYNTHESIZED_WIRE_88 );  // ../../RTL/cpu/alu74181.v(165)
  and \ALU_L4/u9  (\ALU_L4/n2 , \ALU_L4/SYNTHESIZED_WIRE_118 , instr[6]);  // ../../RTL/cpu/alu74181.v(85)
  or \ALU_L4/u90  (\ALU_L4/n39 , \ALU_L4/n38 , \ALU_L4/SYNTHESIZED_WIRE_89 );  // ../../RTL/cpu/alu74181.v(165)
  not \ALU_L4/u91  (\ALU_L4/SYNTHESIZED_WIRE_93 , \ALU_L4/n39 );  // ../../RTL/cpu/alu74181.v(165)
  or \ALU_L4/u92  (\ALU_L4/n40 , \ALU_L4/SYNTHESIZED_WIRE_90 , \ALU_L4/SYNTHESIZED_WIRE_91 );  // ../../RTL/cpu/alu74181.v(167)
  or \ALU_L4/u93  (\ALU_L4/n41 , \ALU_L4/n40 , \ALU_L4/SYNTHESIZED_WIRE_92 );  // ../../RTL/cpu/alu74181.v(167)
  not \ALU_L4/u94  (\ALU_L4/SYNTHESIZED_WIRE_116 , \ALU_L4/n41 );  // ../../RTL/cpu/alu74181.v(167)
  xor \ALU_L4/u95  (ALU_out[3], \ALU_L4/SYNTHESIZED_WIRE_94 , \ALU_L4/SYNTHESIZED_WIRE_93 );  // ../../RTL/cpu/alu74181.v(169)
  or \ALU_L4/u98  (\ALU_L4/n43 , \ALU_L4/SYNTHESIZED_WIRE_98 , \ALU_L4/SYNTHESIZED_WIRE_99 );  // ../../RTL/cpu/alu74181.v(173)
  not \ALU_L4/u99  (\ALU_L4/SYNTHESIZED_WIRE_115 , \ALU_L4/n43 );  // ../../RTL/cpu/alu74181.v(173)
  add_pu24_pu24_o24 add0 (
    .i0(iaddr),
    .i1(24'b000000000000000000000001),
    .o(n9));  // ../../RTL/cpu/KC_LS1u.v(32)
  reg_ar_as_w1 dwrite_reg (
    .clk(clk),
    .d(n21),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .q(dwrite));  // ../../RTL/cpu/KC_LS1u.v(72)
  eq_w3 eq0 (
    .i0(instr[10:8]),
    .i1(3'b111),
    .o(n12));  // ../../RTL/cpu/KC_LS1u.v(46)
  eq_w5 eq1 (
    .i0(funct5),
    .i1(5'b00001),
    .o(jmp_en));  // ../../RTL/cpu/KC_LS1u.v(93)
  eq_w5 eq10 (
    .i0(funct5),
    .i1(5'b10100),
    .o(n39));  // ../../RTL/cpu/KC_LS1u.v(111)
  eq_w5 eq11 (
    .i0(funct5),
    .i1(5'b10110),
    .o(n40));  // ../../RTL/cpu/KC_LS1u.v(113)
  eq_w5 eq12 (
    .i0(funct5),
    .i1(5'b11000),
    .o(n41));  // ../../RTL/cpu/KC_LS1u.v(115)
  eq_w5 eq13 (
    .i0(funct5),
    .i1(5'b11010),
    .o(n42));  // ../../RTL/cpu/KC_LS1u.v(117)
  eq_w5 eq14 (
    .i0(funct5),
    .i1(5'b11100),
    .o(n43));  // ../../RTL/cpu/KC_LS1u.v(119)
  eq_w5 eq2 (
    .i0(funct5),
    .i1(5'b00010),
    .o(n31));  // ../../RTL/cpu/KC_LS1u.v(95)
  eq_w5 eq3 (
    .i0(funct5),
    .i1(5'b00100),
    .o(n32));  // ../../RTL/cpu/KC_LS1u.v(97)
  eq_w5 eq4 (
    .i0(funct5),
    .i1(5'b00101),
    .o(n33));  // ../../RTL/cpu/KC_LS1u.v(99)
  eq_w5 eq5 (
    .i0(funct5),
    .i1(5'b00110),
    .o(n34));  // ../../RTL/cpu/KC_LS1u.v(101)
  eq_w5 eq6 (
    .i0(funct5),
    .i1(5'b00111),
    .o(n35));  // ../../RTL/cpu/KC_LS1u.v(103)
  eq_w5 eq7 (
    .i0(funct5),
    .i1(5'b01101),
    .o(n36));  // ../../RTL/cpu/KC_LS1u.v(105)
  eq_w5 eq8 (
    .i0(funct5),
    .i1(5'b10000),
    .o(n37));  // ../../RTL/cpu/KC_LS1u.v(107)
  eq_w5 eq9 (
    .i0(funct5),
    .i1(5'b10010),
    .o(n38));  // ../../RTL/cpu/KC_LS1u.v(109)
  not \instr[10]_inv  (\instr[10]_neg , instr[10]);
  not \instr[8]_inv  (\instr[8]_neg , instr[8]);
  not \instr[9]_inv  (\instr[9]_neg , instr[9]);
  ELF_LOGIC_GSRN #(
    .USR_GSRN("ENABLE"))
    logic_gsrn (
    .gsrn(rst_neg),
    .sync_clk(1'b0));
  binary_mux_s1_w1 mux0_b0 (
    .i0(n9[0]),
    .i1(daddr[0]),
    .sel(jmp),
    .o(n10[0]));  // ../../RTL/cpu/KC_LS1u.v(33)
  binary_mux_s1_w1 mux0_b1 (
    .i0(n9[1]),
    .i1(daddr[1]),
    .sel(jmp),
    .o(n10[1]));  // ../../RTL/cpu/KC_LS1u.v(33)
  binary_mux_s1_w1 mux0_b10 (
    .i0(n9[10]),
    .i1(daddr[10]),
    .sel(jmp),
    .o(n10[10]));  // ../../RTL/cpu/KC_LS1u.v(33)
  binary_mux_s1_w1 mux0_b11 (
    .i0(n9[11]),
    .i1(daddr[11]),
    .sel(jmp),
    .o(n10[11]));  // ../../RTL/cpu/KC_LS1u.v(33)
  binary_mux_s1_w1 mux0_b12 (
    .i0(n9[12]),
    .i1(daddr[12]),
    .sel(jmp),
    .o(n10[12]));  // ../../RTL/cpu/KC_LS1u.v(33)
  binary_mux_s1_w1 mux0_b13 (
    .i0(n9[13]),
    .i1(daddr[13]),
    .sel(jmp),
    .o(n10[13]));  // ../../RTL/cpu/KC_LS1u.v(33)
  binary_mux_s1_w1 mux0_b14 (
    .i0(n9[14]),
    .i1(daddr[14]),
    .sel(jmp),
    .o(n10[14]));  // ../../RTL/cpu/KC_LS1u.v(33)
  binary_mux_s1_w1 mux0_b15 (
    .i0(n9[15]),
    .i1(daddr[15]),
    .sel(jmp),
    .o(n10[15]));  // ../../RTL/cpu/KC_LS1u.v(33)
  binary_mux_s1_w1 mux0_b16 (
    .i0(n9[16]),
    .i1(daddr[16]),
    .sel(jmp),
    .o(n10[16]));  // ../../RTL/cpu/KC_LS1u.v(33)
  binary_mux_s1_w1 mux0_b17 (
    .i0(n9[17]),
    .i1(daddr[17]),
    .sel(jmp),
    .o(n10[17]));  // ../../RTL/cpu/KC_LS1u.v(33)
  binary_mux_s1_w1 mux0_b18 (
    .i0(n9[18]),
    .i1(daddr[18]),
    .sel(jmp),
    .o(n10[18]));  // ../../RTL/cpu/KC_LS1u.v(33)
  binary_mux_s1_w1 mux0_b19 (
    .i0(n9[19]),
    .i1(daddr[19]),
    .sel(jmp),
    .o(n10[19]));  // ../../RTL/cpu/KC_LS1u.v(33)
  binary_mux_s1_w1 mux0_b2 (
    .i0(n9[2]),
    .i1(daddr[2]),
    .sel(jmp),
    .o(n10[2]));  // ../../RTL/cpu/KC_LS1u.v(33)
  binary_mux_s1_w1 mux0_b20 (
    .i0(n9[20]),
    .i1(daddr[20]),
    .sel(jmp),
    .o(n10[20]));  // ../../RTL/cpu/KC_LS1u.v(33)
  binary_mux_s1_w1 mux0_b21 (
    .i0(n9[21]),
    .i1(daddr[21]),
    .sel(jmp),
    .o(n10[21]));  // ../../RTL/cpu/KC_LS1u.v(33)
  binary_mux_s1_w1 mux0_b22 (
    .i0(n9[22]),
    .i1(daddr[22]),
    .sel(jmp),
    .o(n10[22]));  // ../../RTL/cpu/KC_LS1u.v(33)
  binary_mux_s1_w1 mux0_b23 (
    .i0(n9[23]),
    .i1(daddr[23]),
    .sel(jmp),
    .o(n10[23]));  // ../../RTL/cpu/KC_LS1u.v(33)
  binary_mux_s1_w1 mux0_b3 (
    .i0(n9[3]),
    .i1(daddr[3]),
    .sel(jmp),
    .o(n10[3]));  // ../../RTL/cpu/KC_LS1u.v(33)
  binary_mux_s1_w1 mux0_b4 (
    .i0(n9[4]),
    .i1(daddr[4]),
    .sel(jmp),
    .o(n10[4]));  // ../../RTL/cpu/KC_LS1u.v(33)
  binary_mux_s1_w1 mux0_b5 (
    .i0(n9[5]),
    .i1(daddr[5]),
    .sel(jmp),
    .o(n10[5]));  // ../../RTL/cpu/KC_LS1u.v(33)
  binary_mux_s1_w1 mux0_b6 (
    .i0(n9[6]),
    .i1(daddr[6]),
    .sel(jmp),
    .o(n10[6]));  // ../../RTL/cpu/KC_LS1u.v(33)
  binary_mux_s1_w1 mux0_b7 (
    .i0(n9[7]),
    .i1(daddr[7]),
    .sel(jmp),
    .o(n10[7]));  // ../../RTL/cpu/KC_LS1u.v(33)
  binary_mux_s1_w1 mux0_b8 (
    .i0(n9[8]),
    .i1(daddr[8]),
    .sel(jmp),
    .o(n10[8]));  // ../../RTL/cpu/KC_LS1u.v(33)
  binary_mux_s1_w1 mux0_b9 (
    .i0(n9[9]),
    .i1(daddr[9]),
    .sel(jmp),
    .o(n10[9]));  // ../../RTL/cpu/KC_LS1u.v(33)
  and mux10_b0_sel_is_3 (mux10_b0_sel_is_3_o, regwrite, mux2_b0_sel_is_7_o);
  and mux11_b0_sel_is_3 (mux11_b0_sel_is_3_o, regwrite, mux3_b0_sel_is_6_o);
  and mux12_b0_sel_is_3 (mux12_b0_sel_is_3_o, regwrite, mux4_b0_sel_is_5_o);
  and mux13_b0_sel_is_3 (mux13_b0_sel_is_3_o, regwrite, mux5_b0_sel_is_4_o);
  and mux14_b0_sel_is_3 (mux14_b0_sel_is_3_o, regwrite, mux6_b0_sel_is_3_o);
  and mux15_b0_sel_is_3 (mux15_b0_sel_is_3_o, regwrite, mux7_b0_sel_is_2_o);
  and mux16_b0_sel_is_3 (mux16_b0_sel_is_3_o, regwrite, mux8_b0_sel_is_1_o);
  and mux17_b0_sel_is_3 (mux17_b0_sel_is_3_o, regwrite, mux9_b0_sel_is_0_o);
  binary_mux_s3_w1 mux18 (
    .i0(1'b0),
    .i1(n51),
    .i2(\ALU_H4/SYNTHESIZED_WIRE_119 ),
    .i3(n53),
    .i4(\ALU_H4/n42 ),
    .i5(1'b1),
    .i6(1'b0),
    .i7(1'b0),
    .sel(instr[10:8]),
    .o(n55));  // ../../RTL/cpu/KC_LS1u.v(173)
  binary_mux_s4_w1 mux19_b0 (
    .i0(C[0]),
    .i1(ALU_out[0]),
    .i10(A[1]),
    .i11(1'b0),
    .i12(B[1]),
    .i13(B[1]),
    .i14(B[1]),
    .i15(1'b0),
    .i2(ddata_i[0]),
    .i3(instr[0]),
    .i4(D[0]),
    .i5(1'b0),
    .i6(1'b0),
    .i7(1'b0),
    .i8(B[7]),
    .i9(A[1]),
    .sel(dbsrc_addr),
    .o(DB8w[0]));  // ../../RTL/cpu/KC_LS1u.v(193)
  binary_mux_s4_w1 mux19_b1 (
    .i0(C[1]),
    .i1(ALU_out[1]),
    .i10(A[2]),
    .i11(B[0]),
    .i12(B[2]),
    .i13(B[2]),
    .i14(B[2]),
    .i15(1'b0),
    .i2(ddata_i[1]),
    .i3(instr[1]),
    .i4(D[1]),
    .i5(1'b0),
    .i6(1'b0),
    .i7(A[0]),
    .i8(A[0]),
    .i9(A[2]),
    .sel(dbsrc_addr),
    .o(DB8w[1]));  // ../../RTL/cpu/KC_LS1u.v(193)
  binary_mux_s4_w1 mux19_b2 (
    .i0(C[2]),
    .i1(ALU_out[2]),
    .i10(A[3]),
    .i11(B[1]),
    .i12(B[3]),
    .i13(B[3]),
    .i14(B[3]),
    .i15(1'b0),
    .i2(ddata_i[2]),
    .i3(instr[2]),
    .i4(D[2]),
    .i5(1'b0),
    .i6(1'b0),
    .i7(A[1]),
    .i8(A[1]),
    .i9(A[3]),
    .sel(dbsrc_addr),
    .o(DB8w[2]));  // ../../RTL/cpu/KC_LS1u.v(193)
  binary_mux_s4_w1 mux19_b3 (
    .i0(C[3]),
    .i1(ALU_out[3]),
    .i10(A[4]),
    .i11(B[2]),
    .i12(B[4]),
    .i13(B[4]),
    .i14(B[4]),
    .i15(1'b0),
    .i2(ddata_i[3]),
    .i3(instr[3]),
    .i4(D[3]),
    .i5(1'b0),
    .i6(1'b0),
    .i7(A[2]),
    .i8(A[2]),
    .i9(A[4]),
    .sel(dbsrc_addr),
    .o(DB8w[3]));  // ../../RTL/cpu/KC_LS1u.v(193)
  binary_mux_s4_w1 mux19_b4 (
    .i0(C[4]),
    .i1(ALU_out[4]),
    .i10(A[5]),
    .i11(B[3]),
    .i12(B[5]),
    .i13(B[5]),
    .i14(B[5]),
    .i15(1'b0),
    .i2(ddata_i[4]),
    .i3(instr[4]),
    .i4(D[4]),
    .i5(1'b0),
    .i6(1'b0),
    .i7(A[3]),
    .i8(A[3]),
    .i9(A[5]),
    .sel(dbsrc_addr),
    .o(DB8w[4]));  // ../../RTL/cpu/KC_LS1u.v(193)
  binary_mux_s4_w1 mux19_b5 (
    .i0(C[5]),
    .i1(ALU_out[5]),
    .i10(A[6]),
    .i11(B[4]),
    .i12(B[6]),
    .i13(B[6]),
    .i14(B[6]),
    .i15(1'b0),
    .i2(ddata_i[5]),
    .i3(instr[5]),
    .i4(D[5]),
    .i5(1'b0),
    .i6(1'b0),
    .i7(A[4]),
    .i8(A[4]),
    .i9(A[6]),
    .sel(dbsrc_addr),
    .o(DB8w[5]));  // ../../RTL/cpu/KC_LS1u.v(193)
  binary_mux_s4_w1 mux19_b6 (
    .i0(C[6]),
    .i1(ALU_out[6]),
    .i10(A[7]),
    .i11(B[5]),
    .i12(B[7]),
    .i13(B[7]),
    .i14(B[7]),
    .i15(1'b0),
    .i2(ddata_i[6]),
    .i3(instr[6]),
    .i4(D[6]),
    .i5(1'b0),
    .i6(1'b0),
    .i7(A[5]),
    .i8(A[5]),
    .i9(A[7]),
    .sel(dbsrc_addr),
    .o(DB8w[6]));  // ../../RTL/cpu/KC_LS1u.v(193)
  binary_mux_s4_w1 mux19_b7 (
    .i0(C[7]),
    .i1(ALU_out[7]),
    .i10(A[7]),
    .i11(B[6]),
    .i12(1'b0),
    .i13(B[7]),
    .i14(A[0]),
    .i15(1'b0),
    .i2(ddata_i[7]),
    .i3(instr[7]),
    .i4(D[7]),
    .i5(1'b0),
    .i6(1'b0),
    .i7(A[6]),
    .i8(A[6]),
    .i9(1'b0),
    .sel(dbsrc_addr),
    .o(DB8w[7]));  // ../../RTL/cpu/KC_LS1u.v(193)
  and mux2_b0_sel_is_7 (mux2_b0_sel_is_7_o, instr[8], instr[9], instr[10]);
  and mux3_b0_sel_is_6 (mux3_b0_sel_is_6_o, \instr[8]_neg , instr[9], instr[10]);
  and mux4_b0_sel_is_5 (mux4_b0_sel_is_5_o, instr[8], \instr[9]_neg , instr[10]);
  and mux5_b0_sel_is_4 (mux5_b0_sel_is_4_o, \instr[8]_neg , \instr[9]_neg , instr[10]);
  and mux6_b0_sel_is_3 (mux6_b0_sel_is_3_o, instr[8], instr[9], \instr[10]_neg );
  and mux7_b0_sel_is_2 (mux7_b0_sel_is_2_o, \instr[8]_neg , instr[9], \instr[10]_neg );
  and mux8_b0_sel_is_1 (mux8_b0_sel_is_1_o, instr[8], \instr[9]_neg , \instr[10]_neg );
  and mux9_b0_sel_is_0 (mux9_b0_sel_is_0_o, \instr[8]_neg , \instr[9]_neg , \instr[10]_neg );
  reg_ar_as_w1 reg0_b0 (
    .clk(clk),
    .d(DB8w[0]),
    .en(mux10_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(ddata_o[0]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg0_b1 (
    .clk(clk),
    .d(DB8w[1]),
    .en(mux10_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(ddata_o[1]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg0_b2 (
    .clk(clk),
    .d(DB8w[2]),
    .en(mux10_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(ddata_o[2]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg0_b3 (
    .clk(clk),
    .d(DB8w[3]),
    .en(mux10_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(ddata_o[3]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg0_b4 (
    .clk(clk),
    .d(DB8w[4]),
    .en(mux10_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(ddata_o[4]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg0_b5 (
    .clk(clk),
    .d(DB8w[5]),
    .en(mux10_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(ddata_o[5]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg0_b6 (
    .clk(clk),
    .d(DB8w[6]),
    .en(mux10_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(ddata_o[6]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg0_b7 (
    .clk(clk),
    .d(DB8w[7]),
    .en(mux10_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(ddata_o[7]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg1_b0 (
    .clk(clk),
    .d(DB8w[0]),
    .en(mux11_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(D[0]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg1_b1 (
    .clk(clk),
    .d(DB8w[1]),
    .en(mux11_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(D[1]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg1_b2 (
    .clk(clk),
    .d(DB8w[2]),
    .en(mux11_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(D[2]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg1_b3 (
    .clk(clk),
    .d(DB8w[3]),
    .en(mux11_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(D[3]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg1_b4 (
    .clk(clk),
    .d(DB8w[4]),
    .en(mux11_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(D[4]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg1_b5 (
    .clk(clk),
    .d(DB8w[5]),
    .en(mux11_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(D[5]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg1_b6 (
    .clk(clk),
    .d(DB8w[6]),
    .en(mux11_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(D[6]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg1_b7 (
    .clk(clk),
    .d(DB8w[7]),
    .en(mux11_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(D[7]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg2_b0 (
    .clk(clk),
    .d(DB8w[0]),
    .en(mux12_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(daddr[16]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg2_b1 (
    .clk(clk),
    .d(DB8w[1]),
    .en(mux12_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(daddr[17]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg2_b2 (
    .clk(clk),
    .d(DB8w[2]),
    .en(mux12_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(daddr[18]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg2_b3 (
    .clk(clk),
    .d(DB8w[3]),
    .en(mux12_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(daddr[19]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg2_b4 (
    .clk(clk),
    .d(DB8w[4]),
    .en(mux12_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(daddr[20]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg2_b5 (
    .clk(clk),
    .d(DB8w[5]),
    .en(mux12_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(daddr[21]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg2_b6 (
    .clk(clk),
    .d(DB8w[6]),
    .en(mux12_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(daddr[22]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg2_b7 (
    .clk(clk),
    .d(DB8w[7]),
    .en(mux12_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(daddr[23]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg3_b0 (
    .clk(clk),
    .d(DB8w[0]),
    .en(mux13_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(daddr[8]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg3_b1 (
    .clk(clk),
    .d(DB8w[1]),
    .en(mux13_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(daddr[9]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg3_b2 (
    .clk(clk),
    .d(DB8w[2]),
    .en(mux13_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(daddr[10]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg3_b3 (
    .clk(clk),
    .d(DB8w[3]),
    .en(mux13_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(daddr[11]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg3_b4 (
    .clk(clk),
    .d(DB8w[4]),
    .en(mux13_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(daddr[12]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg3_b5 (
    .clk(clk),
    .d(DB8w[5]),
    .en(mux13_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(daddr[13]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg3_b6 (
    .clk(clk),
    .d(DB8w[6]),
    .en(mux13_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(daddr[14]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg3_b7 (
    .clk(clk),
    .d(DB8w[7]),
    .en(mux13_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(daddr[15]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg4_b0 (
    .clk(clk),
    .d(DB8w[0]),
    .en(mux14_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(daddr[0]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg4_b1 (
    .clk(clk),
    .d(DB8w[1]),
    .en(mux14_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(daddr[1]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg4_b2 (
    .clk(clk),
    .d(DB8w[2]),
    .en(mux14_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(daddr[2]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg4_b3 (
    .clk(clk),
    .d(DB8w[3]),
    .en(mux14_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(daddr[3]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg4_b4 (
    .clk(clk),
    .d(DB8w[4]),
    .en(mux14_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(daddr[4]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg4_b5 (
    .clk(clk),
    .d(DB8w[5]),
    .en(mux14_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(daddr[5]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg4_b6 (
    .clk(clk),
    .d(DB8w[6]),
    .en(mux14_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(daddr[6]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg4_b7 (
    .clk(clk),
    .d(DB8w[7]),
    .en(mux14_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(daddr[7]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg5_b0 (
    .clk(clk),
    .d(DB8w[0]),
    .en(mux15_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(B[0]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg5_b1 (
    .clk(clk),
    .d(DB8w[1]),
    .en(mux15_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(B[1]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg5_b2 (
    .clk(clk),
    .d(DB8w[2]),
    .en(mux15_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(B[2]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg5_b3 (
    .clk(clk),
    .d(DB8w[3]),
    .en(mux15_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(B[3]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg5_b4 (
    .clk(clk),
    .d(DB8w[4]),
    .en(mux15_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(B[4]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg5_b5 (
    .clk(clk),
    .d(DB8w[5]),
    .en(mux15_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(B[5]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg5_b6 (
    .clk(clk),
    .d(DB8w[6]),
    .en(mux15_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(B[6]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg5_b7 (
    .clk(clk),
    .d(DB8w[7]),
    .en(mux15_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(B[7]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg6_b0 (
    .clk(clk),
    .d(DB8w[0]),
    .en(mux16_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(A[0]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg6_b1 (
    .clk(clk),
    .d(DB8w[1]),
    .en(mux16_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(A[1]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg6_b2 (
    .clk(clk),
    .d(DB8w[2]),
    .en(mux16_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(A[2]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg6_b3 (
    .clk(clk),
    .d(DB8w[3]),
    .en(mux16_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(A[3]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg6_b4 (
    .clk(clk),
    .d(DB8w[4]),
    .en(mux16_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(A[4]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg6_b5 (
    .clk(clk),
    .d(DB8w[5]),
    .en(mux16_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(A[5]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg6_b6 (
    .clk(clk),
    .d(DB8w[6]),
    .en(mux16_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(A[6]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg6_b7 (
    .clk(clk),
    .d(DB8w[7]),
    .en(mux16_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(A[7]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg7_b0 (
    .clk(clk),
    .d(DB8w[0]),
    .en(mux17_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(C[0]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg7_b1 (
    .clk(clk),
    .d(DB8w[1]),
    .en(mux17_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(C[1]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg7_b2 (
    .clk(clk),
    .d(DB8w[2]),
    .en(mux17_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(C[2]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg7_b3 (
    .clk(clk),
    .d(DB8w[3]),
    .en(mux17_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(C[3]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg7_b4 (
    .clk(clk),
    .d(DB8w[4]),
    .en(mux17_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(C[4]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg7_b5 (
    .clk(clk),
    .d(DB8w[5]),
    .en(mux17_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(C[5]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg7_b6 (
    .clk(clk),
    .d(DB8w[6]),
    .en(mux17_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(C[6]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 reg7_b7 (
    .clk(clk),
    .d(DB8w[7]),
    .en(mux17_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(C[7]));  // ../../RTL/cpu/KC_LS1u.v(72)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg8_b0 (
    .clk(clk),
    .d(n10[0]),
    .en(~WAIT),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[0]));  // ../../RTL/cpu/KC_LS1u.v(34)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg8_b1 (
    .clk(clk),
    .d(n10[1]),
    .en(~WAIT),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[1]));  // ../../RTL/cpu/KC_LS1u.v(34)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg8_b10 (
    .clk(clk),
    .d(n10[10]),
    .en(~WAIT),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[10]));  // ../../RTL/cpu/KC_LS1u.v(34)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg8_b11 (
    .clk(clk),
    .d(n10[11]),
    .en(~WAIT),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[11]));  // ../../RTL/cpu/KC_LS1u.v(34)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg8_b12 (
    .clk(clk),
    .d(n10[12]),
    .en(~WAIT),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[12]));  // ../../RTL/cpu/KC_LS1u.v(34)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg8_b13 (
    .clk(clk),
    .d(n10[13]),
    .en(~WAIT),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[13]));  // ../../RTL/cpu/KC_LS1u.v(34)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg8_b14 (
    .clk(clk),
    .d(n10[14]),
    .en(~WAIT),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[14]));  // ../../RTL/cpu/KC_LS1u.v(34)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg8_b15 (
    .clk(clk),
    .d(n10[15]),
    .en(~WAIT),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[15]));  // ../../RTL/cpu/KC_LS1u.v(34)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg8_b16 (
    .clk(clk),
    .d(n10[16]),
    .en(~WAIT),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[16]));  // ../../RTL/cpu/KC_LS1u.v(34)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg8_b17 (
    .clk(clk),
    .d(n10[17]),
    .en(~WAIT),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[17]));  // ../../RTL/cpu/KC_LS1u.v(34)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg8_b18 (
    .clk(clk),
    .d(n10[18]),
    .en(~WAIT),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[18]));  // ../../RTL/cpu/KC_LS1u.v(34)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg8_b19 (
    .clk(clk),
    .d(n10[19]),
    .en(~WAIT),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[19]));  // ../../RTL/cpu/KC_LS1u.v(34)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg8_b2 (
    .clk(clk),
    .d(n10[2]),
    .en(~WAIT),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[2]));  // ../../RTL/cpu/KC_LS1u.v(34)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg8_b20 (
    .clk(clk),
    .d(n10[20]),
    .en(~WAIT),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[20]));  // ../../RTL/cpu/KC_LS1u.v(34)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg8_b21 (
    .clk(clk),
    .d(n10[21]),
    .en(~WAIT),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[21]));  // ../../RTL/cpu/KC_LS1u.v(34)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg8_b22 (
    .clk(clk),
    .d(n10[22]),
    .en(~WAIT),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[22]));  // ../../RTL/cpu/KC_LS1u.v(34)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg8_b23 (
    .clk(clk),
    .d(n10[23]),
    .en(~WAIT),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[23]));  // ../../RTL/cpu/KC_LS1u.v(34)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg8_b3 (
    .clk(clk),
    .d(n10[3]),
    .en(~WAIT),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[3]));  // ../../RTL/cpu/KC_LS1u.v(34)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg8_b4 (
    .clk(clk),
    .d(n10[4]),
    .en(~WAIT),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[4]));  // ../../RTL/cpu/KC_LS1u.v(34)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg8_b5 (
    .clk(clk),
    .d(n10[5]),
    .en(~WAIT),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[5]));  // ../../RTL/cpu/KC_LS1u.v(34)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg8_b6 (
    .clk(clk),
    .d(n10[6]),
    .en(~WAIT),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[6]));  // ../../RTL/cpu/KC_LS1u.v(34)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg8_b7 (
    .clk(clk),
    .d(n10[7]),
    .en(~WAIT),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[7]));  // ../../RTL/cpu/KC_LS1u.v(34)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg8_b8 (
    .clk(clk),
    .d(n10[8]),
    .en(~WAIT),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[8]));  // ../../RTL/cpu/KC_LS1u.v(34)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg8_b9 (
    .clk(clk),
    .d(n10[9]),
    .en(~WAIT),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[9]));  // ../../RTL/cpu/KC_LS1u.v(34)
  not rst_inv (rst_neg, rst);
  AL_MUX sel0_b0 (
    .i0(1'b0),
    .i1(1'b1),
    .sel(sel0_b0_sel_o),
    .o(dbsrc_addr[0]));  // ../../RTL/cpu/KC_LS1u.v(121)
  or sel0_b0_sel (sel0_b0_sel_o, n42, n40, n38, n36, n34, n31);  // ../../RTL/cpu/KC_LS1u.v(121)
  AL_MUX sel0_b1 (
    .i0(1'b0),
    .i1(1'b1),
    .sel(sel0_b1_sel_o),
    .o(dbsrc_addr[1]));  // ../../RTL/cpu/KC_LS1u.v(121)
  or sel0_b1_sel (sel0_b1_sel_o, n43, n40, n39, n36, n34, n32);  // ../../RTL/cpu/KC_LS1u.v(121)
  AL_MUX sel0_b2 (
    .i0(1'b0),
    .i1(1'b1),
    .sel(sel0_b2_sel_o),
    .o(dbsrc_addr[2]));  // ../../RTL/cpu/KC_LS1u.v(121)
  or sel0_b2_sel (sel0_b2_sel_o, n43, n42, n41, n36, n35);  // ../../RTL/cpu/KC_LS1u.v(121)
  AL_MUX sel0_b3 (
    .i0(1'b0),
    .i1(1'b1),
    .sel(sel0_b3_sel_o),
    .o(dbsrc_addr[3]));  // ../../RTL/cpu/KC_LS1u.v(121)
  or sel0_b3_sel (sel0_b3_sel_o, n43, n42, n41, n40, n39, n38, n37);  // ../../RTL/cpu/KC_LS1u.v(121)
  and u10 (funct5[0], n30, instr[11]);  // ../../RTL/cpu/KC_LS1u.v(86)
  or u100 (n7, n48, n8);  // ../../RTL/cpu/KC_LS1u.v(121)
  or u101 (n6, n35, n34);  // ../../RTL/cpu/KC_LS1u.v(121)
  or u102 (n5, n36, n6);  // ../../RTL/cpu/KC_LS1u.v(121)
  or u103 (n4, n33, n32);  // ../../RTL/cpu/KC_LS1u.v(121)
  or u104 (n3, n31, jmp_en);  // ../../RTL/cpu/KC_LS1u.v(121)
  or u105 (n2, n4, n3);  // ../../RTL/cpu/KC_LS1u.v(121)
  or u106 (n1, n5, n2);  // ../../RTL/cpu/KC_LS1u.v(121)
  or u107 (n0, n7, n1);  // ../../RTL/cpu/KC_LS1u.v(121)
  not u108 (n44, n0);  // ../../RTL/cpu/KC_LS1u.v(121)
  and u109 (funct5[1], n30, instr[12]);  // ../../RTL/cpu/KC_LS1u.v(86)
  or u11 (n45, jmp_en, n44);  // ../../RTL/cpu/KC_LS1u.v(121)
  and u110 (funct5[2], n30, instr[13]);  // ../../RTL/cpu/KC_LS1u.v(86)
  and u111 (funct5[3], n30, instr[14]);  // ../../RTL/cpu/KC_LS1u.v(86)
  and u112 (funct5[4], n30, instr[15]);  // ../../RTL/cpu/KC_LS1u.v(86)
  not u13 (regwrite, n45);  // ../../RTL/cpu/KC_LS1u.v(121)
  or u14 (n49, n42, n41);  // ../../RTL/cpu/KC_LS1u.v(121)
  and u18 (ALU_eqo, ALU_eq[0], ALU_eq[1]);  // ../../RTL/cpu/KC_LS1u.v(133)
  not u20 (n51, A[7]);  // ../../RTL/cpu/KC_LS1u.v(167)
  not u22 (n53, ALU_eqo);  // ../../RTL/cpu/KC_LS1u.v(169)
  AL_MUX u24 (
    .i0(1'b0),
    .i1(n55),
    .sel(jmp_en),
    .o(jmp));  // ../../RTL/cpu/KC_LS1u.v(174)
  AL_MUX u4 (
    .i0(1'b0),
    .i1(n12),
    .sel(regwrite),
    .o(n21));  // ../../RTL/cpu/KC_LS1u.v(71)
  not u8 (n30, WAIT);  // ../../RTL/cpu/KC_LS1u.v(86)
  or u96 (n48, n43, n49);  // ../../RTL/cpu/KC_LS1u.v(121)
  or u97 (n47, n40, n39);  // ../../RTL/cpu/KC_LS1u.v(121)
  or u98 (n46, n38, n37);  // ../../RTL/cpu/KC_LS1u.v(121)
  or u99 (n8, n47, n46);  // ../../RTL/cpu/KC_LS1u.v(121)

endmodule 

module add_pu24_pu24_o24
  (
  i0,
  i1,
  o
  );

  input [23:0] i0;
  input [23:0] i1;
  output [23:0] o;

  wire net_a0;
  wire net_a1;
  wire net_a10;
  wire net_a11;
  wire net_a12;
  wire net_a13;
  wire net_a14;
  wire net_a15;
  wire net_a16;
  wire net_a17;
  wire net_a18;
  wire net_a19;
  wire net_a2;
  wire net_a20;
  wire net_a21;
  wire net_a22;
  wire net_a23;
  wire net_a3;
  wire net_a4;
  wire net_a5;
  wire net_a6;
  wire net_a7;
  wire net_a8;
  wire net_a9;
  wire net_b0;
  wire net_b1;
  wire net_b10;
  wire net_b11;
  wire net_b12;
  wire net_b13;
  wire net_b14;
  wire net_b15;
  wire net_b16;
  wire net_b17;
  wire net_b18;
  wire net_b19;
  wire net_b2;
  wire net_b20;
  wire net_b21;
  wire net_b22;
  wire net_b23;
  wire net_b3;
  wire net_b4;
  wire net_b5;
  wire net_b6;
  wire net_b7;
  wire net_b8;
  wire net_b9;
  wire net_cout0;
  wire net_cout1;
  wire net_cout10;
  wire net_cout11;
  wire net_cout12;
  wire net_cout13;
  wire net_cout14;
  wire net_cout15;
  wire net_cout16;
  wire net_cout17;
  wire net_cout18;
  wire net_cout19;
  wire net_cout2;
  wire net_cout20;
  wire net_cout21;
  wire net_cout22;
  wire net_cout23;
  wire net_cout3;
  wire net_cout4;
  wire net_cout5;
  wire net_cout6;
  wire net_cout7;
  wire net_cout8;
  wire net_cout9;
  wire net_sum0;
  wire net_sum1;
  wire net_sum10;
  wire net_sum11;
  wire net_sum12;
  wire net_sum13;
  wire net_sum14;
  wire net_sum15;
  wire net_sum16;
  wire net_sum17;
  wire net_sum18;
  wire net_sum19;
  wire net_sum2;
  wire net_sum20;
  wire net_sum21;
  wire net_sum22;
  wire net_sum23;
  wire net_sum3;
  wire net_sum4;
  wire net_sum5;
  wire net_sum6;
  wire net_sum7;
  wire net_sum8;
  wire net_sum9;

  assign net_a23 = i0[23];
  assign net_a22 = i0[22];
  assign net_a21 = i0[21];
  assign net_a20 = i0[20];
  assign net_a19 = i0[19];
  assign net_a18 = i0[18];
  assign net_a17 = i0[17];
  assign net_a16 = i0[16];
  assign net_a15 = i0[15];
  assign net_a14 = i0[14];
  assign net_a13 = i0[13];
  assign net_a12 = i0[12];
  assign net_a11 = i0[11];
  assign net_a10 = i0[10];
  assign net_a9 = i0[9];
  assign net_a8 = i0[8];
  assign net_a7 = i0[7];
  assign net_a6 = i0[6];
  assign net_a5 = i0[5];
  assign net_a4 = i0[4];
  assign net_a3 = i0[3];
  assign net_a2 = i0[2];
  assign net_a1 = i0[1];
  assign net_a0 = i0[0];
  assign net_b23 = i1[23];
  assign net_b22 = i1[22];
  assign net_b21 = i1[21];
  assign net_b20 = i1[20];
  assign net_b19 = i1[19];
  assign net_b18 = i1[18];
  assign net_b17 = i1[17];
  assign net_b16 = i1[16];
  assign net_b15 = i1[15];
  assign net_b14 = i1[14];
  assign net_b13 = i1[13];
  assign net_b12 = i1[12];
  assign net_b11 = i1[11];
  assign net_b10 = i1[10];
  assign net_b9 = i1[9];
  assign net_b8 = i1[8];
  assign net_b7 = i1[7];
  assign net_b6 = i1[6];
  assign net_b5 = i1[5];
  assign net_b4 = i1[4];
  assign net_b3 = i1[3];
  assign net_b2 = i1[2];
  assign net_b1 = i1[1];
  assign net_b0 = i1[0];
  assign o[23] = net_sum23;
  assign o[22] = net_sum22;
  assign o[21] = net_sum21;
  assign o[20] = net_sum20;
  assign o[19] = net_sum19;
  assign o[18] = net_sum18;
  assign o[17] = net_sum17;
  assign o[16] = net_sum16;
  assign o[15] = net_sum15;
  assign o[14] = net_sum14;
  assign o[13] = net_sum13;
  assign o[12] = net_sum12;
  assign o[11] = net_sum11;
  assign o[10] = net_sum10;
  assign o[9] = net_sum9;
  assign o[8] = net_sum8;
  assign o[7] = net_sum7;
  assign o[6] = net_sum6;
  assign o[5] = net_sum5;
  assign o[4] = net_sum4;
  assign o[3] = net_sum3;
  assign o[2] = net_sum2;
  assign o[1] = net_sum1;
  assign o[0] = net_sum0;
  AL_FADD comp_0 (
    .a(net_a0),
    .b(net_b0),
    .c(1'b0),
    .cout(net_cout0),
    .sum(net_sum0));
  AL_FADD comp_1 (
    .a(net_a1),
    .b(net_b1),
    .c(net_cout0),
    .cout(net_cout1),
    .sum(net_sum1));
  AL_FADD comp_10 (
    .a(net_a10),
    .b(net_b10),
    .c(net_cout9),
    .cout(net_cout10),
    .sum(net_sum10));
  AL_FADD comp_11 (
    .a(net_a11),
    .b(net_b11),
    .c(net_cout10),
    .cout(net_cout11),
    .sum(net_sum11));
  AL_FADD comp_12 (
    .a(net_a12),
    .b(net_b12),
    .c(net_cout11),
    .cout(net_cout12),
    .sum(net_sum12));
  AL_FADD comp_13 (
    .a(net_a13),
    .b(net_b13),
    .c(net_cout12),
    .cout(net_cout13),
    .sum(net_sum13));
  AL_FADD comp_14 (
    .a(net_a14),
    .b(net_b14),
    .c(net_cout13),
    .cout(net_cout14),
    .sum(net_sum14));
  AL_FADD comp_15 (
    .a(net_a15),
    .b(net_b15),
    .c(net_cout14),
    .cout(net_cout15),
    .sum(net_sum15));
  AL_FADD comp_16 (
    .a(net_a16),
    .b(net_b16),
    .c(net_cout15),
    .cout(net_cout16),
    .sum(net_sum16));
  AL_FADD comp_17 (
    .a(net_a17),
    .b(net_b17),
    .c(net_cout16),
    .cout(net_cout17),
    .sum(net_sum17));
  AL_FADD comp_18 (
    .a(net_a18),
    .b(net_b18),
    .c(net_cout17),
    .cout(net_cout18),
    .sum(net_sum18));
  AL_FADD comp_19 (
    .a(net_a19),
    .b(net_b19),
    .c(net_cout18),
    .cout(net_cout19),
    .sum(net_sum19));
  AL_FADD comp_2 (
    .a(net_a2),
    .b(net_b2),
    .c(net_cout1),
    .cout(net_cout2),
    .sum(net_sum2));
  AL_FADD comp_20 (
    .a(net_a20),
    .b(net_b20),
    .c(net_cout19),
    .cout(net_cout20),
    .sum(net_sum20));
  AL_FADD comp_21 (
    .a(net_a21),
    .b(net_b21),
    .c(net_cout20),
    .cout(net_cout21),
    .sum(net_sum21));
  AL_FADD comp_22 (
    .a(net_a22),
    .b(net_b22),
    .c(net_cout21),
    .cout(net_cout22),
    .sum(net_sum22));
  AL_FADD comp_23 (
    .a(net_a23),
    .b(net_b23),
    .c(net_cout22),
    .cout(net_cout23),
    .sum(net_sum23));
  AL_FADD comp_3 (
    .a(net_a3),
    .b(net_b3),
    .c(net_cout2),
    .cout(net_cout3),
    .sum(net_sum3));
  AL_FADD comp_4 (
    .a(net_a4),
    .b(net_b4),
    .c(net_cout3),
    .cout(net_cout4),
    .sum(net_sum4));
  AL_FADD comp_5 (
    .a(net_a5),
    .b(net_b5),
    .c(net_cout4),
    .cout(net_cout5),
    .sum(net_sum5));
  AL_FADD comp_6 (
    .a(net_a6),
    .b(net_b6),
    .c(net_cout5),
    .cout(net_cout6),
    .sum(net_sum6));
  AL_FADD comp_7 (
    .a(net_a7),
    .b(net_b7),
    .c(net_cout6),
    .cout(net_cout7),
    .sum(net_sum7));
  AL_FADD comp_8 (
    .a(net_a8),
    .b(net_b8),
    .c(net_cout7),
    .cout(net_cout8),
    .sum(net_sum8));
  AL_FADD comp_9 (
    .a(net_a9),
    .b(net_b9),
    .c(net_cout8),
    .cout(net_cout9),
    .sum(net_sum9));

endmodule 

module reg_ar_as_w1
  (
  clk,
  d,
  en,
  reset,
  set,
  sload_data,
  sload_sel,
  q
  );

  input clk;
  input d;
  input en;
  input reset;
  input set;
  input sload_data;
  input sload_sel;
  output q;

  parameter REGSET = "RESET";
  wire enout;

  AL_MUX u_en0 (
    .i0(q),
    .i1(d),
    .sel(en),
    .o(enout));
  AL_DFF
    u_seq0 (
    .clk(clk),
    .d(enout),
    .reset(reset),
    .set(set),
    .q(q));

endmodule 

module eq_w3
  (
  i0,
  i1,
  o
  );

  input [2:0] i0;
  input [2:0] i1;
  output o;

  wire \or_xor_i0[0]_i1[0]_o_o ;
  wire \or_xor_i0[1]_i1[1]_o_o ;
  wire \xor_i0[0]_i1[0]_o ;
  wire \xor_i0[1]_i1[1]_o ;
  wire \xor_i0[2]_i1[2]_o ;

  not none_diff (o, \or_xor_i0[0]_i1[0]_o_o );
  or \or_xor_i0[0]_i1[0]_o  (\or_xor_i0[0]_i1[0]_o_o , \xor_i0[0]_i1[0]_o , \or_xor_i0[1]_i1[1]_o_o );
  or \or_xor_i0[1]_i1[1]_o  (\or_xor_i0[1]_i1[1]_o_o , \xor_i0[1]_i1[1]_o , \xor_i0[2]_i1[2]_o );
  xor \xor_i0[0]_i1[0]  (\xor_i0[0]_i1[0]_o , i0[0], i1[0]);
  xor \xor_i0[1]_i1[1]  (\xor_i0[1]_i1[1]_o , i0[1], i1[1]);
  xor \xor_i0[2]_i1[2]  (\xor_i0[2]_i1[2]_o , i0[2], i1[2]);

endmodule 

module eq_w5
  (
  i0,
  i1,
  o
  );

  input [4:0] i0;
  input [4:0] i1;
  output o;

  wire \or_or_xor_i0[0]_i1[0_o ;
  wire \or_xor_i0[0]_i1[0]_o_o ;
  wire \or_xor_i0[2]_i1[2]_o_o ;
  wire \or_xor_i0[3]_i1[3]_o_o ;
  wire \xor_i0[0]_i1[0]_o ;
  wire \xor_i0[1]_i1[1]_o ;
  wire \xor_i0[2]_i1[2]_o ;
  wire \xor_i0[3]_i1[3]_o ;
  wire \xor_i0[4]_i1[4]_o ;

  not none_diff (o, \or_or_xor_i0[0]_i1[0_o );
  or \or_or_xor_i0[0]_i1[0  (\or_or_xor_i0[0]_i1[0_o , \or_xor_i0[0]_i1[0]_o_o , \or_xor_i0[2]_i1[2]_o_o );
  or \or_xor_i0[0]_i1[0]_o  (\or_xor_i0[0]_i1[0]_o_o , \xor_i0[0]_i1[0]_o , \xor_i0[1]_i1[1]_o );
  or \or_xor_i0[2]_i1[2]_o  (\or_xor_i0[2]_i1[2]_o_o , \xor_i0[2]_i1[2]_o , \or_xor_i0[3]_i1[3]_o_o );
  or \or_xor_i0[3]_i1[3]_o  (\or_xor_i0[3]_i1[3]_o_o , \xor_i0[3]_i1[3]_o , \xor_i0[4]_i1[4]_o );
  xor \xor_i0[0]_i1[0]  (\xor_i0[0]_i1[0]_o , i0[0], i1[0]);
  xor \xor_i0[1]_i1[1]  (\xor_i0[1]_i1[1]_o , i0[1], i1[1]);
  xor \xor_i0[2]_i1[2]  (\xor_i0[2]_i1[2]_o , i0[2], i1[2]);
  xor \xor_i0[3]_i1[3]  (\xor_i0[3]_i1[3]_o , i0[3], i1[3]);
  xor \xor_i0[4]_i1[4]  (\xor_i0[4]_i1[4]_o , i0[4], i1[4]);

endmodule 

module binary_mux_s1_w1
  (
  i0,
  i1,
  sel,
  o
  );

  input i0;
  input i1;
  input sel;
  output o;


  AL_MUX al_mux_b0_0_0 (
    .i0(i0),
    .i1(i1),
    .sel(sel),
    .o(o));

endmodule 

module binary_mux_s3_w1
  (
  i0,
  i1,
  i2,
  i3,
  i4,
  i5,
  i6,
  i7,
  sel,
  o
  );

  input i0;
  input i1;
  input i2;
  input i3;
  input i4;
  input i5;
  input i6;
  input i7;
  input [2:0] sel;
  output o;

  wire  B0_0;
  wire  B0_1;
  wire  B0_2;
  wire  B0_3;
  wire  B1_0;
  wire  B1_1;

  AL_MUX al_mux_b0_0_0 (
    .i0(i0),
    .i1(i1),
    .sel(sel[0]),
    .o(B0_0));
  AL_MUX al_mux_b0_0_1 (
    .i0(i2),
    .i1(i3),
    .sel(sel[0]),
    .o(B0_1));
  AL_MUX al_mux_b0_0_2 (
    .i0(i4),
    .i1(i5),
    .sel(sel[0]),
    .o(B0_2));
  AL_MUX al_mux_b0_0_3 (
    .i0(i6),
    .i1(i7),
    .sel(sel[0]),
    .o(B0_3));
  AL_MUX al_mux_b0_1_0 (
    .i0(B0_0),
    .i1(B0_1),
    .sel(sel[1]),
    .o(B1_0));
  AL_MUX al_mux_b0_1_1 (
    .i0(B0_2),
    .i1(B0_3),
    .sel(sel[1]),
    .o(B1_1));
  AL_MUX al_mux_b0_2_0 (
    .i0(B1_0),
    .i1(B1_1),
    .sel(sel[2]),
    .o(o));

endmodule 

module binary_mux_s4_w1
  (
  i0,
  i1,
  i10,
  i11,
  i12,
  i13,
  i14,
  i15,
  i2,
  i3,
  i4,
  i5,
  i6,
  i7,
  i8,
  i9,
  sel,
  o
  );

  input i0;
  input i1;
  input i10;
  input i11;
  input i12;
  input i13;
  input i14;
  input i15;
  input i2;
  input i3;
  input i4;
  input i5;
  input i6;
  input i7;
  input i8;
  input i9;
  input [3:0] sel;
  output o;

  wire  B0_0;
  wire  B0_1;
  wire  B0_2;
  wire  B0_3;
  wire  B0_4;
  wire  B0_5;
  wire  B0_6;
  wire  B0_7;
  wire  B1_0;
  wire  B1_1;
  wire  B1_2;
  wire  B1_3;
  wire  B2_0;
  wire  B2_1;

  AL_MUX al_mux_b0_0_0 (
    .i0(i0),
    .i1(i1),
    .sel(sel[0]),
    .o(B0_0));
  AL_MUX al_mux_b0_0_1 (
    .i0(i2),
    .i1(i3),
    .sel(sel[0]),
    .o(B0_1));
  AL_MUX al_mux_b0_0_2 (
    .i0(i4),
    .i1(i5),
    .sel(sel[0]),
    .o(B0_2));
  AL_MUX al_mux_b0_0_3 (
    .i0(i6),
    .i1(i7),
    .sel(sel[0]),
    .o(B0_3));
  AL_MUX al_mux_b0_0_4 (
    .i0(i8),
    .i1(i9),
    .sel(sel[0]),
    .o(B0_4));
  AL_MUX al_mux_b0_0_5 (
    .i0(i10),
    .i1(i11),
    .sel(sel[0]),
    .o(B0_5));
  AL_MUX al_mux_b0_0_6 (
    .i0(i12),
    .i1(i13),
    .sel(sel[0]),
    .o(B0_6));
  AL_MUX al_mux_b0_0_7 (
    .i0(i14),
    .i1(i15),
    .sel(sel[0]),
    .o(B0_7));
  AL_MUX al_mux_b0_1_0 (
    .i0(B0_0),
    .i1(B0_1),
    .sel(sel[1]),
    .o(B1_0));
  AL_MUX al_mux_b0_1_1 (
    .i0(B0_2),
    .i1(B0_3),
    .sel(sel[1]),
    .o(B1_1));
  AL_MUX al_mux_b0_1_2 (
    .i0(B0_4),
    .i1(B0_5),
    .sel(sel[1]),
    .o(B1_2));
  AL_MUX al_mux_b0_1_3 (
    .i0(B0_6),
    .i1(B0_7),
    .sel(sel[1]),
    .o(B1_3));
  AL_MUX al_mux_b0_2_0 (
    .i0(B1_0),
    .i1(B1_1),
    .sel(sel[2]),
    .o(B2_0));
  AL_MUX al_mux_b0_2_1 (
    .i0(B1_2),
    .i1(B1_3),
    .sel(sel[2]),
    .o(B2_1));
  AL_MUX al_mux_b0_3_0 (
    .i0(B2_0),
    .i1(B2_1),
    .sel(sel[3]),
    .o(o));

endmodule 

module AL_MUX
  (
  input i0,
  input i1,
  input sel,
  output o
  );

  wire not_sel, sel_i0, sel_i1;
  not u0 (not_sel, sel);
  and u1 (sel_i1, sel, i1);
  and u2 (sel_i0, not_sel, i0);
  or u3 (o, sel_i1, sel_i0);

endmodule

module AL_FADD
  (
  input a,
  input b,
  input c,
  output sum,
  output cout
  );

  wire prop;
  wire not_prop;
  wire sel_i0;
  wire sel_i1;

  xor u0 (prop, a, b);
  xor u1 (sum, prop, c);
  not u2 (not_prop, prop);
  and u3 (sel_i1, prop, c);
  and u4 (sel_i0, not_prop, a);
  or  u5 (cout, sel_i0, sel_i1);

endmodule

module AL_DFF
  (
  input reset,
  input set,
  input clk,
  input d,
  output reg q
  );

  parameter INI = 1'b0;

  always @(posedge reset or posedge set or posedge clk)
  begin
    if (reset)
      q <= 1'b0;
    else if (set)
      q <= 1'b1;
    else
      q <= d;
  end

endmodule

