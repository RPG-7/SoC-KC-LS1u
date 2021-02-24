/***********************************************************************************************
    GPIO unit for R408 SoC
    Register define(from address offset 0):
    +0 P_in    : input from GPIO(r) XINT Enable(write h4 bit)/Clear (w 0x01)
    +1 P_out   : data out to GPIO
    +2 P_dir : Port dir, this register is for direction control, 0=input 1=output, reset=00000000(all input)
    +3 P_mode : Port mode,  set any bit = 1 to enable 2nd function. reset = 00000000

                    You can add anything you like to this unit!
************************************************************************************************/
module GPIO(
//-------------GPIO port------------
    input wire [7:0]P_in,
    output wire [7:0]D_out,
    output reg [7:0]P_dir,
//-----------2nd Function-----------
    input [7:0]sec_func_i,
    output [7:0]sec_func_o,
    output reg XTNL_INT,
//------------Global signals--------
    input wire clk,
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

wire [7:0]Sdec_out;         //7-segment decoder output
//-----------Regs defines-----------
reg [7:0] Pin;
reg [7:0] P_out;
reg [7:0] P_mode;      //GPIO mode
reg [3:0] xint_enable;
//-----------------P port output-------------------
//assign D_out = P_mode[0] ? Sdec_out : P_out;
genvar i;
generate 
    for(i=0;i<7;i=i+1) 
    begin : IOFUNC_SEL
        assign D_out[i] = P_mode[i] ? sec_func_i : P_out; 
        assign sec_func_o[i]=P_mode[i]&P_in[i];
    end
endgenerate
//XTNL INT SEL
wire xint_set,xint_clr;
wire [3:0]xint_masked;
assign xint_masked=(xint_enable&sec_func_o[7:4]);
reg [3:0]xint_hold;
assign xint_set=(xint_masked!=0);
assign xint_clr= (WB_CYCi & WB_STBi & (WB_ADRi == 2'h0)& WB_WEi & WB_DATi[0])|rst;
always@(posedge xint_set or posedge xint_clr)
begin
    if(xint_clr)
    begin
        XTNL_INT<=1'b0;
        xint_hold<=4'b0;
    end
    else 
    begin
        XTNL_INT<=1'b1;
        xint_hold<=xint_masked;
    end
end
//-----------------GPIO input DFF--------------------
integer j;
always@(posedge clk)
begin
    for (j=0;j<8;j=j+1) 
    begin
        if(!P_dir[j])
            if(xint_enable[j])Pin<=xint_masked;
            else Pin<=P_in;
        else Pin[j]<=0;    
    end  
end
//---------------wishbone signals------------
//---------------REG WRITE------------------
always@(posedge clk or posedge rst)begin
    if(rst)begin
        P_mode <= 8'h00;
        P_dir <= 8'h00;
        xint_enable<=4'h0;
    end
    else if(WB_CYCi & WB_STBi & WB_WEi)
    begin
        case(WB_ADRi[1:0])
        2'h0    :   xint_enable<=WB_DATi ;
        2'h1    :   P_out<=WB_DATi ;
        2'h2    :   P_dir<=WB_DATi ;
        2'h3    :   P_mode<=WB_DATi ;     
        endcase
    end
    else 
    begin
        xint_enable<=xint_enable;
        P_out<=P_out;
        P_dir<=P_dir;
        P_mode<=P_mode;
    end    
end
//-----------DATA READ-----------
always@(*)begin
    case(WB_ADRi[1:0])
        2'h0    :   WB_DATo <= Pin;
        2'h1    :   WB_DATo <= P_out;
        2'h2    :   WB_DATo <= P_dir;
        2'h3    :   WB_DATo <= P_mode;
        default :   WB_DATo <= 8'h00;
    endcase
end
//----------ACK----------------
assign WB_ACKo = 1'b1;


endmodule
//hex-7-segment decoder
// module seg7(
// input wire test,
// input wire blank,
// input wire [3:0]in,
// output reg [7:0]hex	//lowactive g f e d c b a 
// );
// always@(*)begin
// 	if(blank)begin
// 		hex <= 8'b0111_1111;	//blank
// 	end
// 	else begin
// 	case({test,in})
// 		5'b1xxxx	:	hex <= 8'b0000_0000;
// 		5'b00000 	:	hex <= 8'b0100_0000;
// 		5'b00001	:	hex <= 8'b0111_1001;
// 		5'b00010	:	hex <= 8'b0010_0100;
// 		5'b00011	:	hex <= 8'b0011_0000;
// 		5'b00100	:   hex <= 8'b0001_1001;
// 		5'b00101	:	hex <= 8'b0001_0010;
// 		5'b00110	:   hex <= 8'b0000_0010;
// 		5'b00111	:	hex <= 8'b0111_1000;
// 		5'b01000	:	hex <= 8'b0000_0000;
// 		5'b01001	:   hex <= 8'b0001_0000;
// 		5'b01010	:   hex <= 8'b0000_1000;
// 		5'b01011	:	hex <= 8'b0000_0011;
// 		5'b01100	:	hex <= 8'b0100_0110;
// 		5'b01101	:	hex <= 8'b0010_0001; 
// 		5'b01110	:	hex <= 8'b0000_0110;
// 		5'b01111	:   hex <= 8'b0000_1110;
// 	default : hex <= 8'b0000_0000;
// 	endcase
// 	end
// end
// endmodule