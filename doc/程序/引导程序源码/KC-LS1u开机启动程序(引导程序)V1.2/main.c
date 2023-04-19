#include<io.h>
#include<qjbldy.h>
#include<spi.h>
#include<tf_sd.h>
#include<fat32.h>
#include<VGA.h>


void speaker(unsigned int sj,unsigned int pl) //扬声器,sj为持续时间,pl为频率
{

unsigned int x;

   while(--sj != 0)
   {

      XT_C |= 0x20;
      for(x = 0;x != pl;++x);
      XT_C &= 0xdf;
      for(x = 0;x != pl;++x);

   }

}


void cw_0() //错误0
{
     speaker(110,70);
     speaker(110,75);
     speaker(110,80);
     speaker(110,85);
     speaker(110,90);
     speaker(110,95);
     speaker(110,100);
     speaker(110,105);
     speaker(110,110);
     speaker(110,115);
     speaker(110,120);
     speaker(110,125);
     speaker(110,130);
}

void cw_1() //错误1
{
     speaker(110,70);
     speaker(110,115);
     speaker(110,95);
     speaker(110,100);
     speaker(110,70);
     speaker(110,110);
     speaker(110,80);
     speaker(110,75);
     speaker(110,85);
     speaker(110,95);
     speaker(110,90);
     speaker(110,105);
     speaker(110,140);
     speaker(110,70);
     speaker(110,110);
     speaker(110,85);
     speaker(110,95);
     speaker(110,140);
     speaker(110,90);
     speaker(110,105);
     speaker(110,110);
     speaker(110,85);
     speaker(110,75);
     speaker(110,70);
     speaker(110,115);
     speaker(110,95);
     speaker(110,100);
     speaker(110,70);
     speaker(110,105);
     speaker(110,140);
     speaker(110,70);
     speaker(110,110);
     speaker(110,85);
     speaker(110,95);
     speaker(110,140);
     speaker(110,90);
     speaker(110,105);
     speaker(110,90);
     speaker(110,105);
     speaker(110,110);
     speaker(110,85);
     speaker(110,95);
     speaker(110,100);
     speaker(110,70);
     speaker(110,110);
     speaker(110,80);
     speaker(110,75);
     speaker(110,85);
     speaker(110,95);
}

void cw_2() //错误2
{
     speaker(110,95);
     speaker(110,100);
     speaker(110,70);
     speaker(110,110);
     speaker(110,80);
     speaker(110,124);
     speaker(110,85);
     speaker(110,143);
}


