### Číslený zápis

| **celé čísla** |               |              |               |
| -------------- | ------------- | ------------ | ------------- |
| `0b11111111`   | binarné       | `0B11111111` | binarné       |
| `0377`         | osmičkové     | `255`        | desatinný     |
| `0xff`         | hexadecimálne | `0xFF`       | hexadecimálne |

| **Reálne čísla**                                |
| ----------------------------------------------- |
| `88.0f` / `88.1234567f`                         |
| jednoduchá presnosť **float** ( `f`prípona)     |
| `88.0` / `88.123456789012345`                   |
| dvojitou presnosťou **double** (bez `f`prípony) |

### Premenné

| Deklarácia          |                                                              |
| ------------------- | ------------------------------------------------------------ |
| int x;              | Premenná.                                                    |
| `char x = 'C';`     | Premenná a inicializácia.                                    |
| `float x, y, z;`    | Viaceré premenné rovnakého typu.                             |
| `const int x = 88;` | Konštantná premenná: nemôže sa priradiť po deklarácii (kompilátor vynútený.) |

| **Pomenovanie premenných**   |                                                    |
| ---------------------------- | -------------------------------------------------- |
| `cislo5zije;`**             | Alfanumerické, nie kľúčové slovo, začína písmenom. |
| <s>`2001VesmirnaOdysea;`</s> | Nesme začínať číslom                               |
| <s>`while;`**</s>           | Vyhradené kľúčové slovo jazyka c/c++.              |
| <s>`dobra premena!;`**</s>  | neplatné znaky.                                    |

### Primitívne dátové typy

|                                                  |                |                                                             |
| ------------------------------------------------ | -------------- | ----------------------------------------------------------- |
| `[class] [qualifier] [unsigned] type/void name;` |                |                                                             |
| *vzostupnou aritmetickou konverziou*             |                |                                                             |
| **celé čísla**                                   |                |                                                             |
| *typ*                                            | *počet bajtov* | *Rozsah hodnôt*                                             |
| `char`                                           | 1              | `unsigned` **alebo** `signed`                               |
| `unsigned char`                                  | 1              | $0$ až $2^8 -1$                                             |
| `signed char`                                    | 1              | $-2^7$ až $2^7 -1$                                          |
| `int`                                            | 2/4            | `unsigned` **alebo** `signed`                               |
| `unsigned int`                                   | 2/4            | $0$ až $2^{16} -1$ **alebo** $0$ až $2^{32} -1$             |
| `signed int`                                     | 2/4            | $-2^{15}$ až $2^{15} -1$ **alebo** $-2^{31}$ až $2^{31} -1$ |
| `short`                                          | 2              | `unsigned` **alebo** `signed`                               |
| `unsigned short`                                 | 2              | $0$ až $2^{16} -1$                                          |
| `signed short`                                   | 2              | $-2^{15}$ až $2^{15} -1$                                    |
| `long`                                           | 4/8            | `unsigned` **alebo** `signed`                               |
| `unsigned long`                                  | 4/8            | $0$ až $2^{32} -1$ **alebo** $0$ až $2^{64} -1$             |
| `signed long`                                    | 4/8            | $-2^{31}$ až $2^{31} -1$ **alebo** $-2^{63}$ až $2^{63} -1$ |
| `long long`                                      | 8              | `unsigned` **alebo** `signed`                               |
| `unsigned long long`                             | 8              | $0$ až $2^{64} -1$                                          |
| `signed long long`                               | 8              | $-2^{63}$ až $2^{63} -1$                                    |

| Reálne čísla  |                                  |                                                              |
| ------------- | -------------------------------- | ------------------------------------------------------------ |
| *typ*         | *počet bajtov*                   | *Rozsah hodnôt (normalizovaný)*                              |
| `float`       | 4                                | $± 1,2 \times10^{-38}$ až $± 3,4\times10^{38}$               |
| `double`      | 8/4                              | $± 2,3\times10^{-308}$ až $± 1,7\times10^{308}$ **ALEBO** v pripade 8bit AVR je to to iste ako  `float`. |
| `long double` | ARM: 8, AVR: 4, x86: 10, x64: 16 |                                                              |

### Rozšírené typy premenných

