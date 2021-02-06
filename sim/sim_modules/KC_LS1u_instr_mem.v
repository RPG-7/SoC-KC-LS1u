module KC_LS1u_instr_mem
(
    input [23:0]addr,
    output reg[15:0]instr
);
always@(*)
begin
    case (addr)
        24'd0   :instr=16'h3101;//load A,1
        24'd1   :instr=16'h3200;//load B,0
        24'd2   :instr=16'h3400;//load A1,0
        24'd3   :instr=16'h3500;//load A2,0
        24'd4   :instr=16'h13ff;//MOV A0,A
        24'd5   :instr=16'h17ff;//mov *RAM,A
        24'd6   :instr=16'h1100;//A=A+1
        24'd7   :instr= 16'h3301;
        24'd8	:instr=	16'h3400;//
        24'd9	:instr=	16'h3500;
        24'd10	:instr=	16'h0DFF;//JMP 01
        24'd11	:instr=	16'h23ff;
        24'd12	:instr=	16'h24ff;
        24'd13	:instr=	16'h25ff;
        24'd14	:instr=	16'h26ff;
        24'd15	:instr=	16'h27ff;
        24'd16	:instr=	16'h1794;
        24'd17	:instr=	16'h17C4;
        24'd18	:instr=	16'h1700;
        24'd19	:instr=	16'h1790;
        24'd20	:instr=	16'h17C0;
        24'd21	:instr=	16'h1760;
        24'd22	:instr=	16'h17F4;
        24'd23	:instr=	16'h1764;
        24'd24	:instr=	16'h1794;
        24'd25  :instr= 16'h08ff;
        default:
        begin
            instr= 16'h0000;
            //$display("Instruction Fetch Out of Range! ADDR: %h",addr);
            //#100 $finish;
        end
    endcase
end
endmodule
