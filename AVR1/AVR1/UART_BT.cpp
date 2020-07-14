/* 
* UART_BT.cpp
*
* Created: 3.2.2020 15:47:31
* Author: Juraj
*/

#include "UART_BT.h"

UART_BT::UART_BT(){		// Constructor
	PRR &= ~(1<<PRUSART0);
};

UART_BT::~UART_BT(){		// Destruktor
	PRR |= (1<<PRUSART0);
};

void UART_BT::Uart_init(void)
{
	DDRD |=(1<<PORTD1);					// Tx output
	DDRD &=~(1<<PORTD0);				// Rx input
	UBRR0H = (uint8_t)(UBRR_VALUE>>8);	// BAUDERATE  v Board_Solara.h
	UBRR0L = (uint8_t)UBRR_VALUE;
	UCSR0C |= (1<<UCSZ01)|(1<<UCSZ00);  //8 bits, parit non, 1 stop
	UCSR0B |= (1<<RXEN0)|(1<<TXEN0);	// enable rx a tx
	UCSR0A |= (1<<U2X0);
};

void UART_BT::Uart_send_char(uint8_t x)
{
	while(!(UCSR0A& (1<<UDRE0))){};    // caka na uvolnenie UDR
	UDR0 = x;
};

uint8_t UART_BT::Uart_rec_char(void)
{
	while(!(UCSR0A& (1<<RXC0))){};  //return '0';  // pozor uprava: necaka na prijem
	return UDR0;
};


void UART_BT::Uart_send_bytes(char* data, const uint8_t len)
{
	for(uint8_t i=0; i < len; i++) this->Uart_send_char(*(data++));
};

void UART_BT::Uart_send( const char* data) {
	for ( const char* s = data; *s; ++s) {
		this->Uart_send_char( *s);
	}
};

void UART_BT::Uart_send( long num) {
	if ( num < 0) {
		this->Uart_send_char( '-');
		num = -num;
	}
	this->Uart_send( ( unsigned long) num);
};

void UART_BT::Uart_send( unsigned long num) {
	// max pocet signed/unsigned long je 10
	char digits[10];
	uint8_t len = 0;
	do {
		digits[len] = '0' + ( num % 10);
		len++;
	} while ( num /= 10);
	while ( len > 0) {
		this->Uart_send_char( digits[--len]);
	}
};

void UART_BT::Uart_send( int num) {
	this->Uart_send((long) num);
};

void UART_BT::Uart_send( unsigned int num) {
	this->Uart_send(( unsigned long) num);
};

