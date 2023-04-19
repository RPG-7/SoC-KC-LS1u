void jiafachuli_24BIT(a,b,c,d,e,f) //24λ�ӷ�����  FAT32�ļ�ϵͳ��
{
                a = a + d;
		b = b + e;
		c = c + f;

		b = b + (c >> 8);
		aa = a + (b >> 8);

		bb = b;
		cc = c;
		
}


void FAT32_tiquyindaoxinxi()	 //��ȡ������Ϣ
{

//////////////////////////////��ȡ����������ַ//////////////////////////////////////

		TF_RD(0x00,0x00,0x00,200);   //����0����

		FAT1H = SRAM[0x01c7 + 200] << 1;
		FAT1H |= SRAM[0x01c6 + 200] >> 7;		//0�����������ȵ�����������0x02  0x0200ǰ����ʡ�� ��ͬ����1λ 
 ��ʱ��FAT1HL��������������ַ
		FAT1L = SRAM[0x01c6 + 200] << 1;
  

///////////////////////��ȡ�ش�С��FAT��������FAT1��ַ��FAT2��ַ����������ַ///////////

		TF_RD(0x00,FAT1H,FAT1L,200); //������������

		cudx = SRAM[0x000d + 200];  //��ȡ�ش�С

		FATsl = SRAM[0x0010 + 200];  //��ȡFAT������


		FAT2L = SRAM[0x000f + 200] << 1;
		FAT2L |= SRAM[0x000e + 200] >> 7;	  //�����ȵ�FAT1������������0x02  0x0200ǰ����ʡ�� ��ͬ����1λ  ��ʱ
��FAT2L��LL���������ȵ�FAT1��ƫ���� 
		FAT2LL = SRAM[0x000e + 200] << 1;


		jiafachuli_24BIT(0x00,FAT1H,FAT1L,0x00,FAT2L,FAT2LL);  //����������ַ + �����ȵ�FAT1��ƫ����  �õ�FAT1��ַ
		FAT1H = bb;FAT1L = cc;


		DATAH = SRAM[0x0025 + 200] >> 7;
		DATAL = SRAM[0x0025 + 200] << 1;	  //FAT������������0x02	0x0200ǰ����ʡ�� ��ͬ����1λ  ��ʱ��DATAH��L
��LL����FAT���С
		DATAL |= SRAM[0x0024 + 200] >> 7;	
		DATALL = SRAM[0x0024 + 200] << 1;

							  

		if(FATsl == 0x01)
		{
			 jiafachuli_24BIT(0x00,FAT1H,FAT1L,DATAH,DATAL,DATALL);	//FAT1��ַ + FAT���С  �õ���������ַ
			 DATAH = aa;DATAL = bb;DATALL = cc;
			 
		}
		else
		{
		     jiafachuli_24BIT(0x00,FAT1H,FAT1L,DATAH,DATAL,DATALL);	//FAT1��ַ + FAT���С  �õ�FAT2��ַ
			 FAT2H = aa;FAT2L = bb;FAT2LL = cc;
			   
		     jiafachuli_24BIT(FAT2H,FAT2L,FAT2LL,DATAH,DATAL,DATALL);  //FAT2��ַ + FAT���С  �õ���������ַ
			 DATAH = aa;DATAL = bb;DATALL = cc;
		}

	
}


void TF_cuhaozhuanshanqudizhi(cuhao3,cuhao2,cuhao1)	 //�غ�ת������ַ  ��8λ��ʡ��~~~  �㶮�á�����SPI 4G���� 4G����512��
�� = ������(0x800000)
{
        
		cuhao1 = cuhao1 - 2;		  //�غż�2

		if((cuhao1 & 0xff00) == 0xff00)
		{
		    cuhao1 = cuhao1 & 0x00ff;				  //��λ����

		    cuhao2--;
			if((cuhao2 & 0xff00) == 0xff00)
			{
				cuhao2 = cuhao2 & 0x00ff;

			    cuhao3--;
			}
		}
		
		k = 1;
		while(k != cudx + cudx)		   //....������~~~~������������ʼ��ַ��X�ص�ƫ��
		{
		     cuhao1 = cuhao1 + cuhao1;		   //��ֵ��2
		     cuhao2 = cuhao2 + cuhao2;
	         cuhao3 = cuhao3 + cuhao3;

		     cuhao2 = cuhao2 + (cuhao1 >> 8);	   //��λ����
			 cuhao1 = cuhao1 & 0x00ff;
		     cuhao3 = cuhao3 + (cuhao2 >> 8);
			 cuhao2 = cuhao2 & 0x00ff;
			 k = k + k;
	    }
	

	    cuhao1 = cuhao1 + DATALL;	  //��������ʼ��ַ��X�ص�ƫ�� + ��������ʼ��ַ  �õ�����������ַ
		cuhao2 = cuhao2 + DATAL;
		cuhao3 = cuhao3 + DATAH;

		cuhao2 = cuhao2 + (cuhao1 >> 8);	  //��λ����
		sqdz3 = cuhao3 + (cuhao2 >> 8);

		sqdz2 = cuhao2;
		sqdz1 = cuhao1;

}


