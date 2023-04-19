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
  for (i = 0; i != 25000; ++i);

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

void CH375_SET_USB_MODE(unsigned char device,unsigned char x) //设置CH375工作模式,device选择设备,x为模式代码,05H主机方式不产生SOF包,06H主机方式自动产生SOF包,07H主机方式复位USB总线
{

  unsigned int i;

  CS_8080 = 0x08|device; //选中8080总线设备
  D1_8080 = 0x15; //写命令
  CH375_delay_0();
  D0_8080 = x;//写数据
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
     CH375_SET_USB_MODE(0,0x05); //设置为主机模式

  }


  if(CH375_NOT_DATA(1,0xaa) == 0x55 && CH375_NOT_DATA(1,0x55) == 0xaa) //检测第2片CH375存在?
  {

     CS_8080 = 0x09; //选中8080总线设备
     D1_8080 = 0x01; //获取版本号命令
     CH375_delay_0();
     CH375_ICBBH[1] = D0_8080 & 0x3f; //保存版本号
     CS_8080 = 0x00; //选中空设备
     CH375_device_bz[1] = 1; //标志第2片CH375设备存在
     CH375_SET_USB_MODE(1,0x05); //设置为主机模式

  }


  if(CH375_NOT_DATA(2,0xaa) == 0x55 && CH375_NOT_DATA(2,0x55) == 0xaa) //检测第3片CH375存在?
  {

     CS_8080 = 0x0a; //选中8080总线设备
     D1_8080 = 0x01; //获取版本号命令
     CH375_delay_0();
     CH375_ICBBH[2] = D0_8080 & 0x3f; //保存版本号
     CS_8080 = 0x00; //选中空设备
     CH375_device_bz[2] = 1; //标志第3片CH375设备存在
     CH375_SET_USB_MODE(2,0x05); //设置为主机模式

  }


  if(CH375_NOT_DATA(3,0xaa) == 0x55 && CH375_NOT_DATA(3,0x55) == 0xaa) //检测第4片CH375存在?
  {

     CS_8080 = 0x0b; //选中8080总线设备
     D1_8080 = 0x01; //获取版本号命令
     CH375_delay_0();
     CH375_ICBBH[3] = D0_8080 & 0x3f; //保存版本号
     CS_8080 = 0x00; //选中空设备
     CH375_device_bz[3] = 1; //标志第4片CH375设备存在
     CH375_SET_USB_MODE(3,0x05); //设置为主机模式

  }


}


void CH375_ABORT_NAK(unsigned char device) //放弃当前NAK的重试,device选择设备
{

  CS_8080 = 0x08|device; //选中8080总线设备
  D1_8080 = 0x17; //写命令
  CS_8080 = 0x00; //选中空设备

}

void CH375_IN_CLR_STALL(unsigned char device, unsigned char DK) //IN事务清除端点错误,device选择设备,DK为端点号
{

    CS_8080 = 0x08 | device; //选中8080总线设备
    D1_8080 = 0x41; //写命令
    CH375_delay_0();
    D0_8080 = 0x80 | (DK & 0x0f);
    CS_8080 = 0x00; //选中空设备

}

