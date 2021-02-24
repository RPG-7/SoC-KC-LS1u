//2 clock domain :
//main processing in PIX_CLK domain 
//SRAM R/W interface in SYS_CLK domain

module vga_ppu
(
    input sys_clk,rst,
    input pix_clk,
    input [8:0]line_addr,pix_addr,
    //input [9:0]
    output [7:0]pix_data
);



endmodule