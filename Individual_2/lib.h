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
// Вкладена структура габарити велосипеда
struct Dimensions {
    float frameHeight;
    float length;
};

union Specifics {
    int suspensionTravel;  // для MOUNTAIN
    float frameWeight;     // для ROAD
    int gearCount;         // для HYBRID
    int pegCount;          // для BMX

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
    enum Type type;               // тип велосипеда
    enum State Bikestate;         // стан
    struct Dimensions size;       // габарити
    union Specifics specs;        // спеціальні параметри
};

enum Type inputType();
enum State inputState();
void inputSpecifics(union Specifics* specs, enum Type type);
void inputBicycle(struct Bicycle* bike);
void printType(enum Type type);
void printState(enum State state);
void printSpecifics(union Specifics* specs, enum Type type);
void printBicycle(struct Bicycle* bike);
void repairBicycle(struct Bicycle* bike);
void replaceBattery(struct Bicycle* bike, const char* newBattery);
void changePrice(struct Bicycle* bike, double newPrice);
void inputBicyclesArray(struct Bicycle* bikes, int* count, int maxCount);
int loginAsAdmin();
void adminMenu(struct Bicycle* bikes, int* count, int maxCount);


#endif
