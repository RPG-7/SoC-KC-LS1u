//Supported Modes:
//320*240 Text mode
//Original 256*240 KC-LS1u 64K VGA interface
//NES PPU Sprite Overlay
//VESA VGA-Framebuffer, Maximum 1024*768 (Typical 640*480)
//This is the VGA interface(Timing generator)
//In order to minimize the LUT usage, the counters start with the beginning of valid
//lines and valid pixels, and we use this number to help pixel generation

module vga_top
#(parameter COLOR_DEPTH = 8
)
(
    input sys_clk,rst,
    input pix_clk,

    //VGA INTERFACE
    output HSYNC,VSYNC,PIXCLK,
    output [COLOR_DEPTH-1:0]PIXDAT
);




wire [9:0]pixaddr;
wire [9:0]curr_line;
vga_ppbuf VGA_OUTPUT_BUFFER
(
    .sys_clk(sys_clk),
    .pix_clk(pix_clk),
    .rst(rst),
    .sys_addr(),
    .sysdati(),
    .sysdato(),
    .sys_we(),
    .sys_ce(),
    .pix_addr({curr_line[0],pixaddr}),
    .pixdato(PIXDAT)
    
);
vga_timing VGA_TIMING_MODULE     
(
    .rst(rst),
    .pixel_clk(pix_clk),
    //Input control signals
    .pixel_num(),
    .eohfp_num(),
    .eohsync_num(),
    .eoline_num(),
    .line_num(),
    .eovfp_num(),
    .eovsync_num(),
    .eoframe_num(),
    //Control Output
    .vert_cnto(curr_line),
    .curr_pix(pixaddr),
    .pix_valid(),
    .frame_valid(),
    //VGA Interface
    .hsync(HSYNC),
    .vsync(VSYNC)
);
endmodule
