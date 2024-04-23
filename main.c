#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    float a, b;
    char operator;
    float answer = 0.0;

    while (1) {
        printf("Enter calculation (e.g., 5 + 3):\n");
        scanf("%f %c %f", &a, &operator, &b);

        while (getchar() != '\n');

        switch (operator) {
            case '/':
                if (b == 0) {
                    printf("Error! Division by zero.\n");
                    break;
                }
                answer = a / b;
                break;
            case '*':
                answer = a * b;
                break;
            case '+':
                answer = a + b;
                break;
            case '-':
                answer = a - b;
                break;
            case '^':
                answer = pow(a, b);
                break;
            case ' ':
                answer = sqrt(b);
                break;
            default:
                printf("Error! Please enter a valid operator.\n");
                continue;
        }

        printf("%.2f %c %.2f = %.2f\n\n", a, operator, b, answer);

        int exit;
        printf("Do you want to exit? (Yes=1, No=0): ");
        scanf("%d", &exit);

        if (exit == 1) {
            break;
        }
    }

    return 0;
}
