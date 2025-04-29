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
		print_get_choice_menu_2();
		std::cout << "Enter a choice from [0, 8] to operate: ";
		std::cin >> choice;

		if (choice < 0 || choice > 9) {
			std::cout << "Please enter a choice from [0, 9]";
			std::cout << "\n";
		}
	} while (choice < 0 || choice > 9);

	do {
		switch (choice) {
			case 0: break;

			case 1:
			{
			    std::cout << "\n===== LIBRARY BOOK MANAGEMENT =====\n";
			    std::cout << "Insertion: [1]: Beginning, [2]: End, [3]: Middle\n";
			    std::cout << "Deletion: [4]: Beginning, [5]: End, [6]: Middle";
			    std::cout << "\n==============================\n";
			    std::cout << "Enter a choice from [1, 6] to operate: ";

			    int sub_choice;

			    std::cin >> sub_choice;
			    std::cin.ignore();

			    switch (sub_choice) {
			        case 1:
			        case 2:
			        case 3:
			            read_from_keyboard(list, 0, sub_choice);
			            break;

			        case 4:
			            delete_at_head(list);
			            break;

			        case 5:
			            delete_at_tail(list);
			            break;

			        case 6:
			            delete_at_middle(list);
			            break;

			        default:
			            std::cout << "Please enter a choice from [1, 6]\n";
			    }

			    std::cout << "\nSuccessfully done!. Would you like to print the list?";
			    std::cout << "\nEnter [1] to accept, [0] to deny: ";

			    int choice;
			    std::cin >> choice;

			    if (choice) print_books(list);

			    new_line;
			    
			    waiting(choice);
			    break;
			}

			case 2:
			{
				sort_books_by_type_and_id(list);

				new_line;

				waiting(choice);
				break;
			}

			case 3:
			{
				input_source(0, 1, list);
				
				new_line;

				waiting(choice);
				break;
			}

			case 4:
			{
			    std::cout << "\n-> FIND THE AUTHOR WITH THE MOST BOOKS";
				find_author_with_most_books(list);

				new_line;

				waiting(choice);
				break;
			}

			case 5:
			{
			    std::cout << "\n-> FIND THE PUBLISHER WITH THE FEWEST BOOKS";
				find_publisher_with_fewest_books(list);

				new_line;

				waiting(choice);
				break;
			}

			case 6:
			{
			    std::cout << "\n-> STATISTICS BY PUBLICATION YEAR";
				print_statistics_by_year(list);

				new_line;

				waiting(choice);
				break;
			}	

			case 7:
			{
			    std::cout << "\n-> COUNT BOOKS BY TYPE";
				count_books_by_type(list);

				new_line;

				waiting(choice);
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

				waiting(choice);
				break;
			}
		}
	} while (choice);
}