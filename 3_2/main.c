#include "lib.h"
int main(){
    char text[MAXL];// оголошення рядка першим варіантом
    printf("Напишіть рядок\n");
    fgets(text, 100, stdin);

    int words = kolichestvo_slov(text);
    printf("Кількість слів:%d\n", words);

    int n;
    printf("Введіть номер слова: ");
    scanf("%d", &n);

    char* word = NSlovo(text, n);
    if(word){
        printf("Слово #%d: %s\n", n, word);
        free(word);
    }
    else{
        printf("Слово не знайдено\n");
    }
    return 0;
}
