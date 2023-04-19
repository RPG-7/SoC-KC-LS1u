/**********************************************/
/*
/*	ch375键盘鼠标U盘驱动	2015-2022.10 龙少
/*
/**********************************************/

#include "ch375.h"
#include "delay.h"
#include "printf.h"

#define DEVICE_NUM			1		//CH375芯片数量
#define BUF_LEN				256		//USB数据缓冲区
#define KEY_VALUE_NUM		6		//键盘键值队列数量
#define MOUSE_INIT_X		160		//鼠标X坐标初始值
#define MOUSE_INIT_Y		120		//鼠标Y坐标初始值
#define MOUSE_INIT_WHEEL	0		//鼠标滚轮初始值
#define MOUSE_MAX_X			319		//鼠标X坐标最大值
#define MOUSE_MAX_Y			239		//鼠标Y坐标最大值
#define MOUSE_MAX_WHEEL		255		//鼠标滚轮最大值

#define ABORT_NAK_DELAY		32		//放弃NAK重试命令延时
#define USB_IN_DELAY		128		//中断传输IN命令延时

/* 等待中断 */
#define CH375_HOLD_INT(device) while (CH375_GET_INT(device) == (unsigned char)1)

/* 执行IN事务, Syncflag同步标志, Endpoint端点号 */
#define CH375_USB_IN(device, Syncflag, Endpoint) ISSUE_TKN_X(device, Syncflag, Endpoint, 0x09)

/* 执行OUT事务, Syncflag同步标志, Endpoint端点号 */
#define CH375_USB_OUT(device, Syncflag, Endpoint) ISSUE_TKN_X(device, Syncflag, Endpoint, 0x01)

static unsigned char		DataBuf[BUF_LEN];					//数据缓冲区

static unsigned char		CH375_Flag[DEVICE_NUM];				//设备标志,如果设备存在,标志为1,否则为0
static unsigned char		CH375_Ver[DEVICE_NUM];				//CH375芯片版本号

unsigned char				USB_Device_Code[DEVICE_NUM];		//USB设备代码
static unsigned long long	USB_Flash_Disk_Size[DEVICE_NUM];	//USB存储器容量(Byte)
static unsigned char		USB_Key_Endpoint[DEVICE_NUM];		//键盘端点号
static unsigned char		USB_Mouse_Endpoint[DEVICE_NUM];		//鼠标端点号
static unsigned char		USB_Key_Interface[DEVICE_NUM];		//键盘接口号
static unsigned char		USB_Mouse_Interface[DEVICE_NUM];	//鼠标接口号
static unsigned short		USB_Key_Report_Len[DEVICE_NUM];		//键盘报告描述符长度
static unsigned short		USB_Mouse_Report_Len[DEVICE_NUM];	//鼠标报告描述符长度
static unsigned short		USB_Key_PacketSize[DEVICE_NUM];		//键盘端点数据包大小
static unsigned short		USB_Mouse_PacketSize[DEVICE_NUM];	//鼠标端点数据包大小
static unsigned char		USB_Current_Endpoint[DEVICE_NUM];	//当前操作的端点号
static unsigned char		USB_Sync[DEVICE_NUM];				//同步触发控制

static unsigned char		Key_Leftcontrol_RightGUI_StartBit[DEVICE_NUM];	//键盘Left control和Right GUI位起始地址
static unsigned char		Key_Leftcontrol_RightGUI_BitWidth[DEVICE_NUM];	//键盘Left control和Right GUI位宽
static unsigned char		Key_Value_StartBit[DEVICE_NUM][KEY_VALUE_NUM];				//键盘键值位起始地址
static unsigned char		Key_Value_BitWidth[DEVICE_NUM][KEY_VALUE_NUM];				//键盘键值位宽

static unsigned char		Mouse_Button_StartBit[DEVICE_NUM];	//鼠标Button位起始地址
static unsigned char		Mouse_Button_BitWidth[DEVICE_NUM];	//鼠标Button位宽
static unsigned char		Mouse_X_StartBit[DEVICE_NUM];		//鼠标X坐标位起始地址
static unsigned char		Mouse_X_BitWidth[DEVICE_NUM];		//鼠标X坐标位宽
static unsigned char		Mouse_Y_StartBit[DEVICE_NUM];		//鼠标Y坐标位起始地址
static unsigned char		Mouse_Y_BitWidth[DEVICE_NUM];		//鼠标Y坐标位宽
static unsigned char		Mouse_Wheel_StartBit[DEVICE_NUM];	//鼠标滚轮位起始地址
static unsigned char		Mouse_Wheel_BitWidth[DEVICE_NUM];	//鼠标滚轮位宽

unsigned char				Key_Value[KEY_VALUE_NUM + 1] = {0,0,0,0,0,0,0};	//键盘键值, 字节0为LeftControl和RightGUI, 字节1-6为键值
unsigned char				Mouse_Button = 0;								//鼠标按钮
unsigned short				Mouse_X = MOUSE_INIT_X;							//鼠标X坐标数据
unsigned short				Mouse_Y = MOUSE_INIT_Y;							//鼠标Y坐标数据
unsigned short				Mouse_Wheel = MOUSE_INIT_WHEEL;					//鼠标滚轮数据


