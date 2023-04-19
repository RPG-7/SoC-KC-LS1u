/**********************************************/
/*
/*	ch375键盘鼠标U盘驱动	2015-2022.10 龙少
/*
/**********************************************/

#include "cpuio.h"

/* CH375接口IO定义 */
#define CH375_DATA		IO1
#define CH375_A0		M_IO0_DO3
#define CH375_WR		M_IO0_DO7
#define CH375_RD		M_IO0_DO6

/* 设备0 */
#define CH375_CS_0		M_CS3
#define CH375_INT_0		M_IO0_DI1

/* 设备1 */
#define CH375_CS_1		M_CS5
#define CH375_INT_1		M_IO0_DI2

/* IO控制宏 */
#define CH375_CS_LOW(device)        (IO0 = IO0_INIT_VALUE | ((unsigned char)(device) == (unsigned char)0 ? CH375_CS_0 : CH375_CS_1))
#define CH375_CS_A0_WR_RD_HIGH		(IO0 = IO0_INIT_VALUE)
#define CH375_CS_RD_LOW(device)		(IO0 = (IO0_INIT_VALUE | ((unsigned char)(device) == (unsigned char)0 ? CH375_CS_0 : CH375_CS_1)) & ~CH375_RD)
#define CH375_CS_WR_LOW(device)		(IO0 = (IO0_INIT_VALUE | ((unsigned char)(device) == (unsigned char)0 ? CH375_CS_0 : CH375_CS_1)) & ~CH375_WR)
#define CH375_CS_A0_LOW(device)		(IO0 = (IO0_INIT_VALUE | ((unsigned char)(device) == (unsigned char)0 ? CH375_CS_0 : CH375_CS_1)) & ~CH375_A0)
#define CH375_CS_A0_RD_LOW(device)	(IO0 = (IO0_INIT_VALUE | ((unsigned char)(device) == (unsigned char)0 ? CH375_CS_0 : CH375_CS_1)) & ~CH375_A0 & ~CH375_RD)
#define CH375_CS_A0_WR_LOW(device)	(IO0 = (IO0_INIT_VALUE | ((unsigned char)(device) == (unsigned char)0 ? CH375_CS_0 : CH375_CS_1)) & ~CH375_A0 & ~CH375_WR)
#define CH375_GET_INT(device)		((unsigned char)(device) == (unsigned char)0 ? ((IO0 & CH375_INT_0) / CH375_INT_0) : ((IO0 & CH375_INT_1) / CH375_INT_1))

/* 写命令寄存器 */
#define CH375_WR_COMDREG(device, data) \
	CH375_DATA = (data); \
	CH375_CS_WR_LOW(device); \
	CH375_CS_LOW(device);

/* 写数据寄存器 */
#define CH375_WR_DATAREG(device, data) \
	CH375_DATA = (data); \
	CH375_CS_A0_WR_LOW(device); \
	CH375_CS_A0_LOW(device);

/* 读数据寄存器 */
#define CH375_RD_DATAREG(device, data) \
	CH375_CS_A0_RD_LOW(device); \
	(data) = CH375_DATA; \
	CH375_CS_A0_LOW(device);

/* USB设备代码 */
#define NO_DEVICE			(unsigned char)0x00	//无设备
#define DEVICE_KEY			(unsigned char)0x01	//键盘
#define DEVICE_MOUSE		(unsigned char)0x02	//鼠标
#define DEVICE_FLASH_DISK	(unsigned char)0x04	//存储器

/* 键盘键值查询 */
#define Keyboard_A KeyQuery(0x04)
#define Keyboard_B KeyQuery(0x05)
#define Keyboard_C KeyQuery(0x06)
#define Keyboard_D KeyQuery(0x07)
#define Keyboard_E KeyQuery(0x08)
#define Keyboard_F KeyQuery(0x09)
#define Keyboard_G KeyQuery(0x0a)
#define Keyboard_H KeyQuery(0x0b)
#define Keyboard_I KeyQuery(0x0c)
#define Keyboard_J KeyQuery(0x0d)
#define Keyboard_K KeyQuery(0x0e)
#define Keyboard_L KeyQuery(0x0f)
#define Keyboard_M KeyQuery(0x10)
#define Keyboard_N KeyQuery(0x11)
#define Keyboard_O KeyQuery(0x12)
#define Keyboard_P KeyQuery(0x13)
#define Keyboard_Q KeyQuery(0x14)
#define Keyboard_R KeyQuery(0x15)
#define Keyboard_S KeyQuery(0x16)
#define Keyboard_T KeyQuery(0x17)
#define Keyboard_U KeyQuery(0x18)
#define Keyboard_V KeyQuery(0x19)
#define Keyboard_W KeyQuery(0x1a)
#define Keyboard_X KeyQuery(0x1b)
#define Keyboard_Y KeyQuery(0x1c)
#define Keyboard_Z KeyQuery(0x1d)
#define Keyboard_1 KeyQuery(0x1e)
#define Keyboard_2 KeyQuery(0x1f)
#define Keyboard_3 KeyQuery(0x20)
#define Keyboard_4 KeyQuery(0x21)
#define Keyboard_5 KeyQuery(0x22)
#define Keyboard_6 KeyQuery(0x23)
#define Keyboard_7 KeyQuery(0x24)
#define Keyboard_8 KeyQuery(0x25)
#define Keyboard_9 KeyQuery(0x26)
#define Keyboard_0 KeyQuery(0x27)
#define Keyboard_RightArrow KeyQuery(0x4f)
#define Keyboard_LeftArrow KeyQuery(0x50)
#define Keyboard_DownArrow KeyQuery(0x51)
#define Keyboard_UpArrow KeyQuery(0x52)

extern unsigned char USB_Device_Code[];
extern unsigned char Key_Value[];
extern unsigned char Mouse_Button;
extern unsigned short Mouse_X;
extern unsigned short Mouse_Y;
extern unsigned short Mouse_Wheel;

extern void CH375_Init();
extern unsigned char UsbUpdate();
extern unsigned char CH375_RD_LBA(unsigned char device, unsigned long sector, unsigned char count, unsigned char* buf);
extern unsigned char CH375_WR_LBA(unsigned char device, unsigned long sector, unsigned char count, unsigned char* buf);
extern unsigned char KeyQuery(unsigned char value);
