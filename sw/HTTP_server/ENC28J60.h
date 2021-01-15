void ENC28J60_RCR(unsigned char addr) //ENC28J60������  ����ַ ���ú�SPI_DΪ����������
{

  SPI_CS = 0x09;
  SPI_D = addr;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0xff;
  while((SPI_INT & 0x80) != 0x80);
  SPI_CS = 0x00;

}

void ENC28J60_WCR(unsigned char addr,unsigned char data) //  ENC28J60д����  ��ENC28J60_addr��ַ ��ENC28J60_data���� ���ú�д��
{

  SPI_CS = 0x09;
  SPI_D = addr | 0x40;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = data;
  while((SPI_INT & 0x80) != 0x80);
  SPI_CS = 0x00;

}

void Bank0() //����ENC28J60��0��Ĵ���
{

  SPI_CS = 0x09;
  SPI_D = 0xbf;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x03;
  while((SPI_INT & 0x80) != 0x80);
  SPI_CS = 0x00;

}

void Bank1() //����ENC28J60��1��Ĵ���
{

  SPI_CS = 0x09;
  SPI_D = 0xbf;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x02;
  while((SPI_INT & 0x80) != 0x80);
  SPI_CS = 0x00;

  SPI_CS = 0x09;
  SPI_D = 0x9f;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x01;
  while((SPI_INT & 0x80) != 0x80);
  SPI_CS = 0x00;

}

void Bank2() //����ENC28J60��2��Ĵ���
{

  SPI_CS = 0x09;
  SPI_D = 0xbf;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x01;
  while((SPI_INT & 0x80) != 0x80);
  SPI_CS = 0x00;

  SPI_CS = 0x09;
  SPI_D = 0x9f;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x02;
  while((SPI_INT & 0x80) != 0x80);
  SPI_CS = 0x00;

}

void Bank3() //����ENC28J60��3��Ĵ���
{

  SPI_CS = 0x09;
  SPI_D = 0x9f;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x03;
  while((SPI_INT & 0x80) != 0x80);
  SPI_CS = 0x00;

}

void ENC28J60_BFS(unsigned char addr,unsigned char data) //ENC28J60λ����1
{

  SPI_CS = 0x09;
  SPI_D = addr | 0x80;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = data;
  while((SPI_INT & 0x80) != 0x80);
  SPI_CS = 0x00;

}

void ENC28J60_BFC(unsigned char addr,unsigned char data) //ENC28J60λ����0
{

  SPI_CS = 0x09;
  SPI_D = addr | 0xa0;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = data;
  while((SPI_INT & 0x80) != 0x80);
  SPI_CS = 0x00;

}

void ENC28J60_RST() //ENC28J60��λ����
{

  SPI_CS = 0x09;
  SPI_D = 0xff;
  while((SPI_INT & 0x80) != 0x80);
  SPI_CS = 0x00;

}

