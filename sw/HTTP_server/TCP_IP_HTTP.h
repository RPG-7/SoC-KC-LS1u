void ARPyingda()
{

//////////////////////ԴMAC��ַ�͵�Ŀ��MAC��ַ///////////////////////
                
				SRAM[0x0000] = SRAM[0x0006];	
				SRAM[0x0001] = SRAM[0x0007]; 
				SRAM[0x0002] = SRAM[0x0008]; 
				SRAM[0x0003] = SRAM[0x0009]; 
				SRAM[0x0004] = SRAM[0x000a]; 
				SRAM[0x0005] = SRAM[0x000b];

/////////////////////////��ԴMAC��ַ/////////////////////////////////

				SRAM[0x0006] = MAC5;
				SRAM[0x0007] = MAC4;
				SRAM[0x0008] = MAC3;
				SRAM[0x0009] = MAC2;
				SRAM[0x000a] = MAC1;
				SRAM[0x000b] = MAC0;

//////////////////////////��0x0002 ΪARPӦ��/////////////////////////

				SRAM[0x0014] = 0x00;
				SRAM[0x0015] = 0x02;

//////////////////////////������MAC////////////////////////////////
	
				SRAM[0x0020] = SRAM[0x0016];	
				SRAM[0x0021] = SRAM[0x0017]; 
				SRAM[0x0022] = SRAM[0x0018]; 
				SRAM[0x0023] = SRAM[0x0019]; 
				SRAM[0x0024] = SRAM[0x001a]; 
				SRAM[0x0025] = SRAM[0x001b];

//////////////////////////������IP/////////////////////////////////

				SRAM[0x0026] = SRAM[0x001c]; 
				SRAM[0x0027] = SRAM[0x001d]; 
				SRAM[0x0028] = SRAM[0x001e]; 
				SRAM[0x0029] = SRAM[0x001f];

//////////////////////////��Ӧ��MAC///////////////////////////////

				SRAM[0x0016] = MAC5;	
				SRAM[0x0017] = MAC4; 
				SRAM[0x0018] = MAC3; 
				SRAM[0x0019] = MAC2; 
				SRAM[0x001a] = MAC1; 
				SRAM[0x001b] = MAC0;

//////////////////////////��Ӧ��IP///////////////////////////////
				
				SRAM[0x001c] = IP3; 
				SRAM[0x001d] = IP2; 
				SRAM[0x001e] = IP1; 
				SRAM[0x001f] = IP0;
////////////////////////д�����ݰ�//////////////////////////////

                        xierushujubao(0x002a);
				
////////////////////////////����///////////////////////////////

  ENC28J60_BFS(0x1f,0x08);  //ECON1.TXRTSλ��1  ��������

				    
}




void ICMPyingda()	//�յ�ICMP �������ݰ��� ���ü��޸�SRAM����ΪӦ�����ݰ�
{

////////////////////ԴMAC��ַ�͵�Ŀ��MAC��ַ/////////////////////

            SRAM[0x0000] = SRAM[0x0006];	
		    SRAM[0x0001] = SRAM[0x0007]; 
		    SRAM[0x0002] = SRAM[0x0008]; 
			SRAM[0x0003] = SRAM[0x0009]; 
			SRAM[0x0004] = SRAM[0x000a]; 
			SRAM[0x0005] = SRAM[0x000b];

/////////////////////////��ԴMAC��ַ/////////////////////////////

			SRAM[0x0006] = MAC5;
			SRAM[0x0007] = MAC4;
			SRAM[0x0008] = MAC3;
			SRAM[0x0009] = MAC2;
			SRAM[0x000a] = MAC1;
			SRAM[0x000b] = MAC0;
		
////////////////////////��IP��ʶ�ֶ�/////////////////////////////

		        ++IPj;
			SRAM[0x0012] = IPj >> 8;
			SRAM[0x0013] = IPj;

/////////////////////////��IP TTL///////////////////////////////

			SRAM[0x0016] = 0x4d;

//////////////////////ԴIP��ַ�͵�Ŀ��IP��ַ/////////////////////

			SRAM[0x001e] = SRAM[0x001a];
			SRAM[0x001f] = SRAM[0x001b];
			SRAM[0x0020] = SRAM[0x001c];
			SRAM[0x0021] = SRAM[0x001d];

////////////////////////��ԴIP��ַ//////////////////////////////	    	

			SRAM[0x001a] = IP3;
			SRAM[0x001b] = IP2;
			SRAM[0x001c] = IP1;
			SRAM[0x001d] = IP0;

////////////////////////��0x00 Ϊ��ӦӦ��///////////////////////
			
			SRAM[0x0022] = 0x00;

////////////////////////IPУ�����0/////////////////////////////   
			
			SRAM[0x0018] = 0x00;
			SRAM[0x0019] = 0x00;

////////////////////////ICMPУ�����0///////////////////////////

			SRAM[0x0024] = 0x00;
			SRAM[0x0025] = 0x00;

////////////////////////д�����ݰ�//////////////////////////////

                        xierushujubao(jjh);

////////////////////////����IPУ���//////////////////////////// ipЧ���λ��0x0018~0x0019

                        ENC28J60_jisuanxiaoyanhe(0x000f,0x0022,0x0019); //ENC28J60���ͻ��������ֽ�Ϊ0x00 ����λ��Ҫ+1

////////////////////////����ICMPУ���////////////////////////// icmpЧ���λ��0x0024~0x0025

                        ENC28J60_jisuanxiaoyanhe(0x0023,jjh,0x0025); //ENC28J60���ͻ��������ֽ�Ϊ0x00 ����λ��Ҫ+1

///////////////////////����///////////////////////////////

  ENC28J60_BFS(0x1f,0x08);  //ECON1.TXRTSλ��1  ��������
			     
}




void jiafachuli_32BIT(A,B,C,D,K)  //�ӷ����� 32BIT + 16BIT
{
           D = D + (K & 0x00ff);
		   C = C + ((K >> 8) & 0x00ff);

		   C = C + (D >> 8);
		   B = B + (C >> 8);
		   aaa = A + (B >> 8);

		   bbb = B;
		   ccc = C;
		   ddd = D;

}



void TCP_fasong(char D_MAC5,char D_MAC4,char D_MAC3,char D_MAC2,char D_MAC1,char D_MAC0,char D_IP3,char D_IP2,char D_IP1,char 
D_IP0,char D_DK1,char D_DK0,char xh3,char xh2,char xh1,char xh0,char qrh3,char qrh2,char qrh1,char qrh0,char tcptbcd,char 
bz,ckdx,DATAdx)	//��Ŀ��MAC��IP���˿ڡ���š�ȷ�Ϻš�TCPͷ�����ȡ���־�����ڴ�С��TCP 20�ֽں����ݴ�С ���ü�����TCP��
{

///////////////////////��Ŀ��MAC///////////////////////////

	      		SRAM[0x0000] = D_MAC5;
				SRAM[0x0001] = D_MAC4;
				SRAM[0x0002] = D_MAC3;
				SRAM[0x0003] = D_MAC2;
				SRAM[0x0004] = D_MAC1;
				SRAM[0x0005] = D_MAC0;

///////////////////////��ԴMAC(����)////////////////////////

				SRAM[0x0006] = MAC5;
				SRAM[0x0007] = MAC4;
				SRAM[0x0008] = MAC3;
				SRAM[0x0009] = MAC2;
				SRAM[0x000a] = MAC1;
				SRAM[0x000b] = MAC0;

//////////////////////��֡����0x0800/////////////////////////

				SRAM[0x000c] = 0x08;
				SRAM[0x000d] = 0x00;

///////////////////////��IP�汾��ͷ������///////////////////

				SRAM[0x000e] = 0x45;

///////////////////////��������0x00/////////////////////////

				SRAM[0x000f] = 0x00;

/////////////////////////��IP������////////////////////////

				SRAM[0x0010] = 40 + DATAdx >> 8;
				SRAM[0x0011] = 40 + DATAdx;

////////////////////////��IP��ʶ///////////////////////////

			    ++IPj;
			    SRAM[0x0012] = IPj >> 8;	  
			    SRAM[0x0013] = IPj;

/////////////////////////��IP�ֶ�(һ��Ϊ0x4000)///////////

			    SRAM[0x0014] = 0x40;	  
			    SRAM[0x0015] = 0x00;

//////////////////////////��TTL////////////////////////////

				SRAM[0x0016] = 0x40;

//////////////////////////��Э��(0x06 TCP)/////////////////

				SRAM[0x0017] = 0x06;

///////////////////////////��ԴIP//////////////////////////

				SRAM[0x001a] = IP3;
				SRAM[0x001b] = IP2;
				SRAM[0x001c] = IP1;
				SRAM[0x001d] = IP0;

////////////////////////////��Ŀ��IP////////////////////////

				SRAM[0x001e] = D_IP3;
				SRAM[0x001f] = D_IP2;
				SRAM[0x0020] = D_IP1;
				SRAM[0x0021] = D_IP0;

///////////////////////////��Դ�˿�////////////////////////
				
				SRAM[0x0022] = HTTPdk >> 8;
				SRAM[0x0023] = HTTPdk;

////////////////////////��Ŀ�Ķ˿�////////////////////////

				SRAM[0x0024] = D_DK1;
				SRAM[0x0025] = D_DK0;

/////////////////////////�����///////////////////////////

				SRAM[0x0026] = xh3;
				SRAM[0x0027] = xh2;
				SRAM[0x0028] = xh1;
				SRAM[0x0029] = xh0;

/////////////////////////��ȷ�Ϻ�///////////////////////////

				SRAM[0x002a] = qrh3;
				SRAM[0x002b] = qrh2;
				SRAM[0x002c] = qrh1;
				SRAM[0x002d] = qrh0;

//////////////////////////��TCPͷ������///////////////////

				SRAM[0x002e] = tcptbcd;

//////////////////////////��TCP��־///////////////////

				SRAM[0x002f] = bz;

//////////////////////////��TCP���ڴ�С///////////////////

				SRAM[0x0030] = ckdx >> 8;
				SRAM[0x0031] = ckdx;

//////////////////////////IPЧ�����0/////////////////////

				SRAM[0x0018] = 0x00;
				SRAM[0x0019] = 0x00;

/////////////����IPͷ(IP��Э���ֶ�ֵ+IP����+���������ֽ�)////////////////

			    SRAM[0x0032] = DATAdx + 26 >> 8;    
			    SRAM[0x0033] = DATAdx + 26;

////////////////////////д�����ݰ�//////////////////////////////

                        xierushujubao(DATAdx += 54);

////////////////////////����IPУ���//////////////////////////// ipЧ���λ��0x0018~0x0019

                        ENC28J60_jisuanxiaoyanhe(0x000f,0x0022,0x0019); //ENC28J60���ͻ��������ֽ�Ϊ0x00 ����λ��Ҫ+1

////////////////////////����TCPУ���/////////////////////////// TCPЧ���λ��0x0032~0x0033 (TCPУ���Ҫ���� Դ/Ŀ��IP��IP��Э���ֶΡ�TCP����)

                        ENC28J60_jisuanxiaoyanhe(0x001b,DATAdx,0x0033); //ENC28J60���ͻ��������ֽ�Ϊ0x00 ����λ��Ҫ+1

///////////////////////����///////////////////////////////

  ENC28J60_BFS(0x1f,0x08);  //ECON1.TXRTSλ��1  ��������


}


