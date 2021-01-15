void SPI_RST()	 //SPI控制信号和发送单元复位
{

  SPI_S = 0x01; //解锁SPI收发器

  SPI_D = 0xff; //SPI收发器写入1个字节 进入就绪状态

}