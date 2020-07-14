/* 
* AKUC.cpp
*
* Created: 28.1.2020 14:47:49
* Author: Juraj
*/


#include "AKUC.h"

// default constructor
AKUC::AKUC()
{
	sbi(DDRB,AKU);			//nastavenie vystupu AKU
} //AKUC

// default destructor
AKUC::~AKUC()
{
} //~AKUC

void AKUC::set_AKU(int cas){   	// cas trubenia  v ms
	st = true;
	for(int i = 0; i < cas; i++)
	{
		for(uint8_t k = 0; k < 3; k++)   // tri cykly trvaju cca. 1 ms
		{
			sbi(PORTB, AKU);
			_delay_us(161);
			cbi(PORTB, AKU);
			_delay_us(161);
		}
	}
	st = false;
};    

void AKUC::set_AKU(bool stav){   // ak true  trubi,  false nie
	st = stav;
	if(stav) 
		while(1)			// A SKUSTE TO VYPNUT  !!!
		{
			sbi(PORTB, AKU);
			_delay_us(161);
			cbi(PORTB, AKU);
			_delay_us(161);
		}
};   
	
	
bool AKUC::get_AKU(void){
	
	return st;
};
