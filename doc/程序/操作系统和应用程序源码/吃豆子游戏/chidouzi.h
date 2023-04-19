void chidouzi_Display_interface_0(unsigned char y, unsigned char x, unsigned char data) //显示接口0,画点,yx为坐标,data像素数据
{
	_B = data;
	_A = x;
	_A1 = y;
	_A2 = 0x80;
	_A0 = _A;
	_NOP;
	_RAM = _B;
}

void chidouzi_Display_interface_1(unsigned char y, unsigned char x, unsigned char _y, unsigned char _x, unsigned char data) //显示接口1,画色块,yx为起始坐标,_y_x为点数,data像素数据
{
	VGA_SK1(y, x, _y, _x, data);
}

void qingping()	  //清屏  调用后就全屏刷黑色
{
	chidouzi_Display_interface_1(0, 0, 160, 128, 0);
}

void cachu() //擦除(像素帧)	(玩家和鬼还有生命显示共用的“擦除”9*9像素块) 用法:先给xx、yy变量赋上坐标 然后调用此函数即可显示颜色为se2变量的像素块在指定坐标
{
	chidouzi_Display_interface_1(yy, xx, 9, 9, k1[se2]);
}


void shanggai_L()  //上盖 (水平 玩家组成部份(省ROM))  (玩家像素帧的组成部份 非主要函数)
{

unsigned char x,y,data;

	data = k1[se];
	x = 2 + xx1;
	y = 0 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 1 + xx1;
	y = 1 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[7];
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[se];
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
}

void xiagai_L()	  //下盖 (水平 玩家组成部份(省ROM))	  (玩家像素帧的组成部份 非主要函数)
{

unsigned char x,y,data;

    x = 1 + xx1;
	y = 7 + yy1;
	data = k1[se];
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 2 + xx1;
	y = 8 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
}

void zhangzui_R()   //玩家向右张嘴(像素帧)	用法：先给xx1、yy1变量赋上坐标值 然后调用此函数即可显示玩家在指定坐标 玩家颜色为se变量的值
{

unsigned char x, y, data;

	shanggai_L();

	x = 0 + xx1;
	y = 2 + yy1;
	data = k1[se];
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx1;
	y = 3 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx1;
	y = 4 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx1;
	y = 5 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx1;
	y = 6 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	xiagai_L();
}


void bizui_R()	 //玩家向右闭嘴(像素帧)	  用法：先给xx1、yy1变量赋上坐标值 然后调用此函数即可显示玩家在指定坐标 玩家颜色为se变量的值
{

unsigned char x, y, data;

	shanggai_L();

	data = k1[se];
	x = 0 + xx1;
	y = 2 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx1;
	y = 3 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx1;
	y = 4 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[9];
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	data = k1[se];
	x = 0 + xx1;
	y = 5 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx1;
	y = 6 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	xiagai_L();
}


void zhangzui_L()  //玩家向左张嘴(像素帧)  用法：先给xx1、yy1变量赋上坐标值 然后调用此函数即可显示玩家在指定坐标 玩家颜色为se变量的值
{

unsigned char x, y, data;

	shanggai_L();

	data = k1[se];
	x = 2 + xx1;
	y = 2 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 4 + xx1;
	y = 3 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 5 + xx1;
	y = 4 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 4 + xx1;
	y = 5 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 2 + xx1;
	y = 6 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	xiagai_L();
}


void bizui_L() //玩家向左闭嘴(像素帧)  用法：先给xx1、yy1变量赋上坐标值 然后调用此函数即可显示玩家在指定坐标 玩家颜色为se变量的值
{

unsigned char x, y, data;

	shanggai_L();

	data = k1[se];
	x = 0 + xx1;
	y = 2 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx1;
	y = 3 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	data = k1[9];
	x = 0 + xx1;
	y = 4 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[se];
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx1;
	y = 5 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx1;
	y = 6 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	xiagai_L();
}


void zhangzui_O()  //玩家向上张嘴(像素帧)   用法：先给xx1、yy1变量赋上坐标值 然后调用此函数即可显示玩家在指定坐标 玩家颜色为se变量的值
{

unsigned char x, y, data;

	data = k1[se];
	x = 1 + xx1;
	y = 1 + yy1;
	chidouzi_Display_interface_0(y, x, data);

	x = 7 + xx1;
	y = 1 + yy1;
	chidouzi_Display_interface_0(y, x, data);

	x = 0 + xx1;
	y = 2 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 6 + xx1;
	y = 2 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx1;
	y = 3 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 6 + xx1;
	y = 3 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx1;
	y = 4 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	data = k1[7];
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[se];
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[9];
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[se];
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx1;
	y = 5 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx1;
	y = 6 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 1 + xx1;
	y = 7 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 2 + xx1;
	y = 8 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
}


void bizui_O()  //玩家向上闭嘴(像素帧)	  用法：先给xx1、yy1变量赋上坐标值 然后调用此函数即可显示玩家在指定坐标 玩家颜色为se变量的值
{

unsigned char x, y, data;

	data = k1[se];
	x = 0 + xx1;
	y = 5 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[9];
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[se];
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 1 + xx1;
	y = 1 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[9];
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[se];
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx1;
	y = 2 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[9];
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[se];
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx1;
	y = 3 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[9];
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[se];
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx1;
	y = 4 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	data = k1[7];
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[se];
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[9];
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[se];
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx1;
	y = 5 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx1;
	y = 6 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 1 + xx1;
	y = 7 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 2 + xx1;
	y = 8 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
}


void zhangzui_U()  //玩家向下张嘴(像素帧)	用法：先给xx1、yy1变量赋上坐标值 然后调用此函数即可显示玩家在指定坐标 玩家颜色为se变量的值
{

unsigned char x, y, data;

	data = k1[se];
	x = 2 + xx1;
	y = 0 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 1 + xx1;
	y = 1 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx1;
	y = 2 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx1;
	y = 3 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx1;
	y = 4 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[9];
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[se];
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[7];
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[se];
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx1;
	y = 5 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 6 + xx1;
	y = 5 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx1;
	y = 6 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 6 + xx1;
	y = 6 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 1 + xx1;
	y = 7 + yy1;
	chidouzi_Display_interface_0(y, x, data);

	x = 7 + xx1;
	y = 7 + yy1;
	chidouzi_Display_interface_0(y, x, data);
}


