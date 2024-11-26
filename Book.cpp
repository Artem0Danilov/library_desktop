#include "Book.h"

int Book::count = 0;

Book::Book(const std::string& title, const std::string& author, const std::string& info, bool isAvailable)
	: title(title), author(author), info(info), isAvailable(isAvailable), id(++count) {}

std::string Book::getTitle() const{
	return title;
}

std::string Book::getAuthor() const{
	return author;
}

std::string Book::getInfo() const{
	return info;
}

bool Book::getAvailability() const{
	return isAvailable;
}

int Book::getID() const{
	return id;
}

void Book::setTitle(const std::string& title){
	this->title = title;

}

void Book::setAuthor(const std::string& author){
	this->author = author;
}

void Book::setInfo(const std::string& info){
	this->info = info;
}

void Book::addInfo(const std::string& info){
	if (this->info.empty){
		this->info += info;
	}
}

void Book::setAvailability(bool isAvailable){
	this->isAvailable = isAvailable;
}

