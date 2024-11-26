#include "Books.h"
#include <vector>
#include <iostream>


void Books::addBook(Book book) {
	books.push_back(book);
}

bool Books::deleteBookByID(int id)
{
	for (Book book = books.begin(); book != books.end(); ++book) {
		if ((*book)->getID() == id) {
			books.erase(book);
			return true;
		}
	}
	return false;
}