//Generic Embbeded SDRAM Controller 
//for Anlogic's SIP or Any On-board SDRAM
//Expects to have bus clock domain 
//? maybe fast SDRAM needs a refill domain
//? for Anlogic 32b SIP SDRAM, a dRAM/BRAM buffer is needed
//SDRAM run as fast as we could (Constrain 220M+,reality 133M+)
`define ANLOGIC_SIP_SDRAM
`define MSR_PRESET {2'b00,1'b0,`CAS_DLYSET,1'b0,`BURST_LENSET}
`define BURST_LENSET 3'b011 //burst len=8
`define CAS_DLYSET 3'b011 //CAS delay=3 CLK
module sdram_controller
#(
    parameter   CTRLTYPE="MINIMUM",//"MINIMUM"/"HIPERF"
                SDRAM_DBUSWIDTH=32,
                SDRAM_ABUSWIDTH=11,
                SDRAM_ROWWID=11,
                SDRAM_COLWID=8,
                SDRAM_BNKWID=2,
                INTERNAL_DBUSWIDTH=8,
                //Minimum 2K for 32b SDRAM (2xB9K or 1xB18K in Gowin)
                BURST_BUFSIZE=4096,
                ENABLE_CKE=1'b0
)
(
    input sys_clk,rst,sdram_clk,
    //ahb 接口
    input hclk,
    input hreset_n,
    input hsel,
    input hsel_cmd,
    input htrans,
    input hburst,
    input hwrite,
    input [ADDR_WIDTH-1:0]haddr,	
    input [7:0]hwdata,
    output [7:0]hrdata,
    output hresp,
    output hready
    //SDRAM接口
    `ifndef ANLOGIC_SIP_SDRAM
    ,output SD_CLK, // SDRAM 时钟 1bit 位宽
    output SD_RAS_N, // SDRAM 行选通 1bit 位宽
    output SD_CAN_N, //SDRAM 列选通 1bit 位宽
    output SD_WE_N, //SDRAM 写使能 1bit 位宽
    output [SDRAM_ABUSWIDTH-1:0]SD_SA, //SDRAM 地址 11bits 位宽
    output [SDRAM_BNKWID-1:0]SD_BA, // SDRAM BANK 地址 2bits 位宽
    output [SDRAM_DMWIDTH-1:0]SD_DM, //SDRAM 数据屏蔽 1bit 位宽
    output [SDRAM_DBUSWIDTH-1:0]SD_DQo, //SDRAM 数据 32bits 位宽
    input  [SDRAM_DBUSWIDTH-1:0]SD_DQi
    `endif

);
localparam SDRAM_DMWIDTH=SDRAM_DBUSWIDTH/8;
localparam BUS_ADRWID = SDRAM_BNKWID+SDRAM_ROWWID+SDRAM_COLWID+$clog2(SDRAM_DBUSWIDTH/INTERNAL_DBUSWIDTH);
`ifdef ANLOGIC_SIP_SDRAM
    wire SD_CLK,SD_RAS_N,SD_CAN_N,SD_WE_N; 
    wire [10:0]SD_SA;
    wire [1:0]SD_BA;
    wire [31:0]SD_DQo,SD_DQi,SD_DQ;
    assign SD_DQ=(SD_WE_N)?32'hzzzzzzzz:SD_DQo;
    assign SD_DQi=SD_DQ;
    AL_PHY_SDRAM_2M_32 ON_CHIP_SDRAM
    (
        .clk(SD_CLK), // SDRAM 时钟 1bit 位宽
        .ras_n(SD_RAS_N), // SDRAM 行选通 1bit 位宽
        .cas_n(SD_CAN_N), //SDRAM 列选通 1bit 位宽
        .we_n(SD_WE_N), //SDRAM 写使能 1bit 位宽
        .addr(SD_SA), //SDRAM 地址 11bits 位宽
        .ba(SD_BA), // SDRAM BANK 地址 2bits 位宽
        .dq(SD_DQ), //SDRAM 数据 32bits 位宽
        .dm(1’b0) //SDRAM 数据屏蔽 1bit 位宽
    );
`endif 
/*********************Controller FSM Start****************************/
localparam FSM_INIT=4'h0;
localparam FSM_IDLE=4'h1;
localparam FSM_PCHG=4'h2;
localparam FSM_RACT=4'h3;
localparam FSM_SIGR=4'h4;
localparam FSM_SIGW=4'h5;
localparam FSM_BLKR=4'h6;
localparam FSM_BLKW=4'h7;
localparam CMD_DABL=5'h1F;
localparam CMD_IDLE=5'h17;
localparam = ;
reg init_finish;
reg [4:0]sdram_cmd;//A10,CS#,RAS#,CAS#,WE#
//reg [7:0]sdram_msrl;//SDRAM MSR
//reg [1:0]sdram_msrh;

reg [11:0]sdrside_addr,sysside_addr;
reg sdrside_bufwe,sdrside_bufce;
reg sdramc_rst;

/*********************Controller FSM End****************************/
//SYS-SDRAM xclk handshake

always@(posedge sdram_clk)//reset xclk
begin
    sdramc_rst<=rst;
end

/*************************Sysbus START*****************************/



/*************************Sysbus End*****************************/
//defparam SDR_BUFFER.BUF_TYPE=(CTRLTYPE=="MINIMUM")?"LUTRAM":"BRAM";
defparam SDR_BUFFER.BUF_TYPE="BRAM";//LUTRAM buffer is not yet finished
sdram_buffer SDR_BUFFER
(
    .sys_clk(sys_clk),
    .sys_rst(rst),
    .sys_addr(sysside_addr),
    .sys_we(),
    .sys_ce(),
    .sys_datai(),
    .sys_datao(),
    .sdr_clk(sdram_clk),
    .sdr_datai(SD_DQo),
    .sdr_datao(SD_DQi),
    .sdr_addr(sdrside_addr),
    .sdr_we(sdrside_bufwe),
    .sdr_ce(sdrside_bufce)
);

endmodule