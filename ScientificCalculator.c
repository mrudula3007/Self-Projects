#include <stdio.h>
#include <math.h>

void text(void);

int main(void) {
    text();
    return 0;
}

void text(void) {
    int choice, i;
    float x, y, result;
    while (1) {
        printf("Enter your choice:\n");
        printf("1. ADDITION\n");
        printf("2. SUBTRACTION\n");
        printf("3. MULTIPLICATION\n");
        printf("4. DIVISION\n");
        printf("5. SQUARE ROOT\n");
        printf("6. POWER\n");
        printf("7. SQUARE\n");
        printf("8. CUBE\n");
        printf("9. 1/X\n");
        printf("10. EXPONENT\n");
        printf("11. FACTORIAL\n");
        printf("12. PERCENTAGE\n");
        printf("13. LOG\n");
        printf("14. REMAINDER\n");
        printf("15. SIN(x)\n");
        printf("16. COS(x)\n");
        printf("17. TAN(x)\n");
        printf("18. COSEC(x)\n");
        printf("19. SEC(x)\n");
        printf("20. COT(x)\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter X: ");
                scanf("%f", &x);
                printf("Enter Y: ");
                scanf("%f", &y);
                result = x + y;
                printf("Result: %.1f\n", result);
                break;
            case 2:
                printf("Enter X: ");
                scanf("%f", &x);
                printf("Enter Y: ");
                scanf("%f", &y);
                result = x - y;
                printf("Result: %.1f\n", result);
                break;
            case 3:
                printf("Enter X: ");
                scanf("%f", &x);
                printf("Enter Y: ");
                scanf("%f", &y);
                result = x * y;
                printf("Result: %.1f\n", result);
                break;
            case 4:
                printf("Enter X: ");
                scanf("%f", &x);
                printf("Enter Y: ");
                scanf("%f", &y);
                result = x / y;
                printf("Result: %.1f\n", result);
                break;
            case 5:
                printf("Enter X: ");
                scanf("%f", &x);
                result = sqrt(x);
                printf("Result: %.1f\n", result);
                break;
            case 6:
                printf("Enter X: ");
                scanf("%f", &x);
                printf("Enter Y: ");
                scanf("%f", &y);
                result = pow(x, y);
                printf("Result: %.1f\n", result);
                break;
            case 7:
                printf("Enter X: ");
                scanf("%f", &x);
                result = pow(x, 2);
                printf("Result: %.1f\n", result);
                break;
            case 8:
                printf("Enter X: ");
                scanf("%f", &x);
                result = pow(x, 3);
                printf("Result: %.1f\n", result);
                break;
            case 9:
                printf("Enter X: ");
                scanf("%f", &x);
                result = 1 / x;
                printf("Result: %.2f\n", result);
                break;
            case 10:
                printf("Enter X: ");
                scanf("%f", &x);
                result = exp(x);
                printf("Result: %.1f\n", result);
                break;
            case 11:
                printf("Enter X: ");
                scanf("%f", &x);
                result = 1;
                for (i = 1; i <= x; i++) {
                    result *= i;
                }
                printf("Result: %.1f\n", result);
                break;
            case 12:
                printf("Enter X: ");
                scanf("%f", &x);
                printf("Enter Y: ");
                scanf("%f", &y);
                result = (x * y) / 100;
                printf("Result: %.1f\n", result);
                break;
            case 13:
                printf("Enter X: ");
                scanf("%f", &x);
                result = log(x);
                printf("Result: %.1f\n", result);
                break;
            case 14:
                printf("Enter X: ");
                scanf("%f", &x);
                printf("Enter Y: ");
                scanf("%f", &y);
                result = fmod(x, y);
                printf("Result: %.2f\n", result);
                break;
            case 15:
                printf("Enter X: ");
                scanf("%f", &x);
                result = sin(x * 3.14159 / 180.0);
                printf("Result: %.2f\n", result);
                break;
            case 16:
                printf("Enter X: ");
                scanf("%f", &x);
                result = cos(x * 3.14159 / 180.0);
                printf("Result: %.2f\n", result);
                break;
            case 17:
                printf("Enter X: ");
                scanf("%f", &x);
                result = tan(x * 3.14159 / 180.0);
                printf("Result: %.2f\n", result);
                break;
            case 18:
                printf("Enter X: ");
                scanf("%f", &x);
                result = 1 / sin(x * 3.14159 / 180.0);
                printf("Result: %.2f\n", result);
                break;
            case 19:
                printf("Enter X: ");
                scanf("%f", &x);
                result = 1 / cos(x * 3.14159 / 180.0);
                printf("Result: %.2f\n", result);
                break;
            case 20:
                printf("Enter X: ");
                scanf("%f", &x);
                result = 1 / tan(x * 3.14159 / 180.0);
                printf("Result: %.2f\n", result);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        
        int exit;
        printf("Do you want to exit? (Yes=1, No=0): ");
        scanf("%d", &exit);

        if (exit == 1) {
            break;
        }
    }
    
}

