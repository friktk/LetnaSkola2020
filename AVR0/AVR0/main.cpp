/*
 * AVR0.cpp
 *
 * Created: 21.2.2020 11:18:12
 * Author : Juraj
 */ 

#include "BOARD_AVR.h"
#include "RGB_LED.h"

int main(void)
{
  
	RGB_LED led;        // vytvorenie instancie led triedy RGB_LED, konstruktor nastavi vyvody

	//nekonecny cyklus
	while(1)
    {
		
		led.Zasviet_RGB(true, false, false);
		_delay_ms(500);
		led.Zhasni_Vsetko_RGB();
		led.Zasviet_RGB(false, true, false);
		_delay_ms(500);
		led.Zhasni_Vsetko_RGB();
		led.Zasviet_RGB(false, false, true);
		_delay_ms(500);
		led.Zhasni_Vsetko_RGB();
		
    }
	
	return(0);			//len pre poriadok
}

