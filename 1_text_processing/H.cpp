// h)	Napisz funkcj� wyr�wnuj�c� d�ugo�� zadanego tekst'u do N znak�w,
//    poprzez dodanie odpowiedniej ilo�ci spacji na ko�cu tego �a�cucha.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int limit = 15;

void scan(char *array, int size) {
	fgets(array, size, stdin);
}

bool isLetter(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');	
}

void fillRight(char *array, int size, int expectedSize, char fill = ' ') {
	int length = strlen(array);
	if(size <= expectedSize)
		expectedSize = size -1;
	while(length < expectedSize)
		array[length++] = fill;
	array[length] = '\0';	
}

int main() {
	char tab[limit] = "123456789012";
	//scan(tab, limit);
	printf("%s\n", tab);
	fillRight(tab, limit, 20, '#');
	printf("%s\n", tab);

	system("pause");
}