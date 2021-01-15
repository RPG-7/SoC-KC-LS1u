void ENC28J60_RCR(unsigned char addr) //ENC28J60读函数  给地址 调用后SPI_D为读出的数据
{

  SPI_CS = 0x09;
  SPI_D = addr;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0xff;
  while((SPI_INT & 0x80) != 0x80);
  SPI_CS = 0x00;

}

void ENC28J60_WCR(unsigned char addr,unsigned char data) //  ENC28J60写函数  给ENC28J60_addr地址 给ENC28J60_data数据 调用后写入
{

  SPI_CS = 0x09;
  SPI_D = addr | 0x40;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = data;
  while((SPI_INT & 0x80) != 0x80);
  SPI_CS = 0x00;

}

void Bank0() //操作ENC28J60第0组寄存器
{

  SPI_CS = 0x09;
  SPI_D = 0xbf;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x03;
  while((SPI_INT & 0x80) != 0x80);
  SPI_CS = 0x00;

}

void Bank1() //操作ENC28J60第1组寄存器
{

  SPI_CS = 0x09;
  SPI_D = 0xbf;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x02;
  while((SPI_INT & 0x80) != 0x80);
  SPI_CS = 0x00;

  SPI_CS = 0x09;
  SPI_D = 0x9f;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x01;
  while((SPI_INT & 0x80) != 0x80);
  SPI_CS = 0x00;

}

void Bank2() //操作ENC28J60第2组寄存器
{

  SPI_CS = 0x09;
  SPI_D = 0xbf;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x01;
  while((SPI_INT & 0x80) != 0x80);
  SPI_CS = 0x00;

  SPI_CS = 0x09;
  SPI_D = 0x9f;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x02;
  while((SPI_INT & 0x80) != 0x80);
  SPI_CS = 0x00;

}

void Bank3() //操作ENC28J60第3组寄存器
{

  SPI_CS = 0x09;
  SPI_D = 0x9f;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x03;
  while((SPI_INT & 0x80) != 0x80);
  SPI_CS = 0x00;

}

void ENC28J60_BFS(unsigned char addr,unsigned char data) //ENC28J60位域置1
{

  SPI_CS = 0x09;
  SPI_D = addr | 0x80;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = data;
  while((SPI_INT & 0x80) != 0x80);
  SPI_CS = 0x00;

}

void ENC28J60_BFC(unsigned char addr,unsigned char data) //ENC28J60位域清0
{

  SPI_CS = 0x09;
  SPI_D = addr | 0xa0;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = data;
  while((SPI_INT & 0x80) != 0x80);
  SPI_CS = 0x00;

}

void ENC28J60_RST() //ENC28J60复位命令
{

  SPI_CS = 0x09;
  SPI_D = 0xff;
  while((SPI_INT & 0x80) != 0x80);
  SPI_CS = 0x00;

}