| `[class] [quali­fier] type name;` |          |                               |
| --------------------------------- | -------- | ----------------------------- |
| **Z `stdint.h`knižnice**          |          |                               |
| *typ*                             | *bajtov* | *Rozsah hodnôt*               |
| `int8_t`                          | 1        | $-2^7$ až $2^7 -1$            |
| `uint8_t`                         | 1        | $0$ až $2^8 -1$               |
| `int16_t`                         | 2        | $-2^{15}$ až $2^{15} -1$      |
| `uint16_t`                        | 2        | $0$ až $2^{16} -1$            |
| `int32_t`                         | 4        | $-2^{31}$ až $2^{31} -1$      |
| `uint32_t`                        | 4        | $0$ až $2^{32} -1$            |
| `int64_t`                         | 8        | $-2^{63}$ až $2^{63} -1$      |
| `uint64_t`                        | 8        | $0$ až $2^{64} -1$            |
| **Z `stdbo­ol.h`knižnice**        |          |                               |
| *typ*                             | *bajtov* | *Rozsah hodnôt*               |
| `bool`                            | 1        | `true`/ `false` alebo `0`/`1` |

| **Kvalifikátory prístupu** |                                                              |
| -------------------------- | ------------------------------------------------------------ |
| `const type`               | Parametre premennej sú určené len na čítanie (kompilátor ich môže optimalizovať.) |
| `volatile type`            | Premenná, ktorá sa nepredvídateľné môže zmeniť. napr. počas prerušenia. (kompilátor neoptimalizuje túto premennú.) |

| **Klúčové slová defunijúce spôsob uloženia** |                                                              |
| -------------------------------------------- | ------------------------------------------------------------ |
| `register`                                   | Vyžaduje sa pre rýchly prístup. Môže byť uložený v pamäti RAM **alebo** v registri. Maximálna veľkosť je veľkosť registra. |
| `static`                                     | Obsah premenej je ponechaný aj mimo definičný rozsah. `static`globálne premenné sú obmedzené na rozsah kompilovaného súboru objektov, v ktorom boli deklarované. |
| `extern`                                     | Premennú deklaruje iný súbor.                                |

| Pretypovanie                                  |                                     |
| --------------------------------------------- | ----------------------------------- |
| `(type)a`                                     | Vráti `a`pretypované na typ `type`. |
| `char x = 1, y = 2; float z = (float) x / y;` |                                     |

### Definície vlastného typu

| **definovanie**                                |                                                     |
| ---------------------------------------------- | --------------------------------------------------- |
| `typedef unsigned short uint16;`               | Definovanie skráteného názvu `uint16` pre dlhý typ. |
| `typedef struct structName{int a, b;}newType;` | Vytvorenie `newType` štruktúry.                     |
| `typedef enum typeName{false, true}bool;`      | Vytvorenie enum `bool` .                            |
| **deklarácia / použitie**                      |                                                     |
| `uint16 x = 65535;`                            | Premenná `x` typu `uint16`.                         |
| `newType y = {0, 0};`                          | Štruktúra `y`ako typ `newType`.                     |

### Ukazovateľ / pointer

| **deklarovať**    |                                                              |
| ----------------- | ------------------------------------------------------------ |
| `type *x;`        | Ukazovateľ a názvom x na premennú typu `type`                |
| `void *v;`        | Typ može byť nedefinovaný (univerzálny ukazovateľ). Nie je možné použiť iných operátorov, ako je zadanie, pretože dĺžka tohto typu nie je známa. |
| `struct type *y;` | Ukazovateľ štruktúry údajov.                                 |
| `type z[];`       | Názov poľa / reťazca možno použiť ako ukazovateľ na prvý prvok poľa. |
| **prístup**       |                                                              |
| `x`               | Adresa pamäte.                                               |
| `*x`              | Hodnota uložená na tejto adrese.                             |
| `y->a`            | Hodnota uložená v štruktúra ukazovateľ `y`prvku `a`.         |
| `&varName`        | Adresa pamäte normálnej premennej `varName`.                 |
| `*(type *)v`      | Dereferencovanie `void`ukazovateľa ako `type`ukazovateľa.    |

### Poľia

