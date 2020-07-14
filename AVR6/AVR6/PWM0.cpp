/* 
* PWM0.cpp
*
* Created: 7.7.2020 10:30:43
* Author: Juraj
*/


#include "PWM0.h"

// default constructor
PWM0::PWM0()
{
	cbi(PRR,PRTIM0);		// povolit TIM0  
	sbi(DDRD,PORTD6);		// vystup
	sbi(DDRD,PORTD5);		// vystup
	sbi(PORTD,PORTD6);		// vystup
	sbi(PORTD,PORTD5);
	
	TCCR0A = (1<<WGM00)|(1<<WGM01); // rychla PWM, f.korektna 01
	TCCR0B = 4;						// 46875/delic 12000000/64 = 287500/256 = 732

	sbi(TCCR0A,COM0A1);				// nul na zhodu  kanal A
	cbi(TCCR0A,COM0A0);
	
	sbi(TCCR0A,COM0B1);				// nul na zhodu kanal B
	cbi(TCCR0A,COM0B0);
	
} //PWM0

// default destructor
PWM0::~PWM0()
{
	sbi(PRR,PRTIM0);		// zakazat TIM0
} //~PWM0

void PWM0::Set_PWM(uint8_t x, kanal k){  // x= 0 ...255,  A, B
	switch( k ) 
	{
		case 0: OCR0A = x; break;
		case 1:	OCR0B = x; break;
		default: break;
	}
}
