#include "lib.h"
int main() {
    struct Author myAuthor;

    myAuthor = inputAuthor();
    printAuthor(myAuthor);

    return 0;
}