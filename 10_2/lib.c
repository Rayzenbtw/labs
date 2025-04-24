#include "lib.h"

// Введення категорії
Category inputCategory() {
    int c;
    do {
        printf("Категорія (0 - художня, 1 - словник, 2 - підручник): ");
        scanf("%d", &c);
    } while (c < 0 || c > 2);
    return (Category)c;
}

// Введення книги
void inputBook(Book* b) {
    printf("Назва: ");
    scanf(" %[^\n]", b->title);
    printf("Прізвище автора: ");
    scanf(" %[^\n]", b->author.surname);
    printf("Ім’я автора: ");
    scanf(" %[^\n]", b->author.name);
    printf("Ціна: ");
    scanf("%f", &b->price);
    printf("Рік видання: ");
    scanf("%d", &b->year);

    b->category = inputCategory();

    switch (b->category) {
        case FICTION:
            printf("Жанр: ");
            scanf(" %[^\n]", b->details.fiction.genre);
            printf("Прізвище ілюстратора: ");
            scanf(" %[^\n]", b->details.fiction.illustratorSurname);
            break;
        case DICTIONARY:
            printf("Кількість слів у словнику: ");
            scanf("%d", &b->details.wordCount);
            break;
        case TEXTBOOK:
            printf("Предметна галузь: ");
            scanf(" %[^\n]", b->details.textbook.subject);
            printf("Клас: ");
            scanf("%d", &b->details.textbook.grade);
            break;
    }
}

// Виведення категорії
void printCategory(Category c) {
    switch (c) {
        case FICTION: printf("Художня\n"); break;
        case DICTIONARY: printf("Словник\n"); break;
        case TEXTBOOK: printf("Підручник\n"); break;
    }
}

// Виведення книги
void printBook(Book b) {
    printf("\nНазва: %s\n", b.title);
    printf("Автор: %s %s\n", b.author.surname, b.author.name);
    printf("Ціна: %.2f\n", b.price);
    printf("Рік видання: %d\n", b.year);
    printf("Категорія: ");
    printCategory(b.category);

    switch (b.category) {
        case FICTION:
            printf("Жанр: %s\n", b.details.fiction.genre);
            printf("Ілюстратор: %s\n", b.details.fiction.illustratorSurname);
            break;
        case DICTIONARY:
            printf("Кількість слів: %d\n", b.details.wordCount);
            break;
        case TEXTBOOK:
            printf("Предмет: %s\n", b.details.textbook.subject);
            printf("Клас: %d\n", b.details.textbook.grade);
            break;
    }
}

// Пошук за категорією
void searchByCategory(Book books[], int n, Category c) {
    for (int i = 0; i < n; i++) {
        if (books[i].category == c) {
            printBook(books[i]);
        }
    }
}

// Пошук художніх книг за жанром
void searchFictionByGenre(Book books[], int n, const char* genre) {
    for (int i = 0; i < n; i++) {
        if (books[i].category == FICTION &&
            strcmp(books[i].details.fiction.genre, genre) == 0) {
            printBook(books[i]);
        }
    }
}

// Пошук за ціною
void searchByPrice(Book books[], int n, float min, float max) {
    for (int i = 0; i < n; i++) {
        if (books[i].price >= min && books[i].price <= max) {
            printf("\nНазва: %s\nАвтор: %s\nЦіна: %.2f\n",
                   books[i].title, books[i].author.surname, books[i].price);
        }
    }
}