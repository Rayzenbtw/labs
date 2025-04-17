#include "lib.h"

int main() {
    Car* myCar = inputCar();

    printCar(myCar);
    freeCar(myCar);

    return 0;

}