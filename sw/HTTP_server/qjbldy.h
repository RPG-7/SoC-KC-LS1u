unsigned char SRAM[712];

unsigned char TT;
////////////////////////////////

unsigned char x,y,zzz,lj;  //��ʱ ����

unsigned int k,zzzz; //��ʱ ����

/////////////////////�հ���//////////////////////

unsigned char addrL,addrH;	 //������һ���ݰ���ʼ��ַ

unsigned char jjl;	   //���յ������ݰ��ֽ�����8λ����

unsigned int jjh;	   //���յ������ݰ��ֽ���

unsigned char ENC28J60_SJBBZ = 0;  //���ݰ���־  1Ϊ�����������ݰ� 0Ϊû�����ݰ�

unsigned int QSJJ = 0; //ȡʱ�����  �ƹ�����ȡһ��DS1302����


////////////////////////////////

unsigned int IPj;	 //����IP��ʶ�ֶ�  ÿ��1��+1

unsigned char aaaa,bbbb;	//У��ͺ�����
unsigned int cccc,dddd; //У��ͺ�����

unsigned char aaa,bbb,ccc,ddd;   //32λ�ӷ�������


////////////////////////��������//////////////////

unsigned char MAC5 = 0x61,MAC4 = 0x61,MAC3 = 0x61,MAC2 = 0x61,MAC1 = 0x61,MAC0 = 0x70; //����MAC

unsigned char IP3 = 192,IP2 = 168,IP1 = 1,IP0 = 77;	//����IP

unsigned char WGIP3 = 192,WGIP2 = 168,WGIP1 = 1,WGIP0 = 1; //����IP

unsigned char YM3 = 255,YM2 = 255,YM1 = 255,YM0 = 0; //��������

unsigned int HTTPdk = 80; //HTTP���Ķ˿�


//////////////TF��FAT32�ļ�ϵͳ///////////////////

unsigned char aa,bb,cc;  //24λ�ӷ�������


unsigned char cudx,FATsl;  //ÿ����������FAT������

unsigned char FAT1H,FAT1L;  //FAT1����ʼ��ַ

unsigned char FAT2H,FAT2L,FAT2LL; //FAT2����ʼ��ַ

unsigned char DATAH,DATAL,DATALL;  //��������ʼ��ַ


unsigned char sqdz3,sqdz2,sqdz1;  //�غ�ת������ַ���������������ֵַ


unsigned char bencu3,bencu2,bencu1;  //�غ�ת��ֵ���� �������汾��  ����һ�رȽ�
unsigned char culian[24];	  //�غ�ת��ֵ������� ����8����ֵ  һ����ֵ3�ֽ�


unsigned char wjcuhao3,wjcuhao2,wjcuhao1,wjdx4,wjdx3,wjdx2,wjdx1; //�ļ���ѯ1������ �ļ���Ϣ
unsigned char wjbz;  //�ļ���ѯ1�������ļ���Ϣ��־  Ϊ1��Ч Ϊ0��Ч


/////////////////GET·������//////////////////////

unsigned char wjm[8];	//�����ļ���
unsigned char hzm[3];	//�����׺��

unsigned char qh; //0Ϊ�����ļ���  1Ϊ�����׺��

unsigned int zz; //zzΪ�ֽڻ�ַ	��ʼָ��0x2f ��/

unsigned char xj,yj; //xjΪ�ֽ�ƫ��  yjΪ�ļ�������׺����������

unsigned char zzbc;  //�ֽڱ���

unsigned char mlcuhao3,mlcuhao2,mlcuhao1;	  //Ŀ¼�غżĴ�


///////////////////32λת10����////////////////////

unsigned char ywj;  //��λ����

unsigned char sjz10,sjz9,sjz8,sjz7,sjz6,sjz5,sjz4,sjz3,sjz2,sjz1; //10λ10���ƽ������


//////////////////HTTP��ͷ��/////////////////////

unsigned char zzj;  //д���ֽڵ�ָ��


///////////////////TCP���ӱ�//////////////////////

#define TCP_IIS 20 //�������������

unsigned char TCP_C[1040];  //1�����ӱ�52�ֽ� ��������������������ô�С

unsigned int TCPjzz;  //TCP���ӱ��ָ��

unsigned char TCPkbz;  //��Ϊ0��ʾ��һ��������

unsigned char sbc; //��������

/////////////////////////////////////////////////
