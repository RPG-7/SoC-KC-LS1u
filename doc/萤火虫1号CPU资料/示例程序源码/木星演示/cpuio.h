/**********************************************/
/*
/*		cpuio定义		2022.10 龙少
/*
/**********************************************/

extern unsigned char REGISTER_IO0; //CPU的IO0
extern unsigned char REGISTER_IO1; //CPU的IO1
extern unsigned char IO0_STATE; //记录IO0的状态
extern unsigned char IO1_STATE; //记录IO1的状态

#define IO0 REGISTER_IO0
#define IO1 REGISTER_IO1

/* IO掩码 */
#define M_IO_D0 (unsigned char) 0x01
#define M_IO_D1 (unsigned char) 0x02
#define M_IO_D2 (unsigned char) 0x04
#define M_IO_D3 (unsigned char) 0x08
#define M_IO_D4 (unsigned char) 0x10
#define M_IO_D5 (unsigned char) 0x20
#define M_IO_D6 (unsigned char) 0x40
#define M_IO_D7 (unsigned char) 0x80

/* 设备片选掩码 */
#define M_CS0 (unsigned char) 0
#define M_CS1 (unsigned char) 1
#define M_CS2 (unsigned char) 2
#define M_CS3 (unsigned char) 3
#define M_CS4 (unsigned char) 4
#define M_CS5 (unsigned char) 5
#define M_CS6 (unsigned char) 6
#define M_CS7 (unsigned char) 7

/* IO0_DO掩码 */
#define M_IO0_DO0 (unsigned char) 0x01
#define M_IO0_DO1 (unsigned char) 0x02
#define M_IO0_DO2 (unsigned char) 0x04
#define M_IO0_DO3 (unsigned char) 0x08
#define M_IO0_DO4 (unsigned char) 0x10
#define M_IO0_DO5 (unsigned char) 0x20
#define M_IO0_DO6 (unsigned char) 0x40
#define M_IO0_DO7 (unsigned char) 0x80

/* IO0_DI掩码 */
#define M_IO0_DI0 (unsigned char) 0x01
#define M_IO0_DI1 (unsigned char) 0x02
#define M_IO0_DI2 (unsigned char) 0x04
#define M_IO0_DI3 (unsigned char) 0x08
#define M_IO0_DI4 (unsigned char) 0x10
#define M_IO0_DI5 (unsigned char) 0x20
#define M_IO0_DI6 (unsigned char) 0x40
#define M_IO0_DI7 (unsigned char) 0x80

/* IO1_D掩码 */
#define M_IO1_D0 (unsigned char) 0x01
#define M_IO1_D1 (unsigned char) 0x02
#define M_IO1_D2 (unsigned char) 0x04
#define M_IO1_D3 (unsigned char) 0x08
#define M_IO1_D4 (unsigned char) 0x10
#define M_IO1_D5 (unsigned char) 0x20
#define M_IO1_D6 (unsigned char) 0x40
#define M_IO1_D7 (unsigned char) 0x80

/* 定义IO初始化值 */
#define IO0_INIT_VALUE (unsigned char) 0xf8
#define IO1_INIT_VALUE (unsigned char) 0xff

/* 初始化IO */
#define IO_INIT	\
	IO0_INIT;	\
	IO1_INIT;

/* 设置CS片选 */
#define IO_SET_CS(data) (IO0_STATE = IO0_STATE & (unsigned char)0xf8 | (unsigned char)(data), IO0 = IO0_STATE)

/*初始化IO0*/
#define IO0_INIT (IO0_STATE = IO0 = IO0_INIT_VALUE)

/* IO0选中的位置0 */
#define IO0_DO_SET_0(data) (IO0_STATE &= ~(unsigned char)(data), IO0 = IO0_STATE)

/* IO0选中的位置1 */
#define IO0_DO_SET_1(data) (IO0_STATE |= (unsigned char)(data), IO0 = IO0_STATE)

/* 读取IO0_DI的一个位 */
#define IO0_DI0		(IO0 & 0x01)
#define IO0_DI1		((IO0 >> 1) & (unsigned char)1)
#define IO0_DI2		((IO0 >> 2) & (unsigned char)1)
#define IO0_DI3		((IO0 >> 3) & (unsigned char)1)
#define IO0_DI4		((IO0 >> 4) & (unsigned char)1)
#define IO0_DI5		((IO0 >> 5) & (unsigned char)1)
#define IO0_DI6		((IO0 >> 6) & (unsigned char)1)
#define IO0_DI7		((IO0 >> 7) & (unsigned char)1)
#define IO0_DI(bit) ((IO0 >> (bit)) & (unsigned char)1)

