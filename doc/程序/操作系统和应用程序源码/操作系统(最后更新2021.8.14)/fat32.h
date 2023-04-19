/*-------------------------------------------------- FAT32文件系统存储器接口 --------------------------------------------------*/


unsigned char DEVICE_RD_512B(unsigned char device,unsigned long int SQH,unsigned char *buf)  //设备读512字节,device选择设备,SQH为扇区号,buf缓冲区,返回值不为0表示操作成功
{

unsigned char returnX = 0;

   if(FAT32_BZ[device] != 0)
   {
            if((device & 0xfe) == 0x00) returnX = TF_SD_RD_512B(device,SQH,buf);
       else if(device > 1 && device < 6) returnX = CH375_RD_LBA(device - 2,SQH,1,buf);

       if(returnX == 0) FAT32_BZ[device] = 0;
   }

   return returnX;

}

unsigned char DEVICE_WR_512B(unsigned char device,unsigned long int SQH,unsigned char *buf)  //设备写512字节,device选择设备,SQH为扇区号,buf缓冲区,返回值不为0表示操作成功
{

unsigned char returnX = 0;

   if(FAT32_BZ[device] != 0)
   {
            if((device & 0xfe) == 0x00) returnX = TF_SD_WR_512B(device,SQH,buf);
       else if(device > 1 && device < 6) returnX = CH375_WR_LBA(device - 2,SQH,1,buf);

       if(returnX == 0) FAT32_BZ[device] = 0;
   }

   return returnX;

}

unsigned long int DEVICE_GET_LBAX(unsigned char device) //取设备总容量,单位是扇区数
{

        if((device & 0xfe) == 0x00) return TF_SD_LBAX[device];
   else if(device > 1 && device < 6) return CH375_LBAX[device - 2];
   else return 0;

}

/*-------------------------------------------------------------------------------------------------------------------------------*/



/*-------------------------------------------------- FAT32文件系统实时时钟接口 --------------------------------------------------*/

unsigned char FAT32_RTC_SEC() //读取秒 ,返回8位2进制
{

unsigned char i;

    i = DS1302_RD(0) & 0x7f; //读出BCD码
    return ((i & 0xf0) >> 1) + ((i & 0xf0) >> 3) + (i & 0x0f);
}

unsigned char FAT32_RTC_MIN() //读取分钟 ,返回8位2进制
{

unsigned char i;

    i = DS1302_RD(1); //读出BCD码
    return ((i & 0xf0) >> 1) + ((i & 0xf0) >> 3) + (i & 0x0f);
}

unsigned char FAT32_RTC_HR() //读取小时 ,返回8位2进制
{

unsigned char i;

    i = DS1302_RD(2) & 0x7f; //读出BCD码
    return ((i & 0xf0) >> 1) + ((i & 0xf0) >> 3) + (i & 0x0f);
}

unsigned char FAT32_RTC_DATE() //读取日期 ,返回8位2进制
{

unsigned char i;

    i = DS1302_RD(3); //读出BCD码
    return ((i & 0xf0) >> 1) + ((i & 0xf0) >> 3) + (i & 0x0f);
}

unsigned char FAT32_RTC_MONTH() //读取月份 ,返回8位2进制
{

unsigned char i;

    i = DS1302_RD(4); //读出BCD码
    return ((i & 0xf0) >> 1) + ((i & 0xf0) >> 3) + (i & 0x0f);
}

unsigned char FAT32_RTC_YEAR() //读取年 ,0~99,返回8位2进制
{

unsigned char i;

    i = DS1302_RD(6); //读出BCD码
    return ((i & 0xf0) >> 1) + ((i & 0xf0) >> 3) + (i & 0x0f);
}

/*-------------------------------------------------------------------------------------------------------------------------------*/






void FAT32_WJF_32B_UPRTC(unsigned char *WJF_32B,unsigned char UPX) //更新文件时间信息,WJF_32B为32个字节文件符起始地址,UPX位2为1更新文件创建时间和日期,位1为1更新文件最后访问日期,位0为1更新文件最近修改时间和日期
{

unsigned int SJ;
unsigned int RQ;
unsigned char *_addr;


   SJ = FAT32_RTC_HR();
   SJ <<= 6;
   SJ |= FAT32_RTC_MIN();
   SJ <<= 5;
   SJ |= FAT32_RTC_SEC() >> 1;

   RQ = FAT32_RTC_YEAR() + 20;
   RQ <<= 4;
   RQ |= FAT32_RTC_MONTH();
   RQ <<= 5;
   RQ |= FAT32_RTC_DATE();


   if((UPX & 0x04) == 0x04) //更新文件创建时间和日期
   {
      _addr = &WJF_32B[0x0e];

      *_addr = SJ;
      ++_addr;
      *_addr = SJ >> 8;
      ++_addr;

      *_addr = RQ;
      ++_addr;
      *_addr = RQ >> 8;
   }

   if((UPX & 0x02) == 0x02) //更新文件最后访问日期
   {
      _addr = &WJF_32B[0x12];

      *_addr = RQ;
      ++_addr;
      *_addr = RQ >> 8;
   }

   if((UPX & 0x01) == 0x01) //更新文件最近修改时间和日期
   {
      _addr = &WJF_32B[0x16];

      *_addr = SJ;
      ++_addr;
      *_addr = SJ >> 8;
      ++_addr;

      *_addr = RQ;
      ++_addr;
      *_addr = RQ >> 8;
   }


}




unsigned char FAT32_csh(unsigned char device) //初始化该设备的FAT32文件系统和读取该设备的FAT32各参数, 如果操作成功返回值不为0, device选择SPI设备, 0为0号内存卡,1为1号内存卡
{

unsigned char buf[512];
unsigned int x;
unsigned long int FATDX;
unsigned long int FAT1addr;
unsigned long int FAT2addr;
unsigned long int DATAaddr;
unsigned long int _cuhao;
unsigned long int cudx_B;

    if(FAT32_BZ[device] == 0)
    {
        *buf = 0;
        while(*buf != FAT32_RWWJ_WJX) FAT32_RWWJ_bz[device*FAT32_RWWJ_WJX + *buf] = 0,++*buf;  //清0此设备的所有文件标志
    }

//////////////////////////////提取引导扇区地址/////////////////////////////////////////////////////////////

    FAT32_BZ[device] = 1; //先设置为1,可以读设备

    if(DEVICE_RD_512B(device,0,buf) == 0) //读出0号扇区到缓冲区,读失败进入处理
    {
        FAT32_BZ[device] = 0;
        return 0;
    }

///////////////////////提取簇大小、FAT表数量、FAT1表起始扇区号、FAT2表起始扇区号、数据区起始扇区号///////////

    if((x = buf[0x01c7]*256 + buf[0x01c6]) > 255) x = buf[0x01f7]*256 + buf[0x01f6];

    if(DEVICE_RD_512B(device,x,buf) == 0)  //读出引导扇区到缓冲区,读失败进入处理
    {
        FAT32_BZ[device] = 0;
        return 0;
    }


    FAT32_cudx[device] = buf[0x000d];  //提取簇大小(扇区数)
    cudx_B = buf[0x000d];
    FAT32_cudx_B[device] = cudx_B << 9; //乘512算出簇大小(字节)
    FAT32_FATsl[device] = buf[0x0010];  //提取FAT表数量
    FATDX = buf[0x0025]*256 + buf[0x0024]; //提取FAT表大小
    FAT32_FATDX[device] = FATDX; //记录FAT表大小

    FAT1addr = buf[0x000f]*256 + buf[0x000e] + x; //计算FAT表1号表的起始扇区号
    FAT2addr = FATDX + FAT1addr; //计算FAT表2号表的起始扇区号

    FAT32_FAT1addr[device] = FAT1addr;
    FAT32_FAT2addr[device] = FAT2addr;

    if(FAT32_FATsl[device] == 1) DATAaddr = FAT2addr; //计算FAT数据区的起始扇区号
    else DATAaddr = FATDX + FAT2addr; //计算FAT数据区的起始扇区号

    FAT32_DATAaddr[device] = DATAaddr;

    if(buf[0x0052] != 'F' || buf[0x0053] != 'A' || buf[0x0054] != 'T' || buf[0x0055] != '3' || buf[0x0056] != '2') //不是"FAT32"时,返回0
    {
        FAT32_BZ[device] = 0;
        return 0;
    }

    _cuhao = (DEVICE_GET_LBAX(device) - DATAaddr) / buf[0x000d] + 1; //算出存储器最后一个簇的簇号

    FAT32__cuhao[device] = _cuhao;

    FAT32__cuhao_LBAPY[device] = (_cuhao & 0x0000007f) << 2; //算出存储器最后一个扇区对应的簇号在扇区内的偏移



    if(FAT1addr + ((_cuhao) >> 7) == FAT2addr - 1) return 1; //FAT表没有错误时进入



    FAT32_BZ[device] = 0;
    return 0;


}





unsigned long int FAT32_cuhao_shanquhao(unsigned char device,unsigned long int cuhao) //簇号转扇区号, device选择SPI设备, 0为0号内存卡,1为1号内存卡, cuhao是簇号
{
   return FAT32_cudx[device] * (cuhao - 2) + FAT32_DATAaddr[device];
}





unsigned char FAT32_cuhao_culian(unsigned char device,unsigned long int cuhao,unsigned char x,unsigned long int *culian) //给簇号,读出簇链, device选择SPI设备, 0为0号内存卡,1为1号内存卡, cuhao是簇号, x是需要从簇链读出簇号的数量, culian是存放读出簇号的内存首地址,簇号为大端格式, 返回值不为0表示操作成功
{

unsigned char buf[512],*_buf;
unsigned long int _cuhao;


 goto in;

   do
   {

      if((_cuhao & 0xffffff80) == (cuhao & 0xffffff80)) //簇号指向的下个簇号在同一个扇区?
      {

         cuhao = _cuhao;

         _buf = buf + ((cuhao & 0x0000007f) << 2) + 3;       //读出簇号指向的下一个簇号

         _cuhao = *_buf;
         _cuhao <<= 8;
         --_buf;
         _cuhao |= *_buf;
         _cuhao <<= 8;
         --_buf;
         _cuhao |= *_buf;
         _cuhao <<= 8;
         --_buf;
         _cuhao |= *_buf;

         *culian = _cuhao;
         ++culian;
         --x;

      }
      else
      {

         cuhao = _cuhao;

 in:
         if( DEVICE_RD_512B(device,(cuhao >> 7) + FAT32_FAT1addr[device],buf) == 0 ) return 0; //读出簇号所在扇区到缓冲区

         _buf = buf + ((cuhao & 0x0000007f) << 2) + 3;         //读出簇号指向的下一个簇号

         _cuhao = *_buf;
         _cuhao <<= 8;
         --_buf;
         _cuhao |= *_buf;
         _cuhao <<= 8;
         --_buf;
         _cuhao |= *_buf;
         _cuhao <<= 8;
         --_buf;
         _cuhao |= *_buf;

         *culian = _cuhao;
         ++culian;
         --x;

      }


   }while(x != 0 && _cuhao != 0x0fffffff && _cuhao != 0x00000000);


  return 1;

}


/*

unsigned char FAT32_SETUP_culian(unsigned char device,unsigned long int cuhao_,unsigned long int CLX,unsigned char fatx) //给首簇号,创建簇链, device选择SPI设备, 0为0号内存卡,1为1号内存卡, cuhao是首簇号, CLX是创建簇数量, fatx选择FAT表,0为FAT1,其他值为FAT2, 返回值不为0表示操作成功
{

unsigned char buf[512]; //当前扫描缓冲区
unsigned long int sqh_; //记录首簇号所在扇区号
unsigned long int _sqh_; //记录待指簇号所在扇区号
unsigned long int _sqh; //记录扫描扇区号
unsigned long int cuhao_js1; //记录创建簇号数量
unsigned int cuhao_smzz; //簇号扫描指针
unsigned int py1; //记录待指簇号在扇区内的偏移
unsigned long int FAT_; //记录FAT表首扇区号
unsigned long int _FAT; //记录FAT表尾扇区号+1
unsigned char buf_bz; //标志当前扫描缓冲区是否有修改,有修改置1
//unsigned long int py2; //记录存储器最后一个扇区+1对应的簇号在扇区内的偏移

unsigned char buf_[512]; //临时缓冲区(局部)
unsigned long int js1; //计数1,记录空白簇的簇号(局部)


    if(fatx == 0) FAT_ = FAT32_FAT1addr[device],_FAT = FAT32_FAT2addr[device];
    else FAT_ = FAT32_FAT2addr[device],_FAT = FAT32_DATAaddr[device];
     
//    py2 = (FAT32__cuhao[device] & 0x0000007f) << 2; //算出存储器最后一个扇区+1对应的簇号在扇区内的偏移


    sqh_ = (cuhao_ >> 7) + FAT_; //计算首簇号所在扇区号
    _sqh = sqh_; //同值
    _sqh_ = sqh_; //记录待指簇号所在扇区号
    py1 = (cuhao_ & 0x0000007f) << 2; //记录待指簇号所在扇区内的偏移

    if(DEVICE_RD_512B(device,sqh_,buf) == 0) return 0; //读出首簇号所在扇区到缓冲区

    buf[py1] = 0xff; //首簇号位置标上数据,让其不为空白簇

    buf_bz = 0; //标志当前扫描缓冲区没有修改
    cuhao_smzz = 0; //簇号扫描指针指向此扇区的首簇
    cuhao_js1 = 0; //创建簇号数量计数清0

    while(cuhao_js1 != CLX)
    {

       while( cuhao_smzz != 512  &&  ( buf[cuhao_smzz] != 0x00 || buf[cuhao_smzz + 1] != 0x00 || buf[cuhao_smzz + 2] != 0x00 || buf[cuhao_smzz + 3] != 0x00 ) ) cuhao_smzz += 4; //扫描空白簇

       if(cuhao_smzz == 512 || _sqh + 1 == _FAT && cuhao_smzz == FAT32__cuhao_LBAPY[device] + 4) //没有找到空白簇
       {

          if(buf_bz == 1) //当前扫描缓冲区有修改,进入
          {
             buf[py1] = 0xff;    //待指簇号填上簇结束标志0x0fffffff
             buf[py1+1] = 0xff;
             buf[py1+2] = 0xff;
             buf[py1+3] = 0x0f;

             if(DEVICE_WR_512B(device,_sqh,buf) == 0) return 0; //缓冲区存盘

             buf_bz = 0; //标志清0
          }

          ++_sqh; //指向下个扫描扇区号
          if(_sqh == _FAT) _sqh = FAT_; //如果下个扫描扇区号超出FAT表范围,回归FAT表首部
          if(_sqh == sqh_) return 0; //FAT转了一圈,没找到空白簇,返回错误值
          if(DEVICE_RD_512B(device,_sqh,buf) == 0) return 0; //读出下个扫描扇区到缓冲区
          cuhao_smzz = 0; //簇号扫描指针指向此扇区的首簇

       }
       else //找到空白簇
       {

          buf_bz = 1; //标志当前扫描缓冲区有修改

          js1 = ((_sqh - FAT_) << 7) + (cuhao_smzz >> 2); //算出空白簇的簇号

          if(_sqh_ == _sqh)  //待指簇号所在扇区和当前空白簇所在扇区一样
          {

             buf[py1] = js1;          //修改待指簇号指向这个空白簇
             buf[py1+1] = js1 >> 8;
             buf[py1+2] = js1 >> 16;
             buf[py1+3] = js1 >> 24;

          }
          else  //待指簇号所在扇区和当前扇区不一样
          {

             if(DEVICE_RD_512B(device,_sqh_,buf_) == 0) return 0; //读出待指簇号所在扇区到备用缓冲区

             buf_[py1] = js1;          //修改待指簇号指向这个空白簇
             buf_[py1+1] = js1 >> 8;
             buf_[py1+2] = js1 >> 16;
             buf_[py1+3] = js1 >> 24;

             if(DEVICE_WR_512B(device,_sqh_,buf_) == 0) return 0; //备用缓冲区存盘

             _sqh_ = _sqh; //待指簇号所在扇区指向当前空白簇所在扇区

          }


          py1 = cuhao_smzz; //记录待指簇号所在扇区内的偏移指向这个空白簇

          cuhao_smzz += 4; //簇号扫描指针指向下个簇

          ++cuhao_js1; //创建簇号数量+1

       }
    }


    buf[py1] = 0xff;    //待指簇号填上簇结束标志0x0fffffff
    buf[py1+1] = 0xff;
    buf[py1+2] = 0xff;
    buf[py1+3] = 0x0f;

    if(DEVICE_WR_512B(device,_sqh,buf) == 0) return 0; //缓冲区存盘


    return 1;

}

*/


