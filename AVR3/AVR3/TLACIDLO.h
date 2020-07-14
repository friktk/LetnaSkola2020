/* 
* TLACIDLO.h
*
* Created: 29.1.2020 16:08:33
* Author: Juraj
*/


#ifndef __TLACIDLO_H__
#define __TLACIDLO_H__
#include "BOARD_AVR.h"
#include "RGB_LED.h"

//extern bool Tl_stav;

class TLAC: RGB_LED
{
//variables
public:
protected:
private:
//static bool Tl_stav;
//functions
public:
	TLAC();
	~TLAC();
    bool Get_Tlacidlo(void);
	
//	 bool Get_Tlacidlo_int(void);
//static TLAC* tlacidlo_pointer;

//static inline void obsluha_interruptTL(void);
void Tlac_init(void);

protected:
private:
	
}; //TLACIDLO

#endif //__TLACIDLO_H__
