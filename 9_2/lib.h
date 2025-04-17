
#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXL 100
typedef struct {
    char fname[50];
    char lname[50];
} Author;

typedef struct {
    char title[100];
    Author author;
    int pages;
    float price;
} Book;

int findBooksByAuthor(Book books[], int total, const char *lname, Book results[]);
void printBook(Book b);


#endif //LIB_H
