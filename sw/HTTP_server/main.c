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

  SPI_RST();	//SPI������λ

  SPI_S = 0x04;
  SPI_D = 0x11;
  SPI_S = 0x01;

  for(k = 0;k < 61000;k++);

  TF_chushihua();	 //�ڴ濨��ʼ��

  SPI_S = 0x04;
  SPI_D = 0x22;
  SPI_S = 0x01;

  for(k = 0;k < 61000;k++);

  FAT32_tiquyindaoxinxi(); //�ڴ濨FAT32������Ϣ��ȡ

  SPI_S = 0x04;
  SPI_D = 0x33;
  SPI_S = 0x01;

  for(k = 0;k < 61000;k++);



  TCP_Cqingling();  //TCP���ƿ���0

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

  ENC28J60_BFS(0x1f,0x04);  //ECON1.RXENλ��1  ��������
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