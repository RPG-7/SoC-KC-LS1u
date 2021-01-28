//
//  UART module for R408 SoC, No FIFO, do not send too much!!!
//  
module UART(
    //-----------------------------
    input wire clk,
    input wire rst,
    //UART signal
    output wire UART_TXD,
    input wire UART_RXD,
    //--------Wishbone signals-------
    input wire [2:0]Slave_WB_ADRi,
    input wire [7:0]Slave_WB_DATi,
    output reg [7:0]Slave_WB_DATo,
    input wire Slave_WB_WEi,
    input wire Slave_WB_CYCi,
    input wire Slave_WB_STBi,
    output wire Slave_WB_ACKo
);
//------------regs select--------------------------
    wire STATE_select;
    wire RDATA_select;
    wire TDATA_select;
	 wire BDRL_select;
	 wire BDRH_select;
//-----------data and control registers------------
    wire [7:0] UART_STATE;      //UART state        bit0=WE, bit4=Tx_done, bit5=Rx_done
    wire [7:0] UART_RDATA;      //UART Rx data
    reg [7:0] UART_TDATA;       //UART Tx data
    reg [7:0] UART_BDRL;        //UART Bode Rate L
    reg [7:0] UART_BDRH;        //UART Bode Rate H

    reg Flag_Tx_Done;
    reg Flag_Rx_Done;
    reg Tx_enable;
//-------------------control wires----------------------
    wire Tx_done;               //Tx done paulse
    wire Rx_done;               //Rx done paulse
