/**********************************************/
/*
/*		st7789Çý¶¯		2022.10 ÁúÉÙ
/*
/**********************************************/

#include "st7789.h"
#include "delay.h"

/* LCD³õÊ¼»¯ */
void Lcd_ST7789_Init(unsigned short Color) {
	IO0_INIT;

	LCD_RES_LOW; //RES = 0
	Delay(65535);
	LCD_CS_DC_RES_SCL_HIGH; //RES = 1
	Delay(65535);

	Lcd_WriteIndex(0x36);
#if (LCD_DIR == 0)
	Lcd_WriteData(0x00);
#elif (LCD_DIR == 1)
	Lcd_WriteData(0xa0);
#elif (LCD_DIR == 2)
	Lcd_WriteData(0xc0);
#elif (LCD_DIR == 3)
	Lcd_WriteData(0x60);
#endif

	Lcd_WriteIndex(0x3A);
	Lcd_WriteData(0x05);

	Lcd_WriteIndex(0xB2);
	Lcd_WriteData(0x0C);
	Lcd_WriteData(0x0C);
	Lcd_WriteData(0x00);
	Lcd_WriteData(0x33);
	Lcd_WriteData(0x33);

	Lcd_WriteIndex(0xB7);
	Lcd_WriteData(0x35);

	Lcd_WriteIndex(0xBB);
	Lcd_WriteData(0x19);

	Lcd_WriteIndex(0xC0);
	Lcd_WriteData(0x2C);

	Lcd_WriteIndex(0xC2);
	Lcd_WriteData(0x01);

	Lcd_WriteIndex(0xC3);
	Lcd_WriteData(0x12);

	Lcd_WriteIndex(0xC4);
	Lcd_WriteData(0x20);

	Lcd_WriteIndex(0xC6);
	Lcd_WriteData(0x0F);

	Lcd_WriteIndex(0xD0);
	Lcd_WriteData(0xA4);
	Lcd_WriteData(0xA1);

	Lcd_WriteIndex(0xE0);
	Lcd_WriteData(0xD0);
	Lcd_WriteData(0x04);
	Lcd_WriteData(0x0D);
	Lcd_WriteData(0x11);
	Lcd_WriteData(0x13);
	Lcd_WriteData(0x2B);
	Lcd_WriteData(0x3F);
	Lcd_WriteData(0x54);
	Lcd_WriteData(0x4C);
	Lcd_WriteData(0x18);
	Lcd_WriteData(0x0D);
	Lcd_WriteData(0x0B);
	Lcd_WriteData(0x1F);
	Lcd_WriteData(0x23);

	Lcd_WriteIndex(0xE1);
	Lcd_WriteData(0xD0);
	Lcd_WriteData(0x04);
	Lcd_WriteData(0x0C);
	Lcd_WriteData(0x11);
	Lcd_WriteData(0x13);
	Lcd_WriteData(0x2C);
	Lcd_WriteData(0x3F);
	Lcd_WriteData(0x44);
	Lcd_WriteData(0x51);
	Lcd_WriteData(0x2F);
	Lcd_WriteData(0x1F);
	Lcd_WriteData(0x1F);
	Lcd_WriteData(0x20);
	Lcd_WriteData(0x23);

	Lcd_WriteIndex(0x21);
	Lcd_WriteIndex(0x11);
	Lcd_WriteIndex(0x29);

	Lcd_Clear(Color);
}

/* ÉèÖÃ·¶Î§×ø±ê */
void Lcd_SetRegion(unsigned short x_start, unsigned short x_end, unsigned short y_start, unsigned short y_end) {
	Lcd_WriteIndex(0x2a);
	Lcd_WriteData_16Bit_V(x_start);
	Lcd_WriteData_16Bit_V(x_end);
	Lcd_WriteIndex(0x2b);
	Lcd_WriteData_16Bit_V(y_start);
	Lcd_WriteData_16Bit_V(y_end);
}

