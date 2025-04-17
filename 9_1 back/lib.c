#include "lib.h"


struct Author inputAuthor() {
    struct Author a;

    printf("Author: ");
    scanf("%s", a.name);
    printf("Price: ");
    scanf("%d", &a.price);
    printf("Pages: ");
    scanf("%d", &a.pages);
    return a;
};
void printAuthor(struct Author a) {
    printf("\nAuthor: %s\n", a.name);
    printf("Price: %d\n", a.price);
    printf("Pages: %d\n", a.pages);
};
