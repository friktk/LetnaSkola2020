/* 
* TLACIDLO.cpp
*
* Created: 29.1.2020 9:16:55
* Author: Juraj
*/

#include "TLACIDLO.h"

// default constructor
TLACIDLO::TLACIDLO()
{
	cbi(DDRB,TL);   //nastavenie smeru
	sbi(PORTB,TL);	//pull/up odpor
} //TLACIDLO

// default destructor
TLACIDLO::~TLACIDLO()
{
} //~TLACIDLO

 bool TLACIDLO::get_Tlac(void)
{
	bool stav;
	stav = false;
	while((PINB&(1<<TL)) != (1<<TL)){};   // caka pokial tlacidlo nie je pustene 
	_delay_ms(5);
	
	if( (PINB&(1<<TL)) != (1<<TL))		// Test stlacenia
		stav = true;  
	return stav;	
}
