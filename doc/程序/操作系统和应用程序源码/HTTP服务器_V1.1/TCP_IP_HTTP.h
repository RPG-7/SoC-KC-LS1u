void ARPyingda()
{

//////////////////////源MAC地址送到目的MAC地址///////////////////////
                
				SRAM[0x0000] = SRAM[0x0006];	
				SRAM[0x0001] = SRAM[0x0007]; 
				SRAM[0x0002] = SRAM[0x0008]; 
				SRAM[0x0003] = SRAM[0x0009]; 
				SRAM[0x0004] = SRAM[0x000a]; 
				SRAM[0x0005] = SRAM[0x000b];

/////////////////////////填源MAC地址/////////////////////////////////

				SRAM[0x0006] = MAC5;
				SRAM[0x0007] = MAC4;
				SRAM[0x0008] = MAC3;
				SRAM[0x0009] = MAC2;
				SRAM[0x000a] = MAC1;
				SRAM[0x000b] = MAC0;

//////////////////////////填0x0002 为ARP应答/////////////////////////

				SRAM[0x0014] = 0x00;
				SRAM[0x0015] = 0x02;

//////////////////////////填请求方MAC////////////////////////////////
	
				SRAM[0x0020] = SRAM[0x0016];	
				SRAM[0x0021] = SRAM[0x0017]; 
				SRAM[0x0022] = SRAM[0x0018]; 
				SRAM[0x0023] = SRAM[0x0019]; 
				SRAM[0x0024] = SRAM[0x001a]; 
				SRAM[0x0025] = SRAM[0x001b];

//////////////////////////填请求方IP/////////////////////////////////

				SRAM[0x0026] = SRAM[0x001c]; 
				SRAM[0x0027] = SRAM[0x001d]; 
				SRAM[0x0028] = SRAM[0x001e]; 
				SRAM[0x0029] = SRAM[0x001f];

//////////////////////////填应答方MAC///////////////////////////////

				SRAM[0x0016] = MAC5;	
				SRAM[0x0017] = MAC4; 
				SRAM[0x0018] = MAC3; 
				SRAM[0x0019] = MAC2; 
				SRAM[0x001a] = MAC1; 
				SRAM[0x001b] = MAC0;

//////////////////////////填应答方IP///////////////////////////////
				
				SRAM[0x001c] = IP3; 
				SRAM[0x001d] = IP2; 
				SRAM[0x001e] = IP1; 
				SRAM[0x001f] = IP0;
////////////////////////写入数据包//////////////////////////////

                        xierushujubao(0x002a);
				
////////////////////////////发送///////////////////////////////

  ENC28J60_BFS(0x1f,0x08);  //ECON1.TXRTS位置1  启动发送

++TX_X;
}




void ICMPyingda()	//收到ICMP 请求数据包后 调用即修改SRAM内容为应答数据包
{

////////////////////源MAC地址送到目的MAC地址/////////////////////

            SRAM[0x0000] = SRAM[0x0006];	
		    SRAM[0x0001] = SRAM[0x0007]; 
		    SRAM[0x0002] = SRAM[0x0008]; 
			SRAM[0x0003] = SRAM[0x0009]; 
			SRAM[0x0004] = SRAM[0x000a]; 
			SRAM[0x0005] = SRAM[0x000b];

/////////////////////////填源MAC地址/////////////////////////////

			SRAM[0x0006] = MAC5;
			SRAM[0x0007] = MAC4;
			SRAM[0x0008] = MAC3;
			SRAM[0x0009] = MAC2;
			SRAM[0x000a] = MAC1;
			SRAM[0x000b] = MAC0;
		
////////////////////////填IP标识字段/////////////////////////////

		        ++IPj;
			SRAM[0x0012] = IPj >> 8;
			SRAM[0x0013] = IPj;

/////////////////////////填IP TTL///////////////////////////////

			SRAM[0x0016] = 98;

//////////////////////源IP地址送到目的IP地址/////////////////////

			SRAM[0x001e] = SRAM[0x001a];
			SRAM[0x001f] = SRAM[0x001b];
			SRAM[0x0020] = SRAM[0x001c];
			SRAM[0x0021] = SRAM[0x001d];

////////////////////////填源IP地址//////////////////////////////	    	

			SRAM[0x001a] = IP3;
			SRAM[0x001b] = IP2;
			SRAM[0x001c] = IP1;
			SRAM[0x001d] = IP0;

////////////////////////填0x00 为响应应答///////////////////////
			
			SRAM[0x0022] = 0x00;

////////////////////////IP校验和清0/////////////////////////////   
			
			SRAM[0x0018] = 0x00;
			SRAM[0x0019] = 0x00;

////////////////////////ICMP校验和清0///////////////////////////

			SRAM[0x0024] = 0x00;
			SRAM[0x0025] = 0x00;

////////////////////////写入数据包//////////////////////////////

                        xierushujubao(jjh);

////////////////////////计算IP校验和//////////////////////////// ip效验和位置0x0018~0x0019

                        ENC28J60_jisuanxiaoyanhe(0x000f,0x0022,0x0019); //ENC28J60发送缓冲区首字节为0x00 所以位置要+1

////////////////////////计算ICMP校验和////////////////////////// icmp效验和位置0x0024~0x0025

                        ENC28J60_jisuanxiaoyanhe(0x0023,jjh,0x0025); //ENC28J60发送缓冲区首字节为0x00 所以位置要+1

///////////////////////发送///////////////////////////////

  ENC28J60_BFS(0x1f,0x08);  //ECON1.TXRTS位置1  启动发送
++TX_X;		     
}