unsigned char FAT32_SETUP_culian(unsigned char device,unsigned long int cuhao_,unsigned long int CLX,unsigned char fatx) //给首簇号,创建簇链, device选择SPI设备, 0为0号内存卡,1为1号内存卡, cuhao_是首簇号, CLX是创建簇数量, fatx选择FAT表,0为FAT1,1为FAT2,3为FAT1和FAT2, 返回值不为0表示操作成功
{

unsigned char buf[512];
unsigned int py1;
unsigned long int FAT_;
unsigned long int sqh_;
unsigned char *_buf;

    if(fatx == 0)
    {
       FAT_ = FAT32_FAT1addr[device];
       FAT32_SETUP_culian_FAT_[device] = FAT_;
       FAT32_SETUP_culian__FAT[device] = FAT32_FAT2addr[device];
    }
    else
    {
       FAT_ = FAT32_FAT2addr[device];
       FAT32_SETUP_culian_FAT_[device] = FAT_;
       FAT32_SETUP_culian__FAT[device] = FAT32_DATAaddr[device];
    }


    sqh_ = (cuhao_ >> 7) + FAT_; //计算首簇号所在扇区号
    FAT32_SETUP_culian_sqh_[device] = sqh_; //同值
    FAT32_SETUP_culian__sqh[device] = sqh_; //同值
    FAT32_SETUP_culian__sqh_[device] = sqh_; //记录待指簇号所在扇区号

    py1 = (cuhao_ & 0x0000007f) << 2; //算出簇号所在扇区内的偏移
    FAT32_SETUP_culian_py1[device] = py1; //记录待指簇号所在扇区内的偏移


    if(DEVICE_RD_512B(device,sqh_,buf) == 0) return 0; //读出首簇号所在扇区到缓冲区

    _buf = buf + py1;    //首簇号标上0x0fffffff

    *_buf = 0xff;
    ++_buf;
    *_buf = 0xff;
    ++_buf;
    *_buf = 0xff;
    ++_buf;
    *_buf = 0x0f;

    if(DEVICE_WR_512B(device,sqh_,buf) == 0) return 0; //缓冲区存盘

    if(fatx == 3)
    {
       if(DEVICE_WR_512B(device,sqh_ - FAT32_FATDX[device],buf) == 0) return 0; //缓冲区存盘(写FAT1)
    }

    FAT32_SETUP_DELETE_fatx = fatx; //记录fat表选择
    FAT32_SETUP_culian_cuhao_js1[device] = 0; //已创建簇号数量计数清0
    FAT32_SETUP_culian_CLX[device] = CLX; //记录须创建簇数量

    return 1;

}


unsigned char FAT32_SETUP_culian_RUN(unsigned char device)
{

unsigned char buf[512];
unsigned char buf_[512];
unsigned int smzz;
unsigned long int sqh_;
unsigned long int _sqh_;
unsigned long int _sqh;
unsigned long int FAT_;
unsigned long int _FAT;
unsigned int py1;
unsigned long int cuhao_js1;
unsigned long int CLX;

unsigned char *_buf;
unsigned long int js1;
unsigned char buf_bz;



    sqh_ = FAT32_SETUP_culian_sqh_[device];           //读出首簇号所在扇区号
    _sqh_ = FAT32_SETUP_culian__sqh_[device];         //读出待指簇号所在扇区号
    _sqh = FAT32_SETUP_culian__sqh[device];           //读出当前扫描的扇区号
    FAT_ = FAT32_SETUP_culian_FAT_[device];           //读出FAT表首扇区号
    _FAT = FAT32_SETUP_culian__FAT[device];           //读出FAT表尾扇区号+1
    py1 = FAT32_SETUP_culian_py1[device];             //读出待指簇号所在扇区内的偏移
    cuhao_js1 = FAT32_SETUP_culian_cuhao_js1[device]; //读出已创建簇号数量
    CLX = FAT32_SETUP_culian_CLX[device];             //读出须创建簇数量

    if(DEVICE_RD_512B(device,FAT32_SETUP_culian__sqh[device],buf) == 0) return 0; //读出需要扫描的扇区到缓冲区



    buf_bz = 0;
    smzz = 0;

    while(1)
    {



        if(smzz == 512 || _sqh + 1 == _FAT && smzz == FAT32__cuhao_LBAPY[device] + 4 || cuhao_js1 == CLX)
        {

            if(buf_bz == 1) //当前扫描缓冲区有空白簇,进入
            {
                _buf = buf + py1;    //待指簇号填上簇结束标志0x0fffffff
                *_buf = 0xff;
                ++_buf;
                *_buf = 0xff;
                ++_buf;
                *_buf = 0xff;
                ++_buf;
                *_buf = 0x0f;

               if(DEVICE_WR_512B(device,_sqh,buf) == 0) return 0; //缓冲区存盘

               if(FAT32_SETUP_DELETE_fatx == 3)
               {
                   if(DEVICE_WR_512B(device,_sqh - FAT32_FATDX[device],buf) == 0) return 0; //缓冲区存盘(写FAT1)
               }

            }

            if(cuhao_js1 == CLX) return 2;


            ++_sqh; //指向下个扫描扇区号
            if(_sqh == _FAT) _sqh = FAT_; //如果下个扫描扇区号超出FAT表范围,回归FAT表首部
            if(_sqh == sqh_) return 3;    //FAT表转了一圈,没找到空白簇,返回错误值

            FAT32_SETUP_culian__sqh_[device] = _sqh_;            //回存关键数据
            FAT32_SETUP_culian__sqh[device] = _sqh;
            FAT32_SETUP_culian_py1[device] = py1;
            FAT32_SETUP_culian_cuhao_js1[device] = cuhao_js1;

            return 1;

        }
        else if(buf[smzz] == 0x00 && buf[smzz+1] == 0x00 && buf[smzz+2] == 0x00 && buf[smzz+3] == 0x00) //找到空白簇
        {

            buf_bz = 1; //有空白簇

            js1 = ((_sqh - FAT_) << 7) + (smzz >> 2); //算出空白簇的簇号


            if(_sqh_ == _sqh)  //待指簇号所在扇区和当前空白簇所在扇区一样
            {

                _buf = buf + py1;    //修改待指簇号指向这个空白簇
                *_buf = js1;
                ++_buf;
                *_buf = js1 >> 8;
                ++_buf;
                *_buf = js1 >> 16;
                ++_buf;
                *_buf = js1 >> 24;

            }
            else
            {

                if(DEVICE_RD_512B(device,_sqh_,buf_) == 0) return 0; //读出待指簇号所在扇区到备用缓冲区

                _buf = buf_ + py1;    //修改待指簇号指向这个空白簇
                *_buf = js1;
                ++_buf;
                *_buf = js1 >> 8;
                ++_buf;
                *_buf = js1 >> 16;
                ++_buf;
                *_buf = js1 >> 24;

                if(DEVICE_WR_512B(device,_sqh_,buf_) == 0) return 0; //备用缓冲区存盘

                if(FAT32_SETUP_DELETE_fatx == 3)
                {
                    if(DEVICE_WR_512B(device,_sqh_ - FAT32_FATDX[device],buf_) == 0) return 0; //备用缓冲区存盘(写FAT1)
                }

                _sqh_ = _sqh; //待指簇号所在扇区指向当前空白簇所在扇区

            }

            py1 = smzz; //记录待指簇号所在扇区内的偏移指向这个空白簇

            smzz += 4; //指向下个簇号

            ++cuhao_js1; //已创建簇号数量+1

        }
        else smzz += 4; //指向下个簇号


    }



}



/*

unsigned char FAT32_DELETE_culian(unsigned char device,unsigned long int cuhao_,unsigned char cuhao__dc,unsigned char fatx) //给首簇号,删除簇链, device选择SPI设备, 0为0号内存卡,1为1号内存卡,cuhao_是首簇号,cuhao__dc为0首簇号填0x00000000,为其他值首簇号填0x0fffffff,fatx选择FAT表,0为FAT1,其他值为FAT2 返回值不为0表示操作成功
{

unsigned char buf[512]; //缓冲区
unsigned long int FAT_; //记录FAT表首扇区号
unsigned long int _cuhao; //记录下一个要删除的簇号
unsigned char *_buf;



    if(fatx == 0) FAT_ = FAT32_FAT1addr[device];
    else FAT_ = FAT32_FAT2addr[device];



    if(DEVICE_RD_512B(device,(cuhao_ >> 7) + FAT_,buf) == 0) return 0; //读出首簇号所在扇区到缓冲区


    _buf = buf + ((cuhao_ & 0x0000007f) << 2) + 3; //计算首簇号指向下个簇号的最高8位缓冲区地址

    _cuhao = *_buf;       //记录首簇号指向的下个簇号
    _cuhao <<= 8;--_buf;
    _cuhao |= *_buf;
    _cuhao <<= 8;--_buf;
    _cuhao |= *_buf;
    _cuhao <<= 8;--_buf;
    _cuhao |= *_buf;

    if(cuhao__dc != 0) //首簇号填0x0fffffff
    {
       *_buf = 0xff; ++_buf;
       *_buf = 0xff; ++_buf;
       *_buf = 0xff; ++_buf;
       *_buf = 0x0f;
    }
    else //首簇号填0x00000000
    {
       *_buf = 0x00; ++_buf;
       *_buf = 0x00; ++_buf;
       *_buf = 0x00; ++_buf;
       *_buf = 0x00;
    }


   while(_cuhao != 0x0fffffff && _cuhao != 0x00000000)
   {

      if((_cuhao & 0xffffff80) == (cuhao_ & 0xffffff80)) //簇号指向的下个簇号在同一个扇区?
      {

         cuhao_ = _cuhao;

         _buf = buf + ((cuhao_ & 0x0000007f) << 2) + 3;   //读出簇号指向的下一个簇号

         _cuhao = *_buf;
         _cuhao <<= 8;--_buf;
         _cuhao |= *_buf;
         _cuhao <<= 8;--_buf;
         _cuhao |= *_buf;
         _cuhao <<= 8;--_buf;
         _cuhao |= *_buf;

         *_buf = 0x00; ++_buf;     //簇号清0
         *_buf = 0x00; ++_buf;
         *_buf = 0x00; ++_buf;
         *_buf = 0x00;

      }
      else
      {

         if( DEVICE_WR_512B(device,(cuhao_ >> 7) + FAT_,buf) == 0 ) return 0; //缓冲区存盘

         cuhao_ = _cuhao;

         if( DEVICE_RD_512B(device,(cuhao_ >> 7) + FAT_,buf) == 0 ) return 0; //读出簇号所在扇区到缓冲区

         _buf = buf + ((cuhao_ & 0x0000007f) << 2) + 3;   //读出簇号指向的下一个簇号

         _cuhao = *_buf;
         _cuhao <<= 8;--_buf;
         _cuhao |= *_buf;
         _cuhao <<= 8;--_buf;
         _cuhao |= *_buf;
         _cuhao <<= 8;--_buf;
         _cuhao |= *_buf;

         *_buf = 0x00; ++_buf;     //簇号清0
         *_buf = 0x00; ++_buf;
         *_buf = 0x00; ++_buf;
         *_buf = 0x00;

      }


   }


   if( DEVICE_WR_512B(device,(cuhao_ >> 7) + FAT_,buf) == 0 ) return 0; //缓冲区存盘

   return 1;


}
*/



unsigned char FAT32_DELETE_culian(unsigned char device,unsigned long int cuhao_,unsigned char cuhao__dc,unsigned char fatx) //给首簇号,删除簇链, device选择SPI设备, 0为0号内存卡,1为1号内存卡,cuhao_是首簇号,cuhao__dc为0首簇号填0x00000000,为其他值首簇号填0x0fffffff,fatx选择FAT表,0为FAT1,其他值为FAT2 返回值不为0表示操作成功
{

unsigned char buf[512]; //缓冲区
unsigned long int FAT_; //记录FAT表首扇区号
unsigned long int _cuhao; //记录下一个要删除的簇号
unsigned char *_buf;
unsigned long int sqh_;


    if(fatx == 0)
    {
       FAT_ = FAT32_FAT1addr[device];
       FAT32_DELETE_culian_FAT_[device] = FAT_;
    }
    else
    {
       FAT_ = FAT32_FAT2addr[device];
       FAT32_DELETE_culian_FAT_[device] = FAT_;
    }

    sqh_ = (cuhao_ >> 7) + FAT_; //计算首簇号所在扇区号

    if(DEVICE_RD_512B(device,sqh_,buf) == 0) return 0; //读出首簇号所在扇区到缓冲区


    _buf = buf + ((cuhao_ & 0x0000007f) << 2) + 3; //计算首簇号指向下个簇号的最高8位缓冲区地址

    _cuhao = *_buf;       //记录首簇号指向的下个簇号
    _cuhao <<= 8;--_buf;
    _cuhao |= *_buf;
    _cuhao <<= 8;--_buf;
    _cuhao |= *_buf;
    _cuhao <<= 8;--_buf;
    _cuhao |= *_buf;

    if(cuhao__dc != 0) //首簇号填0x0fffffff
    {
       *_buf = 0xff; ++_buf;
       *_buf = 0xff; ++_buf;
       *_buf = 0xff; ++_buf;
       *_buf = 0x0f;
    }
    else //首簇号填0x00000000
    {
       *_buf = 0x00; ++_buf;
       *_buf = 0x00; ++_buf;
       *_buf = 0x00; ++_buf;
       *_buf = 0x00;
    }


    if(DEVICE_WR_512B(device,sqh_,buf) == 0) return 0; //缓冲区存盘

    if(fatx == 3)
    {
        if(DEVICE_WR_512B(device,sqh_ - FAT32_FATDX[device],buf) == 0) return 0; //缓冲区存盘(写FAT1)
    }

    FAT32_SETUP_DELETE_fatx = fatx; //记录fat表选择
    FAT32_DELETE_culian__cuhao[device] = _cuhao; //记录簇号指向的下个簇号

    return 1;

}



unsigned char FAT32_DELETE_culian_RUN(unsigned char device) //给首簇号,删除簇链, device选择SPI设备, 0为0号内存卡,1为1号内存卡,cuhao_是首簇号,cuhao__dc为0首簇号填0x00000000,为其他值首簇号填0x0fffffff,fatx选择FAT表,0为FAT1,其他值为FAT2 返回值不为0表示操作成功
{

unsigned char buf[512]; //缓冲区
unsigned long int FAT_; //记录FAT表首扇区号
unsigned long int _cuhao; //记录下一个要删除的簇号
unsigned char *_buf;
unsigned long int sqh_;
unsigned long int cuhao_;


    FAT_ = FAT32_DELETE_culian_FAT_[device];      //读出FAT表首扇区号
    _cuhao = FAT32_DELETE_culian__cuhao[device];  //读出下一个要删除的簇号

    if(_cuhao == 0x0fffffff || _cuhao == 0x00000000) goto out;
    cuhao_ = _cuhao;


    sqh_ = (_cuhao >> 7) + FAT_; //计算簇号所在扇区号

    if(DEVICE_RD_512B(device,sqh_,buf) == 0) return 0; //读出簇号所在扇区到缓冲区


    while(1)
    {


        if(_cuhao == 0x0fffffff || _cuhao == 0x00000000)
        {

            if(DEVICE_WR_512B(device,(cuhao_ >> 7) + FAT_,buf) == 0) return 0; //缓冲区存盘

            if(FAT32_SETUP_DELETE_fatx == 3)
            {
                if(DEVICE_WR_512B(device,(cuhao_ >> 7) + FAT_ - FAT32_FATDX[device],buf) == 0) return 0; //缓冲区存盘(写FAT1)
            }
     out:
            return 2;

        }
        else if((_cuhao & 0xffffff80) == (cuhao_ & 0xffffff80)) //簇号指向的下个簇号在同一扇区
        {

            cuhao_ = _cuhao;

            _buf = buf + ((cuhao_ & 0x0000007f) << 2) + 3;   //读出簇号指向的下一个簇号

            _cuhao = *_buf;
            _cuhao <<= 8;--_buf;
            _cuhao |= *_buf;
            _cuhao <<= 8;--_buf;
            _cuhao |= *_buf;
            _cuhao <<= 8;--_buf;
            _cuhao |= *_buf;

            *_buf = 0x00; ++_buf;     //簇号清0
            *_buf = 0x00; ++_buf;
            *_buf = 0x00; ++_buf;
            *_buf = 0x00;

        }
        else //簇号指向的下个簇号不在同一扇区
        {

            if(DEVICE_WR_512B(device,(cuhao_ >> 7) + FAT_,buf) == 0) return 0; //缓冲区存盘

            if(FAT32_SETUP_DELETE_fatx == 3)
            {
                if(DEVICE_WR_512B(device,(cuhao_ >> 7) + FAT_ - FAT32_FATDX[device],buf) == 0) return 0; //缓冲区存盘(写FAT1)
            }

            FAT32_DELETE_culian__cuhao[device] = _cuhao; //回存簇号指向的下个簇号

            return 1;

        }


    }



}


