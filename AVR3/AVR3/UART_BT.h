/* 
* UART_BT.h
*
* Created: 3.2.2020 15:47:33
* Author: Juraj
*/


#ifndef __UART_BT_H__
#define __UART_BT_H__
#include "BOARD_AVR.h"

class UART_BT
{
//variables
public:
protected:
private:

//functions
public:
	UART_BT();
	~UART_BT();

	void Uart_init(void);

	void Uart_send_char(uint8_t x);
	uint8_t Uart_rec_char(void);

	void Uart_send_bytes(char* data, const uint8_t len);
	void Uart_send( const char* data);
	void Uart_send( long num);
	void Uart_send( unsigned long num);
	void Uart_send( int num);
	void Uart_send( unsigned int num);

protected:
private:

}; //UART_BT

#endif //__UART_BT_H__
