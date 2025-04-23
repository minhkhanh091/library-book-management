#include <iostream>

#include "book.h"

void init_list(List &list) {
	List newList;

	newList.head = newList.tail = nullptr;
	list = newList;
}

bool is_list_empty(List &list, Book *book) {
    if (!list.head) {
        list.head = list.tail = book;
        book->next = book->prev = nullptr;
        return true;
    }

    return false;
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

void insert_at_head(List &list, Book *book) {
    if (is_list_empty(list, book)) return;

    list.head->prev = book;
    book->next = list.head;
    book->prev = nullptr;
    list.head = book;
}

void insert_at_tail(List &list, Book *book) {
    if (is_list_empty(list, book)) return;

    book->prev = list.tail;
    book->next = nullptr;
    list.tail->next = book;
    list.tail = book;
}

void insert_at_after(List &list, Book *book_before, Book *insert_book) {
    insert_book->prev = book_before;
    insert_book->next = book_before->next;

    if (book_before->next) {
        book_before->next->prev = insert_book;
    } 
    else {
        list.tail = insert_book;
    }

    book_before->next = insert_book;
}

void insert_at_middle() {

}

void print_books(Book *head) {
    Book *cur = head;

    while (cur) {
        std::cout << cur->book_id << " | " << cur->title << " | " << cur->author << " | " << cur->publisher << " | " << cur->publication_year << " | " << cur->type << "\n";
        cur = cur->next;
    }
}