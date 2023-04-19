void CH375_delay_0()
{
}


unsigned char CH375_NOT_DATA(unsigned char device,unsigned char DATA) //CH375���� д������ ���� ~����,  deviceѡ���豸,DATA�ǲ�������
{

unsigned char x;

  CS_8080 = 0x08|device; //ѡ��8080�����豸
  D1_8080 = 0x06; //д����
  CH375_delay_0();
  D0_8080 = DATA; //д����
  CH375_delay_0();
  x = D0_8080;    //����ȡ���������
  CS_8080 = 0x00; //ѡ�п��豸
  return x;

}

void CH375_SET_USB_BUSRST(unsigned char device) //����CH375����ģʽΪ��λUSB����,deviceѡ���豸
{

  unsigned int i;

  CS_8080 = 0x08|device; //ѡ��8080�����豸
  D1_8080 = 0x15; //д����
  CH375_delay_0();
  D0_8080 = 0x07;//д����
  CS_8080 = 0x00; //ѡ�п��豸
  for(i = 0;i != 61000;++i);
  for(i = 0;i != 52000;++i);

}

void CH375_SET_USB_HOST(unsigned char device) //����CH375����ģʽΪ����ģʽ,deviceѡ���豸
{

  unsigned int i;

  CS_8080 = 0x08|device; //ѡ��8080�����豸
  D1_8080 = 0x15; //д����
  CH375_delay_0();
  D0_8080 = 0x06;//д����
  CS_8080 = 0x00; //ѡ�п��豸
  for(i = 0;i != 25000;++i);

}

void CH375_RST(unsigned char device) //CH375Ӳ����λ,deviceѡ���豸
{

unsigned int i;

  CS_8080 = 0x08|device; //ѡ��8080�����豸
  D1_8080 = 0x05; //д����
  CS_8080 = 0x00; //ѡ�п��豸
  for(i = 0;i != 25000;++i); //��40��������

}

void CH375_CSH() //��ʼ��CH375
{


  CH375_RST(0); //��1ƬCH375ִ��Ӳ����λ
  CH375_RST(1); //��2ƬCH375ִ��Ӳ����λ
  CH375_RST(2); //��3ƬCH375ִ��Ӳ����λ
  CH375_RST(3); //��4ƬCH375ִ��Ӳ����λ

  if(CH375_NOT_DATA(0,0xaa) == 0x55 && CH375_NOT_DATA(0,0x55) == 0xaa) //����1ƬCH375����?
  {

     CS_8080 = 0x08; //ѡ��8080�����豸
     D1_8080 = 0x01; //��ȡ�汾������
     CH375_delay_0();
     CH375_ICBBH[0] = D0_8080 & 0x3f; //����汾��
     CS_8080 = 0x00; //ѡ�п��豸
     CH375_device_bz[0] = 1; //��־��1ƬCH375�豸����
     CH375_SET_USB_HOST(0); //����Ϊ����ģʽ

  }


  if(CH375_NOT_DATA(1,0xaa) == 0x55 && CH375_NOT_DATA(1,0x55) == 0xaa) //����2ƬCH375����?
  {

     CS_8080 = 0x09; //ѡ��8080�����豸
     D1_8080 = 0x01; //��ȡ�汾������
     CH375_delay_0();
     CH375_ICBBH[1] = D0_8080 & 0x3f; //����汾��
     CS_8080 = 0x00; //ѡ�п��豸
     CH375_device_bz[1] = 1; //��־��2ƬCH375�豸����
     CH375_SET_USB_HOST(1); //����Ϊ����ģʽ

  }


  if(CH375_NOT_DATA(2,0xaa) == 0x55 && CH375_NOT_DATA(2,0x55) == 0xaa) //����3ƬCH375����?
  {

     CS_8080 = 0x0a; //ѡ��8080�����豸
     D1_8080 = 0x01; //��ȡ�汾������
     CH375_delay_0();
     CH375_ICBBH[2] = D0_8080 & 0x3f; //����汾��
     CS_8080 = 0x00; //ѡ�п��豸
     CH375_device_bz[2] = 1; //��־��3ƬCH375�豸����
     CH375_SET_USB_HOST(2); //����Ϊ����ģʽ

  }


  if(CH375_NOT_DATA(3,0xaa) == 0x55 && CH375_NOT_DATA(3,0x55) == 0xaa) //����4ƬCH375����?
  {

     CS_8080 = 0x0b; //ѡ��8080�����豸
     D1_8080 = 0x01; //��ȡ�汾������
     CH375_delay_0();
     CH375_ICBBH[3] = D0_8080 & 0x3f; //����汾��
     CS_8080 = 0x00; //ѡ�п��豸
     CH375_device_bz[3] = 1; //��־��4ƬCH375�豸����
     CH375_SET_USB_HOST(3); //����Ϊ����ģʽ

  }


}



