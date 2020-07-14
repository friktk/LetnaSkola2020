/*
 * AVR3.cpp
 *
 * Created: 30.6.2020 12:03:07
 * Author : Juraj
 */ 

#include "BOARD_AVR.h"
#include "UART_BT.h"
#include "TLACIDLO.h"

int main(void)
{
	UART_BT uart;
	
	uart.Uart_init();   // 9600 8N1
	uart.Uart_send("AVR_BOARD\r\n");
	
	TLAC tlac;
	tlac.Tlac_init();
	sei();
	
	while (1)
	{
		
	}
}
