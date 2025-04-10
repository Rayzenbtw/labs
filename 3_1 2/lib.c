//
// Created by 19shi on 05.03.2025.
//

#include "lib.h"

char removing_spaces(char ch) {
    while(isspace(ch)){
        ch = getchar();}
    return ch;
}
void readword(char* word, char ch) {//
    int i = 0;//счетчик
    while(ch !='.' && !isspace(ch)) {// проверка чтоб не было точки(крапка не є символом рядка,це ознака закінчення введення)
    word[i++] = ch;ch = getchar();
    }
    word[i] = '\0';
}
void printword(char* word) {
    for(int i = 0; word[i] != '\0'; i++) {//проверка на то, чтобы слово не закончилось(ASCII значення 0)
        putchar(word[i]);
    }
}
void Print_rewerse(char* word) {
    int dlinna = strlen(word);// стрлен возвращает беззнаковый тип, поэтому использую именно его, хотя разнцы с интом не будет(для нас)
    for(int i = dlinna - 1; i>=0;i--)// не использую size_t так как вывод идет неправильным, всё таки инт это правильный вывод
        putchar(word[i]);
}
