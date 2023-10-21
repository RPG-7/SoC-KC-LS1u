//IR act as DBG CTRL (reset / step /inject / halt)
//currently, whole JTAG registers defined as MSB first
//DR instruction inject(i)
//   read from CPU bus & CPU status  
//   Shift in instruction, read from bus
//   SDR(load instr)->E2D->SDR(get previous status)->UDR(commit current instr)->.....
//jtck <-> sysclk cdc will always run
//note: after read status with e2d, you could change instr with another e2d
//DR Step mode
//Select IR CMD->SDR(read prev status)->E1D(issue cmd)->PDR->E2D(data ready)->SDR.....


//inject cmd definition:
//0x0 Read CPU status (actually dummy cmd)
//0x1 Inject instruction to CPU
//0x2 Step the CPU
//0x3 RESERVED

//status pkt format 
//{CMDACK,{3{RESERVED}},TFLAG,JFLAG,CFLAG,PRIO,{8{WBData}}}
//if a 0x55aa is shifted in status phase, 
//CPU reset will be ordered instead of cmd inject
//valid on both STEP mode or INJECT mode, ordered on E1D phase

module jtagbridge
#( parameter JTAG_ID=16'h1234)
(
    //JTAG ports
    input sys_por,
    input jtms,
    input jtck,
    input jtdi,
    output jtdo,

    //system ports (also sys clk domain)
    input sys_clk,
    output reset_out,
    output step_mode, //Also act as halt
    output inject_req,
    output reg[1:0]dbg_cmd,
    output reg [15:0]inject_instr,
    //
    input [7:0]dbus_in,
    input jflag,
    input cflag,
    input tflag,
    input prio,
    input inject_ack//Also act as cmd ready

);
localparam JTAG_RTI = 4'h0; 
localparam JTAG_SDS = 4'h1;//Select DR Scan
localparam JTAG_CDR = 4'h2;//Capture DR
localparam JTAG_SDR = 4'h3;//Sft FR
localparam JTAG_E1D = 4'h4;//Exit DR
localparam JTAG_PDR = 4'h5;//Pause DR
localparam JTAG_E2D = 4'h6;//Exit 2 SDR
localparam JTAG_UDR = 4'h7;//Update DR
localparam JTAG_SIS = 4'h8;//Select
localparam JTAG_CIR = 4'h9;
localparam JTAG_SIR = 4'ha;
localparam JTAG_E1I = 4'hb;
localparam JTAG_PIR = 4'hc;
localparam JTAG_E2I = 4'hd;
localparam JTAG_UIR = 4'he;
localparam JTAG_TLR = 4'hF;//Reset Target TAP


localparam IR_BYPASS = 4'hF;
localparam IR_IDCODE = 4'hE;
localparam IR_INJECT = 4'hD; //Command inject
localparam IR_DUTRST = 4'hC; //whole DUT system reset

localparam IR_DUTSTP = 4'h7; //whole DUT system reset
localparam IR_DUTRUN = 4'h0;

localparam CMD_DUMMY = 4'h0; 
localparam CMD_INJEC = 4'h1;
localparam CMD_STEP  = 4'h2;
localparam CMD_RESERVE  = 4'h3;

wire jtagsys_rst;
reg [3:0] jtag_state;
reg [3:0] jtag_nextstate;
reg [3:0]jtag_ir;
reg [3:0]jtag_irsft;
//reg [15:0]jtag_dr;
reg [15:0]jtag_drsft;

always@(posedge jtck or posedge sys_por)
if(sys_por) begin
    jtag_state<=JTAG_TLR;
end
else begin
    jtag_state<=jtag_nextstate;
end

always@(*)
case(jtag_state)
	JTAG_RTI    :   jtag_nextstate= (jtms)? JTAG_SDS:JTAG_RTI;
	JTAG_SDS    :   jtag_nextstate= (jtms)? JTAG_SIS:JTAG_CDR;
	JTAG_CDR    :   jtag_nextstate= (jtms)? JTAG_E1D:JTAG_SDR;
	JTAG_SDR    :   jtag_nextstate= (jtms)? JTAG_E1D:JTAG_SDR;
	JTAG_E1D    :   jtag_nextstate= (jtms)? JTAG_UDR:JTAG_PDR;
	JTAG_PDR    :   jtag_nextstate= (jtms)? JTAG_E2D:JTAG_PDR;
	JTAG_E2D    :   jtag_nextstate= (jtms)? JTAG_UDR:JTAG_SDR;
	JTAG_UDR    :   jtag_nextstate= (jtms)? JTAG_SDS:JTAG_RTI;
	JTAG_SIS    :   jtag_nextstate= (jtms)? JTAG_TLR:JTAG_CIR;
	JTAG_CIR    :   jtag_nextstate= (jtms)? JTAG_E1I:JTAG_SIR;
	JTAG_SIR    :   jtag_nextstate= (jtms)? JTAG_E1I:JTAG_SIR;
	JTAG_E1I    :   jtag_nextstate= (jtms)? JTAG_UIR:JTAG_PIR;
	JTAG_PIR    :   jtag_nextstate= (jtms)? JTAG_E2I:JTAG_PIR;
	JTAG_E2I    :   jtag_nextstate= (jtms)? JTAG_UIR:JTAG_SIR;
	JTAG_UIR    :   jtag_nextstate= (jtms)? JTAG_SDS:JTAG_RTI;
	JTAG_TLR    :   jtag_nextstate= (jtms)? JTAG_TLR:JTAG_RTI; 
