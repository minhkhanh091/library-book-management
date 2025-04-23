/*
Github Repo: https://github.com/minhkhanh091/project-010110194315

Date Created: 22/4/2024
Finished on: 

*/

#include <iostream>

#include "book.h"
#include "utils.h"
#include "file_io.h"

void read_input(int choice, int need_maintain_order, List &list) {
	if (need_maintain_order) read_from_keyboard(list, need_maintain_order);
	else if (choice) read_from_file(list, "books.txt");
	else read_from_keyboard(list, need_maintain_order);
}

int main() {
	List list;
	init_list(list);

	int choice;

	do {
		print_menu_1();
		std::cout << "Your choice: ";
		std::cin >> choice;

		if (choice <= 0 || choice > 2) {
			std::cout << "Please enter a choice from [1, 2]";
			std::cout << "\n";
		}
	} while (choice <= 0 || choice > 2);

	read_input(choice, 0, list);

	do {
		print_menu_2();
		std::cout << "Your choice: ";
		std::cin >> choice;

		if (choice < 0 || choice > 9) {
			std::cout << "Please enter a choice from [0, 9]";
			std::cout << "\n";
		}
	} while (choice < 0 || choice > 9);

	switch (choice) {
		case 0:
		{
			exit(1);
		}

		case 1:
		{

		}

		case 2:
		{

		}

		case 3:
		{
			sort_books_by_type_and_id(list);
			print_books(list.head);

			break;
		}

		case 4:
		{
			sort_books_by_type_and_id(list);
			read_input(0, 1, list);
			print_books(list.head);
			
			break;
		}		
	}
}