void TCP_fasong1(char D_MAC5,char D_MAC4,char D_MAC3,char D_MAC2,char D_MAC1,char D_MAC0,char D_IP3,char D_IP2,char D_IP1,char 
D_IP0,char D_DK1,char D_DK0,char xh3,char xh2,char xh1,char xh0,char qrh3,char qrh2,char qrh1,char qrh0,char tcptbcd,char 
bz,ckdx,DATAdx)	//��Ŀ��MAC��IP���˿ڡ���š�ȷ�Ϻš�TCPͷ�����ȡ���־�����ڴ�С��TCP 20�ֽں����ݴ�С ���ü�����TCP��
{

///////////////////////��Ŀ��MAC///////////////////////////

	      		SRAM[0x0000] = D_MAC5;
				SRAM[0x0001] = D_MAC4;
				SRAM[0x0002] = D_MAC3;
				SRAM[0x0003] = D_MAC2;
				SRAM[0x0004] = D_MAC1;
				SRAM[0x0005] = D_MAC0;

///////////////////////��ԴMAC(����)////////////////////////

				SRAM[0x0006] = MAC5;
				SRAM[0x0007] = MAC4;
				SRAM[0x0008] = MAC3;
				SRAM[0x0009] = MAC2;
				SRAM[0x000a] = MAC1;
				SRAM[0x000b] = MAC0;

//////////////////////��֡����0x0800/////////////////////////

				SRAM[0x000c] = 0x08;
				SRAM[0x000d] = 0x00;

///////////////////////��IP�汾��ͷ������///////////////////

				SRAM[0x000e] = 0x45;

///////////////////////��������0x00/////////////////////////

				SRAM[0x000f] = 0x00;

/////////////////////////��IP������////////////////////////

				SRAM[0x0010] = 40 + DATAdx >> 8;
				SRAM[0x0011] = 40 + DATAdx;

////////////////////////��IP��ʶ///////////////////////////

			    ++IPj;
			    SRAM[0x0012] = IPj >> 8;	  
			    SRAM[0x0013] = IPj;

/////////////////////////��IP�ֶ�(һ��Ϊ0x4000)///////////

			    SRAM[0x0014] = 0x40;	  
			    SRAM[0x0015] = 0x00;

//////////////////////////��TTL////////////////////////////

				SRAM[0x0016] = 0x40;

//////////////////////////��Э��(0x06 TCP)/////////////////

				SRAM[0x0017] = 0x06;

///////////////////////////��ԴIP//////////////////////////

				SRAM[0x001a] = IP3;
				SRAM[0x001b] = IP2;
				SRAM[0x001c] = IP1;
				SRAM[0x001d] = IP0;

////////////////////////////��Ŀ��IP////////////////////////

				SRAM[0x001e] = D_IP3;
				SRAM[0x001f] = D_IP2;
				SRAM[0x0020] = D_IP1;
				SRAM[0x0021] = D_IP0;

///////////////////////////��Դ�˿�////////////////////////
				
				SRAM[0x0022] = HTTPdk >> 8;
				SRAM[0x0023] = HTTPdk;

////////////////////////��Ŀ�Ķ˿�////////////////////////

				SRAM[0x0024] = D_DK1;
				SRAM[0x0025] = D_DK0;

/////////////////////////�����///////////////////////////

				SRAM[0x0026] = xh3;
				SRAM[0x0027] = xh2;
				SRAM[0x0028] = xh1;
				SRAM[0x0029] = xh0;

/////////////////////////��ȷ�Ϻ�///////////////////////////

				SRAM[0x002a] = qrh3;
				SRAM[0x002b] = qrh2;
				SRAM[0x002c] = qrh1;
				SRAM[0x002d] = qrh0;

//////////////////////////��TCPͷ������///////////////////

				SRAM[0x002e] = tcptbcd;

//////////////////////////��TCP��־///////////////////

				SRAM[0x002f] = bz;

//////////////////////////��TCP���ڴ�С///////////////////

				SRAM[0x0030] = ckdx >> 8;
				SRAM[0x0031] = ckdx;

//////////////////////////IPЧ�����0/////////////////////

				SRAM[0x0018] = 0x00;
				SRAM[0x0019] = 0x00;

/////////////����IPͷ(IP��Э���ֶ�ֵ+IP����+���������ֽ�)////////////////

			    SRAM[0x0032] = DATAdx + 26 >> 8;    
			    SRAM[0x0033] = DATAdx + 26;

////////////////////////д�����ݰ�///////////////////////////////////////

                        xierushujubao(54);

////////////////////////���ͻ�����βָ��ָ�����1���ֽ�///////////////////

  DATAdx += 54;
  ENC28J60_WCR(0x06,DATAdx);  //ETXNDL	���ͻ�����βָ��ָ�����1���ֽ�
  ENC28J60_WCR(0x07,DATAdx >> 8);      //ETXNDH

////////////////////////����IPУ���//////////////////////////// ipЧ���λ��0x0018~0x0019

                        ENC28J60_jisuanxiaoyanhe(0x000f,0x0022,0x0019); //ENC28J60���ͻ��������ֽ�Ϊ0x00 ����λ��Ҫ+1

////////////////////////����TCPУ���/////////////////////////// TCPЧ���λ��0x0032~0x0033 (TCPУ���Ҫ���� Դ/Ŀ��IP��IP��Э���ֶΡ�TCP����)

                        ENC28J60_jisuanxiaoyanhe(0x001b,DATAdx,0x0033); //ENC28J60���ͻ��������ֽ�Ϊ0x00 ����λ��Ҫ+1

///////////////////////����///////////////////////////////

  //while(ENC28J60_RCR(0x1f),(SPI_D & 0x08) != 0);

  ENC28J60_BFS(0x1f,0x08);  //ECON1.TXRTSλ��1  ��������


}







void GET_lujingchuli()	//GET·������  ·���������� �����ļ��غźʹ�С
{

		 wjm[0] = 0x20;		 //�ļ�����20
		 wjm[1] = 0x20;
		 wjm[2] = 0x20;
		 wjm[3] = 0x20;
		 wjm[4] = 0x20;
		 wjm[5] = 0x20;
		 wjm[6] = 0x20;
		 wjm[7] = 0x20;

		 hzm[0] = 0x20;		 //��׺����20
		 hzm[1] = 0x20;
		 hzm[2] = 0x20;


		 mlcuhao3 = 0x00;	 //��Ŀ¼�غ�
		 mlcuhao2 = 0x00;
		 mlcuhao1 = 0x02;

		 qh = 0;  //���ļ�������

		 zz = 0x003a;  //�����ַ  HTTP�����е�1��0x2f(/)�ĵ�ַ

		 xj = 0;yj = 9;	//��0����  �趨�ļ�����������


         while(xj != 0xff)
		 {

			   xj++;

			   zzbc = SRAM[zz + xj];

		       if(zzbc == 0x2f)	  //����"/"����Ŀ¼����
			   {
			        TF_wenjianchaxun1(mlcuhao3,mlcuhao2,mlcuhao1,wjm[0],wjm[1],wjm[2],wjm[3],wjm[4],wjm[5],wjm
[6],wjm[7],hzm[0],hzm[1],hzm[2],0x10);  //����Ŀ¼

					if(wjbz == 1)
					{
						wjm[0] = 0x20;		 //�ļ�����20
		                wjm[1] = 0x20;
		                wjm[2] = 0x20;
		                wjm[3] = 0x20;
		                wjm[4] = 0x20;
		                wjm[5] = 0x20;
		                wjm[6] = 0x20;
		                wjm[7] = 0x20;

		                hzm[0] = 0x20;		 //��׺����20
		                hzm[1] = 0x20;
		                hzm[2] = 0x20;

					    mlcuhao3 = wjcuhao3;   //����Ϊ��Ŀ¼�غ�
						mlcuhao2 = wjcuhao2;
					    mlcuhao1 = wjcuhao1;

						qh = 0;	 //�µĲ�ѯ ���ļ������� 

						zz = zz + xj;  //���»�ַΪ�µ�0x2f��ַ

                        xj = 0;yj = 9;	//��0  �趨�ļ�����������
						
					}
					else   //�Ҳ���Ŀ¼���봦��
					{
						         wjm[0] = 0x57;
								 wjm[1]	= 0x41;
								 wjm[2]	= 0x56;
								 wjm[3]	= 0x20;
								 wjm[4]	= 0x20;
								 wjm[5]	= 0x20;
								 wjm[6]	= 0x20;
								 wjm[7]	= 0x20;

								 hzm[0]	= 0x57;
								 hzm[1]	= 0x41;
								 hzm[2]	= 0x56;

								 wjdx4 = 0x00;wjdx3 = 0x00;wjdx2 = 0x00;wjdx1 = 0x00;

					    xj = 0xff; //��ѭ������
					}
			   }
			   else
			   {
			       if(zzbc == 0x2e)	  //����"."�����л�����׺������
				   {
						 
				         if(qh == 0)
						 {
						     zz = zz + xj;  //���»�ַΪ0x2e��ַ
							 
							 qh = 1; //�л�Ϊ��׺������

							 xj = 0;yj = 4;	 //��0  �趨��׺����������

						 }
						 else  //�ļ������ֵ�2��"."  ���봦��
						 {
							     wjm[0] = 0x57;
								 wjm[1]	= 0x41;
								 wjm[2]	= 0x56;
								 wjm[3]	= 0x20;
								 wjm[4]	= 0x20;
								 wjm[5]	= 0x20;
								 wjm[6]	= 0x20;
								 wjm[7]	= 0x20;

								 hzm[0]	= 0x57;
								 hzm[1]	= 0x41;
								 hzm[2]	= 0x56;

								 wjdx4 = 0x00;wjdx3 = 0x00;wjdx2 = 0x00;wjdx1 = 0x00;

						     xj = 0xff;
						 }
						   
				   }
				   else
				   {
				       if(zzbc == 0x20 | zzbc == 0x3f)	//����" "��"?"�����ļ�����
					   {

							 

					         TF_wenjianchaxun1(mlcuhao3,mlcuhao2,mlcuhao1,wjm[0],wjm[1],wjm[2],wjm
[3],wjm[4],wjm[5],wjm[6],wjm[7],hzm[0],hzm[1],hzm[2],0x20);  //�����ļ�
							 
							 if(wjbz == 0)  //û�ҵ��ļ����봦��
							 {
							     wjm[0] = 0x54;
								 wjm[1]	= 0x58;
								 wjm[2]	= 0x54;
								 wjm[3]	= 0x20;
								 wjm[4]	= 0x20;
								 wjm[5]	= 0x20;
								 wjm[6]	= 0x20;
								 wjm[7]	= 0x20;

								 hzm[0]	= 0x54;
								 hzm[1]	= 0x58;
								 hzm[2]	= 0x54;

								 wjdx4 = 0x00;wjdx3 = 0x00;wjdx2 = 0x00;wjdx1 = 0x00; 
							 }

							 xj = 0xff;

							 if(zzbc == 0x3f) //Ϊ"?" ���봦��"?"��Ĳ���
							 {
							        wjm[0] = 0x57;
								    wjm[1] = 0x41;
								    wjm[2] = 0x56;
								    wjm[3] = 0x20;
								    wjm[4] = 0x20;
								    wjm[5] = 0x20;
								    wjm[6] = 0x20;
								    wjm[7] = 0x20;

								    hzm[0] = 0x57;
								    hzm[1] = 0x41;
								    hzm[2] = 0x56;

								    wjdx4 = 0x00;wjdx3 = 0x00;wjdx2 = 0x00;wjdx1 = 0x00; 
							 }

					   }
					   else
					   {
					        if(xj != yj)  //����û���� ���������ļ������׺��
							{
							     if((zzbc > 0x29 & zzbc < 0x3a) || (zzbc > 0x40 & zzbc < 0x5b) || zzbc == 95)	
//0~9 A~Z
								 {
								     if(qh == 0)
									 {
									    wjm[xj - 1] = zzbc;
									 }
									 else
									 {
									    hzm[xj - 1] = zzbc;
									 }
								 }
								 else
								 {
								    if(zzbc > 0x60 && zzbc < 0x7b)	 //a~z
									{
										zzbc = zzbc - 0x20;	 //��0x20���ΪA~Z

									    if(qh == 0)
										{
										   wjm[xj - 1] = zzbc;
										}
										else
										{
										   hzm[xj - 1] = zzbc;
										}
									}
								 }
							}
							else  //���ȳ��� ���봦��
							{
							     wjm[0] = 0x54;
								 wjm[1]	= 0x58;
								 wjm[2]	= 0x54;
								 wjm[3]	= 0x20;
								 wjm[4]	= 0x20;
								 wjm[5]	= 0x20;
								 wjm[6]	= 0x20;
								 wjm[7]	= 0x20;

								 hzm[0]	= 0x54;
								 hzm[1]	= 0x58;
								 hzm[2]	= 0x54;

								 wjdx4 = 0x00;wjdx3 = 0x00;wjdx2 = 0x00;wjdx1 = 0x00;
							     xj = 0xff;
							}
					   }
					   
				   }
			   }
		 }

}


