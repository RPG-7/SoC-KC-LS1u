//32b Addr+ 8b Data FSB总线
//允许最大256b的burst 传输
//Core 24b访存+8b PAE

module fsb8(

//ahb 接口
input hclk,
input hreset_n,
input hsel,
input [1:0]htrans,
input hwrite,
input [31:0]haddr,	//本桥只占用地址的低32位空间
input [7:0]hwdata,
output [7:0]hrdata,
output hresp,
output hready,
//fsb16信号
output clk,
output rst_n,
output ale,
output cs,
output cmd,
output reg typ,//SINGLE/BLOCK
output wr_n,
input rdy_n,
input irq_n,
output reg Hi_z,	//拉高之后表示高阻态
output [7:0]AAH8,
output [7:0]AD_out,
input [7:0]AD_in,
//对内部中断控制器信号
output FSB_irq

);
//AHB传输参数
localparam Idle  = 2'b00;
localparam Burst = ;
//状态机
localparam stb 		= 3'h0;	//等待状态
localparam addrh	= 3'h1; //地址帧 ALE
localparam dummy	= 3'h2; //空帧(总线换向)
localparam reads	= 3'h3; //读帧
localparam readb	= 3'h4;	//连续读
localparam writs	= 3'h5; //写帧
localparam writb	= 3'h6; //连续写
localparam commd	= 3'h7; //写高位地址/总线桥指令 {8'hxx,8'h00}=写H8地址

reg[2:0]state;

reg [7:0]H8latch;
reg [7:0]M16latch;	
reg [7:0]output_reg;	//输出寄存器	
reg [15:0]DATA_reg;		//AD复用寄存器

//主状态机
always@(posedge hclk)begin
	if(!hreset_n)begin
		state <= stb;
	end
	else begin
		case(state)
			stb				:	if(hsel & (htrans!=Idle) & !hwrite)begin
									state	<=	read_addr_frame0;
								end
								else if(hsel & (htrans!=Idle) & hwrite)begin
									state	<=	write_addr_frame0;
								end
	//地址帧
			read_addr_frame0:	state <= read_addr_frame1;
	
			read_addr_frame1:	state <= nop_frame;
	
			write_addr_frame0:	state <= write_addr_frame1;
	
			write_addr_frame1:	state <= write_frame;
	
			nop_frame		:	state <= read_frame;
	
	//数据帧
	//一个AHB传输可能被分为多个小的数据帧进行传输，trans_ready信号指示了当前传输是否完成
	//发生了错误，马上转到stb状态
			read_frame		:	state <= (!rdy_n | !error_n) ? stb : state;
			write_frame		:	state <= (!rdy_n | !error_n) ? stb : state;
	
		default				:	state <= stb;
		endcase
	end
end
	
//输出到AHB寄存器
always@(posedge hclk)begin
	if(!rdy_n)begin
		output_reg	<= AD_in;
	end
end

//输出寄存器
always@(posedge hclk)begin
	if(state==write_addr_frame0)begin
		case(haddr[3:1])
			2'b00	:	DATA_reg	<=	hwdata[15:0];
			2'b01	:	DATA_reg	<=	hwdata[31:16];
			2'b10	:	DATA_reg	<=	hwdata[47:32];
			2'b11	:	DATA_reg	<=	hwdata[63:48];
		endcase
	end
end

//地址寄存器
always@(posedge hclk)begin
	if(hsel & (htrans!=Idle))begin
		ADDR_reg	<=	haddr[31:0];
	end
end

//高阻态指示寄存器
always@(posedge hclk)begin
	if(state==read_addr_frame1)begin	//当地址传输完成 进入高阻态
		Hi_z	<=	1'b1;
	end
	else if(state==stb)begin
		Hi_z	<=	1'b0;
	end
end
//FSB16信号
//fsb16信号
assign clk	 = hclk;
assign rst_n = hreset_n;
//地址帧时，进行地址使能
assign aen	 = (state==read_addr_frame0)|(state==read_addr_frame1)|(state==write_addr_frame0)|(state==write_addr_frame1);
//传输大小为8bit时，SIZE为0，否则SIZE=1
always@(posedge hclk)begin
	if(hsel & (htrans!=Idle))begin
		size	<=	(hsize!=3'b000);		//如果不是8位传输 那size=1
	end
	else if(!rdy_n)begin
		size	<=	1'b0;					//传输完成后复位
	end
end


assign wr_n	 = (state==write_addr_frame0) | (state==write_addr_frame1);

assign AD_out	=	(((state==read_addr_frame0)|(state==write_addr_frame0))	?ADDR_reg[15:0]	:16'b0) |
					(((state==read_addr_frame1)|(state==write_addr_frame1))	?ADDR_reg[31:16]:16'b0) |
					(((state==write_frame))									?DATA_reg		:16'b0) ;

//AHB响应
assign hresp	=	!error_n;
assign hready	=	!rdy_n;
assign FSB_irq	=	!irq_n;
assign hrdata	=	{output_reg,output_reg,output_reg,output_reg};



endmodule	
