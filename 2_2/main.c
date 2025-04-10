//Розробити програму з такими функціями:
//1. Створення масиву чисел одного з трьох типів ( int, char або double)
//з динамічним відділенням пам’яті.
//2. Введення значень масиву з клавіатури
//3. Виведення масиву на екран
//4. Знаходження мінімального значення цього масиву (функція
//повертає це значення).
//5. Виведення мінімального значення масиву.
//6. Після обробки даних звільняє пам'ять, відділену під масив.
//використовуючи функцію, як в яка в якості одного з аргументів буде приймати вказівник
//на функцію.
#include "lib.h"

int main(void)
{
    int size;
    Type type;

    printf("Выберите тип данных (0 - int, 1 - float, 2 - double): ");
    scanf("%d", (int*)&type);

    printf(" размер : ");
    scanf("%d", &size);

    void* array = allocateArr(size, type);

    if (!array) {
        printf("нету масива!\n");
        return 1;
    }

    // Вибір відповідної функції зчитування
    void (*scanFunc)(void*);
    size_t elemSize;

    switch (type) {
        case TYPE_INT:
            scanFunc = scanInt;
        elemSize = sizeof(int);
        break;
        case TYPE_FLOAT:
            scanFunc = scanFloat;
        elemSize = sizeof(float);
        break;
        case TYPE_DOUBLE:
            scanFunc = scanDouble;
        elemSize = sizeof(double);
        break;
        default:
            printf("Неверный тип данных.\n");
        freeMem(array);
        return 1;
    }

    // Виклик функцій
    scanArr(array, size, elemSize, scanFunc);
    displayArr(array, size, type);
    minOut(array, size, type);

    // Звільнення пам'яті
    freeMem(array);

    return 0;
}
