/* 
* Motor.h
*
* Created: 16.12.2018 11:15:23
* Author: Juraj
*/


#ifndef __MOTOR_H__
#define __MOTOR_H__
#include "BOARD_AVR.h"

class MOTOR
{
	//variables
	public:
	protected:
	private:

	//functions
	public:
	MOTOR();
	~MOTOR();
	void POHYB_B(int, motor);		// -255 az 255  1 pravy   2 lavy  pomaly utlm
	void POHYB_V(int, motor);		// -255 az 255  1 pravy   2 lavy  rychly utlm
	
	void STOP(bool brzda, motor);
	
	protected:
	private:
	//	MOTOR( const MOTOR &c );
	//	MOTOR& operator=( const MOTOR &c );

}; //MOTOR
#endif //__MOTOR_H__
