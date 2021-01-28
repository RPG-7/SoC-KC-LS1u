//NRU/RRIP(WIP) Way-Associative replace arbiter & tag manager
//对于CPU访存提供写穿透策略/写回策略接口，配套了内存同步控制线。
module tag_arbiter_wa
#(
    parameter WAY_DEPTH=32 //How many entries does 1 way have?
    ,WAY_NUM=2//MUST > 1
    ,WAYSEL_WID = ((WAY_NUM > 1) ? $clog2(WAY_NUM) : 1)
    ,TAG_WID=14
    ,M_WIDTH=1//if this is 1, perform NRU, if>1, RRIP
    ,WBACK_ENABLE=1'b0 //this actually heavily depends on optimization
    
)
(
    input clk,
    input rst,
    //Core interface
    input entry_read,   
    input entry_wthru,
    input entry_wback,
    input [TAG_WID-1:0]address_tag,
    input [WAYADDR_WID-1:0]address_ent,	
    input valid_clear, //flush
    //BIU interface
    input [TAG_WID-1:0]refill_tag,
    input line_refill, //cachemem write, confirm refill valid
    input force_sync,//sync cache with memory(write back all dirty line)
    input writeback_ok,//data block write back complete, from cache BU
    output line_miss,//refill request
    output replace_dirty, //page dirty, need to write back first
    output [WAYSEL_WID-1:0]way_replace_sel, //for replace select& dirty flush select
    output [WAYSEL_WID-1:0]way_access_addr//addr for access 
);
localparam WAYADDR_WID = $clog2(WAY_DEPTH);
localparam HADDR_WID=WAYSEL_WID+WAYADDR_WID;
integer i,j;
genvar k;
reg [TAG_WID-1:0]tag_addr[WAY_DEPTH*WAY_NUM-1:0];
reg [WAY_NUM-1:0]line_valid[WAY_DEPTH-1:0];
reg [WAY_NUM-1:0]entry_hit;
wire [WAY_NUM-1:0]valid_comp;
assign valid_comp=line_valid[address_ent];
assign line_miss=(entry_read|entry_wback|entry_wthru) & (entry_hit==0);
always @(*)
    for ( i=0;i<WAY_NUM;i=i+1 ) 
    begin
        entry_hit[i]=(address_tag==tag_addr[address_ent*WAY_NUM+i])&valid_comp[i];
    end
//地址生成
reg [WAYSEL_WID-1:0]entry_select_encode[WAY_NUM-1:0];
assign way_access_addr=entry_select_encode[WAY_NUM-1];
always @(*)//cache命中选择优先编码器
begin
    entry_select_encode[0]=0;
    for ( i=1;i<WAY_NUM;i=i+1 ) 
    begin
        entry_select_encode[i]=sel_entry_cell(entry_select_encode[i-1],i,entry_hit[i]);
    end
end
reg [WAY_NUM-1:0]line_dirty[WAY_DEPTH-1:0];
wire [WAY_NUM-1:0]dirty_comp;
assign dirty_comp=line_dirty[address_ent];
wire [WAY_NUM-1:0]write_line_sel;
assign write_line_sel=sel_decode_sel(way_replace_sel);
always@(posedge clk)//Tag management
begin
    //Tag Valid management
    if(rst)
        for ( i=0 ;i<WAY_DEPTH;i=i+1 ) 
        begin
            line_valid[i]	<=	0;
            if(WBACK_ENABLE)line_dirty[i]   <=  0;
        end
    else 
        if( valid_clear ) //clear valid bit
        begin
            for ( i=0 ;i<WAY_DEPTH;i=i+1 ) 
                line_valid[i]	<=	0;
        end
    else 
        if (writeback_ok&WBACK_ENABLE) //dirty page synced,we can move forward
        begin
            line_dirty[address_ent] <=  line_dirty[address_ent]&(~write_line_sel);//clear dirty bit
        end
    else 
        if(line_refill)//in case refill, bit=1
        begin
            tag_addr[address_ent*WAY_NUM+way_replace_sel]	<=	refill_tag;
            line_valid[address_ent]<=line_valid[address_ent]|write_line_sel;//set valid bit to 1
        end
    else 
        if(entry_wback&(!line_miss)&WBACK_ENABLE) 
        begin
        line_dirty[address_ent]<=line_dirty[address_ent]|write_line_sel;//set dirty bit to 1
        end
end
//NRU Cache替换策略
wire [WAY_NUM-1:0]read_line_sel;
assign read_line_sel=sel_decode_sel(way_access_addr);
reg [WAY_NUM-1:0]recent_used[WAY_DEPTH-1:0];//0=not recent used 1=used
always@(posedge clk)//NRU寄存器管理
begin
    if(rst)//|(~recent_used)==0
    begin
        for ( i=0 ;i<WAY_DEPTH;i=i+1 ) 
            recent_used[i]<=0;
    end
    else 
        //for(i=0;i<WAY_NUM;i=i+1)
        begin
            if((~recent_used[way_access_addr])==0)
                recent_used[way_access_addr]<=0;
            else if(!line_miss)
            begin
                recent_used[way_access_addr]<=recent_used[way_access_addr]|read_line_sel;
            end
        end
end
//替换/写回管理
wire [WAY_NUM-1:0]recent_use_sel;
assign recent_use_sel=recent_used[way_access_addr];
reg [WAYSEL_WID-1:0]entry_replace_encode[WAY_NUM-1:0];
assign way_replace_sel=entry_replace_encode[WAY_NUM-1];
always @(*)//替换/写回选择优先编码器
begin
    entry_replace_encode[0]=0;
    for ( i=1;i<WAY_NUM;i=i+1 ) //从左向右扫描，高位cache单元优先换出
    begin
        entry_replace_encode[i]=sel_entry_cell(entry_replace_encode[i-1],i,!recent_use_sel[i]);//为0才换出
    end
end


assign replace_dirty=(WBACK_ENABLE)?line_dirty[way_replace_sel]:1'b0;//拟定替换cache line脏不？
//可扩展译码器
function [WAY_NUM-1:0]sel_decode_sel;
    input [WAYSEL_WID-1:0]sel_encode_in;
    integer k;
    for(k=0;k<WAY_NUM;k=k+1) 
    begin //: SEL_BITGEN
        sel_decode_sel[k]=(sel_encode_in==k);
    end
endfunction

//可扩展优先编码器：如果该位为1,返回该位所在编号,如果该位为0，传递上一级输入编号
function [WAYSEL_WID-1:0]sel_entry_cell;
    input [WAYSEL_WID-1:0]prev_entry_num;
    input [WAYSEL_WID-1:0]cur_entry_num;
    input cur_entry_bit;
    begin
   		sel_entry_cell=(cur_entry_bit)?cur_entry_num:prev_entry_num;
   	end
endfunction
endmodule
