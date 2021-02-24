//Generic Embbeded SDRAM Controller 
//for Anlogic's SIP or Any On-board SDRAM
//Expects to have bus clock domain 
//? maybe fast SDRAM needs a refill domain
//? for Anlogic 32b SIP SDRAM, a dRAM/BRAM buffer is needed

module sdram_controller
#(
    parameter   SDRAM_DBUSWIDTH=32,
                INTERNAL_DBUSWIDTH=8,
                //Minimum 2K for 32b SDRAM (2xB9K or 1xB18K in Gowin)
                BURST_BUFSIZE=2048,
                SDRAMC_CFGENABLE=1'b0
)
(
    input sys_clk,rst,sdram_clk,
    


);


/*`define ANLOGIC_SIP_SDRAM
`ifdef ANLOGIC_SIP_SDRAM
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
`endif */
endmodule