void jiafachuli_24BIT(a,b,c,d,e,f) //24位加法处理  FAT32文件系统用
{
                a = a + d;
		b = b + e;
		c = c + f;

		b = b + (c >> 8);
		aa = a + (b >> 8);

		bb = b;
		cc = c;
		
}


void FAT32_tiquyindaoxinxi()	 //提取引导信息
{

//////////////////////////////提取引导扇区地址//////////////////////////////////////

		TF_RD(0x00,0x00,0x00,200);   //读出0扇区

		FAT1H = SRAM[0x01c7 + 200] << 1;
		FAT1H |= SRAM[0x01c6 + 200] >> 7;		//0扇区到引导扇的扇区数量乘0x02  0x0200前两零省略 等同左移1位 
 临时用FAT1HL保存引导扇区地址
		FAT1L = SRAM[0x01c6 + 200] << 1;
  

///////////////////////提取簇大小、FAT表数量、FAT1地址、FAT2地址、数据区地址///////////

		TF_RD(0x00,FAT1H,FAT1L,200); //读出引导扇区

		cudx = SRAM[0x000d + 200];  //提取簇大小

		FATsl = SRAM[0x0010 + 200];  //提取FAT表数量


		FAT2L = SRAM[0x000f + 200] << 1;
		FAT2L |= SRAM[0x000e + 200] >> 7;	  //引导扇到FAT1的扇区数量乘0x02  0x0200前两零省略 等同左移1位  临时
用FAT2L、LL保存引导扇到FAT1的偏移量 
		FAT2LL = SRAM[0x000e + 200] << 1;


		jiafachuli_24BIT(0x00,FAT1H,FAT1L,0x00,FAT2L,FAT2LL);  //引导扇区地址 + 引导扇到FAT1的偏移量  得到FAT1地址
		FAT1H = bb;FAT1L = cc;


		DATAH = SRAM[0x0025 + 200] >> 7;
		DATAL = SRAM[0x0025 + 200] << 1;	  //FAT表扇区数量乘0x02	0x0200前两零省略 等同左移1位  临时用DATAH、L
、LL保存FAT表大小
		DATAL |= SRAM[0x0024 + 200] >> 7;	
		DATALL = SRAM[0x0024 + 200] << 1;

							  

		if(FATsl == 0x01)
		{
			 jiafachuli_24BIT(0x00,FAT1H,FAT1L,DATAH,DATAL,DATALL);	//FAT1地址 + FAT表大小  得到数据区地址
			 DATAH = aa;DATAL = bb;DATALL = cc;
			 
		}
		else
		{
		     jiafachuli_24BIT(0x00,FAT1H,FAT1L,DATAH,DATAL,DATALL);	//FAT1地址 + FAT表大小  得到FAT2地址
			 FAT2H = aa;FAT2L = bb;FAT2LL = cc;
			   
		     jiafachuli_24BIT(FAT2H,FAT2L,FAT2LL,DATAH,DATAL,DATALL);  //FAT2地址 + FAT表大小  得到数据区地址
			 DATAH = aa;DATAL = bb;DATALL = cc;
		}

	
}


