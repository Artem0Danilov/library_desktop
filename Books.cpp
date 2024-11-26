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
	std::string lowerAuthor = toLower(author);
	for (const auto& book : books) {
		std::string lowerBookAuthor = toLower(book.getAuthor());
		if (lowerBookAuthor == lowerAuthor) {
			foundBooks.push_back(book);
		}
	}

	return foundBooks;
}

std::vector<Book> findBookByInfo(const std::string& info) const {
	std::vector<Book> foundBooks;
	std::string lowerInfo = toLower(info);

	for (const auto& book : books) {
		std::string lowerBookInfo = toLower(book.getInfo());
		if (lowerBookInfo.find(lowerInfo) != std::string::npos) {
			foundBooks.push_back(book);
		}
	}
	return foundBooks;
}

std::vector<Book> findBook(const std::string& searchQuery) const {
	std::vector<Book> foundBooks;

	std::string lowerSearchQuery = toLower(searchQuery);
	for (auto& book : books) {
		std::string lowerTitle = toLower(book.getTitle());
		std::string lowerAuthor = toLower(book.getAuthor());
		std::string lowerInfo = toLower(book.getInfo());
		if (lowerTitle.find(lowerSearchQuery) != std::string::npos ||
			lowerAuthor.find(lowerSearchQuery) != std::string::npos ||
			lowerInfo.find(lowerSearchQuery) != std::string::npos) {
			foundBooks.push_back(book);
		}
	}
	return foundBooks;
}

