#include <iostream>

#include "book.h"

void init_list(List &list) {
	List newList;

	newList.head = newList.tail = nullptr;
	list = newList;
}

Book* create_book(int book_id, const std::string &title, const std::string &author, const std::string &publisher, int publication_year, const std::string &type) {
    Book *newBook = new Book;

    newBook->book_id = book_id;
    newBook->title = title;
    newBook->author = author;
    newBook->publisher = publisher;
    newBook->publication_year = publication_year;
    newBook->type = type;

    return newBook;
}

void insert_at_tail(List &list, Book *book) {
    if (!list.head) {
        list.head = list.tail = book;
        book->next = book->prev = nullptr;
        return;
    }

    book->prev = list.tail;
    book->next = nullptr;
    list.tail->next = book;
    list.tail = book;
}

void print_books(Book *head) {
    Book *cur = head;

    while (cur) {
        std::cout << cur->book_id << " | " << cur->title << " | " << cur->author << " | " << cur->publisher << " | " << cur->publication_year << " | " << cur->type << "\n";
        cur = cur->next;
    }
}