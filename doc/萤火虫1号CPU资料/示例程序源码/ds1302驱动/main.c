#include "st7789.h"
#include "printf.h"
#include "ds1302.h"

void main() {

	/* 初始化LCD */
	Lcd_ST7789_Init(0);

	/* 设置年月日时分秒 */
	//DS1302_RTC_UP(0x22, 0x10, 0x06, 0x17, 0x30, 0x00);

	/* 显示时分秒 */
	while (1) {
		Printf_Set(0, 0, 0xffff, 0xf800);
		printf("%02x:%02x:%02x", (int)DS1302_RD_REG(2), (int)DS1302_RD_REG(1), (int)DS1302_RD_REG(0));
	}
}
