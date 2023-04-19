void VGA_SK_0(unsigned char Y,unsigned char _Y,unsigned char DATA)
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



void VGA_SK_1(unsigned char y,unsigned char x,unsigned char _y,unsigned char _x,unsigned char data)
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


void VGA_kuang_0(unsigned char y,unsigned char x,unsigned char _y,unsigned char _x,unsigned char data)
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




void KC_LS1u_logo(unsigned char y,unsigned char x,unsigned char data1,unsigned char data2,unsigned char data3,unsigned char data4,unsigned char data5,unsigned char data6,unsigned char data7)
{


unsigned char x_;
unsigned char y_;

unsigned char b_x;
unsigned int b_y;
unsigned char bit_x;
unsigned char bit_data;

x_ = x;
y_ = y;
b_y = 0;





  do
  {
      b_x = 0;

      do
      {
          bit_data = KC_LS1u[(b_y << 2) + b_x];

          bit_x = 0;

          do
          {
               if(bit_data > 127) _B = data1,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B;
               ++x;

               bit_data <<= 1;
               ++bit_x;

          }while(bit_x != 8);

          ++b_x;

      }while(b_x != 4);

      x = x_;
      ++y;
      ++b_y;

  }while(b_y != 64);





y = y_;
x = x_ += 32;

  do
  {
      b_x = 0;

      do
      {
          bit_data = KC_LS1u[(b_y << 2) + b_x];

          bit_x = 0;

          do
          {
               if(bit_data > 127) _B = data2,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B;
               ++x;

               bit_data <<= 1;
               ++bit_x;

          }while(bit_x != 8);

          ++b_x;

      }while(b_x != 4);

      x = x_;
      ++y;
      ++b_y;

  }while(b_y != 64*2);




y = y_;
x = x_ += 32;

  do
  {
      b_x = 0;

      do
      {
          bit_data = KC_LS1u[(b_y << 2) + b_x];

          bit_x = 0;

          do
          {
               if(bit_data > 127) _B = data3,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B;
               ++x;

               bit_data <<= 1;
               ++bit_x;

          }while(bit_x != 8);

          ++b_x;

      }while(b_x != 4);

      x = x_;
      ++y;
      ++b_y;

  }while(b_y != 64*3);




y = y_;
x = x_ += 32;

  do
  {
      b_x = 0;

      do
      {
          bit_data = KC_LS1u[(b_y << 2) + b_x];

          bit_x = 0;

          do
          {
               if(bit_data > 127) _B = data4,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B;
               ++x;

               bit_data <<= 1;
               ++bit_x;

          }while(bit_x != 8);

          ++b_x;

      }while(b_x != 4);

      x = x_;
      ++y;
      ++b_y;

  }while(b_y != 64*4);



y = y_;
x = x_ += 32;

  do
  {
      b_x = 0;

      do
      {
          bit_data = KC_LS1u[(b_y << 2) + b_x];

          bit_x = 0;

          do
          {
               if(bit_data > 127) _B = data5,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B;
               ++x;

               bit_data <<= 1;
               ++bit_x;

          }while(bit_x != 8);

          ++b_x;

      }while(b_x != 4);

      x = x_;
      ++y;
      ++b_y;

  }while(b_y != 64*5);



y = y_;
x = x_ += 32;

  do
  {
      b_x = 0;

      do
      {
          bit_data = KC_LS1u[(b_y << 2) + b_x];

          bit_x = 0;

          do
          {
               if(bit_data > 127) _B = data6,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B;
               ++x;

               bit_data <<= 1;
               ++bit_x;

          }while(bit_x != 8);

          ++b_x;

      }while(b_x != 4);

      x = x_;
      ++y;
      ++b_y;

  }while(b_y != 64*6);


y = y_;
x = x_ += 32;

  do
  {
      b_x = 0;

      do
      {
          bit_data = KC_LS1u[(b_y << 2) + b_x];

          bit_x = 0;

          do
          {
               if(bit_data > 127) _B = data7,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B;
               ++x;

               bit_data <<= 1;
               ++bit_x;

          }while(bit_x != 8);

          ++b_x;

      }while(b_x != 4);

      x = x_;
      ++y;
      ++b_y;

  }while(b_y != 64*7);


}




