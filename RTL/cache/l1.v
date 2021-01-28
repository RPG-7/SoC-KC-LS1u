//Generic Constant word width access L1-D
//forked from HGA-101 project, optimized for KC-LS1U-SoC project 
module l1
#(
    parameter ENTRY_NUM=16
	,CACHE_DEPTH=1024 //1×1K BRAM
	,ADDR_WIDTH=24//寻址空间
	,DATA_WIDTH=8	//WIP 单个SRAM的位宽
	
	//,LANE_NUM=1 //WIP 可配置大位宽cache
	//,LANESEL_WID=//WIP 几根SRAM片选？
	
)
(
//配置信号
input wire cacheable,
//input wire cache_only,
input wire clk,
input wire rst,

//访问信号
input wire read,
input wire write,
input wire execute,
input wire L1_clear,
//input wire [BSEL_WIDTH-1:0]size,		//since this is 8-bit, we don't need this
input wire force_sync,
output sync_ok,

input wire [ADDR_WIDTH-1:0]addr_pa,
input wire [DATA_WIDTH-1:0]data_write,
output wire [DATA_WIDTH-1:0]data_read,
//应答通道
output wire load_acc_fault,
output wire store_acc_fault,
output wire ins_acc_fault,
output wire cache_data_ready,	//可缓存的数据准备好
output wire uncache_data_ready,	//不可缓存的数据准备好
output wire access_ready,
//cache控制器逻辑
output wire write_through_req,	//请求写穿
output wire read_req,			//请求读一次
output wire read_line_req,		//请求读一行
output wire write_line_req,		//脏页写回
//output wire [3:0]L1_size,
output wire [ADDR_WIDTH-1:0]pa,			//
output wire [DATA_WIDTH-1:0]wt_data,
input wire [DATA_WIDTH-1:0]line_data,
input wire [7:0]addr_count,
input wire line_write,			//cache写
input wire cache_entry_refill,	//更新缓存entry
input wire trans_rdy,			//传输完成
input wire bus_error			//访问失败
);
localparam ENTRYSEL_WIDTH = ((ENTRY_NUM > 1) ? $clog2(ENTRY_NUM) : 1);
localparam BSEL_WIDTH=(((DATA_WIDTH/8) > 1) ? $clog2(DATA_WIDTH/8) : 1);
localparam CADR_WIDTH=$clog2(CACHE_DEPTH)+BSEL_WIDTH ;
//状态机
localparam stb			=	4'b0000;		//等待状态
localparam read_line	=	4'b0001;		//读一行
localparam read_singal	=	4'b0010;		//单次读
localparam write_singal	=	4'b0011;		//写一次
localparam access_fault	=	4'b0111;		//访问失败
localparam wb_replace	=	4'b1000;		//替换页写回
localparam wb_seqence	=	4'b1001;		//全写回

reg [3:0]main_state;

//TODO 增加脏位&写回策略
//TODO 具体的写回通路仲裁，写回挂起访问
//TODO 脏块管理逻辑，如何消除脏块？脏块握手？
/*situations of replace_dirty:
1. tag invalid but dirty
2. LFU replace but dirty
3. forced sync ,write back all dirty
*/
wire cache_miss;
//wire access_ready;
wire writeback;
assign access_ready	=	cache_data_ready | uncache_data_ready;
assign writeback=(main_state==wb_replace|main_state==wb_seqence);
//缓存控制信号
wire [DATA_WIDTH-1:0]cache_read;	
wire cache_write;
wire we;				//最终的cache写入信号

wire [ENTRYSEL_WIDTH-1:0]read_block_sel;	//读块选择 00=entry0…………
wire [ENTRYSEL_WIDTH-1:0]write_block_sel;	//写块选择
wire [CADR_WIDTH-1:0]read_addr;
wire [CADR_WIDTH-1:0]write_addr;
wire [DATA_WIDTH-1:0]di;
//wire [63:0]dout;
wire [DATA_WIDTH-1:0]write_data;
wire line_dirty,writeback_ok;
assign writeback_ok=(writeback)&trans_rdy;
assign sync_ok=(main_state==wb_seqence)&trans_rdy&(!line_dirty);
//cache更新


