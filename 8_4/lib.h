
#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CIRCLES 100
#define PI 3.14159265358979323846

struct Circle {
    float radius;
    float diameter;
    float area;
    float perimeter;
};

struct Circle calculateCircleParameters(float radius);// параметрі кругв
void inputCircle(struct Circle circles[], int *count);//ввод круга
void displayCircleByRadius(struct Circle circles[], int count, float targetRadius);// отображение круга


#endif //LIB_H
