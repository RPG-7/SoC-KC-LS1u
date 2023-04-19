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
  for (i = 0; i != 25000; ++i);

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

void CH375_SET_USB_MODE(unsigned char device,unsigned char x) //����CH375����ģʽ,deviceѡ���豸,xΪģʽ����,05H������ʽ������SOF��,06H������ʽ�Զ�����SOF��,07H������ʽ��λUSB����
{

  unsigned int i;

  CS_8080 = 0x08|device; //ѡ��8080�����豸
  D1_8080 = 0x15; //д����
  CH375_delay_0();
  D0_8080 = x;//д����
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
     CH375_SET_USB_MODE(0,0x05); //����Ϊ����ģʽ

  }


  if(CH375_NOT_DATA(1,0xaa) == 0x55 && CH375_NOT_DATA(1,0x55) == 0xaa) //����2ƬCH375����?
  {

     CS_8080 = 0x09; //ѡ��8080�����豸
     D1_8080 = 0x01; //��ȡ�汾������
     CH375_delay_0();
     CH375_ICBBH[1] = D0_8080 & 0x3f; //����汾��
     CS_8080 = 0x00; //ѡ�п��豸
     CH375_device_bz[1] = 1; //��־��2ƬCH375�豸����
     CH375_SET_USB_MODE(1,0x05); //����Ϊ����ģʽ

  }


  if(CH375_NOT_DATA(2,0xaa) == 0x55 && CH375_NOT_DATA(2,0x55) == 0xaa) //����3ƬCH375����?
  {

     CS_8080 = 0x0a; //ѡ��8080�����豸
     D1_8080 = 0x01; //��ȡ�汾������
     CH375_delay_0();
     CH375_ICBBH[2] = D0_8080 & 0x3f; //����汾��
     CS_8080 = 0x00; //ѡ�п��豸
     CH375_device_bz[2] = 1; //��־��3ƬCH375�豸����
     CH375_SET_USB_MODE(2,0x05); //����Ϊ����ģʽ

  }


  if(CH375_NOT_DATA(3,0xaa) == 0x55 && CH375_NOT_DATA(3,0x55) == 0xaa) //����4ƬCH375����?
  {

     CS_8080 = 0x0b; //ѡ��8080�����豸
     D1_8080 = 0x01; //��ȡ�汾������
     CH375_delay_0();
     CH375_ICBBH[3] = D0_8080 & 0x3f; //����汾��
     CS_8080 = 0x00; //ѡ�п��豸
     CH375_device_bz[3] = 1; //��־��4ƬCH375�豸����
     CH375_SET_USB_MODE(3,0x05); //����Ϊ����ģʽ

  }


}


void CH375_ABORT_NAK(unsigned char device) //������ǰNAK������,deviceѡ���豸
{

  CS_8080 = 0x08|device; //ѡ��8080�����豸
  D1_8080 = 0x17; //д����
  CS_8080 = 0x00; //ѡ�п��豸

}

void CH375_IN_CLR_STALL(unsigned char device, unsigned char DK) //IN��������˵����,deviceѡ���豸,DKΪ�˵��
{

    CS_8080 = 0x08 | device; //ѡ��8080�����豸
    D1_8080 = 0x41; //д����
    CH375_delay_0();
    D0_8080 = 0x80 | (DK & 0x0f);
    CS_8080 = 0x00; //ѡ�п��豸

}

