/*---------------------------------------------------------- GUI显示接口 ------------------------------------------------------*/

void GUI_VRAM_LD()
{
   VGA_VRAM_LD();
}

void GUI_VRAM_UP()
{
   VGA_VRAM_UP();
}

void GUI_SK0(unsigned char Y,unsigned char _Y,unsigned char DATA)
{
   VGA_SK0(Y,_Y,DATA);
}

void GUI_SK1(unsigned char y,unsigned char x,unsigned char _y,unsigned char _x,unsigned char data)
{
   VGA_SK1(y,x,_y,_x,data);
}

void GUI_kuang0(unsigned char y,unsigned char x,unsigned char _y,unsigned char _x,unsigned char data)
{
   VGA_kuang0(y,x,_y,_x,data);
}

void GUI_ZX(unsigned char y,unsigned char x,unsigned char _y,unsigned char _x,unsigned char data)
{
   VGA_ZX(y,x,_y,_x,data);
}

void GUI_16_16_XS(unsigned char y,unsigned char x,unsigned char _rgb_,unsigned char *rgb_data)
{
   VGA_16_16_XS(y,x,_rgb_,rgb_data);
}

void GUI_16_16_BC(unsigned char y,unsigned char x,unsigned char _rgb_,unsigned char *rgb_data,unsigned char *_rgb_buf)
{
   VGA_16_16_BC(y,x,_rgb_,rgb_data,_rgb_buf);
}

void GUI_16_16_HY(unsigned char y,unsigned char x,unsigned char _rgb_,unsigned char *rgb_data,unsigned char *_rgb_buf)
{
   VGA_16_16_HY(y,x,_rgb_,rgb_data,_rgb_buf);
}

void GUI_32_32_XS(unsigned char y,unsigned char x,unsigned char _rgb_,unsigned char *rgb_data)
{
   VGA_32_32_XS(y,x,_rgb_,rgb_data);
}


/*-----------------------------------------------------------------------------------------------------------------------------*/



/*---------------------------------------------------------- GUI鼠标接口 ------------------------------------------------------*/

unsigned char GUI_SBZBPD(unsigned char Y_,unsigned char _Y,unsigned char X_,unsigned char _X) //鼠标坐标判断,参数分别为Y起始,Y结束,X起始,X结束,鼠标坐标落在范围内返回1,否则返回0
{

unsigned char YYY;
unsigned char XXX;

   if(Y_ > _Y) YYY = SB_Y >= Y_ || SB_Y <= _Y; else YYY = SB_Y >= Y_ && SB_Y <= _Y;
   if(X_ > _X) XXX = SB_X >= X_ || SB_X <= _X; else XXX = SB_X >= X_ && SB_X <= _X;

   return YYY && XXX;
}

unsigned char GUI_SB_L_KEY() //鼠标左键按下返回1,否则返回0
{
   return SB_KEY & 0x01 ? 1:0;
}

unsigned char GUI_SB_R_KEY() //鼠标右键按下返回1,否则返回0
{
   return SB_KEY & 0x02 ? 1:0;
}

unsigned char GUI_SB_M_KEY() //鼠标中键按下返回1,否则返回0
{
   return SB_KEY & 0x04 ? 1:0;
}

unsigned char GUI_SB_GET_Y() //取鼠标Y坐标
{
   return SB_Y;
}

unsigned char GUI_SB_GET_X() //取鼠标X坐标
{
   return SB_X;
}

unsigned char GUI_SB_GET_Z() //取鼠标滚轮
{
   return SB_Z;
}

unsigned char GUI_SB_GET_AS_Y() //取鼠标Y坐标增减量
{
   return SB_Y - GUI_SB_Y_;
}

unsigned char GUI_SB_GET_AS_X() //取鼠标X坐标增减量
{
   return SB_X - GUI_SB_X_;
}

unsigned char GUI_SB_GET_AS_Z() //取鼠标滚轮增减量
{
   return SB_Z - GUI_SB_Z_;
}

void GUI_WR_SB_Y(unsigned char _data) //修改鼠标Y坐标
{
   SB_Y = _data;
}

void GUI_WR_SB_X(unsigned char _data) //修改鼠标X坐标
{
   SB_X = _data;
}

void GUI_WR_SB_Z(unsigned char _data) //修改鼠标滚轮
{
   SB_Z = _data;
}


/*-----------------------------------------------------------------------------------------------------------------------------*/




void GUI_KEY0(unsigned char y,unsigned char x,unsigned char _y,unsigned char _x,unsigned char K) //按键0,yx为起始坐标,_y_x为长度,K为0是弹起,否则为按下
{

unsigned char x1;
unsigned char x2;

   if(K == 0) x1 = 219,x2 = 73; else x1 = 73,x2 = 219;

   GUI_SK1(y,x,_y - 1,1,x1); //曝光竖
   GUI_SK1(y,x,1,_x - 1,x1); //曝光横
   GUI_SK1(y + _y - 1,x + 1,1,_x - 2,x2); //阴影横
   GUI_SK1(y + 1,x + _x - 1,_y - 1,1,x2); //阴影竖
   GUI_SK1(y + 1,x + 1,_y - 2,_x - 2,114); //平台
}

void GUI_XXX_KEY(unsigned char y,unsigned char x,unsigned char XZ,unsigned char K) //关闭按钮,yx为起始坐标,XZ为0显示被选择,否则为不被选择,K不为0为按下
{

unsigned char x1;
unsigned char x2;

     GUI_kuang0(y,x,8,8,5);
     if(XZ == 0) x1 = 0x80;else x1 = 0x40;
     GUI_SK1(y+1,x+1,7,7,x1);
     if(K != 0) ++y;
     for(x2 = 0;x2 != 5;++x2) GUI_SK1(y+x2+2,x+x2+2,1,1,255);
     for(x2 = 0,x1 = 0;x2 != 5;++x2,--x1) GUI_SK1(y+x1+6,x+x2+2,1,1,255);

}

void GUI_ZXH_KEY(unsigned char y,unsigned char x,unsigned char XZ,unsigned char K) //最小化按钮,yx为起始坐标,XZ为0显示被选择,否则为不被选择,K不为0为按下
{

unsigned char x1;

     GUI_kuang0(y,x,8,8,9);
     if(XZ == 0) x1 = 0x10;else x1 = 0x08;
     GUI_SK1(y+1,x+1,7,7,x1);
     if(K != 0) ++y;
     GUI_SK1(y+5,x+2,1,5,255);

}

void GUI_SC_KEY(unsigned char y,unsigned char x,unsigned char XZ,unsigned char K) //上层按钮,yx为起始坐标,XZ为0显示被选择,否则为不被选择,K不为0为按下
{

unsigned char x1;

     GUI_kuang0(y,x,8,8,10);
     if(XZ == 0) x1 = 0x10;else x1 = 0x08;
     GUI_SK1(y+1,x+1,7,7,x1);
     if(K != 0) ++y;
     GUI_ZX(y+4,x+2,y+2,x+4,255);
     GUI_ZX(y+5,x+3,y+6,x+4,255);
     GUI_SK1(y+4,x+4,1,3,255);

}

void GUI_SY_KEY(unsigned char y,unsigned char x,unsigned char XZ,unsigned char K) //上移按钮,yx为起始坐标,XZ为0显示被选择,否则为不被选择,K不为0为按下
{

unsigned char x1;

     GUI_kuang0(y,x,6,8,9);
     if(XZ != 0) x1 = 0x10;else x1 = 0x08;
     GUI_SK1(y+1,x+1,5,7,x1);
     if(K != 0) --y;
     GUI_ZX(y+4,x+2,y+2,x+4,255);
     GUI_ZX(y+3,x+5,y+4,x+6,255);

}

void GUI_XY_KEY(unsigned char y,unsigned char x,unsigned char XZ,unsigned char K) //下移按钮,yx为起始坐标,XZ为0显示被选择,否则为不被选择,K不为0为按下
{

unsigned char x1;

     GUI_kuang0(y,x,6,8,9);
     if(XZ != 0) x1 = 0x10;else x1 = 0x08;
     GUI_SK1(y+1,x+1,5,7,x1);
     if(K != 0) ++y;
     GUI_ZX(y+2,x+2,y+4,x+4,255);
     GUI_ZX(y+3,x+5,y+2,x+6,255);

}



void GUI_ZMSY_KEY(unsigned char y,unsigned char x,unsigned char XZ,unsigned char K) //桌面上移按钮,yx为起始坐标,XZ不为0显示被选择,否则为不被选择,K不为0为按下
{

     if(XZ != 0)
     {
         GUI_SK0(y,y+7,0x97);
         if(K != 0) --y;
         GUI_ZX(y+4,x+125,y+2,x+127,255);
         GUI_ZX(y+3,x+128,y+4,x+129,255);
     }
     else
     {
         GUI_SK0(y,y+7,0x00);
     }

}


void GUI_ZMXY_KEY(unsigned char y,unsigned char x,unsigned char XZ,unsigned char K) //桌面下移按钮,yx为起始坐标,XZ不为0显示被选择,否则为不被选择,K不为0为按下
{

     if(XZ != 0)
     {
         GUI_SK0(y,y+7,0x97);
         if(K != 0) ++y;
         GUI_ZX(y+2,x+125,y+4,x+127,255);
         GUI_ZX(y+3,x+128,y+2,x+129,255);
     }
     else
     {
         GUI_SK0(y,y+7,0x00);
     }

}




/*
void GUI_ZMSY_KEY(unsigned char y,unsigned char x,unsigned char XZ,unsigned char K) //桌面上移按钮,yx为起始坐标,XZ不为0显示被选择,否则为不被选择,K不为0为按下
{

unsigned char x1;

     if(XZ != 0) x1 = 0x97;else x1 = 0x57;
     GUI_SK0(y,y+7,x1);
     if(K != 0) --y;
     GUI_ZX(y+4,x+125,y+2,x+127,255);
     GUI_ZX(y+3,x+128,y+4,x+129,255);


}


void GUI_ZMXY_KEY(unsigned char y,unsigned char x,unsigned char XZ,unsigned char K) //桌面下移按钮,yx为起始坐标,XZ不为0显示被选择,否则为不被选择,K不为0为按下
{

unsigned char x1;

     if(XZ != 0) x1 = 0x97;else x1 = 0x57;
     GUI_SK0(y,y+7,x1);
     if(K != 0) ++y;
     GUI_ZX(y+2,x+125,y+4,x+127,255);
     GUI_ZX(y+3,x+128,y+2,x+129,255);

}
*/





unsigned char GUI_11B_chars(unsigned char *WJDATA_32B,unsigned char *DWJM) //文件32字节数据提取前11字节转带'.'短文件名字符串,返回值为字符串字节长度
{

unsigned char smzz;
unsigned char js1;
unsigned char js2;
unsigned char js3;
unsigned char js4;

    smzz = 0;
    js2 = 0;
    if(((js4 = WJDATA_32B[0x0c]) & 0x08) != 0) js3 = 32;else js3 = 0;

    do
    {

        if((js1 = WJDATA_32B[smzz]) != 0x20)
        {
           if(smzz == 8) //为后缀名起始,加入'.'
           {
              *DWJM = '.';
              ++DWJM;
              ++js2;
              if((js4 & 0x10) != 0) js3 = 32;else js3 = 0;
           }

           if(js1 > 64 && js1 < 91) //是大写字母
           {
               *DWJM = js1 + js3; //大小写转换
           }
           else
           {
               *DWJM = js1;
           }

           ++DWJM;
           ++js2;
        }

        ++smzz;

    }while(smzz != 11);

    *DWJM = 0;

    return js2;

}

unsigned int GUI_unicode_str(unsigned int *CWJM,unsigned char *str) //unicode码转文件名字符串,返回值为字符串字节长度
{

unsigned int js1;
unsigned int js2;

    js1 = 0;

    while((js2 = CWJM[js1]) != 0)
    {

        if(js2 < 128) //单字节ASCII
        {
            *str = js2;
            ++str;
        }
        else
        {
            *str = ''; //ASCII-127号字符
            ++str;
        }

        ++js1;
    }

    *str = 0;

    return js1;

}



void GUI_UPBZ(unsigned char CKLX,unsigned char CKH,unsigned char UP_K,unsigned char RWL_K) //置更新标志,刷新窗口内容,参数分别为窗口类型,窗口号,窗口更新标志,任务栏跳过控制(为0跳过)
{

unsigned char smzz;
unsigned char js1;

    smzz = 0;
    js1 = 0;

    while(GUI_CKXH[smzz] != 0)
    {

        if(js1 == 0)
        {
            if(CKLX == GUI_CKLX[smzz] && CKH == GUI_CKH[smzz]) //找到窗口
            {
                js1 = 1;
                GUI_CKUP[smzz] |= UP_K; //置更新标志
            }
        }
        else
        {
            if(GUI_CKLX[smzz] != 254 || RWL_K != 0) GUI_CKUP[smzz] = 1; //置更新标志
        }

        ++smzz;

    }


}

unsigned char GUI_GET_MAX_CKXH() //取GUI表最大窗口序号
{
unsigned char smzz = 0;
unsigned char js1 = 0;
unsigned char js2;

   while((js2 = GUI_CKXH[smzz]) != 0)
   {
      if(js2 > js1) js1 = js2;
      ++smzz;
   }

   return js1;
}

unsigned char GUI_GET_CK_CENGX(unsigned char CKLX,unsigned char CKH) //取GUI表里窗口所在层数,0为顶层,为255没有找到窗口
{

unsigned char smzz = 0;
unsigned char CKXH_;
unsigned char js1;


    while((CKXH_ = GUI_CKXH[smzz]) != 0)
    {
        if(GUI_CKLX[smzz] == CKLX && GUI_CKH[smzz] == CKH) break; //窗口类型窗口号相同跳出
        ++smzz;
    }

    if(CKXH_ != 0) //窗口类型窗口号相同
    {
        ++smzz;
        js1 = 0;
        while(GUI_CKXH[smzz] != 2) //扫描任务栏
        {
           if(GUI_CKXS[smzz] != 0) ++js1;
           ++smzz;
        }
        return js1;

    }
    return 255;

}

unsigned long int GUI_GET_CKLX_CKH_CKXS_CKUP(unsigned char CKXH) //给窗口序号,取窗口类型,窗口号,窗口最大最小化标志,窗口更新标志
{

unsigned char smzz = 0;
unsigned long int js1;

   while(GUI_CKXH[smzz] != CKXH) ++smzz;

   js1 = GUI_CKLX[smzz];
   js1 <<= 8;
   js1 |= GUI_CKH[smzz];
   js1 <<= 8;
   js1 |= GUI_CKXS[smzz];
   js1 <<= 8;
   js1 |= GUI_CKUP[smzz];

   return js1;

}

unsigned int GUI_GET_CKXS_CKUP(unsigned char CKLX,unsigned char CKH) //给窗口类型和窗口号,取窗口最大最小化标志,窗口更新标志,返回值为0xffff没有找到窗口
{

unsigned char smzz = 0;
unsigned char CKXH_;
unsigned int js1;


    while((CKXH_ = GUI_CKXH[smzz]) != 0)
    {
        if(GUI_CKLX[smzz] == CKLX && GUI_CKH[smzz] == CKH) break; //窗口类型窗口号相同跳出
        ++smzz;
    }

    if(CKXH_ != 0) //窗口类型窗口号相同
    {

        js1 = GUI_CKXS[smzz];
        js1 <<= 8;
        js1 |= GUI_CKUP[smzz];

        return js1;

    }

    return 0xffff;

}

void GUI_CJCK(unsigned char CKLX,unsigned char CKH) //创建窗口
{

unsigned char smzz = 0;
unsigned char CKXH;


    while(smzz != 127 && GUI_CKXH[smzz] != 2) ++smzz; //扫描任务栏

    if(smzz != 127) //找到任务栏,进入创建新窗口标志
    {
       GUI_CKXH[smzz+2] = GUI_CKXH[smzz+1]; //菜单GUI表拷到下一地址
       GUI_CKLX[smzz+2] = GUI_CKLX[smzz+1];
       GUI_CKH[smzz+2]  = GUI_CKH[smzz+1];
       GUI_CKXS[smzz+2] = GUI_CKXS[smzz+1];
       GUI_CKUP[smzz+2] = 1;

       GUI_CKXH[smzz+1] = GUI_CKXH[smzz]; //任务栏GUI表拷到下一地址
       GUI_CKLX[smzz+1] = GUI_CKLX[smzz];
       GUI_CKH[smzz+1]  = GUI_CKH[smzz];
       GUI_CKXS[smzz+1] = GUI_CKXS[smzz];
       GUI_CKUP[smzz+1] = 1;

       if((CKXH = GUI_GET_MAX_CKXH()) > 2) ++CKXH;else CKXH = 4; //计算新建窗口的序号

       GUI_CKXH[smzz] = CKXH;    //GUI表此位置新建窗口
       GUI_CKLX[smzz] = CKLX;
       GUI_CKH[smzz]  = CKH;
       GUI_CKXS[smzz] = 1;
       GUI_CKUP[smzz] = 1;
    }

}

void GUI_ZXHCK(unsigned char CKLX,unsigned char CKH) //最小化窗口
{

unsigned char smzz = 0;
unsigned char CKXH_;


    while((CKXH_ = GUI_CKXH[smzz]) != 0)
    {
        if(GUI_CKLX[smzz] == CKLX && GUI_CKH[smzz] == CKH) break; //窗口类型窗口号相同跳出
        ++smzz;
    }


    if(CKXH_ != 0) //窗口类型窗口号相同
    {
        GUI_CKXS[smzz] = 0; //标志为最小化
        GUI_UPBZ(253,0,1,1); //从底层桌面开始置更新标志,刷新所有窗口内容
        GUI_UP_K = 1; //打开GUI更新
    }

}

void GUI_QZCK(unsigned char CKLX,unsigned char CKH) //前置窗口
{

unsigned char smzz = 0;
unsigned char CKXH_;
unsigned char CKXS_;
unsigned char js1;


    while((CKXH_ = GUI_CKXH[smzz]) != 0)
    {
        if(GUI_CKLX[smzz] == CKLX && GUI_CKH[smzz] == CKH) break; //窗口类型窗口号相同跳出
        ++smzz;
    }


    if(CKXH_ != 0) //窗口类型窗口号相同
    {

        CKXS_ = GUI_CKXS[smzz]; //记录窗口最大最小化标志

        js1 = 0;

        do
        {
            GUI_CKXH[smzz] = GUI_CKXH[smzz+1];   //GUI表地址+1处数据拷贝到当前地址处
            GUI_CKLX[smzz] = GUI_CKLX[smzz+1];
            GUI_CKH[smzz]  = GUI_CKH[smzz+1];
            GUI_CKXS[smzz] = GUI_CKXS[smzz+1];
            GUI_CKUP[smzz] = GUI_CKUP[smzz+1];

            ++smzz;
            ++js1;

        }while(GUI_CKXH[smzz] != 2); //扫描到任务栏跳出

        --smzz;

        GUI_CKXH[smzz] = CKXH_;
        GUI_CKLX[smzz] = CKLX;
        GUI_CKH[smzz]  = CKH;


        if(js1 > 1 || CKXS_ == 0) //窗口不是前置或窗口最小化的时候进入
        {
            GUI_CKXS[smzz] = 1;
            GUI_UPBZ(CKLX,CKH,1,1); //置更新标志,刷新窗口内容
            GUI_UP_K = 1; //打开GUI更新
        }

    }

}


void GUI_GBCK(unsigned char CKLX,unsigned char CKH) //关闭窗口
{

unsigned char smzz = 0;
unsigned char CKXH_;


    while((CKXH_ = GUI_CKXH[smzz]) != 0)
    {
        if(GUI_CKLX[smzz] == CKLX && GUI_CKH[smzz] == CKH) break; //窗口类型窗口号相同跳出
        ++smzz;
    }


    if(CKXH_ != 0) //窗口类型窗口号相同
    {

        GUI_UPBZ(253,0,1,1); //从底层桌面开始置更新标志,刷新所有窗口内容
        GUI_UP_K = 1; //打开GUI更新

        do
        {
            GUI_CKXH[smzz] = GUI_CKXH[smzz+1];   //GUI表地址+1处数据拷贝到当前地址处
            GUI_CKLX[smzz] = GUI_CKLX[smzz+1];
            GUI_CKH[smzz]  = GUI_CKH[smzz+1];
            GUI_CKXS[smzz] = GUI_CKXS[smzz+1];
            GUI_CKUP[smzz] = GUI_CKUP[smzz+1];

            ++smzz;

        }while(GUI_CKXH[smzz] != 0);


        goto in;

        do
        {
            if(GUI_CKXH[smzz] == CKXH_) //找到相同窗口序号
            {
                --GUI_CKXH[smzz]; //此窗口序号减1
        in:
                ++CKXH_; //指向下一窗口序号
                smzz = 0;
            }

            ++smzz;

        }while(GUI_CKXH[smzz] != 0);


    }

}

void GUI_CJCD(unsigned char CKH) //创建菜单
{

unsigned char smzz = 0;


    while(smzz != 255 && GUI_CKXH[smzz] != 0) ++smzz; //扫描GUI表结尾

    if(smzz != 255) //GUI表未满时进入
    {
       GUI_CKXH[smzz] = 3;    //GUI表此位置建菜单
       GUI_CKLX[smzz] = 255;
       GUI_CKH[smzz]  = CKH;
       GUI_CKXS[smzz] = 1;
       GUI_CKUP[smzz] = 1;
    }

}

void GUI_GBCD() //关闭菜单
{

unsigned char smzz = 0;
unsigned char js1;

    while((js1 = GUI_CKXH[smzz]) != 0)
    {
        if(js1 == 3) //找到菜单序号
        {
           GUI_UPBZ(253,0,1,1); //从底层桌面开始置更新标志,刷新所有窗口内容
           GUI_UP_K = 1; //打开GUI更新
           GUI_CKXH[smzz] = 0; //菜单序号清0
        }
        ++smzz;
    }

}



void GUI_BOOT_WJGL_JDT(unsigned char CKH,unsigned char BTXZ,unsigned char device,unsigned char *wjm) //启动文件管理-进度条
{

unsigned char *_addr;

   GUI_WJGL_JDT_XS_Y[CKH] = 0; //文件管理-进度条-显示,窗口起始Y坐标
   GUI_WJGL_JDT_XS_X[CKH] = 0; //文件管理-进度条-显示,窗口起始X坐标

   GUI_WJGL_JDT_XS_XXX_KEYXZ[CKH] = 0; //文件管理-进度条-显示,关闭按钮(选择)
   GUI_WJGL_JDT_XS_XXX_KEY[CKH] = 0; //文件管理-进度条-显示,关闭按钮(按下弹起)
   GUI_WJGL_JDT_XS_ZXH_KEYXZ[CKH] = 0; //文件管理-进度条-显示,最小化按钮(选择)
   GUI_WJGL_JDT_XS_ZXH_KEY[CKH] = 0; //文件管理-进度条-显示,最小化按钮(按下弹起)

   GUI_WJGL_JDT_XS_JDT_WZ[CKH] = 0; //文件管理-进度条-显示,进度条(位置偏移,0~99)

   GUI_WJGL_JDT_XS_DEVICE[CKH] = device; //存储器设备

   _addr = &GUI_WJGL_JDT_XS_WJM[CKH*13];
   *_addr = 0;
   strcat(_addr,wjm); //文件名

   GUI_WJGL_JDT_XS_FZSD[CKH] = 0; //复制速度KB/S
   GUI_WJGL_JDT_XS_BTXZ[CKH] = BTXZ; //标题显示选择,0复制文件,1存储设备名,2文件名,3复制速度,4创建文件,5删除文件

   GUI_GBCK(3,CKH); //关闭窗口
   GUI_CJCK(3,CKH); //创建窗口

}

void GUI_GB_WJGL_JDT(unsigned char CKH) //关闭文件管理-进度条
{
   GUI_GBCK(3,CKH); //关闭窗口
}


void GUI_WJGL_JDT_XS(unsigned char CKH,unsigned char UP_K) //文件管理-进度条-显示(创建文件,复制文件,删除文件)
{

unsigned char Y; //文件管理-进度条-显示,窗口起始Y坐标
unsigned char X; //文件管理-进度条-显示,窗口起始X坐标

unsigned char XXX_KEYXZ; //文件管理-进度条-显示,关闭按钮(选择)
unsigned char XXX_KEY; //文件管理-进度条-显示,关闭按钮(按下弹起)
unsigned char ZXH_KEYXZ; //文件管理-进度条-显示,最小化按钮(选择)
unsigned char ZXH_KEY; //文件管理-进度条-显示,最小化按钮(按下弹起)
unsigned char *UP_K_KEY; //按键更新标志

unsigned char JDT_WZ; //文件管理-进度条-显示,进度条(位置偏移,0~100)
unsigned char *UP_K_JDT; //进度条更新标志

unsigned char DEVICE; //存储器设备
unsigned char *WJM; //文件名
unsigned char FZSD; //复制速度KB/S
unsigned char BTXZ; //标题显示选择,0复制文件,1存储设备名,2文件名,3复制速度,4创建文件,5删除文件
unsigned char *UP_K_BT; //标题更新标志

unsigned char *_addr;
unsigned char _str[8];



    Y = GUI_WJGL_JDT_XS_Y[CKH];
    X = GUI_WJGL_JDT_XS_X[CKH];

    XXX_KEYXZ = GUI_WJGL_JDT_XS_XXX_KEYXZ[CKH];
    XXX_KEY = GUI_WJGL_JDT_XS_XXX_KEY[CKH];
    ZXH_KEYXZ = GUI_WJGL_JDT_XS_ZXH_KEYXZ[CKH];
    ZXH_KEY = GUI_WJGL_JDT_XS_ZXH_KEY[CKH];
    UP_K_KEY = &GUI_WJGL_JDT_XS_UP_K_KEY[CKH];

    JDT_WZ = GUI_WJGL_JDT_XS_JDT_WZ[CKH];
    UP_K_JDT = &GUI_WJGL_JDT_XS_UP_K_JDT[CKH];

    DEVICE = GUI_WJGL_JDT_XS_DEVICE[CKH];
    WJM = &GUI_WJGL_JDT_XS_WJM[CKH*13];
    FZSD = GUI_WJGL_JDT_XS_FZSD[CKH];
    BTXZ = GUI_WJGL_JDT_XS_BTXZ[CKH];
    UP_K_BT = &GUI_WJGL_JDT_XS_UP_K_BT[CKH];




    if(UP_K & 0x01)
    {
        GUI_kuang0(Y,X,48,119,142); //外边框
        GUI_SK1(Y+15,X+1,1,118,142); //标题下横杠
        GUI_SK1(Y+16,X+1,49-16-1,118,182); //下部背景色块
        GUI_SK1(Y+1,X+1,14,118,116); //标题背景色块
        GUI_kuang0(Y+(16+8),X+8,15,103,30); //进度条外边框
        *UP_K_KEY = 1;
        *UP_K_JDT = 1;
        *UP_K_BT = 1;
    }

    if(UP_K != 0)
    {

        if(*UP_K_BT != 0) //更新标题
        {
            *UP_K_BT = 0;

            if((UP_K & 0x01) == 0) GUI_SK1(Y+1,X+1,14,72,116); //擦除标题


            if(BTXZ == 0) //标题显示复制文件
            {
                printx(Y+2,X+2,"复制文件",255);
            }
            else if(BTXZ == 1) //标题显示存储设备名
            {

                if(DEVICE == 0)
                {
                    _addr = "SPI存储器0";
                }
                else if(DEVICE == 1)
                {
                    _addr = "SPI存储器1";
                }
                else if(DEVICE == 2)
                {
                    _addr = "USB存储器0";
                }
                else if(DEVICE == 3)
                {
                    _addr = "USB存储器1";
                }
                else if(DEVICE == 4)
                {
                    _addr = "USB存储器2";
                }
                else if(DEVICE == 5)
                {
                    _addr = "USB存储器3";
                }
                else
                {
                    _addr = "未知存储设备";
                }

                printx(Y+2,X+2,_addr,255);

            }
            else if(BTXZ == 2) //标题显示文件名
            {
                printx(Y+2,X+2,WJM,255);
            }
            else if(BTXZ == 3) //标题显示复制速度
            {
                *_str = 0;
                printx(Y+2,X+2,strcat(strcat(_str,U8_str(FZSD,1)),"KB/S"),255);
            }
            else if(GUI_YYBFQ_XS_BTXZ == 4) //标题显示创建文件
            {
                printx(Y+2,X+2,"创建文件",255);
            }
            else if(GUI_YYBFQ_XS_BTXZ == 5) //标题显示删除文件
            {
                printx(Y+2,X+2,"删除文件",255);
            }

        }

        if(*UP_K_KEY != 0) //更新按键
        {
            *UP_K_KEY = 0;
            GUI_XXX_KEY(Y+3,X+(119-11),XXX_KEYXZ,XXX_KEY); //写关闭按钮
            GUI_ZXH_KEY(Y+3,X+(119-23),ZXH_KEYXZ,ZXH_KEY); //写最小化按钮
        }

        if(*UP_K_JDT != 0) //更新进度条
        {
            *UP_K_JDT = 0;
            GUI_SK1(Y+(16+8+2),X+(8+2),12,100,182); //擦除进度条色块
            if(JDT_WZ != 0) GUI_SK1(Y+(16+8+2),X+(8+2),12,JDT_WZ,99); //进度条色块
            *_str = 0;
            printx(Y+(16+8+2),X+(8+2+38),strcat(strcat(_str,U8_str(JDT_WZ,1)),"%"),255); //百分比
        }
    }


}


