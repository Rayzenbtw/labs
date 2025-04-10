#include "lib.h"

int main(void)
{
    int size;
    Type type;

    printf("Выберите тип данных (0 - int, 1 - float, 2 - double): ");
    scanf("%d", (int*)&type);

    printf(" размер : ");
    scanf("%d", &size);

    void* array = allocateArr(size, type);

    if (!array) {
        printf("нету масива!\n");
        return 1;
    }

    scanArr(array, size, type);
    displayArr(array, size, type);
    minOut(array, size, type);

    freeMem(array);

    return 0;
}
