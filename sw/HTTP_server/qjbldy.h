unsigned char SRAM[712];

unsigned char TT;
////////////////////////////////

unsigned char x,y,zzz,lj;  //延时 计数

unsigned int k,zzzz; //延时 计数

/////////////////////收包用//////////////////////

unsigned char addrL,addrH;	 //保存下一数据包起始地址

unsigned char jjl;	   //接收到的数据包字节数低8位保存

unsigned int jjh;	   //接收到的数据包字节数

unsigned char ENC28J60_SJBBZ = 0;  //数据包标志  1为缓冲区有数据包 0为没有数据包

unsigned int QSJJ = 0; //取时间计数  计够数了取一次DS1302秒数


////////////////////////////////

unsigned int IPj;	 //本机IP标识字段  每发1个+1

unsigned char aaaa,bbbb;	//校验和函数用
unsigned int cccc,dddd; //校验和函数用

unsigned char aaa,bbb,ccc,ddd;   //32位加法处理结果


////////////////////////网络设置//////////////////

unsigned char MAC5 = 0x61,MAC4 = 0x61,MAC3 = 0x61,MAC2 = 0x61,MAC1 = 0x61,MAC0 = 0x70; //本机MAC

unsigned char IP3 = 192,IP2 = 168,IP1 = 1,IP0 = 77;	//本机IP

unsigned char WGIP3 = 192,WGIP2 = 168,WGIP1 = 1,WGIP0 = 1; //网关IP

unsigned char YM3 = 255,YM2 = 255,YM1 = 255,YM0 = 0; //子网掩码

unsigned int HTTPdk = 80; //HTTP服的端口


//////////////TF卡FAT32文件系统///////////////////

unsigned char aa,bb,cc;  //24位加法处理结果


unsigned char cudx,FATsl;  //每簇扇区数、FAT表数量

unsigned char FAT1H,FAT1L;  //FAT1表起始地址

unsigned char FAT2H,FAT2L,FAT2LL; //FAT2表起始地址

unsigned char DATAH,DATAL,DATALL;  //数据区起始地址


unsigned char sqdz3,sqdz2,sqdz1;  //簇号转扇区地址函数输出的扇区地址值


unsigned char bencu3,bencu2,bencu1;  //簇号转簇值函数 用来保存本簇  和下一簇比较
unsigned char culian[24];	  //簇号转簇值函数输出 保存8个簇值  一个簇值3字节


unsigned char wjcuhao3,wjcuhao2,wjcuhao1,wjdx4,wjdx3,wjdx2,wjdx1; //文件查询1函数的 文件信息
unsigned char wjbz;  //文件查询1函数的文件信息标志  为1有效 为0无效


/////////////////GET路径处理//////////////////////

unsigned char wjm[8];	//保存文件名
unsigned char hzm[3];	//保存后缀名

unsigned char qh; //0为输入文件名  1为输入后缀名

unsigned int zz; //zz为字节基址	起始指向0x2f 即/

unsigned char xj,yj; //xj为字节偏移  yj为文件名、后缀名输入门限

unsigned char zzbc;  //字节保存

unsigned char mlcuhao3,mlcuhao2,mlcuhao1;	  //目录簇号寄存


///////////////////32位转10进制////////////////////

unsigned char ywj;  //移位计数

unsigned char sjz10,sjz9,sjz8,sjz7,sjz6,sjz5,sjz4,sjz3,sjz2,sjz1; //10位10进制结果保存


//////////////////HTTP填头部/////////////////////

unsigned char zzj;  //写入字节的指针


///////////////////TCP连接表//////////////////////

#define TCP_IIS 20 //最大允许连接数

unsigned char TCP_C[1040];  //1个连接表52字节 根据最大允许连接数设置大小

unsigned int TCPjzz;  //TCP连接表基指针

unsigned char TCPkbz;  //不为0表示有一样的连接

unsigned char sbc; //保存秒数

/////////////////////////////////////////////////
