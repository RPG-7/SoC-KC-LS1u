unsigned char FAT32_csh(unsigned char device) //读取该设备的FAT32各参数, 如果操作成功返回值不为0, device选择SPI设备, 0为0号内存卡,1为1号内存卡
{

unsigned char buf[512],ZT;
unsigned int x;

//////////////////////////////提取引导扇区地址/////////////////////////////////////////////////////////////

    ZT = TF_SD_RD_512B(device,0x00000000,buf);   //读出0号扇区到缓冲区

///////////////////////提取簇大小、FAT表数量、FAT1表起始扇区号、FAT2表起始扇区号、数据区起始扇区号///////////

    if(ZT != 0) ZT = TF_SD_RD_512B(device,x = buf[0x01c7]*256 + buf[0x01c6],buf);   //读出引导扇区到缓冲区

    FAT32_cudx[device] = buf[0x000d];  //提取簇大小
    FAT32_FATsl[device] = buf[0x0010];  //提取FAT表数量

    FAT32_FAT1addr[device] = buf[0x000f]*256 + buf[0x000e] + x; //计算FAT表1号表的起始扇区号
    FAT32_FAT2addr[device] = buf[0x0025]*256 + buf[0x0024] + FAT32_FAT1addr[device]; //计算FAT表2号表的起始扇区号

    if(FAT32_FATsl[device] == 1) FAT32_DATAaddr[device] = FAT32_FAT2addr[device]; //计算FAT数据区的起始扇区号
    else FAT32_DATAaddr[device] = buf[0x0025]*256 + buf[0x0024] + FAT32_FAT2addr[device]; //计算FAT数据区的起始扇区号

    if(ZT != 0 && (buf[0x0052] != 'F' || buf[0x0053] != 'A' || buf[0x0054] != 'T' || buf[0x0055] != '3' || buf[0x0056] != '2')) ZT = 0; //不是"FAT32"时,返回错误值

    return ZT;

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
         if( TF_SD_RD_512B(device,(cuhao >> 7) + FAT32_FAT1addr[device],buf) == 0 ) return 0; //读出簇号所在扇区到缓冲区

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


   }while(x != 0 && _cuhao != 0x0fffffff);


  return 1;

}





