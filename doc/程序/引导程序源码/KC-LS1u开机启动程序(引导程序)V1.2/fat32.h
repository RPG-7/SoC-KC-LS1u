unsigned char FAT32_csh(unsigned char device) //��ȡ���豸��FAT32������, ��������ɹ�����ֵ��Ϊ0, deviceѡ��SPI�豸, 0Ϊ0���ڴ濨,1Ϊ1���ڴ濨
{

unsigned char buf[512],ZT;
unsigned int x;

//////////////////////////////��ȡ����������ַ/////////////////////////////////////////////////////////////

    ZT = TF_SD_RD_512B(device,0x00000000,buf);   //����0��������������

///////////////////////��ȡ�ش�С��FAT��������FAT1����ʼ�����š�FAT2����ʼ�����š���������ʼ������///////////

    if(ZT != 0) ZT = TF_SD_RD_512B(device,x = buf[0x01c7]*256 + buf[0x01c6],buf);   //��������������������

    FAT32_cudx[device] = buf[0x000d];  //��ȡ�ش�С
    FAT32_FATsl[device] = buf[0x0010];  //��ȡFAT������

    FAT32_FAT1addr[device] = buf[0x000f]*256 + buf[0x000e] + x; //����FAT��1�ű����ʼ������
    FAT32_FAT2addr[device] = buf[0x0025]*256 + buf[0x0024] + FAT32_FAT1addr[device]; //����FAT��2�ű����ʼ������

    if(FAT32_FATsl[device] == 1) FAT32_DATAaddr[device] = FAT32_FAT2addr[device]; //����FAT����������ʼ������
    else FAT32_DATAaddr[device] = buf[0x0025]*256 + buf[0x0024] + FAT32_FAT2addr[device]; //����FAT����������ʼ������

    if(ZT != 0 && (buf[0x0052] != 'F' || buf[0x0053] != 'A' || buf[0x0054] != 'T' || buf[0x0055] != '3' || buf[0x0056] != '2')) ZT = 0; //����"FAT32"ʱ,���ش���ֵ

    return ZT;

}





unsigned long int FAT32_cuhao_shanquhao(unsigned char device,unsigned long int cuhao) //�غ�ת������, deviceѡ��SPI�豸, 0Ϊ0���ڴ濨,1Ϊ1���ڴ濨, cuhao�Ǵغ�
{
   return FAT32_cudx[device] * (cuhao - 2) + FAT32_DATAaddr[device];
}





