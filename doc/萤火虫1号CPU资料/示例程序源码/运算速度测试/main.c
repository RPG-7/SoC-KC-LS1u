#include "st7789.h"
#include "printf.h"
#include "ds1302.h"

void main() {
	unsigned char i;

	/* ≥ı ºªØLCD */
	Lcd_ST7789_Init(0);

	/* unsigned char add */
	for (i = 0; i < 3;) {
		unsigned long OpCount;
		unsigned char LastSec;
		unsigned short opx;
		unsigned char a, b, c;
		
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;

		opx += (unsigned short)384;
		if (opx >= (unsigned short)(384 * 100)) {
			OpCount += opx;
			opx = 0;
			if (LastSec != DS1302_RD_REG(DS1302_SEC)) {
				LastSec = DS1302_RD_REG(DS1302_SEC);
				Printf_Set(0, 0, 61123, 0);
				printf("unsigned char add: %d/S        ", OpCount);
				OpCount = 0;
				++i;
			}
		}
	}

	/* unsigned char sub */
	for (i = 0; i < 3;) {
		unsigned long OpCount;
		unsigned char LastSec;
		unsigned short opx;
		unsigned char a, b, c;

		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		
		opx += (unsigned short)384;
		if (opx >= (unsigned short)(384 * 100)) {
			OpCount += opx;
			opx = 0;
			if (LastSec != DS1302_RD_REG(DS1302_SEC)) {
				LastSec = DS1302_RD_REG(DS1302_SEC);
				Printf_Set(0, 12, 61123, 0);
				printf("unsigned char sub: %d/S        ", OpCount);
				OpCount = 0;
				++i;
			}
		}
	}

	/* unsigned char mul */
	for (i = 0; i < 3;) {
		unsigned long OpCount;
		unsigned char LastSec;
		unsigned short opx;
		unsigned char a, b, c;

		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;

		opx += (unsigned short)384;
		if (opx >= (unsigned short)(384 * 100)) {
			OpCount += opx;
			opx = 0;
			if (LastSec != DS1302_RD_REG(DS1302_SEC)) {
				LastSec = DS1302_RD_REG(DS1302_SEC);
				Printf_Set(0, 24, 61123, 0);
				printf("unsigned char mul: %d/S        ", OpCount);
				OpCount = 0;
				++i;
			}
		}
	}

	/* unsigned char div */
	for (i = 0; i < 3;) {
		unsigned long OpCount;
		unsigned char LastSec;
		unsigned short opx;
		unsigned char a, b, c;

		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;

		opx += (unsigned short)384;
		if (opx >= (unsigned short)(384 * 100)) {
			OpCount += opx;
			opx = 0;
			if (LastSec != DS1302_RD_REG(DS1302_SEC)) {
				LastSec = DS1302_RD_REG(DS1302_SEC);
				Printf_Set(0, 36, 61123, 0);
				printf("unsigned char div: %d/S        ", OpCount);
				OpCount = 0;
				++i;
			}
		}
	}

	/* unsigned short add */
	for (i = 0; i < 3;) {
		unsigned long OpCount;
		unsigned char LastSec;
		unsigned short opx;
		unsigned short a, b, c;

		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;

		opx += (unsigned short)384;
		if (opx >= (unsigned short)(384 * 50)) {
			OpCount += opx;
			opx = 0;
			if (LastSec != DS1302_RD_REG(DS1302_SEC)) {
				LastSec = DS1302_RD_REG(DS1302_SEC);
				Printf_Set(0, 48, 4893, 0);
				printf("unsigned short add: %d/S        ", OpCount);
				OpCount = 0;
				++i;
			}
		}
	}

	/* unsigned short sub */
	for (i = 0; i < 3;) {
		unsigned long OpCount;
		unsigned char LastSec;
		unsigned short opx;
		unsigned short a, b, c;

		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;

		opx += (unsigned short)384;
		if (opx >= (unsigned short)(384 * 50)) {
			OpCount += opx;
			opx = 0;
			if (LastSec != DS1302_RD_REG(DS1302_SEC)) {
				LastSec = DS1302_RD_REG(DS1302_SEC);
				Printf_Set(0, 60, 4893, 0);
				printf("unsigned short sub: %d/S        ", OpCount);
				OpCount = 0;
				++i;
			}
		}
	}

	/* unsigned short mul */
	for (i = 0; i < 3;) {
		unsigned long OpCount;
		unsigned char LastSec;
		unsigned short opx;
		unsigned short a, b, c;

		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;

		opx += (unsigned short)384;
		if (opx >= (unsigned short)(384 * 50)) {
			OpCount += opx;
			opx = 0;
			if (LastSec != DS1302_RD_REG(DS1302_SEC)) {
				LastSec = DS1302_RD_REG(DS1302_SEC);
				Printf_Set(0, 72, 4893, 0);
				printf("unsigned short mul: %d/S        ", OpCount);
				OpCount = 0;
				++i;
			}
		}
	}

	/* unsigned short div */
	for (i = 0; i < 3;) {
		unsigned long OpCount;
		unsigned char LastSec;
		unsigned short opx;
		unsigned short a, b, c;

		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;

		opx += (unsigned short)384;
		if (opx >= (unsigned short)(384 * 1)) {
			OpCount += opx;
			opx = 0;
			if (LastSec != DS1302_RD_REG(DS1302_SEC)) {
				LastSec = DS1302_RD_REG(DS1302_SEC);
				Printf_Set(0, 84, 4893, 0);
				printf("unsigned short div: %d/S        ", OpCount);
				OpCount = 0;
				++i;
			}
		}
	}

	/* unsigned long add */
	for (i = 0; i < 3;) {
		unsigned long OpCount;
		unsigned char LastSec;
		unsigned short opx;
		unsigned long a, b, c;

		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;

		opx += (unsigned short)384;
		if (opx >= (unsigned short)(384 * 20)) {
			OpCount += opx;
			opx = 0;
			if (LastSec != DS1302_RD_REG(DS1302_SEC)) {
				LastSec = DS1302_RD_REG(DS1302_SEC);
				Printf_Set(0, 96, 13589, 0);
				printf("unsigned long add: %d/S        ", OpCount);
				OpCount = 0;
				++i;
			}
		}
	}

	/* unsigned long sub */
	for (i = 0; i < 3;) {
		unsigned long OpCount;
		unsigned char LastSec;
		unsigned short opx;
		unsigned long a, b, c;

		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;

		opx += (unsigned short)384;
		if (opx >= (unsigned short)(384 * 20)) {
			OpCount += opx;
			opx = 0;
			if (LastSec != DS1302_RD_REG(DS1302_SEC)) {
				LastSec = DS1302_RD_REG(DS1302_SEC);
				Printf_Set(0, 108, 13589, 0);
				printf("unsigned long sub: %d/S        ", OpCount);
				OpCount = 0;
				++i;
			}
		}
	}

	/* unsigned long mul */
	for (i = 0; i < 3;) {
		unsigned long OpCount;
		unsigned char LastSec;
		unsigned short opx;
		unsigned long a, b, c;

		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;

		opx += (unsigned short)384;
		if (opx >= (unsigned short)(384 * 20)) {
			OpCount += opx;
			opx = 0;
			if (LastSec != DS1302_RD_REG(DS1302_SEC)) {
				LastSec = DS1302_RD_REG(DS1302_SEC);
				Printf_Set(0, 120, 13589, 0);
				printf("unsigned long mul: %d/S        ", OpCount);
				OpCount = 0;
				++i;
			}
		}
	}

	/* unsigned long div */
	for (i = 0; i < 3;) {
		unsigned long OpCount;
		unsigned char LastSec;
		unsigned short opx;
		unsigned long a, b, c;

		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;
		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;

		opx += (unsigned short)384;
		if (opx >= (unsigned short)(384 * 1)) {
			OpCount += opx;
			opx = 0;
			if (LastSec != DS1302_RD_REG(DS1302_SEC)) {
				LastSec = DS1302_RD_REG(DS1302_SEC);
				Printf_Set(0, 132, 13589, 0);
				printf("unsigned long div: %d/S        ", OpCount);
				OpCount = 0;
				++i;
			}
		}
	}

	/* unsigned long long add */
	for (i = 0; i < 3;) {
		unsigned long OpCount;
		unsigned char LastSec;
		unsigned short opx;
		unsigned long long a, b, c;

		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;
		a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b; a = b + c; b = c + a; c = a + b;

		opx += (unsigned short)384;
		if (opx >= (unsigned short)(384 * 20)) {
			OpCount += opx;
			opx = 0;
			if (LastSec != DS1302_RD_REG(DS1302_SEC)) {
				LastSec = DS1302_RD_REG(DS1302_SEC);
				Printf_Set(0, 144, 29589, 0);
				printf("unsigned long long add: %d/S        ", OpCount);
				OpCount = 0;
				++i;
			}
		}
	}

	/* unsigned long long sub */
	for (i = 0; i < 3;) {
		unsigned long OpCount;
		unsigned char LastSec;
		unsigned short opx;
		unsigned long long a, b, c;

		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;
		a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b; a = b - c; b = c - a; c = a - b;

		opx += (unsigned short)384;
		if (opx >= (unsigned short)(384 * 20)) {
			OpCount += opx;
			opx = 0;
			if (LastSec != DS1302_RD_REG(DS1302_SEC)) {
				LastSec = DS1302_RD_REG(DS1302_SEC);
				Printf_Set(0, 156, 29589, 0);
				printf("unsigned long long sub: %d/S        ", OpCount);
				OpCount = 0;
				++i;
			}
		}
	}

	/* unsigned long long mul */
	for (i = 0; i < 3;) {
		unsigned long OpCount;
		unsigned char LastSec;
		unsigned short opx;
		unsigned long long a, b, c;

		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;
		a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b; a = b * c; b = c * a; c = a * b;

		opx += (unsigned short)384;
		if (opx >= (unsigned short)(384 * 20)) {
			OpCount += opx;
			opx = 0;
			if (LastSec != DS1302_RD_REG(DS1302_SEC)) {
				LastSec = DS1302_RD_REG(DS1302_SEC);
				Printf_Set(0, 168, 29589, 0);
				printf("unsigned long long mul: %d/S        ", OpCount);
				OpCount = 0;
				++i;
			}
		}
	}

	/* unsigned long long div */
	for (i = 0; i < 3;) {
		unsigned long OpCount;
		unsigned char LastSec;
		unsigned short opx;
		unsigned long long a, b, c;

		a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b; a = b / c; b = c / a; c = a / b;

		opx += (unsigned short)12;
		if (opx >= (unsigned short)(12 * 1)) {
			OpCount += opx;
			opx = 0;
			if (LastSec != DS1302_RD_REG(DS1302_SEC)) {
				LastSec = DS1302_RD_REG(DS1302_SEC);
				Printf_Set(0, 180, 29589, 0);
				printf("unsigned long long div: %d/S        ", OpCount);
				OpCount = 0;
				++i;
			}
		}
	}

	/* float add */
	for (i = 0; i < 3;) {
		unsigned long OpCount;
		unsigned char LastSec;
		unsigned short opx;
		float a, b, c;

		b = 3.1415926, c = 2.7182818;
		a = b + c; b = c + a; c = a + b;
		b = 3.1415926, c = 2.7182818;
		a = b + c; b = c + a; c = a + b;
		b = 3.1415926, c = 2.7182818;
		a = b + c; b = c + a; c = a + b;
		b = 3.1415926, c = 2.7182818;
		a = b + c; b = c + a; c = a + b;

		opx += (unsigned short)12;
		if (opx >= (unsigned short)(12 * 50)) {
			OpCount += opx;
			opx = 0;
			if (LastSec != DS1302_RD_REG(DS1302_SEC)) {
				LastSec = DS1302_RD_REG(DS1302_SEC);
				Printf_Set(0, 192, 45896, 0);
				printf("float add: %d FLOPS        ", OpCount);
				OpCount = 0;
				++i;
			}
		}
	}

	/* float sub */
	for (i = 0; i < 3;) {
		unsigned long OpCount;
		unsigned char LastSec;
		unsigned short opx;
		float a, b, c;

		b = 3.1415926, c = 2.7182818;
		a = b - c; b = c - a; c = a - b;
		b = 3.1415926, c = 2.7182818;
		a = b - c; b = c - a; c = a - b;
		b = 3.1415926, c = 2.7182818;
		a = b - c; b = c - a; c = a - b;
		b = 3.1415926, c = 2.7182818;
		a = b - c; b = c - a; c = a - b;

		opx += (unsigned short)12;
		if (opx >= (unsigned short)(12 * 50)) {
			OpCount += opx;
			opx = 0;
			if (LastSec != DS1302_RD_REG(DS1302_SEC)) {
				LastSec = DS1302_RD_REG(DS1302_SEC);
				Printf_Set(0, 204, 45896, 0);
				printf("float sub: %d FLOPS        ", OpCount);
				OpCount = 0;
				++i;
			}
		}
	}

	/* float mul */
	for (i = 0; i < 3;) {
		unsigned long OpCount;
		unsigned char LastSec;
		unsigned short opx;
		float a, b, c;

		b = 3.1415926, c = 2.7182818;
		a = b * c; b = c * a; c = a * b;
		b = 3.1415926, c = 2.7182818;
		a = b * c; b = c * a; c = a * b;
		b = 3.1415926, c = 2.7182818;
		a = b * c; b = c * a; c = a * b;
		b = 3.1415926, c = 2.7182818;
		a = b * c; b = c * a; c = a * b;

		opx += (unsigned short)12;
		if (opx >= (unsigned short)(12 * 50)) {
			OpCount += opx;
			opx = 0;
			if (LastSec != DS1302_RD_REG(DS1302_SEC)) {
				LastSec = DS1302_RD_REG(DS1302_SEC);
				Printf_Set(0, 216, 45896, 0);
				printf("float mul: %d FLOPS        ", OpCount);
				OpCount = 0;
				++i;
			}
		}
	}

	/* float div */
	for (i = 0; i < 3;) {
		unsigned long OpCount;
		unsigned char LastSec;
		unsigned short opx;
		float a, b, c;

		b = 3.1415926, c = 2.7182818;
		a = b / c; b = c / a; c = a / b;
		b = 3.1415926, c = 2.7182818;
		a = b / c; b = c / a; c = a / b;
		b = 3.1415926, c = 2.7182818;
		a = b / c; b = c / a; c = a / b;
		b = 3.1415926, c = 2.7182818;
		a = b / c; b = c / a; c = a / b;

		opx += (unsigned short)12;
		if (opx >= (unsigned short)(12 * 10)) {
			OpCount += opx;
			opx = 0;
			if (LastSec != DS1302_RD_REG(DS1302_SEC)) {
				LastSec = DS1302_RD_REG(DS1302_SEC);
				Printf_Set(0, 228, 45896, 0);
				printf("float div: %d FLOPS        ", OpCount);
				OpCount = 0;
				++i;
			}
		}
	}

	/* double add */
	for (i = 0; i < 3;) {
		unsigned long OpCount;
		unsigned char LastSec;
		unsigned short opx;
		double a, b, c;

		b = 3.1415926, c = 2.7182818;
		a = b + c; b = c + a; c = a + b;
		b = 3.1415926, c = 2.7182818;
		a = b + c; b = c + a; c = a + b;
		b = 3.1415926, c = 2.7182818;
		a = b + c; b = c + a; c = a + b;
		b = 3.1415926, c = 2.7182818;
		a = b + c; b = c + a; c = a + b;

		opx += (unsigned short)12;
		if (opx >= (unsigned short)(12 * 50)) {
			OpCount += opx;
			opx = 0;
			if (LastSec != DS1302_RD_REG(DS1302_SEC)) {
				LastSec = DS1302_RD_REG(DS1302_SEC);
				Printf_Set(160, 192, 54196, 0);
				printf("double add: %d FLOPS        ", OpCount);
				OpCount = 0;
				++i;
			}
		}
	}

	/* double sub */
	for (i = 0; i < 3;) {
		unsigned long OpCount;
		unsigned char LastSec;
		unsigned short opx;
		double a, b, c;

		b = 3.1415926, c = 2.7182818;
		a = b - c; b = c - a; c = a - b;
		b = 3.1415926, c = 2.7182818;
		a = b - c; b = c - a; c = a - b;
		b = 3.1415926, c = 2.7182818;
		a = b - c; b = c - a; c = a - b;
		b = 3.1415926, c = 2.7182818;
		a = b - c; b = c - a; c = a - b;

		opx += (unsigned short)12;
		if (opx >= (unsigned short)(12 * 50)) {
			OpCount += opx;
			opx = 0;
			if (LastSec != DS1302_RD_REG(DS1302_SEC)) {
				LastSec = DS1302_RD_REG(DS1302_SEC);
				Printf_Set(160, 204, 54196, 0);
				printf("double sub: %d FLOPS        ", OpCount);
				OpCount = 0;
				++i;
			}
		}
	}

	/* double mul */
	for (i = 0; i < 3;) {
		unsigned long OpCount;
		unsigned char LastSec;
		unsigned short opx;
		double a, b, c;

		b = 3.1415926, c = 2.7182818;
		a = b * c; b = c * a; c = a * b;
		b = 3.1415926, c = 2.7182818;
		a = b * c; b = c * a; c = a * b;
		b = 3.1415926, c = 2.7182818;
		a = b * c; b = c * a; c = a * b;
		b = 3.1415926, c = 2.7182818;
		a = b * c; b = c * a; c = a * b;

		opx += (unsigned short)12;
		if (opx >= (unsigned short)(12 * 50)) {
			OpCount += opx;
			opx = 0;
			if (LastSec != DS1302_RD_REG(DS1302_SEC)) {
				LastSec = DS1302_RD_REG(DS1302_SEC);
				Printf_Set(160, 216, 54196, 0);
				printf("double mul: %d FLOPS        ", OpCount);
				OpCount = 0;
				++i;
			}
		}
	}

	/* double div */
	for (i = 0; i < 3;) {
		unsigned long OpCount;
		unsigned char LastSec;
		unsigned short opx;
		double a, b, c;

		b = 3.1415926, c = 2.7182818;
		a = b / c; b = c / a; c = a / b;
		b = 3.1415926, c = 2.7182818;
		a = b / c; b = c / a; c = a / b;
		b = 3.1415926, c = 2.7182818;
		a = b / c; b = c / a; c = a / b;
		b = 3.1415926, c = 2.7182818;
		a = b / c; b = c / a; c = a / b;

		opx += (unsigned short)12;
		if (opx >= (unsigned short)(12 * 10)) {
			OpCount += opx;
			opx = 0;
			if (LastSec != DS1302_RD_REG(DS1302_SEC)) {
				LastSec = DS1302_RD_REG(DS1302_SEC);
				Printf_Set(160, 228, 54196, 0);
				printf("double div: %d FLOPS        ", OpCount);
				OpCount = 0;
				++i;
			}
		}
	}

	while (1);
}