void FAT32_cuhao_culian(cuhao3,cuhao2,cuhao1) //���غŶ�������  ����Ϊx
{

		 bencu3 = ~cuhao3;	//Ū�ɲ�һ���Ĳ��ܽ�����

    	 x = 0;
	     while((cuhao3 != 0xff | cuhao2 != 0xff | cuhao1 != 0xff) & (x != 8))
		 {

              if(bencu3 == cuhao3 & bencu2 == cuhao2 & (bencu1 & 0x80) == (cuhao1 & 0x80))	  //��һ�غͱ�����ͬһ����?	
 (ÿ����Ϊ0~127��)
			  {
			      cuhao3 = SRAM[((cuhao1 << 2) & 0x01ff) + 202];	   
				  cuhao2 = SRAM[((cuhao1 << 2) & 0x01ff) + 201];   
				  cuhao1 = SRAM[((cuhao1 << 2) & 0x01ff) + 200];
			  }
			  else	  //����ͬһ����
			  {
			      bencu3 = cuhao3;bencu2 = cuhao2;bencu1 = cuhao1;  //��һ�غ���Ϊ����
									 

				 /////////////////////////��������ڵ���������������/////////////////////// (�غų�4�ֽ�(����
2λ) ��9λ��ȥ ��Ϊ����������ƫ��   ��9λΪ�������ֽ�ƫ��)

				  jiafachuli_24BIT(cuhao3 >> 6,((cuhao3 << 2) | (cuhao2 >> 6)) & 0x00ff,((cuhao2 << 2) | 
(cuhao1 >> 6)) & 0x00fe,0x00,FAT1H,FAT1L);  //����������ƫ�� + FAT1��ַ �õ�����������

				  TF_RD(aa,bb,cc,200);

				 //////////////////////////�Ѵ�ֵ������ ��Ϊ��һ��////////////////////////////(�غų�4�ֽ�(��
��2λ) ��9λ��Ϊ��ֵ��1�ֽ�ָ��

				  cuhao3 = SRAM[((cuhao1 << 2) & 0x01ff) + 202];	   
				  cuhao2 = SRAM[((cuhao1 << 2) & 0x01ff) + 201];   
				  cuhao1 = SRAM[((cuhao1 << 2) & 0x01ff) + 200];


			  }

			  culian[0 + x + x + x] = cuhao3;
			  culian[1 + x + x + x] = cuhao2;
			  culian[2 + x + x + x] = cuhao1; 
			 	 

			  x++;
		 }	  
			   
}


