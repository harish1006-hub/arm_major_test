#include<lpc21xx.h>
#include"delay_header.h"
#include"lcd_4bit_header.h"
unsigned int adc_read(void);
int main()
{
unsigned int adc_value;
unsigned int value;
lcd_init();
while(1)
{
lcd_cmd(0X80);
lcd_str("FUEL:");
adc_value=adc_read();
value = (adc_value * 100) / 1023;
lcd_cmd(0X85); 
lcd_int(value); 
lcd_data('%');
delay_ms(1000);
lcd_cmd(0X01);
}

}


unsigned int adc_read(void)
{ unsigned int adc;
PINSEL1|= 1<<22;
ADCR=(1<<0)|(4<<8)|(1<<21);
ADCR |= (1<<24);
while(!(ADDR&0X80000000));
adc=((ADDR>>6)&0X3FF);
return adc;
}
