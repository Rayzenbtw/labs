#include "lib.h"

int main() {
    struct book catalog;
    printf("Введіть назву книги \n"); fgets(catalog.title, MAXL, stdin);

    printf(" Введіть ПІБ автора \n"); fgets(catalog.author, MAXL, stdin);

    printf("Введіть кількість сторінок.\n"); scanf("%d", &catalog.pages);

    printf("Введіть ціну.\n"); scanf("%f", &catalog.price);

    printf("%s %s коштує %.2f грн.\n", catalog.title, catalog.author, catalog.price);
    return 0;
}