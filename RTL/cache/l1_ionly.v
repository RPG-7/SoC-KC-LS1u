//Generic unified Directly Mapped L1-I design 
//forked from HGA-101 project, "optimized" for KC-LS1U-SoC project 
//To shrink the SoC into GW1N-1, we use load/store r/w through only 
module l1_ionly
#(
    parameter ENTRY_NUM=8
	,CACHE_DEPTH=1024 //2×1K BRAM
	,ADDR_WIDTH=24//寻址空间
	,DATA_WIDTH=8	//WIP 单个SRAM的位宽
	,INSTR_WIDTH=16
	//,LANE_NUM=1 //WIP 可配置大位宽cache
	//,LANESEL_WID=//WIP 几根SRAM片选？
)
(
//配置信号
//input cacheable,
input clk,
input rst,

//访问信号
input read,
input write,
input execute,
input L1_clear,

input [ADDR_WIDTH-1:0]addr_pa_d,
input [ADDR_WIDTH-1:1]addr_pa_i,
input [7:0]data_write,
output [7:0]data_read,
output [15:0]instr_read,
//应答通道
output load_acc_fault,
output store_acc_fault,
output ins_acc_fault,
output cache_data_ready,	//可缓存的数据准备好
output uncache_data_ready,	//不可缓存的数据准备好
output reg access_ready,
//cache控制器逻辑
output write_through_req,	//请求写穿
output read_req,			//请求读一次
output read_line_req,		//请求读一行
//output [3:0]L1_size,
output [ADDR_WIDTH-1:0]pa,			//
output [7:0]wt_data,
input [7:0]line_data,
input [LINE_WID:0]addr_count,
input line_write,			//cache写
input cache_entry_refill,	//更新缓存entry
input trans_rdy,			//传输完成
input bus_error			//访问失败
);
//状态机
localparam stb			=	4'b0000;		//等待状态
localparam read_line	=	4'b0001;		//读一行
localparam read_singal	=	4'b0010;		//单次读
localparam write_singal	=	4'b0011;		//写一次
localparam access_fault	=	4'b0111;		//访问失败
localparam 	ENTRYSEL_WIDTH = ((ENTRY_NUM > 1) ? $clog2(ENTRY_NUM) : 1)
			//,BSEL_WIDTH=(((DATA_WIDTH/8) > 1) ? $clog2(DATA_WIDTH/8) : 1)
			,CADR_WIDTH=$clog2(CACHE_DEPTH) 
			,LINE_SIZE=CACHE_DEPTH/ENTRY_NUM//*(INSTR_WIDTH/8)
			,LINE_WID=$clog2(LINE_SIZE) ;
reg [3:0]main_state;
wire cache_miss;
//wire writeback;
wire transfer_valid;
always@(posedge clk or negedge transfer_valid)//等待状态锁存
begin
	if(!transfer_valid)access_ready<=1'b0;
	else access_ready<=1'b1;
end
assign transfer_valid=(cache_data_ready | uncache_data_ready) ;//&(!(main_state==stb&(read|write)))
//缓存控制信号
wire [15:0]cache_read;	
wire we;				//最终的cache写入信号
assign instr_read=cache_read;
assign data_read=write_data;
wire [ENTRYSEL_WIDTH-1:0]read_block_sel;	//读块选择 00=entry0…………
wire [ENTRYSEL_WIDTH-1:0]write_block_sel;	//写块选择
wire [9:0]read_addr;
wire [9:0]write_addr;
wire [7:0]write_data;
//主状态机
always@(posedge clk)begin
	if(rst)begin
		main_state	<=	stb;
	end
	else 
	begin
		case(main_state)
		stb			:	if(cache_miss)
						begin		//既然是I$自然能访问的区域一定是内存
							main_state	<=	read_line;
						end
						else if(read)
						begin		//如果是读操作，那单次读
							main_state	<=	read_singal;
						end	
						else if(write)
						begin		//如果是写操作，那单次写
							main_state	<=	write_singal;
						end			
		read_line	:	main_state	<=	bus_error ? access_fault : (trans_rdy ? stb : main_state);
		read_singal	:	main_state	<=	bus_error ? access_fault : (trans_rdy ? stb : main_state);
		write_singal:   main_state	<=	bus_error ? access_fault : (trans_rdy ? stb : main_state);		
		access_fault:	main_state	<=	stb;
		default		:	main_state	<=	stb;
		endcase
	end
end
//wire [ADDR_WIDTH-1:0]addr_pa;//TODO 注意：此处字节编址
//assign addr_pa=
assign uncache_data_ready=	(main_state==read_singal)|
							(main_state==write_singal) & trans_rdy;

//访问失败信号
assign load_acc_fault	=	(main_state==access_fault) & read;
assign store_acc_fault	=	(main_state==access_fault) & write;
assign ins_acc_fault	=	(main_state==access_fault) & execute;

//cache控制器逻辑
assign write_through_req=	(main_state==write_singal);	//请求写穿
assign read_req			=	(main_state==read_singal);			//请求读一次
assign read_line_req	=	(main_state==read_line);		//请求读一行

//tag管理逻辑
defparam tag_manager.ENTRY_NUM=ENTRY_NUM;
defparam tag_manager.TAG_WID=14;
defparam tag_manager.WBACK_ENABLE=1'b0;
tag_arbiter_dm tag_manager
(
//entry0
.clk(clk),
.rst(rst),
.entry_read(execute),   //Core interface
.entry_wthru(1'b0),	//可选写穿/写回策略 
.address_tag(addr_pa_i[23:10]),	
.address_ent(addr_pa_i[9:7]),
.valid_clear(L1_clear), //flush
.refill_tag(pa[23:10]),//BIU interface
.line_refill(cache_entry_refill),
.line_miss(cache_miss),//refill req
.entry_replace_sel(write_block_sel), //生成cache line写入地址	
.entry_select_addr(read_block_sel)//addr for access //缓存块选择
);
//assign cache_write	=write & (trans_rdy);
//如果是不可缓存的数据，直接将line data打入内部
assign write_data	=(main_state==read_line) ? line_data : data_write;
//生成缓存地址
wire we_u,we_d;
assign read_addr	={read_block_sel,addr_pa_i[7:1]};
//L1写地址由当前是否处在缓存行更新阶段生成，如果缓存行没有被更新，地址是正常地址
assign write_addr	=(main_state==read_line) ? {write_block_sel,addr_count[7:1]} : read_addr;
//如果是进行行更新，写入信号切换到外部cache控制器
assign we	=(main_state==read_line) ? line_write : 1'b0;//cache_write
//L1缓存
//TODO async cache-bus interface(decouple bus and core speed)
//This might take 2 BRAMs
wire [15:0]cwrite_data;
wire [1:0]byte_sel;
defparam l1_ram.datawidth=16;
defparam l1_ram.cache_depth=1024;
assign cwrite_data={write_data,write_data};
assign byte_sel={!write_addr,write_addr};
cachemem 				l1_ram
(
    .raddr			({read_addr,1'b0}),
    .waddr			({write_addr,1'b0}),
    .di				(cwrite_data),
    .we				(we),
    .bsel			(byte_sel),
    .dato			(cache_read),
    .clk			(clk)
);
//准备好信号
assign cache_data_ready	=	(!cache_miss) & (execute &trans_rdy);	
assign pa	=	(read|write)?addr_pa_d:{addr_pa_i,1'b0};
assign wt_data=data_write;	
endmodule		
