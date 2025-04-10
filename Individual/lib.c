#include "lib.h"

void sortAnogramma(char *str){// функція, яка сортує букви у першому слові для пошуку анограмми за  алфавітним порядком
    int len = strlen(str); //довжина
    for (int i = 0; i < len - 1; i++) { // цикли для порівняння кожного симвлоу з минулим, доки не стануть за поярдком
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}
bool isValid(char *text){ //перевірка на те, чи задовільняє текст умові завдання
    int len = strlen(text);
    if (len == 0 || text[len - 1] != '.') return false;

    char tempText[MAX_TEXT]; // копіюємо щоб не змінювати початковий текст
    strcpy(tempText, text);

    char *token = strtok(tempText, " .");
    while (token != NULL){
        int wordLen = strlen(token);
        if(wordLen < MIN_len || wordLen > MAX_len)
            return false;
        for (int i = 0; i < wordLen; i++) {
            if (!islower(token[i])) return false; // перевірка на малі букви
        }
        token = strtok(NULL, " .");
    }
    return true;
};
void findAnograma(char *text){//пошук анограми за допомогою функції sortAnogramma та функцій з string.h
    char words[MAX_slov][MAX_len + 1];
    int wordCount = 0;
    char *token = strtok(text, " .");
    while (token != NULL && wordCount < MAX_slov) {
        strcpy(words[wordCount++], token);
        token = strtok(NULL, " .");
    }
    if (wordCount == 0)
        return;

    char sortedFirst[MAX_len + 1];

    strcpy(sortedFirst, words[0]);
    sortAnogramma(sortedFirst);

    printf("Анаграммы первого слова: ");
    for (int i = 1; i < wordCount; i++) {
        char sortedWord[MAX_len+ 1];
        strcpy(sortedWord, words[i]);
        sortAnogramma(sortedWord);
        if (strcmp(sortedFirst, sortedWord) == 0) {
            printf("%s ", words[i]);
        }
    }
    printf("\n");
}
int end(char* word, char* ending) {//перевірка чи закінчується слово на заданий рядок
    int wordlen = strlen(word);
    int endlen = strlen(ending);
    if(wordlen < endlen)
        return 0;
    return strcmp(word + wordlen - endlen, ending) == 0;
}

void removeln(char* text, char* ending) { char result[MAX_TEXT] = ""; //видалення слова яке повторюється
    char word[MAX_len + 1];
    int index = 0;
    for (int i = 0; i <= strlen(text); i++){
        if(isspace(text[i]) || text[i] == '.' || text[i] == '\0') {
            if(index > 0){
                word[index] = '\0';
                if (!end(word, ending)) {
                    strcat(result, word);
                    if (text[i] != '\0') {
                        strcat(result, " ");
                    }
                }
                index = 0;
            }
            if (text[i] == '.') {
                strcat(result, ".");
            }
        } else {
            word[index++] = text[i];
        }
    }
    strcpy(text, result);
}
