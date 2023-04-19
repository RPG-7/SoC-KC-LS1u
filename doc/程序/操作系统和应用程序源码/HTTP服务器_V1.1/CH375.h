void CH375_delay_0()
{
}


unsigned char CH375_NOT_DATA(unsigned char device,unsigned char DATA) //CH375测试 写入数据 返回 ~数据,  device选择设备,DATA是测试数据
{

unsigned char x;

  CS_8080 = 0x08|device; //选中8080总线设备
  D1_8080 = 0x06; //写命令
  CH375_delay_0();
  D0_8080 = DATA; //写数据
  CH375_delay_0();
  x = D0_8080;    //读出取反后的数据
  CS_8080 = 0x00; //选中空设备
  return x;

}

void CH375_SET_USB_BUSRST(unsigned char device) //设置CH375工作模式为复位USB总线,device选择设备
{

  unsigned int i;

  CS_8080 = 0x08|device; //选中8080总线设备
  D1_8080 = 0x15; //写命令
  CH375_delay_0();
  D0_8080 = 0x07;//写数据
  CS_8080 = 0x00; //选中空设备
  for(i = 0;i != 61000;++i);
  for(i = 0;i != 52000;++i);

}

void CH375_SET_USB_HOST(unsigned char device) //设置CH375工作模式为主机模式,device选择设备
{

  unsigned int i;

  CS_8080 = 0x08|device; //选中8080总线设备
  D1_8080 = 0x15; //写命令
  CH375_delay_0();
  D0_8080 = 0x06;//写数据
  CS_8080 = 0x00; //选中空设备
  for(i = 0;i != 25000;++i);

}

void CH375_RST(unsigned char device) //CH375硬件复位,device选择设备
{

unsigned int i;

  CS_8080 = 0x08|device; //选中8080总线设备
  D1_8080 = 0x05; //写命令
  CS_8080 = 0x00; //选中空设备
  for(i = 0;i != 25000;++i); //等40毫秒以上

}

void CH375_CSH() //初始化CH375
{


  CH375_RST(0); //第1片CH375执行硬件复位
  CH375_RST(1); //第2片CH375执行硬件复位
  CH375_RST(2); //第3片CH375执行硬件复位
  CH375_RST(3); //第4片CH375执行硬件复位

  if(CH375_NOT_DATA(0,0xaa) == 0x55 && CH375_NOT_DATA(0,0x55) == 0xaa) //检测第1片CH375存在?
  {

     CS_8080 = 0x08; //选中8080总线设备
     D1_8080 = 0x01; //获取版本号命令
     CH375_delay_0();
     CH375_ICBBH[0] = D0_8080 & 0x3f; //保存版本号
     CS_8080 = 0x00; //选中空设备
     CH375_device_bz[0] = 1; //标志第1片CH375设备存在
     CH375_SET_USB_HOST(0); //设置为主机模式

  }


  if(CH375_NOT_DATA(1,0xaa) == 0x55 && CH375_NOT_DATA(1,0x55) == 0xaa) //检测第2片CH375存在?
  {

     CS_8080 = 0x09; //选中8080总线设备
     D1_8080 = 0x01; //获取版本号命令
     CH375_delay_0();
     CH375_ICBBH[1] = D0_8080 & 0x3f; //保存版本号
     CS_8080 = 0x00; //选中空设备
     CH375_device_bz[1] = 1; //标志第2片CH375设备存在
     CH375_SET_USB_HOST(1); //设置为主机模式

  }


  if(CH375_NOT_DATA(2,0xaa) == 0x55 && CH375_NOT_DATA(2,0x55) == 0xaa) //检测第3片CH375存在?
  {

     CS_8080 = 0x0a; //选中8080总线设备
     D1_8080 = 0x01; //获取版本号命令
     CH375_delay_0();
     CH375_ICBBH[2] = D0_8080 & 0x3f; //保存版本号
     CS_8080 = 0x00; //选中空设备
     CH375_device_bz[2] = 1; //标志第3片CH375设备存在
     CH375_SET_USB_HOST(2); //设置为主机模式

  }


  if(CH375_NOT_DATA(3,0xaa) == 0x55 && CH375_NOT_DATA(3,0x55) == 0xaa) //检测第4片CH375存在?
  {

     CS_8080 = 0x0b; //选中8080总线设备
     D1_8080 = 0x01; //获取版本号命令
     CH375_delay_0();
     CH375_ICBBH[3] = D0_8080 & 0x3f; //保存版本号
     CS_8080 = 0x00; //选中空设备
     CH375_device_bz[3] = 1; //标志第4片CH375设备存在
     CH375_SET_USB_HOST(3); //设置为主机模式

  }


}



