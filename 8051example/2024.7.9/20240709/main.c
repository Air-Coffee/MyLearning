#include <regx52.h>
#include "LCD1602.h"
void main(void)
{
	LCD_Init();
	LCD_ShowChar(1, 1, 'A');
	LCD_ShowString(1, 3, "Hello");
	while(1)
	{
	}
}