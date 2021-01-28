//
module tag_arbiter_dm
#(
    parameter ENTRY_NUM=16
    ,ENTRYSEL_WID = ((ENTRY_NUM > 1) ? $clog2(ENTRY_NUM) : 1)
    ,TAG_WID=14//1K per page
    ,WBACK_ENABLE=1'b0 //this actually heavily depends on optimization
)
(
    input clk,
    input rst,
    input entry_read,   //Core interface
    input entry_wthru,
    input entry_wback,
    input [TAG_WID-1:0]address_tag,
    input [ENTRYSEL_WID-1:0]address_ent,	
    input valid_clear, //flush
    input [TAG_WID-1:0]refill_tag,//BIU interface
    input line_refill, //cachemem write, confirm refill valid
    output line_miss,//refill request
    output replace_dirty, //page dirty, need to write back first
    input writeback_ok, //Writeback finished
    output [ENTRYSEL_WID-1:0]entry_replace_sel, //for replace select& dirty flush select
    output [ENTRYSEL_WID-1:0]entry_select_addr//addr for access 
);
integer i;
reg [ENTRY_NUM-1:0]line_valid;
reg [ENTRY_NUM-1:0]line_dirty;
reg [TAG_WID-1:0]entry_tag[ENTRY_NUM-1:0];
//对于CPU访存提供写穿透策略/写回策略接口，配套了内存同步控制线。
assign line_miss=(entry_read|entry_wback|entry_wthru) & (entry_hit==0);
assign entry_hit=entry_tag[address_ent]==address_tag&line_valid[address_ent];
always@(posedge clk)//Tag management
begin
    if(rst)
        for(i=0;i<ENTRY_NUM;i=i+1)
        begin
            line_valid[i]	<=	0;
            if(WBACK_ENABLE)line_dirty[i]   <=  0;
        end
    else
    begin
        if( valid_clear ) //clear valid bit
        begin
            line_valid[address_ent]	<=	0;
        end
        else if (writeback_ok&WBACK_ENABLE) //dirty page synced,we can move forward
        begin
            line_dirty[address_ent]   <=  0;
        end
        else if(line_refill)
        begin
            entry_tag[address_ent]	<=	refill_tag;
            line_valid[address_ent]	<=	1'b1;
        end
        else if(entry_wback&entry_hit&WBACK_ENABLE) 
        begin
            line_dirty[address_ent]<=1'b1;
        end
    end
end
//写回管理
assign replace_dirty=(WBACK_ENABLE)?line_dirty[address_ent]:1'b0;//拟定替换cache line脏不？
assign entry_replace_sel=address_ent;
assign entry_select_addr=address_ent;
endmodule