void spi_device_boot()  //SROM数据装载服务程序
{

unsigned char device;
unsigned int KC_LS1u_boot_0_txt[] = {'K' , 'C' , '_' , 'L' , 'S' , '1' , 'u' , '_' , 'b' , 'o' , 'o' , 't' , '_' , '0' , '.' , 't' , 'x' , 't' , 0};
unsigned int KC_LS1u_boot_1_txt[] = {'K' , 'C' , '_' , 'L' , 'S' , '1' , 'u' , '_' , 'b' , 'o' , 'o' , 't' , '_' , '1' , '.' , 't' , 'x' , 't' , 0};
unsigned char wj_data_32B[32];
unsigned long int culian[128]; //簇链
unsigned char culian_x; //簇指针,用来指簇链里面的簇号
unsigned long int sqh_; //簇的首扇区号
unsigned long int _sqh; //簇的尾扇区号+1
unsigned long int wj_cuhao; //记录文件首簇号
unsigned long int wj_dx; //记录文件大小
unsigned char buf[512]; //512字节缓冲区
unsigned int _buf[513]; //512双字缓冲区
unsigned char ROM_K = 0; //ROM_L和ROM_H装载切换控制,为0装载ROM_L,为1装载ROM_H
unsigned int js1; //计数1
unsigned long int js2; //计数2
unsigned char Y = 36; //提示信息的Y坐标
unsigned char device_bz = 0; //SPI设备初始化成功标志,位0为SPI设备0,位1为SPI设备1,置1表示初始化成功
unsigned int i; //延时变量
unsigned char sq_x = 0; //扇区计数
unsigned long int jdt_x_10M = 0; //220刻度满格的进度条位置的1千万倍
unsigned char *_SROM_L; //SROM_L装载结束地址
unsigned char *_SROM_H; //SROM_H装载结束地址
unsigned char *SROM_L_; //SROM_L装载指针
unsigned char *SROM_H_; //SROM_H装载指针



 CTVGA_C &= ~0x01; //请求访问VGA
 for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
 VGA_kuang_0(16,16,175,223,238); //主框
 VGA_SK_1(33,16,1,224,238);
 VGA_SROMSJZZFWCX_logo(19,68,255); //"SROM数据装载服务程序"标题
 VGA_kuang_0(208,16,15,223,0x1c); //进度条外框
 VGA_bfb_logo(210,115,0,255); //进度条百分比
 CTVGA_C |= 0x01; //请求VGA显示
 for(i = 0;i < 16000;i++);




      CTVGA_C &= ~0x01; //请求访问VGA
      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
      VGA_spi_device_csh_logo(Y,17,0,255);//"初始化SPI设备0内存卡..."
      CTVGA_C |= 0x01; //请求VGA显示
      for(i = 0;i < 16000;i++);

      CTVGA_C &= ~0x01; //请求访问VGA
      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
      if(TF_SD_CSH(0) != 0) device_bz = 0x01,VGA_cshwc_logo(Y+=13,17,255); //设备0初始化成功
      else VGA_cshsb_logo(Y+=13,17,255); //设备0初始化失败
      CTVGA_C |= 0x01; //请求VGA显示
      for(i = 0;i < 16000;i++);


      CTVGA_C &= ~0x01; //请求访问VGA
      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
      VGA_spi_device_csh_logo(Y+=13,17,1,255);//"初始化SPI设备1内存卡..."
      CTVGA_C |= 0x01; //请求VGA显示
      for(i = 0;i < 16000;i++);

      CTVGA_C &= ~0x01; //请求访问VGA
      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
      if(TF_SD_CSH(1) != 0) device_bz |= 0x02,VGA_cshwc_logo(Y+=13,17,255); //设备1初始化成功
      else VGA_cshsb_logo(Y+=13,17,255); //设备1初始化失败
      CTVGA_C |= 0x01; //请求VGA显示
      for(i = 0;i < 16000;i++);



           if((device_bz & 0x01) == 0x01) device = 0; //使用SPI设备0
      else if((device_bz & 0x02) == 0x02) device = 1; //使用SPI设备1
      else //两个设备都没有初始化成功,进入处理
      {
         _A = 0xaa; //A寄存器显示0xaa
         _B = 0x01; //B寄存器显示0x01
         while(1);
      }






      CTVGA_C &= ~0x01; //请求访问VGA
      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
      VGA_spi_device_boot_txt_logo(Y+=13,17,device,(XT_C & 0x10) >> 4,255); //"搜索SPI设备X内存卡引导X文本..."
      CTVGA_C |= 0x01; //请求VGA显示
      for(i = 0;i < 16000;i++);


      if(FAT32_csh(device) != 0  &&  ( (XT_C & 0x10) == 0x00 && FAT32_wjcx_1(device,KC_LS1u_boot_0_txt,wj_data_32B) != 0  ||  (XT_C & 0x10) == 0x10 && FAT32_wjcx_1(device,KC_LS1u_boot_1_txt,wj_data_32B) != 0 ) ) //初始化FAT32,并且查找引导文本,执行成功进入处理
      {
         CTVGA_C &= ~0x01; //请求访问VGA
         for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
         VGA_zdwb_logo(Y+=13,17,255); //"找到文本"
         CTVGA_C |= 0x01; //请求VGA显示
         for(i = 0;i < 16000;i++);
      }
      else
      {
         CTVGA_C &= ~0x01; //请求访问VGA
         for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
         VGA_myzdwb_logo(Y+=13,17,255); //"没有找到文本"
         CTVGA_C |= 0x01; //请求VGA显示
         for(i = 0;i < 16000;i++);

         if(device == 0 && (device_bz & 0x02) == 0x02) //失败的是设备0并且设备1存在,进入处理
         {

              device = 1; //切换为设备1

              CTVGA_C &= ~0x01; //请求访问VGA
              for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
              VGA_spi_device_boot_txt_logo(Y+=13,17,device,(XT_C & 0x10) >> 4,255); //"搜索SPI设备X内存卡引导X文本..."
              CTVGA_C |= 0x01; //请求VGA显示
              for(i = 0;i < 16000;i++);

              if(FAT32_csh(device) != 0  &&  ( (XT_C & 0x10) == 0x00 && FAT32_wjcx_1(device,KC_LS1u_boot_0_txt,wj_data_32B) != 0  ||  (XT_C & 0x10) == 0x10 && FAT32_wjcx_1(device,KC_LS1u_boot_1_txt,wj_data_32B) != 0 ) ) //初始化FAT32,并且查找引导文本,执行成功进入处理
              {
                 CTVGA_C &= ~0x01; //请求访问VGA
                 for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
                 VGA_zdwb_logo(Y+=13,17,255); //"找到文本"
                 CTVGA_C |= 0x01; //请求VGA显示
                 for(i = 0;i < 16000;i++);
              }
              else
              {
                 CTVGA_C &= ~0x01; //请求访问VGA
                 for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
                 VGA_myzdwb_logo(Y+=13,17,255); //"没有找到文本"
                 CTVGA_C |= 0x01; //请求VGA显示
                 _A = 0xaa; //A寄存器显示0xaa
                 _B = 0x03; //B寄存器显示0x03
                 while(1);
              }

         }
         else
         {
            _A = 0xaa; //A寄存器显示0xaa
            _B = 0x02; //B寄存器显示0x02
            while(1);
         }

      }



      wj_cuhao = wj_data_32B[0x15]; //记录文件首簇号
      wj_cuhao <<= 8;
      wj_cuhao |= wj_data_32B[0x14];
      wj_cuhao <<= 8;
      wj_cuhao |= wj_data_32B[0x1b];
      wj_cuhao <<= 8;
      wj_cuhao |= wj_data_32B[0x1a];

      wj_dx = wj_data_32B[0x1f]; //记录文件大小
      wj_dx <<= 8;
      wj_dx |= wj_data_32B[0x1e];
      wj_dx <<= 8;
      wj_dx |= wj_data_32B[0x1d];
      wj_dx <<= 8;
      wj_dx |= wj_data_32B[0x1c];


      if(wj_dx > 512 || wj_dx < 13) //文件大小范围不对,进入处理
      {
          CTVGA_C &= ~0x01; //请求访问VGA
          for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
          VGA_wjljcw_logo(Y+=13,17,255); //"文件路径错误"
          CTVGA_C |= 0x01; //请求VGA显示
          cw_2(); //错误报警
          _A = 0xaa; //A寄存器显示0xaa
          _B = 0x04; //B寄存器显示0x04
          while(1);
      }



      if(TF_SD_RD_512B(device,FAT32_cuhao_shanquhao(device,wj_cuhao),buf) == 0) //读出存放启动文件路径的文本首512B,没有操作成功进入处理
      {
          CTVGA_C &= ~0x01; //请求访问VGA
          for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
          VGA_spisbcw_logo(Y+=13,17,255); //"SPI设备错误"
          CTVGA_C |= 0x01; //请求VGA显示
          cw_0(); //错误报警
          _A = 0xaa; //A寄存器显示0xaa
          _B = 0x05; //B寄存器显示0x05
          while(1);
      }

      if(buf[0] != 's' || buf[1] != 'p' || buf[2] != 'i' || buf[3] != '_' || buf[4] != 'd' || buf[5] != 'e' || buf[6] != 'v' || buf[7] != 'i' || buf[8] != 'c' || buf[9] != 'e' || buf[11] != ':') //设备描述不对进入处理
      {
          CTVGA_C &= ~0x01; //请求访问VGA
          for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
          VGA_wjljcw_logo(Y+=13,17,255); //"文件路径错误"
          CTVGA_C |= 0x01; //请求VGA显示
          cw_2(); //错误报警
          _A = 0xaa; //A寄存器显示0xaa
          _B = 0x06; //B寄存器显示0x06
          while(1);
      }

      if(buf[10] == '0') device = 0;
      else if(buf[10] == '1') device = 1;
      else if(buf[10] == '_');
      else //设备描述不对进入处理
      {
          CTVGA_C &= ~0x01; //请求访问VGA
          for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
          VGA_wjljcw_logo(Y+=13,17,255); //"文件路径错误"
          CTVGA_C |= 0x01; //请求VGA显示
          cw_2(); //错误报警
          _A = 0xaa; //A寄存器显示0xaa
          _B = 0x07; //B寄存器显示0x07
          while(1);
      }

      for(js1 = 0;js1 != 512;++js1) _buf[js1] = buf[js1]; //字节缓冲区数据转入双字缓冲区
      _buf[wj_dx] = 0; //填路径结束符0







      CTVGA_C &= ~0x01; //请求访问VGA
      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
      VGA_ssmbwj_logo(Y+=13,17,device,_buf + 12,255); //"搜索目标文件(SPI设备X):文件路径"
      CTVGA_C |= 0x01; //请求VGA显示
      for(i = 0;i < 16000;i++);


      if(FAT32_wjcx_1(device,_buf + 12,wj_data_32B) == 0) //查找ROM程序文件,没找到进入处理
      {
          CTVGA_C &= ~0x01; //请求访问VGA
          for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
          VGA_myzdmbwj_logo(Y+=13,17,255); //"没有找到目标文件"
          CTVGA_C |= 0x01; //请求VGA显示
          _A = 0xaa; //A寄存器显示0xaa
          _B = 0x08; //B寄存器显示0x08
          while(1);
      }

      CTVGA_C &= ~0x01; //请求访问VGA
      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
      VGA_zdmbwj_logo(Y+=13,17,255); //"找到目标文件"
      CTVGA_C |= 0x01; //请求VGA显示
      for(i = 0;i < 16000;i++);

      wj_cuhao = wj_data_32B[0x15]; //记录ROM程序文件首簇号
      wj_cuhao <<= 8;
      wj_cuhao |= wj_data_32B[0x14];
      wj_cuhao <<= 8;
      wj_cuhao |= wj_data_32B[0x1b];
      wj_cuhao <<= 8;
      wj_cuhao |= wj_data_32B[0x1a];

      wj_dx = wj_data_32B[0x1f]; //记录ROM程序文件大小
      wj_dx <<= 8;
      wj_dx |= wj_data_32B[0x1e];
      wj_dx <<= 8;
      wj_dx |= wj_data_32B[0x1d];
      wj_dx <<= 8;
      wj_dx |= wj_data_32B[0x1c];



      CTVGA_C &= ~0x01; //请求访问VGA
      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
      VGA_mbwjdx_logo(Y+=13,17,wj_dx,255); //"目标文件大小:x字节"
      CTVGA_C |= 0x01; //请求VGA显示
      for(i = 0;i < 16000;i++);

      if(wj_dx < 2 || (wj_dx & 0x00000001) == 1 || wj_dx > 4194304)
      {
          CTVGA_C &= ~0x01; //请求访问VGA
          for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
          if(Y > 153) VGA_wbsy(),Y=153; //超出打印范围,清行
          VGA_mbwjdxcw_logo(Y+=13,17,255); //"目标文件大小错误"
          CTVGA_C |= 0x01; //请求VGA显示
          _A = 0xaa; //A寄存器显示0xaa
          _B = 0x09; //B寄存器显示0x09
          while(1);
      }



      js2 = 0;              //检查SROM内存大小

      do
      {
         SROM_L[js2] = 0xaa;
         SROM_L[js2+1] = 0x50;
         SROM_H[js2] = 0x55;
         SROM_H[js2+1] = 0x0a;
         if(SROM_L[js2] == 0xaa && SROM_H[js2] != 0x55 || SROM_L[js2] != 0xaa && SROM_H[js2] == 0x55) //内存错误
         {
            CTVGA_C &= ~0x01; //请求访问VGA
            for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
            if(Y > 153) VGA_wbsy(),Y=153; //超出打印范围,清行
            VGA_sromnccw_logo(Y+=13,17,255); //"SROM内存错误"
            CTVGA_C |= 0x01; //请求VGA显示
            cw_1(); //错误报警
            _A = 0xaa; //A寄存器显示0xaa
            _B = 0x0a; //B寄存器显示0x0a
            while(1);
         }

         if(SROM_L[js2] + SROM_H[js2] != 0xff) break;

         SROM_L[js2] = 0x55;
         SROM_L[js2+1] = 0x0a;
         SROM_H[js2] = 0xaa;
         SROM_H[js2+1] = 0x50;
         if(SROM_L[js2] == 0x55 && SROM_H[js2] != 0xaa || SROM_L[js2] != 0x55 && SROM_H[js2] == 0xaa) //内存错误
         {
            CTVGA_C &= ~0x01; //请求访问VGA
            for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
            if(Y > 153) VGA_wbsy(),Y=153; //超出打印范围,清行
            VGA_sromnccw_logo(Y+=13,17,255); //"SROM内存错误"
            CTVGA_C |= 0x01; //请求VGA显示
            cw_1(); //错误报警
            _A = 0xaa; //A寄存器显示0xaa
            _B = 0x0b; //B寄存器显示0x0b
            while(1);
         }

         if(SROM_L[js2] + SROM_H[js2] != 0xff) break;

         js2 += 1024;

      }while(js2 != 2097152);



      CTVGA_C &= ~0x01; //请求访问VGA
      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
      if(Y > 153) VGA_wbsy(),Y=153; //超出打印范围,清行
      VGA_ncyc_logo(Y+=13,17,js2<<=1,255); //"SROM内存大小:X字节"
      CTVGA_C |= 0x01; //请求VGA显示
      for(i = 0;i < 16000;i++);



      if(wj_dx > js2) //文件大小超出SROM大小,进入处理
      {
          CTVGA_C &= ~0x01; //请求访问VGA
          for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
          if(Y > 153) VGA_wbsy(),Y=153; //超出打印范围,清行
          VGA_sromncyc_logo(Y+=13,17,255); //"SROM内存溢出"
          CTVGA_C |= 0x01; //请求VGA显示
          cw_1(); //错误报警
          _A = 0xaa; //A寄存器显示0xaa
          _B = 0x0c; //B寄存器显示0x0c
          while(1);
      }


      CTVGA_C &= ~0x01; //请求访问VGA
      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
      if(Y > 153) VGA_wbsy(),Y=153; //超出打印范围,清行
      VGA_sjzzz_logo(Y+=13,17,255); //"数据装载中..."
      CTVGA_C |= 0x01; //请求VGA显示
      for(i = 0;i < 16000;i++);



      if(TF_SD_RD_512B(device,sqh_ = FAT32_cuhao_shanquhao(device,wj_cuhao),buf) == 0) //读出ROM程序文件首扇区,没成功进入处理
      {
          CTVGA_C &= ~0x01; //请求访问VGA
          for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
          if(Y > 153) VGA_wbsy(),Y=153; //超出打印范围,清行
          VGA_spisbcw_logo(Y+=13,17,255); //"SPI设备错误"
          CTVGA_C |= 0x01; //请求VGA显示
          cw_0(); //错误报警
          _A = 0xaa; //A寄存器显示0xaa
          _B = 0x0d; //B寄存器显示0x0d
          while(1);
      }
      _sqh = sqh_ + FAT32_cudx[device]; //记录首簇的尾扇区号+1
      ++sqh_; //指向下一个扇区

      if(FAT32_cuhao_culian(device,wj_cuhao,128,culian) == 0) //读出首簇指向的下面128个簇放到簇链缓冲区,没成功进入处理
      {
          CTVGA_C &= ~0x01; //请求访问VGA
          for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
          if(Y > 153) VGA_wbsy(),Y=153; //超出打印范围,清行
          VGA_spisbcw_logo(Y+=13,17,255); //"SPI设备错误"
          CTVGA_C |= 0x01; //请求VGA显示
          cw_0(); //错误报警
          _A = 0xaa; //A寄存器显示0xaa
          _B = 0x0e; //B寄存器显示0x0e
          while(1);
      }
      culian_x = 0; //簇指针指向读出的首个簇



      SROM_L_ = SROM_L; //指向SROM_L起始地址
      SROM_H_ = SROM_H; //指向SROM_H起始地址
      _SROM_L = SROM_L + (wj_dx >> 1); //指向SROM_L装载结束地址
      _SROM_H = SROM_H + (wj_dx >> 1); //指向SROM_H装载结束地址


                  do
                  {

                         js1 = 0;

                         do
                         {
                            if(ROM_K == 0)
                            {

                                   *SROM_L_ = buf[js1]; ++SROM_L_; ++js1;

                                   if(SROM_L_ == _SROM_L) ROM_K = ~ROM_K;

                            }
                            else
                            {

                                   *SROM_H_ = buf[js1]; ++SROM_H_; ++js1;

                                   if(SROM_H_ == _SROM_H)
                                   {

                                      CTVGA_C &= ~0x01; //请求访问VGA
                                      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
                                      VGA_SK_1(210,18,12,220,115);        //进度条满格
                                      VGA_bfb_logo(210,115,100,255);       //进度条百分比为100%
                                      CTVGA_C |= 0x01; //请求VGA显示
                                      for(i = 0;i < 25000;i++);

                                      CTVGA_C &= ~0x01; //请求访问VGA
                                      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
                                      if(Y > 153) VGA_wbsy(),Y=153; //超出打印范围,清行
                                      VGA_qdcx_logo(Y+=13,17,255); //"启动程序"
                                      CTVGA_C |= 0x01; //请求VGA显示
                                      for(i = 0;i < 61000;i++);

                                      CTVGA_C &= ~0x01; //请求访问VGA
                                      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
                                      VGA_SK_0(0,240,0); //VGA清屏
                                      CTVGA_C |= 0x01; //请求VGA显示
                                      for(i = 0;i < 16000;i++);

                                      rom_run; //切换ROM

                                   }


                            }


                         }while(js1 != 512);


                         do
                         {

                                ++sq_x; //装完一个扇区,扇区计数+1

                                if(sq_x == 16) //扇区计数达到16(8192字节),进入刷新进度条和百分比
                                {
                                   sq_x = 0;

                                   jdt_x_10M += 2200000000 / (wj_dx >> 13); //计算进度条位置

                                   CTVGA_C &= ~0x01; //请求访问VGA
                                   for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
                                   VGA_SK_1(210,115,12,24,0); //擦除进度条百分比
                                   VGA_SK_1(210,18,12,jdt_x_10M/10000000,115); //更新进度条位置
                                   VGA_bfb_logo(210,115,jdt_x_10M/22000000,255); //更新进度条百分比
                                   CTVGA_C |= 0x01; //请求VGA显示
                                   for(i = 0;i < 7000;i++);
                                }




                                if(sqh_ == _sqh) //一个簇的扇区读完,进入换簇
                                {

                                   if(culian[culian_x] == 0x0fffffff) //为簇结束标志,文件错误,进入处理
                                   {
                                      CTVGA_C &= ~0x01; //请求访问VGA
                                      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
                                      if(Y > 153) VGA_wbsy(),Y=153; //超出打印范围,清行
                                      VGA_wjcw_logo(Y+=13,17,255); //"文件错误"
                                      CTVGA_C |= 0x01; //请求VGA显示
                                      cw_0(); //错误报警
                                      _A = 0xaa; //A寄存器显示0xaa
                                      _B = 0x0f; //B寄存器显示0x0f
                                      while(1);
                                   }

                                   sqh_ = FAT32_cuhao_shanquhao(device,culian[culian_x]); //簇号转首扇区号
                                   _sqh = sqh_ + FAT32_cudx[device]; //记录簇的尾扇区的下一扇区号   !!!BUG要改为device
             

                                   if(culian_x == 127) //尾簇? 进入更新簇链
                                   {
                                      if(FAT32_cuhao_culian(device,culian[127],128,culian) == 0) //读出尾簇指向的下面128个簇放到簇链缓冲区,如果错误,进入处理
                                      {
                                         CTVGA_C &= ~0x01; //请求访问VGA
                                         for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
                                         if(Y > 153) VGA_wbsy(),Y=153; //超出打印范围,清行
                                         VGA_spisbcw_logo(Y+=13,17,255); //"SPI设备错误"
                                         CTVGA_C |= 0x01; //请求VGA显示
                                         cw_0(); //错误报警
                                         _A = 0xaa; //A寄存器显示0xaa
                                         _B = 0x10; //B寄存器显示0x10
                                         while(1);
                                      }
                                      culian_x = 0; //簇指针指向读出的首个簇
                                   }
                                   else
                                   {
                                      ++culian_x; //指向下一个簇号
                                   }

                                }




                                if(ROM_K == 0)
                                {

                                    if(SROM_L_ + 512 < _SROM_L)
                                    {

                                        if(TF_SD_RD_512B(device,sqh_ ,SROM_L_) == 0) //读出一个扇区到缓冲区,如果错误,进入处理
                                        {
                                           CTVGA_C &= ~0x01; //请求访问VGA
                                           for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
                                           if(Y > 153) VGA_wbsy(),Y=153; //超出打印范围,清行
                                           VGA_spisbcw_logo(Y+=13,17,255); //"SPI设备错误"
                                           CTVGA_C |= 0x01; //请求VGA显示
                                           cw_0(); //错误报警
                                           _A = 0xaa; //A寄存器显示0xaa
                                           _B = 0x11; //B寄存器显示0x11
                                           while(1);
                                        }
                                        ++sqh_; //指向下一个扇区

                                        SROM_L_ += 512;

                                    }
                                    else
                                    {

                                        if(TF_SD_RD_512B(device,sqh_ ,buf) == 0) //读出一个扇区到缓冲区,如果错误,进入处理
                                        {
                                           CTVGA_C &= ~0x01; //请求访问VGA
                                           for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
                                           if(Y > 153) VGA_wbsy(),Y=153; //超出打印范围,清行
                                           VGA_spisbcw_logo(Y+=13,17,255); //"SPI设备错误"
                                           CTVGA_C |= 0x01; //请求VGA显示
                                           cw_0(); //错误报警
                                           _A = 0xaa; //A寄存器显示0xaa
                                           _B = 0x11; //B寄存器显示0x11
                                           while(1);
                                        }
                                        ++sqh_; //指向下一个扇区

                                        break;

                                    }

                                }
                                else
                                {

                                    if(SROM_H_ + 512 < _SROM_H)
                                    {

                                        if(TF_SD_RD_512B(device,sqh_ ,SROM_H_) == 0) //读出一个扇区到缓冲区,如果错误,进入处理
                                        {
                                           CTVGA_C &= ~0x01; //请求访问VGA
                                           for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
                                           if(Y > 153) VGA_wbsy(),Y=153; //超出打印范围,清行
                                           VGA_spisbcw_logo(Y+=13,17,255); //"SPI设备错误"
                                           CTVGA_C |= 0x01; //请求VGA显示
                                           cw_0(); //错误报警
                                           _A = 0xaa; //A寄存器显示0xaa
                                           _B = 0x11; //B寄存器显示0x11
                                           while(1);
                                        }
                                        ++sqh_; //指向下一个扇区


                                        SROM_H_ += 512;

                                    }
                                    else
                                    {

                                        if(TF_SD_RD_512B(device,sqh_ ,buf) == 0) //读出一个扇区到缓冲区,如果错误,进入处理
                                        {
                                           CTVGA_C &= ~0x01; //请求访问VGA
                                           for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
                                           if(Y > 153) VGA_wbsy(),Y=153; //超出打印范围,清行
                                           VGA_spisbcw_logo(Y+=13,17,255); //"SPI设备错误"
                                           CTVGA_C |= 0x01; //请求VGA显示
                                           cw_0(); //错误报警
                                           _A = 0xaa; //A寄存器显示0xaa
                                           _B = 0x11; //B寄存器显示0x11
                                           while(1);
                                        }
                                        ++sqh_; //指向下一个扇区

                                        break;

                                    }

                                }



                         }while(1);






                  }while(1);



}