void TF_cuhaozhuanshanqudizhi(cuhao3,cuhao2,cuhao1)	 //簇号转扇区地址  高8位簇省略~~~  你懂得。。。SPI 4G限制 4G除以512字
节 = 簇数量(0x800000)
{
        
		cuhao1 = cuhao1 - 2;		  //簇号减2

		if((cuhao1 & 0xff00) == 0xff00)
		{
		    cuhao1 = cuhao1 & 0x00ff;				  //借位处理

		    cuhao2--;
			if((cuhao2 & 0xff00) == 0xff00)
			{
				cuhao2 = cuhao2 & 0x00ff;

			    cuhao3--;
			}
		}
		
		k = 1;
		while(k != cudx + cudx)		   //....翻倍乘~~~~计算数据区起始地址到X簇的偏移
		{
		     cuhao1 = cuhao1 + cuhao1;		   //本值乘2
		     cuhao2 = cuhao2 + cuhao2;
	         cuhao3 = cuhao3 + cuhao3;

		     cuhao2 = cuhao2 + (cuhao1 >> 8);	   //进位处理
			 cuhao1 = cuhao1 & 0x00ff;
		     cuhao3 = cuhao3 + (cuhao2 >> 8);
			 cuhao2 = cuhao2 & 0x00ff;
			 k = k + k;
	    }
	

	    cuhao1 = cuhao1 + DATALL;	  //数据区起始地址到X簇的偏移 + 数据区起始地址  得到簇首扇区地址
		cuhao2 = cuhao2 + DATAL;
		cuhao3 = cuhao3 + DATAH;

		cuhao2 = cuhao2 + (cuhao1 >> 8);	  //进位处理
		sqdz3 = cuhao3 + (cuhao2 >> 8);

		sqdz2 = cuhao2;
		sqdz1 = cuhao1;

}


void FAT32_cuhao_culian(cuhao3,cuhao2,cuhao1) //给簇号读出簇链  数量为x
{

		 bencu3 = ~cuhao3;	//弄成不一样的才能进换扇

    	 x = 0;
	     while((cuhao3 != 0xff | cuhao2 != 0xff | cuhao1 != 0xff) & (x != 8))
		 {

              if(bencu3 == cuhao3 & bencu2 == cuhao2 & (bencu1 & 0x80) == (cuhao1 & 0x80))	  //下一簇和本簇在同一扇区?	
 (每扇区为0~127簇)
			  {
			      cuhao3 = SRAM[((cuhao1 << 2) & 0x01ff) + 202];	   
				  cuhao2 = SRAM[((cuhao1 << 2) & 0x01ff) + 201];   
				  cuhao1 = SRAM[((cuhao1 << 2) & 0x01ff) + 200];
			  }
			  else	  //不在同一扇区
			  {
			      bencu3 = cuhao3;bencu2 = cuhao2;bencu1 = cuhao1;  //下一簇号作为本簇
									 

				 /////////////////////////计算簇所在的扇区并读出扇区/////////////////////// (簇号乘4字节(左移
2位) 低9位掩去 即为簇所在扇区偏移   低9位为扇区内字节偏移)

				  jiafachuli_24BIT(cuhao3 >> 6,((cuhao3 << 2) | (cuhao2 >> 6)) & 0x00ff,((cuhao2 << 2) | 
(cuhao1 >> 6)) & 0x00fe,0x00,FAT1H,FAT1L);  //簇所在扇区偏移 + FAT1地址 得到簇所在扇区

				  TF_RD(aa,bb,cc,200);

				 //////////////////////////把簇值读出来 记为下一簇////////////////////////////(簇号乘4字节(左
移2位) 低9位即为簇值第1字节指针

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

////////////////////////////////////////////////先查询第一个
簇////////////////////////////////////////////////////////////////////

							wjbz = 0; //文件标志清0

							
							TF_cuhaozhuanshanqudizhi(cuhao3,cuhao2,cuhao1);  //把簇的首扇区地址指
针读出来
							
						    y = 0;
							while(y != cudx & wjbz == 0)	//没处理完1个簇就继续搞
							{
									
									TF_RD(sqdz3,sqdz2,sqdz1,200); //把簇首扇读出来
									
									k = 200;
									while(k != 712 & wjbz == 0)
									{
										 
									     if(SRAM[k] != 0xe5 & SRAM[k] != 0xe2 & SRAM[k + 
0x0b] == mlwj)
										 {
										     if(SRAM[k] == wjm1 & SRAM[k + 1] == wjm2 
& SRAM[k + 2] == wjm3 & SRAM[k + 3] == wjm4 & SRAM[k + 4] == wjm5 & SRAM[k + 5] == wjm6 & SRAM[k + 6] == wjm7 & SRAM[k + 7] 
== wjm8 & SRAM[k + 8] == hzm1 & SRAM[k + 9] == hzm2 & SRAM[k + 10] == hzm3)	//文件名和后缀名一样?
											 {
											      wjcuhao3 = SRAM[k + 0x14];	
//保存文件起始簇号
												  wjcuhao2 = SRAM[k + 0x1b];
												  wjcuhao1 = SRAM[k + 0x1a];

												  wjdx4 = SRAM[k + 0x1f];	
  //保存文件大小
												  wjdx3 = SRAM[k + 0x1e];
												  wjdx2 = SRAM[k + 0x1d];
												  wjdx1 = SRAM[k + 0x1c];

												  wjbz = 1;	 //找到文件
												  
											 }
										 }

									     k = k + 32;
									}

									jiafachuli_24BIT(sqdz3,sqdz2,sqdz1,0x00,0x00,0x02);	
//簇首扇加1个扇区
									sqdz3 = aa;sqdz2 = bb;sqdz1 = cc;

							        y++;

							}

			 				

