/* 
* Opt_BT.h
*
* Created: 1.1.2019 12:34:00
* Author: Juraj
*/


#ifndef __OPT_BT_H__
#define __OPT_BT_H__
#include "BOARD_AVR.h"
#include "ADC.h"

class OPT_BT:ADC1
{
//variables
public:
protected:
private:

//functions
public:
	OPT_BT();
	~OPT_BT();
 
 int Get_Treshold(optika);     // Setup of Sensors (true right false left)
 int Get_val_Opt(optika);	// Get Value of Optical Sensor  (arg.: )


protected:
private:
void ON_Opt(void);
void OFF_Opt(void);


}; 

#endif //__OPT_BT_H__
