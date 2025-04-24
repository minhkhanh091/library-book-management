#ifndef UTILS_H
#define UTILS_H

#include "book.h"

bool is_list_empty(Book *head);

void sort_books_by_type_and_id(List &list);
Book *find_middle(List &list);

void find_author_with_most_books(List &list);
void find_publisher_with_fewest_books(List &list);
void find_books_by_title(List &list, std::string type);

void print_statistics_by_year(List &list);
void count_books_by_type(List &list);

void waiting();

#endif