/* »æÖÆÏñËØ */
void Lcd_Draw_Pixel(unsigned short x, unsigned short y, unsigned short Color) {
	Lcd_WriteIndex(0x2a);
	Lcd_WriteData_16Bit_V(x);
	Lcd_WriteIndex(0x2b);
	Lcd_WriteData_16Bit_V(y);
	Lcd_WriteIndex(0x2c);
	Lcd_WriteData_16Bit_V(Color);
}

/* È«ÆÁÇå³ý */
void Lcd_Clear(unsigned short Color) {
	unsigned long i;

	Lcd_SetRegion(0, LCD_WIDTH, 0, LCD_HIGH);
	Lcd_WriteIndex(0x2c);
	for (i = 0; i < LCD_WIDTH * LCD_HIGH; i += 8) {
		Lcd_WriteData_16Bit_V(Color);
		Lcd_WriteData_16Bit_V(Color);
		Lcd_WriteData_16Bit_V(Color);
		Lcd_WriteData_16Bit_V(Color);
		Lcd_WriteData_16Bit_V(Color);
		Lcd_WriteData_16Bit_V(Color);
		Lcd_WriteData_16Bit_V(Color);
		Lcd_WriteData_16Bit_V(Color);
	}
}

/* ¾ØÐÎÌî³ä */
void Lcd_Fill_Rectangle(unsigned short x, unsigned short y, unsigned short wieth, unsigned short high, unsigned short Color) {
	unsigned long all, i;

	if (wieth == (unsigned short)0 || high == (unsigned short)0)
		return;
	Lcd_SetRegion(x, x + wieth - (unsigned short)1, y, y + high - (unsigned short)1);
	all = (unsigned long)wieth * high;
	Lcd_WriteIndex(0x2c);
	for (i = 0; i < all;) {
		if (all - i >= 8) {
			Lcd_WriteData_16Bit_V(Color);
			Lcd_WriteData_16Bit_V(Color);
			Lcd_WriteData_16Bit_V(Color);
			Lcd_WriteData_16Bit_V(Color);
			Lcd_WriteData_16Bit_V(Color);
			Lcd_WriteData_16Bit_V(Color);
			Lcd_WriteData_16Bit_V(Color);
			Lcd_WriteData_16Bit_V(Color);
			i += 8;
		} else {
			Lcd_WriteData_16Bit_V(Color);
			++i;
		}
	}
}

/* Ó³ÉäÄÚ´æ */
void Lcd_MappRam(unsigned short x, unsigned short y, unsigned short wieth, unsigned short high, unsigned short* vram) {
	unsigned long all, i;

	if (wieth == (unsigned short)0 || high == (unsigned short)0)
		return;
	Lcd_SetRegion(x, x + wieth - (unsigned short)1, y, y + high - (unsigned short)1);
	all = (unsigned long)wieth * high;
	Lcd_WriteIndex(0x2c);
	for (i = 0; i < all;) {
		unsigned short Color;

		if (all - i >= 16) {
			Color = *vram++; Lcd_WriteData_16Bit_V(Color);
			Color = *vram++; Lcd_WriteData_16Bit_V(Color);
			Color = *vram++; Lcd_WriteData_16Bit_V(Color);
			Color = *vram++; Lcd_WriteData_16Bit_V(Color);
			Color = *vram++; Lcd_WriteData_16Bit_V(Color);
			Color = *vram++; Lcd_WriteData_16Bit_V(Color);
			Color = *vram++; Lcd_WriteData_16Bit_V(Color);
			Color = *vram++; Lcd_WriteData_16Bit_V(Color);
			Color = *vram++; Lcd_WriteData_16Bit_V(Color);
			Color = *vram++; Lcd_WriteData_16Bit_V(Color);
			Color = *vram++; Lcd_WriteData_16Bit_V(Color);
			Color = *vram++; Lcd_WriteData_16Bit_V(Color);
			Color = *vram++; Lcd_WriteData_16Bit_V(Color);
			Color = *vram++; Lcd_WriteData_16Bit_V(Color);
			Color = *vram++; Lcd_WriteData_16Bit_V(Color);
			Color = *vram++; Lcd_WriteData_16Bit_V(Color);
			i += 16;
		} else {
			Color = *vram++;
			Lcd_WriteData_16Bit_V(Color);
			++i;
		}
	}
}
