/*2)  Zadania dotycz¹ce zastosowañ typu strukturalnego:
       (przetwarzana tablica struktur oraz iloœæ danych zapisanych w tej tablicy
         powinny byæ przekazywane jako parametry pisanych funkcji)
	a)	Zdefiniuj typ strukturalny oraz 100-elementow¹ tablicê
	    pozwalaj¹c¹ przechowywaæ informacje o ksi¹¿kach w bibliotece
	    (tytu³, autor, indeks, cena) oraz napisz funkcjê, która wyœwietli na ekranie
	    wszystkie dane tanich ksi¹¿ek (tzn. cena<10z³)
*/
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include <iostream>

#define LIMIT 3
#define TITLE 10
#define AUTHOR 10

struct Book {
	char title[TITLE];
	char author[AUTHOR];
	int index;
	double price;
	
	Book(){};
	
	Book(char aTitle[TITLE], char aAuthor[AUTHOR], int aIndex, double aPrice) {
		strcpy(title, aTitle);
		strcpy(author, aAuthor);
		index = aIndex;
		price = aPrice;	
	}
	
	void print() {
		printf("%s, %s, %d, %f\n", title, author, index, price);
	}
};

struct Library {
	int count;
	Book *books;
	
	Library() {
		count = 0;
		books = new Book[LIMIT];
	}
	
	bool scanBook(){
		Book book;
		std::cin.clear();
		fflush(stdin);
		std::cout << count <<"\tTitle: ";
		fgets(book.title, TITLE, stdin);
		std::cin.clear();
		fflush(stdin);
		std::cout << "\n\tAuthor: ";
		fgets(book.author, AUTHOR, stdin);
		std::cout << "\n\tIndex: ";
		std::cin >> book.index;
		std::cout << "\n\tPrice: ";
		std::cin >> book.price;
		return addBook(book);			
	}
	
	bool addBook(Book book) {
		if(count < LIMIT) {
			std::cout << count << std::endl;
			books[count++] = book;
			return true;
		}
		return false;
	}
	
	bool addBook(char title[TITLE], char author[AUTHOR], int index, double price) {
		if(count < LIMIT) {
			std::cout << count << std::endl;
			books[count++] = *new Book(title, author, index, price);
			return true;
		}
		return false;
	}
	
	void printBelowPrice(double price) {
		for(int i = 0; i < count; i++)
			if(books[i].price < price)
				books[i].print();
	}
	
	bool isOverflown() {
		return count == LIMIT;
	}
};

int main() {
	Library library;
	library.addBook("Kopytko", "Autorzysko", 171066, 21.37);
	while(!library.isOverflown())
		library.scanBook();
	library.printBelowPrice(30.00);
	
	system("pause");	
}