void ET_logo(unsigned char y,unsigned char x,unsigned char data)
{

unsigned char x_;

unsigned char b_x;
unsigned int b_y;
unsigned char bit_x;
unsigned char bit_data;

x_ = x;
b_y = 0;


  do
  {
      b_x = 0;

      do
      {
          bit_data = ET[(b_y << 4) + b_x];

          bit_x = 0;

          do
          {
               if((bit_data & 0x80) == 0) _B = data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B;
               ++x;

               bit_data <<= 1;
               ++bit_x;

          }while(bit_x != 8);

          ++b_x;

      }while(b_x != 16);

      x = x_;
      ++y;
      ++b_y;

  }while(b_y != 128);



}



void VGA_ASCII(unsigned char y,unsigned char x,unsigned int ascii_data,unsigned char rgb_data)
{

unsigned char x_;

unsigned char b_x;
unsigned char bit_x;
unsigned char bit_data;

x_ = x;
ascii_data *= 12;
b_x = 0;

     do
     {

          bit_data = ASCII[ascii_data + b_x];

          bit_x = 0;

          do
          {
               if(bit_data > 127) _B = rgb_data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B;
               ++x;

               bit_data <<= 1;
               ++bit_x;

          }while(bit_x != 6);

          ++b_x;
          x = x_;
          ++y;

     }while(b_x != 12);


}



void VGA_B12_B12(unsigned char y,unsigned char x,unsigned char *B12_data,unsigned char rgb_data)
{

unsigned char x_;

unsigned char b_x;
unsigned char bit_x;
unsigned char bit_data;

x_ = x;
b_x = 0;

     do
     {

          bit_data = B12_data[b_x];

          bit_x = 0;

          do
          {
               if(bit_data > 127) _B = rgb_data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B;
               ++x;

               bit_data <<= 1;
               ++bit_x;

          }while(bit_x != 8);

          ++b_x;


          bit_data = B12_data[b_x];

          bit_x = 0;

          do
          {
               if(bit_data > 127) _B = rgb_data,_A = y,_A0 = x,_A2 = 0x80,_A1 = _A,_NOP,_RAM = _B;
               ++x;

               bit_data <<= 1;
               ++bit_x;

          }while(bit_x != 4);

          ++b_x;


          x = x_;
          ++y;

     }while(b_x != 24);

}



void VGA_SROMSJZZFWCX_logo(unsigned char y,unsigned char x,unsigned char rgb_data) //"SROM数据装载服务程序"
{




  VGA_ASCII(y,x,'S',rgb_data);            //"S"
  VGA_ASCII(y,x+=6,'R',rgb_data);         //"R"
  VGA_ASCII(y,x+=6,'O',rgb_data);         //"O"
  VGA_ASCII(y,x+=6,'M',rgb_data);         //"M"
  VGA_B12_B12(y,x+=6,shu,rgb_data);       //"数"
  VGA_B12_B12(y,x+=12,ju,rgb_data);       //"据"
  VGA_B12_B12(y,x+=12,zhuang,rgb_data);   //"装"
  VGA_B12_B12(y,x+=12,zai,rgb_data);      //"载"
  VGA_B12_B12(y,x+=12,fu,rgb_data);       //"服"
  VGA_B12_B12(y,x+=12,wu,rgb_data);       //"务"
  VGA_B12_B12(y,x+=12,cheng,rgb_data);    //"程"
  VGA_B12_B12(y,x+=12,xu,rgb_data);       //"序"


}



