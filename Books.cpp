#include "Books.h"

#include <algorithm>

// Helper function to convert a string to lowercase
std::string toLower(const std::string& str) {
	std::string lowerStr = str;
	std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
	return lowerStr;
}

std::vector<Book> Books::findBookByTitle(const std::string& title) const 
{
	std::vector<Book> foundBooks;
	std::string lowercaseTitle = toLower(title);

	for (auto book : books) {
		std::string lowercaseBookTitle = toLower(book->getTitle());
		if (bookTitle.find(lowerTitle) != std::string::npos) {
			foundBooks.push_back(book);
		}
	}
	return foundBooks;
}

bool Books::changeBookByID(int id, const std::string& title, const std::string& author, const std::string& info, bool isAvailable)
{
	for (Book book : books) {
		if (book.getID() == id) {
			book.setTitle(title);
			book.setAuthor(author);
			book.setInfo(info);
			book.setAvailability(isAvailable);
			return true;
		}
	}
	return false;
}

std::optional<Book> Books::findBookByID(int id) const {
	for (Book book : books) {
		if (book.getID() == id) {
			return book;
		}
	}
	return std::nullopt;
}
