#include <stdio.h>


typedef enum {
    OFF,
    IDLE,
    PRINTING,
    ERROR
} PrinterState;

typedef enum {
    TURN_ON = 1,
    START_PRINT,
    FINISH_PRINT,
    RESTART,
    TURN_OFF,
    EXIT_PROGRAM
} PrinterEvent;

// Функція для виведення поточного стану
void printState(PrinterState state) {
    printf("Поточний стан принтера: ");
    switch (state) {
        case OFF: printf("OFF \n"); break;
        case IDLE: printf("IDLE \n"); break;
        case PRINTING: printf("PRINTING \n"); break;
        case ERROR: printf("ERROR \n"); break;
    }
}

// Функція для зчитування події
PrinterEvent readEvent() {
    int choice;
    printf("\nОберіть подію:\n");
    printf("1. Увімкнути пристрій\n");
    printf("2. Почати друк\n");
    printf("3. Завершити друк\n");
    printf("4. Перезавантажити пристрій\n");
    printf("5. Вимкнути пристрій\n");
    printf("6. Вийти з програми\n");
    printf("Ваш вибір: ");

    while (scanf("%d", &choice) != 1 || choice < 1 || choice > 6) {
        while (getchar() != '\n'); // Очистити буфер
        printf("Некоректне введення. Спробуйте ще раз: ");
    }

    return (PrinterEvent)choice;
}

// Функція для зміни стану пристрою
PrinterState handleEvent(PrinterState currentState, PrinterEvent event) {
    switch (event) {
        case TURN_ON:
            if (currentState == OFF) return IDLE;
            break;
        case START_PRINT:
            if (currentState == IDLE) return PRINTING;
            break;
        case FINISH_PRINT:
            if (currentState == PRINTING) return IDLE;
            break;
        case RESTART:
            return IDLE;
        case TURN_OFF:
            return OFF;
        default:
            break;
    }
    printf("Подія не може бути виконана у поточному стані.\n");
    return currentState;
}

int main() {
    PrinterState state = OFF;
    PrinterEvent event;

    while (1) {
        printState(state);
        event = readEvent();

        if (event == EXIT_PROGRAM) {
            printf("Вихід з програми.\n");
            break;
        }

        state = handleEvent(state, event);
    }

    return 0;
}