unsigned char FAT32_cuhao_culian(unsigned char device,unsigned long int cuhao,unsigned char x,unsigned long int *culian) //���غ�,��������, deviceѡ��SPI�豸, 0Ϊ0���ڴ濨,1Ϊ1���ڴ濨, cuhao�Ǵغ�, x����Ҫ�Ӵ��������غŵ�����, culian�Ǵ�Ŷ����غŵ��ڴ��׵�ַ,�غ�Ϊ��˸�ʽ, ����ֵ��Ϊ0��ʾ�����ɹ�
{

unsigned char buf[512],*_buf;
unsigned long int _cuhao;


 goto in;

   do
   {

      if((_cuhao & 0xffffff80) == (cuhao & 0xffffff80)) //�غ�ָ����¸��غ���ͬһ������?
      {

         cuhao = _cuhao;

         _buf = buf + ((cuhao & 0x0000007f) << 2) + 3;       //�����غ�ָ�����һ���غ�

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
         if( TF_SD_RD_512B(device,(cuhao >> 7) + FAT32_FAT1addr[device],buf) == 0 ) return 0; //�����غ�����������������

         _buf = buf + ((cuhao & 0x0000007f) << 2) + 3;         //�����غ�ָ�����һ���غ�

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





unsigned char FAT32_wjcx_1(unsigned char device,unsigned int *wjlj,unsigned char *return_data) //FAT32�ļ���ѯ1,deviceѡ���豸,wjljΪ�ļ�·��,��0��Ϊ·��������,return_dataΪ���ص�32���ֽ��ļ���Ϣ����
{

unsigned int wjlj_smzz = 0; //�ļ�·��ɨ��ָ��
unsigned int wjlj_cd; //�ļ�·���ַ��ܳ���
unsigned char wjm_gsbz; //�ļ�����ʽ��־ 0Ϊ8�ַ�3��׺����ʽ 1Ϊ���ļ�����ʽ
unsigned char wjm_8_3[12]; //��¼���ļ���,����Ƕ��ļ���,�ļ�����ʽ��־Ϊ0
unsigned char wjm_hzm_x; //wjm_8_3�ļ���,��¼wjm_8_3�ڵ�Ԫ�ظ���
unsigned char wjm_hzm_k; //�ļ�����1��"."��־,�е�1��"."��־=1����=0
unsigned int wjm_c[404]; //��¼���ļ���,����ǳ��ļ���,�ļ�����ʽ��־Ϊ1
unsigned int wjm_x; ////���ļ����ļ���,��¼���ļ����ڵ�Ԫ�ظ���
unsigned char wjlj__bz; //�ļ�·��"/"��־, ��"/"��־=1����=0;
unsigned int _wjlj; //�ļ�·�����������м����


unsigned char buf[512]; //������
unsigned long int culian[128]; //����
unsigned char culian_x; //��ָ��,����ָ��������Ĵغ�
unsigned long int sqh_; //�ص���������
unsigned long int _sqh; //�ص�β������+1
unsigned long int mulu_cuhao = 0x00000002; //Ŀ¼�غ�,��ʼΪ��Ŀ¼
unsigned int wjm_smzz; //�ļ�����ɨ��ָ��

unsigned int js1; //����1
unsigned char js2; //����2
unsigned int js3; //����3


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

                  if(wjm_hzm_k == 0) //�ļ���û�е�1�� '.' ʱ����
                  {
                     wjm_hzm_k = 1; //��־��һ�� '.'
                     while(wjm_hzm_x < 8) wjm_8_3[wjm_hzm_x] = ' ',++wjm_hzm_x; //���ļ����Ʋ���8�ַ�����ո�
                  }
                  else
                  {
                     wjm_gsbz = 1; //��־Ϊ���ļ���
                  }

                  wjm_c[wjm_x] = _wjlj;
                  ++wjm_x;

               }
               else if(_wjlj == '\')
               {
                  if(wjm_x == 0) return 0;
                  if(wjm_gsbz == 0) while(wjm_hzm_x < 11) wjm_8_3[wjm_hzm_x] = ' ',++wjm_hzm_x; //���ļ����Ʋ���11�ַ�����ո�
                  wjlj__bz = 1;
                  break;
               }
               else if(_wjlj == ' ')
               {
                  wjm_gsbz = 1; //�пո�,��־Ϊ���ļ���
                  wjm_c[wjm_x] = _wjlj;
                  ++wjm_x;
               }
               else
               {

                  wjm_c[wjm_x] = _wjlj;
                  ++wjm_x;

                  if(_wjlj > 96 && _wjlj < 123) _wjlj -= 32; //ΪСд��ĸ��ʱ��ת���ɴ�д��ĸ

                  if(wjm_gsbz == 0)
                  {

                     if(_wjlj < 256) //Ϊ1���ֽ�ʱ����
                     {
                         wjm_8_3[wjm_hzm_x] = _wjlj;
                         ++wjm_hzm_x;
                     }
                     else //Ϊ2���ֽ�ʱ����
                     {
                         wjm_8_3[wjm_hzm_x] = _wjlj >> 8;
                         ++wjm_hzm_x;
                         wjm_8_3[wjm_hzm_x] = _wjlj;
                         ++wjm_hzm_x;
                     }

                     if(wjm_hzm_k == 0 && wjm_hzm_x > 8 || wjm_hzm_k == 1 && wjm_hzm_x > 11) wjm_gsbz = 1; //����8_3���ļ�����ʽʱ��־Ϊ���ļ��� BUG!!!Ӧ��Ϊ==��

                  }



               }

               if(wjm_x > 403) return 0; //���ļ����ĳ��ȳ���403���ַ�,����0

          }while(wjlj_smzz < wjlj_cd);

          if(wjm_gsbz == 0) while(wjm_hzm_x < 11) wjm_8_3[wjm_hzm_x] = ' ',++wjm_hzm_x; //���ļ����Ʋ���11�ַ�����ո�




          if(TF_SD_RD_512B(device,sqh_ = FAT32_cuhao_shanquhao(device,mulu_cuhao),buf) == 0) return 0; //������Ҫɨ��Ŀ¼������������0������
          _sqh = sqh_ + FAT32_cudx[device]; //��¼Ŀ¼�״ص�β��������һ������
          ++sqh_; //ָ����һ������

          if(FAT32_cuhao_culian(device,mulu_cuhao,128,culian) == 0) return 0; //����Ŀ¼�״�ָ�������128���طŵ�����������
          culian_x = 0; //��ָ��ָ��������׸���



          if(wjm_gsbz == 0) //���ļ���
          {

             wjm_smzz = 0;

               do
               {

                     if(buf[wjm_smzz] == 0xe5 || buf[wjm_smzz] == 0x2e)
                     {
                        wjm_smzz += 32; //ָ����һ��
                     }
                     else if(buf[wjm_smzz] == 0x00)
                     {
                        return 0;
                     }
                     else if(buf[wjm_smzz] == wjm_8_3[0] && buf[wjm_smzz+1] == wjm_8_3[1] && buf[wjm_smzz+2] == wjm_8_3[2] && buf[wjm_smzz+3] == wjm_8_3[3] && buf[wjm_smzz+4] == wjm_8_3[4] && buf[wjm_smzz+5] == wjm_8_3[5] && buf[wjm_smzz+6] == wjm_8_3[6] && buf[wjm_smzz+7] == wjm_8_3[7] && buf[wjm_smzz+8] == wjm_8_3[8] && buf[wjm_smzz+9] == wjm_8_3[9] && buf[wjm_smzz+10] == wjm_8_3[10])
                     {

                           js1 = 0;
                           while(js1 != 32) return_data[js1] = buf[wjm_smzz + js1],++js1;


                           if((buf[wjm_smzz+0x0b] & 0xf0) == 0x10) //����ļ���Ŀ¼
                           {

                              if(wjlj__bz == 1 && wjlj_smzz < wjlj_cd) //�ļ�·��"\"��־Ϊ1,�����ļ�·��û����,�������Ŀ¼���״غ���ΪĿ¼�غ�,Ȼ�󷵻ؼ���ɨ���ļ�·��
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
                           else //����ļ��Ǵ浵
                           {

                              if(wjlj__bz == 1) //�ļ�·��"\"��־Ϊ1,˵�����ҵ���Ŀ¼,������ļ�����Ŀ¼����0
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
                        wjm_smzz += 32; //ָ����һ��
                     }



                     if(wjm_smzz == 512)
                     {
                         wjm_smzz = 0;

                         if(sqh_ == _sqh) //һ���ص���������,���뻻��
                         {

                            if(culian[culian_x] == 0x0fffffff) return 0; //Ϊ�ؽ�����־ʱ����0

                            sqh_ = FAT32_cuhao_shanquhao(device,culian[culian_x]); //�غ�ת��������
                            _sqh = sqh_ + FAT32_cudx[device]; //��¼�ص�β��������һ������
             

                            if(culian_x == 127) //β��? ������´���
                            {
                               if(FAT32_cuhao_culian(device,culian[127],128,culian) == 0) return 0; //����β��ָ�������128���طŵ�����������
                               culian_x = 0; //��ָ��ָ��������׸���
                            }
                            else
                            {
                               ++culian_x; //ָ����һ���غ�
                            }

                         }

          
                         if(TF_SD_RD_512B(device,sqh_ ,buf) == 0) return 0; //����һ��������������
                         ++sqh_; //ָ����һ������

                     }


               }while(1);


          }
          else //���ļ���
          {

              wjm_smzz = 0;

               do
               {

                     if(buf[wjm_smzz] == 0xe5 || buf[wjm_smzz] == 0x2e)
                     {
                        wjm_smzz += 32; //ָ����һ��
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

                        if(((buf[wjm_smzz] & 0x1f) -1) * 13 + js2 == wjm_x) //�Ƚ��ļ�������
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

                                      js2 = buf[wjm_smzz + js1] == (wjm_c[js3] & 0x00ff) && buf[wjm_smzz + js1 + 1] == wjm_c[js3] >> 8   ||    buf[wjm_smzz + js1 + 1] == 0x00 && wjm_c[js3] >> 8 == 0x00    &&   ( buf[wjm_smzz + js1] > 96 && buf[wjm_smzz + js1] < 123 && buf[wjm_smzz + js1] - 32 == wjm_c[js3]   ||   buf[wjm_smzz + js1] > 64 && buf[wjm_smzz + js1] < 91 && buf[wjm_smzz + js1] + 32 == wjm_c[js3] ); //�Ƚ��ļ���,��ͬʱ��ֵ1,����0

                                   }while(js2 == 1 && js1 != 1); //�ļ�����ͬ����û�е�����ʱ����ɨ


                                   if(js2 == 0) //�ļ�������ͬʱ����
                                   {
                                      wjm_smzz += 32;
                                      break;
                                   }

                                   js1 = 32;
                                   wjm_smzz += 32; //ָ����һ��



                                   if(wjm_smzz == 512)
                                   {

                                       wjm_smzz = 0;

                                       if(sqh_ == _sqh) //һ���ص���������,���뻻��
                                       {

                                          if(culian[culian_x] == 0x0fffffff) return 0; //Ϊ�ؽ�����־ʱ����0

                                          sqh_ = FAT32_cuhao_shanquhao(device,culian[culian_x]); //�غ�ת��������
                                          _sqh = sqh_ + FAT32_cudx[device]; //��¼�ص�β��������һ������
             

                                          if(culian_x == 127) //β��? ������´���
                                          {
                                             if(FAT32_cuhao_culian(device,culian[127],128,culian) == 0) return 0; //����β��ָ�������128���طŵ�����������
                                             culian_x = 0; //��ָ��ָ��������׸���
                                          }
                                          else
                                          {
                                             ++culian_x; //ָ����һ���غ�
                                          }

                                       }

                                       if(TF_SD_RD_512B(device,sqh_ ,buf) == 0) return 0; //����һ��������������
                                       ++sqh_; //ָ����һ������

                                   }


                                   if(js3 == 0) //�ļ���ȫ���Ƚ����,��ȫ��ͬ
                                   {

                                      js1 = 0;
                                      while(js1 != 32) return_data[js1] = buf[wjm_smzz + js1],++js1;


                                      if((buf[wjm_smzz+0x0b] & 0xf0) == 0x10) //����ļ���Ŀ¼
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
                                      else //����ļ��Ǵ浵
                                      {

                                         if(wjlj__bz == 1) //�ļ�·��"\"��־Ϊ1,˵�����ҵ���Ŀ¼,������ļ�����Ŀ¼����0
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
                        else //�ļ������Ȳ�ͬ
                        {
                           wjm_smzz += 32; //ָ����һ��
                        }


                     }
                     else
                     {
                        wjm_smzz += 32; //ָ����һ��
                     }


                     if(wjm_smzz == 512)
                     {

                        wjm_smzz = 0;

                         if(sqh_ == _sqh) //һ���ص���������,���뻻��
                         {

                            if(culian[culian_x] == 0x0fffffff) return 0; //Ϊ�ؽ�����־ʱ����0

                            sqh_ = FAT32_cuhao_shanquhao(device,culian[culian_x]); //�غ�ת��������
                            _sqh = sqh_ + FAT32_cudx[device]; //��¼�ص�β��������һ������
             

                            if(culian_x == 127) //β��? ������´���
                            {
                               if(FAT32_cuhao_culian(device,culian[127],128,culian) == 0) return 0; //����β��ָ�������128���طŵ�����������
                               culian_x = 0; //��ָ��ָ��������׸���
                            }
                            else
                            {
                               ++culian_x; //ָ����һ���غ�
                            }

                         }

          
                         if(TF_SD_RD_512B(device,sqh_ ,buf) == 0) return 0; //����һ��������������
                         ++sqh_; //ָ����һ������

                     }


               }while(1);


          }

     in_1:

    }while(1);


}



/*

unsigned int FAT32_wjcx_2(unsigned char device,unsigned long int mulu_cuhao,unsigned int qs,unsigned int js,unsigned char *return_data) //FAT32�ļ���ѯ2,deviceѡ���豸,mulu_cuhaoΪĿ¼���״غ�,qsΪ���ļ���,jsΪ�����ļ���,return_dataΪ�����ļ���Ϣ����,��˳����32���ֽ�Ϊһ��,����ֵ��Ϊ0��ʾ�����ɹ�; ��Ҫȡ�����ļ�����ʱ,qs��js��return_data��0,���ô˺��������ļ�������; ��Ҫȷ���ļ�����ʱ,qs��return_data��0,js���ļ�����,���ô˺�������ֵΪС�ڵ���js
{

unsigned char buf[512]; //������
unsigned long int culian[128]; //����
unsigned char culian_x; //��ָ��,����ָ��������Ĵغ�
unsigned long int sqh_; //�ص���������
unsigned long int _sqh; //�ص�β������+1
unsigned int wjm_smzz; //�ļ�����ɨ��ָ��
unsigned int wjsl_x = 0; //�ļ���������

unsigned int js1; //����1


            if(TF_SD_RD_512B(device,sqh_ = FAT32_cuhao_shanquhao(device,mulu_cuhao),buf) == 0) return 0; //������Ҫɨ��Ŀ¼������������0������
            _sqh = sqh_ + FAT32_cudx[device]; //��¼Ŀ¼�״ص�β��������һ������
            ++sqh_; //ָ����һ������

            if(FAT32_cuhao_culian(device,mulu_cuhao,128,culian) == 0) return 0; //����Ŀ¼�״�ָ�������128���طŵ�����������
            culian_x = 0; //��ָ��ָ��������׸���


            wjm_smzz = 0;

               do
               {

                     if(buf[wjm_smzz] == 0xe5 || buf[wjm_smzz] == 0x2e)
                     {
                        wjm_smzz += 32; //ָ����һ��
                     }
                     else if(buf[wjm_smzz] == 0x00)
                     {
                        if(qs == 0)
                        {
                           return wjsl_x; //�����ļ�����
                        }
                        else
                        {
                           return 0; //����0
                        }
                     }
                     else if(buf[wjm_smzz+0x0b] & 0xf0) //���ļ���
                     {
                        ++wjsl_x; //�ļ���������+1

                        if(qs != 0 && wjsl_x >= qs)
                        {
                           js1 = wjm_smzz + 32;
                           while(wjm_smzz != js1) *return_data = buf[wjm_smzz],++wjm_smzz,++return_data;
                        }

                        if(wjsl_x == js) return wjsl_x;

                     }
                     else
                     {
                        wjm_smzz += 32; //ָ����һ��
                     }



                     if(wjm_smzz == 512)
                     {
                         wjm_smzz = 0;

                         if(sqh_ == _sqh) //һ���ص���������,���뻻��
                         {

                            if(culian[culian_x] == 0x0fffffff)
                            {
                               if(qs == 0)
                               {
                                  return wjsl_x; //Ϊ�ؽ�����־ʱ�����ļ�����
                               }
                               else
                               {
                                  return 0;
                               }
                            }

                            sqh_ = FAT32_cuhao_shanquhao(device,culian[culian_x]); //�غ�ת��������
                            _sqh = sqh_ + FAT32_cudx[device]; //��¼�ص�β��������һ������
             

                            if(culian_x == 127) //β��? ������´���
                            {
                               if(FAT32_cuhao_culian(device,culian[127],128,culian) == 0) return 0; //����β��ָ�������128���طŵ�����������
                               culian_x = 0; //��ָ��ָ��������׸���
                            }
                            else
                            {
                               ++culian_x; //ָ����һ���غ�
                            }

                         }

          
                         if(TF_SD_RD_512B(device,sqh_ ,buf) == 0) return 0; //����һ��������������
                         ++sqh_; //ָ����һ������

                     }


               }while(1);


}


*/





