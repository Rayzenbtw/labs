#include "lib.h"

int main(){
    char *psent = malloc(MAXL);
    if (psent == NULL){
        printf("Помилка виділення пам'яті\n");
        return 1;
    }
    int wordnum = 0;
    char ch = getchar();
    ch = removing_spaces(ch);// Пропускаем все пробелы и символы новой строки перед началом обработки

    while(ch != '.'){
        wordnum++;
        readword(psent, ch);
        if(wordnum % 2 == 1) {//смотрим на номер слова, если нечетное то оставляем, если четное то реверс показ
            printword(psent);}
        else{
            Print_rewerse(psent);}
        ch = getchar();//cлед символ
        ch = removing_spaces(ch);//удаляем пробелы
        if(ch != '.'){
            putchar(' ');
        }
    }
    putchar('\n');
    return 0;
}