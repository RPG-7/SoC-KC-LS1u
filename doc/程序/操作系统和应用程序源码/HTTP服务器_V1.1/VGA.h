void VGA_VRAM_LD() //读写VRAM之前要调用此函数
{

/***************************** 允许VRAM更新时间 = VGA_CL1 * (65536 / CPU主频) = 16.384毫秒 *****************************/

#define VGA_CL1 4

/***********************************************************************************************************************/

   while((VGA_CT2_ < 256 - VGA_CL1 && (CT2 < VGA_CT2_ || CT2 >= VGA_CT2_ + VGA_CL1)   ||   VGA_CT2_ > 255 - VGA_CL1 && CT2 < VGA_CT2_ && CT2 >= VGA_CT2_ + VGA_CL1) == 0); //上次记录的硬件计数器数据和现在硬件计数器的数据进行比较,达到条件时跳出
   CTVGA_C &= 0xfe; //请求访问VRAM
   while((CTVGA_C & 0x80) == 0x80); //VRAM可以访问的时候跳出


}


void VGA_VRAM_UP() //写入显存的数据更新到屏幕,VRAM读写完成后要调用此函数
{
   CTVGA_C |= 0x01; //请求VRAM显示
   VGA_CT2_ = CT2;  //记录当前硬件计数器数据
}



void VGA_SK0(unsigned char Y,unsigned char _Y,unsigned char DATA) //画色块0,Y为起始坐标,_Y为结束坐标,X坐标256全部写像素,12MHZ的CPU频率下每秒可以执行约40次
{

 while(Y != _Y)
 {

   _B = DATA;
   _A = 0;

   do
   {
     _A1 = Y;
     _A2 = 0x80;

     _A0 = _A;
     _NOP;
     _RAM = _B;
     _A = _A + 1;

     _A0 = _A;
     _NOP;
     _RAM = _B;
     _A = _A + 1;

     _A0 = _A;
     _NOP;
     _RAM = _B;
     _A = _A + 1;

     _A0 = _A;
     _NOP;
     _RAM = _B;
     _A = _A + 1;

     _A0 = _A;
     _NOP;
     _RAM = _B;
     _A = _A + 1;

     _A0 = _A;
     _NOP;
     _RAM = _B;
     _A = _A + 1;

     _A0 = _A;
     _NOP;
     _RAM = _B;
     _A = _A + 1;

     _A0 = _A;
     _NOP;
     _RAM = _B;
     _A = _A + 1;

   }while(_SUB_A_1 != -1);

   ++Y;

 }


}


/*
void VGA_SK1(unsigned char y,unsigned char x,unsigned char _y,unsigned char _x,unsigned char data) //画色块1,yx为起始坐标,_y_x为点数,data像素数据
{

unsigned char x_;


  if(_y != 0 && _x != 0)
  {

    x_ = x;
    _y += y;
    _x += x;

    do
    {
       do
       {
          _B = data;
          _A = y;
          _A0 = x;
          _A2 = 0x80;
          _A1 = _A;
          _NOP;
          _RAM = _B;
          ++x;

       }while(x != _x);

       x = x_;
       ++y;

    }while(y != _y);

  }

}
*/

