#include "GlowTypedef.h"
#include "st7789.h"

typedef struct {
    int x;
    int y;
    uint16_t color;
} Point2D;

void GetInterpolationColor(Point2D p, Point2D p1, Point2D p2, Point2D p3, uint16_t* color)
{
    float x = p.x;
    float i = p.y;
    /** 进行颜色插值 */
    float alph = (-(x - p2.x) * (p3.y - p2.y) + (i - p2.y) * (p3.x - p2.x)) / (-(p1.x - p2.x) * (p3.y - p2.y) + (p1.y - p2.y) * (p3.x - p2.x));
    float beta = (-(x - p3.x) * (p1.y - p3.y) + (i - p3.y) * (p1.x - p3.x)) / (-(p2.x - p3.x) * (p1.y - p3.y) + (p2.y - p3.y) * (p1.x - p3.x));
    /** 注意RGB是三通道，在计算插值颜色时需要分别计算三个通道的插值分量，最后再合并为的插值颜色 */
    uint16_t pixel_r = (uint16_t)(((p1.color & 0xf800) >> 11) * alph + ((p2.color & 0xf800) >> 11) * beta + ((p3.color & 0xf800) >> 11) * (1 - alph - beta));
    uint16_t pixel_g = (uint16_t)(((p1.color & 0x07e0) >> 5) * alph + ((p2.color & 0x07e0) >> 5) * beta + ((p3.color & 0x07e0) >> 5) * (1 - alph - beta));
    uint16_t pixel_b = (uint16_t)((p1.color & 0x001f) * alph + (p2.color & 0x001f) * beta + (p3.color & 0x001f) * (1 - alph - beta));
    *color = (pixel_r << 11) | (pixel_g << 5) | pixel_b;
}

void DrawTop2BottomTrangle(Point2D p1, Point2D p2, Point2D p3)
{
    Point2D p;
    int y;

    if (p2.y <= p1.y)
        return;
    if (p1.x > p3.x)
    {
        p = p1;
        p1 = p3;
        p3 = p;
    }
    /**        p2
               /\
              /  \
             /    \
            /      \
           /        \
        p1 ---------- p3
    */
    for (y = p1.y; y <= p2.y; y++)
    {
        int left_x = p2.x - (int)((p2.y - y) * (p2.x - p1.x) / (p2.y - p1.y));
        int righ_x = p2.x - (int)((p2.y - y) * (p2.x - p3.x) / (p2.y - p3.y));
        int x;

        for (x = left_x; x < righ_x; x++)
        {
            Point2D p;
            p.x = x;
            p.y = y;
            /** 进行颜色插值 */
            GetInterpolationColor(p, p1, p2, p3, &p.color);
            Lcd_Draw_Pixel(x, y, p.color);
        }
    }
}

void DrawBottom2TopTrangle(Point2D p1, Point2D p2, Point2D p3)
{
    Point2D p;
    int y;

    if (p2.y >= p1.y)
        return;
    if (p1.x > p3.x)
    {
        p = p1;
        p1 = p3;
        p3 = p;
    }
    /**
        p1 ---------- p3
           \          /
            \        /
             \      /
              \    /
               \  /
                \/
                p2
    */
    for (y = p1.y; y >= p2.y; y--)
    {
        int left_x = p2.x - (int)((p2.y - y) * (p2.x - p1.x) / (p2.y - p1.y));
        int righ_x = p2.x - (int)((p2.y - y) * (p2.x - p3.x) / (p2.y - p3.y));
        int x;
        /** 进行颜色插值 */
        for (x = left_x; x < righ_x; x++)
        {
            Point2D p;
            p.x = x;
            p.y = y;
            /** 进行颜色插值 */
            GetInterpolationColor(p, p1, p2, p3, &p.color);
            Lcd_Draw_Pixel(x, y, p.color);
        }
    }
}

void DrawTrangle(const Point2D p1, const Point2D p2, const Point2D p3)
{
    Point2D ps[3];
    Point2D tmp;
    int mid_y;
    int mid_x;
    Point2D mid_p;

    ps[0] = p3;
    ps[1] = p2;
    ps[2] = p1;
    /**       p1
               /\
              /  \
             /    \
            /      \
           /        \
          /上半部分  \
         /            \
        p2-------------\ (mid_x,mid_y)
                        \
             下半部分    \
                          \
                           \
                            p3
    */
    /*** 对三角形顶点进行排序， */
    if (ps[0].y < ps[1].y)
    {
        tmp = ps[0];
        ps[0] = ps[1];
        ps[1] = tmp;
    }
    if (ps[0].y < ps[2].y)
    {
        tmp = ps[0];
        ps[0] = ps[2];
        ps[2] = tmp;
    }
    if (ps[1].y < ps[2].y)
    {
        tmp = ps[1];
        ps[1] = ps[2];
        ps[2] = tmp;
    }

    /** 计算出分割点   */
    mid_y = ps[1].y;
    mid_x = ps[2].x - (int)((ps[2].y - mid_y) * (ps[2].x - ps[0].x) / (ps[2].y - ps[0].y));
    mid_p.x = mid_x;
    mid_p.y = mid_y;
    /** 获取分割点的插值颜色 */
    GetInterpolationColor(mid_p, ps[0], ps[1], ps[2], &mid_p.color);
    /** 绘制两个平底三角形  */
    DrawTop2BottomTrangle(mid_p, ps[0], ps[1]);
    DrawBottom2TopTrangle(mid_p, ps[2], ps[1]);
}

void main() {
    Point2D p1, p2, p3;

    Lcd_ST7789_Init(0);

    p1.x = 138; p1.y = 0; p1.color = 0xf800;
    p2.x = 319; p2.y = 220; p2.color = 0x001f;
    p3.x = 0; p3.y = 169; p3.color = 0x07e0;
    DrawTrangle(p1, p2, p3);

    while (1);
}
