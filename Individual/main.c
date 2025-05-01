#include "lib.h"

int main() {
    char text[MAX_TEXT];
    char ending[MAX_len];
    int isTextValid = 0;
    //3 спропи
    for (int q = 0; q < 3; q++) {
        printf("Введіть текст: ");
        fgets(text, MAX_TEXT, stdin);
        text[strchr(text, '\n') != NULL ? strchr(text, '\n') - text : strlen(text)] = '\0'; // Убираем перевод строки
        char tempText[MAX_TEXT];
        strcpy(tempText, text);
        if (isValid(tempText)) {
            isTextValid = 1;
            break;
        }
        printf("Текст не задовільняє умові, введіть ще раз.\n");
    }

    if (!isTextValid) {
        printf("Перевищено кількість спроб. \n");
        return 1; // Повертаємо код помилки
    }

    // Розбиваємо текст на слова
    char words[MAX_slov][MAX_len + 1];
    int wordCount = splitWords(text, words);

    // Знаходимо анаграми
    findAnograma(words, wordCount);

    // Запитуємо суфікс і видаляємо відповідні слова
    printf("Введіть суфікс: ");
    scanf("%s", ending);
    removeln(words, &wordCount, ending);

    printf("Оновлений текст: ");
    for (int i = 0; i < wordCount; i++) {
        printf("%s", words[i]);
        if (i < wordCount - 1)
            printf(" ");
    }
    printf(".\n");

    return 0;
}