void bizui_U()  //玩家向下闭嘴(像素帧)	用法：先给xx1、yy1变量赋上坐标值 然后调用此函数即可显示玩家在指定坐标 玩家颜色为se变量的值
{

unsigned char x, y, data;

	data = k1[se];
	x = 2 + xx1;
	y = 0 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 1 + xx1;
	y = 1 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx1;
	y = 2 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx1;
	y = 3 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx1;
	y = 4 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[9];
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[se];
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[7];
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[se];
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx1;
	y = 5 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[9];
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[se];
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx1;
	y = 6 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[9];
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[se];
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 1 + xx1;
	y = 7 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[9];
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[se];
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 2 + xx1;
	y = 8 + yy1;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[9];
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[se];
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
}


void GHOSTgongyong() //鬼的身体共用部份 (上半身(省ROM))(非主要函数)
{

unsigned char x, y, data;

	data = k1[6];
	x = 2 + xx2;
	y = 0 + yy2;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 1 + xx2;
	y = 1 + yy2;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx2;
	y = 2 + yy2;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[7];
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[6];
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[7];
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[6];
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx2;
	y = 3 + yy2;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx2;
	y = 4 + yy2;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
}


void GHOST_L()		//鬼~~~  缩脚(像素帧)	用法：先给xx2、yy2变量赋上坐标值 然后调用此函数即可显示鬼在指定坐标
{
	GHOSTgongyong();
}


void GHOST_H()	   //鬼~~~ 伸脚(像素帧)	  用法：先给xx2、yy2变量赋上坐标值 然后调用此函数即可显示鬼在指定坐标
{

unsigned char x, y, data;

	GHOSTgongyong();

	data = k1[6];
	x = 0 + xx2;
	y = 5 + yy2;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx2;
	y = 6 + yy2;
	chidouzi_Display_interface_0(y, x, data);
	data = k1[9];
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[6];
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[9];
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[6];
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[9];
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[6];
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[9];
	chidouzi_Display_interface_0(y, ++x, data);
	data = k1[6];
	chidouzi_Display_interface_0(y, ++x, data);
}

void shuzixianshi()	//0~9数字显示 (字库解码)  用法:先给sx、sy变量赋上坐标值 再给zm变量赋上0~9字库的起始位置 然后调用此函数即可显示数字在指定的坐标 颜色参数已定
{

unsigned char x;
unsigned char f1, f2, yw;

	f1 = 0;

	while (f1 < 9)
	{
		x = sx;
		yw = k3[zm];
		f2 = 0;

		while (f2 < 5)
		{
			yw = yw << 1;

			if ((yw & 32) != 0)
			{
				chidouzi_Display_interface_0(f1 + sy, x++, k1[8]);
			}
			else
			{
				chidouzi_Display_interface_0(f1 + sy, x++, k1[7]);
			}

			++f2;
		}

		f1++;
		zm++;
	}
}

void shuzixianshijinweigengxin()  //数字显示进位更新  用法:zzzz1、zzzz2、zzzz3、zzzz4变量对应个位、十位、百位、千位 对字库来说是90进制 所以变量加1等于加9 此函数坐标已定 调用既可更新变量值到分数显示 
{
	if (zzzz1 == 90)
	{
		zzzz1 = 0;
		zzzz2 = zzzz2 + 9;
	}

	if (zzzz2 == 90)
	{
		zzzz2 = 0;
		zzzz3 = zzzz3 + 9;
	}

	if (zzzz3 == 90)
	{
		zzzz3 = 0;
		zzzz4 = zzzz4 + 9;
	}

	if (zzzz4 == 90)
	{
		zzzz4 = 0;
	}

	sx = 58; sy = 0; zm = zzzz1;
	shuzixianshi();        //第1位
	sx = 50; zm = zzzz2;
	shuzixianshi();        //第2位
	sx = 42; zm = zzzz3;
	shuzixianshi();        //第3位
	sx = 34; zm = zzzz4;
	shuzixianshi();        //第4位

}


void douzi()   //豆子(像素帧)  用法：给xx3、yy3变量赋上坐标  然后调用此函数即可显示豆子在指定坐标 豆子颜色为se1变量的值
{

unsigned char x, y, data;

	data = k1[se1];
	x = 1 + xx3;
	y = 0 + yy3;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx3;
	y = 1 + yy3;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx3;
	y = 2 + yy3;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 0 + xx3;
	y = 3 + yy3;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);

	x = 1 + xx3;
	y = 4 + yy3;
	chidouzi_Display_interface_0(y, x, data);
	chidouzi_Display_interface_0(y, ++x, data);
	chidouzi_Display_interface_0(y, ++x, data);
}

