//Generic unified Directly Mapped L1-I design 
//forked from HGA-101 project, "optimized" for KC-LS1U-SoC project 
//To shrink the SoC into GW1N-1, we use load/store r/w through only 
module l1_ionly
#(
    parameter ASYNC_BUS_ENABLE=0
	,ENTRY_NUM=8
	,CACHE_DEPTH=1024 //2×1K BRAM
	,ADDR_WIDTH=24//寻址空间
	,DATA_WIDTH=8	//WIP 单个SRAM的位宽
	,INSTR_WIDTH=16
)
(
//配置信号
//input cacheable,
input clk,
input bclk,
input rst,

//CPU侧访问信号
input read,
input write,
input execute,
input L1_clear,
input cwait,

input [ADDR_WIDTH-1:1]addr_pa_i,
input [ADDR_WIDTH-1:0]addr_pa_d,
input [7:0]host_wdata,
output [7:0]host_rdata,
output [15:0]instr_read,
//应答通道
output load_acc_fault,
output store_acc_fault,
output ins_acc_fault,
output cache_data_ready,	//可缓存的数据准备好
output uncache_data_ready,	//不可缓存的数据准备好
//cache控制器逻辑
output write_through_req,	//请求写穿
output read_req,			//请求读一次
output read_line_req,		//请求读一行
output [ADDR_WIDTH-1:0]bus_pa,			//
output [7:0]bus_wdata,
input [7:0]bus_rdata,
input [LINE_WID:0]addr_count,
input line_write,			//cache写
input bus_trans_finish,			//传输完成
input bus_error			//访问失败
);
//Cache 相关参数
localparam 	ENTRYSEL_WIDTH = ((ENTRY_NUM > 1) ? $clog2(ENTRY_NUM) : 1)
			,CADR_WIDTH=$clog2(CACHE_DEPTH) 
			,LINE_SIZE=CACHE_DEPTH/ENTRY_NUM
			,LINE_WID=$clog2(LINE_SIZE)
			,TAG_WID=ADDR_WIDTH-CADR_WIDTH;
//状态机
localparam stb			=	4'b0000;		//等待状态
localparam read_line	=	4'b0001;		//读一行
localparam read_singal	=	4'b0010;		//单次读
localparam write_singal	=	4'b0011;		//写一次
localparam access_fault	=	4'b0111;		//访问失败

reg [3:0]main_state;
//FSM控制信号 CCLK域
wire bus_error_acq;
wire trans_finish;
wire cache_refill_finish;	//更新缓存entry
//缓存控制信号 CCLK域
wire [1:0]cachemem_bsel;		//低位宽块写入使能
wire [ENTRYSEL_WIDTH-1:0]read_entry;	//读块选择 
wire [ENTRYSEL_WIDTH-1:0]write_entry;	//写块选择
wire [CADR_WIDTH-1:0]cachemem_raddr;
wire [15:0]cachemem_rdata;
wire cache_miss;
//TODO 异步Cache界面 BCLK域
wire [CADR_WIDTH-1:0]cachemem_waddr;
wire [15:0]cachemem_wdata;
wire cachemem_we;	//cache写入使能信号
wire cachemem_wclk;
//CPU侧主状态机
always@(posedge clk)begin
	if(rst)begin
		main_state	<=	stb;
	end
	else 
	begin
		case(main_state)
		stb			:	if(cache_miss) main_state	<=	read_line;//既然是I$自然能访问的区域一定是内存 
						else if(read) main_state	<=	read_singal;//如果是读操作，那单次读 
						else if(write) main_state	<=	write_singal;//如果是写操作，那单次写 	
		read_line	:	main_state	<=	bus_error_acq ? access_fault : (trans_finish ? stb : main_state);
		read_singal	:	main_state	<=	bus_error_acq ? access_fault : (trans_finish ? stb : main_state);
		write_singal:   main_state	<=	bus_error_acq ? access_fault : (trans_finish ? stb : main_state);		
		access_fault:	main_state	<=	stb;
		default		:	main_state	<=	stb;
		endcase
	end
