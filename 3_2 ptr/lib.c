//
// Created by 19shi on 05.03.2025.
//

#include "lib.h"


int kolichestvo_slov(const char* text){//определяем количество слов
    int len = strlen(text);
    int count = 0;
    for(int q = 0;q < len;q++){
        if(isspace(text[q])){
            continue;
        }
        else if(!isspace(text[q]) && text[q + 1] == ' ' && text[q+2]!= '\0'){ // проверка чтоб не біло пробела и символа конца рядка(в другом случае выводит ошибочное значение)
            count++;
        }
    }
    if(!isspace(text[len]))
        count++;//увеличиваем значение счетчика на 1
    return count;//возвращаем количество
}
char* NSlovo(const char* text, int n){// віводим нное слово
    int len = strlen(text);
    int count = 0;
    char* new_slovo = (char*)malloc(MAXL);// віделяем амять маллок на макс длинну
    if(new_slovo == NULL){
        return NULL;
    }
    for(int q = 0;q < len;q++){
        int i = 0;
        while(q < len && isspace(text[q])){//пока у нас счетчик меньше чем длинна и текст пропускает пробелы
            i++;
        }
        if(q < len && !isspace(text[q])){// Проверяетне вышли за границы строки  и чтоб не біло пробела
            while(q < len && text[q] != ' '){ // пока не пробел копируем наш текст в отдельній массив new_slovo
                new_slovo[i++] = text[q++];
            }
            new_slovo[i] = '\0';//добавляем в конце конец строки(0 символ по ascii)
            count++;
        }
        if(count == n){ //если слолво нное то возвращаем его
            return new_slovo;
        }
    }
    free(new_slovo);//освобождаем переменную для копирования
    return NULL;
}