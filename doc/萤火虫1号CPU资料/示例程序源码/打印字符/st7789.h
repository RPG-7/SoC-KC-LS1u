/**********************************************/
/*
/*		st7789驱动		2022.10 龙少
/*
/**********************************************/

#include "cpuio.h"

/* LCD接口IO定义 */
#define LCD_CS      M_CS1
#define LCD_DC      M_IO0_DO3
#define LCD_RES     M_IO0_DO4
#define LCD_SDA     M_IO1_D7
#define LCD_SCL     M_IO0_DO5

/* IO控制宏 */
#define LCD_RES_LOW                 (IO0 = IO0_INIT_VALUE & ~LCD_RES)
#define LCD_CS_LOW                  (IO0 = IO0_INIT_VALUE | LCD_CS)
#define LCD_CS_SCL_LOW              (IO0 = (IO0_INIT_VALUE | LCD_CS) & ~LCD_SCL)
#define LCD_CS_DC_LOW               (IO0 = (IO0_INIT_VALUE | LCD_CS) & ~LCD_DC)
#define LCD_CS_DC_SCL_LOW           (IO0 = (IO0_INIT_VALUE | LCD_CS) & ~LCD_DC & ~LCD_SCL)
#define LCD_CS_DC_RES_SCL_HIGH      (IO0 = IO0_INIT_VALUE)

/* LCD方向 */
#define LCD_DIR		3

/* 宽高切换 */
#if (LCD_DIR == 0) || (LCD_DIR == 2)
#define LCD_WIDTH	240
#define LCD_HIGH	320
#elif (LCD_DIR == 1) || (LCD_DIR == 3)
#define LCD_WIDTH	320
#define LCD_HIGH	240
#endif

/* LCD写命令寄存器 */
#define Lcd_WriteIndex(data) \
    IO1 = (unsigned char)(data); \
    LCD_CS_DC_SCL_LOW; \
    LCD_CS_DC_LOW; \
    IO1 = (unsigned char)(data) << 1; \
    LCD_CS_DC_SCL_LOW; \
    LCD_CS_DC_LOW; \
    IO1 = (unsigned char)(data) << 2; \
    LCD_CS_DC_SCL_LOW; \
    LCD_CS_DC_LOW; \
    IO1 = (unsigned char)(data) << 3; \
    LCD_CS_DC_SCL_LOW; \
    LCD_CS_DC_LOW; \
    IO1 = (unsigned char)(data) << 4; \
    LCD_CS_DC_SCL_LOW; \
    LCD_CS_DC_LOW; \
    IO1 = (unsigned char)(data) << 5; \
    LCD_CS_DC_SCL_LOW; \
    LCD_CS_DC_LOW; \
    IO1 = (unsigned char)(data) << 6; \
    LCD_CS_DC_SCL_LOW; \
    LCD_CS_DC_LOW; \
    IO1 = (unsigned char)(data) << 7; \
    LCD_CS_DC_SCL_LOW; \
    LCD_CS_DC_LOW;

/* LCD写数据寄存器 */
#define Lcd_WriteData(data) \
    IO1 = (unsigned char)(data); \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    IO1 = (unsigned char)(data) << 1; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    IO1 = (unsigned char)(data) << 2; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    IO1 = (unsigned char)(data) << 3; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    IO1 = (unsigned char)(data) << 4; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    IO1 = (unsigned char)(data) << 5; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    IO1 = (unsigned char)(data) << 6; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    IO1 = (unsigned char)(data) << 7; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW;

/* LCD写16位数据寄存器 */
#define Lcd_WriteData_16Bit(data) \
    Lcd_WriteData(data >> 8); \
    Lcd_WriteData(data);

/* LCD写16位数据寄存器(对于变量优化) */
#define Lcd_WriteData_16Bit_V(data) \
    IO1 = ((unsigned char*)&(data))[1]; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    IO1 <<= 1; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    IO1 <<= 1; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    IO1 <<= 1; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    IO1 <<= 1; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    IO1 <<= 1; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    IO1 <<= 1; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    IO1 <<= 1; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    IO1 = ((unsigned char*)&(data))[0]; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    IO1 <<= 1; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    IO1 <<= 1; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    IO1 <<= 1; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    IO1 <<= 1; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    IO1 <<= 1; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    IO1 <<= 1; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    IO1 <<= 1; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW;

/* LCD绘制像素 */
#define Lcd_Draw_Pixel_0(x, y, Color) \
	Lcd_WriteIndex(0x2a); \
    Lcd_WriteData_16Bit(x); \
    Lcd_WriteIndex(0x2b); \
    Lcd_WriteData_16Bit(y); \
    Lcd_WriteIndex(0x2c); \
    Lcd_WriteData_16Bit(Color);

/* LCD设置x寄存器 */
#define Lcd_Set_Reg_X(x) \
    Lcd_WriteIndex(0x2a); \
    Lcd_WriteData_16Bit(x);

/* LCD设置y寄存器 */
#define Lcd_Set_Reg_Y(y) \
    Lcd_WriteIndex(0x2b); \
    Lcd_WriteData_16Bit(y);

/* LCD设置Color寄存器 */
#define Lcd_Set_Reg_Color(Color) \
    Lcd_WriteIndex(0x2c); \
    Lcd_WriteData_16Bit(Color);

/* LCD写16位数据寄存器(8位332转换为16位565) */
#define Lcd_WriteData_8Bit332(data) \
    IO1 = (unsigned char)(data); \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    IO1 <<= 1; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    IO1 <<= 1; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    IO1 <<= 1; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    IO1 <<= 1; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    IO1 <<= 1; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    IO1 <<= 1; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    IO1 <<= 1; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW; \
    LCD_CS_SCL_LOW; \
    LCD_CS_LOW;


extern void Lcd_ST7789_Init(unsigned short Color);
extern void Lcd_Clear(unsigned short Color);
extern void Lcd_SetRegion(unsigned short x_start, unsigned short x_end, unsigned short y_start, unsigned short y_end);
extern void Lcd_Draw_Pixel(unsigned short x, unsigned short y, unsigned short Color);
extern void Lcd_Fill_Rectangle(unsigned short x, unsigned short y, unsigned short wieth, unsigned short high, unsigned short Color);
extern void Lcd_MappRam(unsigned short x, unsigned short y, unsigned short wieth, unsigned short high, unsigned short* vram);
