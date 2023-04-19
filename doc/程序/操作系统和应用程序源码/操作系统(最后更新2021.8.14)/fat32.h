/*-------------------------------------------------- FAT32�ļ�ϵͳ�洢���ӿ� --------------------------------------------------*/


unsigned char DEVICE_RD_512B(unsigned char device,unsigned long int SQH,unsigned char *buf)  //�豸��512�ֽ�,deviceѡ���豸,SQHΪ������,buf������,����ֵ��Ϊ0��ʾ�����ɹ�
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

unsigned char DEVICE_WR_512B(unsigned char device,unsigned long int SQH,unsigned char *buf)  //�豸д512�ֽ�,deviceѡ���豸,SQHΪ������,buf������,����ֵ��Ϊ0��ʾ�����ɹ�
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

unsigned long int DEVICE_GET_LBAX(unsigned char device) //ȡ�豸������,��λ��������
{

        if((device & 0xfe) == 0x00) return TF_SD_LBAX[device];
   else if(device > 1 && device < 6) return CH375_LBAX[device - 2];
   else return 0;

}

/*-------------------------------------------------------------------------------------------------------------------------------*/



/*-------------------------------------------------- FAT32�ļ�ϵͳʵʱʱ�ӽӿ� --------------------------------------------------*/

unsigned char FAT32_RTC_SEC() //��ȡ�� ,����8λ2����
{

unsigned char i;

    i = DS1302_RD(0) & 0x7f; //����BCD��
    return ((i & 0xf0) >> 1) + ((i & 0xf0) >> 3) + (i & 0x0f);
}

unsigned char FAT32_RTC_MIN() //��ȡ���� ,����8λ2����
{

unsigned char i;

    i = DS1302_RD(1); //����BCD��
    return ((i & 0xf0) >> 1) + ((i & 0xf0) >> 3) + (i & 0x0f);
}

unsigned char FAT32_RTC_HR() //��ȡСʱ ,����8λ2����
{

unsigned char i;

    i = DS1302_RD(2) & 0x7f; //����BCD��
    return ((i & 0xf0) >> 1) + ((i & 0xf0) >> 3) + (i & 0x0f);
}

unsigned char FAT32_RTC_DATE() //��ȡ���� ,����8λ2����
{

unsigned char i;

    i = DS1302_RD(3); //����BCD��
    return ((i & 0xf0) >> 1) + ((i & 0xf0) >> 3) + (i & 0x0f);
}

unsigned char FAT32_RTC_MONTH() //��ȡ�·� ,����8λ2����
{

unsigned char i;

    i = DS1302_RD(4); //����BCD��
    return ((i & 0xf0) >> 1) + ((i & 0xf0) >> 3) + (i & 0x0f);
}

unsigned char FAT32_RTC_YEAR() //��ȡ�� ,0~99,����8λ2����
{

unsigned char i;

    i = DS1302_RD(6); //����BCD��
    return ((i & 0xf0) >> 1) + ((i & 0xf0) >> 3) + (i & 0x0f);
}

/*-------------------------------------------------------------------------------------------------------------------------------*/






void FAT32_WJF_32B_UPRTC(unsigned char *WJF_32B,unsigned char UPX) //�����ļ�ʱ����Ϣ,WJF_32BΪ32���ֽ��ļ�����ʼ��ַ,UPXλ2Ϊ1�����ļ�����ʱ�������,λ1Ϊ1�����ļ�����������,λ0Ϊ1�����ļ�����޸�ʱ�������
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


   if((UPX & 0x04) == 0x04) //�����ļ�����ʱ�������
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

   if((UPX & 0x02) == 0x02) //�����ļ�����������
   {
      _addr = &WJF_32B[0x12];

      *_addr = RQ;
      ++_addr;
      *_addr = RQ >> 8;
   }

   if((UPX & 0x01) == 0x01) //�����ļ�����޸�ʱ�������
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




unsigned char FAT32_csh(unsigned char device) //��ʼ�����豸��FAT32�ļ�ϵͳ�Ͷ�ȡ���豸��FAT32������, ��������ɹ�����ֵ��Ϊ0, deviceѡ��SPI�豸, 0Ϊ0���ڴ濨,1Ϊ1���ڴ濨
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
        while(*buf != FAT32_RWWJ_WJX) FAT32_RWWJ_bz[device*FAT32_RWWJ_WJX + *buf] = 0,++*buf;  //��0���豸�������ļ���־
    }

//////////////////////////////��ȡ����������ַ/////////////////////////////////////////////////////////////

    FAT32_BZ[device] = 1; //������Ϊ1,���Զ��豸

    if(DEVICE_RD_512B(device,0,buf) == 0) //����0��������������,��ʧ�ܽ��봦��
    {
        FAT32_BZ[device] = 0;
        return 0;
    }

///////////////////////��ȡ�ش�С��FAT��������FAT1����ʼ�����š�FAT2����ʼ�����š���������ʼ������///////////

    if((x = buf[0x01c7]*256 + buf[0x01c6]) > 255) x = buf[0x01f7]*256 + buf[0x01f6];

    if(DEVICE_RD_512B(device,x,buf) == 0)  //��������������������,��ʧ�ܽ��봦��
    {
        FAT32_BZ[device] = 0;
        return 0;
    }


    FAT32_cudx[device] = buf[0x000d];  //��ȡ�ش�С(������)
    cudx_B = buf[0x000d];
    FAT32_cudx_B[device] = cudx_B << 9; //��512����ش�С(�ֽ�)
    FAT32_FATsl[device] = buf[0x0010];  //��ȡFAT������
    FATDX = buf[0x0025]*256 + buf[0x0024]; //��ȡFAT���С
    FAT32_FATDX[device] = FATDX; //��¼FAT���С

    FAT1addr = buf[0x000f]*256 + buf[0x000e] + x; //����FAT��1�ű����ʼ������
    FAT2addr = FATDX + FAT1addr; //����FAT��2�ű����ʼ������

    FAT32_FAT1addr[device] = FAT1addr;
    FAT32_FAT2addr[device] = FAT2addr;

    if(FAT32_FATsl[device] == 1) DATAaddr = FAT2addr; //����FAT����������ʼ������
    else DATAaddr = FATDX + FAT2addr; //����FAT����������ʼ������

    FAT32_DATAaddr[device] = DATAaddr;

    if(buf[0x0052] != 'F' || buf[0x0053] != 'A' || buf[0x0054] != 'T' || buf[0x0055] != '3' || buf[0x0056] != '2') //����"FAT32"ʱ,����0
    {
        FAT32_BZ[device] = 0;
        return 0;
    }

    _cuhao = (DEVICE_GET_LBAX(device) - DATAaddr) / buf[0x000d] + 1; //����洢�����һ���صĴغ�

    FAT32__cuhao[device] = _cuhao;

    FAT32__cuhao_LBAPY[device] = (_cuhao & 0x0000007f) << 2; //����洢�����һ��������Ӧ�Ĵغ��������ڵ�ƫ��



    if(FAT1addr + ((_cuhao) >> 7) == FAT2addr - 1) return 1; //FAT��û�д���ʱ����



    FAT32_BZ[device] = 0;
    return 0;


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
         if( DEVICE_RD_512B(device,(cuhao >> 7) + FAT32_FAT1addr[device],buf) == 0 ) return 0; //�����غ�����������������

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


   }while(x != 0 && _cuhao != 0x0fffffff && _cuhao != 0x00000000);


  return 1;

}


/*

unsigned char FAT32_SETUP_culian(unsigned char device,unsigned long int cuhao_,unsigned long int CLX,unsigned char fatx) //���״غ�,��������, deviceѡ��SPI�豸, 0Ϊ0���ڴ濨,1Ϊ1���ڴ濨, cuhao���״غ�, CLX�Ǵ���������, fatxѡ��FAT��,0ΪFAT1,����ֵΪFAT2, ����ֵ��Ϊ0��ʾ�����ɹ�
{

unsigned char buf[512]; //��ǰɨ�軺����
unsigned long int sqh_; //��¼�״غ�����������
unsigned long int _sqh_; //��¼��ָ�غ�����������
unsigned long int _sqh; //��¼ɨ��������
unsigned long int cuhao_js1; //��¼�����غ�����
unsigned int cuhao_smzz; //�غ�ɨ��ָ��
unsigned int py1; //��¼��ָ�غ��������ڵ�ƫ��
unsigned long int FAT_; //��¼FAT����������
unsigned long int _FAT; //��¼FAT��β������+1
unsigned char buf_bz; //��־��ǰɨ�軺�����Ƿ����޸�,���޸���1
//unsigned long int py2; //��¼�洢�����һ������+1��Ӧ�Ĵغ��������ڵ�ƫ��

unsigned char buf_[512]; //��ʱ������(�ֲ�)
unsigned long int js1; //����1,��¼�հ״صĴغ�(�ֲ�)


    if(fatx == 0) FAT_ = FAT32_FAT1addr[device],_FAT = FAT32_FAT2addr[device];
    else FAT_ = FAT32_FAT2addr[device],_FAT = FAT32_DATAaddr[device];
     
//    py2 = (FAT32__cuhao[device] & 0x0000007f) << 2; //����洢�����һ������+1��Ӧ�Ĵغ��������ڵ�ƫ��


    sqh_ = (cuhao_ >> 7) + FAT_; //�����״غ�����������
    _sqh = sqh_; //ֵͬ
    _sqh_ = sqh_; //��¼��ָ�غ�����������
    py1 = (cuhao_ & 0x0000007f) << 2; //��¼��ָ�غ����������ڵ�ƫ��

    if(DEVICE_RD_512B(device,sqh_,buf) == 0) return 0; //�����״غ�����������������

    buf[py1] = 0xff; //�״غ�λ�ñ�������,���䲻Ϊ�հ״�

    buf_bz = 0; //��־��ǰɨ�軺����û���޸�
    cuhao_smzz = 0; //�غ�ɨ��ָ��ָ����������״�
    cuhao_js1 = 0; //�����غ�����������0

    while(cuhao_js1 != CLX)
    {

       while( cuhao_smzz != 512  &&  ( buf[cuhao_smzz] != 0x00 || buf[cuhao_smzz + 1] != 0x00 || buf[cuhao_smzz + 2] != 0x00 || buf[cuhao_smzz + 3] != 0x00 ) ) cuhao_smzz += 4; //ɨ��հ״�

       if(cuhao_smzz == 512 || _sqh + 1 == _FAT && cuhao_smzz == FAT32__cuhao_LBAPY[device] + 4) //û���ҵ��հ״�
       {

          if(buf_bz == 1) //��ǰɨ�軺�������޸�,����
          {
             buf[py1] = 0xff;    //��ָ�غ����ϴؽ�����־0x0fffffff
             buf[py1+1] = 0xff;
             buf[py1+2] = 0xff;
             buf[py1+3] = 0x0f;

             if(DEVICE_WR_512B(device,_sqh,buf) == 0) return 0; //����������

             buf_bz = 0; //��־��0
          }

          ++_sqh; //ָ���¸�ɨ��������
          if(_sqh == _FAT) _sqh = FAT_; //����¸�ɨ�������ų���FAT��Χ,�ع�FAT���ײ�
          if(_sqh == sqh_) return 0; //FATת��һȦ,û�ҵ��հ״�,���ش���ֵ
          if(DEVICE_RD_512B(device,_sqh,buf) == 0) return 0; //�����¸�ɨ��������������
          cuhao_smzz = 0; //�غ�ɨ��ָ��ָ����������״�

       }
       else //�ҵ��հ״�
       {

          buf_bz = 1; //��־��ǰɨ�軺�������޸�

          js1 = ((_sqh - FAT_) << 7) + (cuhao_smzz >> 2); //����հ״صĴغ�

          if(_sqh_ == _sqh)  //��ָ�غ����������͵�ǰ�հ״���������һ��
          {

             buf[py1] = js1;          //�޸Ĵ�ָ�غ�ָ������հ״�
             buf[py1+1] = js1 >> 8;
             buf[py1+2] = js1 >> 16;
             buf[py1+3] = js1 >> 24;

          }
          else  //��ָ�غ����������͵�ǰ������һ��
          {

             if(DEVICE_RD_512B(device,_sqh_,buf_) == 0) return 0; //������ָ�غ��������������û�����

             buf_[py1] = js1;          //�޸Ĵ�ָ�غ�ָ������հ״�
             buf_[py1+1] = js1 >> 8;
             buf_[py1+2] = js1 >> 16;
             buf_[py1+3] = js1 >> 24;

             if(DEVICE_WR_512B(device,_sqh_,buf_) == 0) return 0; //���û���������

             _sqh_ = _sqh; //��ָ�غ���������ָ��ǰ�հ״���������

          }


          py1 = cuhao_smzz; //��¼��ָ�غ����������ڵ�ƫ��ָ������հ״�

          cuhao_smzz += 4; //�غ�ɨ��ָ��ָ���¸���

          ++cuhao_js1; //�����غ�����+1

       }
    }


    buf[py1] = 0xff;    //��ָ�غ����ϴؽ�����־0x0fffffff
    buf[py1+1] = 0xff;
    buf[py1+2] = 0xff;
    buf[py1+3] = 0x0f;

    if(DEVICE_WR_512B(device,_sqh,buf) == 0) return 0; //����������


    return 1;

}

*/


