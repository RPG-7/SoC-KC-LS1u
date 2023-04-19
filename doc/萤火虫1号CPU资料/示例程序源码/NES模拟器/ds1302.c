/**********************************************/
/*
/*		ds1302驱动		2022.10 龙少
/*
/**********************************************/

#include "ds1302.h"
#include "cpuio.h"

/* DS1302接口IO定义 */
#define DS1302_RST		M_IO1_D4
#define DS1302_IO		M_IO1_D5
#define DS1302_SCLK		M_CS4

/* IO控制宏 */
#define DS1302_RST_LOW              (IO1 = IO1_INIT_VALUE & ~DS1302_RST)
#define DS1302_RST_HIGH_IO_LOW      (IO1 = (IO1_INIT_VALUE | DS1302_RST) & ~DS1302_IO)
#define DS1302_RST_IO_HIGH          (IO1 = IO1_INIT_VALUE | DS1302_RST | DS1302_IO)
#define DS1302_SCLK_HIGH            (IO0 = IO0_INIT_VALUE)
#define DS1302_SCLK_LOW             (IO0 = IO0_INIT_VALUE | DS1302_SCLK)

#define DS1302_TXB(data)    (data & (unsigned char)1) != (unsigned char)0 ? DS1302_RST_IO_HIGH : DS1302_RST_HIGH_IO_LOW
#define DS1302_RXB(data)    if ((IO1 & DS1302_IO) != (unsigned char)0) data |= (unsigned char)0x80
#define DS1302_DELAY        while ((--delay & (unsigned char)0x07) != (unsigned char)0)

static unsigned char delay = 0;

void DS1302_WR_REG(unsigned char addr, unsigned char data) {
    unsigned char i;

    DS1302_RST_LOW; //DS1302_RST = 0 复位DS1302
    DS1302_SCLK_LOW; //DS1302_CLK = 0
    DS1302_DELAY;
    DS1302_RST_HIGH_IO_LOW; //DS1302_RST = 1 复位完成, 同时 DS1302_IO = 0 发送读写控制位 1读0写
    DS1302_DELAY;
    DS1302_SCLK_HIGH; //DS1302_CLK = 1
    DS1302_DELAY;
    DS1302_SCLK_LOW; //DS1302_CLK = 0
    //发送6位地址
    for (i = 0; i != (unsigned char)6; ++i) {
        DS1302_TXB(addr);
        DS1302_DELAY;
        DS1302_SCLK_HIGH; //DS1302_CLK = 1
        DS1302_DELAY;
        DS1302_SCLK_LOW; //DS1302_CLK = 0
        addr >>= 1;
    }
    DS1302_RST_IO_HIGH; //DS1302_IO = 1 发送停止位1
    DS1302_DELAY;
    DS1302_SCLK_HIGH; //DS1302_CLK = 1
    DS1302_DELAY;
    DS1302_SCLK_LOW; //DS1302_CLK = 0
    //发送8位数据
    for (i = 0; i != (unsigned char)8; ++i) {
        DS1302_TXB(data);
        DS1302_DELAY;
        DS1302_SCLK_HIGH; //DS1302_CLK = 1
        DS1302_DELAY;
        DS1302_SCLK_LOW; //DS1302_CLK = 0
        data >>= 1;
    }
    DS1302_RST_LOW; //DS1302_RST = 0 复位DS1302
}

unsigned char DS1302_RD_REG(unsigned char addr) {
    unsigned char i, data;

    DS1302_RST_LOW; //DS1302_RST = 0 复位DS1302
    DS1302_SCLK_LOW; //DS1302_CLK = 0
    DS1302_DELAY;
    DS1302_RST_IO_HIGH; //DS1302_RST = 1 复位完成, 同时 DS1302_IO = 1 发送读写控制位 1读0写
    DS1302_DELAY;
    DS1302_SCLK_HIGH; //DS1302_CLK = 1
    DS1302_DELAY;
    DS1302_SCLK_LOW; //DS1302_CLK = 0
    //发送6位地址
    for (i = 0; i != (unsigned char)6; ++i) {
        DS1302_TXB(addr);
        DS1302_DELAY;
        DS1302_SCLK_HIGH; //DS1302_CLK = 1
        DS1302_DELAY;
        DS1302_SCLK_LOW; //DS1302_CLK = 0
        addr >>= 1;
    }
    DS1302_RST_IO_HIGH; //DS1302_IO = 1 发送停止位1
    //接收8位数据
    for (i = 0; i != (unsigned char)8; ++i) {
        DS1302_SCLK_HIGH; //DS1302_CLK = 1
        DS1302_DELAY;
        DS1302_SCLK_LOW; //DS1302_CLK = 0
        DS1302_DELAY;
        data >>= 1;
        DS1302_RXB(data);
    }
    DS1302_RST_LOW; //DS1302_RST = 0 复位DS1302
    return data;
}

/* 更新年月日时分秒 */
void DS1302_RTC_UP(unsigned char YEAR, unsigned char MONTH, unsigned char DATE, unsigned char HR, unsigned char MIN, unsigned char SEC) {
    DS1302_WR_REG(6, YEAR);
    DS1302_WR_REG(4, MONTH);
    DS1302_WR_REG(3, DATE);
    DS1302_WR_REG(2, HR);
    DS1302_WR_REG(1, MIN);
    DS1302_WR_REG(0, SEC);
}