endcase
wire jcmd_ack;
wire [15:0]jtag_dbgdata = {jcmd_ack,3'b0,tflag,jflag,cflag,dbus_in};
wire jtag_dr_load_status;
assign jtag_dr_load_status =( jtag_state == JTAG_E2D && jtag_ir == IR_DUTSTP )| //In Step command, will load status into DR by default
     (jtag_ir == IR_INJECT && jtag_state == JTAG_CDR );

//JTAG DRs
always@(posedge jtck)
if(jtagsys_rst | jtag_ir == IR_IDCODE)
    jtag_drsft<=JTAG_ID;
else if(jtag_state == JTAG_SDR)
    jtag_drsft<={jtag_drsft[14:0],jtdi};
else if(jtag_dr_load_status)
    jtag_drsft<=jtag_dbgdata;
else if(jtag_state == JTAG_E2D)
    jtag_drsft<=inject_instr;

//Inject Instruction
always@(posedge jtck)
if(jtagsys_rst )
    inject_instr<=16'h0000;
else if(jtag_ir == IR_INJECT && jtag_state == JTAG_UDR )
    inject_instr<=jtag_drsft;
else 
    inject_instr<=inject_instr;

//Inject Commands
always@(posedge jtck)
if(jtagsys_rst )
    dbg_cmd<=CMD_DUMMY;
else if(jtag_ir == IR_INJECT )
    dbg_cmd<=CMD_INJEC;
else if(jtag_ir == IR_DUTSTP )
    dbg_cmd<=CMD_STEP;
reg jtag_inject_req;
always@(posedge jtck)
if(jtagsys_rst  |jcmd_ack)
    jtag_inject_req<=1'b0;
else 
    jtag_inject_req<=   ( jtag_state == JTAG_E1D && jtag_ir == IR_DUTSTP) |
                        (jtag_ir == IR_INJECT && jtag_state == JTAG_UDR );
//JTAG IR
always@(posedge jtck or posedge sys_por)
if(sys_por)
    jtag_irsft<=0;
else if(jtag_state == JTAG_SIR)
    jtag_irsft<={jtag_irsft[2:0],jtdi};
else 
    jtag_irsft<=jtag_irsft;

always@(posedge jtck or posedge sys_por)
if(sys_por)
    jtag_ir<=IR_DUTRUN;
else if(jtag_state == JTAG_UIR)
    jtag_ir<=jtag_irsft;
else
    jtag_ir<=jtag_ir;

assign jtagsys_rst= jtag_state == JTAG_TLR;
assign jtdo=(jtag_state == JTAG_SDR)?jtag_drsft[15]:jtag_irsft[3];
// sys clk domain signals
reg [1:0] sysrst_cdc,stepmod_cdc,jrst_cdc;
wire sysrst_trig,step_trig;
assign sysrst_trig = (jtag_ir == IR_DUTRST) | sys_por;
always @(posedge sys_clk or posedge sysrst_trig) 
if(sysrst_trig)
    sysrst_cdc<=2'b11;
else
    sysrst_cdc<={sysrst_cdc[0],1'b0};

always @(posedge sys_clk or posedge sysrst_trig)
if(sysrst_trig)
    jrst_cdc<=2'b11;
else
    jrst_cdc<={jrst_cdc[0],jtagsys_rst};

assign step_trig= (jtag_ir == IR_INJECT) | (jtag_ir == IR_DUTSTP);

always @(posedge sys_clk)
if(jrst_cdc[1])
    stepmod_cdc<=2'b00;
else
    stepmod_cdc<={stepmod_cdc[0],step_trig};
assign step_mod = stepmod_cdc[1];

assign reset_out= sysrst_cdc[1];
//cmd inject logic
reg [1:0]cmdreq_cdc;
reg [1:0]cmdack_cdc;
reg cmd_complete;
reg inject_fired;
wire inject_flg_clr;

always@(posedge sys_clk or posedge sysrst_trig)
if(sysrst_trig)
begin
    cmdreq_cdc<=2'b00;
    inject_fired<=0;
end
else
begin
    inject_fired<=jtag_inject_req;
    cmdreq_cdc<={cmdreq_cdc[0],jtag_inject_req && (!cmd_complete)};
end
assign inject_flg_clr = jtag_inject_req && (!inject_fired);
assign inject_req = cmdreq_cdc[1];

always@(posedge jtck)
if(jtagsys_rst |inject_flg_clr)
    cmdack_cdc<=2'b0;
else if(jtag_inject_req)
    cmdack_cdc<={cmdack_cdc[0],inject_ack};

always@(posedge jtck)
if(jtagsys_rst |inject_flg_clr)
    cmd_complete<=CMD_DUMMY;
else if(jtag_inject_req)
    cmd_complete<=cmd_complete | cmdack_cdc[1];
//assign dbg_cmd = (jtag_ir == IR_INJECT) ? 2'b01 :2'b10;
assign jcmd_ack = cmd_complete;
endmodule
