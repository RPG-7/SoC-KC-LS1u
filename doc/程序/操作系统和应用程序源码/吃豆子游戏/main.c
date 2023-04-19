#include<io.h>
#include<qjbldy.h>
#include<sys_in_boot.h>
#include<VGA.h>
#include<string.h>
#include<printing.h>
#include<spi.h>
#include<CH375.h>
#include<keyboard.h>
#include<chidouzi.h>


main()
{

unsigned char i;

    VGA_VRAM_LD(); //装载显存
    VGA_SK0(0,240,0); //VGA清屏
    VGA_VRAM_UP(); //更新显存
    SPI_RST(); //复位SPI控制器
    CH375_CSH(); //初始化CH375
    VGA_VRAM_LD(); //装载显存
    chidouzi_init(); //吃豆子初始化
    VGA_VRAM_UP(); //更新显存

    while(1)
    {
        CH375_RUN();

        if (keyboard_UpArrow() != 0) KEY_O = 1; else KEY_O = 0; //对接游戏的上键
        if (keyboard_DownArrow() != 0) KEY_U = 1; else KEY_U = 0; //对接游戏的下键
        if (keyboard_LeftArrow() != 0) KEY_L = 1; else KEY_L = 0; //对接游戏的左键
        if (keyboard_RightArrow() != 0) KEY_R = 1; else KEY_R = 0; //对接游戏的右键
        if (keyboard_Spacebar() != 0) KEY_D = 1; else KEY_D = 0; //对接游戏的开始键
        if (keyboard_ESCAPE() != 0) sys_in_boot_0(); //退出游戏返回操作系统

        VGA_VRAM_LD(); //装载显存
        for (i = 0; i < z; ++i) chidouzi_run();
        VGA_VRAM_UP(); //更新显存
    }
}