/* 获取芯片及固件版本, device选择设备 */
unsigned char CH375_GET_IC_VER(unsigned char device) {
	unsigned char ver;

	CH375_WR_COMDREG(device, 0x01); //获取版本号命令
	CH375_DATA = 0xff;
	CH375_RD_DATAREG(device, ver); //读数据
	return ver;
}

/* 执行硬件复位, device选择设备 */
void CH375_RESET_ALL(unsigned char device) {
	CH375_WR_COMDREG(device, 0x05); //写命令
	Delay(128000); //等40毫秒以上
}

/* 按位取反, 测试工作状态, device选择设备, indata为输入数据 */
unsigned char CH375_CHECK_EXIST(unsigned char device, unsigned char indata) {
	unsigned char outdata;

	CH375_WR_COMDREG(device, 0x06); //写命令
	CH375_WR_DATAREG(device, indata); //写数据
	CH375_DATA = 0xff;
	CH375_RD_DATAREG(device, outdata); //读数据
	return outdata;
}

/********************************************************************/
/*	mode = 0x00,	未启用的 USB 设备方式（上电或复位后的默认方式）	*/
/*	mode = 0x01,	已启用的 USB 设备方式，外部固件模式				*/
/*	mode = 0x02,	已启用的 USB 设备方式，内置固件模式				*/
/*	mode = 0x04,	未启用的 USB 主机方式							*/
/*	mode = 0x05,	已启用的 USB 主机方式，不产生 SOF 包			*/
/*	mode = 0x06,	已启用的 USB 主机方式，自动产生 SOF 包			*/
/*	mode = 0x07,	已启用的 USB 主机方式，复位 USB 总线			*/
/********************************************************************/

/* 设置USB工作模式,device选择设备,mode模式代码上表所示 */
void CH375_SET_USB_MODE(unsigned char device, unsigned char mode) {
	CH375_WR_COMDREG(device, 0x15); //写命令
	CH375_WR_DATAREG(device, mode); //写数据
	Delay(128000);
}

/* 获取CH375中断状态码,device选择设备,返回值为中断状态码( 0x14:USB事务或者传输操作成功, 0x15:检测到USB设备连接事件, 0x16:检测到USB设备断开事件) */
unsigned char CH375_GET_STATUS(unsigned char device) {
	unsigned char code;

	CH375_WR_COMDREG(device, 0x22); //发送获取中断码命令
	CH375_DATA = 0xff;
	Delay(0);
	CH375_RD_DATAREG(device, code); //读中断码
	return code;
}

/* 初始化CH375 */
void CH375_Init() {
	unsigned char i;

	IO0_INIT;
	for (i = 0; i < (unsigned char)DEVICE_NUM; ++i) {
		CH375_Flag[i] = 0;
		USB_Device_Code[i] = 0;
		CH375_RESET_ALL(i); //CH375执行硬件复位

		//检测CH375存在?
		if (CH375_CHECK_EXIST(i, 0xaa) == (unsigned char)0x55 && CH375_CHECK_EXIST(i, 0x55) == (unsigned char)0xaa) {
			CH375_Ver[i] = CH375_GET_IC_VER(i) & (unsigned char)0x3f; //获取版本号命令
			CH375_Flag[i] = 1; //标志CH375设备存在
			CH375_SET_USB_MODE(i, 0x05); //设置为主机模式
		}
	}
}

/* 放弃当前NAK的重试,device选择设备 */
void CH375_ABORT_NAK(unsigned char device) {
	CH375_WR_COMDREG(device, 0x17); //写命令
}

/* 从当前USB中断的端点缓冲区读取数据块,device选择设备,buf为缓冲区地址,返回值为数据长度 */
unsigned char CH375_RD_USB_DATA0(unsigned char device, unsigned char* buf) {
	unsigned char len; //记录CH375缓冲区数据长度
	unsigned char i;	//计数

	CH375_WR_COMDREG(device, 0x27); //发送读缓冲区命令
	CH375_DATA = 0xff;
	Delay(0);
	CH375_RD_DATAREG(device, len); //读出缓冲区数据长度
	for (i = 0; i != len; ++i) {
		CH375_RD_DATAREG(device, buf[i]);
	}
	return len;
}

/* 向USB主机端点的输出缓冲区写入数据块,device选择设备,len为写入数据长度,buf为缓冲区地址 */
void CH375_WR_USB_DATA7(unsigned char device, unsigned char len, unsigned char* buf) {
	unsigned char i; //计数

	CH375_WR_COMDREG(device, 0x2b); //发送写缓冲区命令
	CH375_WR_DATAREG(device, len); //写入数据长度
	for (i = 0; i != len; ++i) {
		CH375_WR_DATAREG(device, buf[i]);
	}
}

/* 发出同步令牌，执行事务, device选择设备, Syncflag同步标志, Endpoint端点号, PID事务令牌(0x01对应OUT事务,0x09对应IN事务,0x0d对应SETUP事务) */
void ISSUE_TKN_X(unsigned char device, unsigned char Syncflag, unsigned char Endpoint, unsigned char PID) {
	CH375_WR_COMDREG(device, 0x4e); //发送执行事务命令
	if (PID == (unsigned char)0x09)
		Syncflag <<= 7;
	else
		Syncflag = (Syncflag & (unsigned char)0x01) << 6;
	CH375_WR_DATAREG(device, Syncflag); //同步标志
	CH375_WR_DATAREG(device, (Endpoint << 4) | (PID & (unsigned char)0x0f)); //高4位端点 低4位事务属性
}