end
//tag管理逻辑
wire [TAG_WID:0]core_tagaddr;
wire [ENTRYSEL_WIDTH-1:0]core_entaddr;
assign core_tagaddr=addr_pa_i[ADDR_WIDTH-1:CADR_WIDTH];
assign core_entaddr=addr_pa_i[CADR_WIDTH-1:7];//TODO configurable
//TODO 这玩意应该全在CORE CLK时钟域，尽可能把握手输入控制在此前
defparam tag_manager.ENTRY_NUM=ENTRY_NUM;
defparam tag_manager.TAG_WID=14;
defparam tag_manager.WBACK_ENABLE=1'b0;
tag_arbiter_dm tag_manager
(
//entry0
.clk(clk),
.rst(rst),
.entry_read(execute),   //Core interface
.address_tag(core_tagaddr),	
.address_ent(core_entaddr),
.valid_clear(L1_clear), //flush
.refill_tag(core_tagaddr),//BIU interface
.line_refill(cache_refill_finish),
.line_miss(cache_miss),//refill req
.entry_replace_sel(write_entry), //生成cache line写入地址	
.entry_select_addr(read_entry),//addr for access //缓存块选择
.entry_wthru(1'b0),	//L1I不需要
.entry_wback(1'b0),
.writeback_ok(1'b1)
);

//L1缓存
//TODO async cache-bus interface(decouple bus and core speed)
defparam l1_ram.datawidth=16;
defparam l1_ram.cache_depth=CACHE_DEPTH;
assign #1 cachemem_wdata={bus_rdata,bus_rdata};
assign #1 cachemem_bsel={addr_count[0],!addr_count[0]};
cachemem 				l1_ram
(
	.cwait			(cwait),
    .raddr			(cachemem_raddr),
    .waddr			(cachemem_waddr),
    .di				(cachemem_wdata),
    .we				(cachemem_we),
    .bsel			(cachemem_bsel),
    .dato			(cachemem_rdata),
	.wclk			(cachemem_wclk),
    .rclk			(clk)//
);

//CPU侧准备好信号
assign #1 cache_data_ready	=	(!cache_miss) & execute ;	//&trans_finish
assign #1 uncache_data_ready=	(main_state==read_singal)|(main_state==write_singal)&trans_finish;
//CPU侧地址数据
assign #1 cachemem_raddr	={read_entry,addr_pa_i[LINE_WID:1]};
assign #1 instr_read=cachemem_rdata;
assign #1 host_rdata=bus_rdata;
	generate 
	if(ASYNC_BUS_ENABLE) 
	begin : ASYNC_BUS
		//TODO Handshake logic
		reg [1:0]  busfin_sample,//传输完成采样 B->C
					rtreq_sample,//读穿请求采样 C->B
					wtreq_sample,//写穿请求采样 C->B
					rlreq_sample;//填充请求采样 C->B
		assign trans_finish=busfin_sample[1];			
		always @(posedge clk or posedge rst) 
		begin
			if(rst)busfin_sample<=2'b00;
			else busfin_sample<={busfin_sample[0],bus_trans_finish};
		end
		assign read_line_req=rlreq_sample[1];
		assign read_req=rtreq_sample[1];
		assign write_through_req=wtreq_sample[1];
		always @(posedge bclk or posedge rst) 
		begin
			if(rst)
			begin
				rtreq_sample<=2'b00;
				wtreq_sample<=2'b00;
				rlreq_sample<=2'b00;
			end
			else 
			begin
				rtreq_sample<={rtreq_sample[0],(main_state==write_singal)};
				wtreq_sample<={wtreq_sample[0],(main_state==read_singal)};
				rlreq_sample<={rlreq_sample[0],(main_state==read_line)};
			end
		end
	end
	else 
	begin : SYNC_BUS
		//L1写地址由当前是否处在缓存行更新阶段生成，如果缓存行没有被更新，地址是正常地址
		assign #1 cachemem_waddr={write_entry,addr_count[LINE_WID:1]}; //纯L1I$无需写入(假定无自修改代码)
		assign #1 cachemem_we	=(main_state==read_line) ? line_write : 1'b0;//cache_write
		assign #1 bus_error_acq=bus_error;
		assign #1 trans_finish=bus_trans_finish;
		assign #1 cache_refill_finish=trans_finish&cache_miss;
		//访问失败信号
		assign #1 load_acc_fault	=	(main_state==access_fault) & read;
		assign #1 store_acc_fault	=	(main_state==access_fault) & write;
		assign #1 ins_acc_fault	=	(main_state==access_fault) & execute;
		//cache控制器逻辑
		assign #1 write_through_req=	(main_state==write_singal);	//请求写穿
		assign #1 read_req	=	(main_state==read_singal);			//请求读一次
		assign #1 read_line_req	=	(main_state==read_line);		//请求读一行
		assign #1 bus_pa=(read_req|write_through_req)?addr_pa_d:{addr_pa_i,1'b0};
		assign #1 bus_wdata=host_wdata;	

		assign cachemem_wclk=clk;
	end
endgenerate

endmodule		
