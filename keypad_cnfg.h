/*
 * keypad_cnfg.h
 *
 * Created: 11/14/2022 12:06:15 AM
 *  Author: LOGO
 */ 


#ifndef KEYPAD_CNFG_H_
#define KEYPAD_CNFG_H_

#include "std_macro.h"

#define INIT_KEYPAD_PINS() DDRB=0xff; PORTD=0xff; PORTB=0xff
                         

#define K0()  READBIT(PIND,2)
#define K1()  READBIT(PIND,3)
#define K2()  READBIT(PIND,4)
#define K3()  READBIT(PIND,5) 


#define K4(x) if(x==1) SETBIT(PORTB,4); else CLRBIT(PORTB,4);
#define K5(x) if(x==1) SETBIT(PORTB,5); else CLRBIT(PORTB,5);
#define K6(x) if(x==1) SETBIT(PORTB,6); else CLRBIT(PORTB,6);
#define K7(x) if(x==1) SETBIT(PORTB,7); else CLRBIT(PORTB,7);




#endif /* KEYPAD_CNFG_H_ */