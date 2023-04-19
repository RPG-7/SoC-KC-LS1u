void DS1302_WR(unsigned char addr,unsigned char data)
{

  unsigned char i;

  XT_C |= 0x08; //DS1302_CS = 1 启动DS1302

  XT_C &= 0xfb; //DS1302_DATA = 0 发送读写控制位 1读0写

  XT_C |= 0x02; //DS1302_CLK = 1
  XT_C &= 0xfd; //DS1302_CLK = 0

  for(i = 0;i != 6;++i) //发送6位地址
  {

    XT_C = (XT_C & 0xfb) | ((addr & 0x01) << 2);

    XT_C |= 0x02; //DS1302_CLK = 1
    XT_C &= 0xfd; //DS1302_CLK = 0

    addr >>= 1;

  }

  XT_C |= 0x04; //DS1302_DATA = 1 发送停止位1

  XT_C |= 0x02; //DS1302_CLK = 1
  XT_C &= 0xfd; //DS1302_CLK = 0


  for(i = 0;i != 8;++i) //发送8位数据
  {

    XT_C = (XT_C & 0xfb) | ((data & 0x01) << 2);

    XT_C |= 0x02; //DS1302_CLK = 1
    XT_C &= 0xfd; //DS1302_CLK = 0

    data >>= 1;

  }

  XT_C &= 0xf7; //DS1302_CS = 0 关闭DS1302

}

unsigned char DS1302_RD(unsigned char addr)
{

  unsigned char i,data = 0;

  XT_C |= 0x08; //DS1302_CS = 1 启动DS1302

  XT_C |= 0x04; //DS1302_DATA = 1 发送读写控制位 1读0写

  XT_C |= 0x02; //DS1302_CLK = 1
  XT_C &= 0xfd; //DS1302_CLK = 0

  for(i = 0;i != 6;++i) //发送6位地址
  {

    XT_C = (XT_C & 0xfb) | ((addr & 0x01) << 2);

    XT_C |= 0x02; //DS1302_CLK = 1
    XT_C &= 0xfd; //DS1302_CLK = 0

    addr >>= 1;

  }

  XT_C |= 0x04; //DS1302_DATA = 1 发送停止位1

  for(i = 0;i != 8;++i) //接收8位数据
  {

    data >>= 1;
    XT_C |= 0x02; //DS1302_CLK = 1
    XT_C = (XT_C & 0xfd) | 0x04; //DS1302_CLK = 0

    if((XT_C & 0x04) == 0x04) data += 0x80;

  }

  XT_C &= 0xf7; //DS1302_CS = 0 关闭DS1302

  return data;

}


void DS1302_RTC_UP(unsigned char YEAR,unsigned char MONTH,unsigned char DATE,unsigned char HR,unsigned char MIN,unsigned char SEC)  //更新年月日时分秒
{

    DS1302_WR(6,YEAR);
    DS1302_WR(4,MONTH);
    DS1302_WR(3,DATE);
    DS1302_WR(2,HR);
    DS1302_WR(1,MIN);
    DS1302_WR(0,SEC);

}


