/**********************************************/
/*
/*		cpuio����		2022.10 ����
/*
/**********************************************/

extern unsigned char REGISTER_IO0; //CPU��IO0
extern unsigned char REGISTER_IO1; //CPU��IO1
extern unsigned char IO0_STATE; //��¼IO0��״̬
extern unsigned char IO1_STATE; //��¼IO1��״̬

#define IO0 REGISTER_IO0
#define IO1 REGISTER_IO1

/* IO���� */
#define M_IO_D0 (unsigned char) 0x01
#define M_IO_D1 (unsigned char) 0x02
#define M_IO_D2 (unsigned char) 0x04
#define M_IO_D3 (unsigned char) 0x08
#define M_IO_D4 (unsigned char) 0x10
#define M_IO_D5 (unsigned char) 0x20
#define M_IO_D6 (unsigned char) 0x40
#define M_IO_D7 (unsigned char) 0x80

/* �豸Ƭѡ���� */
#define M_CS0 (unsigned char) 0
#define M_CS1 (unsigned char) 1
#define M_CS2 (unsigned char) 2
#define M_CS3 (unsigned char) 3
#define M_CS4 (unsigned char) 4
#define M_CS5 (unsigned char) 5
#define M_CS6 (unsigned char) 6
#define M_CS7 (unsigned char) 7

/* IO0_DO���� */
#define M_IO0_DO0 (unsigned char) 0x01
#define M_IO0_DO1 (unsigned char) 0x02
#define M_IO0_DO2 (unsigned char) 0x04
#define M_IO0_DO3 (unsigned char) 0x08
#define M_IO0_DO4 (unsigned char) 0x10
#define M_IO0_DO5 (unsigned char) 0x20
#define M_IO0_DO6 (unsigned char) 0x40
#define M_IO0_DO7 (unsigned char) 0x80

/* IO0_DI���� */
#define M_IO0_DI0 (unsigned char) 0x01
#define M_IO0_DI1 (unsigned char) 0x02
#define M_IO0_DI2 (unsigned char) 0x04
#define M_IO0_DI3 (unsigned char) 0x08
#define M_IO0_DI4 (unsigned char) 0x10
#define M_IO0_DI5 (unsigned char) 0x20
#define M_IO0_DI6 (unsigned char) 0x40
#define M_IO0_DI7 (unsigned char) 0x80

/* IO1_D���� */
#define M_IO1_D0 (unsigned char) 0x01
#define M_IO1_D1 (unsigned char) 0x02
#define M_IO1_D2 (unsigned char) 0x04
#define M_IO1_D3 (unsigned char) 0x08
#define M_IO1_D4 (unsigned char) 0x10
#define M_IO1_D5 (unsigned char) 0x20
#define M_IO1_D6 (unsigned char) 0x40
#define M_IO1_D7 (unsigned char) 0x80

/* ����IO��ʼ��ֵ */
#define IO0_INIT_VALUE (unsigned char) 0xf8
#define IO1_INIT_VALUE (unsigned char) 0xff

/* ��ʼ��IO */
#define IO_INIT	\
	IO0_INIT;	\
	IO1_INIT;

/* ����CSƬѡ */
#define IO_SET_CS(data) (IO0_STATE = IO0_STATE & (unsigned char)0xf8 | (unsigned char)(data), IO0 = IO0_STATE)

/*��ʼ��IO0*/
#define IO0_INIT (IO0_STATE = IO0 = IO0_INIT_VALUE)

/* IO0ѡ�е�λ��0 */
#define IO0_DO_SET_0(data) (IO0_STATE &= ~(unsigned char)(data), IO0 = IO0_STATE)

/* IO0ѡ�е�λ��1 */
#define IO0_DO_SET_1(data) (IO0_STATE |= (unsigned char)(data), IO0 = IO0_STATE)

/* ��ȡIO0_DI��һ��λ */
#define IO0_DI0		(IO0 & 0x01)
#define IO0_DI1		((IO0 >> 1) & (unsigned char)1)
#define IO0_DI2		((IO0 >> 2) & (unsigned char)1)
#define IO0_DI3		((IO0 >> 3) & (unsigned char)1)
#define IO0_DI4		((IO0 >> 4) & (unsigned char)1)
#define IO0_DI5		((IO0 >> 5) & (unsigned char)1)
#define IO0_DI6		((IO0 >> 6) & (unsigned char)1)
#define IO0_DI7		((IO0 >> 7) & (unsigned char)1)
#define IO0_DI(bit) ((IO0 >> (bit)) & (unsigned char)1)

