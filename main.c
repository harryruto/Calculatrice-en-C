#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#define ERROR (2.22507e-308)

int main() {
    int choice = 0, makeOperation = 1;
    double number1 = 0, number2 = 0, type = 1, result = 0;

    FILE* error = fopen("error.logfile", "a+");


   while (makeOperation == 1 ) {
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
    printf("- 9. Square root\n");
    printf("- 10.Improvement or decrease\n\n");

    scanf("%d", &choice);

    if (choice != 10) {
    printf("Number 1:\n");
    scanf("%lf", &number1);
    }

    if (choice != 5 && choice != 9 && choice != 10) {
        printf("Number 2:\n");
        scanf("%lf", &number2);
    }
    if (choice == 10) {
        printf("Initial price (without the money symbol) :\n");
         scanf("%lf", &number1);
        printf("Do you want an increase or a decrease\n");
        printf("1. Improvement\n");
        printf("2. Decrease\n");
        scanf("%lf", &type);
        printf("Change (without the percent sign):\n");
        scanf("%lf", &number2);
    }

    switch(choice) {
        case 1:
            result = mthadd(number1, number2);
            printf("%.2f + %.2f = %.2f\n", number1, number2, result);
            break;
        case 2:
            result = mthsub(number1, number2);
            printf("%.2f - %.2f = %.2f\n", number1, number2, result);
            break;
        case 3:
            result = mthmult(number1, number2);
            printf("%.2f x %.2f = %.2f\n", number1, number2, result);
            break;
        case 4:
            if (number2 != 0) {
                result = mthdivd(number1, number2);
                printf("%.2f / %.2f = %.2f\n", number1, number2, result);
            } else {
                printf("Error: Division by zero is impossible!\n");
                result = ERROR;
            }
            break;
        case 5:
            result = mthsq(number1);
            printf("The square of %.2f is %.2f\n", number1, result);
            break;
        case 6:
            result = mthp(number1, number2);
            printf("%.2f to the power of %.2f = %.2f\n", number1, number2, result);
            break;
        case 7:
            result = mtharSR(number1, number2);
            printf("The area of this shape is %.2f\n", result);
            break;
        case 8:
            result = mtharT(number1, number2);
            printf("The area of this triangle is %.2f\n", result);
            break;
        case 9:
            result = mthsqr(number1);
            if (result != -1) {
                printf("The square root of %.2f is %.2f\n", number1, result);
            } else {
                printf("Error: Cannot calculate square root of a negative number\n\n");
                result = ERROR;
            }
            break;
        case 10:
            result = mthppct(number1, type, number2);
            if (type == 1) {
                printf("After this improvement the new price is %.2f\n", result);
            } else if (type == 2) {
                 printf("After this decrease the new price is %.2f\n", result);
            } else {
               printf("Invalid choice.\n");
               result = ERROR;
            }
          break;
        default:
            printf("Invalid choice.\n");
            choice = ERROR;
            break;
        }
    FILE* fichier = fopen("log.logfile", "a+");
    if (fichier != NULL) {
        if (choice != 5 && choice != 9 && choice != ERROR && result != ERROR) {
             fprintf(fichier, "\n[LOG] Operation : %d - Number 1 : %.2f - Number 2 : %.2f - Result = %.2f", choice, number1, number2, result);
        } else if (result == ERROR || choice == ERROR) {
             fprintf(fichier, "\n[LOG] Invalid operation");
        } else {
             fprintf(fichier, "\n[LOG] Operation : %d - Number 1 : %.2f - Number 2 : NULL - Result = %.2f", choice, number1, result);
        }
    fclose(fichier);
     } else {
            printf("Log file uncharged");
        if (error != NULL) {
            fprintf(error, "Log file uncharged");
        } else {
         printf("Error file uncharged");
        }
     }

     printf("Do you want to make another operation ?\n");
     printf("1. Yes\n");
     printf("2. No\n\n");
     scanf("%d", &makeOperation);
   }
    system("pause");
    return 0;
}
