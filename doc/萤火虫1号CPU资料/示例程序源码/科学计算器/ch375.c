/**********************************************/
/*
/*	ch375�������U������	2015-2022.10 ����
/*
/**********************************************/

#include "ch375.h"
#include "delay.h"
#include "printf.h"

#define DEVICE_NUM			1		//CH375оƬ����
#define BUF_LEN				256		//USB���ݻ�����
#define KEY_VALUE_NUM		6		//���̼�ֵ��������
#define MOUSE_INIT_X		160		//���X�����ʼֵ
#define MOUSE_INIT_Y		120		//���Y�����ʼֵ
#define MOUSE_INIT_WHEEL	0		//�����ֳ�ʼֵ
#define MOUSE_MAX_X			319		//���X�������ֵ
#define MOUSE_MAX_Y			239		//���Y�������ֵ
#define MOUSE_MAX_WHEEL		255		//���������ֵ

#define ABORT_NAK_DELAY		32		//����NAK����������ʱ
#define USB_IN_DELAY		128		//�жϴ���IN������ʱ

/* �ȴ��ж� */
#define CH375_HOLD_INT(device) while (CH375_GET_INT(device) == (unsigned char)1)

/* ִ��IN����, Syncflagͬ����־, Endpoint�˵�� */
#define CH375_USB_IN(device, Syncflag, Endpoint) ISSUE_TKN_X(device, Syncflag, Endpoint, 0x09)

/* ִ��OUT����, Syncflagͬ����־, Endpoint�˵�� */
#define CH375_USB_OUT(device, Syncflag, Endpoint) ISSUE_TKN_X(device, Syncflag, Endpoint, 0x01)

static unsigned char		DataBuf[BUF_LEN];					//���ݻ�����

static unsigned char		CH375_Flag[DEVICE_NUM];				//�豸��־,����豸����,��־Ϊ1,����Ϊ0
static unsigned char		CH375_Ver[DEVICE_NUM];				//CH375оƬ�汾��

unsigned char				USB_Device_Code[DEVICE_NUM];		//USB�豸����
static unsigned long long	USB_Flash_Disk_Size[DEVICE_NUM];	//USB�洢������(Byte)
static unsigned char		USB_Key_Endpoint[DEVICE_NUM];		//���̶˵��
static unsigned char		USB_Mouse_Endpoint[DEVICE_NUM];		//���˵��
static unsigned char		USB_Key_Interface[DEVICE_NUM];		//���̽ӿں�
static unsigned char		USB_Mouse_Interface[DEVICE_NUM];	//���ӿں�
static unsigned short		USB_Key_Report_Len[DEVICE_NUM];		//���̱�������������
static unsigned short		USB_Mouse_Report_Len[DEVICE_NUM];	//��걨������������
static unsigned short		USB_Key_PacketSize[DEVICE_NUM];		//���̶˵����ݰ���С
static unsigned short		USB_Mouse_PacketSize[DEVICE_NUM];	//���˵����ݰ���С
static unsigned char		USB_Current_Endpoint[DEVICE_NUM];	//��ǰ�����Ķ˵��
static unsigned char		USB_Sync[DEVICE_NUM];				//ͬ����������

static unsigned char		Key_Leftcontrol_RightGUI_StartBit[DEVICE_NUM];	//����Left control��Right GUIλ��ʼ��ַ
static unsigned char		Key_Leftcontrol_RightGUI_BitWidth[DEVICE_NUM];	//����Left control��Right GUIλ��
static unsigned char		Key_Value_StartBit[DEVICE_NUM][KEY_VALUE_NUM];				//���̼�ֵλ��ʼ��ַ
static unsigned char		Key_Value_BitWidth[DEVICE_NUM][KEY_VALUE_NUM];				//���̼�ֵλ��

static unsigned char		Mouse_Button_StartBit[DEVICE_NUM];	//���Buttonλ��ʼ��ַ
static unsigned char		Mouse_Button_BitWidth[DEVICE_NUM];	//���Buttonλ��
static unsigned char		Mouse_X_StartBit[DEVICE_NUM];		//���X����λ��ʼ��ַ
static unsigned char		Mouse_X_BitWidth[DEVICE_NUM];		//���X����λ��
static unsigned char		Mouse_Y_StartBit[DEVICE_NUM];		//���Y����λ��ʼ��ַ
static unsigned char		Mouse_Y_BitWidth[DEVICE_NUM];		//���Y����λ��
static unsigned char		Mouse_Wheel_StartBit[DEVICE_NUM];	//������λ��ʼ��ַ
static unsigned char		Mouse_Wheel_BitWidth[DEVICE_NUM];	//������λ��

