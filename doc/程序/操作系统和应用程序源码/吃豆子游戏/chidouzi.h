void chidouzi_Display_interface_0(unsigned char y, unsigned char x, unsigned char data) //��ʾ�ӿ�0,����,yxΪ����,data��������
{
	_B = data;
	_A = x;
	_A1 = y;
	_A2 = 0x80;
	_A0 = _A;
	_NOP;
	_RAM = _B;
}

void chidouzi_Display_interface_1(unsigned char y, unsigned char x, unsigned char _y, unsigned char _x, unsigned char data) //��ʾ�ӿ�1,��ɫ��,yxΪ��ʼ����,_y_xΪ����,data��������
{
	VGA_SK1(y, x, _y, _x, data);
}

void qingping()	  //����  ���ú��ȫ��ˢ��ɫ
{
	chidouzi_Display_interface_1(0, 0, 160, 128, 0);
}

void cachu() //����(����֡)	(��Һ͹���������ʾ���õġ�������9*9���ؿ�) �÷�:�ȸ�xx��yy������������ Ȼ����ô˺���������ʾ��ɫΪse2���������ؿ���ָ������
{
	chidouzi_Display_interface_1(yy, xx, 9, 9, k1[se2]);
}


void shanggai_L()  //�ϸ� (ˮƽ �����ɲ���(ʡROM))  (�������֡����ɲ��� ����Ҫ����)
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

void xiagai_L()	  //�¸� (ˮƽ �����ɲ���(ʡROM))	  (�������֡����ɲ��� ����Ҫ����)
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

void zhangzui_R()   //�����������(����֡)	�÷����ȸ�xx1��yy1������������ֵ Ȼ����ô˺���������ʾ�����ָ������ �����ɫΪse������ֵ
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


void bizui_R()	 //������ұ���(����֡)	  �÷����ȸ�xx1��yy1������������ֵ Ȼ����ô˺���������ʾ�����ָ������ �����ɫΪse������ֵ
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


void zhangzui_L()  //�����������(����֡)  �÷����ȸ�xx1��yy1������������ֵ Ȼ����ô˺���������ʾ�����ָ������ �����ɫΪse������ֵ
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


void bizui_L() //����������(����֡)  �÷����ȸ�xx1��yy1������������ֵ Ȼ����ô˺���������ʾ�����ָ������ �����ɫΪse������ֵ
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


void zhangzui_O()  //�����������(����֡)   �÷����ȸ�xx1��yy1������������ֵ Ȼ����ô˺���������ʾ�����ָ������ �����ɫΪse������ֵ
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


void bizui_O()  //������ϱ���(����֡)	  �÷����ȸ�xx1��yy1������������ֵ Ȼ����ô˺���������ʾ�����ָ������ �����ɫΪse������ֵ
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


void zhangzui_U()  //�����������(����֡)	�÷����ȸ�xx1��yy1������������ֵ Ȼ����ô˺���������ʾ�����ָ������ �����ɫΪse������ֵ
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


void bizui_U()  //������±���(����֡)	�÷����ȸ�xx1��yy1������������ֵ Ȼ����ô˺���������ʾ�����ָ������ �����ɫΪse������ֵ
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


void GHOSTgongyong() //������干�ò��� (�ϰ���(ʡROM))(����Ҫ����)
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


void GHOST_L()		//��~~~  ����(����֡)	�÷����ȸ�xx2��yy2������������ֵ Ȼ����ô˺���������ʾ����ָ������
{
	GHOSTgongyong();
}


void GHOST_H()	   //��~~~ ���(����֡)	  �÷����ȸ�xx2��yy2������������ֵ Ȼ����ô˺���������ʾ����ָ������
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

void shuzixianshi()	//0~9������ʾ (�ֿ����)  �÷�:�ȸ�sx��sy������������ֵ �ٸ�zm��������0~9�ֿ����ʼλ�� Ȼ����ô˺���������ʾ������ָ�������� ��ɫ�����Ѷ�
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

