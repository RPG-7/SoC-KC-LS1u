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

    VGA_VRAM_LD(); //װ���Դ�
    VGA_SK0(0,240,0); //VGA����
    VGA_VRAM_UP(); //�����Դ�
    SPI_RST(); //��λSPI������
    CH375_CSH(); //��ʼ��CH375
    VGA_VRAM_LD(); //װ���Դ�
    chidouzi_init(); //�Զ��ӳ�ʼ��
    VGA_VRAM_UP(); //�����Դ�

    while(1)
    {
        CH375_RUN();

        if (keyboard_UpArrow() != 0) KEY_O = 1; else KEY_O = 0; //�Խ���Ϸ���ϼ�
        if (keyboard_DownArrow() != 0) KEY_U = 1; else KEY_U = 0; //�Խ���Ϸ���¼�
        if (keyboard_LeftArrow() != 0) KEY_L = 1; else KEY_L = 0; //�Խ���Ϸ�����
        if (keyboard_RightArrow() != 0) KEY_R = 1; else KEY_R = 0; //�Խ���Ϸ���Ҽ�
        if (keyboard_Spacebar() != 0) KEY_D = 1; else KEY_D = 0; //�Խ���Ϸ�Ŀ�ʼ��
        if (keyboard_ESCAPE() != 0) sys_in_boot_0(); //�˳���Ϸ���ز���ϵͳ

        VGA_VRAM_LD(); //װ���Դ�
        for (i = 0; i < z; ++i) chidouzi_run();
        VGA_VRAM_UP(); //�����Դ�
    }
}