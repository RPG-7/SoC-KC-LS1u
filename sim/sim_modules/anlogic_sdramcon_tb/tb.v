`include "../include/timescale.v"
`include "../include/timepara.v"
`include "../include/sdrCtrl_para.v"

module tb;

logic rst;
logic clk;

logic			    SDR_CKE;
logic			    SDR_CSN;
logic			    SDR_RASN;
logic			    SDR_CASN;
logic			    SDR_WEN;
logic[BANKADDR_WIDTH-1:0]   SDR_BA;
logic[SDRADDR_WIDTH-1:0]    SDR_A;
wire[SDRDATA_WIDTH-1:0]	    SDR_DQ;
logic[SDRDATA_WIDTH/8-1:0]  SDR_DQM;


wire		    		cmd;
wire			    cmd_valid;
wire[ROWADDR_WIDTH-1:0]	    rowAddr;
wire[BANKADDR_WIDTH-1:0]    bankAddr;
wire[COLADDR_WIDTH-1:0]	    colAddr;
wire[SDRDATA_WIDTH/8-1:0]   data_mask;
wire			    cmd_rdy;
wire			    data_rdy;
wire[4:0]		    burst_cnt;

wire[SDRDATA_WIDTH-1:0]	    read_data;
wire			    read_data_valid;
wire[SDRDATA_WIDTH-1:0]	    write_data;

//----------------------------------------


initial
begin
    
    rst =  1'b1;
    clk = 1'b0;

    #1000 rst = 1'b0;
    #60us $stop;

end

always
begin
    #5ns clk = ~clk;
end

//----------------------------------------

SDRAMStim SDRAMStim
(
    .rst	    (rst	    ),
    .clk	    (clk	    ),
                               
    .init_done	    (init_done	    ),
                                    
    .cmd	    (cmd	    ),
    .cmd_valid	    (cmd_valid	    ),
    .rowAddr	    (rowAddr	    ),
    .bankAddr	    (bankAddr	    ),
    .colAddr	    (colAddr	    ),
    .data_mask	    (data_mask	    ),
    .cmd_rdy	    (ack	    ),
    .data_rdy	    (data_rdy	    ),
                                    
    .read_data	    (read_data	    ),
    .read_data_valid(read_data_valid),
    .write_data	    (write_data	    ),
                                    
    .error	    (err	    )
);

wire				sdr_CSn;
wire				sdr_RASn;
wire				sdr_CASn;
wire				sdr_WEn;
wire				sdr_CKE;
wire[BANKADDR_WIDTH-1:0]  	sdr_BA;
wire[SDRADDR_WIDTH-1:0]   	sdr_A;
wire[SDRDATA_WIDTH/8-1:0] 	sdr_DQM;
wire[SDRDATA_WIDTH-1:0]		sdr_DQ;
wire 				sdr_CLK;

sdram_controller sdram_controller (/*AUTOARG*/
                         // Outputs
                        .o_data_valid		(read_data_valid), 
			.o_data_req		(data_rdy), 
			.o_busy			(busy), 
			.o_init_done		(init_done), 
			.o_ack			(ack), 
    
                        .o_sdram_addr		(SDR_A), 
			.o_sdram_blkaddr	(SDR_BA), 
			.o_sdram_casn		(SDR_CASN), 
			.o_sdram_cke		(SDR_CKE), 
                        .o_sdram_csn		(SDR_CSN), 
			.o_sdram_dqm		(SDR_DQM), 
			.o_sdram_rasn		(SDR_RASN), 
			.o_sdram_wen		(SDR_WEN), 
			.o_sdram_clk		(SDR_CLK),
                        .o_write_done		(), 
			.o_read_done		(),

                         // Inouts
                        .i_data			(write_data), 
                       	.o_data			(read_data),

                        .io_sdram_dq		(SDR_DQ),

                         // Inputs
                        .i_addr			({bankAddr, rowAddr, colAddr}), 
			.i_adv			(cmd_valid), 
			.i_clk			(clk), 
			.i_rst			(rst), 
			.i_rwn			(cmd), 
                        .i_selfrefresh_req	(1'b0), 
			.i_loadmod_req		(1'b0), 
			.i_burststop_req	(1'b0), 
			.i_disable_active	(1'b0), 
			.i_disable_precharge	(1'b0), 
			.i_precharge_req	(1'b0), 
			.i_power_down		(1'b0), 
			.i_disable_autorefresh	(1'b1)
);



mt48lc2m32b2 mt48lc2m32b2
(
    .Dq	    (SDR_DQ), 
    .Addr   ({1'b0, SDR_A}), 
    .Ba	    (SDR_BA), 
    .Clk    (SDR_CLK), 
    .Cke    (SDR_CKE), 
    .Cs_n   (SDR_CSN), 
    .Ras_n  (SDR_RASN), 
    .Cas_n  (SDR_CASN), 
    .We_n   (SDR_WEN),
    .Dqm    (4'b0000)
);

endmodule