void VGA_spi_device_csh_logo(unsigned char y,unsigned char x,unsigned char device,unsigned char rgb_data) //"初始化SPI设备X内存卡..."
{

  VGA_B12_B12(y,x,chu,rgb_data);          //"初"
  VGA_B12_B12(y,x+=12,shi,rgb_data);      //"始"
  VGA_B12_B12(y,x+=12,hua,rgb_data);      //"化"
  VGA_ASCII(y,x+=12,'S',rgb_data);        //"S"
  VGA_ASCII(y,x+=6,'P',rgb_data);         //"P"
  VGA_ASCII(y,x+=6,'I',rgb_data);         //"I"
  VGA_B12_B12(y,x+=6,she,rgb_data);       //"设"
  VGA_B12_B12(y,x+=12,bei,rgb_data);      //"备"
  VGA_ASCII(y,x+=12,'0'+device,rgb_data); //设备号
  VGA_B12_B12(y,x+=6,nei,rgb_data);       //"内"
  VGA_B12_B12(y,x+=12,cun,rgb_data);      //"存"
  VGA_B12_B12(y,x+=12,ka,rgb_data);       //"卡"
  VGA_ASCII(y,x+=12,'.',rgb_data);        //"."
  VGA_ASCII(y,x+=6,'.',rgb_data);         //"."
  VGA_ASCII(y,x+=6,'.',rgb_data);         //"."

}

void VGA_cshwc_logo(unsigned char y,unsigned char x,unsigned char rgb_data) //"初始化完成"
{

  VGA_B12_B12(y,x,chu,rgb_data);          //"初"
  VGA_B12_B12(y,x+=12,shi,rgb_data);      //"始"
  VGA_B12_B12(y,x+=12,hua,rgb_data);      //"化"
  VGA_B12_B12(y,x+=12,wan,rgb_data);      //"完"
  VGA_B12_B12(y,x+=12,cheng_1,rgb_data);  //"成"

}

void VGA_cshsb_logo(unsigned char y,unsigned char x,unsigned char rgb_data) //"初始化失败"
{

  VGA_B12_B12(y,x,chu,rgb_data);          //"初"
  VGA_B12_B12(y,x+=12,shi,rgb_data);      //"始"
  VGA_B12_B12(y,x+=12,hua,rgb_data);      //"化"
  VGA_B12_B12(y,x+=12,shi_1,rgb_data);    //"失"
  VGA_B12_B12(y,x+=12,bai,rgb_data);      //"败"

}

void VGA_spi_device_boot_txt_logo(unsigned char y,unsigned char x,unsigned char device,unsigned char boot_txt,unsigned char rgb_data) //"搜索SPI设备X内存卡引导X文本..."
{

  VGA_B12_B12(y,x,sou,rgb_data);          //"搜"
  VGA_B12_B12(y,x+=12,suo,rgb_data);      //"索"
  VGA_ASCII(y,x+=12,'S',rgb_data);        //"S"
  VGA_ASCII(y,x+=6,'P',rgb_data);         //"P"
  VGA_ASCII(y,x+=6,'I',rgb_data);         //"I"
  VGA_B12_B12(y,x+=6,she,rgb_data);       //"设"
  VGA_B12_B12(y,x+=12,bei,rgb_data);      //"备"
  VGA_ASCII(y,x+=12,'0'+device,rgb_data); //设备号
  VGA_B12_B12(y,x+=6,nei,rgb_data);       //"内"
  VGA_B12_B12(y,x+=12,cun,rgb_data);      //"存"
  VGA_B12_B12(y,x+=12,ka,rgb_data);       //"卡"
  VGA_B12_B12(y,x+=12,yin,rgb_data);      //"引"
  VGA_B12_B12(y,x+=12,dao,rgb_data);      //"导"
  VGA_ASCII(y,x+=12,'0'+boot_txt,rgb_data); //引导文本号
  VGA_B12_B12(y,x+=6,wen,rgb_data);       //"文"
  VGA_B12_B12(y,x+=12,ben,rgb_data);      //"本"
  VGA_ASCII(y,x+=12,'.',rgb_data);        //"."
  VGA_ASCII(y,x+=6,'.',rgb_data);         //"."
  VGA_ASCII(y,x+=6,'.',rgb_data);         //"."

}

void VGA_myzdwb_logo(unsigned char y,unsigned char x,unsigned char rgb_data) //"没有找到文本"
{

  VGA_B12_B12(y,x,mei,rgb_data);          //"没"
  VGA_B12_B12(y,x+=12,you,rgb_data);      //"有"
  VGA_B12_B12(y,x+=12,zhao,rgb_data);     //"找"
  VGA_B12_B12(y,x+=12,dao_1,rgb_data);    //"到"
  VGA_B12_B12(y,x+=12,wen,rgb_data);      //"文"
  VGA_B12_B12(y,x+=12,ben,rgb_data);      //"本"

}

