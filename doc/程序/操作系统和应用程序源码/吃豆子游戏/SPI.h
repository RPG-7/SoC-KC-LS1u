void SPI_WIDLE_IDLE() //�ȴ�SPI����
{
  while((SPI_INT & 0x80) != 0x80);
}

void SPI_RST()	 //SPI�����źźͷ��͵�Ԫ��λ
{

  SPI_S = 0x01; //����SPI�շ���
  SPI_D = 0xff; //SPI�շ���д��1���ֽ� �������״̬
  SPI_WIDLE_IDLE(); //�ȴ�SPI����

}

void SPI_SET_DLED(unsigned char data)
{

  SPI_S = 0x04;
  SPI_D = data;
  SPI_S = 0x01;

}