#include "lib.h"

int main() {
    Book books[MAXL] = {
        {"Kobzar", {"Taras", "Shevchenko"}, 300, 299.99},
        {"Haidamaky", {"Taras", "Shevchenko"}, 960, 420.00},
        {"The Art of Invisibility:", {"Kevin ", "Mitnick"}, 250, 280.00}
    };

    char searchLname[50];
    printf("Введіть прізвище автора: ");
    scanf("%s", searchLname);

    Book results[MAXL];
    int found = findBooksByAuthor(books, 3, searchLname, results);

    if (found > 0) {
        printf("\nЗнайдено %d книг(и):\n", found);
        for (int i = 0; i < found; i++) {
            printBook(results[i]);
        }
    } else {
        printf("\nКниги не знайдено.\n");
    }

    return 0;
}
