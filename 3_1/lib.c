//
// Created by 19shi on 05.03.2025.
//

#include "lib.h"

char removing_spaces(char ch) {
    while(isspace(ch)){
        ch = getchar();}
    return ch;
}
void readword(char* word, char ch) {
    int i = 0;
    while(ch != '.' && ch != '\n' && !isspace(ch)) {// Читаем символы до пробела, точки или конца строки
        word[i++] = ch;
        ch = getchar();
    }
    word[i] = '\0';
}
void printword(char* word) {
    for(int i = 0; word[i] != '\0'; i++) {//проверка на то, чтобы слово не закончилось(ASCII 0)
        putchar(word[i]);
    }
}
void Print_rewerse(char* word) {
    int dlinna = strlen(word);
    for(int i = dlinna - 1; i>=0;i--)
        putchar(word[i]);
}