void ENC28J60_chushihua() //ENC28J60初始化
{

  ENC28J60_WCR(0x00,0xfa);  //ERDPTL	缓冲器读指针
  ENC28J60_WCR(0x01,0x05);  //ERDPTH

  ENC28J60_WCR(0x02,0x00);  //EWRPTL	缓冲器写指针
  ENC28J60_WCR(0x03,0x00);  //EWRPTH

  ENC28J60_WCR(0x04,0x00);  //ETXSTL	发送缓冲器首指针
  ENC28J60_WCR(0x05,0x00);  //ETXSTH

  ENC28J60_WCR(0x06,0x00);  //ETXNDL	发送缓冲器尾指针
  ENC28J60_WCR(0x07,0x00);  //ETXNDH

  ENC28J60_WCR(0x08,0xfa);  //ERXSTL	接收缓冲器首指针
  ENC28J60_WCR(0x09,0x05);  //ERXSTH

  ENC28J60_WCR(0x0a,0xff);  //ERXNDL	接收缓冲器尾指针
  ENC28J60_WCR(0x0b,0x1f);  //ERXNDH

  ENC28J60_WCR(0x0c,0xfa);  //ERXRDPTL	接收缓冲器硬件限写指针
  ENC28J60_WCR(0x0d,0x05);  //ERXRDPTH


  Bank1();

  ENC28J60_WCR(0x18,0x20);  //ERXFCON	    过滤器


  Bank2();

  ENC28J60_WCR(0x01,0x00);  //MACON2	 MARST清0 使MAC退出复位状态

  ENC28J60_WCR(0x00,0x0d);  //MACON1	 IEEE流量控制和使能MAC接收数据帧

  ENC28J60_WCR(0x02,0x31);  //MACON3   CRC自填 小于60字节自填 全双工

  //ENC28J60_WCR(0x03,0x00);  //MACON4	 默认

  //ENC28J60_WCR(0x0a,0x2e);  //MAMXFLL   发送/接收 最大帧长度
  //ENC28J60_WCR(0x0b,0x00);  //MAMXFLH   

  ENC28J60_WCR(0x04,0x15);  //MABBIPG   背对备包间隔   全双工15H  半双工12H

  ENC28J60_WCR(0x06,0x12);  //MAIPGL   非背对备包间隔	  一般12H
  //ENC28J60_WCR(0x07,0x0c);  //MAIPGH   半双工0CH

  ENC28J60_WCR(0x1b,0xc0);  //EIE 中断控制寄存器 设置接受到数据包时输出中断 数据包计数为0时中断消除


  Bank3();

  ENC28J60_WCR(0x01,MAC0);  //MAADR0	  本机MAC地址
  ENC28J60_WCR(0x00,MAC1);  //MAADR1
  ENC28J60_WCR(0x03,MAC2);  //MAADR2
  ENC28J60_WCR(0x02,MAC3);  //MAADR3
  ENC28J60_WCR(0x05,MAC4);  //MAADR4
  ENC28J60_WCR(0x04,MAC5);  //MAADR5


//////////////////////////////////////写PHY/////////////////////////////////////////

  Bank2();
					
  ENC28J60_WCR(0x14,0x00); 	 //MIREGADR  写入PHY寄存器地址

  ENC28J60_WCR(0x16,0x00);	 //MIWRL   写入PHY寄存器低8位数据

  ENC28J60_WCR(0x17,0x01);	 //MIWRH   写入PHY寄存器高8位数据


  Bank3();

  do ENC28J60_RCR(0x0a);while((SPI_D & 0x01) != 0); //MISTAT


//////////////////////////////////////读PHY/////////////////////////////////////////	    

  Bank2();

  ENC28J60_WCR(0x14,0x00); 	 //MIREGADR  写入PHY寄存器地址

  ENC28J60_WCR(0x12,0x01);	 //MICMD.MIIRD位置1开始PHY读操作


  Bank3();

  do ENC28J60_RCR(0x0a);while((SPI_D & 0x01) != 0); //MISTAT


  Bank2();

  ENC28J60_WCR(0x12,0x00);	 //MICMD.MIIRD位清0


  ENC28J60_RCR(0x19); //MIRDH
					
  for(k = 0;k < 61000;k++);


  ENC28J60_RCR(0x18); //MIRDL
					
  for(k = 0;k < 61000;k++);

}

void xierushujubao(unsigned int addr) //给SRAM包数据大小 调用即写入SRAM内容
{

  unsigned int j_;

  Bank0();

  ENC28J60_WCR(0x02,0x00);  //EWRPTL	缓冲器写指针回归首部
  ENC28J60_WCR(0x03,0x00);  //EWRPTH


  SPI_CS = 0x09;

  SPI_D = 0x7a;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x00;

  j_ = 0;
  while(j_ < addr)
  {

    SPI_D = SRAM[j_++];
    SPI_D = SRAM[j_++];
    SPI_D = SRAM[j_++];
    SPI_D = SRAM[j_++];
    SPI_D = SRAM[j_++];
    SPI_D = SRAM[j_++];

  }

  SPI_CS = 0x00;


  ENC28J60_WCR(0x06,addr & 0x00ff);  //ETXNDL	发送缓冲器尾指针指向最后1个字节
  ENC28J60_WCR(0x07,addr >> 8);      //ETXNDH

}

