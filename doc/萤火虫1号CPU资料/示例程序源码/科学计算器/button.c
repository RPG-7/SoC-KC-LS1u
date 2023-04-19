/**********************************************/
/*
/*			��ť		2022.11 ����
/*
/**********************************************/

#include "button.h"
#include "mouse.h"
#include "printf.h"
#include "string.h"
#include "PrintChar.h"

#define OffsetAdjValX 0
#define OffsetAdjValY -1

/* ���ư�ť���Դ�,ToLcd��Ϊ0��ͬʱ���µ�LCD */
void DrawButton(BUTTON* p, uint8_t ToLcd) {
	BitImage* image = p->Focus == false ? p->Image0 : (p->State == true ? p->Image2 : p->Image1);

	DispRam_LoadImage(p->Left, p->Top, image);
	if (p->TextStr != NULL) {
		uint16_t TrueOffset = (p->State == true ? 1 : 0);
		uint16_t Color = (p->State == true ? (p->TextColor >> 1) & 0x7bef: p->TextColor);
		uint16_t TextOffsetX = (((p->Right - p->Left + 1) - strlen(p->TextStr) * ASCII_Font->FontWidth) >> 1) + OffsetAdjValX;
		uint16_t TextOffsetY = (((p->Bottom - p->Top + 1) - ASCII_Font->FontHigh) >> 1) + OffsetAdjValY;

		Printf_Set(p->Left + TextOffsetX, p->Top + TextOffsetY + TrueOffset, Color, TrnColor);
		printf("%s", p->TextStr);
	}
	if (ToLcd != (uint8_t)0)
		DispRam_ToLcd(p->Left, p->Top, image->Width, image->High);
}

#define FocusEffect 0

/* ���°�ť״̬(�����ص�����) */
void UpdateButton(BUTTON* p) {
	if (GetMouseX >= p->Left && GetMouseX <= p->Right && GetMouseY >= p->Top && GetMouseY <= p->Bottom) {
		if (p->Focus == false) {
			p->Focus = true;
#if FocusEffect
			DrawButton(p, 1);
#endif
		}
		if (p->KeyStep == (uint8_t)0) {
			if (GetMouseButtonAll == (uint8_t)0)
				p->KeyStep = 1;
		} else if (p->KeyStep == (uint8_t)1) {
			if (GetMouseButtonL != (uint8_t)0) {
				p->KeyStep = 2;
				p->State = true;
				DrawButton(p, 1);
			}
		} else if (p->KeyStep == (uint8_t)2) {
			if (GetMouseButtonL == (uint8_t)0) {
				p->KeyStep = 1;
				p->State = false;
				DrawButton(p, 1);
				if (p->ClickCall != NULL)
					p->ClickCall();
			}
		}
	} else {
		if (p->Focus == true) {
			p->Focus = false;
			p->KeyStep = 0;
#if FocusEffect
			p->State = false;
			DrawButton(p, 1);
#else
			if (p->State == true) {
				p->State = false;
				DrawButton(p, 1);
			}
#endif
		}
	}
}

/* ��ȡ��ť״̬(�����ص�����),����Ϊtrue,����Ϊfalse */
bool GetButtonState(BUTTON* p) {
	UpdateButton(p);
	return p->State;
}

/* ���ð�ť�ı� */
void SetButtonText(BUTTON* p, char* str) {
	p->TextStr = str;
	DrawButton(p, 1);
}
