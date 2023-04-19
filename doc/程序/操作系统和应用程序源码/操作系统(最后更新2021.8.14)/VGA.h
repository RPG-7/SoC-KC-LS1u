void VGA_VRAM_LD() //��дVRAM֮ǰҪ���ô˺���
{

/***************************** ����VRAM����ʱ�� = VGA_CL1 * (65536 / CPU��Ƶ) = 16.384���� *****************************/

#define VGA_CL1 4

/***********************************************************************************************************************/

   while((VGA_CT2_ < 256 - VGA_CL1 && (CT2 < VGA_CT2_ || CT2 >= VGA_CT2_ + VGA_CL1)   ||   VGA_CT2_ > 255 - VGA_CL1 && CT2 < VGA_CT2_ && CT2 >= VGA_CT2_ + VGA_CL1) == 0); //�ϴμ�¼��Ӳ�����������ݺ�����Ӳ�������������ݽ��бȽ�,�ﵽ����ʱ����
   CTVGA_C &= 0xfe; //�������VRAM
   while((CTVGA_C & 0x80) == 0x80); //VRAM���Է��ʵ�ʱ������


}


void VGA_VRAM_UP() //д���Դ�����ݸ��µ���Ļ,VRAM��д��ɺ�Ҫ���ô˺���
{
   CTVGA_C |= 0x01; //����VRAM��ʾ
   VGA_CT2_ = CT2;  //��¼��ǰӲ������������
}



void VGA_SK0(unsigned char Y,unsigned char _Y,unsigned char DATA) //��ɫ��0,YΪ��ʼ����,_YΪ��������,X����256ȫ��д����,12MHZ��CPUƵ����ÿ�����ִ��Լ40��
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
void VGA_SK1(unsigned char y,unsigned char x,unsigned char _y,unsigned char _x,unsigned char data) //��ɫ��1,yxΪ��ʼ����,_y_xΪ����,data��������
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

void VGA_SK1(unsigned char y,unsigned char x,unsigned char _y,unsigned char _x,unsigned char data) //��ɫ��1,yxΪ��ʼ����,_y_xΪ����,data��������
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

       while(js1 != 0) //x����д16�����ص�
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