/* д��IO0_DO��һ��λ */
#define IO0_DO0(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D0, IO0 = IO0_STATE) : (IO0_STATE &= ~M_IO_D0, IO0 = IO0_STATE))
#define IO0_DO1(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D1, IO0 = IO0_STATE) : (IO0_STATE &= ~M_IO_D1, IO0 = IO0_STATE))
#define IO0_DO2(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D2, IO0 = IO0_STATE) : (IO0_STATE &= ~M_IO_D2, IO0 = IO0_STATE))
#define IO0_DO3(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D3, IO0 = IO0_STATE) : (IO0_STATE &= ~M_IO_D3, IO0 = IO0_STATE))
#define IO0_DO4(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D4, IO0 = IO0_STATE) : (IO0_STATE &= ~M_IO_D4, IO0 = IO0_STATE))
#define IO0_DO5(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D5, IO0 = IO0_STATE) : (IO0_STATE &= ~M_IO_D5, IO0 = IO0_STATE))
#define IO0_DO6(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D6, IO0 = IO0_STATE) : (IO0_STATE &= ~M_IO_D6, IO0 = IO0_STATE))
#define IO0_DO7(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D7, IO0 = IO0_STATE) : (IO0_STATE &= ~M_IO_D7, IO0 = IO0_STATE))
#define IO0_DO(bit, data)	(((data) & 1) ? (IO0_STATE |= (unsigned char)(0x01 << (bit)), IO0 = IO0_STATE) : (IO0_STATE &= ~(unsigned char)(0x01 << (bit)), IO0 = IO0_STATE))

/*��ʼ��IO1*/
#define IO1_INIT (IO1_STATE = IO1 = IO1_INIT_VALUE)

/* IO1ѡ�е�λ��0 */
#define IO1_DO_SET_0(data) (IO1_STATE &= ~(unsigned char)(data), IO1 = IO1_STATE)

/* IO1ѡ�е�λ��1 */
#define IO1_DO_SET_1(data) (IO1_STATE |= (unsigned char)(data), IO1 = IO1_STATE)

/* ��ȡIO1_DI��һ��λ */
#define IO1_DI0		(IO1 & 0x01)
#define IO1_DI1		((IO1 >> 1) & (unsigned char)1)
#define IO1_DI2		((IO1 >> 2) & (unsigned char)1)
#define IO1_DI3		((IO1 >> 3) & (unsigned char)1)
#define IO1_DI4		((IO1 >> 4) & (unsigned char)1)
#define IO1_DI5		((IO1 >> 5) & (unsigned char)1)
#define IO1_DI6		((IO1 >> 6) & (unsigned char)1)
#define IO1_DI7		((IO1 >> 7) & (unsigned char)1)
#define IO1_DI(bit) ((IO1 >> (bit)) & (unsigned char)1)

/* д��IO1_DO��һ��λ */
#define IO1_DO0(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D0, IO1 = IO0_STATE) : (IO0_STATE &= ~M_IO_D0, IO1 = IO0_STATE))
#define IO1_DO1(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D1, IO1 = IO0_STATE) : (IO0_STATE &= ~M_IO_D1, IO1 = IO0_STATE))
#define IO1_DO2(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D2, IO1 = IO0_STATE) : (IO0_STATE &= ~M_IO_D2, IO1 = IO0_STATE))
#define IO1_DO3(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D3, IO1 = IO0_STATE) : (IO0_STATE &= ~M_IO_D3, IO1 = IO0_STATE))
#define IO1_DO4(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D4, IO1 = IO0_STATE) : (IO0_STATE &= ~M_IO_D4, IO1 = IO0_STATE))
#define IO1_DO5(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D5, IO1 = IO0_STATE) : (IO0_STATE &= ~M_IO_D5, IO1 = IO0_STATE))
#define IO1_DO6(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D6, IO1 = IO0_STATE) : (IO0_STATE &= ~M_IO_D6, IO1 = IO0_STATE))
#define IO1_DO7(data)		(((data) & 1) ? (IO0_STATE |= M_IO_D7, IO1 = IO0_STATE) : (IO0_STATE &= ~M_IO_D7, IO1 = IO0_STATE))
#define IO1_DO(bit, data)	(((data) & 1) ? (IO0_STATE |= (unsigned char)(0x01 << (bit)), IO1 = IO0_STATE) : (IO0_STATE &= ~(unsigned char)(0x01 << (bit)), IO1 = IO0_STATE))