void douzifenbu()	//豆子分布  此函数用于刷新豆子所在坐标的显示
{
	se1 = 2;

	if (z1 == 0)
	{
		xx3 = 7; yy3 = 13;	 //外框左上角坐标
		douzi();
	}

	if (z2 == 0)
	{
		xx3 = 117; yy3 = 13;  //外框右上角坐标
		douzi();
	}

	if (z3 == 0)
	{
		xx3 = 7; yy3 = 143;   //外框左下角坐标
		douzi();
	}

	if (z4 == 0)
	{
		xx3 = 117; yy3 = 143;	 //外框右下角坐标
		douzi();
	}

	if (z5 == 0)
	{
		xx3 = 27; yy3 = 13;   //中框左上角上道坐标
		douzi();
	}

	if (z6 == 0)
	{
		xx3 = 7; yy3 = 113;	//中框左下角下道坐标
		douzi();
	}

	if (z7 == 0)
	{
		xx3 = 117; yy3 = 43;	 //中框右上角上道坐标
		douzi();
	}

	if (z8 == 0)
	{
		xx3 = 97; yy3 = 143;	 //中框右下角下道坐标
		douzi();
	}

	if (z9 == 0)
	{
		xx3 = 27; yy3 = 43;	 //中框左上角坐标
		douzi();
	}

	if (z10 == 0)
	{
		xx3 = 27; yy3 = 113;	 //中框左下角坐标
		douzi();
	}

	if (z11 == 0)
	{
		xx3 = 97; yy3 = 43;	 //中框右上角坐标
		douzi();
	}

	if (z12 == 0)
	{
		xx3 = 97; yy3 = 113;	  //中框右下角坐标
		douzi();
	}

	if (z13 == 0)
	{
		xx3 = 47; yy3 = 43;	//内框左上角上道坐标
		douzi();
	}

	if (z14 == 0)
	{
		xx3 = 27; yy3 = 93;	//内框左下角下道坐标
		douzi();
	}

	if (z15 == 0)
	{
		xx3 = 97; yy3 = 63;   //内框右上角上道坐标
		douzi();
	}

	if (z16 == 0)
	{
		xx3 = 77; yy3 = 113;  //内框右下角下道坐标
		douzi();
	}

	if (z17 == 0)
	{
		xx3 = 47; yy3 = 63;   //内框左上角坐标
		douzi();
	}

	if (z18 == 0)
	{
		xx3 = 47; yy3 = 93;   //内框左下角坐标
		douzi();
	}

	if (z20 == 0)
	{
		xx3 = 77; yy3 = 93;   //内框右下角坐标
		douzi();
	}

	if (z19 == 0)
	{
		xx3 = 77; yy3 = 63;   //内框右上角坐标
		sex++;
		if (sex == 10)
		{
			sex = 0;
		}
		se1 = sex;
		douzi();
	}



}

void kuaicachu()  //块擦除(像素帧) 11*11像素 (画地图用 颜色为天蓝色) 用法:给kx、ky变量赋上坐标值然后调用此函数就OK~~
{
	chidouzi_Display_interface_1(ky, kx, 11, 11, k1[9]);
}

void ditu()	 //地图  调用就画出地图
{
	kx = 4; ky = 0;

	while (ky <= 130)	//外框左道
	{

		ky = ky + 10;
		kuaicachu();
	}


	while (kx <= 104)  //外框下道
	{
		kx = kx + 10;
		kuaicachu();
	}

	while (ky >= 20)	  //外框右道
	{
		ky = ky - 10;
		kuaicachu();
	}

	while (kx >= 24)	  //外框上道
	{
		kx = kx - 10;
		kuaicachu();
	}


	kx = 24; ky = 10;	//中框左道

	while (ky <= 90)
	{
		ky = ky + 10;
		kuaicachu();
	}

	kx = 4;  ky = 110;	 //中框下道

	while (kx <= 74)
	{
		kx = kx + 10;
		kuaicachu();
	}

	kx = 94;  ky = 140;	   //中框右道

	while (ky >= 60)
	{
		ky = ky - 10;
		kuaicachu();
	}

	kx = 114;  ky = 40;	   //中框上道

	while (kx >= 44)
	{
		kx = kx - 10;
		kuaicachu();
	}

	kx = 44;  ky = 40;	 //内框左道

	while (ky <= 70)
	{
		ky = ky + 10;
		kuaicachu();
	}

	kx = 24;  ky = 90;	 //内框下道

	while (kx <= 54)
	{
		kx = kx + 10;
		kuaicachu();
	}

	kx = 74;  ky = 110;	 //内框右道

	while (ky >= 80)
	{
		ky = ky - 10;
		kuaicachu();
	}

	kx = 94;  ky = 60;	 //内框上道

	while (kx >= 64)
	{
		kx = kx - 10;
		kuaicachu();
	}

	kx = 4;  ky = 0;  //外框左上传送门

	kuaicachu();

	kx = 0;  ky = 140;  //外框左下传送门

	kuaicachu();

	kx = 117;  ky = 10;  //外框右上传送门

	kuaicachu();

	kx = 114;  ky = 149;  //外框右下传送门

	kuaicachu();

}




void KEY_Okongzhi()  //方向按键上控制
{
	if (KEY_O == 1)  //判断上键按下
	{
		jj1 = 4;   //打开向上减量
		k = 2;	 //玩家向上张/闭嘴动作打开
	}
}

void KEY_Ukongzhi()  //方向按键下控制
{
	if (KEY_U == 1)  //判断下键按下
	{
		jj1 = 2;   //打开向下增量
		k = 3;	 //玩家向下张/闭嘴动作打开
	}
}

void KEY_Lkongzhi()  //方向按键左控制
{
	if (KEY_L == 1)  //判断左键按下
	{
		jj1 = 3;   //打开向左减量
		k = 1;	 //玩家向左张/闭嘴动作打开
	}
}

void KEY_Rkongzhi()  //方向按键右控制
{
	if (KEY_R == 1)  //判断右键按下
	{
		jj1 = 1;   //打开向右增量
		k = 0;	 //玩家向右张/闭嘴动作打开
	}
}

