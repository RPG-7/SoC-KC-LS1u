#include "st7789.h"
#include "TJpg_Decoder.h"

/* jpgͼƬ���� */
#include "image.c"

void main() {

    /* ��ʼ��LCD */
	Lcd_ST7789_Init(0);

    /* ��ʾJPGͼƬ */
    drawJpg(0, 0, image);

	while (1);
}
