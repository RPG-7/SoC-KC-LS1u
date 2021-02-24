//4K
//1st 1.5K for peripherals (can be located on external bridge)
//following 256b for on chip functions
//last 256b for SYSCALL
//3rd 1K for OCSPM
//4th 1K for thread TLB
module min_pbus
#(parameter MMU_ENABLE=1'b0,
  cDMA_ENABLE=1'b0)
(
//------------SYSTEM CONTROL-------
    input SYST_PAUSE,
    input MNMX,
    output SYNC_MODE,
    output [6:0]ASYNC_WAITCYCLE,
    //-----------MMU SIGNALS-----------
    output [9:0]HPAGE_BASEADDR,
    output PAE_ENABLE,
    output ALWAYS_SVM, 
    output [15:0]ipae_h16,//From MMU control regs
    output [15:0]dpae_h16,
    output [7:0]ipte_h8,
    output [7:0]dpte_h8,
//------------INT signals--------  
    input XTNL_INT,
    input [7:0]XCP_ARR,
    output INT,
    output [23:0]IVEC_ADDR,
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

wire SYSCALL;

wire lclk;
wire [7:0]  DATo_STK,DATo_ITC,
            DATo_SYC,DATo_SPM,
            DATo_MMA;
wire    STBi_STK,STBi_ITC,
        STBi_SYC,STBi_SCL,
        STBi_SPM,STBi_MMA;
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
int_ctrl INTERRUPT_CONTROLLER1( //8Regs

    .IVEC_ADDR(IVEC_ADDR),
    .XCP_ARR(XCP_ARR),
    .INT_ARR({SYSCALL,SYSTICK_INT,XTNL_INT,5'b0}),
    .INT(INT),
    .clk(clk),
    .rst(rst),
    .WB_ADRi(WB_ADRi),
    .WB_DATo(DATo_ITC),
    .WB_DATi(WB_DATi),
    .WB_WEi(WB_WEi),
    .WB_CYCi(WB_CYCi),
    .WB_STBi(STBi_ITC),
    .WB_ACKo()

);
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
    //-----------MMU SIGNALS-----------
    .HPAGE_BASEADDR(HPAGE_BASEADDR),
    .PAE_ENABLE(PAE_ENABLE),
    //1=Always at Supervisor mode, use hugepage,no TLB 
    //0=ISP in supervisor mode,RET to user level TLB
    .ALWAYS_SVM(ALWAYS_SVM), 
    .ipae_h16(ipae_h16),//From MMU control regs
    .dpae_h16(dpae_h16),
    .ipte_h8(ipte_h8),
    .dpte_h8(dpte_h8),
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
defparam DATA_SPM.SPM_DEPTH=2048;
ocspm DATA_SPM
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
assign STBi_STK=(WB_ADRi[11:2]==10'b0110_000000);//0xC00600~0xC00603
assign STBi_ITC=(WB_ADRi[11:3]==9'b0110_11100);//0xC006E0~0xC006E7
//assign STBi_MMA=(WB_ADRi[11:3]==8'b0110_11110)&MMU_ENABLE;//0xC006F0~0xC006F7
assign STBi_SYC=(WB_ADRi[11:4]==8'b0110_1111);//0xC006F0~0xC006FF
//SYSCALL Base-Addr:0xC00700~0xC007FF(256B)
assign STBi_SCL=(WB_ADRi[11:8]==4'b0111);
//SPM Base-Addr:0xC00800~0xC00FFF (2KB)
assign STBi_SPM=(WB_ADRi[11]==1'b1);

always @(*) 
begin
    case ({STBi_STK,STBi_ITC,STBi_SYC,1'b0,STBi_SPM})
        5'b10000: WB_DATo=DATo_STK;
        5'b01000: WB_DATo=DATo_ITC;
        5'b00100: WB_DATo=DATo_SYC;
        //5'b00010: WB_DATo=DATo_MMA;
        5'b00001: WB_DATo=DATo_SPM;
        default: WB_DATo=8'hxx;
    endcase
end
endmodule