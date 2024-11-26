#pragma once

#include "Book.h"
#include <vector>
#include <optional>

class Books {
public:
	Books() = default;
	void addBook(Book book);
	bool deleteBookByID(int id);

	bool changeBookByID(int id, const std::string& title, 
						const std::string& author,
						const std::string& info,
						bool isAvailable);

	std::vector<Book> findBookByTitle(const std::string& title) const;
	std::vector<Book> findBookByAuthor(const std::string& author) const;
	std::vector<Book> findBookByInfo(const std::string& info) const;
	// find book by any matches: author, title, info
	std::vector<Book> findBook(const std::string& searchQuery) const;

	std::optional<Book> findBookByID(int id) const;
private:
	std::vector<Book> books;
};