unsigned char				Key_Value[KEY_VALUE_NUM + 1] = {0,0,0,0,0,0,0};	//���̼�ֵ, �ֽ�0ΪLeftControl��RightGUI, �ֽ�1-6Ϊ��ֵ
unsigned char				Mouse_Button = 0;								//��갴ť
unsigned short				Mouse_X = MOUSE_INIT_X;							//���X��������
unsigned short				Mouse_Y = MOUSE_INIT_Y;							//���Y��������
unsigned short				Mouse_Wheel = MOUSE_INIT_WHEEL;					//����������


/* ��ȡоƬ���̼��汾, deviceѡ���豸 */
unsigned char CH375_GET_IC_VER(unsigned char device) {
	unsigned char ver;

	CH375_WR_COMDREG(device, 0x01); //��ȡ�汾������
	CH375_DATA = 0xff;
	CH375_RD_DATAREG(device, ver); //������
	return ver;
}

/* ִ��Ӳ����λ, deviceѡ���豸 */
void CH375_RESET_ALL(unsigned char device) {
	CH375_WR_COMDREG(device, 0x05); //д����
	Delay(128000); //��40��������
}

/* ��λȡ��, ���Թ���״̬, deviceѡ���豸, indataΪ�������� */
unsigned char CH375_CHECK_EXIST(unsigned char device, unsigned char indata) {
	unsigned char outdata;

	CH375_WR_COMDREG(device, 0x06); //д����
	CH375_WR_DATAREG(device, indata); //д����
	CH375_DATA = 0xff;
	CH375_RD_DATAREG(device, outdata); //������
	return outdata;
}

/********************************************************************/
/*	mode = 0x00,	δ���õ� USB �豸��ʽ���ϵ��λ���Ĭ�Ϸ�ʽ��	*/
/*	mode = 0x01,	�����õ� USB �豸��ʽ���ⲿ�̼�ģʽ				*/
/*	mode = 0x02,	�����õ� USB �豸��ʽ�����ù̼�ģʽ				*/
/*	mode = 0x04,	δ���õ� USB ������ʽ							*/
/*	mode = 0x05,	�����õ� USB ������ʽ�������� SOF ��			*/
/*	mode = 0x06,	�����õ� USB ������ʽ���Զ����� SOF ��			*/
/*	mode = 0x07,	�����õ� USB ������ʽ����λ USB ����			*/
/********************************************************************/

/* ����USB����ģʽ,deviceѡ���豸,modeģʽ�����ϱ���ʾ */
void CH375_SET_USB_MODE(unsigned char device, unsigned char mode) {
	CH375_WR_COMDREG(device, 0x15); //д����
	CH375_WR_DATAREG(device, mode); //д����
	Delay(128000);
}

/* ��ȡCH375�ж�״̬��,deviceѡ���豸,����ֵΪ�ж�״̬��( 0x14:USB������ߴ�������ɹ�, 0x15:��⵽USB�豸�����¼�, 0x16:��⵽USB�豸�Ͽ��¼�) */
unsigned char CH375_GET_STATUS(unsigned char device) {
	unsigned char code;

	CH375_WR_COMDREG(device, 0x22); //���ͻ�ȡ�ж�������
	CH375_DATA = 0xff;
	Delay(0);
	CH375_RD_DATAREG(device, code); //���ж���
	return code;
}

/* ��ʼ��CH375 */
void CH375_Init() {
	unsigned char i;

	IO0_INIT;
	for (i = 0; i < (unsigned char)DEVICE_NUM; ++i) {
		CH375_Flag[i] = 0;
		USB_Device_Code[i] = 0;
		CH375_RESET_ALL(i); //CH375ִ��Ӳ����λ

		//���CH375����?
		if (CH375_CHECK_EXIST(i, 0xaa) == (unsigned char)0x55 && CH375_CHECK_EXIST(i, 0x55) == (unsigned char)0xaa) {
			CH375_Ver[i] = CH375_GET_IC_VER(i) & (unsigned char)0x3f; //��ȡ�汾������
			CH375_Flag[i] = 1; //��־CH375�豸����
			CH375_SET_USB_MODE(i, 0x05); //����Ϊ����ģʽ
		}
	}
}

