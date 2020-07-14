/*
 * AVR1.cpp
 *
 * Created: 24.1.2020 13:28:50
 * Author : Juraj
 */ 

#include "BOARD_AVR.h"
#include "AKUC.h"
#include "TLACIDLO.h"
#include "RGB_LED.h"
#include "UART_BT.h"

int main(void)
{
	RGB_LED led;			// vytvorenie instancie led triedy RGB_LED konstruktor nastavi vyvody
	AKUC aku;
	TLACIDLO tl;			// tl je meno objektu
	TLACIDLO* p_tl = &tl;	//p_tl je pointer na objekt tl triedy TLACIDLO

/*
	// test UART
	UART_BT ua;		    //objekt pomenovaný ua
	UART_BT* p_U = &ua;   //pointer na objekt ua

	ua.Uart_init();        //inicializácia 8N1   9600
	ua.Uart_send("TOTO je test vysielania AVR_BOARD\n\r");

	while(1){};
*/

	while (1)      //nekonecny cyklus
	{
		// ukazka volania funkcie get_Tlac() pomocou pointra p_tl
		while(!p_tl->get_Tlac()){};   // pokial nie je stlacene stoji v tejto slucke
		led.Zhasni_Vsetko_RGB();
		led.Zasviet_RGB(true, false, false);
		
		while(!p_tl->get_Tlac()){};
		led.Zhasni_Vsetko_RGB();
		led.Zasviet_RGB(false, true, false);
		
		while(!p_tl->get_Tlac()){};
		led.Zhasni_Vsetko_RGB();
		led.Zasviet_RGB(false, false, true);
	}
}
