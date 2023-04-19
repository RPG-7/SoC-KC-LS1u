#include "st7789.h"
#include "sd.h"
#include "ff.h"
#include "printf.h"

FATFS SD_FS;
FIL fp;
char buf[32];
UINT rn;

void main() {

	Lcd_ST7789_Init(0);
	Printf_Set(0, 0, 0xffff, 0);

	/* 装载fatfs文件系统 */
	if (f_mount(&SD_FS, "1:", 1) == FR_OK) {
		printf("f_mount: ok\n");

		/* 打开test.txt文件 */
		printf("open file \"test.txt\"\n");
		if (f_open(&fp, "1:\\test.txt", FA_READ) == FR_OK) {
			printf("f_open: ok\n");

			/* 读文件 */
			if (f_read(&fp, buf, 31, &rn) == FR_OK) {
				printf("f_read: ok\n");
				printf("read out %d byte:\n", rn);
				buf[rn] = 0;
				printf(buf);

				/* 关闭文件 */
				f_close(&fp);
			}
			else
				printf("f_read: error");
		}
		else
			printf("f_open: error");
	}
	else
		printf("f_mount: error");

	while (1);
}
