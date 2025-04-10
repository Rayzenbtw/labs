//
// Created by 19shi on 18.02.2025.
//

#include "lib.h"

void* allocateArr(int size, Type type) {
    switch (type) {
        case TYPE_INT:
            return malloc(size * sizeof(int));
        case TYPE_FLOAT:
            return malloc(size * sizeof(float));
        case TYPE_DOUBLE:
            return malloc(size * sizeof(double));
        default:
            return NULL;
    }
}
void scanInt(void* ptr) {
    scanf("%d", (int*)ptr);
}

void scanFloat(void* ptr) {
    scanf("%f", (float*)ptr);
}

void scanDouble(void* ptr) {
    scanf("%lf", (double*)ptr);
}

// Функція для зчитування масиву з переданою функцією зчитування
void scanArr(void* array, int size, size_t elemSize, void (*scanFunc)(void*)) {
    printf("Введіть %d елементів:\n", size);
    for (int i = 0; i < size; i++) {
        scanFunc((char*)array + i * elemSize);
    }
}
void displayArr(void* array, int size, Type type) {
    printf("Масив: ");
    for (int i = 0; i < size; i++) {
        switch (type) {
            case TYPE_INT:
                printf("%d ", ((int*)array)[i]);
            break;
            case TYPE_FLOAT:
                printf("%f ", ((float*)array)[i]);
            break;
            case TYPE_DOUBLE:
                printf("%lf ", ((double*)array)[i]);
            break;
        }
    }
    printf("\n");
}
void* minfind(void* array, int size, Type type) {
    if (size <= 0) return NULL;

    void* min = array;
        switch (type) {
            case TYPE_INT:
                min = malloc(sizeof(int));
                *(int*)min = *(int*)array;
                for(int i = 1; i < size; i++)
                    if (((int*)array)[i] < *(int*)min) *(int*)min = ((int*)array)[i];
            break;
            case TYPE_FLOAT:
                min = malloc(sizeof(float));
                *(float*)min = *(float*)array;
                for(int i = 1; i < size; i++)
                    if (((float*)array)[i] < *(float*)min) *(float*)min = ((float*)array)[i];
            break;
            case TYPE_DOUBLE:
                min = malloc(sizeof(double));
                *(double*)min = *(double*)array;
                for(int i = 1; i < size; i++)
                    if (((double*)array)[i] < *(double*)min) *(double*)min = ((double*)array)[i];
            break;
        }

    return min;
}
void minOut(void* array, int size, Type type) {
    void* min = minfind(array, size, type);
    if (!min) {
        printf("пустой масив.\n");
        return;
    }
    printf("Минимум: ");
    switch (type) {
        case TYPE_INT:
            printf("%d\n", *(int*)min);
        break;
        case TYPE_FLOAT:
            printf("%f\n", *(float*)min);
        break;
        case TYPE_DOUBLE:
            printf("%lf\n", *(double*)min);
        break;
    }
}
void freeMem(void* arr) {
    free(arr);
}