void wanjiazuobiaopanduankongzhi()  //玩家地图转角坐标判断控制(根据地图)
{

	if (xx1 == 5 & yy1 == 1)	  //左上传送门出口坐标(玩家出生地)
	{
		KEY_Okongzhi();

		KEY_Ukongzhi();
	}

	if (xx1 == 5 & yy1 == 11)		 //外框左上角坐标
	{
		if (jj1 == 3)	   //若玩家向左减量为开 则关闭玩家X/Y增减量
		{
			jj1 = 0;
		}

		if (z1 == 0)
		{
			zzzz1 = zzzz1 + 9;
			shuzixianshijinweigengxin();
		}
		z1 = 1;

		KEY_Okongzhi();

		KEY_Ukongzhi();

		KEY_Rkongzhi();
	}

	if (xx1 == 115 & yy1 == 11)   //外框右上角坐标
	{
		if (jj1 == 4)	   //若玩家向上减量为开 则关闭玩家X/Y增减量
		{
			jj1 = 0;
		}

		if (z2 == 0)
		{
			zzzz1 = zzzz1 + 9;
			shuzixianshijinweigengxin();
		}

		z2 = 1;

		KEY_Lkongzhi();

		KEY_Rkongzhi();

		KEY_Ukongzhi();
	}

	if (xx1 == 5 & yy1 == 141)	//外框左下角坐标
	{
		if (jj1 == 2)	   //若玩家向下增量为开 则关闭玩家X/Y增减量
		{
			jj1 = 0;
		}

		if (z3 == 0)
		{
			zzzz1 = zzzz1 + 9;
			shuzixianshijinweigengxin();
		}

		z3 = 1;

		KEY_Lkongzhi();

		KEY_Rkongzhi();

		KEY_Okongzhi();
	}

	if (xx1 == 115 & yy1 == 141)	  //外框右下角坐标
	{
		if (jj1 == 1)	 //若玩家向右增量为开 则关闭玩家X/Y增减量
		{
			jj1 = 0;
		}

		if (z4 == 0)
		{
			zzzz1 = zzzz1 + 9;
			shuzixianshijinweigengxin();
		}

		z4 = 1;

		KEY_Okongzhi();

		KEY_Ukongzhi();

		KEY_Lkongzhi();
	}

	if (xx1 == 25 & yy1 == 11)	//中框左上角上道坐标
	{
		if (jj1 == 4)
		{
			jj1 = 0;
		}

		if (z5 == 0)
		{
			zzzz1 = zzzz1 + 9;
			shuzixianshijinweigengxin();
		}

		z5 = 1;

		KEY_Lkongzhi();

		KEY_Rkongzhi();

		KEY_Ukongzhi();
	}

	if (xx1 == 5 & yy1 == 111)	//中框左下角下道坐标
	{
		if (jj1 == 3)
		{
			jj1 = 0;
		}

		if (z6 == 0)
		{
			zzzz1 = zzzz1 + 9;
			shuzixianshijinweigengxin();
		}

		z6 = 1;

		KEY_Okongzhi();

		KEY_Ukongzhi();

		KEY_Rkongzhi();
	}

	if (xx1 == 115 & yy1 == 41)	 //中框右上角上道坐标
	{
		if (jj1 == 1)
		{
			jj1 = 0;
		}

		if (z7 == 0)
		{
			zzzz1 = zzzz1 + 9;
			shuzixianshijinweigengxin();
		}

		z7 = 1;

		KEY_Okongzhi();

		KEY_Ukongzhi();

		KEY_Lkongzhi();
	}

	if (xx1 == 95 & yy1 == 141)	//中框右下角下道坐标
	{
		if (jj1 == 2)
		{
			jj1 = 0;
		}

		if (z8 == 0)
		{
			zzzz1 = zzzz1 + 9;
			shuzixianshijinweigengxin();
		}

		z8 = 1;

		KEY_Lkongzhi();

		KEY_Rkongzhi();

		KEY_Okongzhi();
	}

	if (xx1 == 25 & yy1 == 41)  //中框左上角坐标
	{
		if (jj1 == 3)
		{
			jj1 = 0;
		}

		if (z9 == 0)
		{
			zzzz1 = zzzz1 + 9;
			shuzixianshijinweigengxin();
		}

		z9 = 1;

		KEY_Okongzhi();

		KEY_Ukongzhi();

		KEY_Rkongzhi();
	}

	if (xx1 == 25 & yy1 == 111)	//中框左下角坐标
	{
		if (jj1 == 2)
		{
			jj1 = 0;
		}

		if (z10 == 0)
		{
			zzzz1 = zzzz1 + 9;
			shuzixianshijinweigengxin();
		}

		z10 = 1;

		KEY_Lkongzhi();

		KEY_Rkongzhi();

		KEY_Okongzhi();
	}

	if (xx1 == 95 & yy1 == 41)	//中框右上角坐标
	{
		if (jj1 == 4)
		{
			jj1 = 0;
		}

		if (z11 == 0)
		{
			zzzz1 = zzzz1 + 9;
			shuzixianshijinweigengxin();
		}

		z11 = 1;

		KEY_Lkongzhi();

		KEY_Rkongzhi();

		KEY_Ukongzhi();
	}

	if (xx1 == 95 & yy1 == 111)	 //中框右下角坐标
	{
		if (jj1 == 1)
		{
			jj1 = 0;
		}

		if (z12 == 0)
		{
			zzzz1 = zzzz1 + 9;
			shuzixianshijinweigengxin();
		}

		z12 = 1;

		KEY_Okongzhi();

		KEY_Ukongzhi();

		KEY_Lkongzhi();
	}

	if (xx1 == 45 & yy1 == 41)  //内框左上角上道坐标
	{
		if (jj1 == 4)
		{
			jj1 = 0;
		}

		if (z13 == 0)
		{
			zzzz1 = zzzz1 + 9;
			shuzixianshijinweigengxin();
		}

		z13 = 1;

		KEY_Lkongzhi();

		KEY_Rkongzhi();

		KEY_Ukongzhi();
	}

	if (xx1 == 25 & yy1 == 91)  //内框左下角下道坐标
	{
		if (jj1 == 3)
		{
			jj1 = 0;
		}

		if (z14 == 0)
		{
			zzzz1 = zzzz1 + 9;
			shuzixianshijinweigengxin();
		}

		z14 = 1;

		KEY_Okongzhi();

		KEY_Ukongzhi();

		KEY_Rkongzhi();
	}

	if (xx1 == 95 & yy1 == 61)  //内框右上角上道坐标
	{
		if (jj1 == 1)
		{
			jj1 = 0;
		}

		if (z15 == 0)
		{
			zzzz1 = zzzz1 + 9;
			shuzixianshijinweigengxin();
		}

		z15 = 1;

		KEY_Okongzhi();

		KEY_Ukongzhi();

		KEY_Lkongzhi();
	}

	if (xx1 == 75 & yy1 == 111)	//内框右下角下道坐标
	{
		if (jj1 == 2)
		{
			jj1 = 0;
		}

		if (z16 == 0)
		{
			zzzz1 = zzzz1 + 9;
			shuzixianshijinweigengxin();
		}

		z16 = 1;

		KEY_Lkongzhi();

		KEY_Rkongzhi();

		KEY_Okongzhi();
	}

	if (xx1 == 45 & yy1 == 61)	//内框左上角坐标
	{
		if (jj1 == 3)
		{
			jj1 = 0;
		}

		if (z17 == 0)
		{
			zzzz1 = zzzz1 + 9;
			shuzixianshijinweigengxin();
		}

		z17 = 1;

		KEY_Okongzhi();

		KEY_Ukongzhi();

		KEY_Rkongzhi();
	}

	if (xx1 == 45 & yy1 == 91)  //内框左下角坐标
	{
		if (jj1 == 2)
		{
			jj1 = 0;
		}

		if (z18 == 0)
		{
			zzzz1 = zzzz1 + 9;
			shuzixianshijinweigengxin();
		}

		z18 = 1;

		KEY_Lkongzhi();

		KEY_Rkongzhi();

		KEY_Okongzhi();
	}

	if (xx1 == 75 & yy1 == 61)  //内框右上角坐标
	{
		if (jj1 == 4)
		{
			jj1 = 0;
		}

		if (z19 == 0)
		{
			zzzz1 = zzzz1 + 9;
			shuzixianshijinweigengxin();
		}

		z19 = 1;

		KEY_Lkongzhi();

		KEY_Rkongzhi();

		KEY_Ukongzhi();
	}

	if (xx1 == 75 & yy1 == 91) //内框右下角坐标
	{
		if (jj1 == 1)
		{
			jj1 = 0;
		}

		if (z20 == 0)
		{
			zzzz1 = zzzz1 + 9;
			shuzixianshijinweigengxin();
		}

		z20 = 1;

		KEY_Okongzhi();

		KEY_Ukongzhi();

		KEY_Lkongzhi();
	}


}

