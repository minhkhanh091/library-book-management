#include <iostream>

#include "utils.h"
#include "file_io.h"

#define new_line std::cout << "\n"

void print_get_choice_menu_1() {
    std::cout << "\n===== LIBRARY BOOK MANAGEMENT =====\n";
    std::cout << "Please select the data source to operate on:\n";
    std::cout << "\n";
    std::cout << "1. Read books from file\n";
    std::cout << "2. Enter books from keyboard\n";
    std::cout << "\n";
    std::cout << "===================================\n";
}

void print_get_choice_menu_2() {
    std::cout << "\n===== LIBRARY BOOK MANAGEMENT =====\n";
    std::cout << "1. Add/Delete books at the beginning/end/middle\n";
    std::cout << "2. Sort by type and book ID\n";
    std::cout << "3. Add book while maintaining order\n";
    std::cout << "4. Find the author with the most books\n";
    std::cout << "5. Find the publisher with the fewest books\n";
    std::cout << "6. Statistics by publication year\n";
    std::cout << "7. Count books by type\n";
    std::cout << "8. Find books by type\n";
    std::cout << "0. Exit\n";
    std::cout << "===================================\n";	
}

void handle_main_menu(List &list) {
	int choice;

	do {
		do {
			print_get_choice_menu_2();
			std::cout << "Enter a choice from [0, 8] to operate: ";
			std::cin >> choice;

			if (choice < 0 || choice > 9) {
				std::cout << "Please enter a choice from [0, 9]";
				std::cout << "\n";
			}
		} while (choice < 0 || choice > 9);

		switch (choice) {
			// EXIT
			case 0: break;

			case 1:
			{
				std::cout << "\n===== LIBRARY BOOK MANAGEMENT =====\n";
				std::cout << "\nInsertion: ";
				std::cout << "\n	- [1]: Beginning\n";
				std::cout << "\n	- [2]: End\n";
				std::cout << "\n	- [3]: Middle\n";
				std::cout << "\nDeletion: ";
				std::cout << "\n	- [4]: Beginning\n";
				std::cout << "\n	- [5]: End\n";
				std::cout << "\n	- [6]: Middle\n";
			    std::cout << "\n==============================\n";
				std::cout << "Please enter a choice from [0, 6]";

			    break;
			}

			case 2:
			{
				sort_books_by_type_and_id(list);

				new_line;

				waiting();
				break;
			}

			case 3:
			{
				sort_books_by_type_and_id(list);
				input_source(0, 1, list);
				
				new_line;

				waiting();
				break;
			}

			case 4:
			{
			    std::cout << "\n-> FIND THE AUTHOR WITH THE MOST BOOKS";
				find_author_with_most_books(list);

				new_line;

				waiting();
				break;
			}

			case 5:
			{
			    std::cout << "\n-> FIND THE PUBLISHER WITH THE FEWEST BOOKS";
				find_publisher_with_fewest_books(list);

				new_line;

				waiting();
				break;
			}

			case 6:
			{
			    std::cout << "\n-> STATISTICS BY PUBLICATION YEAR";
				print_statistics_by_year(list);

				new_line;

				waiting();
				break;
			}	

			case 7:
			{
			    std::cout << "\n-> COUNT BOOKS BY TYPE";
				count_books_by_type(list);

				new_line;

				waiting();
				break;
			}

			case 8:
			{
			    std::cout << "\n-> FIND BOOKS BY TYPE";				
				std::cin.ignore();
				std::string get_title;

				std::cout << "\nEnter the type name (e.g., 'Lap trinh', 'AI'): ";
				std::getline(std::cin, get_title);

				find_books_by_title(list, get_title);

				new_line;

				waiting();
				break;
			}
		}
	} while (choice);	
}