/*Przetwarzanie tekstów -  ³añcuchów znaków
     (tablica zawieraj¹ca przetwarzany tekst powinna byæ parametrem
       wejœciowo/wyjœciowym pisanej funkcji)
*/
// a)	Napisz program, który wczyta ³añcuch znaków z klawiatury
//    	a nastêpnie usunie z tego ³añcucha pierwsz¹ ma³¹ literê.
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
	//       array+start    array + start + shift -> pointer notation, below array notation
	memmove(&array[start], &array[start + shift], strlen(array) - start);
}

void zadAMemmove(char *array, int size) {
	for(int i = 0; i < size || array[i] != '\0'; i++) {
		if(array[i] >= 'a' && array[i] <= 'z') {
			shiftLeftMemmove(array, size, i, 1);
			break;
		}
	}	
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

int main() {
	char tab[limit];
	scan(tab, limit);
	zadA(tab, limit);
	printf("%s\n", tab);

	system("pause");
}