//主状态机
always@(posedge clk)begin
	if(rst)begin
		main_state	<=	stb;
	end
	else 
	begin
		case(main_state)
		stb			:	if(cache_miss)
						begin		//如果可以被缓存，那么就进入缓存；如果不能被缓存，那就进行单次读写
							main_state	<=	cacheable ? ((line_dirty)?wb_replace:read_line) : 
										(read|execute) ? read_singal : write_singal;
						end
						else if(force_sync)
							main_state	<=	wb_seqence;
						else if(write)
						begin		//如果是读操作，那单次读
							main_state	<=	write_singal;
						end
		wb_replace	:	main_state	<=	bus_error ? access_fault : (trans_rdy ? read_line : main_state);	
		wb_seqence	:	main_state	<=	bus_error ? access_fault : ((!line_dirty) ? stb : main_state);			
		read_line	:	main_state	<=	bus_error ? access_fault : (trans_rdy ? stb : main_state);
		read_singal	:	main_state	<=	bus_error ? access_fault : (trans_rdy ? stb : main_state);
		write_singal:   main_state	<=	bus_error ? access_fault : (trans_rdy ? stb : main_state);
		access_fault:	main_state	<=	stb;
		default		:	main_state	<=	stb;
		endcase
	end
end
//tag管理逻辑
defparam tag_manager.ENTRY_NUM=ENTRY_NUM;
defparam tag_manager.TAG_MSB=ADDR_WIDTH;
defparam tag_manager.TAG_LSB=$clog2(CACHE_DEPTH/ENTRY_NUM);//1K per page
defparam tag_manager.WBACK_ENABLE=1'b0;
tag_arbiter_wa tag_manager
(
//entry0
.clk(clk),
.rst(rst),
.entry_read(read|execute),   //Core interface
.entry_wthru(write),	//可选写穿/写回策略 
.entry_wback(1'b0),
.access_addr(addr_pa),	

.valid_clear(L1_clear), //flush
.force_sync(force_sync),//sync cache with memory(write back all dirty line)
.writeback_ok(writeback_ok),//data block write back complete, from cache BU
.replace_dirty(line_dirty), //page dirty, need to write back first
.refill_pa(pa),//BIU interface
.line_refill(cache_entry_refill),
.line_miss(cache_miss),//refill req
.entry_replace_sel(write_block_sel), //生成cache line写入地址	
.entry_select_addr(read_block_sel)//addr for access //缓存块选择
);
wire [(DATA_WIDTH/8)-1:0]byte_sel;
//缓存控制信号	
// byte_sel			byte_sel_unit(
// .addr				(addr_pa[2:0]),				//address
// .size				(size),						//0001=1Byte;0010=2Byte;0100=4Byte;1000=8Byte
// .mask				((main_state==read_line)),	//当进行L1连续行写入时，打开掩码，即全部字节选中
// .bsel				(byte_sel)
// );
//当对内存读写成功，cache才可以被写入
assign cache_write	=	write & (trans_rdy);
assign di			=	(main_state==read_line) ? line_data : data_write;
//如果是不可缓存的数据，直接将line data打入内部
assign data_read	=	(main_state==read_singal) ? line_data	: cache_read; 	
//生成缓存地址
//L1读地址由命中情况生成
wire we_u,we_d;
assign read_addr	=	(writeback) ?{write_block_sel,addr_count[7:1]}:{read_block_sel,addr_pa[7:1]};
//L1写地址由当前是否处在缓存行更新阶段生成，如果缓存行没有被更新，地址是正常地址
assign write_addr	=	(main_state==read_line) ? {write_block_sel,addr_count[7:1]} : read_addr;
//如果是进行行更新，写入信号切换到外部cache控制器
assign we	=	(main_state==read_line) ? line_write : cache_write;
assign write_data=di;
assign byte_sel={(DATA_WIDTH/8){read|write|execute}};//TODO THIS IS JUST A TEMPORARY 
//L1缓存
//since this is 1R1W SRAM,write port needs aribter
//TODO make this cache WB type means we need dirty bit and port arbiter
//TODO async cache-bus interface(decouple bus and core speed)
defparam l1_ram.datawidth=DATA_WIDTH;
defparam l1_ram.cache_depth=CACHE_DEPTH;
cachemem 				l1_ram
(
    .raddr			(read_addr),
    .waddr			(write_addr),
    .di				(write_data),
    .we				(we),
    .bsel			(byte_sel),
    .dato			(cache_read),
    .clk			(clk)
);
//准备好信号
assign cache_data_ready	=	(!cache_miss) & (read | execute | write&trans_rdy);
assign uncache_data_ready=	(main_state==read_singal) & trans_rdy;
//访问失败信号
assign load_acc_fault	=	(main_state==access_fault) & read;
assign store_acc_fault	=	(main_state==access_fault) & write;
assign ins_acc_fault	=	(main_state==access_fault) & execute;

//cache控制器逻辑
assign write_through_req=	(main_state==write_singal);	//请求写穿
assign write_line_req	=	(writeback);	
assign read_req			=	(main_state==read_singal);			//请求读一次
assign read_line_req	=	(main_state==read_line);		//请求读一行
//assign L1_size	=	size;			
assign pa	=	addr_pa;
assign wt_data=	(writeback)?data_read:data_write;	
endmodule		
