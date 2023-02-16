/*
 * App.c
 *
 * Created: 1/25/2023 4:48:56 PM
 *  Author: Ahmed
 */ 
#include "lcd.h"
#include "std_macro.h"
#include <math.h>
void main(){
	int32_t result,power,c;
	int32_t r[4];
	int8_t  err=0,op,var,y,e=0,x,p,irr=0;

	int8_t n[10];
	LCD_INIT();
	KEYPAD_INIT();
	
while(1){
	
	
	for(x=1  ,  n[0]='0'  ;  ( n[x-1]>='0' ) && (n[x-1]) <= '9'  ;   x++ ){
		
		
		for ( n[x]=-1 ;   n[x]<0   ;    ) {
			
			n[x]=KEYPAD_READ() ;
			
		}
		if(n[x-1]=='=') break;
		_delay_ms(200);
		LCD_write_char(n[x]);
     
	}

	if(  (n[1]<'0') ) err=1;
	
	
	
	if(n[x-1]=='=')  e=1; else op=n[x-1];
	 
	  
	x=x-3;
	
	for (p=0 ,power=1 ;p<x;p++) power=power*10;
	x=x+1;

	for(c=1,r[irr]=0 ; c<=power; c=c*10,x--){
			
		r[irr]=r[irr] + ( (n[x])-'0' ) * c;
		
	}
	irr++;
	if (e==1) {
		irr--;
	
	
		LCD_write_command(0x01);
		if(err>0){ LCD_write_string("Error");}
			else{
		switch(op){
			
			case '+' : for(result=0; irr>=0;irr--){ result=result+r[irr]; }  LCD_write_number(   result     );
			break;
			
			case '-' : LCD_write_number(r[irr-1]-r[irr]);
			break;
			
			case '*' : for(result=1; irr>=0;irr--){ result=result*r[irr]; }  LCD_write_number(   result     );
			break;
			
			case '/' : LCD_write_number(r[irr-1]/r[irr]);
			break;
		}
			}
		e=0;
		err=0;
		result=0;
		for ( var=-1 ;   var<0   ;    ) {
			
			var=KEYPAD_READ() ;
			
		}
		LCD_write_command(0x01);
		irr=0;
			
		}
	
	
	_delay_ms(500);
	
}
		
	

}















		