void VGA_zdwb_logo(unsigned char y,unsigned char x,unsigned char rgb_data) //"找到文本"
{

  VGA_B12_B12(y,x,zhao,rgb_data);         //"找"
  VGA_B12_B12(y,x+=12,dao_1,rgb_data);    //"到"
  VGA_B12_B12(y,x+=12,wen,rgb_data);      //"文"
  VGA_B12_B12(y,x+=12,ben,rgb_data);      //"本"

}

void VGA_wjljcw_logo(unsigned char y,unsigned char x,unsigned char rgb_data) //"文件路径错误"
{

  VGA_B12_B12(y,x,wen,rgb_data);         //"文"
  VGA_B12_B12(y,x+=12,jian,rgb_data);    //"件"
  VGA_B12_B12(y,x+=12,lu,rgb_data);      //"路"
  VGA_B12_B12(y,x+=12,jing,rgb_data);    //"径"
  VGA_B12_B12(y,x+=12,cuo,rgb_data);     //"错"
  VGA_B12_B12(y,x+=12,wu_1,rgb_data);    //"误"

}

void VGA_ssmbwj_logo(unsigned char y,unsigned char x,unsigned char device,unsigned int *lujing,unsigned char rgb_data) //"搜索目标文件(SPI设备X):文件路径"
{

  VGA_B12_B12(y,x,sou,rgb_data);         //"搜"
  VGA_B12_B12(y,x+=12,suo,rgb_data);     //"索"
  VGA_B12_B12(y,x+=12,mu,rgb_data);      //"目"
  VGA_B12_B12(y,x+=12,biao,rgb_data);    //"标"
  VGA_B12_B12(y,x+=12,wen,rgb_data);     //"文"
  VGA_B12_B12(y,x+=12,jian,rgb_data);    //"件"
  VGA_ASCII(y,x+=12,'(',rgb_data);       //"("
  VGA_ASCII(y,x+=6,'S',rgb_data);        //"S"
  VGA_ASCII(y,x+=6,'P',rgb_data);        //"P"
  VGA_ASCII(y,x+=6,'I',rgb_data);        //"I"
  VGA_B12_B12(y,x+=6,she,rgb_data);      //"设"
  VGA_B12_B12(y,x+=12,bei,rgb_data);     //"备"
  VGA_ASCII(y,x+=12,'0'+device,rgb_data);//设备号
  VGA_ASCII(y,x+=6,')',rgb_data);        //")"
  VGA_ASCII(y,x+=6,':',rgb_data);        //":"      138像素

  do
  {
     VGA_ASCII(y,x+=6,*lujing,rgb_data);
     ++lujing;

  }while(x+6 < 216 && *lujing != 0);

  if(*lujing != 0)
  {
     VGA_ASCII(y,x+=6,'.',rgb_data);         //"."
     VGA_ASCII(y,x+=6,'.',rgb_data);         //"."
     VGA_ASCII(y,x+=6,'.',rgb_data);         //"."
  }

}

void VGA_myzdmbwj_logo(unsigned char y,unsigned char x,unsigned char rgb_data) //"没有找到目标文件"
{

  VGA_B12_B12(y,x,mei,rgb_data);         //"没"
  VGA_B12_B12(y,x+=12,you,rgb_data);     //"有"
  VGA_B12_B12(y,x+=12,zhao,rgb_data);    //"找"
  VGA_B12_B12(y,x+=12,dao_1,rgb_data);   //"到"
  VGA_B12_B12(y,x+=12,mu,rgb_data);      //"目"
  VGA_B12_B12(y,x+=12,biao,rgb_data);    //"标"
  VGA_B12_B12(y,x+=12,wen,rgb_data);     //"文"
  VGA_B12_B12(y,x+=12,jian,rgb_data);    //"件"

}


void VGA_zdmbwj_logo(unsigned char y,unsigned char x,unsigned char rgb_data) //"找到目标文件"
{
  VGA_B12_B12(y,x,zhao,rgb_data);        //"找"
  VGA_B12_B12(y,x+=12,dao_1,rgb_data);   //"到"
  VGA_B12_B12(y,x+=12,mu,rgb_data);      //"目"
  VGA_B12_B12(y,x+=12,biao,rgb_data);    //"标"
  VGA_B12_B12(y,x+=12,wen,rgb_data);     //"文"
  VGA_B12_B12(y,x+=12,jian,rgb_data);    //"件"
}