unsigned char FAT32_SETUP_culian(unsigned char device,unsigned long int cuhao_,unsigned long int CLX,unsigned char fatx) //���״غ�,��������, deviceѡ��SPI�豸, 0Ϊ0���ڴ濨,1Ϊ1���ڴ濨, cuhao_���״غ�, CLX�Ǵ���������, fatxѡ��FAT��,0ΪFAT1,1ΪFAT2,3ΪFAT1��FAT2, ����ֵ��Ϊ0��ʾ�����ɹ�
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


    sqh_ = (cuhao_ >> 7) + FAT_; //�����״غ�����������
    FAT32_SETUP_culian_sqh_[device] = sqh_; //ֵͬ
    FAT32_SETUP_culian__sqh[device] = sqh_; //ֵͬ
    FAT32_SETUP_culian__sqh_[device] = sqh_; //��¼��ָ�غ�����������

    py1 = (cuhao_ & 0x0000007f) << 2; //����غ����������ڵ�ƫ��
    FAT32_SETUP_culian_py1[device] = py1; //��¼��ָ�غ����������ڵ�ƫ��


    if(DEVICE_RD_512B(device,sqh_,buf) == 0) return 0; //�����״غ�����������������

    _buf = buf + py1;    //�״غű���0x0fffffff

    *_buf = 0xff;
    ++_buf;
    *_buf = 0xff;
    ++_buf;
    *_buf = 0xff;
    ++_buf;
    *_buf = 0x0f;

    if(DEVICE_WR_512B(device,sqh_,buf) == 0) return 0; //����������

    if(fatx == 3)
    {
       if(DEVICE_WR_512B(device,sqh_ - FAT32_FATDX[device],buf) == 0) return 0; //����������(дFAT1)
    }

    FAT32_SETUP_DELETE_fatx = fatx; //��¼fat��ѡ��
    FAT32_SETUP_culian_cuhao_js1[device] = 0; //�Ѵ����غ�����������0
    FAT32_SETUP_culian_CLX[device] = CLX; //��¼�봴��������

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



    sqh_ = FAT32_SETUP_culian_sqh_[device];           //�����״غ�����������
    _sqh_ = FAT32_SETUP_culian__sqh_[device];         //������ָ�غ�����������
    _sqh = FAT32_SETUP_culian__sqh[device];           //������ǰɨ���������
    FAT_ = FAT32_SETUP_culian_FAT_[device];           //����FAT����������
    _FAT = FAT32_SETUP_culian__FAT[device];           //����FAT��β������+1
    py1 = FAT32_SETUP_culian_py1[device];             //������ָ�غ����������ڵ�ƫ��
    cuhao_js1 = FAT32_SETUP_culian_cuhao_js1[device]; //�����Ѵ����غ�����
    CLX = FAT32_SETUP_culian_CLX[device];             //�����봴��������

    if(DEVICE_RD_512B(device,FAT32_SETUP_culian__sqh[device],buf) == 0) return 0; //������Ҫɨ���������������



    buf_bz = 0;
    smzz = 0;

    while(1)
    {



        if(smzz == 512 || _sqh + 1 == _FAT && smzz == FAT32__cuhao_LBAPY[device] + 4 || cuhao_js1 == CLX)
        {

            if(buf_bz == 1) //��ǰɨ�軺�����пհ״�,����
            {
                _buf = buf + py1;    //��ָ�غ����ϴؽ�����־0x0fffffff
                *_buf = 0xff;
                ++_buf;
                *_buf = 0xff;
                ++_buf;
                *_buf = 0xff;
                ++_buf;
                *_buf = 0x0f;

               if(DEVICE_WR_512B(device,_sqh,buf) == 0) return 0; //����������

               if(FAT32_SETUP_DELETE_fatx == 3)
               {
                   if(DEVICE_WR_512B(device,_sqh - FAT32_FATDX[device],buf) == 0) return 0; //����������(дFAT1)
               }

            }

            if(cuhao_js1 == CLX) return 2;


            ++_sqh; //ָ���¸�ɨ��������
            if(_sqh == _FAT) _sqh = FAT_; //����¸�ɨ�������ų���FAT��Χ,�ع�FAT���ײ�
            if(_sqh == sqh_) return 3;    //FAT��ת��һȦ,û�ҵ��հ״�,���ش���ֵ

            FAT32_SETUP_culian__sqh_[device] = _sqh_;            //�ش�ؼ�����
            FAT32_SETUP_culian__sqh[device] = _sqh;
            FAT32_SETUP_culian_py1[device] = py1;
            FAT32_SETUP_culian_cuhao_js1[device] = cuhao_js1;

            return 1;

        }
        else if(buf[smzz] == 0x00 && buf[smzz+1] == 0x00 && buf[smzz+2] == 0x00 && buf[smzz+3] == 0x00) //�ҵ��հ״�
        {

            buf_bz = 1; //�пհ״�

            js1 = ((_sqh - FAT_) << 7) + (smzz >> 2); //����հ״صĴغ�


            if(_sqh_ == _sqh)  //��ָ�غ����������͵�ǰ�հ״���������һ��
            {

                _buf = buf + py1;    //�޸Ĵ�ָ�غ�ָ������հ״�
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

                if(DEVICE_RD_512B(device,_sqh_,buf_) == 0) return 0; //������ָ�غ��������������û�����

                _buf = buf_ + py1;    //�޸Ĵ�ָ�غ�ָ������հ״�
                *_buf = js1;
                ++_buf;
                *_buf = js1 >> 8;
                ++_buf;
                *_buf = js1 >> 16;
                ++_buf;
                *_buf = js1 >> 24;

                if(DEVICE_WR_512B(device,_sqh_,buf_) == 0) return 0; //���û���������

                if(FAT32_SETUP_DELETE_fatx == 3)
                {
                    if(DEVICE_WR_512B(device,_sqh_ - FAT32_FATDX[device],buf_) == 0) return 0; //���û���������(дFAT1)
                }

                _sqh_ = _sqh; //��ָ�غ���������ָ��ǰ�հ״���������

            }

            py1 = smzz; //��¼��ָ�غ����������ڵ�ƫ��ָ������հ״�

            smzz += 4; //ָ���¸��غ�

            ++cuhao_js1; //�Ѵ����غ�����+1

        }
        else smzz += 4; //ָ���¸��غ�


    }



}



/*

unsigned char FAT32_DELETE_culian(unsigned char device,unsigned long int cuhao_,unsigned char cuhao__dc,unsigned char fatx) //���״غ�,ɾ������, deviceѡ��SPI�豸, 0Ϊ0���ڴ濨,1Ϊ1���ڴ濨,cuhao_���״غ�,cuhao__dcΪ0�״غ���0x00000000,Ϊ����ֵ�״غ���0x0fffffff,fatxѡ��FAT��,0ΪFAT1,����ֵΪFAT2 ����ֵ��Ϊ0��ʾ�����ɹ�
{

unsigned char buf[512]; //������
unsigned long int FAT_; //��¼FAT����������
unsigned long int _cuhao; //��¼��һ��Ҫɾ���Ĵغ�
unsigned char *_buf;



    if(fatx == 0) FAT_ = FAT32_FAT1addr[device];
    else FAT_ = FAT32_FAT2addr[device];



    if(DEVICE_RD_512B(device,(cuhao_ >> 7) + FAT_,buf) == 0) return 0; //�����״غ�����������������


    _buf = buf + ((cuhao_ & 0x0000007f) << 2) + 3; //�����״غ�ָ���¸��غŵ����8λ��������ַ

    _cuhao = *_buf;       //��¼�״غ�ָ����¸��غ�
    _cuhao <<= 8;--_buf;
    _cuhao |= *_buf;
    _cuhao <<= 8;--_buf;
    _cuhao |= *_buf;
    _cuhao <<= 8;--_buf;
    _cuhao |= *_buf;

    if(cuhao__dc != 0) //�״غ���0x0fffffff
    {
       *_buf = 0xff; ++_buf;
       *_buf = 0xff; ++_buf;
       *_buf = 0xff; ++_buf;
       *_buf = 0x0f;
    }
    else //�״غ���0x00000000
    {
       *_buf = 0x00; ++_buf;
       *_buf = 0x00; ++_buf;
       *_buf = 0x00; ++_buf;
       *_buf = 0x00;
    }


   while(_cuhao != 0x0fffffff && _cuhao != 0x00000000)
   {

      if((_cuhao & 0xffffff80) == (cuhao_ & 0xffffff80)) //�غ�ָ����¸��غ���ͬһ������?
      {

         cuhao_ = _cuhao;

         _buf = buf + ((cuhao_ & 0x0000007f) << 2) + 3;   //�����غ�ָ�����һ���غ�

         _cuhao = *_buf;
         _cuhao <<= 8;--_buf;
         _cuhao |= *_buf;
         _cuhao <<= 8;--_buf;
         _cuhao |= *_buf;
         _cuhao <<= 8;--_buf;
         _cuhao |= *_buf;

         *_buf = 0x00; ++_buf;     //�غ���0
         *_buf = 0x00; ++_buf;
         *_buf = 0x00; ++_buf;
         *_buf = 0x00;

      }
      else
      {

         if( DEVICE_WR_512B(device,(cuhao_ >> 7) + FAT_,buf) == 0 ) return 0; //����������

         cuhao_ = _cuhao;

         if( DEVICE_RD_512B(device,(cuhao_ >> 7) + FAT_,buf) == 0 ) return 0; //�����غ�����������������

         _buf = buf + ((cuhao_ & 0x0000007f) << 2) + 3;   //�����غ�ָ�����һ���غ�

         _cuhao = *_buf;
         _cuhao <<= 8;--_buf;
         _cuhao |= *_buf;
         _cuhao <<= 8;--_buf;
         _cuhao |= *_buf;
         _cuhao <<= 8;--_buf;
         _cuhao |= *_buf;

         *_buf = 0x00; ++_buf;     //�غ���0
         *_buf = 0x00; ++_buf;
         *_buf = 0x00; ++_buf;
         *_buf = 0x00;

      }


   }


   if( DEVICE_WR_512B(device,(cuhao_ >> 7) + FAT_,buf) == 0 ) return 0; //����������

   return 1;


}
*/



unsigned char FAT32_DELETE_culian(unsigned char device,unsigned long int cuhao_,unsigned char cuhao__dc,unsigned char fatx) //���״غ�,ɾ������, deviceѡ��SPI�豸, 0Ϊ0���ڴ濨,1Ϊ1���ڴ濨,cuhao_���״غ�,cuhao__dcΪ0�״غ���0x00000000,Ϊ����ֵ�״غ���0x0fffffff,fatxѡ��FAT��,0ΪFAT1,����ֵΪFAT2 ����ֵ��Ϊ0��ʾ�����ɹ�
{

unsigned char buf[512]; //������
unsigned long int FAT_; //��¼FAT����������
unsigned long int _cuhao; //��¼��һ��Ҫɾ���Ĵغ�
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

    sqh_ = (cuhao_ >> 7) + FAT_; //�����״غ�����������

    if(DEVICE_RD_512B(device,sqh_,buf) == 0) return 0; //�����״غ�����������������


    _buf = buf + ((cuhao_ & 0x0000007f) << 2) + 3; //�����״غ�ָ���¸��غŵ����8λ��������ַ

    _cuhao = *_buf;       //��¼�״غ�ָ����¸��غ�
    _cuhao <<= 8;--_buf;
    _cuhao |= *_buf;
    _cuhao <<= 8;--_buf;
    _cuhao |= *_buf;
    _cuhao <<= 8;--_buf;
    _cuhao |= *_buf;

    if(cuhao__dc != 0) //�״غ���0x0fffffff
    {
       *_buf = 0xff; ++_buf;
       *_buf = 0xff; ++_buf;
       *_buf = 0xff; ++_buf;
       *_buf = 0x0f;
    }
    else //�״غ���0x00000000
    {
       *_buf = 0x00; ++_buf;
       *_buf = 0x00; ++_buf;
       *_buf = 0x00; ++_buf;
       *_buf = 0x00;
    }


    if(DEVICE_WR_512B(device,sqh_,buf) == 0) return 0; //����������

    if(fatx == 3)
    {
        if(DEVICE_WR_512B(device,sqh_ - FAT32_FATDX[device],buf) == 0) return 0; //����������(дFAT1)
    }

    FAT32_SETUP_DELETE_fatx = fatx; //��¼fat��ѡ��
    FAT32_DELETE_culian__cuhao[device] = _cuhao; //��¼�غ�ָ����¸��غ�

    return 1;

}



unsigned char FAT32_DELETE_culian_RUN(unsigned char device) //���״غ�,ɾ������, deviceѡ��SPI�豸, 0Ϊ0���ڴ濨,1Ϊ1���ڴ濨,cuhao_���״غ�,cuhao__dcΪ0�״غ���0x00000000,Ϊ����ֵ�״غ���0x0fffffff,fatxѡ��FAT��,0ΪFAT1,����ֵΪFAT2 ����ֵ��Ϊ0��ʾ�����ɹ�
{

unsigned char buf[512]; //������
unsigned long int FAT_; //��¼FAT����������
unsigned long int _cuhao; //��¼��һ��Ҫɾ���Ĵغ�
unsigned char *_buf;
unsigned long int sqh_;
unsigned long int cuhao_;


    FAT_ = FAT32_DELETE_culian_FAT_[device];      //����FAT����������
    _cuhao = FAT32_DELETE_culian__cuhao[device];  //������һ��Ҫɾ���Ĵغ�

    if(_cuhao == 0x0fffffff || _cuhao == 0x00000000) goto out;
    cuhao_ = _cuhao;


    sqh_ = (_cuhao >> 7) + FAT_; //����غ�����������

    if(DEVICE_RD_512B(device,sqh_,buf) == 0) return 0; //�����غ�����������������


    while(1)
    {


        if(_cuhao == 0x0fffffff || _cuhao == 0x00000000)
        {

            if(DEVICE_WR_512B(device,(cuhao_ >> 7) + FAT_,buf) == 0) return 0; //����������

            if(FAT32_SETUP_DELETE_fatx == 3)
            {
                if(DEVICE_WR_512B(device,(cuhao_ >> 7) + FAT_ - FAT32_FATDX[device],buf) == 0) return 0; //����������(дFAT1)
            }
     out:
            return 2;

        }
        else if((_cuhao & 0xffffff80) == (cuhao_ & 0xffffff80)) //�غ�ָ����¸��غ���ͬһ����
        {

            cuhao_ = _cuhao;

            _buf = buf + ((cuhao_ & 0x0000007f) << 2) + 3;   //�����غ�ָ�����һ���غ�

            _cuhao = *_buf;
            _cuhao <<= 8;--_buf;
            _cuhao |= *_buf;
            _cuhao <<= 8;--_buf;
            _cuhao |= *_buf;
            _cuhao <<= 8;--_buf;
            _cuhao |= *_buf;

            *_buf = 0x00; ++_buf;     //�غ���0
            *_buf = 0x00; ++_buf;
            *_buf = 0x00; ++_buf;
            *_buf = 0x00;

        }
        else //�غ�ָ����¸��غŲ���ͬһ����
        {

            if(DEVICE_WR_512B(device,(cuhao_ >> 7) + FAT_,buf) == 0) return 0; //����������

            if(FAT32_SETUP_DELETE_fatx == 3)
            {
                if(DEVICE_WR_512B(device,(cuhao_ >> 7) + FAT_ - FAT32_FATDX[device],buf) == 0) return 0; //����������(дFAT1)
            }

            FAT32_DELETE_culian__cuhao[device] = _cuhao; //�ش�غ�ָ����¸��غ�

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

     if(_cuhao == 0x0fffffff || _cuhao == 0x00000000) return 2; //Ϊ�ؽ�����־��ϴ�,���봦��

     _sqh_ = FAT32_cuhao_shanquhao(device,_cuhao); //�غ�ת��������
     *sqh_ = _sqh_;
     *_sqh = _sqh_ + FAT32_cudx[device]; //��¼�ص�β��������һ������

     if(_culianX == culianDX - 1) //β��? ������´���
     {
         if(FAT32_cuhao_culian(device,_cuhao,culianDX,culian) == 0) return 0; //����β��ָ�������culianDX���طŵ�����������,�������,���봦��
         *culianX = 0; //��ָ��ָ���״�
     }
     else
     {
         ++*culianX; //ָ����һ���غ�
     }

     return 1;

}


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


            if(DEVICE_RD_512B(device,sqh_ = FAT32_cuhao_shanquhao(device,mulu_cuhao),buf) == 0) return 0; //������Ҫɨ��Ŀ¼������������0������
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
                     else if((buf[wjm_smzz+0x0b] & 0xf0) != 0x00) //���ļ���
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

          
                         if(DEVICE_RD_512B(device,sqh_ ,buf) == 0) return 0; //����һ��������������
                         ++sqh_; //ָ����һ������

                     }


               }while(1);


}


