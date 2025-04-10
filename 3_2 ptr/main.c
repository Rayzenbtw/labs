#include "lib.h"
#define SIZE 100
int main(){
    char *psent;  // Объявление как char *psent
    psent = malloc(100);  // Выделение памяти
    if (psent == NULL) {
        printf("Помилка виділення\n");
        return 1;
    }

    printf("Напишіть рядок\n");
    fgets(psent, 100, stdin);

    // Удаляем символ новой строки, если есть
    psent[strcspn(psent, "\n")] = 0;

    int words = kolichestvo_slov(psent);
    printf("Кількість слів:%d\n", words);

    int n;
    printf("Введіть номер слова: ");
    scanf("%d", &n);

    char* word = NSlovo(psent, n);
    if(word){
        printf("Слово #%d: %s\n", n, word);
        free(word);
    }
    else{
        printf("Слово не знайдено\n");
    }
    return 0;
}
