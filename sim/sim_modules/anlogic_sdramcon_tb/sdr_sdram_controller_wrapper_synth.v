//   ==================================================================
//   >>>>>>>>>>>>>>>>>>>>>>> COPYRIGHT NOTICE <<<<<<<<<<<<<<<<<<<<<<<<<
//   ------------------------------------------------------------------
//   Copyright (c) 2013 by Lattice Semiconductor Corporation
//   ALL RIGHTS RESERVED 
//   ------------------------------------------------------------------
//
//   Permission:
//
//      Lattice SG Pte. Ltd. grants permission to use this code
//      pursuant to the terms of the Lattice Reference Design License Agreement. 
//
//
//   Disclaimer:
//
//      This VHDL or Verilog source code is intended as a design reference
//      which illustrates how these types of functions can be implemented.
//      It is the user's responsibility to verify their design for
//      consistency and functionality through the use of formal
//      verification methods.  Lattice provides no warranty
//      regarding the use or functionality of this code.
//
//   --------------------------------------------------------------------
//
//                  Lattice SG Pte. Ltd.
//                  101 Thomson Road, United Square #07-02 
//                  Singapore 307591
//
//
//                  TEL: 1-800-Lattice (USA and Canada)
//                       +65-6631-2000 (Singapore)
//                       +1-503-268-8001 (other locations)
//
//                  web: http://www.latticesemi.com/
//                  email: techsupport@latticesemi.com
//
//   --------------------------------------------------------------------
//


 `timescale 1ns / 1ps

`define DISABLE_CPU_IO_BUS 0

