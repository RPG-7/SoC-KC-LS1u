#include "st7789.h"
#include "printf.h"

void main() {

	/* 初始化LCD */
	Lcd_ST7789_Init(0x1018);

	/* 设置printf坐标及颜色参数 */
	Printf_Set(0, 0, 0xffff, 0x1018);

	/* 打印字符 */
	printf("你好!!!\n");
	printf("我是龙少,多谢支持^-^!\n");
	printf("时间: 2022.10.27");

	while (1);
}