unsigned char CH375_RD_bufDATA(unsigned char device,unsigned char *buf) //��CH375�Ļ��������ݵ�����������,deviceѡ���豸,bufΪ�����������׵�ַ,����ֵΪ���ݳ���
{

unsigned char bufx; //��¼CH375���������ݳ���
unsigned char js1;  //����1


      CS_8080 = 0x08|device; //ѡ��8080�����豸
      D1_8080 = 0x27; //���Ͷ�����������
      CH375_delay_0();
      bufx = D0_8080; //�������������ݳ���

      js1 = 0;
      while(js1 != bufx)
      {
        buf[js1] = D0_8080;
        ++js1;
      }

      CS_8080 = 0x00; //ѡ�п��豸

   return bufx;

}



void CH375_WR_bufDATA(unsigned char device,unsigned char x,unsigned char *buf) //��������������д��CH375�Ļ�����,deviceѡ���豸,xΪд�����ݳ���,bufΪ�����������׵�ַ,
{

unsigned char js1; //����1

      CS_8080 = 0x08|device; //ѡ��8080�����豸
      D1_8080 = 0x2b; //����д����������
      CH375_delay_0();
      D0_8080 = x; //д�����ݳ���

      js1 = 0;
      while(js1 != x)
      {
        D0_8080 = buf[js1];
        ++js1;
      }

      CS_8080 = 0x00; //ѡ�п��豸

}



void CH375_USB_CTL(unsigned char device,unsigned char data1,unsigned char data2,unsigned char data3,unsigned char data4,unsigned char data5,unsigned char data6,unsigned char data7,unsigned char data8) //�˵�0ִ��8�ֽ�SETUP����,deviceѡ���豸,data1~data8Ϊ8�ֽ�����
{

  CS_8080 = 0x08|device; //ѡ��8080�����豸

  D1_8080 = 0x2b; //����д����������
  CH375_delay_0();
  D0_8080 = 0x08; //����8�ֽ�
  CH375_delay_0();

  D0_8080 = data1;
  CH375_delay_0();
  D0_8080 = data2;
  CH375_delay_0();
  D0_8080 = data3;
  CH375_delay_0();
  D0_8080 = data4;
  CH375_delay_0();
  D0_8080 = data5;
  CH375_delay_0();
  D0_8080 = data6;
  CH375_delay_0();
  D0_8080 = data7;
  CH375_delay_0();
  D0_8080 = data8;
  CH375_delay_0();

  D1_8080 = 0x4e; //����ִ����������
  CH375_delay_0();
  D0_8080 = 0x00; //ͬ����־ 00H����DATA0 40H����DATA1
  CH375_delay_0();
  D0_8080 = 0x0d; //��4λ�˵� ��4λ��������

  CS_8080 = 0x00; //ѡ�п��豸

}

/*
void CH375_USB_SETUP(unsigned char device,unsigned char DX,unsigned char DK) //ִ��SETUP����, DX = 1��DATA1, DX = 0��DATA0,DK�Ƕ˵��,deviceѡ���豸
{

  CS_8080 = 0x08|device; //ѡ��8080�����豸

  D1_8080 = 0x4e; //����ִ����������
  CH375_delay_0();
  D0_8080 = (DX << 6) & 0x40; //ͬ����־ 00H��DATA0 40H��DATA1
  CH375_delay_0();
  D0_8080 = (DK << 4) | 0x0d; //��4λ�˵� ��4λ��������

  CS_8080 = 0x00; //ѡ�п��豸

}
*/


void CH375_USB_IN(unsigned char device,unsigned char DX,unsigned char DK) //ִ��IN����, DX = 1��DATA1, DX = 0��DATA0,DK�Ƕ˵��,deviceѡ���豸
{

  CS_8080 = 0x08|device; //ѡ��8080�����豸

  D1_8080 = 0x4e; //����ִ����������
  CH375_delay_0();
  D0_8080 = DX << 7; //ͬ����־ 00H��DATA0 80H��DATA1
  CH375_delay_0();
  D0_8080 = (DK << 4) | 0x09; //��4λ�˵� ��4λ��������

  CS_8080 = 0x00; //ѡ�п��豸

}


