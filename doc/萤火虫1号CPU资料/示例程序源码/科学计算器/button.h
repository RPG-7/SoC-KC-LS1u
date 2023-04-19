/**********************************************/
/*
/*			按钮		2022.11 龙少
/*
/**********************************************/

#include "GlowTypedef.h"
#include "DispRam.h"
#include "stdbool.h"

#ifndef __BUTTON__

#define __BUTTON__

typedef struct button BUTTON;

/* 按钮对象定义 */
typedef struct button {
	uint16_t Left;			//X起始坐标
	uint16_t Right;			//X结束坐标
	uint16_t Top;			//Y起始坐标
	uint16_t Bottom;		//Y结束坐标
	BitImage* Image0;		//图片帧0
	BitImage* Image1;		//图片帧1
	BitImage* Image2;		//图片帧2
	uint16_t TextColor;		//按钮文本颜色
	char* TextStr;			//按钮文本字符串
	uint8_t KeyStep;		//按键步骤,0:按键未复位,1:按键已复位,2:按键按下
	bool Focus;				//false:按钮没有聚焦(鼠标在按钮范围外),true:按钮聚焦(鼠标在按钮范围内)
	bool State;				//按钮状态,true:按下,false:弹起
	void (*ClickCall)();	//按钮点击事件的回调函数
};

#endif

extern void DrawButton(BUTTON* p, uint8_t ToLcd);
extern void UpdateButton(BUTTON* p);
extern bool GetButtonState(BUTTON* p);
extern void SetButtonText(BUTTON* p, char* str);
