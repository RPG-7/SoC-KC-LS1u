//32b Addr+ 8b Data FSB总线
//允许最大256b的burst 传输
//Core 24b访存+8b PAE

module fsb8
#(
	parameter PAE_ENABLE = 1'b0,
	ADDR_WIDTH=(PAE_ENABLE)?32:24

)
(
input SYNC_MODE,
input [6:0]ASYNC_WAITCYCLE,
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
output hready,
//fsb8信号
output clk,
output rst_n,
output ale_n,
output cs_n,
output cmd_n,
output reg typ,//SINGLE#/BLOCK
output wr_n,
input rdy_n,
input irq_n,
input err_n,
output reg ADdir,	//0表示高阻态
output [7:0]AAH8,
output [7:0]AD_out,
input [7:0]AD_in,
//对内部中断控制器信号
output FSB_irq

);
//状态机
localparam stb 		= 3'h0;	//等待状态
localparam addrh	= 3'h1; //地址帧 ALE
localparam dummy	= 3'h2; //空帧(总线换向)
localparam read		= 3'h3; //读帧
localparam write	= 3'h4;	//写帧
localparam commd	= 3'h7; //写高位地址/总线桥指令 {8'hxx,8'h00}=写H8地址

wire[7:0]command;
reg [2:0]state;

//reg [7:0]M16latch;	
reg [7:0]output_reg;	//输出寄存器	
reg [15:0]DATA_reg;		//AD复用寄存器
reg rwsel;
wire read_cond,write_cond; 
reg [6:0]async_cnt;
wire wait_cond,burst_cond;
wire cnt_eq_set;
assign cnt_eq_set=(async_cnt==ASYNC_WAITCYCLE);
assign burst_cond=(hburst & hsel & (htrans!=0));
assign wait_cond=(!(cnt_eq_set|SYNC_MODE)|rdy_n);
//assign m16_diff=hsel & (htrans!=0) & (M16latch!=haddr[23:8]);
assign command=(hsel)?8'h00:hwdata;
always@(posedge hclk)//异步总线等待计数器
begin
	if(!hreset_n|cnt_eq_set)
		async_cnt<=0;
	else if(state!=stb&!SYNC_MODE)
		async_cnt<=async_cnt+1;
	else async_cnt<=async_cnt;
end
wire transfer_sel,cmdtran_sel;
assign transfer_sel=hsel & (htrans!=0) ;
assign cmdtran_sel=hsel_cmd & (htrans!=0); 
//主状态机
always@(posedge hclk or negedge hreset_n)begin
	if(!hreset_n)begin
		state <= stb;
	end
	else begin
		case(state)
			stb	:	begin
						rwsel<=hwrite;
						if((PAE_ENABLE&transfer_sel)|cmdtran_sel)
							state<=commd;//In case funct select,update addr first
						else if((!PAE_ENABLE&transfer_sel))
							state<=addrh;
						else state<=stb;
					end

			addrh:	if(wait_cond)state<=addrh;//地址帧
					else if(~rwsel) state <= dummy; 
					else  state<=write; 

			dummy:	state <= (wait_cond)?dummy:read;//SET bus to read, but not really 

			read :	state <= (burst_cond|wait_cond)?read:stb;

			write:	state <= (burst_cond|wait_cond)?write:stb ;

			commd:	if(wait_cond)state<=commd;
					else if(hsel)state<=addrh;
					else state <= stb;
		default :	state <= stb;
		endcase
	end
end
	
//输出到AHB寄存器
always@(posedge hclk)begin
	if(!rdy_n)begin
		output_reg	<= AD_in;
	end
end

//地址缓冲寄存器
always @(posedge hclk) 
begin
	if(state!=stb)typ<=hburst;
end
//高阻态指示寄存器
always@(*)
begin
	if(state==stb|state==dummy)
	begin	//默认 进入高阻态
		ADdir	<=	1'b0;
	end
	else if(state==addrh|state==commd|state==write)//写东西时才摆入输出模式
	begin
		ADdir	<=	1'b1;
	end
end
//FSB8信号
assign clk	 = hclk;
assign rst_n = hreset_n;
//地址帧时，进行地址使能
assign ale_n=!(state==addrh);
assign cs_n=!(state==read|state==write);
assign cmd_n=!(state==commd);
assign wr_n=!(state==write);

assign AD_out=	(state==commd)?command:
				(state==addrh)?haddr[15:8]:hwdata;
generate 
if(PAE_ENABLE) 
	begin : PAE_OUT
		assign AAH8	 =  ((!cmdtran_sel)&state==commd)?haddr[31:24]:
						(state==addrh)?haddr[23:16]:haddr[7:0];
	end
	else begin :PAELESS_OUT
		assign AAH8	 =  (state==addrh)?haddr[23:16]:haddr[7:0];
	end
endgenerate

//AHB响应
assign hresp	=	!err_n;
assign hready	=	(state==stb&(!htrans&!wait_cond))|((state==read|state==write)&!wait_cond);
assign FSB_irq	=	!irq_n;
assign hrdata	=	output_reg;



endmodule	