/* 端点0执行8字节SETUP事务, device选择设备, d0~d7为8字节数据, 返回非0操作成功*/
unsigned char CH375_USB_SETUP(unsigned char device, unsigned char d0, unsigned char d1, unsigned char d2, unsigned char d3, unsigned char d4, unsigned char d5, unsigned char d6, unsigned char d7) {
	CH375_WR_COMDREG(device, 0x2b); //发送写缓冲区命令
	CH375_WR_DATAREG(device, 8); //长度8字节
	CH375_WR_DATAREG(device, d0);
	CH375_WR_DATAREG(device, d1);
	CH375_WR_DATAREG(device, d2);
	CH375_WR_DATAREG(device, d3);
	CH375_WR_DATAREG(device, d4);
	CH375_WR_DATAREG(device, d5);
	CH375_WR_DATAREG(device, d6);
	CH375_WR_DATAREG(device, d7);
	ISSUE_TKN_X(device, 0, 0, 0x0d);
	CH375_HOLD_INT(device); //等待中断
	if (CH375_GET_STATUS(device) == (unsigned char)0x14)
		return 1;
	return 0;
}

/* 设置USB总线速度,device选择设备,speed为速度(00H对应12Mbps全速模式,01H对应1.5Mbps全速模式(非标准模式),02H对应1.5Mbps低速模式) */
void CH375_SET_USB_SPEED(unsigned char device, unsigned char speed) {
	CH375_WR_COMDREG(device, 0x04); //发送设置USB总线速度命令
	CH375_WR_DATAREG(device, speed);
}

/* 获取USB设备速率,device选择设备 */
unsigned char CH375_GET_DEV_RATE(unsigned char device) {
	unsigned char speed;

	CH375_WR_COMDREG(device, 0x0a); //发送获取USB设备速率命令
	CH375_WR_DATAREG(device, 0x07);
	CH375_DATA = 0xff;
	CH375_RD_DATAREG(device, speed);
	return speed;
}

/* 获取描述符, device选择设备, code为描述符代码(1:设备描述符, 2:配置描述符), 返回非0操作成功 */
unsigned char CH375_GET_EDSCR(unsigned char device, unsigned char code) {
	CH375_WR_COMDREG(device, 0x46);
	CH375_WR_DATAREG(device, code);
	CH375_HOLD_INT(device); //等待中断
	if (CH375_GET_STATUS(device) == (unsigned char)0x14)
		return 1;
	return 0;
}

/* 从USB存储器设备读取数据块命令, device选择设备,SQH是扇区号,LBAX是读取扇区个数,返回值不为0表示操作成功 */
unsigned char CH375_DISK_READ(unsigned char device, unsigned long int SQH, unsigned char LBAX) {
	CH375_WR_COMDREG(device, 0x54); //写命令
	CH375_WR_DATAREG(device, ((unsigned char*)&SQH)[0]); //写扇区地址
	CH375_WR_DATAREG(device, ((unsigned char*)&SQH)[1]);
	CH375_WR_DATAREG(device, ((unsigned char*)&SQH)[2]);
	CH375_WR_DATAREG(device, ((unsigned char*)&SQH)[3]);
	CH375_WR_DATAREG(device, LBAX); //写读取扇区数
	CH375_HOLD_INT(device); //等待中断
	//读成功
	if (CH375_GET_STATUS(device) == (unsigned char)0x1d)
		return 1;
	return 0;
}

/* 继续读USB存储器设备数据块命令,device选择设备,返回值不为0表示操作成功 */
unsigned char CH375_DISK_RD_GO(unsigned char device) {
	unsigned char i;

	CH375_WR_COMDREG(device, 0x55); //写命令
	CH375_HOLD_INT(device); //等中断
	i = CH375_GET_STATUS(device); //获取中断状态码到i
	//读成功
	if (i == (unsigned char)0x1d || i == (unsigned char)0x14)
		return 1;
	return 0;
}

/* 写数据块到USB存储器设备命令, device选择设备,SQH是扇区号,LBAX是写取扇区个数,返回值不为0表示操作成功 */
unsigned char CH375_DISK_WRITE(unsigned char device, unsigned long int SQH, unsigned char LBAX) {
	CH375_WR_COMDREG(device, 0x56); //写命令
	CH375_WR_DATAREG(device, ((unsigned char*)&SQH)[0]); //写扇区地址
	CH375_WR_DATAREG(device, ((unsigned char*)&SQH)[1]);
	CH375_WR_DATAREG(device, ((unsigned char*)&SQH)[2]);
	CH375_WR_DATAREG(device, ((unsigned char*)&SQH)[3]);
	CH375_WR_DATAREG(device, LBAX); //写读取扇区数
	CH375_HOLD_INT(device); //等中断
	//写成功
	if (CH375_GET_STATUS(device) == (unsigned char)0x1e)
		return 1;
	return 0;
}

