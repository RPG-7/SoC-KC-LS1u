#include "st7789.h"
#include "ch375.h"
#include "printf.h"
#include "ff.h"
#include "InfoNES.h"
#include "delay.h"

FATFS SD_FS;

void main() {

	Lcd_ST7789_Init(0);
	CH375_Init();

	Printf_Set(0, 0, 0xffff, 0);
	printf("Up:     W\n");
	printf("Down:   S\n");
	printf("Left:   A\n");
	printf("Right:  D\n");
	printf("B:      O\n");
	printf("A:      P\n");
	printf("SELECT: T\n");
	printf("START:  Y\n");
	Delay(2000000);
	Lcd_Clear(0);

	if (f_mount(&SD_FS, "1:", 1)) {
		printf("f_mount error!");
		while (1);
	}
	if (InfoNES_Load("1:\\³¬¼¶ÂêÀö.nes") == -1) {
		printf("InfoNES_Load error!");
		while (1);
	}
	while (1) {
		InfoNES_Main();
	}
}