void CH375_USB_OUT(unsigned char device,unsigned char DX,unsigned char DK) //ִ��OUT����, DX = 1��DATA1, DX = 0��DATA0,DK�Ƕ˵��,deviceѡ���豸
{

  CS_8080 = 0x08|device; //ѡ��8080�����豸

  D1_8080 = 0x4e; //����ִ����������
  CH375_delay_0();
  D0_8080 = (DX << 6) & 0x40; //ͬ����־ 00H��DATA0 40H��DATA1
  CH375_delay_0();
  D0_8080 = (DK << 4) | 0x01; //��4λ�˵� ��4λ��������

  CS_8080 = 0x00; //ѡ�п��豸

}


void CH375_SET_USB_BUSM(unsigned char device,unsigned char x) //����USB�����ٶ�,deviceѡ���豸,xΪ�ٶ�
{

  CS_8080 = 0x08|device; //ѡ��8080�����豸

  D1_8080 = 0x04; //��������USB�����ٶ�����
  CH375_delay_0();
  D0_8080 = x;    //�����ٶ�����,00H��Ӧ12Mbpsȫ��ģʽ,01H��Ӧ1.5Mbpsȫ��ģʽ(�Ǳ�׼ģʽ),02H��Ӧ1.5Mbps����ģʽ

  CS_8080 = 0x00; //ѡ�п��豸

}


unsigned char CH375_RD_INTDATA(unsigned char device) //��ȡCH375�ж�״̬��,deviceѡ���豸
{

unsigned char x;

  CS_8080 = 0x08|device; //ѡ��8080�����豸
  D1_8080 = 0x22; //���ͻ�ȡ�ж�������
  CH375_delay_0();
  x = D0_8080;
  CS_8080 = 0x00; //ѡ�п��豸

  return x;

}


void CH375_USB_HQMSF(unsigned char device,unsigned char x) //��ȡ������,xΪ����������,deviceѡ���豸
{

  CS_8080 = 0x08|device; //ѡ��8080�����豸
  D1_8080 = 0x46;
  CH375_delay_0();
  D0_8080 = x;
  CS_8080 = 0x00; //ѡ�п��豸

}



