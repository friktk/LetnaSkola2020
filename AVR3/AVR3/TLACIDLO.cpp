/* 
* TLACIDLO.cpp
*
* Created: 29.1.2020 16:08:32
* Author: Juraj
*/

#include "TLACIDLO.h"

// default constructor
TLAC::TLAC()
{
//	tlacidlo_pointer = this; 
	cbi(DDRB,TL);		// vstup
	sbi(PORTB,TL);		// pull-up
//	Tl_stav = false;
	sbi(PORTD,LED_RED);		// zhasnutie LED
	sbi(PORTD,LED_GREEN); 
	sbi(PORTD,LED_BLUE); 
} //TLAC

// default destructor
TLAC::~TLAC()
{
	cbi(PCMSK0,PCINT0);		// zakaz prerusenia od PB0 
} //~TLAC

bool TLAC::Get_Tlacidlo()
{
	if((PINB&(1<<TL))==0)
		return true;
	return false;
}

void TLAC::Tlac_init()
{
	sbi(PCICR,PCIE0);		 //povolenie prerusenia 0-tej skupiny
	sbi(PCMSK0,PCINT0);		// povolenie prerusenia od PB0 pri kazdej zmene
}


/* TLAC* TLAC::tlacidlo_pointer;

inline void TLAC::obsluha_interruptTL(void)
{
//	tbi(PORTD,LED_RED);     //priklad2
//	_delay_ms(50);			//priklad2
	Tl_stav = true;			
}
 bool TLAC::Get_Tlacidlo_int(void){
	bool x = Tl_stav;
	Tl_stav = false;
	return x; 
	 }   */

ISR(PCINT0_vect)
{
	//TLAC::tlacidlo_pointer->obsluha_interruptTL();
	tbi(PORTD,LED_RED); 
	_delay_ms(500);
   sbi(PCIFR, PCIF0);   // vynulovanie priznaku prerusenia
}