void CH375_SET_RETRY(unsigned char device, unsigned char data) //����USB����������Դ���,deviceѡ���豸,data������������
{

    CS_8080 = 0x08 | device; //ѡ��8080�����豸
    D1_8080 = 0x0b; //д����
    CH375_delay_0();
    D0_8080 = 0x25;
    CH375_delay_0();
    D0_8080 = data;
    CS_8080 = 0x00; //ѡ�п��豸

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

unsigned char CH375_GET_DEV_RATE(unsigned char device) //��ȡUSB�豸����,deviceѡ���豸
{

unsigned char x;

  CS_8080 = 0x08|device; //ѡ��8080�����豸
  D1_8080 = 0x0a; //���ͻ�ȡUSB�豸��������
  CH375_delay_0();
  D0_8080 = 0x07;
  CH375_delay_0();
  x = D0_8080;
  CS_8080 = 0x00; //ѡ�п��豸

  return x;

}


void CH375_GET_EDSCR(unsigned char device,unsigned char x) //��ȡ������,xΪ����������,deviceѡ���豸
{

  CS_8080 = 0x08|device; //ѡ��8080�����豸
  D1_8080 = 0x46;
  CH375_delay_0();
  D0_8080 = x;
  CS_8080 = 0x00; //ѡ�п��豸

}

void CH375_SET_CONFIG(unsigned char device,unsigned char x) //����USB����,xΪ����ֵ,deviceѡ���豸
{

  CS_8080 = 0x08|device; //ѡ��8080�����豸
  D1_8080 = 0x49;
  CH375_delay_0();
  D0_8080 = x;
  CS_8080 = 0x00; //ѡ�п��豸

}

void CH375_HOLD_INT(unsigned char device) //����������ж�
{
    while((device == 0 && (INT_8080 & 0x01) != 0x00) || (device == 1 && (INT_8080 & 0x02) != 0x00) || (device == 2 && (INT_8080 & 0x04) != 0x00) || (device == 3 && (INT_8080 & 0x08) != 0x00)); //���ж�ʱ����ѭ��
}


unsigned char CH375_DISK_INIT(unsigned char device) //��ʼ��USB�洢�豸,�ɹ����ط�0
{
    CS_8080 = 0x08 | device; //ѡ��8080�����豸
    D1_8080 = 0x51; //���Գ�ʼ��USB�洢�豸
    CS_8080 = 0x00; //ѡ�п��豸

    CH375_HOLD_INT(device); //����������ж�
    if (CH375_RD_INTDATA(device) != 0x14) return 0x88;

    CS_8080 = 0x08 | device; //ѡ��8080�����豸
    D1_8080 = 0x53; //��ȡUSB�洢�豸����
    CS_8080 = 0x00; //ѡ�п��豸

    CH375_HOLD_INT(device); //����������ж�
    if (CH375_RD_INTDATA(device) != 0x14) return 0x8e;

    CH375_RD_bufDATA(device, CH375_DATAbuf); //CH375���������ݶ��뱾��������

    CH375_LBAX[device] = CH375_DATAbuf[0]; //��¼�洢�豸LBA����,USB�洢��������-1,+1�ٳ�512����ʵ������(��λ�ֽ�)
    CH375_LBAX[device] <<= 8;
    CH375_LBAX[device] |= CH375_DATAbuf[1];
    CH375_LBAX[device] <<= 8;
    CH375_LBAX[device] |= CH375_DATAbuf[2];
    CH375_LBAX[device] <<= 8;
    CH375_LBAX[device] |= CH375_DATAbuf[3];

    ++CH375_LBAX[device]; //+1Ϊʵ��������

    return 1;
}


unsigned char CH375_AUTO_SETUP(unsigned char device) //�Զ�����USB�豸,deviceѡ���豸,�ɹ����ط�0
{

  CS_8080 = 0x08|device; //ѡ��8080�����豸
  D1_8080 = 0x4d;
  CS_8080 = 0x00; //ѡ�п��豸

  CH375_HOLD_INT(device); //����������ж�

  if (CH375_RD_INTDATA(device) == 0x14) return 1;
  return 0;

}


unsigned char CH375_GET_SBMSF(unsigned char device,unsigned char *buf) //��ȡ�豸������,deviceѡ���豸,buf���������ݻ������׵�ַ,�ɹ����ض�ȡ���ֽ���,���򷵻�0
{

  CH375_GET_EDSCR(device,1); //��ȡ�豸������

  CH375_HOLD_INT(device); //����������ж�

  if(CH375_RD_INTDATA(device) == 0x14) //��ȡ�豸������ok
  {
    return CH375_RD_bufDATA(device,buf); //��CH375�Ļ��������ݵ�����������
  }

  return 0;

}



unsigned char CH375_GET_PZMSF(unsigned char device,unsigned char *buf) //��ȡ����������,deviceѡ���豸,buf���������ݻ������׵�ַ,�ɹ����ض�ȡ���ֽ���,���򷵻�0
{

unsigned char i;
unsigned char x;
unsigned int j_;
unsigned int j;


  CH375_USB_CTL(device,0x80,0x06,0x00,0x02,0x00,0x00,0x09,0x00); //��ȡ����������

  CH375_HOLD_INT(device); //����������ж�

  if(CH375_RD_INTDATA(device) == 0x14) //��ȡ����������ok
  {

    CH375_USB_IN(device,1,0); //ִ��IN������0�˵�DATA1

    CH375_HOLD_INT(device); //����������ж�

    if(CH375_RD_INTDATA(device) == 0x14) //ִ��IN����ok
    {

       CH375_RD_bufDATA(device,buf); //��CH375�Ļ��������ݵ�����������
       j_ = ((j_ = buf[3]) << 8) | buf[2];
       if(j_ > 256) j_ = 256; //���ƴ�С

       CH375_WR_bufDATA(device,0,buf); //�ظ�0���ݵ�DATA1
       CH375_USB_OUT(device,1,0); //OUT���� ��DATA1 �˵�0

       CH375_HOLD_INT(device); //����������ж�

       if(CH375_RD_INTDATA(device) == 0x14) //ִ��OUT����ok
       {

         CH375_USB_CTL(device,0x80,0x06,0x00,0x02,0x00,0x00,j_ ,j_ >> 8); //��ȡ������������������

         CH375_HOLD_INT(device); //����������ж�

         if(CH375_RD_INTDATA(device) == 0x14) //��ȡ����������ok
         {

           x = 0;
           j = 0;
           while(j < j_)
           {

             CH375_USB_IN(device,(x = ~x),0); //ִ��IN����

             CH375_HOLD_INT(device); //����������ж�

             if(CH375_RD_INTDATA(device) == 0x14) //ִ��IN����ok
             {

               i = CH375_RD_bufDATA(device,buf); //��CH375�Ļ��������ݵ�����������
               buf += i; //�������׵�ַ�ƽ�
               j += i; //�����Ѷ�ȡ�ֽ���

             }
             else return 0;

           }

           CH375_WR_bufDATA(device,0,buf); //�ظ�0���ݵ�DATA1
           CH375_USB_OUT(device,1,0); //OUT���� ��DATA1 �˵�0

           CH375_HOLD_INT(device); //����������ж�

           if(CH375_RD_INTDATA(device) == 0x14) //ִ��OUT����ok
           {
             return j_;
           }

         }

       }

    }

  }

  return 0;

}


unsigned int CH375_GET_BGMSF(unsigned char device,unsigned int index,unsigned int len,unsigned char *buf) //��ȡ����������,deviceѡ���豸,indexΪ����ֵ,lenΪ����������,buf���������ݻ������׵�ַ,�ɹ����ض�ȡ���ֽ���,���򷵻�0
{

unsigned char i;
unsigned char x;
unsigned int j;

         if (len > 256) len = 256; //���ƴ�С
         CH375_USB_CTL(device,0x81,0x06,0x00,0x22,index,index >> 8,len ,len >> 8); //��ȡ����������

         CH375_HOLD_INT(device); //����������ж�

         if(CH375_RD_INTDATA(device) == 0x14) //��ȡ����������ok
         {

           x = 0;
           j = 0;
           while(j < len)
           {

             CH375_USB_IN(device,(x = ~x),0); //ִ��IN����
             CH375_HOLD_INT(device); //����������ж�

             if(CH375_RD_INTDATA(device) == 0x14) //ִ��IN����ok
             {

               i = CH375_RD_bufDATA(device,buf); //��CH375�Ļ��������ݵ�����������
               buf += i; //�������׵�ַ�ƽ�
               j += i; //�����Ѷ�ȡ�ֽ���

             }
             else return 0;

           }

           CH375_WR_bufDATA(device,0,buf); //�ظ�0���ݵ�DATA1
           CH375_USB_OUT(device,1,0); //OUT���� ��DATA1 �˵�0

           CH375_HOLD_INT(device); //����������ж�

           if(CH375_RD_INTDATA(device) == 0x14) //ִ��OUT����ok
           {
             return j;
           }

         }

  return 0;

}


void CH375_FXPZMSF(unsigned char device,unsigned int len,unsigned char *buf) //��������������,deviceѡ���豸,lenΪ��������������,bufΪ����������������
{

unsigned int len_; //�������������ȼ���
unsigned char ddh;

  ddh = 0; //�˵����0
  len_ = 0;

  while(len_ < len)
  {

    if(buf[0] == 0x09 && buf[1] == 0x02) //����������
    {
      len_ += *buf; //������λ���ƽ�
      buf += *buf;
    }
    else if(buf[0] == 0x09 && buf[1] == 0x04) //�ӿ�������
    {

      if((buf[7] == 0x01 || buf[7] == 0x02) && buf[9] == 0x09 && buf[10] == 0x21 && buf[18] == 0x07 && buf[19] == 0x05) //���̻����,��HID������,�˵�������,�������
      {

        ++ddh; //�˵�ŵ���

        if (CH375_SBDM[device] != 0x01 && buf[7] == 0x01) //���̲�����ʱ��¼����������
        {
          CH375_KEY_InterfaceNumber[device] = buf[2]; //��¼�豸�ӿں�
          CH375_KEY_DDH[device] = ddh; //���̶˵��
          CH375_KEY_Report_len[device] = ((CH375_KEY_Report_len[device] = buf[17]) << 8) | buf[16]; //��¼���̱�������������
          CH375_KEY_MaxPacketSize[device] = ((CH375_KEY_MaxPacketSize[device] = buf[23]) << 8) | buf[22]; //��¼���̶˵�������ݰ���С
        }
        else
        {
          CH375_MOUSE_InterfaceNumber[device] = buf[2]; //��¼�豸�ӿں�
          CH375_MOUSE_DDH[device] = ddh; //���˵��
          CH375_MOUSE_Report_len[device] = ((CH375_MOUSE_Report_len[device] = buf[17]) << 8) | buf[16]; //��¼��걨������������
          CH375_MOUSE_MaxPacketSize[device] = ((CH375_MOUSE_MaxPacketSize[device] = buf[23]) << 8) | buf[22]; //��¼���˵�������ݰ���С
        }

        CH375_SBDM[device] |= buf[7]; //��¼�豸����

        buf += 25; //������λ���ƽ�
        len_ += 25;

      }
      else //���Ǽ��������ʽ����
      {
        len_ += *buf; //������λ���ƽ�
        buf += *buf;
      }

    }
    else if(buf[0] == 0x07 && buf[1] == 0x05) //�˵�������
    {
      len_ += *buf; //������λ���ƽ�
      buf += *buf;
      ++ddh; //�˵�ŵ���
    }
    else
    {
      len_ += *buf; //������λ���ƽ�
      buf += *buf;
    }

  }

}

unsigned char CH375_KEY_FXBGMSF(unsigned char device, int len, unsigned char* buf) //�������̱���������,�����ɹ����ط�0,deviceѡ���豸,lenΪ��������������,bufΪ����������������
{

unsigned char Collection_Application;
unsigned char Collection_Physical;
unsigned char Report_ID;
unsigned char Usage_Page;
unsigned char Usage_Minimum;
unsigned int Usage_Maximum;
unsigned char Logical_Minimum;
unsigned int Logical_Maximum;
unsigned char Report_Size;
unsigned char Report_Count;
unsigned char Input;
unsigned char Output;
unsigned char p;
unsigned char i;

    if (len > 0 && buf[0] == 0x05 && buf[1] = 0x01 && buf[2] = 0x09 && buf[3] = 0x06) //Usage Page (Generic Desktop) & Usage (Keyboard)
    {
        Collection_Application = 0;
        Collection_Physical = 0;
        Report_ID = 0;
        Usage_Page = 0;
        Usage_Minimum = 0;
        Usage_Maximum = 0;
        Logical_Minimum = 0;
        Logical_Maximum = 0;
        Report_Size = 0;
        Report_Count = 0;
        Input = 0;
        Output = 0;
        p = 0;
        buf += 4;
        len -= 4;

        do
        {
            i = (buf[0] & 0x03) + 1; //��ȡ��Ŀ����

            if (buf[0] == 0xa1 && buf[1] == 0x01) //Collection (Application)
            {
                Collection_Application = 1;
            }
            else if (buf[0] == 0x05) //Usage Page
            {
                Usage_Page = buf[1];
            }
            else if (buf[0] == 0x19) //Usage Minimum
            {
                Usage_Minimum = buf[1];
            }
            else if (buf[0] == 0x29) //Usage Maximum
            {
                Usage_Maximum = buf[1];
            }
            else if (buf[0] == 0x2a) //Usage Maximum (2)
            {
                Usage_Maximum = ((Usage_Maximum = buf[2]) << 8) | buf[1];
            }
            else if (buf[0] == 0x15) //Logical Minimum
            {
                Logical_Minimum = buf[1];
            }
            else if (buf[0] == 0x25) //Logical Maximum
            {
                Logical_Maximum = buf[1];
            }
            else if (buf[0] == 0x16) //Logical Minimum (2)
            {
                Logical_Minimum = ((Logical_Minimum = buf[2]) << 8) | buf[1];
            }
            else if (buf[0] == 0x26) //Logical Maximum (2)
            {
                Logical_Maximum = ((Logical_Maximum = buf[2]) << 8) | buf[1];
            }
            else if (buf[0] == 0x75) //Report Size
            {
                Report_Size = buf[1];
            }
            else if (buf[0] == 0x95) //Report Count
            {
                Report_Count = buf[1];
            }
            else if (buf[0] == 0x81) //Input
            {
                if (Usage_Page == 0x07) //Usage Page(Keyboard / Keypad)
                {
                    if (Input == 0x02 && buf[1] == 0x01) //������
                    {
                        if (Report_Size != 8 || Report_Count != 1) break;
                    }
                    else if (Report_Size == 1 && Report_Count == 8 && Logical_Minimum == 0x00 && Logical_Maximum == 0x01 && Usage_Minimum == 0xe0 && Usage_Maximum == 0xe7) //����Keyboard Left Control && Keyboard Right GUI
                    {
                        CH375_KEY_BYTE_ADDR_Left_control_Right_GUI[device] = p;
                        p += 1;
                    }
                    else if (Report_Size == 8 && Report_Count == 6 && Logical_Minimum == 0x00 && Logical_Maximum > 1 && Usage_Minimum == 0x00) //������̵�6����
                    {
                        CH375_KEY_BYTE_ADDR_VALUE_6[device] = p;
                        p += 6;
                    }
                    else break;
                }
                else break;

                Input = buf[1];
            }
            else if (buf[0] == 0x91) //Output
            {
                if (Usage_Page == 0x08) //Usage Page (LEDs)
                {
                    if (Report_Size * Report_Count > 8) //����һ���ֽ�
                    {
                        break;
                    }
                    else if (Output == 0x02 && buf[1] == 0x01) //������
                    {
                    }
                    else //����LEDs
                    {
                        CH375_KEY_BYTE_ADDR_LEDs[device] = p;
                        p += 1;
                    }
                }
                else break;

                Output = buf[1];
            }
            else if (buf[0] == 0xc0) //End Collection
            {
                if (Collection_Application != 0 && p <= CH375_KEY_MaxPacketSize[device]) return 1;
                else break;
            }
            else break;

            buf += i;
            len -= i;

        } while (len > 0);
    }

    return 0;
}

unsigned char CH375_MOUSE_FXBGMSF(unsigned char device, int len, unsigned char* buf) //������걨��������,�����ɹ����ط�0,deviceѡ���豸,lenΪ��������������,bufΪ����������������
{

unsigned char Collection_Application;
unsigned char Collection_Physical;
unsigned char Report_ID;
unsigned char Usage_Page;
unsigned char Usage[3];
unsigned char Usage_num;
unsigned char Usage_num_;
unsigned char Usage_Minimum;
unsigned int Usage_Maximum;
unsigned char Logical_Minimum;
unsigned int Logical_Maximum;
unsigned char Report_Size;
unsigned char Report_Count;
unsigned char Input;
unsigned char Output;
unsigned char p;
unsigned char i;


    if (len > 0 && buf[0] == 0x05 && buf[1] = 0x01 && buf[2] = 0x09 && buf[3] = 0x02) //Usage Page (Generic Desktop) & Usage (Mouse)
    {
        Collection_Application = 0;
        Collection_Physical = 0;
        Report_ID = 0;
        Usage_Page = 0;
        Usage_num = 0;
        Usage_Minimum = 0;
        Usage_Maximum = 0;
        Logical_Minimum = 0;
        Logical_Maximum = 0;
        Report_Size = 0;
        Report_Count = 0;
        Input = 0;
        Output = 0;
        p = 0;
        buf += 4;
        len -= 4;

        do
        {
            i = (buf[0] & 0x03) + 1; //��ȡ��Ŀ����

            if (buf[0] == 0xa1 && buf[1] == 0x01) //Collection (Application)
            {
                Collection_Application = 1;
            }
            else if (buf[0] == 0xa1 && buf[1] == 0x00) //Collection (Physical)
            {
                Usage_num = 0;
                Collection_Physical = 1;
            }
            else if (buf[0] == 0x85) //Report ID
            {
                Report_ID = buf[1];
                p += 8;
            }
            else if (buf[0] == 0x05) //Usage Page
            {
                Usage_Page = buf[1];
            }
            else if (buf[0] == 0x09) //Usage
            {
                Usage[Usage_num] = buf[1];
                if (++Usage_num == 4) break;
            }
            else if (buf[0] == 0x19) //Usage Minimum
            {
                Usage_Minimum = buf[1];
            }
            else if (buf[0] == 0x29) //Usage Maximum
            {
                Usage_Maximum = buf[1];
            }
            else if (buf[0] == 0x2a) //Usage Maximum (2)
            {
                Usage_Maximum = ((Usage_Maximum = buf[2]) << 8) | buf[1];
            }
            else if (buf[0] == 0x15) //Logical Minimum
            {
                Logical_Minimum = buf[1];
            }
            else if (buf[0] == 0x25) //Logical Maximum
            {
                Logical_Maximum = buf[1];
            }
            else if (buf[0] == 0x16) //Logical Minimum (2)
            {
                Logical_Minimum = ((Logical_Minimum = buf[2]) << 8) | buf[1];
            }
            else if (buf[0] == 0x26) //Logical Maximum (2)
            {
                Logical_Maximum = ((Logical_Maximum = buf[2]) << 8) | buf[1];
            }
            else if (buf[0] == 0x75) //Report Size
            {
                Report_Size = buf[1];
            }
            else if (buf[0] == 0x95) //Report Count
            {
                Report_Count = buf[1];
            }
            else if (buf[0] == 0x81) //Input
            {
                if (Usage_Page == 0x09) //Usage Page (Button)
                {
                    if (Input == 0x02 && buf[1] == 0x01) //������
                    {
                        p += Report_Size * Report_Count;
                    }
                    else if (Logical_Minimum == 0x00 && Logical_Maximum == 0x01 && Usage_Minimum == 1 && Usage_Maximum > 1) //����Usage Page (Button)
                    {
                        CH375_MOUSE_BIT_ADDR_Button[device] = p;
                        CH375_MOUSE_BIT_SIZE_Button[device] = Report_Size * Report_Count;
                        p += Report_Size * Report_Count;
                    }
                    else break;
                }
                else if (Usage_Page == 0x01) //Usage Page (Generic Desktop)
                {
                    if (Usage_num != 0 && Usage_num < 4 && Report_Count == Usage_num)
                    {
                        Usage_num_ = 0;

                        do
                        {
                            if (Usage[Usage_num_] == 0x30) //X
                            {
                                CH375_MOUSE_BIT_ADDR_X[device] = p;
                                CH375_MOUSE_BIT_SIZE_X[device] = Report_Size;
                            }
                            else if (Usage[Usage_num_] == 0x31) //Y
                            {
                                CH375_MOUSE_BIT_ADDR_Y[device] = p;
                                CH375_MOUSE_BIT_SIZE_Y[device] = Report_Size;
                            }
                            else if (Usage[Usage_num_] == 0x38) //(Wheel)
                            {
                                CH375_MOUSE_BIT_ADDR_Wheel[device] = p;
                                CH375_MOUSE_BIT_SIZE_Wheel[device] = Report_Size;
                            }

                            p += Report_Size;

                        } while (++Usage_num_ != Usage_num);

                        Usage_num = 0;
                    }
                    else break;
                }
                else
                {
                    p += Report_Size * Report_Count;
                }

                Input = buf[1];
            }
            else if (buf[0] == 0xc0) //End Collection
            {
                if (Collection_Physical != 0) Collection_Physical = 0;
                else if (Collection_Application != 0 && p <= (CH375_MOUSE_MaxPacketSize[device] << 3)) return 1;
                else break;
            }

            buf += i;
            len -= i;

        } while (len > 0);
    }

    return 0;
}


unsigned int CH375_BIT_TQ(unsigned char addr, char Bit_width, unsigned char *buf) //λ��ȡ,addrλ��ַ,Bit_widthλ��,buf������,����ֵΪ��ȡ��λ
{

unsigned char Bit_offset; //λƫ��
unsigned char Byte_offset; //�ֽ�ƫ��
unsigned char outbuf[2];
unsigned int Bit_16;
unsigned char js1;

    Bit_offset = addr % 8;
    Byte_offset = addr / 8;
    outbuf[0] = 0;
    outbuf[1] = 0;
    js1 = 0;

    while (Bit_width > 0)
    {
        outbuf[js1] = buf[Byte_offset] >> Bit_offset;
        outbuf[js1] |= buf[++Byte_offset] << (8 - Bit_offset);
        if (Bit_width < 8) outbuf[js1] = ~(0xfe << (Bit_width - 1)) & outbuf[js1];
        ++js1;
        Bit_width -= 8;
    }

    return ((Bit_16 = outbuf[1]) << 8) | outbuf[0];

}


unsigned char CH375_RUN()
{

unsigned char i;
unsigned char device;
unsigned int js1;

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

              if(i == 0x14) //����ִ�гɹ�
              {

                  if ((CH375_SBDM[device] & 0x01) != 0 && CH375_CURRENT_DDH[device] == CH375_KEY_DDH[device]) //���̶˵������
                  {

                      CH375_RD_bufDATA(device, CH375_DATAbuf); //������������

                      KEY_DATA[0] = CH375_DATAbuf[CH375_KEY_BYTE_ADDR_Left_control_Right_GUI[device]];
                      KEY_DATA[1] = CH375_DATAbuf[CH375_KEY_BYTE_ADDR_LEDs[device]];
                      i = CH375_KEY_BYTE_ADDR_VALUE_6[device];
                      KEY_DATA[2] = CH375_DATAbuf[i++];
                      KEY_DATA[3] = CH375_DATAbuf[i++];
                      KEY_DATA[4] = CH375_DATAbuf[i++];
                      KEY_DATA[5] = CH375_DATAbuf[i++];
                      KEY_DATA[6] = CH375_DATAbuf[i++];
                      KEY_DATA[7] = CH375_DATAbuf[i];
                  }
                  else if ((CH375_SBDM[device] & 0x02) != 0 && CH375_CURRENT_DDH[device] == CH375_MOUSE_DDH[device]) //���˵������
                  {
                      CH375_RD_bufDATA(device, CH375_DATAbuf); //������������

                      SB_KEY = CH375_BIT_TQ(CH375_MOUSE_BIT_ADDR_Button[device], CH375_MOUSE_BIT_SIZE_Button[device], CH375_DATAbuf);
                      SB_X += CH375_BIT_TQ(CH375_MOUSE_BIT_ADDR_X[device], CH375_MOUSE_BIT_SIZE_X[device], CH375_DATAbuf);
                      SB_Y += CH375_BIT_TQ(CH375_MOUSE_BIT_ADDR_Y[device], CH375_MOUSE_BIT_SIZE_Y[device], CH375_DATAbuf);
                      SB_Z += CH375_BIT_TQ(CH375_MOUSE_BIT_ADDR_Wheel[device], CH375_MOUSE_BIT_SIZE_Wheel[device], CH375_DATAbuf);

                      SB_X = (SB_X << (16 - CH375_MOUSE_BIT_SIZE_X[device])) >> (16 - CH375_MOUSE_BIT_SIZE_X[device]);
                      SB_Y = (SB_Y << (16 - CH375_MOUSE_BIT_SIZE_Y[device])) >> (16 - CH375_MOUSE_BIT_SIZE_Y[device]);
                      SB_Z = (SB_Z << (16 - CH375_MOUSE_BIT_SIZE_Wheel[device])) >> (16 - CH375_MOUSE_BIT_SIZE_Wheel[device]);
                      
                      if (SB_X > 255) SB_X = 255;
                      else if (SB_X < 0) SB_X = 0;
                      if (SB_Y > 239) SB_Y = 239;
                      else if (SB_Y < 0) SB_Y = 0;
                      if (SB_Z > 255) SB_Z = 255;
                      else if (SB_Z < 0) SB_Z = 0;
                  }

                  CH375_INDX[device] = ~CH375_INDX[device];
                  //SPI_SET_DLED(0xe0); //SPI���ݵ���ʾ����
              }
              else if(i == 0x15) //�豸����
              {
                  CH375_SBIOBZ = 1; //��־���豸����
                  i = (CH375_GET_DEV_RATE(device) & 0x10) >> 3; //��ȡUSB�豸����
                  CH375_SET_USB_MODE(device,0x07); //��λUSB����
                  CH375_SET_USB_MODE(device,0x06);  //����Ϊ����ģʽ
                  CH375_SET_USB_BUSM(device, i); //����USB�����ٶ�
                  
                  if (CH375_GET_SBMSF(device,CH375_DATAbuf) != 0) //��ȡ�豸������
                  {
                      if ((js1 = CH375_GET_PZMSF(device, CH375_DATAbuf)) != 0) //��ȡ����������
                      {
                          CH375_FXPZMSF(device, js1, CH375_DATAbuf); //��������������

                          if ((CH375_SBDM[device] & 0x03) != 0) //�豸Ϊ���̻����
                          {
                              if (CH375_AUTO_SETUP(device) != 0) //�Զ�����USB�豸
                              {
                                  CH375_INDX[device] = 0; //����DATA0

                                  if ((CH375_SBDM[device] & 0x01) != 0) //����
                                  {
                                      if (CH375_GET_BGMSF(device, CH375_KEY_InterfaceNumber[device], CH375_KEY_Report_len[device], CH375_DATAbuf) != 0) //��ȡ����������
                                      {
                                          if (CH375_KEY_FXBGMSF(device, CH375_KEY_Report_len[device], CH375_DATAbuf) != 0) //�������̱���������
                                          {
                                              CH375_CURRENT_DDH[device] = CH375_KEY_DDH[device];
                                          }
                                          else
                                          {
                                              CH375_SBDM[device] = CH375_SBDM[device] & ~0x01; //���̱�־��0
                                          }
                                          
                                      }
                                      else
                                      {
                                          CH375_SBDM[device] = CH375_SBDM[device] & ~0x01; //���̱�־��0
                                      }
                                  }

                                  if ((CH375_SBDM[device] & 0x02) != 0)//���
                                  {
                                      if (CH375_GET_BGMSF(device, CH375_MOUSE_InterfaceNumber[device], CH375_MOUSE_Report_len[device], CH375_DATAbuf) != 0) //��ȡ����������
                                      {
                                          if (CH375_MOUSE_FXBGMSF(device, CH375_MOUSE_Report_len[device], CH375_DATAbuf) != 0) //������걨��������
                                          {
                                              CH375_CURRENT_DDH[device] = CH375_MOUSE_DDH[device];
                                          }
                                          else
                                          {
                                              CH375_SBDM[device] = CH375_SBDM[device] & ~0x02; //����־��0
                                          }
                                      }
                                      else
                                      {
                                          CH375_SBDM[device] = CH375_SBDM[device] & ~0x02; //����־��0
                                      }
                                  }
                              }
                              else
                              {
                                  CH375_SBDM[device] = 0; //û���豸
                              }
                          }
                          else //���Ǽ��̻����
                          {
                              if (CH375_DISK_INIT(device) != 0) //��ʼ��USB�洢�豸
                              {
                                  CH375_SBDM[device] |= 0x04; //��λ�豸����, �洢�豸
                                  //SPI_SET_DLED(0xe1); //SPI���ݵ���ʾ����
                              }
                              else
                              {
                                  //SPI_SET_DLED(0xe2); //SPI���ݵ���ʾ����
                              }
                          }
                      }
                  }
              }
              else if(i == 0x16) //�豸�γ�
              {
                  CH375_SBIOBZ = 2; //��־���豸�γ�
                  CH375_SBDM[device] = 0; //�豸�����־Ϊ���豸
                  CH375_SET_USB_MODE(device,0x05); //05H������ʽ������SOF��
                  //SPI_SET_DLED(0xe2); //SPI���ݵ���ʾ����
              }
              else //�����¼�
              {
                  //SPI_SET_DLED(0xec);
              }
          }

          if ((CH375_SBDM[device] & 0x03) != 0) //�м�������豸
          {
              if (CH375_SBDM[device] == 0x03) //�������ͬʱ����
              {
                  CH375_ABORT_NAK(device);
                  for (js1 = 0; js1 < 32; ++js1);
                  if (CH375_CURRENT_DDH[device] == CH375_KEY_DDH[device]) CH375_CURRENT_DDH[device] = CH375_MOUSE_DDH[device]; //�������˵���л�
                  else CH375_CURRENT_DDH[device] = CH375_KEY_DDH[device];
              }

              CH375_USB_IN(device, CH375_INDX[device], CH375_CURRENT_DDH[device]); //ִ��IN����
          }

          ++device; //��һ���豸

      }while(device != 4);

      CH375_CT2_ = CT2; //��¼��ǰӲ������������
  }

  return CH375_INTT;

}





