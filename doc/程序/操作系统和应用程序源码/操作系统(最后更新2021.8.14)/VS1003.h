

unsigned char VS1003_SPIDX(unsigned char data) //IO模拟SPI,和VS1003交换一个字节
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
unsigned char VS1003_SPIDX(unsigned char data) //IO模拟SPI,和VS1003交换一个字节
{


  SPI_D = data;
  while((SPI_INT & 0x80) != 0x80);

   return SPI_D;

}
*/


/*

void VS1003_SPIDI(unsigned char data) //IO模拟SPI,SDI操作的时候,使用此函数写1个字节
{

  SPI_D = data;
  while((SPI_INT & 0x80) != 0x80);

}

*/





void VS1003_SPIDI(unsigned char data) //IO模拟SPI,SDI操作的时候,使用此函数写1个字节
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




unsigned int VS1003_RD(unsigned char addr)  //读VS1003寄存器, addr寄存器地址, 返回值为16位数
{

unsigned int i;

   while((SPI_INT & 0x02) == 0); //判断VS1003的DREQ线,为低电平时VS1003忙,等待空闲时跳出

   SPI_CS = 0x4a; //选中VS1003的XCS片选线(SCI操作是读写VS10003的寄存器)

   VS1003_SPIDX(0x03);
   VS1003_SPIDX(addr);
   i = VS1003_SPIDX(0xff);
   i <<= 8;
   i |= VS1003_SPIDX(0xff);

   SPI_CS = 0; //选中空设备,撤销VS1003片选

   return i; //返回读出的16位寄存器数据

}


void VS1003_WR(unsigned char addr,unsigned int data)  //写VS1003寄存器, addr寄存器地址, data为16位数
{

   while((SPI_INT & 0x02) == 0); //判断VS1003的DREQ线,为低电平时VS1003忙,等待空闲时跳出

   SPI_CS = 0x4a; //选中VS1003的XCS片选线(SCI操作是读写VS10003的寄存器)

   VS1003_SPIDX(0x02);
   VS1003_SPIDX(addr);
   VS1003_SPIDX(data >> 8);
   VS1003_SPIDX(data);

   SPI_CS = 0; //选中空设备,撤销VS1003片选

}


void VS1003_WR512B(unsigned char *buf)  //写VS1003寄存器, addr寄存器地址, data写入数据
{

unsigned char i = 0;
unsigned char j;

   while(i != 16)
   {
       if((SPI_INT & 0x02) == 0x02) //判断VS1003的DREQ线,为低电平时VS1003忙,等待空闲时进入
       {
           SPI_CS = 0x4b; //选中VS1003的XDCS片选线(SDI操作是数据流)
           for(j = 0;j != 32;++j) VS1003_SPIDI(*buf),++buf; //发送32字节数据到VS1003
           SPI_CS = 0; //选中空设备,撤销VS1003片选
           ++i;
       }
   }

}



void VS1003_CSH() //初始化VS1003
{

  VS1003_WR(0x03,0x9800); //设置时钟和倍频(必须)

  VS1003_WR(0x0b,0x0000); //设置音量

}