unsigned char CH375_RD_bufDATA(unsigned char device,unsigned char *buf) //读CH375的缓冲区数据到本机缓冲区,device选择设备,buf为本机缓冲区首地址,返回值为数据长度
{

unsigned char bufx; //记录CH375缓冲区数据长度
unsigned char js1;  //计数1


      CS_8080 = 0x08|device; //选中8080总线设备
      D1_8080 = 0x27; //发送读缓冲区命令
      CH375_delay_0();
      bufx = D0_8080; //读出缓冲区数据长度

      js1 = 0;
      while(js1 != bufx)
      {
        buf[js1] = D0_8080;
        ++js1;
      }

      CS_8080 = 0x00; //选中空设备

   return bufx;

}



void CH375_WR_bufDATA(unsigned char device,unsigned char x,unsigned char *buf) //本机缓冲区数据写到CH375的缓冲区,device选择设备,x为写入数据长度,buf为本机缓冲区首地址,
{

unsigned char js1; //计数1

      CS_8080 = 0x08|device; //选中8080总线设备
      D1_8080 = 0x2b; //发送写缓冲区命令
      CH375_delay_0();
      D0_8080 = x; //写入数据长度

      js1 = 0;
      while(js1 != x)
      {
        D0_8080 = buf[js1];
        ++js1;
      }

      CS_8080 = 0x00; //选中空设备

}



void CH375_USB_CTL(unsigned char device,unsigned char data1,unsigned char data2,unsigned char data3,unsigned char data4,unsigned char data5,unsigned char data6,unsigned char data7,unsigned char data8) //端点0执行8字节SETUP事务,device选择设备,data1~data8为8字节数据
{

  CS_8080 = 0x08|device; //选中8080总线设备

  D1_8080 = 0x2b; //发送写缓冲区命令
  CH375_delay_0();
  D0_8080 = 0x08; //长度8字节
  CH375_delay_0();

  D0_8080 = data1;
  CH375_delay_0();
  D0_8080 = data2;
  CH375_delay_0();
  D0_8080 = data3;
  CH375_delay_0();
  D0_8080 = data4;
  CH375_delay_0();
  D0_8080 = data5;
  CH375_delay_0();
  D0_8080 = data6;
  CH375_delay_0();
  D0_8080 = data7;
  CH375_delay_0();
  D0_8080 = data8;
  CH375_delay_0();

  D1_8080 = 0x4e; //发送执行事务命令
  CH375_delay_0();
  D0_8080 = 0x00; //同步标志 00H发送DATA0 40H发送DATA1
  CH375_delay_0();
  D0_8080 = 0x0d; //高4位端点 低4位事务属性

  CS_8080 = 0x00; //选中空设备

}

/*
void CH375_USB_SETUP(unsigned char device,unsigned char DX,unsigned char DK) //执行SETUP事务, DX = 1发DATA1, DX = 0发DATA0,DK是端点号,device选择设备
{

  CS_8080 = 0x08|device; //选中8080总线设备

  D1_8080 = 0x4e; //发送执行事务命令
  CH375_delay_0();
  D0_8080 = (DX << 6) & 0x40; //同步标志 00H发DATA0 40H发DATA1
  CH375_delay_0();
  D0_8080 = (DK << 4) | 0x0d; //高4位端点 低4位事务属性

  CS_8080 = 0x00; //选中空设备

}
*/


void CH375_USB_IN(unsigned char device,unsigned char DX,unsigned char DK) //执行IN事务, DX = 1收DATA1, DX = 0收DATA0,DK是端点号,device选择设备
{

  CS_8080 = 0x08|device; //选中8080总线设备

  D1_8080 = 0x4e; //发送执行事务命令
  CH375_delay_0();
  D0_8080 = DX << 7; //同步标志 00H收DATA0 80H收DATA1
  CH375_delay_0();
  D0_8080 = (DK << 4) | 0x09; //高4位端点 低4位事务属性

  CS_8080 = 0x00; //选中空设备

}