/* ������ǰNAK������,deviceѡ���豸 */
void CH375_ABORT_NAK(unsigned char device) {
	CH375_WR_COMDREG(device, 0x17); //д����
}

/* �ӵ�ǰUSB�жϵĶ˵㻺������ȡ���ݿ�,deviceѡ���豸,bufΪ��������ַ,����ֵΪ���ݳ��� */
unsigned char CH375_RD_USB_DATA0(unsigned char device, unsigned char* buf) {
	unsigned char len; //��¼CH375���������ݳ���
	unsigned char i;	//����

	CH375_WR_COMDREG(device, 0x27); //���Ͷ�����������
	CH375_DATA = 0xff;
	Delay(0);
	CH375_RD_DATAREG(device, len); //�������������ݳ���
	for (i = 0; i != len; ++i) {
		CH375_RD_DATAREG(device, buf[i]);
	}
	return len;
}

/* ��USB�����˵�����������д�����ݿ�,deviceѡ���豸,lenΪд�����ݳ���,bufΪ��������ַ */
void CH375_WR_USB_DATA7(unsigned char device, unsigned char len, unsigned char* buf) {
	unsigned char i; //����

	CH375_WR_COMDREG(device, 0x2b); //����д����������
	CH375_WR_DATAREG(device, len); //д�����ݳ���
	for (i = 0; i != len; ++i) {
		CH375_WR_DATAREG(device, buf[i]);
	}
}

/* ����ͬ�����ƣ�ִ������, deviceѡ���豸, Syncflagͬ����־, Endpoint�˵��, PID��������(0x01��ӦOUT����,0x09��ӦIN����,0x0d��ӦSETUP����) */
void ISSUE_TKN_X(unsigned char device, unsigned char Syncflag, unsigned char Endpoint, unsigned char PID) {
	CH375_WR_COMDREG(device, 0x4e); //����ִ����������
	if (PID == (unsigned char)0x09)
		Syncflag <<= 7;
	else
		Syncflag = (Syncflag & (unsigned char)0x01) << 6;
	CH375_WR_DATAREG(device, Syncflag); //ͬ����־
	CH375_WR_DATAREG(device, (Endpoint << 4) | (PID & (unsigned char)0x0f)); //��4λ�˵� ��4λ��������
}

/* �˵�0ִ��8�ֽ�SETUP����, deviceѡ���豸, d0~d7Ϊ8�ֽ�����, ���ط�0�����ɹ�*/
unsigned char CH375_USB_SETUP(unsigned char device, unsigned char d0, unsigned char d1, unsigned char d2, unsigned char d3, unsigned char d4, unsigned char d5, unsigned char d6, unsigned char d7) {
	CH375_WR_COMDREG(device, 0x2b); //����д����������
	CH375_WR_DATAREG(device, 8); //����8�ֽ�
	CH375_WR_DATAREG(device, d0);
	CH375_WR_DATAREG(device, d1);
	CH375_WR_DATAREG(device, d2);
	CH375_WR_DATAREG(device, d3);
	CH375_WR_DATAREG(device, d4);
	CH375_WR_DATAREG(device, d5);
	CH375_WR_DATAREG(device, d6);
	CH375_WR_DATAREG(device, d7);
	ISSUE_TKN_X(device, 0, 0, 0x0d);
	CH375_HOLD_INT(device); //�ȴ��ж�
	if (CH375_GET_STATUS(device) == (unsigned char)0x14)
		return 1;
	return 0;
}

/* ����USB�����ٶ�,deviceѡ���豸,speedΪ�ٶ�(00H��Ӧ12Mbpsȫ��ģʽ,01H��Ӧ1.5Mbpsȫ��ģʽ(�Ǳ�׼ģʽ),02H��Ӧ1.5Mbps����ģʽ) */
void CH375_SET_USB_SPEED(unsigned char device, unsigned char speed) {
	CH375_WR_COMDREG(device, 0x04); //��������USB�����ٶ�����
	CH375_WR_DATAREG(device, speed);
}