void ENC28J60_jisuanxiaoyanhe(unsigned int A1,unsigned int A2,unsigned int A3) //ENC28J60内部计算效验和并填上 给A1A2起始和结束字节地址 给A3效验和填充位置
{

  unsigned char D1,D2;

  Bank0();

  ENC28J60_WCR(0x10,A1); //EDMASTL 效验和计算起始地址低
  ENC28J60_WCR(0x11,A1 >> 8); //EDMASTH 效验和计算起始地址高

  ENC28J60_WCR(0x12,A2); //EDMANDL 效验和计算结束地址低
  ENC28J60_WCR(0x13,A2 >> 8); //EDMANDH 效验和计算结束地址高

  ENC28J60_BFS(0x1f,0x10);  //ECON1.CSUMEN位置1 切换为硬件计算效验和
  ENC28J60_BFS(0x1f,0x20);  //ECON1.DMAST位置1 启动计算

  do ENC28J60_RCR(0x1f);while((SPI_D & 0x20) != 0); //等待ECON1.DMAST清0

  ENC28J60_RCR(0x16); //EDMACSL 效验和计算结果低
  D1 = SPI_D;
  ENC28J60_RCR(0x17); //EDMACSH 效验和计算结果高
  D2 = SPI_D;


  ENC28J60_WCR(0x02,A3); //EWRPTL 缓冲器写指针指向效验和起始字节
  ENC28J60_WCR(0x03,A3 >> 8); //EWRPTH

  SPI_CS = 0x09;

  SPI_D = 0x7a;
  SPI_D = D2;
  SPI_D = D1;
  while((SPI_INT & 0x80) != 0x80);

  SPI_CS = 0x00;

}