void CH375_USB_OUT(unsigned char device,unsigned char DX,unsigned char DK) //执行OUT事务, DX = 1发DATA1, DX = 0发DATA0,DK是端点号,device选择设备
{

  CS_8080 = 0x08|device; //选中8080总线设备

  D1_8080 = 0x4e; //发送执行事务命令
  CH375_delay_0();
  D0_8080 = (DX << 6) & 0x40; //同步标志 00H发DATA0 40H发DATA1
  CH375_delay_0();
  D0_8080 = (DK << 4) | 0x01; //高4位端点 低4位事务属性

  CS_8080 = 0x00; //选中空设备

}


void CH375_SET_USB_BUSM(unsigned char device,unsigned char x) //设置USB总线速度,device选择设备,x为速度
{

  CS_8080 = 0x08|device; //选中8080总线设备

  D1_8080 = 0x04; //发送设置USB总线速度命令
  CH375_delay_0();
  D0_8080 = x;    //发送速度数据,00H对应12Mbps全速模式,01H对应1.5Mbps全速模式(非标准模式),02H对应1.5Mbps低速模式

  CS_8080 = 0x00; //选中空设备

}


unsigned char CH375_RD_INTDATA(unsigned char device) //获取CH375中断状态码,device选择设备
{

unsigned char x;

  CS_8080 = 0x08|device; //选中8080总线设备
  D1_8080 = 0x22; //发送获取中断码命令
  CH375_delay_0();
  x = D0_8080;
  CS_8080 = 0x00; //选中空设备

  return x;

}


void CH375_USB_HQMSF(unsigned char device,unsigned char x) //获取描述符,x为描述符代码,device选择设备
{

  CS_8080 = 0x08|device; //选中8080总线设备
  D1_8080 = 0x46;
  CH375_delay_0();
  D0_8080 = x;
  CS_8080 = 0x00; //选中空设备

}



