//
// Created by 19shi on 17.04.2025.
//

#include "lib.h"

void inputAuthor(struct Author *p) {
    printf("Author:");
    scanf("%s", p->name);
    printf("Price:");
    scanf("%f",&p ->price);
    printf("Pages:");
    scanf("%d",&p ->pages);
};
void printAuthor(struct Author *p) {

    printf("Author:");
    printf("%s\n", (*p).name);
    printf("Price:");
    printf("%d\n", (*p).price);
    printf("Pages:");
    printf("%d\n", (*p).pages);
};
