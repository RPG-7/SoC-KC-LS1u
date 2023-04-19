/**********************************************/
/*
/*		SDÇý¶¯		2022.11 ÁúÉÙ
/*
/**********************************************/

#include "cpuio.h"
#include "stdbool.h"

extern unsigned long sd_byte_size;
extern bool sd_init();
extern bool sd_rd_512byte(unsigned long sc_addr, unsigned char* buf);
extern bool sd_wr_512byte(unsigned long sc_addr, unsigned char* buf);
