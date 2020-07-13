**Projekt AVR1**

Pri bližšom pohľade na modul AVR-board vidíme, že na doske sú umiestnené dve tlačidlá. Jedno s označením RST slúži na reštartovanie MCU, druhé s označením USR budeme využívať na modifikáciu behu programu, vetvenie a podobne. Z tohto dôvodu musíme byť schopní v priebehu výkonu programu identifikovať, či došlo ku stlačeniu tlačidla. Zapojenie tlačidla USR je uvedené na obrázku. Vidíme, že pri stlačení tlačidla na vývode PB0 sa objaví potenciál rovný GND, to je zjednodušene úroveň L. Ako bolo spomenuté vyššie táto úroveň zodpovedá logickej hodnote 0. Aká úroveň napätia bude na vývode PB0 v prípade, že tlačidlo nebude stlačené? Pokiaľ nezapneme príslušný pull-up odpor, tak na túto otázku nedokážeme jednoznačne odpovedať, prípadne ak stačí takáto odpoveď, tak tam bude tzv. neurčitá úroveň. MCU nedokáže jednoznačne interpretovať úroveň na príslušnom vstupe. Preto je potrebné v uvedenej aplikácii zapnúť pull-up odpor na vývode PB0 zapísaním log.1 do bitu PORTB0. Teraz, ak PB0 je v režime vstup (DDRB7 obsahuje log.0) je pri nestlačenom tlačidle na PB0 úroveň H. V prípade, že stlačíme tlačidlo na PB0 sa objaví úroveň L. 

