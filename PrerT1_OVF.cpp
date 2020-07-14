/*
* PrerT1_OVF.cpp
*
* Created: 6.7.2020 11:37:31
* Author: Juraj
*/


#include "PrerT1_OVF.h"

volatile uint16_t PrerT1_OVF::Timer1;

PrerT1_OVF::PrerT1_OVF()
{

}

PrerT1_OVF::~PrerT1_OVF()
{

}


/**********************metody public*************************/
uint16_t PrerT1_OVF::getTim1(void){

}

void PrerT1_OVF::setTim1(uint16_t hod){

}

void PrerT1_OVF::OverflowInterrupt1(void) // staticka funkcia, nemozeme pouzit this
{

}

ISR(TIMER1_OVF_vect){
PrerT1_OVF::OverflowInterrupt1();
}