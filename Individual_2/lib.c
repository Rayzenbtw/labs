#include "lib.h"

enum Type inputType() {
    int type;
    printf("Оберіть тип велосипеда:\n");
    printf("1 - MOUNTAIN\n2 - ROAD\n3 - HYBRID\n4 - BMX\n5 - ELECTRIC\n> ");
    scanf("%d", &type);
    return (enum Type)type;
}
enum State inputState() {
    int state;
    printf("Стан велосипеда (1 - Новий, 2 - Б/у): ");
    scanf("%d", &state);
    return (enum State)state;
}
// Введення варіативної частини (union)
void inputSpecifics(union Specifics* specs, enum Type type) {
    switch (type) {
        case MOUNTAIN:
            printf("Введіть хід підвіски (мм): ");
        scanf("%d", &specs->suspensionTravel);
        break;
        case ROAD:
            printf("Введіть вагу рами (кг): ");
        scanf("%f", &specs->frameWeight);
        break;
        case HYBRID:
            printf("Введіть кількість передач: ");
        scanf("%d", &specs->gearCount);
        break;
        case BMX:
            printf("Введіть кількість пегів: ");
        scanf("%d", &specs->pegCount);
        break;
        case ELECTRIC:
            printf("Введіть назву акумулятора: ");
        scanf(" %49[^\n]", specs->electricData.battery);
        printf("Введіть крутний момент: ");
        scanf("%lf", &specs->electricData.torque);
        printf("Введіть ціну електросистеми: ");
        scanf("%lf", &specs->electricData.price_electro);
        printf("Введіть назву електросистеми: ");
        scanf(" %49[^\n]", specs->electricData.productname);
        printf("Стан електросистеми (1 - нова, 2 - б/у): ");
        scanf("%d", &specs->electricData.statement);
        break;
    }
}

