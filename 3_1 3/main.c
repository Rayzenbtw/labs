#include "lib.h"
char word[]="My name is anton";
int element = 0;
char my_getchar() {
    return word[element++];
}
int main() {
    char sentence[] = "My name is anton";
    int word_count = 0;

    char* part = strtok(sentence, " ");//strtok разбивает наш рядок на части, пробел -  раздеитель, то есть делм по пробелу, всё остальное в програме неизменно
    while (part != NULL) {
        word_count++;
        if (word_count % 2 == 1) {
            printword(part);
        } else {
            Print_rewerse(part);
        }

        part = strtok(NULL, " ");
        if (part != NULL) {
            putchar(' ');
        }
    }
    putchar('\n');

    return 0;
}
