#include "lib.h"

int main() {
    char text[MAX_TEXT];
    char ending[MAX_len];
    for (int q = 0; q < 10; q++) {// 10 спроб на ввод
        printf("Введіть текст: ");
        fgets(text, MAX_TEXT, stdin);
        text[strchr(text, '\n') != NULL ? strchr(text, '\n') - text : strlen(text)] = '\0';// Убираем перевод строки
        char tempText[MAX_TEXT];
        strcpy(tempText, text);
        if (isValid(tempText))
            break;
        printf("Текст не задовільняє умові, введіть ща раз.\n");
    }
    findAnograma(text);

    printf("Введіть суфікс: ");
    scanf("%s", ending);
    removeln(text, ending);

    printf("Оновлений текст: %s\n", text);



    return 0;
}