#include "lib.h"
#define ANSWER "Kitty"
int main() {
    int attempts = 3;
    char try[SIZE];
    char anslower[SIZE];

    while(attempts > 0) {
        strcpy(anslower, ANSWER);
        lower(anslower);

        printf("Who said \"Meow\"?\n");
        fgets(try, SIZE, stdin);
        try[strlen(try) - 1] = '\0';

        lower(try);

        if (strcmp(try, anslower) == 0) {
            puts("Rightly!");
            return 0;
        }

        attempts--;
        if(attempts > 0)
            puts("No");
        else
            puts("No attempts. Answer: Kitty");
    }

    return 0;
}