////////////////////////////////////////////////第1个簇没找到文件就查剩下的
簇////////////////////////////////////////////////////////////////////////


			 x = 8;  //条件弄成真了就进去
	         while(x == 8 & wjbz == 0)	  //处理完8个簇进入读出下8个簇  没处理完8个簇说明有ff ff ff 跳出
			 {
					
			        FAT32_cuhao_culian(cuhao3,cuhao2,cuhao1);	//读出下8个簇

				    cuhao3 = culian[0];	  //簇寄存 = 第1个簇
				    cuhao2 = culian[1];
				    cuhao1 = culian[2];
					
					x = 0;
					while((x != 8) & (cuhao3 != 0xff | cuhao2 != 0xff | cuhao1 != 0xff) & wjbz == 0)  //
没处理完8个簇 & 簇不为最后一个 继续搞...
					{

					        TF_cuhaozhuanshanqudizhi(cuhao3,cuhao2,cuhao1);  //把簇的首扇区地址指针读出来
							
						    y = 0;
							while(y != cudx & wjbz == 0)	//没处理完1个簇就继续搞
							{
								
									TF_RD(sqdz3,sqdz2,sqdz1,200); //把簇首扇读出来

									k = 200;
									while(k != 712 & wjbz == 0)
									{
										 
									     if(SRAM[k] != 0xe5 & SRAM[k] != 0xe2 & SRAM[k + 
0x0b] == mlwj)
										 {	 
										     if(SRAM[k] == wjm1 & SRAM[k + 1] == wjm2 
& SRAM[k + 2] == wjm3 & SRAM[k + 3] == wjm4 & SRAM[k + 4] == wjm5 & SRAM[k + 5] == wjm6 & SRAM[k + 6] == wjm7 & SRAM[k + 7] 
== wjm8 & SRAM[k + 8] == hzm1 & SRAM[k + 9] == hzm2 & SRAM[k + 10] == hzm3)	//文件名和后缀名一样?
											 {
											      wjcuhao3 = SRAM[k + 0x14];	
//保存文件起始簇号
												  wjcuhao2 = SRAM[k + 0x1b];
												  wjcuhao1 = SRAM[k + 0x1a];

												  wjdx4 = SRAM[k + 0x1f];	
  //保存文件大小
												  wjdx3 = SRAM[k + 0x1e];
												  wjdx2 = SRAM[k + 0x1d];
												  wjdx1 = SRAM[k + 0x1c];

												  wjbz = 1;	 //找到文件
												  
											 }
										 }

									     k = k + 32;
									}
									
									jiafachuli_24BIT(sqdz3,sqdz2,sqdz1,0x00,0x00,0x02);	
//簇首扇加1个扇区
									sqdz3 = aa;sqdz2 = bb;sqdz1 = cc;

							        y++;

							}


						    x++;

						    if(x != 8)	 //处理完8个簇就不进入  保持簇寄存为第8个
						    {
						       cuhao3 = culian[x + x + x];		 //把8个簇中的第x簇读出到簇寄
存
				               cuhao2 = culian[x + x + x + 1];
				               cuhao1 = culian[x + x + x + 2];
						    }

					}
				 

			 }


}