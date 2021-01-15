/*
用于cache操作的总线单元
*/
module cache_bus_unit(
input wire clk,
input wire rst,

//cache控制器逻辑
input wire write_through_req,	//请求写穿
input wire read_req,			//请求读一次
input wire read_line_req,		//请求读一行
input wire write_line_req,		//请求写一行
input wire [3:0]size,
input wire [63:0]pa,			//
input wire [63:0]wt_data,
output wire [63:0]line_data,
output wire [10:0]addr_count,
output wire line_write,			//cache写
output wire cache_entry_write,	//更新缓存entry
output wire trans_rdy,			//传输完成
output wire bus_error,			//访问失败

//AHB总线
//ahb
//ahb
output wire[63:0]haddr,
output wire hwrite,
output wire[2:0]hsize,
output [2:0]hburst,
output [3:0]hprot,
output [1:0]htrans,
output hmastlock,
output reg[63:0]hwdata,

input wire hready,
input wire hresp,
input wire hreset_n,
input wire [63:0]hrdata,

input wire bus_ack,		//总线允许使用
output wire bus_req		//总线请求使用

);
//ahb操作
parameter nseq = 2'b10;
parameter idle = 2'b00;
parameter seq  = 2'b11;

//TODO 重构异步Cache总线
//TODO 确认写回状态机完成无误
//TODO 写入：计数器直接接入，1CLK后打出前序计数值SSRAM数据
//ahb burst
parameter Single=3'b000;
parameter INCR  =3'b001;
//主状态机
parameter stb  = 4'b0000;
parameter pacov= 4'b0001;		//页面转换，进行此操作时AHB总线交给MMU控制
parameter wr_ap  = 4'b0010;		//写入发地址
parameter wr_dp  = 4'b0011;		//写入发数据
parameter rd_ap  = 4'b0100;		//读取发地址
parameter rd_dp  = 4'b0101;		//读取收数据
parameter rb_ap= 4'b1001;		//read burst 批量读入，阶段0，使用一个nseq开启seq传输
parameter rb_dp= 4'b1010;		//read burst 阶段1，使用seq连续传输，直到最后一个地址
parameter rb_dl= 4'b1011;		//read burst 阶段2，末尾最后一个数据传输
parameter wb_ap= 4'b1100;		//WR burst 批量写入，阶段0，使用一个nseq开启seq传输
parameter wb_dp= 4'b1101;		//WR burst 阶段1，使用seq连续传输，直到最后一个地址
parameter wb_dl= 4'b1110;		//WR burst 阶段2，末尾最后一个数据传输
parameter acc_fault=4'b1111;	//访问失败

reg [3:0]statu;					//状态机

reg [7:0]addr_counter;				//偏移地址计数器
reg [63:0]haddr_temp;
wire [7:0]last_addr;				//cache地址寄存器，在写入模式下需要利用该寄存器延迟一拍


//主状态机萝莉
always@(posedge clk)begin
	if(rst)begin
		statu <= stb;
	end
	else begin
		case(statu)
			//当请求占用总线时，bus unit等待
			stb:				if(!bus_ack)begin
									statu	<=	statu;
								end
								else if(write_line_req)//TODO 写回应当绝对优先于读入
								begin
									statu<=wb_ap;
								end
								else if(read_line_req)
								begin
									statu	<=	rb_ap;
								end
								else if(read_req)
								begin
									statu	<=	rd_ap;
								end
								else if(write_through_req)
								begin
									statu	<=	wr_ap;
								end
				
			//连续读read burst
			rb_ap:	statu <= rb_dp;
			//连续写write burst
			wb_ap:	statu <= wb_dp;
			//单次写，打出TRANS和HBURST
			wr_ap:	statu <= wr_dp;
			//单次读
			rd_ap:	statu <= rd_dp;

			//当传输到最后一个数据时候，停止传输，并等待传输完成
			rb_dp:	statu <= hresp?acc_fault:((addr_counter==8'b11111111)&hready)?rb_dl:statu;		//特别注意，同步内存写入不需要延迟一个clk，但是读出需要延迟一个clk
			rb_dp:	statu <= hresp?acc_fault:((addr_counter==8'b11111111)&hready)?wb_dl:statu;		//特别注意，同步内存写入不需要延迟一个clk，但是读出需要延迟一个clk
			wr_dp:	statu <= hresp?acc_fault:hready?stb:statu;
			rd_dp:	statu <= hresp?acc_fault:hready?stb:statu;
	
	//状态机第三层
			rb_dl:	statu <= hresp?acc_fault:hready?stb:statu;
			wb_dl:	statu <= hresp?acc_fault:hready?stb:statu;
	//状态机第四层
			acc_fault:	statu <= stb;
			default: statu<= stb;
		endcase
	end	
end

//addr_counter
//addr_counter在计到顶之后停止计数,并等待状态回到stb进行清零
always@(posedge clk)begin
	if(rst|(statu==stb))begin
		addr_counter <= 8'b0;
	end
	
	else if(addr_counter==8'b11111111)begin
		addr_counter <= addr_counter;
	end
	else if((statu==rb_ap)|(statu==rb_dp))begin
		addr_counter <= hready?(addr_counter + 8'b1):addr_counter;
	end
end	
assign last_addr 	= addr_counter - 8'b1;
//从cache写入到内存里的时候，因为同步储存器读取需要一个clk的延迟，故在sync且准备好时候始终保持cache_counter和addr_counter一致
//由于AHB总线总是在第二个周期给出应答信号，此时addr counter已经自动+1，故切换到上一个地址
//
assign line_write = ((statu==rb_dp)|(statu==rb_dl))?hready:1'b0;
assign addr_count	= ((statu==rb_dl)|(statu==wb_dl)) ? {addr_counter,3'b0} : {last_addr,3'b0};

//AHB总线
//AHB输出寄存器
always@(posedge clk)begin
	if(rst)begin
		hwdata		<=	64'b0;
		haddr_temp	<=	64'b0;
	end
	else if(statu==wr_ap|statu==wb_ap|statu==wb_dp)
	begin
		hwdata		<=	wt_data;
		haddr_temp	<=	pa;
	end
end

assign haddr	=	(read_line_req|write_line_req) ? 
							{haddr_temp[63:11],addr_counter,3'b0} : haddr_temp;
assign hwrite	= (statu==wr_ap|statu==wb_ap|statu==wb_dp);

assign hsize[0]	= size[1] | size[3];
assign hsize[1]	= size[2] | size[3];
assign hsize[2] = 1'b0;

assign hburst	= ((statu==wr_ap)|(statu==rd_ap))?Single:
					((statu==rb_ap)|(statu==rb_dp)|(statu==wb_ap)|(statu==wb_dp))?
																		INCR:Single;
assign hprot 	= 4'b0011;
assign htrans	= ((statu==wr_ap)|(statu==rd_ap)|(statu==rb_ap)|(statu==wb_ap))?
														nseq:
														((statu==rb_dp|statu==wb_dp))?seq:idle;	//Burst传输第一个是NSEQ
assign hmastlock= 1'b0;

//cache控制器逻辑

assign line_data			=	hrdata;
assign cache_entry_write	=	trans_rdy & read_line_req;	//更新缓存entry
assign trans_rdy			=	((statu==rd_dp)|(statu==wr_dp)|(statu==rb_dl)|(statu==wb_dl))?hready:1'b0;		//传输完成
assign bus_error			=	(statu==acc_fault);			//访问失败
assign bus_req				=	write_through_req | write_line_req | read_line_req | read_req;



endmodule