void VGA_mbwjdx_logo(unsigned char y,unsigned char x,unsigned long int wjdx,unsigned char rgb_data) //"目标文件大小:x字节"
{

unsigned long int i;
unsigned char k = 0;


  VGA_B12_B12(y,x,mu,rgb_data);          //"目"
  VGA_B12_B12(y,x+=12,biao,rgb_data);    //"标"
  VGA_B12_B12(y,x+=12,wen,rgb_data);     //"文"
  VGA_B12_B12(y,x+=12,jian,rgb_data);    //"件"
  VGA_B12_B12(y,x+=12,da,rgb_data);      //"大"
  VGA_B12_B12(y,x+=12,xiao,rgb_data);    //"小"
  VGA_ASCII(y,x+=12,':',rgb_data);       //":"




  i = wjdx / 1000000000;
  if(i != 0) VGA_ASCII(y,x+=6,'0'+i,rgb_data),k = 1;  //"十亿位"

  wjdx %= 1000000000;
  i = wjdx / 100000000;
  if(k != 0 || i != 0) VGA_ASCII(y,x+=6,'0'+i,rgb_data),k = 1;  //"亿位"

  wjdx %= 100000000;
  i = wjdx / 10000000;
  if(k != 0 || i != 0) VGA_ASCII(y,x+=6,'0'+i,rgb_data),k = 1;  //"千万位"

  wjdx %= 10000000;
  i = wjdx / 1000000;
  if(k != 0 || i != 0) VGA_ASCII(y,x+=6,'0'+i,rgb_data),k = 1;  //"百万位"

  wjdx %= 1000000;
  i = wjdx / 100000;
  if(k != 0 || i != 0) VGA_ASCII(y,x+=6,'0'+i,rgb_data),k = 1;  //"十万位"

  wjdx %= 100000;
  i = wjdx / 10000;
  if(k != 0 || i != 0) VGA_ASCII(y,x+=6,'0'+i,rgb_data),k = 1;  //"万位"

  wjdx %= 10000;
  i = wjdx / 1000;
  if(k != 0 || i != 0) VGA_ASCII(y,x+=6,'0'+i,rgb_data),k = 1;  //"千位"

  wjdx %= 1000;
  i = wjdx / 100;
  if(k != 0 || i != 0) VGA_ASCII(y,x+=6,'0'+i,rgb_data),k = 1;  //"百位"

  wjdx %= 100;
  i = wjdx / 10;
  if(k != 0 || i != 0) VGA_ASCII(y,x+=6,'0'+i,rgb_data);  //"十位"


  VGA_ASCII(y,x+=6,'0' + wjdx % 10,rgb_data);  //"个位"



  VGA_B12_B12(y,x+=6,zi,rgb_data);     //"字"
  VGA_B12_B12(y,x+=12,jie,rgb_data);   //"节"


}

void VGA_mbwjdxcw_logo(unsigned char y,unsigned char x,unsigned char rgb_data) //"目标文件大小错误"
{

  VGA_B12_B12(y,x,mu,rgb_data);          //"目"
  VGA_B12_B12(y,x+=12,biao,rgb_data);    //"标"
  VGA_B12_B12(y,x+=12,wen,rgb_data);     //"文"
  VGA_B12_B12(y,x+=12,jian,rgb_data);    //"件"
  VGA_B12_B12(y,x+=12,da,rgb_data);      //"大"
  VGA_B12_B12(y,x+=12,xiao,rgb_data);    //"小"
  VGA_B12_B12(y,x+=12,cuo,rgb_data);     //"错"
  VGA_B12_B12(y,x+=12,wu_1,rgb_data);    //"误"

}

