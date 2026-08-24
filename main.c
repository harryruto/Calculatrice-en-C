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
        cas 7:
            résultat = mtharSR(numéro1, numéro2);
            printf("La surface de cette forme est de %.2f\n", résultat);
            casser;
        cas 8:
            résultat = mtharT(numéro1, numéro2);
            printf("L'aire de ce triangle est de %.2f\n", résultat);
            casser;
        cas 9:
            résultat = mthsqr(numéro 1);
            si (résultat != -1) {
                printf("La racine carrée de %.2f est %.2f\n", numéro1, résultat);
            } autre {
                printf(« Erreur : impossible de calculer la racine carrée d'un nombre négatif\n\n");
                résultat = ERREUR;
            }
            casser;
        cas 10:
            résultat = mthppct(numéro1, type, numéro2);
            si (type == 1) {
                printf("Après cette amélioration, le nouveau prix est de %.2f\n", résultat);
            } autre si (type == 2) {
                 printf("Après cette baisse, le nouveau prix est de %.2f\n", résultat);
            } autre {
               printf("Choix invalide.\n");
               résultat = ERREUR;
            }
          casser;
        défaut:
            printf("Choix invalide.\n");
            choix = ERREUR;
            casser;
        }
    FICHIER* fichier = ouvrir("log.logfile", "a+");
    si (fichier != NUL) {
        si (choix != 5 && choix != 9 && choix != ERREUR && résultat != ERREUR) {
             fprintf(plus rigide, "\n[LOG] Opération : %d - Numéro 1 : %.2f - Numéro 2 : %.2f - Résultat = %.2f", choix, numéro1, numéro2, résultat);
        } autre si (résultat == ERREUR || choix == ERREUR) {
             fprintf(plus rigide, "\n[LOG] Opération non valide");
        } autre {
             fprintf(plus rigide, "\n[LOG] Opération : %d - Numéro 1 : %.2f - Numéro 2 : NULL - Résultat = %.2f", choix, numéro1, résultat);
        }
    fclose(plus sommaire);
     } autre {
            printf("Fichier journal non chargé\n");
        si (erreur != NUL) {
            fprintf(erreur, "Fichier journal non chargé\n");
        } autre {
         printf("\n[ERREUR]Fichier d'erreur non chargé");
        }
     }

     printf(« Voulez-vous faire une autre opération ?\n");
     printf("1. Oui\n");
     printf("2. Non\n\n");
     scanf("%d", &makeOpération);
   }
    fclose(erreur);
    retour 0;
}
