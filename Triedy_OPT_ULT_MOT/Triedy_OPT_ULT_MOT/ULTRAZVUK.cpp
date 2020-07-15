/* 
* Ultrazvuk_BT.cpp
*
* Created: 22.10.2019 15:29:47
* Author: Juraj
*/


#include "ULTRAZVUK.h"

// default constructor
ULTRAZVUK::ULTRAZVUK()
{
	sbi(DDRC,TRIG);		// smer vystup
	cbi(PORTC,TRIG);	//L
	cbi(PORTC,ECHO);	//off pull up
	cbi(DDRC,ECHO);    // vstup
} //Ultrazvuk_BT

// default destructor
ULTRAZVUK::~ULTRAZVUK()
{
} //~Ultrazvuk_BT

uint8_t ULTRAZVUK::Get_Distance(void)  // blba fcia stoji a caka na ECHO
 {										// vracia hodnotu v cm  ak vrati 250, 
	uint8_t pocet=0;
	cbi(PORTC, TRIG);		//pre istotu
	_delay_us(2);
	sbi(PORTC, TRIG);	// start           potom je vzdialenost > 1m 				
	_delay_us(10);
	cbi(PORTC, TRIG);
	_delay_us(20);					// 8 pulzov po 25 us plus 58 us (1 cm)

	for(uint8_t i=0; i<201; i++)    // tato odozva je 500us
	{
	if((PINC&(1<<ECHO))==(1<<ECHO)) break;   // caka kym nenaskoci ECHO ..H   delay je 200+12
	_delay_us(10);					// max 1ms 10  2ms
	if(i==200)return 245;		// ak do 2ms nepride odpoved potom chyba	
	}
	
	for(pocet=0; pocet<100; pocet++)   //70 cm   delay je 200 + 12 + 4060 = 4.272 ms
 	{
		_delay_us(58);					//58 1 cm      max 254cm   
										// test na PIND7
		if((PINC&(1<<ECHO))!=(1<<ECHO))return pocet;	// konci ECHO  L
	}
	return 255;
 }
 

	  
	 
	