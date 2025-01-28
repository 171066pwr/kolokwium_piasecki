// f)	Napisz funkcjê dodaj¹c¹ zadan¹ iloœæ spacji
//    na pocz¹tku zadanego ³añcucha tekst
//    (wczeœniejsza zawartoœæ tekstu przesuwana jest na dalsze pozycje).
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int limit = 10;

void scan(char *array, int size) {
	fgets(array, size, stdin);
}

void addBeginSpaces(char *array, int size, int spaces) {
	if(spaces <= 0 || spaces >= size)
		return;
	int length = strlen(array);
	if((length + spaces) >= size)
		length -= (length + spaces + 1) - size;
	memmove(array + spaces, array, length);
	array[length + spaces] = '\0';
	while(spaces > 0)
		array[--spaces] = ' ';
}

int main() {
	char tab[limit] = "1234567";
	//scan(tab, limit);
	printf("%s\n", tab);
	addBeginSpaces(tab, limit, 4);
	printf("%s\n", tab);

	system("pause");
}