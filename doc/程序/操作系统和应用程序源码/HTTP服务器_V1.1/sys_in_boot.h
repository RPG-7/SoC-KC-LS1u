void sys_in_boot_0() //返回系统函数
{
    XT_C = 0x01; //设置系统控制寄存器,跳过开机画面,使用"KC_LS1u_boot_0.txt"引导文本的引导路径
    rom_run; //切换ROM,启动"KC_LS1u_boot_0.txt"引导文本的引导路径指向的BIN文件
}

void sys_in_boot_1() //启动程序函数
{
    XT_C = 0x11; //设置系统控制寄存器,跳过开机画面,使用"KC_LS1u_boot_1.txt"引导文本的引导路径
    rom_run; //切换ROM,启动"KC_LS1u_boot_1.txt"引导文本的引导路径指向的BIN文件
}