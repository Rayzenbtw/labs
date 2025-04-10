//
// Created by 19shi on 26.02.2025.
//

#include "lib.h"

double poh(double x, double dx, double (*fun)(double)) {
    double f_x = fun(x);    // Значение функции в точке x
    double f_dx = fun(x + dx); // Значение функции в точке x + dx
    double pr = (f_dx / f_x - 1.0) * f_x / dx;
    return pr;
}

double square_function(double x) {
    return x * x;
}

double sin_function(double x) {
    return sin(x);
}

double exp_function(double x) {
    return exp(x);
}

double polynom(double x) {
    return x * x * x - 2 * x * x + 3 * x - 5;
}