void shijinzhizhuanhuan_32BIT(char a,char b,char c,char d) //��32λ��  ���ü����10���Ƶ�sjz(10λ10����) (���Ƽ�3��7��) 
{
			
			sjz10 = 0x00;sjz9 = 0x00;sjz8 = 0x00;sjz7 = 0x00;sjz6 = 0x00;sjz5 = 0x00;sjz4 = 0x00;sjz3 = 0x00;sjz2 
= 0x00;sjz1 = 0x00;


			ywj = 0;
		    while(ywj != 32)
			{
				  
				  if(sjz1 + 3 > 7)
				  {
				      sjz1 = sjz1 + 3;
				  }

				  if(sjz2 + 3 > 7)
				  {
				      sjz2 = sjz2 + 3;
				  }

				  if(sjz3 + 3 > 7)
				  {
				      sjz3 = sjz3 + 3;
				  }

				  if(sjz4 + 3 > 7)
				  {
				      sjz4 = sjz4 + 3;
				  }

				  if(sjz5 + 3 > 7)
				  {
				      sjz5 = sjz5 + 3;
				  }

				  if(sjz6 + 3 > 7)
				  {
				      sjz6 = sjz6 + 3;
				  }

				  if(sjz7 + 3 > 7)
				  {
				      sjz7 = sjz7 + 3;
				  }

				  if(sjz8 + 3 > 7)
				  {
				      sjz8 = sjz8 + 3;
				  }

				  if(sjz9 + 3 > 7)
				  {
				      sjz9 = sjz9 + 3;
				  }

				  if(sjz10 + 3 > 7)
				  {
				      sjz10 = sjz10 + 3;
				  }

			      sjz10 = sjz10 << 1;
				  sjz10 |= sjz9 >> 3;

				  sjz9 = sjz9 << 1;
				  sjz9 = sjz9 & 0x0f;
				  sjz9 |= sjz8 >> 3;

				  sjz8 = sjz8 << 1;
				  sjz8 = sjz8 & 0x0f;
				  sjz8 |= sjz7 >> 3;

				  sjz7 = sjz7 << 1;
				  sjz7 = sjz7 & 0x0f;
				  sjz7 |= sjz6 >> 3;

				  sjz6 = sjz6 << 1;
				  sjz6 = sjz6 & 0x0f;
				  sjz6 |= sjz5 >> 3;

				  sjz5 = sjz5 << 1;
				  sjz5 = sjz5 & 0x0f;
				  sjz5 |= sjz4 >> 3;

				  sjz4 = sjz4 << 1;
				  sjz4 = sjz4 & 0x0f;
				  sjz4 |= sjz3 >> 3;

				  sjz3 = sjz3 << 1;
				  sjz3 = sjz3 & 0x0f;
				  sjz3 |= sjz2 >> 3;

				  sjz2 = sjz2 << 1;
				  sjz2 = sjz2 & 0x0f;
				  sjz2 |= sjz1 >> 3;

				  sjz1 = sjz1 << 1;
				  sjz1 = sjz1 & 0x0f;
				  sjz1 |= ((a >> 7) & 0x01);

				  a = a << 1;
				  a |= ((b >> 7) & 0x01);

				  b = b << 1;
				  b |= ((c >> 7) & 0x01);

				  c = c << 1;
				  c |= ((d >> 7) & 0x01) ;

				  d = d << 1;

				  
				  ywj++;


			}

}



