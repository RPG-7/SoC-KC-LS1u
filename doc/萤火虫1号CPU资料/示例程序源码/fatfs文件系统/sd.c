/**********************************************/
/*
/*		SD驱动		2022.11 龙少
/*
/**********************************************/

#include "sd.h"
#include "delay.h"

unsigned long sd_byte_size;

/* SD卡接口IO定义 */
#define SD_CS		M_CS2
#define SD_SCK		M_IO0_DO5
#define SD_MOSI		M_IO1_D6
#define SD_MISO		M_IO0_DI0

/* IO控制宏 */
#define SD_SCK_LOW			(IO0 = IO0_INIT_VALUE & ~SD_SCK)
#define SD_CS_LOW			(IO0 = IO0_INIT_VALUE | SD_CS)
#define SD_CS_SCK_LOW       (IO0 = (IO0_INIT_VALUE | SD_CS) & ~SD_SCK)
#define SD_CS_SCK_HIGH		(IO0 = IO0_INIT_VALUE)
#define SD_MOSI_HIGH		(IO1 = SD_MOSI)

/* spi发送一个字节 */
#define SD_SPI_TX(data) \
	IO1 = (unsigned char)(data) >> 1; \
	SD_CS_SCK_LOW; \
	SD_CS_LOW; \
	IO1 = (unsigned char)(data) << 0; \
	SD_CS_SCK_LOW; \
	SD_CS_LOW; \
	IO1 = (unsigned char)(data) << 1; \
	SD_CS_SCK_LOW; \
	SD_CS_LOW; \
	IO1 = (unsigned char)(data) << 2; \
	SD_CS_SCK_LOW; \
	SD_CS_LOW; \
	IO1 = (unsigned char)(data) << 3; \
	SD_CS_SCK_LOW; \
	SD_CS_LOW; \
	IO1 = (unsigned char)(data) << 4; \
	SD_CS_SCK_LOW; \
	SD_CS_LOW; \
	IO1 = (unsigned char)(data) << 5; \
	SD_CS_SCK_LOW; \
	SD_CS_LOW; \
	IO1 = (unsigned char)(data) << 6; \
	SD_CS_SCK_LOW; \
	SD_CS_LOW;

/* spi接收一个字节 */
#define SD_SPI_RX(data) \
	SD_CS_SCK_LOW; \
	SD_CS_LOW; \
	(data) = ((unsigned char)(data) << 1) | (IO0 & SD_MISO); \
	SD_CS_SCK_LOW; \
	SD_CS_LOW; \
	(data) = ((unsigned char)(data) << 1) | (IO0 & SD_MISO); \
	SD_CS_SCK_LOW; \
	SD_CS_LOW; \
	(data) = ((unsigned char)(data) << 1) | (IO0 & SD_MISO); \
	SD_CS_SCK_LOW; \
	SD_CS_LOW; \
	(data) = ((unsigned char)(data) << 1) | (IO0 & SD_MISO); \
	SD_CS_SCK_LOW; \
	SD_CS_LOW; \
	(data) = ((unsigned char)(data) << 1) | (IO0 & SD_MISO); \
	SD_CS_SCK_LOW; \
	SD_CS_LOW; \
	(data) = ((unsigned char)(data) << 1) | (IO0 & SD_MISO); \
	SD_CS_SCK_LOW; \
	SD_CS_LOW; \
	(data) = ((unsigned char)(data) << 1) | (IO0 & SD_MISO); \
	SD_CS_SCK_LOW; \
	SD_CS_LOW; \
	(data) = ((unsigned char)(data) << 1) | (IO0 & SD_MISO);

/* 读设备CSD到缓冲区 */
bool sd_rd_csd(unsigned char* buf) {
	unsigned char i;
	unsigned char spi_reg;
	unsigned char clk_count;

	SD_CS_LOW;
	SD_SPI_TX(0x49);
	SD_SPI_TX(0x00);
	SD_SPI_TX(0x00);
	SD_SPI_TX(0x00);
	SD_SPI_TX(0x00);
	SD_SPI_TX(0xff);
	SD_MOSI_HIGH;
	i = 255;
	do {
		SD_SPI_RX(spi_reg);
	} while (--i != 0 && spi_reg != 0x00);
	if (i == 0)
		return false;
	for (; i != 0 && spi_reg != 0xfe; --i) {
		SD_SPI_RX(spi_reg);
	}
	if (i == 0)
		return false;
	for (i = 16; i != 0; --i) {
		SD_SPI_RX(spi_reg);
		*buf++ = spi_reg;
	}
	for (clk_count = 0; clk_count < 8; ++clk_count) {
		SD_CS_SCK_LOW;
		SD_CS_LOW;
	}
	SD_CS_SCK_HIGH;
	for (clk_count = 0; clk_count < 8; ++clk_count) {
		SD_SCK_LOW;
		SD_CS_SCK_HIGH;
	}
	return true;
}

