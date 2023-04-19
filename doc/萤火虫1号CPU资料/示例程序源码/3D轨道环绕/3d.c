/**********************************************/
/*
/*		3Dª∑»∆πÏµ¿		2015.7-2022.10 ¡˙…Ÿ
/*
/**********************************************/

#include "3d.h"
#include "st7789.h"
#include "delay.h"

short sin[91] = {
0x00,0x02,0x04,0x07,0x09,0x0b,0x0d,0x10,0x12,0x14,0x16,0x18,0x1b,0x1d,0x1f,0x21,
0x23,0x25,0x28,0x2a,0x2c,0x2e,0x30,0x32,0x34,0x36,0x38,0x3a,0x3c,0x3e,0x40,0x42,
0x44,0x46,0x48,0x49,0x4b,0x4d,0x4f,0x51,0x52,0x54,0x56,0x57,0x59,0x5a,0x5c,0x5e,
0x5f,0x61,0x62,0x63,0x65,0x66,0x68,0x69,0x6a,0x6b,0x6d,0x6e,0x6f,0x70,0x71,0x72,
0x73,0x74,0x75,0x76,0x77,0x78,0x78,0x79,0x7a,0x7a,0x7b,0x7c,0x7c,0x7d,0x7d,0x7e,
0x7e,0x7e,0x7f,0x7f,0x7f,0x7f,0x80,0x80,0x80,0x80,0x80,
};

short sin_360[361];
short cos_360[361];

void sin_cos_csh() {
    unsigned short D = 0;

    for (D = 0; D < (unsigned short)361; ++D) {
        if (D < (unsigned short)91) {
            sin_360[D] = sin[D];
            cos_360[D] = sin[(unsigned short)90 - D];
        } else if (D > (unsigned short)90 && D < (unsigned short)181) {
            sin_360[D] = sin[(unsigned short)180 - D];
            cos_360[D] = -sin[D - (unsigned short)90];
        } else if (D > (unsigned short)180 && D < (unsigned short)271) {
            sin_360[D] = -sin[D - (unsigned short)180];
            cos_360[D] = -sin[(unsigned short)270 - D];
        } else {
            sin_360[D] = -sin[(unsigned short)360 - D];
            cos_360[D] = sin[D - (unsigned short)270];
        }
    }
}

void yuan(short VRAMY, short VRAMX, short XD, short YD, short ZD, short r, unsigned short VRAM_DATA) {
    unsigned short dd = 0;
    short y, x;
    short Y, X, Z;
    short _Y, _X, _Z;
    short _sin, _cos;
    short _sin1, _cos1;
    short _sin2, _cos2;
    short _sin3, _cos3;

    _sin1 = sin_360[XD];
    _cos1 = cos_360[XD];
    _sin2 = sin_360[YD];
    _cos2 = cos_360[YD];
    _sin3 = sin_360[ZD];
    _cos3 = cos_360[ZD];
    do {
        _sin = sin_360[dd];
        _cos = cos_360[dd];
        X = _cos * r >> 7;
        _Y = _sin * r >> 7;
        Y = _cos1 * _Y >> 7;
        _Z = _sin1 * _Y >> 7;
        _X = _sin2 * _Z + _cos2 * X >> 7;
        X = _cos3 * _X - _sin3 * Y >> 7;
        Y = _sin3 * _X + _cos3 * Y >> 7;
        y = VRAMY - Y;
        x = VRAMX + X;
        Lcd_Draw_Pixel_0(x, y, VRAM_DATA);
        dd += (unsigned short)5;
    } while (dd < (unsigned short)360);
}