void HTTP_toubu()//��HTTPͷ��
{


             zzj = 0x36;  //��ʼλ��

////////////////////HTTP/1.1 200 OK////////////////////

			 SRAM[zzj] = 0x48;zzj++;
			 SRAM[zzj] = 0x54;zzj++;
			 SRAM[zzj] = 0x54;zzj++;
			 SRAM[zzj] = 0x50;zzj++;
			 SRAM[zzj] = 0x2f;zzj++;
			 SRAM[zzj] = 0x31;zzj++;
			 SRAM[zzj] = 0x2e;zzj++;
			 SRAM[zzj] = 0x31;zzj++;

			 SRAM[zzj] = 0x20;zzj++;

			 SRAM[zzj] = 0x32;zzj++;
			 SRAM[zzj] = 0x30;zzj++;
			 SRAM[zzj] = 0x30;zzj++;

			 SRAM[zzj] = 0x20;zzj++;

			 SRAM[zzj] = 0x4f;zzj++;
			 SRAM[zzj] = 0x4b;zzj++;

			 SRAM[zzj] = 0x0d;zzj++;
			 SRAM[zzj] = 0x0a;zzj++;

//////////////////////Content-Type///////////////////////

			 SRAM[zzj] = 0x43;zzj++;
			 SRAM[zzj] = 0x6f;zzj++;
			 SRAM[zzj] = 0x6e;zzj++;
			 SRAM[zzj] = 0x74;zzj++;
			 SRAM[zzj] = 0x65;zzj++;
			 SRAM[zzj] = 0x6e;zzj++;
			 SRAM[zzj] = 0x74;zzj++;
			 SRAM[zzj] = 0x2d;zzj++;
			 SRAM[zzj] = 0x54;zzj++;
			 SRAM[zzj] = 0x79;zzj++;
			 SRAM[zzj] = 0x70;zzj++;
			 SRAM[zzj] = 0x65;zzj++;

			 SRAM[zzj] = 0x3a;zzj++;

			 SRAM[zzj] = 0x20;zzj++;



			 if(hzm[0] == 0x54 & hzm[1] == 0x58 & hzm[2] == 0x54)  //.TXT?
			 {
			      SRAM[zzj] = 0x74;zzj++;	   // text/plain
			      SRAM[zzj] = 0x65;zzj++;
			      SRAM[zzj] = 0x78;zzj++;
			      SRAM[zzj] = 0x74;zzj++;
			      SRAM[zzj] = 0x2f;zzj++;
			      SRAM[zzj] = 0x70;zzj++;
			      SRAM[zzj] = 0x6c;zzj++;
			      SRAM[zzj] = 0x61;zzj++;
			      SRAM[zzj] = 0x69;zzj++;
			      SRAM[zzj] = 0x6e;zzj++;

			 }
			 else
			 {
			      if(hzm[0] == 0x48 & hzm[1] == 0x54 & hzm[2] == 0x4d) //.HTM?
				  {
				       SRAM[zzj] = 0x74;zzj++;	   // text/html
			           SRAM[zzj] = 0x65;zzj++;
			           SRAM[zzj] = 0x78;zzj++;
			           SRAM[zzj] = 0x74;zzj++;
			           SRAM[zzj] = 0x2f;zzj++;
			           SRAM[zzj] = 0x68;zzj++;
			           SRAM[zzj] = 0x74;zzj++;
			           SRAM[zzj] = 0x6d;zzj++;
			           SRAM[zzj] = 0x6c;zzj++;
			           
				  }
				  else
				  {
				       if(hzm[0] == 0x50 & hzm[1] == 0x4e & hzm[2] == 0x47)	 //.PNG?
					   {
					        SRAM[zzj] = 0x69;zzj++;	 // image/png
							SRAM[zzj] = 0x6d;zzj++;
							SRAM[zzj] = 0x61;zzj++;
							SRAM[zzj] = 0x67;zzj++;
							SRAM[zzj] = 0x65;zzj++;
							SRAM[zzj] = 0x2f;zzj++;
							SRAM[zzj] = 0x70;zzj++;
							SRAM[zzj] = 0x6e;zzj++;
							SRAM[zzj] = 0x67;zzj++;

					   }
					   else
					   {
					        if(hzm[0] == 0x4a & hzm[1] == 0x50 & hzm[2] == 0x47) //.JPG?
							{
							      SRAM[zzj] = 0x69;zzj++;	 // image/jpeg
							      SRAM[zzj] = 0x6d;zzj++;
						          SRAM[zzj] = 0x61;zzj++;
							      SRAM[zzj] = 0x67;zzj++;
							      SRAM[zzj] = 0x65;zzj++;
							      SRAM[zzj] = 0x2f;zzj++;
							      SRAM[zzj] = 0x6a;zzj++;
							      SRAM[zzj] = 0x70;zzj++;
							      SRAM[zzj] = 0x65;zzj++;
								  SRAM[zzj] = 0x67;zzj++;

							}
							else
							{
							     if(hzm[0] == 0x47 & hzm[1] == 0x49 & hzm[2] == 0x46) //.GIF?
								 {
								      SRAM[zzj] = 0x69;zzj++;	 // image/gif
							          SRAM[zzj] = 0x6d;zzj++;
						              SRAM[zzj] = 0x61;zzj++;
							          SRAM[zzj] = 0x67;zzj++;
							          SRAM[zzj] = 0x65;zzj++;
							          SRAM[zzj] = 0x2f;zzj++;
							          SRAM[zzj] = 0x67;zzj++;
							          SRAM[zzj] = 0x69;zzj++;
							          SRAM[zzj] = 0x66;zzj++;

								 }
								 else  //���ֽ���
								 {
								      SRAM[zzj] = 0x61;zzj++;	 // application/octet-stream
							          SRAM[zzj] = 0x70;zzj++;
						              SRAM[zzj] = 0x70;zzj++;
							          SRAM[zzj] = 0x6c;zzj++;
							          SRAM[zzj] = 0x69;zzj++;
							          SRAM[zzj] = 0x63;zzj++;
							          SRAM[zzj] = 0x61;zzj++;
							          SRAM[zzj] = 0x74;zzj++;
							          SRAM[zzj] = 0x69;zzj++;
									  SRAM[zzj] = 0x6f;zzj++;	 
							          SRAM[zzj] = 0x6e;zzj++;
						              SRAM[zzj] = 0x2f;zzj++;
							          SRAM[zzj] = 0x6f;zzj++;
							          SRAM[zzj] = 0x63;zzj++;
							          SRAM[zzj] = 0x74;zzj++;
							          SRAM[zzj] = 0x65;zzj++;
							          SRAM[zzj] = 0x74;zzj++;
							          SRAM[zzj] = 0x2d;zzj++;
									  SRAM[zzj] = 0x73;zzj++;
							          SRAM[zzj] = 0x74;zzj++;
							          SRAM[zzj] = 0x72;zzj++;
							          SRAM[zzj] = 0x65;zzj++;
							          SRAM[zzj] = 0x61;zzj++;
									  SRAM[zzj] = 0x6d;zzj++;

								 }
							}
					   }
				  }
			 }

     		 SRAM[zzj] = 0x0d;zzj++;
		     SRAM[zzj] = 0x0a;zzj++;

///////////////////////Content-Length///////////////////////

			 SRAM[zzj] = 0x43;zzj++;
			 SRAM[zzj] = 0x6f;zzj++;
			 SRAM[zzj] = 0x6e;zzj++;
			 SRAM[zzj] = 0x74;zzj++;
			 SRAM[zzj] = 0x65;zzj++;
			 SRAM[zzj] = 0x6e;zzj++;
			 SRAM[zzj] = 0x74;zzj++;
			 SRAM[zzj] = 0x2d;zzj++;
			 SRAM[zzj] = 0x4c;zzj++;
			 SRAM[zzj] = 0x65;zzj++;
			 SRAM[zzj] = 0x6e;zzj++;
			 SRAM[zzj] = 0x67;zzj++;
			 SRAM[zzj] = 0x74;zzj++;
			 SRAM[zzj] = 0x68;zzj++;

			 SRAM[zzj] = 0x3a;zzj++;

			 SRAM[zzj] = 0x20;zzj++;


			 shijinzhizhuanhuan_32BIT(wjdx4,wjdx3,wjdx2,wjdx1);

			SRAM[zzj] = sjz10 | 0x30;zzj++;
			 SRAM[zzj] = sjz9 | 0x30;zzj++;
			 SRAM[zzj] = sjz8 | 0x30;zzj++;
			 SRAM[zzj] = sjz7 | 0x30;zzj++;
			 SRAM[zzj] = sjz6 | 0x30;zzj++;
			 SRAM[zzj] = sjz5 | 0x30;zzj++;
			 SRAM[zzj] = sjz4 | 0x30;zzj++;
			 SRAM[zzj] = sjz3 | 0x30;zzj++;
			 SRAM[zzj] = sjz2 | 0x30;zzj++;
			 SRAM[zzj] = sjz1 | 0x30;zzj++;

			 SRAM[zzj] = 0x0d;zzj++;
			 SRAM[zzj] = 0x0a;zzj++;

////////////////////Accept-Ranges///////////////////

			 SRAM[zzj] = 0x41;zzj++;
			 SRAM[zzj] = 0x63;zzj++;
			 SRAM[zzj] = 0x63;zzj++;
			 SRAM[zzj] = 0x65;zzj++;
			 SRAM[zzj] = 0x70;zzj++;
			 SRAM[zzj] = 0x74;zzj++;
			 SRAM[zzj] = 0x2d;zzj++;
			 SRAM[zzj] = 0x52;zzj++;
			 SRAM[zzj] = 0x61;zzj++;
			 SRAM[zzj] = 0x6e;zzj++;
			 SRAM[zzj] = 0x67;zzj++;
			 SRAM[zzj] = 0x65;zzj++;
			 SRAM[zzj] = 0x73;zzj++;
			 SRAM[zzj] = 0x3a;zzj++;

			 SRAM[zzj] = 0x20;zzj++;

			 SRAM[zzj] = 0x62;zzj++;
			 SRAM[zzj] = 0x79;zzj++;
			 SRAM[zzj] = 0x74;zzj++;
			 SRAM[zzj] = 0x65;zzj++;
			 SRAM[zzj] = 0x73;zzj++;

			 SRAM[zzj] = 0x0d;zzj++;
			 SRAM[zzj] = 0x0a;zzj++;

////////////////////Content-Disposition///////////////////			 

			 SRAM[zzj] = 0x43;zzj++;
			 SRAM[zzj] = 0x6f;zzj++;
			 SRAM[zzj] = 0x6e;zzj++;
			 SRAM[zzj] = 0x74;zzj++;
			 SRAM[zzj] = 0x65;zzj++;
			 SRAM[zzj] = 0x6e;zzj++;
			 SRAM[zzj] = 0x74;zzj++;
			 SRAM[zzj] = 0x2d;zzj++;
			 SRAM[zzj] = 0x44;zzj++;
			 SRAM[zzj] = 0x69;zzj++;
			 SRAM[zzj] = 0x73;zzj++;
			 SRAM[zzj] = 0x70;zzj++;
			 SRAM[zzj] = 0x6f;zzj++;
			 SRAM[zzj] = 0x73;zzj++;
			 SRAM[zzj] = 0x69;zzj++;
			 SRAM[zzj] = 0x74;zzj++;
			 SRAM[zzj] = 0x69;zzj++;
			 SRAM[zzj] = 0x6f;zzj++;
			 SRAM[zzj] = 0x6e;zzj++;

			 SRAM[zzj] = 0x3a;zzj++;

			 SRAM[zzj] = 0x20;zzj++;

			 
			 if((hzm[0] == 0x54 & hzm[1] == 0x58 & hzm[2] == 0x54) | (hzm[0] == 0x48 & hzm[1] == 0x54 & hzm[2] == 
0x4d) | (hzm[0] == 0x50 & hzm[1] == 0x4e & hzm[2] == 0x47) | (hzm[0] == 0x4a & hzm[1] == 0x50 & hzm[2] == 0x47) | (hzm[0] == 
0x47 & hzm[1] == 0x49 & hzm[2] == 0x46) | (hzm[0] == 0x53 & hzm[1] == 0x57 & hzm[2] == 0x46))  //ֱ�Ӵ򿪵ľͲ�����"����"
			 {
			 }
			 else //������"����"
			 {
			      SRAM[zzj] = 0x61;zzj++;
				  SRAM[zzj] = 0x74;zzj++;
				  SRAM[zzj] = 0x74;zzj++;
				  SRAM[zzj] = 0x61;zzj++;
				  SRAM[zzj] = 0x63;zzj++;
				  SRAM[zzj] = 0x68;zzj++;
				  SRAM[zzj] = 0x6d;zzj++;
				  SRAM[zzj] = 0x65;zzj++;
				  SRAM[zzj] = 0x6e;zzj++;
				  SRAM[zzj] = 0x74;zzj++;
				  SRAM[zzj] = 0x3b;zzj++;

				  SRAM[zzj] = 0x20;zzj++;
				  
			 }


			 SRAM[zzj] = 0x66;zzj++;	 ////// filename="
			 SRAM[zzj] = 0x69;zzj++;
			 SRAM[zzj] = 0x6c;zzj++;
			 SRAM[zzj] = 0x65;zzj++;
			 SRAM[zzj] = 0x6e;zzj++;
			 SRAM[zzj] = 0x61;zzj++;
			 SRAM[zzj] = 0x6d;zzj++;
			 SRAM[zzj] = 0x65;zzj++;
			 SRAM[zzj] = 0x3d;zzj++;
			 SRAM[zzj] = 0x22;zzj++;  

			 
			 if(wjm[0] != 0x20)	                           //�ļ���
			 {
			     if(wjm[0] > 0x40 & wjm[0] < 0x5b)
				 {
				     wjm[0] = wjm[0] + 0x20;
				 }
				 SRAM[zzj] = wjm[0];zzj++;

				 if(wjm[1] != 0x20)
				 {
				     if(wjm[1] > 0x40 & wjm[1] < 0x5b)
				     {
				         wjm[1] = wjm[1] + 0x20;
				     }
					 SRAM[zzj] = wjm[1];zzj++;

					 if(wjm[2] != 0x20)
				     {
				         if(wjm[2] > 0x40 & wjm[2] < 0x5b)
				         {
				             wjm[2] = wjm[2] + 0x20;
				         }
					     SRAM[zzj] = wjm[2];zzj++;

						 if(wjm[3] != 0x20)
				         {
				             if(wjm[3] > 0x40 & wjm[3] < 0x5b)
				             {
				                 wjm[3] = wjm[3] + 0x20;
				             }
					         SRAM[zzj] = wjm[3];zzj++;

						 	 if(wjm[4] != 0x20)
				             {
				                 if(wjm[4] > 0x40 & wjm[4] < 0x5b)
				                 {
				                     wjm[4] = wjm[4] + 0x20;
				                 }
					             SRAM[zzj] = wjm[4];zzj++;

						 		 if(wjm[5] != 0x20)
				                 {
				                     if(wjm[5] > 0x40 & wjm[5] < 0x5b)
				                     {
				                         wjm[5] = wjm[5] + 0x20;
				                     }
					                 SRAM[zzj] = wjm[5];zzj++;

						 			 if(wjm[6] != 0x20)
				                     {
				                         if(wjm[6] > 0x40 & wjm[6] < 0x5b)
				                         {
				                             wjm[6] = wjm[6] + 0x20;
				                         }
					                     SRAM[zzj] = wjm[6];zzj++;

						 				 if(wjm[7] != 0x20)
				                         {
				                             if(wjm[7] > 0x40 & wjm[7] < 0x5b)
				                             {
				                                 wjm[7] = wjm[7] + 0x20;
				                             }
					                         SRAM[zzj] = wjm[7];zzj++;

				                         }
				                     }
				                 }
				             }
				         }
				     }
				 }
			 }


			 if(hzm[0] != 0x20)	                               //��׺��
			 {
				 SRAM[zzj] = 0x2e;zzj++;  //�к�׺������"."

			     if(hzm[0] > 0x40 & hzm[0] < 0x5b)
				 {
				     hzm[0] = hzm[0] + 0x20;
				 }
				 SRAM[zzj] = hzm[0];zzj++;

				 if(hzm[1] != 0x20)	                           
			     {
				     if(hzm[1] > 0x40 & hzm[1] < 0x5b)
				     {
				         hzm[1] = hzm[1] + 0x20;
				     }
				     SRAM[zzj] = hzm[1];zzj++;

					 if(hzm[2] != 0x20)	                           
			         {
				         if(hzm[2] > 0x40 & hzm[2] < 0x5b)
				         {
				             hzm[2] = hzm[2] + 0x20;
				         }
				         SRAM[zzj] = hzm[2];zzj++;

			         }
			     }
			 }


			 SRAM[zzj] = 0x22;zzj++;  //  "

			 SRAM[zzj] = 0x0d;zzj++;
			 SRAM[zzj] = 0x0a;zzj++;
			 SRAM[zzj] = 0x0d;zzj++;
			 SRAM[zzj] = 0x0a;zzj++;


}


void TCP_Cqingling() //TCP���ƿ���0
{
  k = 0;
  while(k != (TCP_IIS*52))
  {
    TCP_C[k++] = 0x00;
  }
}



void TCP_chongfashuju2()	//�ط����� ����ÿ����1���������� ����
{

			 TF_cuhaozhuanshanqudizhi(TCP_C[TCPjzz + 0x1c + TCP_C[TCPjzz + 0x1b]],TCP_C[TCPjzz + 0x1d + TCP_C
[TCPjzz + 0x1b]],TCP_C[TCPjzz + 0x1e + TCP_C[TCPjzz + 0x1b]]); //��ָ��ָ��ĴغŶ��������ȵ�ַ


	         jiafachuli_24BIT(sqdz3,sqdz2,sqdz1,0x00,0x00,TCP_C[TCPjzz + 0x1a] - 4);	//�����ȼ���ƫ�� ƫ��Ϊ����ָ
���0x02 ǰ��0ʡ�� ��4��Ϊ���ϸ�����ƫ��

			 TF_RD_ENC28J60(aa,bb,cc);  //�������ϸ�����

			 jiafachuli_32BIT((~TCP_C[TCPjzz + 0x11]) & 0x00ff,(~TCP_C[TCPjzz + 0x12]) & 0x00ff,(~TCP_C[TCPjzz + 
0x13]) & 0x00ff,(~TCP_C[TCPjzz + 0x14]) & 0x00ff,0x0400); //��0x0400��ó����ϸ��������

			 TCP_fasong1(TCP_C[TCPjzz + 0x01],TCP_C[TCPjzz + 0x02],TCP_C[TCPjzz + 0x03],TCP_C[TCPjzz + 
0x04],TCP_C[TCPjzz + 0x05],TCP_C[TCPjzz + 0x06],TCP_C[TCPjzz + 0x07],TCP_C[TCPjzz + 0x08],TCP_C[TCPjzz + 0x09],TCP_C[TCPjzz + 
0x0a],TCP_C[TCPjzz + 0x0b],TCP_C[TCPjzz + 0x0c],~aaa,~bbb,~ccc,~ddd,TCP_C[TCPjzz + 0x0d],TCP_C[TCPjzz + 0x0e],TCP_C[TCPjzz + 
0x0f],TCP_C[TCPjzz + 0x10],0x50,0x18,0x0400,0x0200); //�������ϸ�����  ���Ϊ���ϸ��������


			 jiafachuli_24BIT(sqdz3,sqdz2,sqdz1,0x00,0x00,TCP_C[TCPjzz + 0x1a] - 2);	//�����ȼ���ƫ�� ƫ��
Ϊ����ָ���0x02 ǰ��0ʡ�� ��2��Ϊ�ϸ�����ƫ��

			 TF_RD_ENC28J60(aa,bb,cc);  //�����ϸ�����

			 jiafachuli_32BIT((~TCP_C[TCPjzz + 0x11]) & 0x00ff,(~TCP_C[TCPjzz + 0x12]) & 0x00ff,(~TCP_C[TCPjzz + 
0x13]) & 0x00ff,(~TCP_C[TCPjzz + 0x14]) & 0x00ff,0x0200); //��0x0200��ó��ϸ��������

			 TCP_fasong1(TCP_C[TCPjzz + 0x01],TCP_C[TCPjzz + 0x02],TCP_C[TCPjzz + 0x03],TCP_C[TCPjzz + 
0x04],TCP_C[TCPjzz + 0x05],TCP_C[TCPjzz + 0x06],TCP_C[TCPjzz + 0x07],TCP_C[TCPjzz + 0x08],TCP_C[TCPjzz + 0x09],TCP_C[TCPjzz + 
0x0a],TCP_C[TCPjzz + 0x0b],TCP_C[TCPjzz + 0x0c],~aaa,~bbb,~ccc,~ddd,TCP_C[TCPjzz + 0x0d],TCP_C[TCPjzz + 0x0e],TCP_C[TCPjzz + 
0x0f],TCP_C[TCPjzz + 0x10],0x50,0x18,0x0400,0x0200); //�����ϸ�����  ���Ϊ�ϸ��������


}



