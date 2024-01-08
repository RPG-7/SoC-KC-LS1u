<?xml version="1.0" encoding="UTF-8"?>
<Project>
    <Project_Created_Time>2024-01-01 03:26:33</Project_Created_Time>
    <TD_Version>4.6.64949</TD_Version>
    <UCode>00000000</UCode>
    <Name>KC_LS1u_SoC</Name>
    <HardWare>
        <Family>EF1</Family>
        <Device>EF1A650LG144</Device>
    </HardWare>
    <Source_Files>
        <Verilog>
            <File>../../RTL/cpu/CPU_LS1u.v</File>
            <File>../../RTL/cpu/alu74181.v</File>
            <File>../../RTL/cpu/pae32_mmu.v</File>
            <File>../../RTL/cpu/KC_LS1u.v</File>
            <File>../../RTL/cpu/KC_LS1u_plus.v</File>
            <File>../../RTL/cpu/KC_LS1u_dbg.v</File>
            <File>../../RTL/debug/jtagbridge.v</File>
            <File>../../RTL/cache/tag_LFU_arbiter.v</File>
            <File>../../RTL/cache/tag_arbiter_wa.v</File>
            <File>../../RTL/cache/tag_arbiter_fa.v</File>
            <File>../../RTL/cache/tag_arbiter_dm.v</File>
            <File>../../RTL/cache/l1.v</File>
            <File>../../RTL/cache/l1_unified.v</File>
            <File>../../RTL/cache/l1_ionly.v</File>
            <File>../../RTL/cache/cachemem.v</File>
            <File>../../RTL/cache/cacheable_lut.v</File>
            <File>../../RTL/cache/byte_sel.v</File>
            <File>../../RTL/cache/bus_unit.v</File>
            <File>../../RTL/cpu/XCR_Components/xcr_top.v</File>
            <File>../../RTL/cpu/XCR_Components/xcr_pae32_ctrl.v</File>
            <File>../../RTL/cpu/XCR_Components/xcr_ecp_ctrl.v</File>
            <File>../../RTL/cpu/XCR_Components/xcr_cdma.v</File>
            <File>../../RTL/peripherals/left_bshifter.v</File>
            <File>../../RTL/top/CPLD_LS1u.v</File>
            <File>../../RTL/cpu/CPU_LS1u_Lite.v</File>
            <File>../../RTL/hispeed/asram16_intf.v</File>
            <File>../../RTL/peripherals/tiny_spi.v</File>
        </Verilog>
        <ADC_FILE/>
        <SDC_FILE/>
        <CWC_FILE/>
    </Source_Files>
    <TOP_MODULE>
        <LABEL>CPU_LS1u/eXternalCtrlRegs</LABEL>
        <MODULE>xcr_top</MODULE>
        <CREATEINDEX>user</CREATEINDEX>
    </TOP_MODULE>
    <Property>
        <DesignProperty>
            <infer_fsm>auto</infer_fsm>
        </DesignProperty>
        <RtlProperty>
            <infer_gsr>on</infer_gsr>
            <keep_hierarchy>auto</keep_hierarchy>
            <opt_mux>on</opt_mux>
        </RtlProperty>
        <GateProperty>
            <opt_area>high</opt_area>
        </GateProperty>
        <GlobalProperty/>
        <PlaceProperty>
            <effort>high</effort>
            <opt_timing>low</opt_timing>
        </PlaceProperty>
        <RouteProperty>
            <effort>high</effort>
            <opt_timing>low</opt_timing>
        </RouteProperty>
    </Property>
    <Project_Settings>
        <Step_Last_Change>2024-01-03 23:41:45</Step_Last_Change>
        <Current_Step>30</Current_Step>
        <Step_Status>true</Step_Status>
    </Project_Settings>
</Project>