/*  c)	Napisz funkcjê tworz¹c¹ dynamiczn¹ tablicê wskaŸników na teksty
    o maksymalnej dlugoœci 30 znaków.
    Wielkoœæ tablicy powinna byæ zadawana przez u¿ytkownika (z klawiatury).
    Nastêpnie napisz funkcjê wczytuj¹c¹ kolejne teksty z klawiatury
    i umieszczaj¹c¹ je w tej dynamicznie utworzonej tablicy. 
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

#define SIZE 10

using namespace std;

typedef char (*text)[SIZE];

void printStudentArray(int *array, int size) {
	while(size > 0)
		printf("%d\t", array[--size]);
	printf("\n\n");
}

text *createArray(int size) {
	text *array = new text[size];
	while(size > 0) {
		array[--size] = (text)malloc(sizeof(char)*);	
	}		
	return array;
}

void readTextArray(text *array, int size) {
	for(int i = 0; i < size; i++) {
		std::cout << i << ".\t";
		std::cin.clear();
		fflush(stdin);
		fgets(*(array[i]), SIZE, stdin);	
	}
}

int main () {
	int size = 0;
	std::cin >> size;
	text *array = createArray(size);
	readTextArray(array, size);
	
	std::cout << endl << "Teksty:" << endl;
	for(int i = 0; i < size; i++)
		std::cout << i << ".\t" << *array[i] << endl;
	
	for(int i = 0; i < size; i++)
		delete array[i];
	delete array;
}