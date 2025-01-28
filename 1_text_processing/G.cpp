// g)	Napisz funkcjê usuwaj¹c¹ z ³añcucha tekst wszystkie litery
//    poczynaj¹c od pozycji pocz do litery na pozycji kon.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int limit = 20;

void scan(char *array, int size) {
	fgets(array, size, stdin);
}

bool isLetter(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');	
}

void removeAllLetters(char *array) {
	int i = 0;
	int j = 0;
	while(array[i] != '\0') {
		if(isLetter(array[i]))
			++i;
		else
			array[j++] = array[i++];
	}
	array[j] = '\0';	
}

int main() {
	char tab[limit] = "Aa21as2-s a3";
	//scan(tab, limit);
	printf("%s\n", tab);
	removeAllLetters(tab);
	printf("%s\n", tab);

	system("pause");
}