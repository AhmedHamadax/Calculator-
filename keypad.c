 /*
 * keypad.c
 *
 * Created: 11/14/2022 12:01:30 AM
 *  Author: LOGO
 */ 

#include "keypad_cnfg.h"
#include "keypad.h"
uint8_t const keypad_matrix[]={
	'7','8','9','/',
	'4','5','6','*',
	'1','2','3','-',
	'c','0','=','+'
	};


void KEYPAD_INIT(void){
     INIT_KEYPAD_PINS();
	
}
int8_t KEYPAD_READ(void){
	K4(0);K5(1);K6(1);K7(1)
	if(K0() == 0 ) return keypad_matrix[0];
	if(K1() == 0 ) return keypad_matrix[1];	
	if(K2() == 0 ) return keypad_matrix[2];	
	if(K3() == 0 ) return keypad_matrix[3];
	_delay_ms(5);
	
	K4(1);K5(0);K6(1);K7(1)
	if(K0() == 0 ) return keypad_matrix[4];
	if(K1() == 0 ) return keypad_matrix[5];
	if(K2() == 0 ) return keypad_matrix[6];
	if(K3() == 0 ) return keypad_matrix[7];
	_delay_ms(5);
		
	K4(1);K5(1);K6(0);K7(1)
	if(K0() == 0 ) return keypad_matrix[8];
	if(K1() == 0 ) return keypad_matrix[9];
	if(K2() == 0 ) return keypad_matrix[10];
	if(K3() == 0 ) return keypad_matrix[11];
	_delay_ms(5);
	
	K4(1);K5(1);K6(1);K7(0)
	if(K0() == 0 ) return keypad_matrix[12];
	if(K1() == 0 ) return keypad_matrix[13];
	if(K2() == 0 ) return keypad_matrix[14];
	if(K3() == 0 ) return keypad_matrix[15];
	_delay_ms(5);
	
	return -1;
	
}
