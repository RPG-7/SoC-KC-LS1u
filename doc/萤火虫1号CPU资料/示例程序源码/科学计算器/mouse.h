/**********************************************/
/*
/*			鼠标		2022.10 龙少
/*
/**********************************************/

#include "GlowTypedef.h"
#include "ch375.h"
#include "DispRam.h"

/* 获取鼠标X坐标值 */
#define GetMouseX Mouse_X

/* 获取鼠标Y坐标值 */
#define GetMouseY Mouse_Y

/* 获取鼠标按钮左键 */
#define GetMouseButtonL	(Mouse_Button & (uint8_t)0x1)

/* 获取鼠标按钮中键 */
#define GetMouseButtonM	(Mouse_Button & (uint8_t)0x4)

/* 获取鼠标按钮右键 */
#define GetMouseButtonR	(Mouse_Button & (uint8_t)0x2)

/* 获取鼠标所有按键 */
#define GetMouseButtonAll Mouse_Button

/* 透明颜色值 */
#define TrnColor 0x0001

/* 鼠标图像数据宽高 */
#define MouseImageWidth 12
#define MouseImageHigh	19

extern const uint16_t Image_Mouse[];

extern void DrawTopImage_ToLcd(uint16_t x, uint16_t y, BitImage* image, uint16_t ElideColor);
extern void MovMouse(uint16_t x, uint16_t y);
