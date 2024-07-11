# include <AT89x51.h>
/*****************************************
 P1------DB0��DB7 P2.0------RS
 P2.1------RW
 P2.2------E
*****************************************/
# define LCD_DB P1
 sbit LCD_RS=P2^0;
 sbit LCD_RW=P2^1;
 sbit LCD_E=P2^2;
/******���庯��****************/

void LCD_init(void);//��ʼ������
void LCD_write_command(char command);//дָ���
void LCD_write_data(char dat);//д���ݺ���
void LCD_disp_char(char x,char y,char dat);//��ĳ����Ļλ������ʾһ
//void LCD_check_busy(void);//���æ��������û�õ��˺�������Ϊͨ���ʼ�
void delay_n40us(int n);//��ʱ����
//********************************
//*******��ʼ������***************
void LCD_init(void)
{
LCD_write_command(0x38);//���� 8 λ��ʽ��2 �У�5x7
LCD_write_command(0x0c);//������ʾ���ع�꣬����˸
LCD_write_command(0x06);//�趨���뷽ʽ����������λ
LCD_write_command(0x01);//�����Ļ��ʾ
delay_n40us(100);//ʵ��֤�����ҵ� LCD1602 �ϣ��� for ѭ�� 200 �ξ��ܿɿ�
}
//********************************
//********дָ���************
void LCD_write_command(char dat)
{
LCD_DB=dat;
LCD_RS=0;//ָ��
LCD_RW=0;//д��
LCD_E=1;//����
LCD_E=0;
delay_n40us(1);//ʵ��֤�����ҵ� LCD1602 �ϣ��� for ѭ�� 1 �ξ��������ͨ
}
//*******************************
//********д���ݺ���*************
void LCD_write_data(char dat)
{
LCD_DB=dat;
LCD_RS=1;//����
LCD_RW=0;//д��
LCD_E=1;//����
LCD_E=0;
delay_n40us(1);
}
//********************************
//*******��ʾһ���ַ�����*********
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
/*******���æ����*************
void LCD_check_busy() //ʵ��֤�������ҵ� LCD1602 �ϣ����æָ��ͨ
���ʼ��ͣ���
{ //���ڲ�������ʹ�� LCD����
����û�����ü��æ��������ʹ
do //������ʱ�ķ�������ʱ���Ƿ�
�����õġ�������һ�£���
 { LCD_E=0; //for ѭ������ʱ����ָͨ��ֻҪ 1
��ѭ�Ϳ���ɡ�����ָ��
 LCD_RS=0; //Ҫ�� 200 ��ѭ��������ɡ�
 LCD_RW=1;
 LCD_DB=0xff;
 LCD_E=1;
 }while(LCD_DB^7==1);
��
******************************/
//********��ʱ����***************
void delay_n40us(int n)
{ int i;
 char j;
 for(i=n;i>0;i--)
 for(j=0;j<2;j++); //�������ʱѭ����������ֻ����
} 
//ʵ��֤���ҵ� LCD1602 ����
//*******************************
//*********������*****************
void main(void)
{
 LCD_init();
 LCD_disp_char(0,1,"A");
 while(1);
}