/* ��ȡUSB�豸����,deviceѡ���豸 */
unsigned char CH375_GET_DEV_RATE(unsigned char device) {
	unsigned char speed;

	CH375_WR_COMDREG(device, 0x0a); //���ͻ�ȡUSB�豸��������
	CH375_WR_DATAREG(device, 0x07);
	CH375_DATA = 0xff;
	CH375_RD_DATAREG(device, speed);
	return speed;
}

/* ��ȡ������, deviceѡ���豸, codeΪ����������(1:�豸������, 2:����������), ���ط�0�����ɹ� */
unsigned char CH375_GET_EDSCR(unsigned char device, unsigned char code) {
	CH375_WR_COMDREG(device, 0x46);
	CH375_WR_DATAREG(device, code);
	CH375_HOLD_INT(device); //�ȴ��ж�
	if (CH375_GET_STATUS(device) == (unsigned char)0x14)
		return 1;
	return 0;
}

/* ��USB�洢���豸��ȡ���ݿ�����, deviceѡ���豸,SQH��������,LBAX�Ƕ�ȡ��������,����ֵ��Ϊ0��ʾ�����ɹ� */
unsigned char CH375_DISK_READ(unsigned char device, unsigned long int SQH, unsigned char LBAX) {
	CH375_WR_COMDREG(device, 0x54); //д����
	CH375_WR_DATAREG(device, ((unsigned char*)&SQH)[0]); //д������ַ
	CH375_WR_DATAREG(device, ((unsigned char*)&SQH)[1]);
	CH375_WR_DATAREG(device, ((unsigned char*)&SQH)[2]);
	CH375_WR_DATAREG(device, ((unsigned char*)&SQH)[3]);
	CH375_WR_DATAREG(device, LBAX); //д��ȡ������
	CH375_HOLD_INT(device); //�ȴ��ж�
	//���ɹ�
	if (CH375_GET_STATUS(device) == (unsigned char)0x1d)
		return 1;
	return 0;
}

/* ������USB�洢���豸���ݿ�����,deviceѡ���豸,����ֵ��Ϊ0��ʾ�����ɹ� */
unsigned char CH375_DISK_RD_GO(unsigned char device) {
	unsigned char i;

	CH375_WR_COMDREG(device, 0x55); //д����
	CH375_HOLD_INT(device); //���ж�
	i = CH375_GET_STATUS(device); //��ȡ�ж�״̬�뵽i
	//���ɹ�
	if (i == (unsigned char)0x1d || i == (unsigned char)0x14)
		return 1;
	return 0;
}

/* д���ݿ鵽USB�洢���豸����, deviceѡ���豸,SQH��������,LBAX��дȡ��������,����ֵ��Ϊ0��ʾ�����ɹ� */
unsigned char CH375_DISK_WRITE(unsigned char device, unsigned long int SQH, unsigned char LBAX) {
	CH375_WR_COMDREG(device, 0x56); //д����
	CH375_WR_DATAREG(device, ((unsigned char*)&SQH)[0]); //д������ַ
	CH375_WR_DATAREG(device, ((unsigned char*)&SQH)[1]);
	CH375_WR_DATAREG(device, ((unsigned char*)&SQH)[2]);
	CH375_WR_DATAREG(device, ((unsigned char*)&SQH)[3]);
	CH375_WR_DATAREG(device, LBAX); //д��ȡ������
	CH375_HOLD_INT(device); //���ж�
	//д�ɹ�
	if (CH375_GET_STATUS(device) == (unsigned char)0x1e)
		return 1;
	return 0;
}

/* ����дUSB�洢���豸���ݿ�����,deviceѡ���豸,����ֵ��Ϊ0��ʾ�����ɹ� */
unsigned char CH375_DISK_WR_GO(unsigned char device) {
	unsigned char i;

	CH375_WR_COMDREG(device, 0x57); //д����
	CH375_HOLD_INT(device); //���ж�
	i = CH375_GET_STATUS(device); //��ȡ�ж�״̬�뵽i
	//д�ɹ�
	if (i == (unsigned char)0x1e || i == (unsigned char)0x14)
		return 1;
	return 0;
}

/* ��ʼ��USB�洢�豸,�ɹ����ط�0 */
unsigned char CH375_DISK_INIT(device) {
	CH375_WR_COMDREG(device, 0x51); //��ʼ��USB�洢�豸
	CH375_HOLD_INT(device); //���ж�
	if (CH375_GET_STATUS(device) == (unsigned char)0x14)
		return 1;
	return 0;
}

