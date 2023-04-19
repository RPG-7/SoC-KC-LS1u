/**********************************************/
/*
/*		科学计算器GUI界面		2022.11 龙少
/*
/**********************************************/

#include "cpuio.h"
#include "st7789.h"
#include "printf.h"
#include "ch375.h"
#include "PrintChar.h"
#include "calc.h"
#include "DispRam.h"
#include "mouse.h"
#include "button.h"
#include "stdbool.h"
#include "string.h"
#include "GlowTypedef.h"
#include "stdlib.h"

#include "Image/ButtonImage00.c"
#include "Image/ButtonImage01.c"
#include "Image/ButtonImage02.c"
#include "Image/BottomImage.c"

#define DispWidth		320		//显示区域宽度
#define DispHigh		240		//显示区域高度
#define ButtonWidth		60		//按钮宽度
#define ButtonHigh		30		//按钮高度
#define ButtonNumX		5		//按钮X数量
#define ButtonNumY		6		//按钮Y数量

BUTTON AllButton[ButtonNumX * ButtonNumY];

char* ButtonName[ButtonNumX * ButtonNumY] = {
	"sqrt",	"pow",	"pi",	"e",	"Del",
	"ln",	"+",	"(",	")",	"C",
	"log",	"-",	"7",	"8",	"9",
	"sin",	"*",	"4",	"5",	"6",
	"cos",	"/",	"1",	"2",	"3",
	"tan",	"DEG",	".",	"0",	"=",
};

uint16_t TextColor[ButtonNumX * ButtonNumY] = {
	0xdd8f,	0xdd8f,	0x877a,	0x877a,	0xe71c,
	0xddaf,	0xe99a,	0xe71c,	0xe71c,	0xe71c,
	0xddaf,	0xe99a,	0x877a,	0x877a,	0x877a,
	0xcc9f,	0xe99a,	0x877a,	0x877a,	0x877a,
	0xcc9f,	0xe99a,	0x877a,	0x877a,	0x877a,
	0xcc9f,	0xe71c,	0xe71c,	0x877a,	0xe71c,
};

void Botton_Sqrt(void);
void Botton_Pow(void);
void Botton_Pi(void);
void Botton_e(void);
void Botton_Del(void);
void Botton_Ln(void);
void Botton_Log(void);
void Botton_Sin(void);
void Botton_Cos(void);
void Botton_Tan(void);
void Botton_Add(void);
void Botton_Sub(void);
void Botton_Mul(void);
void Botton_Div(void);
void Botton_DEG(void);
void Botton_Brace_L(void);
void Botton_Brace_R(void);
void Botton_Clear(void);
void Botton_Point(void);
void Botton_Equal(void);
void Botton_0(void);
void Botton_1(void);
void Botton_2(void);
void Botton_3(void);
void Botton_4(void);
void Botton_5(void);
void Botton_6(void);
void Botton_7(void);
void Botton_8(void);
void Botton_9(void);

void (*ClickCall[ButtonNumX * ButtonNumY])() = {
	Botton_Sqrt,	Botton_Pow,		Botton_Pi,		Botton_e,		Botton_Del,
	Botton_Ln,		Botton_Add,		Botton_Brace_L,	Botton_Brace_R,	Botton_Clear,
	Botton_Log,		Botton_Sub,		Botton_7,		Botton_8,		Botton_9,
	Botton_Sin,		Botton_Mul,		Botton_4,		Botton_5,		Botton_6,
	Botton_Cos,		Botton_Div,		Botton_1,		Botton_2,		Botton_3,
	Botton_Tan,		Botton_DEG,		Botton_Point,	Botton_0,		Botton_Equal,
};