void jieshoushujubao()
{

  unsigned int j_;

      Bank0();

      SPI_CS = 0x09; //设置SPI速率并片选ENC28J60

      SPI_D = 0x3a; //发送读缓冲器命令
  while((SPI_INT & 0x80) != 0x80);
      SPI_D = 0xff;
  while((SPI_INT & 0x80) != 0x80);

      addrL = SPI_D; //保存下一个数据包起始地址L
      addrH = SPI_D; //保存下一个数据包起始地址H

      jjl = SPI_D; //接收的字节数L 
      jjh = SPI_D; //接收的字节数H
      jjh = jjh << 8;
      jjh |= jjl;

      SPI_D = 0xff;    //接收的状态   0xc0为通过
  while((SPI_INT & 0x80) != 0x80);
      SPI_D = 0xff;    //接收的状态	  0x01为组播	0x03为广播


      jjh = jjh - 4;

      if(jjh < 713)	//超过SRAM容量不进
      {

          if(jjh > 53)
          {
             SRAM[0] = SPI_D;
             SRAM[1] = SPI_D;
             SRAM[2] = SPI_D;
             SRAM[3] = SPI_D;
             SRAM[4] = SPI_D;
             SRAM[5] = SPI_D;
             SRAM[6] = SPI_D;
             SRAM[7] = SPI_D;
             SRAM[8] = SPI_D;
             SRAM[9] = SPI_D;
             SRAM[10] = SPI_D;
             SRAM[11] = SPI_D;
             SRAM[12] = SPI_D;
             SRAM[13] = SPI_D;
             SRAM[14] = SPI_D;
             SRAM[15] = SPI_D;
             SRAM[16] = SPI_D;
             SRAM[17] = SPI_D;
             SRAM[18] = SPI_D;
             SRAM[19] = SPI_D;
             SRAM[20] = SPI_D;
             SRAM[21] = SPI_D;
             SRAM[22] = SPI_D;
             SRAM[23] = SPI_D;
             SRAM[24] = SPI_D;
             SRAM[25] = SPI_D;
             SRAM[26] = SPI_D;
             SRAM[27] = SPI_D;
             SRAM[28] = SPI_D;
             SRAM[29] = SPI_D;
             SRAM[30] = SPI_D;
             SRAM[31] = SPI_D;
             SRAM[32] = SPI_D;
             SRAM[33] = SPI_D;
             SRAM[34] = SPI_D;
             SRAM[35] = SPI_D;
             SRAM[36] = SPI_D;
             SRAM[37] = SPI_D;
             SRAM[38] = SPI_D;
             SRAM[39] = SPI_D;
             SRAM[40] = SPI_D;
             SRAM[41] = SPI_D;
             SRAM[42] = SPI_D;
             SRAM[43] = SPI_D;
             SRAM[44] = SPI_D;
             SRAM[45] = SPI_D;
             SRAM[46] = SPI_D;
             SRAM[47] = SPI_D;
             SRAM[48] = SPI_D;
             SRAM[49] = SPI_D;
             SRAM[50] = SPI_D;
             SRAM[51] = SPI_D;
             SRAM[52] = SPI_D;
             SRAM[53] = SPI_D;

             if(jjh != 54)
             {
                j_ = 54;
                while(j_ < jjh - 1)
                {
                  SRAM[j_++] = SPI_D;
                }

                SPI_S = 0x04;
                SRAM[j_] = SPI_D;
                SPI_S = 0x01;
             }

          }
          else
          {

             j_ = 0;
             while(j_ < jjh - 1)
             {
               SRAM[j_++] = SPI_D;
             }

             SPI_S = 0x04;
             SRAM[j_] = SPI_D;
             SPI_S = 0x01;

          }



      }

      SPI_CS = 0x00; //取消ENC28J60片选 选中空设备

      ////////////////////////////////////////////////////////////////////////////////////////////

      ENC28J60_RCR(0x1c);
 
      if((SPI_D & 0x01) == 0x00)   //EIR.RXERIF位为0时进入 (接收缓冲器没溢出时进入)
      {

        ENC28J60_WCR(0x0c,addrL);  //ERXRDPTL	接收缓冲器硬件限写指针	 指向下一个数据包
        ENC28J60_WCR(0x0d,addrH);  //ERXRDPTH

        ENC28J60_WCR(0x00,addrL);  //ERDPTL	缓冲器读指针	 指向下一个数据包
        ENC28J60_WCR(0x01,addrH);  //ERDPTH
						
        ENC28J60_BFS(0x1e,0x40);  //ECON2.PKTDEC 置1  让EPKTCNT接收数据包计数寄存器减1


        Bank1();

        ENC28J60_RCR(0x19);
        if(SPI_D == 0) ENC28J60_SJBBZ = 0;else ENC28J60_SJBBZ = 1; //EPKTCNT大于0时  标志有数据包 否则标志没有数据包

      }
      else     // 接收缓冲器溢出进入
      {

        ENC28J60_SJBBZ = 0; //标志为没有数据包

        ENC28J60_BFC(0x1f,0x04);  //ECON1.RXEN位清0  关闭接收


        ENC28J60_WCR(0x00,0xfa);  //ERDPTL	缓冲器读指针恢复初始值
        ENC28J60_WCR(0x01,0x05);  //ERDPTH

        ENC28J60_WCR(0x08,0xfa);  //ERXSTL	接收缓冲器首指针恢复初始值
        ENC28J60_WCR(0x09,0x05);  //ERXSTH

        ENC28J60_WCR(0x0c,0xfa);  //ERXRDPTL	接收缓冲器硬件限写指针恢复初始值
        ENC28J60_WCR(0x0d,0x05);  //ERXRDPTH


        Bank1();

        do
        {
          ENC28J60_BFS(0x1e,0x40);  //ECON2.PKTDEC 置1  让EPKTCNT接收数据包计数寄存器减1
          ENC28J60_RCR(0x19);
        } while(SPI_D != 0);


        Bank0();

        ENC28J60_BFC(0x1c,0x01);  //EIR.RXERIF位清0  清零接收缓冲器溢出标志
        ENC28J60_BFS(0x1f,0x04);  //ECON1.RXEN位置1  启动接收


      }

}