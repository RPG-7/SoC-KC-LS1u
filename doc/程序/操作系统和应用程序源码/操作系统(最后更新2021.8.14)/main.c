#include<io.h>
#include<qjbldy.h>
#include<VGA.h>
#include<string.h>
#include<printing.h>
#include<ds1302.h>
#include<spi.h>
#include<keyboard.h>
#include<CH375.h>
#include<tf_sd.h>
#include<fat32.h>
#include<VS1003.h>
#include<sys_in_boot.h>
#include<add_sys.h>
#include<sys_GUI.h>



main()
{

unsigned char i;

    VGA_VRAM_LD(); //装载显存
    VGA_SK0(0,240,0); //VGA清屏
    printx(0,0,"Longshao system startup...",255); //打印字符串
    VGA_VRAM_UP(); //更新显存

    SPI_RST(); //复位SPI控制器
    //DS1302_RTC_UP(0x21,0x08,0x03,0x03,0x20,0x00);  //更新年月日时分秒

    TF_SD_CSH(0); //初始化设备0内存卡
    TF_SD_CSH(1); //初始化设备1内存卡

    FAT32_csh(0); //初始化设备0文件系统
    FAT32_csh(1); //初始化设备1文件系统


    VGA_VRAM_LD();
    printx(14, 0, "Load system files...", 255); //打印字符串
    VGA_VRAM_UP();

    if((i = ADD_SYS()) != 1) //加载系统文件
    {
       VGA_VRAM_LD();
       printx(28, 0, "File not found!", 255); //打印字符串
       VGA_VRAM_UP();
       while(1);
    }

    VGA_VRAM_LD();
    printx(28, 0, "File loaded successfully.", 255); //打印字符串
    VGA_VRAM_UP();

    CH375_CSH(); //初始化CH375
    VS1003_CSH(); //初始化VS1003
    GUI_CSH(); //GUI初始化

    VGA_VRAM_LD();
    printx(42, 0, "startup.", 255); //打印字符串
    VGA_VRAM_UP();

    while(1)
    {
        GUI_RUN(CH375_RUN()); //运行GUI和CH375
    }

}