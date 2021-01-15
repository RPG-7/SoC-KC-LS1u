
module biu(
//csr
input wire clk,
input wire rst,
//csr信号
input wire [63:0]satp,			//页表基地址
input wire sum,					//supervis-user访问允许
input wire mxr,					//禁用执行位

//pmp检查信号
//没有PMP 告辞

//if信号
input wire [3:0]if_priv,		//if权限，和机器当前权限相同
input wire [63:0]addr_if,
input wire rd_ins,				//取指令信号
output wire [63:0]ins_read,

output wire ins_acc_fault, 		//指令访问失败
//output wire ins_page_fault,		//指令页面错误
output wire cache_ready_if,		//cache准备好信号


//ex信号
input wire unpage,				//只使用物理地址
input wire [3:0]ex_priv,		//ex权限，0001=U 0010=S 0100=H 1000=M 
input wire [63:0]addr_ex,
input wire [63:0]data_write,
output wire[63:0]data_read,
input wire [3:0]size,			//0001=1Byte 0010=2Byte 0100=4Byte 1000=8Byte other=fault			
input wire l1i_reset,			//缓存刷新信号，用于执行fence指令的时候使用
input wire l1d_reset,			//缓存载入信号，用于执行fence.vma时候和cache_flush配合使用
input wire read,				//读数据信号
input wire write,				//写数据信号

output wire load_acc_fault,
output wire store_acc_fault,
output wire cache_ready_ex,		//cache数据准备好
output wire uncache_data_rdy,	//不可cache的数据准备好

//AHB信号
output wire [63:0]haddr,
output wire hwrite,
output wire [2:0]hsize,
output wire [2:0]hburst,
output wire [1:0]htrans,
output wire hmastlock,
output wire [63:0]hwdata,

input wire hready,
input wire hresp,
input wire hreset_n,
input wire [63:0]hrdata,

input wire bus_master_ack,
output wire bus_master_req
);

wire ins_acc_fault0;
wire ins_acc_fault1;
//TODO 重构，共用AHB-BIU，内部使用SSRAM总线，追加仲裁
//L1I D与L1_bu连接
//L1-I
wire I_write_through_req;	//请求写穿
wire I_read_req;			//请求读一次
wire I_read_line_req;		//请求读一行
wire [3:0]I_size;
wire [63:0]I_pa;			//
wire [63:0]I_wt_data;
wire [63:0]I_line_data;
wire [10:0]I_addr_count;
wire I_line_write;			//cache写
wire I_cache_entry_write;	//更新缓存entry
wire I_trans_rdy;			//传输完成
wire I_bus_error;			//访问失败
//L1-D
wire D_write_through_req;	//请求写穿
wire D_read_req;			//请求读一次
wire D_read_line_req;		//请求读一行
wire [3:0]D_size;
wire [63:0]D_pa;			//
wire [63:0]D_wt_data;
wire [63:0]D_line_data;
wire [10:0]D_addr_count;
wire D_line_write;			//cache写
wire D_cache_entry_write;	//更新缓存entry
wire D_trans_rdy;			//传输完成
wire D_bus_error;			//访问失败
//L1 bus unit
wire write_through_req;	//请求写穿
wire read_req;			//请求读一次
wire read_line_req;		//请求读一行
wire [3:0]bu_size;
wire [63:0]pa;			//
wire [63:0]wt_data;
wire [63:0]line_data;
wire [10:0]addr_count;
wire line_write;			//cache写
wire cache_entry_write;	//更新缓存entry
wire trans_rdy;			//传输完成
wire bus_error;			//访问失败


//TLB bu ahb
wire [63:0]L1_bu_haddr;
wire L1_bu_hwrite;
wire [2:0]L1_bu_hsize;
wire [2:0]L1_bu_hburst;
wire [3:0]L1_bu_hprot;
wire [1:0]L1_bu_htrans;
wire L1_bu_hmastlock;
wire [63:0]L1_bu_hwdata;

wire L1_bu_hready;
wire L1_bu_hresp;
wire L1_bu_hreset_n;
wire [63:0]L1_bu_hrdata;

wire L1_bu_bus_ack;		//总线允许使用
wire L1_bu_bus_req;		//总线请求使用


