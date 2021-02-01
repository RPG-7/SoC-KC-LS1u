module systick
(
    output reg SYSTICK_INT,
    input SYST_PAUSE,
    //------------Global signals--------
    input wire clk,
    input lclk,
    input wire rst,
//-----------Wishbone BUS-----------
    input wire [1:0]WB_ADRi,
    output reg [7:0]WB_DATo,
    input wire [7:0]WB_DATi,
    input wire WB_WEi,
    input wire WB_CYCi,
    input wire WB_STBi,
    output wire WB_ACKo

);
//TIMER CONTROL:
//[7]STKINT_EN [6]STK_CKSEL [5]STPAUSE_ENABLE [4]STK_EN
// [1]STKINT_CLR[0]STKCNT_CLR 
reg [3:0]TIMC;
reg [7:0]STK0,STK1,STK2;
            //,STK3
reg [23:0]systick_cnt;


//Counter Clk sel. this kind of gated, selectable clock is highly NOT recommended in FPGA designs 
wire systick_clk;
assign systick_clk=((TIMC[2])?clk:lclk)&TIMC[0];
//INT SET logic, pair with CLR to form S-R Latch
wire tint_set,stint_set;
assign stint_set=TIMC[3]&(systick_cnt=={STK2,STK1,STK0});
//TCLR logic,use async rst, pay attention to tHOLD constrain and fanout
wire timclr,systick_clr;
wire tint_clr,stint_clr;
assign systick_clr=(WB_CYCi & WB_STBi & WB_WEi & (WB_ADRi==4'h1)&(WB_DATi[7]|WB_DATi[5]))|rst;
assign stint_clr=(WB_CYCi & WB_STBi & WB_WEi & (WB_ADRi==4'h1)&(WB_DATi[7]|WB_DATi[3]))|rst;
//INT OUTPUT
always @(posedge stint_set or posedge stint_clr) 
begin
    if(stint_clr)SYSTICK_INT<=0;
    else SYSTICK_INT<=1;
end
//COUNTERS
wire systick_pause;
assign systick_pause=SYST_PAUSE&TIMC[1];
always@(posedge systick_clk or posedge systick_clr)
begin
    if(systick_clr)systick_cnt<=0;
    else if(!systick_pause)systick_cnt<=systick_cnt+1;
    else systick_cnt<=systick_cnt;
end

//---------------wishbone signals------------
//---------------REG WRITE------------------
always@(posedge clk)begin
    if(rst)begin
        TIMC <= 8'h00;
    end
    else if(WB_CYCi & WB_STBi & WB_WEi)
    begin
        case(WB_ADRi[1:0])
        4'h0    :   TIMC<=WB_DATi ;
        4'h1    :   STK0<=WB_DATi;
        4'h2    :   STK1<=WB_DATi;   
        4'h3    :   STK2<=WB_DATi;   
        //4'h7    :   STK3<=WB_DATi;      
        endcase
    end
    else 
    begin
        TIMC<=TIMC ;
        STK0<=STK0;
        STK1<=STK1;
        STK2<=STK2;
        //STK3<=STK3;        
    end
end

//-----------DATA READ-----------
always@(*)begin
    case(WB_ADRi[1:0])
        4'h0    :   WB_DATo <= {TIMC,4'hx};
        4'h1    :   WB_DATo <= STK0;
        4'h2    :   WB_DATo <= STK1;
        4'h3    :   WB_DATo <= STK2;
        //4'h7    :   WB_DATo <= STK3;
        default :   WB_DATo <= 8'hxx;
    endcase
end
//----------ACK----------------
assign WB_ACKo = 1'b1;

endmodule