unsigned char FAT32_BJ1(unsigned char device,unsigned char culianDX,unsigned long int *culian,unsigned char *culianX,unsigned long int *sqh_,unsigned long int *_sqh)
{

unsigned long int _cuhao;
unsigned long int _sqh_;
unsigned char _culianX;

     _culianX = *culianX;
     _cuhao = culian[_culianX];

     if(_cuhao == 0x0fffffff || _cuhao == 0x00000000) return 2; //为簇结束标志或断簇,进入处理

     _sqh_ = FAT32_cuhao_shanquhao(device,_cuhao); //簇号转首扇区号
     *sqh_ = _sqh_;
     *_sqh = _sqh_ + FAT32_cudx[device]; //记录簇的尾扇区的下一扇区号

     if(_culianX == culianDX - 1) //尾簇? 进入更新簇链
     {
         if(FAT32_cuhao_culian(device,_cuhao,culianDX,culian) == 0) return 0; //读出尾簇指向的下面culianDX个簇放到簇链缓冲区,如果错误,进入处理
         *culianX = 0; //簇指针指向首簇
     }
     else
     {
         ++*culianX; //指向下一个簇号
     }

     return 1;

}


unsigned int FAT32_wjcx_2(unsigned char device,unsigned long int mulu_cuhao,unsigned int qs,unsigned int js,unsigned char *return_data) //FAT32文件查询2,device选择设备,mulu_cuhao为目录的首簇号,qs为首文件号,js为结束文件号,return_data为返回文件信息数据,按顺序以32个字节为一段,返回值不为0表示操作成功; 需要取得总文件数量时,qs、js、return_data置0,调用此函数返回文件总数量; 需要确认文件数量时,qs、return_data置0,js置文件数量,调用此函数返回值为小于等于js
{

unsigned char buf[512]; //缓冲区
unsigned long int culian[128]; //簇链
unsigned char culian_x; //簇指针,用来指簇链里面的簇号
unsigned long int sqh_; //簇的首扇区号
unsigned long int _sqh; //簇的尾扇区号+1
unsigned int wjm_smzz; //文件名段扫描指针
unsigned int wjsl_x = 0; //文件数量计数

unsigned int js1; //计数1


            if(DEVICE_RD_512B(device,sqh_ = FAT32_cuhao_shanquhao(device,mulu_cuhao),buf) == 0) return 0; //读出需要扫描目录的首扇区到第0缓冲区
            _sqh = sqh_ + FAT32_cudx[device]; //记录目录首簇的尾扇区的下一扇区号
            ++sqh_; //指向下一个扇区

            if(FAT32_cuhao_culian(device,mulu_cuhao,128,culian) == 0) return 0; //读出目录首簇指向的下面128个簇放到簇链缓冲区
            culian_x = 0; //簇指针指向读出的首个簇


            wjm_smzz = 0;

               do
               {

                     if(buf[wjm_smzz] == 0xe5 || buf[wjm_smzz] == 0x2e)
                     {
                        wjm_smzz += 32; //指向下一段
                     }
                     else if(buf[wjm_smzz] == 0x00)
                     {
                        if(qs == 0)
                        {
                           return wjsl_x; //返回文件数量
                        }
                        else
                        {
                           return 0; //返回0
                        }
                     }
                     else if((buf[wjm_smzz+0x0b] & 0xf0) != 0x00) //短文件名
                     {
                        ++wjsl_x; //文件数量计数+1

                        if(qs != 0 && wjsl_x >= qs)
                        {
                           js1 = wjm_smzz + 32;
                           while(wjm_smzz != js1) *return_data = buf[wjm_smzz],++wjm_smzz,++return_data;
                        }

                        if(wjsl_x == js) return wjsl_x;

                     }
                     else
                     {
                        wjm_smzz += 32; //指向下一段
                     }



                     if(wjm_smzz == 512)
                     {
                         wjm_smzz = 0;

                         if(sqh_ == _sqh) //一个簇的扇区读完,进入换簇
                         {

                            if(culian[culian_x] == 0x0fffffff)
                            {
                               if(qs == 0)
                               {
                                  return wjsl_x; //为簇结束标志时返回文件数量
                               }
                               else
                               {
                                  return 0;
                               }
                            }

                            sqh_ = FAT32_cuhao_shanquhao(device,culian[culian_x]); //簇号转首扇区号
                            _sqh = sqh_ + FAT32_cudx[device]; //记录簇的尾扇区的下一扇区号
             

                            if(culian_x == 127) //尾簇? 进入更新簇链
                            {
                               if(FAT32_cuhao_culian(device,culian[127],128,culian) == 0) return 0; //读出尾簇指向的下面128个簇放到簇链缓冲区
                               culian_x = 0; //簇指针指向读出的首个簇
                            }
                            else
                            {
                               ++culian_x; //指向下一个簇号
                            }

                         }

          
                         if(DEVICE_RD_512B(device,sqh_ ,buf) == 0) return 0; //读出一个扇区到缓冲区
                         ++sqh_; //指向下一个扇区

                     }


               }while(1);


}


unsigned int FAT32_ML_WJCX1(unsigned char device,unsigned long int mulu_cuhao,unsigned int qs,unsigned int js,unsigned char *return_data) //FAT32文件查询2,device选择设备,mulu_cuhao为目录的首簇号,qs为首文件号,js为结束文件号,return_data为返回文件信息数据,按顺序以32个字节为一段,返回值不为0表示操作成功; 需要取得总文件数量时,qs、js、return_data置0,调用此函数返回文件总数量; 需要确认文件数量时,qs、return_data置0,js置文件数量,调用此函数返回值为小于等于js
{

unsigned char buf[512]; //缓冲区
unsigned long int culian[128]; //簇链
unsigned char culianX; //簇指针,用来指簇链里面的簇号
unsigned long int sqh_; //簇的首扇区号
unsigned long int _sqh; //簇的尾扇区号+1
unsigned int wjm_smzz; //文件名段扫描指针
unsigned int wjsl_x = 0; //文件数量计数

unsigned int js1; //计数1
unsigned char js2; //计数2

   culian[127] = mulu_cuhao;
   culianX = 127;
   sqh_ = _sqh;

   *return_data = 0;

   do
   {


        if(sqh_ == _sqh) //一个簇的扇区读完,进入换簇
        {

            js2 = FAT32_BJ1(device,128,culian,&culianX,&sqh_,&_sqh);

            if(js2 == 0) //读存储器错误
            {
                return 0;
            }
            else if(js2 == 2) //簇结束标志
            {

                     if(qs == 0)
                     {
                         return wjsl_x; //为簇结束标志时返回文件数量
                     }
                     else
                     {
                         return 0;
                     }

            }

        }

        if(DEVICE_RD_512B(device,sqh_,buf) == 0) return 0; //读出到缓冲区
        ++sqh_; //指向下一个扇区


           wjm_smzz = 0;

           do
           {

                     if(wjm_smzz == 512)
                     {
                        break; //跳出循环
                     }
                     else if(buf[wjm_smzz] == 0xe5 || buf[wjm_smzz] == 0x2e)
                     {
                        wjm_smzz += 32; //指向下一段
                     }
                     else if(buf[wjm_smzz] == 0x00)
                     {
                        if(qs == 0)
                        {
                           return wjsl_x; //返回文件数量
                        }
                        else
                        {
                           return 0; //返回0
                        }
                     }
                     else if((buf[wjm_smzz+0x0b] & 0xf0) != 0x00) //短文件名
                     {
                        ++wjsl_x; //文件数量计数+1

                        if(qs != 0 && wjsl_x >= qs)
                        {
                           js1 = wjm_smzz + 32;
                           while(wjm_smzz != js1) *return_data = buf[wjm_smzz],++wjm_smzz,++return_data;
                        }
                        else wjm_smzz+=32; //指向下一段

                        *return_data = 0;
                        if(wjsl_x == js) return wjsl_x;

                     }
                     else
                     {
                        wjm_smzz += 32; //指向下一段
                     }


           }while(1);



   }while(1);



}




unsigned char FAT32_DELETE_E5(unsigned char device,unsigned long int mulu_cuhao)
{


   FAT32_DELETE_E5_32B_sqh_ = FAT32_cuhao_shanquhao(device,mulu_cuhao); //簇号转首扇区号,扫描首扇区号
   FAT32_DELETE_E5_32B__sqh = FAT32_DELETE_E5_32B_sqh_ + FAT32_cudx[device]; //记录簇的尾扇区的下一扇区号

   if(FAT32_cuhao_culian(device,mulu_cuhao,FAT32_DELETE_E5_32B_CLX,FAT32_DELETE_E5_32B_culian) == 0) return 0; //读出簇链,如果错误,进入处理
   FAT32_DELETE_E5_32B_culianX = 0;

   FAT32_DELETE_E5_32B_smzz = 0;
   FAT32_DELETE_E5_qhc = 0;
   FAT32_DELETE_E5_WJFDX = 0;

   return 1;


}





unsigned char FAT32_DELETE_E5_RUN(unsigned char device)
{

unsigned char buf[512];
unsigned char _buf[512];
unsigned char K;
unsigned char X;


unsigned char js1;
unsigned int js2;
unsigned int js3;


   if(FAT32_DELETE_E5_qhc == 0)
   {
       if(DEVICE_RD_512B(device,FAT32_DELETE_E5_32B_sqh_,_buf) == 0) return 0; //读出到缓冲区
   }
   else
   {
       if(DEVICE_RD_512B(device,FAT32_DELETE_E5_sqh_,_buf) == 0) return 0; //读出到缓冲区
       if(DEVICE_RD_512B(device,FAT32_DELETE_E5_32B_sqh_,buf) == 0) return 0; //读出到缓冲区
   }



   K = 0;
   X = 0;


   while(1)
   {

        if(FAT32_DELETE_E5_qhc == 0)
        {

             if(FAT32_DELETE_E5_32B_smzz == 512)
             {

                  ++FAT32_DELETE_E5_32B_sqh_;

                  if(FAT32_DELETE_E5_32B_sqh_ == FAT32_DELETE_E5_32B__sqh) //一个簇的扇区读完,进入换簇
                  {

                      if(( js1 = FAT32_BJ1(device,FAT32_DELETE_E5_32B_CLX,FAT32_DELETE_E5_32B_culian,&FAT32_DELETE_E5_32B_culianX,&FAT32_DELETE_E5_32B_sqh_,&FAT32_DELETE_E5_32B__sqh) ) != 1) return js1;

                  }

                  FAT32_DELETE_E5_32B_smzz = 0;

                  return 1;

             }
             else if(_buf[FAT32_DELETE_E5_32B_smzz] == 0xe5)
             {

                 FAT32_DELETE_E5_culian[FAT32_DELETE_E5_CLX - 1] = FAT32_DELETE_E5_32B_culian[FAT32_DELETE_E5_32B_culianX];
                 FAT32_DELETE_E5_culianX = FAT32_DELETE_E5_CLX - 1;
                 FAT32_DELETE_E5_sqh_ = FAT32_DELETE_E5_32B_sqh_;
                 FAT32_DELETE_E5__sqh = FAT32_DELETE_E5_32B__sqh;
                 FAT32_DELETE_E5_smzz = FAT32_DELETE_E5_32B_smzz;


                 FAT32_DELETE_E5_qhc = 1; //切换
                 K = 1;

             }
             else if(_buf[FAT32_DELETE_E5_32B_smzz] == 0x00)
             {
                 return 2;
             }
             else
             {
                 FAT32_DELETE_E5_32B_smzz += 32;
                 FAT32_DELETE_E5_WJFDX += 32;
             }

        }
        else
        {

             if(FAT32_DELETE_E5_smzz == 512)
             {

                 if(DEVICE_WR_512B(device,FAT32_DELETE_E5_sqh_,_buf) == 0) return 0; //缓冲区存盘

                 if(X == 1)
                 {
                     if(DEVICE_WR_512B(device,FAT32_DELETE_E5_32B_sqh_,buf) == 0) return 0; //缓冲区存盘
                 }

                 ++FAT32_DELETE_E5_sqh_;

                 if(FAT32_DELETE_E5_sqh_ == FAT32_DELETE_E5__sqh) //一个簇的扇区读完,进入换簇
                 {

                     if(( js1 = FAT32_BJ1(device,FAT32_DELETE_E5_CLX,FAT32_DELETE_E5_culian,&FAT32_DELETE_E5_culianX,&FAT32_DELETE_E5_sqh_,&FAT32_DELETE_E5__sqh) ) != 1) return js1;

                 }

                 FAT32_DELETE_E5_smzz = 0;

                 return 1;

             }
             else if(_buf[FAT32_DELETE_E5_smzz] == 0xe5)
             {

                 js2 = FAT32_DELETE_E5_smzz;
                 FAT32_DELETE_E5_smzz += 32;
                 while(js2 != FAT32_DELETE_E5_smzz) _buf[js2] = 0x00,++js2; //清0此32B段

             }
             else if(_buf[FAT32_DELETE_E5_smzz] == 0x00)
             {

                 if(DEVICE_WR_512B(device,FAT32_DELETE_E5_sqh_,_buf) == 0) return 0; //缓冲区存盘

                 if(X == 1)
                 {
                     if(DEVICE_WR_512B(device,FAT32_DELETE_E5_32B_sqh_,buf) == 0) return 0; //缓冲区存盘
                 }

                 return 2;

             }
             else
             {

                 js2 = FAT32_DELETE_E5_smzz;
                 FAT32_DELETE_E5_smzz += 32;
                 js3 = FAT32_DELETE_E5_32B_smzz;
                 FAT32_DELETE_E5_32B_smzz += 32;
                 FAT32_DELETE_E5_WJFDX += 32;

                 while(js2 != FAT32_DELETE_E5_smzz)  //拷贝此32B段
                 {
                    if(K == 0) buf[js3] = _buf[js2],X = 1;
                    else _buf[js3] = _buf[js2];
                    ++js2,++js3;
                 }

                 js2 -= 32;
                 while(js2 != FAT32_DELETE_E5_smzz) _buf[js2] = 0x00,++js2; //清0此32B段


                 if(FAT32_DELETE_E5_32B_smzz == 512)
                 {

                     if(DEVICE_WR_512B(device,FAT32_DELETE_E5_32B_sqh_,buf) == 0) return 0; //缓冲区存盘

                     ++FAT32_DELETE_E5_32B_sqh_;

                     if(FAT32_DELETE_E5_32B_sqh_ == FAT32_DELETE_E5_32B__sqh) //一个簇的扇区读完,进入换簇
                     {

                         if(FAT32_BJ1(device,FAT32_DELETE_E5_32B_CLX,FAT32_DELETE_E5_32B_culian,&FAT32_DELETE_E5_32B_culianX,&FAT32_DELETE_E5_32B_sqh_,&FAT32_DELETE_E5_32B__sqh) != 1) return 0;

                     }


                     if(FAT32_DELETE_E5_32B_sqh_ == FAT32_DELETE_E5_sqh_)
                     {
                         K = 1;
                     }
                     else if(FAT32_DELETE_E5_smzz != 512)
                     {
                         if(DEVICE_RD_512B(device,FAT32_DELETE_E5_32B_sqh_,buf) == 0) return 0; //读出到缓冲区
                     }


                     FAT32_DELETE_E5_32B_smzz = 0;

                     X = 0;

                 }


             }


        }


   }


}


