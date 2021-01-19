
include config.mak
HIERARCHY_FILE=$(REPORT_DIR)/hierarchy.rpt
help:
	@echo "\033[32mRTL-AUTOMATA RTL Automatic Build Script Usage:\033[0m"
	@echo "\033[33melaborate\033[0m to examine given TOP_MODULE and generate \033[34mhierarchy.rpt\033[0m"
	@echo "\033[33mlint\033[0m to check syntax errors of RTLs listed in \033[34mhierarchy.rpt\033[0m"
	@echo "\033[33mautosim\033[0m to automaically simulate testebench of the given \033[34mTB_MODULE\033[0m"
	@echo "\033[33mfpgaflow_VENDOR\033[0m to synthesize the project and attempt to generate bitstream(\033[31mNOT PRESENT\033[0m)"
	@echo "\033[32mATTENTION:Replace VENDOR with specific vendor name (gowin/anlogic/altera)\033[0m"
	@echo "\033[33masicflow\033[0m to run RTL2GDS digital ASIC flow(\033[31mNOT PRESENT\033[0m)"
	@echo "\033[33mclean\033[0m to clean all objects and temp files"
elaborate:
	bash ./script/elaborate.sh $(TOP_MODULE) $(RTL_DIR) $(INCLUDE_DIR) $(HIERARCHY_FILE)
lint:$(REPORT_DIR)/hierarchy.rpt
	bash ./script/lint.sh $(INCLUDE_DIR) $(HIERARCHY_FILE)
autosim:
	bash ./script/simprep.sh $(TB_MODULE) $(TB_DIR) $(SIMU_INCDIR) $(HIERARCHY_FILE) $(RTL_DIR) $(OBJ_DIR)
	bash ./temp/PREPROCESSOR.sh
	cat $(REPORT_DIR)/tb_hierarchy.rpt|xargs iverilog -o $(OBJ_DIR)/tb.run $(SIMU_PARAM)
	vvp $(OBJ_DIR)/tb.run
	#gtkwave $(OBJ_DIR)/$(TB_MODULE).vcd
wave:
	gtkwave $(OBJ_DIR)/$(TB_MODULE).vcd


fpgaflow_%:$(REPORT_DIR)/hierarchy.rpt

asicflow:#$(REPORT_DIR)/hierarchy.rpt
	bash ./script/hierarchy_export.sh 
	qflow gui -T $(ASIC_PDK) -p temp $(TOP_MODULE)

#ctools:
#	$(MAKE) -C sim/make

.PHONY: make help

.PHONY: clean
clean:
	-rm -r $(REPORT_DIR)/*
	-rm $(OBJ_DIR)/*
	-find ./ -name "*.bak"|xargs rm
