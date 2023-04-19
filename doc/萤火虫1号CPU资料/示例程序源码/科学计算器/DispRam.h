/**********************************************/
/*
/*			œ‘¥Ê		2022.10 ¡˙…Ÿ
/*
/**********************************************/

#include "GlowTypedef.h"
#include "st7789.h"

#ifndef __BitImage__

#define __BitImage__

/* RGB565 */
typedef struct {
	uint16_t Width;
	uint16_t High;
	uint16_t* PixelData;
} BitImage;

#endif

extern uint16_t DispRam[LCD_WIDTH][LCD_HIGH];

extern void DispRam_ToLcd(uint16_t x, uint16_t y, uint16_t wieth, uint16_t high);
extern void DispRam_FillRectangle(uint16_t x, uint16_t y, uint16_t wieth, uint16_t high, uint16_t color);
extern void DispRam_LoadImage(uint16_t x, uint16_t y, BitImage* image);
