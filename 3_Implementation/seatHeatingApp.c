//main application
#include <avr/io.h>
#include<util/delay.h>
#include "activity1.h"
#include "activity2.h"
#include "activity3.h"
#include"activity4.h"

int main(void)
{
    initialise();
     InitADC();
    USARTInit(103);//Initialize ports for USART
    uint16_t tempdata=0;// temperature value

    while(1)
    {
        if(occupied)
        {
            PORTB|=(1<<PB0);
            _delay_ms(200);
           
            config_timer();
            pwm_output();
            _delay_ms(200);
            
            tempdata=temp_disp();
            USARTWrite(tempdata);//send data to USART
            _delay_ms(20);
        }
        
        else
        {
           PORTB&=~(1<<PB0);
          _delay_ms(200);
          OCR1A = 0; //PWM wave 0
        }
    }
    return 0;
}
