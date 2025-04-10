#include "lib.h"

int main() {
    char words[LIM] [SIZE];
    char temp[SIZE];
    int i = 0;

printf("Bвeдіть %d слів, які починаються літерою b:\n", LIM);
    while (i < LIM){
    scanf("%39s", temp);
    if (temp[0]!= 'b')
        printf("%s не починається літерою b!\n ", temp);
    else
        strcpy(words[i] , temp); i++;
    }
    puts("Список отриманих слів:");
    for (i = 0; i < LIM; i++ )
    printf("%s\n",words[i]);
    return 0;
}