// Завдання 2. Написати 2 варіанти функції, яка обмінює місцями
// значення двох змінних довільних типів. Ця функція матиме три
// аргументи – вказівники на змінні, які необхідно обміняти місцями та їх
// розмір. Реалізувати для таких типів: int; double, unsigned long
// Варіант І з виділенням пам’яті під вказівники
#include "lib.h"

int main(void) {
    int typeChoice;
    Type type;
    char dia;

    // Ввод типа данных
    printf("Choose type (1: int, 2: float, 3: double): ");
    scanf("%d", &type);

    void *a, *b;
    // Ввод значений
    if (type == TYPE_INT) {
        a = malloc(sizeof(int));
        b = malloc(sizeof(int));
        printf("Enter first integer number: ");
        scanf("%d", a);
        printf("Enter second integer number: ");
        scanf("%d", b);

        // Обмен значениями
        swap1(a, b, type);
        printf("Swapped values: a = %d, b = %d\n", *(int*)a, *(int*)b);
        free(a);
        free(b);
    }
     else if (type == TYPE_FLOAT) {
         a = malloc(sizeof(float));
         b = malloc(sizeof(float));
         printf("Enter first float number: ");
        scanf("%f", a);
        printf("Enter second float number: ");
        scanf("%f", b);

        // Обмен значениями
        swap1(a, b, type);
        printf("Swapped values: a = %f, b = %f\n", *(float*)a, *(float*)b);
         free(a);
         free(b);
    } else if (type == TYPE_DOUBLE) {
        a = malloc(sizeof(double));
        b = malloc(sizeof(double));
        printf("Enter first double number: ");
        scanf("%lf", a);
        printf("Enter second double number: ");
        scanf("%lf", b);

        // Обмен значениями
        swap1(a, b, type);
        printf("Swapped values: a = %lf, b = %lf\n", *(double*)a, *(double*)b);
        free(a);
        free(b);
    }

    return 0;
}
