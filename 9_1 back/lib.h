//
// Created by 19shi on 17.04.2025.
//

#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#define MAXL 100

struct Author {
    char name[MAXL];
    int price;
    int pages;
};
struct Author inputAuthor();
void printAuthor(struct Author a);

#endif //LIB_H