void GHOSTzidongzhuizong() //鬼自动追踪玩家    (核心技术~~~ 根据地图)
{
	if (xxxx == 5 & yyyy == 11)		 //外框左上角坐标
	{
		if (jjj == 3)
		{
			jjj = 2;
		}
		else
		{
			jjj = 1;
		}
	}

	if (xxxx == 115 & yyyy == 11)   //外框右上角坐标
	{
		if (jjj == 1)
		{
			jjj = 2;
		}
		else
		{
			jjj = 3;
		}
	}

	if (xxxx == 5 & yyyy == 141)	//外框左下角坐标
	{
		if (jjj == 3)
		{
			jjj = 4;
		}
		else
		{
			jjj = 1;
		}
	}

	if (xxxx == 115 & yyyy == 141)	 //外框右下角坐标
	{
		if (jjj == 1)
		{
			jjj = 4;
		}
		else
		{
			jjj = 3;
		}
	}

	if (xxxx == 25 & yyyy == 11)	  //中框左上角上道坐标
	{
		if (jjj == 1 || jjj == 3)
		{
			if (xx1 >= 5 & yy1 >= 41 || xx1 == 25 & yy1 > 11)
			{
				jjj = 2;
			}
		}
		else
		{
			if (xx1 <= 25)
			{
				jjj = 3;
			}
			else
			{
				jjj = 1;
			}
		}
	}

	if (xxxx == 5 & yyyy == 111)	//中框左下角下道坐标
	{
		if (jjj == 2 || jjj == 4)
		{
			if (xx1 >= 25 & yy1 <= 141 || xx1 > 5 & yy1 == 111)
			{
				jjj = 1;
			}
		}
		else
		{
			if (yy1 >= 111)
			{
				jjj = 2;
			}
			else
			{
				jjj = 4;
			}
		}
	}

	if (xxxx == 115 & yyyy == 41)	 //中框右上角上道坐标
	{
		if (jjj == 2 || jjj == 4)
		{
			if (xx1 <= 95 & yy1 >= 11 || xx1 < 115 & yy1 == 41)
			{
				jjj = 3;
			}
		}
		else
		{
			if (yy1 <= 41)
			{
				jjj = 4;
			}
			else
			{
				jjj = 2;
			}
		}
	}

	if (xxxx == 95 & yyyy == 141)	//中框右下角下道坐标
	{
		if (jjj == 1 || jjj == 3)
		{
			if (xx1 <= 115 & yy1 <= 111 || xx1 == 95 & yy1 < 141)
			{
				jjj = 4;
			}
		}
		else
		{
			if (xx1 >= 95)
			{
				jjj = 1;
			}
			else
			{
				jjj = 3;
			}
		}
	}

	if (xxxx == 25 & yyyy == 41)  //中框左上角坐标
	{
		if (jjj == 2 || jjj == 4)
		{
			if (xx1 >= 45 & yy1 > 11 || xx1 > 25 & yy1 == 41)
			{
				jjj = 1;
			}
		}
		else
		{
			if (yy1 <= 41)
			{
				jjj = 4;
			}
			else
			{
				jjj = 2;
			}
		}
	}

	if (xxxx == 25 & yyyy == 111)	//中框左下角坐标
	{
		if (jjj == 1 || jjj == 3)
		{
			if (xx1 > 5 & yy1 <= 91 || xx1 == 25 & yy1 < 111)
			{
				jjj = 4;
			}
		}
		else
		{
			if (xx1 <= 25)
			{
				jjj = 3;
			}
			else
			{
				jjj = 1;
			}
		}
	}

	if (xxxx == 95 & yyyy == 41)	//中框右上角坐标
	{
		if (jjj == 1 || jjj == 3)
		{
			if (xx1 < 115 & yy1 >= 61 || xx1 == 95 & yy1 > 41)
			{
				jjj = 2;
			}
		}
		else
		{
			if (xx1 >= 95)
			{
				jjj = 1;
			}
			else
			{
				jjj = 3;
			}
		}
	}

	if (xxxx == 95 & yyyy == 111)	 //中框右下角坐标
	{
		if (jjj == 2 || jjj == 4)
		{
			if (xx1 <= 75 & yy1 < 141 || xx1 < 95 & yy1 == 111)
			{
				jjj = 3;
			}
		}
		else
		{
			if (yy1 >= 111)
			{
				jjj = 2;
			}
			else
			{
				jjj = 4;
			}
		}
	}

	if (xxxx == 45 & yyyy == 41)  //内框左上角上道坐标
	{
		if (jjj == 1 || jjj == 3)
		{
			if (xx1 >= 25 & yy1 >= 61 || xx1 == 45 & yy1 > 41)
			{
				jjj = 2;
			}
		}
		else
		{
			if (xx1 <= 45)
			{
				jjj = 3;
			}
			else
			{
				jjj = 1;
			}
		}
	}

	if (xxxx == 25 & yyyy == 91)  //内框左下角下道坐标
	{
		if (jjj == 2 || jjj == 4)
		{
			if (xx1 >= 45 & yy1 <= 111 || xx1 > 25 & yy1 == 91)
			{
				jjj = 1;
			}
		}
		else
		{
			if (yy1 >= 91)
			{
				jjj = 2;
			}
			else
			{
				jjj = 4;
			}
		}
	}

	if (xxxx == 95 & yyyy == 61)  //内框右上角上道坐标
	{
		if (jjj == 2 || jjj == 4)
		{
			if (xx1 <= 75 & yy1 >= 41 || xx1 < 95 & yy1 == 61)
			{
				jjj = 3;
			}
		}
		else
		{
			if (yy1 <= 61)
			{
				jjj = 4;
			}
			else
			{
				jjj = 2;
			}
		}
	}

	if (xxxx == 75 & yyyy == 111)	//内框右下角下道坐标
	{
		if (jjj == 1 || jjj == 3)
		{
			if (xx1 <= 95 & yy1 <= 91 || xx1 == 75 & yy1 < 111)
			{
				jjj = 4;
			}
		}
		else
		{
			if (xx1 >= 75)
			{
				jjj = 1;
			}
			else
			{
				jjj = 3;
			}
		}
	}

	if (xxxx == 45 & yyyy == 61)	//内框左上角坐标
	{
		if (jjj == 2 || jjj == 4)
		{
			if (xx1 >= 75 & yy1 > 41 || xx1 > 45 & yy1 == 61)
			{
				jjj = 1;
			}
		}
		else
		{
			if (yy1 <= 61)
			{
				jjj = 4;
			}
			else
			{
				jjj = 2;
			}
		}
	}

	if (xxxx == 45 & yyyy == 91)  //内框左下角坐标
	{
		if (jjj == 1 || jjj == 3)
		{
			if (xx1 > 25 & yy1 <= 61 || xx1 == 45 & yy1 < 91)
			{
				jjj = 4;
			}
		}
		else
		{
			if (xx1 <= 45)
			{
				jjj = 3;
			}
			else
			{
				jjj = 1;
			}
		}
	}

	if (xxxx == 75 & yyyy == 61)  //内框右上角坐标
	{
		if (jjj == 1 || jjj == 3)
		{
			if (xx1 < 95 & yy1 >= 91 || xx1 == 75 & yy1 > 61)
			{
				jjj = 2;
			}
		}
		else
		{
			if (xx1 >= 75)
			{
				jjj = 1;
			}
			else
			{
				jjj = 3;
			}
		}
	}

	if (xxxx == 75 & yyyy == 91) //内框右下角坐标
	{
		if (jjj == 2 || jjj == 4)
		{
			if (xx1 <= 45 & yy1 < 111 || xx1 < 75 & yy1 == 91)
			{
				jjj = 3;
			}
		}
		else
		{
			if (yy1 >= 91)
			{
				jjj = 2;
			}
			else
			{
				jjj = 4;
			}
		}
	}
}


