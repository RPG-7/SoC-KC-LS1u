module KC_LS1u_plus
(
    input clk,rst,INT,WAIT,
    input [23:0]IVEC_addr,//中断向量地址
    output IN_ISP,
    output [23:0]iaddr,
    output [23:0]iaddr_next,
    input [15:0]instr,
    output [23:0]daddr,
    output reg dread,
    output reg dwrite,
    input [7:0]ddata_i,
    output [7:0]ddata_o
);
reg [23:0]PC;//Program counter
reg [23:0]PC_NEXT;
reg [7:0]RET0,RET1,RET2;
reg [7:0]RTA0,RTA1,RTA2;//A0/A1/A2 will be pushed into these regs, and pop when return
wire [23:0]jaddr;
reg int_service;//中断处理指示寄存器（用于在中断服务程序中屏蔽后续中断输入）
assign IN_ISP=int_service;
reg [7:0]DB8w;//CPU数据写回总线
reg jmp,ret_sel;//执行跳转/中断返回
wire int_filter;//中断屏蔽信号线
assign int_filter=INT&(!int_service);//中断屏蔽=在中断服务程序中
reg wait_trap;
wire transfer_valid;
always@(posedge clk or posedge WAIT)//等待状态锁存
begin
	if(WAIT)wait_trap<=1'b1;
	else wait_trap<=1'b0;
end
wire [23:0]PCP1;//PC+1,省LE的奇技淫巧(MUX比加法器节约LE)
assign PCP1=PC+1;
//程序计数器，状态：+1s/等待/跳中断处理/(加载A2A1A0跳转|加载返回寄存器(RET)
always@(*)//PC_NEXT 选择器
begin
    if(rst)PC_NEXT=0;//复位
    else if(wait_trap)PC_NEXT<=PC;
    else if(int_filter)PC_NEXT=IVEC_addr;//中断向量
    else if(jmp)PC_NEXT=jaddr;//跳转或返回
    else PC_NEXT=PCP1;//没事+1s
end
always@(posedge clk or posedge rst)//PC寄存器
begin
    if(rst)PC<=24'h0;
    else if(wait_trap)PC<=PC;
    else PC<=PC_NEXT;
end
reg xreg_write;//修改中断返回寄存器
wire [2:0]xreg_addr;
assign xreg_addr=instr[2:0];
//中断管理寄存器
always @(posedge clk) 
begin
    if(rst)
    begin
        {RET2,RET1,RET0}<=24'h0;
        int_service<=1'b0;
    end    
    else if(int_filter&(!wait_trap)) 
    begin
        if(jmp){RET2,RET1,RET0}=jaddr;
            else {RET2,RET1,RET0}<=PCP1;
        int_service<=1'b1;
        RTA0<=A0;
        RTA1<=A1;
        RTA2<=A2;
    end
    else if(ret_sel)
    begin
        int_service<=1'b0;
    end
    else 
    begin
        if(xreg_write)
        case(xreg_addr)
            3'h0:RET0<=DB8w;
            3'h1:RET1<=DB8w;
            3'h2:RET2<=DB8w;
            3'h3:RTA0<=DB8w;
            3'h4:RTA1<=DB8w;
            3'h5:RTA2<=DB8w;
        endcase
    end
