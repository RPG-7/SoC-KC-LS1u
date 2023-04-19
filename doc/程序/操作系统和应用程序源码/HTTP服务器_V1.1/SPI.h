void SPI_WIDLE_IDLE() //等待SPI空闲
{
  while((SPI_INT & 0x80) != 0x80);
}

void SPI_RST()	 //SPI控制信号和发送单元复位
{

  SPI_S = 0x01; //解锁SPI收发器
  SPI_D = 0xff; //SPI收发器写入1个字节 进入就绪状态
  SPI_WIDLE_IDLE(); //等待SPI空闲

}

void SPI_SET_DLED(unsigned char data)
{

  SPI_S = 0x04;
  SPI_D = data;
  SPI_S = 0x01;

}