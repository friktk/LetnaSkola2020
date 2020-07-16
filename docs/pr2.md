**Projekt AVR1**

Nasledujúci projekt sa venuje ovládaniu akustického návestia. Všimnite si, že na doske plošných spojov modulu AVR-board je aj akustické návestie, ktoré umožňuje generovať zvukový signál. Elektromagnetický bzučiak umožňuje generovať akustický signál s frekvenciou 3.1 kHz. Samozrejme je potrebné bzučiak budiť najvhodnejšie harmonickým signálom s frekvenciou 3.1 kHz. 

![img](images/sche_pr2.png#75size)

V našom prípade si úlohu zjednodušíme a bzučiak budeme budiť obdĺžnikovým signálom. Zapojenie je uvedené na obrázku. Poznamenávam, že ak budeme používať popísaný bzučiak bude potrebné prepojku SJ1 spojiť (preletovaním). Nemusíme sa obávať, že tranzistor T1 môže pri nevhodnom nastavení vývodu PB0 ostať otvorený čo by spôsobilo trvalý prúd cievkou elektromagnetického bzučiaka. Hodnota odporu cievky je 20 ohmov. Pri napájaní 3.3V by pretekajúci prúd cievkou bol približne 165 mA. Kondenzátor C8 však zabraňuje trvalému otvoreniu tranzistora. Dióda D1 zabezpečuje vybitie elektromagnetickej energie nahromadenej v cievke pri rozopnutí T1

Ako už bolo spomenuté, na to, aby zaznel akustický tón, musíme na vývode PB0 generovať budiaci obdĺžnikový signál. Pripomeňme, že vývod PB0 musí byť v režime výstup. Budiaci signál má mať priebeh znázornený na obrázku. Budiaci signál $u_{b}(t)$ je periodický obdĺžnikový signál s frekvenciou $\frac{106}{322}=3105 [μs, μs, Hz]$. Pokiaľ bude takýto signál generovaný na vývod PB0, bude bzučiak generovať zodpovedajúci tón. Akonáhle ho procesor prestane generovať, bzučiak stíchne. 

![img](images/signal.jpg#50size)

Poďme predchádzajúci projekt rozšíriť o triedu `AKUC`, ktorá bude obsahovať funkcie pre ovládanie bzučiaka. Pôvodne bola trieda nazvaná `AKU`, pretože ale tento názov už bol rezervovaný pre vývod PB1v hlavičkovom súbore AVR-board.h premenovali sme ju na `AKUC` (AKU Class). Postup tvorby novej triedy je už známy a bol popísaný v predchádzajúcom texte. Doplníme projekt o triedu, ktorá sa bude nazývať `AKUC`. IDP automaticky vygeneruje šablónu hlavičkového súboru `AKUC.h` a súboru `AKUC.cpp`.

> Štrukrúra projektu
>
> ```bash
>  .
>  ├── AKUC.cpp #nová trieda
>  ├── AKUC.h   #nový hlavičkový súbor	 	
>  ├── BOARD_AVR.h
>  ├── main.cpp
>  ├── RGB_LED.cpp
>  └── RGB_LED.h
> ```

``` c++
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
	
	void set_AKU(int);    // cas trubenia
	void set_AKU(bool);    // ak true  trubi,  false nie
	bool get_AKU(void);

protected:
private:

}; //AKUC

#endif //__AKUC_H__
```

Vidíme, že v hlavičkovom súbore je deklarovaná len jedna trieda „AKUC“. Používa jednu privátnu boolovskú premennú „st“, v ktorej je zaznamenaný aktuálny stav (trúbi/netrúbi). Ďalej obsahuje konštruktor „AKUC()“, deštruktor „~AKUC()” a tri verejne prístupné funkcie:

- `void set_AKU(int)`, funkcia slúži na generovanie budiaceho signálu pre bzučiak. Parameter funkcie typu „int“ („cas“) definuje čas, počas ktorého bude bzučiak trúbiť. Hodnota sa zadáva v milisekundách. -
- `void set_AKU(bool)`, funkcia slúži tiež na generovanie budiaceho signálu pre bzučiak. Všimnite si, že sa volá rovnako, ako predchádzajúca. V závislosti od typu parametra „int/bool“ sa použije tá funkcia, ktorej zodpovedá typ parametra: set_AKU(200) volá prvú funkciu a set_AKU(true) volá druhú funkciu. Výber jednej z viacerých funkcií na základe argumentov pri volaní funkcie sa často označuje ako „preťaženie funkcií“. 
- `bool get_AKU(void)`, funkcia slúži na zistenie stavu bzučiaka (trúbi/netrúbi = true/false). Je to funkcia bez argumentu a vracia hodnotu bool.

Uvedené funkcie sú definované v súbore `AKUC.cpp`.

``` c++
#include "AKUC.h"

// default constructor
AKUC::AKUC()
{
	sbi(DDRB, AKU); //nastavenie vystupu AKU
	st = false;
}

// default destructor
AKUC::~AKUC()
{
}

void AKUC::set_AKU(int cas)
{ // cas trubenia v ms
	st = true;
	for (int i = 0; i < cas; i++)
		for (uint8_t k = 0; k < 3; k++) // tri cykly trvaju cca. 1 ms
		{
			sbi(PORTB, AKU);
			_delay_us(161);
			cbi(PORTB, AKU);
			_delay_us(161);
		}
	st = false;
}

void AKUC::set_AKU(bool stav)
{ // ak true trubi, false nie
	st = stav;
	if (stav)
		while (1) // A SKUSTE TO VYPNUT !!!
		{
			sbi(PORTB, AKU);
			_delay_us(161);
			cbi(PORTB, AKU);
			_delay_us(161);
		}
}

bool AKUC::get_AKU(void)
{
	return st;
}
```

V tomto súbore `AKUC.cpp` je definované správanie sa jednotlivých funkcií, ktoré boli deklarované v hlavičkovom súbore triedy AKUC. 

- Konštruktor `AKUC()` – jeho názov musí byť rovnaký ako názov triedy. V ňom sa vykonávajú činnosti súvisiace s alokáciou zdrojov a nastavením počiatočných parametrov. V našom prípade nastavujeme príslušný vývod kontroléra „PB1“ a definujeme počiatočnú hodnotu internej premennej „st“. 
- Deštruktor `~AKUC()` – v deštruktore sa uvoľňujú alokované zdroje pre ďalšie použitie. Deštruktor sa volá automaticky pri skončení platnosti inštancie. Napr. pri opustení bloku kódu v ktorom bola trieda vytvorená. V našom prípade je deštruktor prázdny.
- Funkcia `set_AKU(int cas)` je verejná, čo dovoľuje pristupovať k nej z užívateľskej časti programu. Samozrejme len za podmienky, že existuje jej inštancia. Táto funkcia je používaná na spustenie zvukového signálu. Bzučiak bude generovať akustický signál po dobu definovanú hodnotou argumentu „cas“. Hodnota predstavuje čas v milisekundách. Všimnime si, že počas celej doby generovania je CPU zaneprázdnená výkonom kódu v hlavnej slučke funkcie. Takéto riešenie je pre praktické použitie len ťažko prijateľné. Ako by bolo možné zlepšiť uvedenú funkciu prediskutujem v ďalšom texte.
- Funkcia `set_AKU(bool stav)` je verejná s rovnakým menom, ale s iným typom argumentu. Na základe hodnoty parametra „stav“ je možné zapnúť bzučiak. Žiaľ to je posledná vec čo sme schopní realizovať. Po volaní funkcie s argumentom „true“ sa program bude pohybovať v nekonečnej slučke a nebude ho možné prerušiť. **Funkcia v tomto stave je nepoužiteľná!** 
- Funkcia `get_AKU(void)` vracia stav (trúbi/netrúbi = true/false). V doteraz navrhnutej triede AKUC nemá prakticky význam. Vždy bude vracať len jednu hodnotu. Tipnete si akú?

Pre úplnosť uvedieme ešte súbor `main.cpp`:

``` c++
#include "BOARD_AVR.h"
#include "AKUC.h"

int main(void)
{
	  
	AKUC aku;			// vytvorenie instancie aku triedy AKUC, nastavi sa vyvod
	aku.set_AKU(500);   //0.5 s trúbi
	
	while (1){}	//nekonecna slucka
}
```

Kód main.cpp je veľmi jednoduchý. Direktívou `#include` volá tie hlavičkové súbory, ktorých definície, makrá a funkcie využíva.

!!! note "Poznámka"
	 Súbor `BOARD_AVR.h` nie je potrebné volať v hlavnom programe, pretože jeho volanie je obsiahnuté už v hlavičkovom súbore „AKUC.h“. 
	Pretože je podmienkovo definovaný,
	``` c++
	#ifndef BOARD_AVR_H_
	#define BOARD_AVR_H_
    ```
    použije sa iba raz. Druhé volanie sa ignoruje.
    
V hlavnom programe je v prvom riadku vytvorená inštancia triedy `AKUC` – objekt s menom `aku`. Po vytvorení objektu môžeme začať používať funkcie typu `public` triedy AKUC. Ako bolo konštatované v predchádzajúcom texte, zmysel má využívať len funkciu `set_AKU(500)`. Po jej zavolaní bude znieť akustický signál po dobu 500 ms. Pretože ešte nevieme používať prerušovací systém, nebudeme sa ďalšími úpravami metód triedy `AKUC`zaoberať.
    ```