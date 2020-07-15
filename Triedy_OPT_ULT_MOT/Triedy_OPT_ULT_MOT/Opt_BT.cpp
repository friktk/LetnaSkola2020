/* 
* Opt_Solara.cpp
*
* Created: 1.1.2019 12:34:00
* Author: Juraj
*/


#include "Opt_BT.h"

// default constructor
OPT_BT::OPT_BT()
{
	sbi(PORTB,AKU_OPTON);
	sbi(DDRB,AKU_OPTON);		// Smer
} //

// default destructor
OPT_BT::~OPT_BT()
{
} //~Opt_BT

void OPT_BT::ON_Opt(void){
		cbi(PORTB,AKU_OPTON);		// ON
	_delay_ms(2);    //T = 220 * 2.2 = 484 us 
	};
void OPT_BT::OFF_Opt(void){
	
	sbi(PORTB,AKU_OPTON);		// OFF
	};
/***************************************Treshold*************/	
int OPT_BT::Get_Treshold(optika o){	// Get Value of Optical Sensor  (true right false left)
	int pr1,pr2;
	sbi(PORTB,TL);				//pull-up
	cbi(DDRB,TL);				//input  button S2
	
	/**********************************************WHITE*************/
	//while((PINB&(1<<TL))!=0);
	
	this->ON_Opt();
	
	this->Init_ADC(4, false);			//divider 16, one conversion
	this->Set_REF(1);			// AVcc
	this->Set_CHANNEL(o);
	
	pr1 = this->Get_ADC();    //ADC_BT::Get_ADC();
	pr1 = pr1 + this->Get_ADC();   
	this->OFF_Opt();
	//_delay_ms(500);				// only for visibility
	/******************************************************BLACK*********/
	
//	while((PINB&(1<<TL))!=0);
	
	this->ON_Opt();
	pr2 = this->Get_ADC();    //ADC1::
	pr2 = pr2 + this->Get_ADC();   //ADC1::
	this->OFF_Opt();
	pr1=pr1+pr2;
	pr1=pr1>>2;					// pr1/4	
	return pr1;
 };
 
 // Get Value of Optical Sensor 
 int OPT_BT::Get_val_Opt(optika o){	
	this->ON_Opt();
	this->Init_ADC(4, false);			// delic hodin: 16, one conversion 
	this->Set_REF(1);					// AVcc
	this->Set_CHANNEL(o);
	int pr1 = this->Get_ADC();     //ADC1::
	this->OFF_Opt();
	return pr1;
  };
 