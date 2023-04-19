#include "st7789.h"

void main() {
	int i;
	double x, y;

	Lcd_ST7789_Init(0);

	x = 108.9;
	y = 0.0;
	for (i = 0; i < 3600; ++i) {
		x -= y * 0.00174533;
		y += x * 0.00174533;
		Lcd_Draw_Pixel(160.0 + x, 120.0 - y, 0xffff);
	}
	while (1);
}
