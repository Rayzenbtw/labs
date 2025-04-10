//
// Created by 19shi on 26.02.2025.
//

#include "lib.h"


// Функція для перевірки, чи є число простим
int isPrime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Функція для перевірки, чи є число квадратом іншого числа
int isSquare(int num) {
    int root = sqrt(num);
    return root * root == num;
}

// Функція для перевірки, чи синус числа додатний
int isSinPositive(int num) {
    return sin(num) > 0;
}

// Функція для підрахунку елементів, що задовольняють певну умову
int countIf(int* arr, int size, int (*condition)(int)) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (condition(arr[i])) {
            count++;
        }
    }
    return count;
}

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