| **Deklarácia**                                  |                                                              |
| ----------------------------------------------- | ------------------------------------------------------------ |
| `type name[int];`                               | Nastavíte dĺžku poľa.                                        |
| `type name[int] = {x, y, z};`                   | Nastavujete dĺžku poľa a inicializujete prvky.               |
| `type name[int] = {x};`                         | Nastavíte dĺžku poľa a inicializujete všetky prvky na `x`.   |
| `type name[] = {x, y, z};`                      | Kompilátor nastavuje dĺžku poľa na základe počiatočných prvkov. |
| *Veľkosť už nie je možné po definovaní zmeniť.* |                                                              |
| **Rozmery**                                     |                                                              |
| `name[int]`                                     | Jednorozmerné pole.                                          |
| `name[int][int]`                                | Dvojrozmerné pole.                                           |
| **prístup**                                     |                                                              |
| `name[int]`                                     | Hodnota prvku `int`v poli `name`.                            |
| `*(name + int)`                                 | Rovnaké ako `name[­int]`.                                    |
| *Prvky sú súvisle očíslované vzostupne od `0`.* |                                                              |
| `&name[int]`                                    | Pamäťová adresa prvku `int`v poli `name`.                    |
| `name + int`                                    | Rovnaké ako `&­nam­e[i­nt]`.                                 |
| *Prvky sa ukladajú do súvislej pamäte.*         |                                                              |
| **Určenie veľkoti pola**                        |                                                              |
| `sizeof(array) / sizeof(arrayType)`             | Vráti dĺžku `array`. *(Nebezpečné)*                          |
| `sizeof(array) / sizeof(array[0])`              | Vráti dĺžku `array`. *(Bezpečné)*                            |

### Reťazce

| definovanie                             |                       |
| --------------------------------------- | --------------------- |
| `'A'` znak                              | Jednoduché úvodzovky. |
| `"AB"` textový reťazec                  | Dvojité úvodzovky.    |
| `\0`                                    | Nulový terminátor.    |
| *Reťazce sú* `char`*polia.*             |                       |
| `char name[4] = "Ash";`                 |                       |
| *je ekvivalent*                         |                       |
| `char name[4] = {'A', 's', 'h', '\0'};` |                       |
| `int i; for(i = 0; name[i]; i++){}`     |                       |
| `\0` *sa považuje za false hodnotu.*    |                       |

!!! warning "**Textové reťazce musia obsahovať prvok `char` hodnoty `\0`, ktorý definuje ich koniec.**"

### Funkcie

| Deklarácia                                                   |                                                              |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| `type/void funcName([args...]){ [return var;] }`             |                                                              |
| *Názvy funkcií sa riadia rovnakými obmedzeniami ako názvy premenných a musia byť **tiež** jedinečné.* |                                                              |
| `type/void`                                                  | Typ vrátenej hodnoty ( `void`ak neexistuje)                  |
| `funcName()`                                                 | Názov funkcie a zátvorky.                                    |
| `args...`                                                    | Typy a názvy argumentov ( `void`ak neexistujú)               |
| `{}`                                                         | Oddeľovače obsahu funkcií.                                   |
| `return var;`                                                | Vrátenie návratovej hodnoty. Pre funkcie definované s `void` návratovým typu treba preskočiť `return`. Funkcie sa ukončia okamžite po vykonaní `return`. |
| **Odovzdanie hodnoty alebo  odovzdanie ukazovateľa na hodnotu** |                                                              |
| `void f(type x); f(y);`                                      | Odovzdanie premennej `y` do funkcie `f` pomocou hodnoty.     |
| `void f(type *x); f(array);`                                 | Odovzdanie poľa alebo textového retažca do funkcie `f.` (odovzdanie ukazovateľa) |
| `void f(type *x); f(structure);`                             | Odovzdanie štruktúry do funkcie `f.` (odovzdanie ukazovateľa) |
| `void f(type *x); f(&y);`                                    | Odovzdanie premennej `y` do funkcie `f` pomocou ukazovateľa. |
| `type f(){ return x; }`                                      | Vracia sa podľa hodnoty.                                     |
| `type f(){ type x; return &x; }`                             | Vracia premennú podľa ukazovateľa.                           |
| *Ukazovateľ vám umožňuje zmeniť pôvodnú premennú v rámci funkcie.* |                                                              |

### Podmienené vetvenie

