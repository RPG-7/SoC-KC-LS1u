/**********************************************/
/*
/*			��ť		2022.11 ����
/*
/**********************************************/

#include "GlowTypedef.h"
#include "DispRam.h"
#include "stdbool.h"

#ifndef __BUTTON__

#define __BUTTON__

typedef struct button BUTTON;

/* ��ť������ */
typedef struct button {
	uint16_t Left;			//X��ʼ����
	uint16_t Right;			//X��������
	uint16_t Top;			//Y��ʼ����
	uint16_t Bottom;		//Y��������
	BitImage* Image0;		//ͼƬ֡0
	BitImage* Image1;		//ͼƬ֡1
	BitImage* Image2;		//ͼƬ֡2
	uint16_t TextColor;		//��ť�ı���ɫ
	char* TextStr;			//��ť�ı��ַ���
	uint8_t KeyStep;		//��������,0:����δ��λ,1:�����Ѹ�λ,2:��������
	bool Focus;				//false:��ťû�о۽�(����ڰ�ť��Χ��),true:��ť�۽�(����ڰ�ť��Χ��)
	bool State;				//��ť״̬,true:����,false:����
	void (*ClickCall)();	//��ť����¼��Ļص�����
};

#endif

extern void DrawButton(BUTTON* p, uint8_t ToLcd);
extern void UpdateButton(BUTTON* p);
extern bool GetButtonState(BUTTON* p);
extern void SetButtonText(BUTTON* p, char* str);
