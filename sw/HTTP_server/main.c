#include<qjbldy.h>
#include<io.h>
#include<ds1302.h>
#include<spi.h>
#include<TF.h>
#include<FAT32.h>
#include<ENC28J60.h>
#include<TCP_IP_HTTP.h>



main()
{

  SPI_RST();	//SPI部件复位

  SPI_S = 0x04;
  SPI_D = 0x11;
  SPI_S = 0x01;

  for(k = 0;k < 61000;k++);

  TF_chushihua();	 //内存卡初始化

  SPI_S = 0x04;
  SPI_D = 0x22;
  SPI_S = 0x01;

  for(k = 0;k < 61000;k++);

  FAT32_tiquyindaoxinxi(); //内存卡FAT32引导信息提取

  SPI_S = 0x04;
  SPI_D = 0x33;
  SPI_S = 0x01;

  for(k = 0;k < 61000;k++);



  TCP_Cqingling();  //TCP控制块清0

  ENC28J60_RST();

  SPI_S = 0x04;
  SPI_D = 0x44;
  SPI_S = 0x01;

  for(k = 0;k < 61000;k++);

  ENC28J60_chushihua();

  SPI_S = 0x04;
  SPI_D = 0x55;
  SPI_S = 0x01;

  for(k = 0;k < 61000;k++);

  ENC28J60_BFS(0x1f,0x04);  //ECON1.RXEN位置1  启动接收
  DS1302_WR(0,0);

  while(1)
  {

    TCP_IP_HTTP_RUN();

    ++QSJJ;
    if(QSJJ > 25000)
    {
       SPI_S = 0x04;
       SPI_D = DS1302_RD(0);
       SPI_S = 0x01;
       QSJJ = 0;
    }

  }

}