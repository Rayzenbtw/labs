//
// Created by 19shi on 29.03.2025.
//
#include "lib.h"

int main() {
    char un[] = "університет! ";
    char name [SIZE] = "Каразінський ";
    if(strlen(name) + strlen(un) < SIZE) {
        strncat(name, un, SIZE - strlen(name) - 1);
        printf (" %s%s\n", "VIVAT ", name );
        return 0;
    }

    else {
        printf (" %s%s\n", "ERROR" );
        return 0;
    }
}