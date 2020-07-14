/*
* PrerT1_OVF.h
*
* Created: 6.7.2020 11:37:31
* Author: Juraj
*/

#ifndef __PRERT1_OVF_H__
#define __PRERT1_OVF_H__

#include "BOARD_AVR.h"

#define STRINGIFY(name) #name

#define CLASS_IRQ(name, vektor) \
static void name(void) asm(STRINGIFY(vektor)) \
__attribute__((signal, __INTR_ATTRS))

#define TIMER1_TIMEOUT 64364; // T_T = 65534 - //cas[s]/[(1/FCPU)*delic_hodin]; 16-bit
// 100ms: 65536 - 0.1/(0.000000083*d1024) = 64364;

/***************************************************/
#define STRINGIFY(name) #name

#define CLASS_IRQ(name, vektor) \
static void name(void) asm(STRINGIFY(vektor)) \
__attribute__((signal, __INTR_ATTRS))

class PrerT1_OVF
{
//variables
public:
protected:
private:
volatile static uint16_t Timer1; //volatile
//functions
public:
PrerT1_OVF();
~PrerT1_OVF();
uint16_t getTim1(void);
void setTim1(uint16_t);
static void OverflowInterrupt1(void);
private:
// CLASS_IRQ(OverflowInterrupt1, TIMER1_OVF_vect);

}; //PrerT1_OVF

#endif //__PRERT1_OVF_H__