void shuzixianshijinweigengxin()  //������ʾ��λ����  �÷�:zzzz1��zzzz2��zzzz3��zzzz4������Ӧ��λ��ʮλ����λ��ǧλ ���ֿ���˵��90���� ���Ա�����1���ڼ�9 �˺��������Ѷ� ���üȿɸ��±���ֵ��������ʾ 
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
	shuzixianshi();        //��1λ
	sx = 50; zm = zzzz2;
	shuzixianshi();        //��2λ
	sx = 42; zm = zzzz3;
	shuzixianshi();        //��3λ
	sx = 34; zm = zzzz4;
	shuzixianshi();        //��4λ

}


void douzi()   //����(����֡)  �÷�����xx3��yy3������������  Ȼ����ô˺���������ʾ������ָ������ ������ɫΪse1������ֵ
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

void douzifenbu()	//���ӷֲ�  �˺�������ˢ�¶��������������ʾ
{
	se1 = 2;

	if (z1 == 0)
	{
		xx3 = 7; yy3 = 13;	 //������Ͻ�����
		douzi();
	}

	if (z2 == 0)
	{
		xx3 = 117; yy3 = 13;  //������Ͻ�����
		douzi();
	}

	if (z3 == 0)
	{
		xx3 = 7; yy3 = 143;   //������½�����
		douzi();
	}

	if (z4 == 0)
	{
		xx3 = 117; yy3 = 143;	 //������½�����
		douzi();
	}

	if (z5 == 0)
	{
		xx3 = 27; yy3 = 13;   //�п����Ͻ��ϵ�����
		douzi();
	}

	if (z6 == 0)
	{
		xx3 = 7; yy3 = 113;	//�п����½��µ�����
		douzi();
	}

	if (z7 == 0)
	{
		xx3 = 117; yy3 = 43;	 //�п����Ͻ��ϵ�����
		douzi();
	}

	if (z8 == 0)
	{
		xx3 = 97; yy3 = 143;	 //�п����½��µ�����
		douzi();
	}

	if (z9 == 0)
	{
		xx3 = 27; yy3 = 43;	 //�п����Ͻ�����
		douzi();
	}

	if (z10 == 0)
	{
		xx3 = 27; yy3 = 113;	 //�п����½�����
		douzi();
	}

	if (z11 == 0)
	{
		xx3 = 97; yy3 = 43;	 //�п����Ͻ�����
		douzi();
	}

	if (z12 == 0)
	{
		xx3 = 97; yy3 = 113;	  //�п����½�����
		douzi();
	}

	if (z13 == 0)
	{
		xx3 = 47; yy3 = 43;	//�ڿ����Ͻ��ϵ�����
		douzi();
	}

	if (z14 == 0)
	{
		xx3 = 27; yy3 = 93;	//�ڿ����½��µ�����
		douzi();
	}

	if (z15 == 0)
	{
		xx3 = 97; yy3 = 63;   //�ڿ����Ͻ��ϵ�����
		douzi();
	}

	if (z16 == 0)
	{
		xx3 = 77; yy3 = 113;  //�ڿ����½��µ�����
		douzi();
	}

	if (z17 == 0)
	{
		xx3 = 47; yy3 = 63;   //�ڿ����Ͻ�����
		douzi();
	}

	if (z18 == 0)
	{
		xx3 = 47; yy3 = 93;   //�ڿ����½�����
		douzi();
	}

	if (z20 == 0)
	{
		xx3 = 77; yy3 = 93;   //�ڿ����½�����
		douzi();
	}

	if (z19 == 0)
	{
		xx3 = 77; yy3 = 63;   //�ڿ����Ͻ�����
		sex++;
		if (sex == 10)
		{
			sex = 0;
		}
		se1 = sex;
		douzi();
	}



}

void kuaicachu()  //�����(����֡) 11*11���� (����ͼ�� ��ɫΪ����ɫ) �÷�:��kx��ky������������ֵȻ����ô˺�����OK~~
{
	chidouzi_Display_interface_1(ky, kx, 11, 11, k1[9]);
}

