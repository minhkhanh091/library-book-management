/*

Github Repo: https://github.com/minhkhanh091/project-010110194315

Date Created: 22/4/2024
Finished on: 24/4/2024

*/

#include <iostream>

#include "book.h"
#include "file_io.h"
#include "handle_menu.h"

int get_choice() {
	int choice;

	do {
		print_get_choice_menu_1();
		std::cout << "Enter a choice from [1, 2] to operate: ";
		std::cin >> choice;

		if (choice <= 0 || choice > 2) {
			std::cout << "Please enter a choice from [1, 2]";
			std::cout << "\n";
		}
	} while (choice <= 0 || choice > 2);

	return choice;
}

int main() {
	List list;
	init_list(list);

	int choice = get_choice();

	input_source(choice, 0, list);
	
	print_books(list);
	handle_main_menu(list);
}