#include "st7789.h"
#include "printf.h"

void main() {

	/* ��ʼ��LCD */
	Lcd_ST7789_Init(0x1018);

	/* ����printf���꼰��ɫ���� */
	Printf_Set(0, 0, 0xffff, 0x1018);

	/* ��ӡ�ַ� */
	printf("���!!!\n");
	printf("��������,��л֧��^-^!\n");
	printf("ʱ��: 2022.10.27");

	while (1);
}
