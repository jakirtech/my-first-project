#include <stdio.h>
#include <math.h>

#define MAX_HISTORY 10

// Structure to store history
struct History {
    char operation[50];
    double result;
};

int main() {
    int choice;
    double a, b, result;
    struct History history[MAX_HISTORY];
    int count = 0;

    while (1) {
        printf("\n===== SMART CALCULATOR =====\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Power\n");
        printf("6. Show History\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 7) {
            printf("Exiting Calculator...\n");
            break;
        }

        if (choice >= 1 && choice <= 5) {
            printf("Enter first number: ");
            scanf("%lf", &a);
            printf("Enter second number: ");
            scanf("%lf", &b);
        }

        switch (choice) {
            case 1:
                result = a + b;
                printf("Result = %.2lf\n", result);
                sprintf(history[count % MAX_HISTORY].operation, "%.2lf + %.2lf", a, b);
                history[count % MAX_HISTORY].result = result;
                count++;
                break;

            case 2:
                result = a - b;
                printf("Result = %.2lf\n", result);
                sprintf(history[count % MAX_HISTORY].operation, "%.2lf - %.2lf", a, b);
                history[count % MAX_HISTORY].result = result;
                count++;
                break;

            case 3:
                result = a * b;
                printf("Result = %.2lf\n", result);
                sprintf(history[count % MAX_HISTORY].operation, "%.2lf * %.2lf", a, b);
                history[count % MAX_HISTORY].result = result;
                count++;
                break;

            case 4:
                if (b == 0) {
                    printf("Error: Division by zero is not allowed!\n");
                } else {
                    result = a / b;
                    printf("Result = %.2lf\n", result);
                    sprintf(history[count % MAX_HISTORY].operation, "%.2lf / %.2lf", a, b);
                    history[count % MAX_HISTORY].result = result;
                    count++;
                }
                break;

            case 5:
                result = pow(a, b);
                printf("Result = %.2lf\n", result);
                sprintf(history[count % MAX_HISTORY].operation, "%.2lf ^ %.2lf", a, b);
                history[count % MAX_HISTORY].result = result;
                count++;
                break;

            case 6:
                printf("\n---- Calculation History ----\n");
                if (count == 0) {
                    printf("No history yet.\n");
                } else {
                    int start = (count > MAX_HISTORY) ? count - MAX_HISTORY : 0;
                    for (int i = start; i < count; i++) {
                        printf("%s = %.2lf\n",
                            history[i % MAX_HISTORY].operation,
                            history[i % MAX_HISTORY].result);
                    }
                }
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}