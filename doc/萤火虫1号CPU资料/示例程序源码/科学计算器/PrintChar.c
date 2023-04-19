/**********************************************/
/*
/*		打印字符		2022.11 龙少
/*
/**********************************************/

#include "PrintChar.h"
#include "printf.h"
#include "DispRam.h"
#include "mouse.h"

#define ByteNum(f) (((((f)->FontWidth - (unsigned char)1) >> 3) + 1) * (f)->FontHigh)

/* 打印像素数据 */
void PrintPixelData(unsigned short x, unsigned short y, unsigned char FontWidth, unsigned char FontHigh, unsigned char* p, unsigned short Str_Color, unsigned short BG_Color) {
    unsigned short StartX = x;
    unsigned short EndY = y + FontHigh;

    for (; y < EndY; ++y){
        unsigned char PixelCount;
        unsigned char pixel;

        for (x = StartX, PixelCount = 0; PixelCount < FontWidth; ++x, ++PixelCount) {
            if ((PixelCount & (unsigned char)0x7) == (unsigned char)0)
                pixel = *p++;
            if(pixel > (unsigned char)127)
                DispRam[x][y] = Str_Color;
            else if(BG_Color != TrnColor)
                DispRam[x][y] = BG_Color;
            pixel <<= 1;
        }
    } 
}

#ifdef EnableASCII

/* ASCII字库接口 */
#if ExtLoadASCII == 0
#include "PrintFont/ASCII_Font8x16.c"
//#include "PrintFont/ASCII_Font16x32.c"
#include "PrintFont/ASCII_Font(MSGothic)16x32.c"
PrintFont* ASCII_Font = &ASCII_Font8x16;
#else
PrintFont* ASCII_Font;
#endif

/* 打印单个ASCII字符 */
PrintFont* PrintASCII(unsigned short x, unsigned short y, char character, unsigned short Str_Color, unsigned short BG_Color) {
    PrintPixelData(x, y, ASCII_Font->FontWidth, ASCII_Font->FontHigh, &ASCII_Font->PixelData[character * ByteNum(ASCII_Font)], Str_Color, BG_Color);
    return ASCII_Font;
}

#endif

#ifdef EnableGB2312

/* GB2312字库接口 */
#if ExtLoadGB2312 == 0
#include "PrintFont/GB2312_Font12x12.c"
PrintFont* GB2312_Font = &GB2312_Font12x12;
#else
PrintFont* GB2312_Font;
#endif

/* 打印单个GB2312字符 */
PrintFont* PrintGB2312(unsigned short x, unsigned short y, char* character, unsigned short Str_Color, unsigned short BG_Color) {
    PrintPixelData(x, y, GB2312_Font->FontWidth, GB2312_Font->FontHigh,
        & GB2312_Font->PixelData[(((((unsigned char*)character)[0] - (unsigned char)0xa1) * 94) + (((unsigned char*)character)[1] - (unsigned char)0xa1)) * ByteNum(GB2312_Font)],
        Str_Color, BG_Color);
    return GB2312_Font;
}

#endif