unsigned char CH375_DISK_READ(unsigned char device,unsigned long int SQH,unsigned char LBAX) //��USB�洢���豸��ȡ���ݿ�����, deviceѡ���豸,SQH��������,LBAX�Ƕ�ȡ��������,����ֵ��Ϊ0��ʾ�����ɹ�
{

  if(CH375_device_bz[device] == 1 && (CH375_SBDM[device] & 0x04) != 0) ///CH375оƬ���ڲ����豸�Ǵ洢��,����
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

     CH375_HOLD_INT(device); //����������ж�

     if(CH375_RD_INTDATA(device) == 0x1d) //���ɹ�
     {
         SPI_SET_DLED(0xaa);
        return 1;
     }

     SPI_SET_DLED(0x55);
  }else SPI_SET_DLED(CH375_SBDM[device]);

  return 0;

}


unsigned char CH375_DISK_RD_GO(unsigned char device) //������USB�洢���豸���ݿ�����,deviceѡ���豸,����ֵ��Ϊ0��ʾ�����ɹ�
{

unsigned char i;

  if(CH375_device_bz[device] == 1 && (CH375_SBDM[device] & 0x04) != 0) //CH375оƬ���ڲ����豸�Ǵ洢��,����
  {

     CS_8080 = 0x08|device; //ѡ��8080�����豸
     D1_8080 = 0x55; //д����
     CS_8080 = 0x00; //ѡ�п��豸

     CH375_HOLD_INT(device); //����������ж�

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

  if(CH375_device_bz[device] == 1 && (CH375_SBDM[device] & 0x04) != 0) //CH375оƬ���ڲ����豸�Ǵ洢��,����
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


     CH375_HOLD_INT(device); //����������ж�

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

  if(CH375_device_bz[device] == 1 && (CH375_SBDM[device] & 0x04) != 0) //CH375оƬ���ڲ����豸�Ǵ洢��,����
  {

     CS_8080 = 0x08|device; //ѡ��8080�����豸
     D1_8080 = 0x57; //д����
     CS_8080 = 0x00; //ѡ�п��豸

     CH375_HOLD_INT(device); //����������ж�

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
unsigned char js2;
unsigned char js3 = 0;


    do
    {
        js2 = 1;
        while (js2 != 0)
        {
            if ((CH375_SBDM[js1] & js2) != 0) ++js3;
            js2 <<= 1;
        }

    } while (++js1 != 4);
    
    return js3;
}



