//Написати функцію для обчислення кількості елементів
//масиву, які задовольняють умові:
//1. чи є елемент масиву простим числом;
//2. чи є елемент масиву квадратом іншого числа.
//3. чи є додатнім sin(x) де х - елемент масиву
//Умову потрібно передавати в цю функцію як вказівник на функцію, в
//якій ця умова реалізована.
#include "lib.h"

int main(){
    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);

    int* arr = allocateArr(size);
    scanArr(arr, size);
    displayArr(arr, size);

    printf("Кількість простих чисел: %d\n", countIf(arr, size, isPrime));
    printf("Кількість квадратів чисел: %d\n", countIf(arr, size, isSquare));
    printf("Кількість чисел, для яких sin(x) > 0: %d\n", countIf(arr, size, isSinPositive));

    free(arr);
    return 0;
}