unsigned int FAT32_ML_WJCX1(unsigned char device,unsigned long int mulu_cuhao,unsigned int qs,unsigned int js,unsigned char *return_data) //FAT32�ļ���ѯ2,deviceѡ���豸,mulu_cuhaoΪĿ¼���״غ�,qsΪ���ļ���,jsΪ�����ļ���,return_dataΪ�����ļ���Ϣ����,��˳����32���ֽ�Ϊһ��,����ֵ��Ϊ0��ʾ�����ɹ�; ��Ҫȡ�����ļ�����ʱ,qs��js��return_data��0,���ô˺��������ļ�������; ��Ҫȷ���ļ�����ʱ,qs��return_data��0,js���ļ�����,���ô˺�������ֵΪС�ڵ���js
{

unsigned char buf[512]; //������
unsigned long int culian[128]; //����
unsigned char culianX; //��ָ��,����ָ��������Ĵغ�
unsigned long int sqh_; //�ص���������
unsigned long int _sqh; //�ص�β������+1
unsigned int wjm_smzz; //�ļ�����ɨ��ָ��
unsigned int wjsl_x = 0; //�ļ���������

unsigned int js1; //����1
unsigned char js2; //����2

   culian[127] = mulu_cuhao;
   culianX = 127;
   sqh_ = _sqh;

   *return_data = 0;

   do
   {


        if(sqh_ == _sqh) //һ���ص���������,���뻻��
        {

            js2 = FAT32_BJ1(device,128,culian,&culianX,&sqh_,&_sqh);

            if(js2 == 0) //���洢������
            {
                return 0;
            }
            else if(js2 == 2) //�ؽ�����־
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

        }

        if(DEVICE_RD_512B(device,sqh_,buf) == 0) return 0; //������������
        ++sqh_; //ָ����һ������


           wjm_smzz = 0;

           do
           {

                     if(wjm_smzz == 512)
                     {
                        break; //����ѭ��
                     }
                     else if(buf[wjm_smzz] == 0xe5 || buf[wjm_smzz] == 0x2e)
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
                     else if((buf[wjm_smzz+0x0b] & 0xf0) != 0x00) //���ļ���
                     {
                        ++wjsl_x; //�ļ���������+1

                        if(qs != 0 && wjsl_x >= qs)
                        {
                           js1 = wjm_smzz + 32;
                           while(wjm_smzz != js1) *return_data = buf[wjm_smzz],++wjm_smzz,++return_data;
                        }
                        else wjm_smzz+=32; //ָ����һ��

                        *return_data = 0;
                        if(wjsl_x == js) return wjsl_x;

                     }
                     else
                     {
                        wjm_smzz += 32; //ָ����һ��
                     }


           }while(1);



   }while(1);



}




unsigned char FAT32_DELETE_E5(unsigned char device,unsigned long int mulu_cuhao)
{


   FAT32_DELETE_E5_32B_sqh_ = FAT32_cuhao_shanquhao(device,mulu_cuhao); //�غ�ת��������,ɨ����������
   FAT32_DELETE_E5_32B__sqh = FAT32_DELETE_E5_32B_sqh_ + FAT32_cudx[device]; //��¼�ص�β��������һ������

   if(FAT32_cuhao_culian(device,mulu_cuhao,FAT32_DELETE_E5_32B_CLX,FAT32_DELETE_E5_32B_culian) == 0) return 0; //��������,�������,���봦��
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
       if(DEVICE_RD_512B(device,FAT32_DELETE_E5_32B_sqh_,_buf) == 0) return 0; //������������
   }
   else
   {
       if(DEVICE_RD_512B(device,FAT32_DELETE_E5_sqh_,_buf) == 0) return 0; //������������
       if(DEVICE_RD_512B(device,FAT32_DELETE_E5_32B_sqh_,buf) == 0) return 0; //������������
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

                  if(FAT32_DELETE_E5_32B_sqh_ == FAT32_DELETE_E5_32B__sqh) //һ���ص���������,���뻻��
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


                 FAT32_DELETE_E5_qhc = 1; //�л�
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

                 if(DEVICE_WR_512B(device,FAT32_DELETE_E5_sqh_,_buf) == 0) return 0; //����������

                 if(X == 1)
                 {
                     if(DEVICE_WR_512B(device,FAT32_DELETE_E5_32B_sqh_,buf) == 0) return 0; //����������
                 }

                 ++FAT32_DELETE_E5_sqh_;

                 if(FAT32_DELETE_E5_sqh_ == FAT32_DELETE_E5__sqh) //һ���ص���������,���뻻��
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
                 while(js2 != FAT32_DELETE_E5_smzz) _buf[js2] = 0x00,++js2; //��0��32B��

             }
             else if(_buf[FAT32_DELETE_E5_smzz] == 0x00)
             {

                 if(DEVICE_WR_512B(device,FAT32_DELETE_E5_sqh_,_buf) == 0) return 0; //����������

                 if(X == 1)
                 {
                     if(DEVICE_WR_512B(device,FAT32_DELETE_E5_32B_sqh_,buf) == 0) return 0; //����������
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

                 while(js2 != FAT32_DELETE_E5_smzz)  //������32B��
                 {
                    if(K == 0) buf[js3] = _buf[js2],X = 1;
                    else _buf[js3] = _buf[js2];
                    ++js2,++js3;
                 }

                 js2 -= 32;
                 while(js2 != FAT32_DELETE_E5_smzz) _buf[js2] = 0x00,++js2; //��0��32B��


                 if(FAT32_DELETE_E5_32B_smzz == 512)
                 {

                     if(DEVICE_WR_512B(device,FAT32_DELETE_E5_32B_sqh_,buf) == 0) return 0; //����������

                     ++FAT32_DELETE_E5_32B_sqh_;

                     if(FAT32_DELETE_E5_32B_sqh_ == FAT32_DELETE_E5_32B__sqh) //һ���ص���������,���뻻��
                     {

                         if(FAT32_BJ1(device,FAT32_DELETE_E5_32B_CLX,FAT32_DELETE_E5_32B_culian,&FAT32_DELETE_E5_32B_culianX,&FAT32_DELETE_E5_32B_sqh_,&FAT32_DELETE_E5_32B__sqh) != 1) return 0;

                     }


                     if(FAT32_DELETE_E5_32B_sqh_ == FAT32_DELETE_E5_sqh_)
                     {
                         K = 1;
                     }
                     else if(FAT32_DELETE_E5_smzz != 512)
                     {
                         if(DEVICE_RD_512B(device,FAT32_DELETE_E5_32B_sqh_,buf) == 0) return 0; //������������
                     }


                     FAT32_DELETE_E5_32B_smzz = 0;

                     X = 0;

                 }


             }


        }


   }


}


void FAT32_VOID_cuhao(unsigned char device,unsigned char fatx) //ɨ��հ״س�ʼ��
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