![img](images/schema_pr3.jpg#75size)

Keď už je funkcia tlačidla a jeho správania zrejmá, pristúpme k doplneniu predchádzajúceho projektu o triedu `TLACIDLO`. Postup je identický ako v prípade triedy `AKUC`, preto ho nebudeme komentovať. Po pridaní triedy `TLACIDLO` dostaneme dva súbory jeden s názvom `TLACIDLO.h` a druhý `TLACIDLO.cpp`

> Štrukrúra projektu
>
> ```bash
>     .
>     ├── AKUC.cpp
>     ├── AKUC.h
>     ├── BOARD_AVR.h
>     ├── main.cpp
>     ├── RGB_LED.cpp
>     ├── RGB_LED.h
>     ├── TLACIDLO.cpp # nové súbory
>     └── TLACIDLO.h   # nové súbory
> ```



Hlavičkový súbor `TLACIDLO.h` je jednoduchý:

``` c++
define __TLACIDLO_H__
#include "BOARD_AVR.h"

class TLACIDLO
{
//variables
public:
protected:
private:

//functions
public:
	TLACIDLO();
	~TLACIDLO();
	bool get_Tlac( void); # Funkcia nemá argument a vracia okamžitý stav tlačidla  
protected:
private:

}; //TLACIDLO

#endif //__TLACIDLO_H__
```

Okrem konštruktora a deštruktora hlavičkový súbor obsahuje jedinú funkciu triedy TLACIDLO, `bool get_Tlac( void)`. Funkcia nemá argument a vracia okamžitý stav tlačidla. 

 Súbor `TLACIDLO.cpp` obsahuje definície konštruktora a jednej funkcie `get_Tlac()`:

```c++
#include "TLACIDLO.h"

// default constructor
TLACIDLO::TLACIDLO()
{
	sbi(PORTB,TL);      // zopnutie pull-up odporu
	cbi(DDRB,TL);		// urcenie smeru vyvodu PB0,  vstup.
} //TLACIDLO

// default destructor
TLACIDLO::~TLACIDLO()
{
} //~TLACIDLO

bool TLACIDLO::get_Tlac( void){
	bool stav;
	stav = false;
	if( (PINB & (1<<TL)) != (1<<TL) )stav = true; // Test stlacenia
	return stav;	
}
```

!!! note "Logické a bitové (bitwise) operácie v jazyku C++"
	 Je namieste pripomenúť logické a bitové (bitwise) operácie v jazyku C++. Symboly bitových operácií medzi jednotlivými bitmi slova sú označené jednoduchými znakmi. 
	
	- and: `&`, or:`|`,  XOR: `^`
	- posun doľava: `<<`, posun doprava: `>>`
	- bitová negácia `~`. 
	
	Logické operácie sú s výnimkou negácie označené dvojicou rovnakých po sebe idúcich symbolov: 
	
	- and: `&&`,  or: `||`, negácia: `!`. 
	
	V teste stlačenia je použitá bitová operácia medzi obsahom 8-bitového „registra” PINB a 8-bitovou hodnotou `(1<<TL)`. (Ak v BOARD_AVR.h a avr/io.h je definované, že TL = 0, potom `(1<<TL) = 1`, v binárnom vyjadrení 0b00000001 ). 

Teraz napíšme program, ktorý zabezpečí nasledujúce správanie modulu: po pripojení na napájacie napätie nebude svietiť žiadna dióda a bzučiak bude ticho. Po stlačení tlačidla USR nech sa na 1s zasvieti červená dióda a súčasne sa na sekundu spustí bzučiak. Potom sa čaká na ďalšie stlačenie. Uvádzame výpis programu „main()“, ktorý by s využitím známych tried mal zabezpečiť popísané správanie. Upozorňujeme, že uvedený kód nevyhovuje zadaniu. Čo je potrebné upraviť?

``` c++
#include "AKUC.h"
#include "RGB_LED.h"
#include "TLACIDLO.h"

int main(void)
{
	RGB_LED led;	// vytvorenie instancie led triedy 
                    //RGB_LED konstruktor nastavi vyvody
	AKUC aku;
	TLACIDLO tl;			// tl je meno objektu
	TLACIDLO* p_tl = &tl; 	//p_tl je pointer na objekt tl triedy TLACIDLO
			
	while (1)      	//nekonecny cyklus
	{						
	
		// ukazka volania funkcie get_Tlac() pomocou pointra p_tl
		while(!p_tl->get_Tlac()){}; //pokial nie je stlac. stoji v tejto slucke 
	
		led.Zasviet_RGB(true, false, false);
		_delay_ms(1000);	//ako dlho bude svietit LED? Co sa stane ak vynecham 
							//delay?
		aku.set_AKU(1000);
		led.Zhasni_Vsetko_RGB();
	
	}
		
	return 0;			
	
}
```

Všimnime si, že pri volaní funkcie `get_tlac()` je použité volanie prostredníctvom ukazovateľa (pointra) `p_tl` na objekt `tl`. Je zrejmé, že volať metódu triedy môžeme na základe jej mena. `tl.get_Tlac()`  alebo pointra `p_tl->get_Tlac()`.

Pokúste sa program modifikovať tak, aby po každom stlačení svietila iná farba. Farby nech svietia v poradí (červená, zelená, modrá, červená, zelená ....) a tak ďalej.

``` c++
int main(void)
{
	RGB_LED led; // vytvorenie instancie led triedy RGB_LED konstruktor nastavi vyvody
	AKUC aku;
	TLACIDLO tl;		  // tl je meno objektu
	TLACIDLO *p_tl = &tl; //p_tl je pointer na objekt tl triedy TLACIDLO

	while (1) //nekonecny cyklus
	{
		// ukazka volania funkcie get_Tlac() pomocou pointra p_tl
		while (!p_tl->get_Tlac())
		{
		}; // pokial nie je stlacene stoji v tejto slucke
		led.Zhasni_Vsetko_RGB();
		led.Zasviet_RGB(true, false, false);

		while (!p_tl->get_Tlac())
		{
		};
		led.Zhasni_Vsetko_RGB();
		led.Zasviet_RGB(false, true, false);

		while (!p_tl->get_Tlac())
		{
		};
		led.Zhasni_Vsetko_RGB();
		led.Zasviet_RGB(false, false, true);
	}

	return 0;
}
```

Prečo to teraz uspokojivo nefunguje? Poznajme, že vysvetlenie súvisí už s hardvérom. Ak stlačíte tlačidlo, podržíte ho stlačené určitý čas. Počas tohto času sa vonkajší cyklus samozrejme mnohokrát zopakuje. Ako dôkaz si pozrite, že počas stlačenia tlačidla svietia všetky tri farby diódy. Ak tlačidlo pustíte ostane svietiť náhodná farba. Je zrejmé, že táto farba súvisí s okamihom, v ktorom tlačidlo pustíte. Aby bola situácia ešte zložitejšia pripomeňme, že tlačidlo je elektromechanický prvok, ktorý pri stlačení, alebo pustení môže generovať veľké množstvo zákmitov. Na vývode PB0 sa pri stlačení a pustení tlačidla objaví signál podľa obrázku. Navrhnite úpravu predchádzajúceho programu takú aby sa farba diódy menila v súlade so zadaním.

![img](images/zakmit.jpg#75size)

!!! tip
	Na mierne potlačenie uvedeného javu slúži kondenzátor C7. Nie všetky zákmity sa mu podarí eliminovať. Len pre fanúšikov elektroniky: kondenzátor C7 spolu s interným pull-up odporom vytvára akýsi filtračný obvod na eliminovanie krátkych  impulzov na vývode PB0. Časová konštanta filtračného obvodu je približne daná súčinom RC. Dosadením hodnôt pull-up odporu a kondenzátora dostávame časovú konštantu: $RC = 50.10^{ 3}.10^{-7}  = 5 ms$. Impulzy pod 1 ms by mali byť spoľahlivo odfiltrované. Stačí to, vybrané tlačidlo negeneruje dlhšie impulzy? O tom sa presvedčíme experimentálne. 

Jedna z možných úprav kódu funkcie `get_Tlac()` je uvedená nižšie. Poznamenajme, že oneskorenie `_delay_ms(5)` je použité na ošetrenie tých spomínaných zákmitov tlačidla. Predpokladáme, že prechodový proces (prechod medzi stlačením a pustením tlačidla) netrvá dlhšie ako 5 ms.

> Súbor TLACIDLO.cpp
>
> ``` c++
> bool TLACIDLO::get_Tlac(void)
> {
> 	bool stav;
> 	stav = false;
> 	while ((PINB & (1 << TL)) != (1 << TL))
> 	{
> 	}; // caka pokial tlacidlo nie je
> 	   //pustene
> 	_delay_ms(5);
> 
> 	if ((PINB & (1 << TL)) != (1 << TL))
> 		stav = true; // testuje ci tlacidlo bolo
> 					 //stlacene
> 
> 	return stav;
> }
> 
> ```

Všimnime si, že celý výpočtový výkon procesora je spotrebovaný na testovanie tlačidla. Ako to urobiť efektívnejšie? Aj na riešenie tohoto rébusu neskôr použijeme prerušovací systém.