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
        std::cin.ignore(); // очищаем буфер ввода после ввода выбора

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
                std::cout << "Неверный выбор. Попробуйте снова.\n";
            }
            break;
        case 5:
            exit = true;
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }

    std::cout << "Программа завершена.\n";
	return 0;
}

void printMenu() {
    std::cout << "-----------------------------------------------------------------\n";
    std::cout << "\nМеню:\n";
    std::cout << "1. Добавить книгу\n";
    std::cout << "2. Удалить книгу\n";
    std::cout << "3. Изменить книгу\n";
    std::cout << "4. Найти книгу\n";
    std::cout << "5. Выйти\n";
    std::cout << "Выберите действие: ";
    std::cout << "-----------------------------------------------------------------\n";
}

void printMenusearch() {
    std::cout << "-----------------------------------------------------------------\n";
    std::cout << "\nМеню:\n";
    std::cout << "1. Найти книгу по названию\n";
    std::cout << "2. Найти книгу по автору\n";
    std::cout << "3. Найти книгу по информации\n";
    std::cout << "4. Найти книгу по любому запросу (название, автор, информация)\n";
    std::cout << "-----------------------------------------------------------------\n";
}

void addBookInterface(Books& books) {
    std::string title, author, info;
    bool isAvailable;

    std::cout << "Введите название книги: ";
    std::getline(std::cin, title);
    std::cout << "Введите автора книги: ";
    std::getline(std::cin, author);
    std::cout << "Введите информацию о книге: ";
    std::getline(std::cin, info);
    std::cout << "Доступна ли книга (1 - да, 0 - нет): ";
    std::cin >> isAvailable;
    std::cin.ignore(); // чтобы очистить буфер ввода после ввода isAvailable

    Book book(title, author, info, isAvailable);
    books.addBook(book);
    std::cout << "Книга добавлена.\n";
}

void deleteBookByIDInterface(Books& books) {
    int id;
    std::cout << "Введите ID книги для удаления: ";
    std::cin >> id;
    std::cin.ignore(); // очищаем буфер ввода

    if (books.deleteBookByID(id)) {
        std::cout << "Книга успешно удалена.\n";
    }
    else {
        std::cout << "Книга с таким ID не найдена.\n";
    }
}

void changeBookByIDInterface(Books& books) {
    int id;
    std::cout << "Введите ID книги для изменения: ";
    std::cin >> id;
    std::cin.ignore(); // очищаем буфер ввода

    std::string title, author, info;
    bool isAvailable;

    std::cout << "Введите новое название книги: ";
    std::getline(std::cin, title);
    std::cout << "Введите нового автора книги: ";
    std::getline(std::cin, author);
    std::cout << "Введите новую информацию о книге: ";
    std::getline(std::cin, info);
    std::cout << "Доступна ли книга (1 - да, 0 - нет): ";
    std::cin >> isAvailable;
    std::cin.ignore(); // чтобы очистить буфер ввода после ввода isAvailable

    if (books.changeBookByID(id, title, author, info, isAvailable)) {
        std::cout << "Книга изменена.\n";
    }
    else {
        std::cout << "Книга с таким ID не найдена.\n";
    }
}

void findBookByTitleInterface(Books& books) {
    std::string title;
    std::cout << "Введите название книги: ";
    std::getline(std::cin, title);

    std::vector<Book> foundBooks = books.findBookByTitle(title);
    if (foundBooks.empty()) {
        std::cout << "Книги с таким названием не найдены.\n";
    }
    else {
        std::cout << "Найдено книг по названию:\n";
        for (const auto& book : foundBooks) {
            std::cout << "ID: " << book.getID() << ", Название: " << book.getTitle()
                << ", Автор: " << book.getAuthor() << ", Доступность: "
                << (book.getAvailability() ? "Да" : "Нет") << ", Информация: " << book.getInfo() << "\n";
        }
    }
}

void findBookByAuthorInterface(Books& books) {
    std::string author;
    std::cout << "Введите автора книги: ";
    std::getline(std::cin, author);

    std::vector<Book> foundBooks = books.findBookByAuthor(author);
    if (foundBooks.empty()) {
        std::cout << "Книги с таким автором не найдены.\n";
    }
    else {
        std::cout << "Найдено книг по автору:\n";
        for (const auto& book : foundBooks) {
            std::cout << "ID: " << book.getID() << ", Название: " << book.getTitle()
                << ", Автор: " << book.getAuthor() << ", Доступность: "
                << (book.getAvailability() ? "Да" : "Нет") << ", Информация: " << book.getInfo() << "\n";
        }
    }
}

void findBookByInfoInterface(Books& books) {
    std::string info;
    std::cout << "Введите информацию о книге: ";
    std::getline(std::cin, info);

    std::vector<Book> foundBooks = books.findBookByInfo(info);
    if (foundBooks.empty()) {
        std::cout << "Книги с такой информацией не найдены.\n";
    }
    else {
        std::cout << "Найдено книг по информации:\n";
        for (const auto& book : foundBooks) {
            std::cout << "ID: " << book.getID() << ", Название: " << book.getTitle()
                << ", Автор: " << book.getAuthor() << ", Доступность: "
                << (book.getAvailability() ? "Да" : "Нет") << ", Информация: " << book.getInfo() << "\n";
        }
    }
}

void findBookBySearchQueryInterface(Books& books) {
    std::string query;
    std::cout << "Введите запрос для поиска (название, автор, информация): ";
    std::getline(std::cin, query);

    std::vector<Book> foundBooks = books.findBook(query);
    if (foundBooks.empty()) {
        std::cout << "Книги по запросу не найдены.\n";
    }
    else {
        std::cout << "Найдено книг по запросу:\n";
        for (const auto& book : foundBooks) {
            std::cout << "ID: " << book.getID() << ", Название: " << book.getTitle()
                << ", Автор: " << book.getAuthor() << ", Доступность: "
                << (book.getAvailability() ? "Да" : "Нет") << ", Информация: " << book.getInfo() << "\n";
        }
    }
}

void findBookByIDInterface(Books& books) {
    int id;
    std::cout << "Введите ID книги для просмотра: ";
    std::cin >> id;
    std::cin.ignore(); // очищаем буфер ввода

    auto bookOpt = books.findBookByID(id);
    if (bookOpt) {
        const Book& book = *bookOpt;
        std::cout << "ID: " << book.getID() << ", Название: " << book.getTitle()
            << ", Автор: " << book.getAuthor() << ", Доступность: "
            << (book.getAvailability() ? "Да" : "Нет") << ", Информация: " << book.getInfo() << "\n";
    }
    else {
        std::cout << "Книга с таким ID не найдена.\n";
    }
}