void FAT32_VOID_cuhao(unsigned char device,unsigned char fatx) //扫描空白簇初始化
{
    if(fatx == 0)
    {
        FAT32_VOID_cuhao_FAT_ = FAT32_FAT1addr[device];
        FAT32_VOID_cuhao__FAT = FAT32_FAT2addr[device];
    }
    else
    {
        FAT32_VOID_cuhao_FAT_ = FAT32_FAT2addr[device];
        FAT32_VOID_cuhao__FAT = FAT32_DATAaddr[device];
    }

    FAT32_VOID_cuhao_sqh = FAT32_VOID_cuhao_FAT_;
}


unsigned char FAT32_VOID_cuhao_RUN(unsigned char device) //运行扫描空白簇,返回值1继续,2找到空白簇,0设备错误,3没有找到
{

unsigned char buf[512];
unsigned int smzz;



    if(DEVICE_RD_512B(device,FAT32_VOID_cuhao_sqh,buf) == 0) return 0; //读出到缓冲区

    smzz = 0;


    while(1)
    {


          if(FAT32_VOID_cuhao_sqh == FAT32_VOID_cuhao__FAT - 1 && smzz == FAT32__cuhao_LBAPY[device] + 4) //整个FAT表扫完,没找到空白簇
          {
              return 3;
          }
          else if(smzz == 512) //扫完缓冲区
          {
              ++FAT32_VOID_cuhao_sqh; //指向下一扇区
              return 1;
          }
          else if(buf[smzz] == 0x00 && buf[smzz+1] == 0x00 && buf[smzz+2] == 0x00 && buf[smzz+3] == 0x00) //找到空白簇
          {
              FAT32_VOID_cuhao_cuhao = ((FAT32_VOID_cuhao_sqh - FAT32_VOID_cuhao_FAT_) << 7) + (smzz >> 2);
              return 2;
          }
          else
          {
              smzz += 4;
          }


    }

}




void FAT32_UP_culian(unsigned long int cuhao_,unsigned long int DATADX,unsigned char LBA_VOID_K) //更新簇链长度初始化,cuhao_为首簇号,DATADX为数据大小,LAB_VOID_K选择是否清空新扇区,如果为1将清0新簇映射的扇区,为0不清0
{

   FAT32_UP_culian_cuhao_ = cuhao_;
   FAT32_UP_culian_DATADX = DATADX;
   FAT32_UP_culian_LBA_VOID_K = LBA_VOID_K;
   FAT32_UP_culian_XZ = 0;
   FAT32_UP_culian_DATADX_ = 0;

}



unsigned char FAT32_UP_culian_RUN(unsigned char device) //运行更新簇链长度,device选择设备,返回0错误,1继续,2完成,3存储设备空间不足
{

unsigned long int buf[128];
unsigned char void_buf[512];
unsigned char smzz;
unsigned long int cudx_B;

unsigned long int js1;
unsigned char js2;
unsigned int js3;
unsigned long int js4;




    if(FAT32_UP_culian_XZ == 0) //扫描簇链
    {

        if(FAT32_cuhao_culian(device,FAT32_UP_culian_cuhao_,128,buf) == 0) return 0;
        FAT32_UP_culian__cuhao = FAT32_UP_culian_cuhao_;


        cudx_B = FAT32_cudx_B[device]; //读出簇大小
        smzz = 0;

        while(1)
        {

            if(smzz == 128)
            {
                FAT32_UP_culian_cuhao_ = FAT32_UP_culian__cuhao; //尾簇作为首簇
                break;
            }
            else
            {

                FAT32_UP_culian_DATADX_ += cudx_B; //已扫数据大小加上一个簇的数据大小

                if(FAT32_UP_culian_DATADX_ >= FAT32_UP_culian_DATADX)
                {

                    js2 = 255;
                    if(FAT32_UP_culian_DATADX == 0) js2 = ~js2;

                    FAT32_UP_culian_XZ = 1; //切换为执行删除簇链
                    FAT32_UP_culian_DELETE_culian_K = 0; //标志为正常删除簇链
                    return FAT32_DELETE_culian(device,FAT32_UP_culian__cuhao,js2,3); //初始化删除簇链

                }

                if((js1 = buf[smzz]) == 0x0fffffff || js1 == 0x00000000) //簇链映射的扇区总数据小于目标数据并且是结束簇或空白簇
                {

                    FAT32_UP_culian__cuhao_bz = js1; //记录创建簇链的首簇号标志

                    js1 = FAT32_UP_culian_DATADX - FAT32_UP_culian_DATADX_;    //算出需要创建的簇链长度
                    js4 = js1 / cudx_B;
                    if(js1 % cudx_B != 0) ++js4;


                    FAT32_UP_culian_XZ = 2; //切换为执行创建簇链

                    return FAT32_SETUP_culian(device,FAT32_UP_culian__cuhao,js4,3); //初始化创建簇链

                }

                FAT32_UP_culian__cuhao = js1;

                ++smzz;

            }

        }

    }
    else if(FAT32_UP_culian_XZ == 1) //删除簇链
    {

        js2 = FAT32_DELETE_culian_RUN(device); //运行删除簇链

        if(FAT32_UP_culian_DELETE_culian_K == 1 && js2 == 2) js2 = 3;

        return js2;


    }
    else if(FAT32_UP_culian_XZ == 2) //创建簇链
    {

        if((js2 = FAT32_SETUP_culian_RUN(device)) < 2) return js2; //运行创建簇链

        if(js2 == 2) //创建簇链完成
        {

            if(FAT32_UP_culian_LBA_VOID_K == 0) //不清空新扇区
            {
                return 2; //执行完成
            }
            else //清空新扇区
            {

                if(FAT32_UP_culian__cuhao_bz == 0x00) //创建簇链的首簇号标志为0x00000000,从首簇开始清空
                {
                    FAT32_UP_culian_LBA_VOID_culian[FAT32_UP_culian_LBA_VOID_CLX - 1] = FAT32_UP_culian__cuhao;
                    FAT32_UP_culian_LBA_VOID_culiaX = FAT32_UP_culian_LBA_VOID_CLX - 1; //指向尾簇
                }
                else //创建簇链的首簇号标志为0x0fffffff,从下一簇开始清空
                {
                    if(FAT32_cuhao_culian(device,FAT32_UP_culian__cuhao,FAT32_UP_culian_LBA_VOID_CLX,FAT32_UP_culian_LBA_VOID_culian) == 0) return 0;
                    FAT32_UP_culian_LBA_VOID_culiaX = 0; //指向首簇
                }

                FAT32_UP_culian_LBA_VOID_sqh_ = 0; //sqh_和_sqh同值
                FAT32_UP_culian_LBA_VOID__sqh = 0;

                FAT32_UP_culian_XZ = 255; //切换为清空新扇区
            }

        }
        else //存储空间不够,删除簇链
        {
            FAT32_UP_culian_XZ = 1; //切换为执行删除簇链
            FAT32_UP_culian_DELETE_culian_K = 1; //标志为存储空间不够,删除簇链
            if(FAT32_DELETE_culian(device,FAT32_UP_culian__cuhao,FAT32_UP_culian__cuhao_bz,3) == 0) return 0; //初始化删除簇链
        }

    }
    else //清空新扇区
    {

        if(FAT32_UP_culian_LBA_VOID_sqh_ == FAT32_UP_culian_LBA_VOID__sqh) //一个簇的扇区读完,进入换簇
        {
            if((js2 = FAT32_BJ1(device,FAT32_UP_culian_LBA_VOID_CLX,FAT32_UP_culian_LBA_VOID_culian,&FAT32_UP_culian_LBA_VOID_culiaX,&FAT32_UP_culian_LBA_VOID_sqh_,&FAT32_UP_culian_LBA_VOID__sqh)) != 1) return js2;
        }

        js3 = 0;
        while(js3 != 512) void_buf[js3] = 0x00,++js3;   //清0空缓冲区

        if(DEVICE_WR_512B(device,FAT32_UP_culian_LBA_VOID_sqh_,void_buf) == 0) return 0; //缓冲区存盘
        ++FAT32_UP_culian_LBA_VOID_sqh_;

    }


    return 1;


}



void FAT32_ML_SETUP_WJF(unsigned long int mulu_cuhao,unsigned char *WJDATA_32B,unsigned int *WJ_CWJM,unsigned char UPX) //目录创建文件符初始化, mulu_cuhao是目录首簇号, WJDATA_32B是32个字节的文件数据, WJ_CWJM是文件的长文件名,以0作为结束符,UPX位2为1更新文件创建时间和日期,位1为1更新文件最后访问日期,位0为1更新文件最近修改时间和日期
{

unsigned int js1;
unsigned int js2;
unsigned int js3;
unsigned int js4;
unsigned int js5;
unsigned char js6;
unsigned int js7;
unsigned char js8;
unsigned char js9;

unsigned int js10;



   js1 = 0;
   while(js1 != 403 && WJ_CWJM[js1] != 0) ++js1; //扫描长文件名长度

   js3 = 0;

   if(js1 != 0) //长文件名不为0进入
   {

       js6 = 0;
       js8 = 0;
       while(js6 != 11)
       {
           js8 = ((js8 << 7) | (js8 >> 1)) + WJDATA_32B[js6];  //计算短文件名效验和
           ++js6;
       }


       js2 = js1 / 13;
       if(js1 % 13 != 0) ++js2; //算出文件名占多少个32B


       js2 <<= 5; //乘32,得出长文件名的文件符尾地址+1
       js3 = js2; //保存短文件名的32B文件符首地址


       js5 = 0;
       js6 = 0;
       js9 = 0;

            do
            {
                 js2 -= 32; //退一个32B
                 ++js6; //目录项计数+1

                 FAT32_ML_SETUP_WJF_WJF[js2] = js6; //低5位顺序号数值,位6为1表示长文件最后一个目录项

                 js4 = 1;

                 do
                 {

                     if(js5 != js1)
                     {
                         js7 = WJ_CWJM[js5];
                         ++js5;
                     }
                     else if(js9 == 0) js7 = 0x0000,js9 = 1;
                     else js7 = 0xffff;

                     FAT32_ML_SETUP_WJF_WJF[js2 + js4] = js7;  //长文件名unicode码
                     ++js4;
                     FAT32_ML_SETUP_WJF_WJF[js2 + js4] = js7 >> 8;
                     ++js4;

                     if(js4 == 0x000b)
                     {
                         FAT32_ML_SETUP_WJF_WJF[js2 + js4] = 0x0f; //长文件名目录项标志,取值0FH
                         ++js4;
                         FAT32_ML_SETUP_WJF_WJF[js2 + js4] = 0x00; //系统保留
                         ++js4;
                         FAT32_ML_SETUP_WJF_WJF[js2 + js4] = js8;  //效验和
                         ++js4;
                     }

                     if(js4 == 0x001a) //文件起始簇号(目前常置0)
                     {
                         FAT32_ML_SETUP_WJF_WJF[js2 + js4] = 0x00;
                         ++js4;
                         FAT32_ML_SETUP_WJF_WJF[js2 + js4] = 0x00;
                         ++js4;
                     }

                 }while(js4 != 32);


            }while(js2 != 0);

            FAT32_ML_SETUP_WJF_WJF[0] |= 0x40; //标志为最后一个目录项

   }


   js6 = 0;
   js10 = js3;

   while(js6 != 32) FAT32_ML_SETUP_WJF_WJF[js3] = WJDATA_32B[js6],++js3,++js6;  //拷贝短文件名的32B文件符


   FAT32_WJF_32B_UPRTC(&FAT32_ML_SETUP_WJF_WJF[js10],UPX); //更新文件时间信息


   FAT32_ML_SETUP_WJF_WJFDX = js3;


   FAT32_ML_SETUP_WJF_mulu_cuhao = mulu_cuhao;

   FAT32_ML_SETUP_WJF_culian[FAT32_ML_SETUP_WJF_CLX - 1] = mulu_cuhao;
   FAT32_ML_SETUP_WJF_culiaX = FAT32_ML_SETUP_WJF_CLX - 1;
   FAT32_ML_SETUP_WJF_sqh_ = 0;
   FAT32_ML_SETUP_WJF__sqh = 0;

   FAT32_ML_SETUP_WJF_XZ = 0;
   FAT32_ML_SETUP_WJF_WJFX = 0;

}





unsigned char FAT32_ML_SETUP_WJF_RUN(unsigned char device) //运行目录创建文件符,device选择设备,返回值0错误,1继续,2完成,3设备空间不足
{

unsigned char buf[512];
unsigned int smzz;

unsigned char returnX;


     if(FAT32_ML_SETUP_WJF_XZ == 0) //初始化删除E5
     {

         FAT32_ML_SETUP_WJF_XZ = 1; //切换到运行删除E5
         returnX = FAT32_DELETE_E5(device,FAT32_ML_SETUP_WJF_mulu_cuhao); //初始化删除E5

     }
     else if(FAT32_ML_SETUP_WJF_XZ == 1) //运行删除E5
     {

         returnX = FAT32_DELETE_E5_RUN(device); //运行删除E5

         if(returnX == 2)
         {

             FAT32_ML_SETUP_WJF_XZ = 2; //切换到初始化更新簇链长度
             returnX = 1;
         }

     }
     else if(FAT32_ML_SETUP_WJF_XZ == 2) //初始化更新簇链长度
     {

         FAT32_ML_SETUP_WJF_XZ = 3; //切换到运行更新簇链长度
         FAT32_UP_culian(FAT32_ML_SETUP_WJF_mulu_cuhao,FAT32_DELETE_E5_WJFDX + FAT32_ML_SETUP_WJF_WJFDX,1); //初始化更新簇链长度
         returnX = 1;

     }
     else if(FAT32_ML_SETUP_WJF_XZ == 3) //运行更新簇链长度
     {

         returnX = FAT32_UP_culian_RUN(device); //运行更新簇链长度

         if(returnX == 2) //更新簇链长度完成
         {
             FAT32_ML_SETUP_WJF_XZ = 255; //切换到拷贝文件符
             returnX = 1;
         }

     }
     else //拷贝文件符
     {

        if(FAT32_ML_SETUP_WJF_sqh_ == FAT32_ML_SETUP_WJF__sqh) //一个簇的扇区读完,进入换簇
        {
            if(FAT32_BJ1(device,FAT32_ML_SETUP_WJF_CLX,FAT32_ML_SETUP_WJF_culian,&FAT32_ML_SETUP_WJF_culiaX,&FAT32_ML_SETUP_WJF_sqh_,&FAT32_ML_SETUP_WJF__sqh) != 1) return 0;
        }

        if(DEVICE_RD_512B(device,FAT32_ML_SETUP_WJF_sqh_,buf) == 0) return 0; //读出到缓冲区


        smzz = 0;
        while(1)
        {

            if(smzz == 512)
            {
                returnX = 1;
                break;
            }
            else if(buf[smzz] == 0x00)
            {

                while(smzz != 512 && FAT32_ML_SETUP_WJF_WJFX != FAT32_ML_SETUP_WJF_WJFDX) buf[smzz] = FAT32_ML_SETUP_WJF_WJF[FAT32_ML_SETUP_WJF_WJFX],++smzz,++FAT32_ML_SETUP_WJF_WJFX; //拷贝文件符

                if(DEVICE_WR_512B(device,FAT32_ML_SETUP_WJF_sqh_,buf) == 0) return 0; //缓冲区存盘

                if(FAT32_ML_SETUP_WJF_WJFX == FAT32_ML_SETUP_WJF_WJFDX) //文件符拷贝完成
                {
                    returnX = 2;
                    break;
                }

            }
            else
            {
                smzz += 32;
            }

        }

        ++FAT32_ML_SETUP_WJF_sqh_; //指向下一个扇区

     }


     return returnX;

}


