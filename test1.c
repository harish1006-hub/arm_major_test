#include<lpc21xx.h>
#include"delay_header.h"
#include"lcd_4bit_header.h"
unsigned int adc_read(void);
int main()
{unsigned int adc_value;
float voltage;
float temp;
lcd_init();
lcd_cmd(0X80);
lcd_str("HELLO");
delay_ms(2000);
lcd_cmd(0X01);
while(1)
{
lcd_cmd(0X80);
lcd_str("Temp:");
adc_value=adc_read();
voltage = ((adc_value * 3.3) / 1023.0);
temp = voltage * 100.0;  
lcd_float(temp);
delay_ms(500);
lcd_cmd(0x01);
delay_ms(2);
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
