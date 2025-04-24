//
// Created by 19shi on 24.04.2025.
//

#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <string.h>
#define MAX_BOOKS 100

// Категорії
typedef enum {
    FICTION,
    DICTIONARY,
    TEXTBOOK
} Category;

// Автор
typedef struct {
    char surname[50];
    char name[50];
} Author;

// Книга
typedef struct {
    char title[100];
    Author author;
    float price;
    int year;
    Category category;

    // FICTION
    char genre[50];
    char illustratorSurname[50];

    // DICTIONARY
    int wordCount;

    // TEXTBOOK
    char subject[50];
    int grade;

} Book;

Category inputCategory();
void inputBook(Book* b);
void printCategory(Category c);
void printBook(Book b);
void searchByCategory(Book books[], int n, Category c);
void searchFictionByGenre(Book books[], int n, const char* genre);
void searchByPrice(Book books[], int n, float min, float max);




#endif //LIB_H
