#include "lib.h"


void combine_strings(int n, int m, char *str1, char *str2, char *result) {
    strncpy(result, str1, n); // Копіюємо перші n символів першого рядка
    result[n] = '\0'; // Завершення рядка
    strncat(result, str2 + strlen(str2) - m, m); // Додаємо останні m символів другого рядка
}