/* 写入IO0_DO的一个位 */
#define IO0_DO0(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D0, IO0 = IO0_STATE) : (IO0_STATE &= ~M_IO_D0, IO0 = IO0_STATE))
#define IO0_DO1(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D1, IO0 = IO0_STATE) : (IO0_STATE &= ~M_IO_D1, IO0 = IO0_STATE))
#define IO0_DO2(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D2, IO0 = IO0_STATE) : (IO0_STATE &= ~M_IO_D2, IO0 = IO0_STATE))
#define IO0_DO3(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D3, IO0 = IO0_STATE) : (IO0_STATE &= ~M_IO_D3, IO0 = IO0_STATE))
#define IO0_DO4(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D4, IO0 = IO0_STATE) : (IO0_STATE &= ~M_IO_D4, IO0 = IO0_STATE))
#define IO0_DO5(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D5, IO0 = IO0_STATE) : (IO0_STATE &= ~M_IO_D5, IO0 = IO0_STATE))
#define IO0_DO6(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D6, IO0 = IO0_STATE) : (IO0_STATE &= ~M_IO_D6, IO0 = IO0_STATE))
#define IO0_DO7(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D7, IO0 = IO0_STATE) : (IO0_STATE &= ~M_IO_D7, IO0 = IO0_STATE))
#define IO0_DO(bit, data)	(((data) & 1) ? (IO0_STATE |= (unsigned char)(0x01 << (bit)), IO0 = IO0_STATE) : (IO0_STATE &= ~(unsigned char)(0x01 << (bit)), IO0 = IO0_STATE))

/*初始化IO1*/
#define IO1_INIT (IO1_STATE = IO1 = IO1_INIT_VALUE)

/* IO1选中的位置0 */
#define IO1_DO_SET_0(data) (IO1_STATE &= ~(unsigned char)(data), IO1 = IO1_STATE)

/* IO1选中的位置1 */
#define IO1_DO_SET_1(data) (IO1_STATE |= (unsigned char)(data), IO1 = IO1_STATE)

/* 读取IO1_DI的一个位 */
#define IO1_DI0		(IO1 & 0x01)
#define IO1_DI1		((IO1 >> 1) & (unsigned char)1)
#define IO1_DI2		((IO1 >> 2) & (unsigned char)1)
#define IO1_DI3		((IO1 >> 3) & (unsigned char)1)
#define IO1_DI4		((IO1 >> 4) & (unsigned char)1)
#define IO1_DI5		((IO1 >> 5) & (unsigned char)1)
#define IO1_DI6		((IO1 >> 6) & (unsigned char)1)
#define IO1_DI7		((IO1 >> 7) & (unsigned char)1)
#define IO1_DI(bit) ((IO1 >> (bit)) & (unsigned char)1)

/* 写入IO1_DO的一个位 */
#define IO1_DO0(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D0, IO1 = IO0_STATE) : (IO0_STATE &= ~M_IO_D0, IO1 = IO0_STATE))
#define IO1_DO1(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D1, IO1 = IO0_STATE) : (IO0_STATE &= ~M_IO_D1, IO1 = IO0_STATE))
#define IO1_DO2(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D2, IO1 = IO0_STATE) : (IO0_STATE &= ~M_IO_D2, IO1 = IO0_STATE))
#define IO1_DO3(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D3, IO1 = IO0_STATE) : (IO0_STATE &= ~M_IO_D3, IO1 = IO0_STATE))
#define IO1_DO4(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D4, IO1 = IO0_STATE) : (IO0_STATE &= ~M_IO_D4, IO1 = IO0_STATE))
#define IO1_DO5(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D5, IO1 = IO0_STATE) : (IO0_STATE &= ~M_IO_D5, IO1 = IO0_STATE))
#define IO1_DO6(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D6, IO1 = IO0_STATE) : (IO0_STATE &= ~M_IO_D6, IO1 = IO0_STATE))
#define IO1_DO7(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D7, IO1 = IO0_STATE) : (IO0_STATE &= ~M_IO_D7, IO1 = IO0_STATE))
#define IO1_DO(bit, data)	(((data) & 1) ? (IO0_STATE |= (unsigned char)(0x01 << (bit)), IO1 = IO0_STATE) : (IO0_STATE &= ~(unsigned char)(0x01 << (bit)), IO1 = IO0_STATE))