void ditu()	 //��ͼ  ���þͻ�����ͼ
{
	kx = 4; ky = 0;

	while (ky <= 130)	//������
	{

		ky = ky + 10;
		kuaicachu();
	}


	while (kx <= 104)  //����µ�
	{
		kx = kx + 10;
		kuaicachu();
	}

	while (ky >= 20)	  //����ҵ�
	{
		ky = ky - 10;
		kuaicachu();
	}

	while (kx >= 24)	  //����ϵ�
	{
		kx = kx - 10;
		kuaicachu();
	}


	kx = 24; ky = 10;	//�п����

	while (ky <= 90)
	{
		ky = ky + 10;
		kuaicachu();
	}

	kx = 4;  ky = 110;	 //�п��µ�

	while (kx <= 74)
	{
		kx = kx + 10;
		kuaicachu();
	}

	kx = 94;  ky = 140;	   //�п��ҵ�

	while (ky >= 60)
	{
		ky = ky - 10;
		kuaicachu();
	}

	kx = 114;  ky = 40;	   //�п��ϵ�

	while (kx >= 44)
	{
		kx = kx - 10;
		kuaicachu();
	}

	kx = 44;  ky = 40;	 //�ڿ����

	while (ky <= 70)
	{
		ky = ky + 10;
		kuaicachu();
	}

	kx = 24;  ky = 90;	 //�ڿ��µ�

	while (kx <= 54)
	{
		kx = kx + 10;
		kuaicachu();
	}

	kx = 74;  ky = 110;	 //�ڿ��ҵ�

	while (ky >= 80)
	{
		ky = ky - 10;
		kuaicachu();
	}

	kx = 94;  ky = 60;	 //�ڿ��ϵ�

	while (kx >= 64)
	{
		kx = kx - 10;
		kuaicachu();
	}

	kx = 4;  ky = 0;  //������ϴ�����

	kuaicachu();

	kx = 0;  ky = 140;  //������´�����

	kuaicachu();

	kx = 117;  ky = 10;  //������ϴ�����

	kuaicachu();

	kx = 114;  ky = 149;  //������´�����

	kuaicachu();

}




void KEY_Okongzhi()  //���򰴼��Ͽ���
{
	if (KEY_O == 1)  //�ж��ϼ�����
	{
		jj1 = 4;   //�����ϼ���
		k = 2;	 //���������/���춯����
	}
}

void KEY_Ukongzhi()  //���򰴼��¿���
{
	if (KEY_U == 1)  //�ж��¼�����
	{
		jj1 = 2;   //����������
		k = 3;	 //���������/���춯����
	}
}

void KEY_Lkongzhi()  //���򰴼������
{
	if (KEY_L == 1)  //�ж��������
	{
		jj1 = 3;   //���������
		k = 1;	 //���������/���춯����
	}
}

void KEY_Rkongzhi()  //���򰴼��ҿ���
{
	if (KEY_R == 1)  //�ж��Ҽ�����
	{
		jj1 = 1;   //����������
		k = 0;	 //���������/���춯����
	}
}

