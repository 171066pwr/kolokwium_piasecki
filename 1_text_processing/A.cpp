/*Przetwarzanie tekst�w -  �a�cuch�w znak�w
     (tablica zawieraj�ca przetwarzany tekst powinna by� parametrem
       wej�ciowo/wyj�ciowym pisanej funkcji)



 b)	Napisz funkcj�, kt�ra usunie wszystkie pocz�tkowe spacje
    w �a�cuchu tekst, kt�ry powinien by� parametrem wej�ciowo/wyj�ciowym tej funkcji.

 c)	Napisz funkcj� formatuj�c� tekst poprzez usuni�cie
    wszystkich pocz�tkowych i ko�cowych spacji
    z �a�cucha zadanego jako parametr wej�ciowy tej funkcji.

 d)	Napisz funkcj� usuwaj�c� (poprzez skr�cenie tekstu)
    wszystkie spacje z �a�cucha podawanego jako parametr tej funkcji.

 e)	Napisz funkcj� usuwaj�c� z zadanego �a�cucha (poprzez skr�cenie tekstu)
    wszystkie bezpo�rednie powt�rzenia liter np. zamieniaj�c� tekst �kommputter� na �komputer�.

 f)	Napisz funkcj� dodaj�c� zadan� ilo�� spacji
    na pocz�tku zadanego �a�cucha tekst
    (wcze�niejsza zawarto�� tekstu przesuwana jest na dalsze pozycje).

 g)	Napisz funkcj� usuwaj�c� z �a�cucha tekst wszystkie litery
    poczynaj�c od pozycji pocz do litery na pozycji kon.

 h)	Napisz funkcj� wyr�wnuj�c� d�ugo�� zadanego tekst'u do N znak�w,
    poprzez dodanie odpowiedniej ilo�ci spacji na ko�cu tego �a�cucha.

 i)	Napisz funkcj� sprawdzaj�c� czy zadany �a�cuch znak�w
    ma symetryczn� zawarto�� tzn, pierwszy znak jest r�wny ostatniemu,
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

// a)	Napisz program, kt�ry wczyta �a�cuch znak�w z klawiatury
//    	a nast�pnie usunie z tego �a�cucha pierwsz� ma�� liter�.
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