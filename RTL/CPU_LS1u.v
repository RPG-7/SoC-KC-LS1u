module CPU_LS1u
(
    input clk,rst,

    input cache_flush,//当存在MMU，切换页表须冲刷cache
    //Interrupt
	 input INT,
    input [5:0]INTCODE,//中断源编码
    input [23:0]IVT_addr,//中断向量表基址
    //Shrinked AHB
    output wire [23:0]haddr,
    output wire hwrite,
    output wire [2:0]hburst,
    output wire [1:0]htrans,
    output wire [7:0]hwdata,
    input wire hready,
    input wire hresp,
    input wire hreset_n,
    input wire [7:0]hrdata
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
wire WAIT;
assign WAIT=!(icache_rdy&dcache_rdy);
defparam BIU.BUSD_WIDTH=8;
defparam BIU.BUSA_WIDTH=24;
defparam BIU.INST_WIDTH=16;
biu BIU
    (
    //csr
    .clk            (clk),
    .rst            (rst),
    .addr_if        ({iaddr[22:0],1'b0}),
    .rd_ins         (1'b1),				//取指令信号
    .ins_read       (instr),
    .ins_acc_fault  (), 		//指令访问失败
    .cache_ready_if (icache_rdy),		//cache准备好信号
    .addr_ex        (daddr),
    .data_write     (ddata_o),
    .data_read      (ddata_i),			
    .l1i_reset      (cache_flush),			//缓存刷新信号，用于执行fence指令的时候使用
    .l1d_reset      (cache_flush),			//缓存载入信号，用于执行fence.vma时候和cache_flush配合使用
    .read           (dread),				//读数据信号
    .write          (dwrite),				//写数据信号

    .load_acc_fault (),
    .store_acc_fault(),
    .daccess_rdy    (dcache_rdy),		//cache数据准备好

    //AHB信号
    .haddr          (haddr),
    .hwrite         (hwrite),
    .hburst         (hburst),
    .htrans         (htrans),
    .hwdata         (hwdata),
    .hready         (hready),
    .hresp          (hresp),
    .hreset_n       (!rst),
    .hrdata         (hrdata)
);
KC_LS1u_plus CORE
(
    .clk(clk),
    .rst(rst),
    .INT(INT),
    .WAIT(WAIT),
    .INTCODE(INTCODE),//中断源编码
    .IVT_addr(IVT_addr),//中断向量表基址
    .iaddr(iaddr),
    .instr(instr),
    .daddr(daddr),
    .dwrite(dwrite),
    .dread(dread),
    .ddata_i(ddata_i),
    .ddata_o(ddata_o)
);

endmodule
