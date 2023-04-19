#include "st7789.h"
#include "TJpg_Decoder.h"
#include "printf.h"

/* jpg文件数据 */
#include "jpg/0001.c"
#include "jpg/0002.c"
#include "jpg/0003.c"
#include "jpg/0004.c"
#include "jpg/0005.c"
#include "jpg/0006.c"
#include "jpg/0007.c"
#include "jpg/0008.c"
#include "jpg/0009.c"
#include "jpg/0010.c"
#include "jpg/0011.c"
#include "jpg/0012.c"
#include "jpg/0013.c"
#include "jpg/0014.c"
#include "jpg/0015.c"
#include "jpg/0016.c"
#include "jpg/0017.c"

/* 帧数 */
#define FRAMENUM    17

/* 所有图片的指针 */
unsigned char* allimage[] = {
    image1,
    image2,
    image3,
    image4,
    image5,
    image6,
    image7,
    image8,
    image9,
    image10,
    image11,
    image12,
    image13,
    image14,
    image15,
    image16,
    image17,
};

/* 解码缓冲区 */
unsigned short RGB_DataBuf[240 * 240 * FRAMENUM];

void main() {
    unsigned long i;

	Lcd_ST7789_Init(0);

    for (i = 0; i < FRAMENUM; ++i) {
        Printf_Set(0, 0, 0xffff, 0);
        printf("Decode JPG Data: %.1f%%", (double)(i * 100) / FRAMENUM);
        drawJpg_ToVram(0, 0, allimage[i], &RGB_DataBuf[240 * 240 * i]);
    }
    Lcd_Clear(0);
    for (i = 0;;++i) {
        if (i == FRAMENUM)
            i = 0;
        Lcd_MappRam(40, 0, 240, 240, &RGB_DataBuf[240 * 240 * i]);
    }
}