void chuansongmen()	 //传送门 （玩家坐标修改）
{
	if (xx1 == 5 & yy1 == 0)	  //外框左上传送门入口坐标
	{
		xx1 = 115; yy1 = 150;	  //出口坐标
	}

	if (xx1 == 115 & yy1 == 151)	  //外框右下传送门入口坐标
	{
		xx1 = 5; yy1 = 1;		//出口坐标
	}

	if (xx1 == 119 & yy1 == 11)	  //外框右上传送门入口坐标
	{
		xx1 = 1; yy1 = 141;	//出口坐标
	}

	if (xx1 == 0 & yy1 == 141)	  //外框左下传送门入口坐标
	{
		xx1 = 118; yy1 = 11;	 //出口坐标
	}
}

void shualvse()	  //刷绿色障碍块
{
	chidouzi_Display_interface_1(20, 14, 120, 100, k1[3]);
}



void shengmingxianshi()  //生命显示和更新  sm变量赋上显示的生命数再调用此函数就OK~~~
{
	///////////擦除生命显示/////////
	smx = 0;

	yy = 151; xx = 0; se2 = 7;

	while (smx < 11)
	{
		cachu();
		xx = xx + 10;
		smx++;
	}

	se2 = 9;

	///////////写生命数///////////
	smx = 0;

	xx1jc = xx1;	//保存
	yy1jc = yy1;

	yy1 = 151; xx1 = 0; se = 2;

	while (smx < sm)
	{
		zhangzui_R();
		xx1 = xx1 + 10;
		smx++;
	}

	xx1 = xx1jc;   //取出
	yy1 = yy1jc;
}




void pengzhuangpanduan()   //玩家和鬼碰撞判断(共用)
{

	if (xx1 == xxxxx & yy1 == yyyyy || xx1 == xxxxx + 1 & yy1 == yyyyy || xx1 == xxxxx - 1 & yy1 == yyyyy || xx1 == xxxxx & yy1 == yyyyy + 1 || xx1 == xxxxx & yy1 == yyyyy - 1)
	{
		if (wd == 0 & z19 == 1)   //判断玩家是否无敌
		{
			cc = 0;	 //无敌就关闭鬼显示
			if (sm < 7)
			{
				sm = sm + 1; //生命显示加1
			}
			shengmingxianshi();	//更新生命显示

			zzzz2 = zzzz2 + 9;	//分数的“十位”加9
			shuzixianshijinweigengxin();  //“十位”显示加1到屏幕
		}
		else	//没有无敌
		{
			if (sm > 0)
			{
				sm = sm - 1; //生命显示减1
			}
			shengmingxianshi(); //更新生命显示

			if (sm == 0)	//生命数为0(挂了~~)就清黑屏之后中央显示分数      
			{
				qingping();

				sx = 70; sy = 76; zm = zzzz1;
				shuzixianshi();        //第1位
				sx = 62; zm = zzzz2;
				shuzixianshi();        //第2位
				sx = 54; zm = zzzz3;
				shuzixianshi();        //第3位
				sx = 46; zm = zzzz4;
				shuzixianshi();        //第4位

				xh = 0;	//main()里面的第2死循环开路
			}
		}
	}

}