unsigned char CH375_RUN()
{

unsigned char i;
unsigned char device;


CH375_INTT = 0;

/***************************** 键盘鼠标刷新率 = 1 / ((65536 / CPU主频) * CH375_CL1) = 183HZ ****************************/

#define CH375_CL1 1

/***********************************************************************************************************************/


       if(CH375_CT2_ < 256 - CH375_CL1 && (CT2 < CH375_CT2_ || CT2 >= CH375_CT2_ + CH375_CL1)   ||   CH375_CT2_ > 255 - CH375_CL1 && CT2 < CH375_CT2_ && CT2 >= CH375_CT2_ + CH375_CL1) //上次记录的硬件计数器数据和现在硬件计数器的数据进行比较,达到条件时进入
       {

 device = 0;

 do
 {

    if(CH375_device_bz[device] == 1  &&  (device == 0 && (INT_8080 & 0x01) == 0x00  ||  device == 1 && (INT_8080 & 0x02) == 0x00  ||  device == 2 && (INT_8080 & 0x04) == 0x00  ||  device == 3 && (INT_8080 & 0x08) == 0x00) ) //CH375标志有效并且有中断时进入
    {

        CH375_INTT = 1;

        i = CH375_RD_INTDATA(device); //获取CH375中断状态码到i

        if(i == 0x15) //设备插入
        {

           CH375_SBIOBZ = 1; //标志有设备插入

           CH375_BJ[device] = 1; //步骤1

           CH375_QJ[device] = 0; //其他中断事件清0

           CH375_SET_USB_BUSRST(device); //复位USB总线
           CH375_SET_USB_HOST(device);   //设置为主机模式

           CH375_SET_USB_BUSM(device,CH375_ZXSD[device]); //设置USB总线速度
           CH375_ZXSD[device] += 2;

           CH375_USB_HQMSF(device,1); //测试获取设备描述符

SPI_S = 0x04;
SPI_D = 0x11;
SPI_S = 0x01;

        }
        else if(i == 0x16) //设备拔出
        {

           CH375_SBIOBZ = 2; //标志有设备拔出

           CH375_INK[device] = 0; //关闭查询
           CH375_SBDM[device] = 0; //设备代码0 无设备
           CH375_ZXSD[device] = 0; //总线速度值恢复最高速


SPI_S = 0x04;
SPI_D = 0x22;
SPI_S = 0x01;

        }
        else if(i == 0x14) //命令执行成功
        {

           if(CH375_BJ[device] == 0) //步骤0
           {


              CH375_QJ[device] = 0; //其他中断事件清0

              CH375_INDX[device] = ~CH375_INDX[device]; //DATA0DATA1同步触发标志取反

              i = CH375_RD_bufDATA(device,CH375_DATAbuf); //CH375缓冲区数据读入本机缓冲区 , 数据长度记录到i

              if(i == 4) //鼠标
              {

                 SB_KEY = CH375_DATAbuf[0];

                 if((CH375_DATAbuf[1] & 0x80) == 0x80 && SB_X + CH375_DATAbuf[1] > SB_X)
                 {
                    SB_X = 0;
                 }
                 else if((CH375_DATAbuf[1] & 0x80) == 0x00 && SB_X + CH375_DATAbuf[1] < SB_X)
                 {
                    SB_X = 255;
                 }
                 else
                 {
                    SB_X += CH375_DATAbuf[1];
                 }

                 if((CH375_DATAbuf[2] & 0x80) == 0x80 && SB_Y + CH375_DATAbuf[2] > SB_Y)
                 {
                    SB_Y = 0;
                 }
                 else if((CH375_DATAbuf[2] & 0x80) == 0x00 && (SB_Y + CH375_DATAbuf[2] < SB_Y || SB_Y + CH375_DATAbuf[2] > 239))
                 {
                    SB_Y = 239;
                 }
                 else
                 {
                    SB_Y += CH375_DATAbuf[2];
                 }

                 if((CH375_DATAbuf[3] & 0x80) == 0x80 && SB_Z + CH375_DATAbuf[3] > SB_Z)
                 {
                    SB_Z = 0;
                 }
                 else if((CH375_DATAbuf[3] & 0x80) == 0x00 && SB_Z + CH375_DATAbuf[3] < SB_Z)
                 {
                    SB_Z = 255;
                 }
                 else
                 {
                    SB_Z += CH375_DATAbuf[3];
                 }

              }
              else if(i == 6) //鼠标2
              {
              }
              else if(i == 8) //键盘
              {













                 SB_KEY = CH375_DATAbuf[0];



                 if((CH375_DATAbuf[1] & 0x80) == 0x80 && SB_X + CH375_DATAbuf[1] > SB_X)
                 {
                    SB_X = 0;
                 }
                 else if((CH375_DATAbuf[1] & 0x80) == 0x00 && SB_X + CH375_DATAbuf[1] < SB_X)
                 {
                    SB_X = 255;
                 }
                 else
                 {
                    SB_X += CH375_DATAbuf[1];
                 }



                 if((CH375_DATAbuf[2] & 0x80) == 0x80 && SB_Y + CH375_DATAbuf[2] > SB_Y)
                 {
                    SB_Y = 0;
                 }
                 else if((CH375_DATAbuf[2] & 0x80) == 0x00 && (SB_Y + CH375_DATAbuf[2] < SB_Y || SB_Y + CH375_DATAbuf[2] > 239))
                 {
                    SB_Y = 239;
                 }
                 else
                 {
                    SB_Y += CH375_DATAbuf[2];
                 }















                 KEY_DATA[0] = CH375_DATAbuf[0]; //保存数据到键盘键值
                 KEY_DATA[1] = CH375_DATAbuf[1];
                 KEY_DATA[2] = CH375_DATAbuf[2];
                 KEY_DATA[3] = CH375_DATAbuf[3];
                 KEY_DATA[4] = CH375_DATAbuf[4];
                 KEY_DATA[5] = CH375_DATAbuf[5];
                 KEY_DATA[6] = CH375_DATAbuf[6];
                 KEY_DATA[7] = CH375_DATAbuf[7];

                 if(KEY_Num_Lock()) KEY_LED ^= 0x01;
                 if(KEY_Scroll_Lock()) KEY_LED ^= 0x02;
                 if(KEY_Caps_Lock()) KEY_LED ^= 0x04;

                 if(KEY_Num_Lock() || KEY_Scroll_Lock() || KEY_Caps_Lock())
                 {
                    CH375_USB_CTL(device,0x21,0x09,0x00,0x02,0x00,0x00,0x01,0x00); //设置键盘灯
                    while(device == 0 && (INT_8080 & 0x01) == 0x01  ||  device == 1 && (INT_8080 & 0x02) == 0x02  ||  device == 2 && (INT_8080 & 0x04) == 0x04  ||  device == 3 && (INT_8080 & 0x08) == 0x08); //等待中断
       
                    CH375_DATAbuf[0] = KEY_LED; //输出键盘灯数据
                    CH375_WR_bufDATA(device,1,CH375_DATAbuf); //本机缓冲区数据写入CH375缓冲区
                    CH375_USB_OUT(device,0,0); //OUT事务 发DATA0 端点0
                    while(device == 0 && (INT_8080 & 0x01) == 0x01  ||  device == 1 && (INT_8080 & 0x02) == 0x02  ||  device == 2 && (INT_8080 & 0x04) == 0x04  ||  device == 3 && (INT_8080 & 0x08) == 0x08); //等待中断

                    CH375_USB_IN(device,1,0); //IN事务 收0数据的DATA1 端点0
                    while(device == 0 && (INT_8080 & 0x01) == 0x01  ||  device == 1 && (INT_8080 & 0x02) == 0x02  ||  device == 2 && (INT_8080 & 0x04) == 0x04  ||  device == 3 && (INT_8080 & 0x08) == 0x08); //等待中断
                 }

              }

SPI_S = 0x04;
SPI_D += 0x33;
SPI_S = 0x01;

           }
           else if(CH375_BJ[device] == 1) //步骤1 测试获取设备描述符OK
           {
              CH375_BJ[device] = 2; //步骤2
              CS_8080 = 0x08|device; //选中8080总线设备
              D1_8080 = 0x51; //测试初始化USB存储设备
              CS_8080 = 0x00; //选中空设备
SPI_S = 0x04;
SPI_D = 0x01;
SPI_S = 0x01;

           }
           else if(CH375_BJ[device] == 2) //步骤2 测试初始化USB存储设备OK
           {
              CH375_BJ[device] = 3; //步骤3
              CS_8080 = 0x08|device; //选中8080总线设备
              D1_8080 = 0x53; //获取USB存储设备容量
              CS_8080 = 0x00; //选中空设备

SPI_S = 0x04;
SPI_D = 0x02;
SPI_S = 0x01;

           }
           else if(CH375_BJ[device] == 3) //步骤3 获取USB存储设备容量OK
           {
              CH375_RD_bufDATA(device,CH375_DATAbuf); //CH375缓冲区数据读入本机缓冲区

              CH375_LBAX[device] = CH375_DATAbuf[0]; //记录存储设备LBA数量,USB存储器扇区数-1,+1再乘512就是实际容量(单位字节)
              CH375_LBAX[device] <<= 8;
              CH375_LBAX[device] |= CH375_DATAbuf[1];
              CH375_LBAX[device] <<= 8;
              CH375_LBAX[device] |= CH375_DATAbuf[2];
              CH375_LBAX[device] <<= 8;
              CH375_LBAX[device] |= CH375_DATAbuf[3];

              ++CH375_LBAX[device]; //+1为实际扇区数

              CH375_SBDM[device] = 1; //设备代码1 存储设备

SPI_S = 0x04;
SPI_D = 0x03;
SPI_S = 0x01;

           }
           else if(CH375_BJ[device] == 4) //步骤4 自动配置USB设备OK
           {
              CH375_BJ[device] = 5; //步骤5
              CH375_USB_CTL(device,0x81,0x06,0x00,0x22,0x00,0x00,0x08,0x00); //获取8字节报告描述符

SPI_S = 0x04;
SPI_D = 0x04;
SPI_S = 0x01;

           }
           else if(CH375_BJ[device] == 5) //步骤5 获取8字节报告描述符OK
           {
              CH375_BJ[device] = 6; //步骤6
              CH375_USB_IN(device,1,0); //执行IN事务 收DATA1 端点0

SPI_S = 0x04;
SPI_D = 0x05;
SPI_S = 0x01;

           }
           else if(CH375_BJ[device] == 6) //步骤6 执行IN事务OK
           {
              CH375_BJ[device] = 7; //步骤7

              CH375_RD_bufDATA(device,CH375_DATAbuf); //CH375缓冲区数据读入本机缓冲区

              if(CH375_DATAbuf[2] == 0x09 && CH375_DATAbuf[3] == 0x02) //09 02 是鼠标
              {
                 CH375_SBDM[device] = 3; //设备代码3 鼠标

                 CH375_WR_bufDATA(device,0,CH375_DATAbuf); //回复0数据的DATA1
                 CH375_USB_OUT(device,1,0); //OUT事务 发DATA1 端点0
              }
              else if(CH375_DATAbuf[2] == 0x09 && CH375_DATAbuf[3] == 0x06) //09 06 是键盘
              {
                 CH375_SBDM[device] = 2; //设备代码2 键盘

                 CH375_WR_bufDATA(device,0,CH375_DATAbuf); //回复0数据的DATA1
                 CH375_USB_OUT(device,1,0); //OUT事务 发DATA1 端点0
              }
              else
              {
                 CH375_SBDM[device] = 255; //未识别的设备
              }
SPI_S = 0x04;
SPI_D = 0x06;
SPI_S = 0x01;

           }
           else if(CH375_BJ[device] == 7) //步骤7 执行OUT事务OK
           {

              if(CH375_SBDM[device] == 2) //键盘?
              {
                 CH375_BJ[device] = 8; //步骤8
                 CH375_USB_CTL(device,0x21,0x09,0x00,0x02,0x00,0x00,0x01,0x00); //设置键盘灯
              }
              else
              {
                 CH375_INK[device] = 1; //开启查询
                 CH375_INDX[device] = 0; //先收DATA0
                 CH375_BJ[device] = 0; //步骤0 完成初始化
              }

SPI_S = 0x04;
SPI_D = 0x07;
SPI_S = 0x01;

           }
           else if(CH375_BJ[device] == 8) //步骤8 设置键盘灯OK
           {
              CH375_BJ[device] = 9; //步骤9

              CH375_DATAbuf[0] = KEY_LED;               //输出键盘灯数据
              CH375_WR_bufDATA(device,1,CH375_DATAbuf);
              CH375_USB_OUT(device,0,0); //OUT事务 发DATA0 端点0

SPI_S = 0x04;
SPI_D = 0x08;
SPI_S = 0x01;

           }
           else if(CH375_BJ[device] == 9) //步骤9 输出键盘灯数据OK
           {
              CH375_BJ[device] = 10; //步骤10

              CH375_USB_IN(device,1,0); //IN事务 收0数据的DATA1 端点0

SPI_S = 0x04;
SPI_D = 0x09;
SPI_S = 0x01;

           }
           else if(CH375_BJ[device] == 10) //步骤10 收0数据的DATA1 OK
           {
              CH375_INK[device] = 1; //开启查询
              CH375_INDX[device] = 0; //先收DATA0
              CH375_BJ[device] = 0; //步骤0 完成初始化

SPI_S = 0x04;
SPI_D = 0x0a;
SPI_S = 0x01;

           }

        }
        else //其他事件
        {

           if(CH375_BJ[device] == 0) //步骤0
           {
              ++CH375_QJ[device];//其他中断事件计数+1
              if(CH375_QJ[device] == 2) //其他中断事件计数达到2
              {
                 CH375_INK[device] = 0; //关闭查询
                 CH375_SBDM[device] = 0; //设备代码0 无设备
              }
           }
           else if(CH375_BJ[device] == 1) //步骤1 测试获取设备描述符NO
           {

              if(CH375_ZXSD[device] < 3) //小于3次继续搞...
              {
                 CH375_RST(device); //执行硬件复位
                 CH375_SET_USB_HOST(device); //设置为主机模式
              }
              else
              {
                 CH375_SBDM[device] = 255; //未识别的设备
              }

           }
           else if(CH375_BJ[device] == 2) //步骤2 测试初始化USB存储设备NO
           {
              CH375_BJ[device] = 4; //步骤4
              CS_8080 = 0x08|device; //选中8080总线设备
              D1_8080 = 0x4d; //自动配置USB设备
              CS_8080 = 0x00; //选中空设备
           }
           else if(CH375_BJ[device] == 3 || CH375_BJ[device] == 4 || CH375_BJ[device] == 5 || CH375_BJ[device] == 6 || CH375_BJ[device] == 7 || CH375_BJ[device] == 8 || CH375_BJ[device] == 9 || CH375_BJ[device] == 10) //步骤3 获取USB存储设备容量NO 步骤4 自动配置USB设备NO 步骤5 获取8字节报告描述符NO 步骤6 执行IN事务NO 步骤7 执行OUT事务NO 步骤8 设置键盘灯NO 步骤9 输出键盘灯数据NO 步骤10 收0数据的DATA1NO
           {
              CH375_SBDM[device] = 255; //未识别的设备
           }

        }


    }


    if(CH375_INK[device] == 1) //查询控制开启进入
    {
        CH375_USB_IN(device,CH375_INDX[device],1); //执行IN事务查询设备端点1
    }



    ++device; //下一个设备

 }while(device != 4);





 CH375_CT2_ = CT2; //记录当前硬件计数器数据




       }


   return CH375_INTT;


}





