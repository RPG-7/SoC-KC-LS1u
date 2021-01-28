//NRU/RRIP(WIP) full-associative replace arbiter & tag manager
module tag_arbiter_fa
#(
    parameter ENTRY_NUM=8
    ,ENTRYSEL_WID = ((ENTRY_NUM > 1) ? $clog2(ENTRY_NUM) : 1)
    ,TAG_MSB=32
    ,TAG_LSB=12//1K per page
    ,M_WIDTH=1//if this is 1, perform NRU, if>1, RRIP
    ,WBACK_ENABLE=1'b0 //this actually heavily depends on optimization
)
(
    input clk,
    input rst,
    input entry_read,   //Core interface
    input entry_wthru,
    input entry_wback,
    input [TAG_MSB-1:0]access_addr,	
    input valid_clear, //flush
    input [TAG_MSB-1:0]refill_pa,//BIU interface
    input line_refill, //cachemem write, confirm refill valid
    input force_sync,//sync cache with memory(write back all dirty line)
    input writeback_ok,//data block write back complete, from cache BU
    output line_miss,//refill request
    output replace_dirty, //page dirty, need to write back first
    output [ENTRYSEL_WID-1:0]entry_replace_sel, //for replace select& dirty flush select
    output [ENTRYSEL_WID-1:0]entry_select_addr//addr for access 
);
integer i,j;
genvar k;
reg [(TAG_MSB-TAG_LSB):0]tag_addr[ENTRY_NUM-1:0];
reg [ENTRY_NUM-1:0]line_valid;
reg [ENTRY_NUM-1:0]line_dirty;
reg [ENTRY_NUM-1:0]entry_hit;
//对于CPU访存提供写穿透策略/写回策略接口，配套了内存同步控制线。
assign line_miss=(entry_read|entry_wback|entry_wthru) & (entry_hit==0);
always @(*)
    for ( i=0;i<ENTRY_NUM;i=i+1 ) 
    begin
        entry_hit[i]=(access_addr[TAG_MSB-1:TAG_LSB-1]==tag_addr[i])&line_valid[i];
    end
//地址生成
reg [ENTRYSEL_WID-1:0]entry_select_encode[ENTRY_NUM-1:0];
assign entry_select_addr=entry_select_encode[ENTRY_NUM-1];
always @(*)//cache命中选择优先编码器
begin
    entry_select_encode[0]=0;
    for ( i=1;i<ENTRY_NUM;i=i+1 ) 
    begin
        entry_select_encode[i]=sel_entry_cell(entry_select_encode[i-1],i,entry_hit[i]);
    end
end
always@(posedge clk)//Tag management
begin
    for(i=0;i<ENTRY_NUM;i=i+1)
    begin
        if(rst)
        begin
            line_valid[i]	<=	0;
            if(WBACK_ENABLE)line_dirty[i]   <=  0;
        end
        else if( valid_clear ) //clear valid bit
        begin
            line_valid[i]	<=	0;
        end
        else if (writeback_ok&WBACK_ENABLE) //dirty page synced,we can move forward
        begin
            line_dirty[entry_replace_sel]   <=  0;
        end
        else if(entry_replace_sel==i&line_refill)
        begin
            tag_addr[i]	<=	refill_pa[TAG_MSB-1:TAG_LSB-1];
            line_valid[i]	<=	1'b1;
        end
        else if(entry_wback&entry_hit[i]&WBACK_ENABLE) 
        begin
            line_dirty[i]<=1'b1;
        end
    end
end
//NRU Cache替换策略
reg [ENTRY_NUM-1:0]recent_used;//0=not recent used 1=used
always@(posedge clk)//NRU寄存器管理
begin
    if(rst|(~recent_used)==0)
    begin
        recent_used<=0;
    end
    else 
        for(i=0;i<ENTRY_NUM;i=i+1)
        begin
            if(entry_hit[i]&(entry_read|entry_wthru|entry_wback))
            begin
                recent_used[i]<=1'b1;
            end
        end
end
//替换/写回管理
reg [ENTRYSEL_WID-1:0]dirty_select_encode[ENTRY_NUM-1:0];
reg [ENTRYSEL_WID-1:0]entry_replace_encode[ENTRY_NUM-1:0];
assign entry_replace_sel=(WBACK_ENABLE)?((force_sync)?dirty_select_encode[ENTRY_NUM-1]:
                                    entry_replace_encode[ENTRY_NUM-1]):
                                    entry_replace_encode[ENTRY_NUM-1];
always @(*)//替换/写回选择优先编码器
begin
    if(!WBACK_ENABLE)dirty_select_encode[0]=0;//
    entry_replace_encode[0]=0;
    for ( i=1;i<ENTRY_NUM;i=i+1 ) //从左向右扫描，高位cache单元优先换出
    begin
        if(!WBACK_ENABLE)dirty_select_encode[i]=sel_entry_cell(dirty_select_encode[i-1],i,line_dirty[i]);
        entry_replace_encode[i]=sel_entry_cell(entry_replace_encode[i-1],i,!recent_used[i]);//为0才换出
    end
end
assign replace_dirty=(WBACK_ENABLE)?line_dirty[entry_replace_sel]:1'b0;//拟定替换cache line脏不？
//可扩展优先编码器：如果该位为1,返回该位所在编号,如果该位为0，传递上一级输入编号
function [ENTRYSEL_WID-1:0]sel_entry_cell;
    input [ENTRYSEL_WID-1:0]prev_entry_num;
    input [ENTRYSEL_WID-1:0]cur_entry_num;
    input cur_entry_bit;
    begin
   		sel_entry_cell=(cur_entry_bit)?cur_entry_num:prev_entry_num;
   	end
endfunction
endmodule
