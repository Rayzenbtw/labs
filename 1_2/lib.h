//
// Created by 19shi on 18.02.2025.
//

#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>

typedef enum Type {
    TYPE_INT = 1,
    TYPE_FLOAT,
    TYPE_DOUBLE
    }Type;

void swap1(void* a,void* b, Type type);
void swap_memcpy(void* a, void* b, size_t size);

#endif //LIB_H
