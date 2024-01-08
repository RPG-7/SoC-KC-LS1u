// Verilog netlist created by TD v4.6.64949
// Mon Jan  1 23:40:19 2024

`timescale 1ns / 1ps
module CPLD_LS1u  // ../../RTL/top/CPLD_LS1u.v(1)
  (
  UART_RX,
  button,
  clk,
  rstn,
  QSPI_CLK,
  QSPI_CSN,
  UART_TX,
  WS2812_PULSE,
  ram_addr,
  ram_cen,
  ram_oen,
  ram_wen,
  ram_wstrbn,
  QSPI_DIO,
  ram_data
  );

  input UART_RX;  // ../../RTL/top/CPLD_LS1u.v(18)
  input button;  // ../../RTL/top/CPLD_LS1u.v(27)
  input clk;  // ../../RTL/top/CPLD_LS1u.v(6)
  input rstn;  // ../../RTL/top/CPLD_LS1u.v(6)
  output QSPI_CLK;  // ../../RTL/top/CPLD_LS1u.v(21)
  output QSPI_CSN;  // ../../RTL/top/CPLD_LS1u.v(22)
  output UART_TX;  // ../../RTL/top/CPLD_LS1u.v(19)
  output WS2812_PULSE;  // ../../RTL/top/CPLD_LS1u.v(25)
  output [16:0] ram_addr;  // ../../RTL/top/CPLD_LS1u.v(9)
  output ram_cen;  // ../../RTL/top/CPLD_LS1u.v(10)
  output ram_oen;  // ../../RTL/top/CPLD_LS1u.v(11)
  output ram_wen;  // ../../RTL/top/CPLD_LS1u.v(12)
  output [1:0] ram_wstrbn;  // ../../RTL/top/CPLD_LS1u.v(13)
  inout [3:0] QSPI_DIO;  // ../../RTL/top/CPLD_LS1u.v(23)
  inout [15:0] ram_data;  // ../../RTL/top/CPLD_LS1u.v(14)

  parameter CPU_TYPE = "PLUS";
  parameter MMU_ENABLE = 1'b0;
  parameter RAM_AWIDTH = 17;
  // localparam BUS_AWIDTH = 24;
  wire [23:0] cpu_daddr;  // ../../RTL/top/CPLD_LS1u.v(33)
  wire [23:0] cpu_iaddr;  // ../../RTL/top/CPLD_LS1u.v(30)
  wire [7:0] ddata_i;  // ../../RTL/top/CPLD_LS1u.v(37)
  wire [7:0] ddata_o;  // ../../RTL/top/CPLD_LS1u.v(38)
  wire [15:0] instr;  // ../../RTL/top/CPLD_LS1u.v(31)
  wire [7:0] \ram_ctl/n4 ;
  wire WAIT_DATA;  // ../../RTL/top/CPLD_LS1u.v(36)
  wire WAIT_INSTR;  // ../../RTL/top/CPLD_LS1u.v(32)
  wire dread;  // ../../RTL/top/CPLD_LS1u.v(34)
  wire dwrite;  // ../../RTL/top/CPLD_LS1u.v(35)
  wire n0;
  wire n1;
  wire n10;
  wire n11;
  wire n12;
  wire n13;
  wire n2;
  wire n3;
  wire n4;
  wire n5;
  wire n6;
  wire n7;
  wire n8;
  wire n9;
  wire \ram_ctl/access_data ;  // ../../RTL/hispeed/asram16_intf.v(26)
  wire \ram_ctl/n0 ;
  wire \ram_ctl/n1 ;
  wire \ram_ctl/n2 ;
  wire \ram_ctl/n6 ;
  wire \ram_ctl/n7 ;
  wire \ram_ctl/wait_data_hold ;  // ../../RTL/hispeed/asram16_intf.v(41)
  wire ram_dsel;  // ../../RTL/top/CPLD_LS1u.v(62)
  wire ram_isel;  // ../../RTL/top/CPLD_LS1u.v(61)

  assign ram_oen = n13;
  assign ram_wstrbn[0] = cpu_daddr[0];
  CPU_LS1u_Lite CPU (
    .INT_ARR(8'b00000000),
    .WAIT_DATA(WAIT_DATA),
    .WAIT_INSTR(WAIT_INSTR),
    .clk(clk),
    .ddata_i(ddata_i),
    .instr(instr),
    .jtck(1'b0),
    .jtdi(1'b0),
    .jtms(1'b0),
    .rst(1'b0),
    .sys_por(1'b0),
    .cpu_daddr({open_n1,open_n2,open_n3,open_n4,open_n5,open_n6,open_n7,open_n8,cpu_daddr[15:0]}),
    .cpu_iaddr({cpu_iaddr[23:1],open_n9}),
    .ddata_o(ddata_o),
    .dread(dread),
    .dwrite(dwrite));  // ../../RTL/top/CPLD_LS1u.v(45)
  bufif1 QSPI_CLK_tribuf_program (QSPI_CLK, 1'b0, 1'b0);
  bufif1 QSPI_CSN_tribuf_program (QSPI_CSN, 1'b0, 1'b0);
  bufif1 UART_TX_tribuf_program (UART_TX, 1'b0, 1'b0);
  bufif1 WS2812_PULSE_tribuf_program (WS2812_PULSE, 1'b0, 1'b0);
  reg_ar_as_w1 \ram_ctl/WAIT_INSTR_reg  (
    .clk(clk),
    .d(\ram_ctl/n6 ),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .q(WAIT_INSTR));  // ../../RTL/hispeed/asram16_intf.v(53)
  binary_mux_s1_w1 \ram_ctl/mux0_b0  (
    .i0(1'b0),
    .i1(cpu_daddr[1]),
    .sel(\ram_ctl/access_data ),
    .o(ram_addr[0]));  // ../../RTL/hispeed/asram16_intf.v(28)
  binary_mux_s1_w1 \ram_ctl/mux0_b1  (
    .i0(cpu_iaddr[1]),
    .i1(cpu_daddr[2]),
    .sel(\ram_ctl/access_data ),
    .o(ram_addr[1]));  // ../../RTL/hispeed/asram16_intf.v(28)
  binary_mux_s1_w1 \ram_ctl/mux0_b10  (
    .i0(cpu_iaddr[10]),
    .i1(cpu_daddr[11]),
    .sel(\ram_ctl/access_data ),
    .o(ram_addr[10]));  // ../../RTL/hispeed/asram16_intf.v(28)
  binary_mux_s1_w1 \ram_ctl/mux0_b11  (
    .i0(cpu_iaddr[11]),
    .i1(cpu_daddr[12]),
    .sel(\ram_ctl/access_data ),
    .o(ram_addr[11]));  // ../../RTL/hispeed/asram16_intf.v(28)
  binary_mux_s1_w1 \ram_ctl/mux0_b12  (
    .i0(cpu_iaddr[12]),
    .i1(cpu_daddr[13]),
    .sel(\ram_ctl/access_data ),
    .o(ram_addr[12]));  // ../../RTL/hispeed/asram16_intf.v(28)
  binary_mux_s1_w1 \ram_ctl/mux0_b13  (
    .i0(cpu_iaddr[13]),
    .i1(cpu_daddr[14]),
    .sel(\ram_ctl/access_data ),
    .o(ram_addr[13]));  // ../../RTL/hispeed/asram16_intf.v(28)
  binary_mux_s1_w1 \ram_ctl/mux0_b14  (
    .i0(cpu_iaddr[14]),
    .i1(cpu_daddr[15]),
    .sel(\ram_ctl/access_data ),
    .o(ram_addr[14]));  // ../../RTL/hispeed/asram16_intf.v(28)
  binary_mux_s1_w1 \ram_ctl/mux0_b15  (
    .i0(cpu_iaddr[15]),
    .i1(1'b0),
    .sel(\ram_ctl/access_data ),
    .o(ram_addr[15]));  // ../../RTL/hispeed/asram16_intf.v(28)
  binary_mux_s1_w1 \ram_ctl/mux0_b16  (
    .i0(cpu_iaddr[16]),
    .i1(1'b0),
    .sel(\ram_ctl/access_data ),
    .o(ram_addr[16]));  // ../../RTL/hispeed/asram16_intf.v(28)
  binary_mux_s1_w1 \ram_ctl/mux0_b2  (
    .i0(cpu_iaddr[2]),
    .i1(cpu_daddr[3]),
    .sel(\ram_ctl/access_data ),
    .o(ram_addr[2]));  // ../../RTL/hispeed/asram16_intf.v(28)
  binary_mux_s1_w1 \ram_ctl/mux0_b3  (
    .i0(cpu_iaddr[3]),
    .i1(cpu_daddr[4]),
    .sel(\ram_ctl/access_data ),
    .o(ram_addr[3]));  // ../../RTL/hispeed/asram16_intf.v(28)
  binary_mux_s1_w1 \ram_ctl/mux0_b4  (
    .i0(cpu_iaddr[4]),
    .i1(cpu_daddr[5]),
    .sel(\ram_ctl/access_data ),
    .o(ram_addr[4]));  // ../../RTL/hispeed/asram16_intf.v(28)
  binary_mux_s1_w1 \ram_ctl/mux0_b5  (
    .i0(cpu_iaddr[5]),
    .i1(cpu_daddr[6]),
    .sel(\ram_ctl/access_data ),
    .o(ram_addr[5]));  // ../../RTL/hispeed/asram16_intf.v(28)
  binary_mux_s1_w1 \ram_ctl/mux0_b6  (
    .i0(cpu_iaddr[6]),
    .i1(cpu_daddr[7]),
    .sel(\ram_ctl/access_data ),
    .o(ram_addr[6]));  // ../../RTL/hispeed/asram16_intf.v(28)
  binary_mux_s1_w1 \ram_ctl/mux0_b7  (
    .i0(cpu_iaddr[7]),
    .i1(cpu_daddr[8]),
    .sel(\ram_ctl/access_data ),
    .o(ram_addr[7]));  // ../../RTL/hispeed/asram16_intf.v(28)
  binary_mux_s1_w1 \ram_ctl/mux0_b8  (
    .i0(cpu_iaddr[8]),
    .i1(cpu_daddr[9]),
    .sel(\ram_ctl/access_data ),
    .o(ram_addr[8]));  // ../../RTL/hispeed/asram16_intf.v(28)
  binary_mux_s1_w1 \ram_ctl/mux0_b9  (
    .i0(cpu_iaddr[9]),
    .i1(cpu_daddr[10]),
    .sel(\ram_ctl/access_data ),
    .o(ram_addr[9]));  // ../../RTL/hispeed/asram16_intf.v(28)
  binary_mux_s1_w1 \ram_ctl/mux2_b0  (
    .i0(ram_data[0]),
    .i1(ram_data[8]),
    .sel(cpu_daddr[0]),
    .o(\ram_ctl/n4 [0]));  // ../../RTL/hispeed/asram16_intf.v(39)
  binary_mux_s1_w1 \ram_ctl/mux2_b1  (
    .i0(ram_data[1]),
    .i1(ram_data[9]),
    .sel(cpu_daddr[0]),
    .o(\ram_ctl/n4 [1]));  // ../../RTL/hispeed/asram16_intf.v(39)
  binary_mux_s1_w1 \ram_ctl/mux2_b2  (
    .i0(ram_data[2]),
    .i1(ram_data[10]),
    .sel(cpu_daddr[0]),
    .o(\ram_ctl/n4 [2]));  // ../../RTL/hispeed/asram16_intf.v(39)
  binary_mux_s1_w1 \ram_ctl/mux2_b3  (
    .i0(ram_data[3]),
    .i1(ram_data[11]),
    .sel(cpu_daddr[0]),
    .o(\ram_ctl/n4 [3]));  // ../../RTL/hispeed/asram16_intf.v(39)
  binary_mux_s1_w1 \ram_ctl/mux2_b4  (
    .i0(ram_data[4]),
    .i1(ram_data[12]),
    .sel(cpu_daddr[0]),
    .o(\ram_ctl/n4 [4]));  // ../../RTL/hispeed/asram16_intf.v(39)
  binary_mux_s1_w1 \ram_ctl/mux2_b5  (
    .i0(ram_data[5]),
    .i1(ram_data[13]),
    .sel(cpu_daddr[0]),
    .o(\ram_ctl/n4 [5]));  // ../../RTL/hispeed/asram16_intf.v(39)
  binary_mux_s1_w1 \ram_ctl/mux2_b6  (
    .i0(ram_data[6]),
    .i1(ram_data[14]),
    .sel(cpu_daddr[0]),
    .o(\ram_ctl/n4 [6]));  // ../../RTL/hispeed/asram16_intf.v(39)
  binary_mux_s1_w1 \ram_ctl/mux2_b7  (
    .i0(ram_data[7]),
    .i1(ram_data[15]),
    .sel(cpu_daddr[0]),
    .o(\ram_ctl/n4 [7]));  // ../../RTL/hispeed/asram16_intf.v(39)
  reg_ar_as_w1 \ram_ctl/reg0_b0  (
    .clk(clk),
    .d(\ram_ctl/n4 [0]),
    .en(n12),
    .reset(1'b0),
    .set(1'b0),
    .q(ddata_i[0]));  // ../../RTL/hispeed/asram16_intf.v(40)
  reg_ar_as_w1 \ram_ctl/reg0_b1  (
    .clk(clk),
    .d(\ram_ctl/n4 [1]),
    .en(n12),
    .reset(1'b0),
    .set(1'b0),
    .q(ddata_i[1]));  // ../../RTL/hispeed/asram16_intf.v(40)
  reg_ar_as_w1 \ram_ctl/reg0_b2  (
    .clk(clk),
    .d(\ram_ctl/n4 [2]),
    .en(n12),
    .reset(1'b0),
    .set(1'b0),
    .q(ddata_i[2]));  // ../../RTL/hispeed/asram16_intf.v(40)
  reg_ar_as_w1 \ram_ctl/reg0_b3  (
    .clk(clk),
    .d(\ram_ctl/n4 [3]),
    .en(n12),
    .reset(1'b0),
    .set(1'b0),
    .q(ddata_i[3]));  // ../../RTL/hispeed/asram16_intf.v(40)
  reg_ar_as_w1 \ram_ctl/reg0_b4  (
    .clk(clk),
    .d(\ram_ctl/n4 [4]),
    .en(n12),
    .reset(1'b0),
    .set(1'b0),
    .q(ddata_i[4]));  // ../../RTL/hispeed/asram16_intf.v(40)
  reg_ar_as_w1 \ram_ctl/reg0_b5  (
    .clk(clk),
    .d(\ram_ctl/n4 [5]),
    .en(n12),
    .reset(1'b0),
    .set(1'b0),
    .q(ddata_i[5]));  // ../../RTL/hispeed/asram16_intf.v(40)
  reg_ar_as_w1 \ram_ctl/reg0_b6  (
    .clk(clk),
    .d(\ram_ctl/n4 [6]),
    .en(n12),
    .reset(1'b0),
    .set(1'b0),
    .q(ddata_i[6]));  // ../../RTL/hispeed/asram16_intf.v(40)
  reg_ar_as_w1 \ram_ctl/reg0_b7  (
    .clk(clk),
    .d(\ram_ctl/n4 [7]),
    .en(n12),
    .reset(1'b0),
    .set(1'b0),
    .q(ddata_i[7]));  // ../../RTL/hispeed/asram16_intf.v(40)
  reg_ar_as_w1 \ram_ctl/reg1_b0  (
    .clk(clk),
    .d(ram_data[0]),
    .en(\ram_ctl/n2 ),
    .reset(1'b0),
    .set(1'b0),
    .q(instr[0]));  // ../../RTL/hispeed/asram16_intf.v(40)
  reg_ar_as_w1 \ram_ctl/reg1_b1  (
    .clk(clk),
    .d(ram_data[1]),
    .en(\ram_ctl/n2 ),
    .reset(1'b0),
    .set(1'b0),
    .q(instr[1]));  // ../../RTL/hispeed/asram16_intf.v(40)
  reg_ar_as_w1 \ram_ctl/reg1_b10  (
    .clk(clk),
    .d(ram_data[10]),
    .en(\ram_ctl/n2 ),
    .reset(1'b0),
    .set(1'b0),
    .q(instr[10]));  // ../../RTL/hispeed/asram16_intf.v(40)
  reg_ar_as_w1 \ram_ctl/reg1_b11  (
    .clk(clk),
    .d(ram_data[11]),
    .en(\ram_ctl/n2 ),
    .reset(1'b0),
    .set(1'b0),
    .q(instr[11]));  // ../../RTL/hispeed/asram16_intf.v(40)
  reg_ar_as_w1 \ram_ctl/reg1_b12  (
    .clk(clk),
    .d(ram_data[12]),
    .en(\ram_ctl/n2 ),
    .reset(1'b0),
    .set(1'b0),
    .q(instr[12]));  // ../../RTL/hispeed/asram16_intf.v(40)
  reg_ar_as_w1 \ram_ctl/reg1_b13  (
    .clk(clk),
    .d(ram_data[13]),
    .en(\ram_ctl/n2 ),
    .reset(1'b0),
    .set(1'b0),
    .q(instr[13]));  // ../../RTL/hispeed/asram16_intf.v(40)
  reg_ar_as_w1 \ram_ctl/reg1_b14  (
    .clk(clk),
    .d(ram_data[14]),
    .en(\ram_ctl/n2 ),
    .reset(1'b0),
    .set(1'b0),
    .q(instr[14]));  // ../../RTL/hispeed/asram16_intf.v(40)
  reg_ar_as_w1 \ram_ctl/reg1_b15  (
    .clk(clk),
    .d(ram_data[15]),
    .en(\ram_ctl/n2 ),
    .reset(1'b0),
    .set(1'b0),
    .q(instr[15]));  // ../../RTL/hispeed/asram16_intf.v(40)
  reg_ar_as_w1 \ram_ctl/reg1_b2  (
    .clk(clk),
    .d(ram_data[2]),
    .en(\ram_ctl/n2 ),
    .reset(1'b0),
    .set(1'b0),
    .q(instr[2]));  // ../../RTL/hispeed/asram16_intf.v(40)
  reg_ar_as_w1 \ram_ctl/reg1_b3  (
    .clk(clk),
    .d(ram_data[3]),
    .en(\ram_ctl/n2 ),
    .reset(1'b0),
    .set(1'b0),
    .q(instr[3]));  // ../../RTL/hispeed/asram16_intf.v(40)
  reg_ar_as_w1 \ram_ctl/reg1_b4  (
    .clk(clk),
    .d(ram_data[4]),
    .en(\ram_ctl/n2 ),
    .reset(1'b0),
    .set(1'b0),
    .q(instr[4]));  // ../../RTL/hispeed/asram16_intf.v(40)
  reg_ar_as_w1 \ram_ctl/reg1_b5  (
    .clk(clk),
    .d(ram_data[5]),
    .en(\ram_ctl/n2 ),
    .reset(1'b0),
    .set(1'b0),
    .q(instr[5]));  // ../../RTL/hispeed/asram16_intf.v(40)
  reg_ar_as_w1 \ram_ctl/reg1_b6  (
    .clk(clk),
    .d(ram_data[6]),
    .en(\ram_ctl/n2 ),
    .reset(1'b0),
    .set(1'b0),
    .q(instr[6]));  // ../../RTL/hispeed/asram16_intf.v(40)
  reg_ar_as_w1 \ram_ctl/reg1_b7  (
    .clk(clk),
    .d(ram_data[7]),
    .en(\ram_ctl/n2 ),
    .reset(1'b0),
    .set(1'b0),
    .q(instr[7]));  // ../../RTL/hispeed/asram16_intf.v(40)
  reg_ar_as_w1 \ram_ctl/reg1_b8  (
    .clk(clk),
    .d(ram_data[8]),
    .en(\ram_ctl/n2 ),
    .reset(1'b0),
    .set(1'b0),
    .q(instr[8]));  // ../../RTL/hispeed/asram16_intf.v(40)
  reg_ar_as_w1 \ram_ctl/reg1_b9  (
    .clk(clk),
    .d(ram_data[9]),
    .en(\ram_ctl/n2 ),
    .reset(1'b0),
    .set(1'b0),
    .q(instr[9]));  // ../../RTL/hispeed/asram16_intf.v(40)
  or \ram_ctl/u1  (\ram_ctl/access_data , n12, n13);  // ../../RTL/hispeed/asram16_intf.v(26)
  bufif1 \ram_ctl/u10  (ram_data[13], ddata_o[5], n13);  // ../../RTL/hispeed/asram16_intf.v(33)
  bufif1 \ram_ctl/u11  (ram_data[12], ddata_o[4], n13);  // ../../RTL/hispeed/asram16_intf.v(33)
  bufif1 \ram_ctl/u12  (ram_data[11], ddata_o[3], n13);  // ../../RTL/hispeed/asram16_intf.v(33)
  bufif1 \ram_ctl/u13  (ram_data[10], ddata_o[2], n13);  // ../../RTL/hispeed/asram16_intf.v(33)
  bufif1 \ram_ctl/u14  (ram_data[9], ddata_o[1], n13);  // ../../RTL/hispeed/asram16_intf.v(33)
  bufif1 \ram_ctl/u15  (ram_data[8], ddata_o[0], n13);  // ../../RTL/hispeed/asram16_intf.v(33)
  bufif1 \ram_ctl/u16  (ram_data[7], ddata_o[7], n13);  // ../../RTL/hispeed/asram16_intf.v(33)
  bufif1 \ram_ctl/u17  (ram_data[6], ddata_o[6], n13);  // ../../RTL/hispeed/asram16_intf.v(33)
  bufif1 \ram_ctl/u18  (ram_data[5], ddata_o[5], n13);  // ../../RTL/hispeed/asram16_intf.v(33)
  bufif1 \ram_ctl/u19  (ram_data[4], ddata_o[4], n13);  // ../../RTL/hispeed/asram16_intf.v(33)
  or \ram_ctl/u2  (\ram_ctl/n0 , ram_isel, \ram_ctl/access_data );  // ../../RTL/hispeed/asram16_intf.v(29)
  not \ram_ctl/u20  (\ram_ctl/n1 , \ram_ctl/access_data );  // ../../RTL/hispeed/asram16_intf.v(36)
  and \ram_ctl/u21  (\ram_ctl/n2 , ram_isel, \ram_ctl/n1 );  // ../../RTL/hispeed/asram16_intf.v(36)
  bufif1 \ram_ctl/u22  (ram_data[2], ddata_o[2], n13);  // ../../RTL/hispeed/asram16_intf.v(33)
  bufif1 \ram_ctl/u23  (ram_data[1], ddata_o[1], n13);  // ../../RTL/hispeed/asram16_intf.v(33)
  bufif1 \ram_ctl/u24  (ram_data[0], ddata_o[0], n13);  // ../../RTL/hispeed/asram16_intf.v(33)
  not \ram_ctl/u25  (\ram_ctl/n6 , \ram_ctl/n2 );  // ../../RTL/hispeed/asram16_intf.v(52)
  not \ram_ctl/u26  (\ram_ctl/n7 , \ram_ctl/wait_data_hold );  // ../../RTL/hispeed/asram16_intf.v(54)
  and \ram_ctl/u27  (WAIT_DATA, \ram_ctl/access_data , \ram_ctl/n7 );  // ../../RTL/hispeed/asram16_intf.v(54)
  not \ram_ctl/u3  (ram_cen, \ram_ctl/n0 );  // ../../RTL/hispeed/asram16_intf.v(29)
  not \ram_ctl/u4  (ram_wen, n13);  // ../../RTL/hispeed/asram16_intf.v(30)
  bufif1 \ram_ctl/u5  (ram_data[3], ddata_o[3], n13);  // ../../RTL/hispeed/asram16_intf.v(33)
  not \ram_ctl/u6  (ram_wstrbn[1], cpu_daddr[0]);  // ../../RTL/hispeed/asram16_intf.v(32)
  bufif1 \ram_ctl/u8  (ram_data[15], ddata_o[7], n13);  // ../../RTL/hispeed/asram16_intf.v(33)
  bufif1 \ram_ctl/u9  (ram_data[14], ddata_o[6], n13);  // ../../RTL/hispeed/asram16_intf.v(33)
  reg_ar_as_w1 \ram_ctl/wait_data_hold_reg  (
    .clk(clk),
    .d(\ram_ctl/access_data ),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .q(\ram_ctl/wait_data_hold ));  // ../../RTL/hispeed/asram16_intf.v(53)
  or u0 (n0, 1'b0, 1'b0);  // ../../RTL/top/CPLD_LS1u.v(62)
  or u1 (n1, 1'b0, 1'b0);  // ../../RTL/top/CPLD_LS1u.v(62)
  or u10 (n10, n2, n11);  // ../../RTL/top/CPLD_LS1u.v(62)
  or u11 (n7, cpu_iaddr[17], n9);  // ../../RTL/top/CPLD_LS1u.v(61)
  or u12 (n6, cpu_iaddr[20], cpu_iaddr[21]);  // ../../RTL/top/CPLD_LS1u.v(61)
  or u13 (n5, cpu_iaddr[22], cpu_iaddr[23]);  // ../../RTL/top/CPLD_LS1u.v(61)
  or u14 (n4, n6, n5);  // ../../RTL/top/CPLD_LS1u.v(61)
  or u15 (n8, n7, n4);  // ../../RTL/top/CPLD_LS1u.v(61)
  or u2 (n2, 1'b0, n3);  // ../../RTL/top/CPLD_LS1u.v(62)
  or u3 (n3, 1'b0, 1'b0);  // ../../RTL/top/CPLD_LS1u.v(62)
  not u4 (ram_isel, n8);  // ../../RTL/top/CPLD_LS1u.v(61)
  or u5 (n9, cpu_iaddr[18], cpu_iaddr[19]);  // ../../RTL/top/CPLD_LS1u.v(61)
  not u6 (ram_dsel, n10);  // ../../RTL/top/CPLD_LS1u.v(62)
  and u7 (n12, dread, ram_dsel);  // ../../RTL/top/CPLD_LS1u.v(73)
  and u8 (n13, dwrite, ram_dsel);  // ../../RTL/top/CPLD_LS1u.v(74)
  or u9 (n11, n1, n0);  // ../../RTL/top/CPLD_LS1u.v(62)

endmodule 

module CPU_LS1u_Lite  // ../../RTL/cpu/CPU_LS1u_Lite.v(1)
  (
  INT_ARR,
  WAIT_DATA,
  WAIT_INSTR,
  clk,
  ddata_i,
  instr,
  jtck,
  jtdi,
  jtms,
  rst,
  sys_por,
  INSTR_HOLD,
  cpu_daddr,
  cpu_iaddr,
  ddata_o,
  dread,
  dwrite,
  jrst_out,
  jtdo
  );

  input [7:0] INT_ARR;  // ../../RTL/cpu/CPU_LS1u_Lite.v(24)
  input WAIT_DATA;  // ../../RTL/cpu/CPU_LS1u_Lite.v(20)
  input WAIT_INSTR;  // ../../RTL/cpu/CPU_LS1u_Lite.v(16)
  input clk;  // ../../RTL/cpu/CPU_LS1u_Lite.v(9)
  input [7:0] ddata_i;  // ../../RTL/cpu/CPU_LS1u_Lite.v(22)
  input [15:0] instr;  // ../../RTL/cpu/CPU_LS1u_Lite.v(15)
  input jtck;  // ../../RTL/cpu/CPU_LS1u_Lite.v(11)
  input jtdi;  // ../../RTL/cpu/CPU_LS1u_Lite.v(11)
  input jtms;  // ../../RTL/cpu/CPU_LS1u_Lite.v(11)
  input rst;  // ../../RTL/cpu/CPU_LS1u_Lite.v(9)
  input sys_por;  // ../../RTL/cpu/CPU_LS1u_Lite.v(8)
  output INSTR_HOLD;  // ../../RTL/cpu/CPU_LS1u_Lite.v(21)
  output [23:0] cpu_daddr;  // ../../RTL/cpu/CPU_LS1u_Lite.v(17)
  output [23:0] cpu_iaddr;  // ../../RTL/cpu/CPU_LS1u_Lite.v(14)
  output [7:0] ddata_o;  // ../../RTL/cpu/CPU_LS1u_Lite.v(23)
  output dread;  // ../../RTL/cpu/CPU_LS1u_Lite.v(18)
  output dwrite;  // ../../RTL/cpu/CPU_LS1u_Lite.v(19)
  output jrst_out;  // ../../RTL/cpu/CPU_LS1u_Lite.v(10)
  output jtdo;  // ../../RTL/cpu/CPU_LS1u_Lite.v(12)

  parameter BUS_AWIDTH = 24;
  parameter CPU_TYPE = "PLUS";
  parameter MMU_ENABLE = 1'b0;
  // localparam BUS_ADDRWID = 24;
  wire [23:0] IVEC_addr;  // ../../RTL/cpu/CPU_LS1u_Lite.v(44)
  wire [7:0] XCRa;  // ../../RTL/cpu/CPU_LS1u_Lite.v(39)
  wire [7:0] XCRi;  // ../../RTL/cpu/CPU_LS1u_Lite.v(37)
  wire [7:0] XCRo;  // ../../RTL/cpu/CPU_LS1u_Lite.v(38)
  wire XCRcs;  // ../../RTL/cpu/CPU_LS1u_Lite.v(41)
  wire XCRwe;  // ../../RTL/cpu/CPU_LS1u_Lite.v(40)

  assign INSTR_HOLD = 1'b0;
  assign cpu_daddr[23] = 1'b0;
  assign cpu_daddr[22] = 1'b0;
  assign cpu_daddr[21] = 1'b0;
  assign cpu_daddr[20] = 1'b0;
  assign cpu_daddr[19] = 1'b0;
  assign cpu_daddr[18] = 1'b0;
  assign cpu_daddr[17] = 1'b0;
  assign cpu_daddr[16] = 1'b0;
  assign cpu_iaddr[0] = 1'b0;
  assign jrst_out = 1'b0;
  assign jtdo = 1'b0;
  KC_LS1u_plus GEN_PLUS_CORE$CORE (
    .INT(1'b0),
    .IVEC_addr({1'b0,IVEC_addr[22:0]}),
    .WAIT(WAIT_INSTR),
    .WAIT_DATA(WAIT_DATA),
    .XCRi(XCRi),
    .clk(clk),
    .ddata_i(ddata_i),
    .instr(instr),
    .rst(1'b0),
    .XCRa({XCRa[7:4],open_n2,XCRa[2:0]}),
    .XCRcs(XCRcs),
    .XCRo(XCRo),
    .XCRwe(XCRwe),
    .daddr({open_n3,open_n4,open_n5,open_n6,open_n7,open_n8,open_n9,open_n10,cpu_daddr[15:0]}),
    .ddata_o(ddata_o),
    .dread(dread),
    .dwrite(dwrite),
    .iaddr({open_n11,cpu_iaddr[23:1]}));  // ../../RTL/cpu/CPU_LS1u_Lite.v(128)
  \xcr_top(MMU_ENABLE=1'b0)  GEN_XCR$eXternalCtrlRegs (
    .INT_ARR(8'b00000000),
    .XCP_ARR(8'b00000000),
    .clk(clk),
    .cr_adr({XCRa[7:4],1'b0,XCRa[2:0]}),
    .cr_cs(XCRcs),
    .cr_din(XCRo),
    .cr_we(XCRwe),
    .rst(1'b0),
    .IVEC_ADDR({open_n13,IVEC_addr[22:0]}),
    .cr_dout(XCRi));  // ../../RTL/cpu/CPU_LS1u_Lite.v(175)
  ELF_LOGIC_GSRN #(
    .USR_GSRN("ENABLE"))
    logic_gsrn (
    .gsrn(1'b1),
    .sync_clk(1'b0));

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

module KC_LS1u_plus  // ../../RTL/cpu/KC_LS1u_plus.v(1)
  (
  INT,
  IVEC_addr,
  WAIT,
  WAIT_DATA,
  XCRi,
  clk,
  ddata_i,
  instr,
  rst,
  INSTR_HOLD,
  IN_ISP,
  XCRa,
  XCRcs,
  XCRo,
  XCRwe,
  daddr,
  ddata_o,
  dread,
  dwrite,
  iaddr
  );

  input INT;  // ../../RTL/cpu/KC_LS1u_plus.v(3)
  input [23:0] IVEC_addr;  // ../../RTL/cpu/KC_LS1u_plus.v(4)
  input WAIT;  // ../../RTL/cpu/KC_LS1u_plus.v(3)
  input WAIT_DATA;  // ../../RTL/cpu/KC_LS1u_plus.v(18)
  input [7:0] XCRi;  // ../../RTL/cpu/KC_LS1u_plus.v(7)
  input clk;  // ../../RTL/cpu/KC_LS1u_plus.v(3)
  input [7:0] ddata_i;  // ../../RTL/cpu/KC_LS1u_plus.v(20)
  input [15:0] instr;  // ../../RTL/cpu/KC_LS1u_plus.v(14)
  input rst;  // ../../RTL/cpu/KC_LS1u_plus.v(3)
  output INSTR_HOLD;  // ../../RTL/cpu/KC_LS1u_plus.v(19)
  output IN_ISP;  // ../../RTL/cpu/KC_LS1u_plus.v(5)
  output [7:0] XCRa;  // ../../RTL/cpu/KC_LS1u_plus.v(9)
  output XCRcs;  // ../../RTL/cpu/KC_LS1u_plus.v(11)
  output [7:0] XCRo;  // ../../RTL/cpu/KC_LS1u_plus.v(8)
  output XCRwe;  // ../../RTL/cpu/KC_LS1u_plus.v(10)
  output [23:0] daddr;  // ../../RTL/cpu/KC_LS1u_plus.v(15)
  output [7:0] ddata_o;  // ../../RTL/cpu/KC_LS1u_plus.v(21)
  output dread;  // ../../RTL/cpu/KC_LS1u_plus.v(16)
  output dwrite;  // ../../RTL/cpu/KC_LS1u_plus.v(17)
  output [23:0] iaddr;  // ../../RTL/cpu/KC_LS1u_plus.v(13)

  wire [7:0] A;  // ../../RTL/cpu/KC_LS1u_plus.v(101)
  wire [1:0] ALU_eq;  // ../../RTL/cpu/KC_LS1u_plus.v(224)
  wire [7:0] ALU_out;  // ../../RTL/cpu/KC_LS1u_plus.v(223)
  wire [7:0] B;  // ../../RTL/cpu/KC_LS1u_plus.v(101)
  wire [7:0] C;  // ../../RTL/cpu/KC_LS1u_plus.v(101)
  wire [7:0] D;  // ../../RTL/cpu/KC_LS1u_plus.v(101)
  wire [23:0] PCP1;  // ../../RTL/cpu/KC_LS1u_plus.v(42)
  wire [23:0] PC_NEXT;  // ../../RTL/cpu/KC_LS1u_plus.v(25)
  wire [7:0] RET0;  // ../../RTL/cpu/KC_LS1u_plus.v(26)
  wire [7:0] RET1;  // ../../RTL/cpu/KC_LS1u_plus.v(26)
  wire [7:0] RET2;  // ../../RTL/cpu/KC_LS1u_plus.v(26)
  wire [7:0] RTA0;  // ../../RTL/cpu/KC_LS1u_plus.v(27)
  wire [7:0] RTA1;  // ../../RTL/cpu/KC_LS1u_plus.v(27)
  wire [7:0] RTA2;  // ../../RTL/cpu/KC_LS1u_plus.v(27)
  wire [7:0] SFTO;  // ../../RTL/cpu/KC_LS1u_plus.v(256)
  wire [7:0] XREGr;  // ../../RTL/cpu/KC_LS1u_plus.v(201)
  wire [3:0] dbsrc_addr;  // ../../RTL/cpu/KC_LS1u_plus.v(153)
  wire [23:0] jaddr;  // ../../RTL/cpu/KC_LS1u_plus.v(30)
  wire [7:0] n10;
  wire [7:0] n11;
  wire [7:0] n12;
  wire [7:0] n27;
  wire [7:0] n28;
  wire [7:0] n29;
  wire [7:0] n30;
  wire [7:0] n31;
  wire [7:0] n32;
  wire [7:0] n33;
  wire [7:0] n34;
  wire [7:0] n35;
  wire [7:0] n37;
  wire [7:0] n38;
  wire [7:0] n39;
  wire [23:0] n5;
  wire [7:0] n52;
  wire [7:0] n53;
  wire [7:0] n54;
  wire [7:0] n58;
  wire [7:0] n59;
  wire [7:0] n60;
  wire ALU_C1;  // ../../RTL/cpu/KC_LS1u_plus.v(225)
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
  wire \ALU_L4/SYNTHESIZED_WIRE_102 ;  // ../../RTL/cpu/alu74181.v(57)
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
  wire \ALU_L4/SYNTHESIZED_WIRE_56 ;  // ../../RTL/cpu/alu74181.v(38)
  wire \ALU_L4/SYNTHESIZED_WIRE_57 ;  // ../../RTL/cpu/alu74181.v(39)
  wire \ALU_L4/SYNTHESIZED_WIRE_58 ;  // ../../RTL/cpu/alu74181.v(40)
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
  wire \ALU_L4/SYNTHESIZED_WIRE_97 ;  // ../../RTL/cpu/alu74181.v(53)
  wire \ALU_L4/SYNTHESIZED_WIRE_98 ;  // ../../RTL/cpu/alu74181.v(54)
  wire \ALU_L4/SYNTHESIZED_WIRE_99 ;  // ../../RTL/cpu/alu74181.v(55)
  wire \ALU_L4/g ;  // ../../RTL/cpu/alu74181.v(8)
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
  wire \ALU_L4/n18 ;
  wire \ALU_L4/n19 ;
  wire \ALU_L4/n2 ;
  wire \ALU_L4/n20 ;
  wire \ALU_L4/n22 ;
  wire \ALU_L4/n23 ;
  wire \ALU_L4/n24 ;
  wire \ALU_L4/n25 ;
  wire \ALU_L4/n26 ;
  wire \ALU_L4/n27 ;
  wire \ALU_L4/n28 ;
  wire \ALU_L4/n29 ;
  wire \ALU_L4/n3 ;
  wire \ALU_L4/n30 ;
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
  wire \ALU_L4/n42 ;
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
  wire ALU_eqo;  // ../../RTL/cpu/KC_LS1u_plus.v(225)
  wire \XCRa[0]_neg ;
  wire \XCRa[1]_neg ;
  wire \XCRa[2]_neg ;
  wire \instr[10]_neg ;
  wire \instr[8]_neg ;
  wire \instr[9]_neg ;
  wire instr_wait;  // ../../RTL/cpu/KC_LS1u_plus.v(38)
  wire int_filter;  // ../../RTL/cpu/KC_LS1u_plus.v(35)
  wire jmp;  // ../../RTL/cpu/KC_LS1u_plus.v(32)
  wire jmp_en;  // ../../RTL/cpu/KC_LS1u_plus.v(136)
  wire jmp_wait;  // ../../RTL/cpu/KC_LS1u_plus.v(31)
  wire mux10_b0_sel_is_1_o;
  wire mux11_b0_sel_is_0_o;
  wire mux12_b0_sel_is_3_o;
  wire mux13_b0_sel_is_3_o;
  wire mux14_b0_sel_is_3_o;
  wire mux15_b0_sel_is_3_o;
  wire mux16_b0_sel_is_3_o;
  wire mux17_b0_sel_is_3_o;
  wire mux18_b0_sel_is_2_o;
  wire mux19_b0_sel_is_2_o;
  wire mux20_b0_sel_is_2_o;
  wire mux21_b0_sel_is_2_o;
  wire mux22_b0_sel_is_2_o;
  wire mux23_b0_sel_is_2_o;
  wire mux33_b0_sel_is_6_o;
  wire mux34_b0_sel_is_5_o;
  wire mux35_b0_sel_is_4_o;
  wire mux36_b0_sel_is_3_o;
  wire mux37_b0_sel_is_2_o;
  wire mux38_b0_sel_is_1_o;
  wire mux39_b0_sel_is_0_o;
  wire mux40_b0_sel_is_3_o;
  wire mux41_b0_sel_is_3_o;
  wire mux42_b0_sel_is_3_o;
  wire mux43_b0_sel_is_3_o;
  wire mux44_b0_sel_is_3_o;
  wire mux45_b0_sel_is_3_o;
  wire mux46_b0_sel_is_3_o;
  wire mux50_b0_sel_is_2_o;
  wire mux51_b0_sel_is_2_o;
  wire mux52_b0_sel_is_2_o;
  wire mux53_b0_sel_is_2_o;
  wire mux6_b0_sel_is_5_o;
  wire mux7_b0_sel_is_4_o;
  wire mux8_b0_sel_is_3_o;
  wire mux9_b0_sel_is_2_o;
  wire n0;
  wire n1;
  wire n100;
  wire n101;
  wire n102;
  wire n103;
  wire n104;
  wire n105;
  wire n106;
  wire n107;
  wire n108;
  wire n109;
  wire n110;
  wire n111;
  wire n112;
  wire n113;
  wire n114;
  wire n115;
  wire n116;
  wire n117;
  wire n118;
  wire n119;
  wire n120;
  wire n121;
  wire n122;
  wire n123;
  wire n124;
  wire n125;
  wire n128;
  wire n13;
  wire n133;
  wire n135;
  wire n139;
  wire n140;
  wire n141;
  wire n2;
  wire n26;
  wire n3;
  wire n36;
  wire n4;
  wire n43;
  wire n6;
  wire n65;
  wire n66;
  wire n67;
  wire n68;
  wire n69;
  wire n70;
  wire n71;
  wire n72;
  wire n73;
  wire n74;
  wire n75;
  wire n76;
  wire n77;
  wire n78;
  wire n79;
  wire n8;
  wire n80;
  wire n9;
  wire n90;
  wire n91;
  wire n93;
  wire n95;
  wire n96;
  wire n97;
  wire n98;
  wire n99;
  wire regwrite;  // ../../RTL/cpu/KC_LS1u_plus.v(98)
  wire ret_sel;  // ../../RTL/cpu/KC_LS1u_plus.v(32)
  wire ret_sel_neg;
  wire sel0_b0_sel_o;  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  wire sel0_b1_sel_o;  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  wire sel0_b2_sel_o;  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  wire sel0_b3_sel_o;  // ../../RTL/cpu/KC_LS1u_plus.v(199)

  assign XCRa[7] = instr[7];
  assign XCRa[6] = instr[6];
  assign XCRa[5] = instr[5];
  assign XCRa[4] = instr[4];
  assign XCRa[3] = instr[3];
  assign XCRa[2] = instr[2];
  assign XCRa[1] = instr[1];
  assign XCRa[0] = instr[0];
  assign XCRcs = n115;
  assign ddata_o[7] = XCRo[7];
  assign ddata_o[6] = XCRo[6];
  assign ddata_o[5] = XCRo[5];
  assign ddata_o[4] = XCRo[4];
  assign ddata_o[3] = XCRo[3];
  assign ddata_o[2] = XCRo[2];
  assign ddata_o[1] = XCRo[1];
  assign ddata_o[0] = XCRo[0];
  assign iaddr[23] = 1'b0;
  and \ALU_H4/u1  (\ALU_H4/SYNTHESIZED_WIRE_14 , XCRa[4], B[5]);  // ../../RTL/cpu/alu74181.v(73)
  and \ALU_H4/u10  (\ALU_H4/SYNTHESIZED_WIRE_23 , \ALU_H4/n2 , A[6]);  // ../../RTL/cpu/alu74181.v(85)
  and \ALU_H4/u100  (\ALU_H4/n44 , \ALU_H4/SYNTHESIZED_WIRE_129 , XCRa[6]);  // ../../RTL/cpu/alu74181.v(175)
  and \ALU_H4/u101  (\ALU_H4/SYNTHESIZED_WIRE_19 , \ALU_H4/n44 , A[4]);  // ../../RTL/cpu/alu74181.v(175)
  xor \ALU_H4/u102  (ALU_out[4], \ALU_H4/SYNTHESIZED_WIRE_101 , \ALU_H4/SYNTHESIZED_WIRE_102 );  // ../../RTL/cpu/alu74181.v(177)
  xor \ALU_H4/u103  (ALU_out[5], \ALU_H4/SYNTHESIZED_WIRE_103 , \ALU_H4/SYNTHESIZED_WIRE_115 );  // ../../RTL/cpu/alu74181.v(179)
  xor \ALU_H4/u104  (ALU_out[6], \ALU_H4/SYNTHESIZED_WIRE_105 , \ALU_H4/SYNTHESIZED_WIRE_116 );  // ../../RTL/cpu/alu74181.v(181)
  and \ALU_H4/u105  (\ALU_H4/n45 , ALU_out[7], ALU_out[6]);  // ../../RTL/cpu/alu74181.v(183)
  and \ALU_H4/u106  (\ALU_H4/n46 , \ALU_H4/n45 , ALU_out[5]);  // ../../RTL/cpu/alu74181.v(183)
  and \ALU_H4/u107  (ALU_eq[1], \ALU_H4/n46 , ALU_out[4]);  // ../../RTL/cpu/alu74181.v(183)
  and \ALU_H4/u108  (\ALU_H4/n47 , A[4], XCRa[7]);  // ../../RTL/cpu/alu74181.v(185)
  and \ALU_H4/u109  (\ALU_H4/SYNTHESIZED_WIRE_18 , \ALU_H4/n47 , B[4]);  // ../../RTL/cpu/alu74181.v(185)
  and \ALU_H4/u11  (\ALU_H4/n3 , A[6], XCRa[7]);  // ../../RTL/cpu/alu74181.v(87)
  not \ALU_H4/u110  (\ALU_H4/SYNTHESIZED_WIRE_128 , XCRa[3]);  // ../../RTL/cpu/alu74181.v(187)
  and \ALU_H4/u12  (\ALU_H4/SYNTHESIZED_WIRE_22 , \ALU_H4/n3 , B[6]);  // ../../RTL/cpu/alu74181.v(87)
  and \ALU_H4/u13  (\ALU_H4/SYNTHESIZED_WIRE_26 , XCRa[4], B[7]);  // ../../RTL/cpu/alu74181.v(89)
  and \ALU_H4/u14  (\ALU_H4/SYNTHESIZED_WIRE_27 , \ALU_H4/SYNTHESIZED_WIRE_119 , XCRa[5]);  // ../../RTL/cpu/alu74181.v(91)
  and \ALU_H4/u15  (\ALU_H4/n4 , \ALU_H4/SYNTHESIZED_WIRE_119 , XCRa[6]);  // ../../RTL/cpu/alu74181.v(93)
  and \ALU_H4/u16  (\ALU_H4/SYNTHESIZED_WIRE_29 , \ALU_H4/n4 , A[7]);  // ../../RTL/cpu/alu74181.v(93)
  and \ALU_H4/u17  (\ALU_H4/n5 , A[7], XCRa[7]);  // ../../RTL/cpu/alu74181.v(95)
  and \ALU_H4/u18  (\ALU_H4/SYNTHESIZED_WIRE_28 , \ALU_H4/n5 , B[7]);  // ../../RTL/cpu/alu74181.v(95)
  not \ALU_H4/u19  (\ALU_H4/SYNTHESIZED_WIRE_119 , B[7]);  // ../../RTL/cpu/alu74181.v(97)
  and \ALU_H4/u2  (\ALU_H4/SYNTHESIZED_WIRE_15 , \ALU_H4/SYNTHESIZED_WIRE_117 , XCRa[5]);  // ../../RTL/cpu/alu74181.v(75)
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
  and \ALU_H4/u3  (\ALU_H4/n0 , \ALU_H4/SYNTHESIZED_WIRE_117 , XCRa[6]);  // ../../RTL/cpu/alu74181.v(77)
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
  and \ALU_H4/u5  (\ALU_H4/n1 , A[5], XCRa[7]);  // ../../RTL/cpu/alu74181.v(79)
  and \ALU_H4/u50  (\ALU_H4/SYNTHESIZED_WIRE_12 , XCRa[4], B[4]);  // ../../RTL/cpu/alu74181.v(133)
  and \ALU_H4/u51  (\ALU_H4/n19 , \ALU_H4/SYNTHESIZED_WIRE_24 , \ALU_H4/SYNTHESIZED_WIRE_11 );  // ../../RTL/cpu/alu74181.v(135)
  and \ALU_H4/u52  (\ALU_H4/n20 , \ALU_H4/n19 , \ALU_H4/SYNTHESIZED_WIRE_9 );  // ../../RTL/cpu/alu74181.v(135)
  and \ALU_H4/u55  (\ALU_H4/n22 , \ALU_H4/SYNTHESIZED_WIRE_11 , \ALU_H4/SYNTHESIZED_WIRE_9 );  // ../../RTL/cpu/alu74181.v(137)
  and \ALU_H4/u56  (\ALU_H4/n23 , \ALU_H4/n22 , \ALU_H4/SYNTHESIZED_WIRE_7 );  // ../../RTL/cpu/alu74181.v(137)
  and \ALU_H4/u57  (\ALU_H4/n24 , \ALU_H4/n23 , \ALU_H4/SYNTHESIZED_WIRE_24 );  // ../../RTL/cpu/alu74181.v(137)
  and \ALU_H4/u58  (\ALU_H4/n25 , \ALU_H4/n24 , ALU_C1);  // ../../RTL/cpu/alu74181.v(137)
  and \ALU_H4/u59  (\ALU_H4/n26 , \ALU_H4/n25 , ALU_C1);  // ../../RTL/cpu/alu74181.v(137)
  and \ALU_H4/u6  (\ALU_H4/SYNTHESIZED_WIRE_20 , \ALU_H4/n1 , B[5]);  // ../../RTL/cpu/alu74181.v(79)
  not \ALU_H4/u60  (\ALU_H4/SYNTHESIZED_WIRE_97 , \ALU_H4/n26 );  // ../../RTL/cpu/alu74181.v(137)
  and \ALU_H4/u61  (\ALU_H4/SYNTHESIZED_WIRE_58 , \ALU_H4/n20 , \ALU_H4/SYNTHESIZED_WIRE_6 );  // ../../RTL/cpu/alu74181.v(139)
  or \ALU_H4/u62  (\ALU_H4/n27 , \ALU_H4/SYNTHESIZED_WIRE_25 , \ALU_H4/SYNTHESIZED_WIRE_56 );  // ../../RTL/cpu/alu74181.v(141)
  or \ALU_H4/u63  (\ALU_H4/n28 , \ALU_H4/n27 , \ALU_H4/SYNTHESIZED_WIRE_57 );  // ../../RTL/cpu/alu74181.v(141)
  or \ALU_H4/u64  (\ALU_H4/n29 , \ALU_H4/n28 , \ALU_H4/SYNTHESIZED_WIRE_58 );  // ../../RTL/cpu/alu74181.v(141)
  not \ALU_H4/u65  (\ALU_H4/g , \ALU_H4/n29 );  // ../../RTL/cpu/alu74181.v(141)
  and \ALU_H4/u66  (\ALU_H4/n30 , ALU_C1, \ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(143)
  not \ALU_H4/u67  (\ALU_H4/SYNTHESIZED_WIRE_102 , \ALU_H4/n30 );  // ../../RTL/cpu/alu74181.v(143)
  and \ALU_H4/u68  (\ALU_H4/SYNTHESIZED_WIRE_99 , \ALU_H4/SYNTHESIZED_WIRE_6 , \ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(145)
  and \ALU_H4/u69  (\ALU_H4/n31 , \ALU_H4/SYNTHESIZED_WIRE_128 , \ALU_H4/SYNTHESIZED_WIRE_7 );  // ../../RTL/cpu/alu74181.v(147)
  and \ALU_H4/u7  (\ALU_H4/SYNTHESIZED_WIRE_16 , XCRa[4], B[6]);  // ../../RTL/cpu/alu74181.v(81)
  and \ALU_H4/u70  (\ALU_H4/SYNTHESIZED_WIRE_98 , \ALU_H4/n31 , ALU_C1);  // ../../RTL/cpu/alu74181.v(147)
  and \ALU_H4/u71  (\ALU_H4/SYNTHESIZED_WIRE_90 , \ALU_H4/SYNTHESIZED_WIRE_8 , \ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(149)
  and \ALU_H4/u72  (\ALU_H4/SYNTHESIZED_WIRE_91 , \ALU_H4/SYNTHESIZED_WIRE_99 , \ALU_H4/SYNTHESIZED_WIRE_9 );  // ../../RTL/cpu/alu74181.v(151)
  and \ALU_H4/u73  (\ALU_H4/n32 , ALU_C1, \ALU_H4/SYNTHESIZED_WIRE_7 );  // ../../RTL/cpu/alu74181.v(153)
  and \ALU_H4/u74  (\ALU_H4/n33 , \ALU_H4/n32 , \ALU_H4/SYNTHESIZED_WIRE_9 );  // ../../RTL/cpu/alu74181.v(153)
  and \ALU_H4/u75  (\ALU_H4/SYNTHESIZED_WIRE_92 , \ALU_H4/n33 , \ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(153)
  and \ALU_H4/u76  (\ALU_H4/SYNTHESIZED_WIRE_13 , \ALU_H4/SYNTHESIZED_WIRE_129 , XCRa[5]);  // ../../RTL/cpu/alu74181.v(155)
  and \ALU_H4/u77  (\ALU_H4/SYNTHESIZED_WIRE_89 , \ALU_H4/SYNTHESIZED_WIRE_10 , \ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(157)
  and \ALU_H4/u79  (\ALU_H4/SYNTHESIZED_WIRE_88 , \ALU_H4/SYNTHESIZED_WIRE_90 , \ALU_H4/SYNTHESIZED_WIRE_11 );  // ../../RTL/cpu/alu74181.v(159)
  and \ALU_H4/u8  (\ALU_H4/SYNTHESIZED_WIRE_17 , \ALU_H4/SYNTHESIZED_WIRE_118 , XCRa[5]);  // ../../RTL/cpu/alu74181.v(83)
  and \ALU_H4/u81  (\ALU_H4/n34 , \ALU_H4/n22 , \ALU_H4/SYNTHESIZED_WIRE_6 );  // ../../RTL/cpu/alu74181.v(161)
  and \ALU_H4/u82  (\ALU_H4/SYNTHESIZED_WIRE_87 , \ALU_H4/n34 , \ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(161)
  and \ALU_H4/u85  (\ALU_H4/n35 , \ALU_H4/n33 , ALU_C1);  // ../../RTL/cpu/alu74181.v(163)
  and \ALU_H4/u86  (\ALU_H4/n36 , \ALU_H4/n35 , \ALU_H4/SYNTHESIZED_WIRE_11 );  // ../../RTL/cpu/alu74181.v(163)
  and \ALU_H4/u87  (\ALU_H4/SYNTHESIZED_WIRE_86 , \ALU_H4/n36 , \ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(163)
  or \ALU_H4/u88  (\ALU_H4/n37 , \ALU_H4/SYNTHESIZED_WIRE_86 , \ALU_H4/SYNTHESIZED_WIRE_87 );  // ../../RTL/cpu/alu74181.v(165)
  or \ALU_H4/u89  (\ALU_H4/n38 , \ALU_H4/n37 , \ALU_H4/SYNTHESIZED_WIRE_88 );  // ../../RTL/cpu/alu74181.v(165)
  and \ALU_H4/u9  (\ALU_H4/n2 , \ALU_H4/SYNTHESIZED_WIRE_118 , XCRa[6]);  // ../../RTL/cpu/alu74181.v(85)
  or \ALU_H4/u90  (\ALU_H4/n39 , \ALU_H4/n38 , \ALU_H4/SYNTHESIZED_WIRE_89 );  // ../../RTL/cpu/alu74181.v(165)
  not \ALU_H4/u91  (\ALU_H4/SYNTHESIZED_WIRE_93 , \ALU_H4/n39 );  // ../../RTL/cpu/alu74181.v(165)
  or \ALU_H4/u92  (\ALU_H4/n40 , \ALU_H4/SYNTHESIZED_WIRE_90 , \ALU_H4/SYNTHESIZED_WIRE_91 );  // ../../RTL/cpu/alu74181.v(167)
  or \ALU_H4/u93  (\ALU_H4/n41 , \ALU_H4/n40 , \ALU_H4/SYNTHESIZED_WIRE_92 );  // ../../RTL/cpu/alu74181.v(167)
  not \ALU_H4/u94  (\ALU_H4/SYNTHESIZED_WIRE_116 , \ALU_H4/n41 );  // ../../RTL/cpu/alu74181.v(167)
  xor \ALU_H4/u95  (ALU_out[7], \ALU_H4/SYNTHESIZED_WIRE_94 , \ALU_H4/SYNTHESIZED_WIRE_93 );  // ../../RTL/cpu/alu74181.v(169)
  and \ALU_H4/u96  (\ALU_H4/n42 , \ALU_H4/g , \ALU_H4/SYNTHESIZED_WIRE_97 );  // ../../RTL/cpu/alu74181.v(171)
  or \ALU_H4/u98  (\ALU_H4/n43 , \ALU_H4/SYNTHESIZED_WIRE_98 , \ALU_H4/SYNTHESIZED_WIRE_99 );  // ../../RTL/cpu/alu74181.v(173)
  not \ALU_H4/u99  (\ALU_H4/SYNTHESIZED_WIRE_115 , \ALU_H4/n43 );  // ../../RTL/cpu/alu74181.v(173)
  and \ALU_L4/u1  (\ALU_L4/SYNTHESIZED_WIRE_14 , XCRa[4], B[1]);  // ../../RTL/cpu/alu74181.v(73)
  and \ALU_L4/u10  (\ALU_L4/SYNTHESIZED_WIRE_23 , \ALU_L4/n2 , A[2]);  // ../../RTL/cpu/alu74181.v(85)
  and \ALU_L4/u100  (\ALU_L4/n44 , \ALU_L4/SYNTHESIZED_WIRE_129 , XCRa[6]);  // ../../RTL/cpu/alu74181.v(175)
  and \ALU_L4/u101  (\ALU_L4/SYNTHESIZED_WIRE_19 , \ALU_L4/n44 , A[0]);  // ../../RTL/cpu/alu74181.v(175)
  xor \ALU_L4/u102  (ALU_out[0], \ALU_L4/SYNTHESIZED_WIRE_101 , \ALU_L4/SYNTHESIZED_WIRE_102 );  // ../../RTL/cpu/alu74181.v(177)
  xor \ALU_L4/u103  (ALU_out[1], \ALU_L4/SYNTHESIZED_WIRE_103 , \ALU_L4/SYNTHESIZED_WIRE_115 );  // ../../RTL/cpu/alu74181.v(179)
  xor \ALU_L4/u104  (ALU_out[2], \ALU_L4/SYNTHESIZED_WIRE_105 , \ALU_L4/SYNTHESIZED_WIRE_116 );  // ../../RTL/cpu/alu74181.v(181)
  and \ALU_L4/u105  (\ALU_L4/n45 , ALU_out[3], ALU_out[2]);  // ../../RTL/cpu/alu74181.v(183)
  and \ALU_L4/u106  (\ALU_L4/n46 , \ALU_L4/n45 , ALU_out[1]);  // ../../RTL/cpu/alu74181.v(183)
  and \ALU_L4/u107  (ALU_eq[0], \ALU_L4/n46 , ALU_out[0]);  // ../../RTL/cpu/alu74181.v(183)
  and \ALU_L4/u108  (\ALU_L4/n47 , A[0], XCRa[7]);  // ../../RTL/cpu/alu74181.v(185)
  and \ALU_L4/u109  (\ALU_L4/SYNTHESIZED_WIRE_18 , \ALU_L4/n47 , B[0]);  // ../../RTL/cpu/alu74181.v(185)
  and \ALU_L4/u11  (\ALU_L4/n3 , A[2], XCRa[7]);  // ../../RTL/cpu/alu74181.v(87)
  and \ALU_L4/u12  (\ALU_L4/SYNTHESIZED_WIRE_22 , \ALU_L4/n3 , B[2]);  // ../../RTL/cpu/alu74181.v(87)
  and \ALU_L4/u13  (\ALU_L4/SYNTHESIZED_WIRE_26 , XCRa[4], B[3]);  // ../../RTL/cpu/alu74181.v(89)
  and \ALU_L4/u14  (\ALU_L4/SYNTHESIZED_WIRE_27 , \ALU_L4/SYNTHESIZED_WIRE_119 , XCRa[5]);  // ../../RTL/cpu/alu74181.v(91)
  and \ALU_L4/u15  (\ALU_L4/n4 , \ALU_L4/SYNTHESIZED_WIRE_119 , XCRa[6]);  // ../../RTL/cpu/alu74181.v(93)
  and \ALU_L4/u16  (\ALU_L4/SYNTHESIZED_WIRE_29 , \ALU_L4/n4 , A[3]);  // ../../RTL/cpu/alu74181.v(93)
  and \ALU_L4/u17  (\ALU_L4/n5 , A[3], XCRa[7]);  // ../../RTL/cpu/alu74181.v(95)
  and \ALU_L4/u18  (\ALU_L4/SYNTHESIZED_WIRE_28 , \ALU_L4/n5 , B[3]);  // ../../RTL/cpu/alu74181.v(95)
  not \ALU_L4/u19  (\ALU_L4/SYNTHESIZED_WIRE_119 , B[3]);  // ../../RTL/cpu/alu74181.v(97)
  and \ALU_L4/u2  (\ALU_L4/SYNTHESIZED_WIRE_15 , \ALU_L4/SYNTHESIZED_WIRE_117 , XCRa[5]);  // ../../RTL/cpu/alu74181.v(75)
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
  and \ALU_L4/u3  (\ALU_L4/n0 , \ALU_L4/SYNTHESIZED_WIRE_117 , XCRa[6]);  // ../../RTL/cpu/alu74181.v(77)
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
  and \ALU_L4/u47  (\ALU_L4/SYNTHESIZED_WIRE_56 , \ALU_L4/SYNTHESIZED_WIRE_24 , \ALU_L4/SYNTHESIZED_WIRE_10 );  // ../../RTL/cpu/alu74181.v(129)
  and \ALU_L4/u48  (\ALU_L4/n18 , \ALU_L4/SYNTHESIZED_WIRE_8 , \ALU_L4/SYNTHESIZED_WIRE_11 );  // ../../RTL/cpu/alu74181.v(131)
  and \ALU_L4/u49  (\ALU_L4/SYNTHESIZED_WIRE_57 , \ALU_L4/n18 , \ALU_L4/SYNTHESIZED_WIRE_24 );  // ../../RTL/cpu/alu74181.v(131)
  and \ALU_L4/u5  (\ALU_L4/n1 , A[1], XCRa[7]);  // ../../RTL/cpu/alu74181.v(79)
  and \ALU_L4/u50  (\ALU_L4/SYNTHESIZED_WIRE_12 , XCRa[4], B[0]);  // ../../RTL/cpu/alu74181.v(133)
  and \ALU_L4/u51  (\ALU_L4/n19 , \ALU_L4/SYNTHESIZED_WIRE_24 , \ALU_L4/SYNTHESIZED_WIRE_11 );  // ../../RTL/cpu/alu74181.v(135)
  and \ALU_L4/u52  (\ALU_L4/n20 , \ALU_L4/n19 , \ALU_L4/SYNTHESIZED_WIRE_9 );  // ../../RTL/cpu/alu74181.v(135)
  and \ALU_L4/u55  (\ALU_L4/n22 , \ALU_L4/SYNTHESIZED_WIRE_11 , \ALU_L4/SYNTHESIZED_WIRE_9 );  // ../../RTL/cpu/alu74181.v(137)
  and \ALU_L4/u56  (\ALU_L4/n23 , \ALU_L4/n22 , \ALU_L4/SYNTHESIZED_WIRE_7 );  // ../../RTL/cpu/alu74181.v(137)
  and \ALU_L4/u57  (\ALU_L4/n24 , \ALU_L4/n23 , \ALU_L4/SYNTHESIZED_WIRE_24 );  // ../../RTL/cpu/alu74181.v(137)
  and \ALU_L4/u58  (\ALU_L4/n25 , \ALU_L4/n24 , XCRa[2]);  // ../../RTL/cpu/alu74181.v(137)
  and \ALU_L4/u59  (\ALU_L4/n26 , \ALU_L4/n25 , XCRa[2]);  // ../../RTL/cpu/alu74181.v(137)
  and \ALU_L4/u6  (\ALU_L4/SYNTHESIZED_WIRE_20 , \ALU_L4/n1 , B[1]);  // ../../RTL/cpu/alu74181.v(79)
  not \ALU_L4/u60  (\ALU_L4/SYNTHESIZED_WIRE_97 , \ALU_L4/n26 );  // ../../RTL/cpu/alu74181.v(137)
  and \ALU_L4/u61  (\ALU_L4/SYNTHESIZED_WIRE_58 , \ALU_L4/n20 , \ALU_L4/SYNTHESIZED_WIRE_6 );  // ../../RTL/cpu/alu74181.v(139)
  or \ALU_L4/u62  (\ALU_L4/n27 , \ALU_L4/SYNTHESIZED_WIRE_25 , \ALU_L4/SYNTHESIZED_WIRE_56 );  // ../../RTL/cpu/alu74181.v(141)
  or \ALU_L4/u63  (\ALU_L4/n28 , \ALU_L4/n27 , \ALU_L4/SYNTHESIZED_WIRE_57 );  // ../../RTL/cpu/alu74181.v(141)
  or \ALU_L4/u64  (\ALU_L4/n29 , \ALU_L4/n28 , \ALU_L4/SYNTHESIZED_WIRE_58 );  // ../../RTL/cpu/alu74181.v(141)
  not \ALU_L4/u65  (\ALU_L4/g , \ALU_L4/n29 );  // ../../RTL/cpu/alu74181.v(141)
  and \ALU_L4/u66  (\ALU_L4/n30 , XCRa[2], \ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(143)
  not \ALU_L4/u67  (\ALU_L4/SYNTHESIZED_WIRE_102 , \ALU_L4/n30 );  // ../../RTL/cpu/alu74181.v(143)
  and \ALU_L4/u68  (\ALU_L4/SYNTHESIZED_WIRE_99 , \ALU_L4/SYNTHESIZED_WIRE_6 , \ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(145)
  and \ALU_L4/u69  (\ALU_L4/n31 , \ALU_H4/SYNTHESIZED_WIRE_128 , \ALU_L4/SYNTHESIZED_WIRE_7 );  // ../../RTL/cpu/alu74181.v(147)
  and \ALU_L4/u7  (\ALU_L4/SYNTHESIZED_WIRE_16 , XCRa[4], B[2]);  // ../../RTL/cpu/alu74181.v(81)
  and \ALU_L4/u70  (\ALU_L4/SYNTHESIZED_WIRE_98 , \ALU_L4/n31 , XCRa[2]);  // ../../RTL/cpu/alu74181.v(147)
  and \ALU_L4/u71  (\ALU_L4/SYNTHESIZED_WIRE_90 , \ALU_L4/SYNTHESIZED_WIRE_8 , \ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(149)
  and \ALU_L4/u72  (\ALU_L4/SYNTHESIZED_WIRE_91 , \ALU_L4/SYNTHESIZED_WIRE_99 , \ALU_L4/SYNTHESIZED_WIRE_9 );  // ../../RTL/cpu/alu74181.v(151)
  and \ALU_L4/u73  (\ALU_L4/n32 , XCRa[2], \ALU_L4/SYNTHESIZED_WIRE_7 );  // ../../RTL/cpu/alu74181.v(153)
  and \ALU_L4/u74  (\ALU_L4/n33 , \ALU_L4/n32 , \ALU_L4/SYNTHESIZED_WIRE_9 );  // ../../RTL/cpu/alu74181.v(153)
  and \ALU_L4/u75  (\ALU_L4/SYNTHESIZED_WIRE_92 , \ALU_L4/n33 , \ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(153)
  and \ALU_L4/u76  (\ALU_L4/SYNTHESIZED_WIRE_13 , \ALU_L4/SYNTHESIZED_WIRE_129 , XCRa[5]);  // ../../RTL/cpu/alu74181.v(155)
  and \ALU_L4/u77  (\ALU_L4/SYNTHESIZED_WIRE_89 , \ALU_L4/SYNTHESIZED_WIRE_10 , \ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(157)
  and \ALU_L4/u79  (\ALU_L4/SYNTHESIZED_WIRE_88 , \ALU_L4/SYNTHESIZED_WIRE_90 , \ALU_L4/SYNTHESIZED_WIRE_11 );  // ../../RTL/cpu/alu74181.v(159)
  and \ALU_L4/u8  (\ALU_L4/SYNTHESIZED_WIRE_17 , \ALU_L4/SYNTHESIZED_WIRE_118 , XCRa[5]);  // ../../RTL/cpu/alu74181.v(83)
  and \ALU_L4/u81  (\ALU_L4/n34 , \ALU_L4/n22 , \ALU_L4/SYNTHESIZED_WIRE_6 );  // ../../RTL/cpu/alu74181.v(161)
  and \ALU_L4/u82  (\ALU_L4/SYNTHESIZED_WIRE_87 , \ALU_L4/n34 , \ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(161)
  and \ALU_L4/u85  (\ALU_L4/n35 , \ALU_L4/n33 , XCRa[2]);  // ../../RTL/cpu/alu74181.v(163)
  and \ALU_L4/u86  (\ALU_L4/n36 , \ALU_L4/n35 , \ALU_L4/SYNTHESIZED_WIRE_11 );  // ../../RTL/cpu/alu74181.v(163)
  and \ALU_L4/u87  (\ALU_L4/SYNTHESIZED_WIRE_86 , \ALU_L4/n36 , \ALU_H4/SYNTHESIZED_WIRE_128 );  // ../../RTL/cpu/alu74181.v(163)
  or \ALU_L4/u88  (\ALU_L4/n37 , \ALU_L4/SYNTHESIZED_WIRE_86 , \ALU_L4/SYNTHESIZED_WIRE_87 );  // ../../RTL/cpu/alu74181.v(165)
  or \ALU_L4/u89  (\ALU_L4/n38 , \ALU_L4/n37 , \ALU_L4/SYNTHESIZED_WIRE_88 );  // ../../RTL/cpu/alu74181.v(165)
  and \ALU_L4/u9  (\ALU_L4/n2 , \ALU_L4/SYNTHESIZED_WIRE_118 , XCRa[6]);  // ../../RTL/cpu/alu74181.v(85)
  or \ALU_L4/u90  (\ALU_L4/n39 , \ALU_L4/n38 , \ALU_L4/SYNTHESIZED_WIRE_89 );  // ../../RTL/cpu/alu74181.v(165)
  not \ALU_L4/u91  (\ALU_L4/SYNTHESIZED_WIRE_93 , \ALU_L4/n39 );  // ../../RTL/cpu/alu74181.v(165)
  or \ALU_L4/u92  (\ALU_L4/n40 , \ALU_L4/SYNTHESIZED_WIRE_90 , \ALU_L4/SYNTHESIZED_WIRE_91 );  // ../../RTL/cpu/alu74181.v(167)
  or \ALU_L4/u93  (\ALU_L4/n41 , \ALU_L4/n40 , \ALU_L4/SYNTHESIZED_WIRE_92 );  // ../../RTL/cpu/alu74181.v(167)
  not \ALU_L4/u94  (\ALU_L4/SYNTHESIZED_WIRE_116 , \ALU_L4/n41 );  // ../../RTL/cpu/alu74181.v(167)
  xor \ALU_L4/u95  (ALU_out[3], \ALU_L4/SYNTHESIZED_WIRE_94 , \ALU_L4/SYNTHESIZED_WIRE_93 );  // ../../RTL/cpu/alu74181.v(169)
  and \ALU_L4/u96  (\ALU_L4/n42 , \ALU_L4/g , \ALU_L4/SYNTHESIZED_WIRE_97 );  // ../../RTL/cpu/alu74181.v(171)
  not \ALU_L4/u97  (ALU_C1, \ALU_L4/n42 );  // ../../RTL/cpu/alu74181.v(171)
  or \ALU_L4/u98  (\ALU_L4/n43 , \ALU_L4/SYNTHESIZED_WIRE_98 , \ALU_L4/SYNTHESIZED_WIRE_99 );  // ../../RTL/cpu/alu74181.v(173)
  not \ALU_L4/u99  (\ALU_L4/SYNTHESIZED_WIRE_115 , \ALU_L4/n43 );  // ../../RTL/cpu/alu74181.v(173)
  not \XCRa[0]_inv  (\XCRa[0]_neg , XCRa[0]);
  not \XCRa[1]_inv  (\XCRa[1]_neg , XCRa[1]);
  not \XCRa[2]_inv  (\XCRa[2]_neg , XCRa[2]);
  add_pu23_pu23_o23 add0 (
    .i0(iaddr[22:0]),
    .i1(23'b00000000000000000000001),
    .o(PCP1[22:0]));  // ../../RTL/cpu/KC_LS1u_plus.v(43)
  eq_w3 eq0 (
    .i0(instr[10:8]),
    .i1(3'b111),
    .o(n1));  // ../../RTL/cpu/KC_LS1u_plus.v(40)
  eq_w5 eq1 (
    .i0(instr[15:11]),
    .i1(5'b01000),
    .o(XCRwe));  // ../../RTL/cpu/KC_LS1u_plus.v(156)
  eq_w5 eq10 (
    .i0(instr[15:11]),
    .i1(5'b10000),
    .o(n72));  // ../../RTL/cpu/KC_LS1u_plus.v(185)
  eq_w5 eq11 (
    .i0(instr[15:11]),
    .i1(5'b10010),
    .o(n73));  // ../../RTL/cpu/KC_LS1u_plus.v(187)
  eq_w5 eq12 (
    .i0(instr[15:11]),
    .i1(5'b10100),
    .o(n74));  // ../../RTL/cpu/KC_LS1u_plus.v(189)
  eq_w5 eq13 (
    .i0(instr[15:11]),
    .i1(5'b10110),
    .o(n75));  // ../../RTL/cpu/KC_LS1u_plus.v(191)
  eq_w5 eq14 (
    .i0(instr[15:11]),
    .i1(5'b11000),
    .o(n76));  // ../../RTL/cpu/KC_LS1u_plus.v(193)
  eq_w5 eq15 (
    .i0(instr[15:11]),
    .i1(5'b11010),
    .o(n77));  // ../../RTL/cpu/KC_LS1u_plus.v(195)
  eq_w5 eq16 (
    .i0(instr[15:11]),
    .i1(5'b11100),
    .o(n78));  // ../../RTL/cpu/KC_LS1u_plus.v(197)
  eq_w5 eq2 (
    .i0(instr[15:11]),
    .i1(5'b00001),
    .o(jmp_en));  // ../../RTL/cpu/KC_LS1u_plus.v(158)
  eq_w3 eq25 (
    .i0(instr[10:8]),
    .i1(3'b000),
    .o(n90));  // ../../RTL/cpu/KC_LS1u_plus.v(274)
  eq_w4 eq26 (
    .i0(dbsrc_addr),
    .i1(4'b0000),
    .o(n96));  // ../../RTL/cpu/KC_LS1u_plus.v(297)
  eq_w4 eq27 (
    .i0(dbsrc_addr),
    .i1(4'b0001),
    .o(n97));  // ../../RTL/cpu/KC_LS1u_plus.v(298)
  eq_w4 eq28 (
    .i0(dbsrc_addr),
    .i1(4'b0010),
    .o(dread));  // ../../RTL/cpu/KC_LS1u_plus.v(299)
  eq_w4 eq29 (
    .i0(dbsrc_addr),
    .i1(4'b0011),
    .o(n99));  // ../../RTL/cpu/KC_LS1u_plus.v(300)
  eq_w5 eq3 (
    .i0(instr[15:11]),
    .i1(5'b00111),
    .o(n65));  // ../../RTL/cpu/KC_LS1u_plus.v(162)
  eq_w4 eq30 (
    .i0(dbsrc_addr),
    .i1(4'b0101),
    .o(n100));  // ../../RTL/cpu/KC_LS1u_plus.v(302)
  eq_w4 eq31 (
    .i0(dbsrc_addr),
    .i1(4'b0111),
    .o(n101));  // ../../RTL/cpu/KC_LS1u_plus.v(303)
  eq_w5 eq4 (
    .i0(instr[15:11]),
    .i1(5'b00010),
    .o(n66));  // ../../RTL/cpu/KC_LS1u_plus.v(169)
  eq_w5 eq5 (
    .i0(instr[15:11]),
    .i1(5'b00011),
    .o(n67));  // ../../RTL/cpu/KC_LS1u_plus.v(171)
  eq_w5 eq6 (
    .i0(instr[15:11]),
    .i1(5'b00100),
    .o(n68));  // ../../RTL/cpu/KC_LS1u_plus.v(173)
  eq_w5 eq7 (
    .i0(instr[15:11]),
    .i1(5'b00101),
    .o(n69));  // ../../RTL/cpu/KC_LS1u_plus.v(175)
  eq_w5 eq8 (
    .i0(instr[15:11]),
    .i1(5'b00110),
    .o(n70));  // ../../RTL/cpu/KC_LS1u_plus.v(177)
  eq_w5 eq9 (
    .i0(instr[15:11]),
    .i1(5'b01110),
    .o(n71));  // ../../RTL/cpu/KC_LS1u_plus.v(183)
  not \instr[10]_inv  (\instr[10]_neg , instr[10]);
  not \instr[8]_inv  (\instr[8]_neg , instr[8]);
  not \instr[9]_inv  (\instr[9]_neg , instr[9]);
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    int_service_reg (
    .clk(clk),
    .d(n36),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .q(IN_ISP));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 jmp_wait_reg (
    .clk(clk),
    .d(jmp),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .q(jmp_wait));  // ../../RTL/cpu/KC_LS1u_plus.v(291)
  binary_mux_s1_w1 mux0_b0 (
    .i0(PCP1[0]),
    .i1(jaddr[0]),
    .sel(jmp),
    .o(n5[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux0_b1 (
    .i0(PCP1[1]),
    .i1(jaddr[1]),
    .sel(jmp),
    .o(n5[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux0_b10 (
    .i0(PCP1[10]),
    .i1(jaddr[10]),
    .sel(jmp),
    .o(n5[10]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux0_b11 (
    .i0(PCP1[11]),
    .i1(jaddr[11]),
    .sel(jmp),
    .o(n5[11]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux0_b12 (
    .i0(PCP1[12]),
    .i1(jaddr[12]),
    .sel(jmp),
    .o(n5[12]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux0_b13 (
    .i0(PCP1[13]),
    .i1(jaddr[13]),
    .sel(jmp),
    .o(n5[13]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux0_b14 (
    .i0(PCP1[14]),
    .i1(jaddr[14]),
    .sel(jmp),
    .o(n5[14]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux0_b15 (
    .i0(PCP1[15]),
    .i1(jaddr[15]),
    .sel(jmp),
    .o(n5[15]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux0_b16 (
    .i0(PCP1[16]),
    .i1(jaddr[16]),
    .sel(jmp),
    .o(n5[16]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux0_b17 (
    .i0(PCP1[17]),
    .i1(jaddr[17]),
    .sel(jmp),
    .o(n5[17]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux0_b18 (
    .i0(PCP1[18]),
    .i1(jaddr[18]),
    .sel(jmp),
    .o(n5[18]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux0_b19 (
    .i0(PCP1[19]),
    .i1(jaddr[19]),
    .sel(jmp),
    .o(n5[19]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux0_b2 (
    .i0(PCP1[2]),
    .i1(jaddr[2]),
    .sel(jmp),
    .o(n5[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux0_b20 (
    .i0(PCP1[20]),
    .i1(jaddr[20]),
    .sel(jmp),
    .o(n5[20]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux0_b21 (
    .i0(PCP1[21]),
    .i1(jaddr[21]),
    .sel(jmp),
    .o(n5[21]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux0_b22 (
    .i0(PCP1[22]),
    .i1(jaddr[22]),
    .sel(jmp),
    .o(n5[22]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux0_b3 (
    .i0(PCP1[3]),
    .i1(jaddr[3]),
    .sel(jmp),
    .o(n5[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux0_b4 (
    .i0(PCP1[4]),
    .i1(jaddr[4]),
    .sel(jmp),
    .o(n5[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux0_b5 (
    .i0(PCP1[5]),
    .i1(jaddr[5]),
    .sel(jmp),
    .o(n5[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux0_b6 (
    .i0(PCP1[6]),
    .i1(jaddr[6]),
    .sel(jmp),
    .o(n5[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux0_b7 (
    .i0(PCP1[7]),
    .i1(jaddr[7]),
    .sel(jmp),
    .o(n5[7]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux0_b8 (
    .i0(PCP1[8]),
    .i1(jaddr[8]),
    .sel(jmp),
    .o(n5[8]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux0_b9 (
    .i0(PCP1[9]),
    .i1(jaddr[9]),
    .sel(jmp),
    .o(n5[9]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  and mux10_b0_sel_is_1 (mux10_b0_sel_is_1_o, XCRa[0], \XCRa[1]_neg , \XCRa[2]_neg );
  and mux11_b0_sel_is_0 (mux11_b0_sel_is_0_o, \XCRa[0]_neg , \XCRa[1]_neg , \XCRa[2]_neg );
  and mux12_b0_sel_is_3 (mux12_b0_sel_is_3_o, n13, mux6_b0_sel_is_5_o);
  and mux13_b0_sel_is_3 (mux13_b0_sel_is_3_o, n13, mux7_b0_sel_is_4_o);
  and mux14_b0_sel_is_3 (mux14_b0_sel_is_3_o, n13, mux8_b0_sel_is_3_o);
  and mux15_b0_sel_is_3 (mux15_b0_sel_is_3_o, n13, mux9_b0_sel_is_2_o);
  and mux16_b0_sel_is_3 (mux16_b0_sel_is_3_o, n13, mux10_b0_sel_is_1_o);
  and mux17_b0_sel_is_3 (mux17_b0_sel_is_3_o, n13, mux11_b0_sel_is_0_o);
  AL_MUX mux18_b0 (
    .i0(RTA2[0]),
    .i1(XCRo[0]),
    .sel(mux18_b0_sel_is_2_o),
    .o(n27[0]));
  and mux18_b0_sel_is_2 (mux18_b0_sel_is_2_o, ret_sel_neg, mux12_b0_sel_is_3_o);
  AL_MUX mux18_b1 (
    .i0(RTA2[1]),
    .i1(XCRo[1]),
    .sel(mux18_b0_sel_is_2_o),
    .o(n27[1]));
  AL_MUX mux18_b2 (
    .i0(RTA2[2]),
    .i1(XCRo[2]),
    .sel(mux18_b0_sel_is_2_o),
    .o(n27[2]));
  AL_MUX mux18_b3 (
    .i0(RTA2[3]),
    .i1(XCRo[3]),
    .sel(mux18_b0_sel_is_2_o),
    .o(n27[3]));
  AL_MUX mux18_b4 (
    .i0(RTA2[4]),
    .i1(XCRo[4]),
    .sel(mux18_b0_sel_is_2_o),
    .o(n27[4]));
  AL_MUX mux18_b5 (
    .i0(RTA2[5]),
    .i1(XCRo[5]),
    .sel(mux18_b0_sel_is_2_o),
    .o(n27[5]));
  AL_MUX mux18_b6 (
    .i0(RTA2[6]),
    .i1(XCRo[6]),
    .sel(mux18_b0_sel_is_2_o),
    .o(n27[6]));
  AL_MUX mux18_b7 (
    .i0(RTA2[7]),
    .i1(XCRo[7]),
    .sel(mux18_b0_sel_is_2_o),
    .o(n27[7]));
  AL_MUX mux19_b0 (
    .i0(RTA1[0]),
    .i1(XCRo[0]),
    .sel(mux19_b0_sel_is_2_o),
    .o(n28[0]));
  and mux19_b0_sel_is_2 (mux19_b0_sel_is_2_o, ret_sel_neg, mux13_b0_sel_is_3_o);
  AL_MUX mux19_b1 (
    .i0(RTA1[1]),
    .i1(XCRo[1]),
    .sel(mux19_b0_sel_is_2_o),
    .o(n28[1]));
  AL_MUX mux19_b2 (
    .i0(RTA1[2]),
    .i1(XCRo[2]),
    .sel(mux19_b0_sel_is_2_o),
    .o(n28[2]));
  AL_MUX mux19_b3 (
    .i0(RTA1[3]),
    .i1(XCRo[3]),
    .sel(mux19_b0_sel_is_2_o),
    .o(n28[3]));
  AL_MUX mux19_b4 (
    .i0(RTA1[4]),
    .i1(XCRo[4]),
    .sel(mux19_b0_sel_is_2_o),
    .o(n28[4]));
  AL_MUX mux19_b5 (
    .i0(RTA1[5]),
    .i1(XCRo[5]),
    .sel(mux19_b0_sel_is_2_o),
    .o(n28[5]));
  AL_MUX mux19_b6 (
    .i0(RTA1[6]),
    .i1(XCRo[6]),
    .sel(mux19_b0_sel_is_2_o),
    .o(n28[6]));
  AL_MUX mux19_b7 (
    .i0(RTA1[7]),
    .i1(XCRo[7]),
    .sel(mux19_b0_sel_is_2_o),
    .o(n28[7]));
  binary_mux_s1_w1 mux1_b0 (
    .i0(n5[0]),
    .i1(IVEC_addr[0]),
    .sel(int_filter),
    .o(PC_NEXT[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux1_b1 (
    .i0(n5[1]),
    .i1(IVEC_addr[1]),
    .sel(int_filter),
    .o(PC_NEXT[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux1_b10 (
    .i0(n5[10]),
    .i1(IVEC_addr[10]),
    .sel(int_filter),
    .o(PC_NEXT[10]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux1_b11 (
    .i0(n5[11]),
    .i1(IVEC_addr[11]),
    .sel(int_filter),
    .o(PC_NEXT[11]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux1_b12 (
    .i0(n5[12]),
    .i1(IVEC_addr[12]),
    .sel(int_filter),
    .o(PC_NEXT[12]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux1_b13 (
    .i0(n5[13]),
    .i1(IVEC_addr[13]),
    .sel(int_filter),
    .o(PC_NEXT[13]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux1_b14 (
    .i0(n5[14]),
    .i1(IVEC_addr[14]),
    .sel(int_filter),
    .o(PC_NEXT[14]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux1_b15 (
    .i0(n5[15]),
    .i1(IVEC_addr[15]),
    .sel(int_filter),
    .o(PC_NEXT[15]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux1_b16 (
    .i0(n5[16]),
    .i1(IVEC_addr[16]),
    .sel(int_filter),
    .o(PC_NEXT[16]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux1_b17 (
    .i0(n5[17]),
    .i1(IVEC_addr[17]),
    .sel(int_filter),
    .o(PC_NEXT[17]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux1_b18 (
    .i0(n5[18]),
    .i1(IVEC_addr[18]),
    .sel(int_filter),
    .o(PC_NEXT[18]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux1_b19 (
    .i0(n5[19]),
    .i1(IVEC_addr[19]),
    .sel(int_filter),
    .o(PC_NEXT[19]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux1_b2 (
    .i0(n5[2]),
    .i1(IVEC_addr[2]),
    .sel(int_filter),
    .o(PC_NEXT[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux1_b20 (
    .i0(n5[20]),
    .i1(IVEC_addr[20]),
    .sel(int_filter),
    .o(PC_NEXT[20]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux1_b21 (
    .i0(n5[21]),
    .i1(IVEC_addr[21]),
    .sel(int_filter),
    .o(PC_NEXT[21]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux1_b22 (
    .i0(n5[22]),
    .i1(IVEC_addr[22]),
    .sel(int_filter),
    .o(PC_NEXT[22]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux1_b3 (
    .i0(n5[3]),
    .i1(IVEC_addr[3]),
    .sel(int_filter),
    .o(PC_NEXT[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux1_b4 (
    .i0(n5[4]),
    .i1(IVEC_addr[4]),
    .sel(int_filter),
    .o(PC_NEXT[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux1_b5 (
    .i0(n5[5]),
    .i1(IVEC_addr[5]),
    .sel(int_filter),
    .o(PC_NEXT[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux1_b6 (
    .i0(n5[6]),
    .i1(IVEC_addr[6]),
    .sel(int_filter),
    .o(PC_NEXT[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux1_b7 (
    .i0(n5[7]),
    .i1(IVEC_addr[7]),
    .sel(int_filter),
    .o(PC_NEXT[7]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux1_b8 (
    .i0(n5[8]),
    .i1(IVEC_addr[8]),
    .sel(int_filter),
    .o(PC_NEXT[8]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  binary_mux_s1_w1 mux1_b9 (
    .i0(n5[9]),
    .i1(IVEC_addr[9]),
    .sel(int_filter),
    .o(PC_NEXT[9]));  // ../../RTL/cpu/KC_LS1u_plus.v(50)
  AL_MUX mux20_b0 (
    .i0(RTA0[0]),
    .i1(XCRo[0]),
    .sel(mux20_b0_sel_is_2_o),
    .o(n29[0]));
  and mux20_b0_sel_is_2 (mux20_b0_sel_is_2_o, ret_sel_neg, mux14_b0_sel_is_3_o);
  AL_MUX mux20_b1 (
    .i0(RTA0[1]),
    .i1(XCRo[1]),
    .sel(mux20_b0_sel_is_2_o),
    .o(n29[1]));
  AL_MUX mux20_b2 (
    .i0(RTA0[2]),
    .i1(XCRo[2]),
    .sel(mux20_b0_sel_is_2_o),
    .o(n29[2]));
  AL_MUX mux20_b3 (
    .i0(RTA0[3]),
    .i1(XCRo[3]),
    .sel(mux20_b0_sel_is_2_o),
    .o(n29[3]));
  AL_MUX mux20_b4 (
    .i0(RTA0[4]),
    .i1(XCRo[4]),
    .sel(mux20_b0_sel_is_2_o),
    .o(n29[4]));
  AL_MUX mux20_b5 (
    .i0(RTA0[5]),
    .i1(XCRo[5]),
    .sel(mux20_b0_sel_is_2_o),
    .o(n29[5]));
  AL_MUX mux20_b6 (
    .i0(RTA0[6]),
    .i1(XCRo[6]),
    .sel(mux20_b0_sel_is_2_o),
    .o(n29[6]));
  AL_MUX mux20_b7 (
    .i0(RTA0[7]),
    .i1(XCRo[7]),
    .sel(mux20_b0_sel_is_2_o),
    .o(n29[7]));
  AL_MUX mux21_b0 (
    .i0(RET2[0]),
    .i1(XCRo[0]),
    .sel(mux21_b0_sel_is_2_o),
    .o(n30[0]));
  and mux21_b0_sel_is_2 (mux21_b0_sel_is_2_o, ret_sel_neg, mux15_b0_sel_is_3_o);
  AL_MUX mux21_b1 (
    .i0(RET2[1]),
    .i1(XCRo[1]),
    .sel(mux21_b0_sel_is_2_o),
    .o(n30[1]));
  AL_MUX mux21_b2 (
    .i0(RET2[2]),
    .i1(XCRo[2]),
    .sel(mux21_b0_sel_is_2_o),
    .o(n30[2]));
  AL_MUX mux21_b3 (
    .i0(RET2[3]),
    .i1(XCRo[3]),
    .sel(mux21_b0_sel_is_2_o),
    .o(n30[3]));
  AL_MUX mux21_b4 (
    .i0(RET2[4]),
    .i1(XCRo[4]),
    .sel(mux21_b0_sel_is_2_o),
    .o(n30[4]));
  AL_MUX mux21_b5 (
    .i0(RET2[5]),
    .i1(XCRo[5]),
    .sel(mux21_b0_sel_is_2_o),
    .o(n30[5]));
  AL_MUX mux21_b6 (
    .i0(RET2[6]),
    .i1(XCRo[6]),
    .sel(mux21_b0_sel_is_2_o),
    .o(n30[6]));
  AL_MUX mux22_b0 (
    .i0(RET1[0]),
    .i1(XCRo[0]),
    .sel(mux22_b0_sel_is_2_o),
    .o(n31[0]));
  and mux22_b0_sel_is_2 (mux22_b0_sel_is_2_o, ret_sel_neg, mux16_b0_sel_is_3_o);
  AL_MUX mux22_b1 (
    .i0(RET1[1]),
    .i1(XCRo[1]),
    .sel(mux22_b0_sel_is_2_o),
    .o(n31[1]));
  AL_MUX mux22_b2 (
    .i0(RET1[2]),
    .i1(XCRo[2]),
    .sel(mux22_b0_sel_is_2_o),
    .o(n31[2]));
  AL_MUX mux22_b3 (
    .i0(RET1[3]),
    .i1(XCRo[3]),
    .sel(mux22_b0_sel_is_2_o),
    .o(n31[3]));
  AL_MUX mux22_b4 (
    .i0(RET1[4]),
    .i1(XCRo[4]),
    .sel(mux22_b0_sel_is_2_o),
    .o(n31[4]));
  AL_MUX mux22_b5 (
    .i0(RET1[5]),
    .i1(XCRo[5]),
    .sel(mux22_b0_sel_is_2_o),
    .o(n31[5]));
  AL_MUX mux22_b6 (
    .i0(RET1[6]),
    .i1(XCRo[6]),
    .sel(mux22_b0_sel_is_2_o),
    .o(n31[6]));
  AL_MUX mux22_b7 (
    .i0(RET1[7]),
    .i1(XCRo[7]),
    .sel(mux22_b0_sel_is_2_o),
    .o(n31[7]));
  AL_MUX mux23_b0 (
    .i0(RET0[0]),
    .i1(XCRo[0]),
    .sel(mux23_b0_sel_is_2_o),
    .o(n32[0]));
  and mux23_b0_sel_is_2 (mux23_b0_sel_is_2_o, ret_sel_neg, mux17_b0_sel_is_3_o);
  AL_MUX mux23_b1 (
    .i0(RET0[1]),
    .i1(XCRo[1]),
    .sel(mux23_b0_sel_is_2_o),
    .o(n32[1]));
  AL_MUX mux23_b2 (
    .i0(RET0[2]),
    .i1(XCRo[2]),
    .sel(mux23_b0_sel_is_2_o),
    .o(n32[2]));
  AL_MUX mux23_b3 (
    .i0(RET0[3]),
    .i1(XCRo[3]),
    .sel(mux23_b0_sel_is_2_o),
    .o(n32[3]));
  AL_MUX mux23_b4 (
    .i0(RET0[4]),
    .i1(XCRo[4]),
    .sel(mux23_b0_sel_is_2_o),
    .o(n32[4]));
  AL_MUX mux23_b5 (
    .i0(RET0[5]),
    .i1(XCRo[5]),
    .sel(mux23_b0_sel_is_2_o),
    .o(n32[5]));
  AL_MUX mux23_b6 (
    .i0(RET0[6]),
    .i1(XCRo[6]),
    .sel(mux23_b0_sel_is_2_o),
    .o(n32[6]));
  AL_MUX mux23_b7 (
    .i0(RET0[7]),
    .i1(XCRo[7]),
    .sel(mux23_b0_sel_is_2_o),
    .o(n32[7]));
  binary_mux_s1_w1 mux24_b0 (
    .i0(n32[0]),
    .i1(n10[0]),
    .sel(n9),
    .o(n33[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux24_b1 (
    .i0(n32[1]),
    .i1(n10[1]),
    .sel(n9),
    .o(n33[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux24_b2 (
    .i0(n32[2]),
    .i1(n10[2]),
    .sel(n9),
    .o(n33[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux24_b3 (
    .i0(n32[3]),
    .i1(n10[3]),
    .sel(n9),
    .o(n33[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux24_b4 (
    .i0(n32[4]),
    .i1(n10[4]),
    .sel(n9),
    .o(n33[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux24_b5 (
    .i0(n32[5]),
    .i1(n10[5]),
    .sel(n9),
    .o(n33[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux24_b6 (
    .i0(n32[6]),
    .i1(n10[6]),
    .sel(n9),
    .o(n33[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux24_b7 (
    .i0(n32[7]),
    .i1(n10[7]),
    .sel(n9),
    .o(n33[7]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux25_b0 (
    .i0(n31[0]),
    .i1(n11[0]),
    .sel(n9),
    .o(n34[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux25_b1 (
    .i0(n31[1]),
    .i1(n11[1]),
    .sel(n9),
    .o(n34[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux25_b2 (
    .i0(n31[2]),
    .i1(n11[2]),
    .sel(n9),
    .o(n34[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux25_b3 (
    .i0(n31[3]),
    .i1(n11[3]),
    .sel(n9),
    .o(n34[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux25_b4 (
    .i0(n31[4]),
    .i1(n11[4]),
    .sel(n9),
    .o(n34[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux25_b5 (
    .i0(n31[5]),
    .i1(n11[5]),
    .sel(n9),
    .o(n34[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux25_b6 (
    .i0(n31[6]),
    .i1(n11[6]),
    .sel(n9),
    .o(n34[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux25_b7 (
    .i0(n31[7]),
    .i1(n11[7]),
    .sel(n9),
    .o(n34[7]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux26_b0 (
    .i0(n30[0]),
    .i1(n12[0]),
    .sel(n9),
    .o(n35[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux26_b1 (
    .i0(n30[1]),
    .i1(n12[1]),
    .sel(n9),
    .o(n35[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux26_b2 (
    .i0(n30[2]),
    .i1(n12[2]),
    .sel(n9),
    .o(n35[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux26_b3 (
    .i0(n30[3]),
    .i1(n12[3]),
    .sel(n9),
    .o(n35[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux26_b4 (
    .i0(n30[4]),
    .i1(n12[4]),
    .sel(n9),
    .o(n35[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux26_b5 (
    .i0(n30[5]),
    .i1(n12[5]),
    .sel(n9),
    .o(n35[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux26_b6 (
    .i0(n30[6]),
    .i1(n12[6]),
    .sel(n9),
    .o(n35[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux27_b0 (
    .i0(n29[0]),
    .i1(daddr[0]),
    .sel(n9),
    .o(n37[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux27_b1 (
    .i0(n29[1]),
    .i1(daddr[1]),
    .sel(n9),
    .o(n37[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux27_b2 (
    .i0(n29[2]),
    .i1(daddr[2]),
    .sel(n9),
    .o(n37[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux27_b3 (
    .i0(n29[3]),
    .i1(daddr[3]),
    .sel(n9),
    .o(n37[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux27_b4 (
    .i0(n29[4]),
    .i1(daddr[4]),
    .sel(n9),
    .o(n37[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux27_b5 (
    .i0(n29[5]),
    .i1(daddr[5]),
    .sel(n9),
    .o(n37[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux27_b6 (
    .i0(n29[6]),
    .i1(daddr[6]),
    .sel(n9),
    .o(n37[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux27_b7 (
    .i0(n29[7]),
    .i1(daddr[7]),
    .sel(n9),
    .o(n37[7]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux28_b0 (
    .i0(n28[0]),
    .i1(daddr[8]),
    .sel(n9),
    .o(n38[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux28_b1 (
    .i0(n28[1]),
    .i1(daddr[9]),
    .sel(n9),
    .o(n38[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux28_b2 (
    .i0(n28[2]),
    .i1(daddr[10]),
    .sel(n9),
    .o(n38[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux28_b3 (
    .i0(n28[3]),
    .i1(daddr[11]),
    .sel(n9),
    .o(n38[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux28_b4 (
    .i0(n28[4]),
    .i1(daddr[12]),
    .sel(n9),
    .o(n38[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux28_b5 (
    .i0(n28[5]),
    .i1(daddr[13]),
    .sel(n9),
    .o(n38[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux28_b6 (
    .i0(n28[6]),
    .i1(daddr[14]),
    .sel(n9),
    .o(n38[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux28_b7 (
    .i0(n28[7]),
    .i1(daddr[15]),
    .sel(n9),
    .o(n38[7]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux29_b0 (
    .i0(n27[0]),
    .i1(daddr[16]),
    .sel(n9),
    .o(n39[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux29_b1 (
    .i0(n27[1]),
    .i1(daddr[17]),
    .sel(n9),
    .o(n39[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux29_b2 (
    .i0(n27[2]),
    .i1(daddr[18]),
    .sel(n9),
    .o(n39[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux29_b3 (
    .i0(n27[3]),
    .i1(daddr[19]),
    .sel(n9),
    .o(n39[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux29_b4 (
    .i0(n27[4]),
    .i1(daddr[20]),
    .sel(n9),
    .o(n39[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux29_b5 (
    .i0(n27[5]),
    .i1(daddr[21]),
    .sel(n9),
    .o(n39[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux29_b6 (
    .i0(n27[6]),
    .i1(daddr[22]),
    .sel(n9),
    .o(n39[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  binary_mux_s1_w1 mux29_b7 (
    .i0(n27[7]),
    .i1(daddr[23]),
    .sel(n9),
    .o(n39[7]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  and mux33_b0_sel_is_6 (mux33_b0_sel_is_6_o, \instr[8]_neg , instr[9], instr[10]);
  and mux34_b0_sel_is_5 (mux34_b0_sel_is_5_o, instr[8], \instr[9]_neg , instr[10]);
  and mux35_b0_sel_is_4 (mux35_b0_sel_is_4_o, \instr[8]_neg , \instr[9]_neg , instr[10]);
  and mux36_b0_sel_is_3 (mux36_b0_sel_is_3_o, instr[8], instr[9], \instr[10]_neg );
  and mux37_b0_sel_is_2 (mux37_b0_sel_is_2_o, \instr[8]_neg , instr[9], \instr[10]_neg );
  and mux38_b0_sel_is_1 (mux38_b0_sel_is_1_o, instr[8], \instr[9]_neg , \instr[10]_neg );
  and mux39_b0_sel_is_0 (mux39_b0_sel_is_0_o, \instr[8]_neg , \instr[9]_neg , \instr[10]_neg );
  binary_mux_s1_w1 mux3_b0 (
    .i0(iaddr[0]),
    .i1(jaddr[0]),
    .sel(jmp),
    .o(n10[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 mux3_b1 (
    .i0(iaddr[1]),
    .i1(jaddr[1]),
    .sel(jmp),
    .o(n10[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 mux3_b2 (
    .i0(iaddr[2]),
    .i1(jaddr[2]),
    .sel(jmp),
    .o(n10[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 mux3_b3 (
    .i0(iaddr[3]),
    .i1(jaddr[3]),
    .sel(jmp),
    .o(n10[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 mux3_b4 (
    .i0(iaddr[4]),
    .i1(jaddr[4]),
    .sel(jmp),
    .o(n10[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 mux3_b5 (
    .i0(iaddr[5]),
    .i1(jaddr[5]),
    .sel(jmp),
    .o(n10[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 mux3_b6 (
    .i0(iaddr[6]),
    .i1(jaddr[6]),
    .sel(jmp),
    .o(n10[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 mux3_b7 (
    .i0(iaddr[7]),
    .i1(jaddr[7]),
    .sel(jmp),
    .o(n10[7]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  and mux40_b0_sel_is_3 (mux40_b0_sel_is_3_o, n43, mux33_b0_sel_is_6_o);
  AL_MUX mux41_b0 (
    .i0(daddr[16]),
    .i1(XCRo[0]),
    .sel(mux41_b0_sel_is_3_o),
    .o(n52[0]));
  and mux41_b0_sel_is_3 (mux41_b0_sel_is_3_o, n43, mux34_b0_sel_is_5_o);
  AL_MUX mux41_b1 (
    .i0(daddr[17]),
    .i1(XCRo[1]),
    .sel(mux41_b0_sel_is_3_o),
    .o(n52[1]));
  AL_MUX mux41_b2 (
    .i0(daddr[18]),
    .i1(XCRo[2]),
    .sel(mux41_b0_sel_is_3_o),
    .o(n52[2]));
  AL_MUX mux41_b3 (
    .i0(daddr[19]),
    .i1(XCRo[3]),
    .sel(mux41_b0_sel_is_3_o),
    .o(n52[3]));
  AL_MUX mux41_b4 (
    .i0(daddr[20]),
    .i1(XCRo[4]),
    .sel(mux41_b0_sel_is_3_o),
    .o(n52[4]));
  AL_MUX mux41_b5 (
    .i0(daddr[21]),
    .i1(XCRo[5]),
    .sel(mux41_b0_sel_is_3_o),
    .o(n52[5]));
  AL_MUX mux41_b6 (
    .i0(daddr[22]),
    .i1(XCRo[6]),
    .sel(mux41_b0_sel_is_3_o),
    .o(n52[6]));
  AL_MUX mux41_b7 (
    .i0(daddr[23]),
    .i1(XCRo[7]),
    .sel(mux41_b0_sel_is_3_o),
    .o(n52[7]));
  AL_MUX mux42_b0 (
    .i0(daddr[8]),
    .i1(XCRo[0]),
    .sel(mux42_b0_sel_is_3_o),
    .o(n53[0]));
  and mux42_b0_sel_is_3 (mux42_b0_sel_is_3_o, n43, mux35_b0_sel_is_4_o);
  AL_MUX mux42_b1 (
    .i0(daddr[9]),
    .i1(XCRo[1]),
    .sel(mux42_b0_sel_is_3_o),
    .o(n53[1]));
  AL_MUX mux42_b2 (
    .i0(daddr[10]),
    .i1(XCRo[2]),
    .sel(mux42_b0_sel_is_3_o),
    .o(n53[2]));
  AL_MUX mux42_b3 (
    .i0(daddr[11]),
    .i1(XCRo[3]),
    .sel(mux42_b0_sel_is_3_o),
    .o(n53[3]));
  AL_MUX mux42_b4 (
    .i0(daddr[12]),
    .i1(XCRo[4]),
    .sel(mux42_b0_sel_is_3_o),
    .o(n53[4]));
  AL_MUX mux42_b5 (
    .i0(daddr[13]),
    .i1(XCRo[5]),
    .sel(mux42_b0_sel_is_3_o),
    .o(n53[5]));
  AL_MUX mux42_b6 (
    .i0(daddr[14]),
    .i1(XCRo[6]),
    .sel(mux42_b0_sel_is_3_o),
    .o(n53[6]));
  AL_MUX mux42_b7 (
    .i0(daddr[15]),
    .i1(XCRo[7]),
    .sel(mux42_b0_sel_is_3_o),
    .o(n53[7]));
  AL_MUX mux43_b0 (
    .i0(daddr[0]),
    .i1(XCRo[0]),
    .sel(mux43_b0_sel_is_3_o),
    .o(n54[0]));
  and mux43_b0_sel_is_3 (mux43_b0_sel_is_3_o, n43, mux36_b0_sel_is_3_o);
  AL_MUX mux43_b1 (
    .i0(daddr[1]),
    .i1(XCRo[1]),
    .sel(mux43_b0_sel_is_3_o),
    .o(n54[1]));
  AL_MUX mux43_b2 (
    .i0(daddr[2]),
    .i1(XCRo[2]),
    .sel(mux43_b0_sel_is_3_o),
    .o(n54[2]));
  AL_MUX mux43_b3 (
    .i0(daddr[3]),
    .i1(XCRo[3]),
    .sel(mux43_b0_sel_is_3_o),
    .o(n54[3]));
  AL_MUX mux43_b4 (
    .i0(daddr[4]),
    .i1(XCRo[4]),
    .sel(mux43_b0_sel_is_3_o),
    .o(n54[4]));
  AL_MUX mux43_b5 (
    .i0(daddr[5]),
    .i1(XCRo[5]),
    .sel(mux43_b0_sel_is_3_o),
    .o(n54[5]));
  AL_MUX mux43_b6 (
    .i0(daddr[6]),
    .i1(XCRo[6]),
    .sel(mux43_b0_sel_is_3_o),
    .o(n54[6]));
  AL_MUX mux43_b7 (
    .i0(daddr[7]),
    .i1(XCRo[7]),
    .sel(mux43_b0_sel_is_3_o),
    .o(n54[7]));
  and mux44_b0_sel_is_3 (mux44_b0_sel_is_3_o, n43, mux37_b0_sel_is_2_o);
  and mux45_b0_sel_is_3 (mux45_b0_sel_is_3_o, n43, mux38_b0_sel_is_1_o);
  and mux46_b0_sel_is_3 (mux46_b0_sel_is_3_o, n43, mux39_b0_sel_is_0_o);
  binary_mux_s1_w1 mux47_b0 (
    .i0(n54[0]),
    .i1(RTA0[0]),
    .sel(ret_sel),
    .o(n58[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 mux47_b1 (
    .i0(n54[1]),
    .i1(RTA0[1]),
    .sel(ret_sel),
    .o(n58[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 mux47_b2 (
    .i0(n54[2]),
    .i1(RTA0[2]),
    .sel(ret_sel),
    .o(n58[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 mux47_b3 (
    .i0(n54[3]),
    .i1(RTA0[3]),
    .sel(ret_sel),
    .o(n58[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 mux47_b4 (
    .i0(n54[4]),
    .i1(RTA0[4]),
    .sel(ret_sel),
    .o(n58[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 mux47_b5 (
    .i0(n54[5]),
    .i1(RTA0[5]),
    .sel(ret_sel),
    .o(n58[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 mux47_b6 (
    .i0(n54[6]),
    .i1(RTA0[6]),
    .sel(ret_sel),
    .o(n58[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 mux47_b7 (
    .i0(n54[7]),
    .i1(RTA0[7]),
    .sel(ret_sel),
    .o(n58[7]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 mux48_b0 (
    .i0(n53[0]),
    .i1(RTA1[0]),
    .sel(ret_sel),
    .o(n59[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 mux48_b1 (
    .i0(n53[1]),
    .i1(RTA1[1]),
    .sel(ret_sel),
    .o(n59[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 mux48_b2 (
    .i0(n53[2]),
    .i1(RTA1[2]),
    .sel(ret_sel),
    .o(n59[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 mux48_b3 (
    .i0(n53[3]),
    .i1(RTA1[3]),
    .sel(ret_sel),
    .o(n59[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 mux48_b4 (
    .i0(n53[4]),
    .i1(RTA1[4]),
    .sel(ret_sel),
    .o(n59[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 mux48_b5 (
    .i0(n53[5]),
    .i1(RTA1[5]),
    .sel(ret_sel),
    .o(n59[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 mux48_b6 (
    .i0(n53[6]),
    .i1(RTA1[6]),
    .sel(ret_sel),
    .o(n59[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 mux48_b7 (
    .i0(n53[7]),
    .i1(RTA1[7]),
    .sel(ret_sel),
    .o(n59[7]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 mux49_b0 (
    .i0(n52[0]),
    .i1(RTA2[0]),
    .sel(ret_sel),
    .o(n60[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 mux49_b1 (
    .i0(n52[1]),
    .i1(RTA2[1]),
    .sel(ret_sel),
    .o(n60[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 mux49_b2 (
    .i0(n52[2]),
    .i1(RTA2[2]),
    .sel(ret_sel),
    .o(n60[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 mux49_b3 (
    .i0(n52[3]),
    .i1(RTA2[3]),
    .sel(ret_sel),
    .o(n60[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 mux49_b4 (
    .i0(n52[4]),
    .i1(RTA2[4]),
    .sel(ret_sel),
    .o(n60[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 mux49_b5 (
    .i0(n52[5]),
    .i1(RTA2[5]),
    .sel(ret_sel),
    .o(n60[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 mux49_b6 (
    .i0(n52[6]),
    .i1(RTA2[6]),
    .sel(ret_sel),
    .o(n60[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 mux49_b7 (
    .i0(n52[7]),
    .i1(RTA2[7]),
    .sel(ret_sel),
    .o(n60[7]));  // ../../RTL/cpu/KC_LS1u_plus.v(132)
  binary_mux_s1_w1 mux4_b0 (
    .i0(iaddr[8]),
    .i1(jaddr[8]),
    .sel(jmp),
    .o(n11[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 mux4_b1 (
    .i0(iaddr[9]),
    .i1(jaddr[9]),
    .sel(jmp),
    .o(n11[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 mux4_b2 (
    .i0(iaddr[10]),
    .i1(jaddr[10]),
    .sel(jmp),
    .o(n11[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 mux4_b3 (
    .i0(iaddr[11]),
    .i1(jaddr[11]),
    .sel(jmp),
    .o(n11[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 mux4_b4 (
    .i0(iaddr[12]),
    .i1(jaddr[12]),
    .sel(jmp),
    .o(n11[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 mux4_b5 (
    .i0(iaddr[13]),
    .i1(jaddr[13]),
    .sel(jmp),
    .o(n11[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 mux4_b6 (
    .i0(iaddr[14]),
    .i1(jaddr[14]),
    .sel(jmp),
    .o(n11[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 mux4_b7 (
    .i0(iaddr[15]),
    .i1(jaddr[15]),
    .sel(jmp),
    .o(n11[7]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  and mux50_b0_sel_is_2 (mux50_b0_sel_is_2_o, ret_sel_neg, mux40_b0_sel_is_3_o);
  and mux51_b0_sel_is_2 (mux51_b0_sel_is_2_o, ret_sel_neg, mux44_b0_sel_is_3_o);
  and mux52_b0_sel_is_2 (mux52_b0_sel_is_2_o, ret_sel_neg, mux45_b0_sel_is_3_o);
  and mux53_b0_sel_is_2 (mux53_b0_sel_is_2_o, ret_sel_neg, mux46_b0_sel_is_3_o);
  binary_mux_s3_w1 mux54_b0 (
    .i0(RET0[0]),
    .i1(RET1[0]),
    .i2(RET1[0]),
    .i3(RTA0[0]),
    .i4(RTA1[0]),
    .i5(RTA2[0]),
    .i6(C[0]),
    .i7(D[0]),
    .sel(XCRa[2:0]),
    .o(XREGr[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(214)
  binary_mux_s3_w1 mux54_b1 (
    .i0(RET0[1]),
    .i1(RET1[1]),
    .i2(RET1[1]),
    .i3(RTA0[1]),
    .i4(RTA1[1]),
    .i5(RTA2[1]),
    .i6(C[1]),
    .i7(D[1]),
    .sel(XCRa[2:0]),
    .o(XREGr[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(214)
  binary_mux_s3_w1 mux54_b2 (
    .i0(RET0[2]),
    .i1(RET1[2]),
    .i2(RET1[2]),
    .i3(RTA0[2]),
    .i4(RTA1[2]),
    .i5(RTA2[2]),
    .i6(C[2]),
    .i7(D[2]),
    .sel(XCRa[2:0]),
    .o(XREGr[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(214)
  binary_mux_s3_w1 mux54_b3 (
    .i0(RET0[3]),
    .i1(RET1[3]),
    .i2(RET1[3]),
    .i3(RTA0[3]),
    .i4(RTA1[3]),
    .i5(RTA2[3]),
    .i6(C[3]),
    .i7(D[3]),
    .sel(XCRa[2:0]),
    .o(XREGr[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(214)
  binary_mux_s3_w1 mux54_b4 (
    .i0(RET0[4]),
    .i1(RET1[4]),
    .i2(RET1[4]),
    .i3(RTA0[4]),
    .i4(RTA1[4]),
    .i5(RTA2[4]),
    .i6(C[4]),
    .i7(D[4]),
    .sel(XCRa[2:0]),
    .o(XREGr[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(214)
  binary_mux_s3_w1 mux54_b5 (
    .i0(RET0[5]),
    .i1(RET1[5]),
    .i2(RET1[5]),
    .i3(RTA0[5]),
    .i4(RTA1[5]),
    .i5(RTA2[5]),
    .i6(C[5]),
    .i7(D[5]),
    .sel(XCRa[2:0]),
    .o(XREGr[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(214)
  binary_mux_s3_w1 mux54_b6 (
    .i0(RET0[6]),
    .i1(RET1[6]),
    .i2(RET1[6]),
    .i3(RTA0[6]),
    .i4(RTA1[6]),
    .i5(RTA2[6]),
    .i6(C[6]),
    .i7(D[6]),
    .sel(XCRa[2:0]),
    .o(XREGr[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(214)
  binary_mux_s3_w1 mux54_b7 (
    .i0(RET0[7]),
    .i1(RET1[7]),
    .i2(RET1[7]),
    .i3(RTA0[7]),
    .i4(RTA1[7]),
    .i5(RTA2[7]),
    .i6(C[7]),
    .i7(D[7]),
    .sel(XCRa[2:0]),
    .o(XREGr[7]));  // ../../RTL/cpu/KC_LS1u_plus.v(214)
  binary_mux_s3_w1 mux55 (
    .i0(1'b1),
    .i1(n91),
    .i2(\ALU_H4/SYNTHESIZED_WIRE_119 ),
    .i3(n93),
    .i4(\ALU_H4/n42 ),
    .i5(1'b1),
    .i6(1'b0),
    .i7(1'b0),
    .sel(instr[10:8]),
    .o(n95));  // ../../RTL/cpu/KC_LS1u_plus.v(284)
  binary_mux_s1_w1 mux5_b0 (
    .i0(iaddr[16]),
    .i1(jaddr[16]),
    .sel(jmp),
    .o(n12[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 mux5_b1 (
    .i0(iaddr[17]),
    .i1(jaddr[17]),
    .sel(jmp),
    .o(n12[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 mux5_b2 (
    .i0(iaddr[18]),
    .i1(jaddr[18]),
    .sel(jmp),
    .o(n12[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 mux5_b3 (
    .i0(iaddr[19]),
    .i1(jaddr[19]),
    .sel(jmp),
    .o(n12[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 mux5_b4 (
    .i0(iaddr[20]),
    .i1(jaddr[20]),
    .sel(jmp),
    .o(n12[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 mux5_b5 (
    .i0(iaddr[21]),
    .i1(jaddr[21]),
    .sel(jmp),
    .o(n12[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  binary_mux_s1_w1 mux5_b6 (
    .i0(iaddr[22]),
    .i1(jaddr[22]),
    .sel(jmp),
    .o(n12[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(74)
  and mux6_b0_sel_is_5 (mux6_b0_sel_is_5_o, XCRa[0], \XCRa[1]_neg , XCRa[2]);
  and mux7_b0_sel_is_4 (mux7_b0_sel_is_4_o, \XCRa[0]_neg , \XCRa[1]_neg , XCRa[2]);
  and mux8_b0_sel_is_3 (mux8_b0_sel_is_3_o, XCRa[0], XCRa[1], \XCRa[2]_neg );
  and mux9_b0_sel_is_2 (mux9_b0_sel_is_2_o, \XCRa[0]_neg , XCRa[1], \XCRa[2]_neg );
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg0_b0 (
    .clk(clk),
    .d(n33[0]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RET0[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg0_b1 (
    .clk(clk),
    .d(n33[1]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RET0[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg0_b2 (
    .clk(clk),
    .d(n33[2]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RET0[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg0_b3 (
    .clk(clk),
    .d(n33[3]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RET0[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg0_b4 (
    .clk(clk),
    .d(n33[4]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RET0[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg0_b5 (
    .clk(clk),
    .d(n33[5]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RET0[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg0_b6 (
    .clk(clk),
    .d(n33[6]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RET0[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg0_b7 (
    .clk(clk),
    .d(n33[7]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RET0[7]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 reg10_b0 (
    .clk(clk),
    .d(XCRo[0]),
    .en(mux51_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(B[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg10_b1 (
    .clk(clk),
    .d(XCRo[1]),
    .en(mux51_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(B[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg10_b2 (
    .clk(clk),
    .d(XCRo[2]),
    .en(mux51_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(B[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg10_b3 (
    .clk(clk),
    .d(XCRo[3]),
    .en(mux51_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(B[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg10_b4 (
    .clk(clk),
    .d(XCRo[4]),
    .en(mux51_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(B[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg10_b5 (
    .clk(clk),
    .d(XCRo[5]),
    .en(mux51_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(B[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg10_b6 (
    .clk(clk),
    .d(XCRo[6]),
    .en(mux51_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(B[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg10_b7 (
    .clk(clk),
    .d(XCRo[7]),
    .en(mux51_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(B[7]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg11_b0 (
    .clk(clk),
    .d(XCRo[0]),
    .en(mux52_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(A[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg11_b1 (
    .clk(clk),
    .d(XCRo[1]),
    .en(mux52_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(A[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg11_b2 (
    .clk(clk),
    .d(XCRo[2]),
    .en(mux52_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(A[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg11_b3 (
    .clk(clk),
    .d(XCRo[3]),
    .en(mux52_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(A[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg11_b4 (
    .clk(clk),
    .d(XCRo[4]),
    .en(mux52_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(A[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg11_b5 (
    .clk(clk),
    .d(XCRo[5]),
    .en(mux52_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(A[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg11_b6 (
    .clk(clk),
    .d(XCRo[6]),
    .en(mux52_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(A[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg11_b7 (
    .clk(clk),
    .d(XCRo[7]),
    .en(mux52_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(A[7]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg12_b0 (
    .clk(clk),
    .d(XCRo[0]),
    .en(mux53_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(C[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg12_b1 (
    .clk(clk),
    .d(XCRo[1]),
    .en(mux53_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(C[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg12_b2 (
    .clk(clk),
    .d(XCRo[2]),
    .en(mux53_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(C[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg12_b3 (
    .clk(clk),
    .d(XCRo[3]),
    .en(mux53_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(C[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg12_b4 (
    .clk(clk),
    .d(XCRo[4]),
    .en(mux53_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(C[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg12_b5 (
    .clk(clk),
    .d(XCRo[5]),
    .en(mux53_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(C[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg12_b6 (
    .clk(clk),
    .d(XCRo[6]),
    .en(mux53_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(C[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg12_b7 (
    .clk(clk),
    .d(XCRo[7]),
    .en(mux53_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(C[7]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg13_b0 (
    .clk(clk),
    .d(PC_NEXT[0]),
    .en(~n6),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg13_b1 (
    .clk(clk),
    .d(PC_NEXT[1]),
    .en(~n6),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg13_b10 (
    .clk(clk),
    .d(PC_NEXT[10]),
    .en(~n6),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[10]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg13_b11 (
    .clk(clk),
    .d(PC_NEXT[11]),
    .en(~n6),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[11]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg13_b12 (
    .clk(clk),
    .d(PC_NEXT[12]),
    .en(~n6),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[12]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg13_b13 (
    .clk(clk),
    .d(PC_NEXT[13]),
    .en(~n6),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[13]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg13_b14 (
    .clk(clk),
    .d(PC_NEXT[14]),
    .en(~n6),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[14]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg13_b15 (
    .clk(clk),
    .d(PC_NEXT[15]),
    .en(~n6),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[15]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg13_b16 (
    .clk(clk),
    .d(PC_NEXT[16]),
    .en(~n6),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[16]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg13_b17 (
    .clk(clk),
    .d(PC_NEXT[17]),
    .en(~n6),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[17]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg13_b18 (
    .clk(clk),
    .d(PC_NEXT[18]),
    .en(~n6),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[18]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg13_b19 (
    .clk(clk),
    .d(PC_NEXT[19]),
    .en(~n6),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[19]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg13_b2 (
    .clk(clk),
    .d(PC_NEXT[2]),
    .en(~n6),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg13_b20 (
    .clk(clk),
    .d(PC_NEXT[20]),
    .en(~n6),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[20]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg13_b21 (
    .clk(clk),
    .d(PC_NEXT[21]),
    .en(~n6),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[21]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg13_b22 (
    .clk(clk),
    .d(PC_NEXT[22]),
    .en(~n6),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[22]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg13_b3 (
    .clk(clk),
    .d(PC_NEXT[3]),
    .en(~n6),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg13_b4 (
    .clk(clk),
    .d(PC_NEXT[4]),
    .en(~n6),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg13_b5 (
    .clk(clk),
    .d(PC_NEXT[5]),
    .en(~n6),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg13_b6 (
    .clk(clk),
    .d(PC_NEXT[6]),
    .en(~n6),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg13_b7 (
    .clk(clk),
    .d(PC_NEXT[7]),
    .en(~n6),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[7]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg13_b8 (
    .clk(clk),
    .d(PC_NEXT[8]),
    .en(~n6),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[8]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg13_b9 (
    .clk(clk),
    .d(PC_NEXT[9]),
    .en(~n6),
    .reset(1'b0),
    .set(1'b0),
    .q(iaddr[9]));  // ../../RTL/cpu/KC_LS1u_plus.v(57)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg1_b0 (
    .clk(clk),
    .d(n34[0]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RET1[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg1_b1 (
    .clk(clk),
    .d(n34[1]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RET1[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg1_b2 (
    .clk(clk),
    .d(n34[2]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RET1[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg1_b3 (
    .clk(clk),
    .d(n34[3]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RET1[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg1_b4 (
    .clk(clk),
    .d(n34[4]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RET1[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg1_b5 (
    .clk(clk),
    .d(n34[5]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RET1[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg1_b6 (
    .clk(clk),
    .d(n34[6]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RET1[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg1_b7 (
    .clk(clk),
    .d(n34[7]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RET1[7]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg2_b0 (
    .clk(clk),
    .d(n35[0]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RET2[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg2_b1 (
    .clk(clk),
    .d(n35[1]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RET2[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg2_b2 (
    .clk(clk),
    .d(n35[2]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RET2[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg2_b3 (
    .clk(clk),
    .d(n35[3]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RET2[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg2_b4 (
    .clk(clk),
    .d(n35[4]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RET2[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg2_b5 (
    .clk(clk),
    .d(n35[5]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RET2[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg2_b6 (
    .clk(clk),
    .d(n35[6]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RET2[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 reg3_b0 (
    .clk(clk),
    .d(n37[0]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RTA0[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 reg3_b1 (
    .clk(clk),
    .d(n37[1]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RTA0[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 reg3_b2 (
    .clk(clk),
    .d(n37[2]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RTA0[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 reg3_b3 (
    .clk(clk),
    .d(n37[3]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RTA0[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 reg3_b4 (
    .clk(clk),
    .d(n37[4]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RTA0[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 reg3_b5 (
    .clk(clk),
    .d(n37[5]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RTA0[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 reg3_b6 (
    .clk(clk),
    .d(n37[6]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RTA0[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 reg3_b7 (
    .clk(clk),
    .d(n37[7]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RTA0[7]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 reg4_b0 (
    .clk(clk),
    .d(n38[0]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RTA1[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 reg4_b1 (
    .clk(clk),
    .d(n38[1]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RTA1[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 reg4_b2 (
    .clk(clk),
    .d(n38[2]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RTA1[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 reg4_b3 (
    .clk(clk),
    .d(n38[3]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RTA1[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 reg4_b4 (
    .clk(clk),
    .d(n38[4]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RTA1[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 reg4_b5 (
    .clk(clk),
    .d(n38[5]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RTA1[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 reg4_b6 (
    .clk(clk),
    .d(n38[6]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RTA1[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 reg4_b7 (
    .clk(clk),
    .d(n38[7]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RTA1[7]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 reg5_b0 (
    .clk(clk),
    .d(n39[0]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RTA2[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 reg5_b1 (
    .clk(clk),
    .d(n39[1]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RTA2[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 reg5_b2 (
    .clk(clk),
    .d(n39[2]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RTA2[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 reg5_b3 (
    .clk(clk),
    .d(n39[3]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RTA2[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 reg5_b4 (
    .clk(clk),
    .d(n39[4]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RTA2[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 reg5_b5 (
    .clk(clk),
    .d(n39[5]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RTA2[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 reg5_b6 (
    .clk(clk),
    .d(n39[6]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RTA2[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 reg5_b7 (
    .clk(clk),
    .d(n39[7]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(RTA2[7]));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  reg_ar_as_w1 reg6_b0 (
    .clk(clk),
    .d(n58[0]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg6_b1 (
    .clk(clk),
    .d(n58[1]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg6_b2 (
    .clk(clk),
    .d(n58[2]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg6_b3 (
    .clk(clk),
    .d(n58[3]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg6_b4 (
    .clk(clk),
    .d(n58[4]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg6_b5 (
    .clk(clk),
    .d(n58[5]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg6_b6 (
    .clk(clk),
    .d(n58[6]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg6_b7 (
    .clk(clk),
    .d(n58[7]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[7]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg7_b0 (
    .clk(clk),
    .d(n59[0]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[8]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg7_b1 (
    .clk(clk),
    .d(n59[1]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[9]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg7_b2 (
    .clk(clk),
    .d(n59[2]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[10]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg7_b3 (
    .clk(clk),
    .d(n59[3]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[11]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg7_b4 (
    .clk(clk),
    .d(n59[4]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[12]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg7_b5 (
    .clk(clk),
    .d(n59[5]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[13]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg7_b6 (
    .clk(clk),
    .d(n59[6]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[14]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg7_b7 (
    .clk(clk),
    .d(n59[7]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[15]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg8_b0 (
    .clk(clk),
    .d(n60[0]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[16]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg8_b1 (
    .clk(clk),
    .d(n60[1]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[17]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg8_b2 (
    .clk(clk),
    .d(n60[2]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[18]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg8_b3 (
    .clk(clk),
    .d(n60[3]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[19]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg8_b4 (
    .clk(clk),
    .d(n60[4]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[20]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg8_b5 (
    .clk(clk),
    .d(n60[5]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[21]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg8_b6 (
    .clk(clk),
    .d(n60[6]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[22]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg8_b7 (
    .clk(clk),
    .d(n60[7]),
    .en(1'b1),
    .reset(1'b0),
    .set(1'b0),
    .sload_data(1'b0),
    .sload_sel(1'b1),
    .q(daddr[23]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg9_b0 (
    .clk(clk),
    .d(XCRo[0]),
    .en(mux50_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(D[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg9_b1 (
    .clk(clk),
    .d(XCRo[1]),
    .en(mux50_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(D[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg9_b2 (
    .clk(clk),
    .d(XCRo[2]),
    .en(mux50_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(D[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg9_b3 (
    .clk(clk),
    .d(XCRo[3]),
    .en(mux50_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(D[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg9_b4 (
    .clk(clk),
    .d(XCRo[4]),
    .en(mux50_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(D[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg9_b5 (
    .clk(clk),
    .d(XCRo[5]),
    .en(mux50_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(D[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg9_b6 (
    .clk(clk),
    .d(XCRo[6]),
    .en(mux50_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(D[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  reg_ar_as_w1 reg9_b7 (
    .clk(clk),
    .d(XCRo[7]),
    .en(mux50_b0_sel_is_2_o),
    .reset(1'b0),
    .set(1'b0),
    .q(D[7]));  // ../../RTL/cpu/KC_LS1u_plus.v(133)
  not ret_sel_inv (ret_sel_neg, ret_sel);
  AL_MUX sel0_b0 (
    .i0(1'b1),
    .i1(1'b0),
    .sel(sel0_b0_sel_o),
    .o(dbsrc_addr[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or sel0_b0_sel (sel0_b0_sel_o, n65, n68);  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  AL_MUX sel0_b1 (
    .i0(1'b1),
    .i1(1'b0),
    .sel(sel0_b1_sel_o),
    .o(dbsrc_addr[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or sel0_b1_sel (sel0_b1_sel_o, XCRwe, n65, n69, n67, n66);  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  AL_MUX sel0_b2 (
    .i0(1'b1),
    .i1(1'b0),
    .sel(sel0_b2_sel_o),
    .o(dbsrc_addr[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or sel0_b2_sel (sel0_b2_sel_o, XCRwe, n65, n70, n69, n68, n66);  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  AL_MUX sel0_b3 (
    .i0(1'b0),
    .i1(1'b1),
    .sel(sel0_b3_sel_o),
    .o(dbsrc_addr[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or sel0_b3_sel (sel0_b3_sel_o, n79, jmp_en);  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  binary_mux_s4_w1 sel10 (
    .i0(XCRi[0]),
    .i1(ALU_out[0]),
    .i10(1'bx),
    .i11(1'bx),
    .i12(1'bx),
    .i13(1'bx),
    .i14(1'bx),
    .i15(1'bx),
    .i2(ddata_i[0]),
    .i3(XCRa[0]),
    .i4(1'bx),
    .i5(XREGr[0]),
    .i6(1'bx),
    .i7(SFTO[0]),
    .i8(1'bx),
    .i9(1'bx),
    .sel(dbsrc_addr),
    .o(n133));  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  binary_mux_s4_w1 sel1_b0 (
    .i0(1'b0),
    .i1(1'b0),
    .i10(A[1]),
    .i11(1'b0),
    .i12(B[1]),
    .i13(B[1]),
    .i14(B[1]),
    .i15(1'b0),
    .i2(1'b0),
    .i3(1'b0),
    .i4(1'b0),
    .i5(1'b0),
    .i6(1'b0),
    .i7(1'b0),
    .i8(B[7]),
    .i9(A[1]),
    .sel(instr[15:12]),
    .o(SFTO[0]));  // ../../RTL/cpu/KC_LS1u_plus.v(269)
  binary_mux_s4_w1 sel1_b1 (
    .i0(A[0]),
    .i1(A[0]),
    .i10(A[2]),
    .i11(B[0]),
    .i12(B[2]),
    .i13(B[2]),
    .i14(B[2]),
    .i15(A[0]),
    .i2(A[0]),
    .i3(A[0]),
    .i4(A[0]),
    .i5(A[0]),
    .i6(A[0]),
    .i7(A[0]),
    .i8(A[0]),
    .i9(A[2]),
    .sel(instr[15:12]),
    .o(SFTO[1]));  // ../../RTL/cpu/KC_LS1u_plus.v(269)
  binary_mux_s4_w1 sel1_b2 (
    .i0(A[1]),
    .i1(A[1]),
    .i10(A[3]),
    .i11(B[1]),
    .i12(B[3]),
    .i13(B[3]),
    .i14(B[3]),
    .i15(A[1]),
    .i2(A[1]),
    .i3(A[1]),
    .i4(A[1]),
    .i5(A[1]),
    .i6(A[1]),
    .i7(A[1]),
    .i8(A[1]),
    .i9(A[3]),
    .sel(instr[15:12]),
    .o(SFTO[2]));  // ../../RTL/cpu/KC_LS1u_plus.v(269)
  binary_mux_s4_w1 sel1_b3 (
    .i0(A[2]),
    .i1(A[2]),
    .i10(A[4]),
    .i11(B[2]),
    .i12(B[4]),
    .i13(B[4]),
    .i14(B[4]),
    .i15(A[2]),
    .i2(A[2]),
    .i3(A[2]),
    .i4(A[2]),
    .i5(A[2]),
    .i6(A[2]),
    .i7(A[2]),
    .i8(A[2]),
    .i9(A[4]),
    .sel(instr[15:12]),
    .o(SFTO[3]));  // ../../RTL/cpu/KC_LS1u_plus.v(269)
  binary_mux_s4_w1 sel1_b4 (
    .i0(A[3]),
    .i1(A[3]),
    .i10(A[5]),
    .i11(B[3]),
    .i12(B[5]),
    .i13(B[5]),
    .i14(B[5]),
    .i15(A[3]),
    .i2(A[3]),
    .i3(A[3]),
    .i4(A[3]),
    .i5(A[3]),
    .i6(A[3]),
    .i7(A[3]),
    .i8(A[3]),
    .i9(A[5]),
    .sel(instr[15:12]),
    .o(SFTO[4]));  // ../../RTL/cpu/KC_LS1u_plus.v(269)
  binary_mux_s4_w1 sel1_b5 (
    .i0(A[4]),
    .i1(A[4]),
    .i10(A[6]),
    .i11(B[4]),
    .i12(B[6]),
    .i13(B[6]),
    .i14(B[6]),
    .i15(A[4]),
    .i2(A[4]),
    .i3(A[4]),
    .i4(A[4]),
    .i5(A[4]),
    .i6(A[4]),
    .i7(A[4]),
    .i8(A[4]),
    .i9(A[6]),
    .sel(instr[15:12]),
    .o(SFTO[5]));  // ../../RTL/cpu/KC_LS1u_plus.v(269)
  binary_mux_s4_w1 sel1_b6 (
    .i0(A[5]),
    .i1(A[5]),
    .i10(A[7]),
    .i11(B[5]),
    .i12(B[7]),
    .i13(B[7]),
    .i14(B[7]),
    .i15(A[5]),
    .i2(A[5]),
    .i3(A[5]),
    .i4(A[5]),
    .i5(A[5]),
    .i6(A[5]),
    .i7(A[5]),
    .i8(A[5]),
    .i9(A[7]),
    .sel(instr[15:12]),
    .o(SFTO[6]));  // ../../RTL/cpu/KC_LS1u_plus.v(269)
  binary_mux_s4_w1 sel1_b7 (
    .i0(A[6]),
    .i1(A[6]),
    .i10(A[7]),
    .i11(B[6]),
    .i12(1'b0),
    .i13(B[7]),
    .i14(A[0]),
    .i15(A[6]),
    .i2(A[6]),
    .i3(A[6]),
    .i4(A[6]),
    .i5(A[6]),
    .i6(A[6]),
    .i7(A[6]),
    .i8(A[6]),
    .i9(1'b0),
    .sel(instr[15:12]),
    .o(SFTO[7]));  // ../../RTL/cpu/KC_LS1u_plus.v(269)
  binary_mux_s4_w1 sel2 (
    .i0(XCRi[7]),
    .i1(ALU_out[7]),
    .i10(1'bx),
    .i11(1'bx),
    .i12(1'bx),
    .i13(1'bx),
    .i14(1'bx),
    .i15(1'bx),
    .i2(ddata_i[7]),
    .i3(XCRa[7]),
    .i4(1'bx),
    .i5(XREGr[7]),
    .i6(1'bx),
    .i7(SFTO[7]),
    .i8(1'bx),
    .i9(1'bx),
    .sel(dbsrc_addr),
    .o(n103));  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  AL_MUX sel3 (
    .i0(1'b1),
    .i1(1'b0),
    .sel(n102),
    .o(n104));  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  binary_mux_s4_w1 sel4 (
    .i0(XCRi[6]),
    .i1(ALU_out[6]),
    .i10(1'bx),
    .i11(1'bx),
    .i12(1'bx),
    .i13(1'bx),
    .i14(1'bx),
    .i15(1'bx),
    .i2(ddata_i[6]),
    .i3(XCRa[6]),
    .i4(1'bx),
    .i5(XREGr[6]),
    .i6(1'bx),
    .i7(SFTO[6]),
    .i8(1'bx),
    .i9(1'bx),
    .sel(dbsrc_addr),
    .o(n105));  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  binary_mux_s4_w1 sel5 (
    .i0(XCRi[5]),
    .i1(ALU_out[5]),
    .i10(1'bx),
    .i11(1'bx),
    .i12(1'bx),
    .i13(1'bx),
    .i14(1'bx),
    .i15(1'bx),
    .i2(ddata_i[5]),
    .i3(XCRa[5]),
    .i4(1'bx),
    .i5(XREGr[5]),
    .i6(1'bx),
    .i7(SFTO[5]),
    .i8(1'bx),
    .i9(1'bx),
    .sel(dbsrc_addr),
    .o(n108));  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  binary_mux_s4_w1 sel6 (
    .i0(XCRi[4]),
    .i1(ALU_out[4]),
    .i10(1'bx),
    .i11(1'bx),
    .i12(1'bx),
    .i13(1'bx),
    .i14(1'bx),
    .i15(1'bx),
    .i2(ddata_i[4]),
    .i3(XCRa[4]),
    .i4(1'bx),
    .i5(XREGr[4]),
    .i6(1'bx),
    .i7(SFTO[4]),
    .i8(1'bx),
    .i9(1'bx),
    .sel(dbsrc_addr),
    .o(n113));  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  binary_mux_s4_w1 sel7 (
    .i0(XCRi[3]),
    .i1(ALU_out[3]),
    .i10(1'bx),
    .i11(1'bx),
    .i12(1'bx),
    .i13(1'bx),
    .i14(1'bx),
    .i15(1'bx),
    .i2(ddata_i[3]),
    .i3(XCRa[3]),
    .i4(1'bx),
    .i5(XREGr[3]),
    .i6(1'bx),
    .i7(SFTO[3]),
    .i8(1'bx),
    .i9(1'bx),
    .sel(dbsrc_addr),
    .o(n118));  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  binary_mux_s4_w1 sel8 (
    .i0(XCRi[2]),
    .i1(ALU_out[2]),
    .i10(1'bx),
    .i11(1'bx),
    .i12(1'bx),
    .i13(1'bx),
    .i14(1'bx),
    .i15(1'bx),
    .i2(ddata_i[2]),
    .i3(XCRa[2]),
    .i4(1'bx),
    .i5(XREGr[2]),
    .i6(1'bx),
    .i7(SFTO[2]),
    .i8(1'bx),
    .i9(1'bx),
    .sel(dbsrc_addr),
    .o(n123));  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  binary_mux_s4_w1 sel9 (
    .i0(XCRi[1]),
    .i1(ALU_out[1]),
    .i10(1'bx),
    .i11(1'bx),
    .i12(1'bx),
    .i13(1'bx),
    .i14(1'bx),
    .i15(1'bx),
    .i2(ddata_i[1]),
    .i3(XCRa[1]),
    .i4(1'bx),
    .i5(XREGr[1]),
    .i6(1'bx),
    .i7(SFTO[1]),
    .i8(1'bx),
    .i9(1'bx),
    .sel(dbsrc_addr),
    .o(n128));  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  or u10 (n4, dread, n3);  // ../../RTL/cpu/KC_LS1u_plus.v(40)
  and u103 (dwrite, n43, n1);  // ../../RTL/cpu/KC_LS1u_plus.v(320)
  and u11 (INSTR_HOLD, n4, WAIT_DATA);  // ../../RTL/cpu/KC_LS1u_plus.v(40)
  or u12 (n6, instr_wait, INSTR_HOLD);  // ../../RTL/cpu/KC_LS1u_plus.v(56)
  AL_MUX u126 (
    .i0(daddr[1]),
    .i1(RET0[1]),
    .sel(ret_sel),
    .o(jaddr[1]));
  AL_MUX u127 (
    .i0(daddr[2]),
    .i1(RET0[2]),
    .sel(ret_sel),
    .o(jaddr[2]));
  AL_MUX u128 (
    .i0(daddr[3]),
    .i1(RET0[3]),
    .sel(ret_sel),
    .o(jaddr[3]));
  AL_MUX u129 (
    .i0(daddr[4]),
    .i1(RET0[4]),
    .sel(ret_sel),
    .o(jaddr[4]));
  not u13 (n8, instr_wait);  // ../../RTL/cpu/KC_LS1u_plus.v(71)
  AL_MUX u130 (
    .i0(daddr[5]),
    .i1(RET0[5]),
    .sel(ret_sel),
    .o(jaddr[5]));
  AL_MUX u131 (
    .i0(daddr[6]),
    .i1(RET0[6]),
    .sel(ret_sel),
    .o(jaddr[6]));
  AL_MUX u132 (
    .i0(daddr[7]),
    .i1(RET0[7]),
    .sel(ret_sel),
    .o(jaddr[7]));
  AL_MUX u133 (
    .i0(daddr[8]),
    .i1(RET1[0]),
    .sel(ret_sel),
    .o(jaddr[8]));
  AL_MUX u134 (
    .i0(daddr[9]),
    .i1(RET1[1]),
    .sel(ret_sel),
    .o(jaddr[9]));
  AL_MUX u135 (
    .i0(daddr[10]),
    .i1(RET1[2]),
    .sel(ret_sel),
    .o(jaddr[10]));
  AL_MUX u136 (
    .i0(daddr[11]),
    .i1(RET1[3]),
    .sel(ret_sel),
    .o(jaddr[11]));
  AL_MUX u137 (
    .i0(daddr[12]),
    .i1(RET1[4]),
    .sel(ret_sel),
    .o(jaddr[12]));
  AL_MUX u138 (
    .i0(daddr[13]),
    .i1(RET1[5]),
    .sel(ret_sel),
    .o(jaddr[13]));
  AL_MUX u139 (
    .i0(daddr[14]),
    .i1(RET1[6]),
    .sel(ret_sel),
    .o(jaddr[14]));
  and u14 (n9, int_filter, n8);  // ../../RTL/cpu/KC_LS1u_plus.v(71)
  AL_MUX u140 (
    .i0(daddr[15]),
    .i1(RET1[7]),
    .sel(ret_sel),
    .o(jaddr[15]));
  AL_MUX u141 (
    .i0(daddr[16]),
    .i1(RET2[0]),
    .sel(ret_sel),
    .o(jaddr[16]));
  AL_MUX u142 (
    .i0(daddr[17]),
    .i1(RET2[1]),
    .sel(ret_sel),
    .o(jaddr[17]));
  AL_MUX u143 (
    .i0(daddr[18]),
    .i1(RET2[2]),
    .sel(ret_sel),
    .o(jaddr[18]));
  AL_MUX u144 (
    .i0(daddr[19]),
    .i1(RET2[3]),
    .sel(ret_sel),
    .o(jaddr[19]));
  AL_MUX u145 (
    .i0(daddr[20]),
    .i1(RET2[4]),
    .sel(ret_sel),
    .o(jaddr[20]));
  AL_MUX u146 (
    .i0(daddr[21]),
    .i1(RET2[5]),
    .sel(ret_sel),
    .o(jaddr[21]));
  AL_MUX u147 (
    .i0(daddr[22]),
    .i1(RET2[6]),
    .sel(ret_sel),
    .o(jaddr[22]));
  or u151 (n140, n101, n141);  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  or u152 (n139, n97, n96);  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  or u153 (n98, dread, n139);  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  or u154 (n135, n140, n98);  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  not u155 (n102, n135);  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  and u16 (n13, XCRwe, n8);  // ../../RTL/cpu/KC_LS1u_plus.v(86)
  AL_MUX u17 (
    .i0(IN_ISP),
    .i1(1'b0),
    .sel(ret_sel),
    .o(n26));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  AL_MUX u18 (
    .i0(n26),
    .i1(1'b1),
    .sel(n9),
    .o(n36));  // ../../RTL/cpu/KC_LS1u_plus.v(95)
  and u20 (n43, regwrite, n8);  // ../../RTL/cpu/KC_LS1u_plus.v(111)
  or u227 (n80, n79, n125);  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or u228 (n122, n76, n75);  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or u229 (n121, n124, n122);  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or u230 (n120, n74, n73);  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or u231 (n119, n72, n71);  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or u232 (n117, n120, n119);  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or u233 (n116, n121, n117);  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or u234 (n115, XCRwe, n65);  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or u235 (n114, n70, n69);  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or u236 (n112, n115, n114);  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or u237 (n111, n68, n67);  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or u238 (n110, n66, jmp_en);  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or u239 (n109, n111, n110);  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or u240 (n107, n112, n109);  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or u241 (n106, n116, n107);  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  not u242 (n79, n106);  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or u31 (n124, n78, n77);  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  not u33 (regwrite, n80);  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  or u34 (n125, XCRwe, jmp_en);  // ../../RTL/cpu/KC_LS1u_plus.v(199)
  and u38 (ALU_eqo, ALU_eq[0], ALU_eq[1]);  // ../../RTL/cpu/KC_LS1u_plus.v(226)
  not u41 (n91, A[7]);  // ../../RTL/cpu/KC_LS1u_plus.v(278)
  not u43 (n93, ALU_eqo);  // ../../RTL/cpu/KC_LS1u_plus.v(280)
  AL_MUX u45 (
    .i0(1'b0),
    .i1(n90),
    .sel(jmp_en),
    .o(ret_sel));  // ../../RTL/cpu/KC_LS1u_plus.v(286)
  AL_MUX u46 (
    .i0(1'b0),
    .i1(n95),
    .sel(jmp_en),
    .o(jmp));  // ../../RTL/cpu/KC_LS1u_plus.v(286)
  not u5 (n0, IN_ISP);  // ../../RTL/cpu/KC_LS1u_plus.v(36)
  and u53_and (XCRo[0], n133, n104);
  and u58_and (XCRo[1], n128, n104);
  and u6 (int_filter, INT, n0);  // ../../RTL/cpu/KC_LS1u_plus.v(36)
  and u63_and (XCRo[2], n123, n104);
  and u68_and (XCRo[3], n118, n104);
  or u7 (instr_wait, WAIT, jmp_wait);  // ../../RTL/cpu/KC_LS1u_plus.v(39)
  and u73_and (XCRo[4], n113, n104);
  and u78_and (XCRo[5], n108, n104);
  and u8 (n2, regwrite, n1);  // ../../RTL/cpu/KC_LS1u_plus.v(40)
  and u83_and (XCRo[6], n105, n104);
  and u88_and (XCRo[7], n103, n104);
  or u89 (n141, n100, n99);  // ../../RTL/cpu/KC_LS1u_plus.v(305)
  or u9 (n3, n2, dwrite);  // ../../RTL/cpu/KC_LS1u_plus.v(40)
  AL_MUX u94 (
    .i0(daddr[0]),
    .i1(RET0[0]),
    .sel(ret_sel),
    .o(jaddr[0]));

endmodule 

module \xcr_top(MMU_ENABLE=1'b0)   // ../../RTL/cpu/XCR_Components/xcr_top.v(7)
  (
  INT_ARR,
  XCP_ARR,
  clk,
  cr_adr,
  cr_cs,
  cr_din,
  cr_we,
  rst,
  INT,
  IVEC_ADDR,
  cr_dout,
  dpae_h16,
  dpte_h8,
  hugepage_ptr,
  ipae_h16,
  ipte_h8,
  mmu_enable,
  supervisor_mode
  );

  input [7:0] INT_ARR;  // ../../RTL/cpu/XCR_Components/xcr_top.v(20)
  input [7:0] XCP_ARR;  // ../../RTL/cpu/XCR_Components/xcr_top.v(21)
  input clk;  // ../../RTL/cpu/XCR_Components/xcr_top.v(11)
  input [7:0] cr_adr;  // ../../RTL/cpu/XCR_Components/xcr_top.v(16)
  input cr_cs;  // ../../RTL/cpu/XCR_Components/xcr_top.v(18)
  input [7:0] cr_din;  // ../../RTL/cpu/XCR_Components/xcr_top.v(14)
  input cr_we;  // ../../RTL/cpu/XCR_Components/xcr_top.v(17)
  input rst;  // ../../RTL/cpu/XCR_Components/xcr_top.v(12)
  output INT;  // ../../RTL/cpu/XCR_Components/xcr_top.v(23)
  output [23:0] IVEC_ADDR;  // ../../RTL/cpu/XCR_Components/xcr_top.v(22)
  output [7:0] cr_dout;  // ../../RTL/cpu/XCR_Components/xcr_top.v(15)
  output [15:0] dpae_h16;  // ../../RTL/cpu/XCR_Components/xcr_top.v(26)
  output [7:0] dpte_h8;  // ../../RTL/cpu/XCR_Components/xcr_top.v(28)
  output [10:0] hugepage_ptr;  // ../../RTL/cpu/XCR_Components/xcr_top.v(29)
  output [15:0] ipae_h16;  // ../../RTL/cpu/XCR_Components/xcr_top.v(25)
  output [7:0] ipte_h8;  // ../../RTL/cpu/XCR_Components/xcr_top.v(27)
  output mmu_enable;  // ../../RTL/cpu/XCR_Components/xcr_top.v(30)
  output supervisor_mode;  // ../../RTL/cpu/XCR_Components/xcr_top.v(31)

  parameter MMU_ENABLE = 1'b0;
  parameter cDMA_ENABLE = 1'b0;
  wire [7:0] ecp_dout;  // ../../RTL/cpu/XCR_Components/xcr_top.v(33)
  wire ecp_cs;  // ../../RTL/cpu/XCR_Components/xcr_top.v(34)
  wire n0;

  assign INT = 1'b0;
  assign IVEC_ADDR[23] = 1'b0;
  assign dpae_h16[15] = 1'b0;
  assign dpae_h16[14] = 1'b0;
  assign dpae_h16[13] = 1'b0;
  assign dpae_h16[12] = 1'b0;
  assign dpae_h16[11] = 1'b0;
  assign dpae_h16[10] = 1'b0;
  assign dpae_h16[9] = 1'b0;
  assign dpae_h16[8] = 1'b0;
  assign dpae_h16[7] = 1'b0;
  assign dpae_h16[6] = 1'b0;
  assign dpae_h16[5] = 1'b0;
  assign dpae_h16[4] = 1'b0;
  assign dpae_h16[3] = 1'b0;
  assign dpae_h16[2] = 1'b0;
  assign dpae_h16[1] = 1'b0;
  assign dpae_h16[0] = 1'b0;
  assign dpte_h8[7] = 1'b0;
  assign dpte_h8[6] = 1'b0;
  assign dpte_h8[5] = 1'b0;
  assign dpte_h8[4] = 1'b0;
  assign dpte_h8[3] = 1'b0;
  assign dpte_h8[2] = 1'b0;
  assign dpte_h8[1] = 1'b0;
  assign dpte_h8[0] = 1'b0;
  assign hugepage_ptr[10] = 1'b0;
  assign hugepage_ptr[9] = 1'b0;
  assign hugepage_ptr[8] = 1'b0;
  assign hugepage_ptr[7] = 1'b0;
  assign hugepage_ptr[6] = 1'b0;
  assign hugepage_ptr[5] = 1'b0;
  assign hugepage_ptr[4] = 1'b0;
  assign hugepage_ptr[3] = 1'b0;
  assign hugepage_ptr[2] = 1'b0;
  assign hugepage_ptr[1] = 1'b0;
  assign hugepage_ptr[0] = 1'b0;
  assign ipae_h16[15] = 1'b0;
  assign ipae_h16[14] = 1'b0;
  assign ipae_h16[13] = 1'b0;
  assign ipae_h16[12] = 1'b0;
  assign ipae_h16[11] = 1'b0;
  assign ipae_h16[10] = 1'b0;
  assign ipae_h16[9] = 1'b0;
  assign ipae_h16[8] = 1'b0;
  assign ipae_h16[7] = 1'b0;
  assign ipae_h16[6] = 1'b0;
  assign ipae_h16[5] = 1'b0;
  assign ipae_h16[4] = 1'b0;
  assign ipae_h16[3] = 1'b0;
  assign ipae_h16[2] = 1'b0;
  assign ipae_h16[1] = 1'b0;
  assign ipae_h16[0] = 1'b0;
  assign ipte_h8[7] = 1'b0;
  assign ipte_h8[6] = 1'b0;
  assign ipte_h8[5] = 1'b0;
  assign ipte_h8[4] = 1'b0;
  assign ipte_h8[3] = 1'b0;
  assign ipte_h8[2] = 1'b0;
  assign ipte_h8[1] = 1'b0;
  assign ipte_h8[0] = 1'b0;
  assign mmu_enable = 1'b0;
  assign supervisor_mode = 1'b0;
  xcr_ecp_ctrl Interrupt_Controller (
    .INT_ARR(8'b00000000),
    .XCP_ARR(8'b00000000),
    .clk(clk),
    .cr_adr(cr_adr[2:0]),
    .cr_cs(ecp_cs),
    .cr_din(cr_din),
    .cr_we(cr_we),
    .rst(1'b0),
    .IVEC_ADDR({open_n1,IVEC_ADDR[22:0]}),
    .cr_dout(ecp_dout));  // ../../RTL/cpu/XCR_Components/xcr_top.v(35)
  eq_w4 eq0 (
    .i0(cr_adr[7:4]),
    .i1(4'b0000),
    .o(n0));  // ../../RTL/cpu/XCR_Components/xcr_top.v(86)
  AL_MUX sel0_b0 (
    .i0(1'b0),
    .i1(ecp_dout[0]),
    .sel(n0),
    .o(cr_dout[0]));  // ../../RTL/cpu/XCR_Components/xcr_top.v(93)
  AL_MUX sel0_b1 (
    .i0(1'b0),
    .i1(ecp_dout[1]),
    .sel(n0),
    .o(cr_dout[1]));  // ../../RTL/cpu/XCR_Components/xcr_top.v(93)
  AL_MUX sel0_b2 (
    .i0(1'b0),
    .i1(ecp_dout[2]),
    .sel(n0),
    .o(cr_dout[2]));  // ../../RTL/cpu/XCR_Components/xcr_top.v(93)
  AL_MUX sel0_b3 (
    .i0(1'b0),
    .i1(ecp_dout[3]),
    .sel(n0),
    .o(cr_dout[3]));  // ../../RTL/cpu/XCR_Components/xcr_top.v(93)
  AL_MUX sel0_b4 (
    .i0(1'b0),
    .i1(ecp_dout[4]),
    .sel(n0),
    .o(cr_dout[4]));  // ../../RTL/cpu/XCR_Components/xcr_top.v(93)
  AL_MUX sel0_b5 (
    .i0(1'b0),
    .i1(ecp_dout[5]),
    .sel(n0),
    .o(cr_dout[5]));  // ../../RTL/cpu/XCR_Components/xcr_top.v(93)
  AL_MUX sel0_b6 (
    .i0(1'b0),
    .i1(ecp_dout[6]),
    .sel(n0),
    .o(cr_dout[6]));  // ../../RTL/cpu/XCR_Components/xcr_top.v(93)
  AL_MUX sel0_b7 (
    .i0(1'b0),
    .i1(ecp_dout[7]),
    .sel(n0),
    .o(cr_dout[7]));  // ../../RTL/cpu/XCR_Components/xcr_top.v(93)
  and u11 (ecp_cs, n0, cr_cs);  // ../../RTL/cpu/XCR_Components/xcr_top.v(86)

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

module xcr_ecp_ctrl  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(11)
  (
  INT_ARR,
  XCP_ARR,
  clk,
  cr_adr,
  cr_cs,
  cr_din,
  cr_we,
  rst,
  INT,
  IVEC_ADDR,
  cr_dout
  );

  input [7:0] INT_ARR;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(14)
  input [7:0] XCP_ARR;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(15)
  input clk;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(19)
  input [2:0] cr_adr;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(24)
  input cr_cs;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(26)
  input [7:0] cr_din;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(22)
  input cr_we;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(25)
  input rst;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(20)
  output INT;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(17)
  output [23:0] IVEC_ADDR;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(16)
  output [7:0] cr_dout;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(23)

  // localparam EXCEPTION_CATCHER[0].j = 0;
  // localparam EXCEPTION_CATCHER[1].j = 1;
  // localparam EXCEPTION_CATCHER[2].j = 2;
  // localparam EXCEPTION_CATCHER[3].j = 3;
  // localparam EXCEPTION_CATCHER[4].j = 4;
  // localparam EXCEPTION_CATCHER[5].j = 5;
  // localparam EXCEPTION_CATCHER[6].j = 6;
  // localparam EXCEPTION_CATCHER[7].j = 7;
  wire [7:0] EXPE0;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(35)
  wire [2:0] INTC;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(33)
  wire [7:0] INTE0;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(35)
  wire [7:0] IVT0;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(34)
  wire [7:0] IVT1;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(34)
  wire [7:0] IVT2;  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(34)
  wire [21:0] n1;
  wire [7:0] n23;
  wire \cr_adr[0]_neg ;
  wire \cr_adr[1]_neg ;
  wire \cr_adr[2]_neg ;
  wire mux10_b0_sel_is_3_o;
  wire mux11_b0_sel_is_2_o;
  wire mux12_b0_sel_is_1_o;
  wire mux13_b0_sel_is_0_o;
  wire mux14_b0_sel_is_3_o;
  wire mux15_b0_sel_is_3_o;
  wire mux16_b0_sel_is_3_o;
  wire mux17_b0_sel_is_3_o;
  wire mux18_b0_sel_is_3_o;
  wire mux19_b0_sel_is_3_o;
  wire mux8_b0_sel_is_5_o;
  wire mux9_b0_sel_is_4_o;
  wire n24;
  wire n5;

  assign INT = 1'b0;
  assign IVEC_ADDR[23] = 1'b0;
  add_pu21_pu21_o21 add0 (
    .i0({IVT2[6:0],IVT1,IVT0[7:2]}),
    .i1(21'b000000000000000000000),
    .o(n1[20:0]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(79)
  not \cr_adr[0]_inv  (\cr_adr[0]_neg , cr_adr[0]);
  not \cr_adr[1]_inv  (\cr_adr[1]_neg , cr_adr[1]);
  not \cr_adr[2]_inv  (\cr_adr[2]_neg , cr_adr[2]);
  and mux10_b0_sel_is_3 (mux10_b0_sel_is_3_o, cr_adr[0], cr_adr[1], \cr_adr[2]_neg );
  and mux11_b0_sel_is_2 (mux11_b0_sel_is_2_o, \cr_adr[0]_neg , cr_adr[1], \cr_adr[2]_neg );
  and mux12_b0_sel_is_1 (mux12_b0_sel_is_1_o, cr_adr[0], \cr_adr[1]_neg , \cr_adr[2]_neg );
  and mux13_b0_sel_is_0 (mux13_b0_sel_is_0_o, \cr_adr[0]_neg , \cr_adr[1]_neg , \cr_adr[2]_neg );
  and mux14_b0_sel_is_3 (mux14_b0_sel_is_3_o, n5, mux8_b0_sel_is_5_o);
  and mux15_b0_sel_is_3 (mux15_b0_sel_is_3_o, n5, mux9_b0_sel_is_4_o);
  and mux16_b0_sel_is_3 (mux16_b0_sel_is_3_o, n5, mux10_b0_sel_is_3_o);
  and mux17_b0_sel_is_3 (mux17_b0_sel_is_3_o, n5, mux11_b0_sel_is_2_o);
  and mux18_b0_sel_is_3 (mux18_b0_sel_is_3_o, n5, mux12_b0_sel_is_1_o);
  and mux19_b0_sel_is_3 (mux19_b0_sel_is_3_o, n5, mux13_b0_sel_is_0_o);
  binary_mux_s3_w1 mux25_b0 (
    .i0(INTC[0]),
    .i1(IVT0[0]),
    .i2(IVT1[0]),
    .i3(IVT2[0]),
    .i4(INTE0[0]),
    .i5(EXPE0[0]),
    .i6(1'bx),
    .i7(1'bx),
    .sel(cr_adr),
    .o(n23[0]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(134)
  binary_mux_s3_w1 mux25_b1 (
    .i0(INTC[1]),
    .i1(IVT0[1]),
    .i2(IVT1[1]),
    .i3(IVT2[1]),
    .i4(INTE0[1]),
    .i5(EXPE0[1]),
    .i6(1'bx),
    .i7(1'bx),
    .sel(cr_adr),
    .o(n23[1]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(134)
  binary_mux_s3_w1 mux25_b2 (
    .i0(INTC[2]),
    .i1(IVT0[2]),
    .i2(IVT1[2]),
    .i3(IVT2[2]),
    .i4(INTE0[2]),
    .i5(EXPE0[2]),
    .i6(1'bx),
    .i7(1'bx),
    .sel(cr_adr),
    .o(n23[2]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(134)
  binary_mux_s3_w1 mux25_b3 (
    .i0(1'b0),
    .i1(IVT0[3]),
    .i2(IVT1[3]),
    .i3(IVT2[3]),
    .i4(INTE0[3]),
    .i5(EXPE0[3]),
    .i6(1'bx),
    .i7(1'bx),
    .sel(cr_adr),
    .o(n23[3]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(134)
  binary_mux_s3_w1 mux25_b4 (
    .i0(1'b0),
    .i1(IVT0[4]),
    .i2(IVT1[4]),
    .i3(IVT2[4]),
    .i4(INTE0[4]),
    .i5(EXPE0[4]),
    .i6(1'bx),
    .i7(1'bx),
    .sel(cr_adr),
    .o(n23[4]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(134)
  binary_mux_s3_w1 mux25_b5 (
    .i0(1'b0),
    .i1(IVT0[5]),
    .i2(IVT1[5]),
    .i3(IVT2[5]),
    .i4(INTE0[5]),
    .i5(EXPE0[5]),
    .i6(1'bx),
    .i7(1'bx),
    .sel(cr_adr),
    .o(n23[5]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(134)
  binary_mux_s3_w1 mux25_b6 (
    .i0(1'b0),
    .i1(IVT0[6]),
    .i2(IVT1[6]),
    .i3(IVT2[6]),
    .i4(INTE0[6]),
    .i5(EXPE0[6]),
    .i6(1'bx),
    .i7(1'bx),
    .sel(cr_adr),
    .o(n23[6]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(134)
  binary_mux_s3_w1 mux25_b7 (
    .i0(1'b0),
    .i1(IVT0[7]),
    .i2(IVT1[7]),
    .i3(IVT2[7]),
    .i4(INTE0[7]),
    .i5(EXPE0[7]),
    .i6(1'bx),
    .i7(1'bx),
    .sel(cr_adr),
    .o(n23[7]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(134)
  binary_mux_s3_w1 mux26 (
    .i0(1'b1),
    .i1(1'b1),
    .i2(1'b1),
    .i3(1'b1),
    .i4(1'b1),
    .i5(1'b1),
    .i6(1'b0),
    .i7(1'b0),
    .sel(cr_adr),
    .o(n24));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(134)
  and mux8_b0_sel_is_5 (mux8_b0_sel_is_5_o, cr_adr[0], \cr_adr[1]_neg , cr_adr[2]);
  and mux9_b0_sel_is_4 (mux9_b0_sel_is_4_o, \cr_adr[0]_neg , \cr_adr[1]_neg , cr_adr[2]);
  reg_ar_as_w1 reg0_b0 (
    .clk(clk),
    .d(IVT0[0]),
    .en(INTC[2]),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_ADDR[0]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 reg0_b1 (
    .clk(clk),
    .d(IVT0[1]),
    .en(INTC[2]),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_ADDR[1]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 reg0_b10 (
    .clk(clk),
    .d(n1[8]),
    .en(INTC[2]),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_ADDR[10]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 reg0_b11 (
    .clk(clk),
    .d(n1[9]),
    .en(INTC[2]),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_ADDR[11]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 reg0_b12 (
    .clk(clk),
    .d(n1[10]),
    .en(INTC[2]),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_ADDR[12]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 reg0_b13 (
    .clk(clk),
    .d(n1[11]),
    .en(INTC[2]),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_ADDR[13]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 reg0_b14 (
    .clk(clk),
    .d(n1[12]),
    .en(INTC[2]),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_ADDR[14]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 reg0_b15 (
    .clk(clk),
    .d(n1[13]),
    .en(INTC[2]),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_ADDR[15]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 reg0_b16 (
    .clk(clk),
    .d(n1[14]),
    .en(INTC[2]),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_ADDR[16]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 reg0_b17 (
    .clk(clk),
    .d(n1[15]),
    .en(INTC[2]),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_ADDR[17]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 reg0_b18 (
    .clk(clk),
    .d(n1[16]),
    .en(INTC[2]),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_ADDR[18]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 reg0_b19 (
    .clk(clk),
    .d(n1[17]),
    .en(INTC[2]),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_ADDR[19]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 reg0_b2 (
    .clk(clk),
    .d(n1[0]),
    .en(INTC[2]),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_ADDR[2]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 reg0_b20 (
    .clk(clk),
    .d(n1[18]),
    .en(INTC[2]),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_ADDR[20]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 reg0_b21 (
    .clk(clk),
    .d(n1[19]),
    .en(INTC[2]),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_ADDR[21]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 reg0_b22 (
    .clk(clk),
    .d(n1[20]),
    .en(INTC[2]),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_ADDR[22]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 reg0_b3 (
    .clk(clk),
    .d(n1[1]),
    .en(INTC[2]),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_ADDR[3]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 reg0_b4 (
    .clk(clk),
    .d(n1[2]),
    .en(INTC[2]),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_ADDR[4]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 reg0_b5 (
    .clk(clk),
    .d(n1[3]),
    .en(INTC[2]),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_ADDR[5]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 reg0_b6 (
    .clk(clk),
    .d(n1[4]),
    .en(INTC[2]),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_ADDR[6]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 reg0_b7 (
    .clk(clk),
    .d(n1[5]),
    .en(INTC[2]),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_ADDR[7]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 reg0_b8 (
    .clk(clk),
    .d(n1[6]),
    .en(INTC[2]),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_ADDR[8]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 reg0_b9 (
    .clk(clk),
    .d(n1[7]),
    .en(INTC[2]),
    .reset(1'b0),
    .set(1'b0),
    .q(IVEC_ADDR[9]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(85)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg1_b0 (
    .clk(clk),
    .d(cr_din[0]),
    .en(mux19_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(INTC[0]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg1_b1 (
    .clk(clk),
    .d(cr_din[1]),
    .en(mux19_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(INTC[1]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 #(
    //.GSR("ENABLE"),
    .REGSET("RESET"))
    reg1_b2 (
    .clk(clk),
    .d(cr_din[7]),
    .en(mux19_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(INTC[2]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg2_b0 (
    .clk(clk),
    .d(cr_din[0]),
    .en(mux14_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(EXPE0[0]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg2_b1 (
    .clk(clk),
    .d(cr_din[1]),
    .en(mux14_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(EXPE0[1]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg2_b2 (
    .clk(clk),
    .d(cr_din[2]),
    .en(mux14_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(EXPE0[2]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg2_b3 (
    .clk(clk),
    .d(cr_din[3]),
    .en(mux14_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(EXPE0[3]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg2_b4 (
    .clk(clk),
    .d(cr_din[4]),
    .en(mux14_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(EXPE0[4]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg2_b5 (
    .clk(clk),
    .d(cr_din[5]),
    .en(mux14_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(EXPE0[5]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg2_b6 (
    .clk(clk),
    .d(cr_din[6]),
    .en(mux14_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(EXPE0[6]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg2_b7 (
    .clk(clk),
    .d(cr_din[7]),
    .en(mux14_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(EXPE0[7]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg3_b0 (
    .clk(clk),
    .d(cr_din[0]),
    .en(mux15_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(INTE0[0]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg3_b1 (
    .clk(clk),
    .d(cr_din[1]),
    .en(mux15_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(INTE0[1]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg3_b2 (
    .clk(clk),
    .d(cr_din[2]),
    .en(mux15_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(INTE0[2]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg3_b3 (
    .clk(clk),
    .d(cr_din[3]),
    .en(mux15_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(INTE0[3]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg3_b4 (
    .clk(clk),
    .d(cr_din[4]),
    .en(mux15_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(INTE0[4]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg3_b5 (
    .clk(clk),
    .d(cr_din[5]),
    .en(mux15_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(INTE0[5]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg3_b6 (
    .clk(clk),
    .d(cr_din[6]),
    .en(mux15_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(INTE0[6]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg3_b7 (
    .clk(clk),
    .d(cr_din[7]),
    .en(mux15_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(INTE0[7]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg4_b0 (
    .clk(clk),
    .d(cr_din[0]),
    .en(mux16_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(IVT2[0]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg4_b1 (
    .clk(clk),
    .d(cr_din[1]),
    .en(mux16_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(IVT2[1]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg4_b2 (
    .clk(clk),
    .d(cr_din[2]),
    .en(mux16_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(IVT2[2]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg4_b3 (
    .clk(clk),
    .d(cr_din[3]),
    .en(mux16_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(IVT2[3]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg4_b4 (
    .clk(clk),
    .d(cr_din[4]),
    .en(mux16_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(IVT2[4]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg4_b5 (
    .clk(clk),
    .d(cr_din[5]),
    .en(mux16_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(IVT2[5]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg4_b6 (
    .clk(clk),
    .d(cr_din[6]),
    .en(mux16_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(IVT2[6]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg4_b7 (
    .clk(clk),
    .d(cr_din[7]),
    .en(mux16_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(IVT2[7]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg5_b0 (
    .clk(clk),
    .d(cr_din[0]),
    .en(mux17_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(IVT1[0]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg5_b1 (
    .clk(clk),
    .d(cr_din[1]),
    .en(mux17_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(IVT1[1]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg5_b2 (
    .clk(clk),
    .d(cr_din[2]),
    .en(mux17_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(IVT1[2]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg5_b3 (
    .clk(clk),
    .d(cr_din[3]),
    .en(mux17_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(IVT1[3]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg5_b4 (
    .clk(clk),
    .d(cr_din[4]),
    .en(mux17_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(IVT1[4]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg5_b5 (
    .clk(clk),
    .d(cr_din[5]),
    .en(mux17_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(IVT1[5]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg5_b6 (
    .clk(clk),
    .d(cr_din[6]),
    .en(mux17_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(IVT1[6]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg5_b7 (
    .clk(clk),
    .d(cr_din[7]),
    .en(mux17_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(IVT1[7]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg6_b0 (
    .clk(clk),
    .d(cr_din[0]),
    .en(mux18_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(IVT0[0]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg6_b1 (
    .clk(clk),
    .d(cr_din[1]),
    .en(mux18_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(IVT0[1]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg6_b2 (
    .clk(clk),
    .d(cr_din[2]),
    .en(mux18_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(IVT0[2]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg6_b3 (
    .clk(clk),
    .d(cr_din[3]),
    .en(mux18_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(IVT0[3]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg6_b4 (
    .clk(clk),
    .d(cr_din[4]),
    .en(mux18_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(IVT0[4]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg6_b5 (
    .clk(clk),
    .d(cr_din[5]),
    .en(mux18_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(IVT0[5]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg6_b6 (
    .clk(clk),
    .d(cr_din[6]),
    .en(mux18_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(IVT0[6]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  reg_ar_as_w1 reg6_b7 (
    .clk(clk),
    .d(cr_din[7]),
    .en(mux18_b0_sel_is_3_o),
    .reset(1'b0),
    .set(1'b0),
    .q(IVT0[7]));  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(119)
  and u13_and (cr_dout[0], n23[0], n24);
  and u18_and (cr_dout[1], n23[1], n24);
  and u23_and (cr_dout[2], n23[2], n24);
  and u28_and (cr_dout[3], n23[3], n24);
  and u33_and (cr_dout[4], n23[4], n24);
  and u38_and (cr_dout[5], n23[5], n24);
  and u43_and (cr_dout[6], n23[6], n24);
  and u48_and (cr_dout[7], n23[7], n24);
  and u8 (n5, cr_cs, cr_we);  // ../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v(100)

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

