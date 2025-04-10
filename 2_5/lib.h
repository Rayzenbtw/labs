//
// Created by 19shi on 26.02.2025.
//

#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int num);
int isSquare(int num);
int isSinPositive(int num);
int countIf(int* arr, int size, int (*condition)(int));
int* allocateArr(int size);
void scanArr(int* array, int size);
void displayArr(int* array, int size);


#endif //LIB_H