void VGA_SK1(unsigned char y,unsigned char x,unsigned char _y,unsigned char _x,unsigned char data) //画色块1,yx为起始坐标,_y_x为点数,data像素数据
{

unsigned char x_;
unsigned char js1;


  if(_y != 0 && _x != 0)
  {

    js1 = _x >> 4;
    x_ = x;
    _y += y;
    _x += x;


    do
    {

       while(js1 != 0) //x连续写16个像素点
       {

          _B = data;
          _A = x;
          _A1 = y;
          _A2 = 0x80;


          _A0 = _A;
          _NOP;
          _RAM = _B;
          _A = _A + 1;

          _A0 = _A;
          _NOP;
          _RAM = _B;
          _A = _A + 1;

          _A0 = _A;
          _NOP;
          _RAM = _B;
          _A = _A + 1;

          _A0 = _A;
          _NOP;
          _RAM = _B;
          _A = _A + 1;

          _A0 = _A;
          _NOP;
          _RAM = _B;
          _A = _A + 1;

          _A0 = _A;
          _NOP;
          _RAM = _B;
          _A = _A + 1;

          _A0 = _A;
          _NOP;
          _RAM = _B;
          _A = _A + 1;

          _A0 = _A;
          _NOP;
          _RAM = _B;
          _A = _A + 1;

          _A0 = _A;
          _NOP;
          _RAM = _B;
          _A = _A + 1;

          _A0 = _A;
          _NOP;
          _RAM = _B;
          _A = _A + 1;

          _A0 = _A;
          _NOP;
          _RAM = _B;
          _A = _A + 1;

          _A0 = _A;
          _NOP;
          _RAM = _B;
          _A = _A + 1;

          _A0 = _A;
          _NOP;
          _RAM = _B;
          _A = _A + 1;

          _A0 = _A;
          _NOP;
          _RAM = _B;
          _A = _A + 1;

          _A0 = _A;
          _NOP;
          _RAM = _B;
          _A = _A + 1;

          _A0 = _A;
          _NOP;
          _RAM = _B;

          x+=16;
          --js1;

       }


       while(x != _x)
       {
          _B = data;
          _A = y;
          _A0 = x;
          _A2 = 0x80;
          _A1 = _A;
          _NOP;
          _RAM = _B;
          ++x;

       }

       x = x_;
       ++y;

    }while(y != _y);

  }

}


void VGA_ZX(unsigned char y,unsigned char x,unsigned char _y,unsigned char _x,unsigned char data) //画直线,yx为起始坐标,_y_x为结束坐标,data像素数据
{

unsigned char _y_; //Y坐标差值
unsigned char _x_; //X坐标差值
unsigned char y_; //Y坐标起始
unsigned char x_; //X坐标起始
unsigned char js0;

unsigned int js1;
unsigned int js2;


    if(_x < x) //X坐标反方向
    {
        js0 = x;
        x = _x;
        _x = js0;

        js0 = y;
        y = _y;
        _y = js0;
    }

    if(_y < y) //Y坐标反方向
    {
       --_y;
       _y_ = y - _y;
       js0 = -1;
    }
    else //Y坐标正方向
    {
       ++_y;
       _y_ = _y - y;
       js0 = 1;
    }

    ++_x;
    _x_ = _x - x;


    if(_y_ == _x_) //正方形对角
    {

        do
        {
            _B = data;
            _A = y;
            _A0 = x;
            _A2 = 0x80;
            _A1 = _A;
            _NOP;
            _RAM = _B;
            y += js0;
            ++x;

        }while(y != _y);

    }
    else if(_y_ > _x_) //竖的长方形对角
    {

        js1 = _x_;
        js1 <<= 8;
        js1 = js1 / _y_; //计算出比例增值
        js2 = x;
        js2 <<= 8;

        do
        {

            js2 += js1;
            x = js2 >> 8;

            _B = data;
            _A = y;
            _A0 = x;
            _A2 = 0x80;
            _A1 = _A;
            _NOP;
            _RAM = _B;
            y += js0;

        }while(y != _y);

    }
    else //横的长方形对角
    {

        js1 = _y_;
        js1 <<= 8;
        js1 = js1 / _x_; //计算出比例增值
        if(y > _y) js1 = -js1;
        js2 = y;
        js2 <<= 8;

        do
        {

            js2 += js1;
            y = js2 >> 8;

            _B = data;
            _A = y;
            _A0 = x;
            _A2 = 0x80;
            _A1 = _A;
            _NOP;
            _RAM = _B;
            ++x;

        }while(x != _x);

    }


}


void VGA_kuang0(unsigned char y,unsigned char x,unsigned char _y,unsigned char _x,unsigned char data) //画框0,yx为起始坐标,_y_x为点数+1,data像素数据
{

unsigned char x_;
unsigned char y_;


  if(_y != 0 && _x != 0)
  {

    x_ = x;
    y_ = y;
    _y += y;
    _x += x;


       do
       {
          _B = data;
          _A = y;
          _A0 = x;
          _A2 = 0x80;
          _A1 = _A;
          _NOP;
          _RAM = _B;
          ++x;

       }while(x != _x);

       do
       {
          _B = data;
          _A = y;
          _A0 = x;
          _A2 = 0x80;
          _A1 = _A;
          _NOP;
          _RAM = _B;
          ++y;

       }while(y != _y);

       do
       {
          _B = data;
          _A = y;
          _A0 = x;
          _A2 = 0x80;
          _A1 = _A;
          _NOP;
          _RAM = _B;
          --x;

       }while(x != x_);

       do
       {
          _B = data;
          _A = y;
          _A0 = x;
          _A2 = 0x80;
          _A1 = _A;
          _NOP;
          _RAM = _B;
          --y;

       }while(y != y_);


  }

}


