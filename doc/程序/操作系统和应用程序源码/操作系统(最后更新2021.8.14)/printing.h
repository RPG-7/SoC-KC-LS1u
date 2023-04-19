void print_ASCII(unsigned char y,unsigned char x,unsigned int ascii_data,unsigned char rgb_data)
{
   VGA_ASCII(y,x,ascii_data,rgb_data);
}

void print_GB2312(unsigned char y,unsigned char x,unsigned char *GB2312_data,unsigned char rgb_data)
{
   VGA_GB2312(y,x,GB2312_data,rgb_data);
}


void printx(unsigned char y,unsigned char x,unsigned char *_char_,unsigned char rgb_data) //打印字符串(没有换行),yx为起始坐标,_char_为字符串,rgb_data像素数据
{

unsigned char js1;
unsigned int js2;

    while((js1 = *_char_) != 0)
    {
        if(js1 > 127) //2个字节
        {
            print_GB2312(y,x,_char_,rgb_data);
            _char_+=2;
            x+=12;
        }
        else //1个字节
        {
            ++_char_;
            print_ASCII(y,x,js1,rgb_data);
            x+=6;
        }
    }

}