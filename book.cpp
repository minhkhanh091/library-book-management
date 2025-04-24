#include <iostream>

#include "book.h"
#include "utils.h"

void init_list(List &list) {
	List newList;

	newList.head = newList.tail = nullptr;
	list = newList;
}

bool insert_head_if_empty(List &list, Book *book) {
    if (!list.head) {
        list.head = list.tail = book;
        book->next = book->prev = nullptr;

        return true;
    }

    return false;
}

Book* create_book(int book_id, const std::string &title, const std::string &author, const std::string &publisher, int publication_year, const std::string &type) {
    Book *new_book = new Book;

    if (!new_book) {
        std::cout << "Memory allocation failed for new book!\n";
        exit(1);
    }

    new_book->book_id = book_id;
    new_book->title = title;
    new_book->author = author;
    new_book->publisher = publisher;
    new_book->publication_year = publication_year;
    new_book->type = type;

    return new_book;
}

void insert_at_head(List &list, Book *new_book) {
    if (insert_head_if_empty(list, new_book)) return;

    list.head->prev = new_book;
    new_book->next = list.head;
    new_book->prev = nullptr;
    list.head = new_book;
}

void insert_at_tail(List &list, Book *new_book) {
    if (insert_head_if_empty(list, new_book)) return;

    new_book->prev = list.tail;
    new_book->next = nullptr;
    list.tail->next = new_book;
    list.tail = new_book;
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

void insert_at_middle(List &list, Book *new_book) {
    Book *book_before = find_middle(list);
    insert_at_after(list, book_before, new_book);
}

void insert_maintain_order(List &list, Book *new_book) {
    Book *cur = list.head;

    while (cur && ((new_book->type > cur->type || new_book->type == cur->type) && new_book->book_id > cur->book_id)) {
        cur = cur->next;
    }

    if (!cur) insert_at_tail(list, new_book);
    else if (cur == list.head) insert_at_head(list, new_book);
    else insert_at_after(list, cur->prev, new_book);
}

void delete_at_head(List &list) {
    if (is_list_empty(list.head)) return;

    Book *temp = list.head;
    list.head = list.head->next;

    if (list.head) {
        list.head->prev = nullptr;
    } else {
        list.tail = nullptr;
    }

    delete temp;
}

void delete_at_tail(List &list) {
    if (is_list_empty(list.head)) return;

    Book *temp = list.tail;
    list.tail = list.tail->prev;

    if (list.tail) {
        list.tail->next = nullptr;
    } else {
        list.head = nullptr;
    }

    delete temp;
}

void delete_at_middle(List &list) {
    if (is_list_empty(list.head)) return;

    Book *middle = find_middle(list);

    if (middle->prev) {
        middle->prev->next = middle->next;
    } else {
        list.head = middle->next;
    }

    if (middle->next) {
        middle->next->prev = middle->prev;
    } else {
        list.tail = middle->prev;
    }

    delete middle;
}

void print_books(List &list) {
    Book *cur = list.head;

    std::cout << "\n";

    while (cur) {
        std::cout << cur->book_id << " | " << cur->title << " | " << cur->author << " | " << cur->publisher << " | " << cur->publication_year << " | " << cur->type << "\n";
        cur = cur->next;
    }
}