void VGA_ASCII(unsigned char y,unsigned char x,unsigned int ascii_data,unsigned char rgb_data) //显示默认大小ASCII码,yx为起始坐标,ascii_data为ASCII值,rgb_data像素数据
{

unsigned char x_;
unsigned char b_x;
unsigned char bit_data;
unsigned char *_addr;


     x_ = x;
     _addr = ASCII + ascii_data * 12;

     b_x = 0;

     do
     {

          bit_data = *_addr;


          if((bit_data & 0x80) != 0) _B = rgb_data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x;
          if((bit_data & 0x40) != 0) _B = rgb_data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x;
          if((bit_data & 0x20) != 0) _B = rgb_data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x;
          if((bit_data & 0x10) != 0) _B = rgb_data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x;
          if((bit_data & 0x08) != 0) _B = rgb_data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x;
          if((bit_data & 0x04) != 0) _B = rgb_data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B;


          ++_addr;
          ++b_x;
          x = x_;
          ++y;

     }while(b_x != 12);


}

void VGA_GB2312(unsigned char y,unsigned char x,unsigned char *GB2312_data,unsigned char rgb_data) //显示默认大小GB2312码,yx为起始坐标,GB2312_data为GB2312字符串,rgb_data像素数据
{

unsigned char x_;
unsigned char b_x;
unsigned char D1;
unsigned char D2;
unsigned long int ZADDR;
unsigned char *_addr;

unsigned int DH;
unsigned int DL;

  DH = GB2312_data[0];
  DL = GB2312_data[1];

  x_ = x;
  ZADDR = (DH - 0xa1) * 94 + (DL - 0xa1); //算出GB2312字符地址
  ZADDR *= 24; //一个字符占字库24个字节 乘24算出GB2312字库地址

  _addr = GB2312 + ZADDR;


  b_x = 0;

  do
  {

     D1 = *_addr;  //读出高8位像素字节
     ++_addr;
     D2 = *_addr;  //读出低8位像素字节
     ++_addr;

     if((D1 & 0x80) != 0) _B = rgb_data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x;
     if((D1 & 0x40) != 0) _B = rgb_data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x;
     if((D1 & 0x20) != 0) _B = rgb_data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x;
     if((D1 & 0x10) != 0) _B = rgb_data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x;
     if((D1 & 0x08) != 0) _B = rgb_data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x;
     if((D1 & 0x04) != 0) _B = rgb_data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x;
     if((D1 & 0x02) != 0) _B = rgb_data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x;
     if((D1 & 0x01) != 0) _B = rgb_data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x;

     if((D2 & 0x80) != 0) _B = rgb_data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x;
     if((D2 & 0x40) != 0) _B = rgb_data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x;
     if((D2 & 0x20) != 0) _B = rgb_data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x;
     if((D2 & 0x10) != 0) _B = rgb_data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B;


     x = x_; //x坐标恢复起点
     ++y; //y地址加1
     ++b_x;

  }while(b_x != 12);


}




void VGA_32bit_DP(unsigned char y,unsigned char x,unsigned long int XX,unsigned char rgb_data) //32位无符号数转十进制显示,yx为起始坐标,XX为32位数,rgb_data像素数据
{

unsigned char i;
unsigned char k = 0;


  i = XX / 1000000000;
  if(i != 0) VGA_ASCII(y,x,'0'+i,rgb_data),x+=6,k = 1;  //"十亿位"

  XX %= 1000000000;
  i = XX / 100000000;
  if(k != 0 || i != 0) VGA_ASCII(y,x,'0'+i,rgb_data),x+=6,k = 1;  //"亿位"

  XX %= 100000000;
  i = XX / 10000000;
  if(k != 0 || i != 0) VGA_ASCII(y,x,'0'+i,rgb_data),x+=6,k = 1;  //"千万位"

  XX %= 10000000;
  i = XX / 1000000;
  if(k != 0 || i != 0) VGA_ASCII(y,x,'0'+i,rgb_data),x+=6,k = 1;  //"百万位"

  XX %= 1000000;
  i = XX / 100000;
  if(k != 0 || i != 0) VGA_ASCII(y,x,'0'+i,rgb_data),x+=6,k = 1;  //"十万位"

  XX %= 100000;
  i = XX / 10000;
  if(k != 0 || i != 0) VGA_ASCII(y,x,'0'+i,rgb_data),x+=6,k = 1;  //"万位"

  XX %= 10000;
  i = XX / 1000;
  if(k != 0 || i != 0) VGA_ASCII(y,x,'0'+i,rgb_data),x+=6,k = 1;  //"千位"

  XX %= 1000;
  i = XX / 100;
  if(k != 0 || i != 0) VGA_ASCII(y,x,'0'+i,rgb_data),x+=6,k = 1;  //"百位"

  XX %= 100;
  i = XX / 10;
  if(k != 0 || i != 0) VGA_ASCII(y,x,'0'+i,rgb_data),x+=6;  //"十位"


  VGA_ASCII(y,x,'0' + XX % 10,rgb_data);  //"个位"


}



