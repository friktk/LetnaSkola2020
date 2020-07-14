/* 
* ADC.cpp
*
* Created: 29.6.2020 12:03:25
* Author: Juraj
*/

#include "ADC.h"

  ADC1::ADC1()
{
	PRR &=~(1<<PRADC);			// povoli ADC
} //ADC1

// default destructor
ADC1::~ADC1()
{
	PRR |=(1<<PRADC);			// zakaze ADC
} //~ADC1

void ADC1::Init_ADC(uint8_t hod, bool rezim){   // false - progr.start
	hod=hod&0x7;
	ADCSRA =0b10000000|hod;		// ADEN, ADSC, ADATE, ADIF, ADIE,ADPS2,1,0
	if(rezim) ADCSRA |=0x20;    // ADATE: autotriger;
}

void ADC1::Set_CHANNEL(uint8_t kanal){	// kanal 0- F
	kanal &= 0x0F;
	ADMUX &= 0xF0;
	ADMUX |= kanal;				// AVCC  010... 10bit  0110... 8bit - ADLAR=1
};								// REFS0, REFS1, ADLAR, RES, MUX....

void ADC1::Set_REF(uint8_t ref) // REFS0; REFS1;: 0..00 ext ref, 1..01 AVcc, 2..10 res, 3..11 intref 1.1V
{
	ref=ref & 0b00000011;		// maska
	ADMUX &= 0b00111111;
	ADMUX |= (ref<<6);
};

int ADC1::Get_ADC(void){
	ADMUX &=~(1<<ADLAR);		// ADLAR=0   0b11011111;
	ADCSRA |= (1<<ADSC);		// start
	while((ADCSRA & (1<<ADIF))!=(1<<ADIF)){}; // caka na koniec prevodu
	int prev = ADCL;
	prev |=ADCH<<8;
	ADCSRA |=(1<<ADIF);			// alternativa k vynulovaniu ADIF
	return prev;
};

uint8_t ADC1::Get_ADC8(void){
	ADMUX |=(1<<ADLAR);  		// ADLAR=1
	ADCSRA |= (1<<ADSC);		// start
	while((ADCSRA & (1<<ADIF))!=(1<<ADIF)){}; // caka na koniec prevodu
	uint8_t ppom=ADCH;
	ADCSRA |=(1<<ADIF);   		// alternativa k vynulovaniu ADIF
	return ppom;
};
