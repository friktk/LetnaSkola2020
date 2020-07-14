/* 
* PWM0.h
*
* Created: 7.7.2020 10:30:44
* Author: Juraj
*/


#ifndef __PWM0_H__
#define __PWM0_H__
#include "BOARD_AVR.h"

class PWM0
{
//variables
public:
protected:
private:

//functions
public:
	PWM0();
	~PWM0();
	
	void Set_PWM(uint8_t, kanal); //hodnota od 0 do 255, kanal 1...A, 2 
protected:

}; //PWM0

#endif //__PWM0_H__