void VGA_CS_RGB256() //测试显示256种颜色
{

unsigned char x;
unsigned char y;
unsigned char data;

   data = 0;
   y = 12;

   do
   {
      x = 12;
      do
      {
         VGA_SK1(y,x,12,12,data);
         x += 14;
         ++data;

      }while(x != 236);

      y += 14;

   }while(y != 236);


}

/*
void VGA_KEY1_OFF(unsigned char y,unsigned char x,unsigned char _y,unsigned char _x)
{
   VGA_SK1(y,x,_y - 1,1,219); //曝光竖
   VGA_SK1(y,x,1,_x - 1,219); //曝光横
   VGA_SK1(y + _y - 1,x + 1,1,_x - 2,73); //阴影横
   VGA_SK1(y + 1,x + _x - 1,_y - 1,1,73); //阴影竖
   VGA_SK1(y + 1,x + 1,_y - 2,_x - 2,114); //平台
}

void VGA_KEY1_ON(unsigned char y,unsigned char x,unsigned char _y,unsigned char _x)
{
   VGA_SK1(y,x,_y - 1,1,73); //阴影竖
   VGA_SK1(y,x,1,_x - 1,73); //阴影横
   VGA_SK1(y + _y - 1,x + 1,1,_x - 2,219); //曝光竖
   VGA_SK1(y + 1,x + _x - 1,_y - 1,1,219); //曝光横
   VGA_SK1(y + 1,x + 1,_y - 2,_x - 2,114); //平台
}
*/




void VGA_16_16_XS(unsigned char y,unsigned char x,unsigned char _rgb_,unsigned char *rgb_data)
{

unsigned char x_;
unsigned char _data;

unsigned char js1;
unsigned char js2;

   x_ = x;

   js2 = 0;
   do
   {

       js1 = 0;
       do
       {

         _data = *rgb_data; if(_data != _rgb_) _B = _data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x; ++rgb_data;
         _data = *rgb_data; if(_data != _rgb_) _B = _data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x; ++rgb_data;
         _data = *rgb_data; if(_data != _rgb_) _B = _data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x; ++rgb_data;
         _data = *rgb_data; if(_data != _rgb_) _B = _data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x; ++rgb_data;
         _data = *rgb_data; if(_data != _rgb_) _B = _data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x; ++rgb_data;
         _data = *rgb_data; if(_data != _rgb_) _B = _data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x; ++rgb_data;
         _data = *rgb_data; if(_data != _rgb_) _B = _data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x; ++rgb_data;
         _data = *rgb_data; if(_data != _rgb_) _B = _data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x; ++rgb_data;

         ++js1;

       }while(js1 != 2);

       x = x_;
       ++y;
       ++js2;

   }while(js2 != 16);

}


