module timer
(
    output reg SYSTICK_INT,TIM_INT,
    output PWMo,
    input SYST_PAUSE,
    //------------Global signals--------
    input wire clk,
    input lclk,
    input wire rst,
//-----------Wishbone BUS-----------
    input wire [9:0]WB_ADRi,
    output reg [7:0]WB_DATo,
    input wire [7:0]WB_DATi,
    input wire WB_WEi,
    input wire WB_CYCi,
    input wire WB_STBi,
    output wire WB_ACKo

);
//TIMER CONTROL:
//STICK_INT_EN TIM_INT_EN STICK_CKSEL TIM_CKSEL STPAUSE_ENABLE PWM_ENABLE systick_enable tim_enable
//TCLR: ALLCLR TIMCNT_CLR STKCNT_CLR 
reg [7:0]   TIMC,TCLR,TMS0,TMS1,
            STK0,STK1;//,STK2,STK3
reg [15:0]systick_cnt;
reg [15:0]tim_cnt;


//PWM output
assign PWMo=TIMC[2]&(tim_cnt<={TMS1,TMS0});
//Counter Clk sel. this kind of gated, selectable clock is highly NOT recommended in FPGA designs 
wire timclk,systick_clk;
assign timclk=((TIMC[4])?clk:lclk)&TIMC[0];
assign systick_clk=((TIMC[5])?clk:lclk)&TIMC[1];
//INT SET logic, pair with CLR to form S-R Latch
wire tint_set,stint_set;
assign tint_set=TIMC[6]&(tim_cnt=={TMS1,TMS0});
assign stint_set=TIMC[7]&(systick_cnt=={STK1,STK0});
//TCLR logic,use async rst, pay attention to tHOLD constrain and fanout
wire timclr,systick_clr;
wire tint_clr,stint_clr;
assign timclr=(WB_CYCi & WB_STBi & WB_WEi & (WB_ADRi[3:0]==4'h1)&(WB_DATi[7]|WB_DATi[6]))|rst;
assign systick_clr=(WB_CYCi & WB_STBi & WB_WEi & (WB_ADRi[3:0]==4'h1)&(WB_DATi[7]|WB_DATi[5]))|rst;
assign tint_clr=(WB_CYCi & WB_STBi & WB_WEi & (WB_ADRi[3:0]==4'h1)&(WB_DATi[7]|WB_DATi[4]))|rst;
assign stint_clr=(WB_CYCi & WB_STBi & WB_WEi & (WB_ADRi[3:0]==4'h1)&(WB_DATi[7]|WB_DATi[3]))|rst;
//INT OUTPUT
always @(posedge tint_set or posedge tint_clr) 
begin
    if(tint_clr)TIM_INT<=0;
    else TIM_INT<=1;
end
always @(posedge stint_set or posedge stint_clr) 
begin
    if(stint_clr)SYSTICK_INT<=0;
    else SYSTICK_INT<=1;
end
//COUNTERS
always@(posedge timclk or posedge timclr)
begin
    if(timclr)tim_cnt<=0;
    else tim_cnt<=tim_cnt+1;
end
wire systick_pause;
assign systick_pause=SYST_PAUSE&TIMC[3];
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
        case(WB_ADRi[3:0])
        4'h0    :   TIMC<=WB_DATi ;
        //4'h1    :   IVT0<=WB_DATi ;
        4'h2    :   TMS0<=WB_DATi ;
        4'h3    :   TMS1<=WB_DATi ; 
        4'h4    :   STK0<=WB_DATi;
        4'h5    :   STK1<=WB_DATi;   
        //4'h6    :   STK2<=WB_DATi;   
        //4'h7    :   STK3<=WB_DATi;      
        endcase
    end
    else 
    begin
        TIMC<=TIMC ;
        //IVT0<=IVT0 ;
        TMS0<=TMS0 ;
        TMS1<=TMS1 ; 
        STK0<=STK0;
        STK1<=STK1;
        //STK2<=STK2;
        //STK3<=STK3;        
    end
end

//-----------DATA READ-----------
always@(*)begin
    case(WB_ADRi[3:0])
        4'h0    :   WB_DATo <= TIMC;
        //4'h1    :   WB_DATo <= IVT0;
        4'h2    :   WB_DATo <= TMS0;
        4'h3    :   WB_DATo <= TMS1;
        4'h4    :   WB_DATo <= STK0;
        4'h5    :   WB_DATo <= STK1;
        //4'h6    :   WB_DATo <= STK2;
        //4'h7    :   WB_DATo <= STK3;
        default :   WB_DATo <= 8'h00;
    endcase
end
//----------ACK----------------
assign WB_ACKo = 1'b1;

endmodule