unsigned char FAT32_wjcx_1(unsigned char device,unsigned int *wjlj,unsigned char *return_data) //FAT32文件查询1,device选择设备,wjlj为文件路径,以0作为路径结束符,return_data为返回的32个字节文件信息数据
{

unsigned int wjlj_smzz = 0; //文件路径扫描指针
unsigned int wjlj_cd; //文件路径字符总长度
unsigned char wjm_gsbz; //文件名格式标志 0为8字符3后缀名格式 1为长文件名格式
unsigned char wjm_8_3[12]; //记录短文件名,如果是短文件名,文件名格式标志为0
unsigned char wjm_hzm_x; //wjm_8_3的计数,记录wjm_8_3内的元素个数
unsigned char wjm_hzm_k; //文件名第1个"."标志,有第1个"."标志=1否则=0
unsigned int wjm_c[404]; //记录长文件名,如果是长文件名,文件名格式标志为1
unsigned int wjm_x; ////长文件名的计数,记录长文件名内的元素个数
unsigned char wjlj__bz; //文件路径"/"标志, 有"/"标志=1否则=0;
unsigned int _wjlj; //文件路径读出数据中间变量


unsigned char buf[512]; //缓冲区
unsigned long int culian[128]; //簇链
unsigned char culian_x; //簇指针,用来指簇链里面的簇号
unsigned long int sqh_; //簇的首扇区号
unsigned long int _sqh; //簇的尾扇区号+1
unsigned long int mulu_cuhao = 0x00000002; //目录簇号,起始为根目录
unsigned int wjm_smzz; //文件名段扫描指针

unsigned int js1; //计数1
unsigned char js2; //计数2
unsigned int js3; //计数3


js1 = 0;
while(((wjlj[js1] & 0x00ff) != 0x00 || wjlj[js1] >> 8 != 0x00) && js1 != 65535) ++js1;
wjlj_cd = js1;

    do
    {

          wjlj__bz = 0;
          wjm_gsbz = 0;
          wjm_hzm_k = 0;
          wjm_hzm_x = 0;
          wjm_x = 0;

          do
          {

               _wjlj = wjlj[wjlj_smzz];
               ++wjlj_smzz;

               if(_wjlj == '.')
               {

                  if(wjm_hzm_k == 0) //文件名没有第1个 '.' 时进入
                  {
                     wjm_hzm_k = 1; //标志有一个 '.'
                     while(wjm_hzm_x < 8) wjm_8_3[wjm_hzm_x] = ' ',++wjm_hzm_x; //短文件名称不够8字符就填空格
                  }
                  else
                  {
                     wjm_gsbz = 1; //标志为长文件名
                  }

                  wjm_c[wjm_x] = _wjlj;
                  ++wjm_x;

               }
               else if(_wjlj == '\')
               {
                  if(wjm_x == 0) return 0;
                  if(wjm_gsbz == 0) while(wjm_hzm_x < 11) wjm_8_3[wjm_hzm_x] = ' ',++wjm_hzm_x; //短文件名称不够11字符就填空格
                  wjlj__bz = 1;
                  break;
               }
               else if(_wjlj == ' ')
               {
                  wjm_gsbz = 1; //有空格,标志为长文件名
                  wjm_c[wjm_x] = _wjlj;
                  ++wjm_x;
               }
               else
               {

                  wjm_c[wjm_x] = _wjlj;
                  ++wjm_x;

                  if(_wjlj > 96 && _wjlj < 123) _wjlj -= 32; //为小写字母的时候转换成大写字母

                  if(wjm_gsbz == 0)
                  {

                     if(_wjlj < 256) //为1个字节时进入
                     {
                         wjm_8_3[wjm_hzm_x] = _wjlj;
                         ++wjm_hzm_x;
                     }
                     else //为2个字节时进入
                     {
                         wjm_8_3[wjm_hzm_x] = _wjlj >> 8;
                         ++wjm_hzm_x;
                         wjm_8_3[wjm_hzm_x] = _wjlj;
                         ++wjm_hzm_x;
                     }

                     if(wjm_hzm_k == 0 && wjm_hzm_x > 8 || wjm_hzm_k == 1 && wjm_hzm_x > 11) wjm_gsbz = 1; //超出8_3短文件名格式时标志为长文件名 BUG!!!应该为==号

                  }



               }

               if(wjm_x > 403) return 0; //长文件名的长度超过403个字符,返回0

          }while(wjlj_smzz < wjlj_cd);

          if(wjm_gsbz == 0) while(wjm_hzm_x < 11) wjm_8_3[wjm_hzm_x] = ' ',++wjm_hzm_x; //短文件名称不够11字符就填空格




          if(TF_SD_RD_512B(device,sqh_ = FAT32_cuhao_shanquhao(device,mulu_cuhao),buf) == 0) return 0; //读出需要扫描目录的首扇区到第0缓冲区
          _sqh = sqh_ + FAT32_cudx[device]; //记录目录首簇的尾扇区的下一扇区号
          ++sqh_; //指向下一个扇区

          if(FAT32_cuhao_culian(device,mulu_cuhao,128,culian) == 0) return 0; //读出目录首簇指向的下面128个簇放到簇链缓冲区
          culian_x = 0; //簇指针指向读出的首个簇



          if(wjm_gsbz == 0) //短文件名
          {

             wjm_smzz = 0;

               do
               {

                     if(buf[wjm_smzz] == 0xe5 || buf[wjm_smzz] == 0x2e)
                     {
                        wjm_smzz += 32; //指向下一段
                     }
                     else if(buf[wjm_smzz] == 0x00)
                     {
                        return 0;
                     }
                     else if(buf[wjm_smzz] == wjm_8_3[0] && buf[wjm_smzz+1] == wjm_8_3[1] && buf[wjm_smzz+2] == wjm_8_3[2] && buf[wjm_smzz+3] == wjm_8_3[3] && buf[wjm_smzz+4] == wjm_8_3[4] && buf[wjm_smzz+5] == wjm_8_3[5] && buf[wjm_smzz+6] == wjm_8_3[6] && buf[wjm_smzz+7] == wjm_8_3[7] && buf[wjm_smzz+8] == wjm_8_3[8] && buf[wjm_smzz+9] == wjm_8_3[9] && buf[wjm_smzz+10] == wjm_8_3[10])
                     {

                           js1 = 0;
                           while(js1 != 32) return_data[js1] = buf[wjm_smzz + js1],++js1;


                           if((buf[wjm_smzz+0x0b] & 0xf0) == 0x10) //这个文件是目录
                           {

                              if(wjlj__bz == 1 && wjlj_smzz < wjlj_cd) //文件路径"\"标志为1,并且文件路径没结束,读出这个目录的首簇号作为目录簇号,然后返回继续扫描文件路径
                              {
                                 mulu_cuhao = return_data[0x15];
                                 mulu_cuhao <<= 8;
                                 mulu_cuhao |= return_data[0x14];
                                 mulu_cuhao <<= 8;
                                 mulu_cuhao |= return_data[0x1b];
                                 mulu_cuhao <<= 8;
                                 mulu_cuhao |= return_data[0x1a];
                                 break;
                              }
                              else
                              {
                                 return 1;
                              }

                           }
                           else //这个文件是存档
                           {

                              if(wjlj__bz == 1) //文件路径"\"标志为1,说明查找的是目录,但这个文件不是目录返回0
                              {
                                 return 0;
                              }
                              else
                              {
                                 return 1;
                              }

                           }


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

                            if(culian[culian_x] == 0x0fffffff) return 0; //为簇结束标志时返回0

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

          
                         if(TF_SD_RD_512B(device,sqh_ ,buf) == 0) return 0; //读出一个扇区到缓冲区
                         ++sqh_; //指向下一个扇区

                     }


               }while(1);


          }
          else //长文件名
          {

              wjm_smzz = 0;

               do
               {

                     if(buf[wjm_smzz] == 0xe5 || buf[wjm_smzz] == 0x2e)
                     {
                        wjm_smzz += 32; //指向下一段
                     }
                     else if(buf[wjm_smzz] == 0x00)
                     {
                        return 0;
                     }
                     else if(buf[wjm_smzz+0x0b] == 0x0f && buf[wjm_smzz] < 0x60 && buf[wjm_smzz] > 0x40)
                     {

                        js1 = 3;
                        js2 = 1;
                        while(js1 != 32 && (buf[wjm_smzz + js1] != 0x00 || buf[wjm_smzz + js1 + 1] != 0x00))
                        {
                           if(js1 + 2 == 0x0b) js1 += 5;
                           else if(js1 + 2 == 0x1a) js1 += 4;
                           else js1 += 2;
                           ++js2;
                        }

                        if(((buf[wjm_smzz] & 0x1f) -1) * 13 + js2 == wjm_x) //比较文件名长度
                        {

                            js3 = wjm_x;

                            do
                            {

                                   do
                                   {
                                      if(js1 - 2 == 0x1a) js1 -= 4;
                                      else if(js1 - 2 == 0x0c) js1 -= 5;
                                      else js1 -= 2;
                                      --js3;

                                      js2 = buf[wjm_smzz + js1] == (wjm_c[js3] & 0x00ff) && buf[wjm_smzz + js1 + 1] == wjm_c[js3] >> 8   ||    buf[wjm_smzz + js1 + 1] == 0x00 && wjm_c[js3] >> 8 == 0x00    &&   ( buf[wjm_smzz + js1] > 96 && buf[wjm_smzz + js1] < 123 && buf[wjm_smzz + js1] - 32 == wjm_c[js3]   ||   buf[wjm_smzz + js1] > 64 && buf[wjm_smzz + js1] < 91 && buf[wjm_smzz + js1] + 32 == wjm_c[js3] ); //比较文件名,相同时赋值1,否则0

                                   }while(js2 == 1 && js1 != 1); //文件名相同并且没有到段首时继续扫


                                   if(js2 == 0) //文件名不相同时进入
                                   {
                                      wjm_smzz += 32;
                                      break;
                                   }

                                   js1 = 32;
                                   wjm_smzz += 32; //指向下一段



                                   if(wjm_smzz == 512)
                                   {

                                       wjm_smzz = 0;

                                       if(sqh_ == _sqh) //一个簇的扇区读完,进入换簇
                                       {

                                          if(culian[culian_x] == 0x0fffffff) return 0; //为簇结束标志时返回0

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

                                       if(TF_SD_RD_512B(device,sqh_ ,buf) == 0) return 0; //读出一个扇区到缓冲区
                                       ++sqh_; //指向下一个扇区

                                   }


                                   if(js3 == 0) //文件名全部比较完成,完全相同
                                   {

                                      js1 = 0;
                                      while(js1 != 32) return_data[js1] = buf[wjm_smzz + js1],++js1;


                                      if((buf[wjm_smzz+0x0b] & 0xf0) == 0x10) //这个文件是目录
                                      {

                                         if(wjlj__bz == 1 && wjlj_smzz < wjlj_cd)
                                         {
                                            mulu_cuhao = return_data[0x15];
                                            mulu_cuhao <<= 8;
                                            mulu_cuhao |= return_data[0x14];
                                            mulu_cuhao <<= 8;
                                            mulu_cuhao |= return_data[0x1b];
                                            mulu_cuhao <<= 8;
                                            mulu_cuhao |= return_data[0x1a];
                                            goto in_1;
                                         }
                                         else
                                         {
                                            return 1;
                                         }

                                      }
                                      else //这个文件是存档
                                      {

                                         if(wjlj__bz == 1) //文件路径"\"标志为1,说明查找的是目录,但这个文件不是目录返回0
                                         {
                                            return 0;
                                         }
                                         else
                                         {
                                            return 1;
                                         }

                                      }

                                   }



                            }while(1);


                        }
                        else //文件名长度不同
                        {
                           wjm_smzz += 32; //指向下一段
                        }


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

                            if(culian[culian_x] == 0x0fffffff) return 0; //为簇结束标志时返回0

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

          
                         if(TF_SD_RD_512B(device,sqh_ ,buf) == 0) return 0; //读出一个扇区到缓冲区
                         ++sqh_; //指向下一个扇区

                     }


               }while(1);


          }

     in_1:

    }while(1);


}



/*

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


            if(TF_SD_RD_512B(device,sqh_ = FAT32_cuhao_shanquhao(device,mulu_cuhao),buf) == 0) return 0; //读出需要扫描目录的首扇区到第0缓冲区
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
                     else if(buf[wjm_smzz+0x0b] & 0xf0) //短文件名
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

          
                         if(TF_SD_RD_512B(device,sqh_ ,buf) == 0) return 0; //读出一个扇区到缓冲区
                         ++sqh_; //指向下一个扇区

                     }


               }while(1);


}


*/