void GUI_WJGL_JDT_XS_ZXH_KEY_UP(unsigned char CKH,unsigned char KEY) //更新文件管理-进度条-显示最小化按钮(按下弹起)
{
   GUI_WJGL_JDT_XS_ZXH_KEY[CKH] = KEY;
   GUI_WJGL_JDT_XS_UP_K_KEY[CKH] = 1;
   GUI_UPBZ(3,CKH,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_WJGL_JDT_XS_ZXH_KEYXZ_UP(unsigned char CKH,unsigned char KEY) //更新文件管理-进度条-显示最小化按钮(选择)
{
   GUI_WJGL_JDT_XS_ZXH_KEYXZ[CKH] = KEY;
   GUI_WJGL_JDT_XS_UP_K_KEY[CKH] = 1;
   GUI_UPBZ(3,CKH,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_WJGL_JDT_XS_XXX_KEY_UP(unsigned char CKH,unsigned char KEY) //更新文件管理-进度条-显示关闭按钮(按下弹起)
{
   GUI_WJGL_JDT_XS_XXX_KEY[CKH] = KEY;
   GUI_WJGL_JDT_XS_UP_K_KEY[CKH] = 1;
   GUI_UPBZ(3,CKH,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_WJGL_JDT_XS_XXX_KEYXZ_UP(unsigned char CKH,unsigned char KEY) //更新文件管理-进度条-显示关闭按钮(选择)
{
   GUI_WJGL_JDT_XS_XXX_KEYXZ[CKH] = KEY;
   GUI_WJGL_JDT_XS_UP_K_KEY[CKH] = 1;
   GUI_UPBZ(3,CKH,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

unsigned char GUI_WJGL_JDT_XS_BJ1(unsigned char CKH) //文件管理-进度条-显示(部件1)
{
   return GUI_WJGL_JDT_XS_Y[CKH] > 240 - 65 || GUI_GET_CK_CENGX(3,CKH) != 0; //窗口进入任务栏范围或窗口非前置
}

void GUI_WJGL_JDT_XS_BTXZ_UP(unsigned char CKH) //更新文件管理-进度条-显示标题选择(翻页)
{
unsigned char i;

   if((i = GUI_WJGL_JDT_XS_BTXZ[CKH]) != 4 && i != 5) //不为创建文件和删除文件
   {
       if(++GUI_WJGL_JDT_XS_BTXZ[CKH] == 4) GUI_WJGL_JDT_XS_BTXZ[CKH] = 0;

       if(GUI_GET_CKXS_CKUP(3,CKH) >> 8 != 0) //窗口不为最小化
       {
           GUI_WJGL_JDT_XS_UP_K_BT[CKH] = 1;
           GUI_UPBZ(3,CKH,2,GUI_WJGL_JDT_XS_BJ1(CKH)); //置更新标志,刷新窗口内容
           GUI_UP_K = 1; //打开GUI更新
       }
   }
}

void GUI_WJGL_JDT_XS_FZSD_UP(unsigned char CKH,unsigned char X) //更新文件管理-进度条-显示复制速度
{
   GUI_WJGL_JDT_XS_FZSD[CKH] = X;

   if(GUI_WJGL_JDT_XS_BTXZ[CKH] == 3)
   {
       if(GUI_GET_CKXS_CKUP(3,CKH) >> 8 != 0) //窗口不为最小化
       {
           GUI_WJGL_JDT_XS_UP_K_BT[CKH] = 1;
           GUI_UPBZ(3,CKH,2,GUI_WJGL_JDT_XS_BJ1(CKH)); //置更新标志,刷新窗口内容
           GUI_UP_K = 1; //打开GUI更新
       }
   }
}

void GUI_WJGL_JDT_XS_JDT_WZ_UP(unsigned char CKH,unsigned char X) //更新文件管理-进度条-显示进度条位置
{
   if(X > 100) X = 100;
   GUI_WJGL_JDT_XS_JDT_WZ[CKH] = X;

   if(GUI_GET_CKXS_CKUP(3,CKH) >> 8 != 0) //窗口不为最小化
   {
       GUI_WJGL_JDT_XS_UP_K_JDT[CKH] = 1;
       GUI_UPBZ(3,CKH,2,GUI_WJGL_JDT_XS_BJ1(CKH)); //置更新标志,刷新窗口内容
       GUI_UP_K = 1; //打开GUI更新
   }
}


void GUI_WJGL_JDT_XS_YX_UP(unsigned char CKH,unsigned char Y,unsigned char X) //更新文件管理-进度条-显示窗口起始坐标(移动窗口)
{
   GUI_WJGL_JDT_XS_Y[CKH] += Y;
   GUI_WJGL_JDT_XS_X[CKH] += X;

   GUI_UPBZ(253,0,1,1); //从底层桌面开始置更新标志,刷新所有窗口内容
   GUI_UP_K = 1; //打开GUI更新
}



unsigned char GUI_WJGL_JDT_KEY(unsigned char CKH,unsigned char SB_K,unsigned char KEY_K) //文件管理-进度条-键
{

unsigned char js1;
unsigned char js2;

unsigned char Y;
unsigned char X;


    Y = GUI_WJGL_JDT_XS_Y[CKH];
    X = GUI_WJGL_JDT_XS_X[CKH];


    if(SB_K != 0 && GUI_SBZBPD(Y,Y+48,X,X+119) != 0) //鼠标坐标在窗口范围内
    {

        if(GUI_WJGL_JDT_KEY_KXZ[(CKH << 2)] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_WJGL_JDT_KEY_KXZ[(CKH << 2)] = 1; //弹起指向第1步
        }
        else if(GUI_WJGL_JDT_KEY_KXZ[(CKH << 2)] == 1)
        {
            if(GUI_SB_L_KEY() != 0)
            {
                GUI_WJGL_JDT_KEY_KXZ[(CKH << 2)] = 2; //按下指向第2步
                GUI_QZCK(3,CKH); //前置窗口
            }
        }
        else if(GUI_WJGL_JDT_KEY_KXZ[(CKH << 2)] == 2)
        {
            if(GUI_SB_L_KEY() == 0)
            {
                GUI_WJGL_JDT_KEY_KXZ[(CKH << 2)] = 1; //弹起指向第1步
            }
        }

    }
    else
    {
        GUI_WJGL_JDT_KEY_KXZ[(CKH << 2)] = 0;
    }



    if(SB_K != 0 && GUI_SBZBPD(Y+3,Y+(3+8),X+(119-11),X+(119-11+8)) != 0) //鼠标坐标在关闭按钮范围内
    {
        if(GUI_WJGL_JDT_KEY_IO[(CKH << 2) + 1] == 0)
        {
           GUI_WJGL_JDT_XS_XXX_KEYXZ_UP(CKH,1); //更新文件管理-进度条-显示关闭按钮(选择)
           GUI_WJGL_JDT_KEY_IO[(CKH << 2) + 1] = 1;
        }

        if(GUI_WJGL_JDT_KEY_KXZ[(CKH << 2) + 1] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_WJGL_JDT_KEY_KXZ[(CKH << 2) + 1] = 1; //弹起指向第1步
        }
        else if(GUI_WJGL_JDT_KEY_KXZ[(CKH << 2) + 1] == 1)
        {
            if(GUI_SB_L_KEY() != 0)
            {
                GUI_WJGL_JDT_KEY_KXZ[(CKH << 2) + 1] = 2; //按下指向第2步
                GUI_WJGL_JDT_XS_XXX_KEY_UP(CKH,1); //更新文件管理-进度条-显示关闭按钮(按下弹起)
            }
        }
        else if(GUI_WJGL_JDT_KEY_KXZ[(CKH << 2) + 1] == 2)
        {
            if(GUI_SB_L_KEY() == 0)
            {
                GUI_WJGL_JDT_KEY_KXZ[(CKH << 2) + 1] = 1; //弹起指向第1步
                GUI_WJGL_JDT_XS_XXX_KEY_UP(CKH,0); //更新文件管理-进度条-显示关闭按钮(按下弹起)

                FAT32_GBWJ(GUI_WJGL_FZWJ_S_DEVICE[CKH],GUI_WJGL_FZWJ_S_WJH[CKH]); //关闭文件
                FAT32_GBWJ(GUI_WJGL_FZWJ_D_DEVICE[CKH],GUI_WJGL_FZWJ_D_WJH[CKH]); //关闭文件
                GUI_GBCK(3,CKH); //关闭窗口
            }
        }

    }
    else
    {
        if(GUI_WJGL_JDT_KEY_IO[(CKH << 2) + 1] != 0)
        {
           GUI_WJGL_JDT_XS_XXX_KEYXZ_UP(CKH,0); //更新文件管理-进度条-显示关闭按钮(选择)
           GUI_WJGL_JDT_KEY_IO[(CKH << 2) + 1] = 0;
        }

        if(GUI_WJGL_JDT_KEY_KXZ[(CKH << 2) + 1] != 0)
        {
           GUI_WJGL_JDT_XS_XXX_KEY_UP(CKH,0); //更新文件管理-进度条-显示关闭按钮(按下弹起)
           GUI_WJGL_JDT_KEY_KXZ[(CKH << 2) + 1] = 0;
        }

    }



    if(SB_K != 0 && GUI_SBZBPD(Y+3,Y+(3+8),X+(119-23),X+(119-23+8)) != 0) //鼠标坐标在最小化按钮范围内
    {
        if(GUI_WJGL_JDT_KEY_IO[(CKH << 2) + 2] == 0)
        {
           GUI_WJGL_JDT_XS_ZXH_KEYXZ_UP(CKH,1); //更新文件管理-进度条-显示最小化按钮(选择)
           GUI_WJGL_JDT_KEY_IO[(CKH << 2) + 2] = 1;
        }

        if(GUI_WJGL_JDT_KEY_KXZ[(CKH << 2) + 2] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_WJGL_JDT_KEY_KXZ[(CKH << 2) + 2] = 1; //弹起指向第1步
        }
        else if(GUI_WJGL_JDT_KEY_KXZ[(CKH << 2) + 2] == 1)
        {
            if(GUI_SB_L_KEY() != 0)
            {
                GUI_WJGL_JDT_KEY_KXZ[(CKH << 2) + 2] = 2; //按下指向第2步
                GUI_WJGL_JDT_XS_ZXH_KEY_UP(CKH,1); //更新文件管理-进度条-显示最小化按钮(按下弹起)
            }
        }
        else if(GUI_WJGL_JDT_KEY_KXZ[(CKH << 2) + 2] == 2)
        {
            if(GUI_SB_L_KEY() == 0)
            {
                GUI_WJGL_JDT_KEY_KXZ[(CKH << 2) + 2] = 1; //弹起指向第1步
                GUI_WJGL_JDT_XS_ZXH_KEY_UP(CKH,0); //更新文件管理-进度条-显示最小化按钮(按下弹起)
                GUI_ZXHCK(3,CKH); //最小化窗口
            }
        }

    }
    else
    {
        if(GUI_WJGL_JDT_KEY_IO[(CKH << 2) + 2] != 0)
        {
           GUI_WJGL_JDT_XS_ZXH_KEYXZ_UP(CKH,0); //更新文件管理-进度条-显示最小化按钮(选择)
           GUI_WJGL_JDT_KEY_IO[(CKH << 2) + 2] = 0;
        }

        if(GUI_WJGL_JDT_KEY_KXZ[(CKH << 2) + 2] != 0)
        {
           GUI_WJGL_JDT_XS_ZXH_KEY_UP(CKH,0); //更新文件管理-进度条-显示最小化按钮(按下弹起)
           GUI_WJGL_JDT_KEY_KXZ[(CKH << 2) + 2] = 0;
        }

    }



    if(SB_K != 0 && (GUI_SBZBPD(Y+1,Y+(1+13),X+1,X+(1+117)) != 0 && GUI_WJGL_JDT_KEY_KXZ[(CKH << 2) + 1] == 0 && GUI_WJGL_JDT_KEY_KXZ[(CKH << 2) + 2] == 0 || GUI_WJGL_JDT_KEY_KXZ[(CKH << 2) + 3] == 2)) //鼠标坐标在窗口标题范围内
    {

        if(GUI_WJGL_JDT_KEY_KXZ[(CKH << 2) + 3] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_WJGL_JDT_KEY_KXZ[(CKH << 2) + 3] = 1; //弹起指向第1步
        }
        else if(GUI_WJGL_JDT_KEY_KXZ[(CKH << 2) + 3] == 1)
        {
            if(GUI_SB_L_KEY() != 0)
            {
                GUI_WJGL_JDT_KEY_KXZ[(CKH << 2) + 3] = 2; //按下指向第2步
            }
        }
        else if(GUI_WJGL_JDT_KEY_KXZ[(CKH << 2) + 3] == 2)
        {
            js1 = GUI_SB_GET_AS_Y();
            js2 = GUI_SB_GET_AS_X();

            if(js1 != 0 || js2 != 0)
            {
                GUI_WJGL_JDT_XS_YX_UP(CKH,js1,js2); //更新文件管理-进度条-显示窗口起始坐标(移动窗口)
            }

            if(GUI_SB_L_KEY() == 0)
            {
                GUI_WJGL_JDT_KEY_KXZ[(CKH << 2) + 3] = 1; //弹起指向第1步
                GUI_WJGL_JDT_XS_BTXZ_UP(CKH); //更新文件管理-进度条-显示标题选择(翻页)
            }
        }

    }
    else
    {

        GUI_WJGL_JDT_KEY_KXZ[(CKH << 2) + 3] = 0;

    }




    return SB_K != 0 && GUI_SBZBPD(Y,Y+48,X,X+119) != 0; //落在窗口内返回非0

}






void GUI_WJGL_BOOT_CD(unsigned char X) //启动文件管理-菜单
{

    if(X < 2)
    {
        if((GUI_WJGL_CD_XS_Y = GUI_SB_GET_Y()) > 240-(13*5+1))
        {
            GUI_WJGL_CD_XS_Y -= 13*5; //菜单起始Y坐标
        }
    }

    if(X < 2)
    {
        if((GUI_WJGL_CD_XS_X = GUI_SB_GET_X()) > 218)
        {
            GUI_WJGL_CD_XS_X -= 37; //菜单起始X坐标
        }
    }


    GUI_WJGL_CD_XS_CDXZ = X; //菜单选择,0为目录菜单,1为文件菜单
    GUI_WJGL_CD_XS_XMXZ = 255; //菜单内项目选择,0为首项目,255为不选择

    GUI_CJCD(0); //创建菜单

}


void GUI_WJGL_CD_XS(unsigned char UP_K) //文件管理-菜单-显示(文件右键菜单和目录下右键菜单)
{

    if(UP_K != 0)
    {
        if(GUI_WJGL_CD_XS_CDXZ == 0) //目录菜单
        {

            GUI_SK1(GUI_WJGL_CD_XS_Y,GUI_WJGL_CD_XS_X,13*5+1,12*3+2,208); //菜单背景
            if(GUI_WJGL_CD_XS_XMXZ < 5) GUI_SK1(GUI_WJGL_CD_XS_Y+1+(GUI_WJGL_CD_XS_XMXZ*13),GUI_WJGL_CD_XS_X+1,12,12*3,31); //项目背景

            printx(GUI_WJGL_CD_XS_Y+1,GUI_WJGL_CD_XS_X+(19-12),"刷新",0);
            printx(GUI_WJGL_CD_XS_Y+(1+13),GUI_WJGL_CD_XS_X+(19-12),"粘贴",0);
            printx(GUI_WJGL_CD_XS_Y+(1+13+13),GUI_WJGL_CD_XS_X+(19-12-6),"建目录",0);
            printx(GUI_WJGL_CD_XS_Y+(1+13+13+13),GUI_WJGL_CD_XS_X+(19-12-6),"建文件",0);
            printx(GUI_WJGL_CD_XS_Y+(1+13+13+13+13),GUI_WJGL_CD_XS_X+(19-12),"属性",0);

        }
        else if(GUI_WJGL_CD_XS_CDXZ == 1) //文件菜单
        {

            GUI_SK1(GUI_WJGL_CD_XS_Y,GUI_WJGL_CD_XS_X,13*5+1,12*3+2,208); //菜单背景
            if(GUI_WJGL_CD_XS_XMXZ < 5) GUI_SK1(GUI_WJGL_CD_XS_Y+1+(GUI_WJGL_CD_XS_XMXZ*13),GUI_WJGL_CD_XS_X+1,12,12*3,31); //项目背景
            printx(GUI_WJGL_CD_XS_Y+1,GUI_WJGL_CD_XS_X+(19-12),"打开",0);
            printx(GUI_WJGL_CD_XS_Y+(1+13),GUI_WJGL_CD_XS_X+(19-12),"复制",0);
            printx(GUI_WJGL_CD_XS_Y+(1+13+13),GUI_WJGL_CD_XS_X+(19-12),"删除",0);
            printx(GUI_WJGL_CD_XS_Y+(1+13+13+13),GUI_WJGL_CD_XS_X+(19-12-6),"重命名",0);
            printx(GUI_WJGL_CD_XS_Y+(1+13+13+13+13),GUI_WJGL_CD_XS_X+(19-12),"属性",0);

        }
    }

}


void GUI_WJGL_CD_XS_XMXZ_UP(unsigned char KEY) //更新菜单内项目选择,0为首项目,255为不选择
{
   GUI_WJGL_CD_XS_XMXZ = KEY;
   GUI_UPBZ(255,0,2,0); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}



void GUI_WJGL_TQWJLJ(unsigned char *LJ) //文件管理-提取文件路径(短文件名)
{

unsigned int js1;
unsigned char DWJM[13];

   *LJ = 0;

        if(GUI_WJGL_XS_DEVICE == 0) strcat(LJ,"spi_device0:"); //加入设备名称
   else if(GUI_WJGL_XS_DEVICE == 1) strcat(LJ,"spi_device1:");
   else if(GUI_WJGL_XS_DEVICE == 2) strcat(LJ,"usb_device0:");
   else if(GUI_WJGL_XS_DEVICE == 3) strcat(LJ,"usb_device1:");
   else if(GUI_WJGL_XS_DEVICE == 4) strcat(LJ,"usb_device2:");
   else if(GUI_WJGL_XS_DEVICE == 5) strcat(LJ,"usb_device3:");


   js1 = 0;

   while(js1 != GUI_WJGL_XS_muluX)
   {
       ++js1;
       GUI_11B_chars(&GUI_WJGL_XS_mulu_DATA_32B[js1 << 5],DWJM); //文件32字节数据提取前11字节转带'.'短文件名字符串
       strcat(LJ,DWJM);
       strcat(LJ,"\");
   }

   GUI_11B_chars(&GUI_WJGL_XS_WJDATA_32B[GUI_WJGL_XS_WJXZ0 << 5],DWJM); //文件32字节数据提取前11字节转带'.'短文件名字符串
   strcat(LJ,DWJM);

}




void GUI_WJGL_QDBIN() //文件管理-启动BIN文件
{

    GUI_WJGL_TQWJLJ(GUI_WJGL_QDBIN_LJ); //提取文件路径(短文件名)

    if((GUI_WJGL_QDBIN_LJCD = strlen(GUI_WJGL_QDBIN_LJ)) < 513) //路径512字节内可以启动
    {

        if(GUI_WJGL_QDBIN_BZ == 0) //系统正在启动BIN文件标志为0时进入
        {

            GUI_WJGL_QDBIN_YDWB_DEVICE = 0;
            while(GUI_WJGL_QDBIN_YDWB_DEVICE != 2 && FAT32_BZ[GUI_WJGL_QDBIN_YDWB_DEVICE] == 0) ++GUI_WJGL_QDBIN_YDWB_DEVICE; //寻找文件系统初始化完成的设备

            if(GUI_WJGL_QDBIN_YDWB_DEVICE != 2) //没有超出设备门限
            {

                GUI_WJGL_QDBIN_BZ = 1; //标志系统正在启动BIN文件

                if(FAT32_ML_DELETE_WJ(GUI_WJGL_QDBIN_YDWB_DEVICE,0x00000002,"KC_LS1u_boot_1.txt") == 0) //初始化删除文件,没有找到文件
                {
                    if(FAT32_ML_SETUP_WJ(GUI_WJGL_QDBIN_YDWB_DEVICE,0x00000002,GUI_WJGL_QDBIN_LJCD,"KC_LS1u_boot_1.txt",0x20) == 0) //初始化目录创建文件,创建失败
                    {
                        GUI_WJGL_QDBIN_BZ = 0; //关闭系统正在启动BIN文件标志
                    }
                }

            }
            else //设备错误
            {
            }

        }

    }
    else //路径大于512字节不启动
    {
    }

}


void GUI_BOOT_YYBFQ(unsigned char device,unsigned long int mulu_cuhao,unsigned char *wjm) //启动音乐播放器
{

   GUI_YYBFQ_XS_DEVICE = device; //记录音乐播放器所在的存储设备
   GUI_YYBFQ_XS_mulu_cuhao = mulu_cuhao; //记录音乐播放器所在的目录簇号
   GUI_YYBFQ_XS_WJM[0] = 0; //记录当前播放的文件的文件名
   strcat(GUI_YYBFQ_XS_WJM,wjm);
   GUI_YYBFQ_XS_WJX = 255; //设置为无效文件号

   GUI_YYBFQ_XS_Y = 0; //音乐播放器-显示,窗口起始Y坐标
   GUI_YYBFQ_XS_X = 0; //音乐播放器-显示,窗口起始X坐标

   GUI_YYBFQ_XS_XXX_KEYXZ = 0; //音乐播放器-显示,关闭按钮(选择)
   GUI_YYBFQ_XS_XXX_KEY = 0; //音乐播放器-显示,关闭按钮(按下弹起)
   GUI_YYBFQ_XS_ZXH_KEYXZ = 0; //音乐播放器-显示,最小化按钮(选择)
   GUI_YYBFQ_XS_ZXH_KEY = 0; //音乐播放器-显示,最小化按钮(按下弹起)
   GUI_YYBFQ_XS_TZBF_KEY = 0; //音乐播放器-显示,停止播放按钮(按下弹起)
   GUI_YYBFQ_XS_SYQ_KEY = 0; //音乐播放器-显示,上一曲按钮(按下弹起)
   GUI_YYBFQ_XS_XYQ_KEY = 0; //音乐播放器-显示,下一曲按钮(按下弹起)
   GUI_YYBFQ_XS_BFZT_KEY = 0; //音乐播放器-显示,播放暂停按钮(按下弹起)
   GUI_YYBFQ_XS_DQXH_KEY = 0; //音乐播放器-显示,单曲循环按钮(按下弹起)

   GUI_YYBFQ_XS_JDT_KEYXZ = 0; //音乐播放器-显示,进度条滑块(选择)
   GUI_YYBFQ_XS_JDT_WZ_ = 0; //音乐播放器-显示,进度条滑块(位置偏移旧值)
   GUI_YYBFQ_XS_JDT_WZ = 0; //音乐播放器-显示,进度条滑块(位置偏移)

   GUI_YYBFQ_XS_BFZT_K = 1; //播放控制,为1播放,为0暂停
   GUI_YYBFQ_XS_DQXH_K = 0; //单曲循环控制,不为0单曲循环
   GUI_YYBFQ_XS_SDS = 0; //声道数,为0立体声,为1单声道
   GUI_YYBFQ_XS_kbps = 320; //码率
   GUI_YYBFQ_XS_CYL = 44100; //采样率
   GUI_YYBFQ_XS_RTC_SEC = 0; //播放时间(秒)
   GUI_YYBFQ_XS_RTC_MIN = 0; //播放时间(分)
   GUI_YYBFQ_XS_RTC_HR = 0; //播放时间(时)
   GUI_YYBFQ_XS_BTXZ = 0; //标题显示选择,为0显示音乐播放器,为1显示播放的文件,为2显示码率,为3显示采样率,为4显示声道数,为5显示时间

   GUI_YYBFQ_XS_XYQ_K = 0; //下一曲控制,为0跳过查询下一曲

   GUI_GBCK(2,0); //关闭窗口
   GUI_CJCK(2,0); //创建窗口


}


void GUI_WJGL_ML_IN(unsigned int X) //进入当前目录下的文件或文件夹
{

unsigned char js1;

unsigned char GUI_WJGL_XS_WJDATA_32B_hzm1; //源文件后缀名
unsigned char GUI_WJGL_XS_WJDATA_32B_hzm2;
unsigned char GUI_WJGL_XS_WJDATA_32B_hzm3;

unsigned char *GUI_WJGL_XS_mulu_DATA_32B_addr; //当前目录的32个字节文件符数据首地址
unsigned long int GUI_WJGL_XS_mulu_DATA_32B_cuhao; //当前目录首簇号
unsigned char *GUI_WJGL_XS_WJDATA_32B_addr; //源文件的文件符首地址
unsigned char GUI_WJGL_XS_WJDATA_32B_DWJM[13]; //源文件的短文件名




   GUI_WJGL_XS_WJDATA_32B_addr = &GUI_WJGL_XS_WJDATA_32B[X << 5]; //取文件的32个字节文件符数据首地址

   js1 = GUI_WJGL_XS_WJDATA_32B_addr[0x0b] & 0xf0; //读出文件属性字节

   if(js1 == 0x10) //是文件夹
   {

       if(GUI_WJGL_XS_muluX < 127) //进入目录的层数限制
       {
           ++GUI_WJGL_XS_muluX; //目录层数计数指向下一层
           GUI_WJGL_XS_mulu_DATA_32B_addr = &GUI_WJGL_XS_mulu_DATA_32B[GUI_WJGL_XS_muluX << 5]; //取下一层目录的32个字节文件符数据首地址

           for(js1 = 0;js1 != 32;++js1) GUI_WJGL_XS_mulu_DATA_32B_addr[js1] = GUI_WJGL_XS_WJDATA_32B_addr[js1]; //拷贝32个字节文件符数据到下一层目录

           GUI_WJGL_GET_WJDATA_32B_BZ = 1; //请求数据标志,为1刷新15个文件的32个字节文件符数据
           GUI_WJGL_GET_WJDATA_32B_WJH = 0; //请求数据,首文件号
           GUI_WJGL_GET_WJX_BZ = 1; //为1刷新目录下的总文件数量

           GUI_WJGL_XS_WJDATA_32B[0] = 0; //文件的32个字节文件符数据为0

           GUI_WJGL_XS_WJXZ0 = 0;  //文件选择0,文件图标背景色块,鼠标点击才选择,0~14
           GUI_WJGL_XS_WJXZ0_K = 0; //文件选择0,文件图标背景色块显示控制,为1显示,为0不显示

           GUI_WJGL_XS__WJXZ1 = 0; //文件选择1,选择框,跟随鼠标选择,新值,0~14
           GUI_WJGL_XS_WJXZ1_ = 0;  //文件选择1,选择框,跟随鼠标选择,旧值,0~14
           GUI_WJGL_XS_WJXZ1_K = 0; //文件选择1,文件图标选择框显示控制,为1显示,为0不显示

           GUI_WJGL_XS_TDTWZ = 0; //拖动条位置,偏移值

           GUI_WJGL_XS_ML_WJX = 0; //目录文件总数
           GUI_WJGL_XS_ML_WJXS_PY = 0; //文件图标显示区像素偏移

           GUI_UPBZ(0,0,1,1); //置更新标志,刷新窗口内容
           GUI_UP_K = 1; //打开GUI更新
       }

   }
   else if(js1 == 0x20) //是文件
   {

        GUI_WJGL_XS_mulu_DATA_32B_addr = &GUI_WJGL_XS_mulu_DATA_32B[GUI_WJGL_XS_muluX << 5]; //取当前目录的32个字节文件符数据首地址

        GUI_WJGL_XS_mulu_DATA_32B_cuhao = GUI_WJGL_XS_mulu_DATA_32B_addr[0x15]; //记录目录首簇号
        GUI_WJGL_XS_mulu_DATA_32B_cuhao <<= 8;
        GUI_WJGL_XS_mulu_DATA_32B_cuhao |= GUI_WJGL_XS_mulu_DATA_32B_addr[0x14];
        GUI_WJGL_XS_mulu_DATA_32B_cuhao <<= 8;
        GUI_WJGL_XS_mulu_DATA_32B_cuhao |= GUI_WJGL_XS_mulu_DATA_32B_addr[0x1b];
        GUI_WJGL_XS_mulu_DATA_32B_cuhao <<= 8;
        GUI_WJGL_XS_mulu_DATA_32B_cuhao |= GUI_WJGL_XS_mulu_DATA_32B_addr[0x1a];

       GUI_WJGL_XS_WJDATA_32B_hzm1 = GUI_WJGL_XS_WJDATA_32B_addr[0x08]; //源文件后缀名
       GUI_WJGL_XS_WJDATA_32B_hzm2 = GUI_WJGL_XS_WJDATA_32B_addr[0x09];
       GUI_WJGL_XS_WJDATA_32B_hzm3 = GUI_WJGL_XS_WJDATA_32B_addr[0x0a];


       if(GUI_WJGL_XS_WJDATA_32B_hzm1 == 'M' && GUI_WJGL_XS_WJDATA_32B_hzm2 == 'P' && GUI_WJGL_XS_WJDATA_32B_hzm3 == '3') //为MP3文件
       {

           GUI_11B_chars(GUI_WJGL_XS_WJDATA_32B_addr,GUI_WJGL_XS_WJDATA_32B_DWJM);
           GUI_BOOT_YYBFQ(GUI_WJGL_XS_DEVICE,GUI_WJGL_XS_mulu_DATA_32B_cuhao,GUI_WJGL_XS_WJDATA_32B_DWJM); //启动音乐播放器

       }
       else if(GUI_WJGL_XS_WJDATA_32B_hzm1 == 'B' && GUI_WJGL_XS_WJDATA_32B_hzm2 == 'I' && GUI_WJGL_XS_WJDATA_32B_hzm3 == 'N') //为BIN文件
       {

           GUI_WJGL_QDBIN(); //文件管理-启动BIN文件

       }

   }


}


void GUI_WJGL_CD_IN() //启动菜单项目
{

unsigned int CWJM[404];
unsigned char WJDATA_32B[32];
unsigned int js1;
unsigned long int js2;
unsigned int js3;

unsigned char GUI_WJGL_XS_WJDATA_32B_hzm1; //源文件后缀名
unsigned char GUI_WJGL_XS_WJDATA_32B_hzm2;
unsigned char GUI_WJGL_XS_WJDATA_32B_hzm3;

unsigned char *GUI_WJGL_XS_mulu_DATA_32B_addr; //当前目录的32个字节文件符数据首地址
unsigned long int GUI_WJGL_XS_mulu_DATA_32B_cuhao; //当前目录首簇号
unsigned char *GUI_WJGL_XS_WJDATA_32B_addr; //源文件的文件符首地址
unsigned char GUI_WJGL_XS_WJDATA_32B_DWJM[13]; //源文件的短文件名
unsigned char GUI_WJGL_XS_WJDATA_32B_SX; //源文件属性字节
unsigned long int GUI_WJGL_XS_WJDATA_32B_WJDX; //源文件大小



    GUI_WJGL_XS_mulu_DATA_32B_addr = &GUI_WJGL_XS_mulu_DATA_32B[GUI_WJGL_XS_muluX << 5]; //取当前目录的32个字节文件符数据首地址
    GUI_WJGL_XS_WJDATA_32B_addr = &GUI_WJGL_XS_WJDATA_32B[GUI_WJGL_XS_WJXZ0 << 5]; //取出文件符首地址

    GUI_WJGL_XS_mulu_DATA_32B_cuhao = GUI_WJGL_XS_mulu_DATA_32B_addr[0x15]; //目录首簇号
    GUI_WJGL_XS_mulu_DATA_32B_cuhao <<= 8;
    GUI_WJGL_XS_mulu_DATA_32B_cuhao |= GUI_WJGL_XS_mulu_DATA_32B_addr[0x14];
    GUI_WJGL_XS_mulu_DATA_32B_cuhao <<= 8;
    GUI_WJGL_XS_mulu_DATA_32B_cuhao |= GUI_WJGL_XS_mulu_DATA_32B_addr[0x1b];
    GUI_WJGL_XS_mulu_DATA_32B_cuhao <<= 8;
    GUI_WJGL_XS_mulu_DATA_32B_cuhao |= GUI_WJGL_XS_mulu_DATA_32B_addr[0x1a];

    
    GUI_WJGL_XS_WJDATA_32B_hzm1 = GUI_WJGL_XS_WJDATA_32B_addr[0x08]; //保存源文件后缀名
    GUI_WJGL_XS_WJDATA_32B_hzm2 = GUI_WJGL_XS_WJDATA_32B_addr[0x09];
    GUI_WJGL_XS_WJDATA_32B_hzm3 = GUI_WJGL_XS_WJDATA_32B_addr[0x0a];

    GUI_WJGL_XS_WJDATA_32B_SX = GUI_WJGL_XS_WJDATA_32B_addr[0x0b] & 0xf0; //保存文件属性字节

    GUI_WJGL_XS_WJDATA_32B_WJDX = GUI_WJGL_XS_WJDATA_32B_addr[0x1f]; //保存源文件大小
    GUI_WJGL_XS_WJDATA_32B_WJDX <<= 8;
    GUI_WJGL_XS_WJDATA_32B_WJDX |= GUI_WJGL_XS_WJDATA_32B_addr[0x1e];
    GUI_WJGL_XS_WJDATA_32B_WJDX <<= 8;
    GUI_WJGL_XS_WJDATA_32B_WJDX |= GUI_WJGL_XS_WJDATA_32B_addr[0x1d];
    GUI_WJGL_XS_WJDATA_32B_WJDX <<= 8;
    GUI_WJGL_XS_WJDATA_32B_WJDX |= GUI_WJGL_XS_WJDATA_32B_addr[0x1c];

    GUI_11B_chars(GUI_WJGL_XS_WJDATA_32B_addr,GUI_WJGL_XS_WJDATA_32B_DWJM); //保存源文件的短文件名



    if(GUI_WJGL_CD_XS_CDXZ == 0) //目录菜单
    {

        if(GUI_WJGL_CD_XS_XMXZ == 0) //刷新
        {
        }
        else if(GUI_WJGL_CD_XS_XMXZ == 1) //粘贴
        {

            if(GUI_WJGL_FZ_BZ != 0)
            {

                if(GUI_WJGL_FZWJ_X != GUI_WJGL_FZWJ_WJX) //复制文件表项目计数没有达到最大
                {
                    if(FAT32_ML_SETUP_WJ(GUI_WJGL_XS_DEVICE,GUI_WJGL_XS_mulu_DATA_32B_cuhao,GUI_WJGL_CD_FZ_S_WJDX,GUI_WJGL_CD_FZ_S_WJM,0x20) != 0) //初始化目录创建文件,返回不为0成功
                    {
                        if(GUI_WJGL_CD_FZ_S_WJDX != 0) //源文件大小不为0
                        {
                            GUI_WJGL_FZWJ_K = 1; //加入复制文件
                            GUI_WJGL_CD_ZT_S_DEVICE = GUI_WJGL_CD_FZ_S_DEVICE; //文件管理-菜单-粘贴,保存源文件所在设备
                            GUI_WJGL_CD_ZT_S_mulu_cuhao = GUI_WJGL_CD_FZ_S_mulu_cuhao; //文件管理-菜单-粘贴,保存源文件所在目录的首簇号
                            GUI_WJGL_CD_ZT_S_WJM[0] = 0;
                            strcat(GUI_WJGL_CD_ZT_S_WJM,GUI_WJGL_CD_FZ_S_WJM); //拷贝文件名
                        }

                    }
                }

            }

        }
        else if(GUI_WJGL_CD_XS_XMXZ == 2) //建目录
        {
        }
        else if(GUI_WJGL_CD_XS_XMXZ == 3) //建文件
        {
        }
        else if(GUI_WJGL_CD_XS_XMXZ == 4) //属性
        {
        }

    }
    else if(GUI_WJGL_CD_XS_CDXZ == 1) //文件菜单
    {





        if(GUI_WJGL_CD_XS_XMXZ == 0) //打开
        {

             GUI_WJGL_ML_IN(GUI_WJGL_XS_WJXZ0); //进入当前目录下的文件或文件夹

        }
        else if(GUI_WJGL_CD_XS_XMXZ == 1) //复制
        {

            if((GUI_WJGL_XS_WJDATA_32B_addr[0x0b] & 0xf0) == 0x20) //是文件
            {

                GUI_WJGL_CD_FZ_S_DEVICE = GUI_WJGL_XS_DEVICE; //保存源文件所在设备
                GUI_WJGL_CD_FZ_S_WJDX = GUI_WJGL_XS_WJDATA_32B_WJDX; //保存源文件大小
                GUI_11B_chars(GUI_WJGL_XS_WJDATA_32B_addr,GUI_WJGL_CD_FZ_S_WJM); //保存源文件名
                GUI_WJGL_CD_FZ_S_mulu_cuhao = GUI_WJGL_XS_mulu_DATA_32B_cuhao; //保存源文件所在目录的首簇号


                if(FAT32_ML_WJCX(GUI_WJGL_XS_DEVICE,GUI_WJGL_CD_FZ_S_mulu_cuhao,GUI_WJGL_CD_FZ_S_WJM,WJDATA_32B,CWJM,0,0,0,0,0,0) != 0) //查询文件,提取长文件名unicode码
                {

                    if(*CWJM != 0) //有长文件名
                    {
                        js1 = 0;
                        while((js3 = CWJM[js1]) != 0 && js3 < 128) ++js1;
                        if(js3 == 0) //没有超出ASCII范围
                        {
                            GUI_unicode_str(CWJM,GUI_WJGL_CD_FZ_S_WJM); //unicode码转文件名字符串,返回值为字符串字节长度
                        }
                    }

                    GUI_WJGL_FZ_BZ = 1; //标志复制成功

                }
                else
                {
                    GUI_WJGL_FZ_BZ = 0; //标志复制不成功
                }

            }
            else
            {
                GUI_WJGL_FZ_BZ = 0; //标志复制不成功
            }

        }
        else if(GUI_WJGL_CD_XS_XMXZ == 2) //删除
        {
            if(GUI_WJGL_XS_WJDATA_32B_SX == 0x20) //是文件
            {
                FAT32_ML_DELETE_WJ(GUI_WJGL_XS_DEVICE,GUI_WJGL_XS_mulu_DATA_32B_cuhao,GUI_WJGL_XS_WJDATA_32B_DWJM); //初始化删除文件
            }
        }
        else if(GUI_WJGL_CD_XS_XMXZ == 3) //重命名
        {
        }
        else if(GUI_WJGL_CD_XS_XMXZ == 4) //属性
        {
        }

    }


}



unsigned char GUI_WJGL_CD_KEY(unsigned char SB_K,unsigned char KEY_K) //文件管理-菜单-键
{

unsigned char js1;
unsigned char js2;


    js1 = 0;
    js2 = 0;

    do
    {

        if(SB_K != 0 && GUI_SBZBPD(js1*13 + GUI_WJGL_CD_XS_Y+1,js1*13 + GUI_WJGL_CD_XS_Y+(1+11),GUI_WJGL_CD_XS_X+1,GUI_WJGL_CD_XS_X+(1+35)) != 0) //鼠标坐标在菜单范围项目范围内
        {
            if(GUI_WJGL_CD_KEY_IO[js1] == 0)
            {
               GUI_WJGL_CD_XS_XMXZ_UP(js1); //更新菜单内项目选择,0为首项目,255为不选择
               GUI_WJGL_CD_KEY_IO[js1] = 1;
               js2 = 1;
            }

            if(GUI_WJGL_CD_KEY_KXZ[js1] == 0)
            {
                if(GUI_SB_L_KEY() == 0) GUI_WJGL_CD_KEY_KXZ[js1] = 1; //弹起指向第1步
            }
            else if(GUI_WJGL_CD_KEY_KXZ[js1] == 1)
            {
                if(GUI_SB_L_KEY() != 0) GUI_WJGL_CD_KEY_KXZ[js1] = 2; //按下指向第2步
            }
            else if(GUI_WJGL_CD_KEY_KXZ[js1] == 2)
            {
                if(GUI_SB_L_KEY() == 0)
                {
                    GUI_WJGL_CD_KEY_KXZ[js1] = 1; //弹起指向第1步
                    GUI_GBCD(); //关闭菜单
                    GUI_WJGL_CD_IN(); //启动菜单项目
                }
            }

        }
        else
        {

            if(GUI_WJGL_CD_KEY_IO[js1] != 0)
            {
               if(js2 == 0) GUI_WJGL_CD_XS_XMXZ_UP(255); //更新菜单内项目选择,0为首项目,255为不选择
               GUI_WJGL_CD_KEY_IO[js1] = 0;
            }

            GUI_WJGL_CD_KEY_KXZ[js1] = 0;

        }


    }while(++js1 != 5);



    if(SB_K != 0 && GUI_SBZBPD(GUI_WJGL_CD_XS_Y,GUI_WJGL_CD_XS_Y+(13*5),GUI_WJGL_CD_XS_X,GUI_WJGL_CD_XS_X+37) == 0) //鼠标坐标不在菜单范围内
    {

        if(GUI_WJGL_CD_KEY_KXZ[5] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_WJGL_CD_KEY_KXZ[5] = 1; //弹起指向第1步
        }
        else if(GUI_WJGL_CD_KEY_KXZ[5] == 1)
        {
            if(GUI_SB_L_KEY() != 0 || GUI_SB_R_KEY() != 0 || GUI_SB_M_KEY() != 0)
            {
                GUI_GBCD(); //关闭菜单
            }
        }

    }
    else
    {

        GUI_WJGL_CD_KEY_KXZ[5] = 0;

    }


    return SB_K != 0 && GUI_SBZBPD(GUI_WJGL_CD_XS_Y,js1,GUI_WJGL_CD_XS_X,GUI_WJGL_CD_XS_X+37) != 0; //落在窗口内返回非0

}



void GUI_WJGL_XS(unsigned char UP_K) //文件管理-显示
{

unsigned char X;
unsigned char Y;
unsigned char *TBXS;

unsigned char *WJDATA_32B;

unsigned char hzm[3];
unsigned char DWJM[13];
unsigned char buf[25];

unsigned char js1;
unsigned char js2;



    if(UP_K & 0x01) //更新文件显示,文件选择0
    {

        GUI_SK0(16,16+192,255); //擦除文件显示区,192行像素

        WJDATA_32B = GUI_WJGL_XS_WJDATA_32B;
        Y = 18 - GUI_WJGL_XS_ML_WJXS_PY;
        js2 = 0;
        GUI_WJGL_XS_ML_15_WJX = 0;

        do
        {

            X = 4;
            js1 = 0;

            do
            {

                if(*WJDATA_32B == 0 || *WJDATA_32B == 0x20) goto out1; //已经没有文件数据
                ++GUI_WJGL_XS_ML_15_WJX;

                if((WJDATA_32B[0x0b] & 0xf0) == 0x10) //是文件夹
                {
                    TBXS = WJJXS1;
                }
                else //是文件
                {
                    TBXS = &WJDATA_32B[0x08];

                    hzm[0] = *TBXS;
                    ++TBXS;
                    hzm[1] = *TBXS;
                    ++TBXS;
                    hzm[2] = *TBXS;

                    if(hzm[0] == 'T' && hzm[1] == 'X' && hzm[2] == 'T') //TXT文件
                    {
                        TBXS = TXTXS1;
                    }
                    else if(hzm[0] == 'B' && hzm[1] == 'I' && hzm[2] == 'N') //BIN文件
                    {
                        TBXS = BINXS1;
                    }
                    else if(hzm[0] == 'M' && hzm[1] == 'P' && hzm[2] == '3') //音频文件
                    {
                        TBXS = MP3XS1;
                    }
                    else //未知文件
                    {
                        TBXS = XWJXS1;
                    }


                }


                if(GUI_WJGL_XS_WJXZ0_K != 0 && js2 == GUI_WJGL_XS_WJXZ0) GUI_SK1(Y,X,44,72,0x20); //写文件选择0背景色块

                GUI_32_32_XS(Y,X +(36-16),0x01,TBXS); //写文件图标
                printx(Y+32,X + (36 - (GUI_11B_chars(WJDATA_32B,DWJM) * 6 >> 1)),DWJM,125); //写文件名

                //GUI_11B_chars(WJDATA_32B,DWJM);
                //printx(Y+32,X + (36 - (strlen(DWJM) * 6 >> 1)),DWJM,125); //写文件名

                WJDATA_32B += 32;
                X += 84;
                ++js1;
                ++js2;


            }while(js1 != 3);

            Y += 48;

        }while(js2 != 15);

        out1:

    }



    if(UP_K != 0) //更新拖动条,最小化按钮,关闭按钮,上层按钮,文件选择1,标题,对象数目,窗口框
    {

        Y = (18 - GUI_WJGL_XS_ML_WJXS_PY) + (GUI_WJGL_XS_WJXZ1_ / 3 * 48); //擦除文件选择1框框
        X = 4 + (GUI_WJGL_XS_WJXZ1_ % 3 * 84);
        GUI_kuang0(Y-1,X-1,45,73,255);

        if(GUI_WJGL_XS_WJXZ1_K != 0)
        {
            Y = (18 - GUI_WJGL_XS_ML_WJXS_PY) + (GUI_WJGL_XS__WJXZ1 / 3 * 48); //写文件选择1框框
            X = 4 + (GUI_WJGL_XS__WJXZ1 % 3 * 84);
            GUI_kuang0(Y-1,X-1,45,73,0xa0);
        }


        GUI_SK0(0,1,142); //标题上横杠,1行像素
        GUI_SK0(1,15,163); //擦除标题,14行像素
        GUI_SK0(15,16,142); //标题下横杠,1行像素
        GUI_SK0(16+192,16+192+15,219); //擦除工具栏,15行像素
        GUI_SK0(16+192+15,16+192+16,142); //工具栏下横杠,1行像素
        GUI_SK1(0,0,16+192+16,1,142); //左竖杠
        GUI_SK1(0,255,16+192+16,1,142); //右竖杠
        GUI_SK1(16,255-10,192,1,142); //拖动条左竖杠


        GUI_XXX_KEY(3,255-11,GUI_WJGL_XS_XXX_KEYXZ,GUI_WJGL_XS_XXX_KEY); //写关闭按钮
        GUI_ZXH_KEY(3,255-23,GUI_WJGL_XS_ZXH_KEYXZ,GUI_WJGL_XS_ZXH_KEY); //写最小化按钮
        GUI_SC_KEY(3,255-35,GUI_WJGL_XS_SC_KEYXZ,GUI_WJGL_XS_SC_KEY);    //写上层按钮


        buf[0] = 0;
        printx(16+192+1,2,strcat(strcat(buf,"项目数:"),U32_str(GUI_WJGL_XS_ML_WJX)),64); //写项目数

        buf[0] = 0;
        if(GUI_WJGL_XS_muluX == 0)
        {
            DWJM[0] = 0;
            strcat(DWJM,GUI_WJGL_XS_mulu_DATA_32B);
        }
        else GUI_11B_chars(&GUI_WJGL_XS_mulu_DATA_32B[GUI_WJGL_XS_muluX << 5],DWJM); //写目录标题
        printx(2,2,strcat(strcat(buf,"文件管理 -> "),DWJM),255);



        GUI_SY_KEY(16,255-9,GUI_WJGL_XS_TDTSY_KEYXZ,GUI_WJGL_XS_TDTSY_KEY); //写拖动条上移按钮
        GUI_XY_KEY(16+192-7,255-9,GUI_WJGL_XS_TDTXY_KEYXZ,GUI_WJGL_XS_TDTXY_KEY); //写拖动条下移按钮

        if(GUI_WJGL_XS_TDTXZ == 0) js1 = 0x06; else js1 = 0x0f; //写拖动条滑块
        GUI_SK1(16+7,255-9,178,9,255);
        GUI_SK1(16+7+GUI_WJGL_XS_TDTWZ,255-9,13,9,js1);

    }



}


void GUI_WJGL_XS_WJXZ0_UP(unsigned char TBXZ) //更新文件管理图标选择0
{

   if(TBXZ == 255)
   {
      GUI_WJGL_XS_WJXZ0_K = 0;
   }
   else
   {
      GUI_WJGL_XS_WJXZ0 = TBXZ;
      GUI_WJGL_XS_WJXZ0_K = 1;
   }

   GUI_UPBZ(0,0,1,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新

}

void GUI_WJGL_XS_WJXZ1_UP(unsigned char TBXZ) //更新文件管理图标选择1
{

   GUI_WJGL_XS_WJXZ1_ = GUI_WJGL_XS__WJXZ1;

   if(TBXZ == 255)
   {
      GUI_WJGL_XS_WJXZ1_K = 0;
   }
   else
   {
      GUI_WJGL_XS__WJXZ1 = TBXZ;
      GUI_WJGL_XS_WJXZ1_K = 1;
   }

   GUI_UPBZ(0,0,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新

}

void GUI_WJGL_XS_ZXH_KEY_UP(unsigned char KEY) //更新文件管理最小化按钮(按下弹起)
{
   GUI_WJGL_XS_ZXH_KEY = KEY;
   GUI_UPBZ(0,0,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_WJGL_XS_ZXH_KEYXZ_UP(unsigned char KEY) //更新文件管理最小化按钮(选择)
{
   GUI_WJGL_XS_ZXH_KEYXZ = KEY;
   GUI_UPBZ(0,0,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_WJGL_XS_XXX_KEY_UP(unsigned char KEY) //更新文件管理关闭按钮(按下弹起)
{
   GUI_WJGL_XS_XXX_KEY = KEY;
   GUI_UPBZ(0,0,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_WJGL_XS_XXX_KEYXZ_UP(unsigned char KEY) //更新文件管理关闭按钮(选择)
{
   GUI_WJGL_XS_XXX_KEYXZ = KEY;
   GUI_UPBZ(0,0,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_WJGL_XS_SC_KEY_UP(unsigned char KEY) //更新文件管理上层按钮(按下弹起)
{
   GUI_WJGL_XS_SC_KEY = KEY;
   GUI_UPBZ(0,0,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_WJGL_XS_SC_KEYXZ_UP(unsigned char KEY) //更新文件管理上层按钮(选择)
{
   GUI_WJGL_XS_SC_KEYXZ = KEY;
   GUI_UPBZ(0,0,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_WJGL_XS_TDTSY_KEY_UP(unsigned char KEY) //更新文件管理拖动条上移按钮(按下弹起)
{
   GUI_WJGL_XS_TDTSY_KEY = KEY;
   GUI_UPBZ(0,0,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_WJGL_XS_TDTSY_KEYXZ_UP(unsigned char KEY) //更新文件管理拖动条上移按钮(选择)
{
   GUI_WJGL_XS_TDTSY_KEYXZ = KEY;
   GUI_UPBZ(0,0,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_WJGL_XS_TDTXY_KEY_UP(unsigned char KEY) //更新文件管理拖动条下移按钮(按下弹起)
{
   GUI_WJGL_XS_TDTXY_KEY = KEY;
   GUI_UPBZ(0,0,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_WJGL_XS_TDTXY_KEYXZ_UP(unsigned char KEY) //更新文件管理拖动条下移按钮(选择)
{
   GUI_WJGL_XS_TDTXY_KEYXZ = KEY;
   GUI_UPBZ(0,0,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_WJGL_XS_TDTXZ_UP(unsigned char KEY) //更新文件管理拖动条按钮(选择)
{
   GUI_WJGL_XS_TDTXZ = KEY;
   GUI_UPBZ(0,0,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_WJGL_XS_TDTWZ_UP(unsigned char WZ) //更新文件管理拖动条位置,WZ为偏移
{
   GUI_WJGL_XS_TDTWZ = WZ;

   if(WZ > 225) GUI_WJGL_XS_TDTWZ = 0;
   else if(WZ > 165) GUI_WJGL_XS_TDTWZ = 165;
   
   GUI_UPBZ(0,0,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_WJGL_XS_TDTWZ_AS_UP(unsigned char ASY) //更新文件管理拖动条位置,ASY为鼠标Y坐标补码
{
unsigned char js1;

   js1 = GUI_WJGL_XS_TDTWZ;
   GUI_WJGL_XS_TDTWZ += ASY;

   if(ASY > 127) //负数
   {
      if(GUI_WJGL_XS_TDTWZ > js1) GUI_WJGL_XS_TDTWZ = 0;
   }
   else //正数
   {
      if(GUI_WJGL_XS_TDTWZ > 165 || GUI_WJGL_XS_TDTWZ < js1) GUI_WJGL_XS_TDTWZ = 165;
   }

   GUI_UPBZ(0,0,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_WJGL_XS_ML_WJX_UP(unsigned long int X) //更新文件管理文件总数显示
{
   GUI_WJGL_XS_ML_WJX = X;
   GUI_UPBZ(0,0,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_WJGL_XS_ML_WJXS_PY_UP(unsigned char X) //更新文件管理文件图标显示区像素偏移
{
   GUI_WJGL_XS_ML_WJXS_PY = X;
   GUI_UPBZ(0,0,1,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

unsigned char *GUI_WJGL_XS_WJDATA_32B_UP() //更新文件管理文件的32个字节文件符数据
{
   GUI_UPBZ(0,0,1,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
   return GUI_WJGL_XS_WJDATA_32B;
}


void GUI_BOOT_WJGL(unsigned char device) //启动文件管理
{

unsigned char buf[512];


   if(DEVICE_RD_512B(device,0,buf) == 0) //FAT32读设备512个字节失败(文件系统没有初始化或设备错误)
   {
       if(device < 2) TF_SD_CSH(device); //为SPI存储器,初始化该设备
       if(FAT32_csh(device) == 0);  //初始化该设备的FAT32文件系统
   }


   GUI_WJGL_XS_DEVICE = device; //记录设备

   GUI_WJGL_XS_mulu_DATA_32B[0] = 0;

        if(device == 0) strcat(GUI_WJGL_XS_mulu_DATA_32B,"SPI存储器0");
   else if(device == 1) strcat(GUI_WJGL_XS_mulu_DATA_32B,"SPI存储器1");
   else if(device == 2) strcat(GUI_WJGL_XS_mulu_DATA_32B,"USB存储器0");
   else if(device == 3) strcat(GUI_WJGL_XS_mulu_DATA_32B,"USB存储器1");
   else if(device == 4) strcat(GUI_WJGL_XS_mulu_DATA_32B,"USB存储器2");
   else if(device == 5) strcat(GUI_WJGL_XS_mulu_DATA_32B,"USB存储器3");


   GUI_WJGL_XS_mulu_DATA_32B[0x15] = 0x00; //设置目录首簇号
   GUI_WJGL_XS_mulu_DATA_32B[0x14] = 0x00;
   GUI_WJGL_XS_mulu_DATA_32B[0x1b] = 0x00;
   GUI_WJGL_XS_mulu_DATA_32B[0x1a] = 0x02;

   GUI_WJGL_GET_WJDATA_32B_BZ = 1; //请求数据标志,为1刷新15个文件的32个字节文件符数据
   GUI_WJGL_GET_WJDATA_32B_WJH = 0; //请求数据,首文件号
   GUI_WJGL_GET_WJX_BZ = 1; //为1刷新目录下的总文件数量


   GUI_WJGL_XS_muluX = 0; //目录层数计数指向第0层
   GUI_WJGL_XS_WJDATA_32B[0] = 0; //文件的32个字节文件符数据为0

   GUI_WJGL_XS_WJXZ0 = 0;  //文件选择0,文件图标背景色块,鼠标点击才选择,0~14
   GUI_WJGL_XS_WJXZ0_K = 0; //文件选择0,文件图标背景色块显示控制,为1显示,为0不显示

   GUI_WJGL_XS__WJXZ1 = 0; //文件选择1,选择框,跟随鼠标选择,新值,0~14
   GUI_WJGL_XS_WJXZ1_ = 0;  //文件选择1,选择框,跟随鼠标选择,旧值,0~14
   GUI_WJGL_XS_WJXZ1_K = 0; //文件选择1,文件图标选择框显示控制,为1显示,为0不显示

   GUI_WJGL_XS_ZXH_KEY = 0; //最小化按钮,按下为1,否则为0
   GUI_WJGL_XS_ZXH_KEYXZ = 0; //最小化按钮选择,为1选中
   GUI_WJGL_XS_XXX_KEY = 0; //关闭按钮,按下为1,否则为0
   GUI_WJGL_XS_XXX_KEYXZ = 0; //关闭按钮选择,为1选中

   GUI_WJGL_XS_SC_KEY = 0; //上层按钮,按下为1,否则为0
   GUI_WJGL_XS_SC_KEYXZ = 0; //上层按钮选择,为1选中

   GUI_WJGL_XS_TDTSY_KEY = 0; //拖动条上移按钮,按下为1,否则为0
   GUI_WJGL_XS_TDTXY_KEY = 0; //拖动条下移按钮,按下为1,否则为0
   GUI_WJGL_XS_TDTSY_KEYXZ = 0; //拖动条上移按钮选择,为1选中
   GUI_WJGL_XS_TDTXY_KEYXZ = 0; //拖动条下移按钮选择,为1选中
   GUI_WJGL_XS_TDTWZ = 0; //拖动条位置,偏移值
   GUI_WJGL_XS_TDTXZ = 0; //拖动条滑块选择,为1选中

   GUI_WJGL_XS_ML_WJX = 0; //目录文件总数
   GUI_WJGL_XS_ML_WJXS_PY = 0; //文件图标显示区像素偏移

   GUI_GBCK(0,0); //关闭窗口
   GUI_CJCK(0,0); //创建窗口


}




void GUI_WJGL_ML_R() //返回上一层目录
{

   if(GUI_WJGL_XS_muluX != 0)
   {

       --GUI_WJGL_XS_muluX; //目录层数计数指向上一层目录

       GUI_WJGL_GET_WJDATA_32B_BZ = 1; //请求数据标志,为1刷新15个文件的32个字节文件符数据
       GUI_WJGL_GET_WJDATA_32B_WJH = 0; //请求数据,首文件号
       GUI_WJGL_GET_WJX_BZ = 1; //为1刷新目录下的总文件数量

       GUI_WJGL_XS_WJDATA_32B[0] = 0; //文件的32个字节文件符数据为0

       GUI_WJGL_XS_WJXZ0 = 0;  //文件选择0,文件图标背景色块,鼠标点击才选择,0~14
       GUI_WJGL_XS_WJXZ0_K = 0; //文件选择0,文件图标背景色块显示控制,为1显示,为0不显示

       GUI_WJGL_XS__WJXZ1 = 0; //文件选择1,选择框,跟随鼠标选择,新值,0~14
       GUI_WJGL_XS_WJXZ1_ = 0;  //文件选择1,选择框,跟随鼠标选择,旧值,0~14
       GUI_WJGL_XS_WJXZ1_K = 0; //文件选择1,文件图标选择框显示控制,为1显示,为0不显示

       GUI_WJGL_XS_TDTWZ = 0; //拖动条位置,偏移值

       GUI_WJGL_XS_ML_WJX = 0; //目录文件总数
       GUI_WJGL_XS_ML_WJXS_PY = 0; //文件图标显示区像素偏移

       GUI_UPBZ(0,0,1,1); //置更新标志,刷新窗口内容
       GUI_UP_K = 1; //打开GUI更新

   }

}




unsigned char GUI_WJGL_KEY_BJ1(unsigned char TBXZ) //文件管理-键,部件1
{
   return TBXZ < GUI_WJGL_XS_ML_15_WJX;
}

void GUI_WJGL_BJ2(unsigned char K) //文件管理-键,部件2
{

unsigned char js1;
unsigned long int js4;
unsigned long int js5;

   js4 = (GUI_WJGL_XS_ML_WJX / 3 + (GUI_WJGL_XS_ML_WJX % 3 != 0)) * 48; //算出总像素数
   if(js4 < 192) js4 = 0;else js4 -= 192; //算出余下像素数
   js4 = ((js4 << 8) / 165 * GUI_WJGL_XS_TDTWZ) >> 8; //算出偏移像素

   js1 = js4 % 48;

   if((js5 = js4 / 48 * 3) != GUI_WJGL_GET_WJDATA_32B_WJH || K != 0) //新首文件号和旧首文件号不同
   {
       GUI_WJGL_GET_WJDATA_32B_WJH = js5;
       GUI_WJGL_GET_WJDATA_32B_BZ = 1;    //启动刷新32个字节文件符数据
       GUI_WJGL_XS_ML_WJXS_PY = js1; //更新文件管理文件图标显示区像素偏移(等待文件符数据到了再更新)
   }
   else
   {
       GUI_WJGL_XS_ML_WJXS_PY_UP(js1); //更新文件管理文件图标显示区像素偏移
   }

}

unsigned char GUI_WJGL_KEY(unsigned char SB_K,unsigned char KEY_K) //文件管理-键
{

unsigned char NOACC;
unsigned char js1;
unsigned char js2;
unsigned char js3;



    if(SB_K != 0 && GUI_SBZBPD(0,255-16,0,255) != 0) //鼠标坐标在窗口范围内
    {

        if(GUI_WJGL_KEY_KXZ[22] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_WJGL_KEY_KXZ[22] = 1; //弹起指向第1步
        }
        else if(GUI_WJGL_KEY_KXZ[22] == 1)
        {
            if(GUI_SB_L_KEY() != 0)
            {
                GUI_WJGL_KEY_KXZ[22] = 2; //按下指向第2步
                GUI_QZCK(0,0); //前置窗口
            }
        }
        else if(GUI_WJGL_KEY_KXZ[22] == 2)
        {
            if(GUI_SB_L_KEY() == 0)
            {
                GUI_WJGL_KEY_KXZ[22] = 1; //弹起指向第1步
            }
        }

    }
    else
    {

        GUI_WJGL_KEY_KXZ[22] = 0;

    }


    if(SB_K != 0 && GUI_SBZBPD(3,3+8,255-11,255-11+8) != 0) //鼠标坐标在文件管理关闭按钮范围内
    {
        if(GUI_WJGL_KEY_IO[0] == 0)
        {
           GUI_WJGL_XS_XXX_KEYXZ_UP(1); //更新文件管理关闭按钮(选择)
           GUI_WJGL_KEY_IO[0] = 1;
        }

        if(GUI_WJGL_KEY_KXZ[0] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_WJGL_KEY_KXZ[0] = 1; //弹起指向第1步
        }
        else if(GUI_WJGL_KEY_KXZ[0] == 1)
        {
            if(GUI_SB_L_KEY() != 0)
            {
                GUI_WJGL_KEY_KXZ[0] = 2; //按下指向第2步
                GUI_WJGL_XS_XXX_KEY_UP(1); //更新文件管理关闭按钮(按下弹起)
            }
        }
        else if(GUI_WJGL_KEY_KXZ[0] == 2)
        {
            if(GUI_SB_L_KEY() == 0)
            {
                GUI_WJGL_KEY_KXZ[0] = 1; //弹起指向第1步
                GUI_WJGL_XS_XXX_KEY_UP(0); //更新文件管理关闭按钮(按下弹起)
                GUI_GBCK(0,0); //关闭窗口
            }
        }

    }
    else
    {
        if(GUI_WJGL_KEY_IO[0] != 0)
        {
           GUI_WJGL_XS_XXX_KEYXZ_UP(0); //更新文件管理关闭按钮(选择)
           GUI_WJGL_KEY_IO[0] = 0;
        }

        if(GUI_WJGL_KEY_KXZ[0] != 0)
        {
           GUI_WJGL_XS_XXX_KEY_UP(0); //更新文件管理关闭按钮(按下弹起)
           GUI_WJGL_KEY_KXZ[0] = 0;
        }

    }


    if(SB_K != 0 && GUI_SBZBPD(3,3+8,255-23,255-23+8) != 0) //鼠标坐标在文件管理最小化按钮范围内
    {
        if(GUI_WJGL_KEY_IO[1] == 0)
        {
           GUI_WJGL_XS_ZXH_KEYXZ_UP(1); //更新文件管理最小化按钮(选择)
           GUI_WJGL_KEY_IO[1] = 1;
        }

        if(GUI_WJGL_KEY_KXZ[1] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_WJGL_KEY_KXZ[1] = 1; //弹起指向第1步
        }
        else if(GUI_WJGL_KEY_KXZ[1] == 1)
        {
            if(GUI_SB_L_KEY() != 0)
            {
                GUI_WJGL_KEY_KXZ[1] = 2; //按下指向第2步
                GUI_WJGL_XS_ZXH_KEY_UP(1); //更新文件管理最小化按钮(按下弹起)
            }
        }
        else if(GUI_WJGL_KEY_KXZ[1] == 2)
        {
            if(GUI_SB_L_KEY() == 0)
            {
                GUI_WJGL_KEY_KXZ[1] = 1; //弹起指向第1步
                GUI_WJGL_XS_ZXH_KEY_UP(0); //更新文件管理最小化按钮(按下弹起)
                GUI_ZXHCK(0,0); //最小化窗口
            }
        }

    }
    else
    {
        if(GUI_WJGL_KEY_IO[1] != 0)
        {
           GUI_WJGL_XS_ZXH_KEYXZ_UP(0); //更新文件管理最小化按钮(选择)
           GUI_WJGL_KEY_IO[1] = 0;
        }

        if(GUI_WJGL_KEY_KXZ[1] != 0)
        {
           GUI_WJGL_XS_ZXH_KEY_UP(0); //更新文件管理最小化按钮(按下弹起)
           GUI_WJGL_KEY_KXZ[1] = 0;
        }

    }


    if(SB_K != 0 && GUI_SBZBPD(3,3+8,255-35,255-35+8) != 0) //鼠标坐标在文件管理上层按钮范围内
    {
        if(GUI_WJGL_KEY_IO[2] == 0)
        {
           GUI_WJGL_XS_SC_KEYXZ_UP(1); //更新文件管理上层按钮(选择)
           GUI_WJGL_KEY_IO[2] = 1;
        }

        if(GUI_WJGL_KEY_KXZ[2] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_WJGL_KEY_KXZ[2] = 1; //弹起指向第1步
        }
        else if(GUI_WJGL_KEY_KXZ[2] == 1)
        {
            if(GUI_SB_L_KEY() != 0)
            {
                GUI_WJGL_KEY_KXZ[2] = 2; //按下指向第2步
                GUI_WJGL_XS_SC_KEY_UP(1); //更新文件管理上层按钮(按下弹起)
            }
        }
        else if(GUI_WJGL_KEY_KXZ[2] == 2)
        {
            if(GUI_SB_L_KEY() == 0)
            {
                GUI_WJGL_KEY_KXZ[2] = 1; //弹起指向第1步
                GUI_WJGL_XS_SC_KEY_UP(0); //更新文件管理上层按钮(按下弹起)
                GUI_WJGL_ML_R(); //返回上一层目录
            }
        }

    }
    else
    {
        if(GUI_WJGL_KEY_IO[2] != 0)
        {
           GUI_WJGL_XS_SC_KEYXZ_UP(0); //更新文件管理上层按钮(选择)
           GUI_WJGL_KEY_IO[2] = 0;
        }

        if(GUI_WJGL_KEY_KXZ[2] != 0)
        {
           GUI_WJGL_XS_SC_KEY_UP(0); //更新文件管理上层按钮(按下弹起)
           GUI_WJGL_KEY_KXZ[2] = 0;
        }

    }


    if(SB_K != 0 && GUI_SBZBPD(16,16+6,255-9,255-9+8) != 0) //鼠标坐标在文件管理拖动条上移按钮范围内
    {
        if(GUI_WJGL_KEY_IO[3] == 0)
        {
           GUI_WJGL_XS_TDTSY_KEYXZ_UP(1); //更新文件管理拖动条上移按钮(选择)
           GUI_WJGL_KEY_IO[3] = 1;
        }

        if(GUI_WJGL_KEY_KXZ[3] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_WJGL_KEY_KXZ[3] = 1; //弹起指向第1步
        }
        else if(GUI_WJGL_KEY_KXZ[3] == 1)
        {
            if(GUI_SB_L_KEY() != 0)
            {
                GUI_WJGL_KEY_KXZ[3] = 2; //按下指向第2步
                GUI_WJGL_XS_TDTSY_KEY_UP(1); //更新文件管理拖动条上移按钮(按下弹起)
            }
        }
        else if(GUI_WJGL_KEY_KXZ[3] == 2)
        {
            if(GUI_SB_L_KEY() == 0)
            {
                GUI_WJGL_KEY_KXZ[3] = 1; //弹起指向第1步
                GUI_WJGL_XS_TDTSY_KEY_UP(0); //更新文件管理拖动条上移按钮(按下弹起)
                GUI_WJGL_XS_TDTWZ_AS_UP(255); //更新文件管理拖动条位置,ASY为鼠标Y坐标补码
                GUI_WJGL_BJ2(0); //文件管理-键,部件2
            }
        }

    }
    else
    {
        if(GUI_WJGL_KEY_IO[3] != 0)
        {
           GUI_WJGL_XS_TDTSY_KEYXZ_UP(0); //更新文件管理拖动条上移按钮(选择)
           GUI_WJGL_KEY_IO[3] = 0;
        }

        if(GUI_WJGL_KEY_KXZ[3] != 0)
        {
           GUI_WJGL_XS_TDTSY_KEY_UP(0); //更新文件管理拖动条上移按钮(按下弹起)
           GUI_WJGL_KEY_KXZ[3] = 0;
        }

    }


    if(SB_K != 0 && GUI_SBZBPD(240-32-7,240-32-7+6,255-9,255-9+8) != 0) //鼠标坐标在文件管理拖动条下移按钮范围内
    {
        if(GUI_WJGL_KEY_IO[4] == 0)
        {
           GUI_WJGL_XS_TDTXY_KEYXZ_UP(1); //更新文件管理拖动条下移按钮(选择)
           GUI_WJGL_KEY_IO[4] = 1;
        }

        if(GUI_WJGL_KEY_KXZ[4] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_WJGL_KEY_KXZ[4] = 1; //弹起指向第1步
        }
        else if(GUI_WJGL_KEY_KXZ[4] == 1)
        {
            if(GUI_SB_L_KEY() != 0)
            {
                GUI_WJGL_KEY_KXZ[4] = 2; //按下指向第2步
                GUI_WJGL_XS_TDTXY_KEY_UP(1); //更新文件管理拖动条下移按钮(按下弹起)
            }
        }
        else if(GUI_WJGL_KEY_KXZ[4] == 2)
        {
            if(GUI_SB_L_KEY() == 0)
            {
                GUI_WJGL_KEY_KXZ[4] = 1; //弹起指向第1步
                GUI_WJGL_XS_TDTXY_KEY_UP(0); //更新文件管理拖动条下移按钮(按下弹起)
                GUI_WJGL_XS_TDTWZ_AS_UP(1); //更新文件管理拖动条位置,ASY为鼠标Y坐标补码
                GUI_WJGL_BJ2(0); //文件管理-键,部件2
            }
        }

    }
    else
    {
        if(GUI_WJGL_KEY_IO[4] != 0)
        {
           GUI_WJGL_XS_TDTXY_KEYXZ_UP(0); //更新文件管理拖动条下移按钮(选择)
           GUI_WJGL_KEY_IO[4] = 0;
        }

        if(GUI_WJGL_KEY_KXZ[4] != 0)
        {
           GUI_WJGL_XS_TDTXY_KEY_UP(0); //更新文件管理拖动条下移按钮(按下弹起)
           GUI_WJGL_KEY_KXZ[4] = 0;
        }

    }


    if(SB_K != 0 && (GUI_SBZBPD(16+7,16+7+177,255-9,255-9+8) != 0 || GUI_WJGL_KEY_KXZ[5] == 2)) //鼠标坐标在文件管理拖动条范围内
    {
        if(GUI_WJGL_KEY_IO[5] == 0)
        {
           GUI_WJGL_XS_TDTXZ_UP(1); //更新文件管理拖动条按钮(选择)
           GUI_WJGL_KEY_IO[5] = 1;
        }

        if(GUI_WJGL_KEY_KXZ[5] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_WJGL_KEY_KXZ[5] = 1; //弹起指向第1步
        }
        else if(GUI_WJGL_KEY_KXZ[5] == 1)
        {
            if(GUI_SB_L_KEY() != 0)
            {
                GUI_WJGL_KEY_KXZ[5] = 2; //按下指向第2步
                GUI_WJGL_XS_TDTWZ_UP(GUI_SB_GET_Y() - (16+7+7)); //更新文件管理拖动条位置,WZ为偏移
                GUI_WJGL_BJ2(0); //文件管理-键,部件2
            }
        }
        else if(GUI_WJGL_KEY_KXZ[5] == 2)
        {
            if(GUI_SBZBPD(16+7,16+7+177,0,255) != 0 && GUI_SB_GET_AS_Y() != 0)
            {
                GUI_WJGL_XS_TDTWZ_UP(GUI_SB_GET_Y() - (16+7+7)); //更新文件管理拖动条位置,WZ为偏移
                GUI_WJGL_BJ2(0); //文件管理-键,部件2
            }

            if(GUI_SB_L_KEY() == 0)
            {
                GUI_WJGL_KEY_KXZ[5] = 1; //弹起指向第1步
            }
        }

    }
    else
    {
        if(GUI_WJGL_KEY_IO[5] != 0)
        {
           GUI_WJGL_XS_TDTXZ_UP(0); //更新文件管理拖动条按钮(选择)
           GUI_WJGL_KEY_IO[5] = 0;
        }

        GUI_WJGL_KEY_KXZ[5] = 0;

    }





    NOACC = 0;
    js1 = 0;
    js2 = 0;
    js3 = 0;

    do
    {



        if(SB_K != 0 && GUI_SBZBPD(16,16+191,0,255) != 0 && GUI_SBZBPD(18-GUI_WJGL_XS_ML_WJXS_PY+(js3*48),18-GUI_WJGL_XS_ML_WJXS_PY+43+(js3*48),4+(js2*84),4+71+(js2*84)) != 0 && GUI_WJGL_KEY_BJ1(js1) != 0) //鼠标坐标在图标范围内
        {

            if(GUI_WJGL_KEY_IO[6+js1] == 0)
            {
               GUI_WJGL_XS_WJXZ1_UP(js1); //更新文件管理图标选择1
               GUI_WJGL_KEY_IO[6+js1] = 1;
            }

            if(GUI_WJGL_KEY_KXZ[6+js1] == 0)
            {
                if(GUI_SB_L_KEY() == 0) GUI_WJGL_KEY_KXZ[6+js1] = 1; //弹起指向第1步
            }
            else if(GUI_WJGL_KEY_KXZ[6+js1] == 1)
            {
                if(GUI_SB_L_KEY() != 0) GUI_WJGL_KEY_KXZ[6+js1] = 2; //按下指向第2步
            }
            else if(GUI_WJGL_KEY_KXZ[6+js1] == 2)
            {
                if(GUI_SB_L_KEY() == 0)
                {
                    GUI_WJGL_KEY_KXZ[6+js1] = 3; //弹起指向第3步
                    GUI_WJGL_XS_WJXZ0_UP(js1); //更新文件管理图标选择0
                }
            }
            else if(GUI_WJGL_KEY_KXZ[6+js1] == 3)
            {
                if(GUI_SB_L_KEY() != 0) GUI_WJGL_KEY_KXZ[6+js1] = 4; //按下指向第4步
            }
            else if(GUI_WJGL_KEY_KXZ[6+js1] == 4)
            {
                if(GUI_SB_L_KEY() == 0)
                {
                    GUI_WJGL_KEY_KXZ[6+js1] = 3; //弹起指向第3步(这里启动程序)
                    GUI_WJGL_ML_IN(js1); //进入当前目录下的文件或文件夹
                }
            }



            if(GUI_WJGL_KEY_KXZ[23+js1] == 0)
            {
                if(GUI_SB_R_KEY() == 0) GUI_WJGL_KEY_KXZ[23+js1] = 1; //弹起指向第1步
            }
            else if(GUI_WJGL_KEY_KXZ[23+js1] == 1)
            {
                if(GUI_SB_R_KEY() != 0) GUI_WJGL_KEY_KXZ[23+js1] = 2; //按下指向第2步
            }
            else if(GUI_WJGL_KEY_KXZ[23+js1] == 2)
            {
                if(GUI_SB_R_KEY() == 0)
                {
                    GUI_WJGL_KEY_KXZ[23+js1] = 1; //弹起指向第1步
                    GUI_WJGL_XS_WJXZ0_UP(js1); //更新文件管理图标选择0
                    GUI_WJGL_BOOT_CD(1); //启动文件管理-菜单
                }
            }


        }
        else
        {

            GUI_WJGL_KEY_IO[6+js1] = 0;
            GUI_WJGL_KEY_KXZ[6+js1] = 0;
            GUI_WJGL_KEY_KXZ[23+js1] = 0;
            ++NOACC;

        }



        if(++js2 == 3) js2 = 0,++js3;

    }while(++js1 != 15);



    if(NOACC == 15) //没有落在15个图标内的任何一个
    {

        if(GUI_WJGL_KEY_IO[21] != 0)
        {
           GUI_WJGL_XS_WJXZ1_UP(255); //更新文件管理图标选择1
           GUI_WJGL_KEY_IO[21] = 0;
        }


        if(SB_K != 0)
        {

            if(GUI_WJGL_KEY_KXZ[21] == 0)
            {
                if(GUI_SB_L_KEY() == 0) GUI_WJGL_KEY_KXZ[21] = 1; //弹起指向第1步
            }
            else if(GUI_WJGL_KEY_KXZ[21] == 1)
            {
                if(GUI_SB_L_KEY() != 0) GUI_WJGL_KEY_KXZ[21] = 2; //按下指向第2步
            }
            else if(GUI_WJGL_KEY_KXZ[21] == 2)
            {
                if(GUI_SB_L_KEY() == 0)
                {
                    GUI_WJGL_KEY_KXZ[21] = 1; //弹起指向第1步
                    if(GUI_WJGL_XS_WJXZ0_K != 0) GUI_WJGL_XS_WJXZ0_UP(255); //更新文件管理图标选择0
                }
            }


            if(GUI_WJGL_KEY_KXZ[38] == 0)
            {
                if(GUI_SB_R_KEY() == 0) GUI_WJGL_KEY_KXZ[38] = 1; //弹起指向第1步
            }
            else if(GUI_WJGL_KEY_KXZ[38] == 1)
            {
                if(GUI_SB_R_KEY() != 0) GUI_WJGL_KEY_KXZ[38] = 2; //按下指向第2步
            }
            else if(GUI_WJGL_KEY_KXZ[38] == 2)
            {
                if(GUI_SB_R_KEY() == 0)
                {
                    GUI_WJGL_KEY_KXZ[38] = 1; //弹起指向第1步
                    GUI_WJGL_BOOT_CD(0); //启动文件管理-菜单
                }
            }


        }
        else
        {
            GUI_WJGL_KEY_KXZ[21] = 0;
            GUI_WJGL_KEY_KXZ[38] = 0;
        }


    }
    else //有落在某个图标
    {
        GUI_WJGL_KEY_IO[21] = 1;
        GUI_WJGL_KEY_KXZ[21] = 0;
        GUI_WJGL_KEY_KXZ[38] = 0;
    }




    return SB_K != 0 && GUI_SBZBPD(0,255-16,0,255) != 0; //落在窗口内返回非0

}



void GUI_WJGL_RUN() //文件管理-后台运行
{

unsigned long int mulu_cuhao;
unsigned char *_addr;
unsigned char buf[512];
unsigned char js1;
unsigned char js2;
unsigned char js3;
unsigned long int js4;



    if((GUI_WJGL_GET_WJDATA_32B_BZ | GUI_WJGL_GET_WJX_BZ) != 0)
    {
        _addr = &GUI_WJGL_XS_mulu_DATA_32B[GUI_WJGL_XS_muluX << 5];

        mulu_cuhao = _addr[0x15]; //记录目录首簇号
        mulu_cuhao <<= 8;
        mulu_cuhao |= _addr[0x14];
        mulu_cuhao <<= 8;
        mulu_cuhao |= _addr[0x1b];
        mulu_cuhao <<= 8;
        mulu_cuhao |= _addr[0x1a];


        if(GUI_WJGL_GET_WJDATA_32B_BZ != 0)
        {
            GUI_WJGL_GET_WJDATA_32B_BZ = 0;
            FAT32_ML_WJCX1(GUI_WJGL_XS_DEVICE,mulu_cuhao,GUI_WJGL_GET_WJDATA_32B_WJH+1,GUI_WJGL_GET_WJDATA_32B_WJH+15,GUI_WJGL_XS_WJDATA_32B_UP()); //FAT32文件查询2,device选择设备,mulu_cuhao为目录的首簇号,qs为首文件号,js为结束文件号,return_data为返回文件信息数据,按顺序以32个字节为一段,返回值不为0表示操作成功; 需要取得总文件数量时,qs、js、return_data置0,调用此函数返回文件总数量; 需要确认文件数量时,qs、return_data置0,js置文件数量,调用此函数返回值为小于等于js
        }

        if(GUI_WJGL_GET_WJX_BZ != 0)
        {
            GUI_WJGL_GET_WJX_BZ = 0;
            GUI_WJGL_XS_ML_WJX_UP(FAT32_ML_WJCX1(GUI_WJGL_XS_DEVICE,mulu_cuhao,0,0,0)); //更新文件管理文件总数显示
        }

    }


    js1 = FAT32_ML_XGWJDX_RUN(); //运行修改文件大小,返回值0错误,1继续,2完成,3存储设备空间不足,4空闲
    js1 = FAT32_ML_XGWJM_RUN(); //运行修改文件名,返回值0错误,1继续,2完成,3存储设备空间不足,4空闲


    js1 = FAT32_ML_DELETE_WJ_RUN(); //运行目录删除文件,返回值0错误,1继续,2完成,4空闲


    if(js1 == 0) //设备或文件错误
    {
        if(GUI_WJGL_QDBIN_BZ != 0) GUI_WJGL_QDBIN_BZ = 0; //关闭系统正在启动BIN文件标志
    }
    else if(js1 == 1) //继续
    {
    }
    else if(js1 == 2) //完成
    {

        if(FAT32_ML_DELETE_WJ_DEVICE == GUI_WJGL_XS_DEVICE && FAT32_ML_DELETE_WJ_mulu_cuhao == mulu_cuhao) //删除的文件所在设备和目录首簇号和现行文件管理位置相同
        {
            --GUI_WJGL_XS_ML_WJX; //文件总数+1
            GUI_WJGL_BJ2(1); //更新文件管理
        }

        if(GUI_WJGL_QDBIN_BZ == 1) //正在启动BIN文件
        {
             if(FAT32_ML_SETUP_WJ(GUI_WJGL_QDBIN_YDWB_DEVICE,0x00000002,GUI_WJGL_QDBIN_LJCD,"KC_LS1u_boot_1.txt",0x20) == 0) //初始化目录创建文件,创建失败
             {
                  GUI_WJGL_QDBIN_BZ = 0; //关闭系统正在启动BIN文件的标志
             }
        }
    }





    js1 = FAT32_ML_SETUP_WJ_RUN(); //运行目录创建文件,返回值0错误,1继续,2完成,3存储设备空间不足,4空闲


    if(js1 == 0) //设备或文件错误
    {
        if(GUI_WJGL_QDBIN_BZ != 0) GUI_WJGL_QDBIN_BZ = 0; //关闭系统正在启动BIN文件标志
    }
    else if(js1 == 1) //继续
    {
    }
    else if(js1 == 2) //完成
    {

        if(GUI_WJGL_QDBIN_BZ == 1) //正在启动BIN文件
        {
            if((js1 = FAT32_GET_VOID_RWWJ_BZ(GUI_WJGL_QDBIN_YDWB_DEVICE)) != 255) //申请文件号
            {
                if(FAT32_OPENWJ(GUI_WJGL_QDBIN_YDWB_DEVICE,0x00000002,js1,"KC_LS1u_boot_1.txt") != 0) //打开"KC_LS1u_boot_1.txt"文件
                {
                    FAT32_WRWJ_512B(GUI_WJGL_QDBIN_YDWB_DEVICE,js1,GUI_WJGL_QDBIN_LJ); //启动路径写入"KC_LS1u_boot_1.txt"文件
                    sys_in_boot_1(); //启动程序
                }
                else //打开"KC_LS1u_boot_1.txt"文件失败
                {
                    GUI_WJGL_QDBIN_BZ = 0; //撤销正在启动BIN文件标志
                }
            }
            else //申请文件号失败
            {
                GUI_WJGL_QDBIN_BZ = 0; //撤销正在启动BIN文件标志
            }
        }


        _addr = &GUI_WJGL_XS_mulu_DATA_32B[GUI_WJGL_XS_muluX << 5];

        mulu_cuhao = _addr[0x15]; //记录目录首簇号
        mulu_cuhao <<= 8;
        mulu_cuhao |= _addr[0x14];
        mulu_cuhao <<= 8;
        mulu_cuhao |= _addr[0x1b];
        mulu_cuhao <<= 8;
        mulu_cuhao |= _addr[0x1a];

        if(FAT32_ML_SETUP_WJ_DEVICE == GUI_WJGL_XS_DEVICE && FAT32_ML_SETUP_WJ_mulu_cuhao == mulu_cuhao) //创建的文件所在设备和目录首簇号和现行文件管理位置相同
        {
            ++GUI_WJGL_XS_ML_WJX; //文件总数+1
            GUI_WJGL_XS_TDTWZ = 165; //文件管理拖动条位置设置为末尾
            GUI_WJGL_BJ2(1); //更新文件管理
        }


        if(GUI_WJGL_FZWJ_K != 0) //加入复制文件
        {
            GUI_WJGL_FZWJ_K = 0;



            if((js1 = FAT32_GET_VOID_RWWJ_BZ(GUI_WJGL_CD_ZT_S_DEVICE)) != 255) //申请源文件的文件号
            {

                if(FAT32_OPENWJ(GUI_WJGL_CD_ZT_S_DEVICE,GUI_WJGL_CD_ZT_S_mulu_cuhao,js1,GUI_WJGL_CD_ZT_S_WJM) != 0) //打开源文件
                {

                    if((js2 = FAT32_GET_VOID_RWWJ_BZ(FAT32_ML_SETUP_WJ_DEVICE)) != 255) //申请目标文件的文件号
                    {

                        GUI_11B_chars(FAT32_ML_SETUP_WJ_WJFDATA_32B,buf); //提取目标文件的文件名

                        if(FAT32_OPENWJ(FAT32_ML_SETUP_WJ_DEVICE,FAT32_ML_SETUP_WJ_mulu_cuhao,js2,buf) != 0) //打开目标文件
                        {

                            js3 = 0;
                            while(GUI_WJGL_FZWJ_BZ[js3] != 255)  ++js3; //查找复制文件表空位,找到空位后加入项目

                            GUI_WJGL_FZWJ_BZ[js3] = js3; //文件管理-复制文件表标志,不为255表示有项目
                            GUI_WJGL_FZWJ_S_DEVICE[js3] = GUI_WJGL_CD_ZT_S_DEVICE; //文件管理-复制文件表,源文件设备号
                            GUI_WJGL_FZWJ_S_WJH[js3] = js1; //文件管理-复制文件表,源文件文件号
                            GUI_WJGL_FZWJ_D_DEVICE[js3] = FAT32_ML_SETUP_WJ_DEVICE; //文件管理-复制文件表,目的文件设备号
                            GUI_WJGL_FZWJ_D_WJH[js3] = js2; //文件管理-复制文件表,目的文件文件号

                            ++GUI_WJGL_FZWJ_X; //复制文件表项目计数+1

                            GUI_BOOT_WJGL_JDT(js3,0,FAT32_ML_SETUP_WJ_DEVICE,buf); //启动文件管理-进度条
                            GUI_WJGL_FZWJ_101_DIVZ[js3] = FAT32_RETURN_WJDX_(FAT32_ML_SETUP_WJ_DEVICE,js2) / 101; //计算101刻度除子
                            GUI_WJGL_FZWJ_A[js3] = 0; //已复制大小清0
                            GUI_WJGL_FZWJ_A_[js3] = 0; //已复制大小清0

                        }
                        else //打开目标文件失败
                        {
                        }

                    }
                    else //申请目标文件的文件号失败
                    {
                    }

                }
                else //打开源文件失败
                {
                }

            }
            else //申请源文件的文件号失败
            {
            }




        }



    }
    else if(js1 == 3) //存储设备空间不足
    {
        if(GUI_WJGL_QDBIN_BZ != 0) GUI_WJGL_QDBIN_BZ = 0; //关闭系统正在启动BIN文件标志
    }




    if(GUI_WJGL_FZWJ_X != 0) //有项目则进入
    {

        while(GUI_WJGL_FZWJ_BZ[GUI_WJGL_FZWJ_SMZZ] == 255) if(++GUI_WJGL_FZWJ_SMZZ == GUI_WJGL_FZWJ_WJX) GUI_WJGL_FZWJ_SMZZ = 0; //查找下一个需要复制的项目

        js1 = FAT32_RDWJ_512B(GUI_WJGL_FZWJ_S_DEVICE[GUI_WJGL_FZWJ_SMZZ],GUI_WJGL_FZWJ_S_WJH[GUI_WJGL_FZWJ_SMZZ],buf); //读源文件512字节到缓冲区
        js2 = FAT32_WRWJ_512B(GUI_WJGL_FZWJ_D_DEVICE[GUI_WJGL_FZWJ_SMZZ],GUI_WJGL_FZWJ_D_WJH[GUI_WJGL_FZWJ_SMZZ],buf); //缓冲区数据写入目标文件

        if(js1 == 2 && js2 == 2) //文件复制完成
        {
            GUI_WJGL_FZWJ_BZ[GUI_WJGL_FZWJ_SMZZ] = 255; //清除标志
            --GUI_WJGL_FZWJ_X; //项目计数减1
            GUI_GB_WJGL_JDT(GUI_WJGL_FZWJ_SMZZ); //关闭文件管理-进度条
        }
        else if(js1 == 1 && js2 == 1) //文件复制中
        {
            js4 = GUI_WJGL_FZWJ_A[GUI_WJGL_FZWJ_SMZZ];
            js4 += 512; //传输累计增加512字节
            GUI_WJGL_FZWJ_A[GUI_WJGL_FZWJ_SMZZ] = js4;

            if((js4 & 0x0000ffff) == 0x00000000) //每传输64KB更新1次进度条
            {
                GUI_WJGL_JDT_XS_JDT_WZ_UP(GUI_WJGL_FZWJ_SMZZ,js4 / GUI_WJGL_FZWJ_101_DIVZ[GUI_WJGL_FZWJ_SMZZ]); //更新文件管理-进度条-显示进度条位置
            }
            else if((js4 & 0x0000ffff) == 0x00008000) //每传输32KB更新1次标题
            {
                GUI_WJGL_JDT_XS_BTXZ_UP(GUI_WJGL_FZWJ_SMZZ); //更新文件管理-进度条-显示标题选择(翻页)
            }
            else if ((js4 & 0x000007ff) == 0x00000000) //每传输2KB采样一次时间,足1秒更新1次复制速度
            {
                if ((js3 = DS1302_RD(0)) != GUI_WJGL_FZWJ_SEC[GUI_WJGL_FZWJ_SMZZ]) //过了一秒
                {
                    GUI_WJGL_JDT_XS_FZSD_UP(GUI_WJGL_FZWJ_SMZZ, (GUI_WJGL_FZWJ_A[GUI_WJGL_FZWJ_SMZZ] - GUI_WJGL_FZWJ_A_[GUI_WJGL_FZWJ_SMZZ]) >> 10); //更新文件管理-进度条-显示复制速度
                    GUI_WJGL_FZWJ_A_[GUI_WJGL_FZWJ_SMZZ] = GUI_WJGL_FZWJ_A[GUI_WJGL_FZWJ_SMZZ]; //记录这次的已复制字节数
                    GUI_WJGL_FZWJ_SEC[GUI_WJGL_FZWJ_SMZZ] = js3; //记录秒数
                }
            }
        }
        else //文件复制出错
        {
            FAT32_GBWJ(GUI_WJGL_FZWJ_S_DEVICE[GUI_WJGL_FZWJ_SMZZ],GUI_WJGL_FZWJ_S_WJH[GUI_WJGL_FZWJ_SMZZ]); //关闭文件
            FAT32_GBWJ(GUI_WJGL_FZWJ_D_DEVICE[GUI_WJGL_FZWJ_SMZZ],GUI_WJGL_FZWJ_D_WJH[GUI_WJGL_FZWJ_SMZZ]); //关闭文件
            GUI_WJGL_FZWJ_BZ[GUI_WJGL_FZWJ_SMZZ] = 255; //清除标志
            --GUI_WJGL_FZWJ_X; //项目计数减1
        }

        if(++GUI_WJGL_FZWJ_SMZZ == GUI_WJGL_FZWJ_WJX) GUI_WJGL_FZWJ_SMZZ = 0; //指向下一个项目

    }


}








void GUI_YYBFQ_XS(unsigned char UP_K) //音乐播放器-显示
{

unsigned char _str[16];
unsigned char js1;


    if(UP_K & 0x01)
    {
        GUI_kuang0(GUI_YYBFQ_XS_Y,GUI_YYBFQ_XS_X,69,119,142); //外边框
        GUI_SK1(GUI_YYBFQ_XS_Y+15,GUI_YYBFQ_XS_X+1,1,118,142); //标题下横杠
        GUI_SK1(GUI_YYBFQ_XS_Y+16,GUI_YYBFQ_XS_X+1,70-16-1,118,182); //下部背景色块
        GUI_SK1(GUI_YYBFQ_XS_Y+1,GUI_YYBFQ_XS_X+1,14,118,16); //标题背景色块
        GUI_YYBFQ_XS_UP_K_KEY = 1;
        GUI_YYBFQ_XS_UP_K_JDT = 1;
        GUI_YYBFQ_XS_UP_K_BT = 1;
    }

    if(UP_K != 0)
    {

        if(GUI_YYBFQ_XS_UP_K_BT != 0) //更新标题
        {
            GUI_YYBFQ_XS_UP_K_BT = 0;

            if((UP_K & 0x01) == 0) GUI_SK1(GUI_YYBFQ_XS_Y+1,GUI_YYBFQ_XS_X+1,14,72,16); //擦除标题


            if(GUI_YYBFQ_XS_BTXZ == 0) //标题显示音乐播放器
            {
                printx(GUI_YYBFQ_XS_Y+2,GUI_YYBFQ_XS_X+2,"音乐播放器",255);
            }
            else if(GUI_YYBFQ_XS_BTXZ == 1) //标题显示播放的文件
            {
                printx(GUI_YYBFQ_XS_Y+2,GUI_YYBFQ_XS_X+2,GUI_YYBFQ_XS_WJM,255);
            }
            else if(GUI_YYBFQ_XS_BTXZ == 2) //标题显示码率
            {
                *_str = 0;
                printx(GUI_YYBFQ_XS_Y+2,GUI_YYBFQ_XS_X+2,strcat(strcat(_str,U32_str(GUI_YYBFQ_XS_kbps)),"kbps"),255);
            }
            else if(GUI_YYBFQ_XS_BTXZ == 3) //标题显示采样率
            {
                *_str = 0;
                printx(GUI_YYBFQ_XS_Y+2,GUI_YYBFQ_XS_X+2,strcat(strcat(_str,U32_str(GUI_YYBFQ_XS_CYL)),"HZ"),255);
            }
            else if(GUI_YYBFQ_XS_BTXZ == 4) //标题显示声道数
            {
                if(GUI_YYBFQ_XS_SDS == 0)
                {
                    printx(GUI_YYBFQ_XS_Y+2,GUI_YYBFQ_XS_X+2,"双声道",255);
                }
                else if(GUI_YYBFQ_XS_SDS == 1)
                {
                    printx(GUI_YYBFQ_XS_Y+2,GUI_YYBFQ_XS_X+2,"单声道",255);
                }
            }
            else if(GUI_YYBFQ_XS_BTXZ == 5) //标题显示时间
            {
                *_str = 0;
                printx(GUI_YYBFQ_XS_Y+2,GUI_YYBFQ_XS_X+2,strcat(  strcat(  strcat(  strcat(  strcat(_str,U8_str(GUI_YYBFQ_XS_RTC_HR,1))  ,":")  ,U8_str(GUI_YYBFQ_XS_RTC_MIN,1))  ,":")  ,U8_str(GUI_YYBFQ_XS_RTC_SEC,2)),255);
            }

        }

        if(GUI_YYBFQ_XS_UP_K_KEY != 0) //更新按键
        {
            GUI_YYBFQ_XS_UP_K_KEY = 0;
            GUI_XXX_KEY(GUI_YYBFQ_XS_Y+3,GUI_YYBFQ_XS_X+(119-11),GUI_YYBFQ_XS_XXX_KEYXZ,GUI_YYBFQ_XS_XXX_KEY); //写关闭按钮
            GUI_ZXH_KEY(GUI_YYBFQ_XS_Y+3,GUI_YYBFQ_XS_X+(119-23),GUI_YYBFQ_XS_ZXH_KEYXZ,GUI_YYBFQ_XS_ZXH_KEY); //写最小化按钮

            GUI_KEY0(GUI_YYBFQ_XS_Y+46,GUI_YYBFQ_XS_X+11,16,16,GUI_YYBFQ_XS_TZBF_KEY); //停止播放按钮
            printx(GUI_YYBFQ_XS_Y+GUI_YYBFQ_XS_TZBF_KEY+(46+1),GUI_YYBFQ_XS_X+GUI_YYBFQ_XS_TZBF_KEY+(11+2),"●",255);

            GUI_KEY0(GUI_YYBFQ_XS_Y+46,GUI_YYBFQ_XS_X+(11+16),16,25,GUI_YYBFQ_XS_SYQ_KEY); //上一曲按钮
            printx(GUI_YYBFQ_XS_Y+GUI_YYBFQ_XS_SYQ_KEY+(46+2),GUI_YYBFQ_XS_X+GUI_YYBFQ_XS_SYQ_KEY+(11+16+5),"<<",255);

            GUI_KEY0(GUI_YYBFQ_XS_Y+46,GUI_YYBFQ_XS_X+(11+16+25),16,16,GUI_YYBFQ_XS_BFZT_KEY); //播放暂停按钮
            if(GUI_YYBFQ_XS_BFZT_K != 0) //播放
            {
                printx(GUI_YYBFQ_XS_Y+GUI_YYBFQ_XS_BFZT_KEY+(46+2),GUI_YYBFQ_XS_X+GUI_YYBFQ_XS_BFZT_KEY+(11+16+25+2),"★",255);
            }
            else //暂停
            {
                printx(GUI_YYBFQ_XS_Y+GUI_YYBFQ_XS_BFZT_KEY+(46+2),GUI_YYBFQ_XS_X+GUI_YYBFQ_XS_BFZT_KEY+(11+16+25+2),"№",255);
            }

            GUI_KEY0(GUI_YYBFQ_XS_Y+46,GUI_YYBFQ_XS_X+(11+16+25+16),16,25,GUI_YYBFQ_XS_XYQ_KEY); //下一曲按钮
            printx(GUI_YYBFQ_XS_Y+GUI_YYBFQ_XS_XYQ_KEY+(46+2),GUI_YYBFQ_XS_X+GUI_YYBFQ_XS_XYQ_KEY+(11+16+25+16+8),">>",255);

            GUI_KEY0(GUI_YYBFQ_XS_Y+46,GUI_YYBFQ_XS_X+(11+16+25+16+25),16,16,GUI_YYBFQ_XS_DQXH_KEY); //单曲循环按钮
            printx(GUI_YYBFQ_XS_Y+GUI_YYBFQ_XS_DQXH_KEY+(46+2),GUI_YYBFQ_XS_X+GUI_YYBFQ_XS_DQXH_KEY+(11+16+25+16+25+2),"∞",255);


        }

        if(GUI_YYBFQ_XS_UP_K_JDT != 0) //更新进度条滑块
        {
            GUI_YYBFQ_XS_UP_K_JDT = 0;
            GUI_SK1(GUI_YYBFQ_XS_Y+27,GUI_YYBFQ_XS_X+8+GUI_YYBFQ_XS_JDT_WZ_,7,5,182); //擦除进度条滑块
            GUI_SK1(GUI_YYBFQ_XS_Y+30,GUI_YYBFQ_XS_X+10,1,100,31); //进度条基线
            if(GUI_YYBFQ_XS_JDT_KEYXZ != 0) js1 = 39; else js1 = 31;
            GUI_SK1(GUI_YYBFQ_XS_Y+27,GUI_YYBFQ_XS_X+8+GUI_YYBFQ_XS_JDT_WZ,7,5,js1); //写进度条滑块
            GUI_YYBFQ_XS_JDT_WZ_ = GUI_YYBFQ_XS_JDT_WZ;
        }
    }

}



void GUI_YYBFQ_XS_ZXH_KEY_UP(unsigned char KEY) //更新音乐播放器最小化按钮(按下弹起)
{
   GUI_YYBFQ_XS_ZXH_KEY = KEY;
   GUI_YYBFQ_XS_UP_K_KEY = 1;
   GUI_UPBZ(2,0,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_YYBFQ_XS_ZXH_KEYXZ_UP(unsigned char KEY) //更新音乐播放器最小化按钮(选择)
{
   GUI_YYBFQ_XS_ZXH_KEYXZ = KEY;
   GUI_YYBFQ_XS_UP_K_KEY = 1;
   GUI_UPBZ(2,0,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_YYBFQ_XS_XXX_KEY_UP(unsigned char KEY) //更新音乐播放器关闭按钮(按下弹起)
{
   GUI_YYBFQ_XS_XXX_KEY = KEY;
   GUI_YYBFQ_XS_UP_K_KEY = 1;
   GUI_UPBZ(2,0,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_YYBFQ_XS_XXX_KEYXZ_UP(unsigned char KEY) //更新音乐播放器关闭按钮(选择)
{
   GUI_YYBFQ_XS_XXX_KEYXZ = KEY;
   GUI_YYBFQ_XS_UP_K_KEY = 1;
   GUI_UPBZ(2,0,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_YYBFQ_XS_TZBF_KEY_UP(unsigned char KEY) //更新音乐播放器停止播放按钮(按下弹起)
{
   GUI_YYBFQ_XS_TZBF_KEY = KEY;
   GUI_YYBFQ_XS_UP_K_KEY = 1;
   GUI_UPBZ(2,0,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_YYBFQ_XS_SYQ_KEY_UP(unsigned char KEY) //更新音乐播放器上一曲按钮(按下弹起)
{
   GUI_YYBFQ_XS_SYQ_KEY = KEY;
   GUI_YYBFQ_XS_UP_K_KEY = 1;
   GUI_UPBZ(2,0,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_YYBFQ_XS_XYQ_KEY_UP(unsigned char KEY) //更新音乐播放器下一曲按钮(按下弹起)
{
   GUI_YYBFQ_XS_XYQ_KEY = KEY;
   GUI_YYBFQ_XS_UP_K_KEY = 1;
   GUI_UPBZ(2,0,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_YYBFQ_XS_BFZT_KEY_UP(unsigned char KEY) //更新音乐播放器播放暂停按钮(按下弹起)
{
   GUI_YYBFQ_XS_BFZT_KEY = KEY;
   GUI_YYBFQ_XS_UP_K_KEY = 1;
   GUI_UPBZ(2,0,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_YYBFQ_XS_DQXH_KEY_UP(unsigned char KEY) //更新音乐播放器单曲循环按钮(按下弹起)
{
   GUI_YYBFQ_XS_DQXH_KEY = KEY;
   GUI_YYBFQ_XS_UP_K_KEY = 1;
   GUI_UPBZ(2,0,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_YYBFQ_XS_BFZT_K_UP(unsigned char KEY) //更新音乐播放器播放暂停
{
   GUI_YYBFQ_XS_BFZT_K = KEY;
   GUI_YYBFQ_XS_UP_K_KEY = 1;
   GUI_UPBZ(2,0,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_YYBFQ_XS_JDT_KEYXZ_UP(unsigned char KEY) //更新音乐播放器进度条滑块(选择)
{
   GUI_YYBFQ_XS_JDT_KEYXZ = KEY;
   GUI_YYBFQ_XS_UP_K_JDT = 1;
   GUI_UPBZ(2,0,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

unsigned char GUI_YYBFQ_XS_BJ1() //音乐播放器-显示(部件1)
{
   return GUI_YYBFQ_XS_Y > 240 - 86 || GUI_GET_CK_CENGX(2,0) != 0; //窗口进入任务栏范围或窗口非前置
}

void GUI_YYBFQ_XS_JDT_WZ_UP(unsigned char KEY) //更新音乐播放器进度条滑块(位置偏移)
{
   GUI_YYBFQ_XS_JDT_WZ = KEY;
   if(KEY > 127) GUI_YYBFQ_XS_JDT_WZ = 0;
   else if(KEY > 99)  GUI_YYBFQ_XS_JDT_WZ = 99;

   if(GUI_GET_CKXS_CKUP(2,0) >> 8 != 0) //窗口不为最小化
   {
       GUI_YYBFQ_XS_UP_K_JDT = 1;
       GUI_UPBZ(2,0,2,GUI_YYBFQ_XS_BJ1()); //置更新标志,刷新窗口内容
       GUI_UP_K = 1; //打开GUI更新
   }
}

void GUI_YYBFQ_XS_JDT_WZ_AS_UP(unsigned char ASY) //更新音乐播放器进度条滑块(位置偏移增减量)
{

unsigned char js1;

   js1 = GUI_YYBFQ_XS_JDT_WZ;
   GUI_YYBFQ_XS_JDT_WZ += ASY;

   if(ASY > 127) //负数
   {
      if(GUI_YYBFQ_XS_JDT_WZ > js1) GUI_YYBFQ_XS_JDT_WZ = 0;
   }
   else //正数
   {
      if(GUI_YYBFQ_XS_JDT_WZ > 99 || GUI_YYBFQ_XS_JDT_WZ < js1) GUI_YYBFQ_XS_JDT_WZ = 99;
   }

   GUI_YYBFQ_XS_UP_K_JDT = 1;
   GUI_UPBZ(2,0,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_YYBFQ_XS_SDS_UP(unsigned char KEY) //更新音乐播放器声道数显示
{
   GUI_YYBFQ_XS_SDS = KEY;

   if(GUI_YYBFQ_XS_BTXZ == 4 && GUI_GET_CKXS_CKUP(2,0) >> 8 != 0)
   {
       GUI_YYBFQ_XS_UP_K_BT = 1;
       GUI_UPBZ(2,0,2,GUI_YYBFQ_XS_BJ1()); //置更新标志,刷新窗口内容
       GUI_UP_K = 1; //打开GUI更新
   }
}

void GUI_YYBFQ_XS_kbps_UP(unsigned int KEY) //更新音乐播放器码率显示
{
   GUI_YYBFQ_XS_kbps = KEY;

   if(GUI_YYBFQ_XS_BTXZ == 2 && GUI_GET_CKXS_CKUP(2,0) >> 8 != 0)
   {
       GUI_YYBFQ_XS_UP_K_BT = 1;
       GUI_UPBZ(2,0,2,GUI_YYBFQ_XS_BJ1()); //置更新标志,刷新窗口内容
       GUI_UP_K = 1; //打开GUI更新
   }
}

void GUI_YYBFQ_XS_CYL_UP(unsigned int KEY) //更新音乐播放器采样率显示
{
   GUI_YYBFQ_XS_CYL = KEY;

   if(GUI_YYBFQ_XS_BTXZ == 3 && GUI_GET_CKXS_CKUP(2,0) >> 8 != 0)
   {
       GUI_YYBFQ_XS_UP_K_BT = 1;
       GUI_UPBZ(2,0,2,GUI_YYBFQ_XS_BJ1()); //置更新标志,刷新窗口内容
       GUI_UP_K = 1; //打开GUI更新
   }
}

void GUI_YYBFQ_XS_WJM_UP() //更新音乐播放器文件名显示
{
   if(GUI_YYBFQ_XS_BTXZ == 1 && GUI_GET_CKXS_CKUP(2,0) >> 8 != 0)
   {
       GUI_YYBFQ_XS_UP_K_BT = 1;
       GUI_UPBZ(2,0,2,GUI_YYBFQ_XS_BJ1()); //置更新标志,刷新窗口内容
       GUI_UP_K = 1; //打开GUI更新
   }
}

void GUI_YYBFQ_XS_RTC_UP(unsigned char HR,unsigned char MIN,unsigned char SEC) //更新音乐播放器播放时间显示
{
   GUI_YYBFQ_XS_RTC_SEC = SEC; //播放时间(秒)
   GUI_YYBFQ_XS_RTC_MIN = MIN; //播放时间(分)
   GUI_YYBFQ_XS_RTC_HR = HR; //播放时间(时)

   if(GUI_YYBFQ_XS_BTXZ == 5 && GUI_GET_CKXS_CKUP(2,0) >> 8 != 0)
   {
       GUI_YYBFQ_XS_UP_K_BT = 1;
       GUI_UPBZ(2,0,2,GUI_YYBFQ_XS_BJ1()); //置更新标志,刷新窗口内容
       GUI_UP_K = 1; //打开GUI更新
   }
}

void GUI_YYBFQ_XS_BTXZ_UP() //更新音乐播放器标题显示翻页
{
   if(++GUI_YYBFQ_XS_BTXZ == 6) GUI_YYBFQ_XS_BTXZ = 0;

   if(GUI_GET_CKXS_CKUP(2,0) >> 8 != 0)
   {
       GUI_YYBFQ_XS_UP_K_BT = 1;
       GUI_UPBZ(2,0,2,GUI_YYBFQ_XS_BJ1()); //置更新标志,刷新窗口内容
       GUI_UP_K = 1; //打开GUI更新
   }
}

void GUI_YYBFQ_XS_YX_UP(unsigned char Y,unsigned char X) //更新音乐播放器窗口起始坐标(移动窗口)
{
   GUI_YYBFQ_XS_Y += Y;
   GUI_YYBFQ_XS_X += X;

   GUI_UPBZ(253,0,1,1); //从底层桌面开始置更新标志,刷新所有窗口内容
   GUI_UP_K = 1; //打开GUI更新
}





void GUI_YYBFQ_KEY_BJ1() //音乐播放器-键(部件1)
{

unsigned long int WJDX;

    WJDX = FAT32_RETURN_WJDX_(GUI_YYBFQ_XS_DEVICE,GUI_YYBFQ_XS_WJX); //取文件总大小
    FAT32_RWWJ_SETLBA(GUI_YYBFQ_XS_DEVICE,GUI_YYBFQ_XS_WJX,(((WJDX / 512 + (WJDX % 512 != 0)) << 8) / 100 * GUI_YYBFQ_XS_JDT_WZ) >> 8); //设置读写文件起始扇区
    GUI_YYBFQ_RUN_WJDX_A = FAT32_RETURN_WJDX_(GUI_YYBFQ_XS_DEVICE,GUI_YYBFQ_XS_WJX) - FAT32_RETURN__WJDX(GUI_YYBFQ_XS_DEVICE,GUI_YYBFQ_XS_WJX); //取文件已读大小
}



void GUI_YYBFQ_KEY_BJ2(unsigned char X) //音乐播放器-键(部件2,找出下一个MP3文件的文件名)
{

unsigned char buf[1025];
unsigned int buf_smzz;
unsigned int buf_wz;
unsigned char DWJM[13];

unsigned char js1;
unsigned char *_addr;



         buf_wz = 0;
         while(1)  //查找源文件
         {

             FAT32_ML_WJCX1(GUI_YYBFQ_XS_DEVICE,GUI_YYBFQ_XS_mulu_cuhao,(buf_wz<<5) + 1,(buf_wz<<5) + 32,buf); //调出32个文件符到缓冲区


             buf_smzz = 0;
             while(1) //有文件附数据
             {

                 if(buf_smzz == 1024)
                 {
                     break; //跳出循环,更新缓冲区
                 }
                 else if(buf[buf_smzz] == 0x00) //目录扫描结束
                 {
                     return; //没有找到文件,返回
                 }
                 else
                 {

                     GUI_11B_chars(&buf[buf_smzz],DWJM); //提出文件名

                     js1 = 0;
                     while(DWJM[js1] != 0 && DWJM[js1] == GUI_YYBFQ_XS_WJM[js1]) ++js1; //比较文件名

                     if(DWJM[js1] == 0 && DWJM[js1] == GUI_YYBFQ_XS_WJM[js1]) //文件名相同
                     {
                         goto out;
                     }

                     buf_smzz += 32; //指向下一个文件符
                 }

             }

             ++buf_wz; //指向下一段

         }



         while(1) //查找下一首MP3
         {

             FAT32_ML_WJCX1(GUI_YYBFQ_XS_DEVICE,GUI_YYBFQ_XS_mulu_cuhao,(buf_wz<<5) + 1,(buf_wz<<5) + 32,buf); //调出32个文件符到缓冲区

             while(1) //有文件附数据
             {

                 if(buf[buf_smzz] == 0x00) //目录扫描结束,没有找到文件
                 {
                     return; //没有找到文件,返回
                 }
                 else
                 {
                     _addr = &buf[buf_smzz];

                     if(_addr[0x08] == 'M' && _addr[0x09] == 'P' && _addr[0x0a] == '3') //是MP3文件?
                     {
                         GUI_11B_chars(_addr,GUI_YYBFQ_XS_WJM); //提出文件名
                         return; //找到文件,返回
                     }

  out:
                     if(X != 0) //是下一曲
                     {
                         buf_smzz += 32; //指向下一个文件符
                         if(buf_smzz == 1024)
                         {
                             buf_smzz = 0; //指向缓冲区首部
                             break; //跳出循环,更新缓冲区
                         }
                     }
                     else //是上一曲
                     {
                         if(buf_smzz == 0)
                         {
                             buf_smzz = 1024-32; //指向缓冲区尾部
                             break; //跳出循环,更新缓冲区
                         }
                         buf_smzz -= 32; //指向上一个文件符
                     }

                 }

             }

             if(X != 0) //是下一曲
             {
                 ++buf_wz; //指向下一段
             }
             else //是上一曲
             {
                 if(buf_wz == 0) return; //没有找到文件,返回
                 --buf_wz; //指向上一段
             }

         }



}

unsigned char GUI_YYBFQ_KEY(unsigned char SB_K,unsigned char KEY_K) //音乐播放器-键
{

unsigned char js1;
unsigned char js2;


    if(SB_K != 0 && GUI_SBZBPD(GUI_YYBFQ_XS_Y,GUI_YYBFQ_XS_Y+69,GUI_YYBFQ_XS_X,GUI_YYBFQ_XS_X+119) != 0) //鼠标坐标在窗口范围内
    {

        if(GUI_YYBFQ_KEY_KXZ[0] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_YYBFQ_KEY_KXZ[0] = 1; //弹起指向第1步
        }
        else if(GUI_YYBFQ_KEY_KXZ[0] == 1)
        {
            if(GUI_SB_L_KEY() != 0)
            {
                GUI_YYBFQ_KEY_KXZ[0] = 2; //按下指向第2步
                GUI_QZCK(2,0); //前置窗口
            }
        }
        else if(GUI_YYBFQ_KEY_KXZ[0] == 2)
        {
            if(GUI_SB_L_KEY() == 0)
            {
                GUI_YYBFQ_KEY_KXZ[0] = 1; //弹起指向第1步
            }
        }

    }
    else
    {

        GUI_YYBFQ_KEY_KXZ[0] = 0;

    }


    if(SB_K != 0 && GUI_SBZBPD(GUI_YYBFQ_XS_Y+3,GUI_YYBFQ_XS_Y+(3+8),GUI_YYBFQ_XS_X+(119-11),GUI_YYBFQ_XS_X+(119-11+8)) != 0) //鼠标坐标在关闭按钮范围内
    {
        if(GUI_YYBFQ_KEY_IO[1] == 0)
        {
           GUI_YYBFQ_XS_XXX_KEYXZ_UP(1); //更新音乐播放器关闭按钮(选择)
           GUI_YYBFQ_KEY_IO[1] = 1;
        }

        if(GUI_YYBFQ_KEY_KXZ[1] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_YYBFQ_KEY_KXZ[1] = 1; //弹起指向第1步
        }
        else if(GUI_YYBFQ_KEY_KXZ[1] == 1)
        {
            if(GUI_SB_L_KEY() != 0)
            {
                GUI_YYBFQ_KEY_KXZ[1] = 2; //按下指向第2步
                GUI_YYBFQ_XS_XXX_KEY_UP(1); //更新音乐播放器关闭按钮(按下弹起)
            }
        }
        else if(GUI_YYBFQ_KEY_KXZ[1] == 2)
        {
            if(GUI_SB_L_KEY() == 0)
            {
                GUI_YYBFQ_KEY_KXZ[1] = 1; //弹起指向第1步
                GUI_YYBFQ_XS_XXX_KEY_UP(0); //更新音乐播放器关闭按钮(按下弹起)
                GUI_GBCK(2,0); //关闭窗口

                if(GUI_YYBFQ_XS_WJX != 255)
                {
                    FAT32_GBWJ(GUI_YYBFQ_XS_DEVICE,GUI_YYBFQ_XS_WJX); //关闭文件
                    GUI_YYBFQ_XS_BFZT_K = 0; //暂停播放
                    GUI_YYBFQ_XS_WJX = 255; //无效文件号
                }
            }
        }

    }
    else
    {
        if(GUI_YYBFQ_KEY_IO[1] != 0)
        {
           GUI_YYBFQ_XS_XXX_KEYXZ_UP(0); //更新音乐播放器关闭按钮(选择)
           GUI_YYBFQ_KEY_IO[1] = 0;
        }

        if(GUI_YYBFQ_KEY_KXZ[1] != 0)
        {
           GUI_YYBFQ_XS_XXX_KEY_UP(0); //更新音乐播放器关闭按钮(按下弹起)
           GUI_YYBFQ_KEY_KXZ[1] = 0;
        }

    }


    if(SB_K != 0 && GUI_SBZBPD(GUI_YYBFQ_XS_Y+3,GUI_YYBFQ_XS_Y+(3+8),GUI_YYBFQ_XS_X+(119-23),GUI_YYBFQ_XS_X+(119-23+8)) != 0) //鼠标坐标在最小化按钮范围内
    {
        if(GUI_YYBFQ_KEY_IO[2] == 0)
        {
           GUI_YYBFQ_XS_ZXH_KEYXZ_UP(1); //更新音乐播放器最小化按钮(选择)
           GUI_YYBFQ_KEY_IO[2] = 1;
        }

        if(GUI_YYBFQ_KEY_KXZ[2] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_YYBFQ_KEY_KXZ[2] = 1; //弹起指向第1步
        }
        else if(GUI_YYBFQ_KEY_KXZ[2] == 1)
        {
            if(GUI_SB_L_KEY() != 0)
            {
                GUI_YYBFQ_KEY_KXZ[2] = 2; //按下指向第2步
                GUI_YYBFQ_XS_ZXH_KEY_UP(1); //更新音乐播放器最小化按钮(按下弹起)
            }
        }
        else if(GUI_YYBFQ_KEY_KXZ[2] == 2)
        {
            if(GUI_SB_L_KEY() == 0)
            {
                GUI_YYBFQ_KEY_KXZ[2] = 1; //弹起指向第1步
                GUI_YYBFQ_XS_ZXH_KEY_UP(0); //更新音乐播放器最小化按钮(按下弹起)
                GUI_ZXHCK(2,0); //最小化窗口
            }
        }

    }
    else
    {
        if(GUI_YYBFQ_KEY_IO[2] != 0)
        {
           GUI_YYBFQ_XS_ZXH_KEYXZ_UP(0); //更新音乐播放器最小化按钮(选择)
           GUI_YYBFQ_KEY_IO[2] = 0;
        }

        if(GUI_YYBFQ_KEY_KXZ[2] != 0)
        {
           GUI_YYBFQ_XS_ZXH_KEY_UP(0); //更新音乐播放器最小化按钮(按下弹起)
           GUI_YYBFQ_KEY_KXZ[2] = 0;
        }

    }



    if(SB_K != 0 && GUI_SBZBPD(GUI_YYBFQ_XS_Y+46,GUI_YYBFQ_XS_Y+(46+15),GUI_YYBFQ_XS_X+11,GUI_YYBFQ_XS_X+(11+15)) != 0) //鼠标坐标在停止播放按钮范围内
    {

        if(GUI_YYBFQ_KEY_KXZ[3] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_YYBFQ_KEY_KXZ[3] = 1; //弹起指向第1步
        }
        else if(GUI_YYBFQ_KEY_KXZ[3] == 1)
        {
            if(GUI_SB_L_KEY() != 0)
            {
                GUI_YYBFQ_KEY_KXZ[3] = 2; //按下指向第2步
                GUI_YYBFQ_XS_TZBF_KEY_UP(1); //更新音乐播放器停止播放按钮(按下弹起)
            }
        }
        else if(GUI_YYBFQ_KEY_KXZ[3] == 2)
        {
            if(GUI_SB_L_KEY() == 0)
            {
                GUI_YYBFQ_KEY_KXZ[3] = 1; //弹起指向第1步
                GUI_YYBFQ_XS_TZBF_KEY_UP(0); //更新音乐播放器停止播放按钮(按下弹起)
                if(GUI_YYBFQ_XS_WJX != 255)
                {
                    FAT32_GBWJ(GUI_YYBFQ_XS_DEVICE,GUI_YYBFQ_XS_WJX); //关闭文件
                    GUI_YYBFQ_XS_BFZT_K_UP(0); //暂停播放
                    GUI_YYBFQ_XS_WJX = 255; //无效文件号
                    GUI_YYBFQ_XS_JDT_WZ_UP(0); //更新音乐播放器进度条滑块(位置偏移)
                    GUI_YYBFQ_XS_XYQ_K = 0; //下一曲控制,为0跳过查询下一曲
                }

            }
        }

    }
    else
    {

        if(GUI_YYBFQ_KEY_KXZ[3] != 0)
        {
           GUI_YYBFQ_XS_TZBF_KEY_UP(0); //更新音乐播放器停止播放按钮(按下弹起)
           GUI_YYBFQ_KEY_KXZ[3] = 0;
        }

    }


    if(SB_K != 0 && GUI_SBZBPD(GUI_YYBFQ_XS_Y+46,GUI_YYBFQ_XS_Y+(46+15),GUI_YYBFQ_XS_X+(11+16),GUI_YYBFQ_XS_X+(11+16+24)) != 0) //鼠标坐标在上一曲按钮范围内
    {

        if(GUI_YYBFQ_KEY_KXZ[4] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_YYBFQ_KEY_KXZ[4] = 1; //弹起指向第1步
        }
        else if(GUI_YYBFQ_KEY_KXZ[4] == 1)
        {
            if(GUI_SB_L_KEY() != 0)
            {
                GUI_YYBFQ_KEY_KXZ[4] = 2; //按下指向第2步
                GUI_YYBFQ_XS_SYQ_KEY_UP(1); //更新音乐播放器上一曲按钮(按下弹起)
            }
        }
        else if(GUI_YYBFQ_KEY_KXZ[4] == 2)
        {
            if(GUI_SB_L_KEY() == 0)
            {
                GUI_YYBFQ_KEY_KXZ[4] = 1; //弹起指向第1步
                GUI_YYBFQ_XS_SYQ_KEY_UP(0); //更新音乐播放器上一曲按钮(按下弹起)

                GUI_YYBFQ_KEY_BJ2(0); //音乐播放器-键(部件2,找出下一个MP3文件的文件名)
                GUI_YYBFQ_XS_WJM_UP(); //更新音乐播放器文件名显示

                if(GUI_YYBFQ_XS_WJX != 255)
                {
                    FAT32_GBWJ(GUI_YYBFQ_XS_DEVICE,GUI_YYBFQ_XS_WJX); //关闭文件
                    GUI_YYBFQ_XS_WJX = 255; //无效文件号
                    GUI_YYBFQ_XS_JDT_WZ_UP(0); //更新音乐播放器进度条滑块(位置偏移)
                    GUI_YYBFQ_XS_XYQ_K = 0; //下一曲控制,为0跳过查询下一曲
                }

            }
        }

    }
    else
    {

        if(GUI_YYBFQ_KEY_KXZ[4] != 0)
        {
           GUI_YYBFQ_XS_SYQ_KEY_UP(0); //更新音乐播放器上一曲按钮(按下弹起)
           GUI_YYBFQ_KEY_KXZ[4] = 0;
        }

    }


    if(SB_K != 0 && GUI_SBZBPD(GUI_YYBFQ_XS_Y+46,GUI_YYBFQ_XS_Y+(46+15),GUI_YYBFQ_XS_X+(11+16+25+16),GUI_YYBFQ_XS_X+(11+16+25+16+24)) != 0) //鼠标坐标在下一曲按钮范围内
    {

        if(GUI_YYBFQ_KEY_KXZ[5] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_YYBFQ_KEY_KXZ[5] = 1; //弹起指向第1步
        }
        else if(GUI_YYBFQ_KEY_KXZ[5] == 1)
        {
            if(GUI_SB_L_KEY() != 0)
            {
                GUI_YYBFQ_KEY_KXZ[5] = 2; //按下指向第2步
                GUI_YYBFQ_XS_XYQ_KEY_UP(1); //更新音乐播放器下一曲按钮(按下弹起)
            }
        }
        else if(GUI_YYBFQ_KEY_KXZ[5] == 2)
        {
            if(GUI_SB_L_KEY() == 0)
            {
                GUI_YYBFQ_KEY_KXZ[5] = 1; //弹起指向第1步
                GUI_YYBFQ_XS_XYQ_KEY_UP(0); //更新音乐播放器下一曲按钮(按下弹起)

                GUI_YYBFQ_KEY_BJ2(1); //音乐播放器-键(部件2,找出下一个MP3文件的文件名)
                GUI_YYBFQ_XS_WJM_UP(); //更新音乐播放器文件名显示

                if(GUI_YYBFQ_XS_WJX != 255)
                {
                    FAT32_GBWJ(GUI_YYBFQ_XS_DEVICE,GUI_YYBFQ_XS_WJX); //关闭文件
                    GUI_YYBFQ_XS_WJX = 255; //无效文件号
                    GUI_YYBFQ_XS_JDT_WZ_UP(0); //更新音乐播放器进度条滑块(位置偏移)
                    GUI_YYBFQ_XS_XYQ_K = 0; //下一曲控制,为0跳过查询下一曲
                }
            }
        }

    }
    else
    {

        if(GUI_YYBFQ_KEY_KXZ[5] != 0)
        {
           GUI_YYBFQ_XS_XYQ_KEY_UP(0); //更新音乐播放器下一曲按钮(按下弹起)
           GUI_YYBFQ_KEY_KXZ[5] = 0;
        }

    }


    if(SB_K != 0 && GUI_SBZBPD(GUI_YYBFQ_XS_Y+46,GUI_YYBFQ_XS_Y+(46+15),GUI_YYBFQ_XS_X+(11+16+25),GUI_YYBFQ_XS_X+(11+16+25+15)) != 0) //鼠标坐标在播放暂停按钮范围内
    {

        if(GUI_YYBFQ_KEY_KXZ[6] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_YYBFQ_KEY_KXZ[6] = 1; //弹起指向第1步
        }
        else if(GUI_YYBFQ_KEY_KXZ[6] == 1)
        {
            if(GUI_SB_L_KEY() != 0)
            {
                GUI_YYBFQ_KEY_KXZ[6] = 2; //按下指向第2步
                GUI_YYBFQ_XS_BFZT_KEY_UP(1); //更新音乐播放器播放暂停按钮(按下弹起)
            }
        }
        else if(GUI_YYBFQ_KEY_KXZ[6] == 2)
        {
            if(GUI_SB_L_KEY() == 0)
            {
                GUI_YYBFQ_KEY_KXZ[6] = 1; //弹起指向第1步
                GUI_YYBFQ_XS_BFZT_KEY_UP(0); //更新音乐播放器播放暂停按钮(按下弹起)
                GUI_YYBFQ_XS_BFZT_K_UP(GUI_YYBFQ_XS_BFZT_K^0x01); //播放/暂停
            }
        }

    }
    else
    {

        if(GUI_YYBFQ_KEY_KXZ[6] != 0)
        {
           GUI_YYBFQ_XS_BFZT_KEY_UP(0); //更新音乐播放器播放暂停按钮(按下弹起)
           GUI_YYBFQ_KEY_KXZ[6] = 0;
        }

    }


    if(SB_K != 0 && GUI_SBZBPD(GUI_YYBFQ_XS_Y+46,GUI_YYBFQ_XS_Y+(46+15),GUI_YYBFQ_XS_X+(11+16+25+16+25),GUI_YYBFQ_XS_X+(11+16+25+16+25+15)) != 0) //鼠标坐标在单曲循环按钮范围内
    {

        if(GUI_YYBFQ_KEY_KXZ[7] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_YYBFQ_KEY_KXZ[7] = 1; //弹起指向第1步
        }
        else if(GUI_YYBFQ_KEY_KXZ[7] == 1)
        {
            if(GUI_SB_L_KEY() != 0)
            {
                GUI_YYBFQ_KEY_KXZ[7] = 2; //按下指向第2步
                GUI_YYBFQ_XS_DQXH_KEY_UP(1); //更新音乐播放器单曲循环按钮(按下弹起)
            }
        }
        else if(GUI_YYBFQ_KEY_KXZ[7] == 2)
        {
            if(GUI_SB_L_KEY() == 0)
            {
                GUI_YYBFQ_KEY_KXZ[7] = 1; //弹起指向第1步
                if(GUI_YYBFQ_XS_DQXH_K != 0)
                {
                    GUI_YYBFQ_XS_DQXH_K = 0; //取消单曲循环
                    GUI_YYBFQ_XS_DQXH_KEY_UP(0); //更新音乐播放器单曲循环按钮(按下弹起)
                }
                else
                {
                    GUI_YYBFQ_XS_DQXH_K = 1; //为单曲循环
                }
            }
        }

    }
    else
    {

        if(GUI_YYBFQ_KEY_KXZ[7] != 0)
        {
           if(GUI_YYBFQ_XS_DQXH_K == 0)
           {
               GUI_YYBFQ_XS_DQXH_KEY_UP(0); //更新音乐播放器单曲循环按钮(按下弹起)
           }

           GUI_YYBFQ_KEY_KXZ[7] = 0;
        }

    }



    if(SB_K != 0 && (GUI_SBZBPD(GUI_YYBFQ_XS_Y+27,GUI_YYBFQ_XS_Y+(27+6),GUI_YYBFQ_XS_X+8,GUI_YYBFQ_XS_X+(8+103)) != 0 || GUI_YYBFQ_KEY_KXZ[8] == 2)) //鼠标坐标在进度条范围内
    {

        if(GUI_YYBFQ_KEY_IO[8] == 0)
        {
           GUI_YYBFQ_XS_JDT_KEYXZ_UP(1); //更新音乐播放器进度条滑块(选择)
           GUI_YYBFQ_KEY_IO[8] = 1;
        }

        if(GUI_YYBFQ_KEY_KXZ[8] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_YYBFQ_KEY_KXZ[8] = 1; //弹起指向第1步
        }
        else if(GUI_YYBFQ_KEY_KXZ[8] == 1)
        {
            if(GUI_SB_L_KEY() != 0)
            {
                GUI_YYBFQ_KEY_KXZ[8] = 2; //按下指向第2步
                GUI_YYBFQ_XS_JDT_WZ_UP(GUI_SB_GET_X() - (GUI_YYBFQ_XS_X + 10)); //更新音乐播放器进度条滑块(位置偏移)
            }
        }
        else if(GUI_YYBFQ_KEY_KXZ[8] == 2)
        {
            if(GUI_SBZBPD(0,239,GUI_YYBFQ_XS_X+8,GUI_YYBFQ_XS_X+(8+103)) != 0 && GUI_SB_GET_AS_X() != 0)
            {
                GUI_YYBFQ_XS_JDT_WZ_UP(GUI_SB_GET_X() - (GUI_YYBFQ_XS_X + 10)); //更新音乐播放器进度条滑块(位置偏移)
            }

            if(GUI_SB_L_KEY() == 0)
            {
                GUI_YYBFQ_KEY_KXZ[8] = 1; //弹起指向第1步

                if(GUI_YYBFQ_XS_WJX != 255)
                {
                    GUI_YYBFQ_KEY_BJ1(); //音乐播放器-键(部件1)
                }
            }
        }

    }
    else
    {

        if(GUI_YYBFQ_KEY_IO[8] != 0)
        {
           GUI_YYBFQ_XS_JDT_KEYXZ_UP(0); //更新音乐播放器进度条滑块(选择)
           GUI_YYBFQ_KEY_IO[8] = 0;
        }

        GUI_YYBFQ_KEY_KXZ[8] = 0;

    }


    if(SB_K != 0 && (GUI_SBZBPD(GUI_YYBFQ_XS_Y+1,GUI_YYBFQ_XS_Y+(1+13),GUI_YYBFQ_XS_X+1,GUI_YYBFQ_XS_X+(1+117)) != 0 && GUI_YYBFQ_KEY_KXZ[1] == 0 && GUI_YYBFQ_KEY_KXZ[2] == 0 || GUI_YYBFQ_KEY_KXZ[9] == 2)) //鼠标坐标在窗口标题范围内
    {

        if(GUI_YYBFQ_KEY_KXZ[9] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_YYBFQ_KEY_KXZ[9] = 1; //弹起指向第1步
        }
        else if(GUI_YYBFQ_KEY_KXZ[9] == 1)
        {
            if(GUI_SB_L_KEY() != 0)
            {
                GUI_YYBFQ_KEY_KXZ[9] = 2; //按下指向第2步
            }
        }
        else if(GUI_YYBFQ_KEY_KXZ[9] == 2)
        {
            js1 = GUI_SB_GET_AS_Y();
            js2 = GUI_SB_GET_AS_X();

            if(js1 != 0 || js2 != 0)
            {
                GUI_YYBFQ_XS_YX_UP(js1,js2); //更新音乐播放器窗口起始坐标(移动窗口)
            }

            if(GUI_SB_L_KEY() == 0)
            {
                GUI_YYBFQ_KEY_KXZ[9] = 1; //弹起指向第1步
                GUI_YYBFQ_XS_BTXZ_UP(); //更新音乐播放器标题显示翻页
            }
        }

    }
    else
    {

        GUI_YYBFQ_KEY_KXZ[9] = 0;

    }




    return SB_K != 0 && GUI_SBZBPD(GUI_YYBFQ_XS_Y,GUI_YYBFQ_XS_Y+69,GUI_YYBFQ_XS_X,GUI_YYBFQ_XS_X+119) != 0; //落在窗口内返回非0

}



void GUI_YYBFQ_RUN() //音乐播放器-运行
{

unsigned char buf[512];


    if(GUI_YYBFQ_XS_BFZT_K != 0) //1播放0暂停
    {

        if(GUI_YYBFQ_XS_WJX != 255 && FAT32_RDWJ_512B(GUI_YYBFQ_XS_DEVICE,GUI_YYBFQ_XS_WJX,buf) == 1) //文件号有效并且读512字节成功
        {
            VS1003_WR512B(buf); //写入VS1003播放
            GUI_YYBFQ_RUN_WJDX_A += 512;

            if(++GUI_YYBFQ_XS_delay == 255)
            {
                GUI_YYBFQ_XS_JDT_WZ_UP(GUI_YYBFQ_RUN_WJDX_A / GUI_YYBFQ_RUN_WJDX_DIV_100); //更新音乐播放器进度条滑块(位置偏移)
            }
            else if(GUI_YYBFQ_XS_delay == 127)
            {
                GUI_YYBFQ_XS_BTXZ_UP(); //更新音乐播放器标题显示翻页
            }
        }
        else //读文件失败
        {
            GUI_YYBFQ_XS_WJX = FAT32_GET_VOID_RWWJ_BZ(GUI_YYBFQ_XS_DEVICE); //申请文件号

            if(GUI_YYBFQ_XS_WJX != 255) //文件号有效
            {
                if(GUI_YYBFQ_XS_DQXH_K == 0 && GUI_YYBFQ_XS_XYQ_K != 0) //不是单曲循环,下一曲
                {
                    GUI_YYBFQ_KEY_BJ2(1); //音乐播放器-键(部件2,找出下一个MP3文件的文件名)
                    GUI_YYBFQ_XS_WJM_UP(); //更新音乐播放器文件名显示
                }
                else GUI_YYBFQ_XS_XYQ_K = 1;

                if(FAT32_OPENWJ(GUI_YYBFQ_XS_DEVICE,GUI_YYBFQ_XS_mulu_cuhao,GUI_YYBFQ_XS_WJX,GUI_YYBFQ_XS_WJM) == 0) //打开文件失败
                {
                    GUI_YYBFQ_XS_BFZT_K_UP(0); //暂停播放
                    GUI_YYBFQ_XS_WJX = 255; //文件号无效
                }

                  GUI_YYBFQ_XS_JDT_WZ_UP(0); //更新音乐播放器进度条滑块(位置偏移)
                  GUI_YYBFQ_RUN_WJDX_DIV_100 = FAT32_RETURN_WJDX_(GUI_YYBFQ_XS_DEVICE,GUI_YYBFQ_XS_WJX) / 100;
                  GUI_YYBFQ_RUN_WJDX_A = 0;
            }
            else
            {
                GUI_YYBFQ_XS_BFZT_K_UP(0); //暂停播放
                GUI_YYBFQ_XS_JDT_WZ_UP(0); //更新音乐播放器进度条滑块(位置偏移)
            }
        }

    }


}






void GUI_ZM_XS(unsigned char UP_K) //桌面-显示
{

unsigned char X;
unsigned char Y;
unsigned char *TBXS;
unsigned char *TBMC;

unsigned char js1;
unsigned char js2;
unsigned char js3;
unsigned int js4;


    if(UP_K & 0x01) //更新图标显示,图标选择0
    {

        GUI_SK0(7,7+210,0); //擦除图标显示区,210行像素


        js4 = GUI_ZM_XS_HX;
        TBMC = &GUI_ZM_XS_TBMC[js4*(3*13)]; //取图标名称数据首地址

        Y = GUI_ZM_XS_TBSH_Y;

        js2 = 0;

        do
        {

            X = GUI_ZM_XS_TBSL_X;
            js1 = 0;

            do
            {

                if(GUI_ZM_XS_HX*3 + js2 >= GUI_ZM_XS_TBX) goto out1; //已经没有图标数据

                js3 = GUI_ZM_XS_TBLX[GUI_ZM_XS_HX*3 + js2]; //读出图标类型

                if(js3 == 0)
                {
                   //TBXS = CCQXS;
                   TBXS = WJJXS1;
                }
                else if(js3 == 1)
                {
                   //TBXS = JSQXS;
                   TBXS = WJJXS1;
                }


                if(GUI_ZM_XS_TBXZ0_K != 0 && js2 == GUI_ZM_XS_TBXZ0) GUI_SK1(Y,X,GUI_ZM_XS_TBMC_YJJ+12,72,0x20); //写图标选择0背景色块

                GUI_32_32_XS(Y,X +(36-16),0x01,TBXS); //写图标

                js3 = 0;
                while(TBMC[js3] != 0) ++js3; //取图标名称长度
                printx(Y+GUI_ZM_XS_TBMC_YJJ,X + (36 - (js3 * 6 >> 1)),TBMC,125); //写图标名称


                TBMC += 13;
                X += GUI_ZM_XS_TB_XJJ;
                ++js1;
                ++js2;


            }while(js1 != 3);

            Y += GUI_ZM_XS_TB_YJJ;

        }while(js2 != 12);

        out1:
    }



    if(UP_K != 0) //更新上移按钮,下移按钮,图标选择1
    {

        Y = GUI_ZM_XS_TBSH_Y + (GUI_ZM_XS_TBXZ1_ / 3 * GUI_ZM_XS_TB_YJJ); //擦除图标选择1框框
        X = GUI_ZM_XS_TBSL_X + (GUI_ZM_XS_TBXZ1_ % 3 * GUI_ZM_XS_TB_XJJ);
        GUI_kuang0(Y-1,X-1,GUI_ZM_XS_TBMC_YJJ+12+1,73,0);

        if(GUI_ZM_XS_TBXZ1_K != 0)
        {
            Y = GUI_ZM_XS_TBSH_Y + (GUI_ZM_XS__TBXZ1 / 3 * GUI_ZM_XS_TB_YJJ); //写图标选择1框框
            X = GUI_ZM_XS_TBSL_X + (GUI_ZM_XS__TBXZ1 % 3 * GUI_ZM_XS_TB_XJJ);
            GUI_kuang0(Y-1,X-1,GUI_ZM_XS_TBMC_YJJ+12+1,73,0xa0);
        }

        GUI_ZMSY_KEY(0,0,GUI_ZM_XS_ZMSY_KEYXZ,GUI_ZM_XS_ZMSY_KEY);   //写上移按钮
        GUI_ZMXY_KEY(217,0,GUI_ZM_XS_ZMXY_KEYXZ,GUI_ZM_XS_ZMXY_KEY); //写下移按钮


    }


}


void GUI_ZM_XS_TBXZ1_UP(unsigned char TBXZ1) //更新桌面图标选择1
{

   GUI_ZM_XS_TBXZ1_ = GUI_ZM_XS__TBXZ1;

   if(TBXZ1 == 255)
   {
      GUI_ZM_XS_TBXZ1_K = 0;
   }
   else
   {
      GUI_ZM_XS__TBXZ1 = TBXZ1;
      GUI_ZM_XS_TBXZ1_K = 1;
   }

   GUI_UPBZ(253,0,2,0); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新

}

void GUI_ZM_XS_TBXZ0_UP(unsigned char TBXZ0) //更新桌面图标选择0
{

   if(TBXZ0 == 255)
   {
      GUI_ZM_XS_TBXZ0_K = 0;
   }
   else
   {
      GUI_ZM_XS_TBXZ0 = TBXZ0;
      GUI_ZM_XS_TBXZ0_K = 1;
   }

   GUI_UPBZ(253,0,1,0); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新

}

void GUI_ZM_XS_ZMSY_KEY_UP(unsigned char KEY) //更新桌面上移按钮(按下弹起)
{
   GUI_ZM_XS_ZMSY_KEY = KEY;
   GUI_UPBZ(253,0,2,0); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_ZM_XS_ZMXY_KEY_UP(unsigned char KEY) //更新桌面下移按钮(按下弹起)
{
   GUI_ZM_XS_ZMXY_KEY = KEY;
   GUI_UPBZ(253,0,2,0); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_ZM_XS_ZMSY_KEYXZ_UP(unsigned char XZ) //更新桌面上移按钮(选择)
{
   GUI_ZM_XS_ZMSY_KEYXZ = XZ;
   GUI_UPBZ(253,0,2,0); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_ZM_XS_ZMXY_KEYXZ_UP(unsigned char XZ) //更新桌面下移按钮(选择)
{
   GUI_ZM_XS_ZMXY_KEYXZ = XZ;
   GUI_UPBZ(253,0,2,0); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_ZM_XS_ADDHX_UP() //更新桌面上移行数(上移1行)
{
   if(GUI_ZM_XS_HX != 7)
   {
      ++GUI_ZM_XS_HX;
      GUI_UPBZ(253,0,1,0); //置更新标志,刷新窗口内容
      GUI_UP_K = 1; //打开GUI更新
   }
}

void GUI_ZM_XS_SUBHX_UP() //更新桌面上移行数(下移1行)
{
   if(GUI_ZM_XS_HX != 0)
   {
      --GUI_ZM_XS_HX;
      GUI_UPBZ(253,0,1,0); //置更新标志,刷新窗口内容
      GUI_UP_K = 1; //打开GUI更新
   }
}

unsigned char GUI_ZM_XS_GET_TBXZ0_ADD_HX() //返回现行选择的图标号(图标选择0)
{
   return GUI_ZM_XS_TBXZ0_K ? GUI_ZM_XS_HX*3+GUI_ZM_XS_TBXZ0 : 255;
}

unsigned char GUI_ZM_XS_GET_TBXZ1_ADD_HX() //返回现行选择的图标号(图标选择1)
{
   return GUI_ZM_XS_TBXZ1_K ? GUI_ZM_XS_HX*3+GUI_ZM_XS__TBXZ1 : 255;
}



void GUI_ZM_BOOT() //桌面-启动程序
{

unsigned char X;

    X = GUI_ZM_XS_GET_TBXZ1_ADD_HX(); //返回现行选择的图标号(图标选择1)

    if(X < 6) //存储器
    {
        GUI_BOOT_WJGL(X); //启动文件管理
    }
    else if(X == 6) //关闭计算机
    {
         XT_C = 0x80;
    }
    else if(X == 7)
    {
    }
    else if(X == 8)
    {
    }

}



unsigned char GUI_ZM_KEY_BJ1(unsigned char TBXZ) //桌面-键,部件1
{
   return GUI_ZM_XS_HX*3+TBXZ < GUI_ZM_XS_TBX;
}

unsigned char GUI_ZM_KEY(unsigned char SB_K,unsigned char KEY_K) //桌面-键
{

unsigned char NOACC;
unsigned char js1;
unsigned char js2;
unsigned char js3;


    if(SB_K != 0 && GUI_SBZBPD(0,6,0,255) != 0) //鼠标坐标在桌面上移按钮范围内
    {
        if(GUI_ZM_KEY_IO[0] == 0)
        {
           GUI_ZM_XS_ZMSY_KEYXZ_UP(1); //更新桌面上移按钮(选择)
           GUI_ZM_KEY_IO[0] = 1;
        }

        if(GUI_ZM_KEY_KXZ[0] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_ZM_KEY_KXZ[0] = 1; //弹起指向第1步
        }
        else if(GUI_ZM_KEY_KXZ[0] == 1)
        {
            if(GUI_SB_L_KEY() != 0)
            {
                GUI_ZM_KEY_KXZ[0] = 2; //按下指向第2步
                GUI_ZM_XS_ZMSY_KEY_UP(1); //更新桌面上移按钮(按下弹起)
            }
        }
        else if(GUI_ZM_KEY_KXZ[0] == 2)
        {
            if(GUI_SB_L_KEY() == 0)
            {
                GUI_ZM_KEY_KXZ[0] = 1; //弹起指向第1步
                GUI_ZM_XS_ZMSY_KEY_UP(0); //更新桌面上移按钮(按下弹起)
                GUI_ZM_XS_SUBHX_UP(); //更新桌面上移行数(上移1行)
            }
        }

    }
    else
    {
        if(GUI_ZM_KEY_IO[0] != 0)
        {
           GUI_ZM_XS_ZMSY_KEYXZ_UP(0); //更新桌面上移按钮(选择)
           GUI_ZM_KEY_IO[0] = 0;
        }

        if(GUI_ZM_KEY_KXZ[0] != 0)
        {
           GUI_ZM_XS_ZMSY_KEY_UP(0); //更新桌面上移按钮(按下弹起)
           GUI_ZM_KEY_KXZ[0] = 0;
        }

    }


    if(SB_K != 0 && GUI_SBZBPD(217,217+6,0,255) != 0) //鼠标坐标在桌面下移按钮范围内
    {
        if(GUI_ZM_KEY_IO[1] == 0)
        {
           GUI_ZM_XS_ZMXY_KEYXZ_UP(1); //更新桌面下移按钮(选择)
           GUI_ZM_KEY_IO[1] = 1;
        }

        if(GUI_ZM_KEY_KXZ[1] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_ZM_KEY_KXZ[1] = 1; //弹起指向第1步
        }
        else if(GUI_ZM_KEY_KXZ[1] == 1)
        {
            if(GUI_SB_L_KEY() != 0)
            {
                GUI_ZM_KEY_KXZ[1] = 2; //按下指向第2步
                GUI_ZM_XS_ZMXY_KEY_UP(1); //更新桌面下移按钮(按下弹起)
            }
        }
        else if(GUI_ZM_KEY_KXZ[1] == 2)
        {
            if(GUI_SB_L_KEY() == 0)
            {
                GUI_ZM_KEY_KXZ[1] = 1; //弹起指向第1步
                GUI_ZM_XS_ZMXY_KEY_UP(0); //更新桌面下移按钮(按下弹起)
                GUI_ZM_XS_ADDHX_UP(); //更新桌面上移行数(上移1行)
            }
        }
    }
    else
    {
        if(GUI_ZM_KEY_IO[1] != 0)
        {
           GUI_ZM_XS_ZMXY_KEYXZ_UP(0); //更新桌面下移按钮(选择)
           GUI_ZM_KEY_IO[1] = 0;
        }

        if(GUI_ZM_KEY_KXZ[1] != 0)
        {
           GUI_ZM_XS_ZMXY_KEY_UP(0); //更新桌面下移按钮(按下弹起)
           GUI_ZM_KEY_KXZ[1] = 0;
        }
    }




    NOACC = 0;
    js1 = 0;
    js2 = 0;
    js3 = 0;

    do
    {



        if(SB_K != 0 && GUI_SBZBPD(GUI_ZM_XS_TBSH_Y+(js3*GUI_ZM_XS_TB_YJJ),GUI_ZM_XS_TBSH_Y+GUI_ZM_XS_TBMC_YJJ+12-1+(js3*GUI_ZM_XS_TB_YJJ),GUI_ZM_XS_TBSL_X+(js2*GUI_ZM_XS_TB_XJJ),GUI_ZM_XS_TBSL_X+71+(js2*GUI_ZM_XS_TB_XJJ)) != 0 && GUI_ZM_KEY_BJ1(js1) != 0) //鼠标坐标在桌面下移按钮范围内
        {

            if(GUI_ZM_KEY_IO[2+js1] == 0)
            {
               GUI_ZM_XS_TBXZ1_UP(js1); //更新桌面图标选择1
               GUI_ZM_KEY_IO[2+js1] = 1;
            }

            if(GUI_ZM_KEY_KXZ[2+js1] == 0)
            {
                if(GUI_SB_L_KEY() == 0) GUI_ZM_KEY_KXZ[2+js1] = 1; //弹起指向第1步
            }
            else if(GUI_ZM_KEY_KXZ[2+js1] == 1)
            {
                if(GUI_SB_L_KEY() != 0) GUI_ZM_KEY_KXZ[2+js1] = 2; //按下指向第2步
            }
            else if(GUI_ZM_KEY_KXZ[2+js1] == 2)
            {
                if(GUI_SB_L_KEY() == 0)
                {
                    GUI_ZM_KEY_KXZ[2+js1] = 3; //弹起指向第3步
                    GUI_ZM_XS_TBXZ0_UP(js1); //更新桌面图标选择0
                }
            }
            else if(GUI_ZM_KEY_KXZ[2+js1] == 3)
            {
                if(GUI_SB_L_KEY() != 0) GUI_ZM_KEY_KXZ[2+js1] = 4; //按下指向第4步
            }
            else if(GUI_ZM_KEY_KXZ[2+js1] == 4)
            {
                if(GUI_SB_L_KEY() == 0)
                {
                    GUI_ZM_KEY_KXZ[2+js1] = 3; //弹起指向第3步(这里启动程序)
                    GUI_ZM_BOOT(); //启动程序
                }
            }
        }
        else
        {

            GUI_ZM_KEY_IO[2+js1] = 0;
            GUI_ZM_KEY_KXZ[2+js1] = 0;
            ++NOACC;

        }



        if(++js2 == 3) js2 = 0,++js3;

    }while(++js1 != 12);



    if(NOACC == 12) //没有落在12个图标内的任何一个
    {

        if(GUI_ZM_KEY_IO[14] != 0)
        {
           GUI_ZM_XS_TBXZ1_UP(255); //更新桌面图标选择1
           GUI_ZM_KEY_IO[14] = 0;
        }

        if(SB_K != 0)
        {
            if(GUI_ZM_KEY_KXZ[14] == 0)
            {
                if(GUI_SB_L_KEY() == 0) GUI_ZM_KEY_KXZ[14] = 1; //弹起指向第1步
            }
            else if(GUI_ZM_KEY_KXZ[14] == 1)
            {
                if(GUI_SB_L_KEY() != 0) GUI_ZM_KEY_KXZ[14] = 2; //按下指向第2步
            }
            else if(GUI_ZM_KEY_KXZ[14] == 2)
            {
                if(GUI_SB_L_KEY() == 0)
                {
                    GUI_ZM_KEY_KXZ[14] = 1; //弹起指向第1步
                    if(GUI_ZM_XS_TBXZ0_K != 0) GUI_ZM_XS_TBXZ0_UP(255); //更新桌面图标选择0
                }
            }
        }
        else
        {
            GUI_ZM_KEY_KXZ[14] = 0;
        }

    }
    else //有落在某个图标
    {
        GUI_ZM_KEY_IO[14] = 1;
        GUI_ZM_KEY_KXZ[14] = 0;
    }




    return SB_K != 0 && GUI_SBZBPD(0,217+6,0,255) != 0; //落在窗口内返回非0

}




void GUI_RWL_XS(unsigned char UP_K) //任务栏-显示
{


unsigned char js1;
unsigned char js2;
unsigned char js3;
unsigned char *_str;



    if(UP_K & 0x01)
    {

        //GUI_SK0(240-16,240,0xe3); //擦除任务栏显示区,16行像素
        GUI_SK0(240-16,240,0x05); //擦除任务栏显示区,16行像素

        GUI_KEY0(240-16,0,16,29,GUI_RWL_XS_KS_KEY);      //写开始按钮
        if(GUI_RWL_XS_KS_KEY != 0) js1 = 1;else js1 = 0;
        printx(240-14+js1,2+js1,"开始",255);

        if(GUI_RWL_XS_RTC_XZ != 0) GUI_SK1(240-16,256-6-6-6-6-6,16,30,110); //写时间图标选择色块
        print_ASCII(240-14,256-6,'0'+(GUI_RWL_XS_RTC_BCD_MIN & 0x0f),120); //写分钟,个位
        print_ASCII(240-14,256-6-6,'0'+((GUI_RWL_XS_RTC_BCD_MIN >> 4) & 0x0f),120); //写分钟,十位
        print_ASCII(240-14,256-6-6-6,':',120); //写分号
        print_ASCII(240-14,256-6-6-6-6,'0'+(GUI_RWL_XS_RTC_BCD_HR & 0x0f),120); //写小时,个位
        print_ASCII(240-14,256-6-6-6-6-6,'0'+((GUI_RWL_XS_RTC_BCD_HR >> 4) & 0x0f),120); //写小时,十位

        if(GUI_RWL_XS_WL_XZ != 0) GUI_SK1(240-16,256-6-6-6-6-6-17,16,16,61); //写网络图标选择色块
        if(GUI_RWL_XS_WL_X = 0) GUI_16_16_XS(240-16,256-6-6-6-6-6-17,0x01,SBXS1); //写网络图标0
   else if(GUI_RWL_XS_WL_X = 1) GUI_16_16_XS(240-16,256-6-6-6-6-6-17,0x01,SBXS1); //写网络图标1
   else if(GUI_RWL_XS_WL_X = 2) GUI_16_16_XS(240-16,256-6-6-6-6-6-17,0x01,SBXS1); //写网络图标2
   else GUI_16_16_XS(240-16,256-6-6-6-6-6-17,0x01,SBXS1); //写网络图标3

        if(GUI_RWL_XS_YL_XZ != 0) GUI_SK1(240-16,256-6-6-6-6-6-17-16,16,16,59); //写音量图标选择色块
        GUI_16_16_XS(240-16,256-6-6-6-6-6-17-16,0x01,SBXS1); //写音量图标

        if(GUI_RWL_XS_USB_XZ != 0) GUI_SK1(240-16,256-6-6-6-6-6-17-16-16,16,16,111); //写USB图标选择色块
        if(GUI_RWL_XS_USB_XS != 0) GUI_16_16_XS(240-16,256-6-6-6-6-6-17-16-16,0x01,SBXS1); //写USB图标

        if(GUI_RWL_XS_SYXY_XS != 0)  //写上下移按钮
        {
           GUI_SY_KEY(240-16,256-6-6-6-6-6-17-16-16-9,GUI_RWL_XS_SY_KEYXZ,GUI_RWL_XS_SY_KEY);
           GUI_XY_KEY(240-7,256-6-6-6-6-6-17-16-16-9,GUI_RWL_XS_XY_KEYXZ,GUI_RWL_XS_XY_KEY);
        }

        if(GUI_RWL_XS_XSZM_XZ != 0) GUI_SK1(240-16,29,16,16,93); //写显示桌面按钮选择色块
        GUI_16_16_XS(240-16,29,0x01,SBXS1); //写显示桌面按钮


        js1 = GUI_RWL_XS_SYHX*3 + 4; //算出窗口序号
        js3 = 0;

        do
        {
           for(js2 = 0;js1 != GUI_CKXH[js2] && GUI_CKXH[js2] != 0;++js2); //搜索窗口

           if(GUI_CKXH[js2] != 0) //找到窗口
           {

              js2 = GUI_CKLX[js2]; //读出窗口类型

              if(js2 == 0) _str = "文件..";
              else if(js2 == 1) _str = "计算器";
              else if(js2 == 2) _str = "音乐..";
              else if(js2 == 3) _str = "复制..";
              else _str = "未知";

              GUI_KEY0(240-16,29+16+js3*41,16,41,js2 = GUI_RWL_XS_CK_KEY[js3]); //写显示隐藏窗口按钮

              printx(240-14+js2,29+16+2+js3*41+js2,_str,255);

           }

           ++js1; //下一个窗口

        }while(++js3 != 3);


    }


    if(UP_K != 0)
    {
        if(GUI_RWL_XS_RTC_XZ != 0) js1 = 110; else js1 = 0x05; //写时间图标选择色块
        GUI_SK1(240-16,256-6-6-6-6-6,16,30,js1);

        print_ASCII(240-14,256-6,'0'+(GUI_RWL_XS_RTC_BCD_MIN & 0x0f),120); //写分钟,个位
        print_ASCII(240-14,256-6-6,'0'+((GUI_RWL_XS_RTC_BCD_MIN >> 4) & 0x0f),120); //写分钟,十位
        print_ASCII(240-14,256-6-6-6,':',120); //写分号
        print_ASCII(240-14,256-6-6-6-6,'0'+(GUI_RWL_XS_RTC_BCD_HR & 0x0f),120); //写小时,个位
        print_ASCII(240-14,256-6-6-6-6-6,'0'+((GUI_RWL_XS_RTC_BCD_HR >> 4) & 0x0f),120); //写小时,十位
    }


}


void GUI_RWL_XS_KS_KEY_UP(unsigned char KEY) //更新任务栏开始按钮(按下弹起)
{
   GUI_RWL_XS_KS_KEY = KEY;
   GUI_UPBZ(254,0,1,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_RWL_XS_RTC_XZ_UP(unsigned char KEY) //更新任务栏时间选择
{
   GUI_RWL_XS_RTC_XZ = KEY;
   GUI_UPBZ(254,0,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_RWL_XS_WL_XZ_UP(unsigned char KEY) //更新任务栏网络选择
{
   GUI_RWL_XS_WL_XZ = KEY;
   GUI_UPBZ(254,0,1,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_RWL_XS_YL_XZ_UP(unsigned char KEY) //更新任务栏音量选择
{
   GUI_RWL_XS_YL_XZ = KEY;
   GUI_UPBZ(254,0,1,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_RWL_XS_USB_XZ_UP(unsigned char KEY) //更新任务栏USB选择
{
   GUI_RWL_XS_USB_XZ = KEY;
   GUI_UPBZ(254,0,1,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_RWL_XS_SY_KEYXZ_UP(unsigned char KEY) //更新任务栏上移按钮选择
{
   GUI_RWL_XS_SY_KEYXZ = KEY;
   GUI_UPBZ(254,0,1,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_RWL_XS_XY_KEYXZ_UP(unsigned char KEY) //更新任务栏下移按钮选择
{
   GUI_RWL_XS_XY_KEYXZ = KEY;
   GUI_UPBZ(254,0,1,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_RWL_XS_SY_KEY_UP(unsigned char KEY) //更新任务栏上移按钮按下弹起
{
   GUI_RWL_XS_SY_KEY = KEY;
   GUI_UPBZ(254,0,1,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_RWL_XS_XY_KEY_UP(unsigned char KEY) //更新任务栏下移按钮按下弹起
{
   GUI_RWL_XS_XY_KEY = KEY;
   GUI_UPBZ(254,0,1,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_RWL_XS_XSZM_XZ_UP(unsigned char KEY) //更新任务栏显示桌面按钮选择
{
   GUI_RWL_XS_XSZM_XZ = KEY;
   GUI_UPBZ(254,0,1,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_RWL_XS_ADD_SYHX_UP() //更新任务栏显示隐藏窗口按钮(上移1行)
{
   if(GUI_RWL_XS_SYHX != 82) ++GUI_RWL_XS_SYHX;
   GUI_UPBZ(254,0,1,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_RWL_XS_SUB_SYHX_UP() //更新任务栏显示隐藏窗口按钮(下移1行)
{
   if(GUI_RWL_XS_SYHX != 0) --GUI_RWL_XS_SYHX;
   GUI_UPBZ(254,0,1,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_RWL_XS_SYXY_XS_UP() //更新任务栏上移下移按钮显示(启动关闭程序的时候调用刷新任务栏)
{
unsigned char smzz = 0;

   while(smzz != 255 && GUI_CKXH[smzz] != 7) ++smzz;
   if(smzz != 255) GUI_RWL_XS_SYXY_XS = 1; else GUI_RWL_XS_SYXY_XS = 0;
   GUI_UPBZ(254,0,1,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_RWL_XS_WL_X_UP(unsigned char SCXC,unsigned char MX) //更新任务栏网络图标状态,参数分别为上传下传选择(0上传1下传),传输忙/闲(1忙0闲)
{
   if(SCXC == 0)
   {
       if(MX == 0) GUI_RWL_XS_WL_X &= 0xfe; else GUI_RWL_XS_WL_X |= 0x01;
   }
   else
   {
       if(MX == 0) GUI_RWL_XS_WL_X &= 0xfd; else GUI_RWL_XS_WL_X |= 0x02;
   }

   GUI_UPBZ(254,0,1,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_RWL_XS_USB_XS_UP(unsigned char KEY) //更新任务栏USB显示
{
   GUI_RWL_XS_USB_XS = KEY;
   GUI_UPBZ(254,0,1,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_RWL_XS_RTC_UP(unsigned char HR,unsigned char MIN) //更新任务栏时间显示
{
   GUI_RWL_XS_RTC_BCD_MIN = MIN;
   GUI_RWL_XS_RTC_BCD_HR = HR;
   GUI_UPBZ(254,0,2,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}

void GUI_RWL_XS_CK_KEY_UP(unsigned char X,unsigned char KEY) //更新任务栏显示隐藏窗口按钮按下弹起,X的0~2选择3个按钮,KEY为1按下,为0弹起
{
   GUI_RWL_XS_CK_KEY[X] = KEY;
   GUI_UPBZ(254,0,1,1); //置更新标志,刷新窗口内容
   GUI_UP_K = 1; //打开GUI更新
}



unsigned char GUI_RWL_KEY_BJ1(unsigned char TBXZ) //任务栏-键,部件1
{
   return GUI_RWL_XS_SYHX*3+4+TBXZ <= GUI_GET_MAX_CKXH();
}

unsigned char GUI_RWL_KEY(unsigned char SB_K,unsigned char KEY_K) //任务栏-键
{

unsigned char js1;
unsigned long int js2;


    if(SB_K != 0 && GUI_SBZBPD(240-16,239,0,28) != 0) //鼠标坐标在任务栏开始按钮范围内
    {

        if(GUI_RWL_KEY_KXZ[0] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_RWL_KEY_KXZ[0] = 1; //弹起指向第1步
        }
        else if(GUI_RWL_KEY_KXZ[0] == 1)
        {
            if(GUI_SB_L_KEY() != 0)
            {
                GUI_RWL_XS_KS_KEY_UP(1); //更新任务栏开始按钮(按下弹起)
                GUI_RWL_KEY_KXZ[0] = 2; //按下指向第2步
            }
        }
        else if(GUI_RWL_KEY_KXZ[0] == 2)
        {
            if(GUI_SB_L_KEY() == 0)
            {
                GUI_RWL_KEY_KXZ[0] = 1; //弹起指向第1步
                GUI_RWL_XS_KS_KEY_UP(0); //更新任务栏开始按钮(按下弹起)
            }
        }

    }
    else
    {
        if(GUI_RWL_KEY_KXZ[0] != 0)
        {
           GUI_RWL_KEY_KXZ[0] = 0;
           GUI_RWL_XS_KS_KEY_UP(0); //更新任务栏开始按钮(按下弹起)
        }
    }



    if(SB_K != 0 && GUI_SBZBPD(240-16,239,29,29+15) != 0) //鼠标坐标在显示桌面按钮范围内
    {

        if(GUI_RWL_KEY_IO[1] == 0)
        {
           GUI_RWL_XS_XSZM_XZ_UP(1); //更新任务栏显示桌面按钮选择
           GUI_RWL_KEY_IO[1] = 1;
        }

        if(GUI_RWL_KEY_KXZ[1] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_RWL_KEY_KXZ[1] = 1; //弹起指向第1步
        }
        else if(GUI_RWL_KEY_KXZ[1] == 1)
        {
            if(GUI_SB_L_KEY() != 0) GUI_RWL_KEY_KXZ[1] = 2; //按下指向第2步
        }
        else if(GUI_RWL_KEY_KXZ[1] == 2)
        {
            if(GUI_SB_L_KEY() == 0)
            {
                GUI_RWL_KEY_KXZ[1] = 1; //弹起指向第1步
            }
        }

    }
    else
    {

        if(GUI_RWL_KEY_IO[1] != 0)
        {
           GUI_RWL_XS_XSZM_XZ_UP(0); //更新任务栏显示桌面按钮选择
           GUI_RWL_KEY_IO[1] = 0;
        }

        GUI_RWL_KEY_KXZ[1] = 0;

    }


    if(SB_K != 0 && GUI_SBZBPD(240-16,239,256-30,255) != 0) //鼠标坐标在时间显示范围内
    {

        if(GUI_RWL_KEY_IO[2] == 0)
        {
           GUI_RWL_XS_RTC_XZ_UP(1); //更新任务栏时间选择
           GUI_RWL_KEY_IO[2] = 1;
        }

        if(GUI_RWL_KEY_KXZ[2] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_RWL_KEY_KXZ[2] = 1; //弹起指向第1步
        }
        else if(GUI_RWL_KEY_KXZ[2] == 1)
        {
            if(GUI_SB_L_KEY() != 0) GUI_RWL_KEY_KXZ[2] = 2; //按下指向第2步
        }
        else if(GUI_RWL_KEY_KXZ[2] == 2)
        {
            if(GUI_SB_L_KEY() == 0)
            {
                GUI_RWL_KEY_KXZ[2] = 1; //弹起指向第1步
            }
        }

    }
    else
    {

        if(GUI_RWL_KEY_IO[2] != 0)
        {
           GUI_RWL_XS_RTC_XZ_UP(0); //更新任务栏时间选择
           GUI_RWL_KEY_IO[2] = 0;
        }

        GUI_RWL_KEY_KXZ[2] = 0;

    }


    if(SB_K != 0 && GUI_SBZBPD(240-16,239,256-31-16,256-31-1) != 0) //鼠标坐标在网络图标范围内
    {

        if(GUI_RWL_KEY_IO[3] == 0)
        {
           GUI_RWL_XS_WL_XZ_UP(1); //更新任务栏网络选择
           GUI_RWL_KEY_IO[3] = 1;
        }

        if(GUI_RWL_KEY_KXZ[3] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_RWL_KEY_KXZ[3] = 1; //弹起指向第1步
        }
        else if(GUI_RWL_KEY_KXZ[3] == 1)
        {
            if(GUI_SB_L_KEY() != 0) GUI_RWL_KEY_KXZ[3] = 2; //按下指向第2步
        }
        else if(GUI_RWL_KEY_KXZ[3] == 2)
        {
            if(GUI_SB_L_KEY() == 0)
            {
                GUI_RWL_KEY_KXZ[3] = 1; //弹起指向第1步
            }
        }

    }
    else
    {

        if(GUI_RWL_KEY_IO[3] != 0)
        {
           GUI_RWL_XS_WL_XZ_UP(0); //更新任务栏网络选择
           GUI_RWL_KEY_IO[3] = 0;
        }

        GUI_RWL_KEY_KXZ[3] = 0;

    }


    if(SB_K != 0 && GUI_SBZBPD(240-16,239,256-31-16-16,256-31-16-1) != 0) //鼠标坐标在音量图标范围内
    {

        if(GUI_RWL_KEY_IO[4] == 0)
        {
           GUI_RWL_XS_YL_XZ_UP(1); //更新任务栏音量选择
           GUI_RWL_KEY_IO[4] = 1;
        }

        if(GUI_RWL_KEY_KXZ[4] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_RWL_KEY_KXZ[4] = 1; //弹起指向第1步
        }
        else if(GUI_RWL_KEY_KXZ[4] == 1)
        {
            if(GUI_SB_L_KEY() != 0) GUI_RWL_KEY_KXZ[4] = 2; //按下指向第2步
        }
        else if(GUI_RWL_KEY_KXZ[4] == 2)
        {
            if(GUI_SB_L_KEY() == 0)
            {
                GUI_RWL_KEY_KXZ[4] = 1; //弹起指向第1步
            }
        }

    }
    else
    {

        if(GUI_RWL_KEY_IO[4] != 0)
        {
           GUI_RWL_XS_YL_XZ_UP(0); //更新任务栏音量选择
           GUI_RWL_KEY_IO[4] = 0;
        }

        GUI_RWL_KEY_KXZ[4] = 0;

    }


    if(SB_K != 0 && GUI_SBZBPD(240-16,239,256-31-16-16-16,256-31-16-16-1) != 0 && GUI_RWL_XS_USB_XS == 1) //鼠标坐标在USB图标范围内
    {

        if(GUI_RWL_KEY_IO[5] == 0)
        {
           GUI_RWL_XS_USB_XZ_UP(1); //更新任务栏USB选择
           GUI_RWL_KEY_IO[5] = 1;
        }

        if(GUI_RWL_KEY_KXZ[5] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_RWL_KEY_KXZ[5] = 1; //弹起指向第1步
        }
        else if(GUI_RWL_KEY_KXZ[5] == 1)
        {
            if(GUI_SB_L_KEY() != 0) GUI_RWL_KEY_KXZ[5] = 2; //按下指向第2步
        }
        else if(GUI_RWL_KEY_KXZ[5] == 2)
        {
            if(GUI_SB_L_KEY() == 0)
            {
                GUI_RWL_KEY_KXZ[5] = 1; //弹起指向第1步
            }
        }

    }
    else
    {

        if(GUI_RWL_KEY_IO[5] != 0)
        {
           GUI_RWL_XS_USB_XZ_UP(0); //更新任务栏USB选择
           GUI_RWL_KEY_IO[5] = 0;
        }

        GUI_RWL_KEY_KXZ[5] = 0;

    }


    if(SB_K != 0 && GUI_SBZBPD(240-16,240-16+6,256-31-16-16-16-9,256-31-16-16-16-1) != 0) //鼠标坐标在上移按钮范围内
    {

        if(GUI_RWL_KEY_IO[6] == 0)
        {
           GUI_RWL_XS_SY_KEYXZ_UP(1); //更新任务栏上移按钮选择
           GUI_RWL_KEY_IO[6] = 1;
        }

        if(GUI_RWL_KEY_KXZ[6] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_RWL_KEY_KXZ[6] = 1; //弹起指向第1步
        }
        else if(GUI_RWL_KEY_KXZ[6] == 1)
        {
            if(GUI_SB_L_KEY() != 0)
            {
                GUI_RWL_XS_SY_KEY_UP(1); //更新任务栏上移按钮按下弹起
                GUI_RWL_KEY_KXZ[6] = 2; //按下指向第2步
            }
        }
        else if(GUI_RWL_KEY_KXZ[6] == 2)
        {
            if(GUI_SB_L_KEY() == 0)
            {
                GUI_RWL_XS_SY_KEY_UP(0); //更新任务栏上移按钮按下弹起
                GUI_RWL_XS_SUB_SYHX_UP(); //更新任务栏显示隐藏窗口按钮(上移1行)
                GUI_RWL_KEY_KXZ[6] = 1; //弹起指向第1步
            }
        }

    }
    else
    {

        if(GUI_RWL_KEY_IO[6] != 0)
        {
           GUI_RWL_XS_SY_KEYXZ_UP(0); //更新任务栏上移按钮选择
           GUI_RWL_KEY_IO[6] = 0;
        }

        if(GUI_RWL_KEY_KXZ[6] != 0)
        {
           GUI_RWL_XS_SY_KEY_UP(0); //更新任务栏上移按钮按下弹起
           GUI_RWL_KEY_KXZ[6] = 0;
        }

    }


    if(SB_K != 0 && GUI_SBZBPD(240-7,239,256-31-16-16-16-9,256-31-16-16-16-1) != 0) //鼠标坐标在下移按钮范围内
    {

        if(GUI_RWL_KEY_IO[7] == 0)
        {
           GUI_RWL_XS_XY_KEYXZ_UP(1); //更新任务栏上移按钮选择
           GUI_RWL_KEY_IO[7] = 1;
        }

        if(GUI_RWL_KEY_KXZ[7] == 0)
        {
            if(GUI_SB_L_KEY() == 0) GUI_RWL_KEY_KXZ[7] = 1; //弹起指向第1步
        }
        else if(GUI_RWL_KEY_KXZ[7] == 1)
        {
            if(GUI_SB_L_KEY() != 0)
            {
                GUI_RWL_XS_XY_KEY_UP(1); //更新任务栏上移按钮按下弹起
                GUI_RWL_KEY_KXZ[7] = 2; //按下指向第2步
            }
        }
        else if(GUI_RWL_KEY_KXZ[7] == 2)
        {
            if(GUI_SB_L_KEY() == 0)
            {
                GUI_RWL_XS_XY_KEY_UP(0); //更新任务栏上移按钮按下弹起
                GUI_RWL_XS_ADD_SYHX_UP(); //更新任务栏显示隐藏窗口按钮(下移1行)
                GUI_RWL_KEY_KXZ[7] = 1; //弹起指向第1步
            }
        }

    }
    else
    {

        if(GUI_RWL_KEY_IO[7] != 0)
        {
           GUI_RWL_XS_XY_KEYXZ_UP(0); //更新任务栏上移按钮选择
           GUI_RWL_KEY_IO[7] = 0;
        }

        if(GUI_RWL_KEY_KXZ[7] != 0)
        {
           GUI_RWL_XS_XY_KEY_UP(0); //更新任务栏上移按钮按下弹起
           GUI_RWL_KEY_KXZ[7] = 0;
        }

    }




    js1 = 0;

    do
    {

        if(SB_K != 0 && GUI_SBZBPD(240-16,239,29+16+(js1*41),29+16+40+(js1*41)) != 0 && GUI_RWL_KEY_BJ1(js1) != 0) //鼠标坐标在任务栏开始按钮范围内
        {

            if(GUI_RWL_KEY_KXZ[8+js1] == 0)
            {
                if(GUI_SB_L_KEY() == 0) GUI_RWL_KEY_KXZ[8+js1] = 1; //弹起指向第1步
            }
            else if(GUI_RWL_KEY_KXZ[8+js1] == 1)
            {
                if(GUI_SB_L_KEY() != 0)
                {
                    GUI_RWL_XS_CK_KEY_UP(js1,1); //更新任务栏显示隐藏窗口按钮按下弹起,X的0~2选择3个按钮,KEY为1按下,为0弹起
                    GUI_RWL_KEY_KXZ[8+js1] = 2; //按下指向第2步
                }
            }
            else if(GUI_RWL_KEY_KXZ[8+js1] == 2)
            {
                if(GUI_SB_L_KEY() == 0)
                {
                    GUI_RWL_KEY_KXZ[8+js1] = 1; //弹起指向第1步
                    GUI_RWL_XS_CK_KEY_UP(js1,0); //更新任务栏显示隐藏窗口按钮按下弹起,X的0~2选择3个按钮,KEY为1按下,为0弹起

                    js2 = GUI_GET_CKLX_CKH_CKXS_CKUP(GUI_RWL_XS_SYHX*3+4+js1); //取GUI表数据

                    if((js2 & 0x0000ff00) != 0 && GUI_GET_CK_CENGX(js2 >> 24,js2 >> 16) == 0) //窗口为显示并且是前置
                    {
                        GUI_ZXHCK(js2 >> 24,js2 >> 16); //最小化窗口
                    }
                    else //窗口为最小化或非前置
                    {
                        GUI_QZCK(js2 >> 24,js2 >> 16); //前置窗口
                    }
                    
                }
            }

        }
        else
        {
            if(GUI_RWL_KEY_KXZ[8+js1] != 0)
            {
               GUI_RWL_KEY_KXZ[8+js1] = 0;
               GUI_RWL_XS_CK_KEY_UP(js1,0); //更新任务栏显示隐藏窗口按钮按下弹起,X的0~2选择3个按钮,KEY为1按下,为0弹起
            }
        }


    }while(++js1 != 3);



    return SB_K != 0 && GUI_SBZBPD(240-16,239,0,255) != 0; //落在窗口内返回非0
}



void GUI_RWL_RUN() //任务栏-后台运行
{

unsigned char js1;

   if(++GUI_RWL_RUN_RTC_UP_delay == 255) //延时够数,进入刷新时间
   {
       if((js1 = DS1302_RD(1)) != GUI_RWL_RUN_RTC_UP_MIN_) //分钟数据有变化,进入刷新时间
       {
           GUI_RWL_RUN_RTC_UP_MIN_ = js1;
           GUI_RWL_XS_RTC_UP(DS1302_RD(2),js1); //更新任务栏时间显示
       }
   }
}




unsigned char GUI_KEY(unsigned char CKLX,unsigned char CKH,unsigned char SB_K,unsigned char KEY_K) //参数分别为,窗口类型,窗口号,鼠标输入控制,键盘输入控制,返回值不为0表示坐标落在窗口内
{

unsigned char returnX = 0;

     if(CKLX == 253) //桌面
     {
         returnX = GUI_ZM_KEY(SB_K,KEY_K);
     }
     else if(CKLX == 254) //任务栏
     {
         returnX = GUI_RWL_KEY(SB_K,KEY_K);
     }
     else if(CKLX == 255) //菜单
     {
         if(CKH == 0)
         {
             returnX = GUI_WJGL_CD_KEY(SB_K,KEY_K); //文件管理-菜单-键
         }
         else if(CKH == 1)
         {
         }
     }
     else if(CKLX == 0) //文件管理
     {
         returnX = GUI_WJGL_KEY(SB_K,KEY_K);
     }
     else if(CKLX == 2) //音乐播放器
     {
         returnX = GUI_YYBFQ_KEY(SB_K,KEY_K); //音乐播放器-键
     }
     else if(CKLX == 3) //文件管理-进度条
     {
         returnX = GUI_WJGL_JDT_KEY(CKH,SB_K,KEY_K); //文件管理-进度条-键
     }



     return returnX;

}

void GUI_XS(unsigned char CKLX,unsigned char CKH,unsigned char UP_K) //参数分别为,窗口类型,窗口号,更新控制
{


     if(CKLX == 253) //桌面
     {
         GUI_ZM_XS(UP_K);
     }
     else if(CKLX == 254) //任务栏
     {
         GUI_RWL_XS(UP_K);
     }
     else if(CKLX == 255) //菜单
     {
         if(CKH == 0)
         {
             GUI_WJGL_CD_XS(UP_K); //文件管理-菜单-显示(文件右键菜单和目录下右键菜单)
         }
         else if(CKH == 1)
         {
         }
     }
     else if(CKLX == 0) //文件管理
     {
         GUI_WJGL_XS(UP_K);
     }
     else if(CKLX == 2) //音乐播放器
     {
         GUI_YYBFQ_XS(UP_K); //音乐播放器-显示
     }
     else if(CKLX == 3) //文件管理-进度条
     {
         GUI_WJGL_JDT_XS(CKH,UP_K); //文件管理-进度条-显示
     }



}


void GUI_KEY_UP() //窗口鼠标键盘输入更新数据
{

unsigned char smzz;
unsigned char js1;
unsigned char js2;
unsigned char js3;

    smzz = 255;
    js2 = 1;
    js3 = 1;


    do
    {

        --smzz; //退一格

        if((js1 = GUI_CKXH[smzz]) != 0) //找到有效窗口
        {

            if(js1 == 3) //为菜单
            {
                if(GUI_KEY(255,0,1,1) == 1) js3 = 0; //坐标落在窗口内,撤销下层的鼠标输入
                js2 = 0; //撤销下层的键盘输入
            }
            else
            {
                if(GUI_CKXS[smzz] != 0) //没有最小化
                {

                    if(GUI_KEY(GUI_CKLX[smzz],GUI_CKH[smzz],js3,js2) == 1) //坐标落在窗口内
                    {
                        if(js1 != 2) js2 = 0; //此窗口不是任务栏则撤销下层的键盘输入
                        js3 = 0; //撤销下层的鼠标输入
                    }
                    else //坐标没有落在窗口内
                    {
                        if(js1 != 2) js2 = 0; //此窗口不是任务栏则撤销下层的键盘输入
                    }

                }

            }

        }

    }while(smzz != 0);

}


void GUI_XS_UP() //刷新窗口内容
{

unsigned char smzz;

    smzz = 0;

    while(GUI_CKXH[smzz] != 0) //有效窗口
    {
        if(GUI_CKUP[smzz] != 0) //有更新标志
        {

            if(GUI_CKXS[smzz] != 0) //窗口没有最小化
            {
                GUI_XS(GUI_CKLX[smzz],GUI_CKH[smzz],GUI_CKUP[smzz]); //更新窗口
            }

            GUI_CKUP[smzz] = 0;
        }

        ++smzz;
    }

}






void GUI_CSH() //GUI初始化
{

unsigned char js1;
unsigned int js2;
unsigned char *_addr;


/*************************初始化鼠标坐标**************************/

   GUI_WR_SB_Y(119);
   GUI_WR_SB_X(127);
   GUI_WR_SB_Z(0);


/**************************初始化GUI表****************************/

    GUI_CKXH[0] = 1; //序号为桌面
    GUI_CKLX[0] = 253; //类型为桌面
    GUI_CKH[0] = 0; //窗口号为0
    GUI_CKXS[0] = 1; //显示
    GUI_CKUP[0] = 1; //首次全局更新

    GUI_CKXH[1] = 2; //序号为任务栏
    GUI_CKLX[1] = 254; //类型为任务栏
    GUI_CKH[1] = 0; //窗口号为0
    GUI_CKXS[1] = 1; //显示
    GUI_CKUP[1] = 1; //首次全局更新

    js1 = 1;
    do
    {
       ++js1;
       GUI_CKXH[js1] = 0;  //清0窗口序号标志

    }while(js1 != 255);



/***************************初始化桌面****************************/

    GUI_ZM_XS_TBX = 7; //图标数量为7
    GUI_ZM_XS_HX = 0;  //上移行数为0
    GUI_ZM_XS_ZMSY_KEY = 0; //桌面上移按钮,按下为1,否则为0
    GUI_ZM_XS_ZMXY_KEY = 0;   //桌面下移按钮,按下为1,否则为0
    GUI_ZM_XS_ZMSY_KEYXZ = 0; //桌面上移按钮,选中为1,否则为0
    GUI_ZM_XS_ZMXY_KEYXZ = 0; //桌面下移按钮,选中为1,否则为0

    GUI_ZM_XS_TBXZ0 = 0;   //图标选择0,桌面图标背景色块,鼠标点击才选择,0~11
    GUI_ZM_XS_TBXZ0_K = 0; //图标选择0,桌面图标背景色块显示控制,为1显示,为0不显示

    GUI_ZM_XS__TBXZ1 = 0;  //图标选择1,选择框,跟随鼠标选择,新值,0~11
    GUI_ZM_XS_TBXZ1_ = 0;  //图标选择1,选择框,跟随鼠标选择,旧值,0~11
    GUI_ZM_XS_TBXZ1_K = 0; //图标选择1,桌面图标选择框显示控制,为1显示,为0不显示

    js2 = 0;
    while(js2 != 312) GUI_ZM_XS_TBMC[js2] = 0,++js2; //清0图标名称

    _addr = GUI_ZM_XS_TBMC;

    strcat(_addr,"SPI存储器0"); _addr+=13;
    strcat(_addr,"SPI存储器1"); _addr+=13;
    strcat(_addr,"USB存储器0"); _addr+=13;
    strcat(_addr,"USB存储器1"); _addr+=13;
    strcat(_addr,"USB存储器2"); _addr+=13;
    strcat(_addr,"USB存储器3"); _addr+=13;
    strcat(_addr,"关闭计算机");


    GUI_ZM_XS_TBLX[0] = 0;
    GUI_ZM_XS_TBLX[1] = 0;
    GUI_ZM_XS_TBLX[2] = 0;
    GUI_ZM_XS_TBLX[3] = 0;
    GUI_ZM_XS_TBLX[4] = 0;
    GUI_ZM_XS_TBLX[5] = 0;
    GUI_ZM_XS_TBLX[6] = 1;


/***************************初始化任务栏**************************/


    GUI_RWL_XS_KS_KEY = 0; //开始按钮,为1按下,为0弹起
    GUI_RWL_XS_RTC_XZ = 0; //时间选择,为1选择,为0不选择
    GUI_RWL_XS_WL_XZ = 0;  //网络选择,为1选择,为0不选择
    GUI_RWL_XS_WL_X = 0;   //网络图标切换,0为空闲,1为上传,2为下传,3为上下传
    GUI_RWL_XS_YL_XZ = 0;  //音量选择,为1选择,为0不选择
    GUI_RWL_XS_USB_XZ = 0; //USB选择,为1选择,为0不选择
    GUI_RWL_XS_USB_XS = 0; //USB显示,为1显示,为0不显示

    GUI_RWL_XS_SY_KEYXZ = 0; //上移按钮选择,为1选择,为0不选择
    GUI_RWL_XS_SY_KEY = 0;   //上移按钮,为1按下,为0不按下
    GUI_RWL_XS_XY_KEYXZ = 0; //下移按钮选择,为1选择,为0不选择
    GUI_RWL_XS_XY_KEY = 0;   //下移按钮,为1按下,为0不按下
    GUI_RWL_XS_SYXY_XS = 1;  //上移下移按钮显示,为1显示,为0不显示

    GUI_RWL_XS_SYHX = 0;   //上移行数,记录任务栏显示隐藏窗口按钮上移的行数

    GUI_RWL_XS_XSZM_XZ = 0;  //显示桌面按钮选择,为1选择,为0不选择

    GUI_RWL_XS_CK_KEY[0] = 0;  //显示隐藏窗口按钮,为1按下,为0弹起
    GUI_RWL_XS_CK_KEY[1] = 0;  //显示隐藏窗口按钮,为1按下,为0弹起
    GUI_RWL_XS_CK_KEY[2] = 0;  //显示隐藏窗口按钮,为1按下,为0弹起

    GUI_RWL_XS_RTC_BCD_MIN = DS1302_RD(1); //时间数据,分钟,BCD格式
    GUI_RWL_XS_RTC_BCD_HR = DS1302_RD(2);  //时间数据,小时,BCD格式

    GUI_RUN_IO[0] = 0; //GUI-运行,进出标志
}


void GUI_RUN(unsigned char UP_K) //GUI-运行
{

unsigned char js1;
unsigned int i;
unsigned int x;

    if(UP_K != 0 || GUI_UP_K != 0) //进入更新数据
    {

         GUI_VRAM_LD();

         if(SBXSHY_K == 1) GUI_16_16_HY(GUI_SB_Y_,GUI_SB_X_,0x01,SBXS1,SBXSBC_buf),SBXSHY_K = 0; //还原鼠标掩盖像素


         if(CH375_GET_SBX() != 0) //有USB设备
         {
             if(GUI_RUN_IO[0] == 0)
             {
                 GUI_RUN_IO[0] = 1;
                 GUI_RWL_XS_USB_XS_UP(1); //更新任务栏USB显示
             }
         }
         else
         {
             if(GUI_RUN_IO[0] != 0)
             {
                 GUI_RUN_IO[0] = 0;
                 GUI_RWL_XS_USB_XS_UP(0); //更新任务栏USB显示
             }
         }



         GUI_KEY_UP(); //窗口鼠标键盘输入更新数据
         GUI_XS_UP(); //刷新窗口内容

         GUI_UP_K = 0;



         GUI_16_16_BC(SB_Y,SB_X,0x01,SBXS1,SBXSBC_buf); //保存鼠标掩盖像素
         GUI_16_16_XS(SB_Y,SB_X,0x01,SBXS1); //写鼠标像素
         GUI_SB_Y_ = SB_Y; //这个坐标记录到旧值
         GUI_SB_X_ = SB_X;
         GUI_SB_Z_ = SB_Z;
         SBXSHY_K = 1;


/*
         GUI_SK1(120,127,72,18,255);
         printx(120,127,U32_str(GUI_WJGL_FZWJ_X),0);
         printx(132,127,U32_str(XXXXXXX),0);
         printx(144,127,U32_str(FAT32_ML_SETUP_WJ_XZ),0);
         printx(156,127,U32_str(GUI_WJGL_FZWJ_K),0);
         printx(168,127,U32_str(XXXXXXX1),0);
         printx(180,127,U32_str(XXXXXXX2),0);


         GUI_SK1(120,127,48,18,255);
         printx(120,127,U32_str(GUI_CKXH[0]),0);
         printx(132,127,U32_str(GUI_CKXH[1]),0);
         printx(144,127,U32_str(GUI_CKXH[2]),0);
         printx(156,127,U32_str(GUI_GET_MAX_CKXH()),0);
*/

//         TFT_VRAM_TFTRAM(); //复制VGA显存数据到TFT显存
         GUI_VRAM_UP();


         if(CH375_SBDM[0] == 0) FAT32_BZ[2] = 0; //USB没有设备的时候清零FAT32文件系统标志
         if(CH375_SBDM[1] == 0) FAT32_BZ[3] = 0;
         if(CH375_SBDM[2] == 0) FAT32_BZ[4] = 0;
         if(CH375_SBDM[3] == 0) FAT32_BZ[5] = 0;


    }


    GUI_WJGL_RUN(); //文件管理-后台运行
    GUI_RWL_RUN();  //任务栏-后台运行
    GUI_YYBFQ_RUN();  //音乐播放器-后台运行


}