#include "lib.h"
int main() {
    int n, m;
    char str1[100], str2[100], result[200];

    printf("Введіть n: ");
    scanf("%d", &n);
    printf("Введіть m: ");
    scanf("%d", &m);
    getchar(); // Очищення буфера після scanf

    printf("Введіть перший рядок: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Видаляємо символ нового рядка

    printf("Введіть другий рядок: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Видаляємо символ нового рядка

    if (n > strlen(str1)) n = strlen(str1); // Перевірка довжини n
    if (m > strlen(str2)) m = strlen(str2); // Перевірка довжини m

    combine_strings(n, m, str1, str2, result);
    printf("Результат: %s\n", result);

    return 0;
}