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

	/* װ��fatfs�ļ�ϵͳ */
	if (f_mount(&SD_FS, "1:", 1) == FR_OK) {
		printf("f_mount: ok\n");

		/* ��test.txt�ļ� */
		printf("open file \"test.txt\"\n");
		if (f_open(&fp, "1:\\test.txt", FA_READ) == FR_OK) {
			printf("f_open: ok\n");

			/* ���ļ� */
			if (f_read(&fp, buf, 31, &rn) == FR_OK) {
				printf("f_read: ok\n");
				printf("read out %d byte:\n", rn);
				buf[rn] = 0;
				printf(buf);

				/* �ر��ļ� */
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
