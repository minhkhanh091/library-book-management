#ifndef BOOK_H
#define BOOK_H

struct Book {
    int book_id;
    std::string title;
    std::string author;
    std::string publisher;
    int publication_year;
    std::string type;

    Book *next;
    Book *prev;
};

struct List {
    Book *head, *tail;
};

Book *create_book(int book_id, const std::string &title, const std::string &author, const std::string &publisher, int publication_year, const std::string &type);
void init_list(List &list);

void print_books(List &list);

void insert_at_head(List &list, Book *new_book);
void insert_at_tail(List &list, Book *new_book);
void insert_at_after(List &list, Book *book_before, Book *insert_book);
void insert_at_middle(List &list, Book *new_book);

void delete_at_head(List &list);
void delete_at_tail(List &list);
void delete_at_middle(List &list);

void insert_maintain_order(List &list, Book *new_book);

#endif