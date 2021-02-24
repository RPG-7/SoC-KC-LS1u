module asic_pll
(
    input clki,
    input rsti,
    input [7:0]forediv,
    input [7:0]loopdiv,
    input [7:0]postdiv,
    output reg fout,
    output lock
);

initial begin
    fout=0;
end
always #5 fout=~fout;

endmodule
