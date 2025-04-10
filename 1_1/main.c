#include "lib.h"

int main(void)
{
    Type type;
    char dia;
    printf("Choose the type of numbers:\n1. int\n2. float\n3. double\n");
    int typeChoice;
    scanf("%d", &typeChoice);
    switch (typeChoice) {
        case 1:
            type = TYPE_INT;
            break;
        case 2:
            type = TYPE_FLOAT;
            break;
        case 3:
            type = TYPE_DOUBLE;
            break;
        default:
            printf("Wrong type of numbers\n");
            return 1;
    }

    printf("Choose the operation (+, -, *, /): ");
    scanf(" %c", &dia);

    if (type == TYPE_INT) {
        int a, b, res;
        printf("Enter first number: ");
        scanf("%d", &a);
        printf("Enter second number: ");
        scanf("%d", &b);

        switch (dia) {
            case '+':
                add(&a, &b, type, &res);
                printf("Result: %d\n", res);
                break;
            case '-':
                substraction(&a, &b, type, &res);
                printf("Result: %d\n", res);
                break;
            case '*':
                multiplication(&a, &b, type, &res);
                printf("Result: %d\n", res);
                break;
            case '/':
                if (b != 0) {
                    division(&a, &b, type, &res);
                    printf("Result: %d\n", res);
                } else {
                    printf("Error: division by zero\n");
                }
                break;
            default:
                printf("Wrong operation\n");
        }
    } else if (type == TYPE_FLOAT) {
        float a, b, res;
        printf("Enter first number: ");
        scanf("%f", &a);
        printf("Enter second number: ");
        scanf("%f", &b);

        switch (dia) {
            case '+':
                add(&a, &b, type, &res);
                printf("Result: %f\n", res);
                break;
            case '-':
                substraction(&a, &b, type, &res);
                printf("Result: %f\n", res);
                break;
            case '*':
                multiplication(&a, &b, type, &res);
                printf("Result: %f\n", res);
                break;
            case '/':
                if (b != 0) {
                    division(&a, &b, type, &res);
                    printf("Result: %f\n", res);
                } else {
                    printf("Error: division by zero\n");
                }
                break;
            default:
                printf("Wrong operation\n");
        }
    } else if (type == TYPE_DOUBLE) {
        double a, b, res;
        printf("Enter first number: ");
        scanf("%lf", &a);
        printf("Enter second number: ");
        scanf("%lf", &b);

        switch (dia) {
            case '+':
                add(&a, &b, type, &res);
                printf("Result: %lf\n", res);
                break;
            case '-':
                substraction(&a, &b, type, &res);
                printf("Result: %lf\n", res);
                break;
            case '*':
                multiplication(&a, &b, type, &res);
                printf("Result: %lf\n", res);
                break;
            case '/':
                if (b != 0) {
                    division(&a, &b, type, &res);
                    printf("Result: %lf\n", res);
                } else {
                    printf("Error: division by zero\n");
                }
                break;
            default:
                printf("Wrong operation\n");
        }
    }
    return 0;
}
