#include "lib.h"

Car* inputCar() {
    Car* car = (Car*)malloc(sizeof(Car));
    if (car == NULL) {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }

    printf("Введите марку машины: ");
    fgets(car->brand, sizeof(car->brand), stdin);
    car->brand[strcspn(car->brand, "\n")] = '\0';

    printf("Введите модель машины: ");
    fgets(car->model, sizeof(car->model), stdin);
    car->model[strcspn(car->model, "\n")] = '\0';

    printf("Введите год выпуска: ");
    scanf("%d", &car->year);

    printf("Введите объём двигателя (в литрах): ");
    scanf("%f", &car->engineVolume);

    while (getchar() != '\n');

    return car;
}
void printCar(const Car* car) {
    if (car != NULL) {
        printf("Марка: %s\n", car->brand);
        printf("Модель: %s\n", car->model);
        printf("Год выпуска: %d\n", car->year);
        printf("Объём двигателя: %.1f л\n", car->engineVolume);
    }
}
void freeCar(Car* car) {
    free(car);
}