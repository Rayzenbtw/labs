//
// Created by 19shi on 18.02.2025.
//

#include "lib.h"

void swap1(void* a,void* b, Type type) {
    switch (type) {
        case TYPE_INT:
            int temp_int = *(int*)a;
            *(int*)a = *(int*)b;
            *(int*)b = temp_int;
        break;
        case TYPE_FLOAT:
            float temp_float = *(float*)a;
            *(float*)a = *(float*)b;
            *(float*)b = temp_float;
        break;
        case TYPE_DOUBLE:
            double temp_double = *(double*)a;
            *(double*)a = *(double*)b;
            *(double*)b = temp_double;
        break;
    }
}
void swap_memcpy(void* a, void* b, size_t size){
    char *p1 = (char *)a;
    char *p2 = (char *)b;
    for (size_t i = 0; i < size; i++) {
        unsigned char temp = p1[i];
        p1[i] = p2[i];
        p2[i] = temp;
    }
}
