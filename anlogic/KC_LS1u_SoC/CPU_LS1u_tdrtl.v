// Verilog netlist created by TD v4.6.64949
// Mon Jan  1 04:59:34 2024

`timescale 1ns / 1ps
module CPU_LS1u  // ../../RTL/cpu/CPU_LS1u.v(1)
  (
  INT_ARR,
  clk,
  hrdata,
  hready,
  hresp,
  jtck,
  jtdi,
  jtms,
  rst,
  sys_por,
  haddr,
  hburst,
  htrans,
  hwdata,
  hwrite,
  jrst_out,
  jtdo
  );

  input [7:0] INT_ARR;  // ../../RTL/cpu/CPU_LS1u.v(19)
  input clk;  // ../../RTL/cpu/CPU_LS1u.v(14)
  input [15:0] hrdata;  // ../../RTL/cpu/CPU_LS1u.v(29)
  input hready;  // ../../RTL/cpu/CPU_LS1u.v(26)
  input hresp;  // ../../RTL/cpu/CPU_LS1u.v(27)
  input jtck;  // ../../RTL/cpu/CPU_LS1u.v(16)
  input jtdi;  // ../../RTL/cpu/CPU_LS1u.v(16)
  input jtms;  // ../../RTL/cpu/CPU_LS1u.v(16)
  input rst;  // ../../RTL/cpu/CPU_LS1u.v(14)
  input sys_por;  // ../../RTL/cpu/CPU_LS1u.v(13)
  output [23:0] haddr;  // ../../RTL/cpu/CPU_LS1u.v(21)
  output hburst;  // ../../RTL/cpu/CPU_LS1u.v(23)
  output htrans;  // ../../RTL/cpu/CPU_LS1u.v(24)
  output [15:0] hwdata;  // ../../RTL/cpu/CPU_LS1u.v(25)
  output [1:0] hwrite;  // ../../RTL/cpu/CPU_LS1u.v(22)
  output jrst_out;  // ../../RTL/cpu/CPU_LS1u.v(15)
  output jtdo;  // ../../RTL/cpu/CPU_LS1u.v(17)

  parameter BUS_WIDTH = 16;
  parameter CACHE_DEPTH = 2048;
  parameter CACHE_TYP = 2'b11;
  parameter CACHE_WIDTH = 16;
  parameter CPU_TYPE = "PLUS";
  parameter ENTRY_NUM = 1;
  parameter MMU_ENABLE = 1'b0;
  parameter cDMA_ENABLE = 1'b0;
  // localparam BUS_ADDRWID = 24;
  wire [1:0] \AHB_Interface/addr_counter ;  // ../../RTL/cache/bus_unit.v(71)
  wire [23:0] \AHB_Interface/haddr_temp ;  // ../../RTL/cache/bus_unit.v(72)
  wire [3:0] \AHB_Interface/n1 ;
  wire [3:0] \AHB_Interface/n10 ;
  wire [3:0] \AHB_Interface/n13 ;
  wire [3:0] \AHB_Interface/n14 ;
  wire [3:0] \AHB_Interface/n15 ;
  wire [3:0] \AHB_Interface/n2 ;
  wire [1:0] \AHB_Interface/n23 ;
  wire [1:0] \AHB_Interface/n25 ;
  wire [1:0] \AHB_Interface/n26 ;
  wire [23:0] \AHB_Interface/n31 ;
  wire [3:0] \AHB_Interface/n7 ;
  wire [3:0] \AHB_Interface/n8 ;
  wire [3:0] \AHB_Interface/n9 ;
  wire [3:0] \AHB_Interface/statu ;  // ../../RTL/cache/bus_unit.v(70)
  wire [7:0] \GEN_PLUS_CORE$CORE/A ;  // ../../RTL/cpu/KC_LS1u_plus.v(101)
  wire [1:0] \GEN_PLUS_CORE$CORE/ALU_eq ;  // ../../RTL/cpu/KC_LS1u_plus.v(224)
  wire [7:0] \GEN_PLUS_CORE$CORE/ALU_out ;  // ../../RTL/cpu/KC_LS1u_plus.v(223)
  wire [7:0] \GEN_PLUS_CORE$CORE/B ;  // ../../RTL/cpu/KC_LS1u_plus.v(101)
  wire [7:0] \GEN_PLUS_CORE$CORE/C ;  // ../../RTL/cpu/KC_LS1u_plus.v(101)
  wire [7:0] \GEN_PLUS_CORE$CORE/D ;  // ../../RTL/cpu/KC_LS1u_plus.v(101)
  wire [23:0] \GEN_PLUS_CORE$CORE/PCP1 ;  // ../../RTL/cpu/KC_LS1u_plus.v(42)
  wire [7:0] \GEN_PLUS_CORE$CORE/RET0 ;  // ../../RTL/cpu/KC_LS1u_plus.v(26)
  wire [7:0] \GEN_PLUS_CORE$CORE/RET1 ;  // ../../RTL/cpu/KC_LS1u_plus.v(26)
  wire [7:0] \GEN_PLUS_CORE$CORE/RET2 ;  // ../../RTL/cpu/KC_LS1u_plus.v(26)
  wire [7:0] \GEN_PLUS_CORE$CORE/RTA0 ;  // ../../RTL/cpu/KC_LS1u_plus.v(27)
  wire [7:0] \GEN_PLUS_CORE$CORE/RTA1 ;  // ../../RTL/cpu/KC_LS1u_plus.v(27)
  wire [7:0] \GEN_PLUS_CORE$CORE/RTA2 ;  // ../../RTL/cpu/KC_LS1u_plus.v(27)
  wire [7:0] \GEN_PLUS_CORE$CORE/SFTO ;  // ../../RTL/cpu/KC_LS1u_plus.v(256)
  wire [7:0] \GEN_PLUS_CORE$CORE/XREGr ;  // ../../RTL/cpu/KC_LS1u_plus.v(201)
  wire [3:0] \GEN_PLUS_CORE$CORE/dbsrc_addr ;  // ../../RTL/cpu/KC_LS1u_plus.v(153)
  wire [23:0] \GEN_PLUS_CORE$CORE/jaddr ;  // ../../RTL/cpu/KC_LS1u_plus.v(30)
  wire [7:0] \GEN_PLUS_CORE$CORE/n11 ;
  wire [7:0] \GEN_PLUS_CORE$CORE/n12 ;
  wire [7:0] \GEN_PLUS_CORE$CORE/n13 ;
  wire [7:0] \GEN_PLUS_CORE$CORE/n28 ;
  wire [7:0] \GEN_PLUS_CORE$CORE/n29 ;
  wire [7:0] \GEN_PLUS_CORE$CORE/n30 ;
  wire [7:0] \GEN_PLUS_CORE$CORE/n31 ;
  wire [7:0] \GEN_PLUS_CORE$CORE/n32 ;
  wire [7:0] \GEN_PLUS_CORE$CORE/n33 ;
  wire [7:0] \GEN_PLUS_CORE$CORE/n34 ;
  wire [7:0] \GEN_PLUS_CORE$CORE/n35 ;
  wire [7:0] \GEN_PLUS_CORE$CORE/n36 ;
  wire [7:0] \GEN_PLUS_CORE$CORE/n38 ;
  wire [7:0] \GEN_PLUS_CORE$CORE/n39 ;
  wire [7:0] \GEN_PLUS_CORE$CORE/n40 ;
  wire [23:0] \GEN_PLUS_CORE$CORE/n5 ;
  wire [7:0] \GEN_PLUS_CORE$CORE/n53 ;
  wire [7:0] \GEN_PLUS_CORE$CORE/n54 ;
  wire [7:0] \GEN_PLUS_CORE$CORE/n55 ;
  wire [7:0] \GEN_PLUS_CORE$CORE/n59 ;
  wire [23:0] \GEN_PLUS_CORE$CORE/n6 ;
  wire [7:0] \GEN_PLUS_CORE$CORE/n60 ;
  wire [7:0] \GEN_PLUS_CORE$CORE/n61 ;
  wire [7:0] \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/EXPE0 ;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(35)
  wire [2:0] \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTC ;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(33)
  wire [7:0] \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTE0 ;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(35)
  wire [7:0] \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/shift_stages[1] ;  // ../../RTL/peripherals/left_bshifter.v(12)
  wire [7:0] \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/shift_stages[2] ;  // ../../RTL/peripherals/left_bshifter.v(12)
  wire [7:0] \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT0 ;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(34)
  wire [7:0] \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT1 ;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(34)
  wire [7:0] \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT2 ;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(34)
  wire [7:0] \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked ;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(36)
  wire [2:0] \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_select_encode[2] ;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(41)
  wire [2:0] \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_select_encode[3] ;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(41)
  wire [2:0] \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_select_encode[4] ;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(41)
  wire [2:0] \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_select_encode[5] ;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(41)
  wire [2:0] \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_select_encode[6] ;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(41)
  wire [2:0] \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_select_encode[7] ;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(41)
  wire [21:0] \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n1 ;
  wire [7:0] \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n23 ;
  wire [7:0] \GEN_PLUS_CORE$eXternalCtrlRegs/ecp_dout ;  // ../../RTL/cpu/XCR_Components/xcr_top.v(33)
  wire [23:0] IVEC_addr;  // ../../RTL/cpu/CPU_LS1u.v(51)
  wire [15:0] NO_CACHE$BIT16_BUS_CASE$instr_hold;  // ../../RTL/cpu/CPU_LS1u.v(296)
  wire [7:0] XCRi;  // ../../RTL/cpu/CPU_LS1u.v(44)
  wire [7:0] XCRo;  // ../../RTL/cpu/CPU_LS1u.v(45)
  wire [23:0] daddr;  // ../../RTL/cpu/CPU_LS1u.v(33)
  wire [7:0] ddata_i;  // ../../RTL/cpu/CPU_LS1u.v(36)
  wire [23:0] iaddr;  // ../../RTL/cpu/CPU_LS1u.v(31)
  wire [15:0] instr;  // ../../RTL/cpu/CPU_LS1u.v(32)
  wire [23:0] pa_l1;  // ../../RTL/cpu/CPU_LS1u.v(205)
  wire [1:0] write_through_req;  // ../../RTL/cpu/CPU_LS1u.v(209)
  wire \AHB_Interface/mux14_b0_sel_is_2_o ;
  wire \AHB_Interface/mux15_b11_sel_is_0_o ;
  wire \AHB_Interface/mux1_b0_sel_is_0_o ;
  wire \AHB_Interface/mux9_b0_sel_is_3_o ;
  wire \AHB_Interface/n0 ;
  wire \AHB_Interface/n0_neg ;
  wire \AHB_Interface/n17 ;
  wire \AHB_Interface/n18 ;
  wire \AHB_Interface/n19 ;
  wire \AHB_Interface/n20 ;
  wire \AHB_Interface/n21 ;
  wire \AHB_Interface/n28 ;
  wire \AHB_Interface/n32 ;
  wire \AHB_Interface/n33 ;
  wire \AHB_Interface/n34 ;
  wire \AHB_Interface/n35 ;
  wire \AHB_Interface/n36 ;
  wire \AHB_Interface/n37 ;
  wire \AHB_Interface/n38 ;
  wire \AHB_Interface/n39 ;
  wire \AHB_Interface/n5 ;
  wire \AHB_Interface/n6 ;
  wire \AHB_Interface/n6_neg ;
  wire \GEN_PLUS_CORE$CORE/ALU_C1 ;  // ../../RTL/cpu/KC_LS1u_plus.v(225)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_10 ;  // ../../RTL/cpu/alu74181.v(18)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_101 ;  // ../../RTL/cpu/alu74181.v(56)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_102 ;  // ../../RTL/cpu/alu74181.v(57)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_103 ;  // ../../RTL/cpu/alu74181.v(58)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_105 ;  // ../../RTL/cpu/alu74181.v(59)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_11 ;  // ../../RTL/cpu/alu74181.v(19)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_115 ;  // ../../RTL/cpu/alu74181.v(65)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_116 ;  // ../../RTL/cpu/alu74181.v(60)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_117 ;  // ../../RTL/cpu/alu74181.v(11)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_118 ;  // ../../RTL/cpu/alu74181.v(12)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_119 ;  // ../../RTL/cpu/alu74181.v(13)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_12 ;  // ../../RTL/cpu/alu74181.v(20)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_128 ;  // ../../RTL/cpu/alu74181.v(41)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_129 ;  // ../../RTL/cpu/alu74181.v(42)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_13 ;  // ../../RTL/cpu/alu74181.v(21)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_14 ;  // ../../RTL/cpu/alu74181.v(22)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_15 ;  // ../../RTL/cpu/alu74181.v(23)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_16 ;  // ../../RTL/cpu/alu74181.v(24)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_17 ;  // ../../RTL/cpu/alu74181.v(25)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_18 ;  // ../../RTL/cpu/alu74181.v(26)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_19 ;  // ../../RTL/cpu/alu74181.v(27)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_20 ;  // ../../RTL/cpu/alu74181.v(28)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_21 ;  // ../../RTL/cpu/alu74181.v(29)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_22 ;  // ../../RTL/cpu/alu74181.v(30)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_23 ;  // ../../RTL/cpu/alu74181.v(31)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_24 ;  // ../../RTL/cpu/alu74181.v(32)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_25 ;  // ../../RTL/cpu/alu74181.v(33)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_26 ;  // ../../RTL/cpu/alu74181.v(34)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_27 ;  // ../../RTL/cpu/alu74181.v(35)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_28 ;  // ../../RTL/cpu/alu74181.v(36)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_29 ;  // ../../RTL/cpu/alu74181.v(37)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_56 ;  // ../../RTL/cpu/alu74181.v(38)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_57 ;  // ../../RTL/cpu/alu74181.v(39)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_58 ;  // ../../RTL/cpu/alu74181.v(40)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_6 ;  // ../../RTL/cpu/alu74181.v(14)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_7 ;  // ../../RTL/cpu/alu74181.v(15)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_8 ;  // ../../RTL/cpu/alu74181.v(16)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_86 ;  // ../../RTL/cpu/alu74181.v(43)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_87 ;  // ../../RTL/cpu/alu74181.v(44)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_88 ;  // ../../RTL/cpu/alu74181.v(45)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_89 ;  // ../../RTL/cpu/alu74181.v(46)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_9 ;  // ../../RTL/cpu/alu74181.v(17)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_90 ;  // ../../RTL/cpu/alu74181.v(47)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_91 ;  // ../../RTL/cpu/alu74181.v(48)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_92 ;  // ../../RTL/cpu/alu74181.v(49)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_93 ;  // ../../RTL/cpu/alu74181.v(50)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_94 ;  // ../../RTL/cpu/alu74181.v(51)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_97 ;  // ../../RTL/cpu/alu74181.v(53)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_98 ;  // ../../RTL/cpu/alu74181.v(54)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_99 ;  // ../../RTL/cpu/alu74181.v(55)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/g ;  // ../../RTL/cpu/alu74181.v(8)
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n0 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n1 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n10 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n11 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n12 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n13 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n14 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n15 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n16 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n17 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n18 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n19 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n2 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n20 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n22 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n23 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n24 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n25 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n26 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n27 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n28 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n29 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n3 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n30 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n31 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n32 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n33 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n34 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n35 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n36 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n37 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n38 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n39 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n4 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n40 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n41 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n42 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n43 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n44 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n45 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n46 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n47 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n5 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n6 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n7 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n8 ;
  wire \GEN_PLUS_CORE$CORE/ALU_H4/n9 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_10 ;  // ../../RTL/cpu/alu74181.v(18)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_101 ;  // ../../RTL/cpu/alu74181.v(56)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_102 ;  // ../../RTL/cpu/alu74181.v(57)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_103 ;  // ../../RTL/cpu/alu74181.v(58)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_105 ;  // ../../RTL/cpu/alu74181.v(59)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_11 ;  // ../../RTL/cpu/alu74181.v(19)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_115 ;  // ../../RTL/cpu/alu74181.v(65)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_116 ;  // ../../RTL/cpu/alu74181.v(60)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_117 ;  // ../../RTL/cpu/alu74181.v(11)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_118 ;  // ../../RTL/cpu/alu74181.v(12)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_119 ;  // ../../RTL/cpu/alu74181.v(13)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_12 ;  // ../../RTL/cpu/alu74181.v(20)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_129 ;  // ../../RTL/cpu/alu74181.v(42)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_13 ;  // ../../RTL/cpu/alu74181.v(21)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_14 ;  // ../../RTL/cpu/alu74181.v(22)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_15 ;  // ../../RTL/cpu/alu74181.v(23)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_16 ;  // ../../RTL/cpu/alu74181.v(24)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_17 ;  // ../../RTL/cpu/alu74181.v(25)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_18 ;  // ../../RTL/cpu/alu74181.v(26)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_19 ;  // ../../RTL/cpu/alu74181.v(27)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_20 ;  // ../../RTL/cpu/alu74181.v(28)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_21 ;  // ../../RTL/cpu/alu74181.v(29)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_22 ;  // ../../RTL/cpu/alu74181.v(30)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_23 ;  // ../../RTL/cpu/alu74181.v(31)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_24 ;  // ../../RTL/cpu/alu74181.v(32)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_25 ;  // ../../RTL/cpu/alu74181.v(33)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_26 ;  // ../../RTL/cpu/alu74181.v(34)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_27 ;  // ../../RTL/cpu/alu74181.v(35)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_28 ;  // ../../RTL/cpu/alu74181.v(36)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_29 ;  // ../../RTL/cpu/alu74181.v(37)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_56 ;  // ../../RTL/cpu/alu74181.v(38)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_57 ;  // ../../RTL/cpu/alu74181.v(39)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_58 ;  // ../../RTL/cpu/alu74181.v(40)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_6 ;  // ../../RTL/cpu/alu74181.v(14)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_7 ;  // ../../RTL/cpu/alu74181.v(15)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_8 ;  // ../../RTL/cpu/alu74181.v(16)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_86 ;  // ../../RTL/cpu/alu74181.v(43)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_87 ;  // ../../RTL/cpu/alu74181.v(44)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_88 ;  // ../../RTL/cpu/alu74181.v(45)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_89 ;  // ../../RTL/cpu/alu74181.v(46)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_9 ;  // ../../RTL/cpu/alu74181.v(17)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_90 ;  // ../../RTL/cpu/alu74181.v(47)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_91 ;  // ../../RTL/cpu/alu74181.v(48)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_92 ;  // ../../RTL/cpu/alu74181.v(49)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_93 ;  // ../../RTL/cpu/alu74181.v(50)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_94 ;  // ../../RTL/cpu/alu74181.v(51)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_97 ;  // ../../RTL/cpu/alu74181.v(53)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_98 ;  // ../../RTL/cpu/alu74181.v(54)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_99 ;  // ../../RTL/cpu/alu74181.v(55)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/g ;  // ../../RTL/cpu/alu74181.v(8)
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n0 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n1 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n10 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n11 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n12 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n13 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n14 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n15 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n16 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n17 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n18 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n19 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n2 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n20 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n22 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n23 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n24 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n25 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n26 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n27 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n28 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n29 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n3 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n30 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n31 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n32 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n33 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n34 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n35 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n36 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n37 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n38 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n39 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n4 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n40 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n41 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n42 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n43 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n44 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n45 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n46 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n47 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n5 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n6 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n7 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n8 ;
  wire \GEN_PLUS_CORE$CORE/ALU_L4/n9 ;
  wire \GEN_PLUS_CORE$CORE/ALU_eqo ;  // ../../RTL/cpu/KC_LS1u_plus.v(225)
  wire \GEN_PLUS_CORE$CORE/INSTR_HOLD ;  // ../../RTL/cpu/KC_LS1u_plus.v(19)
  wire \GEN_PLUS_CORE$CORE/INSTR_HOLD_neg ;
  wire \GEN_PLUS_CORE$CORE/IN_ISP ;  // ../../RTL/cpu/KC_LS1u_plus.v(5)
  wire \GEN_PLUS_CORE$CORE/instr_wait ;  // ../../RTL/cpu/KC_LS1u_plus.v(38)
  wire \GEN_PLUS_CORE$CORE/int_filter ;  // ../../RTL/cpu/KC_LS1u_plus.v(35)
  wire \GEN_PLUS_CORE$CORE/jmp ;  // ../../RTL/cpu/KC_LS1u_plus.v(32)
  wire \GEN_PLUS_CORE$CORE/jmp_en ;  // ../../RTL/cpu/KC_LS1u_plus.v(136)
  wire \GEN_PLUS_CORE$CORE/jmp_wait ;  // ../../RTL/cpu/KC_LS1u_plus.v(31)
  wire \GEN_PLUS_CORE$CORE/mux10_b0_sel_is_2_o ;
  wire \GEN_PLUS_CORE$CORE/mux11_b0_sel_is_1_o ;
  wire \GEN_PLUS_CORE$CORE/mux12_b0_sel_is_0_o ;
  wire \GEN_PLUS_CORE$CORE/mux13_b0_sel_is_3_o ;
  wire \GEN_PLUS_CORE$CORE/mux14_b0_sel_is_3_o ;
  wire \GEN_PLUS_CORE$CORE/mux15_b0_sel_is_3_o ;
  wire \GEN_PLUS_CORE$CORE/mux16_b0_sel_is_3_o ;
  wire \GEN_PLUS_CORE$CORE/mux17_b0_sel_is_3_o ;
  wire \GEN_PLUS_CORE$CORE/mux18_b0_sel_is_3_o ;
  wire \GEN_PLUS_CORE$CORE/mux19_b0_sel_is_2_o ;
  wire \GEN_PLUS_CORE$CORE/mux20_b0_sel_is_2_o ;
  wire \GEN_PLUS_CORE$CORE/mux21_b0_sel_is_2_o ;
  wire \GEN_PLUS_CORE$CORE/mux22_b0_sel_is_2_o ;
  wire \GEN_PLUS_CORE$CORE/mux23_b0_sel_is_2_o ;
  wire \GEN_PLUS_CORE$CORE/mux24_b0_sel_is_2_o ;
  wire \GEN_PLUS_CORE$CORE/mux34_b0_sel_is_6_o ;
  wire \GEN_PLUS_CORE$CORE/mux35_b0_sel_is_5_o ;
  wire \GEN_PLUS_CORE$CORE/mux36_b0_sel_is_4_o ;
  wire \GEN_PLUS_CORE$CORE/mux37_b0_sel_is_3_o ;
  wire \GEN_PLUS_CORE$CORE/mux38_b0_sel_is_2_o ;
  wire \GEN_PLUS_CORE$CORE/mux39_b0_sel_is_1_o ;
  wire \GEN_PLUS_CORE$CORE/mux3_b0_sel_is_0_o ;
  wire \GEN_PLUS_CORE$CORE/mux40_b0_sel_is_0_o ;
  wire \GEN_PLUS_CORE$CORE/mux41_b0_sel_is_3_o ;
  wire \GEN_PLUS_CORE$CORE/mux42_b0_sel_is_3_o ;
  wire \GEN_PLUS_CORE$CORE/mux43_b0_sel_is_3_o ;
  wire \GEN_PLUS_CORE$CORE/mux44_b0_sel_is_3_o ;
  wire \GEN_PLUS_CORE$CORE/mux45_b0_sel_is_3_o ;
  wire \GEN_PLUS_CORE$CORE/mux46_b0_sel_is_3_o ;
  wire \GEN_PLUS_CORE$CORE/mux47_b0_sel_is_3_o ;
  wire \GEN_PLUS_CORE$CORE/mux51_b0_sel_is_2_o ;
  wire \GEN_PLUS_CORE$CORE/mux52_b0_sel_is_2_o ;
  wire \GEN_PLUS_CORE$CORE/mux53_b0_sel_is_2_o ;
  wire \GEN_PLUS_CORE$CORE/mux54_b0_sel_is_2_o ;
  wire \GEN_PLUS_CORE$CORE/mux7_b0_sel_is_5_o ;
  wire \GEN_PLUS_CORE$CORE/mux8_b0_sel_is_4_o ;
  wire \GEN_PLUS_CORE$CORE/mux9_b0_sel_is_3_o ;
  wire \GEN_PLUS_CORE$CORE/n0 ;
  wire \GEN_PLUS_CORE$CORE/n1 ;
  wire \GEN_PLUS_CORE$CORE/n10 ;
  wire \GEN_PLUS_CORE$CORE/n100 ;
  wire \GEN_PLUS_CORE$CORE/n101 ;
  wire \GEN_PLUS_CORE$CORE/n102 ;
  wire \GEN_PLUS_CORE$CORE/n103 ;
  wire \GEN_PLUS_CORE$CORE/n104 ;
  wire \GEN_PLUS_CORE$CORE/n105 ;
  wire \GEN_PLUS_CORE$CORE/n106 ;
  wire \GEN_PLUS_CORE$CORE/n107 ;
  wire \GEN_PLUS_CORE$CORE/n108 ;
  wire \GEN_PLUS_CORE$CORE/n109 ;
  wire \GEN_PLUS_CORE$CORE/n110 ;
  wire \GEN_PLUS_CORE$CORE/n111 ;
  wire \GEN_PLUS_CORE$CORE/n112 ;
  wire \GEN_PLUS_CORE$CORE/n113 ;
  wire \GEN_PLUS_CORE$CORE/n114 ;
  wire \GEN_PLUS_CORE$CORE/n115 ;
  wire \GEN_PLUS_CORE$CORE/n117 ;
  wire \GEN_PLUS_CORE$CORE/n118 ;
  wire \GEN_PLUS_CORE$CORE/n119 ;
  wire \GEN_PLUS_CORE$CORE/n120 ;
  wire \GEN_PLUS_CORE$CORE/n121 ;
  wire \GEN_PLUS_CORE$CORE/n122 ;
  wire \GEN_PLUS_CORE$CORE/n123 ;
  wire \GEN_PLUS_CORE$CORE/n124 ;
  wire \GEN_PLUS_CORE$CORE/n125 ;
  wire \GEN_PLUS_CORE$CORE/n126 ;
  wire \GEN_PLUS_CORE$CORE/n129 ;
  wire \GEN_PLUS_CORE$CORE/n134 ;
  wire \GEN_PLUS_CORE$CORE/n136 ;
  wire \GEN_PLUS_CORE$CORE/n14 ;
  wire \GEN_PLUS_CORE$CORE/n140 ;
  wire \GEN_PLUS_CORE$CORE/n141 ;
  wire \GEN_PLUS_CORE$CORE/n142 ;
  wire \GEN_PLUS_CORE$CORE/n2 ;
  wire \GEN_PLUS_CORE$CORE/n27 ;
  wire \GEN_PLUS_CORE$CORE/n3 ;
  wire \GEN_PLUS_CORE$CORE/n37 ;
  wire \GEN_PLUS_CORE$CORE/n4 ;
  wire \GEN_PLUS_CORE$CORE/n44 ;
  wire \GEN_PLUS_CORE$CORE/n66 ;
  wire \GEN_PLUS_CORE$CORE/n67 ;
  wire \GEN_PLUS_CORE$CORE/n68 ;
  wire \GEN_PLUS_CORE$CORE/n69 ;
  wire \GEN_PLUS_CORE$CORE/n7 ;
  wire \GEN_PLUS_CORE$CORE/n70 ;
  wire \GEN_PLUS_CORE$CORE/n71 ;
  wire \GEN_PLUS_CORE$CORE/n72 ;
  wire \GEN_PLUS_CORE$CORE/n73 ;
  wire \GEN_PLUS_CORE$CORE/n74 ;
  wire \GEN_PLUS_CORE$CORE/n75 ;
  wire \GEN_PLUS_CORE$CORE/n76 ;
  wire \GEN_PLUS_CORE$CORE/n77 ;
  wire \GEN_PLUS_CORE$CORE/n78 ;
  wire \GEN_PLUS_CORE$CORE/n79 ;
  wire \GEN_PLUS_CORE$CORE/n7_neg ;
  wire \GEN_PLUS_CORE$CORE/n80 ;
  wire \GEN_PLUS_CORE$CORE/n81 ;
  wire \GEN_PLUS_CORE$CORE/n9 ;
  wire \GEN_PLUS_CORE$CORE/n91 ;
  wire \GEN_PLUS_CORE$CORE/n92 ;
  wire \GEN_PLUS_CORE$CORE/n94 ;
  wire \GEN_PLUS_CORE$CORE/n96 ;
  wire \GEN_PLUS_CORE$CORE/n97 ;
  wire \GEN_PLUS_CORE$CORE/n98 ;
  wire \GEN_PLUS_CORE$CORE/n99 ;
  wire \GEN_PLUS_CORE$CORE/regwrite ;  // ../../RTL/cpu/KC_LS1u_plus.v(98)
  wire \GEN_PLUS_CORE$CORE/ret_sel ;  // ../../RTL/cpu/KC_LS1u_plus.v(32)
  wire \GEN_PLUS_CORE$CORE/ret_sel_neg ;
  wire \GEN_PLUS_CORE$CORE/sel0_b0_sel_o ;  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  wire \GEN_PLUS_CORE$CORE/sel0_b1_sel_o ;  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  wire \GEN_PLUS_CORE$CORE/sel0_b2_sel_o ;  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  wire \GEN_PLUS_CORE$CORE/sel0_b3_sel_o ;  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked[2]_neg ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked[3]_neg ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked[4]_neg ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked[5]_neg ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked[6]_neg ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked[7]_neg ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux14_b0_sel_is_3_o ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux15_b0_sel_is_3_o ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux16_b0_sel_is_3_o ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux17_b0_sel_is_3_o ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux18_b0_sel_is_3_o ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux19_b0_sel_is_3_o ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux1_b1_sel_is_0_o ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux1_b1_sel_is_0_o_neg ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux20_b0_sel_is_2_o ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux21_b0_sel_is_2_o ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux22_b0_sel_is_2_o ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux23_b0_sel_is_2_o ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux24_b0_sel_is_2_o ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux2_b1_sel_is_0_o ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux3_b1_sel_is_2_o ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux3_b1_sel_is_2_o_neg ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux3_b2_sel_is_0_o ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux4_b1_sel_is_0_o ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux4_b2_sel_is_2_o ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux5_b1_sel_is_2_o ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux5_b2_sel_is_2_o ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux7_b0_sel_is_2_o ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n0 ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n2 ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n24 ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n5 ;
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/ecp_cs ;  // ../../RTL/cpu/XCR_Components/xcr_top.v(34)
  wire \GEN_PLUS_CORE$eXternalCtrlRegs/n0 ;
  wire INT_Req;  // ../../RTL/cpu/CPU_LS1u.v(50)
  wire NO_CACHE$BIT16_BUS_CASE$access_is_data;  // ../../RTL/cpu/CPU_LS1u.v(297)
  wire NO_CACHE$BIT16_BUS_CASE$dbyte;  // ../../RTL/cpu/CPU_LS1u.v(295)
  wire NO_CACHE$BIT16_BUS_CASE$prev_xf_is_instr;  // ../../RTL/cpu/CPU_LS1u.v(295)
  wire XCRcs;  // ../../RTL/cpu/CPU_LS1u.v(48)
  wire XCRwe;  // ../../RTL/cpu/CPU_LS1u.v(47)
  wire dread;  // ../../RTL/cpu/CPU_LS1u.v(35)
  wire dwrite;  // ../../RTL/cpu/CPU_LS1u.v(34)
  wire hresp_neg;
  wire \instr[0]_neg ;
  wire \instr[10]_neg ;
  wire \instr[1]_neg ;
  wire \instr[2]_neg ;
  wire \instr[8]_neg ;
  wire \instr[9]_neg ;
  wire n0;
  wire n2;
  wire n3;
  wire n6;
  wire read_req;  // ../../RTL/cpu/CPU_LS1u.v(210)
  wire rst_neg;
  wire trans_rdy;  // ../../RTL/cpu/CPU_LS1u.v(217)

  assign haddr[1] = \AHB_Interface/haddr_temp [1];
  assign haddr[0] = \AHB_Interface/haddr_temp [0];
  assign hwdata[15] = 1'b0;
  assign hwdata[14] = 1'b0;
  assign hwdata[13] = 1'b0;
  assign hwdata[12] = 1'b0;
  assign hwdata[11] = 1'b0;
  assign hwdata[10] = 1'b0;
  assign hwdata[9] = 1'b0;
  assign hwdata[8] = 1'b0;
  assign hwdata[7] = 1'b0;
  assign hwdata[6] = 1'b0;
  assign hwdata[5] = 1'b0;
  assign hwdata[4] = 1'b0;
  assign hwdata[3] = 1'b0;
  assign hwdata[2] = 1'b0;
  assign hwdata[1] = 1'b0;
  assign hwdata[0] = 1'b0;
  add_pu2_pu2_o2 \AHB_Interface/add0  (
    .i0(\AHB_Interface/addr_counter ),
    .i1(2'b01),
    .o(\AHB_Interface/n23 ));  // ../../RTL/cache/bus_unit.v(129)
  eq_w2 \AHB_Interface/eq0  (
    .i0(\AHB_Interface/addr_counter ),
    .i1(2'b11),
    .o(\AHB_Interface/n5 ));  // ../../RTL/cache/bus_unit.v(106)
  eq_w4 \AHB_Interface/eq1  (
    .i0(\AHB_Interface/statu ),
    .i1(4'b0000),
    .o(\AHB_Interface/n17 ));  // ../../RTL/cache/bus_unit.v(121)
  eq_w4 \AHB_Interface/eq2  (
    .i0(\AHB_Interface/statu ),
    .i1(4'b1001),
    .o(\AHB_Interface/n19 ));  // ../../RTL/cache/bus_unit.v(128)
  eq_w4 \AHB_Interface/eq3  (
    .i0(\AHB_Interface/statu ),
    .i1(4'b1010),
    .o(\AHB_Interface/n20 ));  // ../../RTL/cache/bus_unit.v(128)
  eq_w4 \AHB_Interface/eq4  (
    .i0(\AHB_Interface/statu ),
    .i1(4'b1011),
    .o(\AHB_Interface/n28 ));  // ../../RTL/cache/bus_unit.v(135)
  eq_w4 \AHB_Interface/eq5  (
    .i0(\AHB_Interface/statu ),
    .i1(4'b0010),
    .o(\AHB_Interface/n32 ));  // ../../RTL/cache/bus_unit.v(154)
  eq_w4 \AHB_Interface/eq6  (
    .i0(\AHB_Interface/statu ),
    .i1(4'b0100),
    .o(\AHB_Interface/n33 ));  // ../../RTL/cache/bus_unit.v(155)
  eq_w4 \AHB_Interface/eq7  (
    .i0(\AHB_Interface/statu ),
    .i1(4'b0101),
    .o(\AHB_Interface/n36 ));  // ../../RTL/cache/bus_unit.v(161)
  eq_w4 \AHB_Interface/eq8  (
    .i0(\AHB_Interface/statu ),
    .i1(4'b0011),
    .o(\AHB_Interface/n37 ));  // ../../RTL/cache/bus_unit.v(161)
  binary_mux_s1_w1 \AHB_Interface/mux0_b1  (
    .i0(\AHB_Interface/statu [1]),
    .i1(1'b1),
    .sel(\AHB_Interface/n0 ),
    .o(\AHB_Interface/n1 [1]));  // ../../RTL/cache/bus_unit.v(96)
  binary_mux_s1_w1 \AHB_Interface/mux0_b2  (
    .i0(\AHB_Interface/statu [2]),
    .i1(1'b0),
    .sel(\AHB_Interface/n0 ),
    .o(\AHB_Interface/n1 [2]));  // ../../RTL/cache/bus_unit.v(96)
  binary_mux_s1_w1 \AHB_Interface/mux10_b0  (
    .i0(\AHB_Interface/n25 [0]),
    .i1(1'b1),
    .sel(\AHB_Interface/n5 ),
    .o(\AHB_Interface/n26 [0]));  // ../../RTL/cache/bus_unit.v(130)
  binary_mux_s1_w1 \AHB_Interface/mux10_b1  (
    .i0(\AHB_Interface/n25 [1]),
    .i1(1'b1),
    .sel(\AHB_Interface/n5 ),
    .o(\AHB_Interface/n26 [1]));  // ../../RTL/cache/bus_unit.v(130)
  AL_MUX \AHB_Interface/mux14_b0  (
    .i0(1'b0),
    .i1(daddr[0]),
    .sel(\AHB_Interface/mux14_b0_sel_is_2_o ),
    .o(\AHB_Interface/n31 [0]));
  and \AHB_Interface/mux14_b0_sel_is_2  (\AHB_Interface/mux14_b0_sel_is_2_o , rst_neg, NO_CACHE$BIT16_BUS_CASE$access_is_data);
  binary_mux_s1_w1 \AHB_Interface/mux15_b0  (
    .i0(\AHB_Interface/n9 [0]),
    .i1(1'b1),
    .sel(hresp),
    .o(\AHB_Interface/n10 [0]));  // ../../RTL/cache/bus_unit.v(111)
  binary_mux_s1_w1 \AHB_Interface/mux15_b1  (
    .i0(\AHB_Interface/n9 [1]),
    .i1(1'b1),
    .sel(hresp),
    .o(\AHB_Interface/n10 [1]));  // ../../RTL/cache/bus_unit.v(111)
  binary_mux_s1_w1 \AHB_Interface/mux15_b10  (
    .i0(\AHB_Interface/n7 [2]),
    .i1(1'b1),
    .sel(hresp),
    .o(\AHB_Interface/n8 [2]));  // ../../RTL/cache/bus_unit.v(111)
  AL_MUX \AHB_Interface/mux15_b11  (
    .i0(1'b1),
    .i1(\AHB_Interface/statu [3]),
    .sel(\AHB_Interface/mux15_b11_sel_is_0_o ),
    .o(\AHB_Interface/n8 [3]));
  and \AHB_Interface/mux15_b11_sel_is_0  (\AHB_Interface/mux15_b11_sel_is_0_o , hresp_neg, \AHB_Interface/n6_neg );
  binary_mux_s1_w1 \AHB_Interface/mux15_b14  (
    .i0(\AHB_Interface/n13 [2]),
    .i1(1'b1),
    .sel(hresp),
    .o(\AHB_Interface/n14 [2]));  // ../../RTL/cache/bus_unit.v(111)
  binary_mux_s1_w1 \AHB_Interface/mux15_b15  (
    .i0(\AHB_Interface/n13 [3]),
    .i1(1'b1),
    .sel(hresp),
    .o(\AHB_Interface/n14 [3]));  // ../../RTL/cache/bus_unit.v(111)
  AL_MUX \AHB_Interface/mux15_b8  (
    .i0(1'b1),
    .i1(\AHB_Interface/statu [0]),
    .sel(\AHB_Interface/mux15_b11_sel_is_0_o ),
    .o(\AHB_Interface/n8 [0]));
  AL_MUX \AHB_Interface/mux15_b9  (
    .i0(1'b1),
    .i1(\AHB_Interface/statu [1]),
    .sel(\AHB_Interface/mux15_b11_sel_is_0_o ),
    .o(\AHB_Interface/n8 [1]));
  AL_MUX \AHB_Interface/mux1_b0  (
    .i0(1'b0),
    .i1(\AHB_Interface/statu [0]),
    .sel(\AHB_Interface/mux1_b0_sel_is_0_o ),
    .o(\AHB_Interface/n2 [0]));
  and \AHB_Interface/mux1_b0_sel_is_0  (\AHB_Interface/mux1_b0_sel_is_0_o , dwrite, \AHB_Interface/n0_neg );
  binary_mux_s1_w1 \AHB_Interface/mux1_b1  (
    .i0(\AHB_Interface/n1 [1]),
    .i1(1'b0),
    .sel(read_req),
    .o(\AHB_Interface/n2 [1]));  // ../../RTL/cache/bus_unit.v(96)
  binary_mux_s1_w1 \AHB_Interface/mux1_b2  (
    .i0(\AHB_Interface/n1 [2]),
    .i1(1'b1),
    .sel(read_req),
    .o(\AHB_Interface/n2 [2]));  // ../../RTL/cache/bus_unit.v(96)
  AL_MUX \AHB_Interface/mux1_b3  (
    .i0(1'b0),
    .i1(\AHB_Interface/statu [3]),
    .sel(\AHB_Interface/mux1_b0_sel_is_0_o ),
    .o(\AHB_Interface/n2 [3]));
  binary_mux_s1_w1 \AHB_Interface/mux4_b2  (
    .i0(\AHB_Interface/statu [2]),
    .i1(1'b0),
    .sel(\AHB_Interface/n6 ),
    .o(\AHB_Interface/n7 [2]));  // ../../RTL/cache/bus_unit.v(106)
  binary_mux_s1_w1 \AHB_Interface/mux5_b0  (
    .i0(\AHB_Interface/statu [0]),
    .i1(1'b0),
    .sel(hready),
    .o(\AHB_Interface/n9 [0]));  // ../../RTL/cache/bus_unit.v(111)
  binary_mux_s1_w1 \AHB_Interface/mux5_b1  (
    .i0(\AHB_Interface/statu [1]),
    .i1(1'b0),
    .sel(hready),
    .o(\AHB_Interface/n9 [1]));  // ../../RTL/cache/bus_unit.v(111)
  binary_mux_s1_w1 \AHB_Interface/mux5_b10  (
    .i0(\AHB_Interface/statu [2]),
    .i1(1'b0),
    .sel(hready),
    .o(\AHB_Interface/n13 [2]));  // ../../RTL/cache/bus_unit.v(111)
  binary_mux_s1_w1 \AHB_Interface/mux5_b11  (
    .i0(\AHB_Interface/statu [3]),
    .i1(1'b0),
    .sel(hready),
    .o(\AHB_Interface/n13 [3]));  // ../../RTL/cache/bus_unit.v(111)
  binary_mux_s4_w1 \AHB_Interface/mux6_b0  (
    .i0(\AHB_Interface/n2 [0]),
    .i1(1'b0),
    .i10(\AHB_Interface/n8 [0]),
    .i11(\AHB_Interface/n10 [0]),
    .i12(1'b0),
    .i13(1'b0),
    .i14(1'b0),
    .i15(1'b0),
    .i2(1'b1),
    .i3(\AHB_Interface/n10 [0]),
    .i4(1'b1),
    .i5(\AHB_Interface/n10 [0]),
    .i6(1'b0),
    .i7(1'b0),
    .i8(1'b0),
    .i9(1'b0),
    .sel(\AHB_Interface/statu ),
    .o(\AHB_Interface/n15 [0]));  // ../../RTL/cache/bus_unit.v(115)
  binary_mux_s4_w1 \AHB_Interface/mux6_b1  (
    .i0(\AHB_Interface/n2 [1]),
    .i1(1'b0),
    .i10(\AHB_Interface/n8 [1]),
    .i11(\AHB_Interface/n10 [1]),
    .i12(1'b0),
    .i13(1'b0),
    .i14(1'b0),
    .i15(1'b0),
    .i2(1'b1),
    .i3(\AHB_Interface/n10 [1]),
    .i4(1'b0),
    .i5(\AHB_Interface/n10 [1]),
    .i6(1'b0),
    .i7(1'b0),
    .i8(1'b0),
    .i9(1'b1),
    .sel(\AHB_Interface/statu ),
    .o(\AHB_Interface/n15 [1]));  // ../../RTL/cache/bus_unit.v(115)
  binary_mux_s4_w1 \AHB_Interface/mux6_b2  (
    .i0(\AHB_Interface/n2 [2]),
    .i1(1'b0),
    .i10(\AHB_Interface/n8 [2]),
    .i11(\AHB_Interface/n14 [2]),
    .i12(1'b0),
    .i13(1'b0),
    .i14(1'b0),
    .i15(1'b0),
    .i2(1'b0),
    .i3(\AHB_Interface/n14 [2]),
    .i4(1'b1),
    .i5(\AHB_Interface/n14 [2]),
    .i6(1'b0),
    .i7(1'b0),
    .i8(1'b0),
    .i9(1'b0),
    .sel(\AHB_Interface/statu ),
    .o(\AHB_Interface/n15 [2]));  // ../../RTL/cache/bus_unit.v(115)
  binary_mux_s4_w1 \AHB_Interface/mux6_b3  (
    .i0(\AHB_Interface/n2 [3]),
    .i1(1'b0),
    .i10(\AHB_Interface/n8 [3]),
    .i11(\AHB_Interface/n14 [3]),
    .i12(1'b0),
    .i13(1'b0),
    .i14(1'b0),
    .i15(1'b0),
    .i2(1'b0),
    .i3(\AHB_Interface/n14 [3]),
    .i4(1'b0),
    .i5(\AHB_Interface/n14 [3]),
    .i6(1'b0),
    .i7(1'b0),
    .i8(1'b0),
    .i9(1'b1),
    .sel(\AHB_Interface/statu ),
    .o(\AHB_Interface/n15 [3]));  // ../../RTL/cache/bus_unit.v(115)
  AL_MUX \AHB_Interface/mux9_b0  (
    .i0(\AHB_Interface/addr_counter [0]),
    .i1(\AHB_Interface/n23 [0]),
    .sel(\AHB_Interface/mux9_b0_sel_is_3_o ),
    .o(\AHB_Interface/n25 [0]));
  and \AHB_Interface/mux9_b0_sel_is_3  (\AHB_Interface/mux9_b0_sel_is_3_o , \AHB_Interface/n21 , hready);
  AL_MUX \AHB_Interface/mux9_b1  (
    .i0(\AHB_Interface/addr_counter [1]),
    .i1(\AHB_Interface/n23 [1]),
    .sel(\AHB_Interface/mux9_b0_sel_is_3_o ),
    .o(\AHB_Interface/n25 [1]));
  not \AHB_Interface/n0_inv  (\AHB_Interface/n0_neg , \AHB_Interface/n0 );
  not \AHB_Interface/n6_inv  (\AHB_Interface/n6_neg , \AHB_Interface/n6 );
  reg_sr_as_w1 \AHB_Interface/reg0_b0  (
    .clk(clk),
    .d(\AHB_Interface/n26 [0]),
    .en(1'b1),
    .reset(\AHB_Interface/n18 ),
    .set(1'b0),
    .q(\AHB_Interface/addr_counter [0]));  // ../../RTL/cache/bus_unit.v(131)
  reg_sr_as_w1 \AHB_Interface/reg0_b1  (
    .clk(clk),
    .d(\AHB_Interface/n26 [1]),
    .en(1'b1),
    .reset(\AHB_Interface/n18 ),
    .set(1'b0),
    .q(\AHB_Interface/addr_counter [1]));  // ../../RTL/cache/bus_unit.v(131)
  reg_ar_as_w1 \AHB_Interface/reg2_b0  (
    .clk(clk),
    .d(\AHB_Interface/n31 [0]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(\AHB_Interface/haddr_temp [0]));  // ../../RTL/cache/bus_unit.v(149)
  reg_sr_as_w1 \AHB_Interface/reg2_b1  (
    .clk(clk),
    .d(pa_l1[1]),
    .en(1'b1),
    .reset(rst),
    .set(1'b0),
    .q(\AHB_Interface/haddr_temp [1]));  // ../../RTL/cache/bus_unit.v(149)
  reg_sr_as_w1 \AHB_Interface/reg2_b10  (
    .clk(clk),
    .d(pa_l1[10]),
    .en(1'b1),
    .reset(rst),
    .set(1'b0),
    .q(haddr[10]));  // ../../RTL/cache/bus_unit.v(149)
  reg_sr_as_w1 \AHB_Interface/reg2_b11  (
    .clk(clk),
    .d(pa_l1[11]),
    .en(1'b1),
    .reset(rst),
    .set(1'b0),
    .q(haddr[11]));  // ../../RTL/cache/bus_unit.v(149)
  reg_sr_as_w1 \AHB_Interface/reg2_b12  (
    .clk(clk),
    .d(pa_l1[12]),
    .en(1'b1),
    .reset(rst),
    .set(1'b0),
    .q(haddr[12]));  // ../../RTL/cache/bus_unit.v(149)
  reg_sr_as_w1 \AHB_Interface/reg2_b13  (
    .clk(clk),
    .d(pa_l1[13]),
    .en(1'b1),
    .reset(rst),
    .set(1'b0),
    .q(haddr[13]));  // ../../RTL/cache/bus_unit.v(149)
  reg_sr_as_w1 \AHB_Interface/reg2_b14  (
    .clk(clk),
    .d(pa_l1[14]),
    .en(1'b1),
    .reset(rst),
    .set(1'b0),
    .q(haddr[14]));  // ../../RTL/cache/bus_unit.v(149)
  reg_sr_as_w1 \AHB_Interface/reg2_b15  (
    .clk(clk),
    .d(pa_l1[15]),
    .en(1'b1),
    .reset(rst),
    .set(1'b0),
    .q(haddr[15]));  // ../../RTL/cache/bus_unit.v(149)
  reg_sr_as_w1 \AHB_Interface/reg2_b16  (
    .clk(clk),
    .d(pa_l1[16]),
    .en(1'b1),
    .reset(rst),
    .set(1'b0),
    .q(haddr[16]));  // ../../RTL/cache/bus_unit.v(149)
  reg_sr_as_w1 \AHB_Interface/reg2_b17  (
    .clk(clk),
    .d(pa_l1[17]),
    .en(1'b1),
    .reset(rst),
    .set(1'b0),
    .q(haddr[17]));  // ../../RTL/cache/bus_unit.v(149)
  reg_sr_as_w1 \AHB_Interface/reg2_b18  (
    .clk(clk),
    .d(pa_l1[18]),
    .en(1'b1),
    .reset(rst),
    .set(1'b0),
    .q(haddr[18]));  // ../../RTL/cache/bus_unit.v(149)
  reg_sr_as_w1 \AHB_Interface/reg2_b19  (
    .clk(clk),
    .d(pa_l1[19]),
    .en(1'b1),
    .reset(rst),
    .set(1'b0),
    .q(haddr[19]));  // ../../RTL/cache/bus_unit.v(149)
  reg_sr_as_w1 \AHB_Interface/reg2_b2  (
    .clk(clk),
    .d(pa_l1[2]),
    .en(1'b1),
    .reset(rst),
    .set(1'b0),
    .q(haddr[2]));  // ../../RTL/cache/bus_unit.v(149)
  reg_sr_as_w1 \AHB_Interface/reg2_b20  (
    .clk(clk),
    .d(pa_l1[20]),
    .en(1'b1),
    .reset(rst),
    .set(1'b0),
    .q(haddr[20]));  // ../../RTL/cache/bus_unit.v(149)
  reg_sr_as_w1 \AHB_Interface/reg2_b21  (
    .clk(clk),
    .d(pa_l1[21]),
    .en(1'b1),
    .reset(rst),
    .set(1'b0),
    .q(haddr[21]));  // ../../RTL/cache/bus_unit.v(149)
  reg_sr_as_w1 \AHB_Interface/reg2_b22  (
    .clk(clk),
    .d(pa_l1[22]),
    .en(1'b1),
    .reset(rst),
    .set(1'b0),
    .q(haddr[22]));  // ../../RTL/cache/bus_unit.v(149)
  reg_sr_as_w1 \AHB_Interface/reg2_b23  (
    .clk(clk),
    .d(pa_l1[23]),
    .en(1'b1),
    .reset(rst),
    .set(1'b0),
    .q(haddr[23]));  // ../../RTL/cache/bus_unit.v(149)
  reg_sr_as_w1 \AHB_Interface/reg2_b3  (
    .clk(clk),
    .d(pa_l1[3]),
    .en(1'b1),
    .reset(rst),
    .set(1'b0),
    .q(haddr[3]));  // ../../RTL/cache/bus_unit.v(149)
  reg_sr_as_w1 \AHB_Interface/reg2_b4  (
    .clk(clk),
    .d(pa_l1[4]),
    .en(1'b1),
    .reset(rst),
    .set(1'b0),
    .q(haddr[4]));  // ../../RTL/cache/bus_unit.v(149)
  reg_sr_as_w1 \AHB_Interface/reg2_b5  (
    .clk(clk),
    .d(pa_l1[5]),
    .en(1'b1),
    .reset(rst),
    .set(1'b0),
    .q(haddr[5]));  // ../../RTL/cache/bus_unit.v(149)
  reg_sr_as_w1 \AHB_Interface/reg2_b6  (
    .clk(clk),
    .d(pa_l1[6]),
    .en(1'b1),
    .reset(rst),
    .set(1'b0),
    .q(haddr[6]));  // ../../RTL/cache/bus_unit.v(149)
  reg_sr_as_w1 \AHB_Interface/reg2_b7  (
    .clk(clk),
    .d(pa_l1[7]),
    .en(1'b1),
    .reset(rst),
    .set(1'b0),
    .q(haddr[7]));  // ../../RTL/cache/bus_unit.v(149)
  reg_sr_as_w1 \AHB_Interface/reg2_b8  (
    .clk(clk),
    .d(pa_l1[8]),
    .en(1'b1),
    .reset(rst),
    .set(1'b0),
    .q(haddr[8]));  // ../../RTL/cache/bus_unit.v(149)
  reg_sr_as_w1 \AHB_Interface/reg2_b9  (
    .clk(clk),
    .d(pa_l1[9]),
    .en(1'b1),
    .reset(rst),
    .set(1'b0),
    .q(haddr[9]));  // ../../RTL/cache/bus_unit.v(149)
  reg_sr_as_w1 \AHB_Interface/reg3_b0  (
    .clk(clk),
    .d(\AHB_Interface/n15 [0]),
    .en(1'b1),
    .reset(rst),
    .set(1'b0),
    .q(\AHB_Interface/statu [0]));  // ../../RTL/cache/bus_unit.v(117)
  reg_sr_as_w1 \AHB_Interface/reg3_b1  (
    .clk(clk),
    .d(\AHB_Interface/n15 [1]),
    .en(1'b1),
    .reset(rst),
    .set(1'b0),
    .q(\AHB_Interface/statu [1]));  // ../../RTL/cache/bus_unit.v(117)
  reg_sr_as_w1 \AHB_Interface/reg3_b2  (
    .clk(clk),
    .d(\AHB_Interface/n15 [2]),
    .en(1'b1),
    .reset(rst),
    .set(1'b0),
    .q(\AHB_Interface/statu [2]));  // ../../RTL/cache/bus_unit.v(117)
  reg_sr_as_w1 \AHB_Interface/reg3_b3  (
    .clk(clk),
    .d(\AHB_Interface/n15 [3]),
    .en(1'b1),
    .reset(rst),
    .set(1'b0),
    .q(\AHB_Interface/statu [3]));  // ../../RTL/cache/bus_unit.v(117)
  or \AHB_Interface/u12  (\AHB_Interface/n18 , rst, \AHB_Interface/n17 );  // ../../RTL/cache/bus_unit.v(121)
  or \AHB_Interface/u14  (\AHB_Interface/n21 , \AHB_Interface/n19 , \AHB_Interface/n20 );  // ../../RTL/cache/bus_unit.v(128)
  or \AHB_Interface/u19  (\AHB_Interface/n0 , write_through_req[0], write_through_req[1]);  // ../../RTL/cache/bus_unit.v(93)
  and \AHB_Interface/u3  (hwrite[1], \AHB_Interface/n32 , write_through_req[1]);  // ../../RTL/cache/bus_unit.v(154)
  or \AHB_Interface/u38  (\AHB_Interface/n34 , \AHB_Interface/n32 , \AHB_Interface/n33 );  // ../../RTL/cache/bus_unit.v(155)
  AL_MUX \AHB_Interface/u42  (
    .i0(\AHB_Interface/n21 ),
    .i1(1'b0),
    .sel(\AHB_Interface/n34 ),
    .o(hburst));  // ../../RTL/cache/bus_unit.v(156)
  or \AHB_Interface/u47  (\AHB_Interface/n35 , \AHB_Interface/n34 , \AHB_Interface/n19 );  // ../../RTL/cache/bus_unit.v(157)
  or \AHB_Interface/u49  (htrans, \AHB_Interface/n35 , \AHB_Interface/n20 );  // ../../RTL/cache/bus_unit.v(157)
  and \AHB_Interface/u5  (\AHB_Interface/n6 , \AHB_Interface/n5 , hready);  // ../../RTL/cache/bus_unit.v(106)
  and \AHB_Interface/u50  (hwrite[0], \AHB_Interface/n32 , write_through_req[0]);  // ../../RTL/cache/bus_unit.v(154)
  or \AHB_Interface/u51  (\AHB_Interface/n38 , \AHB_Interface/n36 , \AHB_Interface/n37 );  // ../../RTL/cache/bus_unit.v(161)
  or \AHB_Interface/u53  (\AHB_Interface/n39 , \AHB_Interface/n38 , \AHB_Interface/n28 );  // ../../RTL/cache/bus_unit.v(161)
  AL_MUX \AHB_Interface/u54  (
    .i0(1'b0),
    .i1(hready),
    .sel(\AHB_Interface/n39 ),
    .o(trans_rdy));  // ../../RTL/cache/bus_unit.v(161)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u1  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_14 , instr[4], \GEN_PLUS_CORE$CORE/B [5]);  // ../../RTL/cpu/alu74181.v(73)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u10  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_23 , \GEN_PLUS_CORE$CORE/ALU_H4/n2 , \GEN_PLUS_CORE$CORE/A [6]);  // ../../RTL/cpu/alu74181.v(85)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u100  (\GEN_PLUS_CORE$CORE/ALU_H4/n44 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_129 , instr[6]);  // ../../RTL/cpu/alu74181.v(175)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u101  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_19 , \GEN_PLUS_CORE$CORE/ALU_H4/n44 , \GEN_PLUS_CORE$CORE/A [4]);  // ../../RTL/cpu/alu74181.v(175)
  xor \GEN_PLUS_CORE$CORE/ALU_H4/u102  (\GEN_PLUS_CORE$CORE/ALU_out [4], \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_101 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_102 );  // ../../RTL/cpu/alu74181.v(177)
  xor \GEN_PLUS_CORE$CORE/ALU_H4/u103  (\GEN_PLUS_CORE$CORE/ALU_out [5], \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_103 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_115 );  // ../../RTL/cpu/alu74181.v(179)
  xor \GEN_PLUS_CORE$CORE/ALU_H4/u104  (\GEN_PLUS_CORE$CORE/ALU_out [6], \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_105 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_116 );  // ../../RTL/cpu/alu74181.v(181)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u105  (\GEN_PLUS_CORE$CORE/ALU_H4/n45 , \GEN_PLUS_CORE$CORE/ALU_out [7], \GEN_PLUS_CORE$CORE/ALU_out [6]);  // ../../RTL/cpu/alu74181.v(183)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u106  (\GEN_PLUS_CORE$CORE/ALU_H4/n46 , \GEN_PLUS_CORE$CORE/ALU_H4/n45 , \GEN_PLUS_CORE$CORE/ALU_out [5]);  // ../../RTL/cpu/alu74181.v(183)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u107  (\GEN_PLUS_CORE$CORE/ALU_eq [1], \GEN_PLUS_CORE$CORE/ALU_H4/n46 , \GEN_PLUS_CORE$CORE/ALU_out [4]);  // ../../RTL/cpu/alu74181.v(183)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u108  (\GEN_PLUS_CORE$CORE/ALU_H4/n47 , \GEN_PLUS_CORE$CORE/A [4], instr[7]);  // ../../RTL/cpu/alu74181.v(185)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u109  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_18 , \GEN_PLUS_CORE$CORE/ALU_H4/n47 , \GEN_PLUS_CORE$CORE/B [4]);  // ../../RTL/cpu/alu74181.v(185)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u11  (\GEN_PLUS_CORE$CORE/ALU_H4/n3 , \GEN_PLUS_CORE$CORE/A [6], instr[7]);  // ../../RTL/cpu/alu74181.v(87)
  not \GEN_PLUS_CORE$CORE/ALU_H4/u110  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_128 , instr[3]);  // ../../RTL/cpu/alu74181.v(187)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u12  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_22 , \GEN_PLUS_CORE$CORE/ALU_H4/n3 , \GEN_PLUS_CORE$CORE/B [6]);  // ../../RTL/cpu/alu74181.v(87)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u13  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_26 , instr[4], \GEN_PLUS_CORE$CORE/B [7]);  // ../../RTL/cpu/alu74181.v(89)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u14  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_27 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_119 , instr[5]);  // ../../RTL/cpu/alu74181.v(91)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u15  (\GEN_PLUS_CORE$CORE/ALU_H4/n4 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_119 , instr[6]);  // ../../RTL/cpu/alu74181.v(93)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u16  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_29 , \GEN_PLUS_CORE$CORE/ALU_H4/n4 , \GEN_PLUS_CORE$CORE/A [7]);  // ../../RTL/cpu/alu74181.v(93)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u17  (\GEN_PLUS_CORE$CORE/ALU_H4/n5 , \GEN_PLUS_CORE$CORE/A [7], instr[7]);  // ../../RTL/cpu/alu74181.v(95)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u18  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_28 , \GEN_PLUS_CORE$CORE/ALU_H4/n5 , \GEN_PLUS_CORE$CORE/B [7]);  // ../../RTL/cpu/alu74181.v(95)
  not \GEN_PLUS_CORE$CORE/ALU_H4/u19  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_119 , \GEN_PLUS_CORE$CORE/B [7]);  // ../../RTL/cpu/alu74181.v(97)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u2  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_15 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_117 , instr[5]);  // ../../RTL/cpu/alu74181.v(75)
  not \GEN_PLUS_CORE$CORE/ALU_H4/u20  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_129 , \GEN_PLUS_CORE$CORE/B [4]);  // ../../RTL/cpu/alu74181.v(99)
  not \GEN_PLUS_CORE$CORE/ALU_H4/u21  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_117 , \GEN_PLUS_CORE$CORE/B [5]);  // ../../RTL/cpu/alu74181.v(101)
  not \GEN_PLUS_CORE$CORE/ALU_H4/u22  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_118 , \GEN_PLUS_CORE$CORE/B [6]);  // ../../RTL/cpu/alu74181.v(103)
  or \GEN_PLUS_CORE$CORE/ALU_H4/u23  (\GEN_PLUS_CORE$CORE/ALU_H4/n6 , \GEN_PLUS_CORE$CORE/A [4], \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_12 );  // ../../RTL/cpu/alu74181.v(105)
  or \GEN_PLUS_CORE$CORE/ALU_H4/u24  (\GEN_PLUS_CORE$CORE/ALU_H4/n7 , \GEN_PLUS_CORE$CORE/ALU_H4/n6 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_13 );  // ../../RTL/cpu/alu74181.v(105)
  not \GEN_PLUS_CORE$CORE/ALU_H4/u25  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_6 , \GEN_PLUS_CORE$CORE/ALU_H4/n7 );  // ../../RTL/cpu/alu74181.v(105)
  or \GEN_PLUS_CORE$CORE/ALU_H4/u26  (\GEN_PLUS_CORE$CORE/ALU_H4/n8 , \GEN_PLUS_CORE$CORE/A [5], \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_14 );  // ../../RTL/cpu/alu74181.v(107)
  or \GEN_PLUS_CORE$CORE/ALU_H4/u27  (\GEN_PLUS_CORE$CORE/ALU_H4/n9 , \GEN_PLUS_CORE$CORE/ALU_H4/n8 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_15 );  // ../../RTL/cpu/alu74181.v(107)
  not \GEN_PLUS_CORE$CORE/ALU_H4/u28  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_8 , \GEN_PLUS_CORE$CORE/ALU_H4/n9 );  // ../../RTL/cpu/alu74181.v(107)
  or \GEN_PLUS_CORE$CORE/ALU_H4/u29  (\GEN_PLUS_CORE$CORE/ALU_H4/n10 , \GEN_PLUS_CORE$CORE/A [6], \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_16 );  // ../../RTL/cpu/alu74181.v(109)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u3  (\GEN_PLUS_CORE$CORE/ALU_H4/n0 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_117 , instr[6]);  // ../../RTL/cpu/alu74181.v(77)
  or \GEN_PLUS_CORE$CORE/ALU_H4/u30  (\GEN_PLUS_CORE$CORE/ALU_H4/n11 , \GEN_PLUS_CORE$CORE/ALU_H4/n10 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_17 );  // ../../RTL/cpu/alu74181.v(109)
  not \GEN_PLUS_CORE$CORE/ALU_H4/u31  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_10 , \GEN_PLUS_CORE$CORE/ALU_H4/n11 );  // ../../RTL/cpu/alu74181.v(109)
  or \GEN_PLUS_CORE$CORE/ALU_H4/u32  (\GEN_PLUS_CORE$CORE/ALU_H4/n12 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_18 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_19 );  // ../../RTL/cpu/alu74181.v(111)
  not \GEN_PLUS_CORE$CORE/ALU_H4/u33  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_7 , \GEN_PLUS_CORE$CORE/ALU_H4/n12 );  // ../../RTL/cpu/alu74181.v(111)
  or \GEN_PLUS_CORE$CORE/ALU_H4/u34  (\GEN_PLUS_CORE$CORE/ALU_H4/n13 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_20 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_21 );  // ../../RTL/cpu/alu74181.v(113)
  not \GEN_PLUS_CORE$CORE/ALU_H4/u35  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_9 , \GEN_PLUS_CORE$CORE/ALU_H4/n13 );  // ../../RTL/cpu/alu74181.v(113)
  or \GEN_PLUS_CORE$CORE/ALU_H4/u36  (\GEN_PLUS_CORE$CORE/ALU_H4/n14 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_22 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_23 );  // ../../RTL/cpu/alu74181.v(115)
  not \GEN_PLUS_CORE$CORE/ALU_H4/u37  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_11 , \GEN_PLUS_CORE$CORE/ALU_H4/n14 );  // ../../RTL/cpu/alu74181.v(115)
  or \GEN_PLUS_CORE$CORE/ALU_H4/u38  (\GEN_PLUS_CORE$CORE/ALU_H4/n15 , \GEN_PLUS_CORE$CORE/A [7], \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_26 );  // ../../RTL/cpu/alu74181.v(117)
  or \GEN_PLUS_CORE$CORE/ALU_H4/u39  (\GEN_PLUS_CORE$CORE/ALU_H4/n16 , \GEN_PLUS_CORE$CORE/ALU_H4/n15 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_27 );  // ../../RTL/cpu/alu74181.v(117)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u4  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_21 , \GEN_PLUS_CORE$CORE/ALU_H4/n0 , \GEN_PLUS_CORE$CORE/A [5]);  // ../../RTL/cpu/alu74181.v(77)
  not \GEN_PLUS_CORE$CORE/ALU_H4/u40  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_25 , \GEN_PLUS_CORE$CORE/ALU_H4/n16 );  // ../../RTL/cpu/alu74181.v(117)
  or \GEN_PLUS_CORE$CORE/ALU_H4/u41  (\GEN_PLUS_CORE$CORE/ALU_H4/n17 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_28 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_29 );  // ../../RTL/cpu/alu74181.v(119)
  not \GEN_PLUS_CORE$CORE/ALU_H4/u42  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_24 , \GEN_PLUS_CORE$CORE/ALU_H4/n17 );  // ../../RTL/cpu/alu74181.v(119)
  xor \GEN_PLUS_CORE$CORE/ALU_H4/u43  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_101 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_7 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_6 );  // ../../RTL/cpu/alu74181.v(121)
  xor \GEN_PLUS_CORE$CORE/ALU_H4/u44  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_103 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_9 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_8 );  // ../../RTL/cpu/alu74181.v(123)
  xor \GEN_PLUS_CORE$CORE/ALU_H4/u45  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_105 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_11 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_10 );  // ../../RTL/cpu/alu74181.v(125)
  xor \GEN_PLUS_CORE$CORE/ALU_H4/u46  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_94 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_24 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_25 );  // ../../RTL/cpu/alu74181.v(127)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u47  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_56 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_24 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_10 );  // ../../RTL/cpu/alu74181.v(129)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u48  (\GEN_PLUS_CORE$CORE/ALU_H4/n18 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_8 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_11 );  // ../../RTL/cpu/alu74181.v(131)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u49  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_57 , \GEN_PLUS_CORE$CORE/ALU_H4/n18 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_24 );  // ../../RTL/cpu/alu74181.v(131)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u5  (\GEN_PLUS_CORE$CORE/ALU_H4/n1 , \GEN_PLUS_CORE$CORE/A [5], instr[7]);  // ../../RTL/cpu/alu74181.v(79)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u50  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_12 , instr[4], \GEN_PLUS_CORE$CORE/B [4]);  // ../../RTL/cpu/alu74181.v(133)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u51  (\GEN_PLUS_CORE$CORE/ALU_H4/n19 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_24 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_11 );  // ../../RTL/cpu/alu74181.v(135)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u52  (\GEN_PLUS_CORE$CORE/ALU_H4/n20 , \GEN_PLUS_CORE$CORE/ALU_H4/n19 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_9 );  // ../../RTL/cpu/alu74181.v(135)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u55  (\GEN_PLUS_CORE$CORE/ALU_H4/n22 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_11 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_9 );  // ../../RTL/cpu/alu74181.v(137)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u56  (\GEN_PLUS_CORE$CORE/ALU_H4/n23 , \GEN_PLUS_CORE$CORE/ALU_H4/n22 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_7 );  // ../../RTL/cpu/alu74181.v(137)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u57  (\GEN_PLUS_CORE$CORE/ALU_H4/n24 , \GEN_PLUS_CORE$CORE/ALU_H4/n23 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_24 );  // ../../RTL/cpu/alu74181.v(137)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u58  (\GEN_PLUS_CORE$CORE/ALU_H4/n25 , \GEN_PLUS_CORE$CORE/ALU_H4/n24 , \GEN_PLUS_CORE$CORE/ALU_C1 );  // ../../RTL/cpu/alu74181.v(137)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u59  (\GEN_PLUS_CORE$CORE/ALU_H4/n26 , \GEN_PLUS_CORE$CORE/ALU_H4/n25 , \GEN_PLUS_CORE$CORE/ALU_C1 );  // ../../RTL/cpu/alu74181.v(137)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u6  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_20 , \GEN_PLUS_CORE$CORE/ALU_H4/n1 , \GEN_PLUS_CORE$CORE/B [5]);  // ../../RTL/cpu/alu74181.v(79)
  not \GEN_PLUS_CORE$CORE/ALU_H4/u60  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_97 , \GEN_PLUS_CORE$CORE/ALU_H4/n26 );  // ../../RTL/cpu/alu74181.v(137)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u61  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_58 , \GEN_PLUS_CORE$CORE/ALU_H4/n20 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_6 );  // ../../RTL/cpu/alu74181.v(139)
  or \GEN_PLUS_CORE$CORE/ALU_H4/u62  (\GEN_PLUS_CORE$CORE/ALU_H4/n27 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_25 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_56 );  // ../../RTL/cpu/alu74181.v(141)
  or \GEN_PLUS_CORE$CORE/ALU_H4/u63  (\GEN_PLUS_CORE$CORE/ALU_H4/n28 , \GEN_PLUS_CORE$CORE/ALU_H4/n27 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_57 );  // ../../RTL/cpu/alu74181.v(141)
  or \GEN_PLUS_CORE$CORE/ALU_H4/u64  (\GEN_PLUS_CORE$CORE/ALU_H4/n29 , \GEN_PLUS_CORE$CORE/ALU_H4/n28 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_58 );  // ../../RTL/cpu/alu74181.v(141)
  not \GEN_PLUS_CORE$CORE/ALU_H4/u65  (\GEN_PLUS_CORE$CORE/ALU_H4/g , \GEN_PLUS_CORE$CORE/ALU_H4/n29 );  // ../../RTL/cpu/alu74181.v(141)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u66  (\GEN_PLUS_CORE$CORE/ALU_H4/n30 , \GEN_PLUS_CORE$CORE/ALU_C1 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(143)
  not \GEN_PLUS_CORE$CORE/ALU_H4/u67  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_102 , \GEN_PLUS_CORE$CORE/ALU_H4/n30 );  // ../../RTL/cpu/alu74181.v(143)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u68  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_99 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_6 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(145)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u69  (\GEN_PLUS_CORE$CORE/ALU_H4/n31 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_128 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_7 );  // ../../RTL/cpu/alu74181.v(147)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u7  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_16 , instr[4], \GEN_PLUS_CORE$CORE/B [6]);  // ../../RTL/cpu/alu74181.v(81)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u70  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_98 , \GEN_PLUS_CORE$CORE/ALU_H4/n31 , \GEN_PLUS_CORE$CORE/ALU_C1 );  // ../../RTL/cpu/alu74181.v(147)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u71  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_90 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_8 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(149)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u72  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_91 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_99 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_9 );  // ../../RTL/cpu/alu74181.v(151)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u73  (\GEN_PLUS_CORE$CORE/ALU_H4/n32 , \GEN_PLUS_CORE$CORE/ALU_C1 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_7 );  // ../../RTL/cpu/alu74181.v(153)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u74  (\GEN_PLUS_CORE$CORE/ALU_H4/n33 , \GEN_PLUS_CORE$CORE/ALU_H4/n32 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_9 );  // ../../RTL/cpu/alu74181.v(153)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u75  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_92 , \GEN_PLUS_CORE$CORE/ALU_H4/n33 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(153)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u76  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_13 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_129 , instr[5]);  // ../../RTL/cpu/alu74181.v(155)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u77  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_89 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_10 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(157)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u79  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_88 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_90 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_11 );  // ../../RTL/cpu/alu74181.v(159)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u8  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_17 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_118 , instr[5]);  // ../../RTL/cpu/alu74181.v(83)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u81  (\GEN_PLUS_CORE$CORE/ALU_H4/n34 , \GEN_PLUS_CORE$CORE/ALU_H4/n22 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_6 );  // ../../RTL/cpu/alu74181.v(161)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u82  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_87 , \GEN_PLUS_CORE$CORE/ALU_H4/n34 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(161)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u85  (\GEN_PLUS_CORE$CORE/ALU_H4/n35 , \GEN_PLUS_CORE$CORE/ALU_H4/n33 , \GEN_PLUS_CORE$CORE/ALU_C1 );  // ../../RTL/cpu/alu74181.v(163)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u86  (\GEN_PLUS_CORE$CORE/ALU_H4/n36 , \GEN_PLUS_CORE$CORE/ALU_H4/n35 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_11 );  // ../../RTL/cpu/alu74181.v(163)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u87  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_86 , \GEN_PLUS_CORE$CORE/ALU_H4/n36 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(163)
  or \GEN_PLUS_CORE$CORE/ALU_H4/u88  (\GEN_PLUS_CORE$CORE/ALU_H4/n37 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_86 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_87 );  // ../../RTL/cpu/alu74181.v(165)
  or \GEN_PLUS_CORE$CORE/ALU_H4/u89  (\GEN_PLUS_CORE$CORE/ALU_H4/n38 , \GEN_PLUS_CORE$CORE/ALU_H4/n37 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_88 );  // ../../RTL/cpu/alu74181.v(165)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u9  (\GEN_PLUS_CORE$CORE/ALU_H4/n2 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_118 , instr[6]);  // ../../RTL/cpu/alu74181.v(85)
  or \GEN_PLUS_CORE$CORE/ALU_H4/u90  (\GEN_PLUS_CORE$CORE/ALU_H4/n39 , \GEN_PLUS_CORE$CORE/ALU_H4/n38 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_89 );  // ../../RTL/cpu/alu74181.v(165)
  not \GEN_PLUS_CORE$CORE/ALU_H4/u91  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_93 , \GEN_PLUS_CORE$CORE/ALU_H4/n39 );  // ../../RTL/cpu/alu74181.v(165)
  or \GEN_PLUS_CORE$CORE/ALU_H4/u92  (\GEN_PLUS_CORE$CORE/ALU_H4/n40 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_90 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_91 );  // ../../RTL/cpu/alu74181.v(167)
  or \GEN_PLUS_CORE$CORE/ALU_H4/u93  (\GEN_PLUS_CORE$CORE/ALU_H4/n41 , \GEN_PLUS_CORE$CORE/ALU_H4/n40 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_92 );  // ../../RTL/cpu/alu74181.v(167)
  not \GEN_PLUS_CORE$CORE/ALU_H4/u94  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_116 , \GEN_PLUS_CORE$CORE/ALU_H4/n41 );  // ../../RTL/cpu/alu74181.v(167)
  xor \GEN_PLUS_CORE$CORE/ALU_H4/u95  (\GEN_PLUS_CORE$CORE/ALU_out [7], \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_94 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_93 );  // ../../RTL/cpu/alu74181.v(169)
  and \GEN_PLUS_CORE$CORE/ALU_H4/u96  (\GEN_PLUS_CORE$CORE/ALU_H4/n42 , \GEN_PLUS_CORE$CORE/ALU_H4/g , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_97 );  // ../../RTL/cpu/alu74181.v(171)
  or \GEN_PLUS_CORE$CORE/ALU_H4/u98  (\GEN_PLUS_CORE$CORE/ALU_H4/n43 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_98 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_99 );  // ../../RTL/cpu/alu74181.v(173)
  not \GEN_PLUS_CORE$CORE/ALU_H4/u99  (\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_115 , \GEN_PLUS_CORE$CORE/ALU_H4/n43 );  // ../../RTL/cpu/alu74181.v(173)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u1  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_14 , instr[4], \GEN_PLUS_CORE$CORE/B [1]);  // ../../RTL/cpu/alu74181.v(73)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u10  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_23 , \GEN_PLUS_CORE$CORE/ALU_L4/n2 , \GEN_PLUS_CORE$CORE/A [2]);  // ../../RTL/cpu/alu74181.v(85)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u100  (\GEN_PLUS_CORE$CORE/ALU_L4/n44 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_129 , instr[6]);  // ../../RTL/cpu/alu74181.v(175)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u101  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_19 , \GEN_PLUS_CORE$CORE/ALU_L4/n44 , \GEN_PLUS_CORE$CORE/A [0]);  // ../../RTL/cpu/alu74181.v(175)
  xor \GEN_PLUS_CORE$CORE/ALU_L4/u102  (\GEN_PLUS_CORE$CORE/ALU_out [0], \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_101 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_102 );  // ../../RTL/cpu/alu74181.v(177)
  xor \GEN_PLUS_CORE$CORE/ALU_L4/u103  (\GEN_PLUS_CORE$CORE/ALU_out [1], \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_103 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_115 );  // ../../RTL/cpu/alu74181.v(179)
  xor \GEN_PLUS_CORE$CORE/ALU_L4/u104  (\GEN_PLUS_CORE$CORE/ALU_out [2], \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_105 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_116 );  // ../../RTL/cpu/alu74181.v(181)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u105  (\GEN_PLUS_CORE$CORE/ALU_L4/n45 , \GEN_PLUS_CORE$CORE/ALU_out [3], \GEN_PLUS_CORE$CORE/ALU_out [2]);  // ../../RTL/cpu/alu74181.v(183)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u106  (\GEN_PLUS_CORE$CORE/ALU_L4/n46 , \GEN_PLUS_CORE$CORE/ALU_L4/n45 , \GEN_PLUS_CORE$CORE/ALU_out [1]);  // ../../RTL/cpu/alu74181.v(183)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u107  (\GEN_PLUS_CORE$CORE/ALU_eq [0], \GEN_PLUS_CORE$CORE/ALU_L4/n46 , \GEN_PLUS_CORE$CORE/ALU_out [0]);  // ../../RTL/cpu/alu74181.v(183)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u108  (\GEN_PLUS_CORE$CORE/ALU_L4/n47 , \GEN_PLUS_CORE$CORE/A [0], instr[7]);  // ../../RTL/cpu/alu74181.v(185)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u109  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_18 , \GEN_PLUS_CORE$CORE/ALU_L4/n47 , \GEN_PLUS_CORE$CORE/B [0]);  // ../../RTL/cpu/alu74181.v(185)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u11  (\GEN_PLUS_CORE$CORE/ALU_L4/n3 , \GEN_PLUS_CORE$CORE/A [2], instr[7]);  // ../../RTL/cpu/alu74181.v(87)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u12  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_22 , \GEN_PLUS_CORE$CORE/ALU_L4/n3 , \GEN_PLUS_CORE$CORE/B [2]);  // ../../RTL/cpu/alu74181.v(87)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u13  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_26 , instr[4], \GEN_PLUS_CORE$CORE/B [3]);  // ../../RTL/cpu/alu74181.v(89)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u14  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_27 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_119 , instr[5]);  // ../../RTL/cpu/alu74181.v(91)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u15  (\GEN_PLUS_CORE$CORE/ALU_L4/n4 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_119 , instr[6]);  // ../../RTL/cpu/alu74181.v(93)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u16  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_29 , \GEN_PLUS_CORE$CORE/ALU_L4/n4 , \GEN_PLUS_CORE$CORE/A [3]);  // ../../RTL/cpu/alu74181.v(93)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u17  (\GEN_PLUS_CORE$CORE/ALU_L4/n5 , \GEN_PLUS_CORE$CORE/A [3], instr[7]);  // ../../RTL/cpu/alu74181.v(95)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u18  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_28 , \GEN_PLUS_CORE$CORE/ALU_L4/n5 , \GEN_PLUS_CORE$CORE/B [3]);  // ../../RTL/cpu/alu74181.v(95)
  not \GEN_PLUS_CORE$CORE/ALU_L4/u19  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_119 , \GEN_PLUS_CORE$CORE/B [3]);  // ../../RTL/cpu/alu74181.v(97)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u2  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_15 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_117 , instr[5]);  // ../../RTL/cpu/alu74181.v(75)
  not \GEN_PLUS_CORE$CORE/ALU_L4/u20  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_129 , \GEN_PLUS_CORE$CORE/B [0]);  // ../../RTL/cpu/alu74181.v(99)
  not \GEN_PLUS_CORE$CORE/ALU_L4/u21  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_117 , \GEN_PLUS_CORE$CORE/B [1]);  // ../../RTL/cpu/alu74181.v(101)
  not \GEN_PLUS_CORE$CORE/ALU_L4/u22  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_118 , \GEN_PLUS_CORE$CORE/B [2]);  // ../../RTL/cpu/alu74181.v(103)
  or \GEN_PLUS_CORE$CORE/ALU_L4/u23  (\GEN_PLUS_CORE$CORE/ALU_L4/n6 , \GEN_PLUS_CORE$CORE/A [0], \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_12 );  // ../../RTL/cpu/alu74181.v(105)
  or \GEN_PLUS_CORE$CORE/ALU_L4/u24  (\GEN_PLUS_CORE$CORE/ALU_L4/n7 , \GEN_PLUS_CORE$CORE/ALU_L4/n6 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_13 );  // ../../RTL/cpu/alu74181.v(105)
  not \GEN_PLUS_CORE$CORE/ALU_L4/u25  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_6 , \GEN_PLUS_CORE$CORE/ALU_L4/n7 );  // ../../RTL/cpu/alu74181.v(105)
  or \GEN_PLUS_CORE$CORE/ALU_L4/u26  (\GEN_PLUS_CORE$CORE/ALU_L4/n8 , \GEN_PLUS_CORE$CORE/A [1], \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_14 );  // ../../RTL/cpu/alu74181.v(107)
  or \GEN_PLUS_CORE$CORE/ALU_L4/u27  (\GEN_PLUS_CORE$CORE/ALU_L4/n9 , \GEN_PLUS_CORE$CORE/ALU_L4/n8 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_15 );  // ../../RTL/cpu/alu74181.v(107)
  not \GEN_PLUS_CORE$CORE/ALU_L4/u28  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_8 , \GEN_PLUS_CORE$CORE/ALU_L4/n9 );  // ../../RTL/cpu/alu74181.v(107)
  or \GEN_PLUS_CORE$CORE/ALU_L4/u29  (\GEN_PLUS_CORE$CORE/ALU_L4/n10 , \GEN_PLUS_CORE$CORE/A [2], \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_16 );  // ../../RTL/cpu/alu74181.v(109)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u3  (\GEN_PLUS_CORE$CORE/ALU_L4/n0 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_117 , instr[6]);  // ../../RTL/cpu/alu74181.v(77)
  or \GEN_PLUS_CORE$CORE/ALU_L4/u30  (\GEN_PLUS_CORE$CORE/ALU_L4/n11 , \GEN_PLUS_CORE$CORE/ALU_L4/n10 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_17 );  // ../../RTL/cpu/alu74181.v(109)
  not \GEN_PLUS_CORE$CORE/ALU_L4/u31  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_10 , \GEN_PLUS_CORE$CORE/ALU_L4/n11 );  // ../../RTL/cpu/alu74181.v(109)
  or \GEN_PLUS_CORE$CORE/ALU_L4/u32  (\GEN_PLUS_CORE$CORE/ALU_L4/n12 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_18 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_19 );  // ../../RTL/cpu/alu74181.v(111)
  not \GEN_PLUS_CORE$CORE/ALU_L4/u33  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_7 , \GEN_PLUS_CORE$CORE/ALU_L4/n12 );  // ../../RTL/cpu/alu74181.v(111)
  or \GEN_PLUS_CORE$CORE/ALU_L4/u34  (\GEN_PLUS_CORE$CORE/ALU_L4/n13 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_20 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_21 );  // ../../RTL/cpu/alu74181.v(113)
  not \GEN_PLUS_CORE$CORE/ALU_L4/u35  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_9 , \GEN_PLUS_CORE$CORE/ALU_L4/n13 );  // ../../RTL/cpu/alu74181.v(113)
  or \GEN_PLUS_CORE$CORE/ALU_L4/u36  (\GEN_PLUS_CORE$CORE/ALU_L4/n14 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_22 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_23 );  // ../../RTL/cpu/alu74181.v(115)
  not \GEN_PLUS_CORE$CORE/ALU_L4/u37  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_11 , \GEN_PLUS_CORE$CORE/ALU_L4/n14 );  // ../../RTL/cpu/alu74181.v(115)
  or \GEN_PLUS_CORE$CORE/ALU_L4/u38  (\GEN_PLUS_CORE$CORE/ALU_L4/n15 , \GEN_PLUS_CORE$CORE/A [3], \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_26 );  // ../../RTL/cpu/alu74181.v(117)
  or \GEN_PLUS_CORE$CORE/ALU_L4/u39  (\GEN_PLUS_CORE$CORE/ALU_L4/n16 , \GEN_PLUS_CORE$CORE/ALU_L4/n15 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_27 );  // ../../RTL/cpu/alu74181.v(117)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u4  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_21 , \GEN_PLUS_CORE$CORE/ALU_L4/n0 , \GEN_PLUS_CORE$CORE/A [1]);  // ../../RTL/cpu/alu74181.v(77)
  not \GEN_PLUS_CORE$CORE/ALU_L4/u40  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_25 , \GEN_PLUS_CORE$CORE/ALU_L4/n16 );  // ../../RTL/cpu/alu74181.v(117)
  or \GEN_PLUS_CORE$CORE/ALU_L4/u41  (\GEN_PLUS_CORE$CORE/ALU_L4/n17 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_28 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_29 );  // ../../RTL/cpu/alu74181.v(119)
  not \GEN_PLUS_CORE$CORE/ALU_L4/u42  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_24 , \GEN_PLUS_CORE$CORE/ALU_L4/n17 );  // ../../RTL/cpu/alu74181.v(119)
  xor \GEN_PLUS_CORE$CORE/ALU_L4/u43  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_101 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_7 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_6 );  // ../../RTL/cpu/alu74181.v(121)
  xor \GEN_PLUS_CORE$CORE/ALU_L4/u44  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_103 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_9 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_8 );  // ../../RTL/cpu/alu74181.v(123)
  xor \GEN_PLUS_CORE$CORE/ALU_L4/u45  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_105 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_11 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_10 );  // ../../RTL/cpu/alu74181.v(125)
  xor \GEN_PLUS_CORE$CORE/ALU_L4/u46  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_94 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_24 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_25 );  // ../../RTL/cpu/alu74181.v(127)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u47  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_56 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_24 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_10 );  // ../../RTL/cpu/alu74181.v(129)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u48  (\GEN_PLUS_CORE$CORE/ALU_L4/n18 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_8 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_11 );  // ../../RTL/cpu/alu74181.v(131)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u49  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_57 , \GEN_PLUS_CORE$CORE/ALU_L4/n18 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_24 );  // ../../RTL/cpu/alu74181.v(131)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u5  (\GEN_PLUS_CORE$CORE/ALU_L4/n1 , \GEN_PLUS_CORE$CORE/A [1], instr[7]);  // ../../RTL/cpu/alu74181.v(79)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u50  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_12 , instr[4], \GEN_PLUS_CORE$CORE/B [0]);  // ../../RTL/cpu/alu74181.v(133)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u51  (\GEN_PLUS_CORE$CORE/ALU_L4/n19 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_24 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_11 );  // ../../RTL/cpu/alu74181.v(135)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u52  (\GEN_PLUS_CORE$CORE/ALU_L4/n20 , \GEN_PLUS_CORE$CORE/ALU_L4/n19 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_9 );  // ../../RTL/cpu/alu74181.v(135)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u55  (\GEN_PLUS_CORE$CORE/ALU_L4/n22 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_11 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_9 );  // ../../RTL/cpu/alu74181.v(137)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u56  (\GEN_PLUS_CORE$CORE/ALU_L4/n23 , \GEN_PLUS_CORE$CORE/ALU_L4/n22 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_7 );  // ../../RTL/cpu/alu74181.v(137)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u57  (\GEN_PLUS_CORE$CORE/ALU_L4/n24 , \GEN_PLUS_CORE$CORE/ALU_L4/n23 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_24 );  // ../../RTL/cpu/alu74181.v(137)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u58  (\GEN_PLUS_CORE$CORE/ALU_L4/n25 , \GEN_PLUS_CORE$CORE/ALU_L4/n24 , instr[2]);  // ../../RTL/cpu/alu74181.v(137)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u59  (\GEN_PLUS_CORE$CORE/ALU_L4/n26 , \GEN_PLUS_CORE$CORE/ALU_L4/n25 , instr[2]);  // ../../RTL/cpu/alu74181.v(137)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u6  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_20 , \GEN_PLUS_CORE$CORE/ALU_L4/n1 , \GEN_PLUS_CORE$CORE/B [1]);  // ../../RTL/cpu/alu74181.v(79)
  not \GEN_PLUS_CORE$CORE/ALU_L4/u60  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_97 , \GEN_PLUS_CORE$CORE/ALU_L4/n26 );  // ../../RTL/cpu/alu74181.v(137)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u61  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_58 , \GEN_PLUS_CORE$CORE/ALU_L4/n20 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_6 );  // ../../RTL/cpu/alu74181.v(139)
  or \GEN_PLUS_CORE$CORE/ALU_L4/u62  (\GEN_PLUS_CORE$CORE/ALU_L4/n27 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_25 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_56 );  // ../../RTL/cpu/alu74181.v(141)
  or \GEN_PLUS_CORE$CORE/ALU_L4/u63  (\GEN_PLUS_CORE$CORE/ALU_L4/n28 , \GEN_PLUS_CORE$CORE/ALU_L4/n27 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_57 );  // ../../RTL/cpu/alu74181.v(141)
  or \GEN_PLUS_CORE$CORE/ALU_L4/u64  (\GEN_PLUS_CORE$CORE/ALU_L4/n29 , \GEN_PLUS_CORE$CORE/ALU_L4/n28 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_58 );  // ../../RTL/cpu/alu74181.v(141)
  not \GEN_PLUS_CORE$CORE/ALU_L4/u65  (\GEN_PLUS_CORE$CORE/ALU_L4/g , \GEN_PLUS_CORE$CORE/ALU_L4/n29 );  // ../../RTL/cpu/alu74181.v(141)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u66  (\GEN_PLUS_CORE$CORE/ALU_L4/n30 , instr[2], \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(143)
  not \GEN_PLUS_CORE$CORE/ALU_L4/u67  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_102 , \GEN_PLUS_CORE$CORE/ALU_L4/n30 );  // ../../RTL/cpu/alu74181.v(143)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u68  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_99 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_6 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(145)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u69  (\GEN_PLUS_CORE$CORE/ALU_L4/n31 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_128 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_7 );  // ../../RTL/cpu/alu74181.v(147)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u7  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_16 , instr[4], \GEN_PLUS_CORE$CORE/B [2]);  // ../../RTL/cpu/alu74181.v(81)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u70  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_98 , \GEN_PLUS_CORE$CORE/ALU_L4/n31 , instr[2]);  // ../../RTL/cpu/alu74181.v(147)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u71  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_90 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_8 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(149)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u72  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_91 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_99 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_9 );  // ../../RTL/cpu/alu74181.v(151)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u73  (\GEN_PLUS_CORE$CORE/ALU_L4/n32 , instr[2], \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_7 );  // ../../RTL/cpu/alu74181.v(153)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u74  (\GEN_PLUS_CORE$CORE/ALU_L4/n33 , \GEN_PLUS_CORE$CORE/ALU_L4/n32 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_9 );  // ../../RTL/cpu/alu74181.v(153)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u75  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_92 , \GEN_PLUS_CORE$CORE/ALU_L4/n33 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(153)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u76  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_13 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_129 , instr[5]);  // ../../RTL/cpu/alu74181.v(155)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u77  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_89 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_10 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(157)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u79  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_88 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_90 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_11 );  // ../../RTL/cpu/alu74181.v(159)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u8  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_17 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_118 , instr[5]);  // ../../RTL/cpu/alu74181.v(83)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u81  (\GEN_PLUS_CORE$CORE/ALU_L4/n34 , \GEN_PLUS_CORE$CORE/ALU_L4/n22 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_6 );  // ../../RTL/cpu/alu74181.v(161)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u82  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_87 , \GEN_PLUS_CORE$CORE/ALU_L4/n34 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(161)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u85  (\GEN_PLUS_CORE$CORE/ALU_L4/n35 , \GEN_PLUS_CORE$CORE/ALU_L4/n33 , instr[2]);  // ../../RTL/cpu/alu74181.v(163)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u86  (\GEN_PLUS_CORE$CORE/ALU_L4/n36 , \GEN_PLUS_CORE$CORE/ALU_L4/n35 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_11 );  // ../../RTL/cpu/alu74181.v(163)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u87  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_86 , \GEN_PLUS_CORE$CORE/ALU_L4/n36 , \GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(163)
  or \GEN_PLUS_CORE$CORE/ALU_L4/u88  (\GEN_PLUS_CORE$CORE/ALU_L4/n37 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_86 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_87 );  // ../../RTL/cpu/alu74181.v(165)
  or \GEN_PLUS_CORE$CORE/ALU_L4/u89  (\GEN_PLUS_CORE$CORE/ALU_L4/n38 , \GEN_PLUS_CORE$CORE/ALU_L4/n37 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_88 );  // ../../RTL/cpu/alu74181.v(165)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u9  (\GEN_PLUS_CORE$CORE/ALU_L4/n2 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_118 , instr[6]);  // ../../RTL/cpu/alu74181.v(85)
  or \GEN_PLUS_CORE$CORE/ALU_L4/u90  (\GEN_PLUS_CORE$CORE/ALU_L4/n39 , \GEN_PLUS_CORE$CORE/ALU_L4/n38 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_89 );  // ../../RTL/cpu/alu74181.v(165)
  not \GEN_PLUS_CORE$CORE/ALU_L4/u91  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_93 , \GEN_PLUS_CORE$CORE/ALU_L4/n39 );  // ../../RTL/cpu/alu74181.v(165)
  or \GEN_PLUS_CORE$CORE/ALU_L4/u92  (\GEN_PLUS_CORE$CORE/ALU_L4/n40 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_90 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_91 );  // ../../RTL/cpu/alu74181.v(167)
  or \GEN_PLUS_CORE$CORE/ALU_L4/u93  (\GEN_PLUS_CORE$CORE/ALU_L4/n41 , \GEN_PLUS_CORE$CORE/ALU_L4/n40 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_92 );  // ../../RTL/cpu/alu74181.v(167)
  not \GEN_PLUS_CORE$CORE/ALU_L4/u94  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_116 , \GEN_PLUS_CORE$CORE/ALU_L4/n41 );  // ../../RTL/cpu/alu74181.v(167)
  xor \GEN_PLUS_CORE$CORE/ALU_L4/u95  (\GEN_PLUS_CORE$CORE/ALU_out [3], \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_94 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_93 );  // ../../RTL/cpu/alu74181.v(169)
  and \GEN_PLUS_CORE$CORE/ALU_L4/u96  (\GEN_PLUS_CORE$CORE/ALU_L4/n42 , \GEN_PLUS_CORE$CORE/ALU_L4/g , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_97 );  // ../../RTL/cpu/alu74181.v(171)
  not \GEN_PLUS_CORE$CORE/ALU_L4/u97  (\GEN_PLUS_CORE$CORE/ALU_C1 , \GEN_PLUS_CORE$CORE/ALU_L4/n42 );  // ../../RTL/cpu/alu74181.v(171)
  or \GEN_PLUS_CORE$CORE/ALU_L4/u98  (\GEN_PLUS_CORE$CORE/ALU_L4/n43 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_98 , \GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_99 );  // ../../RTL/cpu/alu74181.v(173)
  not \GEN_PLUS_CORE$CORE/ALU_L4/u99  (\GEN_PLUS_CORE$CORE/ALU_L4/SYNTHESIZED_WIRE_115 , \GEN_PLUS_CORE$CORE/ALU_L4/n43 );  // ../../RTL/cpu/alu74181.v(173)
  not \GEN_PLUS_CORE$CORE/INSTR_HOLD_inv  (\GEN_PLUS_CORE$CORE/INSTR_HOLD_neg , \GEN_PLUS_CORE$CORE/INSTR_HOLD );
  add_pu23_pu23_o23 \GEN_PLUS_CORE$CORE/add0  (
    .i0(iaddr[22:0]),
    .i1(23'b00000000000000000000001),
    .o(\GEN_PLUS_CORE$CORE/PCP1 [22:0]));  // ../../RTL/cpu/KC_LS1u_plus.v(43)
  eq_w3 \GEN_PLUS_CORE$CORE/eq0  (
    .i0(instr[10:8]),
    .i1(3'b111),
    .o(\GEN_PLUS_CORE$CORE/n1 ));  // ../../RTL/cpu/KC_LS1u_plus.v(40)
  eq_w5 \GEN_PLUS_CORE$CORE/eq1  (
    .i0(instr[15:11]),
    .i1(5'b01000),
    .o(XCRwe));  // ../../RTL/cpu/KC_LS1u_plus.v(156)
  eq_w5 \GEN_PLUS_CORE$CORE/eq10  (
    .i0(instr[15:11]),
    .i1(5'b10000),
    .o(\GEN_PLUS_CORE$CORE/n73 ));  // ../../RTL/cpu/KC_LS1u_plus.v(185)
  eq_w5 \GEN_PLUS_CORE$CORE/eq11  (
    .i0(instr[15:11]),
    .i1(5'b10010),
    .o(\GEN_PLUS_CORE$CORE/n74 ));  // ../../RTL/cpu/KC_LS1u_plus.v(187)
  eq_w5 \GEN_PLUS_CORE$CORE/eq12  (
    .i0(instr[15:11]),
    .i1(5'b10100),
    .o(\GEN_PLUS_CORE$CORE/n75 ));  // ../../RTL/cpu/KC_LS1u_plus.v(189)
  eq_w5 \GEN_PLUS_CORE$CORE/eq13  (
    .i0(instr[15:11]),
    .i1(5'b10110),
    .o(\GEN_PLUS_CORE$CORE/n76 ));  // ../../RTL/cpu/KC_LS1u_plus.v(191)
  eq_w5 \GEN_PLUS_CORE$CORE/eq14  (
    .i0(instr[15:11]),
    .i1(5'b11000),
    .o(\GEN_PLUS_CORE$CORE/n77 ));  // ../../RTL/cpu/KC_LS1u_plus.v(193)
  eq_w5 \GEN_PLUS_CORE$CORE/eq15  (
    .i0(instr[15:11]),
    .i1(5'b11010),
    .o(\GEN_PLUS_CORE$CORE/n78 ));  // ../../RTL/cpu/KC_LS1u_plus.v(195)
  eq_w5 \GEN_PLUS_CORE$CORE/eq16  (
    .i0(instr[15:11]),
    .i1(5'b11100),
    .o(\GEN_PLUS_CORE$CORE/n79 ));  // ../../RTL/cpu/KC_LS1u_plus.v(197)
  eq_w5 \GEN_PLUS_CORE$CORE/eq2  (
    .i0(instr[15:11]),
    .i1(5'b00001),
    .o(\GEN_PLUS_CORE$CORE/jmp_en ));  // ../../RTL/cpu/KC_LS1u_plus.v(158)
  eq_w3 \GEN_PLUS_CORE$CORE/eq25  (
    .i0(instr[10:8]),
    .i1(3'b000),
    .o(\GEN_PLUS_CORE$CORE/n91 ));  // ../../RTL/cpu/KC_LS1u_plus.v(274)
  eq_w4 \GEN_PLUS_CORE$CORE/eq26  (
    .i0(\GEN_PLUS_CORE$CORE/dbsrc_addr ),
    .i1(4'b0000),
    .o(\GEN_PLUS_CORE$CORE/n97 ));  // ../../RTL/cpu/KC_LS1u_plus.v(297)
  eq_w4 \GEN_PLUS_CORE$CORE/eq27  (
    .i0(\GEN_PLUS_CORE$CORE/dbsrc_addr ),
    .i1(4'b0001),
    .o(\GEN_PLUS_CORE$CORE/n98 ));  // ../../RTL/cpu/KC_LS1u_plus.v(298)
  eq_w4 \GEN_PLUS_CORE$CORE/eq28  (
    .i0(\GEN_PLUS_CORE$CORE/dbsrc_addr ),
    .i1(4'b0010),
    .o(dread));  // ../../RTL/cpu/KC_LS1u_plus.v(299)
  eq_w4 \GEN_PLUS_CORE$CORE/eq29  (
    .i0(\GEN_PLUS_CORE$CORE/dbsrc_addr ),
    .i1(4'b0011),
    .o(\GEN_PLUS_CORE$CORE/n100 ));  // ../../RTL/cpu/KC_LS1u_plus.v(300)
  eq_w5 \GEN_PLUS_CORE$CORE/eq3  (
    .i0(instr[15:11]),
    .i1(5'b00111),
    .o(\GEN_PLUS_CORE$CORE/n66 ));  // ../../RTL/cpu/KC_LS1u_plus.v(162)
  eq_w4 \GEN_PLUS_CORE$CORE/eq30  (
    .i0(\GEN_PLUS_CORE$CORE/dbsrc_addr ),
    .i1(4'b0101),
    .o(\GEN_PLUS_CORE$CORE/n101 ));  // ../../RTL/cpu/KC_LS1u_plus.v(302)
  eq_w4 \GEN_PLUS_CORE$CORE/eq31  (
    .i0(\GEN_PLUS_CORE$CORE/dbsrc_addr ),
    .i1(4'b0111),
    .o(\GEN_PLUS_CORE$CORE/n102 ));  // ../../RTL/cpu/KC_LS1u_plus.v(303)
  eq_w5 \GEN_PLUS_CORE$CORE/eq4  (
    .i0(instr[15:11]),
    .i1(5'b00010),
    .o(\GEN_PLUS_CORE$CORE/n67 ));  // ../../RTL/cpu/KC_LS1u_plus.v(169)
  eq_w5 \GEN_PLUS_CORE$CORE/eq5  (
    .i0(instr[15:11]),
    .i1(5'b00011),
    .o(\GEN_PLUS_CORE$CORE/n68 ));  // ../../RTL/cpu/KC_LS1u_plus.v(171)
  eq_w5 \GEN_PLUS_CORE$CORE/eq6  (
    .i0(instr[15:11]),
    .i1(5'b00100),
    .o(\GEN_PLUS_CORE$CORE/n69 ));  // ../../RTL/cpu/KC_LS1u_plus.v(173)
  eq_w5 \GEN_PLUS_CORE$CORE/eq7  (
    .i0(instr[15:11]),
    .i1(5'b00101),
    .o(\GEN_PLUS_CORE$CORE/n70 ));  // ../../RTL/cpu/KC_LS1u_plus.v(175)
  eq_w5 \GEN_PLUS_CORE$CORE/eq8  (
    .i0(instr[15:11]),
    .i1(5'b00110),
    .o(\GEN_PLUS_CORE$CORE/n71 ));  // ../../RTL/cpu/KC_LS1u_plus.v(177)
  eq_w5 \GEN_PLUS_CORE$CORE/eq9  (
    .i0(instr[15:11]),
    .i1(5'b01110),
    .o(\GEN_PLUS_CORE$CORE/n72 ));  // ../../RTL/cpu/KC_LS1u_plus.v(183)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/int_service_reg  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n37 ),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/IN_ISP ));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/jmp_wait_reg  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/jmp ),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/jmp_wait ));  // ../../RTL/cpu/KC_LS1u_plus.v(291)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux0_b0  (
    .i0(\GEN_PLUS_CORE$CORE/PCP1 [0]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [0]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n5 [0]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux0_b1  (
    .i0(\GEN_PLUS_CORE$CORE/PCP1 [1]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [1]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n5 [1]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux0_b10  (
    .i0(\GEN_PLUS_CORE$CORE/PCP1 [10]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [10]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n5 [10]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux0_b11  (
    .i0(\GEN_PLUS_CORE$CORE/PCP1 [11]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [11]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n5 [11]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux0_b12  (
    .i0(\GEN_PLUS_CORE$CORE/PCP1 [12]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [12]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n5 [12]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux0_b13  (
    .i0(\GEN_PLUS_CORE$CORE/PCP1 [13]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [13]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n5 [13]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux0_b14  (
    .i0(\GEN_PLUS_CORE$CORE/PCP1 [14]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [14]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n5 [14]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux0_b15  (
    .i0(\GEN_PLUS_CORE$CORE/PCP1 [15]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [15]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n5 [15]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux0_b16  (
    .i0(\GEN_PLUS_CORE$CORE/PCP1 [16]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [16]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n5 [16]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux0_b17  (
    .i0(\GEN_PLUS_CORE$CORE/PCP1 [17]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [17]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n5 [17]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux0_b18  (
    .i0(\GEN_PLUS_CORE$CORE/PCP1 [18]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [18]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n5 [18]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux0_b19  (
    .i0(\GEN_PLUS_CORE$CORE/PCP1 [19]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [19]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n5 [19]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux0_b2  (
    .i0(\GEN_PLUS_CORE$CORE/PCP1 [2]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [2]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n5 [2]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux0_b20  (
    .i0(\GEN_PLUS_CORE$CORE/PCP1 [20]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [20]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n5 [20]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux0_b21  (
    .i0(\GEN_PLUS_CORE$CORE/PCP1 [21]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [21]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n5 [21]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux0_b22  (
    .i0(\GEN_PLUS_CORE$CORE/PCP1 [22]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [22]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n5 [22]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux0_b3  (
    .i0(\GEN_PLUS_CORE$CORE/PCP1 [3]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [3]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n5 [3]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux0_b4  (
    .i0(\GEN_PLUS_CORE$CORE/PCP1 [4]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [4]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n5 [4]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux0_b5  (
    .i0(\GEN_PLUS_CORE$CORE/PCP1 [5]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [5]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n5 [5]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux0_b6  (
    .i0(\GEN_PLUS_CORE$CORE/PCP1 [6]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [6]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n5 [6]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux0_b7  (
    .i0(\GEN_PLUS_CORE$CORE/PCP1 [7]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [7]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n5 [7]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux0_b8  (
    .i0(\GEN_PLUS_CORE$CORE/PCP1 [8]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [8]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n5 [8]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux0_b9  (
    .i0(\GEN_PLUS_CORE$CORE/PCP1 [9]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [9]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n5 [9]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  and \GEN_PLUS_CORE$CORE/mux10_b0_sel_is_2  (\GEN_PLUS_CORE$CORE/mux10_b0_sel_is_2_o , \instr[0]_neg , instr[1], \instr[2]_neg );
  and \GEN_PLUS_CORE$CORE/mux11_b0_sel_is_1  (\GEN_PLUS_CORE$CORE/mux11_b0_sel_is_1_o , instr[0], \instr[1]_neg , \instr[2]_neg );
  and \GEN_PLUS_CORE$CORE/mux12_b0_sel_is_0  (\GEN_PLUS_CORE$CORE/mux12_b0_sel_is_0_o , \instr[0]_neg , \instr[1]_neg , \instr[2]_neg );
  and \GEN_PLUS_CORE$CORE/mux13_b0_sel_is_3  (\GEN_PLUS_CORE$CORE/mux13_b0_sel_is_3_o , \GEN_PLUS_CORE$CORE/n14 , \GEN_PLUS_CORE$CORE/mux7_b0_sel_is_5_o );
  and \GEN_PLUS_CORE$CORE/mux14_b0_sel_is_3  (\GEN_PLUS_CORE$CORE/mux14_b0_sel_is_3_o , \GEN_PLUS_CORE$CORE/n14 , \GEN_PLUS_CORE$CORE/mux8_b0_sel_is_4_o );
  and \GEN_PLUS_CORE$CORE/mux15_b0_sel_is_3  (\GEN_PLUS_CORE$CORE/mux15_b0_sel_is_3_o , \GEN_PLUS_CORE$CORE/n14 , \GEN_PLUS_CORE$CORE/mux9_b0_sel_is_3_o );
  and \GEN_PLUS_CORE$CORE/mux16_b0_sel_is_3  (\GEN_PLUS_CORE$CORE/mux16_b0_sel_is_3_o , \GEN_PLUS_CORE$CORE/n14 , \GEN_PLUS_CORE$CORE/mux10_b0_sel_is_2_o );
  and \GEN_PLUS_CORE$CORE/mux17_b0_sel_is_3  (\GEN_PLUS_CORE$CORE/mux17_b0_sel_is_3_o , \GEN_PLUS_CORE$CORE/n14 , \GEN_PLUS_CORE$CORE/mux11_b0_sel_is_1_o );
  and \GEN_PLUS_CORE$CORE/mux18_b0_sel_is_3  (\GEN_PLUS_CORE$CORE/mux18_b0_sel_is_3_o , \GEN_PLUS_CORE$CORE/n14 , \GEN_PLUS_CORE$CORE/mux12_b0_sel_is_0_o );
  AL_MUX \GEN_PLUS_CORE$CORE/mux19_b0  (
    .i0(\GEN_PLUS_CORE$CORE/RTA2 [0]),
    .i1(XCRo[0]),
    .sel(\GEN_PLUS_CORE$CORE/mux19_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n28 [0]));
  and \GEN_PLUS_CORE$CORE/mux19_b0_sel_is_2  (\GEN_PLUS_CORE$CORE/mux19_b0_sel_is_2_o , \GEN_PLUS_CORE$CORE/ret_sel_neg , \GEN_PLUS_CORE$CORE/mux13_b0_sel_is_3_o );
  AL_MUX \GEN_PLUS_CORE$CORE/mux19_b1  (
    .i0(\GEN_PLUS_CORE$CORE/RTA2 [1]),
    .i1(XCRo[1]),
    .sel(\GEN_PLUS_CORE$CORE/mux19_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n28 [1]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux19_b2  (
    .i0(\GEN_PLUS_CORE$CORE/RTA2 [2]),
    .i1(XCRo[2]),
    .sel(\GEN_PLUS_CORE$CORE/mux19_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n28 [2]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux19_b3  (
    .i0(\GEN_PLUS_CORE$CORE/RTA2 [3]),
    .i1(XCRo[3]),
    .sel(\GEN_PLUS_CORE$CORE/mux19_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n28 [3]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux19_b4  (
    .i0(\GEN_PLUS_CORE$CORE/RTA2 [4]),
    .i1(XCRo[4]),
    .sel(\GEN_PLUS_CORE$CORE/mux19_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n28 [4]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux19_b5  (
    .i0(\GEN_PLUS_CORE$CORE/RTA2 [5]),
    .i1(XCRo[5]),
    .sel(\GEN_PLUS_CORE$CORE/mux19_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n28 [5]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux19_b6  (
    .i0(\GEN_PLUS_CORE$CORE/RTA2 [6]),
    .i1(XCRo[6]),
    .sel(\GEN_PLUS_CORE$CORE/mux19_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n28 [6]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux19_b7  (
    .i0(\GEN_PLUS_CORE$CORE/RTA2 [7]),
    .i1(XCRo[7]),
    .sel(\GEN_PLUS_CORE$CORE/mux19_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n28 [7]));
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux1_b0  (
    .i0(\GEN_PLUS_CORE$CORE/n5 [0]),
    .i1(IVEC_addr[0]),
    .sel(\GEN_PLUS_CORE$CORE/int_filter ),
    .o(\GEN_PLUS_CORE$CORE/n6 [0]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux1_b1  (
    .i0(\GEN_PLUS_CORE$CORE/n5 [1]),
    .i1(IVEC_addr[1]),
    .sel(\GEN_PLUS_CORE$CORE/int_filter ),
    .o(\GEN_PLUS_CORE$CORE/n6 [1]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux1_b10  (
    .i0(\GEN_PLUS_CORE$CORE/n5 [10]),
    .i1(IVEC_addr[10]),
    .sel(\GEN_PLUS_CORE$CORE/int_filter ),
    .o(\GEN_PLUS_CORE$CORE/n6 [10]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux1_b11  (
    .i0(\GEN_PLUS_CORE$CORE/n5 [11]),
    .i1(IVEC_addr[11]),
    .sel(\GEN_PLUS_CORE$CORE/int_filter ),
    .o(\GEN_PLUS_CORE$CORE/n6 [11]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux1_b12  (
    .i0(\GEN_PLUS_CORE$CORE/n5 [12]),
    .i1(IVEC_addr[12]),
    .sel(\GEN_PLUS_CORE$CORE/int_filter ),
    .o(\GEN_PLUS_CORE$CORE/n6 [12]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux1_b13  (
    .i0(\GEN_PLUS_CORE$CORE/n5 [13]),
    .i1(IVEC_addr[13]),
    .sel(\GEN_PLUS_CORE$CORE/int_filter ),
    .o(\GEN_PLUS_CORE$CORE/n6 [13]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux1_b14  (
    .i0(\GEN_PLUS_CORE$CORE/n5 [14]),
    .i1(IVEC_addr[14]),
    .sel(\GEN_PLUS_CORE$CORE/int_filter ),
    .o(\GEN_PLUS_CORE$CORE/n6 [14]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux1_b15  (
    .i0(\GEN_PLUS_CORE$CORE/n5 [15]),
    .i1(IVEC_addr[15]),
    .sel(\GEN_PLUS_CORE$CORE/int_filter ),
    .o(\GEN_PLUS_CORE$CORE/n6 [15]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux1_b16  (
    .i0(\GEN_PLUS_CORE$CORE/n5 [16]),
    .i1(IVEC_addr[16]),
    .sel(\GEN_PLUS_CORE$CORE/int_filter ),
    .o(\GEN_PLUS_CORE$CORE/n6 [16]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux1_b17  (
    .i0(\GEN_PLUS_CORE$CORE/n5 [17]),
    .i1(IVEC_addr[17]),
    .sel(\GEN_PLUS_CORE$CORE/int_filter ),
    .o(\GEN_PLUS_CORE$CORE/n6 [17]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux1_b18  (
    .i0(\GEN_PLUS_CORE$CORE/n5 [18]),
    .i1(IVEC_addr[18]),
    .sel(\GEN_PLUS_CORE$CORE/int_filter ),
    .o(\GEN_PLUS_CORE$CORE/n6 [18]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux1_b19  (
    .i0(\GEN_PLUS_CORE$CORE/n5 [19]),
    .i1(IVEC_addr[19]),
    .sel(\GEN_PLUS_CORE$CORE/int_filter ),
    .o(\GEN_PLUS_CORE$CORE/n6 [19]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux1_b2  (
    .i0(\GEN_PLUS_CORE$CORE/n5 [2]),
    .i1(IVEC_addr[2]),
    .sel(\GEN_PLUS_CORE$CORE/int_filter ),
    .o(\GEN_PLUS_CORE$CORE/n6 [2]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux1_b20  (
    .i0(\GEN_PLUS_CORE$CORE/n5 [20]),
    .i1(IVEC_addr[20]),
    .sel(\GEN_PLUS_CORE$CORE/int_filter ),
    .o(\GEN_PLUS_CORE$CORE/n6 [20]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux1_b21  (
    .i0(\GEN_PLUS_CORE$CORE/n5 [21]),
    .i1(IVEC_addr[21]),
    .sel(\GEN_PLUS_CORE$CORE/int_filter ),
    .o(\GEN_PLUS_CORE$CORE/n6 [21]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux1_b22  (
    .i0(\GEN_PLUS_CORE$CORE/n5 [22]),
    .i1(IVEC_addr[22]),
    .sel(\GEN_PLUS_CORE$CORE/int_filter ),
    .o(\GEN_PLUS_CORE$CORE/n6 [22]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux1_b3  (
    .i0(\GEN_PLUS_CORE$CORE/n5 [3]),
    .i1(IVEC_addr[3]),
    .sel(\GEN_PLUS_CORE$CORE/int_filter ),
    .o(\GEN_PLUS_CORE$CORE/n6 [3]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux1_b4  (
    .i0(\GEN_PLUS_CORE$CORE/n5 [4]),
    .i1(IVEC_addr[4]),
    .sel(\GEN_PLUS_CORE$CORE/int_filter ),
    .o(\GEN_PLUS_CORE$CORE/n6 [4]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux1_b5  (
    .i0(\GEN_PLUS_CORE$CORE/n5 [5]),
    .i1(IVEC_addr[5]),
    .sel(\GEN_PLUS_CORE$CORE/int_filter ),
    .o(\GEN_PLUS_CORE$CORE/n6 [5]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux1_b6  (
    .i0(\GEN_PLUS_CORE$CORE/n5 [6]),
    .i1(IVEC_addr[6]),
    .sel(\GEN_PLUS_CORE$CORE/int_filter ),
    .o(\GEN_PLUS_CORE$CORE/n6 [6]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux1_b7  (
    .i0(\GEN_PLUS_CORE$CORE/n5 [7]),
    .i1(IVEC_addr[7]),
    .sel(\GEN_PLUS_CORE$CORE/int_filter ),
    .o(\GEN_PLUS_CORE$CORE/n6 [7]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux1_b8  (
    .i0(\GEN_PLUS_CORE$CORE/n5 [8]),
    .i1(IVEC_addr[8]),
    .sel(\GEN_PLUS_CORE$CORE/int_filter ),
    .o(\GEN_PLUS_CORE$CORE/n6 [8]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux1_b9  (
    .i0(\GEN_PLUS_CORE$CORE/n5 [9]),
    .i1(IVEC_addr[9]),
    .sel(\GEN_PLUS_CORE$CORE/int_filter ),
    .o(\GEN_PLUS_CORE$CORE/n6 [9]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  AL_MUX \GEN_PLUS_CORE$CORE/mux20_b0  (
    .i0(\GEN_PLUS_CORE$CORE/RTA1 [0]),
    .i1(XCRo[0]),
    .sel(\GEN_PLUS_CORE$CORE/mux20_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n29 [0]));
  and \GEN_PLUS_CORE$CORE/mux20_b0_sel_is_2  (\GEN_PLUS_CORE$CORE/mux20_b0_sel_is_2_o , \GEN_PLUS_CORE$CORE/ret_sel_neg , \GEN_PLUS_CORE$CORE/mux14_b0_sel_is_3_o );
  AL_MUX \GEN_PLUS_CORE$CORE/mux20_b1  (
    .i0(\GEN_PLUS_CORE$CORE/RTA1 [1]),
    .i1(XCRo[1]),
    .sel(\GEN_PLUS_CORE$CORE/mux20_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n29 [1]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux20_b2  (
    .i0(\GEN_PLUS_CORE$CORE/RTA1 [2]),
    .i1(XCRo[2]),
    .sel(\GEN_PLUS_CORE$CORE/mux20_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n29 [2]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux20_b3  (
    .i0(\GEN_PLUS_CORE$CORE/RTA1 [3]),
    .i1(XCRo[3]),
    .sel(\GEN_PLUS_CORE$CORE/mux20_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n29 [3]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux20_b4  (
    .i0(\GEN_PLUS_CORE$CORE/RTA1 [4]),
    .i1(XCRo[4]),
    .sel(\GEN_PLUS_CORE$CORE/mux20_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n29 [4]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux20_b5  (
    .i0(\GEN_PLUS_CORE$CORE/RTA1 [5]),
    .i1(XCRo[5]),
    .sel(\GEN_PLUS_CORE$CORE/mux20_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n29 [5]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux20_b6  (
    .i0(\GEN_PLUS_CORE$CORE/RTA1 [6]),
    .i1(XCRo[6]),
    .sel(\GEN_PLUS_CORE$CORE/mux20_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n29 [6]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux20_b7  (
    .i0(\GEN_PLUS_CORE$CORE/RTA1 [7]),
    .i1(XCRo[7]),
    .sel(\GEN_PLUS_CORE$CORE/mux20_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n29 [7]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux21_b0  (
    .i0(\GEN_PLUS_CORE$CORE/RTA0 [0]),
    .i1(XCRo[0]),
    .sel(\GEN_PLUS_CORE$CORE/mux21_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n30 [0]));
  and \GEN_PLUS_CORE$CORE/mux21_b0_sel_is_2  (\GEN_PLUS_CORE$CORE/mux21_b0_sel_is_2_o , \GEN_PLUS_CORE$CORE/ret_sel_neg , \GEN_PLUS_CORE$CORE/mux15_b0_sel_is_3_o );
  AL_MUX \GEN_PLUS_CORE$CORE/mux21_b1  (
    .i0(\GEN_PLUS_CORE$CORE/RTA0 [1]),
    .i1(XCRo[1]),
    .sel(\GEN_PLUS_CORE$CORE/mux21_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n30 [1]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux21_b2  (
    .i0(\GEN_PLUS_CORE$CORE/RTA0 [2]),
    .i1(XCRo[2]),
    .sel(\GEN_PLUS_CORE$CORE/mux21_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n30 [2]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux21_b3  (
    .i0(\GEN_PLUS_CORE$CORE/RTA0 [3]),
    .i1(XCRo[3]),
    .sel(\GEN_PLUS_CORE$CORE/mux21_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n30 [3]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux21_b4  (
    .i0(\GEN_PLUS_CORE$CORE/RTA0 [4]),
    .i1(XCRo[4]),
    .sel(\GEN_PLUS_CORE$CORE/mux21_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n30 [4]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux21_b5  (
    .i0(\GEN_PLUS_CORE$CORE/RTA0 [5]),
    .i1(XCRo[5]),
    .sel(\GEN_PLUS_CORE$CORE/mux21_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n30 [5]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux21_b6  (
    .i0(\GEN_PLUS_CORE$CORE/RTA0 [6]),
    .i1(XCRo[6]),
    .sel(\GEN_PLUS_CORE$CORE/mux21_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n30 [6]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux21_b7  (
    .i0(\GEN_PLUS_CORE$CORE/RTA0 [7]),
    .i1(XCRo[7]),
    .sel(\GEN_PLUS_CORE$CORE/mux21_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n30 [7]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux22_b0  (
    .i0(\GEN_PLUS_CORE$CORE/RET2 [0]),
    .i1(XCRo[0]),
    .sel(\GEN_PLUS_CORE$CORE/mux22_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n31 [0]));
  and \GEN_PLUS_CORE$CORE/mux22_b0_sel_is_2  (\GEN_PLUS_CORE$CORE/mux22_b0_sel_is_2_o , \GEN_PLUS_CORE$CORE/ret_sel_neg , \GEN_PLUS_CORE$CORE/mux16_b0_sel_is_3_o );
  AL_MUX \GEN_PLUS_CORE$CORE/mux22_b1  (
    .i0(\GEN_PLUS_CORE$CORE/RET2 [1]),
    .i1(XCRo[1]),
    .sel(\GEN_PLUS_CORE$CORE/mux22_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n31 [1]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux22_b2  (
    .i0(\GEN_PLUS_CORE$CORE/RET2 [2]),
    .i1(XCRo[2]),
    .sel(\GEN_PLUS_CORE$CORE/mux22_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n31 [2]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux22_b3  (
    .i0(\GEN_PLUS_CORE$CORE/RET2 [3]),
    .i1(XCRo[3]),
    .sel(\GEN_PLUS_CORE$CORE/mux22_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n31 [3]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux22_b4  (
    .i0(\GEN_PLUS_CORE$CORE/RET2 [4]),
    .i1(XCRo[4]),
    .sel(\GEN_PLUS_CORE$CORE/mux22_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n31 [4]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux22_b5  (
    .i0(\GEN_PLUS_CORE$CORE/RET2 [5]),
    .i1(XCRo[5]),
    .sel(\GEN_PLUS_CORE$CORE/mux22_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n31 [5]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux22_b6  (
    .i0(\GEN_PLUS_CORE$CORE/RET2 [6]),
    .i1(XCRo[6]),
    .sel(\GEN_PLUS_CORE$CORE/mux22_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n31 [6]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux23_b0  (
    .i0(\GEN_PLUS_CORE$CORE/RET1 [0]),
    .i1(XCRo[0]),
    .sel(\GEN_PLUS_CORE$CORE/mux23_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n32 [0]));
  and \GEN_PLUS_CORE$CORE/mux23_b0_sel_is_2  (\GEN_PLUS_CORE$CORE/mux23_b0_sel_is_2_o , \GEN_PLUS_CORE$CORE/ret_sel_neg , \GEN_PLUS_CORE$CORE/mux17_b0_sel_is_3_o );
  AL_MUX \GEN_PLUS_CORE$CORE/mux23_b1  (
    .i0(\GEN_PLUS_CORE$CORE/RET1 [1]),
    .i1(XCRo[1]),
    .sel(\GEN_PLUS_CORE$CORE/mux23_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n32 [1]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux23_b2  (
    .i0(\GEN_PLUS_CORE$CORE/RET1 [2]),
    .i1(XCRo[2]),
    .sel(\GEN_PLUS_CORE$CORE/mux23_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n32 [2]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux23_b3  (
    .i0(\GEN_PLUS_CORE$CORE/RET1 [3]),
    .i1(XCRo[3]),
    .sel(\GEN_PLUS_CORE$CORE/mux23_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n32 [3]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux23_b4  (
    .i0(\GEN_PLUS_CORE$CORE/RET1 [4]),
    .i1(XCRo[4]),
    .sel(\GEN_PLUS_CORE$CORE/mux23_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n32 [4]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux23_b5  (
    .i0(\GEN_PLUS_CORE$CORE/RET1 [5]),
    .i1(XCRo[5]),
    .sel(\GEN_PLUS_CORE$CORE/mux23_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n32 [5]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux23_b6  (
    .i0(\GEN_PLUS_CORE$CORE/RET1 [6]),
    .i1(XCRo[6]),
    .sel(\GEN_PLUS_CORE$CORE/mux23_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n32 [6]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux23_b7  (
    .i0(\GEN_PLUS_CORE$CORE/RET1 [7]),
    .i1(XCRo[7]),
    .sel(\GEN_PLUS_CORE$CORE/mux23_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n32 [7]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux24_b0  (
    .i0(\GEN_PLUS_CORE$CORE/RET0 [0]),
    .i1(XCRo[0]),
    .sel(\GEN_PLUS_CORE$CORE/mux24_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n33 [0]));
  and \GEN_PLUS_CORE$CORE/mux24_b0_sel_is_2  (\GEN_PLUS_CORE$CORE/mux24_b0_sel_is_2_o , \GEN_PLUS_CORE$CORE/ret_sel_neg , \GEN_PLUS_CORE$CORE/mux18_b0_sel_is_3_o );
  AL_MUX \GEN_PLUS_CORE$CORE/mux24_b1  (
    .i0(\GEN_PLUS_CORE$CORE/RET0 [1]),
    .i1(XCRo[1]),
    .sel(\GEN_PLUS_CORE$CORE/mux24_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n33 [1]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux24_b2  (
    .i0(\GEN_PLUS_CORE$CORE/RET0 [2]),
    .i1(XCRo[2]),
    .sel(\GEN_PLUS_CORE$CORE/mux24_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n33 [2]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux24_b3  (
    .i0(\GEN_PLUS_CORE$CORE/RET0 [3]),
    .i1(XCRo[3]),
    .sel(\GEN_PLUS_CORE$CORE/mux24_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n33 [3]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux24_b4  (
    .i0(\GEN_PLUS_CORE$CORE/RET0 [4]),
    .i1(XCRo[4]),
    .sel(\GEN_PLUS_CORE$CORE/mux24_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n33 [4]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux24_b5  (
    .i0(\GEN_PLUS_CORE$CORE/RET0 [5]),
    .i1(XCRo[5]),
    .sel(\GEN_PLUS_CORE$CORE/mux24_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n33 [5]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux24_b6  (
    .i0(\GEN_PLUS_CORE$CORE/RET0 [6]),
    .i1(XCRo[6]),
    .sel(\GEN_PLUS_CORE$CORE/mux24_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n33 [6]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux24_b7  (
    .i0(\GEN_PLUS_CORE$CORE/RET0 [7]),
    .i1(XCRo[7]),
    .sel(\GEN_PLUS_CORE$CORE/mux24_b0_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$CORE/n33 [7]));
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux25_b0  (
    .i0(\GEN_PLUS_CORE$CORE/n33 [0]),
    .i1(\GEN_PLUS_CORE$CORE/n11 [0]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n34 [0]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux25_b1  (
    .i0(\GEN_PLUS_CORE$CORE/n33 [1]),
    .i1(\GEN_PLUS_CORE$CORE/n11 [1]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n34 [1]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux25_b2  (
    .i0(\GEN_PLUS_CORE$CORE/n33 [2]),
    .i1(\GEN_PLUS_CORE$CORE/n11 [2]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n34 [2]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux25_b3  (
    .i0(\GEN_PLUS_CORE$CORE/n33 [3]),
    .i1(\GEN_PLUS_CORE$CORE/n11 [3]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n34 [3]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux25_b4  (
    .i0(\GEN_PLUS_CORE$CORE/n33 [4]),
    .i1(\GEN_PLUS_CORE$CORE/n11 [4]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n34 [4]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux25_b5  (
    .i0(\GEN_PLUS_CORE$CORE/n33 [5]),
    .i1(\GEN_PLUS_CORE$CORE/n11 [5]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n34 [5]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux25_b6  (
    .i0(\GEN_PLUS_CORE$CORE/n33 [6]),
    .i1(\GEN_PLUS_CORE$CORE/n11 [6]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n34 [6]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux25_b7  (
    .i0(\GEN_PLUS_CORE$CORE/n33 [7]),
    .i1(\GEN_PLUS_CORE$CORE/n11 [7]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n34 [7]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux26_b0  (
    .i0(\GEN_PLUS_CORE$CORE/n32 [0]),
    .i1(\GEN_PLUS_CORE$CORE/n12 [0]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n35 [0]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux26_b1  (
    .i0(\GEN_PLUS_CORE$CORE/n32 [1]),
    .i1(\GEN_PLUS_CORE$CORE/n12 [1]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n35 [1]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux26_b2  (
    .i0(\GEN_PLUS_CORE$CORE/n32 [2]),
    .i1(\GEN_PLUS_CORE$CORE/n12 [2]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n35 [2]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux26_b3  (
    .i0(\GEN_PLUS_CORE$CORE/n32 [3]),
    .i1(\GEN_PLUS_CORE$CORE/n12 [3]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n35 [3]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux26_b4  (
    .i0(\GEN_PLUS_CORE$CORE/n32 [4]),
    .i1(\GEN_PLUS_CORE$CORE/n12 [4]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n35 [4]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux26_b5  (
    .i0(\GEN_PLUS_CORE$CORE/n32 [5]),
    .i1(\GEN_PLUS_CORE$CORE/n12 [5]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n35 [5]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux26_b6  (
    .i0(\GEN_PLUS_CORE$CORE/n32 [6]),
    .i1(\GEN_PLUS_CORE$CORE/n12 [6]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n35 [6]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux26_b7  (
    .i0(\GEN_PLUS_CORE$CORE/n32 [7]),
    .i1(\GEN_PLUS_CORE$CORE/n12 [7]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n35 [7]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux27_b0  (
    .i0(\GEN_PLUS_CORE$CORE/n31 [0]),
    .i1(\GEN_PLUS_CORE$CORE/n13 [0]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n36 [0]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux27_b1  (
    .i0(\GEN_PLUS_CORE$CORE/n31 [1]),
    .i1(\GEN_PLUS_CORE$CORE/n13 [1]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n36 [1]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux27_b2  (
    .i0(\GEN_PLUS_CORE$CORE/n31 [2]),
    .i1(\GEN_PLUS_CORE$CORE/n13 [2]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n36 [2]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux27_b3  (
    .i0(\GEN_PLUS_CORE$CORE/n31 [3]),
    .i1(\GEN_PLUS_CORE$CORE/n13 [3]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n36 [3]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux27_b4  (
    .i0(\GEN_PLUS_CORE$CORE/n31 [4]),
    .i1(\GEN_PLUS_CORE$CORE/n13 [4]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n36 [4]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux27_b5  (
    .i0(\GEN_PLUS_CORE$CORE/n31 [5]),
    .i1(\GEN_PLUS_CORE$CORE/n13 [5]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n36 [5]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux27_b6  (
    .i0(\GEN_PLUS_CORE$CORE/n31 [6]),
    .i1(\GEN_PLUS_CORE$CORE/n13 [6]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n36 [6]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux28_b0  (
    .i0(\GEN_PLUS_CORE$CORE/n30 [0]),
    .i1(daddr[0]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n38 [0]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux28_b1  (
    .i0(\GEN_PLUS_CORE$CORE/n30 [1]),
    .i1(daddr[1]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n38 [1]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux28_b2  (
    .i0(\GEN_PLUS_CORE$CORE/n30 [2]),
    .i1(daddr[2]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n38 [2]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux28_b3  (
    .i0(\GEN_PLUS_CORE$CORE/n30 [3]),
    .i1(daddr[3]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n38 [3]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux28_b4  (
    .i0(\GEN_PLUS_CORE$CORE/n30 [4]),
    .i1(daddr[4]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n38 [4]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux28_b5  (
    .i0(\GEN_PLUS_CORE$CORE/n30 [5]),
    .i1(daddr[5]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n38 [5]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux28_b6  (
    .i0(\GEN_PLUS_CORE$CORE/n30 [6]),
    .i1(daddr[6]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n38 [6]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux28_b7  (
    .i0(\GEN_PLUS_CORE$CORE/n30 [7]),
    .i1(daddr[7]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n38 [7]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux29_b0  (
    .i0(\GEN_PLUS_CORE$CORE/n29 [0]),
    .i1(daddr[8]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n39 [0]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux29_b1  (
    .i0(\GEN_PLUS_CORE$CORE/n29 [1]),
    .i1(daddr[9]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n39 [1]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux29_b2  (
    .i0(\GEN_PLUS_CORE$CORE/n29 [2]),
    .i1(daddr[10]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n39 [2]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux29_b3  (
    .i0(\GEN_PLUS_CORE$CORE/n29 [3]),
    .i1(daddr[11]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n39 [3]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux29_b4  (
    .i0(\GEN_PLUS_CORE$CORE/n29 [4]),
    .i1(daddr[12]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n39 [4]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux29_b5  (
    .i0(\GEN_PLUS_CORE$CORE/n29 [5]),
    .i1(daddr[13]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n39 [5]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux29_b6  (
    .i0(\GEN_PLUS_CORE$CORE/n29 [6]),
    .i1(daddr[14]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n39 [6]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux29_b7  (
    .i0(\GEN_PLUS_CORE$CORE/n29 [7]),
    .i1(daddr[15]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n39 [7]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux30_b0  (
    .i0(\GEN_PLUS_CORE$CORE/n28 [0]),
    .i1(daddr[16]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n40 [0]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux30_b1  (
    .i0(\GEN_PLUS_CORE$CORE/n28 [1]),
    .i1(daddr[17]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n40 [1]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux30_b2  (
    .i0(\GEN_PLUS_CORE$CORE/n28 [2]),
    .i1(daddr[18]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n40 [2]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux30_b3  (
    .i0(\GEN_PLUS_CORE$CORE/n28 [3]),
    .i1(daddr[19]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n40 [3]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux30_b4  (
    .i0(\GEN_PLUS_CORE$CORE/n28 [4]),
    .i1(daddr[20]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n40 [4]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux30_b5  (
    .i0(\GEN_PLUS_CORE$CORE/n28 [5]),
    .i1(daddr[21]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n40 [5]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux30_b6  (
    .i0(\GEN_PLUS_CORE$CORE/n28 [6]),
    .i1(daddr[22]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n40 [6]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux30_b7  (
    .i0(\GEN_PLUS_CORE$CORE/n28 [7]),
    .i1(daddr[23]),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n40 [7]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  and \GEN_PLUS_CORE$CORE/mux34_b0_sel_is_6  (\GEN_PLUS_CORE$CORE/mux34_b0_sel_is_6_o , \instr[8]_neg , instr[9], instr[10]);
  and \GEN_PLUS_CORE$CORE/mux35_b0_sel_is_5  (\GEN_PLUS_CORE$CORE/mux35_b0_sel_is_5_o , instr[8], \instr[9]_neg , instr[10]);
  and \GEN_PLUS_CORE$CORE/mux36_b0_sel_is_4  (\GEN_PLUS_CORE$CORE/mux36_b0_sel_is_4_o , \instr[8]_neg , \instr[9]_neg , instr[10]);
  and \GEN_PLUS_CORE$CORE/mux37_b0_sel_is_3  (\GEN_PLUS_CORE$CORE/mux37_b0_sel_is_3_o , instr[8], instr[9], \instr[10]_neg );
  and \GEN_PLUS_CORE$CORE/mux38_b0_sel_is_2  (\GEN_PLUS_CORE$CORE/mux38_b0_sel_is_2_o , \instr[8]_neg , instr[9], \instr[10]_neg );
  and \GEN_PLUS_CORE$CORE/mux39_b0_sel_is_1  (\GEN_PLUS_CORE$CORE/mux39_b0_sel_is_1_o , instr[8], \instr[9]_neg , \instr[10]_neg );
  and \GEN_PLUS_CORE$CORE/mux3_b0_sel_is_0  (\GEN_PLUS_CORE$CORE/mux3_b0_sel_is_0_o , \GEN_PLUS_CORE$CORE/n7_neg , \GEN_PLUS_CORE$CORE/INSTR_HOLD_neg );
  and \GEN_PLUS_CORE$CORE/mux40_b0_sel_is_0  (\GEN_PLUS_CORE$CORE/mux40_b0_sel_is_0_o , \instr[8]_neg , \instr[9]_neg , \instr[10]_neg );
  and \GEN_PLUS_CORE$CORE/mux41_b0_sel_is_3  (\GEN_PLUS_CORE$CORE/mux41_b0_sel_is_3_o , \GEN_PLUS_CORE$CORE/n44 , \GEN_PLUS_CORE$CORE/mux34_b0_sel_is_6_o );
  AL_MUX \GEN_PLUS_CORE$CORE/mux42_b0  (
    .i0(daddr[16]),
    .i1(XCRo[0]),
    .sel(\GEN_PLUS_CORE$CORE/mux42_b0_sel_is_3_o ),
    .o(\GEN_PLUS_CORE$CORE/n53 [0]));
  and \GEN_PLUS_CORE$CORE/mux42_b0_sel_is_3  (\GEN_PLUS_CORE$CORE/mux42_b0_sel_is_3_o , \GEN_PLUS_CORE$CORE/n44 , \GEN_PLUS_CORE$CORE/mux35_b0_sel_is_5_o );
  AL_MUX \GEN_PLUS_CORE$CORE/mux42_b1  (
    .i0(daddr[17]),
    .i1(XCRo[1]),
    .sel(\GEN_PLUS_CORE$CORE/mux42_b0_sel_is_3_o ),
    .o(\GEN_PLUS_CORE$CORE/n53 [1]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux42_b2  (
    .i0(daddr[18]),
    .i1(XCRo[2]),
    .sel(\GEN_PLUS_CORE$CORE/mux42_b0_sel_is_3_o ),
    .o(\GEN_PLUS_CORE$CORE/n53 [2]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux42_b3  (
    .i0(daddr[19]),
    .i1(XCRo[3]),
    .sel(\GEN_PLUS_CORE$CORE/mux42_b0_sel_is_3_o ),
    .o(\GEN_PLUS_CORE$CORE/n53 [3]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux42_b4  (
    .i0(daddr[20]),
    .i1(XCRo[4]),
    .sel(\GEN_PLUS_CORE$CORE/mux42_b0_sel_is_3_o ),
    .o(\GEN_PLUS_CORE$CORE/n53 [4]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux42_b5  (
    .i0(daddr[21]),
    .i1(XCRo[5]),
    .sel(\GEN_PLUS_CORE$CORE/mux42_b0_sel_is_3_o ),
    .o(\GEN_PLUS_CORE$CORE/n53 [5]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux42_b6  (
    .i0(daddr[22]),
    .i1(XCRo[6]),
    .sel(\GEN_PLUS_CORE$CORE/mux42_b0_sel_is_3_o ),
    .o(\GEN_PLUS_CORE$CORE/n53 [6]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux42_b7  (
    .i0(daddr[23]),
    .i1(XCRo[7]),
    .sel(\GEN_PLUS_CORE$CORE/mux42_b0_sel_is_3_o ),
    .o(\GEN_PLUS_CORE$CORE/n53 [7]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux43_b0  (
    .i0(daddr[8]),
    .i1(XCRo[0]),
    .sel(\GEN_PLUS_CORE$CORE/mux43_b0_sel_is_3_o ),
    .o(\GEN_PLUS_CORE$CORE/n54 [0]));
  and \GEN_PLUS_CORE$CORE/mux43_b0_sel_is_3  (\GEN_PLUS_CORE$CORE/mux43_b0_sel_is_3_o , \GEN_PLUS_CORE$CORE/n44 , \GEN_PLUS_CORE$CORE/mux36_b0_sel_is_4_o );
  AL_MUX \GEN_PLUS_CORE$CORE/mux43_b1  (
    .i0(daddr[9]),
    .i1(XCRo[1]),
    .sel(\GEN_PLUS_CORE$CORE/mux43_b0_sel_is_3_o ),
    .o(\GEN_PLUS_CORE$CORE/n54 [1]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux43_b2  (
    .i0(daddr[10]),
    .i1(XCRo[2]),
    .sel(\GEN_PLUS_CORE$CORE/mux43_b0_sel_is_3_o ),
    .o(\GEN_PLUS_CORE$CORE/n54 [2]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux43_b3  (
    .i0(daddr[11]),
    .i1(XCRo[3]),
    .sel(\GEN_PLUS_CORE$CORE/mux43_b0_sel_is_3_o ),
    .o(\GEN_PLUS_CORE$CORE/n54 [3]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux43_b4  (
    .i0(daddr[12]),
    .i1(XCRo[4]),
    .sel(\GEN_PLUS_CORE$CORE/mux43_b0_sel_is_3_o ),
    .o(\GEN_PLUS_CORE$CORE/n54 [4]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux43_b5  (
    .i0(daddr[13]),
    .i1(XCRo[5]),
    .sel(\GEN_PLUS_CORE$CORE/mux43_b0_sel_is_3_o ),
    .o(\GEN_PLUS_CORE$CORE/n54 [5]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux43_b6  (
    .i0(daddr[14]),
    .i1(XCRo[6]),
    .sel(\GEN_PLUS_CORE$CORE/mux43_b0_sel_is_3_o ),
    .o(\GEN_PLUS_CORE$CORE/n54 [6]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux43_b7  (
    .i0(daddr[15]),
    .i1(XCRo[7]),
    .sel(\GEN_PLUS_CORE$CORE/mux43_b0_sel_is_3_o ),
    .o(\GEN_PLUS_CORE$CORE/n54 [7]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux44_b0  (
    .i0(daddr[0]),
    .i1(XCRo[0]),
    .sel(\GEN_PLUS_CORE$CORE/mux44_b0_sel_is_3_o ),
    .o(\GEN_PLUS_CORE$CORE/n55 [0]));
  and \GEN_PLUS_CORE$CORE/mux44_b0_sel_is_3  (\GEN_PLUS_CORE$CORE/mux44_b0_sel_is_3_o , \GEN_PLUS_CORE$CORE/n44 , \GEN_PLUS_CORE$CORE/mux37_b0_sel_is_3_o );
  AL_MUX \GEN_PLUS_CORE$CORE/mux44_b1  (
    .i0(daddr[1]),
    .i1(XCRo[1]),
    .sel(\GEN_PLUS_CORE$CORE/mux44_b0_sel_is_3_o ),
    .o(\GEN_PLUS_CORE$CORE/n55 [1]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux44_b2  (
    .i0(daddr[2]),
    .i1(XCRo[2]),
    .sel(\GEN_PLUS_CORE$CORE/mux44_b0_sel_is_3_o ),
    .o(\GEN_PLUS_CORE$CORE/n55 [2]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux44_b3  (
    .i0(daddr[3]),
    .i1(XCRo[3]),
    .sel(\GEN_PLUS_CORE$CORE/mux44_b0_sel_is_3_o ),
    .o(\GEN_PLUS_CORE$CORE/n55 [3]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux44_b4  (
    .i0(daddr[4]),
    .i1(XCRo[4]),
    .sel(\GEN_PLUS_CORE$CORE/mux44_b0_sel_is_3_o ),
    .o(\GEN_PLUS_CORE$CORE/n55 [4]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux44_b5  (
    .i0(daddr[5]),
    .i1(XCRo[5]),
    .sel(\GEN_PLUS_CORE$CORE/mux44_b0_sel_is_3_o ),
    .o(\GEN_PLUS_CORE$CORE/n55 [5]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux44_b6  (
    .i0(daddr[6]),
    .i1(XCRo[6]),
    .sel(\GEN_PLUS_CORE$CORE/mux44_b0_sel_is_3_o ),
    .o(\GEN_PLUS_CORE$CORE/n55 [6]));
  AL_MUX \GEN_PLUS_CORE$CORE/mux44_b7  (
    .i0(daddr[7]),
    .i1(XCRo[7]),
    .sel(\GEN_PLUS_CORE$CORE/mux44_b0_sel_is_3_o ),
    .o(\GEN_PLUS_CORE$CORE/n55 [7]));
  and \GEN_PLUS_CORE$CORE/mux45_b0_sel_is_3  (\GEN_PLUS_CORE$CORE/mux45_b0_sel_is_3_o , \GEN_PLUS_CORE$CORE/n44 , \GEN_PLUS_CORE$CORE/mux38_b0_sel_is_2_o );
  and \GEN_PLUS_CORE$CORE/mux46_b0_sel_is_3  (\GEN_PLUS_CORE$CORE/mux46_b0_sel_is_3_o , \GEN_PLUS_CORE$CORE/n44 , \GEN_PLUS_CORE$CORE/mux39_b0_sel_is_1_o );
  and \GEN_PLUS_CORE$CORE/mux47_b0_sel_is_3  (\GEN_PLUS_CORE$CORE/mux47_b0_sel_is_3_o , \GEN_PLUS_CORE$CORE/n44 , \GEN_PLUS_CORE$CORE/mux40_b0_sel_is_0_o );
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux48_b0  (
    .i0(\GEN_PLUS_CORE$CORE/n55 [0]),
    .i1(\GEN_PLUS_CORE$CORE/RTA0 [0]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/n59 [0]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux48_b1  (
    .i0(\GEN_PLUS_CORE$CORE/n55 [1]),
    .i1(\GEN_PLUS_CORE$CORE/RTA0 [1]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/n59 [1]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux48_b2  (
    .i0(\GEN_PLUS_CORE$CORE/n55 [2]),
    .i1(\GEN_PLUS_CORE$CORE/RTA0 [2]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/n59 [2]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux48_b3  (
    .i0(\GEN_PLUS_CORE$CORE/n55 [3]),
    .i1(\GEN_PLUS_CORE$CORE/RTA0 [3]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/n59 [3]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux48_b4  (
    .i0(\GEN_PLUS_CORE$CORE/n55 [4]),
    .i1(\GEN_PLUS_CORE$CORE/RTA0 [4]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/n59 [4]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux48_b5  (
    .i0(\GEN_PLUS_CORE$CORE/n55 [5]),
    .i1(\GEN_PLUS_CORE$CORE/RTA0 [5]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/n59 [5]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux48_b6  (
    .i0(\GEN_PLUS_CORE$CORE/n55 [6]),
    .i1(\GEN_PLUS_CORE$CORE/RTA0 [6]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/n59 [6]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux48_b7  (
    .i0(\GEN_PLUS_CORE$CORE/n55 [7]),
    .i1(\GEN_PLUS_CORE$CORE/RTA0 [7]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/n59 [7]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux49_b0  (
    .i0(\GEN_PLUS_CORE$CORE/n54 [0]),
    .i1(\GEN_PLUS_CORE$CORE/RTA1 [0]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/n60 [0]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux49_b1  (
    .i0(\GEN_PLUS_CORE$CORE/n54 [1]),
    .i1(\GEN_PLUS_CORE$CORE/RTA1 [1]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/n60 [1]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux49_b2  (
    .i0(\GEN_PLUS_CORE$CORE/n54 [2]),
    .i1(\GEN_PLUS_CORE$CORE/RTA1 [2]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/n60 [2]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux49_b3  (
    .i0(\GEN_PLUS_CORE$CORE/n54 [3]),
    .i1(\GEN_PLUS_CORE$CORE/RTA1 [3]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/n60 [3]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux49_b4  (
    .i0(\GEN_PLUS_CORE$CORE/n54 [4]),
    .i1(\GEN_PLUS_CORE$CORE/RTA1 [4]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/n60 [4]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux49_b5  (
    .i0(\GEN_PLUS_CORE$CORE/n54 [5]),
    .i1(\GEN_PLUS_CORE$CORE/RTA1 [5]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/n60 [5]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux49_b6  (
    .i0(\GEN_PLUS_CORE$CORE/n54 [6]),
    .i1(\GEN_PLUS_CORE$CORE/RTA1 [6]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/n60 [6]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux49_b7  (
    .i0(\GEN_PLUS_CORE$CORE/n54 [7]),
    .i1(\GEN_PLUS_CORE$CORE/RTA1 [7]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/n60 [7]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux4_b0  (
    .i0(iaddr[0]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [0]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n11 [0]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux4_b1  (
    .i0(iaddr[1]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [1]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n11 [1]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux4_b2  (
    .i0(iaddr[2]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [2]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n11 [2]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux4_b3  (
    .i0(iaddr[3]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [3]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n11 [3]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux4_b4  (
    .i0(iaddr[4]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [4]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n11 [4]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux4_b5  (
    .i0(iaddr[5]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [5]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n11 [5]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux4_b6  (
    .i0(iaddr[6]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [6]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n11 [6]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux4_b7  (
    .i0(iaddr[7]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [7]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n11 [7]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux50_b0  (
    .i0(\GEN_PLUS_CORE$CORE/n53 [0]),
    .i1(\GEN_PLUS_CORE$CORE/RTA2 [0]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/n61 [0]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux50_b1  (
    .i0(\GEN_PLUS_CORE$CORE/n53 [1]),
    .i1(\GEN_PLUS_CORE$CORE/RTA2 [1]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/n61 [1]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux50_b2  (
    .i0(\GEN_PLUS_CORE$CORE/n53 [2]),
    .i1(\GEN_PLUS_CORE$CORE/RTA2 [2]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/n61 [2]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux50_b3  (
    .i0(\GEN_PLUS_CORE$CORE/n53 [3]),
    .i1(\GEN_PLUS_CORE$CORE/RTA2 [3]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/n61 [3]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux50_b4  (
    .i0(\GEN_PLUS_CORE$CORE/n53 [4]),
    .i1(\GEN_PLUS_CORE$CORE/RTA2 [4]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/n61 [4]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux50_b5  (
    .i0(\GEN_PLUS_CORE$CORE/n53 [5]),
    .i1(\GEN_PLUS_CORE$CORE/RTA2 [5]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/n61 [5]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux50_b6  (
    .i0(\GEN_PLUS_CORE$CORE/n53 [6]),
    .i1(\GEN_PLUS_CORE$CORE/RTA2 [6]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/n61 [6]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux50_b7  (
    .i0(\GEN_PLUS_CORE$CORE/n53 [7]),
    .i1(\GEN_PLUS_CORE$CORE/RTA2 [7]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/n61 [7]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  and \GEN_PLUS_CORE$CORE/mux51_b0_sel_is_2  (\GEN_PLUS_CORE$CORE/mux51_b0_sel_is_2_o , \GEN_PLUS_CORE$CORE/ret_sel_neg , \GEN_PLUS_CORE$CORE/mux41_b0_sel_is_3_o );
  and \GEN_PLUS_CORE$CORE/mux52_b0_sel_is_2  (\GEN_PLUS_CORE$CORE/mux52_b0_sel_is_2_o , \GEN_PLUS_CORE$CORE/ret_sel_neg , \GEN_PLUS_CORE$CORE/mux45_b0_sel_is_3_o );
  and \GEN_PLUS_CORE$CORE/mux53_b0_sel_is_2  (\GEN_PLUS_CORE$CORE/mux53_b0_sel_is_2_o , \GEN_PLUS_CORE$CORE/ret_sel_neg , \GEN_PLUS_CORE$CORE/mux46_b0_sel_is_3_o );
  and \GEN_PLUS_CORE$CORE/mux54_b0_sel_is_2  (\GEN_PLUS_CORE$CORE/mux54_b0_sel_is_2_o , \GEN_PLUS_CORE$CORE/ret_sel_neg , \GEN_PLUS_CORE$CORE/mux47_b0_sel_is_3_o );
  binary_mux_s3_w1 \GEN_PLUS_CORE$CORE/mux55_b0  (
    .i0(\GEN_PLUS_CORE$CORE/RET0 [0]),
    .i1(\GEN_PLUS_CORE$CORE/RET1 [0]),
    .i2(\GEN_PLUS_CORE$CORE/RET1 [0]),
    .i3(\GEN_PLUS_CORE$CORE/RTA0 [0]),
    .i4(\GEN_PLUS_CORE$CORE/RTA1 [0]),
    .i5(\GEN_PLUS_CORE$CORE/RTA2 [0]),
    .i6(\GEN_PLUS_CORE$CORE/C [0]),
    .i7(\GEN_PLUS_CORE$CORE/D [0]),
    .sel(instr[2:0]),
    .o(\GEN_PLUS_CORE$CORE/XREGr [0]));  // ../../RTL/cpu/KC_LS1u_plus.v(214)
  binary_mux_s3_w1 \GEN_PLUS_CORE$CORE/mux55_b1  (
    .i0(\GEN_PLUS_CORE$CORE/RET0 [1]),
    .i1(\GEN_PLUS_CORE$CORE/RET1 [1]),
    .i2(\GEN_PLUS_CORE$CORE/RET1 [1]),
    .i3(\GEN_PLUS_CORE$CORE/RTA0 [1]),
    .i4(\GEN_PLUS_CORE$CORE/RTA1 [1]),
    .i5(\GEN_PLUS_CORE$CORE/RTA2 [1]),
    .i6(\GEN_PLUS_CORE$CORE/C [1]),
    .i7(\GEN_PLUS_CORE$CORE/D [1]),
    .sel(instr[2:0]),
    .o(\GEN_PLUS_CORE$CORE/XREGr [1]));  // ../../RTL/cpu/KC_LS1u_plus.v(214)
  binary_mux_s3_w1 \GEN_PLUS_CORE$CORE/mux55_b2  (
    .i0(\GEN_PLUS_CORE$CORE/RET0 [2]),
    .i1(\GEN_PLUS_CORE$CORE/RET1 [2]),
    .i2(\GEN_PLUS_CORE$CORE/RET1 [2]),
    .i3(\GEN_PLUS_CORE$CORE/RTA0 [2]),
    .i4(\GEN_PLUS_CORE$CORE/RTA1 [2]),
    .i5(\GEN_PLUS_CORE$CORE/RTA2 [2]),
    .i6(\GEN_PLUS_CORE$CORE/C [2]),
    .i7(\GEN_PLUS_CORE$CORE/D [2]),
    .sel(instr[2:0]),
    .o(\GEN_PLUS_CORE$CORE/XREGr [2]));  // ../../RTL/cpu/KC_LS1u_plus.v(214)
  binary_mux_s3_w1 \GEN_PLUS_CORE$CORE/mux55_b3  (
    .i0(\GEN_PLUS_CORE$CORE/RET0 [3]),
    .i1(\GEN_PLUS_CORE$CORE/RET1 [3]),
    .i2(\GEN_PLUS_CORE$CORE/RET1 [3]),
    .i3(\GEN_PLUS_CORE$CORE/RTA0 [3]),
    .i4(\GEN_PLUS_CORE$CORE/RTA1 [3]),
    .i5(\GEN_PLUS_CORE$CORE/RTA2 [3]),
    .i6(\GEN_PLUS_CORE$CORE/C [3]),
    .i7(\GEN_PLUS_CORE$CORE/D [3]),
    .sel(instr[2:0]),
    .o(\GEN_PLUS_CORE$CORE/XREGr [3]));  // ../../RTL/cpu/KC_LS1u_plus.v(214)
  binary_mux_s3_w1 \GEN_PLUS_CORE$CORE/mux55_b4  (
    .i0(\GEN_PLUS_CORE$CORE/RET0 [4]),
    .i1(\GEN_PLUS_CORE$CORE/RET1 [4]),
    .i2(\GEN_PLUS_CORE$CORE/RET1 [4]),
    .i3(\GEN_PLUS_CORE$CORE/RTA0 [4]),
    .i4(\GEN_PLUS_CORE$CORE/RTA1 [4]),
    .i5(\GEN_PLUS_CORE$CORE/RTA2 [4]),
    .i6(\GEN_PLUS_CORE$CORE/C [4]),
    .i7(\GEN_PLUS_CORE$CORE/D [4]),
    .sel(instr[2:0]),
    .o(\GEN_PLUS_CORE$CORE/XREGr [4]));  // ../../RTL/cpu/KC_LS1u_plus.v(214)
  binary_mux_s3_w1 \GEN_PLUS_CORE$CORE/mux55_b5  (
    .i0(\GEN_PLUS_CORE$CORE/RET0 [5]),
    .i1(\GEN_PLUS_CORE$CORE/RET1 [5]),
    .i2(\GEN_PLUS_CORE$CORE/RET1 [5]),
    .i3(\GEN_PLUS_CORE$CORE/RTA0 [5]),
    .i4(\GEN_PLUS_CORE$CORE/RTA1 [5]),
    .i5(\GEN_PLUS_CORE$CORE/RTA2 [5]),
    .i6(\GEN_PLUS_CORE$CORE/C [5]),
    .i7(\GEN_PLUS_CORE$CORE/D [5]),
    .sel(instr[2:0]),
    .o(\GEN_PLUS_CORE$CORE/XREGr [5]));  // ../../RTL/cpu/KC_LS1u_plus.v(214)
  binary_mux_s3_w1 \GEN_PLUS_CORE$CORE/mux55_b6  (
    .i0(\GEN_PLUS_CORE$CORE/RET0 [6]),
    .i1(\GEN_PLUS_CORE$CORE/RET1 [6]),
    .i2(\GEN_PLUS_CORE$CORE/RET1 [6]),
    .i3(\GEN_PLUS_CORE$CORE/RTA0 [6]),
    .i4(\GEN_PLUS_CORE$CORE/RTA1 [6]),
    .i5(\GEN_PLUS_CORE$CORE/RTA2 [6]),
    .i6(\GEN_PLUS_CORE$CORE/C [6]),
    .i7(\GEN_PLUS_CORE$CORE/D [6]),
    .sel(instr[2:0]),
    .o(\GEN_PLUS_CORE$CORE/XREGr [6]));  // ../../RTL/cpu/KC_LS1u_plus.v(214)
  binary_mux_s3_w1 \GEN_PLUS_CORE$CORE/mux55_b7  (
    .i0(\GEN_PLUS_CORE$CORE/RET0 [7]),
    .i1(\GEN_PLUS_CORE$CORE/RET1 [7]),
    .i2(\GEN_PLUS_CORE$CORE/RET1 [7]),
    .i3(\GEN_PLUS_CORE$CORE/RTA0 [7]),
    .i4(\GEN_PLUS_CORE$CORE/RTA1 [7]),
    .i5(\GEN_PLUS_CORE$CORE/RTA2 [7]),
    .i6(\GEN_PLUS_CORE$CORE/C [7]),
    .i7(\GEN_PLUS_CORE$CORE/D [7]),
    .sel(instr[2:0]),
    .o(\GEN_PLUS_CORE$CORE/XREGr [7]));  // ../../RTL/cpu/KC_LS1u_plus.v(214)
  binary_mux_s3_w1 \GEN_PLUS_CORE$CORE/mux56  (
    .i0(1'b1),
    .i1(\GEN_PLUS_CORE$CORE/n92 ),
    .i2(\GEN_PLUS_CORE$CORE/ALU_H4/SYNTHESIZED_WIRE_119 ),
    .i3(\GEN_PLUS_CORE$CORE/n94 ),
    .i4(\GEN_PLUS_CORE$CORE/ALU_H4/n42 ),
    .i5(1'b1),
    .i6(1'b0),
    .i7(1'b0),
    .sel(instr[10:8]),
    .o(\GEN_PLUS_CORE$CORE/n96 ));  // ../../RTL/cpu/KC_LS1u_plus.v(284)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux5_b0  (
    .i0(iaddr[8]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [8]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n12 [0]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux5_b1  (
    .i0(iaddr[9]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [9]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n12 [1]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux5_b2  (
    .i0(iaddr[10]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [10]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n12 [2]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux5_b3  (
    .i0(iaddr[11]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [11]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n12 [3]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux5_b4  (
    .i0(iaddr[12]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [12]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n12 [4]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux5_b5  (
    .i0(iaddr[13]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [13]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n12 [5]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux5_b6  (
    .i0(iaddr[14]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [14]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n12 [6]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux5_b7  (
    .i0(iaddr[15]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [15]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n12 [7]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux6_b0  (
    .i0(iaddr[16]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [16]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n13 [0]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux6_b1  (
    .i0(iaddr[17]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [17]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n13 [1]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux6_b2  (
    .i0(iaddr[18]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [18]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n13 [2]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux6_b3  (
    .i0(iaddr[19]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [19]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n13 [3]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux6_b4  (
    .i0(iaddr[20]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [20]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n13 [4]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux6_b5  (
    .i0(iaddr[21]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [21]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n13 [5]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 \GEN_PLUS_CORE$CORE/mux6_b6  (
    .i0(iaddr[22]),
    .i1(\GEN_PLUS_CORE$CORE/jaddr [22]),
    .sel(\GEN_PLUS_CORE$CORE/jmp ),
    .o(\GEN_PLUS_CORE$CORE/n13 [6]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  and \GEN_PLUS_CORE$CORE/mux7_b0_sel_is_5  (\GEN_PLUS_CORE$CORE/mux7_b0_sel_is_5_o , instr[0], \instr[1]_neg , instr[2]);
  and \GEN_PLUS_CORE$CORE/mux8_b0_sel_is_4  (\GEN_PLUS_CORE$CORE/mux8_b0_sel_is_4_o , \instr[0]_neg , \instr[1]_neg , instr[2]);
  and \GEN_PLUS_CORE$CORE/mux9_b0_sel_is_3  (\GEN_PLUS_CORE$CORE/mux9_b0_sel_is_3_o , instr[0], instr[1], \instr[2]_neg );
  not \GEN_PLUS_CORE$CORE/n7_inv  (\GEN_PLUS_CORE$CORE/n7_neg , \GEN_PLUS_CORE$CORE/n7 );
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg0_b0  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n34 [0]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(\GEN_PLUS_CORE$CORE/RET0 [0]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg0_b1  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n34 [1]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(\GEN_PLUS_CORE$CORE/RET0 [1]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg0_b2  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n34 [2]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(\GEN_PLUS_CORE$CORE/RET0 [2]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg0_b3  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n34 [3]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(\GEN_PLUS_CORE$CORE/RET0 [3]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg0_b4  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n34 [4]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(\GEN_PLUS_CORE$CORE/RET0 [4]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg0_b5  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n34 [5]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(\GEN_PLUS_CORE$CORE/RET0 [5]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg0_b6  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n34 [6]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(\GEN_PLUS_CORE$CORE/RET0 [6]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg0_b7  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n34 [7]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(\GEN_PLUS_CORE$CORE/RET0 [7]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg10_b0  (
    .clk(clk),
    .d(XCRo[0]),
    .en(\GEN_PLUS_CORE$CORE/mux52_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/B [0]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg10_b1  (
    .clk(clk),
    .d(XCRo[1]),
    .en(\GEN_PLUS_CORE$CORE/mux52_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/B [1]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg10_b2  (
    .clk(clk),
    .d(XCRo[2]),
    .en(\GEN_PLUS_CORE$CORE/mux52_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/B [2]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg10_b3  (
    .clk(clk),
    .d(XCRo[3]),
    .en(\GEN_PLUS_CORE$CORE/mux52_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/B [3]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg10_b4  (
    .clk(clk),
    .d(XCRo[4]),
    .en(\GEN_PLUS_CORE$CORE/mux52_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/B [4]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg10_b5  (
    .clk(clk),
    .d(XCRo[5]),
    .en(\GEN_PLUS_CORE$CORE/mux52_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/B [5]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg10_b6  (
    .clk(clk),
    .d(XCRo[6]),
    .en(\GEN_PLUS_CORE$CORE/mux52_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/B [6]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg10_b7  (
    .clk(clk),
    .d(XCRo[7]),
    .en(\GEN_PLUS_CORE$CORE/mux52_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/B [7]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg11_b0  (
    .clk(clk),
    .d(XCRo[0]),
    .en(\GEN_PLUS_CORE$CORE/mux53_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/A [0]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg11_b1  (
    .clk(clk),
    .d(XCRo[1]),
    .en(\GEN_PLUS_CORE$CORE/mux53_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/A [1]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg11_b2  (
    .clk(clk),
    .d(XCRo[2]),
    .en(\GEN_PLUS_CORE$CORE/mux53_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/A [2]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg11_b3  (
    .clk(clk),
    .d(XCRo[3]),
    .en(\GEN_PLUS_CORE$CORE/mux53_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/A [3]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg11_b4  (
    .clk(clk),
    .d(XCRo[4]),
    .en(\GEN_PLUS_CORE$CORE/mux53_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/A [4]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg11_b5  (
    .clk(clk),
    .d(XCRo[5]),
    .en(\GEN_PLUS_CORE$CORE/mux53_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/A [5]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg11_b6  (
    .clk(clk),
    .d(XCRo[6]),
    .en(\GEN_PLUS_CORE$CORE/mux53_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/A [6]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg11_b7  (
    .clk(clk),
    .d(XCRo[7]),
    .en(\GEN_PLUS_CORE$CORE/mux53_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/A [7]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg12_b0  (
    .clk(clk),
    .d(XCRo[0]),
    .en(\GEN_PLUS_CORE$CORE/mux54_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/C [0]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg12_b1  (
    .clk(clk),
    .d(XCRo[1]),
    .en(\GEN_PLUS_CORE$CORE/mux54_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/C [1]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg12_b2  (
    .clk(clk),
    .d(XCRo[2]),
    .en(\GEN_PLUS_CORE$CORE/mux54_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/C [2]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg12_b3  (
    .clk(clk),
    .d(XCRo[3]),
    .en(\GEN_PLUS_CORE$CORE/mux54_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/C [3]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg12_b4  (
    .clk(clk),
    .d(XCRo[4]),
    .en(\GEN_PLUS_CORE$CORE/mux54_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/C [4]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg12_b5  (
    .clk(clk),
    .d(XCRo[5]),
    .en(\GEN_PLUS_CORE$CORE/mux54_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/C [5]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg12_b6  (
    .clk(clk),
    .d(XCRo[6]),
    .en(\GEN_PLUS_CORE$CORE/mux54_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/C [6]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg12_b7  (
    .clk(clk),
    .d(XCRo[7]),
    .en(\GEN_PLUS_CORE$CORE/mux54_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/C [7]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg13_b0  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n6 [0]),
    .en(\GEN_PLUS_CORE$CORE/mux3_b0_sel_is_0_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg13_b1  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n6 [1]),
    .en(\GEN_PLUS_CORE$CORE/mux3_b0_sel_is_0_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg13_b10  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n6 [10]),
    .en(\GEN_PLUS_CORE$CORE/mux3_b0_sel_is_0_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[10]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg13_b11  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n6 [11]),
    .en(\GEN_PLUS_CORE$CORE/mux3_b0_sel_is_0_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[11]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg13_b12  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n6 [12]),
    .en(\GEN_PLUS_CORE$CORE/mux3_b0_sel_is_0_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[12]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg13_b13  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n6 [13]),
    .en(\GEN_PLUS_CORE$CORE/mux3_b0_sel_is_0_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[13]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg13_b14  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n6 [14]),
    .en(\GEN_PLUS_CORE$CORE/mux3_b0_sel_is_0_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[14]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg13_b15  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n6 [15]),
    .en(\GEN_PLUS_CORE$CORE/mux3_b0_sel_is_0_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[15]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg13_b16  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n6 [16]),
    .en(\GEN_PLUS_CORE$CORE/mux3_b0_sel_is_0_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[16]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg13_b17  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n6 [17]),
    .en(\GEN_PLUS_CORE$CORE/mux3_b0_sel_is_0_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[17]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg13_b18  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n6 [18]),
    .en(\GEN_PLUS_CORE$CORE/mux3_b0_sel_is_0_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[18]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg13_b19  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n6 [19]),
    .en(\GEN_PLUS_CORE$CORE/mux3_b0_sel_is_0_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[19]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg13_b2  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n6 [2]),
    .en(\GEN_PLUS_CORE$CORE/mux3_b0_sel_is_0_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg13_b20  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n6 [20]),
    .en(\GEN_PLUS_CORE$CORE/mux3_b0_sel_is_0_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[20]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg13_b21  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n6 [21]),
    .en(\GEN_PLUS_CORE$CORE/mux3_b0_sel_is_0_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[21]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg13_b22  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n6 [22]),
    .en(\GEN_PLUS_CORE$CORE/mux3_b0_sel_is_0_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[22]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg13_b3  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n6 [3]),
    .en(\GEN_PLUS_CORE$CORE/mux3_b0_sel_is_0_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg13_b4  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n6 [4]),
    .en(\GEN_PLUS_CORE$CORE/mux3_b0_sel_is_0_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg13_b5  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n6 [5]),
    .en(\GEN_PLUS_CORE$CORE/mux3_b0_sel_is_0_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg13_b6  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n6 [6]),
    .en(\GEN_PLUS_CORE$CORE/mux3_b0_sel_is_0_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg13_b7  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n6 [7]),
    .en(\GEN_PLUS_CORE$CORE/mux3_b0_sel_is_0_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[7]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg13_b8  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n6 [8]),
    .en(\GEN_PLUS_CORE$CORE/mux3_b0_sel_is_0_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[8]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg13_b9  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n6 [9]),
    .en(\GEN_PLUS_CORE$CORE/mux3_b0_sel_is_0_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[9]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg1_b0  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n35 [0]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(\GEN_PLUS_CORE$CORE/RET1 [0]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg1_b1  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n35 [1]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(\GEN_PLUS_CORE$CORE/RET1 [1]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg1_b2  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n35 [2]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(\GEN_PLUS_CORE$CORE/RET1 [2]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg1_b3  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n35 [3]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(\GEN_PLUS_CORE$CORE/RET1 [3]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg1_b4  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n35 [4]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(\GEN_PLUS_CORE$CORE/RET1 [4]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg1_b5  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n35 [5]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(\GEN_PLUS_CORE$CORE/RET1 [5]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg1_b6  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n35 [6]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(\GEN_PLUS_CORE$CORE/RET1 [6]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg1_b7  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n35 [7]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(\GEN_PLUS_CORE$CORE/RET1 [7]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg2_b0  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n36 [0]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(\GEN_PLUS_CORE$CORE/RET2 [0]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg2_b1  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n36 [1]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(\GEN_PLUS_CORE$CORE/RET2 [1]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg2_b2  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n36 [2]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(\GEN_PLUS_CORE$CORE/RET2 [2]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg2_b3  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n36 [3]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(\GEN_PLUS_CORE$CORE/RET2 [3]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg2_b4  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n36 [4]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(\GEN_PLUS_CORE$CORE/RET2 [4]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg2_b5  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n36 [5]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(\GEN_PLUS_CORE$CORE/RET2 [5]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$CORE/reg2_b6  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n36 [6]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(\GEN_PLUS_CORE$CORE/RET2 [6]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg3_b0  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n38 [0]),
    .en(~rst),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/RTA0 [0]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg3_b1  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n38 [1]),
    .en(~rst),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/RTA0 [1]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg3_b2  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n38 [2]),
    .en(~rst),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/RTA0 [2]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg3_b3  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n38 [3]),
    .en(~rst),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/RTA0 [3]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg3_b4  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n38 [4]),
    .en(~rst),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/RTA0 [4]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg3_b5  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n38 [5]),
    .en(~rst),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/RTA0 [5]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg3_b6  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n38 [6]),
    .en(~rst),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/RTA0 [6]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg3_b7  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n38 [7]),
    .en(~rst),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/RTA0 [7]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg4_b0  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n39 [0]),
    .en(~rst),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/RTA1 [0]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg4_b1  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n39 [1]),
    .en(~rst),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/RTA1 [1]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg4_b2  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n39 [2]),
    .en(~rst),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/RTA1 [2]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg4_b3  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n39 [3]),
    .en(~rst),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/RTA1 [3]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg4_b4  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n39 [4]),
    .en(~rst),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/RTA1 [4]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg4_b5  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n39 [5]),
    .en(~rst),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/RTA1 [5]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg4_b6  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n39 [6]),
    .en(~rst),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/RTA1 [6]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg4_b7  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n39 [7]),
    .en(~rst),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/RTA1 [7]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg5_b0  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n40 [0]),
    .en(~rst),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/RTA2 [0]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg5_b1  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n40 [1]),
    .en(~rst),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/RTA2 [1]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg5_b2  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n40 [2]),
    .en(~rst),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/RTA2 [2]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg5_b3  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n40 [3]),
    .en(~rst),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/RTA2 [3]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg5_b4  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n40 [4]),
    .en(~rst),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/RTA2 [4]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg5_b5  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n40 [5]),
    .en(~rst),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/RTA2 [5]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg5_b6  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n40 [6]),
    .en(~rst),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/RTA2 [6]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg5_b7  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n40 [7]),
    .en(~rst),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/RTA2 [7]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg6_b0  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n59 [0]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg6_b1  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n59 [1]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg6_b2  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n59 [2]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg6_b3  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n59 [3]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg6_b4  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n59 [4]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg6_b5  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n59 [5]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg6_b6  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n59 [6]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg6_b7  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n59 [7]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[7]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg7_b0  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n60 [0]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[8]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg7_b1  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n60 [1]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[9]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg7_b2  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n60 [2]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[10]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg7_b3  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n60 [3]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[11]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg7_b4  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n60 [4]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[12]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg7_b5  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n60 [5]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[13]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg7_b6  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n60 [6]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[14]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg7_b7  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n60 [7]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[15]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg8_b0  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n61 [0]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[16]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg8_b1  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n61 [1]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[17]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg8_b2  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n61 [2]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[18]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg8_b3  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n61 [3]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[19]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg8_b4  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n61 [4]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[20]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg8_b5  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n61 [5]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[21]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg8_b6  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n61 [6]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[22]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg8_b7  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$CORE/n61 [7]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[23]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg9_b0  (
    .clk(clk),
    .d(XCRo[0]),
    .en(\GEN_PLUS_CORE$CORE/mux51_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/D [0]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg9_b1  (
    .clk(clk),
    .d(XCRo[1]),
    .en(\GEN_PLUS_CORE$CORE/mux51_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/D [1]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg9_b2  (
    .clk(clk),
    .d(XCRo[2]),
    .en(\GEN_PLUS_CORE$CORE/mux51_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/D [2]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg9_b3  (
    .clk(clk),
    .d(XCRo[3]),
    .en(\GEN_PLUS_CORE$CORE/mux51_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/D [3]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg9_b4  (
    .clk(clk),
    .d(XCRo[4]),
    .en(\GEN_PLUS_CORE$CORE/mux51_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/D [4]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg9_b5  (
    .clk(clk),
    .d(XCRo[5]),
    .en(\GEN_PLUS_CORE$CORE/mux51_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/D [5]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg9_b6  (
    .clk(clk),
    .d(XCRo[6]),
    .en(\GEN_PLUS_CORE$CORE/mux51_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/D [6]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 \GEN_PLUS_CORE$CORE/reg9_b7  (
    .clk(clk),
    .d(XCRo[7]),
    .en(\GEN_PLUS_CORE$CORE/mux51_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$CORE/D [7]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  not \GEN_PLUS_CORE$CORE/ret_sel_inv  (\GEN_PLUS_CORE$CORE/ret_sel_neg , \GEN_PLUS_CORE$CORE/ret_sel );
  AL_MUX \GEN_PLUS_CORE$CORE/sel0_b0  (
    .i0(1'b1),
    .i1(1'b0),
    .sel(\GEN_PLUS_CORE$CORE/sel0_b0_sel_o ),
    .o(\GEN_PLUS_CORE$CORE/dbsrc_addr [0]));  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or \GEN_PLUS_CORE$CORE/sel0_b0_sel  (\GEN_PLUS_CORE$CORE/sel0_b0_sel_o , \GEN_PLUS_CORE$CORE/n66 , \GEN_PLUS_CORE$CORE/n69 );  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  AL_MUX \GEN_PLUS_CORE$CORE/sel0_b1  (
    .i0(1'b1),
    .i1(1'b0),
    .sel(\GEN_PLUS_CORE$CORE/sel0_b1_sel_o ),
    .o(\GEN_PLUS_CORE$CORE/dbsrc_addr [1]));  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or \GEN_PLUS_CORE$CORE/sel0_b1_sel  (\GEN_PLUS_CORE$CORE/sel0_b1_sel_o , XCRwe, \GEN_PLUS_CORE$CORE/n66 , \GEN_PLUS_CORE$CORE/n70 , \GEN_PLUS_CORE$CORE/n68 , \GEN_PLUS_CORE$CORE/n67 );  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  AL_MUX \GEN_PLUS_CORE$CORE/sel0_b2  (
    .i0(1'b1),
    .i1(1'b0),
    .sel(\GEN_PLUS_CORE$CORE/sel0_b2_sel_o ),
    .o(\GEN_PLUS_CORE$CORE/dbsrc_addr [2]));  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or \GEN_PLUS_CORE$CORE/sel0_b2_sel  (\GEN_PLUS_CORE$CORE/sel0_b2_sel_o , XCRwe, \GEN_PLUS_CORE$CORE/n66 , \GEN_PLUS_CORE$CORE/n71 , \GEN_PLUS_CORE$CORE/n70 , \GEN_PLUS_CORE$CORE/n69 , \GEN_PLUS_CORE$CORE/n67 );  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  AL_MUX \GEN_PLUS_CORE$CORE/sel0_b3  (
    .i0(1'b0),
    .i1(1'b1),
    .sel(\GEN_PLUS_CORE$CORE/sel0_b3_sel_o ),
    .o(\GEN_PLUS_CORE$CORE/dbsrc_addr [3]));  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or \GEN_PLUS_CORE$CORE/sel0_b3_sel  (\GEN_PLUS_CORE$CORE/sel0_b3_sel_o , \GEN_PLUS_CORE$CORE/n80 , \GEN_PLUS_CORE$CORE/jmp_en );  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  binary_mux_s4_w1 \GEN_PLUS_CORE$CORE/sel10  (
    .i0(XCRi[0]),
    .i1(\GEN_PLUS_CORE$CORE/ALU_out [0]),
    .i10(1'bx),
    .i11(1'bx),
    .i12(1'bx),
    .i13(1'bx),
    .i14(1'bx),
    .i15(1'bx),
    .i2(ddata_i[0]),
    .i3(instr[0]),
    .i4(1'bx),
    .i5(\GEN_PLUS_CORE$CORE/XREGr [0]),
    .i6(1'bx),
    .i7(\GEN_PLUS_CORE$CORE/SFTO [0]),
    .i8(1'bx),
    .i9(1'bx),
    .sel(\GEN_PLUS_CORE$CORE/dbsrc_addr ),
    .o(\GEN_PLUS_CORE$CORE/n134 ));  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  binary_mux_s4_w1 \GEN_PLUS_CORE$CORE/sel1_b0  (
    .i0(1'b0),
    .i1(1'b0),
    .i10(\GEN_PLUS_CORE$CORE/A [1]),
    .i11(1'b0),
    .i12(\GEN_PLUS_CORE$CORE/B [1]),
    .i13(\GEN_PLUS_CORE$CORE/B [1]),
    .i14(\GEN_PLUS_CORE$CORE/B [1]),
    .i15(1'b0),
    .i2(1'b0),
    .i3(1'b0),
    .i4(1'b0),
    .i5(1'b0),
    .i6(1'b0),
    .i7(1'b0),
    .i8(\GEN_PLUS_CORE$CORE/B [7]),
    .i9(\GEN_PLUS_CORE$CORE/A [1]),
    .sel(instr[15:12]),
    .o(\GEN_PLUS_CORE$CORE/SFTO [0]));  // ../../RTL/cpu/KC_LS1u_plus.v(269)
  binary_mux_s4_w1 \GEN_PLUS_CORE$CORE/sel1_b1  (
    .i0(\GEN_PLUS_CORE$CORE/A [0]),
    .i1(\GEN_PLUS_CORE$CORE/A [0]),
    .i10(\GEN_PLUS_CORE$CORE/A [2]),
    .i11(\GEN_PLUS_CORE$CORE/B [0]),
    .i12(\GEN_PLUS_CORE$CORE/B [2]),
    .i13(\GEN_PLUS_CORE$CORE/B [2]),
    .i14(\GEN_PLUS_CORE$CORE/B [2]),
    .i15(\GEN_PLUS_CORE$CORE/A [0]),
    .i2(\GEN_PLUS_CORE$CORE/A [0]),
    .i3(\GEN_PLUS_CORE$CORE/A [0]),
    .i4(\GEN_PLUS_CORE$CORE/A [0]),
    .i5(\GEN_PLUS_CORE$CORE/A [0]),
    .i6(\GEN_PLUS_CORE$CORE/A [0]),
    .i7(\GEN_PLUS_CORE$CORE/A [0]),
    .i8(\GEN_PLUS_CORE$CORE/A [0]),
    .i9(\GEN_PLUS_CORE$CORE/A [2]),
    .sel(instr[15:12]),
    .o(\GEN_PLUS_CORE$CORE/SFTO [1]));  // ../../RTL/cpu/KC_LS1u_plus.v(269)
  binary_mux_s4_w1 \GEN_PLUS_CORE$CORE/sel1_b2  (
    .i0(\GEN_PLUS_CORE$CORE/A [1]),
    .i1(\GEN_PLUS_CORE$CORE/A [1]),
    .i10(\GEN_PLUS_CORE$CORE/A [3]),
    .i11(\GEN_PLUS_CORE$CORE/B [1]),
    .i12(\GEN_PLUS_CORE$CORE/B [3]),
    .i13(\GEN_PLUS_CORE$CORE/B [3]),
    .i14(\GEN_PLUS_CORE$CORE/B [3]),
    .i15(\GEN_PLUS_CORE$CORE/A [1]),
    .i2(\GEN_PLUS_CORE$CORE/A [1]),
    .i3(\GEN_PLUS_CORE$CORE/A [1]),
    .i4(\GEN_PLUS_CORE$CORE/A [1]),
    .i5(\GEN_PLUS_CORE$CORE/A [1]),
    .i6(\GEN_PLUS_CORE$CORE/A [1]),
    .i7(\GEN_PLUS_CORE$CORE/A [1]),
    .i8(\GEN_PLUS_CORE$CORE/A [1]),
    .i9(\GEN_PLUS_CORE$CORE/A [3]),
    .sel(instr[15:12]),
    .o(\GEN_PLUS_CORE$CORE/SFTO [2]));  // ../../RTL/cpu/KC_LS1u_plus.v(269)
  binary_mux_s4_w1 \GEN_PLUS_CORE$CORE/sel1_b3  (
    .i0(\GEN_PLUS_CORE$CORE/A [2]),
    .i1(\GEN_PLUS_CORE$CORE/A [2]),
    .i10(\GEN_PLUS_CORE$CORE/A [4]),
    .i11(\GEN_PLUS_CORE$CORE/B [2]),
    .i12(\GEN_PLUS_CORE$CORE/B [4]),
    .i13(\GEN_PLUS_CORE$CORE/B [4]),
    .i14(\GEN_PLUS_CORE$CORE/B [4]),
    .i15(\GEN_PLUS_CORE$CORE/A [2]),
    .i2(\GEN_PLUS_CORE$CORE/A [2]),
    .i3(\GEN_PLUS_CORE$CORE/A [2]),
    .i4(\GEN_PLUS_CORE$CORE/A [2]),
    .i5(\GEN_PLUS_CORE$CORE/A [2]),
    .i6(\GEN_PLUS_CORE$CORE/A [2]),
    .i7(\GEN_PLUS_CORE$CORE/A [2]),
    .i8(\GEN_PLUS_CORE$CORE/A [2]),
    .i9(\GEN_PLUS_CORE$CORE/A [4]),
    .sel(instr[15:12]),
    .o(\GEN_PLUS_CORE$CORE/SFTO [3]));  // ../../RTL/cpu/KC_LS1u_plus.v(269)
  binary_mux_s4_w1 \GEN_PLUS_CORE$CORE/sel1_b4  (
    .i0(\GEN_PLUS_CORE$CORE/A [3]),
    .i1(\GEN_PLUS_CORE$CORE/A [3]),
    .i10(\GEN_PLUS_CORE$CORE/A [5]),
    .i11(\GEN_PLUS_CORE$CORE/B [3]),
    .i12(\GEN_PLUS_CORE$CORE/B [5]),
    .i13(\GEN_PLUS_CORE$CORE/B [5]),
    .i14(\GEN_PLUS_CORE$CORE/B [5]),
    .i15(\GEN_PLUS_CORE$CORE/A [3]),
    .i2(\GEN_PLUS_CORE$CORE/A [3]),
    .i3(\GEN_PLUS_CORE$CORE/A [3]),
    .i4(\GEN_PLUS_CORE$CORE/A [3]),
    .i5(\GEN_PLUS_CORE$CORE/A [3]),
    .i6(\GEN_PLUS_CORE$CORE/A [3]),
    .i7(\GEN_PLUS_CORE$CORE/A [3]),
    .i8(\GEN_PLUS_CORE$CORE/A [3]),
    .i9(\GEN_PLUS_CORE$CORE/A [5]),
    .sel(instr[15:12]),
    .o(\GEN_PLUS_CORE$CORE/SFTO [4]));  // ../../RTL/cpu/KC_LS1u_plus.v(269)
  binary_mux_s4_w1 \GEN_PLUS_CORE$CORE/sel1_b5  (
    .i0(\GEN_PLUS_CORE$CORE/A [4]),
    .i1(\GEN_PLUS_CORE$CORE/A [4]),
    .i10(\GEN_PLUS_CORE$CORE/A [6]),
    .i11(\GEN_PLUS_CORE$CORE/B [4]),
    .i12(\GEN_PLUS_CORE$CORE/B [6]),
    .i13(\GEN_PLUS_CORE$CORE/B [6]),
    .i14(\GEN_PLUS_CORE$CORE/B [6]),
    .i15(\GEN_PLUS_CORE$CORE/A [4]),
    .i2(\GEN_PLUS_CORE$CORE/A [4]),
    .i3(\GEN_PLUS_CORE$CORE/A [4]),
    .i4(\GEN_PLUS_CORE$CORE/A [4]),
    .i5(\GEN_PLUS_CORE$CORE/A [4]),
    .i6(\GEN_PLUS_CORE$CORE/A [4]),
    .i7(\GEN_PLUS_CORE$CORE/A [4]),
    .i8(\GEN_PLUS_CORE$CORE/A [4]),
    .i9(\GEN_PLUS_CORE$CORE/A [6]),
    .sel(instr[15:12]),
    .o(\GEN_PLUS_CORE$CORE/SFTO [5]));  // ../../RTL/cpu/KC_LS1u_plus.v(269)
  binary_mux_s4_w1 \GEN_PLUS_CORE$CORE/sel1_b6  (
    .i0(\GEN_PLUS_CORE$CORE/A [5]),
    .i1(\GEN_PLUS_CORE$CORE/A [5]),
    .i10(\GEN_PLUS_CORE$CORE/A [7]),
    .i11(\GEN_PLUS_CORE$CORE/B [5]),
    .i12(\GEN_PLUS_CORE$CORE/B [7]),
    .i13(\GEN_PLUS_CORE$CORE/B [7]),
    .i14(\GEN_PLUS_CORE$CORE/B [7]),
    .i15(\GEN_PLUS_CORE$CORE/A [5]),
    .i2(\GEN_PLUS_CORE$CORE/A [5]),
    .i3(\GEN_PLUS_CORE$CORE/A [5]),
    .i4(\GEN_PLUS_CORE$CORE/A [5]),
    .i5(\GEN_PLUS_CORE$CORE/A [5]),
    .i6(\GEN_PLUS_CORE$CORE/A [5]),
    .i7(\GEN_PLUS_CORE$CORE/A [5]),
    .i8(\GEN_PLUS_CORE$CORE/A [5]),
    .i9(\GEN_PLUS_CORE$CORE/A [7]),
    .sel(instr[15:12]),
    .o(\GEN_PLUS_CORE$CORE/SFTO [6]));  // ../../RTL/cpu/KC_LS1u_plus.v(269)
  binary_mux_s4_w1 \GEN_PLUS_CORE$CORE/sel1_b7  (
    .i0(\GEN_PLUS_CORE$CORE/A [6]),
    .i1(\GEN_PLUS_CORE$CORE/A [6]),
    .i10(\GEN_PLUS_CORE$CORE/A [7]),
    .i11(\GEN_PLUS_CORE$CORE/B [6]),
    .i12(1'b0),
    .i13(\GEN_PLUS_CORE$CORE/B [7]),
    .i14(\GEN_PLUS_CORE$CORE/A [0]),
    .i15(\GEN_PLUS_CORE$CORE/A [6]),
    .i2(\GEN_PLUS_CORE$CORE/A [6]),
    .i3(\GEN_PLUS_CORE$CORE/A [6]),
    .i4(\GEN_PLUS_CORE$CORE/A [6]),
    .i5(\GEN_PLUS_CORE$CORE/A [6]),
    .i6(\GEN_PLUS_CORE$CORE/A [6]),
    .i7(\GEN_PLUS_CORE$CORE/A [6]),
    .i8(\GEN_PLUS_CORE$CORE/A [6]),
    .i9(1'b0),
    .sel(instr[15:12]),
    .o(\GEN_PLUS_CORE$CORE/SFTO [7]));  // ../../RTL/cpu/KC_LS1u_plus.v(269)
  binary_mux_s4_w1 \GEN_PLUS_CORE$CORE/sel2  (
    .i0(XCRi[7]),
    .i1(\GEN_PLUS_CORE$CORE/ALU_out [7]),
    .i10(1'bx),
    .i11(1'bx),
    .i12(1'bx),
    .i13(1'bx),
    .i14(1'bx),
    .i15(1'bx),
    .i2(ddata_i[7]),
    .i3(instr[7]),
    .i4(1'bx),
    .i5(\GEN_PLUS_CORE$CORE/XREGr [7]),
    .i6(1'bx),
    .i7(\GEN_PLUS_CORE$CORE/SFTO [7]),
    .i8(1'bx),
    .i9(1'bx),
    .sel(\GEN_PLUS_CORE$CORE/dbsrc_addr ),
    .o(\GEN_PLUS_CORE$CORE/n104 ));  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  AL_MUX \GEN_PLUS_CORE$CORE/sel3  (
    .i0(1'b1),
    .i1(1'b0),
    .sel(\GEN_PLUS_CORE$CORE/n103 ),
    .o(\GEN_PLUS_CORE$CORE/n105 ));  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  binary_mux_s4_w1 \GEN_PLUS_CORE$CORE/sel4  (
    .i0(XCRi[6]),
    .i1(\GEN_PLUS_CORE$CORE/ALU_out [6]),
    .i10(1'bx),
    .i11(1'bx),
    .i12(1'bx),
    .i13(1'bx),
    .i14(1'bx),
    .i15(1'bx),
    .i2(ddata_i[6]),
    .i3(instr[6]),
    .i4(1'bx),
    .i5(\GEN_PLUS_CORE$CORE/XREGr [6]),
    .i6(1'bx),
    .i7(\GEN_PLUS_CORE$CORE/SFTO [6]),
    .i8(1'bx),
    .i9(1'bx),
    .sel(\GEN_PLUS_CORE$CORE/dbsrc_addr ),
    .o(\GEN_PLUS_CORE$CORE/n106 ));  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  binary_mux_s4_w1 \GEN_PLUS_CORE$CORE/sel5  (
    .i0(XCRi[5]),
    .i1(\GEN_PLUS_CORE$CORE/ALU_out [5]),
    .i10(1'bx),
    .i11(1'bx),
    .i12(1'bx),
    .i13(1'bx),
    .i14(1'bx),
    .i15(1'bx),
    .i2(ddata_i[5]),
    .i3(instr[5]),
    .i4(1'bx),
    .i5(\GEN_PLUS_CORE$CORE/XREGr [5]),
    .i6(1'bx),
    .i7(\GEN_PLUS_CORE$CORE/SFTO [5]),
    .i8(1'bx),
    .i9(1'bx),
    .sel(\GEN_PLUS_CORE$CORE/dbsrc_addr ),
    .o(\GEN_PLUS_CORE$CORE/n109 ));  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  binary_mux_s4_w1 \GEN_PLUS_CORE$CORE/sel6  (
    .i0(XCRi[4]),
    .i1(\GEN_PLUS_CORE$CORE/ALU_out [4]),
    .i10(1'bx),
    .i11(1'bx),
    .i12(1'bx),
    .i13(1'bx),
    .i14(1'bx),
    .i15(1'bx),
    .i2(ddata_i[4]),
    .i3(instr[4]),
    .i4(1'bx),
    .i5(\GEN_PLUS_CORE$CORE/XREGr [4]),
    .i6(1'bx),
    .i7(\GEN_PLUS_CORE$CORE/SFTO [4]),
    .i8(1'bx),
    .i9(1'bx),
    .sel(\GEN_PLUS_CORE$CORE/dbsrc_addr ),
    .o(\GEN_PLUS_CORE$CORE/n114 ));  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  binary_mux_s4_w1 \GEN_PLUS_CORE$CORE/sel7  (
    .i0(XCRi[3]),
    .i1(\GEN_PLUS_CORE$CORE/ALU_out [3]),
    .i10(1'bx),
    .i11(1'bx),
    .i12(1'bx),
    .i13(1'bx),
    .i14(1'bx),
    .i15(1'bx),
    .i2(ddata_i[3]),
    .i3(instr[3]),
    .i4(1'bx),
    .i5(\GEN_PLUS_CORE$CORE/XREGr [3]),
    .i6(1'bx),
    .i7(\GEN_PLUS_CORE$CORE/SFTO [3]),
    .i8(1'bx),
    .i9(1'bx),
    .sel(\GEN_PLUS_CORE$CORE/dbsrc_addr ),
    .o(\GEN_PLUS_CORE$CORE/n119 ));  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  binary_mux_s4_w1 \GEN_PLUS_CORE$CORE/sel8  (
    .i0(XCRi[2]),
    .i1(\GEN_PLUS_CORE$CORE/ALU_out [2]),
    .i10(1'bx),
    .i11(1'bx),
    .i12(1'bx),
    .i13(1'bx),
    .i14(1'bx),
    .i15(1'bx),
    .i2(ddata_i[2]),
    .i3(instr[2]),
    .i4(1'bx),
    .i5(\GEN_PLUS_CORE$CORE/XREGr [2]),
    .i6(1'bx),
    .i7(\GEN_PLUS_CORE$CORE/SFTO [2]),
    .i8(1'bx),
    .i9(1'bx),
    .sel(\GEN_PLUS_CORE$CORE/dbsrc_addr ),
    .o(\GEN_PLUS_CORE$CORE/n124 ));  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  binary_mux_s4_w1 \GEN_PLUS_CORE$CORE/sel9  (
    .i0(XCRi[1]),
    .i1(\GEN_PLUS_CORE$CORE/ALU_out [1]),
    .i10(1'bx),
    .i11(1'bx),
    .i12(1'bx),
    .i13(1'bx),
    .i14(1'bx),
    .i15(1'bx),
    .i2(ddata_i[1]),
    .i3(instr[1]),
    .i4(1'bx),
    .i5(\GEN_PLUS_CORE$CORE/XREGr [1]),
    .i6(1'bx),
    .i7(\GEN_PLUS_CORE$CORE/SFTO [1]),
    .i8(1'bx),
    .i9(1'bx),
    .sel(\GEN_PLUS_CORE$CORE/dbsrc_addr ),
    .o(\GEN_PLUS_CORE$CORE/n129 ));  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  or \GEN_PLUS_CORE$CORE/u10  (\GEN_PLUS_CORE$CORE/n4 , dread, \GEN_PLUS_CORE$CORE/n3 );  // ../../RTL/cpu/KC_LS1u_plus.v(40)
  and \GEN_PLUS_CORE$CORE/u103  (dwrite, \GEN_PLUS_CORE$CORE/n44 , \GEN_PLUS_CORE$CORE/n1 );  // ../../RTL/cpu/KC_LS1u_plus.v(320)
  and \GEN_PLUS_CORE$CORE/u11  (\GEN_PLUS_CORE$CORE/INSTR_HOLD , \GEN_PLUS_CORE$CORE/n4 , n0);  // ../../RTL/cpu/KC_LS1u_plus.v(40)
  or \GEN_PLUS_CORE$CORE/u12  (\GEN_PLUS_CORE$CORE/n7 , \GEN_PLUS_CORE$CORE/instr_wait , \GEN_PLUS_CORE$CORE/INSTR_HOLD );  // ../../RTL/cpu/KC_LS1u_plus.v(56)
  AL_MUX \GEN_PLUS_CORE$CORE/u126  (
    .i0(daddr[1]),
    .i1(\GEN_PLUS_CORE$CORE/RET0 [1]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/jaddr [1]));
  AL_MUX \GEN_PLUS_CORE$CORE/u127  (
    .i0(daddr[2]),
    .i1(\GEN_PLUS_CORE$CORE/RET0 [2]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/jaddr [2]));
  AL_MUX \GEN_PLUS_CORE$CORE/u128  (
    .i0(daddr[3]),
    .i1(\GEN_PLUS_CORE$CORE/RET0 [3]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/jaddr [3]));
  AL_MUX \GEN_PLUS_CORE$CORE/u129  (
    .i0(daddr[4]),
    .i1(\GEN_PLUS_CORE$CORE/RET0 [4]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/jaddr [4]));
  not \GEN_PLUS_CORE$CORE/u13  (\GEN_PLUS_CORE$CORE/n9 , \GEN_PLUS_CORE$CORE/instr_wait );  // ../../RTL/cpu/KC_LS1u_plus.v(71)
  AL_MUX \GEN_PLUS_CORE$CORE/u130  (
    .i0(daddr[5]),
    .i1(\GEN_PLUS_CORE$CORE/RET0 [5]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/jaddr [5]));
  AL_MUX \GEN_PLUS_CORE$CORE/u131  (
    .i0(daddr[6]),
    .i1(\GEN_PLUS_CORE$CORE/RET0 [6]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/jaddr [6]));
  AL_MUX \GEN_PLUS_CORE$CORE/u132  (
    .i0(daddr[7]),
    .i1(\GEN_PLUS_CORE$CORE/RET0 [7]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/jaddr [7]));
  AL_MUX \GEN_PLUS_CORE$CORE/u133  (
    .i0(daddr[8]),
    .i1(\GEN_PLUS_CORE$CORE/RET1 [0]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/jaddr [8]));
  AL_MUX \GEN_PLUS_CORE$CORE/u134  (
    .i0(daddr[9]),
    .i1(\GEN_PLUS_CORE$CORE/RET1 [1]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/jaddr [9]));
  AL_MUX \GEN_PLUS_CORE$CORE/u135  (
    .i0(daddr[10]),
    .i1(\GEN_PLUS_CORE$CORE/RET1 [2]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/jaddr [10]));
  AL_MUX \GEN_PLUS_CORE$CORE/u136  (
    .i0(daddr[11]),
    .i1(\GEN_PLUS_CORE$CORE/RET1 [3]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/jaddr [11]));
  AL_MUX \GEN_PLUS_CORE$CORE/u137  (
    .i0(daddr[12]),
    .i1(\GEN_PLUS_CORE$CORE/RET1 [4]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/jaddr [12]));
  AL_MUX \GEN_PLUS_CORE$CORE/u138  (
    .i0(daddr[13]),
    .i1(\GEN_PLUS_CORE$CORE/RET1 [5]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/jaddr [13]));
  AL_MUX \GEN_PLUS_CORE$CORE/u139  (
    .i0(daddr[14]),
    .i1(\GEN_PLUS_CORE$CORE/RET1 [6]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/jaddr [14]));
  and \GEN_PLUS_CORE$CORE/u14  (\GEN_PLUS_CORE$CORE/n10 , \GEN_PLUS_CORE$CORE/int_filter , \GEN_PLUS_CORE$CORE/n9 );  // ../../RTL/cpu/KC_LS1u_plus.v(71)
  AL_MUX \GEN_PLUS_CORE$CORE/u140  (
    .i0(daddr[15]),
    .i1(\GEN_PLUS_CORE$CORE/RET1 [7]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/jaddr [15]));
  AL_MUX \GEN_PLUS_CORE$CORE/u141  (
    .i0(daddr[16]),
    .i1(\GEN_PLUS_CORE$CORE/RET2 [0]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/jaddr [16]));
  AL_MUX \GEN_PLUS_CORE$CORE/u142  (
    .i0(daddr[17]),
    .i1(\GEN_PLUS_CORE$CORE/RET2 [1]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/jaddr [17]));
  AL_MUX \GEN_PLUS_CORE$CORE/u143  (
    .i0(daddr[18]),
    .i1(\GEN_PLUS_CORE$CORE/RET2 [2]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/jaddr [18]));
  AL_MUX \GEN_PLUS_CORE$CORE/u144  (
    .i0(daddr[19]),
    .i1(\GEN_PLUS_CORE$CORE/RET2 [3]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/jaddr [19]));
  AL_MUX \GEN_PLUS_CORE$CORE/u145  (
    .i0(daddr[20]),
    .i1(\GEN_PLUS_CORE$CORE/RET2 [4]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/jaddr [20]));
  AL_MUX \GEN_PLUS_CORE$CORE/u146  (
    .i0(daddr[21]),
    .i1(\GEN_PLUS_CORE$CORE/RET2 [5]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/jaddr [21]));
  AL_MUX \GEN_PLUS_CORE$CORE/u147  (
    .i0(daddr[22]),
    .i1(\GEN_PLUS_CORE$CORE/RET2 [6]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/jaddr [22]));
  or \GEN_PLUS_CORE$CORE/u151  (\GEN_PLUS_CORE$CORE/n141 , \GEN_PLUS_CORE$CORE/n102 , \GEN_PLUS_CORE$CORE/n142 );  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  or \GEN_PLUS_CORE$CORE/u152  (\GEN_PLUS_CORE$CORE/n140 , \GEN_PLUS_CORE$CORE/n98 , \GEN_PLUS_CORE$CORE/n97 );  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  or \GEN_PLUS_CORE$CORE/u153  (\GEN_PLUS_CORE$CORE/n99 , dread, \GEN_PLUS_CORE$CORE/n140 );  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  or \GEN_PLUS_CORE$CORE/u154  (\GEN_PLUS_CORE$CORE/n136 , \GEN_PLUS_CORE$CORE/n141 , \GEN_PLUS_CORE$CORE/n99 );  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  not \GEN_PLUS_CORE$CORE/u155  (\GEN_PLUS_CORE$CORE/n103 , \GEN_PLUS_CORE$CORE/n136 );  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  and \GEN_PLUS_CORE$CORE/u16  (\GEN_PLUS_CORE$CORE/n14 , XCRwe, \GEN_PLUS_CORE$CORE/n9 );  // ../../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MUX \GEN_PLUS_CORE$CORE/u17  (
    .i0(\GEN_PLUS_CORE$CORE/IN_ISP ),
    .i1(1'b0),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/n27 ));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  AL_MUX \GEN_PLUS_CORE$CORE/u18  (
    .i0(\GEN_PLUS_CORE$CORE/n27 ),
    .i1(1'b1),
    .sel(\GEN_PLUS_CORE$CORE/n10 ),
    .o(\GEN_PLUS_CORE$CORE/n37 ));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  and \GEN_PLUS_CORE$CORE/u20  (\GEN_PLUS_CORE$CORE/n44 , \GEN_PLUS_CORE$CORE/regwrite , \GEN_PLUS_CORE$CORE/n9 );  // ../../RTL/cpu/KC_LS1u_plus.v(111)
  or \GEN_PLUS_CORE$CORE/u227  (\GEN_PLUS_CORE$CORE/n81 , \GEN_PLUS_CORE$CORE/n80 , \GEN_PLUS_CORE$CORE/n126 );  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or \GEN_PLUS_CORE$CORE/u228  (\GEN_PLUS_CORE$CORE/n123 , \GEN_PLUS_CORE$CORE/n77 , \GEN_PLUS_CORE$CORE/n76 );  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or \GEN_PLUS_CORE$CORE/u229  (\GEN_PLUS_CORE$CORE/n122 , \GEN_PLUS_CORE$CORE/n125 , \GEN_PLUS_CORE$CORE/n123 );  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or \GEN_PLUS_CORE$CORE/u230  (\GEN_PLUS_CORE$CORE/n121 , \GEN_PLUS_CORE$CORE/n75 , \GEN_PLUS_CORE$CORE/n74 );  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or \GEN_PLUS_CORE$CORE/u231  (\GEN_PLUS_CORE$CORE/n120 , \GEN_PLUS_CORE$CORE/n73 , \GEN_PLUS_CORE$CORE/n72 );  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or \GEN_PLUS_CORE$CORE/u232  (\GEN_PLUS_CORE$CORE/n118 , \GEN_PLUS_CORE$CORE/n121 , \GEN_PLUS_CORE$CORE/n120 );  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or \GEN_PLUS_CORE$CORE/u233  (\GEN_PLUS_CORE$CORE/n117 , \GEN_PLUS_CORE$CORE/n122 , \GEN_PLUS_CORE$CORE/n118 );  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or \GEN_PLUS_CORE$CORE/u234  (XCRcs, XCRwe, \GEN_PLUS_CORE$CORE/n66 );  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or \GEN_PLUS_CORE$CORE/u235  (\GEN_PLUS_CORE$CORE/n115 , \GEN_PLUS_CORE$CORE/n71 , \GEN_PLUS_CORE$CORE/n70 );  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or \GEN_PLUS_CORE$CORE/u236  (\GEN_PLUS_CORE$CORE/n113 , XCRcs, \GEN_PLUS_CORE$CORE/n115 );  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or \GEN_PLUS_CORE$CORE/u237  (\GEN_PLUS_CORE$CORE/n112 , \GEN_PLUS_CORE$CORE/n69 , \GEN_PLUS_CORE$CORE/n68 );  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or \GEN_PLUS_CORE$CORE/u238  (\GEN_PLUS_CORE$CORE/n111 , \GEN_PLUS_CORE$CORE/n67 , \GEN_PLUS_CORE$CORE/jmp_en );  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or \GEN_PLUS_CORE$CORE/u239  (\GEN_PLUS_CORE$CORE/n110 , \GEN_PLUS_CORE$CORE/n112 , \GEN_PLUS_CORE$CORE/n111 );  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or \GEN_PLUS_CORE$CORE/u240  (\GEN_PLUS_CORE$CORE/n108 , \GEN_PLUS_CORE$CORE/n113 , \GEN_PLUS_CORE$CORE/n110 );  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or \GEN_PLUS_CORE$CORE/u241  (\GEN_PLUS_CORE$CORE/n107 , \GEN_PLUS_CORE$CORE/n117 , \GEN_PLUS_CORE$CORE/n108 );  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  not \GEN_PLUS_CORE$CORE/u242  (\GEN_PLUS_CORE$CORE/n80 , \GEN_PLUS_CORE$CORE/n107 );  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or \GEN_PLUS_CORE$CORE/u31  (\GEN_PLUS_CORE$CORE/n125 , \GEN_PLUS_CORE$CORE/n79 , \GEN_PLUS_CORE$CORE/n78 );  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  not \GEN_PLUS_CORE$CORE/u33  (\GEN_PLUS_CORE$CORE/regwrite , \GEN_PLUS_CORE$CORE/n81 );  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or \GEN_PLUS_CORE$CORE/u34  (\GEN_PLUS_CORE$CORE/n126 , XCRwe, \GEN_PLUS_CORE$CORE/jmp_en );  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  and \GEN_PLUS_CORE$CORE/u38  (\GEN_PLUS_CORE$CORE/ALU_eqo , \GEN_PLUS_CORE$CORE/ALU_eq [0], \GEN_PLUS_CORE$CORE/ALU_eq [1]);  // ../../RTL/cpu/KC_LS1u_plus.v(226)
  not \GEN_PLUS_CORE$CORE/u41  (\GEN_PLUS_CORE$CORE/n92 , \GEN_PLUS_CORE$CORE/A [7]);  // ../../RTL/cpu/KC_LS1u_plus.v(278)
  not \GEN_PLUS_CORE$CORE/u43  (\GEN_PLUS_CORE$CORE/n94 , \GEN_PLUS_CORE$CORE/ALU_eqo );  // ../../RTL/cpu/KC_LS1u_plus.v(280)
  AL_MUX \GEN_PLUS_CORE$CORE/u45  (
    .i0(1'b0),
    .i1(\GEN_PLUS_CORE$CORE/n91 ),
    .sel(\GEN_PLUS_CORE$CORE/jmp_en ),
    .o(\GEN_PLUS_CORE$CORE/ret_sel ));  // ../../RTL/cpu/KC_LS1u_plus.v(286)
  AL_MUX \GEN_PLUS_CORE$CORE/u46  (
    .i0(1'b0),
    .i1(\GEN_PLUS_CORE$CORE/n96 ),
    .sel(\GEN_PLUS_CORE$CORE/jmp_en ),
    .o(\GEN_PLUS_CORE$CORE/jmp ));  // ../../RTL/cpu/KC_LS1u_plus.v(286)
  not \GEN_PLUS_CORE$CORE/u5  (\GEN_PLUS_CORE$CORE/n0 , \GEN_PLUS_CORE$CORE/IN_ISP );  // ../../RTL/cpu/KC_LS1u_plus.v(36)
  and \GEN_PLUS_CORE$CORE/u53_and  (XCRo[0], \GEN_PLUS_CORE$CORE/n134 , \GEN_PLUS_CORE$CORE/n105 );
  and \GEN_PLUS_CORE$CORE/u58_and  (XCRo[1], \GEN_PLUS_CORE$CORE/n129 , \GEN_PLUS_CORE$CORE/n105 );
  and \GEN_PLUS_CORE$CORE/u6  (\GEN_PLUS_CORE$CORE/int_filter , INT_Req, \GEN_PLUS_CORE$CORE/n0 );  // ../../RTL/cpu/KC_LS1u_plus.v(36)
  and \GEN_PLUS_CORE$CORE/u63_and  (XCRo[2], \GEN_PLUS_CORE$CORE/n124 , \GEN_PLUS_CORE$CORE/n105 );
  and \GEN_PLUS_CORE$CORE/u68_and  (XCRo[3], \GEN_PLUS_CORE$CORE/n119 , \GEN_PLUS_CORE$CORE/n105 );
  or \GEN_PLUS_CORE$CORE/u7  (\GEN_PLUS_CORE$CORE/instr_wait , n0, \GEN_PLUS_CORE$CORE/jmp_wait );  // ../../RTL/cpu/KC_LS1u_plus.v(39)
  and \GEN_PLUS_CORE$CORE/u73_and  (XCRo[4], \GEN_PLUS_CORE$CORE/n114 , \GEN_PLUS_CORE$CORE/n105 );
  and \GEN_PLUS_CORE$CORE/u78_and  (XCRo[5], \GEN_PLUS_CORE$CORE/n109 , \GEN_PLUS_CORE$CORE/n105 );
  and \GEN_PLUS_CORE$CORE/u8  (\GEN_PLUS_CORE$CORE/n2 , \GEN_PLUS_CORE$CORE/regwrite , \GEN_PLUS_CORE$CORE/n1 );  // ../../RTL/cpu/KC_LS1u_plus.v(40)
  and \GEN_PLUS_CORE$CORE/u83_and  (XCRo[6], \GEN_PLUS_CORE$CORE/n106 , \GEN_PLUS_CORE$CORE/n105 );
  and \GEN_PLUS_CORE$CORE/u88_and  (XCRo[7], \GEN_PLUS_CORE$CORE/n104 , \GEN_PLUS_CORE$CORE/n105 );
  or \GEN_PLUS_CORE$CORE/u89  (\GEN_PLUS_CORE$CORE/n142 , \GEN_PLUS_CORE$CORE/n101 , \GEN_PLUS_CORE$CORE/n100 );  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  or \GEN_PLUS_CORE$CORE/u9  (\GEN_PLUS_CORE$CORE/n3 , \GEN_PLUS_CORE$CORE/n2 , dwrite);  // ../../RTL/cpu/KC_LS1u_plus.v(40)
  AL_MUX \GEN_PLUS_CORE$CORE/u94  (
    .i0(daddr[0]),
    .i1(\GEN_PLUS_CORE$CORE/RET0 [0]),
    .sel(\GEN_PLUS_CORE$CORE/ret_sel ),
    .o(\GEN_PLUS_CORE$CORE/jaddr [0]));
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INT_reg  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n2 ),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .q(INT_Req));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  binary_mux_s1_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/mux0_b0  (
    .i0(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_select_encode[7] [0]),
    .i1(1'b0),
    .sel(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTC [0]),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/shift_stages[1] [0]));  // ../../RTL/peripherals/left_bshifter.v(22)
  binary_mux_s1_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/mux0_b1  (
    .i0(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_select_encode[7] [1]),
    .i1(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_select_encode[7] [0]),
    .sel(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTC [0]),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/shift_stages[1] [1]));  // ../../RTL/peripherals/left_bshifter.v(22)
  binary_mux_s1_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/mux0_b2  (
    .i0(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_select_encode[7] [2]),
    .i1(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_select_encode[7] [1]),
    .sel(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTC [0]),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/shift_stages[1] [2]));  // ../../RTL/peripherals/left_bshifter.v(22)
  binary_mux_s1_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/mux0_b3  (
    .i0(1'b0),
    .i1(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_select_encode[7] [2]),
    .sel(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTC [0]),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/shift_stages[1] [3]));  // ../../RTL/peripherals/left_bshifter.v(22)
  binary_mux_s1_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/mux1_b0  (
    .i0(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/shift_stages[1] [0]),
    .i1(1'b0),
    .sel(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTC [1]),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/shift_stages[2] [0]));  // ../../RTL/peripherals/left_bshifter.v(22)
  binary_mux_s1_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/mux1_b1  (
    .i0(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/shift_stages[1] [1]),
    .i1(1'b0),
    .sel(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTC [1]),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/shift_stages[2] [1]));  // ../../RTL/peripherals/left_bshifter.v(22)
  binary_mux_s1_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/mux1_b2  (
    .i0(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/shift_stages[1] [2]),
    .i1(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/shift_stages[1] [0]),
    .sel(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTC [1]),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/shift_stages[2] [2]));  // ../../RTL/peripherals/left_bshifter.v(22)
  binary_mux_s1_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/mux1_b3  (
    .i0(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/shift_stages[1] [3]),
    .i1(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/shift_stages[1] [1]),
    .sel(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTC [1]),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/shift_stages[2] [3]));  // ../../RTL/peripherals/left_bshifter.v(22)
  binary_mux_s1_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/mux1_b4  (
    .i0(1'b0),
    .i1(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/shift_stages[1] [2]),
    .sel(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTC [1]),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/shift_stages[2] [4]));  // ../../RTL/peripherals/left_bshifter.v(22)
  binary_mux_s1_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/mux1_b5  (
    .i0(1'b0),
    .i1(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/shift_stages[1] [3]),
    .sel(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTC [1]),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/shift_stages[2] [5]));  // ../../RTL/peripherals/left_bshifter.v(22)
  add_pu21_pu21_o21 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/add0  (
    .i0({\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT2 [6:0],\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT1 ,\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT0 [7:2]}),
    .i1({15'b000000000000000,\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVE_SIZE_SHIFTER/shift_stages[2] [5:0]}),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n1 [20:0]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(79)
  not \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked[2]_inv  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked[2]_neg , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked [2]);
  not \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked[3]_inv  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked[3]_neg , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked [3]);
  not \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked[4]_inv  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked[4]_neg , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked [4]);
  not \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked[5]_inv  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked[5]_neg , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked [5]);
  not \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked[6]_inv  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked[6]_neg , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked [6]);
  not \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked[7]_inv  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked[7]_neg , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked [7]);
  binary_mux_s1_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux0_b0  (
    .i0(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked [1]),
    .i1(1'b0),
    .sel(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked [2]),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_select_encode[2] [0]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(144)
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux14_b0_sel_is_3  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux14_b0_sel_is_3_o , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n5 , \GEN_PLUS_CORE$CORE/mux7_b0_sel_is_5_o );
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux15_b0_sel_is_3  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux15_b0_sel_is_3_o , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n5 , \GEN_PLUS_CORE$CORE/mux8_b0_sel_is_4_o );
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux16_b0_sel_is_3  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux16_b0_sel_is_3_o , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n5 , \GEN_PLUS_CORE$CORE/mux9_b0_sel_is_3_o );
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux17_b0_sel_is_3  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux17_b0_sel_is_3_o , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n5 , \GEN_PLUS_CORE$CORE/mux10_b0_sel_is_2_o );
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux18_b0_sel_is_3  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux18_b0_sel_is_3_o , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n5 , \GEN_PLUS_CORE$CORE/mux11_b0_sel_is_1_o );
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux19_b0_sel_is_3  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux19_b0_sel_is_3_o , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n5 , \GEN_PLUS_CORE$CORE/mux12_b0_sel_is_0_o );
  binary_mux_s1_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux1_b0  (
    .i0(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_select_encode[2] [0]),
    .i1(1'b1),
    .sel(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked [3]),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_select_encode[3] [0]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(144)
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux1_b1_sel_is_0  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux1_b1_sel_is_0_o , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked[3]_neg , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked[2]_neg );
  not \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux1_b1_sel_is_0_o_inv  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux1_b1_sel_is_0_o_neg , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux1_b1_sel_is_0_o );
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux20_b0_sel_is_2  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux20_b0_sel_is_2_o , rst_neg, \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux14_b0_sel_is_3_o );
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux21_b0_sel_is_2  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux21_b0_sel_is_2_o , rst_neg, \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux15_b0_sel_is_3_o );
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux22_b0_sel_is_2  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux22_b0_sel_is_2_o , rst_neg, \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux16_b0_sel_is_3_o );
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux23_b0_sel_is_2  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux23_b0_sel_is_2_o , rst_neg, \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux17_b0_sel_is_3_o );
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux24_b0_sel_is_2  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux24_b0_sel_is_2_o , rst_neg, \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux18_b0_sel_is_3_o );
  binary_mux_s3_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux25_b0  (
    .i0(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTC [0]),
    .i1(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT0 [0]),
    .i2(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT1 [0]),
    .i3(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT2 [0]),
    .i4(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTE0 [0]),
    .i5(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/EXPE0 [0]),
    .i6(1'bx),
    .i7(1'bx),
    .sel(instr[2:0]),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n23 [0]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(134)
  binary_mux_s3_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux25_b1  (
    .i0(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTC [1]),
    .i1(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT0 [1]),
    .i2(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT1 [1]),
    .i3(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT2 [1]),
    .i4(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTE0 [1]),
    .i5(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/EXPE0 [1]),
    .i6(1'bx),
    .i7(1'bx),
    .sel(instr[2:0]),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n23 [1]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(134)
  binary_mux_s3_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux25_b2  (
    .i0(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTC [2]),
    .i1(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT0 [2]),
    .i2(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT1 [2]),
    .i3(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT2 [2]),
    .i4(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTE0 [2]),
    .i5(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/EXPE0 [2]),
    .i6(1'bx),
    .i7(1'bx),
    .sel(instr[2:0]),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n23 [2]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(134)
  binary_mux_s3_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux25_b3  (
    .i0(1'b0),
    .i1(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT0 [3]),
    .i2(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT1 [3]),
    .i3(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT2 [3]),
    .i4(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTE0 [3]),
    .i5(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/EXPE0 [3]),
    .i6(1'bx),
    .i7(1'bx),
    .sel(instr[2:0]),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n23 [3]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(134)
  binary_mux_s3_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux25_b4  (
    .i0(1'b0),
    .i1(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT0 [4]),
    .i2(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT1 [4]),
    .i3(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT2 [4]),
    .i4(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTE0 [4]),
    .i5(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/EXPE0 [4]),
    .i6(1'bx),
    .i7(1'bx),
    .sel(instr[2:0]),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n23 [4]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(134)
  binary_mux_s3_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux25_b5  (
    .i0(1'b0),
    .i1(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT0 [5]),
    .i2(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT1 [5]),
    .i3(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT2 [5]),
    .i4(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTE0 [5]),
    .i5(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/EXPE0 [5]),
    .i6(1'bx),
    .i7(1'bx),
    .sel(instr[2:0]),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n23 [5]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(134)
  binary_mux_s3_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux25_b6  (
    .i0(1'b0),
    .i1(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT0 [6]),
    .i2(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT1 [6]),
    .i3(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT2 [6]),
    .i4(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTE0 [6]),
    .i5(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/EXPE0 [6]),
    .i6(1'bx),
    .i7(1'bx),
    .sel(instr[2:0]),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n23 [6]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(134)
  binary_mux_s3_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux25_b7  (
    .i0(1'b0),
    .i1(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT0 [7]),
    .i2(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT1 [7]),
    .i3(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT2 [7]),
    .i4(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTE0 [7]),
    .i5(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/EXPE0 [7]),
    .i6(1'bx),
    .i7(1'bx),
    .sel(instr[2:0]),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n23 [7]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(134)
  binary_mux_s3_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux26  (
    .i0(1'b1),
    .i1(1'b1),
    .i2(1'b1),
    .i3(1'b1),
    .i4(1'b1),
    .i5(1'b1),
    .i6(1'b0),
    .i7(1'b0),
    .sel(instr[2:0]),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n24 ));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(134)
  binary_mux_s1_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux2_b0  (
    .i0(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_select_encode[3] [0]),
    .i1(1'b0),
    .sel(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked [4]),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_select_encode[4] [0]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(144)
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux2_b1_sel_is_0  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux2_b1_sel_is_0_o , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked[4]_neg , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux1_b1_sel_is_0_o_neg );
  binary_mux_s1_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux3_b0  (
    .i0(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_select_encode[4] [0]),
    .i1(1'b1),
    .sel(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked [5]),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_select_encode[5] [0]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(144)
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux3_b1_sel_is_2  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux3_b1_sel_is_2_o , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked[5]_neg , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux2_b1_sel_is_0_o );
  not \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux3_b1_sel_is_2_o_inv  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux3_b1_sel_is_2_o_neg , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux3_b1_sel_is_2_o );
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux3_b2_sel_is_0  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux3_b2_sel_is_0_o , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked[5]_neg , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked[4]_neg );
  binary_mux_s1_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux4_b0  (
    .i0(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_select_encode[5] [0]),
    .i1(1'b0),
    .sel(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked [6]),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_select_encode[6] [0]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(144)
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux4_b1_sel_is_0  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux4_b1_sel_is_0_o , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked[6]_neg , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux3_b1_sel_is_2_o_neg );
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux4_b2_sel_is_2  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux4_b2_sel_is_2_o , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked[6]_neg , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux3_b2_sel_is_0_o );
  binary_mux_s1_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux5_b0  (
    .i0(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_select_encode[6] [0]),
    .i1(1'b1),
    .sel(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked [7]),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_select_encode[7] [0]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(144)
  AL_MUX \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux5_b1  (
    .i0(1'b1),
    .i1(1'b0),
    .sel(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux5_b1_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_select_encode[7] [1]));
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux5_b1_sel_is_2  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux5_b1_sel_is_2_o , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked[7]_neg , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux4_b1_sel_is_0_o );
  AL_MUX \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux5_b2  (
    .i0(1'b1),
    .i1(1'b0),
    .sel(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux5_b2_sel_is_2_o ),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_select_encode[7] [2]));
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux5_b2_sel_is_2  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux5_b2_sel_is_2_o , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked[7]_neg , \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux4_b2_sel_is_2_o );
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux7_b0_sel_is_2  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux7_b0_sel_is_2_o , rst_neg, \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTC [2]);
  ne_w8 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/neq0  (
    .i0(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked ),
    .i1(8'b00000000),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n0 ));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(78)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg0_b0  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT0 [0]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux7_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_addr[0]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg0_b1  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT0 [1]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux7_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_addr[1]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg0_b10  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n1 [8]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux7_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_addr[10]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg0_b11  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n1 [9]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux7_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_addr[11]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg0_b12  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n1 [10]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux7_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_addr[12]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg0_b13  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n1 [11]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux7_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_addr[13]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg0_b14  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n1 [12]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux7_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_addr[14]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg0_b15  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n1 [13]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux7_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_addr[15]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg0_b16  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n1 [14]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux7_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_addr[16]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg0_b17  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n1 [15]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux7_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_addr[17]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg0_b18  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n1 [16]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux7_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_addr[18]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg0_b19  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n1 [17]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux7_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_addr[19]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg0_b2  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n1 [0]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux7_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_addr[2]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg0_b20  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n1 [18]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux7_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_addr[20]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg0_b21  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n1 [19]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux7_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_addr[21]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg0_b22  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n1 [20]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux7_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_addr[22]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg0_b3  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n1 [1]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux7_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_addr[3]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg0_b4  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n1 [2]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux7_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_addr[4]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg0_b5  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n1 [3]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux7_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_addr[5]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg0_b6  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n1 [4]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux7_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_addr[6]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg0_b7  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n1 [5]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux7_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_addr[7]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg0_b8  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n1 [6]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux7_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_addr[8]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg0_b9  (
    .clk(clk),
    .d(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n1 [7]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux7_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_addr[9]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg1_b0  (
    .clk(clk),
    .d(XCRo[0]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux19_b0_sel_is_3_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTC [0]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg1_b1  (
    .clk(clk),
    .d(XCRo[1]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux19_b0_sel_is_3_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTC [1]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg1_b2  (
    .clk(clk),
    .d(XCRo[7]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux19_b0_sel_is_3_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTC [2]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg2_b0  (
    .clk(clk),
    .d(XCRo[0]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux20_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/EXPE0 [0]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg2_b1  (
    .clk(clk),
    .d(XCRo[1]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux20_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/EXPE0 [1]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg2_b2  (
    .clk(clk),
    .d(XCRo[2]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux20_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/EXPE0 [2]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg2_b3  (
    .clk(clk),
    .d(XCRo[3]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux20_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/EXPE0 [3]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg2_b4  (
    .clk(clk),
    .d(XCRo[4]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux20_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/EXPE0 [4]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg2_b5  (
    .clk(clk),
    .d(XCRo[5]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux20_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/EXPE0 [5]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg2_b6  (
    .clk(clk),
    .d(XCRo[6]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux20_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/EXPE0 [6]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg2_b7  (
    .clk(clk),
    .d(XCRo[7]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux20_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/EXPE0 [7]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg3_b0  (
    .clk(clk),
    .d(XCRo[0]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux21_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTE0 [0]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg3_b1  (
    .clk(clk),
    .d(XCRo[1]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux21_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTE0 [1]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg3_b2  (
    .clk(clk),
    .d(XCRo[2]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux21_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTE0 [2]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg3_b3  (
    .clk(clk),
    .d(XCRo[3]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux21_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTE0 [3]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg3_b4  (
    .clk(clk),
    .d(XCRo[4]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux21_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTE0 [4]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg3_b5  (
    .clk(clk),
    .d(XCRo[5]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux21_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTE0 [5]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg3_b6  (
    .clk(clk),
    .d(XCRo[6]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux21_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTE0 [6]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg3_b7  (
    .clk(clk),
    .d(XCRo[7]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux21_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTE0 [7]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg4_b0  (
    .clk(clk),
    .d(XCRo[0]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux22_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT2 [0]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg4_b1  (
    .clk(clk),
    .d(XCRo[1]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux22_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT2 [1]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg4_b2  (
    .clk(clk),
    .d(XCRo[2]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux22_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT2 [2]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg4_b3  (
    .clk(clk),
    .d(XCRo[3]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux22_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT2 [3]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg4_b4  (
    .clk(clk),
    .d(XCRo[4]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux22_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT2 [4]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg4_b5  (
    .clk(clk),
    .d(XCRo[5]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux22_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT2 [5]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg4_b6  (
    .clk(clk),
    .d(XCRo[6]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux22_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT2 [6]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg4_b7  (
    .clk(clk),
    .d(XCRo[7]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux22_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT2 [7]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg5_b0  (
    .clk(clk),
    .d(XCRo[0]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux23_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT1 [0]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg5_b1  (
    .clk(clk),
    .d(XCRo[1]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux23_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT1 [1]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg5_b2  (
    .clk(clk),
    .d(XCRo[2]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux23_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT1 [2]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg5_b3  (
    .clk(clk),
    .d(XCRo[3]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux23_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT1 [3]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg5_b4  (
    .clk(clk),
    .d(XCRo[4]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux23_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT1 [4]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg5_b5  (
    .clk(clk),
    .d(XCRo[5]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux23_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT1 [5]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg5_b6  (
    .clk(clk),
    .d(XCRo[6]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux23_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT1 [6]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg5_b7  (
    .clk(clk),
    .d(XCRo[7]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux23_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT1 [7]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg6_b0  (
    .clk(clk),
    .d(XCRo[0]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux24_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT0 [0]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg6_b1  (
    .clk(clk),
    .d(XCRo[1]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux24_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT0 [1]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg6_b2  (
    .clk(clk),
    .d(XCRo[2]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux24_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT0 [2]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg6_b3  (
    .clk(clk),
    .d(XCRo[3]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux24_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT0 [3]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg6_b4  (
    .clk(clk),
    .d(XCRo[4]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux24_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT0 [4]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg6_b5  (
    .clk(clk),
    .d(XCRo[5]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux24_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT0 [5]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg6_b6  (
    .clk(clk),
    .d(XCRo[6]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux24_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT0 [6]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/reg6_b7  (
    .clk(clk),
    .d(XCRo[7]),
    .en(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/mux24_b0_sel_is_2_o ),
    .reset(1'b0),
    .set(1'b0),
    .q(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/IVT0 [7]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/u10  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked [2], INT_ARR[2], \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTE0 [2]);  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(69)
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/u12  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked [1], INT_ARR[1], \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTE0 [1]);  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(69)
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/u13_and  (\GEN_PLUS_CORE$eXternalCtrlRegs/ecp_dout [0], \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n23 [0], \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n24 );
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/u18_and  (\GEN_PLUS_CORE$eXternalCtrlRegs/ecp_dout [1], \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n23 [1], \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n24 );
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/u2  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked [7], INT_ARR[7], \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTE0 [7]);  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(69)
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/u23_and  (\GEN_PLUS_CORE$eXternalCtrlRegs/ecp_dout [2], \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n23 [2], \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n24 );
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/u28_and  (\GEN_PLUS_CORE$eXternalCtrlRegs/ecp_dout [3], \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n23 [3], \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n24 );
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/u3  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked [6], INT_ARR[6], \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTE0 [6]);  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(69)
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/u33_and  (\GEN_PLUS_CORE$eXternalCtrlRegs/ecp_dout [4], \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n23 [4], \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n24 );
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/u38_and  (\GEN_PLUS_CORE$eXternalCtrlRegs/ecp_dout [5], \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n23 [5], \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n24 );
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/u4  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked [5], INT_ARR[5], \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTE0 [5]);  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(69)
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/u43_and  (\GEN_PLUS_CORE$eXternalCtrlRegs/ecp_dout [6], \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n23 [6], \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n24 );
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/u48_and  (\GEN_PLUS_CORE$eXternalCtrlRegs/ecp_dout [7], \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n23 [7], \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n24 );
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/u49  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked [3], INT_ARR[3], \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTE0 [3]);  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(69)
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/u5  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked [0], INT_ARR[0], \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTE0 [0]);  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(69)
  AL_MUX \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/u7  (
    .i0(INT_Req),
    .i1(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n0 ),
    .sel(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTC [2]),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n2 ));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/u8  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/n5 , \GEN_PLUS_CORE$eXternalCtrlRegs/ecp_cs , XCRwe);  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(100)
  and \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/u9  (\GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/int_masked [4], INT_ARR[4], \GEN_PLUS_CORE$eXternalCtrlRegs/Interrupt_Controller/INTE0 [4]);  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(69)
  eq_w4 \GEN_PLUS_CORE$eXternalCtrlRegs/eq0  (
    .i0(instr[7:4]),
    .i1(4'b0000),
    .o(\GEN_PLUS_CORE$eXternalCtrlRegs/n0 ));  // ../../RTL/cpu/XCR_Components/xcr_top.v(86)
  AL_MUX \GEN_PLUS_CORE$eXternalCtrlRegs/sel0_b0  (
    .i0(1'b0),
    .i1(\GEN_PLUS_CORE$eXternalCtrlRegs/ecp_dout [0]),
    .sel(\GEN_PLUS_CORE$eXternalCtrlRegs/n0 ),
    .o(XCRi[0]));  // ../../RTL/cpu/XCR_Components/xcr_top.v(93)
  AL_MUX \GEN_PLUS_CORE$eXternalCtrlRegs/sel0_b1  (
    .i0(1'b0),
    .i1(\GEN_PLUS_CORE$eXternalCtrlRegs/ecp_dout [1]),
    .sel(\GEN_PLUS_CORE$eXternalCtrlRegs/n0 ),
    .o(XCRi[1]));  // ../../RTL/cpu/XCR_Components/xcr_top.v(93)
  AL_MUX \GEN_PLUS_CORE$eXternalCtrlRegs/sel0_b2  (
    .i0(1'b0),
    .i1(\GEN_PLUS_CORE$eXternalCtrlRegs/ecp_dout [2]),
    .sel(\GEN_PLUS_CORE$eXternalCtrlRegs/n0 ),
    .o(XCRi[2]));  // ../../RTL/cpu/XCR_Components/xcr_top.v(93)
  AL_MUX \GEN_PLUS_CORE$eXternalCtrlRegs/sel0_b3  (
    .i0(1'b0),
    .i1(\GEN_PLUS_CORE$eXternalCtrlRegs/ecp_dout [3]),
    .sel(\GEN_PLUS_CORE$eXternalCtrlRegs/n0 ),
    .o(XCRi[3]));  // ../../RTL/cpu/XCR_Components/xcr_top.v(93)
  AL_MUX \GEN_PLUS_CORE$eXternalCtrlRegs/sel0_b4  (
    .i0(1'b0),
    .i1(\GEN_PLUS_CORE$eXternalCtrlRegs/ecp_dout [4]),
    .sel(\GEN_PLUS_CORE$eXternalCtrlRegs/n0 ),
    .o(XCRi[4]));  // ../../RTL/cpu/XCR_Components/xcr_top.v(93)
  AL_MUX \GEN_PLUS_CORE$eXternalCtrlRegs/sel0_b5  (
    .i0(1'b0),
    .i1(\GEN_PLUS_CORE$eXternalCtrlRegs/ecp_dout [5]),
    .sel(\GEN_PLUS_CORE$eXternalCtrlRegs/n0 ),
    .o(XCRi[5]));  // ../../RTL/cpu/XCR_Components/xcr_top.v(93)
  AL_MUX \GEN_PLUS_CORE$eXternalCtrlRegs/sel0_b6  (
    .i0(1'b0),
    .i1(\GEN_PLUS_CORE$eXternalCtrlRegs/ecp_dout [6]),
    .sel(\GEN_PLUS_CORE$eXternalCtrlRegs/n0 ),
    .o(XCRi[6]));  // ../../RTL/cpu/XCR_Components/xcr_top.v(93)
  AL_MUX \GEN_PLUS_CORE$eXternalCtrlRegs/sel0_b7  (
    .i0(1'b0),
    .i1(\GEN_PLUS_CORE$eXternalCtrlRegs/ecp_dout [7]),
    .sel(\GEN_PLUS_CORE$eXternalCtrlRegs/n0 ),
    .o(XCRi[7]));  // ../../RTL/cpu/XCR_Components/xcr_top.v(93)
  and \GEN_PLUS_CORE$eXternalCtrlRegs/u11  (\GEN_PLUS_CORE$eXternalCtrlRegs/ecp_cs , \GEN_PLUS_CORE$eXternalCtrlRegs/n0 , XCRcs);  // ../../RTL/cpu/XCR_Components/xcr_top.v(86)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    NO_CACHE$BIT16_BUS_CASE$dbyte_reg (
    .clk(clk),
    .d(daddr[0]),
    .en(trans_rdy),
    .reset(1'b0),
    .set(1'b0),
    .q(NO_CACHE$BIT16_BUS_CASE$dbyte));  // ../../RTL/cpu/CPU_LS1u.v(316)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    NO_CACHE$BIT16_BUS_CASE$prev_xf_is_instr_reg (
    .clk(clk),
    .d(n3),
    .en(trans_rdy),
    .reset(1'b0),
    .set(1'b0),
    .q(NO_CACHE$BIT16_BUS_CASE$prev_xf_is_instr));  // ../../RTL/cpu/CPU_LS1u.v(316)
  not hresp_inv (hresp_neg, hresp);
  not \instr[0]_inv  (\instr[0]_neg , instr[0]);
  not \instr[10]_inv  (\instr[10]_neg , instr[10]);
  not \instr[1]_inv  (\instr[1]_neg , instr[1]);
  not \instr[2]_inv  (\instr[2]_neg , instr[2]);
  not \instr[8]_inv  (\instr[8]_neg , instr[8]);
  not \instr[9]_inv  (\instr[9]_neg , instr[9]);
  bufif1 jrst_out_tribuf_program (jrst_out, 1'b0, 1'b0);
  bufif1 jtdo_tribuf_program (jtdo, 1'b0, 1'b0);
  ELF_LOGIC_GSRN #(
    .USR_GSRN("ENABLE"))
    logic_gsrn (
    .gsrn(rst_neg),
    .sync_clk(1'b0));
  binary_mux_s1_w1 mux0_b1 (
    .i0(iaddr[0]),
    .i1(daddr[1]),
    .sel(NO_CACHE$BIT16_BUS_CASE$access_is_data),
    .o(pa_l1[1]));  // ../../RTL/cpu/CPU_LS1u.v(301)
  binary_mux_s1_w1 mux0_b10 (
    .i0(iaddr[9]),
    .i1(daddr[10]),
    .sel(NO_CACHE$BIT16_BUS_CASE$access_is_data),
    .o(pa_l1[10]));  // ../../RTL/cpu/CPU_LS1u.v(301)
  binary_mux_s1_w1 mux0_b11 (
    .i0(iaddr[10]),
    .i1(daddr[11]),
    .sel(NO_CACHE$BIT16_BUS_CASE$access_is_data),
    .o(pa_l1[11]));  // ../../RTL/cpu/CPU_LS1u.v(301)
  binary_mux_s1_w1 mux0_b12 (
    .i0(iaddr[11]),
    .i1(daddr[12]),
    .sel(NO_CACHE$BIT16_BUS_CASE$access_is_data),
    .o(pa_l1[12]));  // ../../RTL/cpu/CPU_LS1u.v(301)
  binary_mux_s1_w1 mux0_b13 (
    .i0(iaddr[12]),
    .i1(daddr[13]),
    .sel(NO_CACHE$BIT16_BUS_CASE$access_is_data),
    .o(pa_l1[13]));  // ../../RTL/cpu/CPU_LS1u.v(301)
  binary_mux_s1_w1 mux0_b14 (
    .i0(iaddr[13]),
    .i1(daddr[14]),
    .sel(NO_CACHE$BIT16_BUS_CASE$access_is_data),
    .o(pa_l1[14]));  // ../../RTL/cpu/CPU_LS1u.v(301)
  binary_mux_s1_w1 mux0_b15 (
    .i0(iaddr[14]),
    .i1(daddr[15]),
    .sel(NO_CACHE$BIT16_BUS_CASE$access_is_data),
    .o(pa_l1[15]));  // ../../RTL/cpu/CPU_LS1u.v(301)
  binary_mux_s1_w1 mux0_b16 (
    .i0(iaddr[15]),
    .i1(daddr[16]),
    .sel(NO_CACHE$BIT16_BUS_CASE$access_is_data),
    .o(pa_l1[16]));  // ../../RTL/cpu/CPU_LS1u.v(301)
  binary_mux_s1_w1 mux0_b17 (
    .i0(iaddr[16]),
    .i1(daddr[17]),
    .sel(NO_CACHE$BIT16_BUS_CASE$access_is_data),
    .o(pa_l1[17]));  // ../../RTL/cpu/CPU_LS1u.v(301)
  binary_mux_s1_w1 mux0_b18 (
    .i0(iaddr[17]),
    .i1(daddr[18]),
    .sel(NO_CACHE$BIT16_BUS_CASE$access_is_data),
    .o(pa_l1[18]));  // ../../RTL/cpu/CPU_LS1u.v(301)
  binary_mux_s1_w1 mux0_b19 (
    .i0(iaddr[18]),
    .i1(daddr[19]),
    .sel(NO_CACHE$BIT16_BUS_CASE$access_is_data),
    .o(pa_l1[19]));  // ../../RTL/cpu/CPU_LS1u.v(301)
  binary_mux_s1_w1 mux0_b2 (
    .i0(iaddr[1]),
    .i1(daddr[2]),
    .sel(NO_CACHE$BIT16_BUS_CASE$access_is_data),
    .o(pa_l1[2]));  // ../../RTL/cpu/CPU_LS1u.v(301)
  binary_mux_s1_w1 mux0_b20 (
    .i0(iaddr[19]),
    .i1(daddr[20]),
    .sel(NO_CACHE$BIT16_BUS_CASE$access_is_data),
    .o(pa_l1[20]));  // ../../RTL/cpu/CPU_LS1u.v(301)
  binary_mux_s1_w1 mux0_b21 (
    .i0(iaddr[20]),
    .i1(daddr[21]),
    .sel(NO_CACHE$BIT16_BUS_CASE$access_is_data),
    .o(pa_l1[21]));  // ../../RTL/cpu/CPU_LS1u.v(301)
  binary_mux_s1_w1 mux0_b22 (
    .i0(iaddr[21]),
    .i1(daddr[22]),
    .sel(NO_CACHE$BIT16_BUS_CASE$access_is_data),
    .o(pa_l1[22]));  // ../../RTL/cpu/CPU_LS1u.v(301)
  binary_mux_s1_w1 mux0_b23 (
    .i0(iaddr[22]),
    .i1(daddr[23]),
    .sel(NO_CACHE$BIT16_BUS_CASE$access_is_data),
    .o(pa_l1[23]));  // ../../RTL/cpu/CPU_LS1u.v(301)
  binary_mux_s1_w1 mux0_b3 (
    .i0(iaddr[2]),
    .i1(daddr[3]),
    .sel(NO_CACHE$BIT16_BUS_CASE$access_is_data),
    .o(pa_l1[3]));  // ../../RTL/cpu/CPU_LS1u.v(301)
  binary_mux_s1_w1 mux0_b4 (
    .i0(iaddr[3]),
    .i1(daddr[4]),
    .sel(NO_CACHE$BIT16_BUS_CASE$access_is_data),
    .o(pa_l1[4]));  // ../../RTL/cpu/CPU_LS1u.v(301)
  binary_mux_s1_w1 mux0_b5 (
    .i0(iaddr[4]),
    .i1(daddr[5]),
    .sel(NO_CACHE$BIT16_BUS_CASE$access_is_data),
    .o(pa_l1[5]));  // ../../RTL/cpu/CPU_LS1u.v(301)
  binary_mux_s1_w1 mux0_b6 (
    .i0(iaddr[5]),
    .i1(daddr[6]),
    .sel(NO_CACHE$BIT16_BUS_CASE$access_is_data),
    .o(pa_l1[6]));  // ../../RTL/cpu/CPU_LS1u.v(301)
  binary_mux_s1_w1 mux0_b7 (
    .i0(iaddr[6]),
    .i1(daddr[7]),
    .sel(NO_CACHE$BIT16_BUS_CASE$access_is_data),
    .o(pa_l1[7]));  // ../../RTL/cpu/CPU_LS1u.v(301)
  binary_mux_s1_w1 mux0_b8 (
    .i0(iaddr[7]),
    .i1(daddr[8]),
    .sel(NO_CACHE$BIT16_BUS_CASE$access_is_data),
    .o(pa_l1[8]));  // ../../RTL/cpu/CPU_LS1u.v(301)
  binary_mux_s1_w1 mux0_b9 (
    .i0(iaddr[8]),
    .i1(daddr[9]),
    .sel(NO_CACHE$BIT16_BUS_CASE$access_is_data),
    .o(pa_l1[9]));  // ../../RTL/cpu/CPU_LS1u.v(301)
  binary_mux_s1_w1 mux1_b0 (
    .i0(NO_CACHE$BIT16_BUS_CASE$instr_hold[0]),
    .i1(hrdata[0]),
    .sel(NO_CACHE$BIT16_BUS_CASE$prev_xf_is_instr),
    .o(instr[0]));  // ../../RTL/cpu/CPU_LS1u.v(302)
  binary_mux_s1_w1 mux1_b1 (
    .i0(NO_CACHE$BIT16_BUS_CASE$instr_hold[1]),
    .i1(hrdata[1]),
    .sel(NO_CACHE$BIT16_BUS_CASE$prev_xf_is_instr),
    .o(instr[1]));  // ../../RTL/cpu/CPU_LS1u.v(302)
  binary_mux_s1_w1 mux1_b10 (
    .i0(NO_CACHE$BIT16_BUS_CASE$instr_hold[10]),
    .i1(hrdata[10]),
    .sel(NO_CACHE$BIT16_BUS_CASE$prev_xf_is_instr),
    .o(instr[10]));  // ../../RTL/cpu/CPU_LS1u.v(302)
  binary_mux_s1_w1 mux1_b11 (
    .i0(NO_CACHE$BIT16_BUS_CASE$instr_hold[11]),
    .i1(hrdata[11]),
    .sel(NO_CACHE$BIT16_BUS_CASE$prev_xf_is_instr),
    .o(instr[11]));  // ../../RTL/cpu/CPU_LS1u.v(302)
  binary_mux_s1_w1 mux1_b12 (
    .i0(NO_CACHE$BIT16_BUS_CASE$instr_hold[12]),
    .i1(hrdata[12]),
    .sel(NO_CACHE$BIT16_BUS_CASE$prev_xf_is_instr),
    .o(instr[12]));  // ../../RTL/cpu/CPU_LS1u.v(302)
  binary_mux_s1_w1 mux1_b13 (
    .i0(NO_CACHE$BIT16_BUS_CASE$instr_hold[13]),
    .i1(hrdata[13]),
    .sel(NO_CACHE$BIT16_BUS_CASE$prev_xf_is_instr),
    .o(instr[13]));  // ../../RTL/cpu/CPU_LS1u.v(302)
  binary_mux_s1_w1 mux1_b14 (
    .i0(NO_CACHE$BIT16_BUS_CASE$instr_hold[14]),
    .i1(hrdata[14]),
    .sel(NO_CACHE$BIT16_BUS_CASE$prev_xf_is_instr),
    .o(instr[14]));  // ../../RTL/cpu/CPU_LS1u.v(302)
  binary_mux_s1_w1 mux1_b15 (
    .i0(NO_CACHE$BIT16_BUS_CASE$instr_hold[15]),
    .i1(hrdata[15]),
    .sel(NO_CACHE$BIT16_BUS_CASE$prev_xf_is_instr),
    .o(instr[15]));  // ../../RTL/cpu/CPU_LS1u.v(302)
  binary_mux_s1_w1 mux1_b2 (
    .i0(NO_CACHE$BIT16_BUS_CASE$instr_hold[2]),
    .i1(hrdata[2]),
    .sel(NO_CACHE$BIT16_BUS_CASE$prev_xf_is_instr),
    .o(instr[2]));  // ../../RTL/cpu/CPU_LS1u.v(302)
  binary_mux_s1_w1 mux1_b3 (
    .i0(NO_CACHE$BIT16_BUS_CASE$instr_hold[3]),
    .i1(hrdata[3]),
    .sel(NO_CACHE$BIT16_BUS_CASE$prev_xf_is_instr),
    .o(instr[3]));  // ../../RTL/cpu/CPU_LS1u.v(302)
  binary_mux_s1_w1 mux1_b4 (
    .i0(NO_CACHE$BIT16_BUS_CASE$instr_hold[4]),
    .i1(hrdata[4]),
    .sel(NO_CACHE$BIT16_BUS_CASE$prev_xf_is_instr),
    .o(instr[4]));  // ../../RTL/cpu/CPU_LS1u.v(302)
  binary_mux_s1_w1 mux1_b5 (
    .i0(NO_CACHE$BIT16_BUS_CASE$instr_hold[5]),
    .i1(hrdata[5]),
    .sel(NO_CACHE$BIT16_BUS_CASE$prev_xf_is_instr),
    .o(instr[5]));  // ../../RTL/cpu/CPU_LS1u.v(302)
  binary_mux_s1_w1 mux1_b6 (
    .i0(NO_CACHE$BIT16_BUS_CASE$instr_hold[6]),
    .i1(hrdata[6]),
    .sel(NO_CACHE$BIT16_BUS_CASE$prev_xf_is_instr),
    .o(instr[6]));  // ../../RTL/cpu/CPU_LS1u.v(302)
  binary_mux_s1_w1 mux1_b7 (
    .i0(NO_CACHE$BIT16_BUS_CASE$instr_hold[7]),
    .i1(hrdata[7]),
    .sel(NO_CACHE$BIT16_BUS_CASE$prev_xf_is_instr),
    .o(instr[7]));  // ../../RTL/cpu/CPU_LS1u.v(302)
  binary_mux_s1_w1 mux1_b8 (
    .i0(NO_CACHE$BIT16_BUS_CASE$instr_hold[8]),
    .i1(hrdata[8]),
    .sel(NO_CACHE$BIT16_BUS_CASE$prev_xf_is_instr),
    .o(instr[8]));  // ../../RTL/cpu/CPU_LS1u.v(302)
  binary_mux_s1_w1 mux1_b9 (
    .i0(NO_CACHE$BIT16_BUS_CASE$instr_hold[9]),
    .i1(hrdata[9]),
    .sel(NO_CACHE$BIT16_BUS_CASE$prev_xf_is_instr),
    .o(instr[9]));  // ../../RTL/cpu/CPU_LS1u.v(302)
  binary_mux_s1_w1 mux2_b0 (
    .i0(hrdata[0]),
    .i1(hrdata[8]),
    .sel(NO_CACHE$BIT16_BUS_CASE$dbyte),
    .o(ddata_i[0]));  // ../../RTL/cpu/CPU_LS1u.v(304)
  binary_mux_s1_w1 mux2_b1 (
    .i0(hrdata[1]),
    .i1(hrdata[9]),
    .sel(NO_CACHE$BIT16_BUS_CASE$dbyte),
    .o(ddata_i[1]));  // ../../RTL/cpu/CPU_LS1u.v(304)
  binary_mux_s1_w1 mux2_b2 (
    .i0(hrdata[2]),
    .i1(hrdata[10]),
    .sel(NO_CACHE$BIT16_BUS_CASE$dbyte),
    .o(ddata_i[2]));  // ../../RTL/cpu/CPU_LS1u.v(304)
  binary_mux_s1_w1 mux2_b3 (
    .i0(hrdata[3]),
    .i1(hrdata[11]),
    .sel(NO_CACHE$BIT16_BUS_CASE$dbyte),
    .o(ddata_i[3]));  // ../../RTL/cpu/CPU_LS1u.v(304)
  binary_mux_s1_w1 mux2_b4 (
    .i0(hrdata[4]),
    .i1(hrdata[12]),
    .sel(NO_CACHE$BIT16_BUS_CASE$dbyte),
    .o(ddata_i[4]));  // ../../RTL/cpu/CPU_LS1u.v(304)
  binary_mux_s1_w1 mux2_b5 (
    .i0(hrdata[5]),
    .i1(hrdata[13]),
    .sel(NO_CACHE$BIT16_BUS_CASE$dbyte),
    .o(ddata_i[5]));  // ../../RTL/cpu/CPU_LS1u.v(304)
  binary_mux_s1_w1 mux2_b6 (
    .i0(hrdata[6]),
    .i1(hrdata[14]),
    .sel(NO_CACHE$BIT16_BUS_CASE$dbyte),
    .o(ddata_i[6]));  // ../../RTL/cpu/CPU_LS1u.v(304)
  binary_mux_s1_w1 mux2_b7 (
    .i0(hrdata[7]),
    .i1(hrdata[15]),
    .sel(NO_CACHE$BIT16_BUS_CASE$dbyte),
    .o(ddata_i[7]));  // ../../RTL/cpu/CPU_LS1u.v(304)
  reg_ar_as_w1 reg0_b0 (
    .clk(clk),
    .d(hrdata[0]),
    .en(n6),
    .reset(1'b0),
    .set(1'b0),
    .q(NO_CACHE$BIT16_BUS_CASE$instr_hold[0]));  // ../../RTL/cpu/CPU_LS1u.v(320)
  reg_ar_as_w1 reg0_b1 (
    .clk(clk),
    .d(hrdata[1]),
    .en(n6),
    .reset(1'b0),
    .set(1'b0),
    .q(NO_CACHE$BIT16_BUS_CASE$instr_hold[1]));  // ../../RTL/cpu/CPU_LS1u.v(320)
  reg_ar_as_w1 reg0_b10 (
    .clk(clk),
    .d(hrdata[10]),
    .en(n6),
    .reset(1'b0),
    .set(1'b0),
    .q(NO_CACHE$BIT16_BUS_CASE$instr_hold[10]));  // ../../RTL/cpu/CPU_LS1u.v(320)
  reg_ar_as_w1 reg0_b11 (
    .clk(clk),
    .d(hrdata[11]),
    .en(n6),
    .reset(1'b0),
    .set(1'b0),
    .q(NO_CACHE$BIT16_BUS_CASE$instr_hold[11]));  // ../../RTL/cpu/CPU_LS1u.v(320)
  reg_ar_as_w1 reg0_b12 (
    .clk(clk),
    .d(hrdata[12]),
    .en(n6),
    .reset(1'b0),
    .set(1'b0),
    .q(NO_CACHE$BIT16_BUS_CASE$instr_hold[12]));  // ../../RTL/cpu/CPU_LS1u.v(320)
  reg_ar_as_w1 reg0_b13 (
    .clk(clk),
    .d(hrdata[13]),
    .en(n6),
    .reset(1'b0),
    .set(1'b0),
    .q(NO_CACHE$BIT16_BUS_CASE$instr_hold[13]));  // ../../RTL/cpu/CPU_LS1u.v(320)
  reg_ar_as_w1 reg0_b14 (
    .clk(clk),
    .d(hrdata[14]),
    .en(n6),
    .reset(1'b0),
    .set(1'b0),
    .q(NO_CACHE$BIT16_BUS_CASE$instr_hold[14]));  // ../../RTL/cpu/CPU_LS1u.v(320)
  reg_ar_as_w1 reg0_b15 (
    .clk(clk),
    .d(hrdata[15]),
    .en(n6),
    .reset(1'b0),
    .set(1'b0),
    .q(NO_CACHE$BIT16_BUS_CASE$instr_hold[15]));  // ../../RTL/cpu/CPU_LS1u.v(320)
  reg_ar_as_w1 reg0_b2 (
    .clk(clk),
    .d(hrdata[2]),
    .en(n6),
    .reset(1'b0),
    .set(1'b0),
    .q(NO_CACHE$BIT16_BUS_CASE$instr_hold[2]));  // ../../RTL/cpu/CPU_LS1u.v(320)
  reg_ar_as_w1 reg0_b3 (
    .clk(clk),
    .d(hrdata[3]),
    .en(n6),
    .reset(1'b0),
    .set(1'b0),
    .q(NO_CACHE$BIT16_BUS_CASE$instr_hold[3]));  // ../../RTL/cpu/CPU_LS1u.v(320)
  reg_ar_as_w1 reg0_b4 (
    .clk(clk),
    .d(hrdata[4]),
    .en(n6),
    .reset(1'b0),
    .set(1'b0),
    .q(NO_CACHE$BIT16_BUS_CASE$instr_hold[4]));  // ../../RTL/cpu/CPU_LS1u.v(320)
  reg_ar_as_w1 reg0_b5 (
    .clk(clk),
    .d(hrdata[5]),
    .en(n6),
    .reset(1'b0),
    .set(1'b0),
    .q(NO_CACHE$BIT16_BUS_CASE$instr_hold[5]));  // ../../RTL/cpu/CPU_LS1u.v(320)
  reg_ar_as_w1 reg0_b6 (
    .clk(clk),
    .d(hrdata[6]),
    .en(n6),
    .reset(1'b0),
    .set(1'b0),
    .q(NO_CACHE$BIT16_BUS_CASE$instr_hold[6]));  // ../../RTL/cpu/CPU_LS1u.v(320)
  reg_ar_as_w1 reg0_b7 (
    .clk(clk),
    .d(hrdata[7]),
    .en(n6),
    .reset(1'b0),
    .set(1'b0),
    .q(NO_CACHE$BIT16_BUS_CASE$instr_hold[7]));  // ../../RTL/cpu/CPU_LS1u.v(320)
  reg_ar_as_w1 reg0_b8 (
    .clk(clk),
    .d(hrdata[8]),
    .en(n6),
    .reset(1'b0),
    .set(1'b0),
    .q(NO_CACHE$BIT16_BUS_CASE$instr_hold[8]));  // ../../RTL/cpu/CPU_LS1u.v(320)
  reg_ar_as_w1 reg0_b9 (
    .clk(clk),
    .d(hrdata[9]),
    .en(n6),
    .reset(1'b0),
    .set(1'b0),
    .q(NO_CACHE$BIT16_BUS_CASE$instr_hold[9]));  // ../../RTL/cpu/CPU_LS1u.v(320)
  not rst_inv (rst_neg, rst);
  not u11 (n3, NO_CACHE$BIT16_BUS_CASE$access_is_data);  // ../../RTL/cpu/CPU_LS1u.v(314)
  and u15 (n6, n3, trans_rdy);  // ../../RTL/cpu/CPU_LS1u.v(319)
  and u16 (write_through_req[0], dwrite, n2);  // ../../RTL/cpu/CPU_LS1u.v(299)
  not u4 (n0, trans_rdy);  // ../../RTL/cpu/CPU_LS1u.v(140)
  and u50 (write_through_req[1], dwrite, daddr[0]);  // ../../RTL/cpu/CPU_LS1u.v(299)
  or u6 (NO_CACHE$BIT16_BUS_CASE$access_is_data, dwrite, dread);  // ../../RTL/cpu/CPU_LS1u.v(297)
  not u8 (n2, daddr[0]);  // ../../RTL/cpu/CPU_LS1u.v(299)
  not u9 (read_req, dwrite);  // ../../RTL/cpu/CPU_LS1u.v(300)

endmodule 

module add_pu2_pu2_o2
  (
  i0,
  i1,
  o
  );

  input [1:0] i0;
  input [1:0] i1;
  output [1:0] o;

  wire net_a0;
  wire net_a1;
  wire net_b0;
  wire net_b1;
  wire net_cout0;
  wire net_cout1;
  wire net_sum0;
  wire net_sum1;

  assign net_a1 = i0[1];
  assign net_a0 = i0[0];
  assign net_b1 = i1[1];
  assign net_b0 = i1[0];
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

endmodule 

module eq_w2
  (
  i0,
  i1,
  o
  );

  input [1:0] i0;
  input [1:0] i1;
  output o;

  wire \or_xor_i0[0]_i1[0]_o_o ;
  wire \xor_i0[0]_i1[0]_o ;
  wire \xor_i0[1]_i1[1]_o ;

  not none_diff (o, \or_xor_i0[0]_i1[0]_o_o );
  or \or_xor_i0[0]_i1[0]_o  (\or_xor_i0[0]_i1[0]_o_o , \xor_i0[0]_i1[0]_o , \xor_i0[1]_i1[1]_o );
  xor \xor_i0[0]_i1[0]  (\xor_i0[0]_i1[0]_o , i0[0], i1[0]);
  xor \xor_i0[1]_i1[1]  (\xor_i0[1]_i1[1]_o , i0[1], i1[1]);

endmodule 

module eq_w4
  (
  i0,
  i1,
  o
  );

  input [3:0] i0;
  input [3:0] i1;
  output o;

  wire \or_or_xor_i0[0]_i1[0_o ;
  wire \or_xor_i0[0]_i1[0]_o_o ;
  wire \or_xor_i0[2]_i1[2]_o_o ;
  wire \xor_i0[0]_i1[0]_o ;
  wire \xor_i0[1]_i1[1]_o ;
  wire \xor_i0[2]_i1[2]_o ;
  wire \xor_i0[3]_i1[3]_o ;

  not none_diff (o, \or_or_xor_i0[0]_i1[0_o );
  or \or_or_xor_i0[0]_i1[0  (\or_or_xor_i0[0]_i1[0_o , \or_xor_i0[0]_i1[0]_o_o , \or_xor_i0[2]_i1[2]_o_o );
  or \or_xor_i0[0]_i1[0]_o  (\or_xor_i0[0]_i1[0]_o_o , \xor_i0[0]_i1[0]_o , \xor_i0[1]_i1[1]_o );
  or \or_xor_i0[2]_i1[2]_o  (\or_xor_i0[2]_i1[2]_o_o , \xor_i0[2]_i1[2]_o , \xor_i0[3]_i1[3]_o );
  xor \xor_i0[0]_i1[0]  (\xor_i0[0]_i1[0]_o , i0[0], i1[0]);
  xor \xor_i0[1]_i1[1]  (\xor_i0[1]_i1[1]_o , i0[1], i1[1]);
  xor \xor_i0[2]_i1[2]  (\xor_i0[2]_i1[2]_o , i0[2], i1[2]);
  xor \xor_i0[3]_i1[3]  (\xor_i0[3]_i1[3]_o , i0[3], i1[3]);

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

module reg_sr_as_w1
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
  wire resetout;

  AL_MUX u_en0 (
    .i0(q),
    .i1(d),
    .sel(en),
    .o(enout));
  AL_MUX u_reset0 (
    .i0(enout),
    .i1(1'b0),
    .sel(reset),
    .o(resetout));
  AL_DFF
    u_seq0 (
    .clk(clk),
    .d(resetout),
    .reset(1'b0),
    .set(set),
    .q(q));

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

module add_pu23_pu23_o23
  (
  i0,
  i1,
  o
  );

  input [22:0] i0;
  input [22:0] i1;
  output [22:0] o;

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
  wire net_sum3;
  wire net_sum4;
  wire net_sum5;
  wire net_sum6;
  wire net_sum7;
  wire net_sum8;
  wire net_sum9;

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

module add_pu21_pu21_o21
  (
  i0,
  i1,
  o
  );

  input [20:0] i0;
  input [20:0] i1;
  output [20:0] o;

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
  wire net_sum3;
  wire net_sum4;
  wire net_sum5;
  wire net_sum6;
  wire net_sum7;
  wire net_sum8;
  wire net_sum9;

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

module ne_w8
  (
  i0,
  i1,
  o
  );

  input [7:0] i0;
  input [7:0] i1;
  output o;

  wire [7:0] diff;

  or any_diff (o, diff[0], diff[1], diff[2], diff[3], diff[4], diff[5], diff[6], diff[7]);
  xor diff_0 (diff[0], i0[0], i1[0]);
  xor diff_1 (diff[1], i0[1], i1[1]);
  xor diff_2 (diff[2], i0[2], i1[2]);
  xor diff_3 (diff[3], i0[3], i1[3]);
  xor diff_4 (diff[4], i0[4], i1[4]);
  xor diff_5 (diff[5], i0[5], i1[5]);
  xor diff_6 (diff[6], i0[6], i1[6]);
  xor diff_7 (diff[7], i0[7], i1[7]);

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

