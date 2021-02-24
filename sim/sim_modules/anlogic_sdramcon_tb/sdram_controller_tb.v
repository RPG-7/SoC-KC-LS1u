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

`define SIM_ONLY 

module sdram_controller_tb ();
    
    
    

`include "sdram_defines.v"

    reg [26:0]                     i_addr_tb;
    reg                            i_adv_tb;
    reg                            i_rwn_tb;
    reg                            i_power_down_tb;
    reg                            i_disable_autorefresh_tb;
    
    reg [31:0]                     i_data_tb;
    reg                            i_selfrefresh_req_tb;
    wire                           i_clk_tb;
    reg                            i_rst_tb;
    reg                            i_loadmod_req_tb;
    reg                            i_burststop_req_tb;
    reg                            i_disable_active_tb;
    reg                            i_disable_precharge_tb;
    reg                            i_precharge_req_tb; 
    reg                            cpu_clk_tb_i;
   
    wire [31:0]                    io_sdram_dq_tb;   
    wire                           o_sdram_wen_tb;
    wire                           o_sdram_rasn_tb;
    wire [3:0]                     o_sdram_dqm_tb;
    wire                           o_sdram_csn_tb;
    wire                           o_sdram_cke_tb;
    wire                           o_sdram_casn_tb;
    wire [1:0]                     o_sdram_blkaddr_tb;
    wire [12:0]                    o_sdram_addr_tb;
    wire                           o_ack_tb;
    wire                           o_init_done_tb;
    wire                           o_busy_tb;
    wire                           o_data_valid_tb;
    wire                           o_sdram_clk_tb;
    wire                           o_data_req_tb;
    wire [31:0]                    o_data_tb;
    wire                           o_write_done;
    wire                           o_read_done;
         

    integer                        err_count_i;

