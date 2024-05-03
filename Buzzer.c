#include<xc.h>

#pragma config WDT=OFF //Disable Watchdog timer
#pragma config LVP=OFF 
#pragma config PBADEN=OFF

//Declarations
#define lrbit PORTBbits.RB0
#define rlbit PORTBbits.RB1
#define relay PORTBbits.RB2
#define buzzer PORTbits.RB3

void msdelay(unsigned int time);

void main()
{
    unsigned char val=0;
    INTCON2bits.RBPU=0;
    ADCON1=0X0F;
    
    TRISBbits.TRISB0=1;
    TRISBbits.TRISB1=1;
    
    TRISBbits.TRISB2=0;
    TRISBbits.TRISB3=0;
    TRISD=0X00;
    
    PORTD=0x00;
    buzzer=0;
    relay=0;
    
    while(1)
    {
        if(!(lrbit))
            val=1;
        if(!(rlbit))
            val=2;
        
        if(val==1)
        {
            buzzer=1;
            relay=1;
            PORTD=PORTD>>1;
            if(PORTD == 0X00)
                PORTD=0X80;
            msdelay(250);
            
        }
        if(val==2)
        {
            buzzer=0;
            relay=0;
            PORTD=PORTD<<1;
            if(PORTD =0X00)
                PORTD=0X01;
            msdelay(250);
            
        }
    }   
}
void msdealy(unsigned int time)
{
    unsigned int i,j;
    for(i=0;i<time;i++)
        for(j=0;j<275;j++);
}





