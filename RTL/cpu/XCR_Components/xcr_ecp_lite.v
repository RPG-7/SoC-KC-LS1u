//SoC-LS1u Interrupt controller
//Reg map:
//0x00:INTC :   {INTEN,RSVD[5:0],IVESIZ[1:0]}
//0x01:MCAUS:   Interrupt Number
//0x01:IVT0 :   Interrupt Vector Table[7:0]
//0x02:IVT1 :   Interrupt Vector Table[15:8]
//0x03:IVT2 :   Interrupt Vector Table[23:16]
//0x04:INTE0:   INTerrupt Enable0
//0x05:XCPP0:   eXCePtion Pending 0 ,w1c
//0x06:INTP0 :  Int Pending 0,w1c
//0x07:RESERVED

module xcr_ecp_lite
(
//------------INT signals--------   
    input [7:0]INT_ARR,
    input [7:0]XCP_ARR,
    output [23:0]IVEC_ADDR,
    output INT,
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
reg   INTC;
reg [7:0]   IVT0,IVT1,IVT2,
            INTE0,XCPP0,INTP0;//,INTE2,INTE3//sub-interrupt enable
wire [7:0]int_masked;
wire int_trigged;
assign int_trigged = |int_masked;
wire [4:0]INT_CODE;
wire [7:0]INT_OFFSET;
wire [23:0]IVT_ADDR;
wire [7:0]xcp_clr,int_clr;
assign int_clr=~({8{(cr_cs & cr_we & (cr_adr[2:0]==4'h6))}}&cr_din);
assign xcp_clr=~({8{(cr_cs & cr_we & (cr_adr[2:0]==4'h5))}}&cr_din);

//中断地址生成
assign int_masked=(INT_ARR[7:0]&INTE0);
assign IVT_ADDR={IVT2,IVT1,IVT0};//INTC Highest bit is interrupt enable 
assign IVEC_ADDR=IVT_ADDR;
assign INT = (|{INTP0,XCPP0}) & INTC;

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

//---------------REG WRITE------------------
always@(posedge clk or posedge rst)
begin
    if(rst)begin
        INTC <= 1'h0;
    end
    else if(cr_cs & cr_we)
    begin
        case(cr_adr[2:0])
        4'h0    :   INTC<=cr_din[7];
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
        4'h0    :   cr_dout <= {INTC,7'b00};
        4'h1    :   cr_dout <= IVT0;
        4'h2    :   cr_dout <= IVT1;
        4'h3    :   cr_dout <= IVT2;
        4'h4    :   cr_dout <= INTE0;
        4'h5    :   cr_dout <= XCPP0;
        4'h6    :   cr_dout <= INTP0;
        default :   cr_dout <= 8'hzz;
    endcase
end
//----------ACK----------------

endmodule
