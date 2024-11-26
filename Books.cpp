#include "Books.h"

#include <algorithm>

// Helper function to convert a string to lowercase
std::string toLower(std::string str) {
	std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
	return lowerStr;
}

std::vector<Book> Books::findBookByTitle(const std::string& title) const 
{
	std::vector<Book> foundBooks;
	std::string lowercaseTitle = toLower(title);

	for (Book book : books) {
		std::string bookTitle = toLower(book->getTitle());
		if (bookTitle.find(lowerTitle) != std::string::npos) {
			foundBooks.push_back(book);
		}
	}
	return foundBooks;
}
std::vector<Book> findBookByAuthor(const std::string& author) const {
	std::vector<Book> foundBooks;
	for (const auto& book : books) {
		if (book.getAuthor() == author) {
			foundBooks.push_back(book);
		}
	}
	return foundBooks;
}
std::vector<Book> findBookByInfo(const std::string& info) const {
	std::vector<Book> foundBooks;
	for (const auto& book : books) {
		if (book.getInfo().find(info) != std::string::npos) {
			foundBooks.push_back(book);
		}
	}
	return foundBooks;
}
std::vector<Book> findBook(const std::string& searchQuery) const {
	std::vector<Book> foundBooks;
	for (const auto& book : books) {
		if (book.getTitle().find(searchQuery) != std::string::npos ||
			book.getAuthor().find(searchQuery) != std::string::npos ||
			book.getInfo().find(searchQuery) != std::string::npos) {
			foundBooks.push_back(book);
		}
	}
	return foundBooks;
}

