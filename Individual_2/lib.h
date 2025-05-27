#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum Type {
    MOUNTAIN = 1,
    ROAD,
    HYBRID,
    BMX,
    ELECTRIC
};
enum State {
    NEW = 1,
    USED = 2
};

// розміри велосипеда
struct Dimensions {
    float frameHeight;
    float length;
};

union Specifics {
    int suspensionTravel;  // для горного
    float frameWeight;     // для доролжного
    int gearCount;         // для гибридного
    int pegCount;          // для бмх

    struct {
        char battery[50];         // акумулятор
        double torque;     // крутний момент
        double price_electro;          // ціна електросистеми
        char productname[50];  // назва електросистеми
        int statement;           // стан: 1 — новий, 2 — б/у
    } electricData; // для ELECTRIC
};

// Основна структура — велосипед
struct Bicycle {
    char brand[50];               // бренд
    double wheelSize;                // розмір колеса
    double price;                  // ціна
    enum Type type;               // тип
    enum State Bikestate;         // стан
    struct Dimensions size;       // габарити
    union Specifics specs;        // спеціальні параметри
};

enum Type inputType(); //ввод типу, на вхід - нічого, на вихід - тип який вводить коричтувач
enum State inputState();//ввод стану, на вхід - нічого, на вихід - стан який вводить коричтувач
void inputSpecifics(union Specifics* specs, enum Type type);//приймає обєднання, та тип,на вихід - нічого, записує специфікації в юніон
void inputBicycle(struct Bicycle* bike);//приймає велосипед, на вихід - нічого, заповнює структуру велосипеда
void printType(enum Type type);//приймає тип, на вихід - нічого, виводить тип
void printState(enum State state);//приймає стан, на вихід - нічого, виводить стан
void printSpecifics(union Specifics* specs, enum Type type);//приймає обєднання, та тип, на вихід - нічого, виводить специфікації
void printBicycle(struct Bicycle* bike, int index);//приймає велосипед, та індекс, на вихід - нічого, виводить інформацію про велосипед
void repairBicycle(struct Bicycle* bike);//приймає велосипед, на вихід - нічого, ремонтує велосипед
void replaceBattery(struct Bicycle* bike, const char* newBattery);//приймає велосипед, та нову батарею, на вихід - нічого, змінює батарею велосипеда
void changePrice(struct Bicycle* bike, double newPrice);//приймає велосипед, та нову ціну, на вихід - нічого, змінює ціну велосипеда
void inputBicyclesArray(struct Bicycle* bikes, int* count, int maxCount);// приймає масив велосипедів, вказівник на кількість велосипедів, та максимальну кількість велосипедів, на вихід - нічого, заповнює масив велосипедами
int loginAsAdmin();//вхід в адмін меню, на вхід - нічого, на вихід - 1 якщо пароль вірний, 0 якщо ні
void adminMenu(struct Bicycle* bikes, int* count, int maxCount);//панель адміна
void writeToBinaryFile(struct Bicycle* bikes, int count, const char* filename);//приймає масив велосипедів, кількість велосипедів, та назву файлу, на вихід - нічого, записує масив у файл
int readFromBinaryFile(struct Bicycle* bikes, int maxCount, const char* filename);//приймає масив велосипедів, максимальну кількість велосипедів, та назву файлу, на вихід - кількість прочитаних велосипедів, відкриває файл, та зчитує масив
void searchBicycleByBrand(const struct Bicycle* bikes, int count);//приймає масив велосипедів, та кількість велосипедів, на вихід - нічого, шукає велосипеди за брендом
void removeBicycleByIndex(struct Bicycle* bikes, int* count, int index);//приймає масив велосипедів, вказівник на кількість велосипедів, та індекс велосипеда, на вихід - нічого, видаляє велосипед з масиву


#endif