void jiafachuli_32BIT(A,B,C,D,K)  //加法处理 32BIT + 16BIT
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
bz,ckdx,DATAdx)	//给目的MAC、IP、端口、序号、确认号、TCP头部长度、标志、窗口大小、TCP 20字节后数据大小 调用即发送TCP包
{

///////////////////////填目的MAC///////////////////////////

	      		SRAM[0x0000] = D_MAC5;
				SRAM[0x0001] = D_MAC4;
				SRAM[0x0002] = D_MAC3;
				SRAM[0x0003] = D_MAC2;
				SRAM[0x0004] = D_MAC1;
				SRAM[0x0005] = D_MAC0;

///////////////////////填源MAC(本机)////////////////////////

				SRAM[0x0006] = MAC5;
				SRAM[0x0007] = MAC4;
				SRAM[0x0008] = MAC3;
				SRAM[0x0009] = MAC2;
				SRAM[0x000a] = MAC1;
				SRAM[0x000b] = MAC0;

//////////////////////填帧类型0x0800/////////////////////////

				SRAM[0x000c] = 0x08;
				SRAM[0x000d] = 0x00;

///////////////////////填IP版本和头部长度///////////////////

				SRAM[0x000e] = 0x45;

///////////////////////服务类型0x00/////////////////////////

				SRAM[0x000f] = 0x00;

/////////////////////////填IP包长度////////////////////////

				SRAM[0x0010] = 40 + DATAdx >> 8;
				SRAM[0x0011] = 40 + DATAdx;

////////////////////////填IP标识///////////////////////////

			    ++IPj;
			    SRAM[0x0012] = IPj >> 8;	  
			    SRAM[0x0013] = IPj;

/////////////////////////填IP分段(一般为0x4000)///////////

			    SRAM[0x0014] = 0x40;	  
			    SRAM[0x0015] = 0x00;

//////////////////////////填TTL////////////////////////////

				SRAM[0x0016] = 0x40;

//////////////////////////填协议(0x06 TCP)/////////////////

				SRAM[0x0017] = 0x06;

///////////////////////////填源IP//////////////////////////

				SRAM[0x001a] = IP3;
				SRAM[0x001b] = IP2;
				SRAM[0x001c] = IP1;
				SRAM[0x001d] = IP0;

////////////////////////////填目的IP////////////////////////

				SRAM[0x001e] = D_IP3;
				SRAM[0x001f] = D_IP2;
				SRAM[0x0020] = D_IP1;
				SRAM[0x0021] = D_IP0;

///////////////////////////填源端口////////////////////////
				
				SRAM[0x0022] = HTTPdk >> 8;
				SRAM[0x0023] = HTTPdk;

////////////////////////填目的端口////////////////////////

				SRAM[0x0024] = D_DK1;
				SRAM[0x0025] = D_DK0;

/////////////////////////填序号///////////////////////////

				SRAM[0x0026] = xh3;
				SRAM[0x0027] = xh2;
				SRAM[0x0028] = xh1;
				SRAM[0x0029] = xh0;

/////////////////////////填确认号///////////////////////////

				SRAM[0x002a] = qrh3;
				SRAM[0x002b] = qrh2;
				SRAM[0x002c] = qrh1;
				SRAM[0x002d] = qrh0;

//////////////////////////填TCP头部长度///////////////////

				SRAM[0x002e] = tcptbcd;

//////////////////////////填TCP标志///////////////////

				SRAM[0x002f] = bz;

//////////////////////////填TCP窗口大小///////////////////

				SRAM[0x0030] = ckdx >> 8;
				SRAM[0x0031] = ckdx;

//////////////////////////IP效验和清0/////////////////////

				SRAM[0x0018] = 0x00;
				SRAM[0x0019] = 0x00;

/////////////填虚IP头(IP的协议字段值+IP长度+负载数据字节)////////////////

			    SRAM[0x0032] = DATAdx + 26 >> 8;    
			    SRAM[0x0033] = DATAdx + 26;

////////////////////////写入数据包//////////////////////////////

                        xierushujubao(DATAdx += 54);

////////////////////////计算IP校验和//////////////////////////// ip效验和位置0x0018~0x0019

                        ENC28J60_jisuanxiaoyanhe(0x000f,0x0022,0x0019); //ENC28J60发送缓冲区首字节为0x00 所以位置要+1

////////////////////////计算TCP校验和/////////////////////////// TCP效验和位置0x0032~0x0033 (TCP校验和要加入 源/目的IP、IP的协议字段、TCP长度)

                        ENC28J60_jisuanxiaoyanhe(0x001b,DATAdx,0x0033); //ENC28J60发送缓冲区首字节为0x00 所以位置要+1

///////////////////////发送///////////////////////////////

  ENC28J60_BFS(0x1f,0x08);  //ECON1.TXRTS位置1  启动发送
++TX_X;

}


void TCP_fasong1(char D_MAC5,char D_MAC4,char D_MAC3,char D_MAC2,char D_MAC1,char D_MAC0,char D_IP3,char D_IP2,char D_IP1,char 
D_IP0,char D_DK1,char D_DK0,char xh3,char xh2,char xh1,char xh0,char qrh3,char qrh2,char qrh1,char qrh0,char tcptbcd,char 
bz,ckdx,DATAdx)	//给目的MAC、IP、端口、序号、确认号、TCP头部长度、标志、窗口大小、TCP 20字节后数据大小 调用即发送TCP包
{

///////////////////////填目的MAC///////////////////////////

	      		SRAM[0x0000] = D_MAC5;
				SRAM[0x0001] = D_MAC4;
				SRAM[0x0002] = D_MAC3;
				SRAM[0x0003] = D_MAC2;
				SRAM[0x0004] = D_MAC1;
				SRAM[0x0005] = D_MAC0;

///////////////////////填源MAC(本机)////////////////////////

				SRAM[0x0006] = MAC5;
				SRAM[0x0007] = MAC4;
				SRAM[0x0008] = MAC3;
				SRAM[0x0009] = MAC2;
				SRAM[0x000a] = MAC1;
				SRAM[0x000b] = MAC0;

//////////////////////填帧类型0x0800/////////////////////////

				SRAM[0x000c] = 0x08;
				SRAM[0x000d] = 0x00;

///////////////////////填IP版本和头部长度///////////////////

				SRAM[0x000e] = 0x45;

///////////////////////服务类型0x00/////////////////////////

				SRAM[0x000f] = 0x00;

/////////////////////////填IP包长度////////////////////////

				SRAM[0x0010] = 40 + DATAdx >> 8;
				SRAM[0x0011] = 40 + DATAdx;

////////////////////////填IP标识///////////////////////////

			    ++IPj;
			    SRAM[0x0012] = IPj >> 8;	  
			    SRAM[0x0013] = IPj;

/////////////////////////填IP分段(一般为0x4000)///////////

			    SRAM[0x0014] = 0x40;	  
			    SRAM[0x0015] = 0x00;

//////////////////////////填TTL////////////////////////////

				SRAM[0x0016] = 0x40;

//////////////////////////填协议(0x06 TCP)/////////////////

				SRAM[0x0017] = 0x06;

///////////////////////////填源IP//////////////////////////

				SRAM[0x001a] = IP3;
				SRAM[0x001b] = IP2;
				SRAM[0x001c] = IP1;
				SRAM[0x001d] = IP0;

////////////////////////////填目的IP////////////////////////

				SRAM[0x001e] = D_IP3;
				SRAM[0x001f] = D_IP2;
				SRAM[0x0020] = D_IP1;
				SRAM[0x0021] = D_IP0;

///////////////////////////填源端口////////////////////////
				
				SRAM[0x0022] = HTTPdk >> 8;
				SRAM[0x0023] = HTTPdk;

////////////////////////填目的端口////////////////////////

				SRAM[0x0024] = D_DK1;
				SRAM[0x0025] = D_DK0;

/////////////////////////填序号///////////////////////////

				SRAM[0x0026] = xh3;
				SRAM[0x0027] = xh2;
				SRAM[0x0028] = xh1;
				SRAM[0x0029] = xh0;

/////////////////////////填确认号///////////////////////////

				SRAM[0x002a] = qrh3;
				SRAM[0x002b] = qrh2;
				SRAM[0x002c] = qrh1;
				SRAM[0x002d] = qrh0;

//////////////////////////填TCP头部长度///////////////////

				SRAM[0x002e] = tcptbcd;

//////////////////////////填TCP标志///////////////////

				SRAM[0x002f] = bz;

//////////////////////////填TCP窗口大小///////////////////

				SRAM[0x0030] = ckdx >> 8;
				SRAM[0x0031] = ckdx;

//////////////////////////IP效验和清0/////////////////////

				SRAM[0x0018] = 0x00;
				SRAM[0x0019] = 0x00;

/////////////填虚IP头(IP的协议字段值+IP长度+负载数据字节)////////////////

			    SRAM[0x0032] = DATAdx + 26 >> 8;    
			    SRAM[0x0033] = DATAdx + 26;

////////////////////////写入数据包///////////////////////////////////////

                        xierushujubao(54);

////////////////////////发送缓冲器尾指针指向最后1个字节///////////////////

  DATAdx += 54;
  ENC28J60_WCR(0x06,DATAdx);  //ETXNDL	发送缓冲器尾指针指向最后1个字节
  ENC28J60_WCR(0x07,DATAdx >> 8);      //ETXNDH

////////////////////////计算IP校验和//////////////////////////// ip效验和位置0x0018~0x0019

                        ENC28J60_jisuanxiaoyanhe(0x000f,0x0022,0x0019); //ENC28J60发送缓冲区首字节为0x00 所以位置要+1

////////////////////////计算TCP校验和/////////////////////////// TCP效验和位置0x0032~0x0033 (TCP校验和要加入 源/目的IP、IP的协议字段、TCP长度)

                        ENC28J60_jisuanxiaoyanhe(0x001b,DATAdx,0x0033); //ENC28J60发送缓冲区首字节为0x00 所以位置要+1

///////////////////////发送///////////////////////////////

  //while(ENC28J60_RCR(0x1f),(SPI_D & 0x08) != 0);

  ENC28J60_BFS(0x1f,0x08);  //ECON1.TXRTS位置1  启动发送
++TX_X;

}