unsigned int FAT32_WJMFL_DWJM_CWJM(unsigned char *WJM,unsigned char *DWJM,unsigned int *CWJM,unsigned char *WJM_GSBZ,unsigned char *WJFDATA_32B_byte_0CH,unsigned char CT1) //文件名分离,WJM为源文件名,DWJM为分离出的短文件名,CWJM为分离出的长文件名,WJM_GSBZ为1长文件名,0为短文件名,WJFDATA_32B_byte_0CH为32字节文件符0CH处字节,控制大小写,CT1为1的时候判断短文件名里面的大小写确定是否为长文件名,为0不判断短文件名大小写
{

unsigned int wjm_smzz; //文件名扫描指针
unsigned int _wjm_smzz; //文件名扫描指针结束位置
unsigned int wjmcd; //文件名字符总长度
unsigned char wjm_gs; //文件名格式 0为8字符3后缀名格式 1为长文件名格式
unsigned char dwjm_x; //短文件名输入指针
unsigned char dwjm_k; //文件名有第1个"."标志=1,否则=0
unsigned int cwjm_x; //长文件名的计数,记录长文件名内的元素个数
unsigned char _wjm; //文件名读出数据中间变量
unsigned char _wjm_2; //文件名读出数据中间变量2
unsigned char dwjm_dxxbz; //短文件名大小写标志
unsigned char dwjm_dxx_k; //短文件名大小写控制字节,如果短文件名的前8个字节全部为小写,位4置1,后3个字节为小写,位3置1
unsigned int D_J; //"."计数
unsigned int D_WZ1; //纪录最后一个"."的位置+1
unsigned char _WJM[807];

unsigned char js1;


  _wjm_smzz = 0;
  while(_wjm_smzz != 806 && WJM[_wjm_smzz] != 0) _WJM[_wjm_smzz] = WJM[_wjm_smzz],++_wjm_smzz;


  while(_wjm_smzz != 0)
  {
     --_wjm_smzz;

     if(_WJM[_wjm_smzz] != '.')
     {
         ++_wjm_smzz;
         _WJM[_wjm_smzz] = 0;
         break;
     }
  }

  _WJM[_wjm_smzz] = 0;



  wjmcd = 0;
  _wjm_smzz = 0;

  while(wjmcd != 403 && _WJM[_wjm_smzz] != 0) //取文件名长度
  {
     if((js1 = _WJM[_wjm_smzz]) < 128)
     {
        ++_wjm_smzz;
        if(js1 == '.') D_WZ1 = _wjm_smzz;
     }
     else _wjm_smzz += 2;
     ++wjmcd;
  }


          wjm_gs = 0;
          dwjm_k = 0;
          dwjm_x = 0;
          cwjm_x = 0;
          wjm_smzz = 0;
          dwjm_dxxbz = 0;
          dwjm_dxx_k = 0;
          D_J = 0;


          while(wjm_smzz < _wjm_smzz) //文件名没扫完继续扫
          {

               _wjm = _WJM[wjm_smzz];
               ++wjm_smzz;

               CWJM[cwjm_x] = _wjm;


               if(_wjm == '.')
               {

                  if(D_WZ1 == wjm_smzz) //为最后一个"."
                  {
                     dwjm_k = 1; //切换到后缀名输入
                     while(dwjm_x < 8) DWJM[dwjm_x] = ' ',++dwjm_x; //短文件名称不够8字符就填空格
                     dwjm_dxxbz = 0;
                  }

                  if(++D_J > 1) wjm_gs = 1; //标志为长文件名

               }
               else if(_wjm == ' ')
               {

                  wjm_gs = 1; //有空格,标志为长文件名

               }
               else
               {

                  if(_wjm > 127) //为2个字节
                  {
                      CWJM[cwjm_x] <<= 8;
                      _wjm_2 = _WJM[wjm_smzz];
                      CWJM[cwjm_x] |= _wjm_2;
                      ++wjm_smzz;
                      if(CT1 == 1) wjm_gs = 1; //标志为长文件名
                  }

                  if(dwjm_k == 0 && dwjm_x == 8 || dwjm_k == 1 && dwjm_x == 11) //超出8_3短文件名格式时标志为长文件名
                  {
                      wjm_gs = 1;
                  }
                  else
                  {

                          if(_wjm < 128) //为1个字节时进入
                          {

                              if(_wjm > 64 && _wjm < 91) //大写字母
                              {
                                  if(CT1 == 1 && dwjm_dxxbz == 2) wjm_gs = 1; //标志为长文件名
                                  dwjm_dxxbz = 1;
                              }

                              if(_wjm > 96 && _wjm < 123) //小写字母
                              {
                                  if(CT1 == 1 && dwjm_dxxbz == 1) wjm_gs = 1; //标志为长文件名
                                  dwjm_dxxbz = 2;
                                  if(dwjm_k == 0) dwjm_dxx_k = 0x08; //前8字符全为小写
                                  else dwjm_dxx_k |= 0x10; //后3字符全为小写
                                  _wjm -= 32; //为小写字母的时候转换成大写字母
                              }

                              DWJM[dwjm_x] = _wjm;
                              ++dwjm_x;

                          }
                          else //为2个字节时进入
                          {

                              DWJM[dwjm_x] = _wjm;
                              ++dwjm_x;

                              if(dwjm_k == 0 && dwjm_x == 8 || dwjm_k == 1 && dwjm_x == 11) //超出8_3短文件名格式时标志为长文件名
                              {
                                 DWJM[dwjm_x-1] = 0x20;
                                 wjm_gs = 1;
                              }
                              else
                              {
                                 DWJM[dwjm_x] = _wjm_2;
                                 ++dwjm_x;
                              }

                          }


                  }



               }

               ++cwjm_x;

          }



     while(dwjm_x < 11) DWJM[dwjm_x] = ' ',++dwjm_x; //短文件名称不够11字符就填空格

     if(wjm_gs == 0) //为短文件名
     {
         *CWJM = 0; //长文件名长度为0
     }
     else //为长文件名
     {
         CWJM[cwjm_x] = 0; //填0结尾
         dwjm_dxx_k = 0x00;
     }

     *WJM_GSBZ = wjm_gs;
     *WJFDATA_32B_byte_0CH = dwjm_dxx_k;

     return wjmcd;

}



unsigned char FAT32_ML_WJCX(unsigned char device,unsigned long int mulu_cuhao,unsigned char *WJM,unsigned char *RETURN_WJFDATA_32B,unsigned int *RETURN_CWJM,unsigned char E5_DELETE_K,unsigned char WJDX_UP_K,unsigned long int WJDX_UP,unsigned char cuhao_UP_K,unsigned long int cuhao_UP,unsigned char RTCUP_K) //目录下文件查询,device选择设备,mulu_cuhao为目录首簇号,WJM为文件名,0作为结束符,RETURN_WJFDATA_32B为返回的32个字节文件符数据,RETURN_CWJM为返回的长文件名,以0作为结束符,E5_DELETE_K为1读出文件符数据后填E5删除文件符,为0不删除文件符,WJDX_UP_K为1更新文件大小信息,WJDX_UP为文件大小,cuhao_UP_K为1更新文件簇号信息,cuhao_UP为文件簇号,RTCUP_K位2为1更新文件创建时间和日期,位1为1更新文件最后访问日期,位0为1更新文件最近修改时间和日期
{

unsigned char WJFDATA_32B_byte_0CH;
unsigned int WJMCD;

unsigned char DWJM[11];
unsigned int CWJM[404];
unsigned char CWJM_smzz;
unsigned char GSBZ;

unsigned char buf[512];
unsigned int smzz;


#define WJCX_CLX 8  //簇链长度              //记录当前扫描位置

unsigned long int WJCX_culian[8];
unsigned char WJCX_culianX;
unsigned long int WJCX_sqh_;
unsigned long int WJCX__sqh;


unsigned long int CWJM_ADDR_culian[2];           //记录长文件名起始位置
unsigned char CWJM_ADDR_culianX;
unsigned long int CWJM_ADDR_sqh_;
unsigned long int CWJM_ADDRX__sqh;
unsigned int CWJM_ADDR_smzz;
unsigned char CWJM_ADDR_BZ;
unsigned int CWJM_ADDR_CD;

unsigned char CWJM_buf[1024];
unsigned char *CWJM_buf_a;
unsigned int CWJM_buf_smzz; //指向长文件名缓冲区底部

unsigned char CWJM_TBBZ; //长文件名头部标志,1为头部,0不是头部
unsigned char CWJM_BJBZ; //长文件名比较标志,1为进行比较,0为不比较

unsigned int js1;
unsigned int js2;
unsigned int js3;


   *RETURN_WJFDATA_32B = 0;
   *RETURN_CWJM = 0;

   WJMCD = FAT32_WJMFL_DWJM_CWJM(WJM,DWJM,CWJM,&GSBZ,&WJFDATA_32B_byte_0CH,0); //文件名分离,WJM为源文件名,DWJM为分离出的短文件名,CWJM为分离出的长文件名,WJM_GSBZ为1长文件名,0为短文件名,WJFDATA_32B_byte_0CH为32字节文件符0CH处字节,控制大小写,CT1为1的时候判断短文件名里面的大小写确定是否为长文件名,为0不判断短文件名大小写



   WJCX_culian[WJCX_CLX - 1] = mulu_cuhao;
   WJCX_culianX = WJCX_CLX - 1;
   WJCX_sqh_ = 0;
   WJCX__sqh = 0;

   smzz = 0;
   CWJM_ADDR_BZ = 0;
   CWJM_BJBZ = 0;

   while(1)
   {


        if(WJCX_sqh_ == WJCX__sqh) //一个簇的扇区读完,进入换簇
        {
            if(FAT32_BJ1(device,WJCX_CLX,WJCX_culian,&WJCX_culianX,&WJCX_sqh_,&WJCX__sqh) != 1) return 0;
        }

        if(DEVICE_RD_512B(device,WJCX_sqh_,buf) == 0) return 0; //读出到缓冲区




        while(1)
        {

            if(smzz == 512)
            {
                smzz = 0;
                break;
            }
            else if(buf[smzz] == 0xe5 || buf[smzz] == 0x2e)
            {
                smzz += 32;
            }
            else if(buf[smzz] == 0x00) //没有找到文件
            {
                return 0;
            }
            else
            {



                if(buf[smzz + 0x0b] == 0x0f) //是长文件名标志
                {

                    if((buf[smzz] & 0xe0) == 0x40) //是长文件名头部
                    {

                        CWJM_ADDR_culian[1] = WJCX_culian[WJCX_culianX];           //记录长文件名起始位置
                        CWJM_ADDR_culianX = 1;
                        CWJM_ADDR_sqh_ = WJCX_sqh_;
                        CWJM_ADDRX__sqh = WJCX__sqh;
                        CWJM_ADDR_smzz = smzz;
                        CWJM_ADDR_BZ = 1;
                        CWJM_ADDR_CD = buf[smzz] & 0x1f;
                        CWJM_buf_smzz = CWJM_ADDR_CD;
                        CWJM_buf_smzz <<= 5; //乘32字节,算出长文件名底部

                        CWJM_TBBZ = 1;

                    }
                    else //不是长文件名头部
                    {
                        CWJM_TBBZ = 2;
                    }

                }
                else //不是长文件名
                {
                    CWJM_TBBZ = 0;
                }




                if(GSBZ == 0) //短文件名
                {

                    if(buf[smzz + 0x0b] != 0x0f) //是短文件名的数据
                    {

                        js1 = 0;
                        while(js1 != 11 && buf[smzz + js1] == DWJM[js1]) ++js1;

                        if(js1 != 11) //文件名不相同
                        {
                            CWJM_ADDR_BZ = 0;
                            smzz += 32;
                        }
                        else //文件名相同
                        {

                            js1 = 0;
                            while(js1 != 32) RETURN_WJFDATA_32B[js1] = buf[smzz + js1],++js1; //拷贝32B文件符


                            FAT32_WJF_32B_UPRTC(&buf[smzz],RTCUP_K); //更新文件符时间信息

                            if(WJDX_UP_K != 0) //更新文件大小
                            {
                                buf[smzz + 0x1f] = WJDX_UP >> 24; //填文件大小
                                buf[smzz + 0x1e] = WJDX_UP >> 16;
                                buf[smzz + 0x1d] = WJDX_UP >> 8;
                                buf[smzz + 0x1c] = WJDX_UP;
                            }

                            if(cuhao_UP_K != 0) //更新文件簇号
                            {
                                buf[smzz + 0x15] = cuhao_UP >> 24; //填文件簇号
                                buf[smzz + 0x14] = cuhao_UP >> 16;
                                buf[smzz + 0x1b] = cuhao_UP >> 8;
                                buf[smzz + 0x1a] = cuhao_UP;
                            }

                            if(E5_DELETE_K != 0) //删除文件
                            {
                                buf[smzz] = 0xe5;
                            }

                            if(DEVICE_WR_512B(device,WJCX_sqh_,buf) == 0) return 0; //缓冲区存盘


                            if(CWJM_ADDR_BZ == 1) //有长文件名
                            {

                                CWJM_buf_a = CWJM_buf;

                                while(1)
                                {

                                    if(CWJM_ADDR_sqh_ == CWJM_ADDRX__sqh) //一个簇的扇区读完,进入换簇
                                    {
                                        if(FAT32_BJ1(device,2,CWJM_ADDR_culian,&CWJM_ADDR_culianX,&CWJM_ADDR_sqh_,&CWJM_ADDRX__sqh) != 1) return 0;
                                    }

                                    if(DEVICE_RD_512B(device,CWJM_ADDR_sqh_,buf) == 0) return 0; //读出到缓冲区

                                    while(1)
                                    {

                                        if(CWJM_ADDR_CD == 0) //为0处理完成
                                        {

                                            if(E5_DELETE_K != 0)
                                            {
                                               if(DEVICE_WR_512B(device,CWJM_ADDR_sqh_,buf) == 0) return 0; //缓冲区存盘
                                            }

                                            goto out;

                                        }
                                        else if(CWJM_ADDR_smzz == 512)
                                        {

                                            if(E5_DELETE_K != 0)
                                            {
                                               if(DEVICE_WR_512B(device,CWJM_ADDR_sqh_,buf) == 0) return 0; //缓冲区存盘
                                            }

                                            CWJM_ADDR_smzz = 0;
                                            break;

                                        }
                                        else
                                        {

                                            js1 = 0;
                                            while(js1 != 32) *CWJM_buf_a = buf[CWJM_ADDR_smzz + js1],++CWJM_buf_a,++js1; //拷贝32B

                                            if(E5_DELETE_K != 0) buf[CWJM_ADDR_smzz] = 0xe5;
                                            CWJM_ADDR_smzz += 32;
                                            --CWJM_ADDR_CD;

                                        }

                                    }

                                    ++CWJM_ADDR_sqh_;

                                }


                                out:

                                do
                                {

                                    CWJM_buf_smzz -= 32;

                                    js1 = 1;

                                    do
                                    {
                                       js2 = CWJM_buf[CWJM_buf_smzz + js1 + 1];                         //提取出长文件名
                                       js2 <<= 8;
                                       js2 |= CWJM_buf[CWJM_buf_smzz + js1];

                                       *RETURN_CWJM = js2;
                                       js1 += 2;

                                       if(js2 == 0) break;

                                       ++RETURN_CWJM;

                                       if(js1 == 0x000b) js1 += 3;else if(js1 == 0x001a) js1 += 2;

                                    }while(js1 != 32);

                                    
                                }while(CWJM_buf_smzz != 0);


                            }


                            *RETURN_CWJM = 0; //填0结束符

                            return 1; //找到文件


                        }

                    }
                    else //是长文件名的数据
                    {
                        smzz += 32;
                    }






                }
                else //长文件名
                {

                     if(CWJM_TBBZ == 0) //不是长文件名
                     {

                         if(CWJM_BJBZ == 1)
                         {

                                 js1 = 0;
                                 while(js1 != 32) RETURN_WJFDATA_32B[js1] = buf[smzz + js1],++js1; //拷贝32B文件符


                                 FAT32_WJF_32B_UPRTC(&buf[smzz],RTCUP_K); //更新文件符时间信息

                                 if(WJDX_UP_K != 0) //更新文件大小
                                 {
                                     buf[smzz + 0x1f] = WJDX_UP >> 24; //填文件大小
                                     buf[smzz + 0x1e] = WJDX_UP >> 16;
                                     buf[smzz + 0x1d] = WJDX_UP >> 8;
                                     buf[smzz + 0x1c] = WJDX_UP;
                                 }

                                 if(cuhao_UP_K != 0) //更新文件簇号
                                 {
                                     buf[smzz + 0x15] = cuhao_UP >> 24; //填文件簇号
                                     buf[smzz + 0x14] = cuhao_UP >> 16;
                                     buf[smzz + 0x1b] = cuhao_UP >> 8;
                                     buf[smzz + 0x1a] = cuhao_UP;
                                 }

                                 if(E5_DELETE_K != 0) //删除文件
                                 {
                                     buf[smzz] = 0xe5;
                                 }

                                 if(DEVICE_WR_512B(device,WJCX_sqh_,buf) == 0) return 0; //缓冲区存盘


                                 if(E5_DELETE_K != 0) //进入填E5,删除文件
                                 {

                                     while(1)
                                     {

                                        if(CWJM_ADDR_sqh_ == CWJM_ADDRX__sqh) //一个簇的扇区读完,进入换簇
                                        {
                                            if(FAT32_BJ1(device,2,CWJM_ADDR_culian,&CWJM_ADDR_culianX,&CWJM_ADDR_sqh_,&CWJM_ADDRX__sqh) != 1) return 0;
                                        }

                                        if(DEVICE_RD_512B(device,CWJM_ADDR_sqh_,buf) == 0) return 0; //读出到缓冲区

                                        while(1)
                                        {

                                            if(CWJM_ADDR_CD == 0) //长度为0,处理完成
                                            {
                                                if(DEVICE_WR_512B(device,CWJM_ADDR_sqh_,buf) == 0) return 0; //缓冲区存盘
                                                goto out2;
                                            }
                                            else if(CWJM_ADDR_smzz == 512)
                                            {
                                                if(DEVICE_WR_512B(device,CWJM_ADDR_sqh_,buf) == 0) return 0; //缓冲区存盘
                                                CWJM_ADDR_smzz = 0;
                                                break;
                                            }
                                            else
                                            {
                                                buf[CWJM_ADDR_smzz] = 0xe5;
                                                CWJM_ADDR_smzz += 32;
                                                --CWJM_ADDR_CD;
                                            }

                                        }

                                        ++CWJM_ADDR_sqh_;

                                     }

                                     out2:

                                 }


                                 js1 = 0;
                                 while(js1 != WJMCD) RETURN_CWJM[js1] = CWJM[js1],++js1;
                                 RETURN_CWJM[js1] = 0;

                                 return 1; //处理完成


                         }


                         smzz += 32;


                     }
                     else //是长文件名
                     {

                         if(CWJM_BJBZ == 0) //比较标志为0
                         {

                             if(CWJM_TBBZ == 1) //为长文件名头部
                             {

                                 js1 = 1;
                                 js2 = 0;
                                 do
                                 {
                                     if(buf[smzz + js1] != 0x00 || buf[smzz + js1 + 1] != 0x00) ++js2;else break;
                                     js1 += 2;
                                     if(js1 == 0x000b) js1 += 3;else if(js1 == 0x001a) js1 += 2;

                                 }while(js1 != 32);


                                 if((CWJM_ADDR_CD - 1) * 13 + js2 == WJMCD) //文件名长度相同
                                 {

                                    CWJM_smzz = WJMCD;
                                    CWJM_BJBZ = 1; //进行比较
                                    goto out1;
                                 }
                                 else //文件名长度不同
                                 {
                                    smzz += 32;
                                 }

                             }
                             else //不是长文件名头部
                             {
                                 smzz += 32;
                             }

                         }
                         else //比较标志为1,文件名长度相同,进行比较
                         {

                                 js1 = 32;

                                 out1:

                                 do
                                 {

                                     js1 -= 2;
                                     if(js1 == 0x001a) js1 -= 2;else if(js1 == 0x000c) js1 -= 3;
                                     --CWJM_smzz;

                                     js2 = buf[smzz + js1 + 1];
                                     js2 <<= 8;
                                     js2 |= buf[smzz + js1];

                                     js3 = CWJM[CWJM_smzz];

                                     if(js2 > 96 && js2 < 123 && js3 > 64 && js3 < 91) js3 += 32;        //大小写对齐
                                     else if(js3 > 96 && js3 < 123 && js2 > 64 && js2 < 91) js2 += 32;

                                     if(js2 != js3) //文件名不同
                                     {
                                         CWJM_BJBZ = 0; //切换为搜索长文件名头部
                                         break;
                                     }

                                 }while(js1 != 1);

                                 smzz += 32;


                         }


                     }


                }





            }

        }


        ++WJCX_sqh_; //指向下一扇区


   }



}





