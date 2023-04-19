/**********************************************/
/*
/*			���		2022.10 ����
/*
/**********************************************/

#include "GlowTypedef.h"
#include "ch375.h"
#include "DispRam.h"

/* ��ȡ���X����ֵ */
#define GetMouseX Mouse_X

/* ��ȡ���Y����ֵ */
#define GetMouseY Mouse_Y

/* ��ȡ��갴ť��� */
#define GetMouseButtonL	(Mouse_Button & (uint8_t)0x1)

/* ��ȡ��갴ť�м� */
#define GetMouseButtonM	(Mouse_Button & (uint8_t)0x4)

/* ��ȡ��갴ť�Ҽ� */
#define GetMouseButtonR	(Mouse_Button & (uint8_t)0x2)

/* ��ȡ������а��� */
#define GetMouseButtonAll Mouse_Button

/* ͸����ɫֵ */
#define TrnColor 0x0001

/* ���ͼ�����ݿ�� */
#define MouseImageWidth 12
#define MouseImageHigh	19

extern const uint16_t Image_Mouse[];

extern void DrawTopImage_ToLcd(uint16_t x, uint16_t y, BitImage* image, uint16_t ElideColor);
extern void MovMouse(uint16_t x, uint16_t y);
