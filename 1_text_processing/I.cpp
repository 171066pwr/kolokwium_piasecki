// i)	Napisz funkcjê sprawdzaj¹c¹ czy zadany ³añcuch znaków
//    ma symetryczn¹ zawartoœæ tzn, pierwszy znak jest równy ostatniemu,
//    drugi przedostatniemu itd. 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int limit = 15;

bool isSymmetrical(char *array) {
	int i = 0, j = strlen(array) - 1;
	while(i <= j)
		if(array[i++] != array[j--])
			return false;
	return true;
}

int main() {
	char tab[limit] = "12344321";
	printf("%s\n", tab);
	printf("%s\n", isSymmetrical(tab) ? "True" : "False");
	
	system("pause");
}