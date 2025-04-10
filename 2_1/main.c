//
// Created by 19shi on 24.02.2025.
//Створити функцію, яка формує масив зі значень
//вхідного масиву, які кратні заданому числу і повертає адресу
//цього масиву.
//

#include "lib.h"

int main() {
    int* ptrarr = NULL;
    int arr[] = {89, 25, 23, 710, 42, 50010};
    int size = sizeof(arr) / sizeof(int);
    int d = 5;
    int result_size;

    ptrarr = fun_arr(arr, size, d, &result_size);

    if (ptrarr) {
        printf("кратные %d: ", d);
        displayArr(ptrarr, result_size, TYPE_INT);// показываем массив
        free(ptrarr);
    }
    else {
        printf("нет кратных\n");
    }

    return 0;
}


