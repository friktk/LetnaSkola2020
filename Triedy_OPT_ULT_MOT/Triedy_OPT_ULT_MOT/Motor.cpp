/* 
* Motor.cpp
*
* Created: 16.12.2018 11:15:23
* Author: Juraj
*/


#include "Motor.h"

MOTOR::MOTOR()
{
	//...............MOTOR LAVY............................

	cbi(PRR,PRTIM0);		// enable TIM0
	sbi(PORTC,MSLEEP_C);		//  NON SLEEP
	sbi(DDRC,MSLEEP_C);		   // vystup
	cbi(PORTD,AIN1_D);		// vysoka impedancia High impedance
	cbi(PORTD,AIN2_D);
	sbi(DDRD,AIN1_D);		// smer, vysoka impedancia kotva motor
	sbi(DDRD,AIN2_D);
	TCCR0A |= (1<<WGM00)|(1<<WGM01);  //rychla PWM, f.korektna 01
	TCCR0B |= 4;						//46875/delic 12000000/64 = 287500/256 = 732
	//...............MOTOR PRAVY............................
	cbi(PRR,PRTIM2);		// enable TIM2
	
	cbi(PORTB,BIN1_B);		// vysoka impedancia na vystupe mostika
	cbi(PORTD,BIN2_D);
	sbi(DDRB,BIN1_B);		// smer, vysoka impedancia
	sbi(DDRD,BIN2_D);
	TCCR2A |= (1<<WGM20)|(1<<WGM21);  //rychla PWM, f.korektna 01
	TCCR2B |= 4;				//46875/delic 12000000/64 = 287500/256 = 732
} //MOTOR

// default destructor
MOTOR::~MOTOR()
{
	sbi(PRR,PRTIM2);		// disable TIM2
	sbi(PRR,PRTIM0);		// disable TIM0
} //~MOTOR

void MOTOR::POHYB_B(int rychlost, motor mot){
	if(rychlost < -255) rychlost = -255;
	if(rychlost > 255) rychlost = 255;
		
	if (mot == pravy) {					//pravy  motor (1) TC2
		if(rychlost<0)					//reverz
		{
			OCR0A = -rychlost;
		
			sbi(PORTD,AIN2_D);			//AIN2 H
			
			cbi(TCCR0A,COM0B1);			//uvolnenie vystupu IN2
			cbi(TCCR0A,COM0B0);			
		
		    sbi(TCCR0A,COM0A1);			//  AIN1 set na zhodu  PWM
			sbi(TCCR0A,COM0A0);
		}
		else{
			OCR0B = rychlost;
		
			sbi(PORTD,AIN1_D);			//AIN1  H
			cbi(TCCR0A,COM0A1);			//uvolnenie AIN1
			cbi(TCCR0A,COM0A0);
			
			
			sbi(TCCR0A,COM0B1);			//AIN2 set na zhodu OC0B  stale 
			sbi(TCCR0A,COM0B0);			//<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			
		}
		
	}
	
		if (mot == lavy) {				//lavy  motor-----TC0
		
		if(rychlost<0)					//reverz
		{
			OCR2A = -rychlost;
		
		   sbi(PORTD,BIN2_D);			//BIN2 H
			cbi(TCCR2A,COM2B1);			//uvolnenie vystupu IN2
			cbi(TCCR2A,COM2B0);
			
			
			sbi(TCCR2A,COM2A1);			// BIN1 set na zhodu
			sbi(TCCR2A,COM2A0);
		}
		else{
			OCR2B = rychlost;
			
			sbi(PORTB,BIN1_B);			//BIN1 H
			cbi(TCCR2A,COM2A1);			//uvolnenie BIN1
			cbi(TCCR2A,COM2A0);
			
			sbi(TCCR2A,COM2B1);			// BIN2 set na zhodu OC2B  stale je 
			sbi(TCCR2A,COM2B0);			//<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			
		}
		
	}  
	// osetrenie chyby
};

