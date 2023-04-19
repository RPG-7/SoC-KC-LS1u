void TFT_WR(unsigned char addr,unsigned int data)
{

     CS_8080 = 0x09; //"CS1" 片选信号线为低电平, 选中接 "CS1" 的设备

     D0_8080 = 0x00;
     D0_8080 = addr;
     D1_8080 = data >> 8;
     D1_8080 = data;

     CS_8080 = 0x00; //撤销片选

}

void TFT_CSH() //初始化TFT
{
     TFT_WR(0x01,0x0100);
     TFT_WR(0x02,0x0700);
     TFT_WR(0x03,0x1028);
     TFT_WR(0x04,0x0000);
     TFT_WR(0x08,0x0202);
     TFT_WR(0x09,0x0000);
     TFT_WR(0x0a,0x0000);
     TFT_WR(0x0c,0x0000);
     TFT_WR(0x0d,0x0000);
     TFT_WR(0x0f,0x0000);

     TFT_WR(0x10,0x0000);
     TFT_WR(0x11,0x0007);
     TFT_WR(0x12,0x0000);
     TFT_WR(0x13,0x0000);
     TFT_WR(0x07,0x0001);
     TFT_WR(0x10,0x1690);
     TFT_WR(0x11,0x0227);
     TFT_WR(0x12,0x009d);
     TFT_WR(0x13,0x1900);
     TFT_WR(0x29,0x0025);
     TFT_WR(0x2b,0x000d);
     TFT_WR(0x20,0x0000);
     TFT_WR(0x21,0x0000);

     TFT_WR(0x30,0x0007);
     TFT_WR(0x31,0x0303);
     TFT_WR(0x32,0x0003);
     TFT_WR(0x35,0x0206);
     TFT_WR(0x36,0x0008);
     TFT_WR(0x37,0x0406);
     TFT_WR(0x38,0x0304);
     TFT_WR(0x39,0x0007);
     TFT_WR(0x3c,0x0602);
     TFT_WR(0x3d,0x0008);

     TFT_WR(0x50,0x0000);
     TFT_WR(0x51,0x00ef);
     TFT_WR(0x52,0x0000);
     TFT_WR(0x53,0x013f);
     TFT_WR(0x60,0xa700);
     TFT_WR(0x61,0x0001);
     TFT_WR(0x6a,0x0000);

     TFT_WR(0x80,0x0000);
     TFT_WR(0x81,0x0000);
     TFT_WR(0x82,0x0000);
     TFT_WR(0x83,0x0000);
     TFT_WR(0x84,0x0000);
     TFT_WR(0x85,0x0000);

     TFT_WR(0x90,0x0010);
     TFT_WR(0x92,0x0600);
     TFT_WR(0x07,0x0133);	
}


void TFT_QP() //清屏TFT
{

unsigned int k;

		 
		 TFT_WR(0x20,0x00ef);
		 TFT_WR(0x21,0x0000);

		 k = 0;

		 while(k != 9600)
		 {
			TFT_WR(0x22,0x0000);
			TFT_WR(0x22,0x0000);
			TFT_WR(0x22,0x0000);
			TFT_WR(0x22,0x0000);
			TFT_WR(0x22,0x0000);
			TFT_WR(0x22,0x0000);
			TFT_WR(0x22,0x0000);
			TFT_WR(0x22,0x0000);

			k++;
		 }
                     
}