unsigned char CH375_RUN()
{

unsigned char i;
unsigned char device;


CH375_INTT = 0;

/***************************** �������ˢ���� = 1 / ((65536 / CPU��Ƶ) * CH375_CL1) = 183HZ ****************************/

#define CH375_CL1 1

/***********************************************************************************************************************/


       if(CH375_CT2_ < 256 - CH375_CL1 && (CT2 < CH375_CT2_ || CT2 >= CH375_CT2_ + CH375_CL1)   ||   CH375_CT2_ > 255 - CH375_CL1 && CT2 < CH375_CT2_ && CT2 >= CH375_CT2_ + CH375_CL1) //�ϴμ�¼��Ӳ�����������ݺ�����Ӳ�������������ݽ��бȽ�,�ﵽ����ʱ����
       {

 device = 0;

 do
 {

    if(CH375_device_bz[device] == 1  &&  (device == 0 && (INT_8080 & 0x01) == 0x00  ||  device == 1 && (INT_8080 & 0x02) == 0x00  ||  device == 2 && (INT_8080 & 0x04) == 0x00  ||  device == 3 && (INT_8080 & 0x08) == 0x00) ) //CH375��־��Ч�������ж�ʱ����
    {

        CH375_INTT = 1;

        i = CH375_RD_INTDATA(device); //��ȡCH375�ж�״̬�뵽i

        if(i == 0x15) //�豸����
        {

           CH375_SBIOBZ = 1; //��־���豸����

           CH375_BJ[device] = 1; //����1

           CH375_QJ[device] = 0; //�����ж��¼���0

           CH375_SET_USB_BUSRST(device); //��λUSB����
           CH375_SET_USB_HOST(device);   //����Ϊ����ģʽ

           CH375_SET_USB_BUSM(device,CH375_ZXSD[device]); //����USB�����ٶ�
           CH375_ZXSD[device] += 2;

           CH375_USB_HQMSF(device,1); //���Ի�ȡ�豸������

SPI_S = 0x04;
SPI_D = 0x11;
SPI_S = 0x01;

        }
        else if(i == 0x16) //�豸�γ�
        {

           CH375_SBIOBZ = 2; //��־���豸�γ�

           CH375_INK[device] = 0; //�رղ�ѯ
           CH375_SBDM[device] = 0; //�豸����0 ���豸
           CH375_ZXSD[device] = 0; //�����ٶ�ֵ�ָ������


SPI_S = 0x04;
SPI_D = 0x22;
SPI_S = 0x01;

        }
        else if(i == 0x14) //����ִ�гɹ�
        {

           if(CH375_BJ[device] == 0) //����0
           {


              CH375_QJ[device] = 0; //�����ж��¼���0

              CH375_INDX[device] = ~CH375_INDX[device]; //DATA0DATA1ͬ��������־ȡ��

              i = CH375_RD_bufDATA(device,CH375_DATAbuf); //CH375���������ݶ��뱾�������� , ���ݳ��ȼ�¼��i

              if(i == 4) //���
              {

                 SB_KEY = CH375_DATAbuf[0];

                 if((CH375_DATAbuf[1] & 0x80) == 0x80 && SB_X + CH375_DATAbuf[1] > SB_X)
                 {
                    SB_X = 0;
                 }
                 else if((CH375_DATAbuf[1] & 0x80) == 0x00 && SB_X + CH375_DATAbuf[1] < SB_X)
                 {
                    SB_X = 255;
                 }
                 else
                 {
                    SB_X += CH375_DATAbuf[1];
                 }

                 if((CH375_DATAbuf[2] & 0x80) == 0x80 && SB_Y + CH375_DATAbuf[2] > SB_Y)
                 {
                    SB_Y = 0;
                 }
                 else if((CH375_DATAbuf[2] & 0x80) == 0x00 && (SB_Y + CH375_DATAbuf[2] < SB_Y || SB_Y + CH375_DATAbuf[2] > 239))
                 {
                    SB_Y = 239;
                 }
                 else
                 {
                    SB_Y += CH375_DATAbuf[2];
                 }

                 if((CH375_DATAbuf[3] & 0x80) == 0x80 && SB_Z + CH375_DATAbuf[3] > SB_Z)
                 {
                    SB_Z = 0;
                 }
                 else if((CH375_DATAbuf[3] & 0x80) == 0x00 && SB_Z + CH375_DATAbuf[3] < SB_Z)
                 {
                    SB_Z = 255;
                 }
                 else
                 {
                    SB_Z += CH375_DATAbuf[3];
                 }

              }
              else if(i == 6) //���2
              {
              }
              else if(i == 8) //����
              {













                 SB_KEY = CH375_DATAbuf[0];



                 if((CH375_DATAbuf[1] & 0x80) == 0x80 && SB_X + CH375_DATAbuf[1] > SB_X)
                 {
                    SB_X = 0;
                 }
                 else if((CH375_DATAbuf[1] & 0x80) == 0x00 && SB_X + CH375_DATAbuf[1] < SB_X)
                 {
                    SB_X = 255;
                 }
                 else
                 {
                    SB_X += CH375_DATAbuf[1];
                 }



                 if((CH375_DATAbuf[2] & 0x80) == 0x80 && SB_Y + CH375_DATAbuf[2] > SB_Y)
                 {
                    SB_Y = 0;
                 }
                 else if((CH375_DATAbuf[2] & 0x80) == 0x00 && (SB_Y + CH375_DATAbuf[2] < SB_Y || SB_Y + CH375_DATAbuf[2] > 239))
                 {
                    SB_Y = 239;
                 }
                 else
                 {
                    SB_Y += CH375_DATAbuf[2];
                 }















                 KEY_DATA[0] = CH375_DATAbuf[0]; //�������ݵ����̼�ֵ
                 KEY_DATA[1] = CH375_DATAbuf[1];
                 KEY_DATA[2] = CH375_DATAbuf[2];
                 KEY_DATA[3] = CH375_DATAbuf[3];
                 KEY_DATA[4] = CH375_DATAbuf[4];
                 KEY_DATA[5] = CH375_DATAbuf[5];
                 KEY_DATA[6] = CH375_DATAbuf[6];
                 KEY_DATA[7] = CH375_DATAbuf[7];

                 if(KEY_Num_Lock()) KEY_LED ^= 0x01;
                 if(KEY_Scroll_Lock()) KEY_LED ^= 0x02;
                 if(KEY_Caps_Lock()) KEY_LED ^= 0x04;

                 if(KEY_Num_Lock() || KEY_Scroll_Lock() || KEY_Caps_Lock())
                 {
                    CH375_USB_CTL(device,0x21,0x09,0x00,0x02,0x00,0x00,0x01,0x00); //���ü��̵�
                    while(device == 0 && (INT_8080 & 0x01) == 0x01  ||  device == 1 && (INT_8080 & 0x02) == 0x02  ||  device == 2 && (INT_8080 & 0x04) == 0x04  ||  device == 3 && (INT_8080 & 0x08) == 0x08); //�ȴ��ж�
       
                    CH375_DATAbuf[0] = KEY_LED; //������̵�����
                    CH375_WR_bufDATA(device,1,CH375_DATAbuf); //��������������д��CH375������
                    CH375_USB_OUT(device,0,0); //OUT���� ��DATA0 �˵�0
                    while(device == 0 && (INT_8080 & 0x01) == 0x01  ||  device == 1 && (INT_8080 & 0x02) == 0x02  ||  device == 2 && (INT_8080 & 0x04) == 0x04  ||  device == 3 && (INT_8080 & 0x08) == 0x08); //�ȴ��ж�

                    CH375_USB_IN(device,1,0); //IN���� ��0���ݵ�DATA1 �˵�0
                    while(device == 0 && (INT_8080 & 0x01) == 0x01  ||  device == 1 && (INT_8080 & 0x02) == 0x02  ||  device == 2 && (INT_8080 & 0x04) == 0x04  ||  device == 3 && (INT_8080 & 0x08) == 0x08); //�ȴ��ж�
                 }

              }

SPI_S = 0x04;
SPI_D += 0x33;
SPI_S = 0x01;

           }
           else if(CH375_BJ[device] == 1) //����1 ���Ի�ȡ�豸������OK
           {
              CH375_BJ[device] = 2; //����2
              CS_8080 = 0x08|device; //ѡ��8080�����豸
              D1_8080 = 0x51; //���Գ�ʼ��USB�洢�豸
              CS_8080 = 0x00; //ѡ�п��豸
SPI_S = 0x04;
SPI_D = 0x01;
SPI_S = 0x01;

           }
           else if(CH375_BJ[device] == 2) //����2 ���Գ�ʼ��USB�洢�豸OK
           {
              CH375_BJ[device] = 3; //����3
              CS_8080 = 0x08|device; //ѡ��8080�����豸
              D1_8080 = 0x53; //��ȡUSB�洢�豸����
              CS_8080 = 0x00; //ѡ�п��豸

SPI_S = 0x04;
SPI_D = 0x02;
SPI_S = 0x01;

           }
           else if(CH375_BJ[device] == 3) //����3 ��ȡUSB�洢�豸����OK
           {
              CH375_RD_bufDATA(device,CH375_DATAbuf); //CH375���������ݶ��뱾��������

              CH375_LBAX[device] = CH375_DATAbuf[0]; //��¼�洢�豸LBA����,USB�洢��������-1,+1�ٳ�512����ʵ������(��λ�ֽ�)
              CH375_LBAX[device] <<= 8;
              CH375_LBAX[device] |= CH375_DATAbuf[1];
              CH375_LBAX[device] <<= 8;
              CH375_LBAX[device] |= CH375_DATAbuf[2];
              CH375_LBAX[device] <<= 8;
              CH375_LBAX[device] |= CH375_DATAbuf[3];

              ++CH375_LBAX[device]; //+1Ϊʵ��������

              CH375_SBDM[device] = 1; //�豸����1 �洢�豸

SPI_S = 0x04;
SPI_D = 0x03;
SPI_S = 0x01;

           }
           else if(CH375_BJ[device] == 4) //����4 �Զ�����USB�豸OK
           {
              CH375_BJ[device] = 5; //����5
              CH375_USB_CTL(device,0x81,0x06,0x00,0x22,0x00,0x00,0x08,0x00); //��ȡ8�ֽڱ���������

SPI_S = 0x04;
SPI_D = 0x04;
SPI_S = 0x01;

           }
           else if(CH375_BJ[device] == 5) //����5 ��ȡ8�ֽڱ���������OK
           {
              CH375_BJ[device] = 6; //����6
              CH375_USB_IN(device,1,0); //ִ��IN���� ��DATA1 �˵�0

SPI_S = 0x04;
SPI_D = 0x05;
SPI_S = 0x01;

           }
           else if(CH375_BJ[device] == 6) //����6 ִ��IN����OK
           {
              CH375_BJ[device] = 7; //����7

              CH375_RD_bufDATA(device,CH375_DATAbuf); //CH375���������ݶ��뱾��������

              if(CH375_DATAbuf[2] == 0x09 && CH375_DATAbuf[3] == 0x02) //09 02 �����
              {
                 CH375_SBDM[device] = 3; //�豸����3 ���

                 CH375_WR_bufDATA(device,0,CH375_DATAbuf); //�ظ�0���ݵ�DATA1
                 CH375_USB_OUT(device,1,0); //OUT���� ��DATA1 �˵�0
              }
              else if(CH375_DATAbuf[2] == 0x09 && CH375_DATAbuf[3] == 0x06) //09 06 �Ǽ���
              {
                 CH375_SBDM[device] = 2; //�豸����2 ����

                 CH375_WR_bufDATA(device,0,CH375_DATAbuf); //�ظ�0���ݵ�DATA1
                 CH375_USB_OUT(device,1,0); //OUT���� ��DATA1 �˵�0
              }
              else
              {
                 CH375_SBDM[device] = 255; //δʶ����豸
              }
SPI_S = 0x04;
SPI_D = 0x06;
SPI_S = 0x01;

           }
           else if(CH375_BJ[device] == 7) //����7 ִ��OUT����OK
           {

              if(CH375_SBDM[device] == 2) //����?
              {
                 CH375_BJ[device] = 8; //����8
                 CH375_USB_CTL(device,0x21,0x09,0x00,0x02,0x00,0x00,0x01,0x00); //���ü��̵�
              }
              else
              {
                 CH375_INK[device] = 1; //������ѯ
                 CH375_INDX[device] = 0; //����DATA0
                 CH375_BJ[device] = 0; //����0 ��ɳ�ʼ��
              }

SPI_S = 0x04;
SPI_D = 0x07;
SPI_S = 0x01;

           }
           else if(CH375_BJ[device] == 8) //����8 ���ü��̵�OK
           {
              CH375_BJ[device] = 9; //����9

              CH375_DATAbuf[0] = KEY_LED;               //������̵�����
              CH375_WR_bufDATA(device,1,CH375_DATAbuf);
              CH375_USB_OUT(device,0,0); //OUT���� ��DATA0 �˵�0

SPI_S = 0x04;
SPI_D = 0x08;
SPI_S = 0x01;

           }
           else if(CH375_BJ[device] == 9) //����9 ������̵�����OK
           {
              CH375_BJ[device] = 10; //����10

              CH375_USB_IN(device,1,0); //IN���� ��0���ݵ�DATA1 �˵�0

SPI_S = 0x04;
SPI_D = 0x09;
SPI_S = 0x01;

           }
           else if(CH375_BJ[device] == 10) //����10 ��0���ݵ�DATA1 OK
           {
              CH375_INK[device] = 1; //������ѯ
              CH375_INDX[device] = 0; //����DATA0
              CH375_BJ[device] = 0; //����0 ��ɳ�ʼ��

SPI_S = 0x04;
SPI_D = 0x0a;
SPI_S = 0x01;

           }

        }
        else //�����¼�
        {

           if(CH375_BJ[device] == 0) //����0
           {
              ++CH375_QJ[device];//�����ж��¼�����+1
              if(CH375_QJ[device] == 2) //�����ж��¼������ﵽ2
              {
                 CH375_INK[device] = 0; //�رղ�ѯ
                 CH375_SBDM[device] = 0; //�豸����0 ���豸
              }
           }
           else if(CH375_BJ[device] == 1) //����1 ���Ի�ȡ�豸������NO
           {

              if(CH375_ZXSD[device] < 3) //С��3�μ�����...
              {
                 CH375_RST(device); //ִ��Ӳ����λ
                 CH375_SET_USB_HOST(device); //����Ϊ����ģʽ
              }
              else
              {
                 CH375_SBDM[device] = 255; //δʶ����豸
              }

           }
           else if(CH375_BJ[device] == 2) //����2 ���Գ�ʼ��USB�洢�豸NO
           {
              CH375_BJ[device] = 4; //����4
              CS_8080 = 0x08|device; //ѡ��8080�����豸
              D1_8080 = 0x4d; //�Զ�����USB�豸
              CS_8080 = 0x00; //ѡ�п��豸
           }
           else if(CH375_BJ[device] == 3 || CH375_BJ[device] == 4 || CH375_BJ[device] == 5 || CH375_BJ[device] == 6 || CH375_BJ[device] == 7 || CH375_BJ[device] == 8 || CH375_BJ[device] == 9 || CH375_BJ[device] == 10) //����3 ��ȡUSB�洢�豸����NO ����4 �Զ�����USB�豸NO ����5 ��ȡ8�ֽڱ���������NO ����6 ִ��IN����NO ����7 ִ��OUT����NO ����8 ���ü��̵�NO ����9 ������̵�����NO ����10 ��0���ݵ�DATA1NO
           {
              CH375_SBDM[device] = 255; //δʶ����豸
           }

        }


    }


    if(CH375_INK[device] == 1) //��ѯ���ƿ�������
    {
        CH375_USB_IN(device,CH375_INDX[device],1); //ִ��IN�����ѯ�豸�˵�1
    }



    ++device; //��һ���豸

 }while(device != 4);





 CH375_CT2_ = CT2; //��¼��ǰӲ������������




       }


   return CH375_INTT;


}