main()
{

unsigned int i;
unsigned char ld;


    CTVGA_C &= ~0x01; //请求访问VGA
    for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
    VGA_SK_0(0,240,0); //VGA清屏
    CTVGA_C |= 0x01; //请求VGA显示

    SPI_RST(); //复位SPI控制器
    for(i = 0;i < 16000;i++);

    SPI_S = 0x04;  //SPI数据灯显示0x69
    SPI_D = 0x69;
    SPI_S = 0x01;
    for(i = 0;i < 61000;i++);


  if((XT_C & 0x01) == 0x00) //位0为0的时候进行开机画面
  {


      CTVGA_C &= ~0x01; //请求访问VGA
      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
      KC_LS1u_logo(16,16,0xe0,0x03,0x1c,238,176,95,115);
      CTVGA_C |= 0x01; //请求VGA显示

      for(i = 0;i < 61000;i++);
      for(i = 0;i < 61000;i++);
      for(i = 0;i < 61000;i++);


      ld = 0;

      do
      {
         CTVGA_C &= ~0x01; //请求访问VGA
         for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
         ET_logo(90,64,(ld << 5) | (ld << 2) | (ld >> 1));
         ++ld;
         CTVGA_C |= 0x01; //请求VGA显示
         for(i = 0;i < 16000;i++);

      }while(ld != 8);

      for(i = 0;i < 61000;i++);
      for(i = 0;i < 61000;i++);
      for(i = 0;i < 61000;i++);
      for(i = 0;i < 61000;i++);
      for(i = 0;i < 61000;i++);

      do
      {
         CTVGA_C &= ~0x01; //请求访问VGA
         for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
         --ld;
         ET_logo(90,64,(ld << 5) | (ld << 2) | (ld >> 1));
         CTVGA_C |= 0x01; //请求VGA显示
         for(i = 0;i < 16000;i++);

      }while(ld != 0);


      CTVGA_C &= ~0x01; //请求访问VGA
      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //可以访问的时候跳出
      VGA_SK_0(0,240,0); //VGA清屏
      CTVGA_C |= 0x01; //请求VGA显示
      speaker(160,151);
      for(i = 0;i < 61000;i++);


  }



  spi_device_boot(); //进入SROM数据装载服务程序


}