void TCP_chongfashuju1()   //�ط����� ����ÿ����1������ ����
{

			 TF_cuhaozhuanshanqudizhi(TCP_C[TCPjzz + 0x1c + TCP_C[TCPjzz + 0x1b] - 3],TCP_C[TCPjzz + 0x1d + 
TCP_C[TCPjzz + 0x1b] - 3],TCP_C[TCPjzz + 0x1e + TCP_C[TCPjzz + 0x1b] - 3]); //�����ϸ������ȵ�ַ  ��3Ϊ������� 


			 TF_RD_ENC28J60(sqdz3,sqdz2,sqdz1);  //�����ϸ�����

			 jiafachuli_32BIT((~TCP_C[TCPjzz + 0x11]) & 0x00ff,(~TCP_C[TCPjzz + 0x12]) & 0x00ff,(~TCP_C[TCPjzz + 
0x13]) & 0x00ff,(~TCP_C[TCPjzz + 0x14]) & 0x00ff,0x0200); //��0x0200��ó��ϸ��������

			 TCP_fasong1(TCP_C[TCPjzz + 0x01],TCP_C[TCPjzz + 0x02],TCP_C[TCPjzz + 0x03],TCP_C[TCPjzz + 
0x04],TCP_C[TCPjzz + 0x05],TCP_C[TCPjzz + 0x06],TCP_C[TCPjzz + 0x07],TCP_C[TCPjzz + 0x08],TCP_C[TCPjzz + 0x09],TCP_C[TCPjzz + 
0x0a],TCP_C[TCPjzz + 0x0b],TCP_C[TCPjzz + 0x0c],~aaa,~bbb,~ccc,~ddd,TCP_C[TCPjzz + 0x0d],TCP_C[TCPjzz + 0x0e],TCP_C[TCPjzz + 
0x0f],TCP_C[TCPjzz + 0x10],0x50,0x18,0x0400,0x0200); //�����ϸ�����  ���Ϊ�ϸ��������


}



void TCP_dingshiqi()	 //TCP��ʱ��	(��ʱ�ط��Ͷ�ʱ�Ͽ���������)
{

		 TCPjzz = 0;  lj = 0;

		 while(TCPjzz != (TCP_IIS*52))
		 {
		      if((TCP_C[TCPjzz] & 0x80) == 0x80)  //����Ч ����
			  {
					lj++;

			       if((TCP_C[TCPjzz] & 0x20) == 0x20 | (TCP_C[TCPjzz] & 0x10) == 0x10) //�򿪶�ʱ��?
				   {

							 TCP_C[TCPjzz + 0x15]--;  //��ʱ����1
							  
							 if(TCP_C[TCPjzz + 0x15] == 0x00)	 //��ʱ��Ϊ0����
							 { 

								   Bank0();  //�����ﺦ����...  �������ʱBank1.....������
��..

							       if((TCP_C[TCPjzz] & 0x20) == 0x20)  //������ʱ��
								   {
										  
										  TCP_fasong(TCP_C[TCPjzz + 0x01],TCP_C
[TCPjzz + 0x02],TCP_C[TCPjzz + 0x03],TCP_C[TCPjzz + 0x04],TCP_C[TCPjzz + 0x05],TCP_C[TCPjzz + 0x06],TCP_C[TCPjzz + 
0x07],TCP_C[TCPjzz + 0x08],TCP_C[TCPjzz + 0x09],TCP_C[TCPjzz + 0x0a],TCP_C[TCPjzz + 0x0b],TCP_C[TCPjzz + 0x0c],TCP_C[TCPjzz + 
0x11],TCP_C[TCPjzz + 0x12],TCP_C[TCPjzz + 0x13],TCP_C[TCPjzz + 0x14],TCP_C[TCPjzz + 0x0d],TCP_C[TCPjzz + 0x0e],TCP_C[TCPjzz + 
0x0f],TCP_C[TCPjzz + 0x10],0x50,0x11,0x0400,0x0000);	//�Ͽ����� FIN = 1
										  
								          TCP_C[TCPjzz] = 0x00;  //��TCP���־��0  �ͷ�

									      TCP_C[TCPjzz + 0x16] = 0x00;  //��TCP���ļ�ʣ��
�ֽڴ�С��0
									      TCP_C[TCPjzz + 0x17] = 0x00;
									      TCP_C[TCPjzz + 0x18] = 0x00;
									      TCP_C[TCPjzz + 0x19] = 0x00;

								   }
								   else
								   {
										  if((TCP_C[TCPjzz] & 0x0f) != 0x0f)  //�ط�������Ϊ15�� �����ط�
										  {
												TCP_C[TCPjzz]++; //�ط�������1

												TCP_C[TCPjzz + 0x15] = 2;  //��ʱ��װ�� 2��
					                            
											    if(cudx == 1)
											    {
													 TCP_chongfashuju1();
												}
												else
												{
													 TCP_chongfashuju2(); 
												}

										  }
										  else  //�ط���15�β��ص��蹷����
										  {
												TCP_C[TCPjzz] = 0x00;  //�����ӱ��־��0  �ͷ�

									            TCP_C[TCPjzz + 0x16] = 0x00;  //�����ӱ��ļ�ʣ���ֽڴ�С��0
									            TCP_C[TCPjzz + 0x17] = 0x00;
									            TCP_C[TCPjzz + 0x18] = 0x00;
									            TCP_C[TCPjzz + 0x19] = 0x00;

										  }

								   }
								    
							 }

						
				   }
			  }

			 TCPjzz = TCPjzz + 52; //ָ����һ����
		 }
	     

}