| **if, else if, else**                                        |                                                              |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| `if(a) b;`                                                   | Vykonáva, `b`ak `a`je pravda.                                |
| `if(a){ b; c; }`                                             | Vykonáva `b`a `c`ak `a`je pravda.                            |
| `if(a){ b; }else{ c; }`                                      | Vykonáva, `b`ak `a`je pravda, inak `c`.                      |
| `if(a){ b; }else if(c){ d; }else{ e; }`                      | Vykonáva, `b`ak `a`je pravda, inak, vykonáva`d`ak `c`je pravda, inak `e`. |
| **switch, case, break**                                      |                                                              |
| `switch(a){ case b: c; }`                                    | Vykonáva, `c`ak sa `a`rovná `b`.                             |
| `switch(a){ default: b; }`                                   | Vykonáva, `b`ak `a`nezodpovedá žiadnemu inému prípadu.       |
| `switch(a){ case b: case c: d; }`                            | Vykonáva, `d`ak sa `a`rovná buď `b`alebo `c`.                |
| `switch(a){ case b: c; case d: e; default: f; }`             | Vykonáva `c`, `e`a `f`ak sa `a`rovná `b`, `e`a `f`ak sa `a`rovná `d`, inak `f`. |
| `switch(a){ case b: c; break; case d: e; break; default: f; }` | Vykonáva, `c`ak sa `a`rovná `b`, `e`ak sa `a`rovná `d`a `e`inak. |

### Slučky (opakovanie)

| **while**                                                    |                                                              |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| `int x = 0; while(x < 10){ x += 2; }`                        |                                                              |
| *Slučka je preskočená, ak sú podmienky testu spočiatku nepravdivé.* |                                                              |
| `int x = 0;`                                                 | Deklarácia a inicializovanie celého čísla `x`.               |
| `while()`                                                    | Klúčové slovo a v zátvorkách je umiestnená podmienka         |
| `x < 10`                                                     | Podmineka opakovania slučky.                                 |
| `{}`                                                         | Odelenie kódu vykonávaného v slučke.                         |
| `x += 2;`                                                    | Obsah slučky.                                                |
| **do while**                                                 |                                                              |
| `char c = 'A'; do { c++; } while(c != 'Z');`                 |                                                              |
| *Vždy prechádza slučkou najmenej raz.*                       |                                                              |
| `char c = 'A';`                                              | Deklarácia a inicializovanie znaku `c`.                      |
| `do`                                                         | Kľúčové slovo.                                               |
| `{}`                                                         | Oddeľovače slučky.                                           |
| `c++;`                                                       | Obsah slučky.                                                |
| `while();`                                                   | Klúčové slovo a v zátvorkách je umiestnená podmienka. Bedkočiarka na konci. |
| `c != 'Z'`                                                   | Podmineka opakovania slučky.                                 |
| **for**                                                      |                                                              |
| `int i; for(i = 0; n[i] != '\0'; i++){}`                     | verzia jazyka c **(C89)**                                    |
| alebo                                                        |                                                              |
| `for(int i = 0; n[i] != '\0'; i++){}`                        | verzia jazyka c **(C99 +)**                                  |
| Slučka založená na zvýšení / znížení hodnoty premennej.      |                                                              |
| `int i;`                                                     | Deklaruje celé číslo `i`.                                    |
| `for()`                                                      | Kľúčové slovo.                                               |
| `i = 0;`                                                     | Inicializuje celé číslo `i`. *Bodkočiarka.*                  |
| `n[i] != '\0';`                                              | Podmienka opakovania slučky. *Bodkočiarka.*                  |
| `i++`                                                        | Prírastky `i`. *Žiadna bodkočiarka.*                         |
| `{}`                                                         | Oddeľovač slučky.                                            |
| **continue**                                                 |                                                              |
| `int i=0; while(i<10){ i++; continue; i--;}`                 |                                                              |
| *Preskočí zvyšok obsahu slučky a reštartuje ju, pokračuje na začiatku slučky.* |                                                              |
| **break**                                                    |                                                              |
| `int i=0; while(1){ if(x==10){break;} i++; }`                |                                                              |
| *Preskočí zvyšok obsahu slučky a ukončí slučku.*             |                                                              |

### Direktívy o predprocesoroch

|                         |                                                             |
| ----------------------- | ----------------------------------------------------------- |
| `#include <inbuilt.h>`  | Nahrádza riadok obsahom štandardného hlavičkového súboru h. |
| `#include "./custom.h"` | Nahrádza riadok obsahom vlastného súboru hlavičky.          |
| `#define NAME value`    | Definovanie makra. Nahradí všetky výskyty `NAME`za `value`. |

### Komentáre

```c++
// Toto je jednoriadkový komentár!
// Na týchto riadkoch nezostane // po kompilácii nič.

/* Toto je viacriadkový komentár!
Medzi týmito oddeľovačmi nebolo nič kompilované. */
```

### Unárne operátory

