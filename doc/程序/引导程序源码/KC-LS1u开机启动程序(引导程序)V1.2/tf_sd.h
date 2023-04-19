unsigned char TF_SD_CSH(unsigned char device) //TF/SD����ʼ��, �����ʼ���ɹ�����ֵ��Ϊ0, deviceѡ��SPI�豸, 0Ϊ0���ڴ濨,1Ϊ1���ڴ濨
{
  unsigned int x;

//////////////////��λΪSPIģʽ//////////////////     

  SPI_CS = 0x10;  //SPI��������Ϊ4��Ƶ ��ѡ�п��豸
  
  for(x = 0;x != 8;++x)SPI_D = 0xff; //����80��ʱ��


  SPI_CS = device & 0x01 | 0x18; //�������ʲ�ѡ���ڴ濨

  SPI_D = 0x40;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x00;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x00;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x00;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x00;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x95;
  while((SPI_INT & 0x80) != 0x80);

  SPI_S = 0x02; //SPI���1

  x = 16; //��16�β��ɹ�����
  while(SPI_D != 0x01 && x != 0) //����0x01�򳬳��޶�������ʱ����
  {
     while((SPI_INT & 0x80) != 0x80);
     --x;
  }

  if(x != 0)
  {

///////////////////��ʼ��/////////////////////////

     x = 65535; //��ʼ��65535�β��ɹ�����

     while(SPI_D != 0x00 && x != 0)
     {

        SPI_S = 0x01; //SPI�ر����1

        SPI_CS = 0x10; //ѡ�п��豸

        SPI_D = 0xff;   //���8��ʱ��
        while((SPI_INT & 0x80) != 0x80);

        SPI_CS = device & 0x01 | 0x18; //�������ʲ�ѡ���ڴ濨

        SPI_D = 0x41;
        while((SPI_INT & 0x80) != 0x80);
        SPI_D = 0x00;
        while((SPI_INT & 0x80) != 0x80);
        SPI_D = 0x00;
        while((SPI_INT & 0x80) != 0x80);
        SPI_D = 0x00;
        while((SPI_INT & 0x80) != 0x80);
        SPI_D = 0x00;
        while((SPI_INT & 0x80) != 0x80);
        SPI_D = 0xff;
        while((SPI_INT & 0x80) != 0x80);

        SPI_S = 0x02; //SPI���1

        SPI_D = 0xff;
        while((SPI_INT & 0x80) != 0x80);
        SPI_D = 0xff;
        while((SPI_INT & 0x80) != 0x80);

        --x;
     }

  }

  SPI_S = 0x01; //SPI�ر����1

  SPI_CS = 0x00; //ѡ�п��豸
  SPI_D = 0xff;


  return x;

}




unsigned char TF_SD_RD_512B(unsigned char device,unsigned long int SQH,unsigned char *RAMaddr)  //SQDZΪ������, RAMaddrΪ��������д���ڴ���׵�ַ, deviceѡ���豸, 0Ϊ0���ڴ濨,1Ϊ1���ڴ濨,��������ɹ�����ֵ��Ϊ0
{

  unsigned char x,y;

  SQH <<= 1;

  SPI_CS = device & 0x01 | 0x18; //�������ʲ�ѡ���ڴ濨

  SPI_D = 0x51;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = SQH >> 16;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = SQH >> 8;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = SQH;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x00;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0xff;
  while((SPI_INT & 0x80) != 0x80);

  SPI_S = 0x02; //SPI���1

  x = 255;
  while(x != 0 && SPI_D != 0x00) //����Ӧ���־0x00����
  {
    while((SPI_INT & 0x80) != 0x80);
    --x;
  }

  while(x != 0 && SPI_D != 0xfe)
  {
    while((SPI_INT & 0x80) != 0x80); //��������������ʼ��־0xfe����
    --x;
  }

  if(x != 0)
  {
      y = 64;
      while(y != 0)
      {
        *RAMaddr = SPI_D;
        ++RAMaddr;
        *RAMaddr = SPI_D;
        ++RAMaddr;
        *RAMaddr = SPI_D;
        ++RAMaddr;
        *RAMaddr = SPI_D;
        ++RAMaddr;
        *RAMaddr = SPI_D;
        ++RAMaddr;
        *RAMaddr = SPI_D;
        ++RAMaddr;
        *RAMaddr = SPI_D;
        ++RAMaddr;
        *RAMaddr = SPI_D;
        ++RAMaddr;
        --y;
      }
  }

  SPI_D = 0xff;

  SPI_S = 0x01; //SPI�ر����1

  SPI_CS = 0x00; //ѡ�п��豸
  SPI_D = 0xff;

  return x;

}


