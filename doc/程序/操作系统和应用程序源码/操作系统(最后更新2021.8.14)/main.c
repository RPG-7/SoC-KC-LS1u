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

    VGA_VRAM_LD(); //װ���Դ�
    VGA_SK0(0,240,0); //VGA����
    printx(0,0,"Longshao system startup...",255); //��ӡ�ַ���
    VGA_VRAM_UP(); //�����Դ�

    SPI_RST(); //��λSPI������
    //DS1302_RTC_UP(0x21,0x08,0x03,0x03,0x20,0x00);  //����������ʱ����

    TF_SD_CSH(0); //��ʼ���豸0�ڴ濨
    TF_SD_CSH(1); //��ʼ���豸1�ڴ濨

    FAT32_csh(0); //��ʼ���豸0�ļ�ϵͳ
    FAT32_csh(1); //��ʼ���豸1�ļ�ϵͳ


    VGA_VRAM_LD();
    printx(14, 0, "Load system files...", 255); //��ӡ�ַ���
    VGA_VRAM_UP();

    if((i = ADD_SYS()) != 1) //����ϵͳ�ļ�
    {
       VGA_VRAM_LD();
       printx(28, 0, "File not found!", 255); //��ӡ�ַ���
       VGA_VRAM_UP();
       while(1);
    }

    VGA_VRAM_LD();
    printx(28, 0, "File loaded successfully.", 255); //��ӡ�ַ���
    VGA_VRAM_UP();

    CH375_CSH(); //��ʼ��CH375
    VS1003_CSH(); //��ʼ��VS1003
    GUI_CSH(); //GUI��ʼ��

    VGA_VRAM_LD();
    printx(42, 0, "startup.", 255); //��ӡ�ַ���
    VGA_VRAM_UP();

    while(1)
    {
        GUI_RUN(CH375_RUN()); //����GUI��CH375
    }

}