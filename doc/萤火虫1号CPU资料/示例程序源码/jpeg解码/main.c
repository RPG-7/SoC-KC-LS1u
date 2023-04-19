#include "st7789.h"
#include "TJpg_Decoder.h"

/* jpg图片数据 */
#include "image.c"

void main() {

    /* 初始化LCD */
	Lcd_ST7789_Init(0);

    /* 显示JPG图片 */
    drawJpg(0, 0, image);

	while (1);
}
