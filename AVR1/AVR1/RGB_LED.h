/* 
* RGB_LED.h
*
* Created: 25.2.2020 12:02:59
* Author: Juraj
*/


#ifndef __RGB_LED_H__
#define __RGB_LED_H__

#include "BOARD_AVR.h"

class RGB_LED
{
//variables
public:
protected:
private:

//functions
public:
	RGB_LED();
	~RGB_LED();

void Zhasni_Vsetko_RGB(void);
void Zasviet_RGB(bool, bool, bool);

protected:

private:
//	RGB( const RGB &c );
//	RGB& operator=( const RGB &c );

}; //RGB_LED
#endif //__RGB_LED_H__
