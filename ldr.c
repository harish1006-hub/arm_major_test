#include<lpc21xx.h>
#include"lcd_4bit_header.h"
#include"delay_header.h"


#define ldr  16
#define led1  1<<17

int main()
{
lcd_init();
IODIR0 |=led1;
IOSET0=led1;
lcd_cmd(0x80);
lcd_str("welcome");
delay_ms(2000);
while(1)
{

 lcd_cmd(0x01);
if(((IOPIN0 >> ldr)&1)==1)
{lcd_cmd(0x80);
lcd_str("LED ON");
IOCLR0= led1;
}
else
{
lcd_cmd(0x80);
lcd_str("LED OFF");
IOSET0=led1;}
}
}
