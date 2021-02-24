`timescale 1ns/100ps
module MIN_LS1u_tb();
bit sysclk,sysrst_n;
bit busclk,busrst_n,ale_n,cs_n;
bit cmd_n,typ,wr_n;
bit rdy_n,irq_n;
logic [23:0]busaddr;
wire [7:0]busdata;
wire [7:0]AAH8;
always #5 sysclk=!sysclk;
initial 
begin
    $dumpfile("./temp/MIN_LS1u_tb.vcd"); // 指定用作dumpfile的文件
    $dumpvars; // dump all vars
    sysclk=0;sysrst_n=0;rdy_n=1;irq_n=1;
    #20 sysrst_n=1;
    #300 rdy_n=0; 
    #50000 irq_n=0;
    #100000 $finish;
end
assign busaddr[7:0]=AAH8;
always@(posedge busclk)//mimick 74373
    if(!ale_n)
    begin
        busaddr[23:8]={AAH8,busdata};
    end

MIN_LS1u DUT
(
    //FSB8 bus,
    .sysclk(sysclk),
    .sysrst_n(sysrst_n),
    .busclk(busclk),
    .busrst_n(busrst_n),
    .ale_n(ale_n),
    .cs_n(cs_n),
    .cmd_n(cmd_n),
    .typ(typ),//SINGLE#/BLOCK
    .wr_n(wr_n),
    .rdy_n(rdy_n),//Also MN#/MX
    .irq_n(irq_n),
    .AD8(busdata),
    .AAH8(AAH8)
);
fake_sram PESUDO_PERIPHERAL
(
    .addr(busaddr),
    .cs(cs_n),
    .oe(!wr_n),
    .we(wr_n),
    .data(busdata)
);
endmodule


module fake_sram
(
    input [23:0]addr,
    input cs,oe,we,
    inout [7:0]data
);
wire [15:0]datao;
assign data=(!(cs|oe))?SPMEM[addr[7:0]]:8'hzz;
reg [7:0]SPMEM[255:0];
reg ack;
initial 
begin
    $readmemh("./sim/sim_modules/testspm.mif",SPMEM);
end
always@(negedge (we|cs))begin
    SPMEM[addr[7:0]]<=data;
end
endmodule