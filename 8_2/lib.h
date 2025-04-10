//
// Created by 19shi on 10.04.2025.
//

#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#define MAXL 40
#define N 10

struct book {
    char title[MAXL];
    char author[MAXL];
    int pages;
    float price;
};
void input_books(struct book catalog_mas[], int *n);
void print_books(struct book catalog_mas[], int n);
void search_by_author(struct book catalog_mas[], int n, char *author);
void search_by_price(struct book catalog_mas[], int n, float price);
void largestbook(struct book catalog_mas[], int n, char *author);


#endif //LIB_H