/* 继续写USB存储器设备数据块命令,device选择设备,返回值不为0表示操作成功 */
unsigned char CH375_DISK_WR_GO(unsigned char device) {
	unsigned char i;

	CH375_WR_COMDREG(device, 0x57); //写命令
	CH375_HOLD_INT(device); //等中断
	i = CH375_GET_STATUS(device); //获取中断状态码到i
	//写成功
	if (i == (unsigned char)0x1e || i == (unsigned char)0x14)
		return 1;
	return 0;
}

/* 初始化USB存储设备,成功返回非0 */
unsigned char CH375_DISK_INIT(device) {
	CH375_WR_COMDREG(device, 0x51); //初始化USB存储设备
	CH375_HOLD_INT(device); //等中断
	if (CH375_GET_STATUS(device) == (unsigned char)0x14)
		return 1;
	return 0;
}

/* 获取USB存储设备的容量,成功返回非0 */
unsigned char CH375_DISK_SIZE(device) {
	CH375_WR_COMDREG(device, 0x53); //获取USB存储设备容量
	CH375_HOLD_INT(device); //等中断
	if (CH375_GET_STATUS(device) == (unsigned char)0x14)
		return 1;
	return 0;
}

/* 初始化USB存储设备(带获取设备容量),成功返回非0 */
unsigned char USB_FLASH_DISK_INIT(unsigned char device) {
	unsigned long long Size;

	//测试初始化USB存储设备
	if(CH375_DISK_INIT(device) == (unsigned char)0)
		return 0;
	//获取USB存储设备容量
	if (CH375_DISK_SIZE(device) == (unsigned char)0)
		return 0;

	CH375_RD_USB_DATA0(device, DataBuf); //CH375缓冲区数据读入本机缓冲区

	//记录存储设备LBA数量,USB存储器扇区数-1,+1再乘512就是实际容量(单位字节)
	((unsigned char*)&Size)[0] = 0;
	((unsigned char*)&Size)[1] = DataBuf[3];
	((unsigned char*)&Size)[2] = DataBuf[2];
	((unsigned char*)&Size)[3] = DataBuf[1];
	((unsigned char*)&Size)[4] = DataBuf[0];
	((unsigned char*)&Size)[5] = 0;
	((unsigned char*)&Size)[6] = 0;
	((unsigned char*)&Size)[7] = 0;
	USB_Flash_Disk_Size[device] = (Size + 0x100) << 1;

	return 1;
}

/* 自动配置USB设备,device选择设备,成功返回非0 */
unsigned char CH375_AUTO_SETUP(unsigned char device) {
	CH375_WR_COMDREG(device, 0x4d);
	CH375_HOLD_INT(device); //等中断
	if (CH375_GET_STATUS(device) == (unsigned char)0x14)
		return 1;
	return 0;
}

/* 获取设备描述符,device选择设备,buf描述符数据缓冲区首地址,成功返回读取的字节数,否则返回0 */
unsigned char CH375_GET_DEVICE_DES(unsigned char device, unsigned char* buf) {
	//获取设备描述符
	if(CH375_GET_EDSCR(device, 1) == (unsigned char)0)
		return 0;
	return CH375_RD_USB_DATA0(device, buf); //读CH375的缓冲区数据到本机缓冲区
}

/* 获取配置描述符,device选择设备,buf缓冲区首地址,成功返回描述符长度,否则返回0 */
unsigned short CH375_GET_CONFIG_DES(unsigned char device, unsigned char* buf) {
	unsigned short size;
	unsigned short i;
	unsigned char sync;

	//获取配置描述符
	if (CH375_USB_SETUP(device, 0x80, 0x06, 0x00, 0x02, 0x00, 0x00, 0x09, 0x00) == (unsigned char)0)
		return 0;
	//执行IN事务,同步触发1端点0
	CH375_USB_IN(device, 1, 0);
	CH375_HOLD_INT(device); //等待中断
	if (CH375_GET_STATUS(device) != (unsigned char)0x14)
		return 0;
	CH375_RD_USB_DATA0(device, buf); //读CH375的缓冲区数据
	//限制大小
	if ((size = *(unsigned short*)&buf[2]) > BUF_LEN)
		size = BUF_LEN;
	CH375_WR_USB_DATA7(device, 0, buf); //回复0数据的包
	//执行OUT事务,同步触发1端点0
	CH375_USB_OUT(device, 1, 0);
	CH375_HOLD_INT(device); //等待中断
	if (CH375_GET_STATUS(device) != (unsigned char)0x14)
		return 0;
	//获取完整长度配置描述符
	if (CH375_USB_SETUP(device, 0x80, 0x06, 0x00, 0x02, 0x00, 0x00, size, size >> 8) == (unsigned char)0)
		return 0;
	i = 0;
	sync = 0;
	while (i < size) {
		//执行IN事务
		CH375_USB_IN(device, (sync = ~sync), 0);
		CH375_HOLD_INT(device); //等待中断
		if (CH375_GET_STATUS(device) != (unsigned char)0x14)
			return 0;
		i += CH375_RD_USB_DATA0(device, &buf[i]); //读CH375的缓冲区数据
	}
	CH375_WR_USB_DATA7(device, 0, buf); //回复0数据的包
	//执行OUT事务,同步触发1端点0
	CH375_USB_OUT(device, 1, 0);
	CH375_HOLD_INT(device); //等待中断
	if (CH375_GET_STATUS(device) != (unsigned char)0x14)
		return 0;
	return size;
}

