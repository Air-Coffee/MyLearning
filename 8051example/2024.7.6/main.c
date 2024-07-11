# include <AT89x51.h>
/*****************************************
 P1------DB0～DB7 P2.0------RS
 P2.1------RW
 P2.2------E
*****************************************/
# define LCD_DB P1
 sbit LCD_RS=P2^0;
 sbit LCD_RW=P2^1;
 sbit LCD_E=P2^2;
/******定义函数****************/

void LCD_init(void);//初始化函数
void LCD_write_command(char command);//写指令函数
void LCD_write_data(char dat);//写数据函数
void LCD_disp_char(char x,char y,char dat);//在某个屏幕位置上显示一
//void LCD_check_busy(void);//检查忙函数。我没用到此函数，因为通过率极
void delay_n40us(int n);//延时函数
//********************************
//*******初始化函数***************
void LCD_init(void)
{
LCD_write_command(0x38);//设置 8 位格式，2 行，5x7
LCD_write_command(0x0c);//整体显示，关光标，不闪烁
LCD_write_command(0x06);//设定输入方式，增量不移位
LCD_write_command(0x01);//清除屏幕显示
delay_n40us(100);//实践证明，我的 LCD1602 上，用 for 循环 200 次就能可靠
}
//********************************
//********写指令函数************
void LCD_write_command(char dat)
{
LCD_DB=dat;
LCD_RS=0;//指令
LCD_RW=0;//写入
LCD_E=1;//允许
LCD_E=0;
delay_n40us(1);//实践证明，我的 LCD1602 上，用 for 循环 1 次就能完成普通
}
//*******************************
//********写数据函数*************
void LCD_write_data(char dat)
{
LCD_DB=dat;
LCD_RS=1;//数据
LCD_RW=0;//写入
LCD_E=1;//允许
LCD_E=0;
delay_n40us(1);
}
//********************************
//*******显示一个字符函数*********
void LCD_disp_char(char x,char y,char dat)
{
char address;
if(y==1)
 address=0x80+x;
else
 address=0xc0+x;
LCD_write_command(address);
LCD_write_data(dat);
}
//********************************
/*******检查忙函数*************
void LCD_check_busy() //实践证明，在我的 LCD1602 上，检查忙指令通
过率极低，以
{ //至于不能正常使用 LCD。因
此我没有再用检查忙函数。而使
do //用了延时的方法，延时还是非
常好用的。我试了一下，用
 { LCD_E=0; //for 循环作延时，普通指令只要 1
次循就可完成。清屏指令
 LCD_RS=0; //要用 200 次循环便能完成。
 LCD_RW=1;
 LCD_DB=0xff;
 LCD_E=1;
 }while(LCD_DB^7==1);
｝
******************************/
//********延时函数***************
void delay_n40us(int n)
{ int i;
 char j;
 for(i=n;i>0;i--)
 for(j=0;j<2;j++); //在这个延时循环函数中我只做了
} 
//实践证明我的 LCD1602 上普
//*******************************
//*********主函数*****************
void main(void)
{
 LCD_init();
 LCD_disp_char(0,1,"A");
 while(1);
}
