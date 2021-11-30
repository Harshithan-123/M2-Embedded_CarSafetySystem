#ifndef ACTIVITY1_H_INCLUDED
#define ACTIVITY1_H_INCLUDED

void initialise();//TO INITIALISE PORTS

#define occupied (!(PIND&(3<<PD0)))//Check if seat is occupied


#endif
