/* b)	Napisz funkcje tworz¹c¹ dynamiczn¹ tablice struktur
    opisuj¹cych dane osobowe studentów (wczeœniej zdefinuj typ tej struktury).
    Wielkoœæ tej dynamicznie tworzonej tablicy
    powinna byæ zadawana przez u¿ytkownika (z klawiatury).
    Nastêpnie napisz funkcjê wczytuj¹c¹ z klawiatury dane do w/w tablicy.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

struct Student {
	int indeks;
	char name[20];
	//new operator needs default constructor
	Student(){}
	
	Student(int indeks, char name[20]) {
		this->indeks = indeks;
		strcpy(this->name, name);	
	}
	
	void printStudent() {
		printf("%d, %s\n", indeks, name);	
	}	
};

void printStudentArray(int *array, int size) {
	while(size > 0)
		printf("%d\t", array[--size]);
	printf("\n\n");
}

Student *readStudent() {
	int indeks;
	char name[20];
	std::cout << "Indeks: ";
	std::cin >> indeks;
	//yes, you still need to flush endline before using fgets, sad.
	cin.clear();
	fflush(stdin);
	
	std::cout << "Imie: ";
	fgets(name, 20, stdin);
	return new Student(indeks, name);
}

int main () {
	int size = 0;
	std::cin >> size;
	Student array[size];
	
	for(int i = 0; i < size; i++) {
		std::cout << i+1 << ":\t";
		array[i] = *readStudent();
		std::cout << endl;
	}
	
	std::cout << endl << "Studenci:" << endl;
	for(int i = 0; i < size; i++)
		array[i].printStudent();
	delete array;
}