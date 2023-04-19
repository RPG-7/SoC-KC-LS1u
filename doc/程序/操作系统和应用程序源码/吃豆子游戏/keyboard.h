unsigned char keyboard_query(unsigned char keydata)
{
   unsigned char i = 2;
   while (i < 8 && KEY_DATA[i] != keydata) ++i;
   return i < 8 ? 1 : 0;
}


unsigned char keyboard_UpArrow() //ÉÏ
{
	return keyboard_query(0x52);
}

unsigned char keyboard_DownArrow() //ÏÂ
{
	return keyboard_query(0x51);
}

unsigned char keyboard_LeftArrow() //×ó
{
	return keyboard_query(0x50);
}

unsigned char keyboard_RightArrow() //ÓÒ
{
	return keyboard_query(0x4f);
}

unsigned char keyboard_Spacebar() //¿Õ¸ñ
{
	return keyboard_query(0x2c);
}

unsigned char keyboard_ESCAPE() //ESC
{
	return keyboard_query(0x29);
}