/* ��ȡUSB�洢�豸������,�ɹ����ط�0 */
unsigned char CH375_DISK_SIZE(device) {
	CH375_WR_COMDREG(device, 0x53); //��ȡUSB�洢�豸����
	CH375_HOLD_INT(device); //���ж�
	if (CH375_GET_STATUS(device) == (unsigned char)0x14)
		return 1;
	return 0;
}

/* ��ʼ��USB�洢�豸(����ȡ�豸����),�ɹ����ط�0 */
unsigned char USB_FLASH_DISK_INIT(unsigned char device) {
	unsigned long long Size;

	//���Գ�ʼ��USB�洢�豸
	if(CH375_DISK_INIT(device) == (unsigned char)0)
		return 0;
	//��ȡUSB�洢�豸����
	if (CH375_DISK_SIZE(device) == (unsigned char)0)
		return 0;

	CH375_RD_USB_DATA0(device, DataBuf); //CH375���������ݶ��뱾��������

	//��¼�洢�豸LBA����,USB�洢��������-1,+1�ٳ�512����ʵ������(��λ�ֽ�)
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

/* �Զ�����USB�豸,deviceѡ���豸,�ɹ����ط�0 */
unsigned char CH375_AUTO_SETUP(unsigned char device) {
	CH375_WR_COMDREG(device, 0x4d);
	CH375_HOLD_INT(device); //���ж�
	if (CH375_GET_STATUS(device) == (unsigned char)0x14)
		return 1;
	return 0;
}

/* ��ȡ�豸������,deviceѡ���豸,buf���������ݻ������׵�ַ,�ɹ����ض�ȡ���ֽ���,���򷵻�0 */
unsigned char CH375_GET_DEVICE_DES(unsigned char device, unsigned char* buf) {
	//��ȡ�豸������
	if(CH375_GET_EDSCR(device, 1) == (unsigned char)0)
		return 0;
	return CH375_RD_USB_DATA0(device, buf); //��CH375�Ļ��������ݵ�����������
}

/* ��ȡ����������,deviceѡ���豸,buf�������׵�ַ,�ɹ���������������,���򷵻�0 */
unsigned short CH375_GET_CONFIG_DES(unsigned char device, unsigned char* buf) {
	unsigned short size;
	unsigned short i;
	unsigned char sync;

	//��ȡ����������
	if (CH375_USB_SETUP(device, 0x80, 0x06, 0x00, 0x02, 0x00, 0x00, 0x09, 0x00) == (unsigned char)0)
		return 0;
	//ִ��IN����,ͬ������1�˵�0
	CH375_USB_IN(device, 1, 0);
	CH375_HOLD_INT(device); //�ȴ��ж�
	if (CH375_GET_STATUS(device) != (unsigned char)0x14)
		return 0;
	CH375_RD_USB_DATA0(device, buf); //��CH375�Ļ���������
	//���ƴ�С
	if ((size = *(unsigned short*)&buf[2]) > BUF_LEN)
		size = BUF_LEN;
	CH375_WR_USB_DATA7(device, 0, buf); //�ظ�0���ݵİ�
	//ִ��OUT����,ͬ������1�˵�0
	CH375_USB_OUT(device, 1, 0);
	CH375_HOLD_INT(device); //�ȴ��ж�
	if (CH375_GET_STATUS(device) != (unsigned char)0x14)
		return 0;
	//��ȡ������������������
	if (CH375_USB_SETUP(device, 0x80, 0x06, 0x00, 0x02, 0x00, 0x00, size, size >> 8) == (unsigned char)0)
		return 0;
	i = 0;
	sync = 0;
	while (i < size) {
		//ִ��IN����
		CH375_USB_IN(device, (sync = ~sync), 0);
		CH375_HOLD_INT(device); //�ȴ��ж�
		if (CH375_GET_STATUS(device) != (unsigned char)0x14)
			return 0;
		i += CH375_RD_USB_DATA0(device, &buf[i]); //��CH375�Ļ���������
	}
	CH375_WR_USB_DATA7(device, 0, buf); //�ظ�0���ݵİ�
	//ִ��OUT����,ͬ������1�˵�0
	CH375_USB_OUT(device, 1, 0);
	CH375_HOLD_INT(device); //�ȴ��ж�
	if (CH375_GET_STATUS(device) != (unsigned char)0x14)
		return 0;
	return size;
}

/* ��ȡ����������,deviceѡ���豸,indexΪ����ֵ,lenΪ����������,buf���������ݻ������׵�ַ,�ɹ����ض�ȡ���ֽ���,���򷵻�0 */
unsigned char CH375_GET_RPT_DES(unsigned char device, unsigned short index, unsigned short len, unsigned char* buf) {
	unsigned short i;
	unsigned char sync;

	//���ƴ�С
	if (len > BUF_LEN)
		len = BUF_LEN;
	//��ȡ����������
	if (CH375_USB_SETUP(device, 0x81, 0x06, 0x00, 0x22, index, index >> 8, len, len >> 8) == (unsigned char)0)
		return 0;
	i = 0;
	sync = 0;
	while (i < len) {
		//ִ��IN����
		CH375_USB_IN(device, (sync = ~sync), 0);
		CH375_HOLD_INT(device); //�ȴ��ж�
		if (CH375_GET_STATUS(device) != (unsigned char)0x14)
			return 0;
		i += CH375_RD_USB_DATA0(device, &buf[i]); //��CH375�Ļ���������
	}
	CH375_WR_USB_DATA7(device, 0, buf); //�ظ�0���ݵİ�
	//ִ��OUT����,ͬ������1�˵�0
	CH375_USB_OUT(device, 1, 0);
	CH375_HOLD_INT(device); //�ȴ��ж�
	if (CH375_GET_STATUS(device) != (unsigned char)0x14)
		return 0;
	return i;
}

/* ��������������,deviceѡ���豸,len��������������,buf���������������� */
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
		//�ӿ�������
		if (DesType == (unsigned char)0x04) {
			InterfaceNumber = buf[2];
			InterfaceProtocol = buf[7];
		}
		//HID������
		else if (DesType == (unsigned char)0x21) {
			DescriptorType = buf[6];
			DescriptorLength = *(unsigned short*)&buf[7];
		}
		//�˵�������
		else if (DesType == (unsigned char)0x05) {
			MaxPacketSize = *(unsigned short*)&buf[4];
			++EndpointCount;
		}
		//�нӿ�Э�鲢��HID�Ǳ������������Ҷ˵����ݰ���С��Ϊ0
		if (InterfaceProtocol != (unsigned char)0 && DescriptorType == (unsigned char)0x22 && MaxPacketSize != (unsigned short)0) {
			//����
			if (InterfaceProtocol == (unsigned char)0x01) {
				//���̲�����ʱ��¼
				if ((USB_Device_Code[device] & DEVICE_KEY) != DEVICE_KEY) {
					unsigned char i;

					USB_Key_Interface[device] = InterfaceNumber; //�豸�ӿں�
					USB_Key_Report_Len[device] = DescriptorLength; //���̱�������������
					USB_Key_PacketSize[device] = MaxPacketSize; //���̶˵�������ݰ���С
					USB_Key_Endpoint[device] = EndpointCount; //���̶˵��
					USB_Device_Code[device] |= DEVICE_KEY; //�豸����
					for (i = 0; i < (unsigned char)KEY_VALUE_NUM; ++i) //���λ������
						Key_Value_BitWidth[device][i] = 0;
					Key_Leftcontrol_RightGUI_BitWidth[device] = 0;
				}
			}
			//���
			else if (InterfaceProtocol == (unsigned char)0x02) {
				//��겻����ʱ��¼
				if ((USB_Device_Code[device] & DEVICE_MOUSE) != DEVICE_MOUSE) {
					USB_Mouse_Interface[device] = InterfaceNumber; //�豸�ӿں�
					USB_Mouse_Report_Len[device] = DescriptorLength; //��걨������������
					USB_Mouse_PacketSize[device] = MaxPacketSize; //���˵�������ݰ���С
					USB_Mouse_Endpoint[device] = EndpointCount; //���˵��
					USB_Device_Code[device] |= DEVICE_MOUSE; //�豸����
					Mouse_Button_BitWidth[device] = 0; //���λ������
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

/* ������������,�ɹ����ط�0,deviceѡ���豸,lenΪ��������������,bufΪ���������������� */
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
			//����
			if (CollUsage[0] == (unsigned char)0x06) {
				//����Keyboard Left Control && Keyboard Right GUI
				if (UsagePage == (unsigned char)0x07 && UsageMinimum == (unsigned char)0xe0 && UsageMaximum == (unsigned char)0xe7 && \
					LogicalMinimum == 0 && LogicalMaximum == 1 && ReportSize == (unsigned char)1 && ReportCount == (unsigned char)8) {
					Key_Leftcontrol_RightGUI_StartBit[device] = BitCount;
					Key_Leftcontrol_RightGUI_BitWidth[device] = 8;
				}
				//������̵������
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
			//���
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

/* λ����ȡ,StartBitλ��ʼ��ַ,BitWidthλ��,buf������,����ֵΪ��ȡ��λ������ */
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

/* USB���� */
unsigned char UsbUpdate() {
	unsigned char update;
	unsigned char device;

	update = 0;
	for (device = 0; device < (unsigned char)DEVICE_NUM; ++device) {
		//CH375��־��Ч�������ж�ʱ����
		if (CH375_Flag[device] == (unsigned char)1 && CH375_GET_INT(device) == (unsigned char)0) {
			unsigned char initcode;

			initcode = CH375_GET_STATUS(device); //��ȡCH375�ж�״̬��
			//����ִ�гɹ�
			if (initcode == (unsigned char)0x14) {
				update = 1;
				//���̶˵������
				if ((USB_Device_Code[device] & DEVICE_KEY) != 0 && USB_Current_Endpoint[device] == USB_Key_Endpoint[device]) {
					unsigned char i;

					CH375_RD_USB_DATA0(device, DataBuf);
					Key_Value[0] = UsbBitExtract(Key_Leftcontrol_RightGUI_StartBit[device], Key_Leftcontrol_RightGUI_BitWidth[device], DataBuf);
					for(i = 0; i < (unsigned char)KEY_VALUE_NUM; ++i)
						Key_Value[i + (unsigned char)1] = UsbBitExtract(Key_Value_StartBit[device][i], Key_Value_BitWidth[device][i], DataBuf);
				}
				//���˵������
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
			//�豸����
			else if (initcode == (unsigned char)0x15) {
				unsigned char speed;

				speed = (CH375_GET_DEV_RATE(device) & (unsigned char)0x10) >> 3; //��ȡUSB�豸����
				CH375_SET_USB_MODE(device, 0x07); //��λUSB����
				CH375_SET_USB_MODE(device, 0x06);  //����Ϊ����ģʽ
				CH375_SET_USB_SPEED(device, speed); //����USB�����ٶ�
				//��ȡ�豸������
				if (CH375_GET_DEVICE_DES(device, DataBuf) != (unsigned char)0) {
					unsigned short len;
					//��ȡ����������
					if ((len = CH375_GET_CONFIG_DES(device, DataBuf)) != (unsigned char)0) {
						UsbProcConfigDes(device, len, DataBuf); //��������������
						//�豸Ϊ���̻����
						if ((USB_Device_Code[device] & (DEVICE_KEY | DEVICE_MOUSE)) != (unsigned char)0) {
							//�Զ�����USB�豸
							if (CH375_AUTO_SETUP(device) != (unsigned char)0) {
								//����
								if ((USB_Device_Code[device] & DEVICE_KEY) != (unsigned char)0) {
									//��ȡ������������������������
									if (CH375_GET_RPT_DES(device, USB_Key_Interface[device], USB_Key_Report_Len[device], DataBuf) != (unsigned char)0 && \
										UsbProcRptDes(device, USB_Key_Report_Len[device], DataBuf) != 0)
										USB_Current_Endpoint[device] = USB_Key_Endpoint[device];
									else
										USB_Device_Code[device] = USB_Device_Code[device] & (unsigned char)~DEVICE_KEY; //���̱�־��0
								}
								//���
								if ((USB_Device_Code[device] & DEVICE_MOUSE) != (unsigned char)0) {
									//��ȡ������������������������
									if (CH375_GET_RPT_DES(device, USB_Mouse_Interface[device], USB_Mouse_Report_Len[device], DataBuf) != (unsigned char)0 && \
										UsbProcRptDes(device, USB_Mouse_Report_Len[device], DataBuf) != 0)
										USB_Current_Endpoint[device] = USB_Mouse_Endpoint[device];
									else
										USB_Device_Code[device] = USB_Device_Code[device] & (unsigned char)~DEVICE_MOUSE; //����־��0
								}
								USB_Sync[device] = 0;
							}
							else
								USB_Device_Code[device] = NO_DEVICE; //���豸
						}
						//��ʼ��USB�洢�豸
						else if (USB_FLASH_DISK_INIT(device) != (unsigned char)0) {
							USB_Device_Code[device] |= DEVICE_FLASH_DISK; //��λ�豸����, �洢�豸
						}
					}
				}
			}
			//�豸�γ�
			else if (initcode == (unsigned char)0x16) {
				USB_Device_Code[device] = NO_DEVICE; //���豸
				CH375_SET_USB_MODE(device, 0x05); //05H������ʽ������SOF��
			}
		}
		//�м�������豸
		if ((USB_Device_Code[device] & (DEVICE_KEY | DEVICE_MOUSE)) != (unsigned char)0) {
			//�������ͬʱ����
			if (USB_Device_Code[device] == (DEVICE_KEY | DEVICE_MOUSE)) {
				CH375_ABORT_NAK(device);
				Delay(ABORT_NAK_DELAY);
				//�������˵���л�
				if (USB_Current_Endpoint[device] == USB_Key_Endpoint[device])
					USB_Current_Endpoint[device] = USB_Mouse_Endpoint[device];
				else
					USB_Current_Endpoint[device] = USB_Key_Endpoint[device];
			}
			CH375_USB_IN(device, USB_Sync[device], USB_Current_Endpoint[device]); //ִ��IN�����ѯ�豸
			Delay(USB_IN_DELAY);
		}
	}
	return update;
}

/* USB�洢���豸������, deviceѡ���豸,sector��ʼ������,count�������ĸ���,buf�������׵�ַ,��������ɹ�����ֵ��Ϊ0 */
unsigned char CH375_RD_LBA(unsigned char device, unsigned long sector, unsigned char count, unsigned char* buf) {
	unsigned char i = 0;

	//CH375оƬ���ڲ����豸�Ǵ洢��
	if (CH375_Flag[device] == (unsigned char)1 && (USB_Device_Code[device] & DEVICE_FLASH_DISK) != (unsigned char)0) {
		if (CH375_DISK_READ(device, sector, count) == 0) return 0; //���Ͷ����ݿ鵽USB�洢���豸����,ִ��ʧ�ܷ���0
		do {
			if (CH375_RD_USB_DATA0(device, buf) != 64) return 0; //CH375����������64�ֽڵ�����������,���������������64�ֽڷ���0
			buf += 64;
			if (CH375_DISK_RD_GO(device) == 0) return 0; //���ͼ�����USB�洢���豸���ݿ�����,ִ��ʧ�ܷ���0
		} while (++i >> 3 != count);
		return 1;
	}
	return 0;
}

/* USB�洢���豸д����, deviceѡ���豸,sector��ʼ������,count�������ĸ���,bufΪ�������׵�ַ,��������ɹ�����ֵ��Ϊ0 */
unsigned char CH375_WR_LBA(unsigned char device, unsigned long sector, unsigned char count, unsigned char* buf) {
	unsigned int i = 0;

	//CH375оƬ���ڲ����豸�Ǵ洢��
	if (CH375_Flag[device] == (unsigned char)1 && (USB_Device_Code[device] & DEVICE_FLASH_DISK) != (unsigned char)0) {
		if (CH375_DISK_WRITE(device, sector, count) == 0) return 0; //����д���ݿ鵽USB�洢���豸����,ִ��ʧ�ܷ���0
		do {
			CH375_WR_USB_DATA7(device, 64, buf); //д64�ֽڵ�CH375������
			buf += 64;
			if (CH375_DISK_WR_GO(device) == 0) return 0; //���ͼ���дUSB�洢���豸���ݿ�����,ִ��ʧ�ܷ���0
		} while (++i >> 3 != count);
		return 1;
	}
	return 0;
}

/* ���̼�ֵ��ѯ */
unsigned char KeyQuery(unsigned char value) {
	unsigned char i = 1;

	while (i < (unsigned char)KEY_VALUE_NUM + 1 && Key_Value[i] != value) ++i;
	return i < (unsigned char)KEY_VALUE_NUM + 1 ? 1 : 0;
}
