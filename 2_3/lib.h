//
// Created by 19shi on 26.02.2025.
//

#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <math.h>

double poh(double x, double dx, double (*fun)(double));
double square_function(double x);
double sin_function(double x);
double exp_function(double x);
double polynom(double x);

#endif //LIB_H
