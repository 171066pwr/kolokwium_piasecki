/*4)	Zadania z dynamicznej alokacji pamiêci:
 a)	Napisz funkcjê UTWORZ_TABLICÊ( rozmiar_A )
    tworz¹c¹ dynamiczn¹ tablicê A liczb ca³kowitych
    (o rozmiarze zadawanym jako parametr tej funkcji).
           Nastêpnie napisz funkcjê KOPIUJ_DODATNIE(A,rozmiar_A,B,rozmiar_B),
    która policzy ile z elementów tablicy A jest dodatnich
    i utworzy now¹ dynamiczn¹ tablicê B zawieraj¹c¹ kopie tych elementów tablicy A,
    które maj¹ wartoœci dodatnie.
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void printIntArray(int *array, int size) {
	while(size > 0)
		printf("%d\t", array[--size]);
	printf("\n\n");
}

int *createArray(int size) {
	int *array = new int[size];
	for(int i = 0; i < size; i++) {
		array[i] = rand()%200 - 100;
	}
	return array;
}

void copyPositive(int *A, int aSize, int *&B, int &bSize) {
	bSize = 0;
	for(int i = 0; i < aSize; i++)
		if(A[i] > 0)
			bSize++;
	//could use new there as well, but it's worth to rememeber malloc syntaxjust wanted to 
	B = (int*)malloc(sizeof(int) * bSize);
	for(int i = 0, j = 0; i < aSize; i++)
		if(A[i] > 0)
			B[j++] = A[i];
}


int main () {
	srand(time(NULL));
	int aSize = 10;
	int *A = createArray(aSize);
	int *B;
	int bSize;
	copyPositive(A, aSize, B, bSize);
	
	printIntArray(A, aSize);
	printIntArray(B, bSize);
	delete A, delete B;
}