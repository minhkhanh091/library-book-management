#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cctype>

#include "utils.h"
#include "book.h"

#define new_line std::cout << "\n"

bool is_list_empty(Book *head) {
    if (!head) {
        std::cout << "Cannot perform because the list is empty!";

        return true;
    }

    return false;
}

/*

Insertion Sort
    type: A-Z & book_id: assending

*/
void sort_books_by_type_and_id(List &list) {
    if (!list.head || !list.head->next) {
        std::cout << "Cannot perform sorting because the list is empty or contains only one book!";
        return;
    }   

    List sorted;
    init_list(sorted);

    Book *cur = list.head;

    while (cur) {
        Book *cur_next = cur->next;

        if (!sorted.head) insert_at_head(sorted, cur);
        else insert_maintain_order(sorted, cur);

        cur = cur_next;
    }

    list.head = sorted.head;
    list.tail = sorted.tail;


    std::cout << "\nSorted! Do you want to print the list?";
    std::cout << "\nEnter [1] to accept, [0] to deny: ";

    int choice;
    std::cin >> choice;

    if (choice) print_books(list);
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
    if (is_list_empty(list.head)) return;

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

    std::cout << "\nAuthor name: " << author_name;
    std::cout << "\nHis books: ";

    cur = list.head;

    while (cur) {
        if (cur->author == author_name) {
            std::cout << "[" << cur->title << "] ";
        }

        cur = cur->next;
    }
}

void find_publisher_with_fewest_books(List &list) {
    if (is_list_empty(list.head)) return;

    std::map<std::string, int> publisher_book_count;
    Book *cur = list.head;

    while (cur) {
        publisher_book_count[cur->publisher]++;
        cur = cur->next;
    }

    std::string publisher_name;
    long min_book = 0xffffffff;

    for (auto &it : publisher_book_count) {
        if ((long) it.second < min_book) {
            min_book = it.second;
            publisher_name = it.first;
        }
    }

    std::cout << "\nPublisher name: " << publisher_name;
    std::cout << "\nTheir books: ";

    cur = list.head;

    while (cur) {        
        if (cur->publisher == publisher_name) {
            std::cout << "[" << cur->title << "] ";
        }

        cur = cur->next;
    }
}

void print_statistics_by_year(List &list) {
    if (is_list_empty(list.head)) return;

    std::map<int, std::vector<std::string>> book_statistics_year;
    Book *cur = list.head;

    while (cur) {
        book_statistics_year[cur->publication_year].push_back(cur->title);
        cur = cur->next;
    }

    for (auto &it : book_statistics_year) {
        new_line;
        std::cout << it.first << ": ";

        for (auto &book : it.second) {
            std::cout << "[" << book << "]";
        }
    }
}

void count_books_by_type(List &list) {
    if (is_list_empty(list.head)) return;

    std::map<std::string, int> books_by_type;
    Book *cur = list.head;

    while (cur) {
        books_by_type[cur->type]++;
        cur = cur->next;
    }

    new_line;

    for (auto &it : books_by_type) {
        std::cout << it.first << ": " << it.second << "\n";
    }    
}

void find_books_by_title(List &list, std::string type) {
    if (is_list_empty(list.head)) return;

    std::vector<std::string> books_list;

    Book *cur = list.head;

    while (cur) {
        bool match = true;
        
        if (cur->type.size() != type.size()) match = false;

        // case insensitive
        for (int i = 0; i < type.size(); i++) {
            if (tolower(cur->type[i]) != tolower(type[i])) {
                match = false;
                break;
            }
        }            

        if (match) books_list.push_back(cur->title);
        cur = cur->next;
    }

    if (!books_list.size()) {
        std::cout << "Sorry, no book with that type '" << type << "'!";
        return;
    }

    std::cout << "List of books with type '" << type << "': ";

    for (std::string book : books_list) {
        std::cout << "[" << book << "] ";
    } 
}

void waiting(int &choice) {
    std::cout << "\nThe previous request has been completed";
    std::cout << "\nEnter a choice from [0, 8] to continue: ";
    std::cin >> choice;

    new_line;
}

std::string book_format_text(std::string text, int len) {
    if (text.length() > len) {
        return text.substr(0, 3) + "...";
    }

    while (text.length() < len) text += " ";
    
    return text;
}