/* 获取报告描述符,device选择设备,index为索引值,len为描述符长度,buf描述符数据缓冲区首地址,成功返回读取的字节数,否则返回0 */
unsigned char CH375_GET_RPT_DES(unsigned char device, unsigned short index, unsigned short len, unsigned char* buf) {
	unsigned short i;
	unsigned char sync;

	//限制大小
	if (len > BUF_LEN)
		len = BUF_LEN;
	//获取报告描述符
	if (CH375_USB_SETUP(device, 0x81, 0x06, 0x00, 0x22, index, index >> 8, len, len >> 8) == (unsigned char)0)
		return 0;
	i = 0;
	sync = 0;
	while (i < len) {
		//执行IN事务
		CH375_USB_IN(device, (sync = ~sync), 0);
		CH375_HOLD_INT(device); //等待中断
		if (CH375_GET_STATUS(device) != (unsigned char)0x14)
			return 0;
		i += CH375_RD_USB_DATA0(device, &buf[i]); //读CH375的缓冲区数据
	}
	CH375_WR_USB_DATA7(device, 0, buf); //回复0数据的包
	//执行OUT事务,同步触发1端点0
	CH375_USB_OUT(device, 1, 0);
	CH375_HOLD_INT(device); //等待中断
	if (CH375_GET_STATUS(device) != (unsigned char)0x14)
		return 0;
	return i;
}

/* 处理配置描述符,device选择设备,len配置描述符长度,buf配置描述符缓冲区 */
void UsbProcConfigDes(unsigned char device, unsigned short len, unsigned char* buf) {
	unsigned short ByteCount = 0;
	unsigned char EndpointCount = 0;
	unsigned char InterfaceNumber;
	unsigned char InterfaceProtocol = 0;
	unsigned char DescriptorType = 0;
	unsigned short DescriptorLength;
	unsigned short MaxPacketSize = 0;

	while (ByteCount < len) {
		unsigned char DesLen = buf[0];
		unsigned char DesType = buf[1];

		if(DesLen == (unsigned char)0)
			break;
		//接口描述符
		if (DesType == (unsigned char)0x04) {
			InterfaceNumber = buf[2];
			InterfaceProtocol = buf[7];
		}
		//HID描述符
		else if (DesType == (unsigned char)0x21) {
			DescriptorType = buf[6];
			DescriptorLength = *(unsigned short*)&buf[7];
		}
		//端点描述符
		else if (DesType == (unsigned char)0x05) {
			MaxPacketSize = *(unsigned short*)&buf[4];
			++EndpointCount;
		}
		//有接口协议并且HID是报告描述符并且端点数据包大小不为0
		if (InterfaceProtocol != (unsigned char)0 && DescriptorType == (unsigned char)0x22 && MaxPacketSize != (unsigned short)0) {
			//键盘
			if (InterfaceProtocol == (unsigned char)0x01) {
				//键盘不存在时记录
				if ((USB_Device_Code[device] & DEVICE_KEY) != DEVICE_KEY) {
					unsigned char i;

					USB_Key_Interface[device] = InterfaceNumber; //设备接口号
					USB_Key_Report_Len[device] = DescriptorLength; //键盘报告描述符长度
					USB_Key_PacketSize[device] = MaxPacketSize; //键盘端点最大数据包大小
					USB_Key_Endpoint[device] = EndpointCount; //键盘端点号
					USB_Device_Code[device] |= DEVICE_KEY; //设备代码
					for (i = 0; i < (unsigned char)KEY_VALUE_NUM; ++i) //清除位宽数据
						Key_Value_BitWidth[device][i] = 0;
					Key_Leftcontrol_RightGUI_BitWidth[device] = 0;
				}
			}
			//鼠标
			else if (InterfaceProtocol == (unsigned char)0x02) {
				//鼠标不存在时记录
				if ((USB_Device_Code[device] & DEVICE_MOUSE) != DEVICE_MOUSE) {
					USB_Mouse_Interface[device] = InterfaceNumber; //设备接口号
					USB_Mouse_Report_Len[device] = DescriptorLength; //鼠标报告描述符长度
					USB_Mouse_PacketSize[device] = MaxPacketSize; //鼠标端点最大数据包大小
					USB_Mouse_Endpoint[device] = EndpointCount; //鼠标端点号
					USB_Device_Code[device] |= DEVICE_MOUSE; //设备代码
					Mouse_Button_BitWidth[device] = 0; //清除位宽数据
					Mouse_X_BitWidth[device] = 0;
					Mouse_Y_BitWidth[device] = 0;
					Mouse_Wheel_BitWidth[device] = 0;
				}
			}
			InterfaceProtocol = 0;
			DescriptorType = 0;
			MaxPacketSize = 0;
		}
		ByteCount += DesLen;
		buf += DesLen;
	}
}