void GET_lujingchuli()	//GET路径处理  路径分析处理 读出文件簇号和大小
{

		 wjm[0] = 0x20;		 //文件名清20
		 wjm[1] = 0x20;
		 wjm[2] = 0x20;
		 wjm[3] = 0x20;
		 wjm[4] = 0x20;
		 wjm[5] = 0x20;
		 wjm[6] = 0x20;
		 wjm[7] = 0x20;

		 hzm[0] = 0x20;		 //后缀名清20
		 hzm[1] = 0x20;
		 hzm[2] = 0x20;


		 mlcuhao3 = 0x00;	 //首目录簇号
		 mlcuhao2 = 0x00;
		 mlcuhao1 = 0x02;

		 qh = 0;  //打开文件名输入

		 zz = 0x003a;  //输入基址  HTTP请求行第1个0x2f(/)的地址

		 xj = 0;yj = 9;	//清0进入  设定文件名长度门限


         while(xj != 0xff)
		 {

			   xj++;

			   zzbc = SRAM[zz + xj];

		       if(zzbc == 0x2f)	  //读到"/"进入目录处理
			   {
			        TF_wenjianchaxun1(mlcuhao3,mlcuhao2,mlcuhao1,wjm[0],wjm[1],wjm[2],wjm[3],wjm[4],wjm[5],wjm
[6],wjm[7],hzm[0],hzm[1],hzm[2],0x10);  //查找目录

					if(wjbz == 1)
					{
						wjm[0] = 0x20;		 //文件名清20
		                wjm[1] = 0x20;
		                wjm[2] = 0x20;
		                wjm[3] = 0x20;
		                wjm[4] = 0x20;
		                wjm[5] = 0x20;
		                wjm[6] = 0x20;
		                wjm[7] = 0x20;

		                hzm[0] = 0x20;		 //后缀名清20
		                hzm[1] = 0x20;
		                hzm[2] = 0x20;

					    mlcuhao3 = wjcuhao3;   //更新为新目录簇号
						mlcuhao2 = wjcuhao2;
					    mlcuhao1 = wjcuhao1;

						qh = 0;	 //新的查询 打开文件名输入 

						zz = zz + xj;  //更新基址为新的0x2f地址

                        xj = 0;yj = 9;	//清0  设定文件名长度门限
						
					}
					else   //找不到目录进入处理
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

					    xj = 0xff; //主循环跳出
					}
			   }
			   else
			   {
			       if(zzbc == 0x2e)	  //读到"."进入切换到后缀名输入
				   {
						 
				         if(qh == 0)
						 {
						     zz = zz + xj;  //更新基址为0x2e地址
							 
							 qh = 1; //切换为后缀名输入

							 xj = 0;yj = 4;	 //清0  设定后缀名长度门限

						 }
						 else  //文件名出现第2个"."  进入处理
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
				       if(zzbc == 0x20 | zzbc == 0x3f)	//读到" "或"?"进入文件处理
					   {


					         TF_wenjianchaxun1(mlcuhao3,mlcuhao2,mlcuhao1,wjm[0],wjm[1],wjm[2],wjm
[3],wjm[4],wjm[5],wjm[6],wjm[7],hzm[0],hzm[1],hzm[2],0x20);  //查找文件
							 
							 if(wjbz == 0)  //没找到文件进入处理
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

							 if(zzbc == 0x3f) //为"?" 进入处理"?"后的参数
							 {


                                                                sys_in_boot_0(); //返回操作系统


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
					        if(xj != yj)  //长度没超限 进入输入文件名或后缀名
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
										zzbc = zzbc - 0x20;	 //减0x20后变为A~Z

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
							else  //长度超限 进入处理
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


void shijinzhizhuanhuan_32BIT(char a,char b,char c,char d) //给32位数  调用即输出10进制到sjz(10位10进制) (左移加3判7法) 
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



void HTTP_toubu()//填HTTP头部
{


             zzj = 0x36;  //起始位置

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
								 else  //填字节流
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
0x47 & hzm[1] == 0x49 & hzm[2] == 0x46) | (hzm[0] == 0x53 & hzm[1] == 0x57 & hzm[2] == 0x46))  //直接打开的就不用填"附件"
			 {
			 }
			 else //否则填"附件"
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

			 
			 if(wjm[0] != 0x20)	                           //文件名
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


			 if(hzm[0] != 0x20)	                               //后缀名
			 {
				 SRAM[zzj] = 0x2e;zzj++;  //有后缀名就填"."

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


void TCP_Cqingling() //TCP控制块清0
{
  k = 0;
  while(k != (TCP_IIS*52))
  {
    TCP_C[k++] = 0x00;
  }
}



void TCP_chongfashuju2()	//重发数据 对于每个簇1个扇区以上 函数
{

			 TF_cuhaozhuanshanqudizhi(TCP_C[TCPjzz + 0x1c + TCP_C[TCPjzz + 0x1b]],TCP_C[TCPjzz + 0x1d + TCP_C
[TCPjzz + 0x1b]],TCP_C[TCPjzz + 0x1e + TCP_C[TCPjzz + 0x1b]]); //簇指针指向的簇号读出簇首扇地址


	         jiafachuli_24BIT(sqdz3,sqdz2,sqdz1,0x00,0x00,TCP_C[TCPjzz + 0x1a] - 4);	//簇首扇加扇偏移 偏移为扇区指
针乘0x02 前两0省略 减4后为上上个扇区偏移

			 TF_RD_ENC28J60(aa,bb,cc);  //读出上上个扇区

			 jiafachuli_32BIT((~TCP_C[TCPjzz + 0x11]) & 0x00ff,(~TCP_C[TCPjzz + 0x12]) & 0x00ff,(~TCP_C[TCPjzz + 
0x13]) & 0x00ff,(~TCP_C[TCPjzz + 0x14]) & 0x00ff,0x0400); //减0x0400后得出上上个包的序号

			 TCP_fasong1(TCP_C[TCPjzz + 0x01],TCP_C[TCPjzz + 0x02],TCP_C[TCPjzz + 0x03],TCP_C[TCPjzz + 
0x04],TCP_C[TCPjzz + 0x05],TCP_C[TCPjzz + 0x06],TCP_C[TCPjzz + 0x07],TCP_C[TCPjzz + 0x08],TCP_C[TCPjzz + 0x09],TCP_C[TCPjzz + 
0x0a],TCP_C[TCPjzz + 0x0b],TCP_C[TCPjzz + 0x0c],~aaa,~bbb,~ccc,~ddd,TCP_C[TCPjzz + 0x0d],TCP_C[TCPjzz + 0x0e],TCP_C[TCPjzz + 
0x0f],TCP_C[TCPjzz + 0x10],0x50,0x18,0x0400,0x0200); //发送上上个扇区  序号为上上个包的序号


			 jiafachuli_24BIT(sqdz3,sqdz2,sqdz1,0x00,0x00,TCP_C[TCPjzz + 0x1a] - 2);	//簇首扇加扇偏移 偏移
为扇区指针乘0x02 前两0省略 减2后为上个扇区偏移

			 TF_RD_ENC28J60(aa,bb,cc);  //读出上个扇区

			 jiafachuli_32BIT((~TCP_C[TCPjzz + 0x11]) & 0x00ff,(~TCP_C[TCPjzz + 0x12]) & 0x00ff,(~TCP_C[TCPjzz + 
0x13]) & 0x00ff,(~TCP_C[TCPjzz + 0x14]) & 0x00ff,0x0200); //减0x0200后得出上个包的序号

			 TCP_fasong1(TCP_C[TCPjzz + 0x01],TCP_C[TCPjzz + 0x02],TCP_C[TCPjzz + 0x03],TCP_C[TCPjzz + 
0x04],TCP_C[TCPjzz + 0x05],TCP_C[TCPjzz + 0x06],TCP_C[TCPjzz + 0x07],TCP_C[TCPjzz + 0x08],TCP_C[TCPjzz + 0x09],TCP_C[TCPjzz + 
0x0a],TCP_C[TCPjzz + 0x0b],TCP_C[TCPjzz + 0x0c],~aaa,~bbb,~ccc,~ddd,TCP_C[TCPjzz + 0x0d],TCP_C[TCPjzz + 0x0e],TCP_C[TCPjzz + 
0x0f],TCP_C[TCPjzz + 0x10],0x50,0x18,0x0400,0x0200); //发送上个扇区  序号为上个包的序号


}



void TCP_chongfashuju1()   //重发数据 对于每个簇1个扇区 函数
{

			 TF_cuhaozhuanshanqudizhi(TCP_C[TCPjzz + 0x1c + TCP_C[TCPjzz + 0x1b] - 3],TCP_C[TCPjzz + 0x1d + 
TCP_C[TCPjzz + 0x1b] - 3],TCP_C[TCPjzz + 0x1e + TCP_C[TCPjzz + 0x1b] - 3]); //读出上个簇首扇地址  减3为备忘标记 


			 TF_RD_ENC28J60(sqdz3,sqdz2,sqdz1);  //读出上个扇区

			 jiafachuli_32BIT((~TCP_C[TCPjzz + 0x11]) & 0x00ff,(~TCP_C[TCPjzz + 0x12]) & 0x00ff,(~TCP_C[TCPjzz + 
0x13]) & 0x00ff,(~TCP_C[TCPjzz + 0x14]) & 0x00ff,0x0200); //减0x0200后得出上个包的序号

			 TCP_fasong1(TCP_C[TCPjzz + 0x01],TCP_C[TCPjzz + 0x02],TCP_C[TCPjzz + 0x03],TCP_C[TCPjzz + 
0x04],TCP_C[TCPjzz + 0x05],TCP_C[TCPjzz + 0x06],TCP_C[TCPjzz + 0x07],TCP_C[TCPjzz + 0x08],TCP_C[TCPjzz + 0x09],TCP_C[TCPjzz + 
0x0a],TCP_C[TCPjzz + 0x0b],TCP_C[TCPjzz + 0x0c],~aaa,~bbb,~ccc,~ddd,TCP_C[TCPjzz + 0x0d],TCP_C[TCPjzz + 0x0e],TCP_C[TCPjzz + 
0x0f],TCP_C[TCPjzz + 0x10],0x50,0x18,0x0400,0x0200); //发送上个扇区  序号为上个包的序号


}



void TCP_dingshiqi()	 //TCP定时器	(定时重发和定时断开闲置连接)
{

		 TCPjzz = 0;  lj = 0;

		 while(TCPjzz != (TCP_IIS*52))
		 {
		      if((TCP_C[TCPjzz] & 0x80) == 0x80)  //表有效 进入
			  {
					lj++;

			       if((TCP_C[TCPjzz] & 0x20) == 0x20 | (TCP_C[TCPjzz] & 0x10) == 0x10) //打开定时器?
				   {

							 TCP_C[TCPjzz + 0x15]--;  //定时器减1
							  
							 if(TCP_C[TCPjzz + 0x15] == 0x00)	 //定时器为0进入
							 { 

								   Bank0();  //被这里害惨了...  外面出来时Bank1.....发不了
包..

							       if((TCP_C[TCPjzz] & 0x20) == 0x20)  //断连定时器
								   {
										  
										  TCP_fasong(TCP_C[TCPjzz + 0x01],TCP_C
[TCPjzz + 0x02],TCP_C[TCPjzz + 0x03],TCP_C[TCPjzz + 0x04],TCP_C[TCPjzz + 0x05],TCP_C[TCPjzz + 0x06],TCP_C[TCPjzz + 
0x07],TCP_C[TCPjzz + 0x08],TCP_C[TCPjzz + 0x09],TCP_C[TCPjzz + 0x0a],TCP_C[TCPjzz + 0x0b],TCP_C[TCPjzz + 0x0c],TCP_C[TCPjzz + 
0x11],TCP_C[TCPjzz + 0x12],TCP_C[TCPjzz + 0x13],TCP_C[TCPjzz + 0x14],TCP_C[TCPjzz + 0x0d],TCP_C[TCPjzz + 0x0e],TCP_C[TCPjzz + 
0x0f],TCP_C[TCPjzz + 0x10],0x50,0x11,0x0400,0x0000);	//断开连接 FIN = 1
										  
								          TCP_C[TCPjzz] = 0x00;  //此TCP块标志清0  释放

									      TCP_C[TCPjzz + 0x16] = 0x00;  //此TCP块文件剩余
字节大小清0
									      TCP_C[TCPjzz + 0x17] = 0x00;
									      TCP_C[TCPjzz + 0x18] = 0x00;
									      TCP_C[TCPjzz + 0x19] = 0x00;

								   }
								   else
								   {
										  if((TCP_C[TCPjzz] & 0x0f) != 0x0f)  //重发次数不为15次 进入重发
										  {
												TCP_C[TCPjzz]++; //重发次数加1

												TCP_C[TCPjzz + 0x15] = 2;  //定时器装数 2秒
					                            
											    if(cudx == 1)
											    {
													 TCP_chongfashuju1();
												}
												else
												{
													 TCP_chongfashuju2(); 
												}

										  }
										  else  //重发了15次不回当疯狗处理
										  {
												TCP_C[TCPjzz] = 0x00;  //此连接表标志清0  释放

									            TCP_C[TCPjzz + 0x16] = 0x00;  //此连接表文件剩余字节大小清0
									            TCP_C[TCPjzz + 0x17] = 0x00;
									            TCP_C[TCPjzz + 0x18] = 0x00;
									            TCP_C[TCPjzz + 0x19] = 0x00;

										  }

								   }
								    
							 }

						
				   }
			  }

			 TCPjzz = TCPjzz + 52; //指向下一个表
		 }
	     

}



void TCP_fasongshuju_2() //发送数据  对于每个簇1个扇区以上
{

	      if(SRAM[0x0030] > 4)	//窗口大于2个扇区?
		  {


			   if(TCP_C[TCPjzz + 0x1a] == cudx + cudx) //1个簇的扇区读完?
			   {
			          TCP_C[TCPjzz + 0x1b] = TCP_C[TCPjzz + 0x1b] + 3;	//簇指针指向下一个簇

					  if(TCP_C[TCPjzz + 0x1b] == 24)  //8个簇读完?
					  {
							 FAT32_cuhao_culian(TCP_C[TCPjzz + 0x31],TCP_C[TCPjzz + 0x32],TCP_C
[TCPjzz + 0x33]);  //读出下8个簇号

					         TCP_C[TCPjzz + 0x1c] = culian[0];	 //保存首簇号到此TCP块
							 TCP_C[TCPjzz + 0x1d] = culian[1];
							 TCP_C[TCPjzz + 0x1e] = culian[2];

							 TCP_C[TCPjzz + 0x1f] = culian[3];  //保存下7个簇号到此TCP块
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

							 TCP_C[TCPjzz + 0x1b] = 0;	 //簇指针清0
					  }


					TCP_C[TCPjzz + 0x1a] = 0; //扇区指针清0  指向簇首扇

			   }


			   TF_cuhaozhuanshanqudizhi(TCP_C[TCPjzz + 0x1c + TCP_C[TCPjzz + 0x1b]],TCP_C[TCPjzz + 0x1d + TCP_C
[TCPjzz + 0x1b]],TCP_C[TCPjzz + 0x1e + TCP_C[TCPjzz + 0x1b]]); //簇指针指向的簇号读出簇首扇地址




			   jiafachuli_24BIT(sqdz3,sqdz2,sqdz1,0x00,0x00,TCP_C[TCPjzz + 0x1a]); //簇首扇加扇偏移 偏移为扇区指
针乘0x02 前两0省略

			   TF_RD_ENC28J60(aa,bb,cc);	//读出1扇数据  地址为簇首扇加扇偏移的结果

			   TCP_C[TCPjzz + 0x1a] = TCP_C[TCPjzz + 0x1a] + 2; //扇区指针指向下1个扇区


			   if(TCP_C[TCPjzz + 0x16] == 0x00 & TCP_C[TCPjzz + 0x17] == 0x00 & TCP_C[TCPjzz + 0x18] < 2)  //文件
剩余字节小于1个扇区?
			   {
					 k = TCP_C[TCPjzz + 0x18];  //.....蛋疼~~~	 把文件剩余字节大小低16位转换为1个16
位变量
					 k = k << 8;
					 k |= TCP_C[TCPjzz + 0x19];

			       	 TCP_fasong1(TCP_C[TCPjzz + 0x01],TCP_C[TCPjzz + 0x02],TCP_C[TCPjzz + 0x03],TCP_C[TCPjzz + 
0x04],TCP_C[TCPjzz + 0x05],TCP_C[TCPjzz + 0x06],TCP_C[TCPjzz + 0x07],TCP_C[TCPjzz + 0x08],TCP_C[TCPjzz + 0x09],TCP_C[TCPjzz + 
0x0a],TCP_C[TCPjzz + 0x0b],TCP_C[TCPjzz + 0x0c],TCP_C[TCPjzz + 0x11],TCP_C[TCPjzz + 0x12],TCP_C[TCPjzz + 0x13],TCP_C[TCPjzz + 
0x14],TCP_C[TCPjzz + 0x0d],TCP_C[TCPjzz + 0x0e],TCP_C[TCPjzz + 0x0f],TCP_C[TCPjzz + 0x10],0x50,0x19,0x0400,k); //发送文件剩余
字节  FIN = 1 断开连接


					 TCP_C[TCPjzz] = 0x00;  //此TCP块标志清0  释放

					 TCP_C[TCPjzz + 0x16] = 0x00;  //此TCP块文件剩余字节大小清0
					 TCP_C[TCPjzz + 0x17] = 0x00;
					 TCP_C[TCPjzz + 0x18] = 0x00;
					 TCP_C[TCPjzz + 0x19] = 0x00;
					  
			   }
			   else
			   {
			         TCP_fasong1(TCP_C[TCPjzz + 0x01],TCP_C[TCPjzz + 0x02],TCP_C[TCPjzz + 0x03],TCP_C[TCPjzz + 
0x04],TCP_C[TCPjzz + 0x05],TCP_C[TCPjzz + 0x06],TCP_C[TCPjzz + 0x07],TCP_C[TCPjzz + 0x08],TCP_C[TCPjzz + 0x09],TCP_C[TCPjzz + 
0x0a],TCP_C[TCPjzz + 0x0b],TCP_C[TCPjzz + 0x0c],TCP_C[TCPjzz + 0x11],TCP_C[TCPjzz + 0x12],TCP_C[TCPjzz + 0x13],TCP_C[TCPjzz + 
0x14],TCP_C[TCPjzz + 0x0d],TCP_C[TCPjzz + 0x0e],TCP_C[TCPjzz + 0x0f],TCP_C[TCPjzz + 0x10],0x50,0x18,0x0400,0x0200); //发送1扇
			   
					 jiafachuli_32BIT(TCP_C[TCPjzz + 0x11],TCP_C[TCPjzz + 0x12],TCP_C[TCPjzz + 
0x13],TCP_C[TCPjzz + 0x14],0x0200);  //确认号加发送数据大小 1个扇区
									 
					 TCP_C[TCPjzz + 0x11] = aaa;   //加发送数据大小后的确认号存进此TCP块
					 TCP_C[TCPjzz + 0x12] = bbb;
					 TCP_C[TCPjzz + 0x13] = ccc;
					 TCP_C[TCPjzz + 0x14] = ddd;

					 jiafachuli_32BIT((~TCP_C[TCPjzz + 0x16]) & 0x00ff,(~TCP_C[TCPjzz + 0x17]) & 0x00ff,
(~TCP_C[TCPjzz + 0x18]) & 0x00ff,(~TCP_C[TCPjzz + 0x19]) & 0x00ff,0x0200); //文件剩余字节减1个扇区

					 TCP_C[TCPjzz + 0x16] = ~aaa;  //结果存回文件剩余字节
					 TCP_C[TCPjzz + 0x17] = ~bbb;
					 TCP_C[TCPjzz + 0x18] = ~ccc;
					 TCP_C[TCPjzz + 0x19] = ~ddd;


					 if((~aaa) != 0x00 | (~bbb) != 0x00 | (~ccc) != 0x00 | (~ddd) != 0x00) //文件剩余字节
大小不为0
					 {

						   jiafachuli_24BIT(sqdz3,sqdz2,sqdz1,0x00,0x00,TCP_C[TCPjzz + 0x1a]); //簇首
扇加扇偏移 偏移为扇区指针乘0x02 前两0省略

			               TF_RD_ENC28J60(aa,bb,cc);	//读出1扇数据  地址为簇首扇加扇偏移的结果

			               TCP_C[TCPjzz + 0x1a] = TCP_C[TCPjzz + 0x1a] + 2; //扇区指针指向下1个扇区


			               if(TCP_C[TCPjzz + 0x16] == 0x00 & TCP_C[TCPjzz + 0x17] == 0x00 & TCP_C[TCPjzz + 0x18] 
< 2)  //文件剩余字节小于1个扇区?
			               {
					             k = TCP_C[TCPjzz + 0x18];  //.....蛋疼~~~	 把文件剩余字节大小低16位转换
为1个16位变量
					             k = k << 8;
					             k |= TCP_C[TCPjzz + 0x19];

			       	             TCP_fasong1(TCP_C[TCPjzz + 0x01],TCP_C[TCPjzz + 0x02],TCP_C[TCPjzz + 0x03],TCP_C
[TCPjzz + 0x04],TCP_C[TCPjzz + 0x05],TCP_C[TCPjzz + 0x06],TCP_C[TCPjzz + 0x07],TCP_C[TCPjzz + 0x08],TCP_C[TCPjzz + 
0x09],TCP_C[TCPjzz + 0x0a],TCP_C[TCPjzz + 0x0b],TCP_C[TCPjzz + 0x0c],TCP_C[TCPjzz + 0x11],TCP_C[TCPjzz + 0x12],TCP_C[TCPjzz + 
0x13],TCP_C[TCPjzz + 0x14],TCP_C[TCPjzz + 0x0d],TCP_C[TCPjzz + 0x0e],TCP_C[TCPjzz + 0x0f],TCP_C[TCPjzz + 
0x10],0x50,0x19,0x0400,k); //发送文件剩余字节 FIN = 1

									 
					             TCP_C[TCPjzz] = 0x00;  //此TCP块标志清0  释放

					             TCP_C[TCPjzz + 0x16] = 0x00;  //此TCP块文件剩余字节大小清0
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
0x10],0x50,0x18,0x0400,0x0200);  //发送1扇
			   
					             jiafachuli_32BIT(TCP_C[TCPjzz + 0x11],TCP_C[TCPjzz + 0x12],TCP_C[TCPjzz 
+ 0x13],TCP_C[TCPjzz + 0x14],0x0200);  //确认号加发送数据大小
									 
					             TCP_C[TCPjzz + 0x11] = aaa;   //加发送数据大小后的确认号存进此TCP块
					             TCP_C[TCPjzz + 0x12] = bbb;
					             TCP_C[TCPjzz + 0x13] = ccc;
					             TCP_C[TCPjzz + 0x14] = ddd;

					             jiafachuli_32BIT((~TCP_C[TCPjzz + 0x16]) & 0x00ff,(~TCP_C[TCPjzz + 
0x17]) & 0x00ff,(~TCP_C[TCPjzz + 0x18]) & 0x00ff,(~TCP_C[TCPjzz + 0x19]) & 0x00ff,0x0200); //文件剩余字节减1个扇区

					             TCP_C[TCPjzz + 0x16] = ~aaa;  //结果存回文件剩余字节
					             TCP_C[TCPjzz + 0x17] = ~bbb;
					             TCP_C[TCPjzz + 0x18] = ~ccc;
					             TCP_C[TCPjzz + 0x19] = ~ddd;

					             TCP_C[TCPjzz + 0x15] = 2;  //定时器装数 2秒
					            
					             TCP_C[TCPjzz] = 0x90;	 //启动重发定时器

			               }


					 }
					 else
					 {
							TCP_C[TCPjzz + 0x15] = 2;  //定时器装数 2秒 最后1包个丢包机率低...中
途丢包的机率高  在这里 重发机制只照顾中途丢包
					        
					        TCP_C[TCPjzz] = 0xa0;	 //启动断连定时器

					 }

			   }
 
		  }
		  else
		  {
		         TCP_C[TCPjzz + 0x15] = 60;  //定时器装数 60秒
				 
				 TCP_C[TCPjzz] = 0xa0;	 //启动断连定时器 
		  }


}


void TCP_fasongshuju_1() // 发送数据  对于每个簇1个扇区
{

		  if(SRAM[0x0030] > 2)	//窗口大于1个扇区?
		  {

					  if(TCP_C[TCPjzz + 0x1b] == 24)  //8个簇读完?
					  {
							 FAT32_cuhao_culian(TCP_C[TCPjzz + 0x31],TCP_C[TCPjzz + 0x32],TCP_C
[TCPjzz + 0x33]);  //读出下8个簇号

					         TCP_C[TCPjzz + 0x1c] = culian[0];	 //保存首簇号到此TCP块
							 TCP_C[TCPjzz + 0x1d] = culian[1];
							 TCP_C[TCPjzz + 0x1e] = culian[2];

							 TCP_C[TCPjzz + 0x1f] = culian[3];  //保存下7个簇号到此TCP块
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

							 TCP_C[TCPjzz + 0x1b] = 0;	 //簇指针清0
					  }

			   TF_cuhaozhuanshanqudizhi(TCP_C[TCPjzz + 0x1c + TCP_C[TCPjzz + 0x1b]],TCP_C[TCPjzz + 0x1d + TCP_C
[TCPjzz + 0x1b]],TCP_C[TCPjzz + 0x1e + TCP_C[TCPjzz + 0x1b]]); //簇指针指向的簇号读出簇首扇地址



			   TF_RD_ENC28J60(sqdz3,sqdz2,sqdz1);	//读出1扇数据  地址为簇首扇

			   TCP_C[TCPjzz + 0x1b] = TCP_C[TCPjzz + 0x1b] + 3;	//簇指针指向下一个簇

			   if(TCP_C[TCPjzz + 0x16] == 0x00 & TCP_C[TCPjzz + 0x17] == 0x00 & TCP_C[TCPjzz + 0x18] < 2)  //文件
剩余字节小于1个扇区?
			   {
					 k = TCP_C[TCPjzz + 0x18];  //.....蛋疼~~~	 把文件剩余字节大小低16位转换为1个16
位变量
					 k = k << 8;
					 k |= TCP_C[TCPjzz + 0x19];

			       	 TCP_fasong1(TCP_C[TCPjzz + 0x01],TCP_C[TCPjzz + 0x02],TCP_C[TCPjzz + 0x03],TCP_C[TCPjzz + 
0x04],TCP_C[TCPjzz + 0x05],TCP_C[TCPjzz + 0x06],TCP_C[TCPjzz + 0x07],TCP_C[TCPjzz + 0x08],TCP_C[TCPjzz + 0x09],TCP_C[TCPjzz + 
0x0a],TCP_C[TCPjzz + 0x0b],TCP_C[TCPjzz + 0x0c],TCP_C[TCPjzz + 0x11],TCP_C[TCPjzz + 0x12],TCP_C[TCPjzz + 0x13],TCP_C[TCPjzz + 
0x14],TCP_C[TCPjzz + 0x0d],TCP_C[TCPjzz + 0x0e],TCP_C[TCPjzz + 0x0f],TCP_C[TCPjzz + 0x10],0x50,0x19,0x0400,k); //发送文件剩余
字节  FIN = 1


					 TCP_C[TCPjzz] = 0x00;  //此TCP块标志清0  释放

					 TCP_C[TCPjzz + 0x16] = 0x00;  //此TCP块文件剩余字节大小清0
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
0x13],TCP_C[TCPjzz + 0x14],0x0200);  //确认号加发送数据大小
									 
					 TCP_C[TCPjzz + 0x11] = aaa;   //加发送数据大小后的确认号存进此TCP块
					 TCP_C[TCPjzz + 0x12] = bbb;
					 TCP_C[TCPjzz + 0x13] = ccc;
					 TCP_C[TCPjzz + 0x14] = ddd;

					 jiafachuli_32BIT((~TCP_C[TCPjzz + 0x16]) & 0x00ff,(~TCP_C[TCPjzz + 0x17]) & 0x00ff,
(~TCP_C[TCPjzz + 0x18]) & 0x00ff,(~TCP_C[TCPjzz + 0x19]) & 0x00ff,0x0200); //文件剩余字节减1个扇区

					 TCP_C[TCPjzz + 0x16] = ~aaa;  //结果存回文件剩余字节
					 TCP_C[TCPjzz + 0x17] = ~bbb;
					 TCP_C[TCPjzz + 0x18] = ~ccc;
					 TCP_C[TCPjzz + 0x19] = ~ddd;

					 TCP_C[TCPjzz + 0x15] = 2;  //定时器装数  2秒
					 
					 TCP_C[TCPjzz] = 0x90;	 //启动重发定时器

			   }
   
		  }
		  else
		  {
		         TCP_C[TCPjzz + 0x15] = 60;  //定时器装数 60秒
				 
				 TCP_C[TCPjzz] = 0xa0;	 //启动断连定时器
				  
		  }

}



void TCPchuli() //TCP处理
{


          if(SRAM[0x0024] == (HTTPdk >> 8) & SRAM[0x0025] == (HTTPdk & 0x00ff)) //  目标端口正确
		  {

          //////////////////扫描TCP块查看是否有一样的连接////////////////

				TCPkbz = 0;  //块标志清0

			    TCPjzz = 0;  //基指针清0

				while(TCPjzz != (TCP_IIS*52) & TCPkbz == 0)
			    {
					 if((TCP_C[TCPjzz] & 0x80) == 0x80)  //块有效 进入对比
					 { 
						  if(TCP_C[TCPjzz + 0x07] == SRAM[0x001a] & TCP_C[TCPjzz + 0x08] == SRAM
[0x001b] & TCP_C[TCPjzz + 0x09] == SRAM[0x001c] & TCP_C[TCPjzz + 0x0a] == SRAM[0x001d] & TCP_C[TCPjzz + 0x0b] == SRAM[0x0022] 
& TCP_C[TCPjzz + 0x0c] == SRAM[0x0023]) //收到的包源IP和源端口与TCP块一样?
						  {
							  TCPkbz = 1;
						  }
					 }
												  
					TCPjzz = TCPjzz + 52; //指向下一个TCP块
					
			    }

				
		  ///////////////////////////TCP标志判断处理//////////////////////////

				if(TCPkbz == 0)	//没有一样的连接
				{
				     if(SRAM[0x002f] == 0x02)   //SYN = 1 发起连接
					 {
					      TCPjzz = 0;  //基指针清0

						  while(TCPjzz != (TCP_IIS*52))
						  {
						       if(TCP_C[TCPjzz] == 0x00)  //是闲置TCP块? (连接空间)
							   {


							         TCP_C[TCPjzz + 0x01] = SRAM[0x0006];	//保存源MAC到此TCP块
									 TCP_C[TCPjzz + 0x02] = SRAM[0x0007];
									 TCP_C[TCPjzz + 0x03] = SRAM[0x0008];
									 TCP_C[TCPjzz + 0x04] = SRAM[0x0009];
									 TCP_C[TCPjzz + 0x05] = SRAM[0x000a];
									 TCP_C[TCPjzz + 0x06] = SRAM[0x000b];

									 TCP_C[TCPjzz + 0x07] = SRAM[0x001a];	//保存源IP到
此TCP块
									 TCP_C[TCPjzz + 0x08] = SRAM[0x001b];
									 TCP_C[TCPjzz + 0x09] = SRAM[0x001c];
									 TCP_C[TCPjzz + 0x0a] = SRAM[0x001d];

									 TCP_C[TCPjzz + 0x0b] = SRAM[0x0022];   //保存源端口
到此TCP块
									 TCP_C[TCPjzz + 0x0c] = SRAM[0x0023];

									 jiafachuli_32BIT(SRAM[0x0026],SRAM[0x0027],SRAM
[0x0028],SRAM[0x0029],0x0001); //序号加1

									 TCP_C[TCPjzz + 0x0d] = aaa;   //加1后的序号存进此TCP
块
									 TCP_C[TCPjzz + 0x0e] = bbb;
									 TCP_C[TCPjzz + 0x0f] = ccc;
									 TCP_C[TCPjzz + 0x10] = ddd;

									 TCP_C[TCPjzz + 0x11] = 0x77;   //确认号存进此TCP块
									 TCP_C[TCPjzz + 0x12] = 0x77;
									 TCP_C[TCPjzz + 0x13] = 0x77;
									 TCP_C[TCPjzz + 0x14] = 0x78;


									 SRAM[0x003a] = 0x01;  //填NOP	
				                     SRAM[0x003b] = 0x01;
				                     SRAM[0x003c] = 0x01;
				                     SRAM[0x003d] = 0x01;
				                     SRAM[0x003e] = 0x01;
				                     SRAM[0x003f] = 0x01;

				                     SRAM[0x0040] = 0x04;  //填 TCP SACK允许选项:真  
				                     SRAM[0x0041] = 0x02;

									 TCP_fasong(SRAM[0x0006],SRAM[0x0007],SRAM
[0x0008],SRAM[0x0009],SRAM[0x000a],SRAM[0x000b],SRAM[0x001a],SRAM[0x001b],SRAM[0x001c],SRAM[0x001d],SRAM[0x0022],SRAM
[0x0023],0x77,0x77,0x77,0x77,aaa,bbb,ccc,ddd,0x80,0x12,0x0400,0x000c);  //发送 ACK = 1 SYN = 1  回复请求连接


									 TCP_C[TCPjzz + 0x15] = 2;  //定时器装数 2秒
									 
									 TCP_C[TCPjzz] = 0xa0;	//启动断连定时器  同时标志此
块有效

									 TCPjzz = (TCP_IIS*52); //跳出循环
							   }
							   else
							   {
							         TCPjzz = TCPjzz + 52;	//指向下一个TCP块
							   }

						  }
					 }
					 else
					 {
						   if((SRAM[0x002f] & 0x01) == 0x01)  //FIN = 1 断开连接
						   {
								jiafachuli_32BIT(SRAM[0x0026],SRAM[0x0027],SRAM[0x0028],SRAM
[0x0029],0x0001);

							    TCP_fasong(SRAM[0x0006],SRAM[0x0007],SRAM[0x0008],SRAM
[0x0009],SRAM[0x000a],SRAM[0x000b],SRAM[0x001a],SRAM[0x001b],SRAM[0x001c],SRAM[0x001d],SRAM[0x0022],SRAM[0x0023],SRAM
[0x002a],SRAM[0x002b],SRAM[0x002c],SRAM[0x002d],aaa,bbb,ccc,ddd,0x50,0x10,0x0400,0x0000);  //发送 ACK = 1 回复确认
										  
						   }

					 }

				}
				else  //有一样的连接
				{
					 TCPjzz = TCPjzz - 52; //指向此TCP块起始位置
					 
				     if(SRAM[0x002f] == 0x10)	  //ACK = 1 带确认
					 {
					      if(TCP_C[TCPjzz + 0x0d] == SRAM[0x0026] & TCP_C[TCPjzz + 0x0e] == SRAM[0x0027] 
& TCP_C[TCPjzz + 0x0f] == SRAM[0x0028] & TCP_C[TCPjzz + 0x10] == SRAM[0x0029] & TCP_C[TCPjzz + 0x11] == SRAM[0x002a] & TCP_C
[TCPjzz + 0x12] == SRAM[0x002b] & TCP_C[TCPjzz + 0x13] == SRAM[0x002c] & TCP_C[TCPjzz + 0x14] == SRAM[0x002d])	 //收到的ACK
包序号确认号和此TCP块的一样?
						  {

								if(TCP_C[TCPjzz + 0x16] == 0x00 & TCP_C[TCPjzz + 0x17] == 
0x00 & TCP_C[TCPjzz + 0x18] == 0x00 & TCP_C[TCPjzz + 0x19] == 0x00) //此TCP块文件剩余字节大小为0?
								{
								      TCP_C[TCPjzz + 0x15] = 2;  //定时器装数 2秒
									  
									  TCP_C[TCPjzz] = 0xa0;	//启动断连定时器


								}
								else  //文件剩余字节大小不为0
								{
									  if(cudx == 1)
									  {
										 TCP_fasongshuju_1();

										 //zzzz = zzzz + 430;	 //430倍补偿
									  }
									  else
									  {
									     TCP_fasongshuju_2();

										 //zzzz = zzzz + 900;	 //900倍补偿
									  }

								}

						  }
					 }
					 else
					 {
					      if(SRAM[0x002f] == 0x18)   //ACK = 1 PUSH = 1 直接送应用程序
						  { 
								if(SRAM[0x0036] == 0x47 & SRAM[0x0037] == 0x45 & SRAM[0x0038] 
== 0x54) //GET请求?	 (在这里先判断GET)
								{
									 jiafachuli_32BIT(SRAM[0x0026],SRAM[0x0027],SRAM
[0x0028],SRAM[0x0029],jjh - 54);  //序号加携带数据大小
									 
							         TCP_C[TCPjzz + 0x0d] = aaa;   //加携带数据大小后的序号存进此
TCP块
							         TCP_C[TCPjzz + 0x0e] = bbb;
							         TCP_C[TCPjzz + 0x0f] = ccc;
							         TCP_C[TCPjzz + 0x10] = ddd;

								     TCP_C[TCPjzz + 0x11] = SRAM[0x002a];   //确认号存进此TCP
块
							         TCP_C[TCPjzz + 0x12] = SRAM[0x002b];
							         TCP_C[TCPjzz + 0x13] = SRAM[0x002c];
								     TCP_C[TCPjzz + 0x14] = SRAM[0x002d];

								     TCP_fasong(SRAM[0x0006],SRAM[0x0007],SRAM[0x0008],SRAM
[0x0009],SRAM[0x000a],SRAM[0x000b],SRAM[0x001a],SRAM[0x001b],SRAM[0x001c],SRAM[0x001d],SRAM[0x0022],SRAM[0x0023],SRAM
[0x002a],SRAM[0x002b],SRAM[0x002c],SRAM[0x002d],aaa,bbb,ccc,ddd,0x50,0x10,0x0400,0x0000);  //发送 ACK = 1 回复确认
								
									 GET_lujingchuli(); //GET路径分析处理 读出文件簇号和
大小

									 TCP_C[TCPjzz + 0x16] = wjdx4; 	 //文件字节大小存入此
TCP块
									 TCP_C[TCPjzz + 0x17] = wjdx3;
									 TCP_C[TCPjzz + 0x18] = wjdx2;
									 TCP_C[TCPjzz + 0x19] = wjdx1;

									 if(wjdx4 != 0x00 | wjdx3 != 0x00 | wjdx2 != 0x00 | 
wjdx1 != 0x00) //文件字节大小不为0进入
									 {
									       TCP_C[TCPjzz + 0x1c] = wjcuhao3;	 //保存首簇号
到此TCP块
										   TCP_C[TCPjzz + 0x1d] = wjcuhao2;
										   TCP_C[TCPjzz + 0x1e] = wjcuhao1;

										   FAT32_cuhao_culian(wjcuhao3,wjcuhao2,wjcuhao1);

										   TCP_C[TCPjzz + 0x1f] = culian[0];  //保存
下7个簇号到此TCP块
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
										   
										   TCP_C[TCPjzz + 0x1b]	= 0;   //簇号指针清0

										   TCP_C[TCPjzz + 0x1a]	= 0;   //扇区指针清0


									 }


									 HTTP_toubu();	//填HTTP头部

									 TCP_fasong(TCP_C[TCPjzz + 0x01],TCP_C[TCPjzz + 
0x02],TCP_C[TCPjzz + 0x03],TCP_C[TCPjzz + 0x04],TCP_C[TCPjzz + 0x05],TCP_C[TCPjzz + 0x06],TCP_C[TCPjzz + 0x07],TCP_C[TCPjzz + 
0x08],TCP_C[TCPjzz + 0x09],TCP_C[TCPjzz + 0x0a],TCP_C[TCPjzz + 0x0b],TCP_C[TCPjzz + 0x0c],TCP_C[TCPjzz + 0x11],TCP_C[TCPjzz + 
0x12],TCP_C[TCPjzz + 0x13],TCP_C[TCPjzz + 0x14],TCP_C[TCPjzz + 0x0d],TCP_C[TCPjzz + 0x0e],TCP_C[TCPjzz + 0x0f],TCP_C[TCPjzz + 
0x10],0x50,0x18,0x0400,zzj - 54); //发送HTTP头部

									 jiafachuli_32BIT(TCP_C[TCPjzz + 0x11],TCP_C[TCPjzz + 
0x12],TCP_C[TCPjzz + 0x13],TCP_C[TCPjzz + 0x14],zzj - 54);  //此TCP块的确认号 + HTTP头部大小

									 TCP_C[TCPjzz + 0x11] = aaa;  //结果存回此TCP块的确认
号
									 TCP_C[TCPjzz + 0x12] = bbb;
									 TCP_C[TCPjzz + 0x13] = ccc;
									 TCP_C[TCPjzz + 0x14] = ddd;

									 TCP_C[TCPjzz + 0x15] = 2;  //定时器装数  2秒
									
									 TCP_C[TCPjzz] = 0xa0;	//启动断连定时器
									 
									 
								}
								else  //不是GET请求 断开连接释放空间
								{
									 TCP_C[TCPjzz] = 0x00;  //此TCP块标志清0  释放

									 TCP_C[TCPjzz + 0x16] = 0x00;  //此TCP块文件剩余字节
大小清0
									 TCP_C[TCPjzz + 0x17] = 0x00;
									 TCP_C[TCPjzz + 0x18] = 0x00;
									 TCP_C[TCPjzz + 0x19] = 0x00; 				
					 
								}

						  }
						  else
						  {
						       if((SRAM[0x002f] & 0x04) == 0x04)  //RST = 1 重建连接  (RST待删)
							   {
							         TCP_C[TCPjzz] = 0x00;  //此TCP块标志清0  释放

									 TCP_C[TCPjzz + 0x16] = 0x00;  //此TCP块文件剩余字节
大小清0
									 TCP_C[TCPjzz + 0x17] = 0x00;
									 TCP_C[TCPjzz + 0x18] = 0x00;
									 TCP_C[TCPjzz + 0x19] = 0x00; 
							   }
							   else
							   {
							        if((SRAM[0x002f] & 0x01) == 0x01)  //FIN = 1 断开连接
									{
										  jiafachuli_32BIT(SRAM[0x0026],SRAM
[0x0027],SRAM[0x0028],SRAM[0x0029],0x0001);	//序号加1

									      TCP_fasong(SRAM[0x0006],SRAM[0x0007],SRAM
[0x0008],SRAM[0x0009],SRAM[0x000a],SRAM[0x000b],SRAM[0x001a],SRAM[0x001b],SRAM[0x001c],SRAM[0x001d],SRAM[0x0022],SRAM
[0x0023],SRAM[0x002a],SRAM[0x002b],SRAM[0x002c],SRAM[0x002d],aaa,bbb,ccc,ddd,0x50,0x10,0x0400,0x0000);  //发送 ACK = 1 回复确
认
									
										  TCP_C[TCPjzz] = 0x00;  //此TCP块标志清0  释
放

									      TCP_C[TCPjzz + 0x16] = 0x00;  //此TCP块文件剩余
字节大小清0
									      TCP_C[TCPjzz + 0x17] = 0x00;
									      TCP_C[TCPjzz + 0x18] = 0x00;
									      TCP_C[TCPjzz + 0x19] = 0x00;

									}
									else
									{
									      TCP_C[TCPjzz] = 0x00;  //此TCP块标志清0  释放

									      TCP_C[TCPjzz + 0x16] = 0x00;  //此TCP块文件剩余
字节大小清0
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



void TCP_IP() //TCP_IP收包处理
{


		if(SRAM[0x000c] == 0x08 & SRAM[0x000d] == 0x06)	 //ARP?
		{
			if(SRAM[0x0014] == 0x00 & SRAM[0x0015] == 0x01)	  //ARP请求包? 
		    {
			     if(SRAM[0x0026] == IP3 & SRAM[0x0027] == IP2 & SRAM[0x0028] == IP1 & SRAM[0x0029] == IP0)	//本
机IP?
				 {
					 ARPyingda();
			     }
			}
			else
			{
				 if(SRAM[0x0014] == 0x00 & SRAM[0x0015] == 0x02)	 //ARP应答包?
				 {
					  if(SRAM[0x0000] == MAC5 & SRAM[0x0001] == MAC4 & SRAM[0x0002] == MAC3 & SRAM
[0x0003] == MAC2 & SRAM[0x0004] == MAC1 & SRAM[0x0005] == MAC0)	  //本机MAC地址?
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
& SRAM[0x0004] == MAC1 & SRAM[0x0005] == MAC0)	//本机MAC地址?
				 {
					 if(SRAM[0x000e] == 0x45 & SRAM[0x001e] == IP3 & SRAM[0x001f] == IP2 & SRAM[0x0020] 
== IP1 & SRAM[0x0021] == IP0)  //IPV4?  5X32?  本机IP?
					 {
						  if(SRAM[0x0017] == 1)	//ICMP?
						  {
								if(SRAM[0x0022] == 0x08)  //响应请求?
								{
									ICMPyingda(); //回响处理
							    }
						  }
						  else
						  {
								if(SRAM[0x0017] == 6)  //TCP?
								{
								     TCPchuli(); //TCP处理
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
    if(zzzz > 0x3400)	 //不精确0.25秒基准
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
 
    //if(SPI_D != 0)		 //EPKTCNT大于0时进入  有数据包

    if((SPI_INT & 0x01) == 0 || ENC28J60_SJBBZ == 1) //ENC28J60有中断 或 标志还有数据包 进入
    {

     /////////////////////////////////////接收部份////////////////////////////////////////////////
						
       jieshoushujubao();

      //////////////////////////////////////////// TCP/IP /////////////////////////////////////////////////
					   	
      if(jjh < 713)	//超过SRAM容量不进
      {
        TCP_IP();
        ++RX_X;
      }

      /////////////////////////////////////////////////////////////////////////////////////////////////////	  		


    }

}