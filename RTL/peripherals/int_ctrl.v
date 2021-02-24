//SoC-LS1u Interrupt controller
//Reg map:
//0x00:INTC :   {INTEN,RSVD[5:0],IVESIZ[1:0]}
//0x01:IVT0 :   Interrupt Vector Table[7:0]
//0x02:IVT1 :   Interrupt Vector Table[15:8]
//0x03:IVT2 :   Interrupt Vector Table[23:16]
//0x04:INTE0:   INTerrupt Enable0
//0x05:XCPE0:   eXCePtion Enable0
//0x06:XCPC :   eXCePtion Clear
module int_ctrl
(
//------------INT signals--------   
    input [7:0]INT_ARR,
    input [7:0]XCP_ARR,
    output reg[23:0]IVEC_ADDR,
    output reg INT,
//------------Global signals--------
    input wire clk,
    input wire rst,
//-----------Wishbone BUS-----------
    input wire [2:0]WB_ADRi,
    output reg [7:0]WB_DATo,
    input wire [7:0]WB_DATi,
    input wire WB_WEi,
    input wire WB_CYCi,
    input wire WB_STBi,
    output wire WB_ACKo

);
integer i;
//Currently 16 INTs are enough
//INTERRUPTS:SYSCALL SYSTICK SPI UART I2C TIM XINT DMA
//-----------Regs defines-----------
reg [2:0]   INTC;
reg [7:0]   IVT0,IVT1,IVT2,
            INTE0,EXPE0;//,INTE2,INTE3//sub-interrupt enable
wire [7:0]int_masked;
reg  [7:0]xcp_trig;
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
        int_select_encode[i]=sel_entry_cell(int_select_encode[i-1],i,int_masked[i]);
        xcp_select_encode[i]=sel_entry_cell(xcp_select_encode[i-1],i,xcp_trig[i]);
    end
end
wire [7:0]xcp_clr,xcp_set;
assign xcp_set=XCP_ARR&EXPE0;
assign xcp_clr={8{(WB_CYCi & WB_STBi & WB_WEi & (WB_ADRi[2:0]==4'h6))}}&WB_DATi|{8{rst}};
genvar j;
generate 
    for(j=0;j<8;j=j+1) 
    begin : EXCEPTION_CATCHER
        always@(posedge xcp_set[j] or posedge xcp_clr[j])
        begin
            if(xcp_clr[j])
                xcp_trig[j]<=1'b0;
            else xcp_trig[j]<=1'b1;
        end
    end
endgenerate
//中断地址生成
assign int_masked=(INT_ARR[7:0]&INTE0);
assign IVT_ADDR={IVT2,IVT1,IVT0};//INTC Highest bit is interrupt enable 
assign INT_CODE={2'b00,int_select_encode[7]};
always @(posedge clk or posedge rst) 
begin
    if(rst)
        INT<=0;
    else if(INTC[2])
    begin
        INT<=(int_masked!=0);
        IVEC_ADDR<=IVT_ADDR+{INT_OFFSET,2'b00};
    end
    else 
    begin
        INT <= INT;
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
    else if(WB_CYCi & WB_STBi & WB_WEi)
    begin
        case(WB_ADRi[2:0])
        4'h0    :   INTC<={WB_DATi[7],WB_DATi[1:0]} ;
        4'h1    :   IVT0<=WB_DATi ;
        4'h2    :   IVT1<=WB_DATi ;
        4'h3    :   IVT2<=WB_DATi ; 
        4'h4    :   INTE0<=WB_DATi;
        4'h5    :   EXPE0<=WB_DATi;
        endcase
    end
    else 
    begin
        INTC<=INTC ;
        IVT0<=IVT0 ;
        IVT1<=IVT1 ;
        IVT2<=IVT2 ; 
        INTE0<=INTE0;
        EXPE0<=EXPE0;
    end
end
//---------------wishbone signals------------
//-----------DATA-----------
always@(*)begin
    case(WB_ADRi[2:0])
        4'h0    :   WB_DATo <= INTC;
        4'h1    :   WB_DATo <= IVT0;
        4'h2    :   WB_DATo <= IVT1;
        4'h3    :   WB_DATo <= IVT2;
        4'h4    :   WB_DATo <= INTE0;
        4'h5    :   WB_DATo <= EXPE0;
        //4'h6    :   WB_DATo <= INTE2;
        //4'h7    :   WB_DATo <= INTE3;
        default :   WB_DATo <= 8'h00;
    endcase
end
//----------ACK----------------
assign WB_ACKo = 1'b1;

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
