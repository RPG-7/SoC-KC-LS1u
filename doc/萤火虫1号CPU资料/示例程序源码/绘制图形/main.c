#include "st7789.h"
#include "gl.h"

void main() {

	/* ��ʼ��LCD */
	Lcd_ST7789_Init(0);

	/* ������Բ */
	GDI_DrawRound(160, 120, 119, 0xffff);

	/* ��ʵ��Բ */
	GDI_DrawFillRound(160, 120, 50, 0xffff);

	/* ��ֱ�� */
	glib_line(0, 0, 319, 239, 0xffff);

	while (1);
}
