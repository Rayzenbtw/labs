//
// Created by 19shi on 05.03.2025.
//

#include "lib.h"


int kolichestvo_slov(const char* text){
    int len = strlen(text);
    int count = 0;
    for(int q = 0;q < len;q++){
        if(isspace(text[q])){
            continue;
        }
        else if(!isspace(text[q]) && text[q + 1] == ' ' && text[q+2]!= '\0'){
            count++;
        }
    }
    if(!isspace(text[len]))
        count++;
    return count;
}
char* NSlovo(const char* text, int n){
    int len = strlen(text);
    int count = 0;
    char* new_slovo = (char*)malloc(MAXL);
    if(new_slovo == NULL){
        return NULL;
    }
    for(int q = 0;q < len;q++){
        int g = 0;
        while(q < len && isspace(text[q])){
            q++;
        }
        if(q < len && !isspace(text[q])){
            while(q < len && text[q] != ' '){
                new_slovo[g++] = text[q++];
            }
            new_slovo[g] = '\0';
            count++;
        }
        if(count == n){
            return new_slovo;
        }
    }
    free(new_slovo);
    return NULL;
}