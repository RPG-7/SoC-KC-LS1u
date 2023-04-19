#include "sd.h"
#include "st7789.h"
#include "printf.h"

unsigned char buf[512];

void main() {

	Lcd_ST7789_Init(0);
	Printf_Set(0, 0, 0xffff, 0);

	/* 初始化sd卡 */
	if (sd_init() == true) {
		printf("sd_init: ok\n");
		printf("sd_size: %d Byte\n", sd_byte_size);

		/* sd读512字节到内存 */
		if (sd_rd_512byte(0, buf) == true) {
			printf("sd_rd_512byte: ok\n");

			/* 内存回写sd */
			if (sd_wr_512byte(0, buf) == true)
				printf("sd_wr_512byte: ok\n");
			else
				printf("sd_wr_512byte: error");
		}
		else
			printf("sd_rd_512byte: error");
	}
	else
		printf("sd_init: error");

	while (1);
}