// Введення повного об'єкта Bicycle
void inputBicycle(struct Bicycle* bike) {
    printf("Введіть бренд: ");
    scanf(" %49[^\n]", bike->brand);
    printf("Введіть розмір колеса (дюйми): ");
    scanf("%lf", &bike->wheelSize);
    printf("Введіть ціну: ");
    scanf("%lf", &bike->price);

    bike->type = inputType();
    bike->Bikestate = inputState();

    printf("Введіть висоту рами (см): ");
    scanf("%f", &bike->size.frameHeight);
    printf("Введіть довжину велосипеда (см): ");
    scanf("%f", &bike->size.length);

    inputSpecifics(&bike->specs, bike->type);
}
// Виведення типу
void printType(enum Type type) {
    const char* names[] = {"MOUNTAIN", "ROAD", "HYBRID", "BMX", "ELECTRIC"};
    printf("Тип велосипеда: %s\n", names[type]);
}
// Виведення стану
void printState(enum State state) {
    if (state == NEW)
        printf("Стан: Новий\n");
    else
        printf("Стан: Б/у\n");
}
// Виведення union
void printSpecifics(union Specifics* specs, enum Type type) {
    switch (type) {
        case MOUNTAIN:
            printf("Хід підвіски: %d мм\n", specs->suspensionTravel);
        break;
        case ROAD:
            printf("Вага рами: %.2f кг\n", specs->frameWeight);
        break;
        case HYBRID:
            printf("Кількість передач: %d\n", specs->gearCount);
        break;
        case BMX:
            printf("Кількість пегів: %d\n", specs->pegCount);
        break;
        case ELECTRIC:
            printf("Акумулятор: %s\n", specs->electricData.battery);
        printf("Крутний момент: %.2lf Нм\n", specs->electricData.torque);
        printf("Ціна електросистеми: %.2lf грн\n", specs->electricData.price_electro);
        printf("Модель електросистеми: %s\n", specs->electricData.productname);
        printf("Стан електросистеми: %s\n",
            specs->electricData.statement == NEW ? "нова" : "б/у");
        break;
    }
}
// Виведення всієї структури Bicycle
void printBicycle(struct Bicycle* bike) {
    printf("\n--- Інформація про велосипед ---\n");
    printf("Бренд: %s\n", bike->brand);
    printf("Розмір колеса: %.1lf дюймів\n", bike->wheelSize);
    printf("Ціна: %.2lf грн\n", bike->price);
    printType(bike->type);
    printState(bike->Bikestate);
    printf("Висота рами: %.1f см\n", bike->size.frameHeight);
    printf("Довжина: %.1f см\n", bike->size.length);
    printSpecifics(&bike->specs, bike->type);
}
//Фунцкія для починки велосипеда
void repairBicycle(struct Bicycle* bike) {
    if (bike->Bikestate == USED) {
        bike->Bikestate = NEW;
        printf("Велосипед \"%s\" відремонтовано. Стан: новий.\n", bike->brand);
    } else {
        printf("Велосипед \"%s\" вже новий. Ремонт не потрібен.\n", bike->brand);
    }
}
//Функція починки батареї
void replaceBattery(struct Bicycle* bike, const char* newBattery) {
    if (bike->type == ELECTRIC) {
        strncpy(bike->specs.electricData.battery, newBattery, 49);
        bike->specs.electricData.battery[49] = '\0';
        bike->specs.electricData.statement = NEW;
        printf("Акумулятор замінено на \"%s\". Стан — новий.\n", bike->specs.electricData.battery);
    } else {
        printf("Це не електровелосипед. Акумулятор відсутній.\n");
    }
}
//Фунцкія зміни ціни
void changePrice(struct Bicycle* bike, double newPrice) {
    if (newPrice > 0) {
        bike->price = newPrice;
        printf("Ціну велосипеда \"%s\" змінено на %.2lf грн.\n", bike->brand, bike->price);
    } else {
        printf("Ціна має бути додатньою!\n");
    }
}
//Функція для вводу масиву велосипедів
void inputBicyclesArray(struct Bicycle* bikes, int* count, int maxCount) {
    printf("Скільки велосипедів ви хочете додати (макс. %d)? ", maxCount);
    scanf("%d", count);

    if (*count > maxCount) {
        printf("Перевищено максимальну кількість. Встановлено %d.\n", maxCount);
        *count = maxCount;
    }

    for (int i = 0; i < *count; i++) {
        printf("\n--- Введення велосипеда #%d ---\n", i + 1);
        inputBicycle(&bikes[i]);
    }
}
//перевірка пароля адміністратора
int loginAsAdmin() {
    char password[50];
    printf("Введіть пароль адміністратора: ");
    scanf(" %49s", password);
    return strcmp(password, "admin123") == 0;
}
// меню адміністратора
void adminMenu(struct Bicycle* bikes, int* count, int maxCount) {
    if (!loginAsAdmin()) {
        printf("Невірний пароль. Доступ заборонено.\n");
        return;
    }

    int choice;
    do {
        printf("\n--- Меню адміністратора ---\n");
        printf("1. Починка велосипеда\n");
        printf("2. Заміна акумулятора\n");
        printf("3. Зміна ціни\n");
        printf("4. Додати нові велосипеди\n");
        printf("0. Назад\n> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int found = 0;
                for (int i = 0; i < *count; i++) {
                    if (bikes[i].Bikestate == USED) {
                        printf("[%d] ", i);
                        printBicycle(&bikes[i]);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("Немає велосипедів для ремонту.\n");
                    break;
                }
                int index;
                printf("Індекс велосипеда: ");
                scanf("%d", &index);
                if (index >= 0 && index < *count)
                    repairBicycle(&bikes[index]);
                else
                    printf("Невірний індекс.\n");
                break;
            }
            case 2: {
                int found = 0;
                for (int i = 0; i < *count; i++) {
                    if (bikes[i].type == ELECTRIC && bikes[i].specs.electricData.statement == USED) {
                        printf("[%d] ", i);
                        printBicycle(&bikes[i]);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("Немає батарей для заміни.\n");
                    break;
                }
                int index;
                printf("Індекс: ");
                scanf("%d", &index);
                if (index >= 0 && index < *count && bikes[index].type == ELECTRIC) {
                    char newBattery[50];
                    printf("Нова батарея: ");
                    scanf(" %49[^\n]", newBattery);
                    replaceBattery(&bikes[index], newBattery);
                } else {
                    printf("Невірний індекс.\n");
                }
                break;
            }
            case 3: {
                int index;
                printf("Індекс велосипеда: ");
                scanf("%d", &index);
                if (index >= 0 && index < *count) {
                    double newPrice;
                    printf("Нова ціна: ");
                    scanf("%lf", &newPrice);
                    changePrice(&bikes[index], newPrice);
                } else {
                    printf("Невірний індекс.\n");
                }
                break;
            }
            case 4:
                inputBicyclesArray(bikes, count, maxCount);
                break;
            case 0:
                printf("Вихід з адмін-меню.\n");
                break;
            default:
                printf("Невірний вибір.\n");
        }
    } while (choice != 0);
}

