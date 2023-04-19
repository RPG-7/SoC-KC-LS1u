unsigned char KEY_XXX(unsigned char keydata)
{
   unsigned char i = 0;
   while(++i,i < 8 && KEY_DATA[i] != keydata);
   return i<8?1:0;
}



unsigned char KEY_Num_Lock() //左灯
{
   return KEY_XXX(0x53);
}

unsigned char KEY_Scroll_Lock() //中灯
{
   return KEY_XXX(0x39);
}

unsigned char KEY_Caps_Lock() //右灯
{
   return KEY_XXX(0x47);
}

unsigned char KEY_UP() //箭头上
{
   return KEY_XXX(0x52);
}

unsigned char KEY_DOWN() //箭头下
{
   return KEY_XXX(0x51);
}

unsigned char KEY_LEFT() //箭头左
{
   return KEY_XXX(0x50);
}

unsigned char KEY_RIGHT() //箭头右
{
   return KEY_XXX(0x4f);
}


unsigned char KEY_Return() //回车1
{
   return KEY_XXX(0x28);
}

unsigned char KEY_Esc() //键盘左上角按键
{
   return KEY_XXX(0x29);
}

unsigned char KEY_Backspace() //箭头指左的删除键
{
   return KEY_XXX(0x2a);
}

unsigned char KEY_Tab() //Tab
{
   return KEY_XXX(0x2b);
}

unsigned char KEY_Spacebar() //Spacebar
{
   return KEY_XXX(0x2c);
}




unsigned char KEY_A() //A
{
   return KEY_XXX(0x04);
}

unsigned char KEY_B() //B
{
   return KEY_XXX(0x05);
}

unsigned char KEY_C() //C
{
   return KEY_XXX(0x06);
}

unsigned char KEY_D() //D
{
   return KEY_XXX(0x07);
}

unsigned char KEY_E() //E
{
   return KEY_XXX(0x08);
}

unsigned char KEY_F() //F
{
   return KEY_XXX(0x09);
}

unsigned char KEY_G() //G
{
   return KEY_XXX(0x0a);
}

unsigned char KEY_H() //H
{
   return KEY_XXX(0x0b);
}

unsigned char KEY_I() //I
{
   return KEY_XXX(0x0c);
}

unsigned char KEY_J() //J
{
   return KEY_XXX(0x0d);
}

unsigned char KEY_K() //K
{
   return KEY_XXX(0x0e);
}

unsigned char KEY_L() //L
{
   return KEY_XXX(0x0f);
}

unsigned char KEY_M() //M
{
   return KEY_XXX(0x10);
}

unsigned char KEY_N() //N
{
   return KEY_XXX(0x11);
}

unsigned char KEY_O() //O
{
   return KEY_XXX(0x12);
}

unsigned char KEY_P() //P
{
   return KEY_XXX(0x13);
}

unsigned char KEY_Q() //Q
{
   return KEY_XXX(0x14);
}

unsigned char KEY_R() //R
{
   return KEY_XXX(0x15);
}

unsigned char KEY_S() //S
{
   return KEY_XXX(0x16);
}

unsigned char KEY_T() //T
{
   return KEY_XXX(0x17);
}

unsigned char KEY_U() //U
{
   return KEY_XXX(0x18);
}

unsigned char KEY_V() //V
{
   return KEY_XXX(0x19);
}

unsigned char KEY_W() //W
{
   return KEY_XXX(0x1a);
}

unsigned char KEY_X() //X
{
   return KEY_XXX(0x1b);
}

unsigned char KEY_Y() //Y
{
   return KEY_XXX(0x1c);
}

unsigned char KEY_Z() //Z
{
   return KEY_XXX(0x1d);
}





unsigned char KEY_1() //1
{
   return KEY_XXX(0x1e);
}

unsigned char KEY_2() //2
{
   return KEY_XXX(0x1f);
}

unsigned char KEY_3() //3
{
   return KEY_XXX(0x20);
}

unsigned char KEY_4() //4
{
   return KEY_XXX(0x21);
}

unsigned char KEY_5() //5
{
   return KEY_XXX(0x22);
}

unsigned char KEY_6() //6
{
   return KEY_XXX(0x23);
}

unsigned char KEY_7() //7
{
   return KEY_XXX(0x24);
}

unsigned char KEY_8() //8
{
   return KEY_XXX(0x25);
}

unsigned char KEY_9() //9
{
   return KEY_XXX(0x26);
}

unsigned char KEY_0() //0
{
   return KEY_XXX(0x27);
}


