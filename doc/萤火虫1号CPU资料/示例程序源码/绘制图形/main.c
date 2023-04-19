#include "st7789.h"
#include "gl.h"

void main() {

	/* 初始化LCD */
	Lcd_ST7789_Init(0);

	/* 画空心圆 */
	GDI_DrawRound(160, 120, 119, 0xffff);

	/* 画实心圆 */
	GDI_DrawFillRound(160, 120, 50, 0xffff);

	/* 画直线 */
	glib_line(0, 0, 319, 239, 0xffff);

	while (1);
}
