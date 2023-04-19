/**********************************************/
/*
/*			显存		2022.10 龙少
/*
/**********************************************/

#include "DispRam.h"
#include "mouse.h"

/* 显存 */
uint16_t DispRam[LCD_WIDTH][LCD_HIGH];

/* 显存数据更新至LCD */
void DispRam_ToLcd(uint16_t x, uint16_t y, uint16_t width, uint16_t high) {
	uint16_t StartX = x;
	uint16_t EndX;
	uint16_t EndY;

	if (x + width > LCD_WIDTH)
		EndX = LCD_WIDTH;
	else
		EndX = x + width;
	if (y + high > LCD_HIGH)
		EndY = LCD_HIGH;
	else
		EndY = y + high;
	for (; y < EndY; ++y) {
		for (x = StartX; x < EndX; ++x) {
			if (x < GetMouseX || x >= GetMouseX + (uint16_t)MouseImageWidth || y < GetMouseY || y >= GetMouseY + (uint16_t)MouseImageHigh || \
				Image_Mouse[(y - GetMouseY) * (uint16_t)MouseImageWidth + (x - GetMouseX)] == (uint16_t)TrnColor) {
#if 1
				uint16_t Color = DispRam[x][y];
				Lcd_WriteIndex(0x2a);
				Lcd_WriteData_16Bit_V(x);
				Lcd_WriteIndex(0x2b);
				Lcd_WriteData_16Bit_V(y);
				Lcd_WriteIndex(0x2c);
				Lcd_WriteData_16Bit_V(Color);
#else
				Lcd_Draw_Pixel(x, y, DispRam[x][y]);
#endif
			}
		}
	}
}

/* 在显存上绘制矩形填充 */
void DispRam_FillRectangle(uint16_t x, uint16_t y, uint16_t width, uint16_t high, uint16_t color) {
	uint16_t StartX = x;
	uint16_t EndX;
	uint16_t EndY;

	if (x + width > LCD_WIDTH)
		EndX = LCD_WIDTH;
	else
		EndX = x + width;
	if (y + high > LCD_HIGH)
		EndY = LCD_HIGH;
	else
		EndY = y + high;
	for (; y < EndY; ++y)
		for (x = StartX; x < EndX; ++x)
			DispRam[x][y] = color;
}

/* 显存装载位图 */
void DispRam_LoadImage(uint16_t x, uint16_t y, BitImage* image) {
	uint16_t StartX = x;
	uint16_t EndX;
	uint16_t EndY;
	uint16_t SkipX;
	uint16_t* PixelData = image->PixelData;

	if (x + image->Width > LCD_WIDTH) {
		SkipX = x + image->Width - LCD_WIDTH;
		EndX = LCD_WIDTH;
	}
	else {
		SkipX = 0;
		EndX = x + image->Width;
	}
	if (y + image->High > LCD_HIGH)
		EndY = LCD_HIGH;
	else
		EndY = y + image->High;
	for (; y < EndY; ++y) {
		for (x = StartX; x < EndX; ++x)
			DispRam[x][y] = *PixelData++;
		PixelData += SkipX;
	}
}
