include "Book.h"
include "Books.h"
include <iostream>
include <string>

void printMenu();
void printMenusearch();
void addBookInterface(Books& books);
void deleteBookByIDInterface(Books& books);
void changeBookByIDInterface(Books& books);
void findBookByTitleInterface(Books& books);
void findBookByAuthorInterface(Books& books);
void findBookByInfoInterface(Books& books);
void findBookBySearchQueryInterface(Books& books);

int main() {
    setlocale(LC_ALL, "ru");

    Books books;
    bool exit = false;

    while (!exit) {
        printMenu();
        int choice;
        std::cin >> choice;
        std::cin.ignore(); // ������� ����� ����� ����� ����� ������

        switch (choice) {
        case 1:
            addBookInterface(books);
            break;
        case 2:
            deleteBookByIDInterface(books);
            break;
        case 3:
            changeBookByIDInterface(books);
            break;
        case 4:
            printMenusearch();
            int choice1;
            std::cin >> choice1;
            std::cin.ignore();

            switch (choice1) {
            case 1:
                findBookByTitleInterface(books);
                break;
            case 2:
                findBookByAuthorInterface(books);
                break;
            case 3:
                findBookByInfoInterface(books);
                break;
            case 4:
                findBookBySearchQueryInterface(books);
                break;
            default:
                std::cout << "�������� �����. ���������� �����.\n";
            }
            break;
        case 5:
            exit = true;
            break;
        default:
            std::cout << "�������� �����. ���������� �����.\n";
        }
    }

    std::cout << "��������� ���������.\n";
	return 0;
}

void printMenu() {
    std::cout << "-----------------------------------------------------------------\n";
    std::cout << "\n����:\n";
    std::cout << "1. �������� �����\n";
    std::cout << "2. ������� �����\n";
    std::cout << "3. �������� �����\n";
    std::cout << "4. ����� �����\n";
    std::cout << "5. �����\n";
    std::cout << "�������� ��������: ";
    std::cout << "-----------------------------------------------------------------\n";
}

void printMenusearch() {
    std::cout << "-----------------------------------------------------------------\n";
    std::cout << "\n����:\n";
    std::cout << "1. ����� ����� �� ��������\n";
    std::cout << "2. ����� ����� �� ������\n";
    std::cout << "3. ����� ����� �� ����������\n";
    std::cout << "4. ����� ����� �� ������ ������� (��������, �����, ����������)\n";
    std::cout << "-----------------------------------------------------------------\n";
}

void addBookInterface(Books& books) {
    std::string title, author, info;
    bool isAvailable;

    std::cout << "������� �������� �����: ";
    std::getline(std::cin, title);
    std::cout << "������� ������ �����: ";
    std::getline(std::cin, author);
    std::cout << "������� ���������� � �����: ";
    std::getline(std::cin, info);
    std::cout << "�������� �� ����� (1 - ��, 0 - ���): ";
    std::cin >> isAvailable;
    std::cin.ignore(); // ����� �������� ����� ����� ����� ����� isAvailable

    Book book(title, author, info, isAvailable);
    books.addBook(book);
    std::cout << "����� ���������.\n";
}

void deleteBookByIDInterface(Books& books) {
    int id;
    std::cout << "������� ID ����� ��� ��������: ";
    std::cin >> id;
    std::cin.ignore(); // ������� ����� �����

    if (books.deleteBookByID(id)) {
        std::cout << "����� ������� �������.\n";
    }
    else {
        std::cout << "����� � ����� ID �� �������.\n";
    }
}

void changeBookByIDInterface(Books& books) {
    int id;
    std::cout << "������� ID ����� ��� ���������: ";
    std::cin >> id;
    std::cin.ignore(); // ������� ����� �����

    std::string title, author, info;
    bool isAvailable;

    std::cout << "������� ����� �������� �����: ";
    std::getline(std::cin, title);
    std::cout << "������� ������ ������ �����: ";
    std::getline(std::cin, author);
    std::cout << "������� ����� ���������� � �����: ";
    std::getline(std::cin, info);
    std::cout << "�������� �� ����� (1 - ��, 0 - ���): ";
    std::cin >> isAvailable;
    std::cin.ignore(); // ����� �������� ����� ����� ����� ����� isAvailable

    if (books.changeBookByID(id, title, author, info, isAvailable)) {
        std::cout << "����� ��������.\n";
    }
    else {
        std::cout << "����� � ����� ID �� �������.\n";
    }
}

