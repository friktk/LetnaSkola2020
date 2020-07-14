/* 
* RGB_LED.cpp
*
* Created: 25.2.2020 12:02:58
* Author: Juraj
*/


#include "RGB_LED.h"

// default constructor
RGB_LED::RGB_LED()
{
	sbi(DDRD,LED_RED);   //DDRD
	sbi(DDRD,LED_GREEN);
	sbi(DDRD,LED_BLUE);
} //RGB_LED

// default destructor
RGB_LED::~RGB_LED()
{
} //~RGB_LED


void RGB_LED::Zhasni_Vsetko_RGB()
{
	sbi(PORTD,LED_RED);
	sbi(PORTD,LED_GREEN);
	sbi(PORTD,LED_BLUE);
}

void RGB_LED::Zasviet_RGB(bool r, bool g, bool b)
{
	this->Zhasni_Vsetko_RGB();
	if(r==true) cbi(PORTD,LED_RED);
	if(g==true) cbi(PORTD,LED_GREEN);
	if(b==true) cbi(PORTD,LED_BLUE);
}