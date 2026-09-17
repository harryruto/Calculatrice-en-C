#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include <windows.h>
#define ERROR (2.22507e-308)


int main() {
    int choice = 0, makeOperation = 1, language = 1;
    double number1 = 0, number2 = 0, type = 1, result = 0;

    FILE* error = fopen("error.logfile", "a+");

    printf("Do you accept the T&C\n");
    int accept = 0;

    printf("1. Yes\n");
    printf("2. No\n\n");
    scanf("%d", &accept);

    if (accept == 1) {
    printf("What language you speak / Quelle langue parlez-vous ?\n");
    printf("1. English\n");
    printf("2. Francais\n");
    scanf("%d", &language);

    if (language == 1) {
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
            printf("- 10.Improvement or decrease\n");
            printf("- 11. Percetage\n");
            printf("- 12. Pythagorus Theorem\n\n");

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
                        color(12, 0);
                        printf("Error: Division by zero is impossible!\n");
                        result = ERROR;
                        color(15, 0);
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
                        color(12, 0);
                        printf("Error: Cannot calculate square root of a negative number\n\n");
                        result = ERROR;
                        color(15, 0);
                    }
                    break;
                case 10:
                    result = mthppct(number1, type, number2);
                    if (type == 1) {
                        printf("After this improvement the new price is %.2f\n", result);
                    } else if (type == 2) {
                        printf("After this decrease the new price is %.2f\n", result);
                    } else {
                        color(12, 0);
                        printf("Invalid choice.\n");
                        result = ERROR;
                        color(15, 0);
                    }
                    break;
                case 11:
                    result = mthpct(number1, number2);
                    printf("%.2f percents of %.2f = %.2f\n", number2, number1, result);
                    break;
                case 12:
                    result = mthpytTh(number1, number2);
                    printf("The hypotenuse of this triangle is %.2f\n", result);
                    break;
                default:
                    color(12, 0);
                    printf("Invalid choice.\n");
                    choice = ERROR;
                    color(15, 0);
                    break;
            }
            FILE* fichier = fopen("log.logfile", "a+");
            if (fichier != NULL) {
                if (choice != 5 && choice != 9 && choice != ERROR && result != ERROR) {
                    fprintf(fichier, "[LOG] Operation : %d - Number 1 : %.2f - Number 2 : %.2f - Result = %.2f\n", choice, number1, number2, result);
                } else if (result == ERROR || choice == ERROR) {
                    fprintf(fichier, "[LOG] Invalid operation\n");
                    fprintf(error, "[ERROR] Invalid operation\n");
                } else {
                    fprintf(fichier, "[LOG] Operation : %d - Number 1 : %.2f - Number 2 : NULL - Result = %.2f\n", choice, number1, result);
                }
                fclose(fichier);
            } else {
                color(12, 0);
                printf("[ERROR]Log file uncharged\n");
                color(15, 0);
                if (error != NULL) {
                    fprintf(error, "[ERROR] Log file uncharged\n");
                } else {
                    color(12, 0);
                    printf("[ERROR]Error file uncharged\n");
                    color(15, 0);
                }
            }

            printf("Do you want to make another operation ?\n");
            printf("1. Yes\n");
            printf("2. No\n\n");
            scanf("%d", &makeOperation);
        }
        printf("Press enter to exit");

    } else if (language == 2) {
        while (makeOperation == 1) {
            printf("-- Calculatrice --\n");
            printf("Quelle operation souhaitez-vous effectuer ?\n");
            printf("- 1. Addition\n");
            printf("- 2. Soustraction\n");
            printf("- 3. Multiplication\n");
            printf("- 4. Division\n");
            printf("- 5. Carre\n");
            printf("- 6. Puissance\n");
            printf("- 7. Aire d'un carre / rectangle\n");
            printf("- 8. Aire d'un triangle\n");
            printf("- 9. Racine carree\n");
            printf("- 10. Augmentation ou diminution\n");
            printf("- 11. Pourcentage\n");
            printf("- 12. Theoreme de Pythagore\n\n");

            scanf("%d", &choice);

            if (choice != 10) {
                printf("Nombre 1 :\n");
                scanf("%lf", &number1);
            }

            if (choice != 5 && choice != 9 && choice != 10) {
                printf("Nombre 2 :\n");
                scanf("%lf", &number2);
            }
            if (choice == 10) {
                printf("Prix initial (sans le symbole monetaire) :\n");
                scanf("%lf", &number1);
                printf("Souhaitez-vous une augmentation ou une diminution ?\n");
                printf("1. Augmentation\n");
                printf("2. Diminution\n");
                scanf("%lf", &type);
                printf("Variation (sans le signe %) :\n");
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
                        color(12, 0);
                        printf("Erreur : La division par zero est impossible !\n");
                        result = ERROR;
                        color(15, 0);
                    }
                    break;
                case 5:
                    result = mthsq(number1);
                    printf("Le carre de %.2f est %.2f\n", number1, result);
                    break;
                case 6:
                    result = mthp(number1, number2);
                    printf("%.2f a la puissance %.2f = %.2f\n", number1, number2, result);
                    break;
                case 7:
                    result = mtharSR(number1, number2);
                    printf("L'aire de cette forme est de %.2f\n", result);
                    break;
                case 8:
                    result = mtharT(number1, number2);
                    printf("L'aire de ce triangle est de %.2f\n", result);
                    break;
                case 9:
                    result = mthsqr(number1);
                    if (result != -1) {
                        printf("La racine carree de %.2f est %.2f\n", number1, result);
                    } else {
                        color(12, 0);
                        printf("Erreur : Impossible de calculer la racine carree d'un nombre négatif\n\n");
                        result = ERROR;
                        color(15, 0);
                    }
                    break;
                case 10:
                    result = mthppct(number1, type, number2);
                    if (type == 1) {
                        printf("Apres cette augmentation, le nouveau prix est de %.2f\n", result);
                    } else if (type == 2) {
                        printf("Apres cette diminution, le nouveau prix est de %.2f\n", result);
                    } else {
                        color(12, 0);
                        printf("Choix invalide.\n");
                        result = ERROR;
                        color(15, 0);
                    }
                    break;
                case 11:
                    result = mthpct(number1, number2);
                    printf("%.2f pourcents de %.2f = %.2f\n", number2, number1, result);
                    break;
                case 12:
                    result = mthpytTh(number1, number2);
                    printf("L'hypotenuse de ce triangle est %.2f\n", result);
                    break;
                default:
                    color(12, 0);
                    printf("Choix invalide.\n");
                    choice = ERROR;
                     color(15, 0);
                    break;
            }
            FILE* fichier = fopen("log.logfile", "a+");
            if (fichier != NULL) {
                if (choice != 5 && choice != 9 && choice != ERROR && result != ERROR) {
                    fprintf(fichier, "[LOG] Operation : %d - Number 1 : %.2f - Number 2 : %.2f - Result = %.2f\n", choice, number1, number2, result);
                } else if (result == ERROR || choice == ERROR) {
                    fprintf(fichier, "[LOG] Invalid operation\n");
                    fprintf(error, "[ERROR] Invalid operation\n");
                } else {
                    fprintf(fichier, "[LOG] Operation : %d - Number 1 : %.2f - Number 2 : NULL - Result = %.2f\n", choice, number1, result);
                }
                fclose(fichier);
            } else {
                color(12, 0);
                printf("Fichier de log non charge\n");
                color(15, 0);
                if (error != NULL) {
                    fprintf(error, "[ERROR] Log file uncharged\n");
                } else {
                    color(12, 0);
                    printf("[ERREUR] Fichier d'erreur non charge\n");
                    color(15, 0);
                }
            }

            printf("Souhaitez-vous effectuer une autre operation ?\n");
            printf("1. Oui\n");
            printf("2. Non\n\n");
            scanf("%d", &makeOperation);
        }
        printf("Appuyez sur Entree pour quitter");

    } else {
        color(12, 0);
        printf("Choix invalide / Invalid choice\n");
        color(15, 0);
    }
    fclose(error);
    return 0;
    } else {
     fprintf(error, "[ERROR] Terms and conditions don't accepted\n");
     return 0;
    }
}