unsigned char CH375_DISK_READ(unsigned char device,unsigned long int SQH,unsigned char LBAX) //��USB�洢���豸��ȡ���ݿ�����, deviceѡ���豸,SQH��������,LBAX�Ƕ�ȡ��������,����ֵ��Ϊ0��ʾ�����ɹ�
{

  if(CH375_device_bz[device] == 1 && CH375_SBDM[device] == 1) ///CH375оƬ���ڲ����豸�Ǵ洢��,����
  {

     CS_8080 = 0x08|device; //ѡ��8080�����豸


     D1_8080 = 0x54; //д����
     CH375_delay_0();

     D0_8080 = SQH; //д����
     CH375_delay_0();
     D0_8080 = SQH >> 8; //д����
     CH375_delay_0();
     D0_8080 = SQH >> 16; //д����
     CH375_delay_0();
     D0_8080 = SQH >> 24; //д����
     CH375_delay_0();

     D0_8080 = LBAX; //д����


     CS_8080 = 0x00; //ѡ�п��豸


     while(device == 0 && (INT_8080 & 0x01) != 0x00  ||  device == 1 && (INT_8080 & 0x02) != 0x00  ||  device == 2 && (INT_8080 & 0x04) != 0x00  ||  device == 3 && (INT_8080 & 0x08) != 0x00); //�ȴ��жϵ�������

     if(CH375_RD_INTDATA(device) == 0x1d) //���ɹ�
     {
        return 1;
     }

  }

  return 0;

}