l1				L1_I(
//配置信号
.cache_only			(1'b1),
.cacheable          (1'b1),
.clk				(clk),
.rst				(rst),

//访问信号
.read				(1'b0),
.write				(1'b0),
.execute			(rd_ins),
.L1_clear			(l1i_reset),			//L1缓存清零，用于fence指令同步数据

.size				(4'b1000),				//


.addr_pa			(addr_if),
.data_write			(64'b0),
.data_read			(ins_read),
//应答通道
.load_acc_fault		(),
.store_acc_fault	(),
.ins_acc_fault		(ins_acc_fault0),
.cache_data_ready	(cache_ready_if),	//可缓存的数据准备好
.uncache_data_ready	(ins_acc_fault1),	//不可缓存的数据准备好

//cache控制器逻辑
.read_line_req		(I_read_line_req),		//请求读一行
.L1_size			(I_size),
.pa					(I_pa),			//
.line_data			(I_line_data),
.addr_count			(I_addr_count),
.line_write			(I_line_write),			//cache写
.cache_entry_write	(I_cache_entry_write),	//更新缓存entry
.trans_rdy			(I_trans_rdy),			//传输完成
.bus_error			(I_bus_error)			//访问失败
);

wire cacheable_i,D_write_line_req,write_line_req;
cacheable_lut DCACHE_LUT //ATTENTION:NEEDS TO BE CONFIGURED ACCORDING TO MEMMAP
(
    .addr(addr_ex),
    .cacheable(cacheable_i)
);
l1d				L1_D(
//配置信号
.cache_only			(1'b0),
.cacheable          (cacheable_i)  ,
.clk				(clk),
.rst				(rst),

//访问信号
.read				(read),
.write				(write),
.execute			(1'b0),
.L1_clear			(l1d_reset),			//L1缓存清零，用于fence指令同步数据
.vpu_access         (vpu_access),
.size				(size),				//


.force_sync(force_sync),      //TO EX 内存同步握手
.sync_ok(sync_ok),

.addr_pa			(addr_ex),
.data_write			(data_write),
.data_read			(data_read),
.vpu_write          (vpu_write),
.vpu_read           (vpu_read),
//应答通道
.load_acc_fault		(load_acc_fault),
.store_acc_fault	(store_acc_fault),
//.ins_acc_fault		(ins_acc_falt),
.cache_data_ready	(cache_ready_ex),	//可缓存的数据准备好
.uncache_data_ready	(uncache_data_rdy),	//不可缓存的数据准备好

//cache控制器逻辑
.write_through_req	(D_write_through_req),	//请求写穿
.write_line_req     (D_write_line_req),		//脏页写回
.read_req			(D_read_req),			//请求读一次
.read_line_req		(D_read_line_req),		//请求读一行
.L1_size			(D_size),
.pa					(D_pa),			//
.wt_data			(D_wt_data),
.line_data			(D_line_data),
.addr_count			(D_addr_count),

.line_write			(D_line_write),			//cache写
.cache_entry_refill	(D_cache_entry_write),	//更新缓存entry
.trans_rdy			(D_trans_rdy),			//传输完成
.bus_error			(D_bus_error)			//访问失败
);
//BUS REQ MUX
bu_req_mux		cache_req_mux(
.clk				(clk),
.rst				(rst),
//cache bug unit
//L1-I
.I_read_line_req		(I_read_line_req),		//请求读一行
.I_size					(I_size),
.I_pa					(I_pa),			//
.I_line_data			(I_line_data),
.I_addr_count			(I_addr_count),
.I_line_write			(I_line_write),			//cache写
.I_cache_entry_write	(I_cache_entry_write),	//更新缓存entry
.I_trans_rdy			(I_trans_rdy),			//传输完成
.I_bus_error			(I_bus_error),			//访问失败
//L1-D
.D_write_through_req	(D_write_through_req),	//请求写穿
.D_write_line_req	    (D_write_line_req),
.D_read_req				(D_read_req),			//请求读一次
.D_read_line_req		(D_read_line_req),		//请求读一行
.D_size					(D_size),
.D_pa					(D_pa),			//
.D_wt_data				(D_wt_data),
.D_line_data			(D_line_data),
.D_addr_count			(D_addr_count),
.D_line_write			(D_line_write),			//cache写
.D_cache_entry_write	(D_cache_entry_write),	//更新缓存entry
.D_trans_rdy			(D_trans_rdy),			//传输完成
.D_bus_error			(D_bus_error),			//访问失败
//L1 bus unit
.write_through_req		(write_through_req),	//请求写穿
.write_line_req		    (write_line_req),
.read_req				(read_req),			//请求读一次
.read_line_req			(read_line_req),		//请求读一行
.size					(bu_size),
.pa						(pa),			//
.wt_data				(wt_data),
.line_data				(line_data),
.addr_count				(addr_count),
.line_write				(line_write),			//cache写
.cache_entry_write		(cache_entry_write),	//更新缓存entry
.trans_rdy				(trans_rdy),			//传输完成
.bus_error				(bus_error)				//访问失败
);

//L1 bus unit
cache_bus_unit		L1_bus_unit(
.clk					(clk),
.rst					(rst),

//cache控制器逻辑
.write_through_req		(write_through_req),	//请求写穿
.write_line_req		    (write_line_req),
.read_req				(read_req),			//请求读一次
.read_line_req			(read_line_req),		//请求读一行
.size					(bu_size),
.pa						(pa),			//
.wt_data				(wt_data),
.line_data				(line_data),
.addr_count				(addr_count),
.line_write				(line_write),			//cache写
.cache_entry_write		(cache_entry_write),	//更新缓存entry
.trans_rdy				(trans_rdy),			//传输完成
.bus_error				(bus_error),				//访问失败

//AHB总线
//ahb
.haddr					(L1_bu_haddr),
.hwrite					(L1_bu_hwrite),
.hsize					(L1_bu_hsize),
.hburst					(L1_bu_hburst),
.hprot					(L1_bu_hprot),
.htrans					(L1_bu_htrans),
.hmastlock				(L1_bu_hmastlock),
.hwdata					(L1_bu_hwdata),

.hready					(L1_bu_hready),
.hresp					(L1_bu_hresp),
.hreset_n				(),
.hrdata					(L1_bu_hrdata),

.bus_ack				(L1_bu_bus_ack),		//总线允许使用
.bus_req				(L1_bu_bus_req)	//总线请求使用

);

//对外AHB总线
assign haddr	=	L1_bu_haddr;
assign hwrite	=	L1_bu_hwrite;
assign hsize	=	L1_bu_hsize;
assign hburst	=	L1_bu_hburst;
assign hprot	=	L1_bu_hprot;
assign htrans	=	L1_bu_htrans;
assign hmastlock=	L1_bu_hmastlock;
assign hwdata	=	L1_bu_hwdata;
assign bus_master_req   =   L1_bu_bus_req;
//L1-bu
assign L1_bu_hready		=	hready;
assign L1_bu_hresp		=	hresp;
assign L1_bu_hreset_n	=	hreset_n;
assign L1_bu_hrdata		=	hrdata;
assign L1_bu_bus_ack    =   bus_master_ack
//bu mux

assign ins_acc_fault	=	ins_acc_fault0 | ins_acc_fault1;

endmodule

