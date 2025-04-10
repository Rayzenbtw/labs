//
// Created by 19shi on 19.02.2025.
//

#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
typedef enum Type {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE
    }Type;

void add(void* a, void* b, Type type, void* res);
void substraction(void* a, void* b, Type type, void* res);
void multiplication(void* a, void* b, Type type, void* res);
void division(void* a, void* b, Type type, void* res);


#endif //LIB_H
