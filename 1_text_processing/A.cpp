/*Przetwarzanie tekstów -  ³añcuchów znaków
     (tablica zawieraj¹ca przetwarzany tekst powinna byæ parametrem
       wejœciowo/wyjœciowym pisanej funkcji)



 b)	Napisz funkcjê, która usunie wszystkie pocz¹tkowe spacje
    w ³añcuchu tekst, który powinien byæ parametrem wejœciowo/wyjœciowym tej funkcji.

 c)	Napisz funkcjê formatuj¹c¹ tekst poprzez usuniêcie
    wszystkich pocz¹tkowych i koñcowych spacji
    z ³añcucha zadanego jako parametr wejœciowy tej funkcji.

 d)	Napisz funkcjê usuwaj¹c¹ (poprzez skrócenie tekstu)
    wszystkie spacje z ³añcucha podawanego jako parametr tej funkcji.

 e)	Napisz funkcjê usuwaj¹c¹ z zadanego ³añcucha (poprzez skrócenie tekstu)
    wszystkie bezpoœrednie powtórzenia liter np. zamieniaj¹c¹ tekst “kommputter” na ”komputer”.

 f)	Napisz funkcjê dodaj¹c¹ zadan¹ iloœæ spacji
    na pocz¹tku zadanego ³añcucha tekst
    (wczeœniejsza zawartoœæ tekstu przesuwana jest na dalsze pozycje).

 g)	Napisz funkcjê usuwaj¹c¹ z ³añcucha tekst wszystkie litery
    poczynaj¹c od pozycji pocz do litery na pozycji kon.

 h)	Napisz funkcjê wyrównuj¹c¹ d³ugoœæ zadanego tekst'u do N znaków,
    poprzez dodanie odpowiedniej iloœci spacji na koñcu tego ³añcucha.

 i)	Napisz funkcjê sprawdzaj¹c¹ czy zadany ³añcuch znaków
    ma symetryczn¹ zawartoœæ tzn, pierwszy znak jest równy ostatniemu,
    drugi przedostatniemu itd.
    */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int limit = 10;

void scan(char *array, int size) {
	fgets(array, size, stdin);
}

// memmove(addr of target; addr of source; size of source in bytes)
void shiftLeftMemmove(char *array, int size, int start, int shift) {
	if((start > size-1 && start < 1) || shift == 0)
		return;
	if(start + shift > size-1)
		shift = size-1-start;
	memmove(&array[start], &array[start + shift], strlen(array) - start);
}

// function shifting (inclusive) from start element to the left, i.e:
// "Kopytko lepsze"
//       ^ start = 5
// "Kopko lepsze" shift = 2
void shiftLeft(char *array, int size, int start, int shift) {
	if((start > size-1 && start < 1) || shift == 0)
		return;
	if(start - shift < 0)
		shift = start;
	for(int i = start; i < size; i++) {
		array[i-shift] = array[i];
		if(array[i] == '\0')
			break;
	}
}

void zadA(char *array, int size) {
	for(int i = 0; i < size || array[i] != '\0'; i++) {
		if(array[i] >= 'a' && array[i] <= 'z') {
			shiftLeft(array, size, i+1, 1);
			break;
		}
	}	
}

void zadAMemmove(char *array, int size) {
	for(int i = 0; i < size || array[i] != '\0'; i++) {
		if(array[i] >= 'a' && array[i] <= 'z') {
			shiftLeftMemmove(array, size, i, 1);
			break;
		}
	}	
}

// a)	Napisz program, który wczyta ³añcuch znaków z klawiatury
//    	a nastêpnie usunie z tego ³añcucha pierwsz¹ ma³¹ literê.
int main() {
	char tab[limit];
	char tab2[limit];

	printf("%s\n", tab);
	zadA(tab, 10);
	printf("%s\n", tab);
	
	zadAMemmove(tab2, 10);
	printf("%s\n", tab2);

	system("pause");
}