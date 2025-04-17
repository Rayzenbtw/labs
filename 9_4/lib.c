#include "lib.h"

Car* inputCar() {
    Car* car = (Car*)malloc(sizeof(Car));
    if (car == NULL) {
        printf("Помилка виділення пам’яті для структури!\n");
        exit(1);
    }

    char temp[100];
    printf("Введіть марку авто: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0';  // Видаляємо символ нового рядка

    car->brand = (char*)malloc(strlen(temp) + 1);
    if (car->brand == NULL) {
        printf("Помилка виділення пам’яті для рядка!\n");
        free(car);
        exit(1);
    }
    strcpy(car->brand, temp);

    printf("Введіть рік випуску: ");
    scanf("%d", &car->year);
    while (getchar() != '\n'); // очищення буфера

    return car;
}

void printCar(const Car* car) {
    if (car != NULL) {
        printf("Марка: %s\n", car->brand);
        printf("Год выпуска: %d\n", car->year);
    }
}
void freeCar(Car* car) {
    free(car);
}