unsigned char FAT32_VOID_cuhao_RUN(unsigned char device) //����ɨ��հ״�,����ֵ1����,2�ҵ��հ״�,0�豸����,3û���ҵ�
{

unsigned char buf[512];
unsigned int smzz;



    if(DEVICE_RD_512B(device,FAT32_VOID_cuhao_sqh,buf) == 0) return 0; //������������

    smzz = 0;


    while(1)
    {


          if(FAT32_VOID_cuhao_sqh == FAT32_VOID_cuhao__FAT - 1 && smzz == FAT32__cuhao_LBAPY[device] + 4) //����FAT��ɨ��,û�ҵ��հ״�
          {
              return 3;
          }
          else if(smzz == 512) //ɨ�껺����
          {
              ++FAT32_VOID_cuhao_sqh; //ָ����һ����
              return 1;
          }
          else if(buf[smzz] == 0x00 && buf[smzz+1] == 0x00 && buf[smzz+2] == 0x00 && buf[smzz+3] == 0x00) //�ҵ��հ״�
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




void FAT32_UP_culian(unsigned long int cuhao_,unsigned long int DATADX,unsigned char LBA_VOID_K) //���´������ȳ�ʼ��,cuhao_Ϊ�״غ�,DATADXΪ���ݴ�С,LAB_VOID_Kѡ���Ƿ����������,���Ϊ1����0�´�ӳ�������,Ϊ0����0
{

   FAT32_UP_culian_cuhao_ = cuhao_;
   FAT32_UP_culian_DATADX = DATADX;
   FAT32_UP_culian_LBA_VOID_K = LBA_VOID_K;
   FAT32_UP_culian_XZ = 0;
   FAT32_UP_culian_DATADX_ = 0;

}



unsigned char FAT32_UP_culian_RUN(unsigned char device) //���и��´�������,deviceѡ���豸,����0����,1����,2���,3�洢�豸�ռ䲻��
{

unsigned long int buf[128];
unsigned char void_buf[512];
unsigned char smzz;
unsigned long int cudx_B;

unsigned long int js1;
unsigned char js2;
unsigned int js3;
unsigned long int js4;




    if(FAT32_UP_culian_XZ == 0) //ɨ�����
    {

        if(FAT32_cuhao_culian(device,FAT32_UP_culian_cuhao_,128,buf) == 0) return 0;
        FAT32_UP_culian__cuhao = FAT32_UP_culian_cuhao_;


        cudx_B = FAT32_cudx_B[device]; //�����ش�С
        smzz = 0;

        while(1)
        {

            if(smzz == 128)
            {
                FAT32_UP_culian_cuhao_ = FAT32_UP_culian__cuhao; //β����Ϊ�״�
                break;
            }
            else
            {

                FAT32_UP_culian_DATADX_ += cudx_B; //��ɨ���ݴ�С����һ���ص����ݴ�С

                if(FAT32_UP_culian_DATADX_ >= FAT32_UP_culian_DATADX)
                {

                    js2 = 255;
                    if(FAT32_UP_culian_DATADX == 0) js2 = ~js2;

                    FAT32_UP_culian_XZ = 1; //�л�Ϊִ��ɾ������
                    FAT32_UP_culian_DELETE_culian_K = 0; //��־Ϊ����ɾ������
                    return FAT32_DELETE_culian(device,FAT32_UP_culian__cuhao,js2,3); //��ʼ��ɾ������

                }

                if((js1 = buf[smzz]) == 0x0fffffff || js1 == 0x00000000) //����ӳ�������������С��Ŀ�����ݲ����ǽ����ػ�հ״�
                {

                    FAT32_UP_culian__cuhao_bz = js1; //��¼�����������״غű�־

                    js1 = FAT32_UP_culian_DATADX - FAT32_UP_culian_DATADX_;    //�����Ҫ�����Ĵ�������
                    js4 = js1 / cudx_B;
                    if(js1 % cudx_B != 0) ++js4;


                    FAT32_UP_culian_XZ = 2; //�л�Ϊִ�д�������

                    return FAT32_SETUP_culian(device,FAT32_UP_culian__cuhao,js4,3); //��ʼ����������

                }

                FAT32_UP_culian__cuhao = js1;

                ++smzz;

            }

        }

    }
    else if(FAT32_UP_culian_XZ == 1) //ɾ������
    {

        js2 = FAT32_DELETE_culian_RUN(device); //����ɾ������

        if(FAT32_UP_culian_DELETE_culian_K == 1 && js2 == 2) js2 = 3;

        return js2;


    }
    else if(FAT32_UP_culian_XZ == 2) //��������
    {

        if((js2 = FAT32_SETUP_culian_RUN(device)) < 2) return js2; //���д�������

        if(js2 == 2) //�����������
        {

            if(FAT32_UP_culian_LBA_VOID_K == 0) //�����������
            {
                return 2; //ִ�����
            }
            else //���������
            {

                if(FAT32_UP_culian__cuhao_bz == 0x00) //�����������״غű�־Ϊ0x00000000,���״ؿ�ʼ���
                {
                    FAT32_UP_culian_LBA_VOID_culian[FAT32_UP_culian_LBA_VOID_CLX - 1] = FAT32_UP_culian__cuhao;
                    FAT32_UP_culian_LBA_VOID_culiaX = FAT32_UP_culian_LBA_VOID_CLX - 1; //ָ��β��
                }
                else //�����������״غű�־Ϊ0x0fffffff,����һ�ؿ�ʼ���
                {
                    if(FAT32_cuhao_culian(device,FAT32_UP_culian__cuhao,FAT32_UP_culian_LBA_VOID_CLX,FAT32_UP_culian_LBA_VOID_culian) == 0) return 0;
                    FAT32_UP_culian_LBA_VOID_culiaX = 0; //ָ���״�
                }

                FAT32_UP_culian_LBA_VOID_sqh_ = 0; //sqh_��_sqhֵͬ
                FAT32_UP_culian_LBA_VOID__sqh = 0;

                FAT32_UP_culian_XZ = 255; //�л�Ϊ���������
            }

        }
        else //�洢�ռ䲻��,ɾ������
        {
            FAT32_UP_culian_XZ = 1; //�л�Ϊִ��ɾ������
            FAT32_UP_culian_DELETE_culian_K = 1; //��־Ϊ�洢�ռ䲻��,ɾ������
            if(FAT32_DELETE_culian(device,FAT32_UP_culian__cuhao,FAT32_UP_culian__cuhao_bz,3) == 0) return 0; //��ʼ��ɾ������
        }

    }
    else //���������
    {

        if(FAT32_UP_culian_LBA_VOID_sqh_ == FAT32_UP_culian_LBA_VOID__sqh) //һ���ص���������,���뻻��
        {
            if((js2 = FAT32_BJ1(device,FAT32_UP_culian_LBA_VOID_CLX,FAT32_UP_culian_LBA_VOID_culian,&FAT32_UP_culian_LBA_VOID_culiaX,&FAT32_UP_culian_LBA_VOID_sqh_,&FAT32_UP_culian_LBA_VOID__sqh)) != 1) return js2;
        }

        js3 = 0;
        while(js3 != 512) void_buf[js3] = 0x00,++js3;   //��0�ջ�����

        if(DEVICE_WR_512B(device,FAT32_UP_culian_LBA_VOID_sqh_,void_buf) == 0) return 0; //����������
        ++FAT32_UP_culian_LBA_VOID_sqh_;

    }


    return 1;


}



void FAT32_ML_SETUP_WJF(unsigned long int mulu_cuhao,unsigned char *WJDATA_32B,unsigned int *WJ_CWJM,unsigned char UPX) //Ŀ¼�����ļ�����ʼ��, mulu_cuhao��Ŀ¼�״غ�, WJDATA_32B��32���ֽڵ��ļ�����, WJ_CWJM���ļ��ĳ��ļ���,��0��Ϊ������,UPXλ2Ϊ1�����ļ�����ʱ�������,λ1Ϊ1�����ļ�����������,λ0Ϊ1�����ļ�����޸�ʱ�������
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
   while(js1 != 403 && WJ_CWJM[js1] != 0) ++js1; //ɨ�賤�ļ�������

   js3 = 0;

   if(js1 != 0) //���ļ�����Ϊ0����
   {

       js6 = 0;
       js8 = 0;
       while(js6 != 11)
       {
           js8 = ((js8 << 7) | (js8 >> 1)) + WJDATA_32B[js6];  //������ļ���Ч���
           ++js6;
       }


       js2 = js1 / 13;
       if(js1 % 13 != 0) ++js2; //����ļ���ռ���ٸ�32B


       js2 <<= 5; //��32,�ó����ļ������ļ���β��ַ+1
       js3 = js2; //������ļ�����32B�ļ����׵�ַ


       js5 = 0;
       js6 = 0;
       js9 = 0;

            do
            {
                 js2 -= 32; //��һ��32B
                 ++js6; //Ŀ¼�����+1

                 FAT32_ML_SETUP_WJF_WJF[js2] = js6; //��5λ˳�����ֵ,λ6Ϊ1��ʾ���ļ����һ��Ŀ¼��

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

                     FAT32_ML_SETUP_WJF_WJF[js2 + js4] = js7;  //���ļ���unicode��
                     ++js4;
                     FAT32_ML_SETUP_WJF_WJF[js2 + js4] = js7 >> 8;
                     ++js4;

                     if(js4 == 0x000b)
                     {
                         FAT32_ML_SETUP_WJF_WJF[js2 + js4] = 0x0f; //���ļ���Ŀ¼���־,ȡֵ0FH
                         ++js4;
                         FAT32_ML_SETUP_WJF_WJF[js2 + js4] = 0x00; //ϵͳ����
                         ++js4;
                         FAT32_ML_SETUP_WJF_WJF[js2 + js4] = js8;  //Ч���
                         ++js4;
                     }

                     if(js4 == 0x001a) //�ļ���ʼ�غ�(Ŀǰ����0)
                     {
                         FAT32_ML_SETUP_WJF_WJF[js2 + js4] = 0x00;
                         ++js4;
                         FAT32_ML_SETUP_WJF_WJF[js2 + js4] = 0x00;
                         ++js4;
                     }

                 }while(js4 != 32);


            }while(js2 != 0);

            FAT32_ML_SETUP_WJF_WJF[0] |= 0x40; //��־Ϊ���һ��Ŀ¼��

   }


   js6 = 0;
   js10 = js3;

   while(js6 != 32) FAT32_ML_SETUP_WJF_WJF[js3] = WJDATA_32B[js6],++js3,++js6;  //�������ļ�����32B�ļ���


   FAT32_WJF_32B_UPRTC(&FAT32_ML_SETUP_WJF_WJF[js10],UPX); //�����ļ�ʱ����Ϣ


   FAT32_ML_SETUP_WJF_WJFDX = js3;


   FAT32_ML_SETUP_WJF_mulu_cuhao = mulu_cuhao;

   FAT32_ML_SETUP_WJF_culian[FAT32_ML_SETUP_WJF_CLX - 1] = mulu_cuhao;
   FAT32_ML_SETUP_WJF_culiaX = FAT32_ML_SETUP_WJF_CLX - 1;
   FAT32_ML_SETUP_WJF_sqh_ = 0;
   FAT32_ML_SETUP_WJF__sqh = 0;

   FAT32_ML_SETUP_WJF_XZ = 0;
   FAT32_ML_SETUP_WJF_WJFX = 0;

}





unsigned char FAT32_ML_SETUP_WJF_RUN(unsigned char device) //����Ŀ¼�����ļ���,deviceѡ���豸,����ֵ0����,1����,2���,3�豸�ռ䲻��
{

unsigned char buf[512];
unsigned int smzz;

unsigned char returnX;


     if(FAT32_ML_SETUP_WJF_XZ == 0) //��ʼ��ɾ��E5
     {

         FAT32_ML_SETUP_WJF_XZ = 1; //�л�������ɾ��E5
         returnX = FAT32_DELETE_E5(device,FAT32_ML_SETUP_WJF_mulu_cuhao); //��ʼ��ɾ��E5

     }
     else if(FAT32_ML_SETUP_WJF_XZ == 1) //����ɾ��E5
     {

         returnX = FAT32_DELETE_E5_RUN(device); //����ɾ��E5

         if(returnX == 2)
         {

             FAT32_ML_SETUP_WJF_XZ = 2; //�л�����ʼ�����´�������
             returnX = 1;
         }

     }
     else if(FAT32_ML_SETUP_WJF_XZ == 2) //��ʼ�����´�������
     {

         FAT32_ML_SETUP_WJF_XZ = 3; //�л������и��´�������
         FAT32_UP_culian(FAT32_ML_SETUP_WJF_mulu_cuhao,FAT32_DELETE_E5_WJFDX + FAT32_ML_SETUP_WJF_WJFDX,1); //��ʼ�����´�������
         returnX = 1;

     }
     else if(FAT32_ML_SETUP_WJF_XZ == 3) //���и��´�������
     {

         returnX = FAT32_UP_culian_RUN(device); //���и��´�������

         if(returnX == 2) //���´����������
         {
             FAT32_ML_SETUP_WJF_XZ = 255; //�л��������ļ���
             returnX = 1;
         }

     }
     else //�����ļ���
     {

        if(FAT32_ML_SETUP_WJF_sqh_ == FAT32_ML_SETUP_WJF__sqh) //һ���ص���������,���뻻��
        {
            if(FAT32_BJ1(device,FAT32_ML_SETUP_WJF_CLX,FAT32_ML_SETUP_WJF_culian,&FAT32_ML_SETUP_WJF_culiaX,&FAT32_ML_SETUP_WJF_sqh_,&FAT32_ML_SETUP_WJF__sqh) != 1) return 0;
        }

        if(DEVICE_RD_512B(device,FAT32_ML_SETUP_WJF_sqh_,buf) == 0) return 0; //������������


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

                while(smzz != 512 && FAT32_ML_SETUP_WJF_WJFX != FAT32_ML_SETUP_WJF_WJFDX) buf[smzz] = FAT32_ML_SETUP_WJF_WJF[FAT32_ML_SETUP_WJF_WJFX],++smzz,++FAT32_ML_SETUP_WJF_WJFX; //�����ļ���

                if(DEVICE_WR_512B(device,FAT32_ML_SETUP_WJF_sqh_,buf) == 0) return 0; //����������

                if(FAT32_ML_SETUP_WJF_WJFX == FAT32_ML_SETUP_WJF_WJFDX) //�ļ����������
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

        ++FAT32_ML_SETUP_WJF_sqh_; //ָ����һ������

     }


     return returnX;

}


