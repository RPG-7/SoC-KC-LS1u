void delay_16(unsigned int x)
{

unsigned int i;

   for(i = 0;i < x;++i);

}


unsigned char ADD_SYS_KC_LS1u_boot_txt() //���������ı�·��,����ֵΪ1��ʾ�ɹ�
{

unsigned char buf[512];
unsigned char device = 0;
unsigned long int WJDX;


unsigned char js0;
unsigned int js1;
unsigned int js2;
unsigned int js3;
unsigned int js4;

unsigned char returnX;
device = 0;
    do
    {
       if(FAT32_OPENWJ(device,0x00000002,0,"KC_LS1u_boot_0.txt") != 0) break;
       ++device;

    }while(device != 2);

    if(device != 2) //�������ı��ɹ�
    {

       if((WJDX = FAT32_RETURN_WJDX_(device,0)) < 513 && WJDX > 12)
       {

           if(FAT32_RDWJ_512B(device,0,buf) == 1) //����512B
           {

                if(buf[0] == 's' && buf[1] == 'p' && buf[2] == 'i' && buf[3] == '_' && buf[4] == 'd' && buf[5] == 'e' && buf[6] == 'v' && buf[7] == 'i' && buf[8] == 'c' && buf[9] == 'e' && buf[11] == ':' && (buf[10] == '_' || buf[10] == '0' || buf[10] == '1'))
                {

                    if(buf[10] == '_') KC_LS1u_boot_0_txt_device = device; else KC_LS1u_boot_0_txt_device = buf[10];


                    js1 = 0;
                    js2 = 12;
                    js4 = WJDX;

                    do
                    {

                        KC_LS1u_boot_0_txt_LJ[js1] = buf[js2];
                        ++js1;
                        ++js2;

                    }while(js2 < js4);

                    --js1;
                    while(js1 != 0 && KC_LS1u_boot_0_txt_LJ[js1] != '\') --js1;

                    if(js1 == 0)
                    {
                        KC_LS1u_boot_0_txt_X = 0;
                    }
                    else
                    {
                        KC_LS1u_boot_0_txt_X = js1 + 1;
                    }

                    returnX = 1;

                }
                else  //�豸�������Խ��봦��
                {
                   returnX = 4;
                }

           }
           else //���ļ�ʧ��
           {
              returnX = 3;
           }

       }
       else //�����ı�����512�ֽ�,��С��13�ֽ�
       {
          returnX = 2;
       }

    }
    else //û���ҵ������ı�
    {
       returnX = 0;
    }

    return returnX;

}



unsigned char *BOOT_LJ_ADD_LJ(unsigned char *ADD_LJ) //�����ı�·������
{

unsigned char *_addr;
unsigned int ADD_LJ_CD;

unsigned int js1;

   _addr = & KC_LS1u_boot_0_txt_LJ[KC_LS1u_boot_0_txt_X];

   ADD_LJ_CD = 0;
   while(ADD_LJ_CD != 512 && ADD_LJ[ADD_LJ_CD] != 0) ++ADD_LJ_CD; //ȡ����·���ĳ���

   js1 = 0;
   while(js1 != ADD_LJ_CD) *_addr = ADD_LJ[js1],++_addr,++js1;

   *_addr = 0;

   return KC_LS1u_boot_0_txt_LJ;

}



unsigned char ADD_SYS_GB2312_bin() //����ϵͳ�ļ�GB2312.bin(��ʼ��GB2312����)
{

unsigned char returnX;
unsigned char *_GB2312;

unsigned char js1;


   if(FAT32_OPENWJ(KC_LS1u_boot_0_txt_device,0x00000002,0,BOOT_LJ_ADD_LJ("�ֿ��ļ�\�����ֿ�.bin")) != 0) //�ҵ��ļ�GB2312.bin
   {
       _GB2312 = GB2312;
       while((js1 = FAT32_RDWJ_512B(KC_LS1u_boot_0_txt_device,0,_GB2312)) == 1) _GB2312 += 512; //����GB2312.bin����

       if(js1 == 2) returnX = 1; //�������
       else returnX = 6; //��;����
   }
   else //û���ҵ��ļ�GB2312.bin
   {
      returnX = 5;
   }

   return returnX;

}


unsigned char ADD_SYS_WJ(unsigned char *WJLJ,unsigned char *buf) //����ϵͳ�ļ�,����ֵΪ1���
{

unsigned char returnX;


   if(FAT32_OPENWJ(KC_LS1u_boot_0_txt_device,0x00000002,0,BOOT_LJ_ADD_LJ(WJLJ)) != 0) //�ҵ�ϵͳ�ļ�
   {
       while((returnX = FAT32_RDWJ_512B(KC_LS1u_boot_0_txt_device,0,buf)) == 1) buf += 512; //����ϵͳ�ļ�����
       if(returnX == 2) returnX = 1;
   }
   else //û���ҵ�ϵͳ�ļ�
   {
      returnX = 0;
   }

   return returnX;

}


unsigned char ADD_SYS() //����ϵͳ�ļ�
{

unsigned char returnX;

    if ((returnX = ADD_SYS_KC_LS1u_boot_txt()) == 1)           //��������·��
    if ((returnX = ADD_SYS_GB2312_bin()) == 1);                 //����GB2312.bin
    //if((returnX = ADD_SYS_WJ("JSQTB.bin",JSQXS)) == 1);      //���ؼ�����ͼ��

    return returnX;

}
