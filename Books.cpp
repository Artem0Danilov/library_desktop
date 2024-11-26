#include "Books.h"
#include <vector>
#include <iostream>


void Books::addBook(Book& book) {
	books.push_back(book);
}

bool Books::deleteBookById(int id) {
	int index = 0;
	bool found = false;
	for (Book& book : books) {
		if (book.GetId() == id) {
			std::cout << "This book has been found " << std::endl;
			found = true;
		}
		++index;
	}
	if (found = true) {
		books.erase(books.begin() + index);
		return true;
	}
	else {
		std::cout << "This book has not been found " << std::endl;
		return false;
	}

}