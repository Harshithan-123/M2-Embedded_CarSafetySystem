#include <avr/io.h>
#include "activity2.h"


void InitADC()
{
    ADMUX=(1<<REFS0); //ADref=AVcc
    ADCSRA=(1<<ADEN)|(7<<ADPS0);
}
uint16_t ReadADC(uint8_t ch)
{

    ADMUX&=0xf8;//SELECT ADC CHANNEL CH MUST BE 0-7
    ch=ch&0b00000111;
    ADMUX|=ch;
    //start single conversion
    ADCSRA|=(1<<ADSC);
    //WAIT FOR CONVERSION TO COMPLETE
    while(!(ADCSRA&(1<<ADIF)));
    //CLEAR ADIF BY WRITING ONE TO IT
    ADCSRA|=(1<<ADIF);
    return(ADC);
}
