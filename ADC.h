/* 
* ADC.h
*
* Created: 29.6.2020 12:03:26
* Author: Juraj
*/


#ifndef __ADC_H__
#define __ADC_H__
#include "BOARD_AVR.h"

class ADC1
{
//variables
public:
protected:
private:

//functions
public:
	ADC1();
	~ADC1();
	
	void Init_ADC(uint8_t clock, bool mode);    // clk 000 2, 001 2, 010  4,  8,  16, 32, 64, 128
												// opakovany rezim: true; jednorazov: false
	void Set_CHANNEL(uint8_t);					// vyber kanal 0-7
	void Set_REF(uint8_t);						// vyber referencne napatie
	int Get_ADC(void);							// vrat vysledok prevodu 10-bitov
	uint8_t Get_ADC8(void);						// vrat vysledok prevodu 8-bitov

protected:
private:
	
}; //ADC

#endif //__ADC_H__