void main() {
	uint16_t x;
	uint16_t y;
	uint8_t i;

	/* 设备初始化 */
	Lcd_ST7789_Init(0);
	CH375_Init();

	/* 背景纹理初始化 */
	for (y = 0; y < DispHigh; y += BottomImage.High)
		for (x = 0; x < DispWidth; x += BottomImage.Width)
			DispRam_LoadImage(x, y, &BottomImage);

	/* 按钮阵列初始化 */
	i = 0;
	for (y = DispHigh - (ButtonHigh + 2) * ButtonNumY; y < (DispHigh - (ButtonHigh + 2) * ButtonNumY) + (ButtonHigh + 2) * ButtonNumY; y += (ButtonHigh + 2)) {
		for (x = 0; x < (ButtonWidth + 4) * ButtonNumX; x += (ButtonWidth + 4)) {
			BUTTON* p = &AllButton[i];
			p->Left = x;
			p->Right = x + (ButtonWidth - 1);
			p->Top = y;
			p->Bottom = y + (ButtonHigh - 1);
			p->Image0 = &Image0;
			p->Image1 = &Image1;
			p->Image2 = &Image2;
			p->TextStr = ButtonName[i];
			//p->TextColor = 0xe71c + x;
			p->TextColor = TextColor[i];
			p->KeyStep = 0;
			p->Focus = false;
			p->State = false;
			p->ClickCall = ClickCall[i];
			DrawButton(p, 0);
			++i;
		}
	}

	/* 界面初始化 */
	MovMouse(GetMouseX, GetMouseY);
	DispRam_ToLcd(0, 0, DispWidth, DispHigh);
	Botton_Clear();

	/* loop */
	while (1) {
		if (UsbUpdate() == (unsigned char)1) {
			for (i = 0; i < ButtonNumX * ButtonNumY; ++i)
				UpdateButton(&AllButton[i]);
			MovMouse(GetMouseX, GetMouseY);
		}
	}
}

#define DispOffsetY		7		//表达式显示Y偏移
#define ExprBufLen		1024	//表达式缓冲区长度

short ExprStrCount;				//表达式字符串计数
char  ExprBuf[ExprBufLen];		//表达式缓冲区
uint8_t ModeState = 1;			//模式状态,(三角函数,0:RAD,1:DEG),(反三角函数,2:RAD,3:DEG)

/* 显示表达式 */
void DispExpr() {
	uint16_t x;
	uint16_t y;

	//设置字体
	ASCII_Font = &ASCII_FontMSGothic16x32;
	//擦除结果
	for (y = DispOffsetY; y < ASCII_Font->FontHigh + DispOffsetY; y += BottomImage.High)
		for (x = 0; x < DispWidth; x += BottomImage.Width)
			DispRam_LoadImage(x, y, &BottomImage);
	//打印结果
	if (ExprStrCount * ASCII_Font->FontWidth > DispWidth) {
		Printf_Set(DispWidth % ASCII_Font->FontWidth, DispOffsetY, 0xe71c, TrnColor);
		printf(&ExprBuf[ExprStrCount - DispWidth / ASCII_Font->FontWidth]);
	}
	else {
		Printf_Set(DispWidth - ExprStrCount * ASCII_Font->FontWidth, DispOffsetY, 0xe71c, TrnColor);
		printf(ExprBuf);
	}
	for (x = 0; x < DispWidth; x += ASCII_Font->FontWidth)
		DispRam_ToLcd(x, DispOffsetY, ASCII_Font->FontWidth, ASCII_Font->FontHigh);
	//恢复字体
	ASCII_Font = &ASCII_Font8x16;
}

/* 添加表达式字符串 */
void AddExprStr(char* str) {
	short len = strlen(str);

	if (len < ExprBufLen - ExprStrCount) {
		strcpy(&ExprBuf[ExprStrCount], str);
		ExprStrCount += len;
		DispExpr();
	} else
		Botton_Clear();
}

/* 添加表达式字符串(去除首个0) */
void AddExprStrCoverFirstZero(char* str) {
	if (ExprStrCount == 1 && *ExprBuf == '0')
		ExprStrCount = 0;
	AddExprStr(str);
}

/************************** 所有按钮回调函数 **************************/

void Botton_Sqrt()	{ AddExprStrCoverFirstZero("sqrt"); }
void Botton_Pow()	{ AddExprStr("^"); }
void Botton_Pi()	{ AddExprStrCoverFirstZero("3.141592653589793"); }
void Botton_e()		{ AddExprStrCoverFirstZero("2.718281828459046"); }

void Botton_Del() {
	if (ExprStrCount > 1) {
		--ExprStrCount;
		ExprBuf[ExprStrCount] = 0;
		DispExpr();
	} else
		Botton_Clear();
}

void Botton_Ln()	{ AddExprStrCoverFirstZero("ln"); }
void Botton_Log()	{ AddExprStrCoverFirstZero("log"); }

void Botton_Sin() {
	if (ModeState == (uint8_t)0 || ModeState == (uint8_t)1)
		AddExprStrCoverFirstZero("sin");
	else
		AddExprStrCoverFirstZero("asin");
}