void VGA_16_16_BC(unsigned char y,unsigned char x,unsigned char _rgb_,unsigned char *rgb_data,unsigned char *_rgb_buf)
{

unsigned char x_;
unsigned char _data;

unsigned char js1;
unsigned char js2;

   x_ = x;

   js2 = 0;
   do
   {

       js1 = 0;
       do
       {

         _data = *rgb_data; if(_data != _rgb_) _A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_B = _RAM,_data = _B,*_rgb_buf = _data; ++x; ++rgb_data; ++_rgb_buf;
         _data = *rgb_data; if(_data != _rgb_) _A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_B = _RAM,_data = _B,*_rgb_buf = _data; ++x; ++rgb_data; ++_rgb_buf;
         _data = *rgb_data; if(_data != _rgb_) _A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_B = _RAM,_data = _B,*_rgb_buf = _data; ++x; ++rgb_data; ++_rgb_buf;
         _data = *rgb_data; if(_data != _rgb_) _A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_B = _RAM,_data = _B,*_rgb_buf = _data; ++x; ++rgb_data; ++_rgb_buf;
         _data = *rgb_data; if(_data != _rgb_) _A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_B = _RAM,_data = _B,*_rgb_buf = _data; ++x; ++rgb_data; ++_rgb_buf;
         _data = *rgb_data; if(_data != _rgb_) _A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_B = _RAM,_data = _B,*_rgb_buf = _data; ++x; ++rgb_data; ++_rgb_buf;
         _data = *rgb_data; if(_data != _rgb_) _A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_B = _RAM,_data = _B,*_rgb_buf = _data; ++x; ++rgb_data; ++_rgb_buf;
         _data = *rgb_data; if(_data != _rgb_) _A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_B = _RAM,_data = _B,*_rgb_buf = _data; ++x; ++rgb_data; ++_rgb_buf;

         ++js1;

       }while(js1 != 2);

       x = x_;
       ++y;
       ++js2;

   }while(js2 != 16);

}

void VGA_16_16_HY(unsigned char y,unsigned char x,unsigned char _rgb_,unsigned char *rgb_data,unsigned char *_rgb_buf)
{

unsigned char x_;
unsigned char _data;

unsigned char js1;
unsigned char js2;

   x_ = x;

   js2 = 0;
   do
   {

       js1 = 0;
       do
       {

         _data = *rgb_data; if(_data != _rgb_) _data = *_rgb_buf,_B = _data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x; ++rgb_data; ++_rgb_buf;
         _data = *rgb_data; if(_data != _rgb_) _data = *_rgb_buf,_B = _data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x; ++rgb_data; ++_rgb_buf;
         _data = *rgb_data; if(_data != _rgb_) _data = *_rgb_buf,_B = _data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x; ++rgb_data; ++_rgb_buf;
         _data = *rgb_data; if(_data != _rgb_) _data = *_rgb_buf,_B = _data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x; ++rgb_data; ++_rgb_buf;
         _data = *rgb_data; if(_data != _rgb_) _data = *_rgb_buf,_B = _data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x; ++rgb_data; ++_rgb_buf;
         _data = *rgb_data; if(_data != _rgb_) _data = *_rgb_buf,_B = _data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x; ++rgb_data; ++_rgb_buf;
         _data = *rgb_data; if(_data != _rgb_) _data = *_rgb_buf,_B = _data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x; ++rgb_data; ++_rgb_buf;
         _data = *rgb_data; if(_data != _rgb_) _data = *_rgb_buf,_B = _data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x; ++rgb_data; ++_rgb_buf;

         ++js1;

       }while(js1 != 2);

       x = x_;
       ++y;
       ++js2;

   }while(js2 != 16);

}



void VGA_32_32_XS(unsigned char y,unsigned char x,unsigned char _rgb_,unsigned char *rgb_data)
{

unsigned char x_;
unsigned char _data;

unsigned char js1;
unsigned char js2;

   x_ = x;

   js2 = 0;
   do
   {

       js1 = 0;
       do
       {

         _data = *rgb_data; if(_data != _rgb_) _B = _data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x; ++rgb_data;
         _data = *rgb_data; if(_data != _rgb_) _B = _data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x; ++rgb_data;
         _data = *rgb_data; if(_data != _rgb_) _B = _data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x; ++rgb_data;
         _data = *rgb_data; if(_data != _rgb_) _B = _data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x; ++rgb_data;
         _data = *rgb_data; if(_data != _rgb_) _B = _data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x; ++rgb_data;
         _data = *rgb_data; if(_data != _rgb_) _B = _data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x; ++rgb_data;
         _data = *rgb_data; if(_data != _rgb_) _B = _data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x; ++rgb_data;
         _data = *rgb_data; if(_data != _rgb_) _B = _data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B; ++x; ++rgb_data;

         ++js1;

       }while(js1 != 4);

       x = x_;
       ++y;
       ++js2;

   }while(js2 != 32);

}