void GHOST()	 //鬼。。。(N个鬼共用)
{

	///////////////////////////////鬼控制部份///////////////////////////

	GHOSTzidongzhuizong();   //鬼地图转角自动追踪控制  影响下面的X、Y坐标增减量控制台

////////////////////////////////鬼擦除帧/////////////////////////////

	xx = xxxx; yy = yyyy;

	cachu();

	////////////////////////////鬼X、Y坐标增减量控制台///////////////////////////

	if (jjj == 0)
	{

	}

	if (jjj == 1)
	{
		xxxx++;
	}

	if (jjj == 2)
	{
		yyyy++;
	}

	if (jjj == 3)
	{
		xxxx--;
	}

	if (jjj == 4)
	{
		yyyy--;
	}

	/////////////////////////鬼的控制帧显示部份////////////////////////////

	xx2 = xxxx; yy2 = yyyy;

	if (kkk == 0)
	{
		GHOST_H();
	}


	if (kkk == 1)
	{
		GHOST_L();
	}

}

void tongguanchushihua()  //通关初始化
{

unsigned char i;

	qingping();
	shualvse();
	ditu();
	shuzixianshijinweigengxin();
	shengmingxianshi();

	z1 = 0; z2 = 0; z3 = 0; z4 = 0; z5 = 0;
	z6 = 0; z7 = 0; z8 = 0; z9 = 0; z10 = 0;
	z11 = 0; z12 = 0; z13 = 0; z14 = 0; z15 = 0;
	z16 = 0; z17 = 0; z18 = 0; z19 = 0; z20 = 0;

	xx1 = 5; yy1 = 1;
	se = 2;
	jj1 = 0;
	k = 0;
	wd = 0;
	y = 0;

	//for (i = 0; i < ghost_num; ++i) ghost_x[i] = 0; //初始化鬼的参数
	//for (i = 0; i < ghost_num; ++i) ghost_y[i] = 0; //初始化鬼的参数
	for (i = 0; i < ghost_num; ++i) ghost_display[i] = 0; //初始化鬼的参数
	for (i = 0; i < ghost_num; ++i) ghost_delayed[i] = 0; //初始化鬼的参数

/*
	c1 = 0;
	c2 = 0;
	c3 = 0;
	c4 = 0;

	s1 = 0;
	s2 = 0;
	s3 = 0;
	s4 = 0;
*/
}

void chidouzi_init() //吃豆子初始化
{
	z = 2; //游戏速度
	sm = 3; //设置玩家生命值
	ghost_num = 1; //鬼的初始数量
	zzzz1 = 0;
	zzzz2 = 0;
	zzzz3 = 0;
	zzzz4 = 0;
	tongguanchushihua();
}

