//
// Created by 19shi on 28.03.2025.
//

#include "lib.h"

void lower(char * str){
    for(int i = 0; str[i]; i++)
      str[i] = tolower(str[i]);
}