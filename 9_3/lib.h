
#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char brand[50];
    char model[50];
    int year;
    float engineVolume;
} Car;

Car* inputCar();
void printCar(const Car* car);
void freeCar(Car* car);

#endif //LIB_H
