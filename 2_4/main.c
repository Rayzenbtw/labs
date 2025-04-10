//Написати функцію для визначення екстремуму
//(максимального або мінімального) елемента масиву, з аргументами:
//адреса масиву, розмір масиву і вказівник на функцію для порівняння
//значень.
#include "lib.h"


int main(){
    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);

    int* arr = allocateArr(size);
    if (!arr) {
        puts("Ошибка выделения памяти");
        return 1;
    }

    scanArr(arr, size);
    displayArr(arr, size);

    int maxVal = extremum(arr, size, sravnmax);
    int minVal = extremum(arr, size, sravnmin);

    printf("Максимум: %d\n", maxVal);
    printf("Минимум: %d\n", minVal);

    free(arr);
    return 0;
}