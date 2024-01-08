//SoC-LS1u Interrupt controller
//Reg map:
//0x00:INTC :   {INTEN,RSVD[5:0],IVESIZ[1:0]}
//0x01:MCAUS:   Interrupt Number
//0x01:IVT0 :   Interrupt Vector Table[7:0]
//0x02:IVT1 :   Interrupt Vector Table[15:8]
//0x03:IVT2 :   Interrupt Vector Table[23:16]
//0x04:INTE0:   INTerrupt Enable0
//0x05:INTP0:   Interrupt Pending0
//0x06:XCPP :   eXCePtion Pending
module xcr_ecp_ctrl
(
//------------INT signals--------   
    input [7:0]INT_ARR,
    input [7:0]XCP_ARR,
    output reg[23:0]IVEC_ADDR,
    output reg INT,
//------------Global signals--------
    input wire clk,
    input wire rst,
//-----------ECR BUS-----------
    input [7:0]cr_din,
    output reg[7:0]cr_dout,
    input [2:0]cr_adr,
    input cr_we,
	input cr_cs

);
integer i;
//Currently 16 INTs are enough
//INTERRUPTS:SYSCALL SYSTICK SPI UART I2C TIM XINT DMA
//-----------Regs defines-----------
reg [2:0]   INTC;
reg [7:0]   IVT0,IVT1,IVT2,
            INTE0,XCPP0,INTP0;//,INTE2,INTE3//sub-interrupt enable
wire [7:0]int_masked;
reg [7:0] int_capture,xcp_capture;
wire int_trigged;
assign int_trigged = |int_masked;
wire [4:0]INT_CODE;
wire [7:0]INT_OFFSET;
wire [23:0]IVT_ADDR;
reg [2:0]int_select_encode[7:0];
reg [2:0]xcp_select_encode[7:0];
always @(*)//中断源选择优先编码器
begin
    int_select_encode[0]=0;
    xcp_select_encode[0]=0;
    for ( i=1;i<8;i=i+1 ) 
    begin
        int_select_encode[i]=sel_entry_cell(int_select_encode[i-1],i,INTP0[i]);
        xcp_select_encode[i]=sel_entry_cell(xcp_select_encode[i-1],i,XCPP0[i]);
    end
end
wire [7:0]xcp_clr,int_clr;
assign int_clr=~({8{(cr_cs & cr_we & (cr_adr[2:0]==4'h6))}}&cr_din);
assign xcp_clr=~({8{(cr_cs & cr_we & (cr_adr[2:0]==4'h5))}}&cr_din);

always @(posedge clk or posedge rst) 
begin
    if(rst)
    begin
        INTP0<=0;
        XCPP0<=0;
    end
    else 
    begin
        INTP0 <= (INTP0 & int_clr) | int_masked;
        XCPP0 <= (XCPP0 & xcp_clr) | XCP_ARR;
    end
end

//中断地址生成
assign int_masked=(INT_ARR[7:0]&INTE0);
assign IVT_ADDR={IVT2,IVT1,IVT0};//INTC Highest bit is interrupt enable 
assign INT_CODE={1'b0,int_trigged,(int_trigged)?int_select_encode[7]:xcp_select_encode[7]};
always @(posedge clk or posedge rst) 
begin
    if(rst)
    begin
        INT<=0;
        IVEC_ADDR<=0;
    end
    else if(INTC[2])
    begin
        INT <= (|{INTPO,XCPP0}) & INTC;
        IVEC_ADDR<=IVT_ADDR+{INT_OFFSET,2'b00};
    end
    else 
    begin
        INT<=0;
        IVEC_ADDR<=IVEC_ADDR;
    end
end
defparam IVE_SIZE_SHIFTER.IN_WIDTH=8;
left_bshifter IVE_SIZE_SHIFTER
(
    .datain({3'h0,INT_CODE}),
    .shiftnum({1'b0,INTC[1:0]}),
    .dataout(INT_OFFSET)
);
//---------------REG WRITE------------------
always@(posedge clk or posedge rst)
begin
    if(rst)begin
        INTC <= 3'h0;
    end
    else if(cr_cs & cr_we)
    begin
        case(cr_adr[2:0])
        4'h0    :   INTC<={cr_din[7],cr_din[1:0]} ;
        4'h1    :   IVT0<=cr_din ;
        4'h2    :   IVT1<=cr_din ;
        4'h3    :   IVT2<=cr_din ; 
        4'h4    :   INTE0<=cr_din;
        endcase
    end
    else 
    begin
        INTC<=INTC ;
        IVT0<=IVT0 ;
        IVT1<=IVT1 ;
        IVT2<=IVT2 ; 
        INTE0<=INTE0;
    end
end
//---------------wishbone signals------------
//-----------DATA-----------
always@(*)begin
    case(cr_adr[2:0])
        4'h0    :   cr_dout <= INTC;
        4'h1    :   cr_dout <= IVT0;
        4'h2    :   cr_dout <= IVT1;
        4'h3    :   cr_dout <= IVT2;
        4'h4    :   cr_dout <= INTE0;
        4'h5    :   cr_dout <= EXPP0;
        4'h6    :   cr_dout <= INTP0;
        default :   cr_dout <= 8'hzz;
    endcase
end
//----------ACK----------------

//可扩展优先编码器：如果该位为1,返回该位所在编号,如果该位为0，传递上一级输入编号
function [2:0]sel_entry_cell;
    input [2:0]prev_entry_num;
    input [2:0]cur_entry_num;
    input cur_entry_bit;
    begin
   		sel_entry_cell=(cur_entry_bit)?cur_entry_num:prev_entry_num;
   	end
endfunction
endmodule