void ENC28J60_chushihua() //ENC28J60��ʼ��
{

  ENC28J60_WCR(0x00,0xfa);  //ERDPTL	��������ָ��
  ENC28J60_WCR(0x01,0x05);  //ERDPTH

  ENC28J60_WCR(0x02,0x00);  //EWRPTL	������дָ��
  ENC28J60_WCR(0x03,0x00);  //EWRPTH

  ENC28J60_WCR(0x04,0x00);  //ETXSTL	���ͻ�������ָ��
  ENC28J60_WCR(0x05,0x00);  //ETXSTH

  ENC28J60_WCR(0x06,0x00);  //ETXNDL	���ͻ�����βָ��
  ENC28J60_WCR(0x07,0x00);  //ETXNDH

  ENC28J60_WCR(0x08,0xfa);  //ERXSTL	���ջ�������ָ��
  ENC28J60_WCR(0x09,0x05);  //ERXSTH

  ENC28J60_WCR(0x0a,0xff);  //ERXNDL	���ջ�����βָ��
  ENC28J60_WCR(0x0b,0x1f);  //ERXNDH

  ENC28J60_WCR(0x0c,0xfa);  //ERXRDPTL	���ջ�����Ӳ����дָ��
  ENC28J60_WCR(0x0d,0x05);  //ERXRDPTH


  Bank1();

  ENC28J60_WCR(0x18,0x20);  //ERXFCON	    ������


  Bank2();

  ENC28J60_WCR(0x01,0x00);  //MACON2	 MARST��0 ʹMAC�˳���λ״̬

  ENC28J60_WCR(0x00,0x0d);  //MACON1	 IEEE�������ƺ�ʹ��MAC��������֡

  ENC28J60_WCR(0x02,0x31);  //MACON3   CRC���� С��60�ֽ����� ȫ˫��

  //ENC28J60_WCR(0x03,0x00);  //MACON4	 Ĭ��

  //ENC28J60_WCR(0x0a,0x2e);  //MAMXFLL   ����/���� ���֡����
  //ENC28J60_WCR(0x0b,0x00);  //MAMXFLH   

  ENC28J60_WCR(0x04,0x15);  //MABBIPG   ���Ա������   ȫ˫��15H  ��˫��12H

  ENC28J60_WCR(0x06,0x12);  //MAIPGL   �Ǳ��Ա������	  һ��12H
  //ENC28J60_WCR(0x07,0x0c);  //MAIPGH   ��˫��0CH

  ENC28J60_WCR(0x1b,0xc0);  //EIE �жϿ��ƼĴ��� ���ý��ܵ����ݰ�ʱ����ж� ���ݰ�����Ϊ0ʱ�ж�����


  Bank3();

  ENC28J60_WCR(0x01,MAC0);  //MAADR0	  ����MAC��ַ
  ENC28J60_WCR(0x00,MAC1);  //MAADR1
  ENC28J60_WCR(0x03,MAC2);  //MAADR2
  ENC28J60_WCR(0x02,MAC3);  //MAADR3
  ENC28J60_WCR(0x05,MAC4);  //MAADR4
  ENC28J60_WCR(0x04,MAC5);  //MAADR5


//////////////////////////////////////дPHY/////////////////////////////////////////

  Bank2();
					
  ENC28J60_WCR(0x14,0x00); 	 //MIREGADR  д��PHY�Ĵ�����ַ

  ENC28J60_WCR(0x16,0x00);	 //MIWRL   д��PHY�Ĵ�����8λ����

  ENC28J60_WCR(0x17,0x01);	 //MIWRH   д��PHY�Ĵ�����8λ����


  Bank3();

  do ENC28J60_RCR(0x0a);while((SPI_D & 0x01) != 0); //MISTAT


//////////////////////////////////////��PHY/////////////////////////////////////////	    

  Bank2();

  ENC28J60_WCR(0x14,0x00); 	 //MIREGADR  д��PHY�Ĵ�����ַ

  ENC28J60_WCR(0x12,0x01);	 //MICMD.MIIRDλ��1��ʼPHY������


  Bank3();

  do ENC28J60_RCR(0x0a);while((SPI_D & 0x01) != 0); //MISTAT


  Bank2();

  ENC28J60_WCR(0x12,0x00);	 //MICMD.MIIRDλ��0


  ENC28J60_RCR(0x19); //MIRDH
					
  for(k = 0;k < 61000;k++);


  ENC28J60_RCR(0x18); //MIRDL
					
  for(k = 0;k < 61000;k++);

}

void xierushujubao(unsigned int addr) //��SRAM�����ݴ�С ���ü�д��SRAM����
{

  unsigned int j_;

  Bank0();

  ENC28J60_WCR(0x02,0x00);  //EWRPTL	������дָ��ع��ײ�
  ENC28J60_WCR(0x03,0x00);  //EWRPTH


  SPI_CS = 0x09;

  SPI_D = 0x7a;
  while((SPI_INT & 0x80) != 0x80);
  SPI_D = 0x00;

  j_ = 0;
  while(j_ < addr)
  {

    SPI_D = SRAM[j_++];
    SPI_D = SRAM[j_++];
    SPI_D = SRAM[j_++];
    SPI_D = SRAM[j_++];
    SPI_D = SRAM[j_++];
    SPI_D = SRAM[j_++];

  }

  SPI_CS = 0x00;


  ENC28J60_WCR(0x06,addr & 0x00ff);  //ETXNDL	���ͻ�����βָ��ָ�����1���ֽ�
  ENC28J60_WCR(0x07,addr >> 8);      //ETXNDH

}