void wanjiazuobiaopanduankongzhi()  //��ҵ�ͼת�������жϿ���(���ݵ�ͼ)
{

	if (xx1 == 5 & yy1 == 1)	  //���ϴ����ų�������(��ҳ�����)
	{
		KEY_Okongzhi();

		KEY_Ukongzhi();
	}

	if (xx1 == 5 & yy1 == 11)		 //������Ͻ�����
	{
		if (jj1 == 3)	   //������������Ϊ�� ��ر����X/Y������
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

	if (xx1 == 115 & yy1 == 11)   //������Ͻ�����
	{
		if (jj1 == 4)	   //��������ϼ���Ϊ�� ��ر����X/Y������
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

	if (xx1 == 5 & yy1 == 141)	//������½�����
	{
		if (jj1 == 2)	   //�������������Ϊ�� ��ر����X/Y������
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

	if (xx1 == 115 & yy1 == 141)	  //������½�����
	{
		if (jj1 == 1)	 //�������������Ϊ�� ��ر����X/Y������
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

	if (xx1 == 25 & yy1 == 11)	//�п����Ͻ��ϵ�����
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

	if (xx1 == 5 & yy1 == 111)	//�п����½��µ�����
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

	if (xx1 == 115 & yy1 == 41)	 //�п����Ͻ��ϵ�����
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

	if (xx1 == 95 & yy1 == 141)	//�п����½��µ�����
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

	if (xx1 == 25 & yy1 == 41)  //�п����Ͻ�����
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

	if (xx1 == 25 & yy1 == 111)	//�п����½�����
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

	if (xx1 == 95 & yy1 == 41)	//�п����Ͻ�����
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

	if (xx1 == 95 & yy1 == 111)	 //�п����½�����
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

	if (xx1 == 45 & yy1 == 41)  //�ڿ����Ͻ��ϵ�����
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

	if (xx1 == 25 & yy1 == 91)  //�ڿ����½��µ�����
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

	if (xx1 == 95 & yy1 == 61)  //�ڿ����Ͻ��ϵ�����
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

	if (xx1 == 75 & yy1 == 111)	//�ڿ����½��µ�����
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

	if (xx1 == 45 & yy1 == 61)	//�ڿ����Ͻ�����
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

	if (xx1 == 45 & yy1 == 91)  //�ڿ����½�����
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

	if (xx1 == 75 & yy1 == 61)  //�ڿ����Ͻ�����
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

	if (xx1 == 75 & yy1 == 91) //�ڿ����½�����
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

void GHOSTzidongzhuizong() //���Զ�׷�����    (���ļ���~~~ ���ݵ�ͼ)
{
	if (xxxx == 5 & yyyy == 11)		 //������Ͻ�����
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

	if (xxxx == 115 & yyyy == 11)   //������Ͻ�����
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

	if (xxxx == 5 & yyyy == 141)	//������½�����
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

	if (xxxx == 115 & yyyy == 141)	 //������½�����
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

	if (xxxx == 25 & yyyy == 11)	  //�п����Ͻ��ϵ�����
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

	if (xxxx == 5 & yyyy == 111)	//�п����½��µ�����
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

	if (xxxx == 115 & yyyy == 41)	 //�п����Ͻ��ϵ�����
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

	if (xxxx == 95 & yyyy == 141)	//�п����½��µ�����
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

	if (xxxx == 25 & yyyy == 41)  //�п����Ͻ�����
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

	if (xxxx == 25 & yyyy == 111)	//�п����½�����
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

	if (xxxx == 95 & yyyy == 41)	//�п����Ͻ�����
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

	if (xxxx == 95 & yyyy == 111)	 //�п����½�����
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

	if (xxxx == 45 & yyyy == 41)  //�ڿ����Ͻ��ϵ�����
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

	if (xxxx == 25 & yyyy == 91)  //�ڿ����½��µ�����
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

	if (xxxx == 95 & yyyy == 61)  //�ڿ����Ͻ��ϵ�����
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

	if (xxxx == 75 & yyyy == 111)	//�ڿ����½��µ�����
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

	if (xxxx == 45 & yyyy == 61)	//�ڿ����Ͻ�����
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

	if (xxxx == 45 & yyyy == 91)  //�ڿ����½�����
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

	if (xxxx == 75 & yyyy == 61)  //�ڿ����Ͻ�����
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

	if (xxxx == 75 & yyyy == 91) //�ڿ����½�����
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


void chuansongmen()	 //������ ����������޸ģ�
{
	if (xx1 == 5 & yy1 == 0)	  //������ϴ������������
	{
		xx1 = 115; yy1 = 150;	  //��������
	}

	if (xx1 == 115 & yy1 == 151)	  //������´������������
	{
		xx1 = 5; yy1 = 1;		//��������
	}

	if (xx1 == 119 & yy1 == 11)	  //������ϴ������������
	{
		xx1 = 1; yy1 = 141;	//��������
	}

	if (xx1 == 0 & yy1 == 141)	  //������´������������
	{
		xx1 = 118; yy1 = 11;	 //��������
	}
}

void shualvse()	  //ˢ��ɫ�ϰ���
{
	chidouzi_Display_interface_1(20, 14, 120, 100, k1[3]);
}



void shengmingxianshi()  //������ʾ�͸���  sm����������ʾ���������ٵ��ô˺�����OK~~~
{
	///////////����������ʾ/////////
	smx = 0;

	yy = 151; xx = 0; se2 = 7;

	while (smx < 11)
	{
		cachu();
		xx = xx + 10;
		smx++;
	}

	se2 = 9;

	///////////д������///////////
	smx = 0;

	xx1jc = xx1;	//����
	yy1jc = yy1;

	yy1 = 151; xx1 = 0; se = 2;

	while (smx < sm)
	{
		zhangzui_R();
		xx1 = xx1 + 10;
		smx++;
	}

	xx1 = xx1jc;   //ȡ��
	yy1 = yy1jc;
}




void pengzhuangpanduan()   //��Һ͹���ײ�ж�(����)
{

	if (xx1 == xxxxx & yy1 == yyyyy || xx1 == xxxxx + 1 & yy1 == yyyyy || xx1 == xxxxx - 1 & yy1 == yyyyy || xx1 == xxxxx & yy1 == yyyyy + 1 || xx1 == xxxxx & yy1 == yyyyy - 1)
	{
		if (wd == 0 & z19 == 1)   //�ж�����Ƿ��޵�
		{
			cc = 0;	 //�޵о͹رչ���ʾ
			if (sm < 7)
			{
				sm = sm + 1; //������ʾ��1
			}
			shengmingxianshi();	//����������ʾ

			zzzz2 = zzzz2 + 9;	//�����ġ�ʮλ����9
			shuzixianshijinweigengxin();  //��ʮλ����ʾ��1����Ļ
		}
		else	//û���޵�
		{
			if (sm > 0)
			{
				sm = sm - 1; //������ʾ��1
			}
			shengmingxianshi(); //����������ʾ

			if (sm == 0)	//������Ϊ0(����~~)�������֮��������ʾ����      
			{
				qingping();

				sx = 70; sy = 76; zm = zzzz1;
				shuzixianshi();        //��1λ
				sx = 62; zm = zzzz2;
				shuzixianshi();        //��2λ
				sx = 54; zm = zzzz3;
				shuzixianshi();        //��3λ
				sx = 46; zm = zzzz4;
				shuzixianshi();        //��4λ

				xh = 0;	//main()����ĵ�2��ѭ����·
			}
		}
	}

}

void GHOST()	 //������(N������)
{

	///////////////////////////////����Ʋ���///////////////////////////

	GHOSTzidongzhuizong();   //���ͼת���Զ�׷�ٿ���  Ӱ�������X��Y��������������̨

////////////////////////////////�����֡/////////////////////////////

	xx = xxxx; yy = yyyy;

	cachu();

	////////////////////////////��X��Y��������������̨///////////////////////////

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

	/////////////////////////��Ŀ���֡��ʾ����////////////////////////////

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

void tongguanchushihua()  //ͨ�س�ʼ��
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

	//for (i = 0; i < ghost_num; ++i) ghost_x[i] = 0; //��ʼ����Ĳ���
	//for (i = 0; i < ghost_num; ++i) ghost_y[i] = 0; //��ʼ����Ĳ���
	for (i = 0; i < ghost_num; ++i) ghost_display[i] = 0; //��ʼ����Ĳ���
	for (i = 0; i < ghost_num; ++i) ghost_delayed[i] = 0; //��ʼ����Ĳ���

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

void chidouzi_init() //�Զ��ӳ�ʼ��
{
	z = 2; //��Ϸ�ٶ�
	sm = 3; //�����������ֵ
	ghost_num = 1; //��ĳ�ʼ����
	zzzz1 = 0;
	zzzz2 = 0;
	zzzz3 = 0;
	zzzz4 = 0;
	tongguanchushihua();
}

void chidouzi_run() //�Զ���_����
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
				chidouzi_init(); //�Զ��ӳ�ʼ��
				xh = 1; //��Ϸ��ʼ����
			}
		}

		if (xh != 0)
		{


			//for (x = 0; x < z; x++);	 //��Ϸ�ٶȿ���



			douzifenbu();	 //ˢ�¶���

  ///////////////////////////////////��ҿ��Ʋ���(�����޵п��� & ����֡ & ������ & X��Y��������������̨ & ����֡��ʾ)/////////////////

			wanjiazuobiaopanduankongzhi();  //��ҵ�ͼת�ǰ�������  Ӱ�������X��Y��������������̨

  ////////////////////////////////����޵п���/////////////////////////////

			if (wd == 0)
			{
				if (z19 == 1)
				{
					se++;
					if (se == 10)	 //�����ɫ��ͣ�ĸ���  ~����Ч��
					{
						se = 0;
					}
					y++;
					if (y == 700)		//�޵�ʱ����ʱʱ��
					{
						y = 0;
						wd = 1;
						se = 2;
					}
				}
			}

			///////////////////////////////��Ҳ���֡//////////////////////

			xx = xx1; yy = yy1;

			cachu();

			///////////////////////������////////////////////////////////

			chuansongmen();

			////////////////////////////////���X��Y��������������̨//////////////////////	
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

			////////////////////////////////��ҿ���֡��ʾ����///////////////////////////

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


			///////////////////////����ƴ���/////////////////////////////

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

			///////////////////////��1���ƴ���/////////////////////////////

			if (c1 == 1)
			{
				xxxx = xxx1; yyyy = yyy1; jjj = jj2; //��ʵ����Ϳ����͵���������Ϳ���
				GHOST();
				xxx1 = xxxx; yyy1 = yyyy; jj2 = jjj; //��������Ϳ����ͻ���ʵ����Ϳ���
			}

			///////////////////////��2���ƴ���////////////////////////////

			if (c2 == 1)
			{
				xxxx = xxx2; yyyy = yyy2; jjj = jj3;
				GHOST();
				xxx2 = xxxx; yyy2 = yyyy; jj3 = jjj;
			}

			////////////////////////��3���ƴ���///////////////////////////

			if (c3 == 1)
			{
				xxxx = xxx3; yyyy = yyy3; jjj = jj4;
				GHOST();
				xxx3 = xxxx; yyy3 = yyyy; jj4 = jjj;
			}

			/////////////////////////��4���ƴ���//////////////////////////

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

			//////////////////////��ײ�жϹ�1////////////////////////////

			xxxxx = xxx1; yyyyy = yyy1; cc = c1;	  //�������͸���ײ�жϹ���������� �����رձ���Ҳ�͹�ȥ
			pengzhuangpanduan();
			c1 = cc;			   //����Ľ���ͻ���

//////////////////////��ײ�жϹ�2////////////////////////////

			xxxxx = xxx2; yyyyy = yyy2; cc = c2;
			pengzhuangpanduan();
			c2 = cc;

			//////////////////////��ײ�жϹ�3////////////////////////////

			xxxxx = xxx3; yyyyy = yyy3; cc = c3;
			pengzhuangpanduan();
			c3 = cc;

			//////////////////////��ײ�жϹ�4////////////////////////////

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
			//////////////////////��1��ʱ����/////////////////////////////			   

			if (c1 == 0)
			{
				xxx1 = 0; yyy1 = 0;	  //�������ÿ�
				s1++;
				if (s1 == 160)     //��ʱֵ
				{
					xxx1 = 75; yyy1 = 61;	  //�������
					s1 = 0;
					c1 = 1;
				}
			}

			//////////////////////��2��ʱ����/////////////////////////////

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

			//////////////////////��3��ʱ����/////////////////////////////

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

			//////////////////////��4��ʱ����/////////////////////////////

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



			////////////////��Һ͹�֡�л�Ƶ�ʺ�ռ�ձȷ�������(����/���ռ�ձ�0.76  ����/����ռ�ձ�0.24)///////

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

			//////////////////////////////////�жϳ��궹�Ӻ�ͨ�ش���///////////////////////////		  

			if (z1 + z2 + z3 + z4 + z5 + z6 + z7 + z8 + z9 + z10 + z11 + z12 + z13 + z14 + z15 + z16 + z17 + z18 + z19 + z20 == 20) //�жϳ��궹��
			{

				if (ghost_num == 20)	//ȫ��ͨ�� �����֮��������ʾ����
				{
					qingping();

					sx = 70; sy = 76; zm = zzzz1;
					shuzixianshi();        //��1λ
					sx = 62; zm = zzzz2;
					shuzixianshi();        //��2λ
					sx = 54; zm = zzzz3;
					shuzixianshi();        //��3λ
					sx = 46; zm = zzzz4;
					shuzixianshi();        //��4λ

					xh = 0;
					return;
				}

				//z = z - 2000;	 //��2000��ʱ��  ��Ϸ����

				 
				if (ghost_num > 7) ghost_num += 2; //�����������
				else ++ghost_num;
				//++z; //��Ϸ����

				tongguanchushihua();

			}


		}

	
}