void CH375_SET_RETRY(unsigned char device, unsigned char data) //设置USB事务操作重试次数,device选择设备,data设置重试数据
{

    CS_8080 = 0x08 | device; //选中8080总线设备
    D1_8080 = 0x0b; //写命令
    CH375_delay_0();
    D0_8080 = 0x25;
    CH375_delay_0();
    D0_8080 = data;
    CS_8080 = 0x00; //选中空设备

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

unsigned char CH375_GET_DEV_RATE(unsigned char device) //获取USB设备速率,device选择设备
{

unsigned char x;

  CS_8080 = 0x08|device; //选中8080总线设备
  D1_8080 = 0x0a; //发送获取USB设备速率命令
  CH375_delay_0();
  D0_8080 = 0x07;
  CH375_delay_0();
  x = D0_8080;
  CS_8080 = 0x00; //选中空设备

  return x;

}


void CH375_GET_EDSCR(unsigned char device,unsigned char x) //获取描述符,x为描述符代码,device选择设备
{

  CS_8080 = 0x08|device; //选中8080总线设备
  D1_8080 = 0x46;
  CH375_delay_0();
  D0_8080 = x;
  CS_8080 = 0x00; //选中空设备

}

void CH375_SET_CONFIG(unsigned char device,unsigned char x) //设置USB配置,x为配置值,device选择设备
{

  CS_8080 = 0x08|device; //选中8080总线设备
  D1_8080 = 0x49;
  CH375_delay_0();
  D0_8080 = x;
  CS_8080 = 0x00; //选中空设备

}

void CH375_HOLD_INT(unsigned char device) //卡在这里等中断
{
    while((device == 0 && (INT_8080 & 0x01) != 0x00) || (device == 1 && (INT_8080 & 0x02) != 0x00) || (device == 2 && (INT_8080 & 0x04) != 0x00) || (device == 3 && (INT_8080 & 0x08) != 0x00)); //有中断时跳出循环
}


unsigned char CH375_DISK_INIT(unsigned char device) //初始化USB存储设备,成功返回非0
{
    CS_8080 = 0x08 | device; //选中8080总线设备
    D1_8080 = 0x51; //测试初始化USB存储设备
    CS_8080 = 0x00; //选中空设备

    CH375_HOLD_INT(device); //卡在这里等中断
    if (CH375_RD_INTDATA(device) != 0x14) return 0x88;

    CS_8080 = 0x08 | device; //选中8080总线设备
    D1_8080 = 0x53; //获取USB存储设备容量
    CS_8080 = 0x00; //选中空设备

    CH375_HOLD_INT(device); //卡在这里等中断
    if (CH375_RD_INTDATA(device) != 0x14) return 0x8e;

    CH375_RD_bufDATA(device, CH375_DATAbuf); //CH375缓冲区数据读入本机缓冲区

    CH375_LBAX[device] = CH375_DATAbuf[0]; //记录存储设备LBA数量,USB存储器扇区数-1,+1再乘512就是实际容量(单位字节)
    CH375_LBAX[device] <<= 8;
    CH375_LBAX[device] |= CH375_DATAbuf[1];
    CH375_LBAX[device] <<= 8;
    CH375_LBAX[device] |= CH375_DATAbuf[2];
    CH375_LBAX[device] <<= 8;
    CH375_LBAX[device] |= CH375_DATAbuf[3];

    ++CH375_LBAX[device]; //+1为实际扇区数

    return 1;
}


unsigned char CH375_AUTO_SETUP(unsigned char device) //自动配置USB设备,device选择设备,成功返回非0
{

  CS_8080 = 0x08|device; //选中8080总线设备
  D1_8080 = 0x4d;
  CS_8080 = 0x00; //选中空设备

  CH375_HOLD_INT(device); //卡在这里等中断

  if (CH375_RD_INTDATA(device) == 0x14) return 1;
  return 0;

}


unsigned char CH375_GET_SBMSF(unsigned char device,unsigned char *buf) //获取设备描述符,device选择设备,buf描述符数据缓冲区首地址,成功返回读取的字节数,否则返回0
{

  CH375_GET_EDSCR(device,1); //获取设备描述符

  CH375_HOLD_INT(device); //卡在这里等中断

  if(CH375_RD_INTDATA(device) == 0x14) //获取设备描述符ok
  {
    return CH375_RD_bufDATA(device,buf); //读CH375的缓冲区数据到本机缓冲区
  }

  return 0;

}



unsigned char CH375_GET_PZMSF(unsigned char device,unsigned char *buf) //获取配置描述符,device选择设备,buf描述符数据缓冲区首地址,成功返回读取的字节数,否则返回0
{

unsigned char i;
unsigned char x;
unsigned int j_;
unsigned int j;


  CH375_USB_CTL(device,0x80,0x06,0x00,0x02,0x00,0x00,0x09,0x00); //获取配置描述符

  CH375_HOLD_INT(device); //卡在这里等中断

  if(CH375_RD_INTDATA(device) == 0x14) //获取配置描述符ok
  {

    CH375_USB_IN(device,1,0); //执行IN事务收0端点DATA1

    CH375_HOLD_INT(device); //卡在这里等中断

    if(CH375_RD_INTDATA(device) == 0x14) //执行IN事务ok
    {

       CH375_RD_bufDATA(device,buf); //读CH375的缓冲区数据到本机缓冲区
       j_ = ((j_ = buf[3]) << 8) | buf[2];
       if(j_ > 256) j_ = 256; //限制大小

       CH375_WR_bufDATA(device,0,buf); //回复0数据的DATA1
       CH375_USB_OUT(device,1,0); //OUT事务 发DATA1 端点0

       CH375_HOLD_INT(device); //卡在这里等中断

       if(CH375_RD_INTDATA(device) == 0x14) //执行OUT事务ok
       {

         CH375_USB_CTL(device,0x80,0x06,0x00,0x02,0x00,0x00,j_ ,j_ >> 8); //获取完整长度配置描述符

         CH375_HOLD_INT(device); //卡在这里等中断

         if(CH375_RD_INTDATA(device) == 0x14) //获取配置描述符ok
         {

           x = 0;
           j = 0;
           while(j < j_)
           {

             CH375_USB_IN(device,(x = ~x),0); //执行IN事务

             CH375_HOLD_INT(device); //卡在这里等中断

             if(CH375_RD_INTDATA(device) == 0x14) //执行IN事务ok
             {

               i = CH375_RD_bufDATA(device,buf); //读CH375的缓冲区数据到本机缓冲区
               buf += i; //缓冲区首地址推进
               j += i; //计算已读取字节数

             }
             else return 0;

           }

           CH375_WR_bufDATA(device,0,buf); //回复0数据的DATA1
           CH375_USB_OUT(device,1,0); //OUT事务 发DATA1 端点0

           CH375_HOLD_INT(device); //卡在这里等中断

           if(CH375_RD_INTDATA(device) == 0x14) //执行OUT事务ok
           {
             return j_;
           }

         }

       }

    }

  }

  return 0;

}


unsigned int CH375_GET_BGMSF(unsigned char device,unsigned int index,unsigned int len,unsigned char *buf) //获取报告描述符,device选择设备,index为索引值,len为描述符长度,buf描述符数据缓冲区首地址,成功返回读取的字节数,否则返回0
{

unsigned char i;
unsigned char x;
unsigned int j;

         if (len > 256) len = 256; //限制大小
         CH375_USB_CTL(device,0x81,0x06,0x00,0x22,index,index >> 8,len ,len >> 8); //获取报告描述符

         CH375_HOLD_INT(device); //卡在这里等中断

         if(CH375_RD_INTDATA(device) == 0x14) //获取报告描述符ok
         {

           x = 0;
           j = 0;
           while(j < len)
           {

             CH375_USB_IN(device,(x = ~x),0); //执行IN事务
             CH375_HOLD_INT(device); //卡在这里等中断

             if(CH375_RD_INTDATA(device) == 0x14) //执行IN事务ok
             {

               i = CH375_RD_bufDATA(device,buf); //读CH375的缓冲区数据到本机缓冲区
               buf += i; //缓冲区首地址推进
               j += i; //计算已读取字节数

             }
             else return 0;

           }

           CH375_WR_bufDATA(device,0,buf); //回复0数据的DATA1
           CH375_USB_OUT(device,1,0); //OUT事务 发DATA1 端点0

           CH375_HOLD_INT(device); //卡在这里等中断

           if(CH375_RD_INTDATA(device) == 0x14) //执行OUT事务ok
           {
             return j;
           }

         }

  return 0;

}


void CH375_FXPZMSF(unsigned char device,unsigned int len,unsigned char *buf) //分析配置描述符,device选择设备,len为配置描述符长度,buf为配置描述符缓冲区
{

unsigned int len_; //配置描述符长度计数
unsigned char ddh;

  ddh = 0; //端点号清0
  len_ = 0;

  while(len_ < len)
  {

    if(buf[0] == 0x09 && buf[1] == 0x02) //配置描述符
    {
      len_ += *buf; //描述符位置推进
      buf += *buf;
    }
    else if(buf[0] == 0x09 && buf[1] == 0x04) //接口描述符
    {

      if((buf[7] == 0x01 || buf[7] == 0x02) && buf[9] == 0x09 && buf[10] == 0x21 && buf[18] == 0x07 && buf[19] == 0x05) //键盘或鼠标,有HID描述符,端点描述符,进入分析
      {

        ++ddh; //端点号递增

        if (CH375_SBDM[device] != 0x01 && buf[7] == 0x01) //键盘不存在时记录描述符数据
        {
          CH375_KEY_InterfaceNumber[device] = buf[2]; //记录设备接口号
          CH375_KEY_DDH[device] = ddh; //键盘端点号
          CH375_KEY_Report_len[device] = ((CH375_KEY_Report_len[device] = buf[17]) << 8) | buf[16]; //记录键盘报告描述符长度
          CH375_KEY_MaxPacketSize[device] = ((CH375_KEY_MaxPacketSize[device] = buf[23]) << 8) | buf[22]; //记录键盘端点最大数据包大小
        }
        else
        {
          CH375_MOUSE_InterfaceNumber[device] = buf[2]; //记录设备接口号
          CH375_MOUSE_DDH[device] = ddh; //鼠标端点号
          CH375_MOUSE_Report_len[device] = ((CH375_MOUSE_Report_len[device] = buf[17]) << 8) | buf[16]; //记录鼠标报告描述符长度
          CH375_MOUSE_MaxPacketSize[device] = ((CH375_MOUSE_MaxPacketSize[device] = buf[23]) << 8) | buf[22]; //记录鼠标端点最大数据包大小
        }

        CH375_SBDM[device] |= buf[7]; //记录设备代码

        buf += 25; //描述符位置推进
        len_ += 25;

      }
      else //不是键盘鼠标或格式不对
      {
        len_ += *buf; //描述符位置推进
        buf += *buf;
      }

    }
    else if(buf[0] == 0x07 && buf[1] == 0x05) //端点描述符
    {
      len_ += *buf; //描述符位置推进
      buf += *buf;
      ++ddh; //端点号递增
    }
    else
    {
      len_ += *buf; //描述符位置推进
      buf += *buf;
    }

  }

}

unsigned char CH375_KEY_FXBGMSF(unsigned char device, int len, unsigned char* buf) //分析键盘报告描述符,分析成功返回非0,device选择设备,len为报告描述符长度,buf为报告描述符缓冲区
{

unsigned char Collection_Application;
unsigned char Collection_Physical;
unsigned char Report_ID;
unsigned char Usage_Page;
unsigned char Usage_Minimum;
unsigned int Usage_Maximum;
unsigned char Logical_Minimum;
unsigned int Logical_Maximum;
unsigned char Report_Size;
unsigned char Report_Count;
unsigned char Input;
unsigned char Output;
unsigned char p;
unsigned char i;

    if (len > 0 && buf[0] == 0x05 && buf[1] = 0x01 && buf[2] = 0x09 && buf[3] = 0x06) //Usage Page (Generic Desktop) & Usage (Keyboard)
    {
        Collection_Application = 0;
        Collection_Physical = 0;
        Report_ID = 0;
        Usage_Page = 0;
        Usage_Minimum = 0;
        Usage_Maximum = 0;
        Logical_Minimum = 0;
        Logical_Maximum = 0;
        Report_Size = 0;
        Report_Count = 0;
        Input = 0;
        Output = 0;
        p = 0;
        buf += 4;
        len -= 4;

        do
        {
            i = (buf[0] & 0x03) + 1; //提取项目长度

            if (buf[0] == 0xa1 && buf[1] == 0x01) //Collection (Application)
            {
                Collection_Application = 1;
            }
            else if (buf[0] == 0x05) //Usage Page
            {
                Usage_Page = buf[1];
            }
            else if (buf[0] == 0x19) //Usage Minimum
            {
                Usage_Minimum = buf[1];
            }
            else if (buf[0] == 0x29) //Usage Maximum
            {
                Usage_Maximum = buf[1];
            }
            else if (buf[0] == 0x2a) //Usage Maximum (2)
            {
                Usage_Maximum = ((Usage_Maximum = buf[2]) << 8) | buf[1];
            }
            else if (buf[0] == 0x15) //Logical Minimum
            {
                Logical_Minimum = buf[1];
            }
            else if (buf[0] == 0x25) //Logical Maximum
            {
                Logical_Maximum = buf[1];
            }
            else if (buf[0] == 0x16) //Logical Minimum (2)
            {
                Logical_Minimum = ((Logical_Minimum = buf[2]) << 8) | buf[1];
            }
            else if (buf[0] == 0x26) //Logical Maximum (2)
            {
                Logical_Maximum = ((Logical_Maximum = buf[2]) << 8) | buf[1];
            }
            else if (buf[0] == 0x75) //Report Size
            {
                Report_Size = buf[1];
            }
            else if (buf[0] == 0x95) //Report Count
            {
                Report_Count = buf[1];
            }
            else if (buf[0] == 0x81) //Input
            {
                if (Usage_Page == 0x07) //Usage Page(Keyboard / Keypad)
                {
                    if (Input == 0x02 && buf[1] == 0x01) //空描述
                    {
                        if (Report_Size != 8 || Report_Count != 1) break;
                    }
                    else if (Report_Size == 1 && Report_Count == 8 && Logical_Minimum == 0x00 && Logical_Maximum == 0x01 && Usage_Minimum == 0xe0 && Usage_Maximum == 0xe7) //处理Keyboard Left Control && Keyboard Right GUI
                    {
                        CH375_KEY_BYTE_ADDR_Left_control_Right_GUI[device] = p;
                        p += 1;
                    }
                    else if (Report_Size == 8 && Report_Count == 6 && Logical_Minimum == 0x00 && Logical_Maximum > 1 && Usage_Minimum == 0x00) //处理键盘的6个键
                    {
                        CH375_KEY_BYTE_ADDR_VALUE_6[device] = p;
                        p += 6;
                    }
                    else break;
                }
                else break;

                Input = buf[1];
            }
            else if (buf[0] == 0x91) //Output
            {
                if (Usage_Page == 0x08) //Usage Page (LEDs)
                {
                    if (Report_Size * Report_Count > 8) //超过一个字节
                    {
                        break;
                    }
                    else if (Output == 0x02 && buf[1] == 0x01) //空描述
                    {
                    }
                    else //处理LEDs
                    {
                        CH375_KEY_BYTE_ADDR_LEDs[device] = p;
                        p += 1;
                    }
                }
                else break;

                Output = buf[1];
            }
            else if (buf[0] == 0xc0) //End Collection
            {
                if (Collection_Application != 0 && p <= CH375_KEY_MaxPacketSize[device]) return 1;
                else break;
            }
            else break;

            buf += i;
            len -= i;

        } while (len > 0);
    }

    return 0;
}

unsigned char CH375_MOUSE_FXBGMSF(unsigned char device, int len, unsigned char* buf) //分析鼠标报告描述符,分析成功返回非0,device选择设备,len为报告描述符长度,buf为报告描述符缓冲区
{

unsigned char Collection_Application;
unsigned char Collection_Physical;
unsigned char Report_ID;
unsigned char Usage_Page;
unsigned char Usage[3];
unsigned char Usage_num;
unsigned char Usage_num_;
unsigned char Usage_Minimum;
unsigned int Usage_Maximum;
unsigned char Logical_Minimum;
unsigned int Logical_Maximum;
unsigned char Report_Size;
unsigned char Report_Count;
unsigned char Input;
unsigned char Output;
unsigned char p;
unsigned char i;


    if (len > 0 && buf[0] == 0x05 && buf[1] = 0x01 && buf[2] = 0x09 && buf[3] = 0x02) //Usage Page (Generic Desktop) & Usage (Mouse)
    {
        Collection_Application = 0;
        Collection_Physical = 0;
        Report_ID = 0;
        Usage_Page = 0;
        Usage_num = 0;
        Usage_Minimum = 0;
        Usage_Maximum = 0;
        Logical_Minimum = 0;
        Logical_Maximum = 0;
        Report_Size = 0;
        Report_Count = 0;
        Input = 0;
        Output = 0;
        p = 0;
        buf += 4;
        len -= 4;

        do
        {
            i = (buf[0] & 0x03) + 1; //提取项目长度

            if (buf[0] == 0xa1 && buf[1] == 0x01) //Collection (Application)
            {
                Collection_Application = 1;
            }
            else if (buf[0] == 0xa1 && buf[1] == 0x00) //Collection (Physical)
            {
                Usage_num = 0;
                Collection_Physical = 1;
            }
            else if (buf[0] == 0x85) //Report ID
            {
                Report_ID = buf[1];
                p += 8;
            }
            else if (buf[0] == 0x05) //Usage Page
            {
                Usage_Page = buf[1];
            }
            else if (buf[0] == 0x09) //Usage
            {
                Usage[Usage_num] = buf[1];
                if (++Usage_num == 4) break;
            }
            else if (buf[0] == 0x19) //Usage Minimum
            {
                Usage_Minimum = buf[1];
            }
            else if (buf[0] == 0x29) //Usage Maximum
            {
                Usage_Maximum = buf[1];
            }
            else if (buf[0] == 0x2a) //Usage Maximum (2)
            {
                Usage_Maximum = ((Usage_Maximum = buf[2]) << 8) | buf[1];
            }
            else if (buf[0] == 0x15) //Logical Minimum
            {
                Logical_Minimum = buf[1];
            }
            else if (buf[0] == 0x25) //Logical Maximum
            {
                Logical_Maximum = buf[1];
            }
            else if (buf[0] == 0x16) //Logical Minimum (2)
            {
                Logical_Minimum = ((Logical_Minimum = buf[2]) << 8) | buf[1];
            }
            else if (buf[0] == 0x26) //Logical Maximum (2)
            {
                Logical_Maximum = ((Logical_Maximum = buf[2]) << 8) | buf[1];
            }
            else if (buf[0] == 0x75) //Report Size
            {
                Report_Size = buf[1];
            }
            else if (buf[0] == 0x95) //Report Count
            {
                Report_Count = buf[1];
            }
            else if (buf[0] == 0x81) //Input
            {
                if (Usage_Page == 0x09) //Usage Page (Button)
                {
                    if (Input == 0x02 && buf[1] == 0x01) //空描述
                    {
                        p += Report_Size * Report_Count;
                    }
                    else if (Logical_Minimum == 0x00 && Logical_Maximum == 0x01 && Usage_Minimum == 1 && Usage_Maximum > 1) //处理Usage Page (Button)
                    {
                        CH375_MOUSE_BIT_ADDR_Button[device] = p;
                        CH375_MOUSE_BIT_SIZE_Button[device] = Report_Size * Report_Count;
                        p += Report_Size * Report_Count;
                    }
                    else break;
                }
                else if (Usage_Page == 0x01) //Usage Page (Generic Desktop)
                {
                    if (Usage_num != 0 && Usage_num < 4 && Report_Count == Usage_num)
                    {
                        Usage_num_ = 0;

                        do
                        {
                            if (Usage[Usage_num_] == 0x30) //X
                            {
                                CH375_MOUSE_BIT_ADDR_X[device] = p;
                                CH375_MOUSE_BIT_SIZE_X[device] = Report_Size;
                            }
                            else if (Usage[Usage_num_] == 0x31) //Y
                            {
                                CH375_MOUSE_BIT_ADDR_Y[device] = p;
                                CH375_MOUSE_BIT_SIZE_Y[device] = Report_Size;
                            }
                            else if (Usage[Usage_num_] == 0x38) //(Wheel)
                            {
                                CH375_MOUSE_BIT_ADDR_Wheel[device] = p;
                                CH375_MOUSE_BIT_SIZE_Wheel[device] = Report_Size;
                            }

                            p += Report_Size;

                        } while (++Usage_num_ != Usage_num);

                        Usage_num = 0;
                    }
                    else break;
                }
                else
                {
                    p += Report_Size * Report_Count;
                }

                Input = buf[1];
            }
            else if (buf[0] == 0xc0) //End Collection
            {
                if (Collection_Physical != 0) Collection_Physical = 0;
                else if (Collection_Application != 0 && p <= (CH375_MOUSE_MaxPacketSize[device] << 3)) return 1;
                else break;
            }

            buf += i;
            len -= i;

        } while (len > 0);
    }

    return 0;
}


unsigned int CH375_BIT_TQ(unsigned char addr, char Bit_width, unsigned char *buf) //位提取,addr位地址,Bit_width位宽,buf缓冲区,返回值为提取的位
{

unsigned char Bit_offset; //位偏移
unsigned char Byte_offset; //字节偏移
unsigned char outbuf[2];
unsigned int Bit_16;
unsigned char js1;

    Bit_offset = addr % 8;
    Byte_offset = addr / 8;
    outbuf[0] = 0;
    outbuf[1] = 0;
    js1 = 0;

    while (Bit_width > 0)
    {
        outbuf[js1] = buf[Byte_offset] >> Bit_offset;
        outbuf[js1] |= buf[++Byte_offset] << (8 - Bit_offset);
        if (Bit_width < 8) outbuf[js1] = ~(0xfe << (Bit_width - 1)) & outbuf[js1];
        ++js1;
        Bit_width -= 8;
    }

    return ((Bit_16 = outbuf[1]) << 8) | outbuf[0];

}


unsigned char CH375_RUN()
{

unsigned char i;
unsigned char device;
unsigned int js1;

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

              if(i == 0x14) //命令执行成功
              {

                  if ((CH375_SBDM[device] & 0x01) != 0 && CH375_CURRENT_DDH[device] == CH375_KEY_DDH[device]) //键盘端点的数据
                  {

                      CH375_RD_bufDATA(device, CH375_DATAbuf); //读缓冲区数据

                      KEY_DATA[0] = CH375_DATAbuf[CH375_KEY_BYTE_ADDR_Left_control_Right_GUI[device]];
                      KEY_DATA[1] = CH375_DATAbuf[CH375_KEY_BYTE_ADDR_LEDs[device]];
                      i = CH375_KEY_BYTE_ADDR_VALUE_6[device];
                      KEY_DATA[2] = CH375_DATAbuf[i++];
                      KEY_DATA[3] = CH375_DATAbuf[i++];
                      KEY_DATA[4] = CH375_DATAbuf[i++];
                      KEY_DATA[5] = CH375_DATAbuf[i++];
                      KEY_DATA[6] = CH375_DATAbuf[i++];
                      KEY_DATA[7] = CH375_DATAbuf[i];
                  }
                  else if ((CH375_SBDM[device] & 0x02) != 0 && CH375_CURRENT_DDH[device] == CH375_MOUSE_DDH[device]) //鼠标端点的数据
                  {
                      CH375_RD_bufDATA(device, CH375_DATAbuf); //读缓冲区数据

                      SB_KEY = CH375_BIT_TQ(CH375_MOUSE_BIT_ADDR_Button[device], CH375_MOUSE_BIT_SIZE_Button[device], CH375_DATAbuf);
                      SB_X += CH375_BIT_TQ(CH375_MOUSE_BIT_ADDR_X[device], CH375_MOUSE_BIT_SIZE_X[device], CH375_DATAbuf);
                      SB_Y += CH375_BIT_TQ(CH375_MOUSE_BIT_ADDR_Y[device], CH375_MOUSE_BIT_SIZE_Y[device], CH375_DATAbuf);
                      SB_Z += CH375_BIT_TQ(CH375_MOUSE_BIT_ADDR_Wheel[device], CH375_MOUSE_BIT_SIZE_Wheel[device], CH375_DATAbuf);

                      SB_X = (SB_X << (16 - CH375_MOUSE_BIT_SIZE_X[device])) >> (16 - CH375_MOUSE_BIT_SIZE_X[device]);
                      SB_Y = (SB_Y << (16 - CH375_MOUSE_BIT_SIZE_Y[device])) >> (16 - CH375_MOUSE_BIT_SIZE_Y[device]);
                      SB_Z = (SB_Z << (16 - CH375_MOUSE_BIT_SIZE_Wheel[device])) >> (16 - CH375_MOUSE_BIT_SIZE_Wheel[device]);
                      
                      if (SB_X > 255) SB_X = 255;
                      else if (SB_X < 0) SB_X = 0;
                      if (SB_Y > 239) SB_Y = 239;
                      else if (SB_Y < 0) SB_Y = 0;
                      if (SB_Z > 255) SB_Z = 255;
                      else if (SB_Z < 0) SB_Z = 0;
                  }

                  CH375_INDX[device] = ~CH375_INDX[device];
                  //SPI_SET_DLED(0xe0); //SPI数据灯显示数据
              }
              else if(i == 0x15) //设备插入
              {
                  CH375_SBIOBZ = 1; //标志有设备插入
                  i = (CH375_GET_DEV_RATE(device) & 0x10) >> 3; //获取USB设备速率
                  CH375_SET_USB_MODE(device,0x07); //复位USB总线
                  CH375_SET_USB_MODE(device,0x06);  //设置为主机模式
                  CH375_SET_USB_BUSM(device, i); //设置USB总线速度
                  
                  if (CH375_GET_SBMSF(device,CH375_DATAbuf) != 0) //获取设备描述符
                  {
                      if ((js1 = CH375_GET_PZMSF(device, CH375_DATAbuf)) != 0) //获取配置描述符
                      {
                          CH375_FXPZMSF(device, js1, CH375_DATAbuf); //分析配置描述符

                          if ((CH375_SBDM[device] & 0x03) != 0) //设备为键盘或鼠标
                          {
                              if (CH375_AUTO_SETUP(device) != 0) //自动配置USB设备
                              {
                                  CH375_INDX[device] = 0; //先收DATA0

                                  if ((CH375_SBDM[device] & 0x01) != 0) //键盘
                                  {
                                      if (CH375_GET_BGMSF(device, CH375_KEY_InterfaceNumber[device], CH375_KEY_Report_len[device], CH375_DATAbuf) != 0) //获取报告描述符
                                      {
                                          if (CH375_KEY_FXBGMSF(device, CH375_KEY_Report_len[device], CH375_DATAbuf) != 0) //分析键盘报告描述符
                                          {
                                              CH375_CURRENT_DDH[device] = CH375_KEY_DDH[device];
                                          }
                                          else
                                          {
                                              CH375_SBDM[device] = CH375_SBDM[device] & ~0x01; //键盘标志清0
                                          }
                                          
                                      }
                                      else
                                      {
                                          CH375_SBDM[device] = CH375_SBDM[device] & ~0x01; //键盘标志清0
                                      }
                                  }

                                  if ((CH375_SBDM[device] & 0x02) != 0)//鼠标
                                  {
                                      if (CH375_GET_BGMSF(device, CH375_MOUSE_InterfaceNumber[device], CH375_MOUSE_Report_len[device], CH375_DATAbuf) != 0) //获取报告描述符
                                      {
                                          if (CH375_MOUSE_FXBGMSF(device, CH375_MOUSE_Report_len[device], CH375_DATAbuf) != 0) //分析鼠标报告描述符
                                          {
                                              CH375_CURRENT_DDH[device] = CH375_MOUSE_DDH[device];
                                          }
                                          else
                                          {
                                              CH375_SBDM[device] = CH375_SBDM[device] & ~0x02; //鼠标标志清0
                                          }
                                      }
                                      else
                                      {
                                          CH375_SBDM[device] = CH375_SBDM[device] & ~0x02; //鼠标标志清0
                                      }
                                  }
                              }
                              else
                              {
                                  CH375_SBDM[device] = 0; //没有设备
                              }
                          }
                          else //不是键盘或鼠标
                          {
                              if (CH375_DISK_INIT(device) != 0) //初始化USB存储设备
                              {
                                  CH375_SBDM[device] |= 0x04; //置位设备代码, 存储设备
                                  //SPI_SET_DLED(0xe1); //SPI数据灯显示数据
                              }
                              else
                              {
                                  //SPI_SET_DLED(0xe2); //SPI数据灯显示数据
                              }
                          }
                      }
                  }
              }
              else if(i == 0x16) //设备拔出
              {
                  CH375_SBIOBZ = 2; //标志有设备拔出
                  CH375_SBDM[device] = 0; //设备代码标志为无设备
                  CH375_SET_USB_MODE(device,0x05); //05H主机方式不产生SOF包
                  //SPI_SET_DLED(0xe2); //SPI数据灯显示数据
              }
              else //其他事件
              {
                  //SPI_SET_DLED(0xec);
              }
          }

          if ((CH375_SBDM[device] & 0x03) != 0) //有键盘鼠标设备
          {
              if (CH375_SBDM[device] == 0x03) //键盘鼠标同时存在
              {
                  CH375_ABORT_NAK(device);
                  for (js1 = 0; js1 < 32; ++js1);
                  if (CH375_CURRENT_DDH[device] == CH375_KEY_DDH[device]) CH375_CURRENT_DDH[device] = CH375_MOUSE_DDH[device]; //键盘鼠标端点号切换
                  else CH375_CURRENT_DDH[device] = CH375_KEY_DDH[device];
              }

              CH375_USB_IN(device, CH375_INDX[device], CH375_CURRENT_DDH[device]); //执行IN事务
          }

          ++device; //下一个设备

      }while(device != 4);

      CH375_CT2_ = CT2; //记录当前硬件计数器数据
  }

  return CH375_INTT;

}





