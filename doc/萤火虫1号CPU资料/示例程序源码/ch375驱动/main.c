#include "cpuio.h"
#include "st7789.h"
#include "printf.h"
#include "ch375.h"
#include "delay.h"

void main() {

	Lcd_ST7789_Init(0x1018);
	CH375_Init();

	goto label;
	while (1) {
		if (UsbUpdate() == (unsigned char)1) {
			static unsigned short Mouse_X_, Mouse_Y_;

			if (Mouse_X_ != Mouse_X || Mouse_Y_ != Mouse_Y) {
				Printf_Set(Mouse_X_, Mouse_Y_, 0xffff, 0x1018);
				printf(" ");
				label:
				Printf_Set(Mouse_X, Mouse_Y, 0xffff, 0x1018);
				printf("");
				Mouse_X_ = Mouse_X;
				Mouse_Y_ = Mouse_Y;
			}
			Printf_Set(0, 0, 0xffff, 0);
			printf("KeyValue: %02x %02x %02x %02x %02x %02x %02x\n", (int)Key_Value[0], (int)Key_Value[1], (int)Key_Value[2], (int)Key_Value[3], (int)Key_Value[4], (int)Key_Value[5], (int)Key_Value[6]);
			printf("MouseValue: %02x %04x %04x %04x\n", (int)Mouse_Button, (int)Mouse_X, (int)Mouse_Y, (int)Mouse_Wheel);
		}
	}
}