| Deklarácia  |                                                  |
| ----------- | ------------------------------------------------ |
| `+a`        | Súčet `0`(nula) a `a`. (0 + a)                   |
| `-a`        | Rozdiel `0`(nula) a `a`. (0 - a)                 |
| `!a`        | Doplnok (logická negácia) z `a`. (~ A)           |
| `~a`        | Binárny doplnok (bitová negácia) z `a`. (~ A)    |
| `++a`       | Prírastok `a`o `1`. (a = a + 1)                  |
| `--a`       | Úbytok `a`o `1`. (a = a - 1)                     |
| `a++`       | Vráti `a`potom prírastok `a`o `1`. (a = a + 1)   |
| `a--`       | Vráti a `a`potom zníži `a`o `1`. (a = a - 1)     |
| `(type)a`   | Typcasty `a`ako `type`.                          |
| `&a;`       | Umiestnenie `a` v pamäti.                        |
| `sizeof(a)` | Koľko zaberá pamäte `a`(alebo `type`) v bajtoch. |

### Binárne operátory

| Definícia |                                                              |
| --------- | ------------------------------------------------------------ |
| `a * b;`  | Násobenie `a`a `b`. (a × b)                                  |
| `a / b;`  | Podiel `a` a `b`. Uistite sa, že deliteľ nie je nula. (a ÷ b) |
| `a % b;`  | Zvyšok po delení *celých čísel*  `a`a `b`.                   |
| `a + b;`  | Súčet `a`a `b`.                                              |
| `a - b;`  | Rozdiel `a`a `b`.                                            |
| `a << b;` | Ľavý bitový posun `a`o `b`miest. ($a\times2^b$)              |
| `a >> b;` | Pravá bitový posun `a`o `b`miest. ($a\times2^{-b}$)          |
| `a < b;`  | Menej ako. Pravda, ak `a`je menej ako `b`a inak nepravda.    |
| `a <= b;` | Menej ako alebo rovné. Pravda, ak `a`je menšia alebo rovná `b`a inak nepravda. (a ≤ b) |
| `a > b;`  | Väčší než. Pravda, ak `a`je väčšia ako `b`a inak nesprávna.  |
| `a >= b;` | Väčší alebo rovný. Pravda, ak `a`je väčšie alebo rovné `b`a inak nepravda. (a ≥ b) |
| `a == b;` | Rovnosť. Pravda, ak `a`je rovné `b`a inak nepravda. (a ⇔ b)  |
| `a != b;` | Nerovnosť. Pravda, ak `a`nie je rovné `b`a inak nepravda. (a ≠ b) |
| `a & b;`  | Bitový AND z `a`a `b`. (a ⋂ b)                               |
| `a ^ b;`  | Bitový exkluzívny OR- ALEBO `a`a `b`. (a ⊕ b)                |
| `a | b;`  | Bitový OR - ALEBO `a`a `b`. (a ⋃ b)                          |
| `a && b;` | Logické AND. Pravda, ak oboje `a`a `b`nie je nula. (Logické A) (a ⋂ b) |
| `a || b;` | Logické OR. Pravda, ak `a`alebo `b`nie je nula. (Logické ALEBO) (a ⋃ b) |

### Ternárne operátory

| Definícia    |                                                              |
| ------------ | ------------------------------------------------------------ |
| `x ? a : b;` | Vykonáva, `a` ak `x`, hodnotoný ako logický výraz, je pravdivý alebo `b` ak nie je pravdivý. if(x){ a; } else { b; }) |
| `x = a;`     | Priradí hodnotu `a`do `x`.                                   |
| `a *= b;`    | a = a × b                                                    |
| `a /= b;`    | a = a ÷ b                                                    |
| `a %= b;`    | a = a mod b                                                  |
| `a += b;`    | a = a + b                                                    |
| `a -= b;`    | a = a - b                                                    |
| `a <<= b;`   | Priradí bitový posun vľavo `a`o `b`miesta do `a`. ($a = a × 2^b$) |
| `a >>= b;`   | Priradí bitový posun vprávo `a`o `b`miest k `a`. ($a = a × 2^{-b}$) |
| `a &= b;`    | Bitové operácie: a = a ⋂ b, a = a & b                        |
| `a ^= b;`    | Bitové operácie: a = a ⊕ b, a = a ^ b                        |
| `a |= b;`    | Bitové operácie: a = a ⋃ b, a = a \| b                       |