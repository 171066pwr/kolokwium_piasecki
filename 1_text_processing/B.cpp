// b)	Napisz funkcjê, która usunie wszystkie pocz¹tkowe spacje
//    w ³añcuchu tekst, który powinien byæ parametrem wejœciowo/wyjœciowym tej funkcji.
//	nastêpnie usunie z tego ³añcucha pierwsz¹ ma³¹ literê.

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

void zadB(char *array, int size) {
	int counter = 0;
	while(array[counter] == ' ')
		++counter;
	shiftLeft(array, size, 0, counter);
	
	for(int i = 0; i < size || array[i] != '\0'; i++) {
		if(array[i] >= 'a' && array[i] <= 'z') {
			shiftLeft(array, size, i, 1);
			break;
		}
	}	
}

int main() {
	char tab[limit];
	scan(tab, limit);
	printf("%s\n", tab);
	zadB(tab, limit);
	printf("%s\n", tab);

	system("pause");
}