unsigned char CH375_DISK_READ(unsigned char device,unsigned long int SQH,unsigned char LBAX) //从USB存储器设备读取数据块命令, device选择设备,SQH是扇区号,LBAX是读取扇区个数,返回值不为0表示操作成功
{

  if(CH375_device_bz[device] == 1 && CH375_SBDM[device] == 1) ///CH375芯片存在并且设备是存储器,进入
  {

     CS_8080 = 0x08|device; //选中8080总线设备


     D1_8080 = 0x54; //写命令
     CH375_delay_0();

     D0_8080 = SQH; //写数据
     CH375_delay_0();
     D0_8080 = SQH >> 8; //写数据
     CH375_delay_0();
     D0_8080 = SQH >> 16; //写数据
     CH375_delay_0();
     D0_8080 = SQH >> 24; //写数据
     CH375_delay_0();

     D0_8080 = LBAX; //写数据


     CS_8080 = 0x00; //选中空设备


     while(device == 0 && (INT_8080 & 0x01) != 0x00  ||  device == 1 && (INT_8080 & 0x02) != 0x00  ||  device == 2 && (INT_8080 & 0x04) != 0x00  ||  device == 3 && (INT_8080 & 0x08) != 0x00); //等待中断到就跳出

     if(CH375_RD_INTDATA(device) == 0x1d) //读成功
     {
        return 1;
     }

  }

  return 0;

}


