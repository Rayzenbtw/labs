#include "lib.h"

int main() {
    struct Circle circles[MAX_CIRCLES];
    int circleCount = 0;
    int choice;
    float searchRadius;

    do {
        printf("\nМеню:\n");
        printf("1. Добавить новый круг\n");
        printf("2. Вывести информацию о круге по радиусу\n");
        printf("0. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);
        scanf("%*c"); // Очищаем буфер

        switch (choice) {
            case 1:
                inputCircle(circles, &circleCount);
            break;

            case 2:
                printf("Введите радиус круга для поиска: ");
            scanf("%f", &searchRadius);
            scanf("%*c"); // Очищаем буфер
            displayCircleByRadius(circles, circleCount, searchRadius);
            break;

            case 0:
                printf("Программа завершена.\n");
            break;

            default:
                printf("Неверный выбор. Пожалуйста, попробуйте снова.\n");
        }

    } while (choice != 0);

    return 0;
}