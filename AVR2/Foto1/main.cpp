/*
 * uuu.cpp
 *
 * Created: 29.1.2020 14:48:33
 * Author : Juraj
 */ 
#include "BOARD_AVR.h"
#include "RGB_LED.h"
#include "AKUC.h"
#include "TLACIDLO.h"
#include "ADC.h"

int main(void)
{
	RGB_LED r;
	ADC1 adc;

	adc.Init_ADC(4, false); // hodiny/64, jednorazovy prevod
	adc.Set_CHANNEL(6);
	adc.Set_REF(1);			// Avcc
    
	while (1) 
    {
		if(adc.Get_ADC() < 300)
			r.Zasviet_RGB(true,false,false); 
		else
			r.Zasviet_RGB(false,false,true);
		_delay_ms(100);
    }
}
