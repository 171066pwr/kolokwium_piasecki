// e)	Napisz funkcjê usuwaj¹c¹ z zadanego ³añcucha (poprzez skrócenie tekstu)
//    wszystkie bezpoœrednie powtórzenia liter np. zamieniaj¹c¹ tekst “kommputter” na ”komputer”.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int limit = 20;

void scan(char *array, int size) {
	fgets(array, size, stdin);
}

//damn, that's clean
void removeDuplicateChars(char *array) {
	char current = 0;
	int i = 0, j = 0;
	while((current = array[i]) != '\0')
		if(array[i+1] == current)
			++i;
		else
		   array[j++] = array[i++];
   array[j] = '\0';
}

int main() {
	char tab[limit] = "KKo  pyttkoooo";
	//scan(tab, limit);
	printf("%s\n", tab);
	removeDuplicateChars(tab);
	printf("%s\n", tab);

	system("pause");
}