void VGA_ZX(unsigned char y,unsigned char x,unsigned char _y,unsigned char _x,unsigned char data) //��ֱ��,yxΪ��ʼ����,_y_xΪ��������,data��������
{

unsigned char _y_; //Y�����ֵ
unsigned char _x_; //X�����ֵ
unsigned char y_; //Y������ʼ
unsigned char x_; //X������ʼ
unsigned char js0;

unsigned int js1;
unsigned int js2;


    if(_x < x) //X���귴����
    {
        js0 = x;
        x = _x;
        _x = js0;

        js0 = y;
        y = _y;
        _y = js0;
    }

    if(_y < y) //Y���귴����
    {
       --_y;
       _y_ = y - _y;
       js0 = -1;
    }
    else //Y����������
    {
       ++_y;
       _y_ = _y - y;
       js0 = 1;
    }

    ++_x;
    _x_ = _x - x;


    if(_y_ == _x_) //�����ζԽ�
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
    else if(_y_ > _x_) //���ĳ����ζԽ�
    {

        js1 = _x_;
        js1 <<= 8;
        js1 = js1 / _y_; //�����������ֵ
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
    else //��ĳ����ζԽ�
    {

        js1 = _y_;
        js1 <<= 8;
        js1 = js1 / _x_; //�����������ֵ
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


void VGA_kuang0(unsigned char y,unsigned char x,unsigned char _y,unsigned char _x,unsigned char data) //����0,yxΪ��ʼ����,_y_xΪ����+1,data��������
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


void VGA_ASCII(unsigned char y,unsigned char x,unsigned int ascii_data,unsigned char rgb_data) //��ʾĬ�ϴ�СASCII��,yxΪ��ʼ����,ascii_dataΪASCIIֵ,rgb_data��������
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

void VGA_GB2312(unsigned char y,unsigned char x,unsigned char *GB2312_data,unsigned char rgb_data) //��ʾĬ�ϴ�СGB2312��,yxΪ��ʼ����,GB2312_dataΪGB2312�ַ���,rgb_data��������
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
  ZADDR = (DH - 0xa1) * 94 + (DL - 0xa1); //���GB2312�ַ���ַ
  ZADDR *= 24; //һ���ַ�ռ�ֿ�24���ֽ� ��24���GB2312�ֿ��ַ

  _addr = GB2312 + ZADDR;


  b_x = 0;

  do
  {

     D1 = *_addr;  //������8λ�����ֽ�
     ++_addr;
     D2 = *_addr;  //������8λ�����ֽ�
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


     x = x_; //x����ָ����
     ++y; //y��ַ��1
     ++b_x;

  }while(b_x != 12);


}




void VGA_32bit_DP(unsigned char y,unsigned char x,unsigned long int XX,unsigned char rgb_data) //32λ�޷�����תʮ������ʾ,yxΪ��ʼ����,XXΪ32λ��,rgb_data��������
{

unsigned char i;
unsigned char k = 0;


  i = XX / 1000000000;
  if(i != 0) VGA_ASCII(y,x,'0'+i,rgb_data),x+=6,k = 1;  //"ʮ��λ"

  XX %= 1000000000;
  i = XX / 100000000;
  if(k != 0 || i != 0) VGA_ASCII(y,x,'0'+i,rgb_data),x+=6,k = 1;  //"��λ"

  XX %= 100000000;
  i = XX / 10000000;
  if(k != 0 || i != 0) VGA_ASCII(y,x,'0'+i,rgb_data),x+=6,k = 1;  //"ǧ��λ"

  XX %= 10000000;
  i = XX / 1000000;
  if(k != 0 || i != 0) VGA_ASCII(y,x,'0'+i,rgb_data),x+=6,k = 1;  //"����λ"

  XX %= 1000000;
  i = XX / 100000;
  if(k != 0 || i != 0) VGA_ASCII(y,x,'0'+i,rgb_data),x+=6,k = 1;  //"ʮ��λ"

  XX %= 100000;
  i = XX / 10000;
  if(k != 0 || i != 0) VGA_ASCII(y,x,'0'+i,rgb_data),x+=6,k = 1;  //"��λ"

  XX %= 10000;
  i = XX / 1000;
  if(k != 0 || i != 0) VGA_ASCII(y,x,'0'+i,rgb_data),x+=6,k = 1;  //"ǧλ"

  XX %= 1000;
  i = XX / 100;
  if(k != 0 || i != 0) VGA_ASCII(y,x,'0'+i,rgb_data),x+=6,k = 1;  //"��λ"

  XX %= 100;
  i = XX / 10;
  if(k != 0 || i != 0) VGA_ASCII(y,x,'0'+i,rgb_data),x+=6;  //"ʮλ"


  VGA_ASCII(y,x,'0' + XX % 10,rgb_data);  //"��λ"


}



void VGA_CS_RGB256() //������ʾ256����ɫ
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
   VGA_SK1(y,x,_y - 1,1,219); //�ع���
   VGA_SK1(y,x,1,_x - 1,219); //�ع��
   VGA_SK1(y + _y - 1,x + 1,1,_x - 2,73); //��Ӱ��
   VGA_SK1(y + 1,x + _x - 1,_y - 1,1,73); //��Ӱ��
   VGA_SK1(y + 1,x + 1,_y - 2,_x - 2,114); //ƽ̨
}

void VGA_KEY1_ON(unsigned char y,unsigned char x,unsigned char _y,unsigned char _x)
{
   VGA_SK1(y,x,_y - 1,1,73); //��Ӱ��
   VGA_SK1(y,x,1,_x - 1,73); //��Ӱ��
   VGA_SK1(y + _y - 1,x + 1,1,_x - 2,219); //�ع���
   VGA_SK1(y + 1,x + _x - 1,_y - 1,1,219); //�ع��
   VGA_SK1(y + 1,x + 1,_y - 2,_x - 2,114); //ƽ̨
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