/* 初始化SD卡 */
bool sd_init() {
	unsigned char spi_reg;
    unsigned short i;
	unsigned char clk_count;
    unsigned char csd[16];
	unsigned long C_SIZE;
	unsigned char C_SIZE_MULT;
	unsigned char READ_BL_LEN;

	IO0_INIT;
    /* 复位为spi模式 */
	SD_MOSI_HIGH;
    for (i = 0; i != 80; ++i) {
        SD_SCK_LOW;
		SD_CS_SCK_HIGH;
    }
	SD_CS_LOW;
	SD_SPI_TX(0x40);
	SD_SPI_TX(0x00);
	SD_SPI_TX(0x00);
	SD_SPI_TX(0x00);
	SD_SPI_TX(0x00);
	SD_SPI_TX(0x95);
	SD_MOSI_HIGH;
	i = 16;
	do {
		SD_SPI_RX(spi_reg);
	} while (--i != 0 && spi_reg != 0x01);
	if(i == 0)
		return false;

	/* 初始化 */
	for (i = 65535; i != 0 && spi_reg != 0x00; --i) {
		SD_CS_SCK_HIGH;
		SD_MOSI_HIGH;
		for (clk_count = 0; clk_count < 8; ++clk_count) {
			SD_SCK_LOW;
			SD_CS_SCK_HIGH;
		}
		SD_CS_LOW;
		SD_SPI_TX(0x41);
		SD_SPI_TX(0x00);
		SD_SPI_TX(0x00);
		SD_SPI_TX(0x00);
		SD_SPI_TX(0x00);
		SD_MOSI_HIGH;
		for (clk_count = 0; clk_count < 16; ++clk_count) {
			SD_CS_SCK_LOW;
			SD_CS_LOW;
		}
		SD_SPI_RX(spi_reg);
	}
	SD_CS_SCK_HIGH;
	for (clk_count = 0; clk_count < 8; ++clk_count) {
		SD_SCK_LOW;
		SD_CS_SCK_HIGH;
	}
	if (i == 0)
		return false;

	/* 读CSD计算设备容量 */
	if(sd_rd_csd(csd) == 0)
		return false;
	C_SIZE = (csd[8] >> 6) | ((unsigned short)csd[7] << 2) | ((unsigned short)(csd[6] & 3) << 10);
	C_SIZE_MULT = ((csd[10] & 128) >> 7) | ((csd[9] & 3) << 1);
	READ_BL_LEN = csd[5] & 0x0f;
	sd_byte_size = (C_SIZE + 1) << (C_SIZE_MULT + 2 + READ_BL_LEN);

	return true;
}

/* SD读512字节到缓冲区 */
bool sd_rd_512byte(unsigned long sc_addr, unsigned char* buf) {
	unsigned char i;
	unsigned char spi_reg;

	sc_addr <<= 1;
	SD_CS_LOW;
	SD_SPI_TX(0x51);
	SD_SPI_TX(((unsigned char*)&sc_addr)[2]);
	SD_SPI_TX(((unsigned char*)&sc_addr)[1]);
	SD_SPI_TX(((unsigned char*)&sc_addr)[0]);
	SD_SPI_TX(0x00);
	SD_SPI_TX(0xff);
	SD_MOSI_HIGH;
	i = 255;
	do {
		SD_SPI_RX(spi_reg);
	} while (--i != 0 && spi_reg != 0x00);
	if (i == 0)
		return false;
	for (; i != 0 && spi_reg != 0xfe; --i) {
		SD_SPI_RX(spi_reg);
	}
	if (i == 0)
		return false;
	for (i = 128; i != 0; --i) {
		SD_SPI_RX(spi_reg);
		*buf++ = spi_reg;
		SD_SPI_RX(spi_reg);
		*buf++ = spi_reg;
		SD_SPI_RX(spi_reg);
		*buf++ = spi_reg;
		SD_SPI_RX(spi_reg);
		*buf++ = spi_reg;
	}
	for (i = 0; i < 8; ++i) {
		SD_CS_SCK_LOW;
		SD_CS_LOW;
	}
	SD_CS_SCK_HIGH;
	for (i = 0; i < 8; ++i) {
		SD_SCK_LOW;
		SD_CS_SCK_HIGH;
	}
	return true;
}

/* 缓冲区写512字节到SD */
bool sd_wr_512byte(unsigned long sc_addr, unsigned char* buf) {
	unsigned char i;
	unsigned char spi_reg;

	sc_addr <<= 1;
	SD_CS_LOW;
	SD_SPI_TX(0x58);
	SD_SPI_TX(((unsigned char*)&sc_addr)[2]);
	SD_SPI_TX(((unsigned char*)&sc_addr)[1]);
	SD_SPI_TX(((unsigned char*)&sc_addr)[0]);
	SD_SPI_TX(0x00);
	SD_SPI_TX(0xff);
	SD_MOSI_HIGH;
	i = 255;
	do {
		SD_SPI_RX(spi_reg);
	} while (--i != 0 && spi_reg != 0x00);
	if (i == 0)
		return false;
	SD_SPI_TX(0xfe);
	for (i = 128; i != 0; --i) {
		spi_reg = *buf++;
		SD_SPI_TX(spi_reg);
		spi_reg = *buf++;
		SD_SPI_TX(spi_reg);
		spi_reg = *buf++;
		SD_SPI_TX(spi_reg);
		spi_reg = *buf++;
		SD_SPI_TX(spi_reg);
	}
	SD_MOSI_HIGH;
	for (i = 255; i != 0 && (spi_reg & 0x1f) != 0x05; --i) {
		SD_SPI_RX(spi_reg);
	}
	if (i == 0)
		return false;
	while (spi_reg != 0xff) {
		SD_SPI_RX(spi_reg);
	}
	SD_CS_SCK_HIGH;
	for (i = 0; i < 8; ++i) {
		SD_SCK_LOW;
		SD_CS_SCK_HIGH;
	}
	return true;
}
