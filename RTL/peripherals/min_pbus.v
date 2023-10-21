//4K
//1st 1.5K for peripherals (can be located on external bridge)
//following 256b for on chip functions
//last 256b for SYSCALL
//next 2K for OCSPM
module min_pbus
(
//------------SYSTEM CONTROL-------
    input SYST_PAUSE,
    input MNMX,
    output SYNC_MODE,
    output [6:0]ASYNC_WAITCYCLE,
//Systick Output
    output SYSTICK_INT,
    output SYSCALL,
//------------Global signals--------
    input wire clki,
    input wire rsti,
    output clk,rst,//SYSTEM CORE CLK/RST
//-----------Wishbone BUS-----------
    input wire [11:0]WB_ADRi,
    output reg [7:0]WB_DATo,
    input wire [7:0]WB_DATi,
    input wire WB_WEi,
    input wire WB_CYCi,
    input wire WB_STBi,
    output wire WB_ACKo
);


wire lclk;
wire [7:0]  DATo_SYC,DATo_SPM,DATo_STK;
wire    STBi_SYC,STBi_SCL,
        STBi_SPM, STBi_STK;
wire SYSCALL_clr;
systick SYSTICK
(   //4Regs
    .SYSTICK_INT(SYSTICK_INT),
    .SYST_PAUSE(SYST_PAUSE),
    .clk(clk),
    .cntclk(clk),
    .rst(rst),
    .WB_ADRi(WB_ADRi[1:0]),
    .WB_DATo(DATo_STK),
    .WB_DATi(WB_DATi),
    .WB_WEi(WB_WEi),
    .WB_CYCi(WB_CYCi),
    .WB_STBi(STBi_STK),
    .WB_ACKo()

);    
//.INT_ARR({SYSCALL,SYSTICK_INT,XTNL_INT,5'b0}),   
//.INT(INT),

wire [7:0]SYSCALL_num;
wire [7:0]SYSCALL_info;


sys_ctrl SYSCTRL
(   //8regs
    .clki(clki),
    .rsti(rsti),//Low-speed CLK& RST input
    .reset_req(1'b0),
    .clk(clk),
    .lclk(lclk),//SYSTEM GLOBAL SIGNAL
    .rst(rst),
    .SYSCALL_clr(SYSCALL_clr),
    .SYSCALL_num(SYSCALL_num),
    .SYSCALL_info(SYSCALL_info),
    .MNMX(MNMX),
    .SYNC_MODE(SYNC_MODE),
    .ASYNC_WAITCYCLE(ASYNC_WAITCYCLE),
    //-----------Wishbone BUS-----------
    .WB_ADRi(WB_ADRi[3:0]),
    .WB_DATo(DATo_SYC),
    .WB_DATi(WB_DATi),
    .WB_WEi(WB_WEi),
    .WB_CYCi(WB_CYCi),
    .WB_STBi(STBi_SYC),
    .WB_ACKo()
);
syscall SYSCALL_UNIT 
(   //256Byte Write Only area
    .SYSCALL_clr(SYSCALL_clr),
    .SYSCALL_trig(SYSCALL),
    .SYSCALL_num(SYSCALL_num),
    .SYSCALL_info(SYSCALL_info),
    //-----------System Signals----------
    .clk(clk),
    .rst(rst),
    //-----------Wishbone BUS-----------
    .WB_ADRi(WB_ADRi[7:0]),
    //.WB_DATo(DATo_SCL),
    .WB_DATi(WB_DATi),
    .WB_WEi(WB_WEi),
    .WB_CYCi(WB_CYCi),
    .WB_STBi(STBi_SCL),
    .WB_ACKo()
);
ocspm #(.SPM_DEPTH(2048))
DATA_SPM
(   //Last 2K R/W area
//------------Global signals--------
    .clk(clk),
    .rst(rst),
//-----------Wishbone BUS-----------
    .WB_ADRi(WB_ADRi[10:0]),
    .WB_DATo(DATo_SPM),
    .WB_DATi(WB_DATi),
    .WB_WEi(WB_WEi),
    .WB_CYCi(WB_CYCi),
    .WB_STBi(STBi_SPM),
    .WB_ACKo()
);
//IO Bank Base-Addr:0xC00000~0xC005FF (1.5KB)
//GOTO EXTERNAL 
//Config Bank Base-Addr:0xC00600~0xC006FF;(256B)
assign STBi_STK=(WB_ADRi[11:4]==8'b0110_0000);//0xC00600~0xC0060F
assign STBi_SYC=(WB_ADRi[11:4]==8'b0110_1111);//0xC006F0~0xC006FF
//SYSCALL Base-Addr:0xC00700~0xC007FF(256B)
assign STBi_SCL=(WB_ADRi[11:8]==4'b0111);
//SPM Base-Addr:0xC00800~0xC00FFF (2KB)
assign STBi_SPM=(WB_ADRi[11]==1'b1);
assign WB_ACKo=1'b1;
always @(*) 
begin
    case ({STBi_STK,STBi_SYC,1'b0,STBi_SPM})
        4'b1000: WB_DATo=DATo_STK;
        //5'b01000: WB_DATo=DATo_ITC;
        4'b0100: WB_DATo=DATo_SYC;
        //5'b00010: WB_DATo=DATo_MMA;
        4'b0001: WB_DATo=DATo_SPM;
        default: WB_DATo=8'hxx;
    endcase
end
endmodule