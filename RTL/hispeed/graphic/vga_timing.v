
`define RESOLUTION_ADJ ;
module vga_timing
#(parameter FIXED_HRES     = 640,
            FIXED_VRES     = 480,
            FIXED_FP       = 24,
            FIXED_HSYNC    = 32,       // horizontal sync
            FIXED_HBP      = 46,       // horizontal back porch
            FIXED_VFP      = 3,        // vertical front porch
            FIXED_VSYNC    = 5,        // vertical sync
            FIXED_VBP      = 14      // vertical back porch
)       
(
    input rst,
    input pixel_clk,
    //Input control signals
    input [10:0]pixel_num,
    input [10:0]eohfp_num,
    input [10:0]eohsync_num,
    input [10:0]eoline_num,
    input [10:0]line_num,
    input [10:0]eovfp_num,
    input [10:0]eovsync_num,
    input [10:0]eoframe_num,
    //Control Output
    output [9:0]vert_cnto,
    output [9:0]curr_pix,
    output pix_valid,
    output frame_valid,
    //VGA Interface
    output hsync,vsync//,pix_clko,
    //output [7:0]pixel_data,
);

`ifdef RESOLUTION_ADJ
  wire[10:0]EOHFP  =eohfp_num;
  wire[10:0]EOHSYNC=eohsync_num;
  wire[10:0]EOLINE =eoline_num;
  wire[10:0]EOVFP  =eovfp_num;
  wire[10:0]EOVSYNC=eovsync_num;
  wire[10:0]EOFRAME=eoframe_num;
  wire[10:0]PIXEL  =pixel_num;
  wire[10:0]LINE   =line_num;
`else 
  wire[10:0]EOHFP  =FIXED_HRES+FIXED_FP;
  wire[10:0]EOHSYNC=EOHFP+FIXED_HSYNC;
  wire[10:0]EOLINE =EOHSYNC+FIXED_HBP;
  wire[10:0]EOVFP  =FIXED_VRES+FIXED_VFP;
  wire[10:0]EOVSYNC=EOVFP+FIXED_VSYNC;
  wire[10:0]EOFRAME=EOVSYNC+FIXED_VBP;
  wire[10:0]PIXEL  =FIXED_HRES;
  wire[10:0]LINE   =FIXED_VRES;
`endif

reg [10:0]hor_cnt;
reg [9:0]vert_cnt;
assign vert_cnto=vert_cnt;
assign curr_pix=hor_cnt[9:0];
assign pix_valid=(hor_cnt<=PIXEL);
assign frame_valid=(vert_cnt<=LINE);
assign hsync=~(hor_cnt>EOHFP&hor_cnt<=EOHSYNC);
assign vsync=~(vert_cnt>EOVFP&vert_cnt<=EOVSYNC);
always@(posedge pixel_clk)
begin
    if(rst)
    begin
        hor_cnt<=EOHFP;
        vert_cnt<=EOVFP;
    end
    else 
    begin
        if(hor_cnt==EOLINE)
        begin
            hor_cnt<=0;
            if(vert_cnt==EOFRAME)vert_cnt<=0;
            else vert_cnt<=vert_cnt+1;
        end
        else
            hor_cnt <= hor_cnt + 1;
    end
end
endmodule