void findBookByTitleInterface(Books& books) {
    std::string title;
    std::cout << "������� �������� �����: ";
    std::getline(std::cin, title);

    std::vector<Book> foundBooks = books.findBookByTitle(title);
    if (foundBooks.empty()) {
        std::cout << "����� � ����� ��������� �� �������.\n";
    }
    else {
        std::cout << "������� ���� �� ��������:\n";
        for (const auto& book : foundBooks) {
            std::cout << "ID: " << book.getID() << ", ��������: " << book.getTitle()
                << ", �����: " << book.getAuthor() << ", �����������: "
                << (book.getAvailability() ? "��" : "���") << ", ����������: " << book.getInfo() << "\n";
        }
    }
}

void findBookByAuthorInterface(Books& books) {
    std::string author;
    std::cout << "������� ������ �����: ";
    std::getline(std::cin, author);

    std::vector<Book> foundBooks = books.findBookByAuthor(author);
    if (foundBooks.empty()) {
        std::cout << "����� � ����� ������� �� �������.\n";
    }
    else {
        std::cout << "������� ���� �� ������:\n";
        for (const auto& book : foundBooks) {
            std::cout << "ID: " << book.getID() << ", ��������: " << book.getTitle()
                << ", �����: " << book.getAuthor() << ", �����������: "
                << (book.getAvailability() ? "��" : "���") << ", ����������: " << book.getInfo() << "\n";
        }
    }
}

void findBookByInfoInterface(Books& books) {
    std::string info;
    std::cout << "������� ���������� � �����: ";
    std::getline(std::cin, info);

    std::vector<Book> foundBooks = books.findBookByInfo(info);
    if (foundBooks.empty()) {
        std::cout << "����� � ����� ����������� �� �������.\n";
    }
    else {
        std::cout << "������� ���� �� ����������:\n";
        for (const auto& book : foundBooks) {
            std::cout << "ID: " << book.getID() << ", ��������: " << book.getTitle()
                << ", �����: " << book.getAuthor() << ", �����������: "
                << (book.getAvailability() ? "��" : "���") << ", ����������: " << book.getInfo() << "\n";
        }
    }
}

void findBookBySearchQueryInterface(Books& books) {
    std::string query;
    std::cout << "������� ������ ��� ������ (��������, �����, ����������): ";
    std::getline(std::cin, query);

    std::vector<Book> foundBooks = books.findBook(query);
    if (foundBooks.empty()) {
        std::cout << "����� �� ������� �� �������.\n";
    }
    else {
        std::cout << "������� ���� �� �������:\n";
        for (const auto& book : foundBooks) {
            std::cout << "ID: " << book.getID() << ", ��������: " << book.getTitle()
                << ", �����: " << book.getAuthor() << ", �����������: "
                << (book.getAvailability() ? "��" : "���") << ", ����������: " << book.getInfo() << "\n";
        }
    }
}

void findBookByIDInterface(Books& books) {
    int id;
    std::cout << "������� ID ����� ��� ���������: ";
    std::cin >> id;
    std::cin.ignore(); // ������� ����� �����

    auto bookOpt = books.findBookByID(id);
    if (bookOpt) {
        const Book& book = *bookOpt;
        std::cout << "ID: " << book.getID() << ", ��������: " << book.getTitle()
            << ", �����: " << book.getAuthor() << ", �����������: "
            << (book.getAvailability() ? "��" : "���") << ", ����������: " << book.getInfo() << "\n";
    }
    else {
        std::cout << "����� � ����� ID �� �������.\n";
    }
}
