#ifndef BOOK_H
#define BOOK_H

typedef struct Book {
    int book_id;
    std::string title;
    std::string author;
    std::string publisher;
    int publication_year;
    std::string type;

    struct Book *next;
    struct Book *prev;
} Book;

typedef struct List {
    Book *head, *tail;
};

Book *create_book(int book_id, const std::string &title, const std::string &author, const std::string &publisher, int publication_year, const std::string &type);
void init_list(List& list);

void print_books(Book *head);

void insert_at_head(Book** head, Book *new_book);
void insert_at_tail(List &list, Book *book);
void insert_at_position(Book** head, Book* new_book, int position);
void delete_by_position(Book** head, int position);

void sort_books(Book** head);
void insert_sorted(Book** head, Book* new_book);

void free_books(Book* head);

#endif
