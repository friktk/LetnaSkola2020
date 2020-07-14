/*
 * AVR6.cpp
 *
 * Created: 7.7.2020 10:28:59
 * Author : Juraj
 */ 

#include "BOARD_AVR.h"
#include "PWM0.h"

int main(void)
{
    PWM0 pwm0;
	pwm0.Set_PWM(128, A);
    while (1) 
    {
    }
}

