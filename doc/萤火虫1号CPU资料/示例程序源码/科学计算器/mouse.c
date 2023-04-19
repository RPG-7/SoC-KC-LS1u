/**********************************************/
/*
/*			鼠标		2022.10 龙少
/*
/**********************************************/

#include "mouse.h"
#include "st7789.h"

/* 鼠标图像数据 */
const uint16_t Image_Mouse[MouseImageWidth * MouseImageHigh] = {
0XFFFF,   TrnColor, TrnColor, TrnColor, TrnColor, TrnColor, TrnColor, TrnColor, TrnColor, TrnColor, TrnColor, TrnColor,
0XFFFF,   0XFFFF,	TrnColor, TrnColor, TrnColor, TrnColor, TrnColor, TrnColor, TrnColor, TrnColor, TrnColor, TrnColor,
0XFFFF,   0X0000,   0XFFFF,   TrnColor, TrnColor, TrnColor, TrnColor, TrnColor, TrnColor, TrnColor, TrnColor, TrnColor,
0XFFFF,   0X0000,   0X0000,   0XFFFF,   TrnColor, TrnColor, TrnColor, TrnColor, TrnColor, TrnColor, TrnColor, TrnColor,
0XFFFF,   0X0000,   0X0000,   0X0000,   0XFFFF,   TrnColor, TrnColor, TrnColor, TrnColor, TrnColor, TrnColor, TrnColor,
0XFFFF,   0X0000,   0X0000,   0X0000,   0X0000,   0XFFFF,   TrnColor, TrnColor, TrnColor, TrnColor, TrnColor, TrnColor,
0XFFFF,   0X0000,   0X0000,   0X0000,   0X0000,   0X0000,   0XFFFF,   TrnColor, TrnColor, TrnColor, TrnColor, TrnColor,
0XFFFF,   0X0000,   0X0000,   0X0000,   0X0000,   0X0000,   0X0000,   0XFFFF,   TrnColor, TrnColor, TrnColor, TrnColor,
0XFFFF,   0X0000,   0X0000,   0X0000,   0X0000,   0X0000,   0X0000,   0X0000,   0XFFFF,   TrnColor, TrnColor, TrnColor,
0XFFFF,   0X0000,   0X0000,   0X0000,   0X0000,   0X0000,   0X0000,   0X0000,   0X0000,   0XFFFF,   TrnColor, TrnColor,
0XFFFF,   0X0000,   0X0000,   0X0000,   0X0000,   0X0000,   0X0000,   0X0000,   0X0000,   0X0000,   0XFFFF,   TrnColor,
0XFFFF,   0X0000,   0X0000,   0X0000,   0X0000,   0X0000,   0X0000,   0X0000,   0X0000,   0X0000,   0X0000,   0XFFFF,
0XFFFF,   0X0000,   0X0000,   0X0000,   0X0000,   0X0000,   0X0000,   0XFFFF,   0XFFFF,   0XFFFF,   0XFFFF,   0XFFFF,
0XFFFF,   0X0000,   0X0000,   0X0000,   0XFFFF,   0X0000,   0X0000,   0XFFFF,   TrnColor, TrnColor, TrnColor, TrnColor,
0XFFFF,   0X0000,   0X0000,   0XFFFF,   TrnColor, 0XFFFF,   0X0000,   0X0000,   0XFFFF,   TrnColor, TrnColor, TrnColor,
0XFFFF,   0X0000,   0XFFFF,   TrnColor, TrnColor, 0XFFFF,   0X0000,   0X0000,   0XFFFF,   TrnColor, TrnColor, TrnColor,
0XFFFF,   0XFFFF,   TrnColor, TrnColor, TrnColor, TrnColor, 0XFFFF,   0X0000,   0X0000,   0XFFFF,   TrnColor, TrnColor,
TrnColor, TrnColor, TrnColor, TrnColor, TrnColor, TrnColor, 0XFFFF,   0X0000,   0X0000,   0XFFFF,   TrnColor, TrnColor,
TrnColor, TrnColor, TrnColor, TrnColor, TrnColor, TrnColor, TrnColor, 0XFFFF,   0XFFFF,   TrnColor, TrnColor, TrnColor,
};

BitImage MouseImage = { MouseImageWidth, MouseImageHigh, (uint16_t*)Image_Mouse };

/* 绘制顶层位图至LCD */
void DrawTopImage_ToLcd(uint16_t x, uint16_t y, BitImage* image, uint16_t ElideColor) {
	uint16_t StartX = x;
	uint16_t EndX;
	uint16_t EndY;
	uint16_t SkipX;
	uint16_t* PixelData;

	if (x + image->Width > LCD_WIDTH) {
		SkipX = x + image->Width - LCD_WIDTH;
		EndX = LCD_WIDTH;
	} else {
		SkipX = 0;
		EndX = x + image->Width;
	}
	if (y + image->High > LCD_HIGH)
		EndY = LCD_HIGH;
	else
		EndY = y + image->High;
	PixelData = image->PixelData;
	for (; y < EndY; ++y) {
		for (x = StartX; x < EndX; ++x) {
			uint16_t Color;

			Color = *PixelData++;
			if (Color != ElideColor)
				Lcd_Draw_Pixel(x, y, Color);
		}
		PixelData += SkipX;
	}
}

/* 移动鼠标 */
void MovMouse(uint16_t x, uint16_t y) {
	static uint16_t BackX = 0;
	static uint16_t BackY = 0;

	if (x != BackX || y != BackY) {
		DrawTopImage_ToLcd(GetMouseX, GetMouseY, &MouseImage, TrnColor);
		DispRam_ToLcd(BackX, BackY, MouseImageWidth, MouseImageHigh);
		BackX = x;
		BackY = y;
	}
}