void TCP_fasongshuju_2() //��������  ����ÿ����1����������
{

	      if(SRAM[0x0030] > 4)	//���ڴ���2������?
		  {


			   if(TCP_C[TCPjzz + 0x1a] == cudx + cudx) //1���ص���������?
			   {
			          TCP_C[TCPjzz + 0x1b] = TCP_C[TCPjzz + 0x1b] + 3;	//��ָ��ָ����һ����

					  if(TCP_C[TCPjzz + 0x1b] == 24)  //8���ض���?
					  {
							 FAT32_cuhao_culian(TCP_C[TCPjzz + 0x31],TCP_C[TCPjzz + 0x32],TCP_C
[TCPjzz + 0x33]);  //������8���غ�

					         TCP_C[TCPjzz + 0x1c] = culian[0];	 //�����״غŵ���TCP��
							 TCP_C[TCPjzz + 0x1d] = culian[1];
							 TCP_C[TCPjzz + 0x1e] = culian[2];

							 TCP_C[TCPjzz + 0x1f] = culian[3];  //������7���غŵ���TCP��
							 TCP_C[TCPjzz + 0x20] = culian[4];
							 TCP_C[TCPjzz + 0x21] = culian[5];

							 TCP_C[TCPjzz + 0x22] = culian[6];
							 TCP_C[TCPjzz + 0x23] = culian[7];
							 TCP_C[TCPjzz + 0x24] = culian[8];

							 TCP_C[TCPjzz + 0x25] = culian[9];
							 TCP_C[TCPjzz + 0x26] = culian[10];
							 TCP_C[TCPjzz + 0x27] = culian[11];

							 TCP_C[TCPjzz + 0x28] = culian[12];
							 TCP_C[TCPjzz + 0x29] = culian[13];
							 TCP_C[TCPjzz + 0x2a] = culian[14];

							 TCP_C[TCPjzz + 0x2b] = culian[15];
							 TCP_C[TCPjzz + 0x2c] = culian[16];
							 TCP_C[TCPjzz + 0x2d] = culian[17];

							 TCP_C[TCPjzz + 0x2e] = culian[18];
							 TCP_C[TCPjzz + 0x2f] = culian[19];
							 TCP_C[TCPjzz + 0x30] = culian[20];

							 TCP_C[TCPjzz + 0x31] = culian[21];
							 TCP_C[TCPjzz + 0x32] = culian[22];
							 TCP_C[TCPjzz + 0x33] = culian[23];

							 TCP_C[TCPjzz + 0x1b] = 0;	 //��ָ����0
					  }


					TCP_C[TCPjzz + 0x1a] = 0; //����ָ����0  ָ�������

			   }


			   TF_cuhaozhuanshanqudizhi(TCP_C[TCPjzz + 0x1c + TCP_C[TCPjzz + 0x1b]],TCP_C[TCPjzz + 0x1d + TCP_C
[TCPjzz + 0x1b]],TCP_C[TCPjzz + 0x1e + TCP_C[TCPjzz + 0x1b]]); //��ָ��ָ��ĴغŶ��������ȵ�ַ




			   jiafachuli_24BIT(sqdz3,sqdz2,sqdz1,0x00,0x00,TCP_C[TCPjzz + 0x1a]); //�����ȼ���ƫ�� ƫ��Ϊ����ָ
���0x02 ǰ��0ʡ��

			   TF_RD_ENC28J60(aa,bb,cc);	//����1������  ��ַΪ�����ȼ���ƫ�ƵĽ��

			   TCP_C[TCPjzz + 0x1a] = TCP_C[TCPjzz + 0x1a] + 2; //����ָ��ָ����1������


			   if(TCP_C[TCPjzz + 0x16] == 0x00 & TCP_C[TCPjzz + 0x17] == 0x00 & TCP_C[TCPjzz + 0x18] < 2)  //�ļ�
ʣ���ֽ�С��1������?
			   {
					 k = TCP_C[TCPjzz + 0x18];  //.....����~~~	 ���ļ�ʣ���ֽڴ�С��16λת��Ϊ1��16
λ����
					 k = k << 8;
					 k |= TCP_C[TCPjzz + 0x19];

			       	 TCP_fasong1(TCP_C[TCPjzz + 0x01],TCP_C[TCPjzz + 0x02],TCP_C[TCPjzz + 0x03],TCP_C[TCPjzz + 
0x04],TCP_C[TCPjzz + 0x05],TCP_C[TCPjzz + 0x06],TCP_C[TCPjzz + 0x07],TCP_C[TCPjzz + 0x08],TCP_C[TCPjzz + 0x09],TCP_C[TCPjzz + 
0x0a],TCP_C[TCPjzz + 0x0b],TCP_C[TCPjzz + 0x0c],TCP_C[TCPjzz + 0x11],TCP_C[TCPjzz + 0x12],TCP_C[TCPjzz + 0x13],TCP_C[TCPjzz + 
0x14],TCP_C[TCPjzz + 0x0d],TCP_C[TCPjzz + 0x0e],TCP_C[TCPjzz + 0x0f],TCP_C[TCPjzz + 0x10],0x50,0x19,0x0400,k); //�����ļ�ʣ��
�ֽ�  FIN = 1 �Ͽ�����


					 TCP_C[TCPjzz] = 0x00;  //��TCP���־��0  �ͷ�

					 TCP_C[TCPjzz + 0x16] = 0x00;  //��TCP���ļ�ʣ���ֽڴ�С��0
					 TCP_C[TCPjzz + 0x17] = 0x00;
					 TCP_C[TCPjzz + 0x18] = 0x00;
					 TCP_C[TCPjzz + 0x19] = 0x00;
					  
			   }
			   else
			   {
			         TCP_fasong1(TCP_C[TCPjzz + 0x01],TCP_C[TCPjzz + 0x02],TCP_C[TCPjzz + 0x03],TCP_C[TCPjzz + 
0x04],TCP_C[TCPjzz + 0x05],TCP_C[TCPjzz + 0x06],TCP_C[TCPjzz + 0x07],TCP_C[TCPjzz + 0x08],TCP_C[TCPjzz + 0x09],TCP_C[TCPjzz + 
0x0a],TCP_C[TCPjzz + 0x0b],TCP_C[TCPjzz + 0x0c],TCP_C[TCPjzz + 0x11],TCP_C[TCPjzz + 0x12],TCP_C[TCPjzz + 0x13],TCP_C[TCPjzz + 
0x14],TCP_C[TCPjzz + 0x0d],TCP_C[TCPjzz + 0x0e],TCP_C[TCPjzz + 0x0f],TCP_C[TCPjzz + 0x10],0x50,0x18,0x0400,0x0200); //����1��
			   
					 jiafachuli_32BIT(TCP_C[TCPjzz + 0x11],TCP_C[TCPjzz + 0x12],TCP_C[TCPjzz + 
0x13],TCP_C[TCPjzz + 0x14],0x0200);  //ȷ�Ϻżӷ������ݴ�С 1������
									 
					 TCP_C[TCPjzz + 0x11] = aaa;   //�ӷ������ݴ�С���ȷ�ϺŴ����TCP��
					 TCP_C[TCPjzz + 0x12] = bbb;
					 TCP_C[TCPjzz + 0x13] = ccc;
					 TCP_C[TCPjzz + 0x14] = ddd;

					 jiafachuli_32BIT((~TCP_C[TCPjzz + 0x16]) & 0x00ff,(~TCP_C[TCPjzz + 0x17]) & 0x00ff,
(~TCP_C[TCPjzz + 0x18]) & 0x00ff,(~TCP_C[TCPjzz + 0x19]) & 0x00ff,0x0200); //�ļ�ʣ���ֽڼ�1������

					 TCP_C[TCPjzz + 0x16] = ~aaa;  //�������ļ�ʣ���ֽ�
					 TCP_C[TCPjzz + 0x17] = ~bbb;
					 TCP_C[TCPjzz + 0x18] = ~ccc;
					 TCP_C[TCPjzz + 0x19] = ~ddd;


					 if((~aaa) != 0x00 | (~bbb) != 0x00 | (~ccc) != 0x00 | (~ddd) != 0x00) //�ļ�ʣ���ֽ�
��С��Ϊ0
					 {

						   jiafachuli_24BIT(sqdz3,sqdz2,sqdz1,0x00,0x00,TCP_C[TCPjzz + 0x1a]); //����
�ȼ���ƫ�� ƫ��Ϊ����ָ���0x02 ǰ��0ʡ��

			               TF_RD_ENC28J60(aa,bb,cc);	//����1������  ��ַΪ�����ȼ���ƫ�ƵĽ��

			               TCP_C[TCPjzz + 0x1a] = TCP_C[TCPjzz + 0x1a] + 2; //����ָ��ָ����1������


			               if(TCP_C[TCPjzz + 0x16] == 0x00 & TCP_C[TCPjzz + 0x17] == 0x00 & TCP_C[TCPjzz + 0x18] 
< 2)  //�ļ�ʣ���ֽ�С��1������?
			               {
					             k = TCP_C[TCPjzz + 0x18];  //.....����~~~	 ���ļ�ʣ���ֽڴ�С��16λת��
Ϊ1��16λ����
					             k = k << 8;
					             k |= TCP_C[TCPjzz + 0x19];

			       	             TCP_fasong1(TCP_C[TCPjzz + 0x01],TCP_C[TCPjzz + 0x02],TCP_C[TCPjzz + 0x03],TCP_C
[TCPjzz + 0x04],TCP_C[TCPjzz + 0x05],TCP_C[TCPjzz + 0x06],TCP_C[TCPjzz + 0x07],TCP_C[TCPjzz + 0x08],TCP_C[TCPjzz + 
0x09],TCP_C[TCPjzz + 0x0a],TCP_C[TCPjzz + 0x0b],TCP_C[TCPjzz + 0x0c],TCP_C[TCPjzz + 0x11],TCP_C[TCPjzz + 0x12],TCP_C[TCPjzz + 
0x13],TCP_C[TCPjzz + 0x14],TCP_C[TCPjzz + 0x0d],TCP_C[TCPjzz + 0x0e],TCP_C[TCPjzz + 0x0f],TCP_C[TCPjzz + 
0x10],0x50,0x19,0x0400,k); //�����ļ�ʣ���ֽ� FIN = 1

									 
					             TCP_C[TCPjzz] = 0x00;  //��TCP���־��0  �ͷ�

					             TCP_C[TCPjzz + 0x16] = 0x00;  //��TCP���ļ�ʣ���ֽڴ�С��0
					             TCP_C[TCPjzz + 0x17] = 0x00;
					             TCP_C[TCPjzz + 0x18] = 0x00;
					             TCP_C[TCPjzz + 0x19] = 0x00;

			               }
			               else
			               {
			                     TCP_fasong1(TCP_C[TCPjzz + 0x01],TCP_C[TCPjzz + 0x02],TCP_C[TCPjzz + 0x03],TCP_C
[TCPjzz + 0x04],TCP_C[TCPjzz + 0x05],TCP_C[TCPjzz + 0x06],TCP_C[TCPjzz + 0x07],TCP_C[TCPjzz + 0x08],TCP_C[TCPjzz + 
0x09],TCP_C[TCPjzz + 0x0a],TCP_C[TCPjzz + 0x0b],TCP_C[TCPjzz + 0x0c],TCP_C[TCPjzz + 0x11],TCP_C[TCPjzz + 0x12],TCP_C[TCPjzz + 
0x13],TCP_C[TCPjzz + 0x14],TCP_C[TCPjzz + 0x0d],TCP_C[TCPjzz + 0x0e],TCP_C[TCPjzz + 0x0f],TCP_C[TCPjzz + 
0x10],0x50,0x18,0x0400,0x0200);  //����1��
			   
					             jiafachuli_32BIT(TCP_C[TCPjzz + 0x11],TCP_C[TCPjzz + 0x12],TCP_C[TCPjzz 
+ 0x13],TCP_C[TCPjzz + 0x14],0x0200);  //ȷ�Ϻżӷ������ݴ�С
									 
					             TCP_C[TCPjzz + 0x11] = aaa;   //�ӷ������ݴ�С���ȷ�ϺŴ����TCP��
					             TCP_C[TCPjzz + 0x12] = bbb;
					             TCP_C[TCPjzz + 0x13] = ccc;
					             TCP_C[TCPjzz + 0x14] = ddd;

					             jiafachuli_32BIT((~TCP_C[TCPjzz + 0x16]) & 0x00ff,(~TCP_C[TCPjzz + 
0x17]) & 0x00ff,(~TCP_C[TCPjzz + 0x18]) & 0x00ff,(~TCP_C[TCPjzz + 0x19]) & 0x00ff,0x0200); //�ļ�ʣ���ֽڼ�1������

					             TCP_C[TCPjzz + 0x16] = ~aaa;  //�������ļ�ʣ���ֽ�
					             TCP_C[TCPjzz + 0x17] = ~bbb;
					             TCP_C[TCPjzz + 0x18] = ~ccc;
					             TCP_C[TCPjzz + 0x19] = ~ddd;

					             TCP_C[TCPjzz + 0x15] = 2;  //��ʱ��װ�� 2��
					            
					             TCP_C[TCPjzz] = 0x90;	 //�����ط���ʱ��

			               }


					 }
					 else
					 {
							TCP_C[TCPjzz + 0x15] = 2;  //��ʱ��װ�� 2�� ���1�����������ʵ�...��
;�����Ļ��ʸ�  ������ �ط�����ֻ�չ���;����
					        
					        TCP_C[TCPjzz] = 0xa0;	 //����������ʱ��

					 }

			   }
 
		  }
		  else
		  {
		         TCP_C[TCPjzz + 0x15] = 60;  //��ʱ��װ�� 60��
				 
				 TCP_C[TCPjzz] = 0xa0;	 //����������ʱ�� 
		  }


}


