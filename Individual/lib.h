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

void sortAnogramma(char *str);
bool isValid(char *text);
void findAnograma(char words[MAX_slov][MAX_len + 1], int wordCount);
int end(char* word, char* ending);
void removeln(char words[MAX_slov][MAX_len + 1], int* wordCount, char* ending);
int splitWords(char* text, char words[MAX_slov][MAX_len + 1]);
void combine_words(char words[MAX_slov][MAX_len + 1], int wordCount, char* result);
#endif //LIB_H