void TFT_VRAM_TFTRAM() //复制VGA显存数据到TFT显存
{

unsigned char *VRAM_ADDR = 0x800000;
unsigned char VRAM_DATA;
unsigned char TFTRAM_DATA_H;
unsigned char TFTRAM_DATA_L;
unsigned char js1;

unsigned char DATA0;
unsigned char DATA1;
unsigned char DATA2;
unsigned char DATA3;
unsigned char DATA4;
unsigned char DATA5;
unsigned char DATA6;
unsigned char DATA7;

unsigned char RD_Y_A;
unsigned char RD_X_A;


     CS_8080 = 0x09; //"CS1" 片选信号线为低电平, 选中接 "CS1" 的设备

     js1 = 240;
     RD_X_A = 0;
     RD_Y_A = 0;

     do
     {


          --js1;


          D0_8080 = 0x00; //设置起始Y坐标
          D0_8080 = 0x20;
          D1_8080 = 0x00;
          D1_8080 = js1;

          D0_8080 = 0x00; //设置起始X坐标
          D0_8080 = 0x21;
          D1_8080 = 0x00;
          D1_8080 = 0;


          D0_8080 = 0x00; //设置TFT命令寄存器选中显存数据寄存器
          D0_8080 = 0x22;


          do
          {

              _A = RD_X_A;

              _A1 = RD_Y_A;
              _A2 = 0x80;
              _A0 = _A;
              ++_A;
              _B = _RAM;
              DATA0 = _B;

              _A1 = RD_Y_A;
              _A2 = 0x80;
              _A0 = _A;
              ++_A;
              _B = _RAM;
              DATA1 = _B;

              _A1 = RD_Y_A;
              _A2 = 0x80;
              _A0 = _A;
              ++_A;
              _B = _RAM;
              DATA2 = _B;

              _A1 = RD_Y_A;
              _A2 = 0x80;
              _A0 = _A;
              ++_A;
              _B = _RAM;
              DATA3 = _B;

              _A1 = RD_Y_A;
              _A2 = 0x80;
              _A0 = _A;
              ++_A;
              _B = _RAM;
              DATA4 = _B;

              _A1 = RD_Y_A;
              _A2 = 0x80;
              _A0 = _A;
              ++_A;
              _B = _RAM;
              DATA5 = _B;

              _A1 = RD_Y_A;
              _A2 = 0x80;
              _A0 = _A;
              ++_A;
              _B = _RAM;
              DATA6 = _B;

              _A1 = RD_Y_A;
              _A2 = 0x80;
              _A0 = _A;
              ++_A;
              _B = _RAM;
              DATA7 = _B;

              RD_X_A = _A;



              TFTRAM_DATA_H = (DATA0 & 0xe0) | ((DATA0 >> 2) & 0x07);     //拷贝VRAM数据到TFTRAM
              TFTRAM_DATA_L = (DATA0 << 3) & 0x1f;
              D1_8080 = TFTRAM_DATA_H;
              D1_8080 = TFTRAM_DATA_L;

              TFTRAM_DATA_H = (DATA1 & 0xe0) | ((DATA1 >> 2) & 0x07);     //拷贝VRAM数据到TFTRAM
              TFTRAM_DATA_L = (DATA1 << 3) & 0x1f;
              D1_8080 = TFTRAM_DATA_H;
              D1_8080 = TFTRAM_DATA_L;

              TFTRAM_DATA_H = (DATA2 & 0xe0) | ((DATA2 >> 2) & 0x07);     //拷贝VRAM数据到TFTRAM
              TFTRAM_DATA_L = (DATA2 << 3) & 0x1f;
              D1_8080 = TFTRAM_DATA_H;
              D1_8080 = TFTRAM_DATA_L;

              TFTRAM_DATA_H = (DATA3 & 0xe0) | ((DATA3 >> 2) & 0x07);     //拷贝VRAM数据到TFTRAM
              TFTRAM_DATA_L = (DATA3 << 3) & 0x1f;
              D1_8080 = TFTRAM_DATA_H;
              D1_8080 = TFTRAM_DATA_L;

              TFTRAM_DATA_H = (DATA4 & 0xe0) | ((DATA4 >> 2) & 0x07);     //拷贝VRAM数据到TFTRAM
              TFTRAM_DATA_L = (DATA4 << 3) & 0x1f;
              D1_8080 = TFTRAM_DATA_H;
              D1_8080 = TFTRAM_DATA_L;

              TFTRAM_DATA_H = (DATA5 & 0xe0) | ((DATA5 >> 2) & 0x07);     //拷贝VRAM数据到TFTRAM
              TFTRAM_DATA_L = (DATA5 << 3) & 0x1f;
              D1_8080 = TFTRAM_DATA_H;
              D1_8080 = TFTRAM_DATA_L;

              TFTRAM_DATA_H = (DATA6 & 0xe0) | ((DATA6 >> 2) & 0x07);     //拷贝VRAM数据到TFTRAM
              TFTRAM_DATA_L = (DATA6 << 3) & 0x1f;
              D1_8080 = TFTRAM_DATA_H;
              D1_8080 = TFTRAM_DATA_L;

              TFTRAM_DATA_H = (DATA7 & 0xe0) | ((DATA7 >> 2) & 0x07);     //拷贝VRAM数据到TFTRAM
              TFTRAM_DATA_L = (DATA7 << 3) & 0x1f;
              D1_8080 = TFTRAM_DATA_H;
              D1_8080 = TFTRAM_DATA_L;



          }while(RD_X_A != 0);


          ++RD_Y_A; //Y坐标+1

     }while(js1 != 0);



     CS_8080 = 0x00; //撤销片选



}