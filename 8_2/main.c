#include <string.h>

#include "lib.h"

int main() {
    struct book catalog_mas[201];
    int n; // Кількість книг
    char search_author[MAXL];
    float search_price;

    // Ініціалізація та введення даних
    input_books(catalog_mas, &n);

    // Виведення всіх книг
    print_books(catalog_mas, n);

    // Пошук книги за автором
    printf("\nВведіть автора для пошуку: ");
    fgets(search_author, MAXL, stdin);
    search_author[strcspn(search_author, "\n")] = 0; // Видаляємо символ нового рядка
    search_by_author(catalog_mas, n, search_author);

    // Пошук книги за ціною
    printf("\nВведіть ціну для пошуку: ");
    scanf("%f", &search_price);
    getchar(); // Очищаємо буфер
    search_by_price(catalog_mas, n, search_price);

    // Знаходження найбільшої книги вказаного автора
    largestbook(catalog_mas, n, search_author);

    return 0;

    return 0;
}