void TCP_fasongshuju_1() // ��������  ����ÿ����1������
{

		  if(SRAM[0x0030] > 2)	//���ڴ���1������?
		  {

					  if(TCP_C[TCPjzz + 0x1b] == 24)  //8���ض���?
					  {
							 FAT32_cuhao_culian(TCP_C[TCPjzz + 0x31],TCP_C[TCPjzz + 0x32],TCP_C
[TCPjzz + 0x33]);  //������8���غ�

					         TCP_C[TCPjzz + 0x1c] = culian[0];	 //�����״غŵ���TCP��
							 TCP_C[TCPjzz + 0x1d] = culian[1];
							 TCP_C[TCPjzz + 0x1e] = culian[2];

							 TCP_C[TCPjzz + 0x1f] = culian[3];  //������7���غŵ���TCP��
							 TCP_C[TCPjzz + 0x20] = culian[4];
							 TCP_C[TCPjzz + 0x21] = culian[5];

							 TCP_C[TCPjzz + 0x22] = culian[6];
							 TCP_C[TCPjzz + 0x23] = culian[7];
							 TCP_C[TCPjzz + 0x24] = culian[8];

							 TCP_C[TCPjzz + 0x25] = culian[9];
							 TCP_C[TCPjzz + 0x26] = culian[10];
							 TCP_C[TCPjzz + 0x27] = culian[11];

							 TCP_C[TCPjzz + 0x28] = culian[12];
							 TCP_C[TCPjzz + 0x29] = culian[13];
							 TCP_C[TCPjzz + 0x2a] = culian[14];

							 TCP_C[TCPjzz + 0x2b] = culian[15];
							 TCP_C[TCPjzz + 0x2c] = culian[16];
							 TCP_C[TCPjzz + 0x2d] = culian[17];

							 TCP_C[TCPjzz + 0x2e] = culian[18];
							 TCP_C[TCPjzz + 0x2f] = culian[19];
							 TCP_C[TCPjzz + 0x30] = culian[20];

							 TCP_C[TCPjzz + 0x31] = culian[21];
							 TCP_C[TCPjzz + 0x32] = culian[22];
							 TCP_C[TCPjzz + 0x33] = culian[23];

							 TCP_C[TCPjzz + 0x1b] = 0;	 //��ָ����0
					  }

			   TF_cuhaozhuanshanqudizhi(TCP_C[TCPjzz + 0x1c + TCP_C[TCPjzz + 0x1b]],TCP_C[TCPjzz + 0x1d + TCP_C
[TCPjzz + 0x1b]],TCP_C[TCPjzz + 0x1e + TCP_C[TCPjzz + 0x1b]]); //��ָ��ָ��ĴغŶ��������ȵ�ַ



			   TF_RD_ENC28J60(sqdz3,sqdz2,sqdz1);	//����1������  ��ַΪ������

			   TCP_C[TCPjzz + 0x1b] = TCP_C[TCPjzz + 0x1b] + 3;	//��ָ��ָ����һ����

			   if(TCP_C[TCPjzz + 0x16] == 0x00 & TCP_C[TCPjzz + 0x17] == 0x00 & TCP_C[TCPjzz + 0x18] < 2)  //�ļ�
ʣ���ֽ�С��1������?
			   {
					 k = TCP_C[TCPjzz + 0x18];  //.....����~~~	 ���ļ�ʣ���ֽڴ�С��16λת��Ϊ1��16
λ����
					 k = k << 8;
					 k |= TCP_C[TCPjzz + 0x19];

			       	 TCP_fasong1(TCP_C[TCPjzz + 0x01],TCP_C[TCPjzz + 0x02],TCP_C[TCPjzz + 0x03],TCP_C[TCPjzz + 
0x04],TCP_C[TCPjzz + 0x05],TCP_C[TCPjzz + 0x06],TCP_C[TCPjzz + 0x07],TCP_C[TCPjzz + 0x08],TCP_C[TCPjzz + 0x09],TCP_C[TCPjzz + 
0x0a],TCP_C[TCPjzz + 0x0b],TCP_C[TCPjzz + 0x0c],TCP_C[TCPjzz + 0x11],TCP_C[TCPjzz + 0x12],TCP_C[TCPjzz + 0x13],TCP_C[TCPjzz + 
0x14],TCP_C[TCPjzz + 0x0d],TCP_C[TCPjzz + 0x0e],TCP_C[TCPjzz + 0x0f],TCP_C[TCPjzz + 0x10],0x50,0x19,0x0400,k); //�����ļ�ʣ��
�ֽ�  FIN = 1


					 TCP_C[TCPjzz] = 0x00;  //��TCP���־��0  �ͷ�

					 TCP_C[TCPjzz + 0x16] = 0x00;  //��TCP���ļ�ʣ���ֽڴ�С��0
					 TCP_C[TCPjzz + 0x17] = 0x00;
					 TCP_C[TCPjzz + 0x18] = 0x00;
					 TCP_C[TCPjzz + 0x19] = 0x00;

			   }
			   else
			   {
			         TCP_fasong1(TCP_C[TCPjzz + 0x01],TCP_C[TCPjzz + 0x02],TCP_C[TCPjzz + 0x03],TCP_C[TCPjzz + 
0x04],TCP_C[TCPjzz + 0x05],TCP_C[TCPjzz + 0x06],TCP_C[TCPjzz + 0x07],TCP_C[TCPjzz + 0x08],TCP_C[TCPjzz + 0x09],TCP_C[TCPjzz + 
0x0a],TCP_C[TCPjzz + 0x0b],TCP_C[TCPjzz + 0x0c],TCP_C[TCPjzz + 0x11],TCP_C[TCPjzz + 0x12],TCP_C[TCPjzz + 0x13],TCP_C[TCPjzz + 
0x14],TCP_C[TCPjzz + 0x0d],TCP_C[TCPjzz + 0x0e],TCP_C[TCPjzz + 0x0f],TCP_C[TCPjzz + 0x10],0x50,0x18,0x0400,0x0200);
			   
					 jiafachuli_32BIT(TCP_C[TCPjzz + 0x11],TCP_C[TCPjzz + 0x12],TCP_C[TCPjzz + 
0x13],TCP_C[TCPjzz + 0x14],0x0200);  //ȷ�Ϻżӷ������ݴ�С
									 
					 TCP_C[TCPjzz + 0x11] = aaa;   //�ӷ������ݴ�С���ȷ�ϺŴ����TCP��
					 TCP_C[TCPjzz + 0x12] = bbb;
					 TCP_C[TCPjzz + 0x13] = ccc;
					 TCP_C[TCPjzz + 0x14] = ddd;

					 jiafachuli_32BIT((~TCP_C[TCPjzz + 0x16]) & 0x00ff,(~TCP_C[TCPjzz + 0x17]) & 0x00ff,
(~TCP_C[TCPjzz + 0x18]) & 0x00ff,(~TCP_C[TCPjzz + 0x19]) & 0x00ff,0x0200); //�ļ�ʣ���ֽڼ�1������

					 TCP_C[TCPjzz + 0x16] = ~aaa;  //�������ļ�ʣ���ֽ�
					 TCP_C[TCPjzz + 0x17] = ~bbb;
					 TCP_C[TCPjzz + 0x18] = ~ccc;
					 TCP_C[TCPjzz + 0x19] = ~ddd;

					 TCP_C[TCPjzz + 0x15] = 2;  //��ʱ��װ��  2��
					 
					 TCP_C[TCPjzz] = 0x90;	 //�����ط���ʱ��

			   }
   
		  }
		  else
		  {
		         TCP_C[TCPjzz + 0x15] = 60;  //��ʱ��װ�� 60��
				 
				 TCP_C[TCPjzz] = 0xa0;	 //����������ʱ��
				  
		  }

}



