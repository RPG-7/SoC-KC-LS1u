module CPU_LS1u
#(
    parameter CACHE_TYP = 2'b00
)
(
    input clk,rst,

    input cache_flush,//当存在MMU，切换页表须冲刷cache
    //Interrupt
	input INT,
    //input [5:0]INTCODE,//中断源编码
    input [23:0]IVEC_addr,//中断向量表基址
    output IN_ISP,//在中断服务程序中
    //Shrinked AHB
    output wire [23:0]haddr,
    output wire hwrite,
    output wire [2:0]hburst,
    output wire [1:0]htrans,
    output wire [7:0]hwdata,
    input wire hready,
    input wire hresp,
    input wire hreset_n,
    input wire [7:0]hrdata,
    input bus_ack,//this is for DMA as 2nd master
    output bus_req
);
wire [23:0]iaddr;
wire [15:0]instr;
wire [23:0]daddr;
wire dwrite;
wire dread;
wire [7:0]ddata_i;
wire [7:0]ddata_o;
wire icache_rdy;
wire dcache_rdy;
wire READY;
KC_LS1u_plus CORE
(
    .clk(clk),
    .rst(rst),
    .INT(INT),
    .WAIT(!READY),
    .IVEC_addr(IVEC_addr),//中断向量地址
    .IN_ISP(IN_ISP),//注意:这里的取值是字编址的！
    .iaddr(),//如果使用异步SRAM(ASRAM)，用这个
    .iaddr_next(iaddr),//但是基于FPGA中多见同步SRAM(SSRAM)，必须用PC_NEXT输出才保证取指正确
    .instr(instr),
    .daddr(daddr),
    .dwrite(dwrite),
    .dread(dread),
    .ddata_i(ddata_i),
    .ddata_o(ddata_o)
);
wire load_acc_fault;
wire store_acc_fault;
wire ins_acc_fault;
wire write_through_req;	//请求写穿
wire read_req;			//请求读一次
wire read_line_req;		//请求读一行
wire [23:0]pa;			//
wire [7:0]wt_data;
wire [7:0]line_data;
wire [6:0]addr_count;
wire line_write;			//cache写
wire cache_entry_refill;	//更新缓存entry
wire trans_rdy;			//传输完成
wire bus_error;			//访问失败
//Since KC-LS1U is not and never a RAM access intensive core, 
//seprate I$ D$ is not in consideration
generate
case (CACHE_TYP)
    2'b00 : begin : L1_I_Only
            l1_ionly L1CX(
            .clk(clk),
            .rst(rst),
            .read(dread),
            .write(dwrite),
            .execute(1'b1),
            .L1_clear(cache_flush),
            .addr_pa_d(daddr),
            .addr_pa_i(iaddr[22:0]),
            .data_write(ddata_o),
            .data_read(ddata_i),
            .instr_read(instr),
            .load_acc_fault(load_acc_fault),
            .store_acc_fault(store_acc_fault),
            .ins_acc_fault(ins_acc_fault),
            .access_ready(READY),
            //cache控制器逻辑
            .write_through_req(write_through_req),	//请求写穿
            .read_req(read_req),			//请求读一次
            .read_line_req(read_line_req),		//请求读一行
            .pa(pa),			//
            .wt_data(wt_data),
            .line_data(line_data),
            .addr_count(addr_count),
            .line_write(line_write),			//cache写
            .cache_entry_refill(cache_entry_refill),	//更新缓存entry
            .trans_rdy(trans_rdy),			//传输完成
            .bus_error(bus_error)			//访问失败
            );
            end
    default: begin : Unified_L1
            l1_unified L1_Cache
            (
            .cacheable((iaddr[23:16]!=8'hC0)&(daddr[23:16]!=8'hC0)),//64K peripheral space@0xC0xxxx
            .clk(clk),
            .rst(rst),
            .read(dread),
            .write(dwrite),
            .execute(1'b1),
            .L1_clear(cache_flush),
            .addr_pa_d(daddr),
            .addr_pa_i(iaddr[22:0]),
            .data_write(ddata_o),
            .data_read(ddata_i),
            .instr_read(instr),
            .load_acc_fault(load_acc_fault),
            .store_acc_fault(store_acc_fault),
            .ins_acc_fault(ins_acc_fault),
            .access_ready(READY),
            //cache控制器逻辑
            .write_through_req(write_through_req),	//请求写穿
            .read_req(read_req),			//请求读一次
            .read_line_req(read_line_req),		//请求读一行
            .pa(pa),			//
            .wt_data(wt_data),
            .line_data(line_data),
            .addr_count(addr_count),
            .line_write(line_write),			//cache写
            .cache_entry_refill(cache_entry_refill),	//更新缓存entry
            .trans_rdy(trans_rdy),			//传输完成
            .bus_error(bus_error)			//访问失败
            );
            end
    endcase
endgenerate
bus_unit AHB_INTERFACE
(
.clk(clk),
.rst(rst),

.write_through_req(write_through_req),	//请求写穿
.read_req(read_req),			//请求读一次
.read_line_req(read_line_req),		//请求读一行
.pa(pa),			//
.wt_data(wt_data),
.line_data(line_data),
.addr_count(addr_count),
.line_write(line_write),			//cache写
.cache_entry_refill(cache_entry_refill),	//更新缓存entry
.trans_rdy(trans_rdy),			//传输完成
.bus_error(bus_error),			//访问失败
//AHB总线
//ahb
.haddr(haddr),
.hwrite(hwrite),
.hburst(hburst),
.htrans(htrans),
.hwdata(hwdata),
.hready(hready),
.hresp(hresp),
.hreset_n(hreset_n),
.hrdata(hrdata),
.bus_ack(bus_ack),	//总线允许使用
.bus_req(bus_req)		//总线请求使用

);

endmodule
