//
// Created by 19shi on 26.02.2025.
//

#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>


typedef enum {
  TYPE_INT = 1 ,
  TYPE_FLOAT,
  TYPE_DOUBLE
} Type;

int sravnmin(int a, int b);
int sravnmax(int a, int b);
int extremum(int* arr, int size, int (*compare)(int, int));
int* allocateArr(int size);
void scanArr(int* array, int size);
void displayArr(int* array, int size);

#endif //LIB_H