unsigned char CH375_DISK_RD_GO(unsigned char device) //������USB�洢���豸���ݿ�����,deviceѡ���豸,����ֵ��Ϊ0��ʾ�����ɹ�
{

unsigned char i;

  if(CH375_device_bz[device] == 1 && CH375_SBDM[device] == 1) //CH375оƬ���ڲ����豸�Ǵ洢��,����
  {

     CS_8080 = 0x08|device; //ѡ��8080�����豸
     D1_8080 = 0x55; //д����
     CS_8080 = 0x00; //ѡ�п��豸

     while(device == 0 && (INT_8080 & 0x01) != 0x00  ||  device == 1 && (INT_8080 & 0x02) != 0x00  ||  device == 2 && (INT_8080 & 0x04) != 0x00  ||  device == 3 && (INT_8080 & 0x08) != 0x00); //�ȴ��жϵ�������

     i = CH375_RD_INTDATA(device); //��ȡ�ж�״̬�뵽i

     if(i == 0x1d || i == 0x14) //���ɹ�
     {
        return 1;
     }

  }

  return 0;

}



unsigned char CH375_DISK_WRITE(unsigned char device,unsigned long int SQH,unsigned char LBAX) //д���ݿ鵽USB�洢���豸����, deviceѡ���豸,SQH��������,LBAX��дȡ��������,����ֵ��Ϊ0��ʾ�����ɹ�
{

  if(CH375_device_bz[device] == 1 && CH375_SBDM[device] == 1) //CH375оƬ���ڲ����豸�Ǵ洢��,����
  {

     CS_8080 = 0x08|device; //ѡ��8080�����豸


     D1_8080 = 0x56; //д����
     CH375_delay_0();

     D0_8080 = SQH; //д����
     CH375_delay_0();
     D0_8080 = SQH >> 8; //д����
     CH375_delay_0();
     D0_8080 = SQH >> 16; //д����
     CH375_delay_0();
     D0_8080 = SQH >> 24; //д����
     CH375_delay_0();

     D0_8080 = LBAX; //д����


     CS_8080 = 0x00; //ѡ�п��豸


     while(device == 0 && (INT_8080 & 0x01) != 0x00  ||  device == 1 && (INT_8080 & 0x02) != 0x00  ||  device == 2 && (INT_8080 & 0x04) != 0x00  ||  device == 3 && (INT_8080 & 0x08) != 0x00); //�ȴ��жϵ�������

     if(CH375_RD_INTDATA(device) == 0x1e) //д�ɹ�
     {
        return 1;
     }

  }

  return 0;

}


