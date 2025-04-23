#ifndef UTILS_H
#define UTILS_H

#include "book.h"

void print_menu_1() {
    std::cout << "\n===== LIBRARY BOOK MANAGEMENT =====\n";
    std::cout << "Please select the data source to operate on:\n";
    std::cout << "\n";
    std::cout << "1. Read books from file\n";
    std::cout << "2. Enter books from keyboard\n";
    std::cout << "\n";
    std::cout << "==============================\n";
}

void print_menu_2() {
    std::cout << "\n===== LIBRARY BOOK MANAGEMENT =====\n";
    std::cout << "1. Save book list to file\n";
    std::cout << "2. Add/Delete books at the beginning/end/middle\n";
    std::cout << "3. Sort by type and book ID\n";
    std::cout << "4. Add book while maintaining order\n";
    std::cout << "5. Find the author with the most books\n";
    std::cout << "6. Find the publisher with the fewest books\n";
    std::cout << "7. Statistics by publication year\n";
    std::cout << "8. Count books by genre\n";
    std::cout << "9. Find books containing the string 'programming'\n";
    std::cout << "0. Exit\n";
    std::cout << "==============================\n";
}

Book *find_middle();
void sort_books_by_type_and_id(List &list);

#endif