unsigned char CH375_DISK_RD_GO(unsigned char device) //继续读USB存储器设备数据块命令,device选择设备,返回值不为0表示操作成功
{

unsigned char i;

  if(CH375_device_bz[device] == 1 && CH375_SBDM[device] == 1) //CH375芯片存在并且设备是存储器,进入
  {

     CS_8080 = 0x08|device; //选中8080总线设备
     D1_8080 = 0x55; //写命令
     CS_8080 = 0x00; //选中空设备

     while(device == 0 && (INT_8080 & 0x01) != 0x00  ||  device == 1 && (INT_8080 & 0x02) != 0x00  ||  device == 2 && (INT_8080 & 0x04) != 0x00  ||  device == 3 && (INT_8080 & 0x08) != 0x00); //等待中断到就跳出

     i = CH375_RD_INTDATA(device); //获取中断状态码到i

     if(i == 0x1d || i == 0x14) //读成功
     {
        return 1;
     }

  }

  return 0;

}



unsigned char CH375_DISK_WRITE(unsigned char device,unsigned long int SQH,unsigned char LBAX) //写数据块到USB存储器设备命令, device选择设备,SQH是扇区号,LBAX是写取扇区个数,返回值不为0表示操作成功
{

  if(CH375_device_bz[device] == 1 && CH375_SBDM[device] == 1) //CH375芯片存在并且设备是存储器,进入
  {

     CS_8080 = 0x08|device; //选中8080总线设备


     D1_8080 = 0x56; //写命令
     CH375_delay_0();

     D0_8080 = SQH; //写数据
     CH375_delay_0();
     D0_8080 = SQH >> 8; //写数据
     CH375_delay_0();
     D0_8080 = SQH >> 16; //写数据
     CH375_delay_0();
     D0_8080 = SQH >> 24; //写数据
     CH375_delay_0();

     D0_8080 = LBAX; //写数据


     CS_8080 = 0x00; //选中空设备


     while(device == 0 && (INT_8080 & 0x01) != 0x00  ||  device == 1 && (INT_8080 & 0x02) != 0x00  ||  device == 2 && (INT_8080 & 0x04) != 0x00  ||  device == 3 && (INT_8080 & 0x08) != 0x00); //等待中断到就跳出

     if(CH375_RD_INTDATA(device) == 0x1e) //写成功
     {
        return 1;
     }

  }

  return 0;

}