unsigned char CH375_DISK_READ(unsigned char device,unsigned long int SQH,unsigned char LBAX) //从USB存储器设备读取数据块命令, device选择设备,SQH是扇区号,LBAX是读取扇区个数,返回值不为0表示操作成功
{

  if(CH375_device_bz[device] == 1 && (CH375_SBDM[device] & 0x04) != 0) ///CH375芯片存在并且设备是存储器,进入
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

     CH375_HOLD_INT(device); //卡在这里等中断

     if(CH375_RD_INTDATA(device) == 0x1d) //读成功
     {
         SPI_SET_DLED(0xaa);
        return 1;
     }

     SPI_SET_DLED(0x55);
  }else SPI_SET_DLED(CH375_SBDM[device]);

  return 0;

}


unsigned char CH375_DISK_RD_GO(unsigned char device) //继续读USB存储器设备数据块命令,device选择设备,返回值不为0表示操作成功
{

unsigned char i;

  if(CH375_device_bz[device] == 1 && (CH375_SBDM[device] & 0x04) != 0) //CH375芯片存在并且设备是存储器,进入
  {

     CS_8080 = 0x08|device; //选中8080总线设备
     D1_8080 = 0x55; //写命令
     CS_8080 = 0x00; //选中空设备

     CH375_HOLD_INT(device); //卡在这里等中断

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

  if(CH375_device_bz[device] == 1 && (CH375_SBDM[device] & 0x04) != 0) //CH375芯片存在并且设备是存储器,进入
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


     CH375_HOLD_INT(device); //卡在这里等中断

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

  if(CH375_device_bz[device] == 1 && (CH375_SBDM[device] & 0x04) != 0) //CH375芯片存在并且设备是存储器,进入
  {

     CS_8080 = 0x08|device; //选中8080总线设备
     D1_8080 = 0x57; //写命令
     CS_8080 = 0x00; //选中空设备

     CH375_HOLD_INT(device); //卡在这里等中断

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
unsigned char js2;
unsigned char js3 = 0;


    do
    {
        js2 = 1;
        while (js2 != 0)
        {
            if ((CH375_SBDM[js1] & js2) != 0) ++js3;
            js2 <<= 1;
        }

    } while (++js1 != 4);
    
    return js3;
}