void ENC28J60_jisuanxiaoyanhe(unsigned int A1,unsigned int A2,unsigned int A3) //ENC28J60�ڲ�����Ч��Ͳ����� ��A1A2��ʼ�ͽ����ֽڵ�ַ ��A3Ч������λ��
{

  unsigned char D1,D2;

  Bank0();

  ENC28J60_WCR(0x10,A1); //EDMASTL Ч��ͼ�����ʼ��ַ��
  ENC28J60_WCR(0x11,A1 >> 8); //EDMASTH Ч��ͼ�����ʼ��ַ��

  ENC28J60_WCR(0x12,A2); //EDMANDL Ч��ͼ��������ַ��
  ENC28J60_WCR(0x13,A2 >> 8); //EDMANDH Ч��ͼ��������ַ��

  ENC28J60_BFS(0x1f,0x10);  //ECON1.CSUMENλ��1 �л�ΪӲ������Ч���
  ENC28J60_BFS(0x1f,0x20);  //ECON1.DMASTλ��1 ��������

  do ENC28J60_RCR(0x1f);while((SPI_D & 0x20) != 0); //�ȴ�ECON1.DMAST��0

  ENC28J60_RCR(0x16); //EDMACSL Ч��ͼ�������
  D1 = SPI_D;
  ENC28J60_RCR(0x17); //EDMACSH Ч��ͼ�������
  D2 = SPI_D;


  ENC28J60_WCR(0x02,A3); //EWRPTL ������дָ��ָ��Ч�����ʼ�ֽ�
  ENC28J60_WCR(0x03,A3 >> 8); //EWRPTH

  SPI_CS = 0x09;

  SPI_D = 0x7a;
  SPI_D = D2;
  SPI_D = D1;
  while((SPI_INT & 0x80) != 0x80);

  SPI_CS = 0x00;

}

