#ifndef LIB_H
#define LIB_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


#define MAX_len  11 // нулевой символ тоже символ, по задаче макс 10, +1 нулевой
#define MAX_slov 20
#define MIN_len 3 // с нулевым символом минимум два символа
#define MAX_TEXT 1000

void sortAnogramma(char *str);// принимает указатель на строку
bool isValid(char *text);// принимает строку, возвращает true если строка удовлетворяет условиям задачи, false если нет
void findAnograma(char words[MAX_slov][MAX_len + 1], int wordCount);//принимает массив слов и количество слов на входе, выводит анаграммы первого слова
int end(char* word, char* ending);//Принимает две строки, слово и суфікс, повертає 1 якщо слово закінчується на суфікс, 0 якщо ні
void removeln(char words[MAX_slov][MAX_len + 1], int* wordCount, char* ending);//Удаляет из массива words все слова, заканчивающиеся на ending, и обновляет значение wordCount, без возврата
int splitWords(char* text, char words[MAX_slov][MAX_len + 1]);//Разбивает строку text на слова и сохраняет их в массив words, возвращает количество найденных слов.
#endif //LIB_H
