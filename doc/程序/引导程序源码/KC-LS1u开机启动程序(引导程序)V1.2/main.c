#include<io.h>
#include<qjbldy.h>
#include<spi.h>
#include<tf_sd.h>
#include<fat32.h>
#include<VGA.h>


void speaker(unsigned int sj,unsigned int pl) //������,sjΪ����ʱ��,plΪƵ��
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


void cw_0() //����0
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

void cw_1() //����1
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

void cw_2() //����2
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


void spi_device_boot()  //SROM����װ�ط������
{

unsigned char device;
unsigned int KC_LS1u_boot_0_txt[] = {'K' , 'C' , '_' , 'L' , 'S' , '1' , 'u' , '_' , 'b' , 'o' , 'o' , 't' , '_' , '0' , '.' , 't' , 'x' , 't' , 0};
unsigned int KC_LS1u_boot_1_txt[] = {'K' , 'C' , '_' , 'L' , 'S' , '1' , 'u' , '_' , 'b' , 'o' , 'o' , 't' , '_' , '1' , '.' , 't' , 'x' , 't' , 0};
unsigned char wj_data_32B[32];
unsigned long int culian[128]; //����
unsigned char culian_x; //��ָ��,����ָ��������Ĵغ�
unsigned long int sqh_; //�ص���������
unsigned long int _sqh; //�ص�β������+1
unsigned long int wj_cuhao; //��¼�ļ��״غ�
unsigned long int wj_dx; //��¼�ļ���С
unsigned char buf[512]; //512�ֽڻ�����
unsigned int _buf[513]; //512˫�ֻ�����
unsigned char ROM_K = 0; //ROM_L��ROM_Hװ���л�����,Ϊ0װ��ROM_L,Ϊ1װ��ROM_H
unsigned int js1; //����1
unsigned long int js2; //����2
unsigned char Y = 36; //��ʾ��Ϣ��Y����
unsigned char device_bz = 0; //SPI�豸��ʼ���ɹ���־,λ0ΪSPI�豸0,λ1ΪSPI�豸1,��1��ʾ��ʼ���ɹ�
unsigned int i; //��ʱ����
unsigned char sq_x = 0; //��������
unsigned long int jdt_x_10M = 0; //220�̶�����Ľ�����λ�õ�1ǧ��
unsigned char *_SROM_L; //SROM_Lװ�ؽ�����ַ
unsigned char *_SROM_H; //SROM_Hװ�ؽ�����ַ
unsigned char *SROM_L_; //SROM_Lװ��ָ��
unsigned char *SROM_H_; //SROM_Hװ��ָ��



 CTVGA_C &= ~0x01; //�������VGA
 for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
 VGA_kuang_0(16,16,175,223,238); //����
 VGA_SK_1(33,16,1,224,238);
 VGA_SROMSJZZFWCX_logo(19,68,255); //"SROM����װ�ط������"����
 VGA_kuang_0(208,16,15,223,0x1c); //���������
 VGA_bfb_logo(210,115,0,255); //�������ٷֱ�
 CTVGA_C |= 0x01; //����VGA��ʾ
 for(i = 0;i < 16000;i++);




      CTVGA_C &= ~0x01; //�������VGA
      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
      VGA_spi_device_csh_logo(Y,17,0,255);//"��ʼ��SPI�豸0�ڴ濨..."
      CTVGA_C |= 0x01; //����VGA��ʾ
      for(i = 0;i < 16000;i++);

      CTVGA_C &= ~0x01; //�������VGA
      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
      if(TF_SD_CSH(0) != 0) device_bz = 0x01,VGA_cshwc_logo(Y+=13,17,255); //�豸0��ʼ���ɹ�
      else VGA_cshsb_logo(Y+=13,17,255); //�豸0��ʼ��ʧ��
      CTVGA_C |= 0x01; //����VGA��ʾ
      for(i = 0;i < 16000;i++);


      CTVGA_C &= ~0x01; //�������VGA
      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
      VGA_spi_device_csh_logo(Y+=13,17,1,255);//"��ʼ��SPI�豸1�ڴ濨..."
      CTVGA_C |= 0x01; //����VGA��ʾ
      for(i = 0;i < 16000;i++);

      CTVGA_C &= ~0x01; //�������VGA
      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
      if(TF_SD_CSH(1) != 0) device_bz |= 0x02,VGA_cshwc_logo(Y+=13,17,255); //�豸1��ʼ���ɹ�
      else VGA_cshsb_logo(Y+=13,17,255); //�豸1��ʼ��ʧ��
      CTVGA_C |= 0x01; //����VGA��ʾ
      for(i = 0;i < 16000;i++);



           if((device_bz & 0x01) == 0x01) device = 0; //ʹ��SPI�豸0
      else if((device_bz & 0x02) == 0x02) device = 1; //ʹ��SPI�豸1
      else //�����豸��û�г�ʼ���ɹ�,���봦��
      {
         _A = 0xaa; //A�Ĵ�����ʾ0xaa
         _B = 0x01; //B�Ĵ�����ʾ0x01
         while(1);
      }






      CTVGA_C &= ~0x01; //�������VGA
      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
      VGA_spi_device_boot_txt_logo(Y+=13,17,device,(XT_C & 0x10) >> 4,255); //"����SPI�豸X�ڴ濨����X�ı�..."
      CTVGA_C |= 0x01; //����VGA��ʾ
      for(i = 0;i < 16000;i++);


      if(FAT32_csh(device) != 0  &&  ( (XT_C & 0x10) == 0x00 && FAT32_wjcx_1(device,KC_LS1u_boot_0_txt,wj_data_32B) != 0  ||  (XT_C & 0x10) == 0x10 && FAT32_wjcx_1(device,KC_LS1u_boot_1_txt,wj_data_32B) != 0 ) ) //��ʼ��FAT32,���Ҳ��������ı�,ִ�гɹ����봦��
      {
         CTVGA_C &= ~0x01; //�������VGA
         for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
         VGA_zdwb_logo(Y+=13,17,255); //"�ҵ��ı�"
         CTVGA_C |= 0x01; //����VGA��ʾ
         for(i = 0;i < 16000;i++);
      }
      else
      {
         CTVGA_C &= ~0x01; //�������VGA
         for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
         VGA_myzdwb_logo(Y+=13,17,255); //"û���ҵ��ı�"
         CTVGA_C |= 0x01; //����VGA��ʾ
         for(i = 0;i < 16000;i++);

         if(device == 0 && (device_bz & 0x02) == 0x02) //ʧ�ܵ����豸0�����豸1����,���봦��
         {

              device = 1; //�л�Ϊ�豸1

              CTVGA_C &= ~0x01; //�������VGA
              for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
              VGA_spi_device_boot_txt_logo(Y+=13,17,device,(XT_C & 0x10) >> 4,255); //"����SPI�豸X�ڴ濨����X�ı�..."
              CTVGA_C |= 0x01; //����VGA��ʾ
              for(i = 0;i < 16000;i++);

              if(FAT32_csh(device) != 0  &&  ( (XT_C & 0x10) == 0x00 && FAT32_wjcx_1(device,KC_LS1u_boot_0_txt,wj_data_32B) != 0  ||  (XT_C & 0x10) == 0x10 && FAT32_wjcx_1(device,KC_LS1u_boot_1_txt,wj_data_32B) != 0 ) ) //��ʼ��FAT32,���Ҳ��������ı�,ִ�гɹ����봦��
              {
                 CTVGA_C &= ~0x01; //�������VGA
                 for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
                 VGA_zdwb_logo(Y+=13,17,255); //"�ҵ��ı�"
                 CTVGA_C |= 0x01; //����VGA��ʾ
                 for(i = 0;i < 16000;i++);
              }
              else
              {
                 CTVGA_C &= ~0x01; //�������VGA
                 for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
                 VGA_myzdwb_logo(Y+=13,17,255); //"û���ҵ��ı�"
                 CTVGA_C |= 0x01; //����VGA��ʾ
                 _A = 0xaa; //A�Ĵ�����ʾ0xaa
                 _B = 0x03; //B�Ĵ�����ʾ0x03
                 while(1);
              }

         }
         else
         {
            _A = 0xaa; //A�Ĵ�����ʾ0xaa
            _B = 0x02; //B�Ĵ�����ʾ0x02
            while(1);
         }

      }



      wj_cuhao = wj_data_32B[0x15]; //��¼�ļ��״غ�
      wj_cuhao <<= 8;
      wj_cuhao |= wj_data_32B[0x14];
      wj_cuhao <<= 8;
      wj_cuhao |= wj_data_32B[0x1b];
      wj_cuhao <<= 8;
      wj_cuhao |= wj_data_32B[0x1a];

      wj_dx = wj_data_32B[0x1f]; //��¼�ļ���С
      wj_dx <<= 8;
      wj_dx |= wj_data_32B[0x1e];
      wj_dx <<= 8;
      wj_dx |= wj_data_32B[0x1d];
      wj_dx <<= 8;
      wj_dx |= wj_data_32B[0x1c];


      if(wj_dx > 512 || wj_dx < 13) //�ļ���С��Χ����,���봦��
      {
          CTVGA_C &= ~0x01; //�������VGA
          for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
          VGA_wjljcw_logo(Y+=13,17,255); //"�ļ�·������"
          CTVGA_C |= 0x01; //����VGA��ʾ
          cw_2(); //���󱨾�
          _A = 0xaa; //A�Ĵ�����ʾ0xaa
          _B = 0x04; //B�Ĵ�����ʾ0x04
          while(1);
      }



      if(TF_SD_RD_512B(device,FAT32_cuhao_shanquhao(device,wj_cuhao),buf) == 0) //������������ļ�·�����ı���512B,û�в����ɹ����봦��
      {
          CTVGA_C &= ~0x01; //�������VGA
          for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
          VGA_spisbcw_logo(Y+=13,17,255); //"SPI�豸����"
          CTVGA_C |= 0x01; //����VGA��ʾ
          cw_0(); //���󱨾�
          _A = 0xaa; //A�Ĵ�����ʾ0xaa
          _B = 0x05; //B�Ĵ�����ʾ0x05
          while(1);
      }

      if(buf[0] != 's' || buf[1] != 'p' || buf[2] != 'i' || buf[3] != '_' || buf[4] != 'd' || buf[5] != 'e' || buf[6] != 'v' || buf[7] != 'i' || buf[8] != 'c' || buf[9] != 'e' || buf[11] != ':') //�豸�������Խ��봦��
      {
          CTVGA_C &= ~0x01; //�������VGA
          for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
          VGA_wjljcw_logo(Y+=13,17,255); //"�ļ�·������"
          CTVGA_C |= 0x01; //����VGA��ʾ
          cw_2(); //���󱨾�
          _A = 0xaa; //A�Ĵ�����ʾ0xaa
          _B = 0x06; //B�Ĵ�����ʾ0x06
          while(1);
      }

      if(buf[10] == '0') device = 0;
      else if(buf[10] == '1') device = 1;
      else if(buf[10] == '_');
      else //�豸�������Խ��봦��
      {
          CTVGA_C &= ~0x01; //�������VGA
          for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
          VGA_wjljcw_logo(Y+=13,17,255); //"�ļ�·������"
          CTVGA_C |= 0x01; //����VGA��ʾ
          cw_2(); //���󱨾�
          _A = 0xaa; //A�Ĵ�����ʾ0xaa
          _B = 0x07; //B�Ĵ�����ʾ0x07
          while(1);
      }

      for(js1 = 0;js1 != 512;++js1) _buf[js1] = buf[js1]; //�ֽڻ���������ת��˫�ֻ�����
      _buf[wj_dx] = 0; //��·��������0







      CTVGA_C &= ~0x01; //�������VGA
      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
      VGA_ssmbwj_logo(Y+=13,17,device,_buf + 12,255); //"����Ŀ���ļ�(SPI�豸X):�ļ�·��"
      CTVGA_C |= 0x01; //����VGA��ʾ
      for(i = 0;i < 16000;i++);


      if(FAT32_wjcx_1(device,_buf + 12,wj_data_32B) == 0) //����ROM�����ļ�,û�ҵ����봦��
      {
          CTVGA_C &= ~0x01; //�������VGA
          for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
          VGA_myzdmbwj_logo(Y+=13,17,255); //"û���ҵ�Ŀ���ļ�"
          CTVGA_C |= 0x01; //����VGA��ʾ
          _A = 0xaa; //A�Ĵ�����ʾ0xaa
          _B = 0x08; //B�Ĵ�����ʾ0x08
          while(1);
      }

      CTVGA_C &= ~0x01; //�������VGA
      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
      VGA_zdmbwj_logo(Y+=13,17,255); //"�ҵ�Ŀ���ļ�"
      CTVGA_C |= 0x01; //����VGA��ʾ
      for(i = 0;i < 16000;i++);

      wj_cuhao = wj_data_32B[0x15]; //��¼ROM�����ļ��״غ�
      wj_cuhao <<= 8;
      wj_cuhao |= wj_data_32B[0x14];
      wj_cuhao <<= 8;
      wj_cuhao |= wj_data_32B[0x1b];
      wj_cuhao <<= 8;
      wj_cuhao |= wj_data_32B[0x1a];

      wj_dx = wj_data_32B[0x1f]; //��¼ROM�����ļ���С
      wj_dx <<= 8;
      wj_dx |= wj_data_32B[0x1e];
      wj_dx <<= 8;
      wj_dx |= wj_data_32B[0x1d];
      wj_dx <<= 8;
      wj_dx |= wj_data_32B[0x1c];



      CTVGA_C &= ~0x01; //�������VGA
      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
      VGA_mbwjdx_logo(Y+=13,17,wj_dx,255); //"Ŀ���ļ���С:x�ֽ�"
      CTVGA_C |= 0x01; //����VGA��ʾ
      for(i = 0;i < 16000;i++);

      if(wj_dx < 2 || (wj_dx & 0x00000001) == 1 || wj_dx > 4194304)
      {
          CTVGA_C &= ~0x01; //�������VGA
          for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
          if(Y > 153) VGA_wbsy(),Y=153; //������ӡ��Χ,����
          VGA_mbwjdxcw_logo(Y+=13,17,255); //"Ŀ���ļ���С����"
          CTVGA_C |= 0x01; //����VGA��ʾ
          _A = 0xaa; //A�Ĵ�����ʾ0xaa
          _B = 0x09; //B�Ĵ�����ʾ0x09
          while(1);
      }



      js2 = 0;              //���SROM�ڴ��С

      do
      {
         SROM_L[js2] = 0xaa;
         SROM_L[js2+1] = 0x50;
         SROM_H[js2] = 0x55;
         SROM_H[js2+1] = 0x0a;
         if(SROM_L[js2] == 0xaa && SROM_H[js2] != 0x55 || SROM_L[js2] != 0xaa && SROM_H[js2] == 0x55) //�ڴ����
         {
            CTVGA_C &= ~0x01; //�������VGA
            for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
            if(Y > 153) VGA_wbsy(),Y=153; //������ӡ��Χ,����
            VGA_sromnccw_logo(Y+=13,17,255); //"SROM�ڴ����"
            CTVGA_C |= 0x01; //����VGA��ʾ
            cw_1(); //���󱨾�
            _A = 0xaa; //A�Ĵ�����ʾ0xaa
            _B = 0x0a; //B�Ĵ�����ʾ0x0a
            while(1);
         }

         if(SROM_L[js2] + SROM_H[js2] != 0xff) break;

         SROM_L[js2] = 0x55;
         SROM_L[js2+1] = 0x0a;
         SROM_H[js2] = 0xaa;
         SROM_H[js2+1] = 0x50;
         if(SROM_L[js2] == 0x55 && SROM_H[js2] != 0xaa || SROM_L[js2] != 0x55 && SROM_H[js2] == 0xaa) //�ڴ����
         {
            CTVGA_C &= ~0x01; //�������VGA
            for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
            if(Y > 153) VGA_wbsy(),Y=153; //������ӡ��Χ,����
            VGA_sromnccw_logo(Y+=13,17,255); //"SROM�ڴ����"
            CTVGA_C |= 0x01; //����VGA��ʾ
            cw_1(); //���󱨾�
            _A = 0xaa; //A�Ĵ�����ʾ0xaa
            _B = 0x0b; //B�Ĵ�����ʾ0x0b
            while(1);
         }

         if(SROM_L[js2] + SROM_H[js2] != 0xff) break;

         js2 += 1024;

      }while(js2 != 2097152);



      CTVGA_C &= ~0x01; //�������VGA
      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
      if(Y > 153) VGA_wbsy(),Y=153; //������ӡ��Χ,����
      VGA_ncyc_logo(Y+=13,17,js2<<=1,255); //"SROM�ڴ��С:X�ֽ�"
      CTVGA_C |= 0x01; //����VGA��ʾ
      for(i = 0;i < 16000;i++);



      if(wj_dx > js2) //�ļ���С����SROM��С,���봦��
      {
          CTVGA_C &= ~0x01; //�������VGA
          for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
          if(Y > 153) VGA_wbsy(),Y=153; //������ӡ��Χ,����
          VGA_sromncyc_logo(Y+=13,17,255); //"SROM�ڴ����"
          CTVGA_C |= 0x01; //����VGA��ʾ
          cw_1(); //���󱨾�
          _A = 0xaa; //A�Ĵ�����ʾ0xaa
          _B = 0x0c; //B�Ĵ�����ʾ0x0c
          while(1);
      }


      CTVGA_C &= ~0x01; //�������VGA
      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
      if(Y > 153) VGA_wbsy(),Y=153; //������ӡ��Χ,����
      VGA_sjzzz_logo(Y+=13,17,255); //"����װ����..."
      CTVGA_C |= 0x01; //����VGA��ʾ
      for(i = 0;i < 16000;i++);



      if(TF_SD_RD_512B(device,sqh_ = FAT32_cuhao_shanquhao(device,wj_cuhao),buf) == 0) //����ROM�����ļ�������,û�ɹ����봦��
      {
          CTVGA_C &= ~0x01; //�������VGA
          for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
          if(Y > 153) VGA_wbsy(),Y=153; //������ӡ��Χ,����
          VGA_spisbcw_logo(Y+=13,17,255); //"SPI�豸����"
          CTVGA_C |= 0x01; //����VGA��ʾ
          cw_0(); //���󱨾�
          _A = 0xaa; //A�Ĵ�����ʾ0xaa
          _B = 0x0d; //B�Ĵ�����ʾ0x0d
          while(1);
      }
      _sqh = sqh_ + FAT32_cudx[device]; //��¼�״ص�β������+1
      ++sqh_; //ָ����һ������

      if(FAT32_cuhao_culian(device,wj_cuhao,128,culian) == 0) //�����״�ָ�������128���طŵ�����������,û�ɹ����봦��
      {
          CTVGA_C &= ~0x01; //�������VGA
          for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
          if(Y > 153) VGA_wbsy(),Y=153; //������ӡ��Χ,����
          VGA_spisbcw_logo(Y+=13,17,255); //"SPI�豸����"
          CTVGA_C |= 0x01; //����VGA��ʾ
          cw_0(); //���󱨾�
          _A = 0xaa; //A�Ĵ�����ʾ0xaa
          _B = 0x0e; //B�Ĵ�����ʾ0x0e
          while(1);
      }
      culian_x = 0; //��ָ��ָ��������׸���



      SROM_L_ = SROM_L; //ָ��SROM_L��ʼ��ַ
      SROM_H_ = SROM_H; //ָ��SROM_H��ʼ��ַ
      _SROM_L = SROM_L + (wj_dx >> 1); //ָ��SROM_Lװ�ؽ�����ַ
      _SROM_H = SROM_H + (wj_dx >> 1); //ָ��SROM_Hװ�ؽ�����ַ


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

                                      CTVGA_C &= ~0x01; //�������VGA
                                      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
                                      VGA_SK_1(210,18,12,220,115);        //����������
                                      VGA_bfb_logo(210,115,100,255);       //�������ٷֱ�Ϊ100%
                                      CTVGA_C |= 0x01; //����VGA��ʾ
                                      for(i = 0;i < 25000;i++);

                                      CTVGA_C &= ~0x01; //�������VGA
                                      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
                                      if(Y > 153) VGA_wbsy(),Y=153; //������ӡ��Χ,����
                                      VGA_qdcx_logo(Y+=13,17,255); //"��������"
                                      CTVGA_C |= 0x01; //����VGA��ʾ
                                      for(i = 0;i < 61000;i++);

                                      CTVGA_C &= ~0x01; //�������VGA
                                      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
                                      VGA_SK_0(0,240,0); //VGA����
                                      CTVGA_C |= 0x01; //����VGA��ʾ
                                      for(i = 0;i < 16000;i++);

                                      rom_run; //�л�ROM

                                   }


                            }


                         }while(js1 != 512);


                         do
                         {

                                ++sq_x; //װ��һ������,��������+1

                                if(sq_x == 16) //���������ﵽ16(8192�ֽ�),����ˢ�½������Ͱٷֱ�
                                {
                                   sq_x = 0;

                                   jdt_x_10M += 2200000000 / (wj_dx >> 13); //���������λ��

                                   CTVGA_C &= ~0x01; //�������VGA
                                   for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
                                   VGA_SK_1(210,115,12,24,0); //�����������ٷֱ�
                                   VGA_SK_1(210,18,12,jdt_x_10M/10000000,115); //���½�����λ��
                                   VGA_bfb_logo(210,115,jdt_x_10M/22000000,255); //���½������ٷֱ�
                                   CTVGA_C |= 0x01; //����VGA��ʾ
                                   for(i = 0;i < 7000;i++);
                                }




                                if(sqh_ == _sqh) //һ���ص���������,���뻻��
                                {

                                   if(culian[culian_x] == 0x0fffffff) //Ϊ�ؽ�����־,�ļ�����,���봦��
                                   {
                                      CTVGA_C &= ~0x01; //�������VGA
                                      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
                                      if(Y > 153) VGA_wbsy(),Y=153; //������ӡ��Χ,����
                                      VGA_wjcw_logo(Y+=13,17,255); //"�ļ�����"
                                      CTVGA_C |= 0x01; //����VGA��ʾ
                                      cw_0(); //���󱨾�
                                      _A = 0xaa; //A�Ĵ�����ʾ0xaa
                                      _B = 0x0f; //B�Ĵ�����ʾ0x0f
                                      while(1);
                                   }

                                   sqh_ = FAT32_cuhao_shanquhao(device,culian[culian_x]); //�غ�ת��������
                                   _sqh = sqh_ + FAT32_cudx[device]; //��¼�ص�β��������һ������   !!!BUGҪ��Ϊdevice
             

                                   if(culian_x == 127) //β��? ������´���
                                   {
                                      if(FAT32_cuhao_culian(device,culian[127],128,culian) == 0) //����β��ָ�������128���طŵ�����������,�������,���봦��
                                      {
                                         CTVGA_C &= ~0x01; //�������VGA
                                         for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
                                         if(Y > 153) VGA_wbsy(),Y=153; //������ӡ��Χ,����
                                         VGA_spisbcw_logo(Y+=13,17,255); //"SPI�豸����"
                                         CTVGA_C |= 0x01; //����VGA��ʾ
                                         cw_0(); //���󱨾�
                                         _A = 0xaa; //A�Ĵ�����ʾ0xaa
                                         _B = 0x10; //B�Ĵ�����ʾ0x10
                                         while(1);
                                      }
                                      culian_x = 0; //��ָ��ָ��������׸���
                                   }
                                   else
                                   {
                                      ++culian_x; //ָ����һ���غ�
                                   }

                                }




                                if(ROM_K == 0)
                                {

                                    if(SROM_L_ + 512 < _SROM_L)
                                    {

                                        if(TF_SD_RD_512B(device,sqh_ ,SROM_L_) == 0) //����һ��������������,�������,���봦��
                                        {
                                           CTVGA_C &= ~0x01; //�������VGA
                                           for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
                                           if(Y > 153) VGA_wbsy(),Y=153; //������ӡ��Χ,����
                                           VGA_spisbcw_logo(Y+=13,17,255); //"SPI�豸����"
                                           CTVGA_C |= 0x01; //����VGA��ʾ
                                           cw_0(); //���󱨾�
                                           _A = 0xaa; //A�Ĵ�����ʾ0xaa
                                           _B = 0x11; //B�Ĵ�����ʾ0x11
                                           while(1);
                                        }
                                        ++sqh_; //ָ����һ������

                                        SROM_L_ += 512;

                                    }
                                    else
                                    {

                                        if(TF_SD_RD_512B(device,sqh_ ,buf) == 0) //����һ��������������,�������,���봦��
                                        {
                                           CTVGA_C &= ~0x01; //�������VGA
                                           for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
                                           if(Y > 153) VGA_wbsy(),Y=153; //������ӡ��Χ,����
                                           VGA_spisbcw_logo(Y+=13,17,255); //"SPI�豸����"
                                           CTVGA_C |= 0x01; //����VGA��ʾ
                                           cw_0(); //���󱨾�
                                           _A = 0xaa; //A�Ĵ�����ʾ0xaa
                                           _B = 0x11; //B�Ĵ�����ʾ0x11
                                           while(1);
                                        }
                                        ++sqh_; //ָ����һ������

                                        break;

                                    }

                                }
                                else
                                {

                                    if(SROM_H_ + 512 < _SROM_H)
                                    {

                                        if(TF_SD_RD_512B(device,sqh_ ,SROM_H_) == 0) //����һ��������������,�������,���봦��
                                        {
                                           CTVGA_C &= ~0x01; //�������VGA
                                           for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
                                           if(Y > 153) VGA_wbsy(),Y=153; //������ӡ��Χ,����
                                           VGA_spisbcw_logo(Y+=13,17,255); //"SPI�豸����"
                                           CTVGA_C |= 0x01; //����VGA��ʾ
                                           cw_0(); //���󱨾�
                                           _A = 0xaa; //A�Ĵ�����ʾ0xaa
                                           _B = 0x11; //B�Ĵ�����ʾ0x11
                                           while(1);
                                        }
                                        ++sqh_; //ָ����һ������


                                        SROM_H_ += 512;

                                    }
                                    else
                                    {

                                        if(TF_SD_RD_512B(device,sqh_ ,buf) == 0) //����һ��������������,�������,���봦��
                                        {
                                           CTVGA_C &= ~0x01; //�������VGA
                                           for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
                                           if(Y > 153) VGA_wbsy(),Y=153; //������ӡ��Χ,����
                                           VGA_spisbcw_logo(Y+=13,17,255); //"SPI�豸����"
                                           CTVGA_C |= 0x01; //����VGA��ʾ
                                           cw_0(); //���󱨾�
                                           _A = 0xaa; //A�Ĵ�����ʾ0xaa
                                           _B = 0x11; //B�Ĵ�����ʾ0x11
                                           while(1);
                                        }
                                        ++sqh_; //ָ����һ������

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


    CTVGA_C &= ~0x01; //�������VGA
    for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
    VGA_SK_0(0,240,0); //VGA����
    CTVGA_C |= 0x01; //����VGA��ʾ

    SPI_RST(); //��λSPI������
    for(i = 0;i < 16000;i++);

    SPI_S = 0x04;  //SPI���ݵ���ʾ0x69
    SPI_D = 0x69;
    SPI_S = 0x01;
    for(i = 0;i < 61000;i++);


  if((XT_C & 0x01) == 0x00) //λ0Ϊ0��ʱ����п�������
  {


      CTVGA_C &= ~0x01; //�������VGA
      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
      KC_LS1u_logo(16,16,0xe0,0x03,0x1c,238,176,95,115);
      CTVGA_C |= 0x01; //����VGA��ʾ

      for(i = 0;i < 61000;i++);
      for(i = 0;i < 61000;i++);
      for(i = 0;i < 61000;i++);


      ld = 0;

      do
      {
         CTVGA_C &= ~0x01; //�������VGA
         for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
         ET_logo(90,64,(ld << 5) | (ld << 2) | (ld >> 1));
         ++ld;
         CTVGA_C |= 0x01; //����VGA��ʾ
         for(i = 0;i < 16000;i++);

      }while(ld != 8);

      for(i = 0;i < 61000;i++);
      for(i = 0;i < 61000;i++);
      for(i = 0;i < 61000;i++);
      for(i = 0;i < 61000;i++);
      for(i = 0;i < 61000;i++);

      do
      {
         CTVGA_C &= ~0x01; //�������VGA
         for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
         --ld;
         ET_logo(90,64,(ld << 5) | (ld << 2) | (ld >> 1));
         CTVGA_C |= 0x01; //����VGA��ʾ
         for(i = 0;i < 16000;i++);

      }while(ld != 0);


      CTVGA_C &= ~0x01; //�������VGA
      for(i = 0;(CTVGA_C & 0x80) == 0x80 && i != 70;++i); //���Է��ʵ�ʱ������
      VGA_SK_0(0,240,0); //VGA����
      CTVGA_C |= 0x01; //����VGA��ʾ
      speaker(160,151);
      for(i = 0;i < 61000;i++);


  }



  spi_device_boot(); //����SROM����װ�ط������


}