/* 处理报告描述符,成功返回非0,device选择设备,len为报告描述符长度,buf为报告描述符缓冲区 */
unsigned char UsbProcRptDes(unsigned char device, unsigned short len, unsigned char* buf) {
	unsigned short ByteCount = 0;
	unsigned char BitCount = 0;
	unsigned char UsagePage = 0;
	unsigned char Usage[3];
	unsigned char UsageCount = 0;
	unsigned char UsageMinimum = 0;
	unsigned char UsageMaximum = 0;
	long LogicalMinimum = 0;
	long LogicalMaximum = 0;
	unsigned char ReportCount = 0;
	unsigned char ReportSize = 0;
	unsigned char CollUsage[2];
	unsigned char CollCount = 0;
	unsigned char KeyValueNum = 0;
	
	while (ByteCount < len) {
		unsigned char Size = buf[0] & (unsigned char)0x03;
		unsigned char Type = buf[0] & (unsigned char)0xfc;
		long Data;

		if (Size == (unsigned char)1)
			Data = *(char*)&buf[1];
		else if (Size == (unsigned char)2)
			Data = *(short*)&buf[1];
		else if (Size == (unsigned char)3)
			Data = *(long*)&buf[1];
		//Usage Page 
		if (Type == (unsigned char)0x04) {
			UsagePage = Data;
		}
		//Usage
		else if (Type == (unsigned char)0x08) {
			if(UsageCount < (unsigned char)3)
				Usage[UsageCount++] = Data;
		}
		//Usage Minimum
		else if (Type == (unsigned char)0x18) {
			UsageMinimum = Data;
		}
		//Usage Maximum
		else if (Type == (unsigned char)0x28) {
			UsageMaximum = Data;
		}
		//Logical Minimum
		else if (Type == (unsigned char)0x14) {
			LogicalMinimum = Data;
		}
		//Logical Maximum
		else if (Type == (unsigned char)0x24) {
			LogicalMaximum = Data;
		}
		//Report Count
		else if (Type == (unsigned char)0x94) {
			ReportCount = Data;
		}
		//Report Size
		else if (Type == (unsigned char)0x74) {
			ReportSize = Data;
		}
		//Report ID
		else if (Type == (unsigned char)0x84) {
			BitCount += (unsigned char)8;
		}
		//Input
		else if (Type == (unsigned char)0x80) {
			//键盘
			if (CollUsage[0] == (unsigned char)0x06) {
				//处理Keyboard Left Control && Keyboard Right GUI
				if (UsagePage == (unsigned char)0x07 && UsageMinimum == (unsigned char)0xe0 && UsageMaximum == (unsigned char)0xe7 && \
					LogicalMinimum == 0 && LogicalMaximum == 1 && ReportSize == (unsigned char)1 && ReportCount == (unsigned char)8) {
					Key_Leftcontrol_RightGUI_StartBit[device] = BitCount;
					Key_Leftcontrol_RightGUI_BitWidth[device] = 8;
				}
				//处理键盘的其余键
				else if (UsagePage == (unsigned char)0x07 && UsageMinimum == (unsigned char)0x00 && UsageMaximum > (unsigned char)0x01 && \
					LogicalMinimum == 0 && LogicalMaximum > 1) {
					unsigned char i;
					unsigned char StartBit = BitCount;

					for (i = 0; i < ReportCount; ++i) {
						if (KeyValueNum == (unsigned char)KEY_VALUE_NUM) return 0;
						Key_Value_StartBit[device][KeyValueNum] = StartBit;
						Key_Value_BitWidth[device][KeyValueNum] = ReportSize;
						++KeyValueNum;
						StartBit += ReportSize;
					}
				}
			}
			//鼠标
			else if (CollUsage[0] == (unsigned char)0x02) {
				//Button
				if (UsagePage == (unsigned char)0x09 && UsageMinimum == (unsigned char)0x01 && UsageMaximum <= (unsigned char)0x08 && \
					LogicalMinimum == 0 && LogicalMaximum == 1 && ReportSize == (unsigned char)1 && ReportCount <= (unsigned char)8) {
					Mouse_Button_StartBit[device] = BitCount;
					Mouse_Button_BitWidth[device] = ReportSize * ReportCount;
				}
				//X, Y, Wheel
				else if (UsagePage == (unsigned char)0x01 && ReportSize <= (unsigned char)32 && ReportCount == UsageCount) {
					unsigned char i;
					unsigned char StartBit = BitCount;

					for (i = 0; i < UsageCount; ++i) {
						//X
						if (Usage[i] == (unsigned char)0x30) {
							Mouse_X_StartBit[device] = StartBit;
							Mouse_X_BitWidth[device] = ReportSize;
						}
						//Y
						else if (Usage[i] == (unsigned char)0x31) {
							Mouse_Y_StartBit[device] = StartBit;
							Mouse_Y_BitWidth[device] = ReportSize;
						}
						//Wheel
						else if (Usage[i] == (unsigned char)0x38) {
							Mouse_Wheel_StartBit[device] = StartBit;
							Mouse_Wheel_BitWidth[device] = ReportSize;
						}
						StartBit += ReportSize;
					}
				}
			}
			UsageMinimum = 0;
			UsageMaximum = 0;
			UsageCount = 0;
			BitCount += ReportSize * ReportCount;
		}
		//Output
		else if (Type == (unsigned char)0x90) {
			UsageMinimum = 0;
			UsageMaximum = 0;
			UsageCount = 0;
		}
		//Collection
		else if (Type == (unsigned char)0xa0) {
			if(CollCount == (unsigned char)2 || UsageCount == (unsigned char)0)
				return 0;
			CollUsage[CollCount++] = Usage[0];
			UsageCount = 0;
		}
		//End Collection
		else if (Type == (unsigned char)0xc0) {
			if (CollCount == (unsigned char)0) return 0;
			--CollCount;
		}

		ByteCount += Size + 1;
		buf += Size + 1;
	}
	if(CollCount == (unsigned char)0)
		return 1;
	return 0;
}

