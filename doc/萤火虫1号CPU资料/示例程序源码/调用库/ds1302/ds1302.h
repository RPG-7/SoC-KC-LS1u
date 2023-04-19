/**********************************************/
/*
/*		ds1302Çý¶¯		2022.10 ÁúÉÙ
/*
/**********************************************/

#define DS1302_SEC		0
#define DS1302_MIN		1
#define DS1302_HR		2
#define DS1302_DATE		3
#define DS1302_MONTH	4
#define DS1302_YEAR		5

extern void DS1302_WR_REG(unsigned char addr, unsigned char data);
extern unsigned char DS1302_RD_REG(unsigned char addr);
extern void DS1302_RTC_UP(unsigned char YEAR, unsigned char MONTH, unsigned char DATE, unsigned char HR, unsigned char MIN, unsigned char SEC);