unsigned char FAT32_ML_SETUP_WJ(unsigned char device,unsigned long int mulu_cuhao,unsigned long int WJDX,unsigned char *WJM,unsigned char WJSX) //初始化目录创建文件,device选择设备,mulu_cuhao为目录首簇号,WJDX为文件大小,WJM为文件名,以0作为结束符,WJSX为文件属性字节,00000000(读写),00000001(只读),00000010(隐藏),00000100(系统),00001000(卷标),00010000(子目录),00100000(归档),返回值0错误,1完成
{

unsigned char WJM_GS;
unsigned char WJFDATA_32B_byte_0CH;
unsigned char _WJM[807];
unsigned char RETURN_WJFDATA_32B[32];
unsigned int RETURN_CWJM[404];
unsigned char _HZM[807];
unsigned char buf[807];
unsigned int smzz;
unsigned int smzz1;
unsigned int _HZM_WZ;
unsigned char js1;
unsigned char js2;
unsigned char js3;
unsigned char js4;
unsigned char *_addr;


unsigned char X_; //起点
unsigned char _X_; //中间
unsigned char _X; //终点
unsigned char _X_BZ; //终点标志


  smzz = 0;
  while(smzz != 806 && WJM[smzz] != 0) _WJM[smzz] = WJM[smzz],++smzz;
  if(smzz == 806 || smzz == 0) return 0; //文件名超出长度或为0,返回0
  _WJM[smzz] = 0;


  do
  {
     --smzz;

  }while(_WJM[smzz] != '.' && smzz != 0);

  smzz1 = 0;
  if(_WJM[smzz] == '.')
  {
      _HZM_WZ = smzz;
      while(_WJM[smzz] != 0) _HZM[smzz1] = _WJM[smzz],++smzz,++smzz1;
      _WJM[_HZM_WZ] = 0;
  }
  _HZM[smzz1] = 0;



  if(FAT32_ML_SETUP_WJ_XZ == 0 && FAT32_ML_DELETE_WJ_XZ == 0 && FAT32_ML_XGWJM_XZ == 0 && FAT32_ML_XGWJDX_XZ == 0) //创建文件机构,删除文件机构,修改文件名机构,修改文件大小机构,全部空闲时进入
  {

      buf[0] = 0;
      if(FAT32_ML_WJCX(device,mulu_cuhao,strcat(buf,WJM),RETURN_WJFDATA_32B,RETURN_CWJM,0,0,0,0,0,0) != 0) //有同名文件
      {

          X_ = 1;
          _X_ = 1;
          _X_BZ = 0;

          while(1)
          {

              buf[0] = 0;
              if(FAT32_ML_WJCX(device,mulu_cuhao,strcat( strcat( strcat( strcat(buf,_WJM) ,"~") , U8_str(_X_,1) ) , _HZM ),RETURN_WJFDATA_32B,RETURN_CWJM,0,0,0,0,0,0) != 0) //有同名文件
              {
                  X_ = _X_; //纪录为起点

                  if(_X_BZ != 0) //有终点
                  {
                      if(_X - X_ < 2) //_X为结果
                      {
                          _X_ = _X;
                      }
                      else
                      {
                          _X_ = X_ + ((_X - X_) >> 1); //取中间值
                      }
                  }
                  else //没有终点
                  {
                      _X_ <<= 1; //乘2
                      if(_X_ == 0) return 0;
                  }
              }
              else //没有同名文件
              {

                 _X = _X_; //纪录为终点
                 _X_BZ = 1; //标志为有终点

                 if(_X - X_ < 2) //_X为结果
                 {
                     break; //跳出结束
                 }

                 _X_ = X_ + ((_X - X_) >> 1); //取中间值

              }

          }

      }





     FAT32_WJMFL_DWJM_CWJM(buf,FAT32_ML_SETUP_WJ_WJFDATA_32B,FAT32_ML_SETUP_WJ_CWJM,&WJM_GS,&WJFDATA_32B_byte_0CH,1); //分离出短文件名的32B和长文件名的unicode

     if(FAT32_ML_SETUP_WJ_WJFDATA_32B[0] == ' ' && FAT32_ML_SETUP_WJ_WJFDATA_32B[8] == ' ') return 0;





     js1 = 0;
     js2 = 0;
     do
     {
         if((js3 = FAT32_ML_SETUP_WJ_WJFDATA_32B[js1]) != 0x20)
         {

             if(js1 == 8)
             {
                 _WJM[js2] = '.';
                 ++js2;
             }
             _WJM[js2] = js3;
             ++js2;
         }

         ++js1;

     }while(js1 != 11);

     _WJM[js2] = 0;




      if(FAT32_ML_WJCX(device,mulu_cuhao,_WJM,RETURN_WJFDATA_32B,RETURN_CWJM,0,0,0,0,0,0) != 0) //有同名文件
      {

          X_ = 1;
          _X_ = 1;
          _X_BZ = 0;

          while(1)
          {



              _addr = U8_str(_X_,1);
              js1 = 0;
              while(_addr[js1] != 0) ++js1; //取?长度


              js2 = 0;
              js3 = 0;
              while(_WJM[js2] != 0 && _WJM[js2] != '.') buf[js3] = _WJM[js2],++js2,++js3; //拷贝前8文件名

              while(js3 + js1 + 1 > 8) --js3; //移动到合适位置

              js4 = 0;
              while(_WJM[js4] != 0 && _WJM[js4] != '.')
              {
                  if(_WJM[js4] > 127)
                  {
                      js4 += 2;
                      if(js4 - 1 == js3)
                      {
                          --js3;
                          break;
                      }
                  }
                  else ++js4;
              }


              buf[js3] = '~';
              ++js3;

              while(js1 != 0) buf[js3] = *_addr,++js3,++_addr,--js1; //拷贝~?

              while(_WJM[js2] != 0) buf[js3] = _WJM[js2],++js2,++js3; //拷贝后缀名

              buf[js3] = 0;




              if(FAT32_ML_WJCX(device,mulu_cuhao,buf,RETURN_WJFDATA_32B,RETURN_CWJM,0,0,0,0,0,0) != 0) //有同名文件
              {
                  X_ = _X_; //纪录为起点

                  if(_X_BZ != 0) //有终点
                  {
                      if(_X - X_ < 2) //_X为结果
                      {
                          _X_ = _X;
                      }
                      else
                      {
                          _X_ = X_ + ((_X - X_) >> 1); //取中间值
                      }
                  }
                  else //没有终点
                  {
                      _X_ <<= 1; //乘2
                      if(_X_ == 0) return 0;
                  }
              }
              else //没有同名文件
              {

                 _X = _X_; //纪录为终点
                 _X_BZ = 1; //标志为有终点

                 if(_X - X_ < 2) //_X为结果
                 {
                     break; //跳出结束
                 }

                 _X_ = X_ + ((_X - X_) >> 1); //取中间值

              }

          }


          FAT32_WJMFL_DWJM_CWJM(buf,FAT32_ML_SETUP_WJ_WJFDATA_32B,RETURN_CWJM,&WJM_GS,&WJFDATA_32B_byte_0CH,1); //分离出短文件名的32B和长文件名的unicode



      }







     FAT32_ML_SETUP_WJ_WJFDATA_32B[0x0b] = WJSX; //填文件属性
     FAT32_ML_SETUP_WJ_WJFDATA_32B[0x0c] = WJFDATA_32B_byte_0CH; //填短文件名大小写控制字节,位3为1,前8字符全为小写,位4为1,后3字符全为小写
     FAT32_ML_SETUP_WJ_WJFDATA_32B[0x0d] = 0x00; //填10毫秒位


     FAT32_ML_SETUP_WJ_DEVICE = device;
     FAT32_ML_SETUP_WJ_mulu_cuhao = mulu_cuhao;
     FAT32_ML_SETUP_WJ_XZ = 1;

     if((WJSX & 0xf0) == 0x20) //是文件
     {
         FAT32_ML_SETUP_WJ_WJDX = WJDX;
         FAT32_ML_SETUP_WJ_LBA_VOID_K = 0; //不清空新扇区

         FAT32_ML_SETUP_WJ_WJFDATA_32B[0x1f] = WJDX >> 24; //填文件大小
         FAT32_ML_SETUP_WJ_WJFDATA_32B[0x1e] = WJDX >> 16;
         FAT32_ML_SETUP_WJ_WJFDATA_32B[0x1d] = WJDX >> 8;
         FAT32_ML_SETUP_WJ_WJFDATA_32B[0x1c] = WJDX;

     }
     else //是目录
     {
         FAT32_ML_SETUP_WJ_WJDX = 1;
         FAT32_ML_SETUP_WJ_LBA_VOID_K = 1; //清空新扇区

         FAT32_ML_SETUP_WJ_WJFDATA_32B[0x1f] = 0x00; //填文件大小
         FAT32_ML_SETUP_WJ_WJFDATA_32B[0x1e] = 0x00;
         FAT32_ML_SETUP_WJ_WJFDATA_32B[0x1d] = 0x00;
         FAT32_ML_SETUP_WJ_WJFDATA_32B[0x1c] = 0x00;
     }

     return 1;

  }
  else return 0;

}



unsigned char FAT32_ML_SETUP_WJ_RUN() //运行目录创建文件,返回值0错误,1继续,2完成,3存储设备空间不足,4空闲
{

unsigned char returnX;


     if(FAT32_ML_SETUP_WJ_XZ == 0) //完成
     {
         returnX = 4; //空闲

     }
     else if(FAT32_ML_SETUP_WJ_XZ == 1) //扫描空白簇初始化
     {

         FAT32_VOID_cuhao(FAT32_ML_SETUP_WJ_DEVICE,0); //扫描空白簇初始化,扫FAT1
         FAT32_ML_SETUP_WJ_XZ = 2; //切换到运行扫描空白簇
         returnX = 1;

     }
     else if(FAT32_ML_SETUP_WJ_XZ == 2) //运行扫描空白簇
     {

         returnX = FAT32_VOID_cuhao_RUN(FAT32_ML_SETUP_WJ_DEVICE); //运行扫描空白簇,返回值1继续,2找到空白簇,0设备错误,3存储设备满

         if(returnX == 2) //找到空白簇
         {
             FAT32_ML_SETUP_WJ_XZ = 3; //切换到初始化更新文件簇链长度
             returnX = 1;
         }

     }
     else if(FAT32_ML_SETUP_WJ_XZ == 3) //初始化更新文件簇链长度
     {

         FAT32_UP_culian(FAT32_VOID_cuhao_cuhao,FAT32_ML_SETUP_WJ_WJDX,FAT32_ML_SETUP_WJ_LBA_VOID_K); //初始化更新簇链长度
         FAT32_ML_SETUP_WJ_XZ = 4; //切换到运行更新簇链长度
         returnX = 1;

     }
     else if(FAT32_ML_SETUP_WJ_XZ == 4) //运行更新文件簇链长度
     {

         returnX = FAT32_UP_culian_RUN(FAT32_ML_SETUP_WJ_DEVICE); //运行更新簇链长度,device选择设备,返回0错误,1继续,2完成,3存储设备空间不足

         if(returnX == 2) //更新簇链长度完成
         {
             FAT32_ML_SETUP_WJ_XZ = 5; //切换到目录创建文件符初始化
             returnX = 1;
         }

     }
     else if(FAT32_ML_SETUP_WJ_XZ == 5) //目录创建文件符初始化
     {

         FAT32_ML_SETUP_WJ_WJFDATA_32B[0x15] = FAT32_VOID_cuhao_cuhao >> 24; //修改32B文件符簇号
         FAT32_ML_SETUP_WJ_WJFDATA_32B[0x14] = FAT32_VOID_cuhao_cuhao >> 16;
         FAT32_ML_SETUP_WJ_WJFDATA_32B[0x1b] = FAT32_VOID_cuhao_cuhao >> 8;
         FAT32_ML_SETUP_WJ_WJFDATA_32B[0x1a] = FAT32_VOID_cuhao_cuhao;

         FAT32_ML_SETUP_WJF(FAT32_ML_SETUP_WJ_mulu_cuhao,FAT32_ML_SETUP_WJ_WJFDATA_32B,FAT32_ML_SETUP_WJ_CWJM,0x07); //目录创建文件符初始化, mulu_cuhao是目录首簇号, WJDATA_32B是32个字节的文件数据, WJ_CWJM是文件的长文件名,以0作为结束符,UPX位2为1更新文件创建时间和日期,位1为1更新文件最后访问日期,位0为1更新文件最近修改时间和日期
         FAT32_ML_SETUP_WJ_XZ = 6; //切换到运行目录创建文件符
         returnX = 1;

     }
     else if(FAT32_ML_SETUP_WJ_XZ == 6) //运行目录创建文件符
     {

         returnX = FAT32_ML_SETUP_WJF_RUN(FAT32_ML_SETUP_WJ_DEVICE); //运行目录创建文件符,device选择设备,返回值0错误,1继续,2完成,3设备空间不足

         if(returnX == 3) //设备空间不足
         {
             FAT32_ML_SETUP_WJ_XZ = 7; //初始化更新文件簇链长度(清除文件簇链)
             returnX = 1;
         }

     }
     else if(FAT32_ML_SETUP_WJ_XZ == 7) //初始化更新文件簇链长度(清除文件簇链)
     {

         FAT32_UP_culian(FAT32_VOID_cuhao_cuhao,0,0); //初始化更新簇链长度
         FAT32_ML_SETUP_WJ_XZ = 8; //切换到运行更新簇链长度
         returnX = 1;

     }
     else if(FAT32_ML_SETUP_WJ_XZ == 8) //运行更新文件簇链长度(清除文件簇链)
     {

         returnX = FAT32_UP_culian_RUN(FAT32_ML_SETUP_WJ_DEVICE); //运行更新簇链长度,device选择设备,返回0错误,1继续,2完成,3存储设备空间不足(创建簇链)

         if(returnX == 2) //更新簇链长度完成
         {
             returnX = 3; //设备空间不足
         }

     }


     if(returnX != 1) FAT32_ML_SETUP_WJ_XZ = 0; //结束

     return returnX;

}















