module KC_LS1u
(
    input clk,rst,
    input WAIT,
    output [23:0]iaddr,
    input [15:0]instr,
    output [23:0]daddr,
    input [7:0]ddata_i,
    output [7:0]ddata_o,    
	output reg dwrite
);
reg [23:0]PC;//Program counter
wire [23:0]jaddr;
reg [7:0]DB8w;//CPU数据写回总线
reg jmp;//执行跳转/中断返回
//程序计数器，状态：+1s/等待/加载A2A1A0跳转
always@(posedge clk or posedge rst)
begin
    if(rst)
    begin
        PC<=24'h0;
    end
    else 
    begin
        if(WAIT)PC<=PC;
        else if(jmp)
        begin
            PC <= {A2,A1,A0};
        end
        else 
        begin
            PC<=PC+1;
        end
    end
end
//REGs
reg regwrite;
wire [2:0]regwaddr;//寄存器堆写回信号线
reg [7:0]A0,A1,A2;//data memory address register
reg [7:0]A,B,C,D;//So called "GPR"
reg [7:0]MDR;//Mem Data Register
always@(posedge clk)
begin
    if(regwrite)
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
reg [3:0]dbsrc_addr;
//wb dst decode
assign regwaddr=instr[10:8];
wire [4:0]funct5;
assign funct5={5{!WAIT}}&instr[15:11];//当CPU进入等待状态，不译码，执行NOP
//Instruction FUNCT5 decode (写回总线数据源控制/控制信号编码)
always@(*)
begin
    case(funct5)
        default://NOP or ILLEGAL_INS
            begin dbsrc_addr=4'h0;regwrite=0;jmp_en=0; end
        5'h01://JMP select
            begin dbsrc_addr=4'h0;regwrite=0;jmp_en=1; end
        5'h02://ALU SELECT
            begin dbsrc_addr=4'h1;regwrite=1;jmp_en=0; end
        5'h04://LOAD MEM
            begin dbsrc_addr=4'h2;regwrite=1;jmp_en=0; end
         5'h05://MOV C
            begin dbsrc_addr=4'h0;regwrite=1;jmp_en=0; end
        5'h06://LOAD IMM
            begin dbsrc_addr=4'h3;regwrite=1;jmp_en=0; end
        5'h07://MOV D
            begin dbsrc_addr=4'h4;regwrite=1;jmp_en=0; end
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
//ALU控制线
wire [4:0]ALU_S;
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
    .cin(ALU_Ci), 
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
        3'h1:begin jmp=!ALU_inA[7];end
        3'h2:begin jmp=!ALU_inB[7];end
        3'h3:begin jmp=!ALU_eqo;end
        3'h4:begin jmp=!ALU_Co;end
        3'h5:begin jmp=1;end//JMP指令
        default: begin jmp=0;end
    endcase
else begin jmp=0; end
//WB mux
always@(*)//WB DATA BUS (shift contained here)
begin
    case(dbsrc_addr)
        4'h0:DB8w=C;
        4'h1:DB8w=ALU_out;
        4'h2:DB8w=ddata_i;
        4'h3:DB8w=IMM;
        4'h4:DB8w=D;
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
//Top level connections
assign daddr={A2,A1,A0};
assign iaddr=PC;
assign ddata_o=MDR;
endmodule
