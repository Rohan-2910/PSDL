#include<xc.h>

#pragma config  WDT=OFF;
#pragma config LVP=OFF;
#pragma config PBADEN =OFF;

#define LCD_DATA  PORTD
#define ctrl PORTE
#define rs PORTEbits.RE0
#define rw PORTEbits.RE1
#define en PORTEbits.RE2

void init_LCD(void);
void LCD_command(unsigned char cmd);
void LCD_data(unsigned char data);
void LCD_write_string(char *str);
void msdelay(unsigned int time);

//start of main program
void main(void)
{
    char var1[]="Welcome SE-IT";
    char var2[]="IT's not a joke";
    ADCON1=0x0f;
    TRISD =0x00;
    TRISE=0X00;
    
    init_LCD();
    msdelay(50);
    
    LCD_write_string(var1);
    msdelay(15);
    
    LCD_command(0xC0);
    LCD_write_string(var2);
    while(1);    
}

void msdelay(unsigned int time)
{
    unsigned int i,j;
    for(i=0;i<time;i++)
        for(j=0;j<275;j++);
}
void init_LCD(void)
{
    LCD_command(0x38);
    msdelay(15);
    LCD_command(0x01);
    msdelay(15);
    LCD_command(0x0c);
    msdelay(15);
    LCD_command(0x80);
    msdelay(15);    
}
void LCD_command(unsigned char cmd)
{
    LCD_DATA=cmd;
    rs=0;
    rw=0;
    en=1;
    msdelay(15);
    en=0;
}
void LCD_data(unsigned char data)
{
    LCD_DATA=data;
    rs=1;
    rw=0;
    en=1;
    msdelay(15);
    en=0;
}

void LCD_write_string(char *str)
{
    int i=0;
    while(str[i]!=0)
    {
        LCD_data(str[i]);
        msdelay(15);
        i++;
    }
}