/* 位段提取,StartBit位起始地址,BitWidth位宽,buf缓冲区,返回值为提取的位段数据 */
short UsbBitExtract(unsigned char StartBit, unsigned char BitWidth, unsigned char* buf) {
	unsigned char ByteOffset = StartBit / (unsigned char)8;
	unsigned char BitOffset = StartBit % (unsigned char)8;
	unsigned long Data;

	if (BitWidth == (unsigned char)0 || BitWidth > (unsigned char)16)
		return 0;
	Data = *(unsigned long*)&buf[ByteOffset];
	Data >>= BitOffset;
	return (((short*)&Data)[0] << ((unsigned char)16 - BitWidth)) >> ((unsigned char)16 - BitWidth);
}

/* USB更新 */
unsigned char UsbUpdate() {
	unsigned char update;
	unsigned char device;

	update = 0;
	for (device = 0; device < (unsigned char)DEVICE_NUM; ++device) {
		//CH375标志有效并且有中断时进入
		if (CH375_Flag[device] == (unsigned char)1 && CH375_GET_INT(device) == (unsigned char)0) {
			unsigned char initcode;

			initcode = CH375_GET_STATUS(device); //获取CH375中断状态码
			//命令执行成功
			if (initcode == (unsigned char)0x14) {
				update = 1;
				//键盘端点的数据
				if ((USB_Device_Code[device] & DEVICE_KEY) != 0 && USB_Current_Endpoint[device] == USB_Key_Endpoint[device]) {
					unsigned char i;

					CH375_RD_USB_DATA0(device, DataBuf);
					Key_Value[0] = UsbBitExtract(Key_Leftcontrol_RightGUI_StartBit[device], Key_Leftcontrol_RightGUI_BitWidth[device], DataBuf);
					for(i = 0; i < (unsigned char)KEY_VALUE_NUM; ++i)
						Key_Value[i + (unsigned char)1] = UsbBitExtract(Key_Value_StartBit[device][i], Key_Value_BitWidth[device][i], DataBuf);
				}
				//鼠标端点的数据
				else if ((USB_Device_Code[device] & DEVICE_MOUSE) != 0 && USB_Current_Endpoint[device] == USB_Mouse_Endpoint[device]) {
					CH375_RD_USB_DATA0(device, DataBuf);
					Mouse_Button = (unsigned char)UsbBitExtract(Mouse_Button_StartBit[device], Mouse_Button_BitWidth[device], DataBuf) & ~((unsigned char)0xff << Mouse_Button_BitWidth[device]);
					Mouse_X += UsbBitExtract(Mouse_X_StartBit[device], Mouse_X_BitWidth[device], DataBuf);
					Mouse_Y += UsbBitExtract(Mouse_Y_StartBit[device], Mouse_Y_BitWidth[device], DataBuf);
					Mouse_Wheel += UsbBitExtract(Mouse_Wheel_StartBit[device], Mouse_Wheel_BitWidth[device], DataBuf);
					if (*(short*)&Mouse_X > (short)MOUSE_MAX_X)
						Mouse_X = MOUSE_MAX_X;
					else if (*(short*)&Mouse_X < (short)0)
						Mouse_X = 0;
					if (*(short*)&Mouse_Y > (short)MOUSE_MAX_Y)
						Mouse_Y = MOUSE_MAX_Y;
					else if (*(short*)&Mouse_Y < (short)0)
						Mouse_Y = 0;
					if (*(short*)&Mouse_Wheel > (short)MOUSE_MAX_WHEEL)
						Mouse_Wheel = MOUSE_MAX_WHEEL;
					else if (*(short*)&Mouse_Wheel < (short)0)
						Mouse_Wheel = 0;
				}
				USB_Sync[device] = ~USB_Sync[device];
			}
			//设备插入
			else if (initcode == (unsigned char)0x15) {
				unsigned char speed;

				speed = (CH375_GET_DEV_RATE(device) & (unsigned char)0x10) >> 3; //获取USB设备速率
				CH375_SET_USB_MODE(device, 0x07); //复位USB总线
				CH375_SET_USB_MODE(device, 0x06);  //设置为主机模式
				CH375_SET_USB_SPEED(device, speed); //设置USB总线速度
				//获取设备描述符
				if (CH375_GET_DEVICE_DES(device, DataBuf) != (unsigned char)0) {
					unsigned short len;
					//获取配置描述符
					if ((len = CH375_GET_CONFIG_DES(device, DataBuf)) != (unsigned char)0) {
						UsbProcConfigDes(device, len, DataBuf); //分析配置描述符
						//设备为键盘或鼠标
						if ((USB_Device_Code[device] & (DEVICE_KEY | DEVICE_MOUSE)) != (unsigned char)0) {
							//自动配置USB设备
							if (CH375_AUTO_SETUP(device) != (unsigned char)0) {
								//键盘
								if ((USB_Device_Code[device] & DEVICE_KEY) != (unsigned char)0) {
									//获取报告描述符分析报告描述符
									if (CH375_GET_RPT_DES(device, USB_Key_Interface[device], USB_Key_Report_Len[device], DataBuf) != (unsigned char)0 && \
										UsbProcRptDes(device, USB_Key_Report_Len[device], DataBuf) != 0)
										USB_Current_Endpoint[device] = USB_Key_Endpoint[device];
									else
										USB_Device_Code[device] = USB_Device_Code[device] & (unsigned char)~DEVICE_KEY; //键盘标志清0
								}
								//鼠标
								if ((USB_Device_Code[device] & DEVICE_MOUSE) != (unsigned char)0) {
									//获取报告描述符分析报告描述符
									if (CH375_GET_RPT_DES(device, USB_Mouse_Interface[device], USB_Mouse_Report_Len[device], DataBuf) != (unsigned char)0 && \
										UsbProcRptDes(device, USB_Mouse_Report_Len[device], DataBuf) != 0)
										USB_Current_Endpoint[device] = USB_Mouse_Endpoint[device];
									else
										USB_Device_Code[device] = USB_Device_Code[device] & (unsigned char)~DEVICE_MOUSE; //鼠标标志清0
								}
								USB_Sync[device] = 0;
							}
							else
								USB_Device_Code[device] = NO_DEVICE; //无设备
						}
						//初始化USB存储设备
						else if (USB_FLASH_DISK_INIT(device) != (unsigned char)0) {
							USB_Device_Code[device] |= DEVICE_FLASH_DISK; //置位设备代码, 存储设备
						}
					}
				}
			}
			//设备拔出
			else if (initcode == (unsigned char)0x16) {
				USB_Device_Code[device] = NO_DEVICE; //无设备
				CH375_SET_USB_MODE(device, 0x05); //05H主机方式不产生SOF包
			}
		}
		//有键盘鼠标设备
		if ((USB_Device_Code[device] & (DEVICE_KEY | DEVICE_MOUSE)) != (unsigned char)0) {
			//键盘鼠标同时存在
			if (USB_Device_Code[device] == (DEVICE_KEY | DEVICE_MOUSE)) {
				CH375_ABORT_NAK(device);
				Delay(ABORT_NAK_DELAY);
				//键盘鼠标端点号切换
				if (USB_Current_Endpoint[device] == USB_Key_Endpoint[device])
					USB_Current_Endpoint[device] = USB_Mouse_Endpoint[device];
				else
					USB_Current_Endpoint[device] = USB_Key_Endpoint[device];
			}
			CH375_USB_IN(device, USB_Sync[device], USB_Current_Endpoint[device]); //执行IN事务查询设备
			Delay(USB_IN_DELAY);
		}
	}
	return update;
}

