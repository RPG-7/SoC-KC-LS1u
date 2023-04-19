#include "sd.h"
#include "st7789.h"
#include "printf.h"

unsigned char buf[512];

void main() {

	Lcd_ST7789_Init(0);
	Printf_Set(0, 0, 0xffff, 0);

	/* ��ʼ��sd�� */
	if (sd_init() == true) {
		printf("sd_init: ok\n");
		printf("sd_size: %d Byte\n", sd_byte_size);

		/* sd��512�ֽڵ��ڴ� */
		if (sd_rd_512byte(0, buf) == true) {
			printf("sd_rd_512byte: ok\n");

			/* �ڴ��дsd */
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
