#include "lib.h"

int findBooksByAuthor(Book books[], int total, const char *lname, Book results[]) {
    int count = 0;
    for (int i = 0; i < total; i++) {
        if (strcmp(books[i].author.lname, lname) == 0) {
            results[count++] = books[i];
        }
    }
    return count;
}
void printBook(Book b) {
    printf("\nНазва: %s\n", b.title);
    printf("Автор: %s %s\n", b.author.fname, b.author.lname);
    printf("Сторінки: %d\n", b.pages);
    printf("Ціна: %.2f грн\n", b.price);
}


