/**********************************************/
/*
/*		��ӡ�ַ�		2022.10 ����
/*
/**********************************************/

#ifndef __PrintFont__

#define __PrintFont__

typedef struct {
    unsigned char FontWidth;
    unsigned char FontHigh;
    unsigned char* PixelData;
} PrintFont;

#endif

/* ʹ��ASCII */
#define EnableASCII

/* ʹ��GB2312 */
//#define EnableGB2312

#ifdef EnableASCII
/* ��Ϊ0���ⲿ����ASCII�ֿ����� */
#define ExtLoadASCII    0
#endif

#ifdef EnableGB2312
/* ��Ϊ0���ⲿ����GB2312�ֿ����� */
#define ExtLoadGB2312   0
#endif

extern PrintFont* ASCII_Font;
extern PrintFont ASCII_Font6x12;
extern PrintFont ASCII_Font7x14;
extern PrintFont ASCII_Font8x16;
extern PrintFont ASCII_Font12x24;
extern PrintFont ASCII_Font16x32;
extern PrintFont ASCII_FontMSMincho16x32;
extern PrintFont ASCII_FontBodoniMT16x32;
extern PrintFont ASCII_FontArialRoundedMT16x32;
extern PrintFont ASCII_FontMSGothic16x32;

extern PrintFont* GB2312_Font;
extern PrintFont GB2312_Font12x12;
extern PrintFont GB2312_Font24x24;
extern PrintFont GB2312_Font32x32;

extern void PrintPixelData(unsigned short x, unsigned short y, unsigned char FontWidth, unsigned char FontHigh, unsigned char* p, unsigned short Str_Color, unsigned short BG_Color);
extern PrintFont* PrintASCII(unsigned short x, unsigned short y, char character, unsigned short Str_Color, unsigned short BG_Color);
extern PrintFont* PrintGB2312(unsigned short x, unsigned short y, char* character, unsigned short Str_Color, unsigned short BG_Color);