unsigned char CH375_DISK_WR_GO(unsigned char device) //继续写USB存储器设备数据块命令,device选择设备,返回值不为0表示操作成功
{

unsigned char i;

  if(CH375_device_bz[device] == 1 && CH375_SBDM[device] == 1) //CH375芯片存在并且设备是存储器,进入
  {

     CS_8080 = 0x08|device; //选中8080总线设备
     D1_8080 = 0x57; //写命令
     CS_8080 = 0x00; //选中空设备

     while(device == 0 && (INT_8080 & 0x01) != 0x00  ||  device == 1 && (INT_8080 & 0x02) != 0x00  ||  device == 2 && (INT_8080 & 0x04) != 0x00  ||  device == 3 && (INT_8080 & 0x08) != 0x00); //等待中断到就跳出

     i = CH375_RD_INTDATA(device); //获取中断状态码到i

     if(i == 0x1e || i == 0x14) //读成功
     {
        return 1;
     }

  }

  return 0;

}



unsigned char CH375_RD_LBA(unsigned char device,unsigned long int SQH,unsigned char LBAX,unsigned char *buf) //USB存储器设备读扇区, device选择设备,SQH为起始扇区号,LBAX为读扇区的个数,buf为缓冲区首地址,如果操作成功返回值不为0
{

unsigned int js1 = 0;

   if(CH375_DISK_READ(device,SQH,LBAX) == 0) return 0; //发送读数据块到USB存储器设备命令,执行失败返回0

   do
   {

      if(CH375_RD_bufDATA(device,buf) != 64) return 0; //CH375缓冲区读出64字节到本机缓冲区,读出数据如果不是64字节返回0
      buf += 64;
      ++js1;
      if(CH375_DISK_RD_GO(device) == 0) return 0; //发送继续读USB存储器设备数据块命令,执行失败返回0

   }while(js1 >> 3 != LBAX);

   return 1;

}

unsigned char CH375_WR_LBA(unsigned char device,unsigned long int SQH,unsigned char LBAX,unsigned char *buf) //USB存储器设备写扇区, device选择设备,SQH为起始扇区号,LBAX为写扇区的个数,buf为缓冲区首地址,如果操作成功返回值不为0
{

unsigned int js1 = 0;

   if(CH375_DISK_WRITE(device,SQH,LBAX) == 0) return 0; //发送写数据块到USB存储器设备命令,执行失败返回0

   do
   {

      CH375_WR_bufDATA(device,64,buf); //写64字节到CH375缓冲区
      buf += 64;
      ++js1;
      //SPI_SET_DLED(0xa0 | js1);
      if(CH375_DISK_WR_GO(device) == 0) return 0; //发送继续写USB存储器设备数据块命令,执行失败返回0
      //SPI_SET_DLED(0x50 | js1);

   }while(js1 >> 3 != LBAX);

   return 1;

}

unsigned char CH375_GET_SBX() //取设备数量
{

unsigned char js1 = 0;
unsigned char js2 = 0;

   do
   {
      if(CH375_SBDM[js1] != 0) ++js2;

   }while(++js1 != 4);

   return js2;

}