void TF_wenjianchaxun1(cuhao3,cuhao2,cuhao1,wjm1,wjm2,wjm3,wjm4,wjm5,wjm6,wjm7,wjm8,hzm1,hzm2,hzm3,mlwj)
{

////////////////////////////////////////////////�Ȳ�ѯ��һ��
��////////////////////////////////////////////////////////////////////

							wjbz = 0; //�ļ���־��0

							
							TF_cuhaozhuanshanqudizhi(cuhao3,cuhao2,cuhao1);  //�Ѵص���������ַָ
�������
							
						    y = 0;
							while(y != cudx & wjbz == 0)	//û������1���ؾͼ�����
							{
									
									TF_RD(sqdz3,sqdz2,sqdz1,200); //�Ѵ����ȶ�����
									
									k = 200;
									while(k != 712 & wjbz == 0)
									{
										 
									     if(SRAM[k] != 0xe5 & SRAM[k] != 0xe2 & SRAM[k + 
0x0b] == mlwj)
										 {
										     if(SRAM[k] == wjm1 & SRAM[k + 1] == wjm2 
& SRAM[k + 2] == wjm3 & SRAM[k + 3] == wjm4 & SRAM[k + 4] == wjm5 & SRAM[k + 5] == wjm6 & SRAM[k + 6] == wjm7 & SRAM[k + 7] 
== wjm8 & SRAM[k + 8] == hzm1 & SRAM[k + 9] == hzm2 & SRAM[k + 10] == hzm3)	//�ļ����ͺ�׺��һ��?
											 {
											      wjcuhao3 = SRAM[k + 0x14];	
//�����ļ���ʼ�غ�
												  wjcuhao2 = SRAM[k + 0x1b];
												  wjcuhao1 = SRAM[k + 0x1a];

												  wjdx4 = SRAM[k + 0x1f];	
  //�����ļ���С
												  wjdx3 = SRAM[k + 0x1e];
												  wjdx2 = SRAM[k + 0x1d];
												  wjdx1 = SRAM[k + 0x1c];

												  wjbz = 1;	 //�ҵ��ļ�
												  
											 }
										 }

									     k = k + 32;
									}

									jiafachuli_24BIT(sqdz3,sqdz2,sqdz1,0x00,0x00,0x02);	
//�����ȼ�1������
									sqdz3 = aa;sqdz2 = bb;sqdz1 = cc;

							        y++;

							}

			 				

////////////////////////////////////////////////��1����û�ҵ��ļ��Ͳ�ʣ�µ�
��////////////////////////////////////////////////////////////////////////


			 x = 8;  //����Ū�����˾ͽ�ȥ
	         while(x == 8 & wjbz == 0)	  //������8���ؽ��������8����  û������8����˵����ff ff ff ����
			 {
					
			        FAT32_cuhao_culian(cuhao3,cuhao2,cuhao1);	//������8����

				    cuhao3 = culian[0];	  //�ؼĴ� = ��1����
				    cuhao2 = culian[1];
				    cuhao1 = culian[2];
					
					x = 0;
					while((x != 8) & (cuhao3 != 0xff | cuhao2 != 0xff | cuhao1 != 0xff) & wjbz == 0)  //
û������8���� & �ز�Ϊ���һ�� ������...
					{

					        TF_cuhaozhuanshanqudizhi(cuhao3,cuhao2,cuhao1);  //�Ѵص���������ַָ�������
							
						    y = 0;
							while(y != cudx & wjbz == 0)	//û������1���ؾͼ�����
							{
								
									TF_RD(sqdz3,sqdz2,sqdz1,200); //�Ѵ����ȶ�����

									k = 200;
									while(k != 712 & wjbz == 0)
									{
										 
									     if(SRAM[k] != 0xe5 & SRAM[k] != 0xe2 & SRAM[k + 
0x0b] == mlwj)
										 {	 
										     if(SRAM[k] == wjm1 & SRAM[k + 1] == wjm2 
& SRAM[k + 2] == wjm3 & SRAM[k + 3] == wjm4 & SRAM[k + 4] == wjm5 & SRAM[k + 5] == wjm6 & SRAM[k + 6] == wjm7 & SRAM[k + 7] 
== wjm8 & SRAM[k + 8] == hzm1 & SRAM[k + 9] == hzm2 & SRAM[k + 10] == hzm3)	//�ļ����ͺ�׺��һ��?
											 {
											      wjcuhao3 = SRAM[k + 0x14];	
//�����ļ���ʼ�غ�
												  wjcuhao2 = SRAM[k + 0x1b];
												  wjcuhao1 = SRAM[k + 0x1a];

												  wjdx4 = SRAM[k + 0x1f];	
  //�����ļ���С
												  wjdx3 = SRAM[k + 0x1e];
												  wjdx2 = SRAM[k + 0x1d];
												  wjdx1 = SRAM[k + 0x1c];

												  wjbz = 1;	 //�ҵ��ļ�
												  
											 }
										 }

									     k = k + 32;
									}
									
									jiafachuli_24BIT(sqdz3,sqdz2,sqdz1,0x00,0x00,0x02);	
//�����ȼ�1������
									sqdz3 = aa;sqdz2 = bb;sqdz1 = cc;

							        y++;

							}


						    x++;

						    if(x != 8)	 //������8���ؾͲ�����  ���ִؼĴ�Ϊ��8��
						    {
						       cuhao3 = culian[x + x + x];		 //��8�����еĵ�x�ض������ؼ�
��
				               cuhao2 = culian[x + x + x + 1];
				               cuhao1 = culian[x + x + x + 2];
						    }

					}
				 

			 }


}