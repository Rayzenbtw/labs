//
// Created by 19shi on 26.02.2025.
//

#include "lib.h"


int* allocateArr(int size) {
    return (int*)malloc(size * sizeof(int));
}

void scanArr(int* array, int size) {
    printf("Введите %d элементов:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
}
void displayArr(int* array, int size) {
    printf("Массив: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int extremum(int* arr, int size, int (*sravn)(int, int)) {
    if (size <= 0) {
        puts("Ошибка: некорректный размер массива");
        return 0;
    }
    int extremum = arr[0];
    for (int i = 1; i < size; ++i) {
        if (sravn(arr[i], extremum)) {
            extremum = arr[i];
        }
    }
    return extremum;
}
int sravnmax(int a, int b) {
    return a > b;
}

int sravnmin(int a, int b) {
    return a < b;
}
