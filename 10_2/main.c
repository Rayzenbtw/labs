#include "lib.h"

int main() {
    Book library[MAX_BOOKS];
    int n;

    printf("Скільки книг ввести? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\n--- Книга %d ---\n", i + 1);
        inputBook(&library[i]);
    }

    int menu;
    do {
        printf("\n--- МЕНЮ ---\n");
        printf("1. Показати всі художні книги\n");
        printf("2. Знайти художню книгу за жанром\n");
        printf("3. Пошук за діапазоном цін\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");
        scanf("%d", &menu);

        if (menu == 1) {
            searchByCategory(library, n, FICTION);
        } else if (menu == 2) {
            char genre[50];
            printf("Введіть жанр: ");
            scanf(" %[^\n]", genre);
            searchFictionByGenre(library, n, genre);
        } else if (menu == 3) {
            float min, max;
            printf("Мінімальна ціна: ");
            scanf("%f", &min);
            printf("Максимальна ціна: ");
            scanf("%f", &max);
            searchByPrice(library, n, min, max);
        }

    } while (menu != 0);

    return 0;
}