void Botton_Cos() {
	if (ModeState == (uint8_t)0 || ModeState == (uint8_t)1)
		AddExprStrCoverFirstZero("cos");
	else
		AddExprStrCoverFirstZero("acos");
}

void Botton_Tan() {
	if (ModeState == (uint8_t)0 || ModeState == (uint8_t)1)
		AddExprStrCoverFirstZero("tan");
	else
		AddExprStrCoverFirstZero("atan");
}

void Botton_Add()	{ AddExprStr("+"); }
void Botton_Sub()	{ AddExprStr("-"); }
void Botton_Mul()	{ AddExprStr("*"); }
void Botton_Div()	{ AddExprStr("/"); }

void Botton_DEG() {
	if (ModeState == (uint8_t)0) {
		ModeState = 3;
		SetButtonText(&AllButton[26], "DEG");
		SetButtonText(&AllButton[15], "sin-1");
		SetButtonText(&AllButton[20], "cos-1");
		SetButtonText(&AllButton[25], "tan-1");
	}
	else if (ModeState == (uint8_t)1) {
		ModeState = 0;
		SetButtonText(&AllButton[26], "RAD");
	}
	else if (ModeState == (uint8_t)2) {
		ModeState = 1;
		SetButtonText(&AllButton[26], "DEG");
		SetButtonText(&AllButton[15], "sin");
		SetButtonText(&AllButton[20], "cos");
		SetButtonText(&AllButton[25], "tan");
	}
	else if (ModeState == (uint8_t)3) {
		ModeState = 2;
		SetButtonText(&AllButton[26], "RAD");
	}
}

void Botton_Brace_L() { AddExprStrCoverFirstZero("("); }
void Botton_Brace_R() { AddExprStr(")"); }

void Botton_Clear() {
	ExprStrCount = 0;
	AddExprStr("0");
}

void Botton_Point()	{ AddExprStr("."); }

void Botton_Equal() {
	char Buf[21];
	char Param[6];
	double Value;
	double AbsValue;

	//表达式运算结果
	Value = AbsValue = DealExpr(ExprBuf, ModeState & (uint8_t)1);

	//取绝对值
	((uint8_t*)&AbsValue)[7] &= (uint8_t)0x7f;

	//结果为0则返回纯0
	if (AbsValue == 0.0) {
		Botton_Clear();
		return;
	}

	//精度限制处理
	if (AbsValue < 1.0) {
#if 1
		if(AbsValue > 1E-9)
			strcpy(Param, "%.15f");
		else
			strcpy(Param, "%.6e");
#else
		int i;
		double MulValue = 0.1;
		for (i = 6; i < 19; ++i) {
			if (AbsValue > MulValue) {
				sprintf(Param, "%%.%df", i < 19 ? i : 18);
				break;
			}
			MulValue *= 0.1;
		}
		if (i == 19)
			strcpy(Param, "%.6e");
#endif
	} else {
		int i;
		double MulValue = 10.0;
		for (i = 14; i != 0; --i) {
			if (AbsValue < MulValue) {
				sprintf(Param, "%%.%df", i);
				break;
			}
			MulValue *= 10.0;
		}
		if(i == 0)
			strcpy(Param, "%.11e");
	}

	//浮点值转换为字符串
	sprintf(Buf, Param, Value);

	//删除多余的0
	if (Param[strlen(Param) - 1] != 'e') {
		char* p = &Buf[strlen(Buf) - 1];
		while (*p == '0') {
			*p-- = 0;
			if (*p == '.') {
				*p = 0;
				break;
			}
		}
	}

	//打印结果
	ExprStrCount = 0;
	AddExprStr(Buf);
}

void Botton_0() { AddExprStrCoverFirstZero("0"); }
void Botton_1() { AddExprStrCoverFirstZero("1"); }
void Botton_2() { AddExprStrCoverFirstZero("2"); }
void Botton_3() { AddExprStrCoverFirstZero("3"); }
void Botton_4() { AddExprStrCoverFirstZero("4"); }
void Botton_5() { AddExprStrCoverFirstZero("5"); }
void Botton_6() { AddExprStrCoverFirstZero("6"); }
void Botton_7() { AddExprStrCoverFirstZero("7"); }
void Botton_8() { AddExprStrCoverFirstZero("8"); }
void Botton_9() { AddExprStrCoverFirstZero("9"); }
