#include <iostream>
#include <sstream>
#include <fstream>

#include "file_io.h"

void input_source(int choice, int need_maintain_order, List &list) {
    if (need_maintain_order) read_from_keyboard(list, need_maintain_order);
    else if (choice) read_from_file(list, "books.txt");
    else read_from_keyboard(list, need_maintain_order);
}

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

        if (std::getline(ss, tmp, '|')) book_id = stoi(tmp);
        if (std::getline(ss, title, '|'));
        if (std::getline(ss, author, '|'));
        if (std::getline(ss, publisher, '|'));
        if (std::getline(ss, tmp, '|')) publication_year = stoi(tmp);
        if (std::getline(ss, type, '|'));

        Book *new_book = create_book(book_id, title, author, publisher, publication_year, type);
        insert_at_tail(list, new_book);
    }

    file.close();
}

void read_from_keyboard(List &list, int need_maintain_order) {
    int choice;
    do {
        std::cout << "\nEnter [1] to add a book, [0] to exit: ";
        std::cin >> choice;
        std::cin.ignore();

        std::cout << "\n";

        if (!choice) break;

        int book_id, publication_year;
        std::string title, author, publisher, type;

        std::cout << "Enter book ID: ";
        std::cin >> book_id;
        std::cin.ignore();

        std::cout << "Enter book title: ";
        std::getline(std::cin, title);

        std::cout << "Enter author name: ";
        std::getline(std::cin, author);

        std::cout << "Enter publisher: ";
        std::getline(std::cin, publisher);

        std::cout << "Enter publication year: ";
        std::cin >> publication_year;
        std::cin.ignore();

        std::cout << "Enter type: ";
        std::getline(std::cin, type);

        Book* new_book = create_book(book_id, title, author, publisher, publication_year, type);
        
        if (need_maintain_order) insert_maintain_order(list, new_book);
        else insert_at_tail(list, new_book);

        std::cout << "Book added successfully!\n";
    } while (choice);
}