module sdr_sdram_controller_wrapper_synth (/*AUTOARG*/
                         // Outputs
                         o_data_valid, o_data_req, o_busy, o_init_done, o_ack, 
    
                         o_sdram_addr, o_sdram_blkaddr, o_sdram_casn, o_sdram_cke, 
                         o_sdram_csn, o_sdram_dqm, o_sdram_rasn, o_sdram_wen, o_sdram_clk,
                         o_write_done, o_read_done,

                         // Inouts
`ifdef DISABLE_CPU_IO_BUS
                         i_data, 
                         o_data,
`else
                         io_data, 
`endif
                         io_sdram_dq,
                         
                         // Inputs
                         i_addr, i_adv, i_clk, i_rst, i_rwn, 
                         i_selfrefresh_req, i_loadmod_req, i_burststop_req, i_disable_active, i_disable_precharge, i_precharge_req, i_power_down, i_disable_autorefresh
                         );

`include "sdram_defines.v"

    /*AUTOINPUT*/
    // Beginning of automatic inputs (from unused autoinst inputs)
    input [26:0]                    i_addr; // To U0 of sdram_control_fsm.v
    input                           i_adv;             // To U0 of sdram_control_fsm.v
    input                           i_clk;              // To U0 of sdram_control_fsm.v
    input                           i_rst;              // To U0 of sdram_control_fsm.v
    input                           i_rwn;              // To U0 of sdram_control_fsm.v
    input                           i_selfrefresh_req;          // To U0 of sdram_control_fsm.v
    input                           i_loadmod_req;          // To U0 of sdram_control_fsm.v
    input                           i_burststop_req;          // To U0 of sdram_control_fsm.v
    input                           i_disable_active;
    input                           i_disable_precharge;
    input                           i_precharge_req;
    input                           i_power_down;
    input                           i_disable_autorefresh;
   
       
    
    /*AUTOOUTPUT*/
    // End of automatics
    output                          o_data_valid;       // From U0 of sdram_control_fsm.v
    output                          o_data_req;       // From U0 of sdram_control_fsm.v
    output                          o_busy;           // From U0 of sdram_control_fsm.v
    output                          o_init_done;            // From U0 of sdram_control_fsm.v
    output                          o_ack;          // From U0 of sdram_control_fsm.v
    output [12:0]                   o_sdram_addr; // From U0 of sdram_control_fsm.v
    output [1:0]                    o_sdram_blkaddr;// From U0 of sdram_control_fsm.v
    output                          o_sdram_casn;           // From U0 of sdram_control_fsm.v
    output                          o_sdram_cke;            // From U0 of sdram_control_fsm.v
    output                          o_sdram_csn;            // From U0 of sdram_control_fsm.v
    output [3:0]                    o_sdram_dqm;            // From U0 of sdram_control_fsm.v
    output                          o_sdram_rasn;           // From U0 of sdram_control_fsm.v
    output                          o_sdram_wen;            // From U0 of sdram_control_fsm.v
    output                          o_sdram_clk;            // From U0 of sdram_control_fsm.v

    output                          o_write_done;
    output                          o_read_done;
   
    
    /*AUTOINOUT*/
`ifdef DISABLE_CPU_IO_BUS
    input [31:0]                    i_data;            // To/From U0 of sdram_control_fsm.v
    output [31:0]                   o_data;            // To/From U0 of sdram_control_fsm.v
`else
    inout [31:0]                    io_data;            // To/From U0 of sdram_control_fsm.v
`endif
    inout [31:0]                    io_sdram_dq;            // To/From U0 of sdram_control_fsm.v


   
         sdram_controller sdram_controller_u1 (/*AUTOINST*/
                                          .o_data_valid(o_data_valid),
                                          .o_data_req(o_data_req),
                                          .o_busy(o_busy),
                                          .o_init_done(o_init_done),
                                          .o_ack(o_ack),
                                          .o_sdram_addr(o_sdram_addr),
                                          .o_sdram_blkaddr(o_sdram_blkaddr),
                                          .o_sdram_casn(o_sdram_casn),
                                          .o_sdram_cke(o_sdram_cke),
                                          .o_sdram_csn(o_sdram_csn),
                                          .o_sdram_dqm(o_sdram_dqm),
                                          .o_sdram_rasn(o_sdram_rasn),
                                          .o_sdram_wen(o_sdram_wen),
                                          .o_sdram_clk(o_sdram_clk),
                                          .o_write_done(o_write_done),
                                          .o_read_done(o_read_done),
                                          .i_data(i_data),
                                          .o_data(o_data),
                                          .io_sdram_dq(io_sdram_dq),
                                          .i_addr(i_addr),
                                          .i_adv(i_adv),
                                          .i_clk(i_clk),
                                          .i_rst(i_rst),
                                          .i_rwn(i_rwn),
                                          .i_selfrefresh_req(i_selfrefresh_req),
                                          .i_loadmod_req(i_loadmod_req),
                                          .i_burststop_req(i_burststop_req),
                                          .i_disable_active(i_disable_active),
                                          .i_disable_precharge(i_disable_precharge),
                                          .i_precharge_req(i_precharge_req),
                                          .i_power_down(i_power_down),
                                          .i_disable_autorefresh(i_disable_autorefresh)                                          
                                          );

   
    parameter SDRAM_BURST_LEN_1            = 3'b000;
    parameter SDRAM_BURST_LEN_2            = 3'b001;
    parameter SDRAM_BURST_LEN_4            = 3'b010;
    parameter SDRAM_BURST_LEN_8            = 3'b011;
    
    parameter SDRAM_BURST_PAGE             = 3'b111;
    defparam sdram_controller_u1.SDRAM_BURST_PAGE = SDRAM_BURST_PAGE;

    parameter SDRAM_CAS_LATENCY_2          = 3'b010;
    parameter SDRAM_CAS_LATENCY_3          = 3'b011;

    parameter SDRAM_DATA_WIDTH = 16;
    defparam sdram_controller_u1.SDRAM_DATA_WIDTH = SDRAM_DATA_WIDTH;

    parameter CPU_ADDR_WIDTH = 22;
    defparam sdram_controller_u1.CPU_ADDR_WIDTH = CPU_ADDR_WIDTH;

    parameter SDRAM_ADDR_WIDTH = 12;
    defparam sdram_controller_u1.SDRAM_ADDR_WIDTH = SDRAM_ADDR_WIDTH;

    parameter SDRAM_BLKADR_WIDTH = 2;
    defparam sdram_controller_u1.SDRAM_BLKADR_WIDTH = SDRAM_BLKADR_WIDTH;

    parameter SDRAM_DQM_WIDTH = 2;
    defparam sdram_controller_u1.SDRAM_DQM_WIDTH = SDRAM_DQM_WIDTH;

    parameter ROWADDR_MSB = 22;
    defparam sdram_controller_u1.ROWADDR_MSB = ROWADDR_MSB;
   
    parameter ROWADDR_LSB = 10;
    defparam sdram_controller_u1.ROWADDR_LSB = ROWADDR_LSB;

    parameter MODEREG_CAS_LATENCY = 2;
    defparam sdram_controller_u1.MODEREG_CAS_LATENCY = MODEREG_CAS_LATENCY;

    parameter MODEREG_BURST_LENGTH = 3'b000;
    defparam sdram_controller_u1.MODEREG_BURST_LENGTH = MODEREG_BURST_LENGTH;

    parameter MODEREG_BURST_TYPE = 1'b0;
    defparam sdram_controller_u1.MODEREG_BURST_TYPE = MODEREG_BURST_TYPE;
   
    parameter MODEREG_OPERATION_MODE = 2'b00;
    defparam sdram_controller_u1.MODEREG_OPERATION_MODE = MODEREG_OPERATION_MODE;

    parameter MODEREG_WRITE_BURST_MODE = 1'b0;
    defparam sdram_controller_u1.MODEREG_WRITE_BURST_MODE = MODEREG_WRITE_BURST_MODE;
   
    parameter SDRAM_PAGE_LEN = 256;
    defparam sdram_controller_u1.SDRAM_PAGE_LEN = SDRAM_PAGE_LEN;
   
    parameter CLK_PERIOD            = 10;
    defparam sdram_controller_u1.CLK_PERIOD = CLK_PERIOD;

    parameter LOAD_MODEREG_DELAY = 2*CLK_PERIOD;
    defparam sdram_controller_u1.LOAD_MODEREG_DELAY = LOAD_MODEREG_DELAY;

    parameter PRECHARE_PERIOD = CLK_PERIOD/2 + 22;
    defparam sdram_controller_u1.PRECHARE_PERIOD = PRECHARE_PERIOD;

    parameter AUTOREFRESH_PERIOD = CLK_PERIOD/2 + 67;
    defparam sdram_controller_u1.AUTOREFRESH_PERIOD = AUTOREFRESH_PERIOD;
         
    parameter ACTIVE2RW_DELAY = CLK_PERIOD/2 + 22;
    defparam sdram_controller_u1.ACTIVE2RW_DELAY = ACTIVE2RW_DELAY;
         
    parameter WRITE_RECOVERY_DELAY = CLK_PERIOD/2 + CLK_PERIOD + 8;
    defparam sdram_controller_u1.WRITE_RECOVERY_DELAY = WRITE_RECOVERY_DELAY;
         
    parameter DATAIN2ACTIVE = CLK_PERIOD/2 + 37;
    defparam sdram_controller_u1.DATAIN2ACTIVE = DATAIN2ACTIVE;
         
    parameter DATAIN2PRECHARGE = CLK_PERIOD + 14;
    defparam sdram_controller_u1.DATAIN2PRECHARGE = DATAIN2PRECHARGE;
         
    parameter LDMODEREG2ACTIVE = 2 * CLK_PERIOD;
    defparam sdram_controller_u1.LDMODEREG2ACTIVE = LDMODEREG2ACTIVE;
         
    parameter SELFREFRESH2ACTIVE_DELAY = CLK_PERIOD + 44;
    defparam sdram_controller_u1.SELFREFRESH2ACTIVE_DELAY = SELFREFRESH2ACTIVE_DELAY;
    
    parameter NUM_CLK_CL    = (MODEREG_CAS_LATENCY == SDRAM_CAS_LATENCY_2 ) ? 2 :
                              (MODEREG_CAS_LATENCY == SDRAM_CAS_LATENCY_3) ? 3 :
                              3;  // default, for CAS_LATENCY_3
    defparam sdram_controller_u1.NUM_CLK_CL = NUM_CLK_CL;

    parameter NUM_CLK_READ  = (MODEREG_BURST_LENGTH == SDRAM_BURST_LEN_1) ? 1 :
                              (MODEREG_BURST_LENGTH == SDRAM_BURST_LEN_2) ? 2 :
                              (MODEREG_BURST_LENGTH == SDRAM_BURST_LEN_4) ? 4 :
                              (MODEREG_BURST_LENGTH == SDRAM_BURST_LEN_8) ? 8 :
                              (MODEREG_BURST_LENGTH == SDRAM_BURST_PAGE) ? SDRAM_PAGE_LEN :
                              4; // default, for SDRAM_BURST_LEN_4
    defparam sdram_controller_u1.NUM_CLK_READ = NUM_CLK_READ;
   
    parameter NUM_CLK_WRITE  = (MODEREG_BURST_LENGTH == SDRAM_BURST_LEN_1) ? 1 :
                               (MODEREG_BURST_LENGTH == SDRAM_BURST_LEN_2) ? 2 :
                               (MODEREG_BURST_LENGTH == SDRAM_BURST_LEN_4) ? 4 :
                               (MODEREG_BURST_LENGTH == SDRAM_BURST_LEN_8) ? 8 :
                               (MODEREG_BURST_LENGTH == SDRAM_BURST_PAGE) ? SDRAM_PAGE_LEN :
                               4; // default, for SDRAM_BURST_LEN_4
    defparam sdram_controller_u1.NUM_CLK_WRITE = NUM_CLK_WRITE;
      
    parameter AUTO_REFRESH_COUNT = 1500;
    defparam sdram_controller_u1.AUTO_REFRESH_COUNT = AUTO_REFRESH_COUNT;
   
    parameter NUM_CLK_LOAD_MODEREG_DELAY = LOAD_MODEREG_DELAY/CLK_PERIOD;
    parameter NUM_CLK_PRECHARGE_PERIOD    = PRECHARE_PERIOD/CLK_PERIOD;
    parameter NUM_CLK_AUTOREFRESH_PERIOD = AUTOREFRESH_PERIOD/CLK_PERIOD;
    parameter NUM_CLK_ACTIVE2RW_DELAY    = ACTIVE2RW_DELAY/CLK_PERIOD;
    parameter NUM_CLK_DATAIN2ACTIVE      = DATAIN2ACTIVE/CLK_PERIOD;
    parameter NUM_CLK_DATAIN2PRECHARGE   = DATAIN2PRECHARGE/CLK_PERIOD;
    parameter NUM_CLK_LDMODEREG2ACTIVE   = LDMODEREG2ACTIVE/CLK_PERIOD;
    parameter NUM_CLK_SELFREFRESH2ACTIVE = SELFREFRESH2ACTIVE_DELAY/CLK_PERIOD;
    parameter NUM_CLK_WRITE_RECOVERY_DELAY   = WRITE_RECOVERY_DELAY/CLK_PERIOD;
    
    parameter NUM_CLK_WAIT = (NUM_CLK_DATAIN2ACTIVE < 3) ? 0 : NUM_CLK_DATAIN2ACTIVE - 3;    
    defparam sdram_controller_u1.NUM_CLK_WAIT = NUM_CLK_WAIT;

   endmodule
