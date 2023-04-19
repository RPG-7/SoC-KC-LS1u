void DS1302_WR(unsigned char addr,unsigned char data)
{

  unsigned char i;

  XT_C |= 0x08; //DS1302_CS = 1 ����DS1302

  XT_C &=~0x04; //DS1302_DATA = 0 ���Ͷ�д����λ 1��0д

  XT_C |= 0x02; //DS1302_CLK = 1
  XT_C &=~0x02; //DS1302_CLK = 0

  for(i = 0;i != 6;++i) //����6λ��ַ
  {

    XT_C = (XT_C &~0x04) | ((addr & 0x01) << 2);

    XT_C |= 0x02; //DS1302_CLK = 1
    XT_C &=~0x02; //DS1302_CLK = 0

    addr >>= 1;

  }

  XT_C |= 0x04; //DS1302_DATA = 1 ����ֹͣλ1

  XT_C |= 0x02; //DS1302_CLK = 1
  XT_C &=~0x02; //DS1302_CLK = 0


  for(i = 0;i != 8;++i) //����8λ����
  {

    XT_C = (XT_C &~0x04) | ((data & 0x01) << 2);

    XT_C |= 0x02; //DS1302_CLK = 1
    XT_C &=~0x02; //DS1302_CLK = 0

    data >>= 1;

  }

  XT_C &=~0x08; //DS1302_CS = 0 �ر�DS1302

}

unsigned char DS1302_RD(unsigned char addr)
{

  unsigned char i,data = 0;

  XT_C |= 0x08; //DS1302_CS = 1 ����DS1302

  XT_C |= 0x04; //DS1302_DATA = 1 ���Ͷ�д����λ 1��0д

  XT_C |= 0x02; //DS1302_CLK = 1
  XT_C &=~0x02; //DS1302_CLK = 0

  for(i = 0;i != 6;++i) //����6λ��ַ
  {

    XT_C = (XT_C &~0x04) | ((addr & 0x01) << 2);

    XT_C |= 0x02; //DS1302_CLK = 1
    XT_C &=~0x02; //DS1302_CLK = 0

    addr >>= 1;

  }

  XT_C |= 0x04; //DS1302_DATA = 1 ����ֹͣλ1

  for(i = 0;i != 8;++i) //����8λ����
  {

    data >>= 1;
    XT_C |= 0x02; //DS1302_CLK = 1
    XT_C = (XT_C &~0x02) | 0x04; //DS1302_CLK = 0

    if((XT_C & 0x04) == 0x04) data += 0x80;

  }

  XT_C &=~0x08; //DS1302_CS = 0 �ر�DS1302

  return data;

}