end
//REGs
reg regwrite;
wire [2:0]regwaddr;//寄存器堆写回地址线
reg [7:0]A0,A1,A2;//data memory address register
reg [7:0]A,B,C,D;//So called "GPR"
reg [7:0]MDR;//Mem Data Register
always@(posedge clk)
begin
    if(ret_sel)//自动弹出
    begin
        A0<=RTA0;
        A1<=RTA1;
        A2<=RTA2;
    end
    else if(regwrite&(!wait_trap))
    begin
        if(regwaddr==3'h7)//DWRITE=1,指示MDR数据有效，触发总线写入
                dwrite<=1'b1;
        else dwrite<=1'b0;
        case(regwaddr)//原作的“阻塞”3-8写回译码器，现已允许连续写入同一寄存器
            3'h0:C<=DB8w;
            3'h1:A<=DB8w;
            3'h2:B<=DB8w;
            3'h3:A0<=DB8w;        
            3'h4:A1<=DB8w;  
            3'h5:A2<=DB8w;
            3'h6:D<=DB8w;  
            3'h7:MDR<=DB8w;
        endcase
    end
    else 
    begin
        C<=C;
        A<=A;
        B<=B;
        D<=D;
        A0<=A0;        
        A1<=A1;  
        A2<=A2;  
        MDR<=MDR;
        dwrite<=1'b0;
    end
end
//Instruction decode logic
//JMP function select
reg jmp_en;
wire [2:0]jmp_sel;
assign jmp_sel=instr[10:8];
//immediate num
wire [7:0]IMM;
assign IMM=instr[7:0];
//wb src decode
/*****************************
C D AO A1 A2 RAM
ALU OUT (A B) 
8 SHIFT OUT
IMM
XREG (RETURN REGs)
********************************/
reg [3:0]dbsrc_addr;
wire [4:0]funct5;
assign funct5=instr[15:11];//当CPU进入等待状态，不译码，执行NOP{5{!wait_trap}}&
//wb dst decode
assign regwaddr=instr[10:8];
//Instruction FUNCT5 decode (写回总线数据源控制/控制信号编码)
always@(*)
begin
    if(funct5==5'h08)xreg_write=1;
        else xreg_write=0;
    case(funct5)
        default: 
            begin dbsrc_addr=4'hf;regwrite=0;jmp_en=0; end//NOP
        5'h01://JMP select
            begin dbsrc_addr=4'hf;regwrite=0;jmp_en=1; end
        5'h02://ALU SELECT
            begin dbsrc_addr=4'h1;regwrite=1;jmp_en=0; end
        5'h03://MOV From XREG
            begin dbsrc_addr=4'h5;regwrite=1;jmp_en=0; end
        5'h04://LOAD MEM
            begin dbsrc_addr=4'h2;regwrite=1;jmp_en=0; end
        5'h05://MOV FROM C
            begin dbsrc_addr=4'h0;regwrite=1;jmp_en=0; end
        5'h06://LOAD IMM
            begin dbsrc_addr=4'h3;regwrite=1;jmp_en=0; end
        5'h07://MOV FROM D
            begin dbsrc_addr=4'h4;regwrite=1;jmp_en=0; end
        5'h08://MOV A/B to XREG
            begin dbsrc_addr=4'h1;regwrite=0;jmp_en=0; end
        5'h0d://SHIFT START
            begin dbsrc_addr=4'h7;regwrite=1;jmp_en=0; end
        5'h10:
            begin dbsrc_addr=4'h8;regwrite=1;jmp_en=0; end
        5'h12:
            begin dbsrc_addr=4'h9;regwrite=1;jmp_en=0; end  
        5'h14:
            begin dbsrc_addr=4'ha;regwrite=1;jmp_en=0; end  
        5'h16:
            begin dbsrc_addr=4'hb;regwrite=1;jmp_en=0; end  
        5'h18:
            begin dbsrc_addr=4'hc;regwrite=1;jmp_en=0; end  
        5'h1a:
            begin dbsrc_addr=4'hd;regwrite=1;jmp_en=0; end  
        5'h1c://SHIFT END
            begin dbsrc_addr=4'he;regwrite=1;jmp_en=0; end       
    endcase
end
reg [7:0]XREGr;
always@(*)
begin
    case(xreg_addr)
        3'h0:XREGr=RET0;
        3'h1:XREGr=RET1;
        3'h2:XREGr=RET1;
        3'h3:XREGr=RTA0;
        3'h4:XREGr=RTA1;
        3'h5:XREGr=RTA2;
    default :XREGr=8'hxx;
    endcase
end
//ALU控制线
wire [3:0]ALU_S;
wire ALU_M,ALU_Ci;
assign ALU_S=instr[7:4];
assign ALU_M=instr[3];
assign ALU_Ci=instr[2];
//74181 ALU
wire [7:0]ALU_out;//ALU out
wire [1:0]ALU_eq;
wire ALU_eqo,ALU_C1,ALU_Co;
assign ALU_eqo=&ALU_eq;//both L4&H4 are equal
wire [7:0]ALU_inA,ALU_inB;
assign ALU_inA=A;
assign ALU_inB=B;
alu74181 ALU_L4
(
    .a(ALU_inA[3:0]),
    .b(ALU_inB[3:0]),
    .cin(ALU_Ci), 
    .s(ALU_S),
    .m(ALU_M), 
    .f(ALU_out[3:0]), 
    .cout(ALU_C1), 
    .eqv(ALU_eq[0]), 
    .g(),
    .p()
);
alu74181 ALU_H4
(
    .a(ALU_inA[7:4]),
    .b(ALU_inB[7:4]),
    .cin(ALU_C1), 
    .s(ALU_S),
    .m(ALU_M), 
    .f(ALU_out[7:4]), 
    .cout(ALU_Co), 
    .eqv(ALU_eq[1]), 
    .g(),
    .p()
);
//JMP exec
always@(*)
if(jmp_en)
    case (jmp_sel)
        3'h0:begin jmp=1;ret_sel=1;end//RET 指令,0x08xx
        3'h1:begin jmp=!ALU_inA[7]; ret_sel=0;end
        3'h2:begin jmp=!ALU_inB[7]; ret_sel=0;end
        3'h3:begin jmp=!ALU_eqo; ret_sel=0;end
        3'h4:begin jmp=!ALU_Co; ret_sel=0;end
        3'h5:begin jmp=1; ret_sel=0;end//JMP指令
        default: begin jmp=0; ret_sel=0;end
    endcase
else begin jmp=0;ret_sel=0; end
//WB mux
always@(*)//WB DATA BUS (shift contained here)
begin
    if(dbsrc_addr==4'h2)dread=1;
        else dread=0;
    case(dbsrc_addr)
        4'h0:DB8w=C;
        4'h1:DB8w=ALU_out;
        4'h2:DB8w=ddata_i;
        4'h3:DB8w=IMM;
        4'h4:DB8w=D;
        4'h5:DB8w=XREGr;
        4'h7:DB8w=ALU_inA<<1;
        4'h8:DB8w={ALU_inA[6:0],ALU_inB[7]};
        4'h9:DB8w=ALU_inA>>1;
        4'ha:DB8w={ALU_inA[7],ALU_inA[7:1]};
        4'hb:DB8w=ALU_inB<<1;
        4'hc:DB8w=ALU_inB>>1;
        4'hd:DB8w={ALU_inB[7],ALU_inB[7:1]};
        4'he:DB8w={ALU_inA[0],ALU_inB[7:1]};
        default:DB8w=8'h00;
    endcase
end
assign jaddr=(  //JUMP ADDRESS
        ({24{ret_sel}}&{RET2,RET1,RET0})|
        ({24{~ret_sel}}&{A2,A1,A0}));
//Top level connections
assign daddr={A2,A1,A0};
assign iaddr=PC;
assign iaddr_next=PC_NEXT;
assign ddata_o=MDR;
endmodule
