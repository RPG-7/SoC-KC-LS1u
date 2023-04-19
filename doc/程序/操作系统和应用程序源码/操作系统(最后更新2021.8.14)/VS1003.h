

unsigned char VS1003_SPIDX(unsigned char data) //IOģ��SPI,��VS1003����һ���ֽ�
{

unsigned char i = 0;
unsigned char rdata = 0;

   do
   {
       rdata <<= 1;
       rdata |= (CTVGA_C >> 3) & 0x01;

       if(data & 0x80)
       {
           CTVGA_C = 0x07;
           CTVGA_C = 0x0f;
           CTVGA_C = 0x07;
       }
       else
       {
           CTVGA_C = 0x06;
           CTVGA_C = 0x0e;
           CTVGA_C = 0x07;
       }
       data <<= 1;

   }while(++i != 8);

   return rdata;

}



/*
unsigned char VS1003_SPIDX(unsigned char data) //IOģ��SPI,��VS1003����һ���ֽ�
{


  SPI_D = data;
  while((SPI_INT & 0x80) != 0x80);

   return SPI_D;

}
*/


/*

void VS1003_SPIDI(unsigned char data) //IOģ��SPI,SDI������ʱ��,ʹ�ô˺���д1���ֽ�
{

  SPI_D = data;
  while((SPI_INT & 0x80) != 0x80);

}

*/





void VS1003_SPIDI(unsigned char data) //IOģ��SPI,SDI������ʱ��,ʹ�ô˺���д1���ֽ�
{

   _B = data;
   _A2 = 0xc0;
   _A0 = 0x0c;
   _NOP;
   _A = 0x03;


   _RAM = _A_BH << 1;
   _A = 0x07;
   _RAM = _A_BH << 1;
   _A = 0x03;
   _RAM = _A_BH << 1;
   _B = _B << 1;

   _RAM = _A_BH << 1;
   _A = 0x07;
   _RAM = _A_BH << 1;
   _A = 0x03;
   _RAM = _A_BH << 1;
   _B = _B << 1;

   _RAM = _A_BH << 1;
   _A = 0x07;
   _RAM = _A_BH << 1;
   _A = 0x03;
   _RAM = _A_BH << 1;
   _B = _B << 1;

   _RAM = _A_BH << 1;
   _A = 0x07;
   _RAM = _A_BH << 1;
   _A = 0x03;
   _RAM = _A_BH << 1;
   _B = _B << 1;

   _RAM = _A_BH << 1;
   _A = 0x07;
   _RAM = _A_BH << 1;
   _A = 0x03;
   _RAM = _A_BH << 1;
   _B = _B << 1;

   _RAM = _A_BH << 1;
   _A = 0x07;
   _RAM = _A_BH << 1;
   _A = 0x03;
   _RAM = _A_BH << 1;
   _B = _B << 1;

   _RAM = _A_BH << 1;
   _A = 0x07;
   _RAM = _A_BH << 1;
   _A = 0x03;
   _RAM = _A_BH << 1;
   _B = _B << 1;

   _RAM = _A_BH << 1;
   _A = 0x07;
   _RAM = _A_BH << 1;
   _B = 0x80;
   _A = 0x03;
   _RAM = _A_BH << 1;


}




unsigned int VS1003_RD(unsigned char addr)  //��VS1003�Ĵ���, addr�Ĵ�����ַ, ����ֵΪ16λ��
{

unsigned int i;

   while((SPI_INT & 0x02) == 0); //�ж�VS1003��DREQ��,Ϊ�͵�ƽʱVS1003æ,�ȴ�����ʱ����

   SPI_CS = 0x4a; //ѡ��VS1003��XCSƬѡ��(SCI�����Ƕ�дVS10003�ļĴ���)

   VS1003_SPIDX(0x03);
   VS1003_SPIDX(addr);
   i = VS1003_SPIDX(0xff);
   i <<= 8;
   i |= VS1003_SPIDX(0xff);

   SPI_CS = 0; //ѡ�п��豸,����VS1003Ƭѡ

   return i; //���ض�����16λ�Ĵ�������

}


void VS1003_WR(unsigned char addr,unsigned int data)  //дVS1003�Ĵ���, addr�Ĵ�����ַ, dataΪ16λ��
{

   while((SPI_INT & 0x02) == 0); //�ж�VS1003��DREQ��,Ϊ�͵�ƽʱVS1003æ,�ȴ�����ʱ����

   SPI_CS = 0x4a; //ѡ��VS1003��XCSƬѡ��(SCI�����Ƕ�дVS10003�ļĴ���)

   VS1003_SPIDX(0x02);
   VS1003_SPIDX(addr);
   VS1003_SPIDX(data >> 8);
   VS1003_SPIDX(data);

   SPI_CS = 0; //ѡ�п��豸,����VS1003Ƭѡ

}


void VS1003_WR512B(unsigned char *buf)  //дVS1003�Ĵ���, addr�Ĵ�����ַ, dataд������
{

unsigned char i = 0;
unsigned char j;

   while(i != 16)
   {
       if((SPI_INT & 0x02) == 0x02) //�ж�VS1003��DREQ��,Ϊ�͵�ƽʱVS1003æ,�ȴ�����ʱ����
       {
           SPI_CS = 0x4b; //ѡ��VS1003��XDCSƬѡ��(SDI������������)
           for(j = 0;j != 32;++j) VS1003_SPIDI(*buf),++buf; //����32�ֽ����ݵ�VS1003
           SPI_CS = 0; //ѡ�п��豸,����VS1003Ƭѡ
           ++i;
       }
   }

}



void VS1003_CSH() //��ʼ��VS1003
{

  VS1003_WR(0x03,0x9800); //����ʱ�Ӻͱ�Ƶ(����)

  VS1003_WR(0x0b,0x0000); //��������

}