void MOTOR::POHYB_V(int rychlost, motor mot){
		if(rychlost < -255) rychlost = -255;
		if(rychlost > 255) rychlost = 255;
		
		if (mot == pravy) {				//pravy  motor (1) TC2  BINx...T/T2  OC2A...BIN1  PB3
			if(rychlost<0)				//reverz                             OC2B...BIN2  PD3
	  {
		 		 
		 OCR2B = -rychlost;
		  cbi(PORTB,BIN1_B);			//BIN1  L
		  cbi(TCCR2A,COM2A1);			//uvolnenie vystupu BIN1
		  cbi(TCCR2A,COM2A0);			//BIN1 L
		
		sbi(TCCR2A,COM2B1);			   // BIN2 clear na zhodu  PWM
		cbi(TCCR2A,COM2B0);
		  
	  }
		else{
			OCR2A = rychlost;
			cbi(PORTD,BIN2_D);        // BIN2  L
			cbi(TCCR2A,COM2B1);			//uvolnenie vystupu BIN2
			cbi(TCCR2A,COM2B0);			//BIN2 H
			
			sbi(TCCR2A,COM2A1);			// BIN1 clear na zhodu  PWM
			cbi(TCCR2A,COM2A0);
		}
	}
	
	if (mot == lavy) {					//pravy  motor (1) TC2  BINx...T/T2  OC2A...BIN1  PB3
		if(rychlost<0)					//reverz                             OC2B...BIN2  PD3
		{
			
			OCR0B = -rychlost;
			cbi(PORTD,AIN1_D);			//AIN1  L
			cbi(TCCR0A,COM0A1);			//uvolnenie vystupu BIN1
			cbi(TCCR0A,COM0A0);			//AIN1 L
			
			sbi(TCCR0A,COM0B1);			   // AIN2 clear na zhodu  PWM
			cbi(TCCR0A,COM0B0);
			
		}
		else{
			OCR0A = rychlost;
			cbi(PORTD,AIN2_D);        // BIN2  L
			cbi(TCCR0A,COM0B1);			//uvolnenie vystupu BIN2
			cbi(TCCR0A,COM0B0);			//AIN2 L
			
			sbi(TCCR0A,COM0A1);			// AIN1 clear na zhodu  PWM
			cbi(TCCR0A,COM0A0);
		}
	  }
	
	};


void MOTOR::STOP(bool brzda, motor mot)  //brzda == true
{
	if(mot == pravy){
		if(brzda){
			
			cbi(TCCR0A,COM0A1);			//uvolnenie IN1
			cbi(TCCR0A,COM0A0);
			cbi(TCCR0A,COM0B1);			//uvolnenie IN2
			cbi(TCCR0A,COM0B0);
		
			sbi(PORTD,AIN1_D);
			sbi(PORTD,AIN2_D);
		}
		else
		
		cbi(TCCR0A,COM0A1);			//uvolnenie IN1
		cbi(TCCR0A,COM0A0);
		cbi(TCCR0A,COM0B1);			//uvolnenie IN2
		cbi(TCCR0A,COM0B0);
	    cbi(PORTD,AIN1_D);
	    cbi(PORTD,AIN2_D);
	
	}			
	//.............................Pravy motor................
	if(mot==lavy){
		if(brzda){
						
			cbi(TCCR2A,COM2A1);			//uvolnenie BIN1
			cbi(TCCR2A,COM2A0);
			cbi(TCCR2A,COM2B1);			//uvolnenie BIN2
			cbi(TCCR2A,COM2B0);
			
			sbi(PORTB,BIN1_B);
			sbi(PORTD,BIN2_D);
	
		}
		else
		
		
		cbi(TCCR2A,COM2A1);			//uvolnenie BIN1
		cbi(TCCR2A,COM2A0);
		cbi(TCCR2A,COM2B1);			//uvolnenie BIN2
		cbi(TCCR2A,COM2B0);
	   
	   cbi(PORTB,BIN1_B);
	   cbi(PORTD,BIN2_D);
	
	}								

};