void guidaoyuan(short VRAMY, short VRAMX, short XD, short YD, short ZD, short r, short rr, short rrD, unsigned short VRAM_DATA) {
    unsigned short dd = 0;
    short y, x;
    short Y, X, Z;
    short _Y, _X, _Z;
    short _sin, _cos;
    short _sin1, _cos1;
    short _sin2, _cos2;
    short _sin3, _cos3;
    short _sin4, _cos4;

    _sin1 = sin_360[XD];
    _cos1 = cos_360[XD];
    _sin2 = sin_360[YD];
    _cos2 = cos_360[YD];
    _sin3 = sin_360[ZD];
    _cos3 = cos_360[ZD];
    _sin4 = sin_360[rrD];
    _cos4 = cos_360[rrD];
    do {
        _sin = sin_360[dd];
        _cos = cos_360[dd];
        Z = _cos * rr >> 7;
        _X = _sin * rr >> 7;
        X = _cos4 * (r + _X) >> 7;
        _Y = _sin4 * (r + _X) >> 7;
        Y = _cos1 * _Y - _sin1 * Z >> 7;
        _Z = _sin1 * _Y + _cos1 * Z >> 7;
        _X = _sin2 * _Z + _cos2 * X >> 7;
        X = _cos3 * _X - _sin3 * Y >> 7;
        Y = _sin3 * _X + _cos3 * Y >> 7;
        y = VRAMY - Y;
        x = VRAMX + X;
        Lcd_Draw_Pixel_0(x, y, VRAM_DATA);
        dd += (unsigned short)10;
    } while (dd < (unsigned short)360);
}

void zhongxinzhou(short VRAMY, short VRAMX, short XD, short YD, short ZD, unsigned short VRAM_DATA) {
    short zz = -64;
    short y, x;
    short Y, X, Z;
    short _Y, _X, _Z;
    short _sin, _cos;
    short _sin1, _cos1;
    short _sin2, _cos2;
    short _sin3, _cos3;

    _sin1 = sin_360[XD];
    _cos1 = cos_360[XD];
    _sin2 = sin_360[YD];
    _cos2 = cos_360[YD];
    _sin3 = sin_360[ZD];
    _cos3 = cos_360[ZD];
    do {
        Y = -_sin1 * zz >> 7;
        _Z = _cos1 * zz >> 7;
        _X = _sin2 * _Z >> 7;
        X = _cos3 * _X - _sin3 * Y >> 7;
        Y = _sin3 * _X + _cos3 * Y >> 7;
        y = VRAMY - Y;
        x = VRAMX + X;
        Lcd_Draw_Pixel_0(x, y, VRAM_DATA);
        zz += (short)1;
    } while (zz < (short)64);
}


void _3d_main() {
    short YD = 0, XD = 0, ZD = 0;
    short YD1 = 0, XD1 = 0, ZD1 = 0;
    short gdhwz1 = 0, gdhwz2 = 360;
    unsigned short SW_Delay = 0;
    unsigned char SW = 0;

    sin_cos_csh();
    while (1) {
        XD += 3; ++ZD;
        if (XD == 360) XD = 0;
        if (ZD == 360) ZD = 0;

        XD1 += 3; YD1 += 1; ZD1 += 2;
        if (XD1 == 360) XD1 = 0;
        if (YD1 == 360) YD1 = 0;
        if (ZD1 == 360) ZD1 = 0;
        
        gdhwz1 += 4;
        gdhwz2 -= 8;
        if (gdhwz1 == 360) gdhwz1 = 0;
        if (gdhwz2 == 0) gdhwz2 = 360;

        SW_Delay += 4;
        if (SW_Delay >= 1080) SW_Delay = 0, SW = ~SW;

        zhongxinzhou(120, 160, XD, YD, ZD, 0xffff);
        yuan(120, 160, XD, YD, ZD, 32, 0xffff);
        guidaoyuan(120, 160, XD, YD, ZD, 32, 5, gdhwz2, 0xf800);
        if (SW == 0)
            yuan(120, 160, XD, YD, ZD, 64, 0x0f1f);
        if (SW == 0)
            yuan(120, 160, XD1, YD1, ZD1, 96, 0xffe0);
        guidaoyuan(120, 160, XD1, YD1, ZD1, 96, 13, gdhwz1, 0x07e0);

        Delay(6000);

        zhongxinzhou(120, 160, XD, YD, ZD, 0);
        yuan(120, 160, XD, YD, ZD, 32, 0);
        guidaoyuan(120, 160, XD, YD, ZD, 32, 5, gdhwz2, 0);
        if (SW == 0)
            yuan(120, 160, XD, YD, ZD, 64, 0);
        if (SW == 0)
            yuan(120, 160, XD1, YD1, ZD1, 96, 0);
        guidaoyuan(120, 160, XD1, YD1, ZD1, 96, 13, gdhwz1, 0);
    }
}
