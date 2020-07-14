/*
 * AVR5.cpp
 *
 * Created: 6.7.2020 15:56:01
 * Author : Juraj
 */ 

#include "BOARD_AVR.h"

int main(void)
{
	sbi(DDRD,LED_RED);			// smer
	sbi(PORTD,LED_RED);			// zhasne
   
	for(uint16_t i = 0; i<256; ++i)
	{
		cbi(PORTD,LED_RED);		// zasviet
		for(uint16_t k = 0; k<i; k++)
			_delay_us(153);		// cakaj i.153
	 
		sbi(PORTD,LED_RED);		// zhasni 
		for(uint16_t l = 0; l<(255-i); l++) 
			_delay_us(153);		// cakaj (256-i)i.153
	}
   
	while (1) 
    {
    }

	return 0;
}
