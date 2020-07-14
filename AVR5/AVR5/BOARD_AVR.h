/*
 * BOARD_AVR.h
 *
 * Created: 24.1.2020 13:29:45
 *  Author: Juraj
 */ 


#ifndef BOARD_AVR_H_
#define BOARD_AVR_H_

#ifndef F_CPU
#define F_CPU 12000000UL	/* Define CPU clock Frequency e.g. here its 8MHz */
#endif
#include <avr/io.h>		/* Include AVR std. library file */
#include <util/delay.h>	/* Include delay header file */
#include <inttypes.h>	/* Include integer type header file */
#include <stdlib.h>		/* Include standard library file */
#include <stdio.h>		/* Include standard library file */
#include <avr/interrupt.h> 

/********Definicie uživate¾skych makier********************************/
#define sbi(x,y) x |= (1<<y)	//_BV(y)	 //nastav bit     (1<<y)
#define cbi(x,y) x &= ~(1<<y)   //(_BV(y)) //nuluj bit - using bitwise AND operator
#define tbi(x,y) x ^= _BV(y)    //zmen bit - using bitwise XOR operator

/********I2C********************************/
//#define SCL_CLK 20000L		/* Define SCL clock frequency */
//#define BITRATE	((F_CPU/SCL_CLK)-16)/2

/********LED DIODA********************************/
#define LED_BLUE  PORTD7
#define LED_GREEN PORTD2
#define LED_RED   PORTD4
//********************AKU**************************************
#define AKU  PORTB1
//********************USART**************************************
#define TXD PORTD1
#define RXD PORTD0
#define BAUDERATE	9600  //115200	//1200 
#define UBRR_VALUE ((F_CPU / (BAUDERATE * 8L)) -1)

//******************MOTOR DRIVER LEFT  *********************************
#define AIN1_D PORTD6		// IN1, IN2  PWM  0  dopredu/brzda
#define AIN2_D PORTD5		//            1  PWM  dopredu/vybeh  
#define MSLEEP_C PORTC3		// motor sleep L-SLEEP, H-run

//******************MOTOR DRIVER RIGHT  *********************************
#define BIN1_B PORTB3		// IN1, OC2A
#define BIN2_D PORTD3		// IN2, OC2B

//*******************GYRO a ACC MPU ****************************************
#define MPU_ON  PORTB2		//  L --> ON
#define MPU_SCL PORTC5
#define MPU_SDA PORTC4

//*******************OPTIKA ****************************************
#define OPT_ON PORTB1		//  L --> ON
#define O_RIGHT PORTC2			// ADC channel
#define O_LEFT  PORTC0			// ADC channel
#define O_ZAD   PORTC1			// ADC channel

#define FOTORES	6			// ADC channel

//*******************TLACIDLO ****************************************
#define TL PORTB0		//  L --> ON
//*******************TIMER1****************************************
enum delic_hodin{
	dSTOP,
	d1,
	d8,
	d64,
	d256,
	d1024,
	EXT_F,
	EXT_R
};

#endif /* BOARD_AVR_H_ */
