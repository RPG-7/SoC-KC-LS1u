#include<io.h>
#include<qjbldy.h>
#include<sys_in_boot.h>
#include<ds1302.h>
#include<spi.h>
#include<VGA.h>
#include<string.h>
#include<printing.h>
#include<KEY.h>
#include<CH375.h>
#include<TF.h>
#include<FAT32.h>
#include<ENC28J60.h>
#include<TCP_IP_HTTP.h>



main()
{


unsigned char Mx;  //计数用
unsigned int My;  //计数用
unsigned char MS; //保存秒数
unsigned char MS_J; //计数用



  SPI_RST();	//SPI部件复位
  CH375_CSH(); //初始化CH375

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


  if((DS1302_RD(0) & 0x80) == 0x80) DS1302_WR(0,0); //如果DS1302暂停,则开启

/*
  DS1302_WR(0,0); //修改秒
  DS1302_WR(1,5); //修改分钟
  DS1302_WR(2,0x12); //修改时
  DS1302_WR(3,0x08); //修改日
  DS1302_WR(4,0x05); //修改月
  DS1302_WR(5,0x07); //修改星期
  DS1302_WR(6,0x16); //修改年
*/

  VGA_VRAM_LD();
  printx(0,0,"HTTP server is running...",255);
  printx(14,0,"MAC : 61:61:61:61:70",255);
  printx(28,0,"IP : 192.168.1.77",255);
  printx(42,0,"Back Please click the right mouse button.",255);
  printx(42+14,0,"TX : ",255);
  printx(42+14+14,0,"RX : ",255);
  printx(42+14+14+14,0,"TCP : ",255);
  VGA_VRAM_UP();

  while(1)
  {

    TCP_IP_HTTP_RUN();

    if(CH375_RUN())
    {
        if(SB_KEY & 0x02) sys_in_boot_0(); //按下鼠标右键返回操作系统
    }



    Mx = 0;
    for(My = 0;My != TCP_IIS*52;My += 52) if(TCP_C[My] != 0x00) ++Mx;  //查询TCP连接数
    if(Mx != 0) QSJJ += 20;
    ++QSJJ;

    if(QSJJ > 5000)
    {
       SPI_S = 0x04;
       SPI_D = DS1302_RD(0);
       SPI_S = 0x01;
       QSJJ = 0;



       if(DS1302_RD(0) != MS)
       {
           MS = DS1302_RD(0);
           ++MS_J;

           if(MS_J > 2)
           {

                MS_J = 0;

                VGA_VRAM_LD();

                VGA_SK1(42+14,6*5,14,6*10,0x00);
                VGA_SK1(42+14+14,6*5,14,6*10,0x00);
                VGA_SK1(42+14+14+14,6*6,14,6*3,0x00);

                printx(42+14,6*5,U32_str(TX_X),255);
                printx(42+14+14,6*5,U32_str(RX_X),255);
                printx(42+14+14+14,6*6,U32_str(Mx),255);
                VGA_VRAM_UP();
            }


        }



    }


  }

}