//-----------------------select-------------------------
assign STATE_select = Slave_WB_STBi & Slave_WB_CYCi & (Slave_WB_ADRi==3'h0);    
assign RDATA_select = Slave_WB_STBi & Slave_WB_CYCi & (Slave_WB_ADRi==3'h1);
assign TDATA_select = Slave_WB_STBi & Slave_WB_CYCi & (Slave_WB_ADRi==3'h2);
assign BDRL_select  = Slave_WB_STBi & Slave_WB_CYCi & (Slave_WB_ADRi==3'h3);
assign BDRH_select  = Slave_WB_STBi & Slave_WB_CYCi & (Slave_WB_ADRi==3'h4);
//---------------------Wishbone output data mux---------------------
assign UART_STATE = {2'b0,Flag_Rx_Done,Flag_Tx_Done,4'b0};
always@(*)begin
    case(Slave_WB_ADRi)
        3'h0 : Slave_WB_DATo <= UART_STATE;
        3'h1 : Slave_WB_DATo <= UART_RDATA;
        3'h2 : Slave_WB_DATo <= UART_TDATA;
        3'h3 : Slave_WB_DATo <= UART_BDRL;
        3'h4 : Slave_WB_DATo <= UART_BDRH;
    default  : Slave_WB_DATo <= 8'h00;
    endcase
end
assign Slave_WB_ACKo = 1'b1;
////Tx enable register
always@(posedge clk)begin
    if(rst)begin
        Tx_enable <= 1'b0; 
    end
    else if(STATE_select & Slave_WB_WEi)begin
        Tx_enable <= Slave_WB_DATi[0];
    end
    else begin
        Tx_enable <= 1'b0;
    end
end
////Flag_Tx_Done
always@(posedge clk)begin
    if(rst)begin
        Flag_Tx_Done <= 1'b0;
    end
    else begin
        case(Flag_Tx_Done)
            0:  if(Tx_done)begin
                    Flag_Tx_Done <= 1'b1;
                end
            1:  if(Tx_enable)begin
                    Flag_Tx_Done <= 1'b0;
                end
        endcase
    end
end
////Flag Rx done
always@(posedge clk)begin
    if(rst)begin
        Flag_Rx_Done <= 1'b0;
    end
    else begin
        case(Flag_Rx_Done)
            0:  if(Rx_done)begin
                    Flag_Rx_Done <= 1'b1;
                end
            1:  if(RDATA_select)begin
                    Flag_Rx_Done <= 1'b0;
                end
        endcase
    end
end
////Tx data
always@(posedge clk)begin
    if(TDATA_select & Slave_WB_WEi)begin
        UART_TDATA <= 8'h00;    
    end
end

////BDRL
always@(posedge clk)begin
    if(rst)begin
        UART_BDRL <= 8'h58;    
    end
    else if(BDRL_select & Slave_WB_WEi)begin
        UART_BDRL <= Slave_WB_DATi;
    end
end
////BDRH
always@(posedge clk)begin
    if(rst)begin
        UART_BDRH <= 8'h14;    
    end
    else if(BDRH_select & Slave_WB_WEi)begin
        UART_BDRH <= Slave_WB_DATi;
    end
end
//-------------------------UART Tx Core--------------------------
uart_tx                     Tx(
    .i_clk                      (clk), //100MHZ;
    .i_rst_n                    (!rst),
    .i_send_en                  (Tx_enable), //打开发送；
    .i_data_i                   (UART_TDATA),
    .o_tx                       (UART_TXD),
    .o_tx_done                  (Tx_done),          //发送完成指示；
    .BPS_CNT_MAX                ({UART_BDRH[6:0],UART_BDRL})
);
//------------------------UART Rx Core----------------------------
uart_rx                     Rx(
    .i_clk                      (clk), //100MHZ;
    .i_rst_n                    (!rst),
    .i_rx                       (UART_RXD), //打开发送；
    .o_rx_finish                (Rx_done),
    .o_rx_data                  (UART_RDATA),
    .p_bps_max                  ({3'b0,UART_BDRH,UART_BDRL[7:4]})
);


endmodule

////////uart 接收模块；
module uart_rx (
    input     wire             i_clk                , //100M；
    input     wire             i_rst_n              ,
    input     wire             i_rx                 ,
    output    wire             o_rx_finish          ,
    output    wire    [7:0]    o_rx_data            ,
    input     wire    [14:0]   p_bps_max
);
/////////////////波特率选择；默认115200bps/s；
//parameter [14:0] p_bps_max = 100_000_000/115200/16;
reg [1:0] r_rx;
always @(posedge i_clk) begin
    r_rx <= {r_rx[0],i_rx};
end
reg [14:0] r_bps_cnt;
reg [7:0] r_position_cnt;
reg r_cnt_en;
always @(posedge i_clk,negedge i_rst_n) begin
    if (~i_rst_n) begin
        r_cnt_en <= 0;
    end //if
    else begin
        if (r_rx == 2'b10) begin
            r_cnt_en <= 1'b1;
        end
        else begin
            if (((r_position_cnt == 8'd7) && (r_rx[1])) || (r_position_cnt == 8'd144)) begin
                r_cnt_en <= 1'b0;
            end
        end
    end //else
end //always
always @(posedge i_clk,negedge i_rst_n) begin
    if (~i_rst_n) begin
        r_bps_cnt <= 0;
    end //if
    else begin
        if (r_cnt_en) begin
            if (r_bps_cnt == (p_bps_max -15'd1)) begin
                r_bps_cnt <= 0;
            end
            else begin
                r_bps_cnt <= r_bps_cnt + 15'd1;
            end
        end
        else begin
            r_bps_cnt <= 0;
        end
    end //else
end //always
////////////位置计数逻辑；
always @(posedge i_clk,negedge i_rst_n) begin
    if (~i_rst_n) begin
        r_position_cnt <= 0;
    end //if
    else begin
        if (r_cnt_en) begin
            if (r_bps_cnt == (p_bps_max-15'd1)) begin
                r_position_cnt <= r_position_cnt + 8'd1;
            end
        end
        else begin
            r_position_cnt <= 0;
        end
    end //else
end //always
reg [7:0] r_rx_data;
always @(posedge i_clk,negedge i_rst_n) begin
    if (~i_rst_n) begin
        r_rx_data <= 0;
    end //if
    else begin
        case (r_position_cnt)
            15'd23:  begin r_rx_data[0] <= r_rx[1]; end
            15'd39:  begin r_rx_data[1] <= r_rx[1]; end
            15'd55:  begin r_rx_data[2] <= r_rx[1]; end
            15'd71:  begin r_rx_data[3] <= r_rx[1]; end
            15'd87:  begin r_rx_data[4] <= r_rx[1]; end
            15'd103: begin r_rx_data[5] <= r_rx[1]; end
            15'd119: begin r_rx_data[6] <= r_rx[1]; end
            15'd135: begin r_rx_data[7] <= r_rx[1]; end
          default: ;
        endcase
    end //else
end //always

assign o_rx_finish = (r_position_cnt >= 15'd139) ? 1'b1 : 1'b0;
assign o_rx_data = r_rx_data;

endmodule // end the uart_rx model;
///////uart 发送模块；
module  uart_tx (
        input    wire             i_clk            , //100MHZ;
        input    wire             i_rst_n          ,
        input    wire             i_send_en        , //打开发送；
        input    wire    [7:0]    i_data_i         ,
        output   wire             o_tx             ,
        output   wire             o_tx_done        , //发送完成指示；
        input    wire    [14:0]   BPS_CNT_MAX
);
/////////////////波特率选择；
//parameter [14:0] BPS_CNT_MAX = 100_000_000/115200;  //时钟根据需要修改；
//parameter [14:0] BPS_CNT_MAX = 15'd2; //仿真使用2；缩短仿真时间；
reg [1:0] r_i_send_en; //同步两拍；
always @(posedge i_clk) begin
    r_i_send_en <= {r_i_send_en[0],i_send_en};
end
reg [7:0] tx_data;
always @(posedge i_clk or negedge i_rst_n) begin
    if (~i_rst_n) begin
        tx_data <= 0;
    end //if
    else begin
        if (r_i_send_en[1]) begin
            tx_data <= i_data_i;
        end
        else begin
            tx_data <= tx_data;
        end
    end //else
end //always
reg tx_en; //整个发送区间计数使能；
reg [14:0] bps_cnt;
reg [3:0] cnt;
always @(posedge i_clk or negedge i_rst_n) begin
    if (~i_rst_n) begin
        tx_en <= 0;
    end //if
    else begin
        if (r_i_send_en[1]) begin
            tx_en <= 1'b1;
        end
        else begin
            if ((cnt == 4'd10) && (bps_cnt == (BPS_CNT_MAX - 15'd1))) begin
                tx_en <= 1'b0;
            end
        end
    end //else
end //always
always @(posedge i_clk or negedge i_rst_n) begin
    if (~i_rst_n) begin
        bps_cnt <= 0;
    end //if
    else begin
        if (tx_en) begin
            if (bps_cnt == (BPS_CNT_MAX - 15'd1)) begin
                bps_cnt <= 0;
            end
            else begin
                bps_cnt <= bps_cnt + 15'd1;
            end
        end
        else begin
            bps_cnt <= 0;
        end
    end //else
end //always
always @(posedge i_clk or negedge i_rst_n) begin
    if (~i_rst_n) begin
        cnt <= 0;
    end //if
    else begin
        if (tx_en) begin
            if (bps_cnt == (BPS_CNT_MAX - 15'd1)) begin
                cnt <= cnt + 4'd1; //bps计数到最大值则cnt加1；
            end
        end
        else begin
            cnt <= 0;
        end
    end //else
end //always
reg tx_done;
reg tx;
always @(posedge i_clk) begin
    case (cnt)
        0 : begin tx <= 1'b1;tx_done <= 1'b0; end //tx默认为高电平；
        1 : begin tx <= 1'b0; end
        2 : begin tx <= tx_data[0]; end
        3 : begin tx <= tx_data[1]; end
        4 : begin tx <= tx_data[2]; end
        5 : begin tx <= tx_data[3]; end
        6 : begin tx <= tx_data[4]; end
        7 : begin tx <= tx_data[5]; end
        8 : begin tx <= tx_data[6]; end
        9 : begin tx <= tx_data[7]; end
        10: begin tx <= 1'b1;tx_done <= 1'b1;end //拉高tx，产生发送完成指示信号；
        default:  begin tx <= 1'b1;tx_done <= 1'b0; end
    endcase //case
end //always
assign o_tx = tx;
assign o_tx_done = tx_done;

endmodule