unsigned char CH375_DISK_WR_GO(unsigned char device) //����дUSB�洢���豸���ݿ�����,deviceѡ���豸,����ֵ��Ϊ0��ʾ�����ɹ�
{

unsigned char i;

  if(CH375_device_bz[device] == 1 && CH375_SBDM[device] == 1) //CH375оƬ���ڲ����豸�Ǵ洢��,����
  {

     CS_8080 = 0x08|device; //ѡ��8080�����豸
     D1_8080 = 0x57; //д����
     CS_8080 = 0x00; //ѡ�п��豸

     while(device == 0 && (INT_8080 & 0x01) != 0x00  ||  device == 1 && (INT_8080 & 0x02) != 0x00  ||  device == 2 && (INT_8080 & 0x04) != 0x00  ||  device == 3 && (INT_8080 & 0x08) != 0x00); //�ȴ��жϵ�������

     i = CH375_RD_INTDATA(device); //��ȡ�ж�״̬�뵽i

     if(i == 0x1e || i == 0x14) //���ɹ�
     {
        return 1;
     }

  }

  return 0;

}



unsigned char CH375_RD_LBA(unsigned char device,unsigned long int SQH,unsigned char LBAX,unsigned char *buf) //USB�洢���豸������, deviceѡ���豸,SQHΪ��ʼ������,LBAXΪ�������ĸ���,bufΪ�������׵�ַ,��������ɹ�����ֵ��Ϊ0
{

unsigned int js1 = 0;

   if(CH375_DISK_READ(device,SQH,LBAX) == 0) return 0; //���Ͷ����ݿ鵽USB�洢���豸����,ִ��ʧ�ܷ���0

   do
   {

      if(CH375_RD_bufDATA(device,buf) != 64) return 0; //CH375����������64�ֽڵ�����������,���������������64�ֽڷ���0
      buf += 64;
      ++js1;
      if(CH375_DISK_RD_GO(device) == 0) return 0; //���ͼ�����USB�洢���豸���ݿ�����,ִ��ʧ�ܷ���0

   }while(js1 >> 3 != LBAX);

   return 1;

}