void jieshoushujubao()
{

  unsigned int j_;

      Bank0();

      SPI_CS = 0x09; //����SPI���ʲ�ƬѡENC28J60

      SPI_D = 0x3a; //���Ͷ�����������
  while((SPI_INT & 0x80) != 0x80);
      SPI_D = 0xff;
  while((SPI_INT & 0x80) != 0x80);

      addrL = SPI_D; //������һ�����ݰ���ʼ��ַL
      addrH = SPI_D; //������һ�����ݰ���ʼ��ַH

      jjl = SPI_D; //���յ��ֽ���L 
      jjh = SPI_D; //���յ��ֽ���H
      jjh = jjh << 8;
      jjh |= jjl;

      SPI_D = 0xff;    //���յ�״̬   0xc0Ϊͨ��
  while((SPI_INT & 0x80) != 0x80);
      SPI_D = 0xff;    //���յ�״̬	  0x01Ϊ�鲥	0x03Ϊ�㲥


      jjh = jjh - 4;

      if(jjh < 713)	//����SRAM��������
      {

          if(jjh > 53)
          {
             SRAM[0] = SPI_D;
             SRAM[1] = SPI_D;
             SRAM[2] = SPI_D;
             SRAM[3] = SPI_D;
             SRAM[4] = SPI_D;
             SRAM[5] = SPI_D;
             SRAM[6] = SPI_D;
             SRAM[7] = SPI_D;
             SRAM[8] = SPI_D;
             SRAM[9] = SPI_D;
             SRAM[10] = SPI_D;
             SRAM[11] = SPI_D;
             SRAM[12] = SPI_D;
             SRAM[13] = SPI_D;
             SRAM[14] = SPI_D;
             SRAM[15] = SPI_D;
             SRAM[16] = SPI_D;
             SRAM[17] = SPI_D;
             SRAM[18] = SPI_D;
             SRAM[19] = SPI_D;
             SRAM[20] = SPI_D;
             SRAM[21] = SPI_D;
             SRAM[22] = SPI_D;
             SRAM[23] = SPI_D;
             SRAM[24] = SPI_D;
             SRAM[25] = SPI_D;
             SRAM[26] = SPI_D;
             SRAM[27] = SPI_D;
             SRAM[28] = SPI_D;
             SRAM[29] = SPI_D;
             SRAM[30] = SPI_D;
             SRAM[31] = SPI_D;
             SRAM[32] = SPI_D;
             SRAM[33] = SPI_D;
             SRAM[34] = SPI_D;
             SRAM[35] = SPI_D;
             SRAM[36] = SPI_D;
             SRAM[37] = SPI_D;
             SRAM[38] = SPI_D;
             SRAM[39] = SPI_D;
             SRAM[40] = SPI_D;
             SRAM[41] = SPI_D;
             SRAM[42] = SPI_D;
             SRAM[43] = SPI_D;
             SRAM[44] = SPI_D;
             SRAM[45] = SPI_D;
             SRAM[46] = SPI_D;
             SRAM[47] = SPI_D;
             SRAM[48] = SPI_D;
             SRAM[49] = SPI_D;
             SRAM[50] = SPI_D;
             SRAM[51] = SPI_D;
             SRAM[52] = SPI_D;
             SRAM[53] = SPI_D;

             if(jjh != 54)
             {
                j_ = 54;
                while(j_ < jjh - 1)
                {
                  SRAM[j_++] = SPI_D;
                }

                SPI_S = 0x04;
                SRAM[j_] = SPI_D;
                SPI_S = 0x01;
             }

          }
          else
          {

             j_ = 0;
             while(j_ < jjh - 1)
             {
               SRAM[j_++] = SPI_D;
             }

             SPI_S = 0x04;
             SRAM[j_] = SPI_D;
             SPI_S = 0x01;

          }



      }

      SPI_CS = 0x00; //ȡ��ENC28J60Ƭѡ ѡ�п��豸

      ////////////////////////////////////////////////////////////////////////////////////////////

      ENC28J60_RCR(0x1c);
 
      if((SPI_D & 0x01) == 0x00)   //EIR.RXERIFλΪ0ʱ���� (���ջ�����û���ʱ����)
      {

        ENC28J60_WCR(0x0c,addrL);  //ERXRDPTL	���ջ�����Ӳ����дָ��	 ָ����һ�����ݰ�
        ENC28J60_WCR(0x0d,addrH);  //ERXRDPTH

        ENC28J60_WCR(0x00,addrL);  //ERDPTL	��������ָ��	 ָ����һ�����ݰ�
        ENC28J60_WCR(0x01,addrH);  //ERDPTH
						
        ENC28J60_BFS(0x1e,0x40);  //ECON2.PKTDEC ��1  ��EPKTCNT�������ݰ������Ĵ�����1


        Bank1();

        ENC28J60_RCR(0x19);
        if(SPI_D == 0) ENC28J60_SJBBZ = 0;else ENC28J60_SJBBZ = 1; //EPKTCNT����0ʱ  ��־�����ݰ� �����־û�����ݰ�

      }
      else     // ���ջ������������
      {

        ENC28J60_SJBBZ = 0; //��־Ϊû�����ݰ�

        ENC28J60_BFC(0x1f,0x04);  //ECON1.RXENλ��0  �رս���


        ENC28J60_WCR(0x00,0xfa);  //ERDPTL	��������ָ��ָ���ʼֵ
        ENC28J60_WCR(0x01,0x05);  //ERDPTH

        ENC28J60_WCR(0x08,0xfa);  //ERXSTL	���ջ�������ָ��ָ���ʼֵ
        ENC28J60_WCR(0x09,0x05);  //ERXSTH

        ENC28J60_WCR(0x0c,0xfa);  //ERXRDPTL	���ջ�����Ӳ����дָ��ָ���ʼֵ
        ENC28J60_WCR(0x0d,0x05);  //ERXRDPTH


        Bank1();

        do
        {
          ENC28J60_BFS(0x1e,0x40);  //ECON2.PKTDEC ��1  ��EPKTCNT�������ݰ������Ĵ�����1
          ENC28J60_RCR(0x19);
        } while(SPI_D != 0);


        Bank0();

        ENC28J60_BFC(0x1c,0x01);  //EIR.RXERIFλ��0  ������ջ����������־
        ENC28J60_BFS(0x1f,0x04);  //ECON1.RXENλ��1  ��������


      }

}