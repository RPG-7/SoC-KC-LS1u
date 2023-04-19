#ifndef __B3D_2D_H__
#define __B3D_2D_H__

#include "b3dlib.h"

typedef struct{
    fBuff_t   frontColor;
    fBuff_t   backColor;
    u16       fontIndex;
    u16       
}B3L_2DControl_t;

extern void     B3L_DrawHLine(s32 xa, s32 xb, s32 y, fBuff_t color);
extern void     B3L_DrawBox(s32 xa, s32 xb, s32 ya, s32 yb, fBuff_t color);
extern void     B3L_DrawVLine(s32 x, s32 ya, s32 yb, fBuff_t color);
extern void     B3L_DrawChar(s32 x, s32 y, u8 c, fBuff_t fColor, fBuff_t bColor);
extern void     B3L_SetFont(u32 index);
//extern void     B3L_SetFrontColor();
//extern void     B3L_SetBackColor();
//extern void     B3L_PrintStr();
//extern void     B3L_DrawLine();
//extern void     B3L_Draw


#endif