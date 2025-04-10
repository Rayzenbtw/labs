//
// Created by 19shi on 19.02.2025.
//

#include "lib.h"

void add(void* a, void* b, Type type, void* res) {
    switch (type) {
        case TYPE_INT:
            *(int*)res = *(int*)a + *(int*)b;
        break;
        case TYPE_FLOAT:
            *(float*)res = *(float*)a + *(float*)b;
        break;
        case TYPE_DOUBLE:
            *(double*)res = *(double*)a + *(double*)b;
        break;
        default:
            printf("wrong type.\n");
        break;
    }
}

    void substraction(void* a, void* b, Type type, void* res) {
    switch (type) {
        case TYPE_INT:
            *(int*)res = *(int*)a - *(int*)b;
        break;
        case TYPE_FLOAT:
            *(float*)res = *(float*)a - *(float*)b;
        break;
        case TYPE_DOUBLE:
            *(double*)res = *(double*)a - *(double*)b;
        break;
        default:
            printf("wrong type.\n");
        break;
    }
}
void multiplication(void* a, void* b, Type type, void* res) {
    switch (type) {
        case TYPE_INT:
            *(int*)res = *(int*)a * *(int*)b;
        break;
        case TYPE_FLOAT:
            *(float*)res = *(float*)a * *(float*)b;
        break;
        case TYPE_DOUBLE:
            *(double*)res = *(double*)a * *(double*)b;
        break;
        default:
            printf("wrong type.\n");
        break;
    }
}

void division(void* a, void* b, Type type, void* res) {
    switch (type) {
        case TYPE_INT:
            if (*(int*)b != 0)
                *(int*)res = *(int*)a / *(int*)b;
            else
                printf("division by 0\n");
        break;
        case TYPE_FLOAT:
            if (*(float*)b != 0.0f)
                *(float*)res = *(float*)a / *(float*)b;
            else
                printf("division by 0\n");
        break;
        case TYPE_DOUBLE:
            if (*(double*)b != 0.0)
                *(double*)res = *(double*)a / *(double*)b;
            else
                printf("division by 0\n");
        break;
        default:
            printf("wrong type.\n");
        break;
    }
}