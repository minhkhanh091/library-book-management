#include <iostream>
#include <sstream>
#include <fstream>

#include "file_io.h"

void input_source(int choice, int need_maintain_order, List &list) {
    if (need_maintain_order) read_from_keyboard(list, need_maintain_order, 2);
    else if (choice == 1) read_from_file(list, "books.txt");
    else if (choice == 2) read_from_keyboard(list, need_maintain_order, 2);
}

/*

Please make sure the data format is correct before proceeding

*/
void read_from_file(List &list, const char *file_name) {
    std::ifstream file(file_name);

    if (!file.is_open()) {
        std::cout << "Unable to open the file!\n";
        return;
    }

    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);

        int book_id;
        std::string title, author, publisher, type;
        int publication_year;
        std::string tmp;

        std::getline(ss, tmp, '|'); book_id = stoi(tmp);
        std::getline(ss, title, '|');
        std::getline(ss, author, '|');
        std::getline(ss, publisher, '|');
        std::getline(ss, tmp, '|'); publication_year = stoi(tmp);
        std::getline(ss, type, '|');

        Book *new_book = create_book(book_id, title, author, publisher, publication_year, type);
        insert_at_tail(list, new_book);
    }

    file.close();
}

void read_from_keyboard(List &list, int need_maintain_order, int insert_pos) {
    int choice;

    do {
        std::cout << "\nEnter [1] to add a book, [0] to return to the main menu: ";
        std::cin >> choice;
        std::cin.ignore();

        std::cout << "\n";

        if (!choice) break;

        int book_id, publication_year;
        std::string title, author, publisher, type;

        std::cout << "Enter book ID: ";
        while (!(std::cin >> book_id)) {
            std::cout << "Invalid input. Please enter an integer: ";
            std::cin.clear();
            std::cin.ignore(99999, '\n');
        }
        std::cin.ignore();

        std::cout << "Enter book title: ";
        std::getline(std::cin, title);

        std::cout << "Enter author name: ";
        std::getline(std::cin, author);

        std::cout << "Enter publisher: ";
        std::getline(std::cin, publisher);

        std::cout << "Enter publication year: ";
        while (!(std::cin >> publication_year)) {
            std::cout << "Invalid input. Please enter an integer: ";
            std::cin.clear();
            std::cin.ignore(99999, '\n');
        }       
        std::cin.ignore();

        std::cout << "Enter type: ";
        std::getline(std::cin, type);

        Book* new_book = create_book(book_id, title, author, publisher, publication_year, type);

        if (!new_book) {
            std::cout << "Memory allocation failed for new book!\n";
            exit(1);
        }

        if (need_maintain_order) {
            insert_maintain_order(list, new_book);
        } else {
            switch (insert_pos) {
                case 1:
                    insert_at_head(list, new_book);
                    break;

                case 2:
                    insert_at_tail(list, new_book);                    
                    break;

                case 3:
                default:
                    insert_at_middle(list, new_book);
                    break;
            }
        }

        std::cout << "\nBook added successfully!\n";

    } while (choice);
}