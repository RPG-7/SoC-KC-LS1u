/*************************************************
//SYSCTRL Module Mem map:
//0x00 CKSET: {SYSLEEP PLLEN REFCLKSEL MAINCLK[1:0]}
//0x01 SCALL: {SCALL_EN SCALL_CLR RSVD[5:0]}
//0x02 SCNUM: System call number    //READ ONLY
//0X03 CINFO: System call info      //READ ONLY
//0x04 FSBMOD:{SYNC_FSB ASYNC_WAITCNT[6:0]}
*************************************************/
module sys_ctrl
(
    input clki,rsti,//Low-speed CLK& RST input
    input reset_req,
    output clk,lclk,//SYSTEM GLOBAL SIGNAL
    output reg rst,
    //-----------Syscall wire-----------
    output SYSCALL_clr,
    input MNMX,
    input [7:0]SYSCALL_num,
    input [7:0]SYSCALL_info,
    //-----------Bus Control-----------
    output SYNC_MODE,
    output [6:0]ASYNC_WAITCYCLE,
    //-----------Wishbone BUS-----------
    input wire [3:0]WB_ADRi,
    output reg [7:0]WB_DATo,
    input wire [7:0]WB_DATi,
    input wire WB_WEi,
    input wire WB_CYCi,
    input wire WB_STBi,
    output wire WB_ACKo
);
//reg [6:0]CKSET;
reg [7:0]FSBMOD;

reg scall_en;
wire pll_lock;
wire lclk_div;
wire sys_rst;
wire wb_write;
assign wb_write=(WB_CYCi & WB_STBi & WB_WEi);
//SYSTEM Reset management
assign sys_rst=rsti|reset_req;
assign SYSCALL_clr=rst|(wb_write&(WB_ADRi==3'h1)&WB_DATi[6]);
always@(posedge clki or posedge sys_rst)
begin
    if(sys_rst)
        rst<=1'b1;
    //else if(!pll_lock)rst<=1'b1;
	 else rst<=1'b0;
end
//---------------wishbone signals------------
//---------------REG WRITE------------------
always@(posedge clk)begin
    if(rst)begin
        //CKSET<=8'h00;
        scall_en <= 0;
        FSBMOD<={MNMX,7'h7f};
//        MMUMOD<=2'h0;
    end
    else if(WB_CYCi & WB_STBi & WB_WEi)
    begin
        case(WB_ADRi[3:0])
//        4'h0    :   CKSET<={WB_DATi[7],WB_DATi[5:0]} ;
        4'h1    :   scall_en<=WB_DATi[7];   
        4'h4    :   FSBMOD<=WB_DATi;

        endcase
    end
    else 
    begin
//        CKSET<=CKSET ;
        scall_en<=scall_en;
        FSBMOD<=FSBMOD;

    end
end

//-----------DATA READ-----------
always@(*)begin
    case(WB_ADRi[3:0])
//        4'h0    :   WB_DATo <= {CKSET[6],1'b0,CKSET[5:0]};
        4'h1    :   WB_DATo <= {scall_en,7'hxx};
        4'h2    :   WB_DATo <= SYSCALL_num;
        4'h3    :   WB_DATo <= SYSCALL_info;
        4'h4    :   WB_DATo <= FSBMOD;
        default :   WB_DATo <= 8'hxx;
    endcase
end
//----------ACK----------------
assign WB_ACKo = 1'b1;

//Output ports
assign SYNC_MODE=FSBMOD[7];
assign ASYNC_WAITCYCLE=FSBMOD[6:0];

assign lclk=clk;
assign clk=clki;
//可扩展优先编码器：如果该位为1,返回该位所在编号,如果该位为0，传递上一级输入编号
function [2:0]sel_entry_cell;
    input [2:0]prev_entry_num;
    input [2:0]cur_entry_num;
    input cur_entry_bit;
    begin
   		sel_entry_cell=(cur_entry_bit)?cur_entry_num:prev_entry_num;
   	end
endfunction

endmodule