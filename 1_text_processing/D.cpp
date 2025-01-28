//   d)	Napisz funkcj� usuwaj�c� (poprzez skr�cenie tekstu)
//    wszystkie spacje z �a�cucha podawanego jako parametr tej funkcji.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int limit = 20;

void scan(char *array, int size) {
	fgets(array, size, stdin);
}

void removeAllSmart(char *array, char character) {
	int i = 0, j = 0;
	while(array[i] != '\0')
		if(array[i] == character)
			++i;
		else
		   array[j++] = array[i++];
   array[j] = '\0';
}

//strcpy(destination, source) till \0
void removeAll(char *array, char character) {
  int i=0;
  while(array[i]!='\0' )
    if(array[i] == character)
      strcpy(&array[i], &array[i+1]);
    else
      i++;
}

void zadD(char *array) {
	removeAll(array, ' ');
	//removeAllSmart(array, ' ');
}

int main() {
	char tab[limit];
	scan(tab, limit);
	printf("%s\n", tab);
	zadD(tab);
	printf("%s\n", tab);

	system("pause");
}