#include <avr/io.h>
#include "activity1.h"

void initialise()//TO INITIALISE PORTS
{
    DDRB|=(1<<PB0);//TO MAKE B0 AS AN OUTPUT PIN
    DDRD&=~(3<<PD0);//TO MAKE Do and D1  AS AN INPUT PIN
    PORTD|=(3<<PD0);//PULL UP
  
}
