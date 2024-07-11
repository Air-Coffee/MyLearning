#include <regx52.h>
void Delay(int p)	//@12.000MHz
{
	unsigned char data i, j;
	while(p >= 0) 
	{i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
	p--;
	}
}

int number[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
void led(int location, num)
{
	switch(location)
	{
		case 1:P2_4 = 1;P2_3 = 1;P2_2 = 1;break;
		case 2:P2_4 = 1;P2_3 = 1;P2_2 = 0;break;
		case 3:P2_4 = 1;P2_3 = 0;P2_2 = 1;break;
		case 4:P2_4 = 1;P2_3 = 0;P2_2 = 0;break;
		case 5:P2_4 = 0;P2_3 = 1;P2_2 = 1;break;
		case 6:P2_4 = 0;P2_3 = 1;P2_2 = 0;break;
		case 7:P2_4 = 0;P2_3 = 0;P2_2 = 1;break;
		case 8:P2_4 = 0;P2_3 = 0;P2_2 = 0;break;			
	}
	P0 = number[num];
}
void main(void)
{
	while(1)
	{
		led(2, 1);
		Delay(1);
		led(3, 1);
		Delay(1);
		led(4, 4);
		Delay(1);
		led(5, 5);
		Delay(1);
		led(6, 1);
		Delay(1);
		led(7, 4);
		Delay(1);
	}
}