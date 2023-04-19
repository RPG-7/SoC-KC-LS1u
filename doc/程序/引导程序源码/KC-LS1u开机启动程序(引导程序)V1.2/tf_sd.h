unsigned char TF_SD_CSH(unsigned char device) //TF/SD卡初始化, 如果初始化成功返回值不为0, device选择SPI设备, 0为0号内存卡,1为1号内存卡
{
  unsigned int x;

//////////////////复位为SPI模式//////////////////     

  SPI_CS = 0x10;  //SPI速率设置为4分频 并选中空设备
  
  for(x = 0;x != 8;++x)SPI_D = 0xff; //发送80个时钟


  SPI_CS = device & 0x01 | 0x18; //设置速率并选中内存卡

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

  SPI_S = 0x02; //SPI输出1

  x = 16; //读16次不成功跳出
  while(SPI_D != 0x01 && x != 0) //读到0x01或超出限定读次数时跳出
  {
     while((SPI_INT & 0x80) != 0x80);
     --x;
  }

  if(x != 0)
  {

///////////////////初始化/////////////////////////

     x = 65535; //初始化65535次不成功跳出

     while(SPI_D != 0x00 && x != 0)
     {

        SPI_S = 0x01; //SPI关闭输出1

        SPI_CS = 0x10; //选中空设备

        SPI_D = 0xff;   //填充8个时钟
        while((SPI_INT & 0x80) != 0x80);

        SPI_CS = device & 0x01 | 0x18; //设置速率并选中内存卡

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

        SPI_S = 0x02; //SPI输出1

        SPI_D = 0xff;
        while((SPI_INT & 0x80) != 0x80);
        SPI_D = 0xff;
        while((SPI_INT & 0x80) != 0x80);

        --x;
     }

  }

  SPI_S = 0x01; //SPI关闭输出1

  SPI_CS = 0x00; //选中空设备
  SPI_D = 0xff;


  return x;

}




unsigned char TF_SD_RD_512B(unsigned char device,unsigned long int SQH,unsigned char *RAMaddr)  //SQDZ为扇区号, RAMaddr为读出数据写入内存的首地址, device选择设备, 0为0号内存卡,1为1号内存卡,如果操作成功返回值不为0
{

  unsigned char x,y;

  SQH <<= 1;

  SPI_CS = device & 0x01 | 0x18; //设置速率并选中内存卡

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

  SPI_S = 0x02; //SPI输出1

  x = 255;
  while(x != 0 && SPI_D != 0x00) //读到应答标志0x00跳出
  {
    while((SPI_INT & 0x80) != 0x80);
    --x;
  }

  while(x != 0 && SPI_D != 0xfe)
  {
    while((SPI_INT & 0x80) != 0x80); //读到扇区数据起始标志0xfe跳出
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

  SPI_S = 0x01; //SPI关闭输出1

  SPI_CS = 0x00; //选中空设备
  SPI_D = 0xff;

  return x;

}


