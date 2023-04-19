#include "st7789.h"

void main() {
	int i;
	double x, y;

	/* 初始化LCD */
	Lcd_ST7789_Init(0);

	/* 画彩条 */
	Lcd_Fill_Rectangle(0, 0, 40, 240, 0xffff);
	Lcd_Fill_Rectangle(40, 0, 40, 240, 0xffe0);
	Lcd_Fill_Rectangle(80, 0, 40, 240, 0x07ff);
	Lcd_Fill_Rectangle(120, 0, 40, 240, 0x07e0);
	Lcd_Fill_Rectangle(160, 0, 40, 240, 0xf81f);
	Lcd_Fill_Rectangle(200, 0, 40, 240, 0xf800);
	Lcd_Fill_Rectangle(240, 0, 40, 240, 0x001f);
	Lcd_Fill_Rectangle(280, 0, 40, 240, 0x0000);

	/* 画一个圆 */
	x = 108.9;
	y = 0.0;
	for (i = 0; i < 3600; ++i) {
		x -= y * 0.00174533;
		y += x * 0.00174533;
		Lcd_Draw_Pixel(160.0 + x, 120.0 - y, 0xffff);
	}

	/* 映射内存 */
	while (1) {
		static unsigned short* p = 0;
		Lcd_MappRam(80, 75, 160, 90, p++);
	}
}
