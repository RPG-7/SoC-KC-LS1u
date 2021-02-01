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

reg [7:0]M16latch;	
reg [7:0]output_reg;	//输出寄存器	
reg [15:0]DATA_reg;		//AD复用寄存器
wire read_cond,write_cond; 
wire h8_diff,m16_diff;
generate 
if(PAE_ENABLE) 
	begin : PAE
		reg [7:0]H8latch;//if haddr[31:24]!=h8latch, use commd to write outside h8 address
		
		assign h8_diff=hsel & (htrans!=0) & (H8latch!=haddr[31:24]) & PAE_ENABLE;
		always @(posedge hclk ) 
		begin	
			if(h8_diff&state==commd)H8latch<=haddr[31:28];
		end
	end
	else 
	begin:PAELESS
		assign h8_diff= 1'b0 ;
	end
endgenerate

assign m16_diff=hsel & (htrans!=0) & (M16latch!=haddr[23:8]);
assign read_cond=hsel & (htrans!=0) & !hwrite;
assign write_cond=hsel & (htrans!=0) & hwrite;
assign command=(h8_diff)?8'h00:hwdata;
//主状态机
always@(posedge hclk)begin
	if(!hreset_n)begin
		state <= stb;
	end
	else begin
		case(state)
			stb	:	if(h8_diff|hsel_cmd)
					begin
						state<=commd;//In case funct select,update addr first
					end
					else if(m16_diff)state<=addrh;
					else if(read_cond)
					begin
						state<=read;
					end
					else if(write_cond)begin
						state<=write;
					end
	//地址帧
			addrh:	if(read_cond)
					begin
						state <= dummy;
					end
					else if(write_cond)begin
						state<=write;
					end

			dummy:	state <= read;//SET bus to read, but not really 

			read :	state <= (hburst & hsel & (htrans!=0) )?read:stb;

			write:	state <= (hburst & hsel & (htrans!=0) )?write:stb ;

			commd:	if(m16_diff)state<=addrh;
					else if(read_cond)
					begin
						state<=read;
					end
					else if(write_cond)begin
						state<=write;
					end
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
	if(state==addrh)M16latch<=haddr[23:8];
end
//高阻态指示寄存器
always@(posedge hclk)begin
	if(state==stb|state==dummy)
	begin	//默认 进入高阻态
		ADdir	<=	1'b0;
	end
	else if(state==addrh|state==commd|state==write)//写东西时才摆入输出模式
	begin
		ADdir	<=	1'b0;
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
		assign AAH8	 =  (h8_diff&state==commd)?haddr[31:24]:
						(state==addrh)?haddr[23:16]:haddr[7:0];
	end
	else begin :PAELESS_OUT
		assign AAH8	 =  (state==addrh)?haddr[23:16]:haddr[7:0];
	end
endgenerate

//AHB响应
assign hresp	=	1'b1;
assign hready	=	!rdy_n;
assign FSB_irq	=	!irq_n;
assign hrdata	=	output_reg;



endmodule	