unsigned char FAT32_ML_DELETE_WJ(unsigned char device,unsigned long int mulu_cuhao,unsigned char *WJM) //初始化目录删除文件,device选择设备,mulu_cuhao为目录首簇号,WJM为文件名,以0作为结束符,返回值0错误,1完成
{

unsigned char WJFDATA_32B[32];
unsigned int CWJM[404];
unsigned char returnX;

  if(FAT32_ML_SETUP_WJ_XZ == 0 && FAT32_ML_DELETE_WJ_XZ == 0 && FAT32_ML_XGWJM_XZ == 0 && FAT32_ML_XGWJDX_XZ == 0) //创建文件机构,删除文件机构,修改文件名机构,修改文件大小机构,全部空闲时进入
  {

    FAT32_ML_DELETE_WJ_mulu_cuhao = mulu_cuhao; //记录目录的首簇号
    if(FAT32_ML_WJCX(device,mulu_cuhao,WJM,WJFDATA_32B,CWJM,1,0,0,0,0,0) == 0) return 0;

    FAT32_ML_DELETE_WJ_cuhao = WJFDATA_32B[0x15]; //记录文件首簇号
    FAT32_ML_DELETE_WJ_cuhao <<= 8;
    FAT32_ML_DELETE_WJ_cuhao |= WJFDATA_32B[0x14];
    FAT32_ML_DELETE_WJ_cuhao <<= 8;
    FAT32_ML_DELETE_WJ_cuhao |= WJFDATA_32B[0x1b];
    FAT32_ML_DELETE_WJ_cuhao <<= 8;
    FAT32_ML_DELETE_WJ_cuhao |= WJFDATA_32B[0x1a];

    FAT32_ML_DELETE_WJ_DEVICE = device;
    FAT32_ML_DELETE_WJ_XZ = 1;

    return 1;

  }
  else return 0;

}


unsigned char FAT32_ML_DELETE_WJ_RUN() //运行目录删除文件,返回值0错误,1继续,2完成,4空闲
{

unsigned char returnX;

    if(FAT32_ML_DELETE_WJ_XZ == 0) //初始化更新文件簇链长度(清除文件簇链)
    {
         returnX = 4;
    }
    else if(FAT32_ML_DELETE_WJ_XZ == 1) //初始化更新文件簇链长度(清除文件簇链)
    {

         if(FAT32_ML_DELETE_WJ_cuhao == 0) //簇号为0完成
         {
             returnX = 2;
         }
         else
         {
             FAT32_UP_culian(FAT32_ML_DELETE_WJ_cuhao,0,0); //初始化更新簇链长度
             FAT32_ML_DELETE_WJ_XZ = 2; //切换到运行更新簇链长度
             returnX = 1;
         }

    }
    else if(FAT32_ML_DELETE_WJ_XZ == 2) //运行更新文件簇链长度(清除文件簇链)
    {
         returnX = FAT32_UP_culian_RUN(FAT32_ML_DELETE_WJ_DEVICE); //运行更新簇链长度,device选择设备,返回0错误,1继续,2完成,3存储设备空间不足(创建簇链)
    }


    if(returnX != 1) FAT32_ML_DELETE_WJ_XZ = 0; //结束

    return returnX;

}




unsigned char FAT32_ML_XGWJM(unsigned char device,unsigned long int mulu_cuhao,unsigned char *WJM_,unsigned char *_WJM) //初始化修改文件名,device选择设备,mulu_cuhao为目录首簇号,WJM_为原文件的文件名,_WJM为新文件名
{

unsigned char GSBZ;
unsigned char WJFDATA_32B_byte_0CH;
unsigned char returnX;

unsigned char js1;

  if(FAT32_ML_SETUP_WJ_XZ == 0 && FAT32_ML_DELETE_WJ_XZ == 0 && FAT32_ML_XGWJM_XZ == 0 && FAT32_ML_XGWJDX_XZ == 0) //创建文件机构,删除文件机构,修改文件名机构,修改文件大小机构,全部空闲时进入
  {

    returnX = FAT32_ML_WJCX(device,mulu_cuhao,WJM_,FAT32_ML_XGWJM_S_WJFDATA_32B,FAT32_ML_XGWJM_S_CWJM,1,0,0,0,0,0); //取出原文件符,并填E5删除原文件符

    FAT32_WJMFL_DWJM_CWJM(_WJM,FAT32_ML_XGWJM_D_WJFDATA_32B,FAT32_ML_XGWJM_D_CWJM,&GSBZ,&WJFDATA_32B_byte_0CH,1); //文件名分离

    js1 = 0x0b;
    while(js1 != 32) FAT32_ML_XGWJM_D_WJFDATA_32B[js1] = FAT32_ML_XGWJM_S_WJFDATA_32B[js1],++js1; //拷贝原文件符信息

    FAT32_ML_XGWJM_DEVICE = device;
    FAT32_ML_XGWJM_D_WJFDATA_32B[0x0c] = WJFDATA_32B_byte_0CH;
    FAT32_ML_XGWJM_mulu_cuhao = mulu_cuhao;
    FAT32_ML_XGWJM_XZ = 1;

    return returnX;

  }
  else return 0;

}

unsigned char FAT32_ML_XGWJM_RUN() //运行修改文件名,返回值0错误,1继续,2完成,3存储设备空间不足,4空闲
{

unsigned char returnX;


     if(FAT32_ML_XGWJM_XZ == 0) //完成
     {
         returnX = 4;

     }
     else if(FAT32_ML_XGWJM_XZ == 1) //目录创建文件符初始化
     {

         FAT32_ML_SETUP_WJF(FAT32_ML_XGWJM_mulu_cuhao,FAT32_ML_XGWJM_D_WJFDATA_32B,FAT32_ML_XGWJM_D_CWJM,0x00); //目录创建文件符初始化, mulu_cuhao是目录首簇号, WJDATA_32B是32个字节的文件数据, WJ_CWJM是文件的长文件名,以0作为结束符,UPX位2为1更新文件创建时间和日期,位1为1更新文件最后访问日期,位0为1更新文件最近修改时间和日期
         FAT32_ML_XGWJM_XZ = 2; //切换到运行目录创建文件符
         returnX = 1;

     }
     else if(FAT32_ML_XGWJM_XZ == 2) //运行目录创建文件符
     {

         returnX = FAT32_ML_SETUP_WJF_RUN(FAT32_ML_XGWJM_DEVICE); //运行目录创建文件符,device选择设备,返回值0错误,1继续,2完成,3设备空间不足

         if(returnX == 3) //设备空间不足
         {
             FAT32_ML_XGWJM_XZ = 3; //切换到目录创建文件符初始化(恢复原文件符)
             returnX = 1;
         }

     }
     else if(FAT32_ML_XGWJM_XZ == 3) //目录创建文件符初始化(恢复原文件符)
     {

         FAT32_ML_SETUP_WJF(FAT32_ML_XGWJM_mulu_cuhao,FAT32_ML_XGWJM_S_WJFDATA_32B,FAT32_ML_XGWJM_S_CWJM,0x00); //目录创建文件符初始化, mulu_cuhao是目录首簇号, WJDATA_32B是32个字节的文件数据, WJ_CWJM是文件的长文件名,以0作为结束符,UPX位2为1更新文件创建时间和日期,位1为1更新文件最后访问日期,位0为1更新文件最近修改时间和日期
         FAT32_ML_XGWJM_XZ = 4; //切换到运行目录创建文件符
         returnX = 1;

     }
     else if(FAT32_ML_XGWJM_XZ == 4) //运行目录创建文件符(恢复原文件符)
     {

         returnX = FAT32_ML_SETUP_WJF_RUN(FAT32_ML_XGWJM_DEVICE); //运行目录创建文件符,device选择设备,返回值0错误,1继续,2完成,3设备空间不足

     }


     if(returnX != 1) FAT32_ML_XGWJM_XZ = 0; //结束

     return returnX;

}