`ifdef SIM_ONLY


    parameter SDRAM_BURST_LEN_1            = 3'b000;
    parameter SDRAM_BURST_LEN_2            = 3'b001;
    parameter SDRAM_BURST_LEN_4            = 3'b010;
    parameter SDRAM_BURST_LEN_8            = 3'b011;
    
    parameter SDRAM_BURST_PAGE             = 3'b111;
    defparam sdram_controller_tb_u1.SDRAM_BURST_PAGE = SDRAM_BURST_PAGE;

    parameter SDRAM_CAS_LATENCY_2          = 3'b010;
    parameter SDRAM_CAS_LATENCY_3          = 3'b011;

    parameter SDRAM_DATA_WIDTH = 32;
    defparam sdram_controller_tb_u1.SDRAM_DATA_WIDTH = SDRAM_DATA_WIDTH;

    parameter CPU_ADDR_WIDTH = 22;
    defparam sdram_controller_tb_u1.CPU_ADDR_WIDTH = CPU_ADDR_WIDTH;

    parameter SDRAM_ADDR_WIDTH = 12;
    defparam sdram_controller_tb_u1.SDRAM_ADDR_WIDTH = SDRAM_ADDR_WIDTH;

    parameter SDRAM_BLKADR_WIDTH = 2;
    defparam sdram_controller_tb_u1.SDRAM_BLKADR_WIDTH = SDRAM_BLKADR_WIDTH;

    parameter SDRAM_DQM_WIDTH = 4;
    defparam sdram_controller_tb_u1.SDRAM_DQM_WIDTH = SDRAM_DQM_WIDTH;

    parameter ROWADDR_MSB = 21;
    defparam sdram_controller_tb_u1.ROWADDR_MSB = ROWADDR_MSB;
   
    parameter ROWADDR_LSB = 10;
    defparam sdram_controller_tb_u1.ROWADDR_LSB = ROWADDR_LSB;

    parameter MODEREG_CAS_LATENCY = 2;
    defparam sdram_controller_tb_u1.MODEREG_CAS_LATENCY = MODEREG_CAS_LATENCY;

    parameter MODEREG_BURST_LENGTH = 3'b000;
    defparam sdram_controller_tb_u1.MODEREG_BURST_LENGTH = MODEREG_BURST_LENGTH;

    parameter MODEREG_BURST_TYPE = 1'b0;
    defparam sdram_controller_tb_u1.MODEREG_BURST_TYPE = MODEREG_BURST_TYPE;
   
    parameter MODEREG_OPERATION_MODE = 2'b00;
    defparam sdram_controller_tb_u1.MODEREG_OPERATION_MODE = MODEREG_OPERATION_MODE;

    parameter MODEREG_WRITE_BURST_MODE = 1'b0;
    defparam sdram_controller_tb_u1.MODEREG_WRITE_BURST_MODE = MODEREG_WRITE_BURST_MODE;
   
    parameter SDRAM_PAGE_LEN = 256;
    defparam sdram_controller_tb_u1.SDRAM_PAGE_LEN = SDRAM_PAGE_LEN;
   
    parameter CLK_PERIOD            = 10;
    defparam sdram_controller_tb_u1.CLK_PERIOD = CLK_PERIOD;

    parameter LOAD_MODEREG_DELAY = 2*CLK_PERIOD;
    defparam sdram_controller_tb_u1.LOAD_MODEREG_DELAY = LOAD_MODEREG_DELAY;

    parameter PRECHARE_PERIOD = CLK_PERIOD + 8;
    defparam sdram_controller_tb_u1.PRECHARE_PERIOD = PRECHARE_PERIOD;

    parameter AUTOREFRESH_PERIOD = CLK_PERIOD + 50;
    defparam sdram_controller_tb_u1.AUTOREFRESH_PERIOD = AUTOREFRESH_PERIOD;
         
    parameter ACTIVE2RW_DELAY = CLK_PERIOD * 2;
    defparam sdram_controller_tb_u1.ACTIVE2RW_DELAY = ACTIVE2RW_DELAY;
         
    parameter WRITE_RECOVERY_DELAY = CLK_PERIOD/2 + CLK_PERIOD + 2;
    defparam sdram_controller_tb_u1.WRITE_RECOVERY_DELAY = WRITE_RECOVERY_DELAY;
         
    parameter DATAIN2ACTIVE = 5 * CLK_PERIOD;
    defparam sdram_controller_tb_u1.DATAIN2ACTIVE = DATAIN2ACTIVE;
         
    parameter DATAIN2PRECHARGE = 2 * CLK_PERIOD;
    defparam sdram_controller_tb_u1.DATAIN2PRECHARGE = DATAIN2PRECHARGE;
         
    parameter LDMODEREG2ACTIVE = 2 * CLK_PERIOD;
    defparam sdram_controller_tb_u1.LDMODEREG2ACTIVE = LDMODEREG2ACTIVE;
         
    parameter SELFREFRESH2ACTIVE_DELAY = 4 * CLK_PERIOD + 2;
    defparam sdram_controller_tb_u1.SELFREFRESH2ACTIVE_DELAY = SELFREFRESH2ACTIVE_DELAY;
    
    parameter NUM_CLK_CL    = (MODEREG_CAS_LATENCY == SDRAM_CAS_LATENCY_2 ) ? 2 :
                              (MODEREG_CAS_LATENCY == SDRAM_CAS_LATENCY_3) ? 3 :
                              3;  // default, for CAS_LATENCY_3
    defparam sdram_controller_tb_u1.NUM_CLK_CL = NUM_CLK_CL;

    parameter NUM_CLK_READ  = (MODEREG_BURST_LENGTH == SDRAM_BURST_LEN_1) ? 1 :
                              (MODEREG_BURST_LENGTH == SDRAM_BURST_LEN_2) ? 2 :
                              (MODEREG_BURST_LENGTH == SDRAM_BURST_LEN_4) ? 4 :
                              (MODEREG_BURST_LENGTH == SDRAM_BURST_LEN_8) ? 8 :
                              (MODEREG_BURST_LENGTH == SDRAM_BURST_PAGE) ? SDRAM_PAGE_LEN :
                              4; // default, for SDRAM_BURST_LEN_4
    defparam sdram_controller_tb_u1.NUM_CLK_READ = NUM_CLK_READ;
   
    parameter NUM_CLK_WRITE  = (MODEREG_BURST_LENGTH == SDRAM_BURST_LEN_1) ? 1 :
                               (MODEREG_BURST_LENGTH == SDRAM_BURST_LEN_2) ? 2 :
                               (MODEREG_BURST_LENGTH == SDRAM_BURST_LEN_4) ? 4 :
                               (MODEREG_BURST_LENGTH == SDRAM_BURST_LEN_8) ? 8 :
                               (MODEREG_BURST_LENGTH == SDRAM_BURST_PAGE) ? SDRAM_PAGE_LEN :
                               4; // default, for SDRAM_BURST_LEN_4
    defparam sdram_controller_tb_u1.NUM_CLK_WRITE = NUM_CLK_WRITE;
      
    parameter AUTO_REFRESH_COUNT = 1500;
    defparam sdram_controller_tb_u1.AUTO_REFRESH_COUNT = AUTO_REFRESH_COUNT;
   
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
    defparam sdram_controller_tb_u1.NUM_CLK_WAIT = NUM_CLK_WAIT;

   
    sdram_controller_wrapper sdram_controller_tb_u1
        (
         .i_rst(i_rst_tb), 
         .i_clk(i_clk_tb),
         .i_selfrefresh_req(i_selfrefresh_req_tb),
         .i_loadmod_req(i_loadmod_req_tb),
         .i_burststop_req(i_burststop_req_tb),
         .i_disable_active(i_disable_active_tb),
         .i_disable_precharge(i_disable_precharge_tb),
         .i_precharge_req(i_precharge_req_tb),
         .i_rwn(i_rwn_tb),
         .i_adv(i_adv_tb),
         .i_addr(i_addr_tb),
         .i_power_down(i_power_down_tb),
         .i_disable_autorefresh(i_disable_autorefresh_tb),
         .io_sdram_dq(io_sdram_dq_tb),
         .i_data(i_data_tb),
         .o_data(o_data_tb),
         .o_sdram_wen(o_sdram_wen_tb),
         .o_sdram_rasn(o_sdram_rasn_tb),
         .o_sdram_dqm(o_sdram_dqm_tb),
         .o_sdram_csn(o_sdram_csn_tb),
         .o_sdram_cke(o_sdram_cke_tb),
         .o_sdram_casn(o_sdram_casn_tb),
         .o_sdram_blkaddr(o_sdram_blkaddr_tb),
         .o_sdram_addr(o_sdram_addr_tb),
         .o_ack(o_ack_tb),
         .o_init_done(o_init_done_tb),
         .o_busy(o_busy_tb),
         .o_data_valid(o_data_valid_tb),
         .o_sdram_clk(o_sdram_clk_tb),
         .o_data_req(o_data_req_tb),
         .o_write_done(o_write_done),
         .o_read_done(o_read_done)
         );   


    `else // !`ifdef SIM_ONLY
   
    parameter SDRAM_BURST_LEN_1            = 3'b000;
    parameter SDRAM_BURST_LEN_2            = 3'b001;
    parameter SDRAM_BURST_LEN_4            = 3'b010;
    parameter SDRAM_BURST_LEN_8            = 3'b011;
    
    parameter SDRAM_BURST_PAGE             = 3'b111;
    
    parameter SDRAM_CAS_LATENCY_2          = 3'b010;
    parameter SDRAM_CAS_LATENCY_3          = 3'b011;

    parameter SDRAM_DATA_WIDTH = 32;
    
    parameter CPU_ADDR_WIDTH = 22;
    
    parameter SDRAM_ADDR_WIDTH = 12;
    
    parameter SDRAM_BLKADR_WIDTH = 2;
    
    parameter SDRAM_DQM_WIDTH = 4;
    
    parameter ROWADDR_MSB = 21;
       
    parameter ROWADDR_LSB = 10;
    
    parameter MODEREG_CAS_LATENCY = 2;
    
    parameter MODEREG_BURST_LENGTH = 3'b000;
    
    parameter MODEREG_BURST_TYPE = 1'b0;
       
    parameter MODEREG_OPERATION_MODE = 2'b00;
    
    parameter MODEREG_WRITE_BURST_MODE = 1'b0;
       
    parameter SDRAM_PAGE_LEN = 256;
       
    parameter CLK_PERIOD            = 10;
    
    parameter LOAD_MODEREG_DELAY = 2*CLK_PERIOD;
    
    parameter PRECHARE_PERIOD = CLK_PERIOD + 8;
    
    parameter AUTOREFRESH_PERIOD = CLK_PERIOD + 50;
             
    parameter ACTIVE2RW_DELAY = CLK_PERIOD * 2;
             
    parameter WRITE_RECOVERY_DELAY = CLK_PERIOD/2 + CLK_PERIOD + 2;
             
    parameter DATAIN2ACTIVE = 5 * CLK_PERIOD;
             
    parameter DATAIN2PRECHARGE = 2 * CLK_PERIOD;
             
    parameter LDMODEREG2ACTIVE = 2 * CLK_PERIOD;
             
    parameter SELFREFRESH2ACTIVE_DELAY = 4 * CLK_PERIOD + 2;
        
    parameter NUM_CLK_CL    = (MODEREG_CAS_LATENCY == SDRAM_CAS_LATENCY_2 ) ? 2 :
                              (MODEREG_CAS_LATENCY == SDRAM_CAS_LATENCY_3) ? 3 :
                              3;  // default, for CAS_LATENCY_3
    
    parameter NUM_CLK_READ  = (MODEREG_BURST_LENGTH == SDRAM_BURST_LEN_1) ? 1 :
                              (MODEREG_BURST_LENGTH == SDRAM_BURST_LEN_2) ? 2 :
                              (MODEREG_BURST_LENGTH == SDRAM_BURST_LEN_4) ? 4 :
                              (MODEREG_BURST_LENGTH == SDRAM_BURST_LEN_8) ? 8 :
                              (MODEREG_BURST_LENGTH == SDRAM_BURST_PAGE) ? SDRAM_PAGE_LEN :
                              4; // default, for SDRAM_BURST_LEN_4
       
    parameter NUM_CLK_WRITE  = (MODEREG_BURST_LENGTH == SDRAM_BURST_LEN_1) ? 1 :
                               (MODEREG_BURST_LENGTH == SDRAM_BURST_LEN_2) ? 2 :
                               (MODEREG_BURST_LENGTH == SDRAM_BURST_LEN_4) ? 4 :
                               (MODEREG_BURST_LENGTH == SDRAM_BURST_LEN_8) ? 8 :
                               (MODEREG_BURST_LENGTH == SDRAM_BURST_PAGE) ? SDRAM_PAGE_LEN :
                               4; // default, for SDRAM_BURST_LEN_4
          
    parameter AUTO_REFRESH_COUNT = 1500;
       
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
    
   
    sdram_controller_wrapper sdram_controller_tb_u1
        (
         .i_rst(i_rst_tb), 
         .i_clk(i_clk_tb),
         .i_selfrefresh_req(i_selfrefresh_req_tb),
         .i_loadmod_req(i_loadmod_req_tb),
         .i_burststop_req(i_burststop_req_tb),
         .i_disable_active(i_disable_active_tb),
         .i_disable_precharge(i_disable_precharge_tb),
         .i_precharge_req(i_precharge_req_tb),
         .i_rwn(i_rwn_tb),
         .i_adv(i_adv_tb),
         .i_addr(i_addr_tb),
         .i_power_down(i_power_down_tb),
         .i_disable_autorefresh(i_disable_autorefresh_tb),
         .io_sdram_dq(io_sdram_dq_tb),
         .i_data(i_data_tb),
         .o_data(o_data_tb),
         .o_sdram_wen(o_sdram_wen_tb),
         .o_sdram_rasn(o_sdram_rasn_tb),
         .o_sdram_dqm(o_sdram_dqm_tb),
         .o_sdram_csn(o_sdram_csn_tb),
         .o_sdram_cke(o_sdram_cke_tb),
         .o_sdram_casn(o_sdram_casn_tb),
         .o_sdram_blkaddr(o_sdram_blkaddr_tb),
         .o_sdram_addr(o_sdram_addr_tb),
         .o_ack(o_ack_tb),
         .o_init_done(o_init_done_tb),
         .o_busy(o_busy_tb),
         .o_data_valid(o_data_valid_tb),
         .o_sdram_clk(o_sdram_clk_tb),
         .o_data_req(o_data_req_tb),
         .o_write_done(o_write_done),
         .o_read_done(o_read_done)
         );

       
    `endif // !`ifdef SIM_ONLY


     mt48lc4m32b2 sim_model_u2
     ( io_sdram_dq_tb[31:0], o_sdram_addr_tb[11:0], o_sdram_blkaddr_tb[1:0], 
     o_sdram_clk_tb, o_sdram_cke_tb, o_sdram_csn_tb,
     o_sdram_rasn_tb, o_sdram_casn_tb, o_sdram_wen_tb, o_sdram_dqm_tb[3:0]);
    

    task burst_write;
        input [26:0] addr;
        input [31:0] start_value;
        integer                     write_cycles;
        integer                     total_cycles;
        begin
            i_addr_tb = addr;
            i_adv_tb = 1;
            i_rwn_tb = 0;
            i_burststop_req_tb = 0;
            write_cycles = 0;
            total_cycles = NUM_CLK_ACTIVE2RW_DELAY + NUM_CLK_WRITE + 3;
            for (write_cycles = 0; write_cycles <= total_cycles; 
                 write_cycles = write_cycles + 1) begin
                @(posedge i_clk_tb);
                if (write_cycles == NUM_CLK_ACTIVE2RW_DELAY)
                    i_data_tb = start_value;
                if (write_cycles >  NUM_CLK_ACTIVE2RW_DELAY)
                    i_data_tb = i_data_tb + 1'b1;
                if (write_cycles == NUM_CLK_ACTIVE2RW_DELAY + 3) begin
                    i_adv_tb = 0;
                    i_rwn_tb = 1;
                    i_addr_tb = {27'b1{1'b1}};
                end
                if (MODEREG_BURST_LENGTH == SDRAM_BURST_PAGE) 
                    if (write_cycles == NUM_CLK_ACTIVE2RW_DELAY + NUM_CLK_WRITE) begin
                        i_burststop_req_tb = 1;
                    end
            end
            @(posedge i_clk_tb);
            if (MODEREG_BURST_LENGTH == SDRAM_BURST_PAGE) 
                i_burststop_req_tb = 0;
        end 
    endtask // burst_write
    
    
   task burst_write_new;
        input [26:0] addr;
        input [31:0] start_value;
        integer                     write_cycles;
        integer                     total_cycles;
        integer                     i;
        begin
            i_addr_tb = addr;
            i_adv_tb = 1;
            i_rwn_tb = 0;
            i_burststop_req_tb = 0;
            write_cycles = 0;
            total_cycles = NUM_CLK_ACTIVE2RW_DELAY + NUM_CLK_WRITE + 3;
            @(posedge o_data_req_tb);
            @(posedge i_clk_tb);
            @(posedge i_clk_tb);
            i_data_tb = #1 start_value; 
            for (write_cycles = 0; write_cycles <= total_cycles; write_cycles = write_cycles + 1) begin
                @(posedge i_clk_tb);
                    i_data_tb = #1 i_data_tb + 1'b1;
                if (write_cycles == NUM_CLK_ACTIVE2RW_DELAY ) begin
                    i_adv_tb = 0;
                    i_rwn_tb = 1;
                    i_addr_tb = {27'b1{1'b1}};
                end
                if (MODEREG_BURST_LENGTH == SDRAM_BURST_PAGE) 
                    if (write_cycles == NUM_CLK_ACTIVE2RW_DELAY + NUM_CLK_WRITE -5) begin
                        i_burststop_req_tb = 1;
                    end
            end // for (write_cycles = 0; write_cycles <= total_cycles;...
            @(posedge i_clk_tb);
            if (MODEREG_BURST_LENGTH == SDRAM_BURST_PAGE) 
                i_burststop_req_tb = 0;
        end 
    endtask // burst_write_new

   

    task    burst_read; 
        input   [26:0]          addr; 
        input [31:0]           start_value; 
        reg [31:0]             data; 
        integer                                read_cycles; 
        integer                                total_cycles;
        begin 
            i_addr_tb = addr;
            i_adv_tb = 1;
            i_rwn_tb = 1;
            i_burststop_req_tb = 0;
            total_cycles = NUM_CLK_ACTIVE2RW_DELAY + NUM_CLK_READ + 3 + MODEREG_CAS_LATENCY;
            for (read_cycles = 0; read_cycles <= total_cycles -1; read_cycles = read_cycles + 1) begin
                @(posedge i_clk_tb);
                if (read_cycles == NUM_CLK_ACTIVE2RW_DELAY + MODEREG_CAS_LATENCY + 4)
                    data = start_value;
                if (read_cycles > (NUM_CLK_ACTIVE2RW_DELAY + MODEREG_CAS_LATENCY + 4))
                    data = data + 1'b1;
                if ((data !== o_data_tb)  && 
                    (read_cycles >= NUM_CLK_ACTIVE2RW_DELAY + MODEREG_CAS_LATENCY+ 4)) begin 
                    $display("Read error at %h read %h expected %h", 
                             (addr + read_cycles - 1), o_data_tb, data);
                    err_count_i = err_count_i + 1;
                end
                if (read_cycles == (NUM_CLK_ACTIVE2RW_DELAY + 3 + MODEREG_CAS_LATENCY)) begin
                    i_adv_tb = 0;
                    i_rwn_tb = 1;
                    i_addr_tb = {27'b1{1'b1}};
                end
                if (MODEREG_BURST_LENGTH == SDRAM_BURST_PAGE) 
                    if (read_cycles == (NUM_CLK_ACTIVE2RW_DELAY + NUM_CLK_READ)) 
                        i_burststop_req_tb = 1;
            end
            @(posedge i_clk_tb);
            if (MODEREG_BURST_LENGTH == SDRAM_BURST_PAGE) 
                i_burststop_req_tb = 0;
        end 
    endtask 
    
    
    task load_mode_reg;
        begin
            i_adv_tb = #WIREDLY 0;
            i_rwn_tb = #WIREDLY 1;
            i_adv_tb = #WIREDLY 0;
            i_addr_tb = #WIREDLY {27'b1{1'b1}};
            @(posedge i_clk_tb);
            @(posedge i_clk_tb);
            i_adv_tb = #WIREDLY 1;
            i_rwn_tb = #WIREDLY 1;
            i_precharge_req_tb = #WIREDLY 1'b1; //Precharge request before LOAD MODE REG
            i_adv_tb = #WIREDLY 1;
            @(posedge o_ack_tb);
            i_adv_tb = #WIREDLY 0;
            i_precharge_req_tb = #WIREDLY 1'b0;
            @(posedge i_clk_tb);
            @(posedge i_clk_tb);
            i_loadmod_req_tb = #WIREDLY 1'b1; //LOAD MODE REG request
            i_adv_tb = #WIREDLY 1;
            i_addr_tb[9:0] = {MODEREG_WRITE_BURST_MODE, 
                                  MODEREG_OPERATION_MODE, 
                                  MODEREG_CAS_LATENCY, 
                                  MODEREG_BURST_TYPE, 
                                  MODEREG_BURST_LENGTH};
            @(posedge o_ack_tb);
            i_adv_tb = #WIREDLY 0;
            i_loadmod_req_tb = #WIREDLY 1'b0;
            @(posedge i_clk_tb);
        end
    endtask // load_mode_reg


    //////////////////////////////////////////////////////////////////////////////////////////////////

      task burst_write_disable_active;
        input [26:0] addr;
        input [31:0] start_value;
        integer                     write_cycles;
        integer                     total_cycles;
        begin
            i_addr_tb = addr;
            i_data_tb = start_value;
            i_adv_tb = 1;
            i_rwn_tb = 0;
            i_burststop_req_tb = 0;
            write_cycles = 0;
            total_cycles = NUM_CLK_ACTIVE2RW_DELAY + NUM_CLK_WRITE + 3;
            for (write_cycles = 0; write_cycles <= total_cycles; 
                 write_cycles = write_cycles + 1) begin
                @(posedge i_clk_tb);
                    i_data_tb = i_data_tb + 1'b1;
                if (write_cycles == NUM_CLK_ACTIVE2RW_DELAY + 2) begin
                    i_adv_tb = 0;
                    i_rwn_tb = 1;
                    i_addr_tb = {27'b1{1'b1}};
                end
                if (MODEREG_BURST_LENGTH == SDRAM_BURST_PAGE) 
                    if (write_cycles == NUM_CLK_ACTIVE2RW_DELAY + NUM_CLK_WRITE) begin
                        i_burststop_req_tb = 1;
                    end
            end
            @(posedge i_clk_tb);
            if (MODEREG_BURST_LENGTH == SDRAM_BURST_PAGE) 
                i_burststop_req_tb = 0;
        end 
    endtask // burst_write



   task burst_write_disable_active_new;
        input [26:0]  addr;
        input [31:0] start_value;
        integer                     write_cycles;
        integer                     total_cycles;
        integer                       i;
        begin
            i_addr_tb = addr;
            //i_data_tb = start_value;
            i_adv_tb = 1;
            i_rwn_tb = 0;
            i_burststop_req_tb = 0;
            write_cycles = 0;
            total_cycles = NUM_CLK_ACTIVE2RW_DELAY + NUM_CLK_WRITE + 3;
            @(posedge o_data_req_tb);
            @(posedge i_clk_tb);
            @(posedge i_clk_tb);
            i_data_tb = #1 start_value;
                for (write_cycles = 0; write_cycles <= total_cycles; write_cycles = write_cycles + 1) begin
                    @(posedge i_clk_tb);
                    i_data_tb = #1 i_data_tb + 1'b1;
                if (write_cycles == NUM_CLK_ACTIVE2RW_DELAY ) begin
                    i_adv_tb = 0;
                    i_rwn_tb = 1;
                    i_addr_tb = {27'b1{1'b1}};
                end
                if (MODEREG_BURST_LENGTH == SDRAM_BURST_PAGE) 
                    if (write_cycles == NUM_CLK_ACTIVE2RW_DELAY + NUM_CLK_WRITE) begin
                        i_burststop_req_tb = 1;
                    end
            end
            @(posedge i_clk_tb);
            if (MODEREG_BURST_LENGTH == SDRAM_BURST_PAGE) 
                i_burststop_req_tb = 0;
        end 
    endtask // burst_write_disable_active_new

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    task    burst_read_disable_active; 
        input   [26:0]         addr; 
        input [31:0]           start_value; 
        reg [31:0]             data; 
        integer                                read_cycles; 
        integer                                total_cycles;
        begin 
            i_addr_tb = addr;
            i_adv_tb = 1;
            i_rwn_tb = 1;
            i_burststop_req_tb = 0;
            data = start_value;
            total_cycles = NUM_CLK_ACTIVE2RW_DELAY + NUM_CLK_READ + 3 + MODEREG_CAS_LATENCY;
            for (read_cycles = 0; read_cycles <= total_cycles -4; read_cycles = read_cycles + 1) begin
                @(posedge i_clk_tb);
                if (read_cycles ==  MODEREG_CAS_LATENCY + 4)
                    data = start_value;
                if (read_cycles > ( MODEREG_CAS_LATENCY + 2))
                    data = data + 1'b1;
                if (read_cycles == ( 2 + MODEREG_CAS_LATENCY)) begin
                    i_adv_tb = 0;
                    i_rwn_tb = 1;
                    i_addr_tb = {27'b1{1'b1}};
                end
                if (MODEREG_BURST_LENGTH == SDRAM_BURST_PAGE) 
                    if (read_cycles == (  NUM_CLK_READ)) 
                        i_burststop_req_tb = 1;
            end
            @(posedge i_clk_tb);
            if (MODEREG_BURST_LENGTH == SDRAM_BURST_PAGE) 
                i_burststop_req_tb = 0;
        end 
    endtask 

    
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
     
    initial begin
        err_count_i = 0;
        cpu_clk_tb_i = 0; 
        i_rst_tb = 1;                                          
        i_adv_tb = 1'b0;
        i_rwn_tb = 1'b1;
        i_selfrefresh_req_tb = 1'b0;
        i_loadmod_req_tb = 1'b0;
        i_burststop_req_tb = 1'b0;
        i_disable_active_tb = 1'b0;
        i_disable_precharge_tb = 1'b0;
        i_power_down_tb = 1'b0;
        i_disable_autorefresh_tb = 1'b0;
        i_precharge_req_tb = 1'b0;
        i_data_tb = {32'b1{1'b1}}; 
        i_addr_tb = {27'b1{1'b1}};
        #(10 * CLK_PERIOD + WIREDLY) i_rst_tb = 0; 
        @(posedge o_init_done_tb);
        load_mode_reg; //Load Mode register for SDRAM configuration

        $display("Initialization is completed", $time);
       
       
        @(negedge o_busy_tb);
        burst_write_new(8192, 0);

           
       
        $display("Writing is completed", $time);

        @(negedge o_busy_tb);
        burst_read(8192, 0);

       
       
        
       
        $display("Reading is completed", $time);

        @(negedge o_busy_tb);
        burst_write_new(32768, 256);

       
        @(negedge o_busy_tb);
        burst_write_new(65536, 512);

        
       
        @(negedge o_busy_tb);
        burst_read(32768, 256);

  
       
        @(negedge o_busy_tb);
        burst_read(65536, 512);
       
        
       
        @(negedge o_busy_tb);
        burst_read(65536, 512);

        //$stop; 
        

        ////////////////////////////////////////////////////////////////////////////////////////
        // Writing with out precharge


        i_disable_precharge_tb = 1;      // Open a row but,DO NOT precharge
        
       
        @(negedge o_busy_tb);
        burst_write_new(22'b0000000000001100000000,5);  // Write data

       
       
        i_disable_active_tb = 1;               // DO NOT open same row
       
        
       
        @(negedge o_busy_tb);
        burst_read_disable_active(22'b0000000000001100000000,0);
       
        
       
        burst_write_disable_active_new(22'b0000000000001100010000,3);    // Write data
       

       
       
        i_disable_active_tb = 1;               // DO NOT open same row
        #(2 * CLK_PERIOD + WIREDLY);
       
        #(2 * CLK_PERIOD + WIREDLY);
        burst_read_disable_active(22'b0000000000001100010000,10);
        #(2 * CLK_PERIOD + WIREDLY);

 
        i_disable_precharge_tb = 0;           // Close that row after data write
        #(2 * CLK_PERIOD + WIREDLY);

        i_disable_active_tb = 1;   
       

        @(negedge o_busy_tb);
        burst_write_disable_active(22'b0000000000001110000000,20);     // Write data

        #(2 * CLK_PERIOD + WIREDLY);
       

        #(2 * CLK_PERIOD + WIREDLY);
        i_disable_active_tb = 0;     


        #(2 * CLK_PERIOD + WIREDLY);


        ////////////////////////////////////////////////////////////////////////////////////////
        // Loading Mode Register after initialization by using i_loadmod_req_tb

        $display("Loading Mode Register", $time);

        i_adv_tb = #WIREDLY 0;
        i_rwn_tb = #WIREDLY 1;
        i_addr_tb = #WIREDLY {27'b1{1'b1}};
        @(posedge i_clk_tb);
        @(posedge i_clk_tb);
        i_adv_tb = #WIREDLY 1;
        i_rwn_tb = #WIREDLY 1;
        i_precharge_req_tb = #WIREDLY 1'b1; //Precharge request before LOAD MODE REG
        i_adv_tb = #WIREDLY 1;
        @(posedge o_ack_tb);
        i_adv_tb = #WIREDLY 0;
        i_precharge_req_tb = #WIREDLY 1'b0;
        @(posedge i_clk_tb);
        @(posedge i_clk_tb);
        i_loadmod_req_tb = #WIREDLY 1'b1; //LOAD MODE REG request
        i_adv_tb = #WIREDLY 1;
        i_addr_tb[9:0] = {MODEREG_WRITE_BURST_MODE, 
                              MODEREG_OPERATION_MODE, 
                              MODEREG_CAS_LATENCY, 
                              MODEREG_BURST_TYPE, 
                              SDRAM_BURST_LEN_4};
        @(posedge o_ack_tb);
        i_adv_tb = #WIREDLY 0;
        i_loadmod_req_tb = #WIREDLY 1'b0;
        @(posedge i_clk_tb);

        @(posedge i_clk_tb);
        @(posedge i_clk_tb);
         

        ////////////////////////////////////////////////////////////////////////////////////////
        // Self refresh
       
        @(posedge i_clk_tb);
        i_selfrefresh_req_tb <= 1'b1;
        @(posedge i_clk_tb);
        i_selfrefresh_req_tb <= 1'b0;
        #(8 * CLK_PERIOD + WIREDLY);


        ////////////////////////////////////////////////////////////////////////////////////////
        // Power Down Mode

        @(posedge i_clk_tb);
        i_power_down_tb <= 1'b1;
        @(posedge i_clk_tb);
        @(posedge i_clk_tb);
        @(posedge i_clk_tb);
        i_power_down_tb <= 1'b0;
        #(4 * CLK_PERIOD + WIREDLY);

        ////////////////////////////////////////////////////////////////////////////////////////
        // Disable Auto refresh

        @(posedge i_clk_tb);
        i_disable_autorefresh_tb = 1'b1;
        #(14 * CLK_PERIOD + WIREDLY);
       

        ////////////////////////////////////////////////////////////////////////////////////////
        // Enable Auto refresh

        @(posedge i_clk_tb);
        i_disable_autorefresh_tb = 1'b0;
        #(14 * CLK_PERIOD + WIREDLY);


       
        if (err_count_i == 0)
            $display("Set Pass");
        else
            $display("Set Fail") ;
      
 

        /////////////////////////////////////////////////////////////////////////////////////////

       
    end 
    
    // CLK_PERIOD defined in the pamaters file
    always
        #(CLK_PERIOD/2) cpu_clk_tb_i <= ~cpu_clk_tb_i;


   assign i_clk_tb = ~cpu_clk_tb_i;
   
endmodule


   
   