void VGA_sjzzz_logo(unsigned char y,unsigned char x,unsigned char rgb_data) //"数据装载中..."
{

  VGA_B12_B12(y,x,shu,rgb_data);          //"数"
  VGA_B12_B12(y,x+=12,ju,rgb_data);       //"据"
  VGA_B12_B12(y,x+=12,zhuang,rgb_data);   //"装"
  VGA_B12_B12(y,x+=12,zai,rgb_data);      //"载"
  VGA_B12_B12(y,x+=12,zhong,rgb_data);    //"中"
  VGA_ASCII(y,x+=12,'.',rgb_data);        //"."
  VGA_ASCII(y,x+=6,'.',rgb_data);         //"."
  VGA_ASCII(y,x+=6,'.',rgb_data);         //"."

}

void VGA_qdcx_logo(unsigned char y,unsigned char x,unsigned char rgb_data) //"启动程序"
{
  VGA_B12_B12(y,x,qi,rgb_data);           //"启"
  VGA_B12_B12(y,x+=12,dong,rgb_data);     //"动"
  VGA_B12_B12(y,x+=12,cheng,rgb_data);    //"程"
  VGA_B12_B12(y,x+=12,xu,rgb_data);       //"序"
}

void VGA_sromnccw_logo(unsigned char y,unsigned char x,unsigned char rgb_data) //"SROM内存错误"
{
  VGA_ASCII(y,x,'S',rgb_data);            //"S"
  VGA_ASCII(y,x+=6,'R',rgb_data);         //"R"
  VGA_ASCII(y,x+=6,'O',rgb_data);         //"O"
  VGA_ASCII(y,x+=6,'M',rgb_data);         //"M"
  VGA_B12_B12(y,x+=6,nei,rgb_data);       //"内"
  VGA_B12_B12(y,x+=12,cun,rgb_data);      //"存"
  VGA_B12_B12(y,x+=12,cuo,rgb_data);      //"错"
  VGA_B12_B12(y,x+=12,wu_1,rgb_data);     //"误"
}

void VGA_sromncyc_logo(unsigned char y,unsigned char x,unsigned char rgb_data) //"SROM内存溢出"
{
  VGA_ASCII(y,x,'S',rgb_data);            //"S"
  VGA_ASCII(y,x+=6,'R',rgb_data);         //"R"
  VGA_ASCII(y,x+=6,'O',rgb_data);         //"O"
  VGA_ASCII(y,x+=6,'M',rgb_data);         //"M"
  VGA_B12_B12(y,x+=6,nei,rgb_data);       //"内"
  VGA_B12_B12(y,x+=12,cun,rgb_data);      //"存"
  VGA_B12_B12(y,x+=12,yi,rgb_data);       //"溢"
  VGA_B12_B12(y,x+=12,chu_1,rgb_data);    //"出"
}

void VGA_wjcw_logo(unsigned char y,unsigned char x,unsigned char rgb_data) //"文件错误"
{
  VGA_B12_B12(y,x,wen,rgb_data);          //"文"
  VGA_B12_B12(y,x+=12,jian,rgb_data);     //"件"
  VGA_B12_B12(y,x+=12,cuo,rgb_data);      //"错"
  VGA_B12_B12(y,x+=12,wu_1,rgb_data);     //"误"
}

void VGA_spisbcw_logo(unsigned char y,unsigned char x,unsigned char rgb_data) //"SPI设备错误"
{
  VGA_ASCII(y,x,'S',rgb_data);            //"S"
  VGA_ASCII(y,x+=6,'P',rgb_data);         //"P"
  VGA_ASCII(y,x+=6,'I',rgb_data);         //"I"
  VGA_B12_B12(y,x+=6,she,rgb_data);       //"设"
  VGA_B12_B12(y,x+=12,bei,rgb_data);      //"备"
  VGA_B12_B12(y,x+=12,cuo,rgb_data);      //"错"
  VGA_B12_B12(y,x+=12,wu_1,rgb_data);     //"误"
}


