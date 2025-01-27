//  c)	Napisz funkcjê formatuj¹c¹ tekst poprzez usuniêcie
//    wszystkich pocz¹tkowych i koñcowych spacji
//    z ³añcucha zadanego jako parametr wejœciowy tej funkcji.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int limit = 10;

void scan(char *array, int size) {
	fgets(array, size, stdin);
}

// memmove(addr of target; addr of source; size of source in bytes)
void shiftLeft(char *array, int size, int start, int shift) {
	if((start > size-1 && start < 1) || shift == 0)
		return;
	if(start + shift > size-1)
		shift = size-1-start;
	memmove(&array[start], &array[start + shift], strlen(array) - start);
}

void trimEnd(char *array, int size) {
	int end = strlen(array);
	if(end == 0)
		return;
	int counter = 0;
	while(array[end-1] == ' ')
		--end;
	array[end] = '\0';
}

void trimBegin(char *array, int size) {
	int counter = 0;
	while(array[counter] == ' ')
		++counter;
	shiftLeft(array, size, 0, counter);
}

void zadC(char *array, int size) {
	trimBegin(array, size);
	trimEnd(array, size);
}

int main() {
	char tab[limit];
	scan(tab, limit);
	printf("%s\n", tab);
	zadC(tab, limit);
	printf("%s\n", tab);

	system("pause");
}