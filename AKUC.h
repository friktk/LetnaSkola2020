/* 
* AKUC.h
*
* Created: 28.1.2020 14:47:50
* Author: Juraj
*/


#ifndef __AKUC_H__
#define __AKUC_H__
#include "BOARD_AVR.h"

class AKUC
{
//variables
public:
protected:
private:
	bool st;
//functions
public:
	AKUC();
	~AKUC();

	void set_AKU(int);    	// cas trubenia
	void set_AKU(bool);    	// ak true  trubi,  false nie
	bool get_AKU(void);

protected:
private:

}; //AKUC

#endif //__AKUC_H__