/* USB存储器设备读扇区, device选择设备,sector起始扇区号,count读扇区的个数,buf缓冲区首地址,如果操作成功返回值不为0 */
unsigned char CH375_RD_LBA(unsigned char device, unsigned long sector, unsigned char count, unsigned char* buf) {
	unsigned char i = 0;

	//CH375芯片存在并且设备是存储器
	if (CH375_Flag[device] == (unsigned char)1 && (USB_Device_Code[device] & DEVICE_FLASH_DISK) != (unsigned char)0) {
		if (CH375_DISK_READ(device, sector, count) == 0) return 0; //发送读数据块到USB存储器设备命令,执行失败返回0
		do {
			if (CH375_RD_USB_DATA0(device, buf) != 64) return 0; //CH375缓冲区读出64字节到本机缓冲区,读出数据如果不是64字节返回0
			buf += 64;
			if (CH375_DISK_RD_GO(device) == 0) return 0; //发送继续读USB存储器设备数据块命令,执行失败返回0
		} while (++i >> 3 != count);
		return 1;
	}
	return 0;
}

/* USB存储器设备写扇区, device选择设备,sector起始扇区号,count读扇区的个数,buf为缓冲区首地址,如果操作成功返回值不为0 */
unsigned char CH375_WR_LBA(unsigned char device, unsigned long sector, unsigned char count, unsigned char* buf) {
	unsigned int i = 0;

	//CH375芯片存在并且设备是存储器
	if (CH375_Flag[device] == (unsigned char)1 && (USB_Device_Code[device] & DEVICE_FLASH_DISK) != (unsigned char)0) {
		if (CH375_DISK_WRITE(device, sector, count) == 0) return 0; //发送写数据块到USB存储器设备命令,执行失败返回0
		do {
			CH375_WR_USB_DATA7(device, 64, buf); //写64字节到CH375缓冲区
			buf += 64;
			if (CH375_DISK_WR_GO(device) == 0) return 0; //发送继续写USB存储器设备数据块命令,执行失败返回0
		} while (++i >> 3 != count);
		return 1;
	}
	return 0;
}

/* 键盘键值查询 */
unsigned char KeyQuery(unsigned char value) {
	unsigned char i = 1;

	while (i < (unsigned char)KEY_VALUE_NUM + 1 && Key_Value[i] != value) ++i;
	return i < (unsigned char)KEY_VALUE_NUM + 1 ? 1 : 0;
}
