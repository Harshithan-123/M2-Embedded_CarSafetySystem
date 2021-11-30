#include <avr/io.h>
#include <util/delay.h>

#include "activity3.h"
#include "activity2.h"

void config_timer()
{
     TCCR1A|=(1<<COM1A1)|(1<<WGM11)|(1<<WGM10);
    TCCR1B|=(1<<CS11)|(1<<WGM12)|(1<<CS10);
    DDRB|=(1<<PB1);
}
void pwm_output(void)
{

    if((ReadADC(0)>=0) && (ReadADC(0)<=209)){

        OCR1A = 205; //20% duty cycle
        _delay_ms(20);
    }
    else if((ReadADC(0)>=210) && (ReadADC(0)<=509)){

        OCR1A = 410; //40% duty cycle
        _delay_ms(20);
    }
    else if((ReadADC(0)>=510) && (ReadADC(0)<=709)){

        OCR1A = 717;//70% duty cycle
        _delay_ms(20);
    }
    else if((ReadADC(0)>=710) && (ReadADC(0)<=1024)){

        OCR1A = 973; //95% duty cycle
        _delay_ms(20);
    }
    else
    {
        OCR1A = 0; //0% output
    }

}
