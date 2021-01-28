module KC_LS1u_instr_mem
(
    input [23:0]addr,
    output reg[15:0]instr
);
always@(*)
begin
    case (addr)
        24'd0   :instr=16'h30aa;//load imm
        24'd1   :instr=16'h31bb;
        24'd2   :instr=16'h32cc;
        24'd3   :instr=16'h33dd;
        24'd4   :instr=16'h34ee;
        24'd5   :instr=16'h35ff;
        24'd6   :instr=16'h3611;
        24'd7   :instr=16'h3722;
        24'd8	:instr=	16'h20ff;//LOAD RAM
        24'd9	:instr=	16'h21ff;
        24'd10	:instr=	16'h22ff;
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
            $display("Instruction Fetch Out of Range! ADDR: %h",addr);
            $finish;
        end
    endcase
end
endmodule
