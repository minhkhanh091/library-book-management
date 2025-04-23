#include <iostream>
#include <map>
#include <vector>

#include "utils.h"
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
    std::cout << "1. Add/Delete books at the beginning/end/middle\n";
    std::cout << "2. Sort by type and book ID\n";
    std::cout << "3. Add book while maintaining order\n";
    std::cout << "4. Find the author with the most books\n";
    std::cout << "5. Find the publisher with the fewest books\n";
    std::cout << "6. Statistics by publication year\n";
    std::cout << "7. Count books by genre\n";
    std::cout << "8. Find books containing the string 'programming'\n";
    std::cout << "0. Exit\n";
    std::cout << "==============================\n";
}

/*

Insertion Sort
    type: A-Z, book_id: assending

*/
void sort_books_by_type_and_id(List &list) {
    if (!list.head || !list.head->next) return;    

    List sorted;
    init_list(sorted);

    Book *cur = list.head;

    while (cur) {
        Book *cur_next = cur->next;

        if (!sorted.head) {
            insert_at_head(sorted, cur);
        }
        else {
            insert_maintain_order(sorted, cur);
        }

        cur = cur_next;
    }

    list.head = sorted.head;
    list.tail = sorted.tail;
}

Book *find_middle(List &list) {
    Book *slow = list.head, *fast = list.head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void find_author_with_most_books(List &list) {
    std::map<std::string, int> author_book_count;

    Book *cur = list.head;

    while (cur) {
        author_book_count[cur->author]++;
        cur = cur->next;
    }

    std::string author_name;
    int max_book = 0;

    for (auto &it : author_book_count) {
        if (it.second > max_book) {
            max_book = it.second;
            author_name = it.first;
        }
    }

    std::cout << "Author with the most books: " << author_name << "\n";
    std::cout << "His books: ";

    cur = list.head;

    while (cur) {
        if (cur->author == author_name) {
            std::cout << "[" << cur->title << "] ";
        }

        cur = cur->next;
    }

    std::cout << "\n";
}