void chidouzi_run() //吃豆子_运行
{

unsigned char i;
unsigned int js1;

		if (chidouzi_KEY_D_bz == 0 && KEY_D == 0)
		{
			chidouzi_KEY_D_bz = 1;
		}
		else if (chidouzi_KEY_D_bz == 1 && KEY_D == 1)
		{
			chidouzi_KEY_D_bz = 2;
		}
		else if (chidouzi_KEY_D_bz == 2 && KEY_D == 0)
		{
			chidouzi_KEY_D_bz = 0;

			if (xh == 0)
			{
				chidouzi_init(); //吃豆子初始化
				xh = 1; //游戏开始运行
			}
		}

		if (xh != 0)
		{


			//for (x = 0; x < z; x++);	 //游戏速度控制



			douzifenbu();	 //刷新豆子

  ///////////////////////////////////玩家控制部份(包含无敌控制 & 擦除帧 & 传送门 & X、Y坐标增减量控制台 & 控制帧显示)/////////////////

			wanjiazuobiaopanduankongzhi();  //玩家地图转角按键控制  影响下面的X、Y坐标增减量控制台

  ////////////////////////////////玩家无敌控制/////////////////////////////

			if (wd == 0)
			{
				if (z19 == 1)
				{
					se++;
					if (se == 10)	 //玩家颜色不停的更换  ~金身效果
					{
						se = 0;
					}
					y++;
					if (y == 700)		//无敌时间延时时间
					{
						y = 0;
						wd = 1;
						se = 2;
					}
				}
			}

			///////////////////////////////玩家擦除帧//////////////////////

			xx = xx1; yy = yy1;

			cachu();

			///////////////////////传送门////////////////////////////////

			chuansongmen();

			////////////////////////////////玩家X、Y坐标增减量控制台//////////////////////	
			if (jj1 == 0)
			{

			}

			if (jj1 == 1)
			{
				xx1++;
				if (KEY_L == 1)
				{
					jj1 = 3;
					k = 1;
				}
			}

			if (jj1 == 2)
			{
				yy1++;
				if (KEY_O == 1)
				{
					jj1 = 4;
					k = 2;
				}
			}

			if (jj1 == 3)
			{
				xx1--;
				if (KEY_R == 1)
				{
					jj1 = 1;
					k = 0;
				}
			}

			if (jj1 == 4)
			{
				yy1--;
				if (KEY_U == 1)
				{
					jj1 = 2;
					k = 3;
				}
			}

			////////////////////////////////玩家控制帧显示部分///////////////////////////

			if (kkk == 0)
			{
				if (k == 0)
				{
					zhangzui_R();
				}
				if (k == 1)
				{
					zhangzui_L();
				}
				if (k == 2)
				{
					zhangzui_O();
				}
				if (k == 3)
				{
					zhangzui_U();
				}
			}

			if (kkk == 1)
			{
				if (k == 0)
				{
					bizui_R();
				}
				if (k == 1)
				{
					bizui_L();
				}
				if (k == 2)
				{
					bizui_O();
				}
				if (k == 3)
				{
					bizui_U();
				}
			}


			///////////////////////鬼控制处理/////////////////////////////

			for (i = 0; i < ghost_num; ++i)
			{
				if (ghost_display[i] == 1)
				{
					xxxx = ghost_x[i];
					yyyy = ghost_y[i];
					jjj = ghost_xy_add_sub[i];
					GHOST();
					ghost_x[i] = xxxx;
					ghost_y[i] = yyyy;
					ghost_xy_add_sub[i] = jjj;
				}
			}

			/*

			///////////////////////鬼1控制处理/////////////////////////////

			if (c1 == 1)
			{
				xxxx = xxx1; yyyy = yyy1; jjj = jj2; //真实坐标和控制送到共用坐标和控制
				GHOST();
				xxx1 = xxxx; yyy1 = yyyy; jj2 = jjj; //共用坐标和控制送回真实坐标和控制
			}

			///////////////////////鬼2控制处理////////////////////////////

			if (c2 == 1)
			{
				xxxx = xxx2; yyyy = yyy2; jjj = jj3;
				GHOST();
				xxx2 = xxxx; yyy2 = yyyy; jj3 = jjj;
			}

			////////////////////////鬼3控制处理///////////////////////////

			if (c3 == 1)
			{
				xxxx = xxx3; yyyy = yyy3; jjj = jj4;
				GHOST();
				xxx3 = xxxx; yyy3 = yyyy; jj4 = jjj;
			}

			/////////////////////////鬼4控制处理//////////////////////////

			if (c4 == 1)
			{
				xxxx = xxx4; yyyy = yyy4; jjj = jj5;
				GHOST();
				xxx4 = xxxx; yyy4 = yyyy; jj5 = jjj;
			}
			*/


			for (i = 0; i < ghost_num; ++i)
			{
				xxxxx = ghost_x[i];
				yyyyy = ghost_y[i];
				cc = ghost_display[i];
				pengzhuangpanduan();
				ghost_display[i] = cc;
				if (xh == 0) return;
			}

			/*

			//////////////////////碰撞判断鬼1////////////////////////////

			xxxxx = xxx1; yyyyy = yyy1; cc = c1;	  //把坐标送给碰撞判断共用坐标变量 鬼开启关闭变量也送过去
			pengzhuangpanduan();
			c1 = cc;			   //处理的结果送回来

//////////////////////碰撞判断鬼2////////////////////////////

			xxxxx = xxx2; yyyyy = yyy2; cc = c2;
			pengzhuangpanduan();
			c2 = cc;

			//////////////////////碰撞判断鬼3////////////////////////////

			xxxxx = xxx3; yyyyy = yyy3; cc = c3;
			pengzhuangpanduan();
			c3 = cc;

			//////////////////////碰撞判断鬼4////////////////////////////

			xxxxx = xxx4; yyyyy = yyy4; cc = c4;
			pengzhuangpanduan();
			c4 = cc;

			if (xh == 0) return;

			*/

			js1 = 160;

			for (i = 0; i < ghost_num; ++i)
			{
				if (ghost_display[i] == 0)
				{
					ghost_x[i] = 0;
					ghost_y[i] = 0;

					if (++ghost_delayed[i] == js1)
					{
						ghost_x[i] = 75;
						ghost_y[i] = 61;
						ghost_delayed[i] = 0;
						ghost_display[i] = 1;
					}
				}

				js1 += 30;
			}

			/*
			//////////////////////鬼1延时出击/////////////////////////////			   

			if (c1 == 0)
			{
				xxx1 = 0; yyy1 = 0;	  //鬼坐标置空
				s1++;
				if (s1 == 160)     //延时值
				{
					xxx1 = 75; yyy1 = 61;	  //鬼出生地
					s1 = 0;
					c1 = 1;
				}
			}

			//////////////////////鬼2延时出击/////////////////////////////

			if (c2 == 0)
			{
				xxx2 = 0; yyy2 = 0;
				s2++;
				if (s2 == 190)
				{
					xxx2 = 75; yyy2 = 61;
					s2 = 0;
					c2 = 1;
				}
			}

			//////////////////////鬼3延时出击/////////////////////////////

			if (c3 == 0)
			{
				xxx3 = 0; yyy3 = 0;
				s3++;
				if (s3 == 220)
				{
					xxx3 = 75; yyy3 = 61;
					s3 = 0;
					c3 = 1;
				}
			}

			//////////////////////鬼4延时出击/////////////////////////////

			if (c4 == 0)
			{
				xxx4 = 0; yyy4 = 0;
				s4++;
				if (s4 == 250)
				{
					xxx4 = 75; yyy4 = 61;
					s4 = 0;
					c4 = 1;
				}
			}
			*/



			////////////////玩家和鬼帧切换频率和占空比发生部份(张嘴/伸脚占空比0.76  闭嘴/缩脚占空比0.24)///////

			j++;

			if (j == 16)
			{
				kkk = 1;
			}

			if (j == 21)
			{
				kkk = 0;
				j = 0;
			}

			//////////////////////////////////判断吃完豆子和通关处理///////////////////////////		  

			if (z1 + z2 + z3 + z4 + z5 + z6 + z7 + z8 + z9 + z10 + z11 + z12 + z13 + z14 + z15 + z16 + z17 + z18 + z19 + z20 == 20) //判断吃完豆子
			{

				if (ghost_num == 20)	//全关通完 清黑屏之后中央显示分数
				{
					qingping();

					sx = 70; sy = 76; zm = zzzz1;
					shuzixianshi();        //第1位
					sx = 62; zm = zzzz2;
					shuzixianshi();        //第2位
					sx = 54; zm = zzzz3;
					shuzixianshi();        //第3位
					sx = 46; zm = zzzz4;
					shuzixianshi();        //第4位

					xh = 0;
					return;
				}

				//z = z - 2000;	 //减2000延时量  游戏加速

				 
				if (ghost_num > 7) ghost_num += 2; //鬼的数量增加
				else ++ghost_num;
				//++z; //游戏加速

				tongguanchushihua();

			}


		}

	
}

