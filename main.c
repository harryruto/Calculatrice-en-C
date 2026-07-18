#include <stdio.h>
#include <stdlib.h>
#include "math.h"

int main() {
    int choice = 0;
    double number1 = 0, number2 = 0, result = 0;

    printf("-- Calculator --\n");
    printf("Which operation would you like to perform?\n");
    printf("- 1. Addition\n");
    printf("- 2. Subtraction\n");
    printf("- 3. Multiplication\n");
    printf("- 4. Division\n");
    printf("- 5. Square\n");
    printf("- 6. Power\n");
    printf("- 7. Area of a square / rectangle\n");
    printf("- 8. Area of a triangle\n");
    printf("- 9. Square root\n\n");

    scanf("%d", &choice);

    printf("Number 1:\n");
    scanf("%lf", &number1);

    // For square (5) and square root (9), we only need one number
    if (choice != 5 && choice != 9) {
        printf("Number 2:\n");
        scanf("%lf", &number2);
    }

    switch(choice) {
        case 1:
            result = addition(number1, number2);
            printf("%.2f + %.2f = %.2f\n", number1, number2, result);
            break;
        case 2:
            result = subtraction(number1, number2);
            printf("%.2f - %.2f = %.2f\n", number1, number2, result);
            break;
        case 3:
            result = multiplication(number1, number2);
            printf("%.2f x %.2f = %.2f\n", number1, number2, result);
            break;
        case 4:
            if (number2 != 0) {
                result = division(number1, number2);
                printf("%.2f / %.2f = %.2f\n", number1, number2, result);
            } else {
                printf("Error: Division by zero is impossible!\n");
            }
            break;
        case 5:
            result = square(number1);
            printf("The square of %.2f is %.2f\n", number1, result);
            break;
        case 6:
            result = power(number1, number2);
            printf("%.2f to the power of %.2f = %.2f\n", number1, number2, result);
            break;
        case 7:
            result = areaSR(number1, number2); // Area Square/Rectangle
            printf("The area of this shape is %.2f\n", result);
            break;
        case 8:
            result = areaT(number1, number2); // Area Triangle
            printf("The area of this triangle is %.2f\n", result);
            break;
        case 9:
            result = squareRoot(number1);
            if (result != -1) {
            printf("The square root of %.2f is %.2f\n", number1, result);
            } else {
            printf("This number does not have an integer as a square root\n\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    system("pause");
    return 0;
}