unsigned char CH375_WR_LBA(unsigned char device,unsigned long int SQH,unsigned char LBAX,unsigned char *buf) //USB�洢���豸д����, deviceѡ���豸,SQHΪ��ʼ������,LBAXΪд�����ĸ���,bufΪ�������׵�ַ,��������ɹ�����ֵ��Ϊ0
{

unsigned int js1 = 0;

   if(CH375_DISK_WRITE(device,SQH,LBAX) == 0) return 0; //����д���ݿ鵽USB�洢���豸����,ִ��ʧ�ܷ���0

   do
   {

      CH375_WR_bufDATA(device,64,buf); //д64�ֽڵ�CH375������
      buf += 64;
      ++js1;
      //SPI_SET_DLED(0xa0 | js1);
      if(CH375_DISK_WR_GO(device) == 0) return 0; //���ͼ���дUSB�洢���豸���ݿ�����,ִ��ʧ�ܷ���0
      //SPI_SET_DLED(0x50 | js1);

   }while(js1 >> 3 != LBAX);

   return 1;

}

unsigned char CH375_GET_SBX() //ȡ�豸����
{

unsigned char js1 = 0;
unsigned char js2 = 0;

   do
   {
      if(CH375_SBDM[js1] != 0) ++js2;

   }while(++js1 != 4);

   return js2;

}



