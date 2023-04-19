//Copyright (C)2014-2023 GOWIN Semiconductor Corporation.
//All rights reserved.
//File Title: Timing Constraints file
//GOWIN Version: 1.9.8.09 Education
//Created Time: 2023-04-20 00:02:27
create_clock -name SystemClk -period 10 -waveform {0 5} [get_nets {sysclk}]
report_high_fanout_nets -max_nets 30 -clock_regions -slr
report_max_frequency -mod_ins {CPU1 CPU1/CORE}
set_operating_conditions -grade c -model slow -speed 6 -setup -hold -max -min -max_min
