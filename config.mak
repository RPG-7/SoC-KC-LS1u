#This file is to store Project-specific variables and toolchain setting
#Project-specific make instructions should also be placed here
#This file is a part of the RTL-AUTOMATA project
SIMULATOR=iverilog
SIMU_PARAM=-I $(SIMU_INCDIR) -I $(UVM_INCDIR)
SYNTHESIZER=qflow synthesize
RTL_DIR = ./RTL
TB_DIR=./sim
ASIC_PDK=osu018
OBJ_DIR=./obj
REPORT_DIR=./temp
INCLUDE_DIR=./RTL/
SIMU_INCDIR=./sim/
UVM_INCDIR=./sim/uvm_library/
TOP_MODULE=KC_LS1u_plus
TB_MODULE=KC_LS1u_plus_tb
SHOW_WAVEFORM=TRUE
