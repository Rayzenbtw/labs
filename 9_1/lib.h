//
// Created by 19shi on 17.04.2025.
//

#ifndef LIB_H
#define LIB_H

#include <stdlib.h>
#include <stdio.h>
#define MAXL 100
struct Author {
    char name[MAXL];
    float price;
    int pages;
};
void inputAuthor(struct Author *p);
void printAuthor(struct Author *p);

#endif //LIB_H
