/*
 * Foto2.cpp
 *
 * Created: 29.6.2020 15:57:16
 * Author : Juraj
 */ 

#include "..\Foto1\BOARD_AVR.h"
#include "..\Foto1\RGB_LED.h"
#include "..\Foto1\RGB_LED.cpp"
#include "..\Foto1\AKUC.h"
#include "..\Foto1\AKUC.cpp"
#include "..\Foto1\TLACIDLO.h"
#include "..\Foto1\TLACIDLO.cpp"
#include "..\Foto1\ADC.h"
#include "..\Foto1\ADC.cpp"
#include "UART_BT.h"

int main(void)
{
  	RGB_LED r;
	AKUC a;
	TLACIDLO t;
	UART_BT uart;
	   
	uart.Uart_init();   //115200, 8N1
	uart.Uart_send("Tets fotoodpora\n\r");
	   
	r.Zhasni_Vsetko_RGB();
	
	ADC1 adc;
	adc.Init_ADC(4, false);  //hodiny/64	 jednorazovy prevod
	adc.Set_CHANNEL(6);
	adc.Set_REF(1);		// Avcc
	 	   
   while (1)
   {
		uart.Uart_send(adc.Get_ADC());
	    uart.Uart_send("\r");
		  
		if(adc.Get_ADC() < 300)
			r.Zasviet_RGB(true,false,false); 
		else
		   r.Zasviet_RGB(false,false,true);
		_delay_ms(1000);
   }
}
