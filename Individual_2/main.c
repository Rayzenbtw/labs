#include "lib.h"

#define MAX_BIKES 100

int main() {
    struct Bicycle bikes[MAX_BIKES];
    int count = 0;

    int choice;
    do {
        printf("\n--- Головне меню ---\n");
        printf("1. Додати велосипед\n");
        printf("2. Показати всі велосипеди\n");
        printf("3. Увійти як адміністратор\n");
        printf("0. Вихід\n> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count < MAX_BIKES)
                    inputBicycle(&bikes[count++]);
                else
                    printf("Досягнуто максимуму велосипедів!\n");
            break;
            case 2:
                for (int i = 0; i < count; i++) {
                    printf("\n[%d] ", i);
                    printBicycle(&bikes[i]);
                }
            break;
            case 3:
                adminMenu(bikes, &count, MAX_BIKES);
            break;
            case 0:
                printf("До побачення!\n");
            break;
            default:
                printf("Невірний вибір!\n");
        }
    } while (choice != 0);

    return 0;
}
