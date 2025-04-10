#include "lib.h"

#include <string.h>

struct book catalog_mas[201];
void input_books(struct book catalog_mas[], int *n) {
    printf("Введіть кількість книг (не більше 201): ");
    scanf("%d", n);

    if (*n > 201 || *n <= 0) {
        printf("Некоректна кількість книг. Використовуємо значення за замовчуванням: 5\n");
        *n = 5;
    }

    for (int i = 0; i < *n; i++) {
        printf("\nКнига #%d:\n", i+1);
        printf("Введіть назву книги: ");
        fgets(catalog_mas[i].title, MAXL, stdin);
        catalog_mas[i].title[strcspn(catalog_mas[i].title, "\n")] = 0;

        printf("Введіть ПІБ автора: ");
        fgets(catalog_mas[i].author, MAXL, stdin);
        catalog_mas[i].author[strcspn(catalog_mas[i].author, "\n")] = 0;

        printf("Введіть кількість сторінок: ");
        scanf("%d", &catalog_mas[i].pages);

        printf("Введіть ціну: ");
        scanf("%f", &catalog_mas[i].price);
        getchar();
    }
}
void print_books(struct book catalog_mas[], int n) {
    printf("\nКаталог книг\n");
    for (int i = 0; i < n; i++) {
        printf("\nКнига #%d:\n", i+1);
        printf("Назва: %s\n", catalog_mas[i].title);
        printf("Автор: %s\n", catalog_mas[i].author);
        printf("Кількість сторінок: %d\n", catalog_mas[i].pages);
        printf("Ціна: %.2f грн.\n", catalog_mas[i].price);
    }
}

void search_by_author(struct book catalog_mas[], int n, char *author) {
    int found = 0;
    printf("\nКниги автора %s \n", author);
    for (int i = 0; i < n; i++) {
        if (strcasecmp(catalog_mas[i].author, author) == 0) {
            printf("\nНазва: %s\n", catalog_mas[i].title);
            printf("Автор: %s\n", catalog_mas[i].author);
            printf("Кількість сторінок: %d\n", catalog_mas[i].pages);
            printf("Ціна: %.2f грн.\n", catalog_mas[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("Книги автора %s не знайдено.\n", author);
    }
}
void search_by_price(struct book catalog_mas[], int n, float price) {
    int found = 0;
    printf("\nКниги з ціною %.2f грн.\n", price);

    for (int i = 0; i < n; i++) {
        if (catalog_mas[i].price == price) {
            printf("\nНазва: %s\n", catalog_mas[i].title);
            printf("Автор: %s\n", catalog_mas[i].author);
            printf("Кількість сторінок: %d\n", catalog_mas[i].pages);
            printf("Ціна: %.2f грн.\n", catalog_mas[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("Книги з ціною %.2f грн. не знайдено.\n", price);
    }
}

void largestbook(struct book catalog_mas[], int n, char *author) {
    int max_pages = -1;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (strcasecmp(catalog_mas[i].author, author) == 0) {
            if (catalog_mas[i].pages > max_pages) {
                max_pages = catalog_mas[i].pages;
                index = i;
            }
        }
    }
    if (index != -1) {
        printf("\n Найбільша книга автора %s\n", author);
        printf("Назва: %s\n", catalog_mas[index].title);
        printf("Автор: %s\n", catalog_mas[index].author);
        printf("Кількість сторінок: %d\n", catalog_mas[index].pages);
        printf("Ціна: %.2f грн.\n", catalog_mas[index].price);
    } else {
        printf("\nКниги автора %s не знайдено.\n", author);
    }
}