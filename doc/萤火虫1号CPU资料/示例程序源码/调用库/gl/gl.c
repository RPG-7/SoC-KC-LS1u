#include "gl.h"
#include "st7789.h"

/* »­¿ÕÐÄÔ² */
void GDI_DrawRound(unsigned short Ox, unsigned short Oy, unsigned short r, unsigned short rgb) {
    unsigned short dx = r;
    unsigned short dy = 0;

    while ((unsigned short)2 * dy * dy <= r * r)
    {
        Lcd_Draw_Pixel(Ox + dx, Oy + dy, rgb);// 0   pi ~ 1/4 pi
        Lcd_Draw_Pixel(Ox + dy, Oy + dx, rgb);// 1/4 pi ~ 1/2 pi
        Lcd_Draw_Pixel(Ox - dy, Oy + dx, rgb);// 1/2 pi ~ 3/4 pi
        Lcd_Draw_Pixel(Ox - dx, Oy + dy, rgb);// 3/4 pi ~   1 pi
        Lcd_Draw_Pixel(Ox - dx, Oy - dy, rgb);// 1   pi ~ 5/4 pi
        Lcd_Draw_Pixel(Ox - dy, Oy - dx, rgb);// 5/4 pi ~ 3/2 pi
        Lcd_Draw_Pixel(Ox + dy, Oy - dx, rgb);// 3/2 pi ~ 7/4 pi
        Lcd_Draw_Pixel(Ox + dx, Oy - dy, rgb);// 7/4 pi ~   2 pi
        --dx;
        ++dy;
        if (dx * dx + dy * dy > (r + 0.5) * (r + 0.5) || dx * dx + dy * dy < (r - 0.5) * (r - 0.5))
            ++dx;
    }
    Lcd_Draw_Pixel(Ox + dx, Oy + dy, rgb);// 0   pi ~ 1/4 pi
    Lcd_Draw_Pixel(Ox + dy, Oy + dx, rgb);// 1/4 pi ~ 1/2 pi
    Lcd_Draw_Pixel(Ox - dy, Oy + dx, rgb);// 1/2 pi ~ 3/4 pi
    Lcd_Draw_Pixel(Ox - dx, Oy + dy, rgb);// 3/4 pi ~   1 pi
    Lcd_Draw_Pixel(Ox - dx, Oy - dy, rgb);// 1   pi ~ 5/4 pi
    Lcd_Draw_Pixel(Ox - dy, Oy - dx, rgb);// 5/4 pi ~ 3/2 pi
    Lcd_Draw_Pixel(Ox + dy, Oy - dx, rgb);// 3/2 pi ~ 7/4 pi
    Lcd_Draw_Pixel(Ox + dx, Oy - dy, rgb);// 7/4 pi ~   2 pi
}

/* »­ÊµÐÄÔ² */
void GDI_DrawFillRound(unsigned short Ox, unsigned short Oy, unsigned short r, unsigned short rgb) {
    unsigned short dx = r;
    unsigned short dy = 0;

    while ((unsigned short)2 * dy * dy <= r * r)
    {
        Lcd_Fill_Rectangle(Ox - dy, Oy - dx, (Ox + dy) - (Ox - dy) + 1, 1, rgb); //ÉÏ°ëÔ²
        Lcd_Fill_Rectangle(Ox - dx, Oy - dy, (Ox + dx) - (Ox - dx) + 1, 1, rgb); //ÉÏ°ëÔ²
        Lcd_Fill_Rectangle(Ox - dx, Oy + dy, (Ox + dx) - (Ox - dx) + 1, 1, rgb); //ÏÂ°ëÔ²
        Lcd_Fill_Rectangle(Ox - dy, Oy + dx, (Ox + dy) - (Ox - dy) + 1, 1, rgb); //ÏÂ°ëÔ²
        --dx;
        ++dy;
        if (dx * dx + dy * dy > (r + 0.5) * (r + 0.5) || dx * dx + dy * dy < (r - 0.5) * (r - 0.5))
            ++dx;
    }
    Lcd_Fill_Rectangle(Ox - dy, Oy - dx, (Ox + dy) - (Ox - dy) + 1, 1, rgb); //ÉÏ°ëÔ²
    Lcd_Fill_Rectangle(Ox - dx, Oy - dy, (Ox + dx) - (Ox - dx) + 1, 1, rgb); //ÉÏ°ëÔ²
    Lcd_Fill_Rectangle(Ox - dx, Oy + dy, (Ox + dx) - (Ox - dx) + 1, 1, rgb); //ÏÂ°ëÔ²
    Lcd_Fill_Rectangle(Ox - dy, Oy + dx, (Ox + dy) - (Ox - dy) + 1, 1, rgb); //ÏÂ°ëÔ²
}

