//
// Created by 19shi on 18.02.2025.
//

#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum Type {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE
    }Type;

void* allocateArr(int nums, Type type);//выделение памяти
void displayArr(void* array, int size, Type type);//отображение матрицы
void scanArr(void* array, int size, Type type);// ввод значений с клавиатуры
void* minfind(void* array, int size, Type type);//поиск минимума
void minOut(void* array, int size, Type type);//вывод минимума
void freeMem(void* arr);//освобождение памяти
#endif //LIB_H