void TCPchuli() //TCP����
{


          if(SRAM[0x0024] == (HTTPdk >> 8) & SRAM[0x0025] == (HTTPdk & 0x00ff)) //  Ŀ��˿���ȷ
		  {

          //////////////////ɨ��TCP��鿴�Ƿ���һ��������////////////////

				TCPkbz = 0;  //���־��0

			    TCPjzz = 0;  //��ָ����0

				while(TCPjzz != (TCP_IIS*52) & TCPkbz == 0)
			    {
					 if((TCP_C[TCPjzz] & 0x80) == 0x80)  //����Ч ����Ա�
					 { 
						  if(TCP_C[TCPjzz + 0x07] == SRAM[0x001a] & TCP_C[TCPjzz + 0x08] == SRAM
[0x001b] & TCP_C[TCPjzz + 0x09] == SRAM[0x001c] & TCP_C[TCPjzz + 0x0a] == SRAM[0x001d] & TCP_C[TCPjzz + 0x0b] == SRAM[0x0022] 
& TCP_C[TCPjzz + 0x0c] == SRAM[0x0023]) //�յ��İ�ԴIP��Դ�˿���TCP��һ��?
						  {
							  TCPkbz = 1;
						  }
					 }
												  
					TCPjzz = TCPjzz + 52; //ָ����һ��TCP��
					
			    }

				
		  ///////////////////////////TCP��־�жϴ���//////////////////////////

				if(TCPkbz == 0)	//û��һ��������
				{
				     if(SRAM[0x002f] == 0x02)   //SYN = 1 ��������
					 {
					      TCPjzz = 0;  //��ָ����0

						  while(TCPjzz != (TCP_IIS*52))
						  {
						       if(TCP_C[TCPjzz] == 0x00)  //������TCP��? (���ӿռ�)
							   {


							         TCP_C[TCPjzz + 0x01] = SRAM[0x0006];	//����ԴMAC����TCP��
									 TCP_C[TCPjzz + 0x02] = SRAM[0x0007];
									 TCP_C[TCPjzz + 0x03] = SRAM[0x0008];
									 TCP_C[TCPjzz + 0x04] = SRAM[0x0009];
									 TCP_C[TCPjzz + 0x05] = SRAM[0x000a];
									 TCP_C[TCPjzz + 0x06] = SRAM[0x000b];

									 TCP_C[TCPjzz + 0x07] = SRAM[0x001a];	//����ԴIP��
��TCP��
									 TCP_C[TCPjzz + 0x08] = SRAM[0x001b];
									 TCP_C[TCPjzz + 0x09] = SRAM[0x001c];
									 TCP_C[TCPjzz + 0x0a] = SRAM[0x001d];

									 TCP_C[TCPjzz + 0x0b] = SRAM[0x0022];   //����Դ�˿�
����TCP��
									 TCP_C[TCPjzz + 0x0c] = SRAM[0x0023];

									 jiafachuli_32BIT(SRAM[0x0026],SRAM[0x0027],SRAM
[0x0028],SRAM[0x0029],0x0001); //��ż�1

									 TCP_C[TCPjzz + 0x0d] = aaa;   //��1�����Ŵ����TCP
��
									 TCP_C[TCPjzz + 0x0e] = bbb;
									 TCP_C[TCPjzz + 0x0f] = ccc;
									 TCP_C[TCPjzz + 0x10] = ddd;

									 TCP_C[TCPjzz + 0x11] = 0x77;   //ȷ�ϺŴ����TCP��
									 TCP_C[TCPjzz + 0x12] = 0x77;
									 TCP_C[TCPjzz + 0x13] = 0x77;
									 TCP_C[TCPjzz + 0x14] = 0x78;


									 SRAM[0x003a] = 0x01;  //��NOP	
				                     SRAM[0x003b] = 0x01;
				                     SRAM[0x003c] = 0x01;
				                     SRAM[0x003d] = 0x01;
				                     SRAM[0x003e] = 0x01;
				                     SRAM[0x003f] = 0x01;

				                     SRAM[0x0040] = 0x04;  //�� TCP SACK����ѡ��:��  
				                     SRAM[0x0041] = 0x02;

									 TCP_fasong(SRAM[0x0006],SRAM[0x0007],SRAM
[0x0008],SRAM[0x0009],SRAM[0x000a],SRAM[0x000b],SRAM[0x001a],SRAM[0x001b],SRAM[0x001c],SRAM[0x001d],SRAM[0x0022],SRAM
[0x0023],0x77,0x77,0x77,0x77,aaa,bbb,ccc,ddd,0x80,0x12,0x0400,0x000c);  //���� ACK = 1 SYN = 1  �ظ���������


									 TCP_C[TCPjzz + 0x15] = 2;  //��ʱ��װ�� 2��
									 
									 TCP_C[TCPjzz] = 0xa0;	//����������ʱ��  ͬʱ��־��
����Ч

									 TCPjzz = (TCP_IIS*52); //����ѭ��
							   }
							   else
							   {
							         TCPjzz = TCPjzz + 52;	//ָ����һ��TCP��
							   }

						  }
					 }
					 else
					 {
						   if((SRAM[0x002f] & 0x01) == 0x01)  //FIN = 1 �Ͽ�����
						   {
								jiafachuli_32BIT(SRAM[0x0026],SRAM[0x0027],SRAM[0x0028],SRAM
[0x0029],0x0001);

							    TCP_fasong(SRAM[0x0006],SRAM[0x0007],SRAM[0x0008],SRAM
[0x0009],SRAM[0x000a],SRAM[0x000b],SRAM[0x001a],SRAM[0x001b],SRAM[0x001c],SRAM[0x001d],SRAM[0x0022],SRAM[0x0023],SRAM
[0x002a],SRAM[0x002b],SRAM[0x002c],SRAM[0x002d],aaa,bbb,ccc,ddd,0x50,0x10,0x0400,0x0000);  //���� ACK = 1 �ظ�ȷ��
										  
						   }

					 }

				}
				else  //��һ��������
				{
					 TCPjzz = TCPjzz - 52; //ָ���TCP����ʼλ��
					 
				     if(SRAM[0x002f] == 0x10)	  //ACK = 1 ��ȷ��
					 {
					      if(TCP_C[TCPjzz + 0x0d] == SRAM[0x0026] & TCP_C[TCPjzz + 0x0e] == SRAM[0x0027] 
& TCP_C[TCPjzz + 0x0f] == SRAM[0x0028] & TCP_C[TCPjzz + 0x10] == SRAM[0x0029] & TCP_C[TCPjzz + 0x11] == SRAM[0x002a] & TCP_C
[TCPjzz + 0x12] == SRAM[0x002b] & TCP_C[TCPjzz + 0x13] == SRAM[0x002c] & TCP_C[TCPjzz + 0x14] == SRAM[0x002d])	 //�յ���ACK
�����ȷ�Ϻźʹ�TCP���һ��?
						  {

								if(TCP_C[TCPjzz + 0x16] == 0x00 & TCP_C[TCPjzz + 0x17] == 
0x00 & TCP_C[TCPjzz + 0x18] == 0x00 & TCP_C[TCPjzz + 0x19] == 0x00) //��TCP���ļ�ʣ���ֽڴ�СΪ0?
								{
								      TCP_C[TCPjzz + 0x15] = 2;  //��ʱ��װ�� 2��
									  
									  TCP_C[TCPjzz] = 0xa0;	//����������ʱ��


								}
								else  //�ļ�ʣ���ֽڴ�С��Ϊ0
								{
									  if(cudx == 1)
									  {
										 TCP_fasongshuju_1();

										 //zzzz = zzzz + 430;	 //430������
									  }
									  else
									  {
									     TCP_fasongshuju_2();

										 //zzzz = zzzz + 900;	 //900������
									  }

								}

						  }
					 }
					 else
					 {
					      if(SRAM[0x002f] == 0x18)   //ACK = 1 PUSH = 1 ֱ����Ӧ�ó���
						  { 
								if(SRAM[0x0036] == 0x47 & SRAM[0x0037] == 0x45 & SRAM[0x0038] 
== 0x54) //GET����?	 (���������ж�GET)
								{
									 jiafachuli_32BIT(SRAM[0x0026],SRAM[0x0027],SRAM
[0x0028],SRAM[0x0029],jjh - 54);  //��ż�Я�����ݴ�С
									 
							         TCP_C[TCPjzz + 0x0d] = aaa;   //��Я�����ݴ�С�����Ŵ����
TCP��
							         TCP_C[TCPjzz + 0x0e] = bbb;
							         TCP_C[TCPjzz + 0x0f] = ccc;
							         TCP_C[TCPjzz + 0x10] = ddd;

								     TCP_C[TCPjzz + 0x11] = SRAM[0x002a];   //ȷ�ϺŴ����TCP
��
							         TCP_C[TCPjzz + 0x12] = SRAM[0x002b];
							         TCP_C[TCPjzz + 0x13] = SRAM[0x002c];
								     TCP_C[TCPjzz + 0x14] = SRAM[0x002d];

								     TCP_fasong(SRAM[0x0006],SRAM[0x0007],SRAM[0x0008],SRAM
[0x0009],SRAM[0x000a],SRAM[0x000b],SRAM[0x001a],SRAM[0x001b],SRAM[0x001c],SRAM[0x001d],SRAM[0x0022],SRAM[0x0023],SRAM
[0x002a],SRAM[0x002b],SRAM[0x002c],SRAM[0x002d],aaa,bbb,ccc,ddd,0x50,0x10,0x0400,0x0000);  //���� ACK = 1 �ظ�ȷ��
								
									 GET_lujingchuli(); //GET·���������� �����ļ��غź�
��С

									 TCP_C[TCPjzz + 0x16] = wjdx4; 	 //�ļ��ֽڴ�С�����
TCP��
									 TCP_C[TCPjzz + 0x17] = wjdx3;
									 TCP_C[TCPjzz + 0x18] = wjdx2;
									 TCP_C[TCPjzz + 0x19] = wjdx1;

									 if(wjdx4 != 0x00 | wjdx3 != 0x00 | wjdx2 != 0x00 | 
wjdx1 != 0x00) //�ļ��ֽڴ�С��Ϊ0����
									 {
									       TCP_C[TCPjzz + 0x1c] = wjcuhao3;	 //�����״غ�
����TCP��
										   TCP_C[TCPjzz + 0x1d] = wjcuhao2;
										   TCP_C[TCPjzz + 0x1e] = wjcuhao1;

										   FAT32_cuhao_culian(wjcuhao3,wjcuhao2,wjcuhao1);

										   TCP_C[TCPjzz + 0x1f] = culian[0];  //����
��7���غŵ���TCP��
										   TCP_C[TCPjzz + 0x20] = culian[1];
										   TCP_C[TCPjzz + 0x21] = culian[2];

										   TCP_C[TCPjzz + 0x22] = culian[3];
										   TCP_C[TCPjzz + 0x23] = culian[4];
										   TCP_C[TCPjzz + 0x24] = culian[5];

										   TCP_C[TCPjzz + 0x25] = culian[6];
										   TCP_C[TCPjzz + 0x26] = culian[7];
										   TCP_C[TCPjzz + 0x27] = culian[8];

										   TCP_C[TCPjzz + 0x28] = culian[9];
										   TCP_C[TCPjzz + 0x29] = culian[10];
										   TCP_C[TCPjzz + 0x2a] = culian[11];

										   TCP_C[TCPjzz + 0x2b] = culian[12];
										   TCP_C[TCPjzz + 0x2c] = culian[13];
										   TCP_C[TCPjzz + 0x2d] = culian[14];

										   TCP_C[TCPjzz + 0x2e] = culian[15];
										   TCP_C[TCPjzz + 0x2f] = culian[16];
										   TCP_C[TCPjzz + 0x30] = culian[17];

										   TCP_C[TCPjzz + 0x31] = culian[18];
										   TCP_C[TCPjzz + 0x32] = culian[19];
										   TCP_C[TCPjzz + 0x33] = culian[20];
										   
										   TCP_C[TCPjzz + 0x1b]	= 0;   //�غ�ָ����0

										   TCP_C[TCPjzz + 0x1a]	= 0;   //����ָ����0


									 }


									 HTTP_toubu();	//��HTTPͷ��

									 TCP_fasong(TCP_C[TCPjzz + 0x01],TCP_C[TCPjzz + 
0x02],TCP_C[TCPjzz + 0x03],TCP_C[TCPjzz + 0x04],TCP_C[TCPjzz + 0x05],TCP_C[TCPjzz + 0x06],TCP_C[TCPjzz + 0x07],TCP_C[TCPjzz + 
0x08],TCP_C[TCPjzz + 0x09],TCP_C[TCPjzz + 0x0a],TCP_C[TCPjzz + 0x0b],TCP_C[TCPjzz + 0x0c],TCP_C[TCPjzz + 0x11],TCP_C[TCPjzz + 
0x12],TCP_C[TCPjzz + 0x13],TCP_C[TCPjzz + 0x14],TCP_C[TCPjzz + 0x0d],TCP_C[TCPjzz + 0x0e],TCP_C[TCPjzz + 0x0f],TCP_C[TCPjzz + 
0x10],0x50,0x18,0x0400,zzj - 54); //����HTTPͷ��

									 jiafachuli_32BIT(TCP_C[TCPjzz + 0x11],TCP_C[TCPjzz + 
0x12],TCP_C[TCPjzz + 0x13],TCP_C[TCPjzz + 0x14],zzj - 54);  //��TCP���ȷ�Ϻ� + HTTPͷ����С

									 TCP_C[TCPjzz + 0x11] = aaa;  //�����ش�TCP���ȷ��
��
									 TCP_C[TCPjzz + 0x12] = bbb;
									 TCP_C[TCPjzz + 0x13] = ccc;
									 TCP_C[TCPjzz + 0x14] = ddd;

									 TCP_C[TCPjzz + 0x15] = 2;  //��ʱ��װ��  2��
									
									 TCP_C[TCPjzz] = 0xa0;	//����������ʱ��
									 
									 
								}
								else  //����GET���� �Ͽ������ͷſռ�
								{
									 TCP_C[TCPjzz] = 0x00;  //��TCP���־��0  �ͷ�

									 TCP_C[TCPjzz + 0x16] = 0x00;  //��TCP���ļ�ʣ���ֽ�
��С��0
									 TCP_C[TCPjzz + 0x17] = 0x00;
									 TCP_C[TCPjzz + 0x18] = 0x00;
									 TCP_C[TCPjzz + 0x19] = 0x00; 				
					 
								}

						  }
						  else
						  {
						       if((SRAM[0x002f] & 0x04) == 0x04)  //RST = 1 �ؽ�����  (RST��ɾ)
							   {
							         TCP_C[TCPjzz] = 0x00;  //��TCP���־��0  �ͷ�

									 TCP_C[TCPjzz + 0x16] = 0x00;  //��TCP���ļ�ʣ���ֽ�
��С��0
									 TCP_C[TCPjzz + 0x17] = 0x00;
									 TCP_C[TCPjzz + 0x18] = 0x00;
									 TCP_C[TCPjzz + 0x19] = 0x00; 
							   }
							   else
							   {
							        if((SRAM[0x002f] & 0x01) == 0x01)  //FIN = 1 �Ͽ�����
									{
										  jiafachuli_32BIT(SRAM[0x0026],SRAM
[0x0027],SRAM[0x0028],SRAM[0x0029],0x0001);	//��ż�1

									      TCP_fasong(SRAM[0x0006],SRAM[0x0007],SRAM
[0x0008],SRAM[0x0009],SRAM[0x000a],SRAM[0x000b],SRAM[0x001a],SRAM[0x001b],SRAM[0x001c],SRAM[0x001d],SRAM[0x0022],SRAM
[0x0023],SRAM[0x002a],SRAM[0x002b],SRAM[0x002c],SRAM[0x002d],aaa,bbb,ccc,ddd,0x50,0x10,0x0400,0x0000);  //���� ACK = 1 �ظ�ȷ
��
									
										  TCP_C[TCPjzz] = 0x00;  //��TCP���־��0  ��
��

									      TCP_C[TCPjzz + 0x16] = 0x00;  //��TCP���ļ�ʣ��
�ֽڴ�С��0
									      TCP_C[TCPjzz + 0x17] = 0x00;
									      TCP_C[TCPjzz + 0x18] = 0x00;
									      TCP_C[TCPjzz + 0x19] = 0x00;

									}
									else
									{
									      TCP_C[TCPjzz] = 0x00;  //��TCP���־��0  �ͷ�

									      TCP_C[TCPjzz + 0x16] = 0x00;  //��TCP���ļ�ʣ��
�ֽڴ�С��0
									      TCP_C[TCPjzz + 0x17] = 0x00;
									      TCP_C[TCPjzz + 0x18] = 0x00;
									      TCP_C[TCPjzz + 0x19] = 0x00; 

									}
							   }
						  }
					 }
				}



				 
									  		       
		  }




}



void TCP_IP() //TCP_IP�հ�����
{


		if(SRAM[0x000c] == 0x08 & SRAM[0x000d] == 0x06)	 //ARP?
		{
			if(SRAM[0x0014] == 0x00 & SRAM[0x0015] == 0x01)	  //ARP�����? 
		    {
			     if(SRAM[0x0026] == IP3 & SRAM[0x0027] == IP2 & SRAM[0x0028] == IP1 & SRAM[0x0029] == IP0)	//��
��IP?
				 {
					 ARPyingda();
			     }
			}
			else
			{
				 if(SRAM[0x0014] == 0x00 & SRAM[0x0015] == 0x02)	 //ARPӦ���?
				 {
					  if(SRAM[0x0000] == MAC5 & SRAM[0x0001] == MAC4 & SRAM[0x0002] == MAC3 & SRAM
[0x0003] == MAC2 & SRAM[0x0004] == MAC1 & SRAM[0x0005] == MAC0)	  //����MAC��ַ?
					  {
					  }
				 }
			}
	    }
		else //IP
		{
			 if(SRAM[0x000c] == 0x08 & SRAM[0x000d] == 0x00)  //IP?
			 {
				 if(SRAM[0x0000] == MAC5 & SRAM[0x0001] == MAC4 & SRAM[0x0002] == MAC3 & SRAM[0x0003] == MAC2 
& SRAM[0x0004] == MAC1 & SRAM[0x0005] == MAC0)	//����MAC��ַ?
				 {
					 if(SRAM[0x000e] == 0x45 & SRAM[0x001e] == IP3 & SRAM[0x001f] == IP2 & SRAM[0x0020] 
== IP1 & SRAM[0x0021] == IP0)  //IPV4?  5X32?  ����IP?
					 {
						  if(SRAM[0x0017] == 1)	//ICMP?
						  {
								if(SRAM[0x0022] == 0x08)  //��Ӧ����?
								{
									ICMPyingda(); //���촦��
							    }
						  }
						  else
						  {
								if(SRAM[0x0017] == 6)  //TCP?
								{
								     TCPchuli(); //TCP����
								}
						  }
					 }
				 }
		     }
		}


}



void TCP_IP_HTTP_RUN()
{

  /*  zzzz++;
    if(zzzz > 0x3400)	 //����ȷ0.25���׼
    {

      zzzz = 0;
      zzz++;
      TCP_dingshiqi();

    } */

    if(QSJJ == 0 && sbc != DS1302_RD(0))
    {

      sbc = DS1302_RD(0);
      TCP_dingshiqi();

    }

    //Bank1();

    //ENC28J60_RCR(0x19);
 
    //if(SPI_D != 0)		 //EPKTCNT����0ʱ����  �����ݰ�

    if((SPI_INT & 0x01) == 0 || ENC28J60_SJBBZ == 1) //ENC28J60���ж� �� ��־�������ݰ� ����
    {

     /////////////////////////////////////���ղ���////////////////////////////////////////////////
						
       jieshoushujubao();

      //////////////////////////////////////////// TCP/IP /////////////////////////////////////////////////
					   	
      if(jjh < 713)	//����SRAM��������
      {
        TCP_IP();
      }

      /////////////////////////////////////////////////////////////////////////////////////////////////////	  		


    }

}