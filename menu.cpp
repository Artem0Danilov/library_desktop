#include <iostream>
//#include "Book.hpp"
//#include "Books.hpp"

void analizeChoise(int choise, int searchChoise);

void interactiveLibrary(int choise, int searchChoise) {
	while (true) {
		std::cout << "#--------------------#" << std::endl;
		std::cout << "Меню библиотеки:\n" << std::endl;
		std::cout << "1. добавить книгу" << std::endl;
		std::cout << "2. удалить книгу" << std::endl;
		std::cout << "3. найти книгу" << std::endl;
		std::cout << "(введите 0 для выхода)\n" << std::endl;
		std::cin >> choise;
		std::cout << "\n#--------------------#" << std::endl;
		if (choise == 0)
			break;
		else
			analizeChoise(choise, searchChoise);
	}
}

void analizeChoise(int choise, int searchChoise) {
	if (choise == 1) {}
	if (choise == 2) {}
	if (choise == 3) {
		std::cout << "#--------------------#" << std::endl;
		std::cout << "Выберете по какому признаку искать книгу:\n" << std::endl;
		std::cout << "1. по названию" << std::endl;
		std::cout << "2. по автору" << std::endl;
		std::cout << "3. по ID" << std::endl;
		std::cout << "4. по информации" << std::endl;
		std::cout << "(введите 0 для выхода)\n" << std::endl;
		std::cin >> searchChoise;
		std::cout << "\n#--------------------#" << std::endl;
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	int choose = 0;
	int searchChoose = 0;
	interactiveLibrary(choose, searchChoose);
}