unsigned int FAT32_WJMFL_DWJM_CWJM(unsigned char *WJM,unsigned char *DWJM,unsigned int *CWJM,unsigned char *WJM_GSBZ,unsigned char *WJFDATA_32B_byte_0CH,unsigned char CT1) //�ļ�������,WJMΪԴ�ļ���,DWJMΪ������Ķ��ļ���,CWJMΪ������ĳ��ļ���,WJM_GSBZΪ1���ļ���,0Ϊ���ļ���,WJFDATA_32B_byte_0CHΪ32�ֽ��ļ���0CH���ֽ�,���ƴ�Сд,CT1Ϊ1��ʱ���ж϶��ļ�������Ĵ�Сдȷ���Ƿ�Ϊ���ļ���,Ϊ0���ж϶��ļ�����Сд
{

unsigned int wjm_smzz; //�ļ���ɨ��ָ��
unsigned int _wjm_smzz; //�ļ���ɨ��ָ�����λ��
unsigned int wjmcd; //�ļ����ַ��ܳ���
unsigned char wjm_gs; //�ļ�����ʽ 0Ϊ8�ַ�3��׺����ʽ 1Ϊ���ļ�����ʽ
unsigned char dwjm_x; //���ļ�������ָ��
unsigned char dwjm_k; //�ļ����е�1��"."��־=1,����=0
unsigned int cwjm_x; //���ļ����ļ���,��¼���ļ����ڵ�Ԫ�ظ���
unsigned char _wjm; //�ļ������������м����
unsigned char _wjm_2; //�ļ������������м����2
unsigned char dwjm_dxxbz; //���ļ�����Сд��־
unsigned char dwjm_dxx_k; //���ļ�����Сд�����ֽ�,������ļ�����ǰ8���ֽ�ȫ��ΪСд,λ4��1,��3���ֽ�ΪСд,λ3��1
unsigned int D_J; //"."����
unsigned int D_WZ1; //��¼���һ��"."��λ��+1
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

  while(wjmcd != 403 && _WJM[_wjm_smzz] != 0) //ȡ�ļ�������
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


          while(wjm_smzz < _wjm_smzz) //�ļ���ûɨ�����ɨ
          {

               _wjm = _WJM[wjm_smzz];
               ++wjm_smzz;

               CWJM[cwjm_x] = _wjm;


               if(_wjm == '.')
               {

                  if(D_WZ1 == wjm_smzz) //Ϊ���һ��"."
                  {
                     dwjm_k = 1; //�л�����׺������
                     while(dwjm_x < 8) DWJM[dwjm_x] = ' ',++dwjm_x; //���ļ����Ʋ���8�ַ�����ո�
                     dwjm_dxxbz = 0;
                  }

                  if(++D_J > 1) wjm_gs = 1; //��־Ϊ���ļ���

               }
               else if(_wjm == ' ')
               {

                  wjm_gs = 1; //�пո�,��־Ϊ���ļ���

               }
               else
               {

                  if(_wjm > 127) //Ϊ2���ֽ�
                  {
                      CWJM[cwjm_x] <<= 8;
                      _wjm_2 = _WJM[wjm_smzz];
                      CWJM[cwjm_x] |= _wjm_2;
                      ++wjm_smzz;
                      if(CT1 == 1) wjm_gs = 1; //��־Ϊ���ļ���
                  }

                  if(dwjm_k == 0 && dwjm_x == 8 || dwjm_k == 1 && dwjm_x == 11) //����8_3���ļ�����ʽʱ��־Ϊ���ļ���
                  {
                      wjm_gs = 1;
                  }
                  else
                  {

                          if(_wjm < 128) //Ϊ1���ֽ�ʱ����
                          {

                              if(_wjm > 64 && _wjm < 91) //��д��ĸ
                              {
                                  if(CT1 == 1 && dwjm_dxxbz == 2) wjm_gs = 1; //��־Ϊ���ļ���
                                  dwjm_dxxbz = 1;
                              }

                              if(_wjm > 96 && _wjm < 123) //Сд��ĸ
                              {
                                  if(CT1 == 1 && dwjm_dxxbz == 1) wjm_gs = 1; //��־Ϊ���ļ���
                                  dwjm_dxxbz = 2;
                                  if(dwjm_k == 0) dwjm_dxx_k = 0x08; //ǰ8�ַ�ȫΪСд
                                  else dwjm_dxx_k |= 0x10; //��3�ַ�ȫΪСд
                                  _wjm -= 32; //ΪСд��ĸ��ʱ��ת���ɴ�д��ĸ
                              }

                              DWJM[dwjm_x] = _wjm;
                              ++dwjm_x;

                          }
                          else //Ϊ2���ֽ�ʱ����
                          {

                              DWJM[dwjm_x] = _wjm;
                              ++dwjm_x;

                              if(dwjm_k == 0 && dwjm_x == 8 || dwjm_k == 1 && dwjm_x == 11) //����8_3���ļ�����ʽʱ��־Ϊ���ļ���
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



     while(dwjm_x < 11) DWJM[dwjm_x] = ' ',++dwjm_x; //���ļ����Ʋ���11�ַ�����ո�

     if(wjm_gs == 0) //Ϊ���ļ���
     {
         *CWJM = 0; //���ļ�������Ϊ0
     }
     else //Ϊ���ļ���
     {
         CWJM[cwjm_x] = 0; //��0��β
         dwjm_dxx_k = 0x00;
     }

     *WJM_GSBZ = wjm_gs;
     *WJFDATA_32B_byte_0CH = dwjm_dxx_k;

     return wjmcd;

}



unsigned char FAT32_ML_WJCX(unsigned char device,unsigned long int mulu_cuhao,unsigned char *WJM,unsigned char *RETURN_WJFDATA_32B,unsigned int *RETURN_CWJM,unsigned char E5_DELETE_K,unsigned char WJDX_UP_K,unsigned long int WJDX_UP,unsigned char cuhao_UP_K,unsigned long int cuhao_UP,unsigned char RTCUP_K) //Ŀ¼���ļ���ѯ,deviceѡ���豸,mulu_cuhaoΪĿ¼�״غ�,WJMΪ�ļ���,0��Ϊ������,RETURN_WJFDATA_32BΪ���ص�32���ֽ��ļ�������,RETURN_CWJMΪ���صĳ��ļ���,��0��Ϊ������,E5_DELETE_KΪ1�����ļ������ݺ���E5ɾ���ļ���,Ϊ0��ɾ���ļ���,WJDX_UP_KΪ1�����ļ���С��Ϣ,WJDX_UPΪ�ļ���С,cuhao_UP_KΪ1�����ļ��غ���Ϣ,cuhao_UPΪ�ļ��غ�,RTCUP_Kλ2Ϊ1�����ļ�����ʱ�������,λ1Ϊ1�����ļ�����������,λ0Ϊ1�����ļ�����޸�ʱ�������
{

unsigned char WJFDATA_32B_byte_0CH;
unsigned int WJMCD;

unsigned char DWJM[11];
unsigned int CWJM[404];
unsigned char CWJM_smzz;
unsigned char GSBZ;

unsigned char buf[512];
unsigned int smzz;


#define WJCX_CLX 8  //��������              //��¼��ǰɨ��λ��

unsigned long int WJCX_culian[8];
unsigned char WJCX_culianX;
unsigned long int WJCX_sqh_;
unsigned long int WJCX__sqh;


unsigned long int CWJM_ADDR_culian[2];           //��¼���ļ�����ʼλ��
unsigned char CWJM_ADDR_culianX;
unsigned long int CWJM_ADDR_sqh_;
unsigned long int CWJM_ADDRX__sqh;
unsigned int CWJM_ADDR_smzz;
unsigned char CWJM_ADDR_BZ;
unsigned int CWJM_ADDR_CD;

unsigned char CWJM_buf[1024];
unsigned char *CWJM_buf_a;
unsigned int CWJM_buf_smzz; //ָ���ļ����������ײ�

unsigned char CWJM_TBBZ; //���ļ���ͷ����־,1Ϊͷ��,0����ͷ��
unsigned char CWJM_BJBZ; //���ļ����Ƚϱ�־,1Ϊ���бȽ�,0Ϊ���Ƚ�

unsigned int js1;
unsigned int js2;
unsigned int js3;


   *RETURN_WJFDATA_32B = 0;
   *RETURN_CWJM = 0;

   WJMCD = FAT32_WJMFL_DWJM_CWJM(WJM,DWJM,CWJM,&GSBZ,&WJFDATA_32B_byte_0CH,0); //�ļ�������,WJMΪԴ�ļ���,DWJMΪ������Ķ��ļ���,CWJMΪ������ĳ��ļ���,WJM_GSBZΪ1���ļ���,0Ϊ���ļ���,WJFDATA_32B_byte_0CHΪ32�ֽ��ļ���0CH���ֽ�,���ƴ�Сд,CT1Ϊ1��ʱ���ж϶��ļ�������Ĵ�Сдȷ���Ƿ�Ϊ���ļ���,Ϊ0���ж϶��ļ�����Сд



   WJCX_culian[WJCX_CLX - 1] = mulu_cuhao;
   WJCX_culianX = WJCX_CLX - 1;
   WJCX_sqh_ = 0;
   WJCX__sqh = 0;

   smzz = 0;
   CWJM_ADDR_BZ = 0;
   CWJM_BJBZ = 0;

   while(1)
   {


        if(WJCX_sqh_ == WJCX__sqh) //һ���ص���������,���뻻��
        {
            if(FAT32_BJ1(device,WJCX_CLX,WJCX_culian,&WJCX_culianX,&WJCX_sqh_,&WJCX__sqh) != 1) return 0;
        }

        if(DEVICE_RD_512B(device,WJCX_sqh_,buf) == 0) return 0; //������������




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
            else if(buf[smzz] == 0x00) //û���ҵ��ļ�
            {
                return 0;
            }
            else
            {



                if(buf[smzz + 0x0b] == 0x0f) //�ǳ��ļ�����־
                {

                    if((buf[smzz] & 0xe0) == 0x40) //�ǳ��ļ���ͷ��
                    {

                        CWJM_ADDR_culian[1] = WJCX_culian[WJCX_culianX];           //��¼���ļ�����ʼλ��
                        CWJM_ADDR_culianX = 1;
                        CWJM_ADDR_sqh_ = WJCX_sqh_;
                        CWJM_ADDRX__sqh = WJCX__sqh;
                        CWJM_ADDR_smzz = smzz;
                        CWJM_ADDR_BZ = 1;
                        CWJM_ADDR_CD = buf[smzz] & 0x1f;
                        CWJM_buf_smzz = CWJM_ADDR_CD;
                        CWJM_buf_smzz <<= 5; //��32�ֽ�,������ļ����ײ�

                        CWJM_TBBZ = 1;

                    }
                    else //���ǳ��ļ���ͷ��
                    {
                        CWJM_TBBZ = 2;
                    }

                }
                else //���ǳ��ļ���
                {
                    CWJM_TBBZ = 0;
                }




                if(GSBZ == 0) //���ļ���
                {

                    if(buf[smzz + 0x0b] != 0x0f) //�Ƕ��ļ���������
                    {

                        js1 = 0;
                        while(js1 != 11 && buf[smzz + js1] == DWJM[js1]) ++js1;

                        if(js1 != 11) //�ļ�������ͬ
                        {
                            CWJM_ADDR_BZ = 0;
                            smzz += 32;
                        }
                        else //�ļ�����ͬ
                        {

                            js1 = 0;
                            while(js1 != 32) RETURN_WJFDATA_32B[js1] = buf[smzz + js1],++js1; //����32B�ļ���


                            FAT32_WJF_32B_UPRTC(&buf[smzz],RTCUP_K); //�����ļ���ʱ����Ϣ

                            if(WJDX_UP_K != 0) //�����ļ���С
                            {
                                buf[smzz + 0x1f] = WJDX_UP >> 24; //���ļ���С
                                buf[smzz + 0x1e] = WJDX_UP >> 16;
                                buf[smzz + 0x1d] = WJDX_UP >> 8;
                                buf[smzz + 0x1c] = WJDX_UP;
                            }

                            if(cuhao_UP_K != 0) //�����ļ��غ�
                            {
                                buf[smzz + 0x15] = cuhao_UP >> 24; //���ļ��غ�
                                buf[smzz + 0x14] = cuhao_UP >> 16;
                                buf[smzz + 0x1b] = cuhao_UP >> 8;
                                buf[smzz + 0x1a] = cuhao_UP;
                            }

                            if(E5_DELETE_K != 0) //ɾ���ļ�
                            {
                                buf[smzz] = 0xe5;
                            }

                            if(DEVICE_WR_512B(device,WJCX_sqh_,buf) == 0) return 0; //����������


                            if(CWJM_ADDR_BZ == 1) //�г��ļ���
                            {

                                CWJM_buf_a = CWJM_buf;

                                while(1)
                                {

                                    if(CWJM_ADDR_sqh_ == CWJM_ADDRX__sqh) //һ���ص���������,���뻻��
                                    {
                                        if(FAT32_BJ1(device,2,CWJM_ADDR_culian,&CWJM_ADDR_culianX,&CWJM_ADDR_sqh_,&CWJM_ADDRX__sqh) != 1) return 0;
                                    }

                                    if(DEVICE_RD_512B(device,CWJM_ADDR_sqh_,buf) == 0) return 0; //������������

                                    while(1)
                                    {

                                        if(CWJM_ADDR_CD == 0) //Ϊ0�������
                                        {

                                            if(E5_DELETE_K != 0)
                                            {
                                               if(DEVICE_WR_512B(device,CWJM_ADDR_sqh_,buf) == 0) return 0; //����������
                                            }

                                            goto out;

                                        }
                                        else if(CWJM_ADDR_smzz == 512)
                                        {

                                            if(E5_DELETE_K != 0)
                                            {
                                               if(DEVICE_WR_512B(device,CWJM_ADDR_sqh_,buf) == 0) return 0; //����������
                                            }

                                            CWJM_ADDR_smzz = 0;
                                            break;

                                        }
                                        else
                                        {

                                            js1 = 0;
                                            while(js1 != 32) *CWJM_buf_a = buf[CWJM_ADDR_smzz + js1],++CWJM_buf_a,++js1; //����32B

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
                                       js2 = CWJM_buf[CWJM_buf_smzz + js1 + 1];                         //��ȡ�����ļ���
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


                            *RETURN_CWJM = 0; //��0������

                            return 1; //�ҵ��ļ�


                        }

                    }
                    else //�ǳ��ļ���������
                    {
                        smzz += 32;
                    }






                }
                else //���ļ���
                {

                     if(CWJM_TBBZ == 0) //���ǳ��ļ���
                     {

                         if(CWJM_BJBZ == 1)
                         {

                                 js1 = 0;
                                 while(js1 != 32) RETURN_WJFDATA_32B[js1] = buf[smzz + js1],++js1; //����32B�ļ���


                                 FAT32_WJF_32B_UPRTC(&buf[smzz],RTCUP_K); //�����ļ���ʱ����Ϣ

                                 if(WJDX_UP_K != 0) //�����ļ���С
                                 {
                                     buf[smzz + 0x1f] = WJDX_UP >> 24; //���ļ���С
                                     buf[smzz + 0x1e] = WJDX_UP >> 16;
                                     buf[smzz + 0x1d] = WJDX_UP >> 8;
                                     buf[smzz + 0x1c] = WJDX_UP;
                                 }

                                 if(cuhao_UP_K != 0) //�����ļ��غ�
                                 {
                                     buf[smzz + 0x15] = cuhao_UP >> 24; //���ļ��غ�
                                     buf[smzz + 0x14] = cuhao_UP >> 16;
                                     buf[smzz + 0x1b] = cuhao_UP >> 8;
                                     buf[smzz + 0x1a] = cuhao_UP;
                                 }

                                 if(E5_DELETE_K != 0) //ɾ���ļ�
                                 {
                                     buf[smzz] = 0xe5;
                                 }

                                 if(DEVICE_WR_512B(device,WJCX_sqh_,buf) == 0) return 0; //����������


                                 if(E5_DELETE_K != 0) //������E5,ɾ���ļ�
                                 {

                                     while(1)
                                     {

                                        if(CWJM_ADDR_sqh_ == CWJM_ADDRX__sqh) //һ���ص���������,���뻻��
                                        {
                                            if(FAT32_BJ1(device,2,CWJM_ADDR_culian,&CWJM_ADDR_culianX,&CWJM_ADDR_sqh_,&CWJM_ADDRX__sqh) != 1) return 0;
                                        }

                                        if(DEVICE_RD_512B(device,CWJM_ADDR_sqh_,buf) == 0) return 0; //������������

                                        while(1)
                                        {

                                            if(CWJM_ADDR_CD == 0) //����Ϊ0,�������
                                            {
                                                if(DEVICE_WR_512B(device,CWJM_ADDR_sqh_,buf) == 0) return 0; //����������
                                                goto out2;
                                            }
                                            else if(CWJM_ADDR_smzz == 512)
                                            {
                                                if(DEVICE_WR_512B(device,CWJM_ADDR_sqh_,buf) == 0) return 0; //����������
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

                                 return 1; //�������


                         }


                         smzz += 32;


                     }
                     else //�ǳ��ļ���
                     {

                         if(CWJM_BJBZ == 0) //�Ƚϱ�־Ϊ0
                         {

                             if(CWJM_TBBZ == 1) //Ϊ���ļ���ͷ��
                             {

                                 js1 = 1;
                                 js2 = 0;
                                 do
                                 {
                                     if(buf[smzz + js1] != 0x00 || buf[smzz + js1 + 1] != 0x00) ++js2;else break;
                                     js1 += 2;
                                     if(js1 == 0x000b) js1 += 3;else if(js1 == 0x001a) js1 += 2;

                                 }while(js1 != 32);


                                 if((CWJM_ADDR_CD - 1) * 13 + js2 == WJMCD) //�ļ���������ͬ
                                 {

                                    CWJM_smzz = WJMCD;
                                    CWJM_BJBZ = 1; //���бȽ�
                                    goto out1;
                                 }
                                 else //�ļ������Ȳ�ͬ
                                 {
                                    smzz += 32;
                                 }

                             }
                             else //���ǳ��ļ���ͷ��
                             {
                                 smzz += 32;
                             }

                         }
                         else //�Ƚϱ�־Ϊ1,�ļ���������ͬ,���бȽ�
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

                                     if(js2 > 96 && js2 < 123 && js3 > 64 && js3 < 91) js3 += 32;        //��Сд����
                                     else if(js3 > 96 && js3 < 123 && js2 > 64 && js2 < 91) js2 += 32;

                                     if(js2 != js3) //�ļ�����ͬ
                                     {
                                         CWJM_BJBZ = 0; //�л�Ϊ�������ļ���ͷ��
                                         break;
                                     }

                                 }while(js1 != 1);

                                 smzz += 32;


                         }


                     }


                }





            }

        }


        ++WJCX_sqh_; //ָ����һ����


   }



}





unsigned char FAT32_ML_SETUP_WJ(unsigned char device,unsigned long int mulu_cuhao,unsigned long int WJDX,unsigned char *WJM,unsigned char WJSX) //��ʼ��Ŀ¼�����ļ�,deviceѡ���豸,mulu_cuhaoΪĿ¼�״غ�,WJDXΪ�ļ���С,WJMΪ�ļ���,��0��Ϊ������,WJSXΪ�ļ������ֽ�,00000000(��д),00000001(ֻ��),00000010(����),00000100(ϵͳ),00001000(���),00010000(��Ŀ¼),00100000(�鵵),����ֵ0����,1���
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


unsigned char X_; //���
unsigned char _X_; //�м�
unsigned char _X; //�յ�
unsigned char _X_BZ; //�յ��־


  smzz = 0;
  while(smzz != 806 && WJM[smzz] != 0) _WJM[smzz] = WJM[smzz],++smzz;
  if(smzz == 806 || smzz == 0) return 0; //�ļ����������Ȼ�Ϊ0,����0
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



  if(FAT32_ML_SETUP_WJ_XZ == 0 && FAT32_ML_DELETE_WJ_XZ == 0 && FAT32_ML_XGWJM_XZ == 0 && FAT32_ML_XGWJDX_XZ == 0) //�����ļ�����,ɾ���ļ�����,�޸��ļ�������,�޸��ļ���С����,ȫ������ʱ����
  {

      buf[0] = 0;
      if(FAT32_ML_WJCX(device,mulu_cuhao,strcat(buf,WJM),RETURN_WJFDATA_32B,RETURN_CWJM,0,0,0,0,0,0) != 0) //��ͬ���ļ�
      {

          X_ = 1;
          _X_ = 1;
          _X_BZ = 0;

          while(1)
          {

              buf[0] = 0;
              if(FAT32_ML_WJCX(device,mulu_cuhao,strcat( strcat( strcat( strcat(buf,_WJM) ,"~") , U8_str(_X_,1) ) , _HZM ),RETURN_WJFDATA_32B,RETURN_CWJM,0,0,0,0,0,0) != 0) //��ͬ���ļ�
              {
                  X_ = _X_; //��¼Ϊ���

                  if(_X_BZ != 0) //���յ�
                  {
                      if(_X - X_ < 2) //_XΪ���
                      {
                          _X_ = _X;
                      }
                      else
                      {
                          _X_ = X_ + ((_X - X_) >> 1); //ȡ�м�ֵ
                      }
                  }
                  else //û���յ�
                  {
                      _X_ <<= 1; //��2
                      if(_X_ == 0) return 0;
                  }
              }
              else //û��ͬ���ļ�
              {

                 _X = _X_; //��¼Ϊ�յ�
                 _X_BZ = 1; //��־Ϊ���յ�

                 if(_X - X_ < 2) //_XΪ���
                 {
                     break; //��������
                 }

                 _X_ = X_ + ((_X - X_) >> 1); //ȡ�м�ֵ

              }

          }

      }





     FAT32_WJMFL_DWJM_CWJM(buf,FAT32_ML_SETUP_WJ_WJFDATA_32B,FAT32_ML_SETUP_WJ_CWJM,&WJM_GS,&WJFDATA_32B_byte_0CH,1); //��������ļ�����32B�ͳ��ļ�����unicode

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




      if(FAT32_ML_WJCX(device,mulu_cuhao,_WJM,RETURN_WJFDATA_32B,RETURN_CWJM,0,0,0,0,0,0) != 0) //��ͬ���ļ�
      {

          X_ = 1;
          _X_ = 1;
          _X_BZ = 0;

          while(1)
          {



              _addr = U8_str(_X_,1);
              js1 = 0;
              while(_addr[js1] != 0) ++js1; //ȡ?����


              js2 = 0;
              js3 = 0;
              while(_WJM[js2] != 0 && _WJM[js2] != '.') buf[js3] = _WJM[js2],++js2,++js3; //����ǰ8�ļ���

              while(js3 + js1 + 1 > 8) --js3; //�ƶ�������λ��

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

              while(js1 != 0) buf[js3] = *_addr,++js3,++_addr,--js1; //����~?

              while(_WJM[js2] != 0) buf[js3] = _WJM[js2],++js2,++js3; //������׺��

              buf[js3] = 0;




              if(FAT32_ML_WJCX(device,mulu_cuhao,buf,RETURN_WJFDATA_32B,RETURN_CWJM,0,0,0,0,0,0) != 0) //��ͬ���ļ�
              {
                  X_ = _X_; //��¼Ϊ���

                  if(_X_BZ != 0) //���յ�
                  {
                      if(_X - X_ < 2) //_XΪ���
                      {
                          _X_ = _X;
                      }
                      else
                      {
                          _X_ = X_ + ((_X - X_) >> 1); //ȡ�м�ֵ
                      }
                  }
                  else //û���յ�
                  {
                      _X_ <<= 1; //��2
                      if(_X_ == 0) return 0;
                  }
              }
              else //û��ͬ���ļ�
              {

                 _X = _X_; //��¼Ϊ�յ�
                 _X_BZ = 1; //��־Ϊ���յ�

                 if(_X - X_ < 2) //_XΪ���
                 {
                     break; //��������
                 }

                 _X_ = X_ + ((_X - X_) >> 1); //ȡ�м�ֵ

              }

          }


          FAT32_WJMFL_DWJM_CWJM(buf,FAT32_ML_SETUP_WJ_WJFDATA_32B,RETURN_CWJM,&WJM_GS,&WJFDATA_32B_byte_0CH,1); //��������ļ�����32B�ͳ��ļ�����unicode



      }







     FAT32_ML_SETUP_WJ_WJFDATA_32B[0x0b] = WJSX; //���ļ�����
     FAT32_ML_SETUP_WJ_WJFDATA_32B[0x0c] = WJFDATA_32B_byte_0CH; //����ļ�����Сд�����ֽ�,λ3Ϊ1,ǰ8�ַ�ȫΪСд,λ4Ϊ1,��3�ַ�ȫΪСд
     FAT32_ML_SETUP_WJ_WJFDATA_32B[0x0d] = 0x00; //��10����λ


     FAT32_ML_SETUP_WJ_DEVICE = device;
     FAT32_ML_SETUP_WJ_mulu_cuhao = mulu_cuhao;
     FAT32_ML_SETUP_WJ_XZ = 1;

     if((WJSX & 0xf0) == 0x20) //���ļ�
     {
         FAT32_ML_SETUP_WJ_WJDX = WJDX;
         FAT32_ML_SETUP_WJ_LBA_VOID_K = 0; //�����������

         FAT32_ML_SETUP_WJ_WJFDATA_32B[0x1f] = WJDX >> 24; //���ļ���С
         FAT32_ML_SETUP_WJ_WJFDATA_32B[0x1e] = WJDX >> 16;
         FAT32_ML_SETUP_WJ_WJFDATA_32B[0x1d] = WJDX >> 8;
         FAT32_ML_SETUP_WJ_WJFDATA_32B[0x1c] = WJDX;

     }
     else //��Ŀ¼
     {
         FAT32_ML_SETUP_WJ_WJDX = 1;
         FAT32_ML_SETUP_WJ_LBA_VOID_K = 1; //���������

         FAT32_ML_SETUP_WJ_WJFDATA_32B[0x1f] = 0x00; //���ļ���С
         FAT32_ML_SETUP_WJ_WJFDATA_32B[0x1e] = 0x00;
         FAT32_ML_SETUP_WJ_WJFDATA_32B[0x1d] = 0x00;
         FAT32_ML_SETUP_WJ_WJFDATA_32B[0x1c] = 0x00;
     }

     return 1;

  }
  else return 0;

}



unsigned char FAT32_ML_SETUP_WJ_RUN() //����Ŀ¼�����ļ�,����ֵ0����,1����,2���,3�洢�豸�ռ䲻��,4����
{

unsigned char returnX;


     if(FAT32_ML_SETUP_WJ_XZ == 0) //���
     {
         returnX = 4; //����

     }
     else if(FAT32_ML_SETUP_WJ_XZ == 1) //ɨ��հ״س�ʼ��
     {

         FAT32_VOID_cuhao(FAT32_ML_SETUP_WJ_DEVICE,0); //ɨ��հ״س�ʼ��,ɨFAT1
         FAT32_ML_SETUP_WJ_XZ = 2; //�л�������ɨ��հ״�
         returnX = 1;

     }
     else if(FAT32_ML_SETUP_WJ_XZ == 2) //����ɨ��հ״�
     {

         returnX = FAT32_VOID_cuhao_RUN(FAT32_ML_SETUP_WJ_DEVICE); //����ɨ��հ״�,����ֵ1����,2�ҵ��հ״�,0�豸����,3�洢�豸��

         if(returnX == 2) //�ҵ��հ״�
         {
             FAT32_ML_SETUP_WJ_XZ = 3; //�л�����ʼ�������ļ���������
             returnX = 1;
         }

     }
     else if(FAT32_ML_SETUP_WJ_XZ == 3) //��ʼ�������ļ���������
     {

         FAT32_UP_culian(FAT32_VOID_cuhao_cuhao,FAT32_ML_SETUP_WJ_WJDX,FAT32_ML_SETUP_WJ_LBA_VOID_K); //��ʼ�����´�������
         FAT32_ML_SETUP_WJ_XZ = 4; //�л������и��´�������
         returnX = 1;

     }
     else if(FAT32_ML_SETUP_WJ_XZ == 4) //���и����ļ���������
     {

         returnX = FAT32_UP_culian_RUN(FAT32_ML_SETUP_WJ_DEVICE); //���и��´�������,deviceѡ���豸,����0����,1����,2���,3�洢�豸�ռ䲻��

         if(returnX == 2) //���´����������
         {
             FAT32_ML_SETUP_WJ_XZ = 5; //�л���Ŀ¼�����ļ�����ʼ��
             returnX = 1;
         }

     }
     else if(FAT32_ML_SETUP_WJ_XZ == 5) //Ŀ¼�����ļ�����ʼ��
     {

         FAT32_ML_SETUP_WJ_WJFDATA_32B[0x15] = FAT32_VOID_cuhao_cuhao >> 24; //�޸�32B�ļ����غ�
         FAT32_ML_SETUP_WJ_WJFDATA_32B[0x14] = FAT32_VOID_cuhao_cuhao >> 16;
         FAT32_ML_SETUP_WJ_WJFDATA_32B[0x1b] = FAT32_VOID_cuhao_cuhao >> 8;
         FAT32_ML_SETUP_WJ_WJFDATA_32B[0x1a] = FAT32_VOID_cuhao_cuhao;

         FAT32_ML_SETUP_WJF(FAT32_ML_SETUP_WJ_mulu_cuhao,FAT32_ML_SETUP_WJ_WJFDATA_32B,FAT32_ML_SETUP_WJ_CWJM,0x07); //Ŀ¼�����ļ�����ʼ��, mulu_cuhao��Ŀ¼�״غ�, WJDATA_32B��32���ֽڵ��ļ�����, WJ_CWJM���ļ��ĳ��ļ���,��0��Ϊ������,UPXλ2Ϊ1�����ļ�����ʱ�������,λ1Ϊ1�����ļ�����������,λ0Ϊ1�����ļ�����޸�ʱ�������
         FAT32_ML_SETUP_WJ_XZ = 6; //�л�������Ŀ¼�����ļ���
         returnX = 1;

     }
     else if(FAT32_ML_SETUP_WJ_XZ == 6) //����Ŀ¼�����ļ���
     {

         returnX = FAT32_ML_SETUP_WJF_RUN(FAT32_ML_SETUP_WJ_DEVICE); //����Ŀ¼�����ļ���,deviceѡ���豸,����ֵ0����,1����,2���,3�豸�ռ䲻��

         if(returnX == 3) //�豸�ռ䲻��
         {
             FAT32_ML_SETUP_WJ_XZ = 7; //��ʼ�������ļ���������(����ļ�����)
             returnX = 1;
         }

     }
     else if(FAT32_ML_SETUP_WJ_XZ == 7) //��ʼ�������ļ���������(����ļ�����)
     {

         FAT32_UP_culian(FAT32_VOID_cuhao_cuhao,0,0); //��ʼ�����´�������
         FAT32_ML_SETUP_WJ_XZ = 8; //�л������и��´�������
         returnX = 1;

     }
     else if(FAT32_ML_SETUP_WJ_XZ == 8) //���и����ļ���������(����ļ�����)
     {

         returnX = FAT32_UP_culian_RUN(FAT32_ML_SETUP_WJ_DEVICE); //���и��´�������,deviceѡ���豸,����0����,1����,2���,3�洢�豸�ռ䲻��(��������)

         if(returnX == 2) //���´����������
         {
             returnX = 3; //�豸�ռ䲻��
         }

     }


     if(returnX != 1) FAT32_ML_SETUP_WJ_XZ = 0; //����

     return returnX;

}















unsigned char FAT32_ML_DELETE_WJ(unsigned char device,unsigned long int mulu_cuhao,unsigned char *WJM) //��ʼ��Ŀ¼ɾ���ļ�,deviceѡ���豸,mulu_cuhaoΪĿ¼�״غ�,WJMΪ�ļ���,��0��Ϊ������,����ֵ0����,1���
{

unsigned char WJFDATA_32B[32];
unsigned int CWJM[404];
unsigned char returnX;

  if(FAT32_ML_SETUP_WJ_XZ == 0 && FAT32_ML_DELETE_WJ_XZ == 0 && FAT32_ML_XGWJM_XZ == 0 && FAT32_ML_XGWJDX_XZ == 0) //�����ļ�����,ɾ���ļ�����,�޸��ļ�������,�޸��ļ���С����,ȫ������ʱ����
  {

    FAT32_ML_DELETE_WJ_mulu_cuhao = mulu_cuhao; //��¼Ŀ¼���״غ�
    if(FAT32_ML_WJCX(device,mulu_cuhao,WJM,WJFDATA_32B,CWJM,1,0,0,0,0,0) == 0) return 0;

    FAT32_ML_DELETE_WJ_cuhao = WJFDATA_32B[0x15]; //��¼�ļ��״غ�
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


unsigned char FAT32_ML_DELETE_WJ_RUN() //����Ŀ¼ɾ���ļ�,����ֵ0����,1����,2���,4����
{

unsigned char returnX;

    if(FAT32_ML_DELETE_WJ_XZ == 0) //��ʼ�������ļ���������(����ļ�����)
    {
         returnX = 4;
    }
    else if(FAT32_ML_DELETE_WJ_XZ == 1) //��ʼ�������ļ���������(����ļ�����)
    {

         if(FAT32_ML_DELETE_WJ_cuhao == 0) //�غ�Ϊ0���
         {
             returnX = 2;
         }
         else
         {
             FAT32_UP_culian(FAT32_ML_DELETE_WJ_cuhao,0,0); //��ʼ�����´�������
             FAT32_ML_DELETE_WJ_XZ = 2; //�л������и��´�������
             returnX = 1;
         }

    }
    else if(FAT32_ML_DELETE_WJ_XZ == 2) //���и����ļ���������(����ļ�����)
    {
         returnX = FAT32_UP_culian_RUN(FAT32_ML_DELETE_WJ_DEVICE); //���и��´�������,deviceѡ���豸,����0����,1����,2���,3�洢�豸�ռ䲻��(��������)
    }


    if(returnX != 1) FAT32_ML_DELETE_WJ_XZ = 0; //����

    return returnX;

}




unsigned char FAT32_ML_XGWJM(unsigned char device,unsigned long int mulu_cuhao,unsigned char *WJM_,unsigned char *_WJM) //��ʼ���޸��ļ���,deviceѡ���豸,mulu_cuhaoΪĿ¼�״غ�,WJM_Ϊԭ�ļ����ļ���,_WJMΪ���ļ���
{

unsigned char GSBZ;
unsigned char WJFDATA_32B_byte_0CH;
unsigned char returnX;

unsigned char js1;

  if(FAT32_ML_SETUP_WJ_XZ == 0 && FAT32_ML_DELETE_WJ_XZ == 0 && FAT32_ML_XGWJM_XZ == 0 && FAT32_ML_XGWJDX_XZ == 0) //�����ļ�����,ɾ���ļ�����,�޸��ļ�������,�޸��ļ���С����,ȫ������ʱ����
  {

    returnX = FAT32_ML_WJCX(device,mulu_cuhao,WJM_,FAT32_ML_XGWJM_S_WJFDATA_32B,FAT32_ML_XGWJM_S_CWJM,1,0,0,0,0,0); //ȡ��ԭ�ļ���,����E5ɾ��ԭ�ļ���

    FAT32_WJMFL_DWJM_CWJM(_WJM,FAT32_ML_XGWJM_D_WJFDATA_32B,FAT32_ML_XGWJM_D_CWJM,&GSBZ,&WJFDATA_32B_byte_0CH,1); //�ļ�������

    js1 = 0x0b;
    while(js1 != 32) FAT32_ML_XGWJM_D_WJFDATA_32B[js1] = FAT32_ML_XGWJM_S_WJFDATA_32B[js1],++js1; //����ԭ�ļ�����Ϣ

    FAT32_ML_XGWJM_DEVICE = device;
    FAT32_ML_XGWJM_D_WJFDATA_32B[0x0c] = WJFDATA_32B_byte_0CH;
    FAT32_ML_XGWJM_mulu_cuhao = mulu_cuhao;
    FAT32_ML_XGWJM_XZ = 1;

    return returnX;

  }
  else return 0;

}

unsigned char FAT32_ML_XGWJM_RUN() //�����޸��ļ���,����ֵ0����,1����,2���,3�洢�豸�ռ䲻��,4����
{

unsigned char returnX;


     if(FAT32_ML_XGWJM_XZ == 0) //���
     {
         returnX = 4;

     }
     else if(FAT32_ML_XGWJM_XZ == 1) //Ŀ¼�����ļ�����ʼ��
     {

         FAT32_ML_SETUP_WJF(FAT32_ML_XGWJM_mulu_cuhao,FAT32_ML_XGWJM_D_WJFDATA_32B,FAT32_ML_XGWJM_D_CWJM,0x00); //Ŀ¼�����ļ�����ʼ��, mulu_cuhao��Ŀ¼�״غ�, WJDATA_32B��32���ֽڵ��ļ�����, WJ_CWJM���ļ��ĳ��ļ���,��0��Ϊ������,UPXλ2Ϊ1�����ļ�����ʱ�������,λ1Ϊ1�����ļ�����������,λ0Ϊ1�����ļ�����޸�ʱ�������
         FAT32_ML_XGWJM_XZ = 2; //�л�������Ŀ¼�����ļ���
         returnX = 1;

     }
     else if(FAT32_ML_XGWJM_XZ == 2) //����Ŀ¼�����ļ���
     {

         returnX = FAT32_ML_SETUP_WJF_RUN(FAT32_ML_XGWJM_DEVICE); //����Ŀ¼�����ļ���,deviceѡ���豸,����ֵ0����,1����,2���,3�豸�ռ䲻��

         if(returnX == 3) //�豸�ռ䲻��
         {
             FAT32_ML_XGWJM_XZ = 3; //�л���Ŀ¼�����ļ�����ʼ��(�ָ�ԭ�ļ���)
             returnX = 1;
         }

     }
     else if(FAT32_ML_XGWJM_XZ == 3) //Ŀ¼�����ļ�����ʼ��(�ָ�ԭ�ļ���)
     {

         FAT32_ML_SETUP_WJF(FAT32_ML_XGWJM_mulu_cuhao,FAT32_ML_XGWJM_S_WJFDATA_32B,FAT32_ML_XGWJM_S_CWJM,0x00); //Ŀ¼�����ļ�����ʼ��, mulu_cuhao��Ŀ¼�״غ�, WJDATA_32B��32���ֽڵ��ļ�����, WJ_CWJM���ļ��ĳ��ļ���,��0��Ϊ������,UPXλ2Ϊ1�����ļ�����ʱ�������,λ1Ϊ1�����ļ�����������,λ0Ϊ1�����ļ�����޸�ʱ�������
         FAT32_ML_XGWJM_XZ = 4; //�л�������Ŀ¼�����ļ���
         returnX = 1;

     }
     else if(FAT32_ML_XGWJM_XZ == 4) //����Ŀ¼�����ļ���(�ָ�ԭ�ļ���)
     {

         returnX = FAT32_ML_SETUP_WJF_RUN(FAT32_ML_XGWJM_DEVICE); //����Ŀ¼�����ļ���,deviceѡ���豸,����ֵ0����,1����,2���,3�豸�ռ䲻��

     }


     if(returnX != 1) FAT32_ML_XGWJM_XZ = 0; //����

     return returnX;

}


unsigned char FAT32_LJ_WJCX(unsigned char device,unsigned long int mulu_cuhao,unsigned char *WJLJ,unsigned char *RETURN_WJFDATA_32B,unsigned int *RETURN_CWJM) //·���ļ���ѯ,deviceѡ���豸,mulu_cuhaoΪĿ¼�״غ�,WJLJΪ�ļ�·��,0��Ϊ������,RETURN_WJFDATA_32BΪ���ص�32���ֽ��ļ�������,RETURN_CWJMΪ���صĳ��ļ���,��0��Ϊ������
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

          if(_WJM == 0) //�ļ�·������
          {

              WJM[WJM_smzz] = 0; //��0������
              return FAT32_ML_WJCX(device,mulu_cuhao,WJM,RETURN_WJFDATA_32B,RETURN_CWJM,0,0,0,0,0,0); //��ѯ��Ŀ¼�ļ�

          }
          else if(_WJM == '\') //Ŀ¼��
          {

              WJM[WJM_smzz] = 0; //��0������
              if(FAT32_ML_WJCX(device,mulu_cuhao,WJM,RETURN_WJFDATA_32B,RETURN_CWJM,0,0,0,0,0,0) != 1) return 0; //��ѯ��Ŀ¼�ļ�

              if((RETURN_WJFDATA_32B[0x0b] & 0xf0) == 0x10) //��Ŀ¼
              {

                  mulu_cuhao = RETURN_WJFDATA_32B[0x15]; //��¼�ļ��״غ�
                  mulu_cuhao <<= 8;
                  mulu_cuhao |= RETURN_WJFDATA_32B[0x14];
                  mulu_cuhao <<= 8;
                  mulu_cuhao |= RETURN_WJFDATA_32B[0x1b];
                  mulu_cuhao <<= 8;
                  mulu_cuhao |= RETURN_WJFDATA_32B[0x1a];

                  WJM_smzz = 0;

              }
              else //����Ŀ¼
              {
                  return 0;
              }

          }
          else //�ļ���
          {

              WJM[WJM_smzz] = _WJM;
              ++WJM_smzz;

          }


     }


}




unsigned char FAT32_GET_VOID_RWWJ_BZ(unsigned int device) //������е��ļ���,����255��ʾû�п��е��ļ���
{

unsigned char *_addr;
unsigned char smzz;

   _addr = FAT32_RWWJ_bz + device*FAT32_RWWJ_WJX;

   for(smzz = 0;smzz != FAT32_RWWJ_WJX && _addr[smzz] != 0;++smzz); //�ҿձ�־

   return smzz != FAT32_RWWJ_WJX ? smzz : 255;
}

void FAT32_GBWJ(unsigned int device,unsigned int wjx) //�ر��ļ�
{
   FAT32_RWWJ_bz[device*FAT32_RWWJ_WJX+wjx] = 0;
}



unsigned char FAT32_RWWJ_512B_BJ(unsigned char rw,unsigned int device,unsigned int wjx,unsigned char *buf) //��д�ļ�512�ֽڲ���,rw=1Ϊ��,rw=0Ϊд,deviceѡ���豸,wjx�ļ���,buf������,����ֵ0����,1����,2���
{

//�Ż��� ��ʡ6KB��ROM


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



   if(*a_bz != 0) //�ж��ļ��Ƿ��
   {

        if(*a_sqh_ == *a__sqh) //һ���ص���������,���뻻��
        {

                culianX = *a_culianX;
                cuhao = FAT32_RWWJ_culian[addry + culianX];


                if(cuhao == 0x0fffffff || cuhao == 0x00000000)
                {
                    *a_bz = 0; //�ļ�ʣ���СС�ڻ����512�ֽ�,��־�ļ��ر�
                    *a_wjdx = 0; //�ļ�ʣ���С����0
                    return 0; //Ϊ�ؽ�����־��ϴ�,���봦��
                }

                sqh_= FAT32_cuhao_shanquhao(device,cuhao); //�غ�ת��������
                *a_sqh_ = sqh_;
                *a__sqh = sqh_ + FAT32_cudx[device]; //��¼�ص�β��������һ������

                if(culianX == FAT32_RWWJ_CLX - 1) //β��? ������´���
                {
                    if(FAT32_cuhao_culian(device,cuhao,FAT32_RWWJ_CLX,&FAT32_RWWJ_culian[addry]) == 0) return 0; //����β��ָ�������16���طŵ�����������,�������,���봦��

                    *a_culianX = 0; //��ָ��ָ���״�
                }
                else
                {
                    ++*a_culianX; //ָ����һ���غ�
                }

        }

        sqh_ = *a_sqh_++; //ָ����һ������

        if(rw == 1 && DEVICE_RD_512B(device,sqh_,buf) == 0 || rw == 0 && DEVICE_WR_512B(device,sqh_,buf) == 0) return 0; //����һ��������������,�������,���봦��

//        ++*a_sqh_; //ָ����һ������

        if(*a_wjdx <= 512)
        {
           *a_bz = 0; //�ļ�ʣ���СС�ڻ����512�ֽ�,��־�ļ��ر�
           *a_wjdx = 0; //�ļ�ʣ���С����0
        }
        else *a_wjdx -= 512; //�ļ�ʣ���С��512�ֽ�

        return 1;

   }else return 2;

}


unsigned char FAT32_RDWJ_512B(unsigned char device,unsigned char wjx,unsigned char *buf) //���ļ�512�ֽ�,deviceѡ���豸,wjx�ļ���,buf������,����ֵ��Ϊ0��ʾ�����ɹ�
{

   return FAT32_RWWJ_512B_BJ(1,device,wjx,buf);

}


unsigned char FAT32_WRWJ_512B(unsigned char device,unsigned char wjx,unsigned char *buf) //д�ļ�512�ֽ�,deviceѡ���豸,wjx�ļ���,buf������,����ֵ��Ϊ0��ʾ�����ɹ�
{

   return FAT32_RWWJ_512B_BJ(0,device,wjx,buf);

}


unsigned char FAT32_OPENWJ(unsigned int device,unsigned long int mulu_cuhao,unsigned int wjx,unsigned char *wjlj) //���ļ�,deviceѡ���豸,mulu_cuhaoָ����ʼĿ¼�״غ�,wjx�ļ���,wjlj�ļ�·��,��0��Ϊ·��������,����ֵ��Ϊ0��ʾ�����ɹ�
{

unsigned char buf[32];
unsigned long int js1;

unsigned int addrx;

unsigned int RETURN_CWJM[404];


   addrx = device*FAT32_RWWJ_WJX + wjx;

   if(FAT32_LJ_WJCX(device,mulu_cuhao,wjlj,buf,RETURN_CWJM) == 0) return 0; //��ѯ�ļ�

   js1 = buf[0x15]; //��¼�ļ��״غ�
   js1 <<= 8;
   js1 |= buf[0x14];
   js1 <<= 8;
   js1 |= buf[0x1b];
   js1 <<= 8;
   js1 |= buf[0x1a];

   FAT32_RWWJ_cuhao[addrx] = js1; //��¼�ļ��״غ�
   FAT32_RWWJ_culian[(device*(FAT32_RWWJ_WJX*FAT32_RWWJ_CLX))+(wjx*FAT32_RWWJ_CLX) + (FAT32_RWWJ_CLX - 1)] = js1; //�ļ��״غŷŵ�����β��
   FAT32_RWWJ_culianX[addrx] = FAT32_RWWJ_CLX - 1; //����ָ��ָ�����β��


   js1 = buf[0x1f]; //��¼�ļ���С
   js1 <<= 8;
   js1 |= buf[0x1e];
   js1 <<= 8;
   js1 |= buf[0x1d];
   js1 <<= 8;
   js1 |= buf[0x1c];

   FAT32_RWWJ__wjdx[addrx] = js1; //��¼�ļ���С���ļ�ʣ���С
   FAT32_RWWJ_wjdx_[addrx] = js1; //��¼�ļ���С���ļ��ܴ�С

   if(js1 != 0)
   {
      FAT32_RWWJ_bz[addrx] = 1; //�ļ���С��Ϊ0,��־�ļ���
      FAT32_RWWJ_sqh_[addrx] = FAT32_RWWJ__sqh[addrx]; //����������ָ��ʹ�β������+1ָ��ֵͬ
   }

   return 1;

}



unsigned long int FAT32_RETURN_WJDX_(unsigned int device,unsigned int wjx) //ȡ�ļ��ܴ�С,deviceѡ���豸,wjx�ļ���,����ֵΪ�ļ���С,��λ�ֽ�
{
   return FAT32_RWWJ_wjdx_[device*FAT32_RWWJ_WJX + wjx];
}


unsigned long int FAT32_RETURN__WJDX(unsigned int device,unsigned int wjx) //ȡ�ļ���дʣ���С,deviceѡ���豸,wjx�ļ���,����ֵΪ�ļ���С,��λ�ֽ�
{
   return FAT32_RWWJ__wjdx[device*FAT32_RWWJ_WJX + wjx];
}

unsigned long int FAT32_RETURN_WJ_cuhao(unsigned int device,unsigned int wjx) //ȡ�ļ��״غ�,deviceѡ���豸,wjx�ļ���,����ֵΪ�ļ��״غ�
{
   return FAT32_RWWJ_cuhao[device*FAT32_RWWJ_WJX + wjx];
}


/*
unsigned char FAT32_RWWJ_SETLBA(unsigned int device,unsigned int wjx,unsigned long int LBA) //���ö�д�ļ���ʼ����,deviceѡ���豸,wjx�ļ���,LBA�ļ��߼�������,����ֵ��Ϊ0��ʾ�����ɹ�
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



   if(FAT32_RWWJ_bz[addrx] == 1) //�ж��ļ��Ƿ��
   {

       culian[15] = FAT32_RWWJ_cuhao[addrx]; //�ļ��״غŷŵ�����β��
       culianX = 15; //����ָ��ָ�����β��
       _wjdx = FAT32_RWWJ_wjdx_[addrx];  //��¼�ļ���С���ļ�ʣ���С
       sqh_ = _sqh;
       js1 = 0;

       while(js1 != LBA)
       {

           if(sqh_ == _sqh) //һ���ص���������,���뻻��
           {

                cuhao = culian[culianX];

                if(cuhao == 0x0fffffff) return 0; //Ϊ�ؽ�����־,���봦��

                sqh_ = FAT32_cuhao_shanquhao(device,cuhao); //�غ�ת��������
                _sqh = sqh_ + FAT32_cudx[device]; //��¼�ص�β��������һ������

                if(culianX == 15) //β��? ������´���
                {
                    if(FAT32_cuhao_culian(device,culian[15],16,culian) == 0) return 0; //����β��ָ�������16���طŵ�����������,�������,���봦��
                    culianX = 0; //��ָ��ָ���״�
                }
                else
                {
                    ++culianX; //ָ����һ���غ�
                }

           }

           if(_wjdx <= 512) break;
           ++sqh_; //ָ����һ������
           ++js1; //����������1
           _wjdx -= 512; //�ļ�ʣ���С��512�ֽ�

       }

       FAT32_RWWJ__wjdx[addrx] = _wjdx;
       FAT32_RWWJ_culian[(device*(FAT32_RWWJ_WJX*FAT32_RWWJ_CLX))+(wjx*FAT32_RWWJ_CLX) + (FAT32_RWWJ_CLX - 1)] = culian[culianX]; //�ļ��״غŷŵ�����β��
       FAT32_RWWJ_culianX[addrx] = FAT32_RWWJ_CLX - 1; //����ָ��ָ�����β��
       FAT32_RWWJ_sqh_[addrx] = sqh_;
       FAT32_RWWJ__sqh[addrx] = _sqh;

       return 1;

   }else return 0;

}
*/

unsigned char FAT32_RWWJ_SETLBA(unsigned int device,unsigned int wjx,unsigned long int LBA) //���ö�д�ļ���ʼ����,deviceѡ���豸,wjx�ļ���,LBA�ļ��߼�������,����ֵ��Ϊ0��ʾ�����ɹ�
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


   if(FAT32_RWWJ_bz[addrx] == 1) //�ж��ļ��Ƿ��
   {

       js1 = LBA << 9; //��512����ļ���С(�ֽ�)
       js2 = FAT32_RWWJ_wjdx_[addrx]; //�����ļ��ܴ�С(�ֽ�)

       if(js1 >= js2) //���õ����������ļ���Χ
       {
           LBA = js2 >> 9 + (js2 % 512 != 0) - 1; //LBA����Ϊ�ļ����һ������
       }
       else
       {
           _wjdx = js2 - js1; //���ʣ���ļ���С
       }

       js1 = FAT32_cudx[device];
       cuX = LBA / js1; //���������
       sqh_ = LBA % js1; //�����������ƫ��

       culian[127] = FAT32_RWWJ_cuhao[addrx]; //�ļ��״غŷŵ�����β��
       culianX = 127; //��ָ��ָ�����һ����
       cuX_J = 0;


       while(cuX_J != cuX)
       {

           js1 = culian[culianX];
           if(js1 == 0x0fffffff || js1 == 0x00000000) break;

           if(culianX == 127) //β��? ������´���
           {
               if(FAT32_cuhao_culian(device,culian[127],128,culian) == 0) return 0; //����β��ָ�������128���طŵ�����������,�������,���봦��
               culianX = 0; //��ָ��ָ���״�
           }
           else
           {
               ++culianX; //ָ����һ���غ�
           }

           ++cuX_J; //�ؼ���

       }


       js1 = culian[culianX]; //�����غ�

       FAT32_RWWJ__wjdx[addrx] = _wjdx; //��д�ļ�ʣ���С
       FAT32_RWWJ_culian[(device*(FAT32_RWWJ_WJX*FAT32_RWWJ_CLX))+(wjx*FAT32_RWWJ_CLX) + (FAT32_RWWJ_CLX - 1)] = js1; //�ļ��״غŷŵ�����β��
       FAT32_RWWJ_culianX[addrx] = FAT32_RWWJ_CLX - 1; //����ָ��ָ�����β��

       js2 = FAT32_cuhao_shanquhao(device,js1); //�غ�ת��������
       FAT32_RWWJ_sqh_[addrx] = js2 + sqh_;  //��д���������Ӵ�������ƫ��
       FAT32_RWWJ__sqh[addrx] = js2 + FAT32_cudx[device];  //��д��β������+1

       return 1;


   }else return 0;

}



unsigned char FAT32_ML_XGWJDX(unsigned char device,unsigned long int mulu_cuhao,unsigned char *WJM,unsigned long int WJDX) //��ʼ���޸��ļ���С,deviceѡ���豸,mulu_cuhaoΪĿ¼�״غ�,WJMΪ�ļ���,WJDXΪ�ļ���С,����ֵΪ1�ɹ�
{

unsigned char WJFDATA_32B[32];
unsigned int CWJM[404];
unsigned char returnX;

unsigned char XGCH;

  if(FAT32_ML_SETUP_WJ_XZ == 0 && FAT32_ML_DELETE_WJ_XZ == 0 && FAT32_ML_XGWJM_XZ == 0 && FAT32_ML_XGWJDX_XZ == 0) //�����ļ�����,ɾ���ļ�����,�޸��ļ�������,�޸��ļ���С����,ȫ������ʱ����
  {

    XGCH = 0;
    if(WJDX == 0) XGCH = 1; //����ļ���СΪ0,�޸Ĵغ�

    returnX = FAT32_ML_WJCX(device,mulu_cuhao,WJM,WJFDATA_32B,CWJM,0,1,WJDX,XGCH,0,0x03); //�޸��ļ���С,����ļ���СΪ0,�غ���0


    FAT32_ML_XGWJDX_WJDX_ = WJFDATA_32B[0x1f]; //��¼�ļ���ԭ��С
    FAT32_ML_XGWJDX_WJDX_ <<= 8;
    FAT32_ML_XGWJDX_WJDX_ |= WJFDATA_32B[0x1e];
    FAT32_ML_XGWJDX_WJDX_ <<= 8;
    FAT32_ML_XGWJDX_WJDX_ |= WJFDATA_32B[0x1d];
    FAT32_ML_XGWJDX_WJDX_ <<= 8;
    FAT32_ML_XGWJDX_WJDX_ |= WJFDATA_32B[0x1c];

    FAT32_ML_XGWJDX_WJ_cuhao = WJFDATA_32B[0x15]; //��¼�ļ��Ĵغ�
    FAT32_ML_XGWJDX_WJ_cuhao <<= 8;
    FAT32_ML_XGWJDX_WJ_cuhao |= WJFDATA_32B[0x14];
    FAT32_ML_XGWJDX_WJ_cuhao <<= 8;
    FAT32_ML_XGWJDX_WJ_cuhao |= WJFDATA_32B[0x1b];
    FAT32_ML_XGWJDX_WJ_cuhao <<= 8;
    FAT32_ML_XGWJDX_WJ_cuhao |= WJFDATA_32B[0x1a];

    FAT32_ML_XGWJDX__WJDX = WJDX; //��¼�ļ����´�С
    FAT32_ML_XGWJDX_mulu_cuhao = mulu_cuhao; //��¼�ļ�����Ŀ¼�غ�
    FAT32_ML_XGWJDX_WJM = WJM; //��¼�ļ�����ַ
    FAT32_ML_XGWJDX_WJKCBZ = 0; //�մر�־��0

    FAT32_ML_XGWJDX_DEVICE = device;

    if(WJDX == 0) //�޸��ļ���СΪ0�ֽ�
    {
        if(FAT32_ML_XGWJDX_WJ_cuhao == 0) //�ļ��غ�Ϊ0
        {
            FAT32_ML_XGWJDX_XZ = 5; //���
        }
        else //�ļ��غŲ�Ϊ0
        {
            FAT32_ML_XGWJDX_XZ = 3; //��ʼ�������ļ���������(ɾ������)
        }
    }
    else //�޸��ļ���С��Ϊ0�ֽ�
    {
        if(FAT32_ML_XGWJDX_WJ_cuhao == 0) //�ļ��غ�Ϊ0
        {
            FAT32_ML_XGWJDX_WJKCBZ = 1; //��־�մ�
            FAT32_ML_XGWJDX_XZ = 1; //��ʼ��ɨ��հ״�
        }
        else //�ļ��غŲ�Ϊ0
        {
            FAT32_ML_XGWJDX_XZ = 3; //��ʼ�������ļ���������
        }
    }


    return returnX;

  }
  else return 0;

}


unsigned char FAT32_ML_XGWJDX_RUN() //�����޸��ļ���С,����ֵ0����,1����,2���,3�洢�豸�ռ䲻��,4����
{

unsigned int CWJM[404];
unsigned char WJFDATA_32B[32];
unsigned char returnX;


    if(FAT32_ML_XGWJDX_XZ == 0)
    {
        returnX = 4; //����

    }
    else if(FAT32_ML_XGWJDX_XZ == 1) //��ʼ��ɨ��հ״�
    {

        FAT32_VOID_cuhao(FAT32_ML_XGWJDX_DEVICE,0); //��ʼ��ɨ��հ״�,0ΪɨFAT1
        FAT32_ML_XGWJDX_XZ = 2; //�л�������ɨ��հ״�
        returnX = 1;

    }
    else if(FAT32_ML_XGWJDX_XZ == 2) //����ɨ��հ״�
    {

        returnX = FAT32_VOID_cuhao_RUN(FAT32_ML_XGWJDX_DEVICE); //����ɨ��հ״�

        if(returnX == 2) //�ҵ��հ״�
        {
            returnX = FAT32_ML_WJCX(FAT32_ML_XGWJDX_DEVICE,FAT32_ML_XGWJDX_mulu_cuhao,FAT32_ML_XGWJDX_WJM,WJFDATA_32B,CWJM,0,0,0,1,FAT32_VOID_cuhao_cuhao,0); //���ļ��غ�

            FAT32_ML_XGWJDX_WJ_cuhao = FAT32_VOID_cuhao_cuhao; //�մؼ�¼���ļ��״غ�
            FAT32_ML_XGWJDX_XZ = 3; //�л�����ʼ�������ļ���������

        }
        else if(returnX == 3) //û���ҵ��հ״�
        {
            returnX = FAT32_ML_WJCX(FAT32_ML_XGWJDX_DEVICE,FAT32_ML_XGWJDX_mulu_cuhao,FAT32_ML_XGWJDX_WJM,WJFDATA_32B,CWJM,0,1,0,0,0,0); //��ԭ�ļ���С
            if(returnX == 1) returnX = 3; //û���ҵ��հ״�,�洢�ռ䲻��
        }

    }
    else if(FAT32_ML_XGWJDX_XZ == 3) //��ʼ�������ļ���������
    {

         FAT32_UP_culian(FAT32_ML_XGWJDX_WJ_cuhao,FAT32_ML_XGWJDX__WJDX,0); //��ʼ�����´�������
         FAT32_ML_XGWJDX_XZ = 4; //�л������и��´�������
         returnX = 1;

    }
    else if(FAT32_ML_XGWJDX_XZ == 4) //���и����ļ���������
    {

         returnX = FAT32_UP_culian_RUN(FAT32_ML_XGWJDX_DEVICE); //���и��´�������

         if(returnX == 3) //�洢�豸�ռ䲻��
         {
             returnX = FAT32_ML_WJCX(FAT32_ML_XGWJDX_DEVICE,FAT32_ML_XGWJDX_mulu_cuhao,FAT32_ML_XGWJDX_WJM,WJFDATA_32B,CWJM,0,1,FAT32_ML_XGWJDX_WJDX_,FAT32_ML_XGWJDX_WJKCBZ,0,0); //��ԭ�ļ���С�ʹغ�
             if(returnX == 1) returnX = 3; //�洢�豸�ռ䲻��
         }

    }
    else if(FAT32_ML_XGWJDX_XZ == 5) //���
    {
         returnX = 2; //���
    }


    if(returnX != 1) FAT32_ML_XGWJDX_XZ = 0; //����

    return returnX;


}