/* »­Ö±Ïß */
void glib_line(unsigned short x1, unsigned short y1, unsigned short x2, unsigned short y2, unsigned short color)
{
    short dx, dy, e;
    dx = x2 - x1;
    dy = y2 - y1;
    if (dx >= 0)
    {
        if (dy >= (short)0) // dy>=0
        {
            if (dx >= dy) // 1/8 octant
            {
                e = dy - dx / (short)2;
                while (x1 <= x2)
                {
                    Lcd_Draw_Pixel(x1, y1, color);
                    if (e > (short)0) { y1 += (unsigned short)1; e -= dx; }
                    x1 += (unsigned short)1;
                    e += dy;
                }
            }
            else        // 2/8 octant
            {
                e = dx - dy / (short)2;
                while (y1 <= y2)
                {
                    Lcd_Draw_Pixel(x1, y1, color);
                    if (e > (short)0) { x1 += (unsigned short)1; e -= dy; }
                    y1 += (unsigned short)1;
                    e += dx;
                }
            }
        }
        else           // dy<0
        {
            dy = -dy;   // dy=abs(dy)

            if (dx >= dy) // 8/8 octant
            {
                e = dy - dx / (short)2;
                while (x1 <= x2)
                {
                    Lcd_Draw_Pixel(x1, y1, color);
                    if (e > (short)0) { y1 -= (unsigned short)1; e -= dx; }
                    x1 += (unsigned short)1;
                    e += dy;
                }
            }
            else     // 7/8 octant
            {
                e = dx - dy / (short)2;
                while (y1 >= y2)
                {
                    Lcd_Draw_Pixel(x1, y1, color);
                    if (e > (short)0) { x1 += (unsigned short)1; e -= dy; }
                    y1 -= (unsigned short)1;
                    e += dx;
                }
            }
        }
    }
    else //dx<0
    {
        dx = -dx;        //dx=abs(dx)
        if (dy >= (short)0) // dy>=0
        {
            if (dx >= dy) // 4/8 octant
            {
                e = dy - dx / (short)2;
                while (x1 >= x2)
                {
                    Lcd_Draw_Pixel(x1, y1, color);
                    if (e > (short)0) { y1 += (unsigned short)1; e -= dx; }
                    x1 -= (unsigned short)1;
                    e += dy;
                }
            }
            else        // 3/8 octant
            {
                e = dx - dy / (short)2;
                while (y1 <= y2)
                {
                    Lcd_Draw_Pixel(x1, y1, color);
                    if (e > (short)0) { x1 -= (unsigned short)1; e -= dy; }
                    y1 += (unsigned short)1;
                    e += dx;
                }
            }
        }
        else           // dy<0
        {
            dy = -dy;   // dy=abs(dy)

            if (dx >= dy) // 5/8 octant
            {
                e = dy - dx / (short)2;
                while (x1 >= x2)
                {
                    Lcd_Draw_Pixel(x1, y1, color);
                    if (e > (short)0) { y1 -= (unsigned short)1; e -= dx; }
                    x1 -= (unsigned short)1;
                    e += dy;
                }
            }
            else        // 6/8 octant
            {
                e = dx - dy / (short)2;
                while (y1 >= y2)
                {
                    Lcd_Draw_Pixel(x1, y1, color);
                    if (e > (short)0) { x1 -= (unsigned short)1; e -= dy; }
                    y1 -= (unsigned short)1;
                    e += dx;
                }
            }
        }
    }
}

/*
void glib_line(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int color)
{
    int dx, dy, e;
    dx = x2 - x1;
    dy = y2 - y1;
    if (dx >= 0)
    {
        if (dy >= 0) // dy>=0
        {
            if (dx >= dy) // 1/8 octant
            {
                e = dy - dx / 2;
                while (x1 <= x2)
                {
                    Lcd_Draw_Pixel(x1, y1, color);
                    if (e > 0) { y1 += 1; e -= dx; }
                    x1 += 1;
                    e += dy;
                }
            }
            else        // 2/8 octant
            {
                e = dx - dy / 2;
                while (y1 <= y2)
                {
                    Lcd_Draw_Pixel(x1, y1, color);
                    if (e > 0) { x1 += 1; e -= dy; }
                    y1 += 1;
                    e += dx;
                }
            }
        }
        else           // dy<0
        {
            dy = -dy;   // dy=abs(dy)

            if (dx >= dy) // 8/8 octant
            {
                e = dy - dx / 2;
                while (x1 <= x2)
                {
                    Lcd_Draw_Pixel(x1, y1, color);
                    if (e > 0) { y1 -= 1; e -= dx; }
                    x1 += 1;
                    e += dy;
                }
            }
            else     // 7/8 octant
            {
                e = dx - dy / 2;
                while (y1 >= y2)
                {
                    Lcd_Draw_Pixel(x1, y1, color);
                    if (e > 0) { x1 += 1; e -= dy; }
                    y1 -= 1;
                    e += dx;
                }
            }
        }
    }
    else //dx<0
    {
        dx = -dx;        //dx=abs(dx)
        if (dy >= 0) // dy>=0
        {
            if (dx >= dy) // 4/8 octant
            {
                e = dy - dx / 2;
                while (x1 >= x2)
                {
                    Lcd_Draw_Pixel(x1, y1, color);
                    if (e > 0) { y1 += 1; e -= dx; }
                    x1 -= 1;
                    e += dy;
                }
            }
            else        // 3/8 octant
            {
                e = dx - dy / 2;
                while (y1 <= y2)
                {
                    Lcd_Draw_Pixel(x1, y1, color);
                    if (e > 0) { x1 -= 1; e -= dy; }
                    y1 += 1;
                    e += dx;
                }
            }
        }
        else           // dy<0
        {
            dy = -dy;   // dy=abs(dy)

            if (dx >= dy) // 5/8 octant
            {
                e = dy - dx / 2;
                while (x1 >= x2)
                {
                    Lcd_Draw_Pixel(x1, y1, color);
                    if (e > 0) { y1 -= 1; e -= dx; }
                    x1 -= 1;
                    e += dy;
                }
            }
            else        // 6/8 octant
            {
                e = dx - dy / 2;
                while (y1 >= y2)
                {
                    Lcd_Draw_Pixel(x1, y1, color);
                    if (e > 0) { x1 -= 1; e -= dy; }
                    y1 -= 1;
                    e += dx;
                }
            }
        }
    }
}
*/
