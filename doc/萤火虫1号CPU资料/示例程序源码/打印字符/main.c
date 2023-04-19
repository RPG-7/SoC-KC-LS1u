#include "st7789.h"
#include "printf.h"

void main() {

	/* ��ʼ��LCD */
	Lcd_ST7789_Init(0);

	/* ����printf���꼰��ɫ���� */
	Printf_Set(0, 0, 0xffff, 0xf800);

	/* ��ӡ�ַ� */
	printf("0x%016llX\n", 0xfedcba9876543210);

	/* �ı䱳����ɫ */
	Printf_BG_Color(0x06e0);

	/* ��ӡ�ַ� */
	printf("%.18f\n", 3.141592653589793238);

	/* �ı䱳����ɫ */
	Printf_BG_Color(0x001f);

	/* ��ӡ�ַ� */
	printf("%lld\n", -9223372036854775807);

	while (1);
}