unsigned char FAT32_LJ_WJCX(unsigned char device,unsigned long int mulu_cuhao,unsigned char *WJLJ,unsigned char *RETURN_WJFDATA_32B,unsigned int *RETURN_CWJM) //路径文件查询,device选择设备,mulu_cuhao为目录首簇号,WJLJ为文件路径,0作为结束符,RETURN_WJFDATA_32B为返回的32个字节文件符数据,RETURN_CWJM为返回的长文件名,以0作为结束符
{

unsigned char returnX;
unsigned int WJLJ_smzz;
unsigned char _WJM;
unsigned char WJM[807];
unsigned int WJM_smzz;


     WJLJ_smzz = 0;
     WJM_smzz = 0;

     while(1)
     {

          _WJM = WJLJ[WJLJ_smzz];
          ++WJLJ_smzz;

          if(_WJM == 0) //文件路径结束
          {

              WJM[WJM_smzz] = 0; //填0结束符
              return FAT32_ML_WJCX(device,mulu_cuhao,WJM,RETURN_WJFDATA_32B,RETURN_CWJM,0,0,0,0,0,0); //查询此目录文件

          }
          else if(_WJM == '\') //目录符
          {

              WJM[WJM_smzz] = 0; //填0结束符
              if(FAT32_ML_WJCX(device,mulu_cuhao,WJM,RETURN_WJFDATA_32B,RETURN_CWJM,0,0,0,0,0,0) != 1) return 0; //查询此目录文件

              if((RETURN_WJFDATA_32B[0x0b] & 0xf0) == 0x10) //是目录
              {

                  mulu_cuhao = RETURN_WJFDATA_32B[0x15]; //记录文件首簇号
                  mulu_cuhao <<= 8;
                  mulu_cuhao |= RETURN_WJFDATA_32B[0x14];
                  mulu_cuhao <<= 8;
                  mulu_cuhao |= RETURN_WJFDATA_32B[0x1b];
                  mulu_cuhao <<= 8;
                  mulu_cuhao |= RETURN_WJFDATA_32B[0x1a];

                  WJM_smzz = 0;

              }
              else //不是目录
              {
                  return 0;
              }

          }
          else //文件名
          {

              WJM[WJM_smzz] = _WJM;
              ++WJM_smzz;

          }


     }


}




unsigned char FAT32_GET_VOID_RWWJ_BZ(unsigned int device) //申请空闲的文件号,返回255表示没有空闲的文件号
{

unsigned char *_addr;
unsigned char smzz;

   _addr = FAT32_RWWJ_bz + device*FAT32_RWWJ_WJX;

   for(smzz = 0;smzz != FAT32_RWWJ_WJX && _addr[smzz] != 0;++smzz); //找空标志

   return smzz != FAT32_RWWJ_WJX ? smzz : 255;
}

void FAT32_GBWJ(unsigned int device,unsigned int wjx) //关闭文件
{
   FAT32_RWWJ_bz[device*FAT32_RWWJ_WJX+wjx] = 0;
}



unsigned char FAT32_RWWJ_512B_BJ(unsigned char rw,unsigned int device,unsigned int wjx,unsigned char *buf) //读写文件512字节部件,rw=1为读,rw=0为写,device选择设备,wjx文件号,buf缓冲区,返回值0错误,1继续,2完成
{

//优化后 节省6KB的ROM


unsigned int addrx;
unsigned int addry;
unsigned long int sqh_;
unsigned long int *a_sqh_;
unsigned long int *a__sqh;
unsigned char *a_bz;
unsigned long int *a_wjdx;
unsigned char *a_culianX;
unsigned char culianX;
unsigned long int cuhao;



   addrx = device*FAT32_RWWJ_WJX + wjx;
   addry = device*(FAT32_RWWJ_WJX*FAT32_RWWJ_CLX) + wjx*FAT32_RWWJ_CLX;

   a_sqh_ = FAT32_RWWJ_sqh_ + addrx;
   a__sqh = FAT32_RWWJ__sqh + addrx;
   a_bz = FAT32_RWWJ_bz + addrx;
   a_wjdx = FAT32_RWWJ__wjdx + addrx;
   a_culianX = FAT32_RWWJ_culianX + addrx;



   if(*a_bz != 0) //判断文件是否打开
   {

        if(*a_sqh_ == *a__sqh) //一个簇的扇区读完,进入换簇
        {

                culianX = *a_culianX;
                cuhao = FAT32_RWWJ_culian[addry + culianX];


                if(cuhao == 0x0fffffff || cuhao == 0x00000000)
                {
                    *a_bz = 0; //文件剩余大小小于或等于512字节,标志文件关闭
                    *a_wjdx = 0; //文件剩余大小等于0
                    return 0; //为簇结束标志或断簇,进入处理
                }

                sqh_= FAT32_cuhao_shanquhao(device,cuhao); //簇号转首扇区号
                *a_sqh_ = sqh_;
                *a__sqh = sqh_ + FAT32_cudx[device]; //记录簇的尾扇区的下一扇区号

                if(culianX == FAT32_RWWJ_CLX - 1) //尾簇? 进入更新簇链
                {
                    if(FAT32_cuhao_culian(device,cuhao,FAT32_RWWJ_CLX,&FAT32_RWWJ_culian[addry]) == 0) return 0; //读出尾簇指向的下面16个簇放到簇链缓冲区,如果错误,进入处理

                    *a_culianX = 0; //簇指针指向首簇
                }
                else
                {
                    ++*a_culianX; //指向下一个簇号
                }

        }

        sqh_ = *a_sqh_++; //指向下一个扇区

        if(rw == 1 && DEVICE_RD_512B(device,sqh_,buf) == 0 || rw == 0 && DEVICE_WR_512B(device,sqh_,buf) == 0) return 0; //读出一个扇区到缓冲区,如果错误,进入处理

//        ++*a_sqh_; //指向下一个扇区

        if(*a_wjdx <= 512)
        {
           *a_bz = 0; //文件剩余大小小于或等于512字节,标志文件关闭
           *a_wjdx = 0; //文件剩余大小等于0
        }
        else *a_wjdx -= 512; //文件剩余大小减512字节

        return 1;

   }else return 2;

}


unsigned char FAT32_RDWJ_512B(unsigned char device,unsigned char wjx,unsigned char *buf) //读文件512字节,device选择设备,wjx文件号,buf缓冲区,返回值不为0表示操作成功
{

   return FAT32_RWWJ_512B_BJ(1,device,wjx,buf);

}


unsigned char FAT32_WRWJ_512B(unsigned char device,unsigned char wjx,unsigned char *buf) //写文件512字节,device选择设备,wjx文件号,buf缓冲区,返回值不为0表示操作成功
{

   return FAT32_RWWJ_512B_BJ(0,device,wjx,buf);

}


unsigned char FAT32_OPENWJ(unsigned int device,unsigned long int mulu_cuhao,unsigned int wjx,unsigned char *wjlj) //打开文件,device选择设备,mulu_cuhao指定起始目录首簇号,wjx文件号,wjlj文件路径,以0作为路径结束符,返回值不为0表示操作成功
{

unsigned char buf[32];
unsigned long int js1;

unsigned int addrx;

unsigned int RETURN_CWJM[404];


   addrx = device*FAT32_RWWJ_WJX + wjx;

   if(FAT32_LJ_WJCX(device,mulu_cuhao,wjlj,buf,RETURN_CWJM) == 0) return 0; //查询文件

   js1 = buf[0x15]; //记录文件首簇号
   js1 <<= 8;
   js1 |= buf[0x14];
   js1 <<= 8;
   js1 |= buf[0x1b];
   js1 <<= 8;
   js1 |= buf[0x1a];

   FAT32_RWWJ_cuhao[addrx] = js1; //记录文件首簇号
   FAT32_RWWJ_culian[(device*(FAT32_RWWJ_WJX*FAT32_RWWJ_CLX))+(wjx*FAT32_RWWJ_CLX) + (FAT32_RWWJ_CLX - 1)] = js1; //文件首簇号放到簇链尾部
   FAT32_RWWJ_culianX[addrx] = FAT32_RWWJ_CLX - 1; //簇链指针指向簇链尾部


   js1 = buf[0x1f]; //记录文件大小
   js1 <<= 8;
   js1 |= buf[0x1e];
   js1 <<= 8;
   js1 |= buf[0x1d];
   js1 <<= 8;
   js1 |= buf[0x1c];

   FAT32_RWWJ__wjdx[addrx] = js1; //记录文件大小到文件剩余大小
   FAT32_RWWJ_wjdx_[addrx] = js1; //记录文件大小到文件总大小

   if(js1 != 0)
   {
      FAT32_RWWJ_bz[addrx] = 1; //文件大小不为0,标志文件打开
      FAT32_RWWJ_sqh_[addrx] = FAT32_RWWJ__sqh[addrx]; //操作扇区号指针和簇尾扇区号+1指针同值
   }

   return 1;

}



unsigned long int FAT32_RETURN_WJDX_(unsigned int device,unsigned int wjx) //取文件总大小,device选择设备,wjx文件号,返回值为文件大小,单位字节
{
   return FAT32_RWWJ_wjdx_[device*FAT32_RWWJ_WJX + wjx];
}


unsigned long int FAT32_RETURN__WJDX(unsigned int device,unsigned int wjx) //取文件读写剩余大小,device选择设备,wjx文件号,返回值为文件大小,单位字节
{
   return FAT32_RWWJ__wjdx[device*FAT32_RWWJ_WJX + wjx];
}

unsigned long int FAT32_RETURN_WJ_cuhao(unsigned int device,unsigned int wjx) //取文件首簇号,device选择设备,wjx文件号,返回值为文件首簇号
{
   return FAT32_RWWJ_cuhao[device*FAT32_RWWJ_WJX + wjx];
}


/*
unsigned char FAT32_RWWJ_SETLBA(unsigned int device,unsigned int wjx,unsigned long int LBA) //设置读写文件起始扇区,device选择设备,wjx文件号,LBA文件逻辑扇区号,返回值不为0表示操作成功
{

unsigned char sqh_;
unsigned char _sqh;
unsigned long int culian[16];
unsigned char culianX;
unsigned long int _wjdx;
unsigned long int js1;

unsigned int addrx;
unsigned long int cuhao;

   addrx = device*FAT32_RWWJ_WJX + wjx;



   if(FAT32_RWWJ_bz[addrx] == 1) //判断文件是否打开
   {

       culian[15] = FAT32_RWWJ_cuhao[addrx]; //文件首簇号放到簇链尾部
       culianX = 15; //簇链指针指向簇链尾部
       _wjdx = FAT32_RWWJ_wjdx_[addrx];  //记录文件大小到文件剩余大小
       sqh_ = _sqh;
       js1 = 0;

       while(js1 != LBA)
       {

           if(sqh_ == _sqh) //一个簇的扇区读完,进入换簇
           {

                cuhao = culian[culianX];

                if(cuhao == 0x0fffffff) return 0; //为簇结束标志,进入处理

                sqh_ = FAT32_cuhao_shanquhao(device,cuhao); //簇号转首扇区号
                _sqh = sqh_ + FAT32_cudx[device]; //记录簇的尾扇区的下一扇区号

                if(culianX == 15) //尾簇? 进入更新簇链
                {
                    if(FAT32_cuhao_culian(device,culian[15],16,culian) == 0) return 0; //读出尾簇指向的下面16个簇放到簇链缓冲区,如果错误,进入处理
                    culianX = 0; //簇指针指向首簇
                }
                else
                {
                    ++culianX; //指向下一个簇号
                }

           }

           if(_wjdx <= 512) break;
           ++sqh_; //指向下一个扇区
           ++js1; //扇区计数加1
           _wjdx -= 512; //文件剩余大小减512字节

       }

       FAT32_RWWJ__wjdx[addrx] = _wjdx;
       FAT32_RWWJ_culian[(device*(FAT32_RWWJ_WJX*FAT32_RWWJ_CLX))+(wjx*FAT32_RWWJ_CLX) + (FAT32_RWWJ_CLX - 1)] = culian[culianX]; //文件首簇号放到簇链尾部
       FAT32_RWWJ_culianX[addrx] = FAT32_RWWJ_CLX - 1; //簇链指针指向簇链尾部
       FAT32_RWWJ_sqh_[addrx] = sqh_;
       FAT32_RWWJ__sqh[addrx] = _sqh;

       return 1;

   }else return 0;

}
*/

unsigned char FAT32_RWWJ_SETLBA(unsigned int device,unsigned int wjx,unsigned long int LBA) //设置读写文件起始扇区,device选择设备,wjx文件号,LBA文件逻辑扇区号,返回值不为0表示操作成功
{

unsigned long int cuX;
unsigned long int sqh_;
unsigned long int culian[128];
unsigned char culianX;
unsigned long int cuX_J;
unsigned long int _wjdx;
unsigned int addrx;
unsigned long int js1;
unsigned long int js2;



   addrx = device*FAT32_RWWJ_WJX + wjx;


   if(FAT32_RWWJ_bz[addrx] == 1) //判断文件是否打开
   {

       js1 = LBA << 9; //乘512算出文件大小(字节)
       js2 = FAT32_RWWJ_wjdx_[addrx]; //读出文件总大小(字节)

       if(js1 >= js2) //设置的扇区超出文件范围
       {
           LBA = js2 >> 9 + (js2 % 512 != 0) - 1; //LBA设置为文件最后一个扇区
       }
       else
       {
           _wjdx = js2 - js1; //算出剩余文件大小
       }

       js1 = FAT32_cudx[device];
       cuX = LBA / js1; //算出簇数量
       sqh_ = LBA % js1; //算出簇内扇区偏移

       culian[127] = FAT32_RWWJ_cuhao[addrx]; //文件首簇号放到簇链尾部
       culianX = 127; //簇指针指向最后一个簇
       cuX_J = 0;


       while(cuX_J != cuX)
       {

           js1 = culian[culianX];
           if(js1 == 0x0fffffff || js1 == 0x00000000) break;

           if(culianX == 127) //尾簇? 进入更新簇链
           {
               if(FAT32_cuhao_culian(device,culian[127],128,culian) == 0) return 0; //读出尾簇指向的下面128个簇放到簇链缓冲区,如果错误,进入处理
               culianX = 0; //簇指针指向首簇
           }
           else
           {
               ++culianX; //指向下一个簇号
           }

           ++cuX_J; //簇计数

       }


       js1 = culian[culianX]; //读出簇号

       FAT32_RWWJ__wjdx[addrx] = _wjdx; //回写文件剩余大小
       FAT32_RWWJ_culian[(device*(FAT32_RWWJ_WJX*FAT32_RWWJ_CLX))+(wjx*FAT32_RWWJ_CLX) + (FAT32_RWWJ_CLX - 1)] = js1; //文件首簇号放到簇链尾部
       FAT32_RWWJ_culianX[addrx] = FAT32_RWWJ_CLX - 1; //簇链指针指向簇链尾部

       js2 = FAT32_cuhao_shanquhao(device,js1); //簇号转首扇区号
       FAT32_RWWJ_sqh_[addrx] = js2 + sqh_;  //回写簇首扇区加簇内扇区偏移
       FAT32_RWWJ__sqh[addrx] = js2 + FAT32_cudx[device];  //回写簇尾扇区号+1

       return 1;


   }else return 0;

}



unsigned char FAT32_ML_XGWJDX(unsigned char device,unsigned long int mulu_cuhao,unsigned char *WJM,unsigned long int WJDX) //初始化修改文件大小,device选择设备,mulu_cuhao为目录首簇号,WJM为文件名,WJDX为文件大小,返回值为1成功
{

unsigned char WJFDATA_32B[32];
unsigned int CWJM[404];
unsigned char returnX;

unsigned char XGCH;

  if(FAT32_ML_SETUP_WJ_XZ == 0 && FAT32_ML_DELETE_WJ_XZ == 0 && FAT32_ML_XGWJM_XZ == 0 && FAT32_ML_XGWJDX_XZ == 0) //创建文件机构,删除文件机构,修改文件名机构,修改文件大小机构,全部空闲时进入
  {

    XGCH = 0;
    if(WJDX == 0) XGCH = 1; //如果文件大小为0,修改簇号

    returnX = FAT32_ML_WJCX(device,mulu_cuhao,WJM,WJFDATA_32B,CWJM,0,1,WJDX,XGCH,0,0x03); //修改文件大小,如果文件大小为0,簇号填0


    FAT32_ML_XGWJDX_WJDX_ = WJFDATA_32B[0x1f]; //记录文件的原大小
    FAT32_ML_XGWJDX_WJDX_ <<= 8;
    FAT32_ML_XGWJDX_WJDX_ |= WJFDATA_32B[0x1e];
    FAT32_ML_XGWJDX_WJDX_ <<= 8;
    FAT32_ML_XGWJDX_WJDX_ |= WJFDATA_32B[0x1d];
    FAT32_ML_XGWJDX_WJDX_ <<= 8;
    FAT32_ML_XGWJDX_WJDX_ |= WJFDATA_32B[0x1c];

    FAT32_ML_XGWJDX_WJ_cuhao = WJFDATA_32B[0x15]; //记录文件的簇号
    FAT32_ML_XGWJDX_WJ_cuhao <<= 8;
    FAT32_ML_XGWJDX_WJ_cuhao |= WJFDATA_32B[0x14];
    FAT32_ML_XGWJDX_WJ_cuhao <<= 8;
    FAT32_ML_XGWJDX_WJ_cuhao |= WJFDATA_32B[0x1b];
    FAT32_ML_XGWJDX_WJ_cuhao <<= 8;
    FAT32_ML_XGWJDX_WJ_cuhao |= WJFDATA_32B[0x1a];

    FAT32_ML_XGWJDX__WJDX = WJDX; //记录文件的新大小
    FAT32_ML_XGWJDX_mulu_cuhao = mulu_cuhao; //记录文件所在目录簇号
    FAT32_ML_XGWJDX_WJM = WJM; //记录文件名地址
    FAT32_ML_XGWJDX_WJKCBZ = 0; //空簇标志清0

    FAT32_ML_XGWJDX_DEVICE = device;

    if(WJDX == 0) //修改文件大小为0字节
    {
        if(FAT32_ML_XGWJDX_WJ_cuhao == 0) //文件簇号为0
        {
            FAT32_ML_XGWJDX_XZ = 5; //完成
        }
        else //文件簇号不为0
        {
            FAT32_ML_XGWJDX_XZ = 3; //初始化更新文件簇链长度(删除簇链)
        }
    }
    else //修改文件大小不为0字节
    {
        if(FAT32_ML_XGWJDX_WJ_cuhao == 0) //文件簇号为0
        {
            FAT32_ML_XGWJDX_WJKCBZ = 1; //标志空簇
            FAT32_ML_XGWJDX_XZ = 1; //初始化扫描空白簇
        }
        else //文件簇号不为0
        {
            FAT32_ML_XGWJDX_XZ = 3; //初始化更新文件簇链长度
        }
    }


    return returnX;

  }
  else return 0;

}


unsigned char FAT32_ML_XGWJDX_RUN() //运行修改文件大小,返回值0错误,1继续,2完成,3存储设备空间不足,4空闲
{

unsigned int CWJM[404];
unsigned char WJFDATA_32B[32];
unsigned char returnX;


    if(FAT32_ML_XGWJDX_XZ == 0)
    {
        returnX = 4; //空闲

    }
    else if(FAT32_ML_XGWJDX_XZ == 1) //初始化扫描空白簇
    {

        FAT32_VOID_cuhao(FAT32_ML_XGWJDX_DEVICE,0); //初始化扫描空白簇,0为扫FAT1
        FAT32_ML_XGWJDX_XZ = 2; //切换到运行扫描空白簇
        returnX = 1;

    }
    else if(FAT32_ML_XGWJDX_XZ == 2) //运行扫描空白簇
    {

        returnX = FAT32_VOID_cuhao_RUN(FAT32_ML_XGWJDX_DEVICE); //运行扫描空白簇

        if(returnX == 2) //找到空白簇
        {
            returnX = FAT32_ML_WJCX(FAT32_ML_XGWJDX_DEVICE,FAT32_ML_XGWJDX_mulu_cuhao,FAT32_ML_XGWJDX_WJM,WJFDATA_32B,CWJM,0,0,0,1,FAT32_VOID_cuhao_cuhao,0); //填文件簇号

            FAT32_ML_XGWJDX_WJ_cuhao = FAT32_VOID_cuhao_cuhao; //空簇记录到文件首簇号
            FAT32_ML_XGWJDX_XZ = 3; //切换到初始化更新文件簇链长度

        }
        else if(returnX == 3) //没有找到空白簇
        {
            returnX = FAT32_ML_WJCX(FAT32_ML_XGWJDX_DEVICE,FAT32_ML_XGWJDX_mulu_cuhao,FAT32_ML_XGWJDX_WJM,WJFDATA_32B,CWJM,0,1,0,0,0,0); //还原文件大小
            if(returnX == 1) returnX = 3; //没有找到空白簇,存储空间不够
        }

    }
    else if(FAT32_ML_XGWJDX_XZ == 3) //初始化更新文件簇链长度
    {

         FAT32_UP_culian(FAT32_ML_XGWJDX_WJ_cuhao,FAT32_ML_XGWJDX__WJDX,0); //初始化更新簇链长度
         FAT32_ML_XGWJDX_XZ = 4; //切换到运行更新簇链长度
         returnX = 1;

    }
    else if(FAT32_ML_XGWJDX_XZ == 4) //运行更新文件簇链长度
    {

         returnX = FAT32_UP_culian_RUN(FAT32_ML_XGWJDX_DEVICE); //运行更新簇链长度

         if(returnX == 3) //存储设备空间不足
         {
             returnX = FAT32_ML_WJCX(FAT32_ML_XGWJDX_DEVICE,FAT32_ML_XGWJDX_mulu_cuhao,FAT32_ML_XGWJDX_WJM,WJFDATA_32B,CWJM,0,1,FAT32_ML_XGWJDX_WJDX_,FAT32_ML_XGWJDX_WJKCBZ,0,0); //还原文件大小和簇号
             if(returnX == 1) returnX = 3; //存储设备空间不足
         }

    }
    else if(FAT32_ML_XGWJDX_XZ == 5) //完成
    {
         returnX = 2; //完成
    }


    if(returnX != 1) FAT32_ML_XGWJDX_XZ = 0; //结束

    return returnX;


}



