//
// Created by 19shi on 10.04.2025.
//

#include "lib.h"

struct Circle calculateCircleParameters(float radius) {
    struct Circle circle;
    circle.radius = radius;
    circle.diameter = 2 * radius;
    circle.area = PI * radius * radius;
    circle.perimeter = 2 * PI * radius;
    return circle;
}
void inputCircle(struct Circle circles[], int *count) {
    if (*count >= MAX_CIRCLES) {
        printf("Достигнуто максимальное количество кругов (%d).\n", MAX_CIRCLES);
        return;
    }
    float radius;
    printf("Введите радиус круга: ");
    scanf("%f", &radius);
    scanf("%*c"); // Очищаем буфер
    // Проверка на корректность введенного значения
    if (radius <= 0) {
        printf("Ошибка: радиус должен быть положительным числом.\n");
        return;
    }
    circles[*count] = calculateCircleParameters(radius);// Вычисляем параметры круга и сохраняем их в массив
    (*count)++;
    printf("Круг с радиусом %.2f успешно добавлен.\n", radius);
}
void displayCircleByRadius(struct Circle circles[], int count, float targetRadius) {
    int found = 0;
    printf("\nИнформация о круге с радиусом %.2f \n", targetRadius);
    for (int i = 0; i < count; i++) {
        if (circles[i].radius == targetRadius) {
            printf("Радиус: %.2f\n", circles[i].radius);
            printf("Диаметр: %.2f\n", circles[i].diameter);
            printf("Площадь: %.2f\n", circles[i].area);
            printf("Длина окружности: %.2f\n", circles[i].perimeter);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Круг с радиусом %.2f не найден.\n", targetRadius);
    }
}