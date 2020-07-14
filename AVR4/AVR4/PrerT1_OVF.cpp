/* 
* PrerT1_OVF.cpp
*
* Created: 6.7.2020 11:37:31
* Author: Juraj
*/


#include "PrerT1_OVF.h"

PrerT1_OVF::PrerT1_OVF()
{
	PRR &=~(1<<PRTIM1);			// zapneme TIM0 napriek tomu, ze je def. zapnute
	
	uint8_t sreg = SREG;
	cli();						// atomicka operacia
	TCNT1 = TIMER1_TIMEOUT;
	SREG = sreg;
	TCCR1B |= d1024;			// nastavenie preddelicky clkio
	TIMSK1 |= (1<<TOIE1);		// povolenie prerusenia
	this->Timer1 = TIMER1_TIMEOUT;
}

PrerT1_OVF::~PrerT1_OVF()
{
	TIMSK1 &=~(1<<TOIE1);		// zakazanie prerusenia
	//	PRR |=(1<<PRTIM1);		// vypneme TIM0 ak chceme setrit, ale pozor nepojde nic
}


class PrerT1_OVF Timer01;
/**********************metody public*************************/
uint16_t PrerT1_OVF::getTim1(void){
	return Timer01.Timer1;
};

void  PrerT1_OVF::setTim1(uint16_t hod){
	Timer01.Timer1 = hod;
};


void PrerT1_OVF::OverflowInterrupt1(void) 	// staticka funkcia, nemozeme pouzit this
{
	// atomicka operacia
	cli();		// ak som sa ocitol tu, tak muselo byt glob. povolene prerusenie
	TCNT1 = TIMER1_TIMEOUT;		//restart
	sei();
	Timer01.Timer1++;
	// kod obsluhy
	// 	if(Timer01.Timer1>30)
	//	{	tbi(PORTD,G_LED); 
	//		Timer01.Timer1 = 0; 
	//	}
};
