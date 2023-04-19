#include "st7789.h"
#include "printf.h"

void main() {

	/* 初始化LCD */
	Lcd_ST7789_Init(0);

	/* 设置printf坐标及颜色参数 */
	Printf_Set(0, 0, 0xffff, 0xf800);

	/* 打印字符 */
	printf("0x%016llX\n", 0xfedcba9876543210);

	/* 改变背景颜色 */
	Printf_BG_Color(0x06e0);

	/* 打印字符 */
	printf("%.18f\n", 3.141592653589793238);

	/* 改变背景颜色 */
	Printf_BG_Color(0x001f);

	/* 打印字符 */
	printf("%lld\n", -9223372036854775807);

	while (1);
}