void VGA_ncyc_logo(unsigned char y,unsigned char x,unsigned long int ncdx,unsigned char rgb_data) //"SROM内存大小:X字节"
{

unsigned long int i;
unsigned char k = 0;

  VGA_ASCII(y,x,'S',rgb_data);           //"S"
  VGA_ASCII(y,x+=6,'R',rgb_data);        //"R"
  VGA_ASCII(y,x+=6,'O',rgb_data);        //"O"
  VGA_ASCII(y,x+=6,'M',rgb_data);        //"M"
  VGA_B12_B12(y,x+=6,nei,rgb_data);      //"内"
  VGA_B12_B12(y,x+=12,cun,rgb_data);     //"存"
  VGA_B12_B12(y,x+=12,da,rgb_data);      //"大"
  VGA_B12_B12(y,x+=12,xiao,rgb_data);    //"小"
  VGA_ASCII(y,x+=12,':',rgb_data);       //":"



  i = ncdx / 1000000;
  if(i != 0) VGA_ASCII(y,x+=6,'0'+i,rgb_data),k = 1;  //"百万位"

  ncdx %= 1000000;
  i = ncdx / 100000;
  if(k != 0 || i != 0) VGA_ASCII(y,x+=6,'0'+i,rgb_data),k = 1;  //"十万位"

  ncdx %= 100000;
  i = ncdx / 10000;
  if(k != 0 || i != 0) VGA_ASCII(y,x+=6,'0'+i,rgb_data),k = 1;  //"万位"

  ncdx %= 10000;
  i = ncdx / 1000;
  if(k != 0 || i != 0) VGA_ASCII(y,x+=6,'0'+i,rgb_data),k = 1;  //"千位"

  ncdx %= 1000;
  i = ncdx / 100;
  if(k != 0 || i != 0) VGA_ASCII(y,x+=6,'0'+i,rgb_data),k = 1;  //"百位"

  ncdx %= 100;
  i = ncdx / 10;
  if(k != 0 || i != 0) VGA_ASCII(y,x+=6,'0'+i,rgb_data);  //"十位"


  VGA_ASCII(y,x+=6,'0' + ncdx % 10,rgb_data);  //"个位"




  VGA_B12_B12(y,x+=6,zi,rgb_data);     //"字"
  VGA_B12_B12(y,x+=12,jie,rgb_data);   //"节"


}


/*
void VGA_KB_S_logo(unsigned char y,unsigned char x,unsigned char KB,unsigned char rgb_data) //"?KB/S"
{

unsigned char i;
unsigned char k = 0;


  i = KB / 100;
  if(i != 0) VGA_ASCII(y,x,'0'+i,rgb_data),k = 1;  //"百位"

  KB %= 100;
  i = KB / 10;
  if(k != 0 || i != 0) VGA_ASCII(y,x+=6,'0'+i,rgb_data);  //"十位"


  VGA_ASCII(y,x+=6,'0' + KB % 10,rgb_data);  //"个位"


  VGA_ASCII(y,x+=6,'K',rgb_data);  //"K"
  VGA_ASCII(y,x+=6,'B',rgb_data);  //"B"
  VGA_ASCII(y,x+=6,'/',rgb_data);  //"/"
  VGA_ASCII(y,x+=6,'S',rgb_data);  //"S"

}
*/


void VGA_bfb_logo(unsigned char y,unsigned char x,unsigned char bfb,unsigned char rgb_data) //"?%"
{

unsigned char i;
unsigned char k = 0;


  i = bfb / 100;
  if(i != 0) VGA_ASCII(y,x,'0'+i,rgb_data),k = 1;  //"百位"

  bfb %= 100;
  i = bfb / 10;
  x+=6;
  if(k != 0 || i != 0) VGA_ASCII(y,x,'0'+i,rgb_data);  //"十位"


  VGA_ASCII(y,x+=6,'0' + bfb % 10,rgb_data);  //"个位"


  VGA_ASCII(y,x+=6,'%',rgb_data);  //"%"


}


void VGA_wbsy() //文本框内容上移   打印字符的Y坐标超过166时,调用,清出一行,然后再打印
{

unsigned char y = 36;
unsigned char x;

  do
  {
      x = 17;

      do
      {
         _A = y + 13;
         _A0 = x;
         _A2 = 0x80;
         _A1 = _A;
         _NOP;
         _B = _RAM;

         _A = y;
         _A0 = x;
         _A2 = 0x80;
         _A1 = _A;
         _NOP;
         _RAM = _B;
         ++x;

      }while(x != 239);

      ++y;

  }while(y != 165);

  VGA_SK_1(166,17,12,222,0); //擦除166Y坐标这行文本

}