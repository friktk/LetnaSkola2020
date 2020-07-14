/*
 * AVR4.cpp
 *
 * Created: 6.7.2020 11:22:27
 * Author : Juraj
 */ 

#include "BOARD_AVR.h"
#include "PrerT1_OVF.h"

int main(void)
{
 	sbi(DDRD,LED_RED);  	// cervena svieti pri stlaceni
	sbi(DDRD,LED_BLUE);
	sbi(DDRD,LED_GREEN);
	_delay_ms(500);
	  
	sbi(PORTD,LED_BLUE); 	// vsetko zhasne
	sbi(PORTD,LED_GREEN);
	sbi(PORTD,LED_RED);
		   
	PrerT1_OVF timer11;		// objekt timer11 nastavenie  konstruktore
	   
	sei();			    	// globalne povolim prerusenie
	  
	while(1) {
		if(timer11.getTim1()>30) {		// 30 * 100ms = 3s
		   timer11.setTim1(0);
			  			   
		   cbi(PORTD,LED_GREEN);		// zasvieti
		   _delay_ms(50);
		   sbi(PORTD,LED_GREEN);		// zhasne
		}
	}
}
