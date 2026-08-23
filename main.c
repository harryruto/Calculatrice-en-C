#include <stdio.h>
#include <stdlib.h>
#include "math.h"

int main() {
    int choice = 0, makeOperation = 1;
    double number1 = 0, number2 = 0, type = 1, result = 0;


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

    si (choix != 5 && choix != 9 && choix != 10) {
        printf("Numéro 2:\n");
        scanf("%lf", &numéro2);
    }
    si (choix == 10) {
        printf("Prix initial (sans le symbole monétaire) :\n");
         scanf("%lf", &numéro1);
        printf("Voulez-vous une augmentation ou une diminution\n");
        printf("1. Amélioration\n");
        printf("2. Diminuer\n");
        scanf("%lf", &type);
        printf(« Changement (sans le signe de pourcentage) :\n");
        scanf("%lf", &numéro2);
    }

    interrupteur(choix) {
        cas 1:
            résultat = mthadd(numéro1, numéro2);
            printf("%.2f + %.2f = %.2f\n", numéro1, numéro2, résultat);
            casser;
        cas 2:
            résultat = mthsub(numéro1, numéro2);
            printf("%.2f - %.2f = %.2f\n", numéro1, numéro2, résultat);
            casser;
        cas 3:
            résultat = mthmult(numéro1, numéro2);
            printf("%.2f x %.2f = %.2f\n", numéro1, numéro2, résultat);
            casser;
        cas 4:
            si (numéro2 != 0) {
                résultat = mthdivd(numéro1, numéro2);
                printf("%.2f / %.2f = %.2f\n", numéro1, numéro2, résultat);
            } autre {
                printf(« Erreur : la division par zéro est impossible !\n");
            }
            casser;
        cas 5:
            résultat = mthsq(numéro 1);
            printf("Le carré de %.2f est %.2f\n", numéro1, résultat);
            casser;
        cas 6:
            résultat = mthp(numéro1, numéro2);
            printf("%.2f à la puissance %.2f = %.2f\n", numéro1, numéro2, résultat);
            casser;
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
            }
            casser;
        cas 10:
            résultat = mthppct(numéro1, type, numéro2);
            si (type == 1) {
                printf("Après cette amélioration, le nouveau prix est de %.2f\n", résultat);
            } si (type == 2) {
                 printf("Après cette baisse, le nouveau prix est de %.2f\n", résultat);
            } autre {
               printf("Choix invalide.\n");
            }
          casser;
        défaut:
            printf("Choix invalide.\n");
            casser;
        }
         FICHIER* fichier = ouvrir("log.logfile", "a+");
        si (choix != 5 && choix != 9) {
      fprintf(plus rigide, "\n[LOG][%s %s]Opération : %d - Numéro 1 : %.2f - Numéro 2 : %.2f - Résultat = %.2f", __DATE__, __HEURE__choix, numéro1, numéro2, résultat);
        } autre {
        fprintf(plus rigide, "\n[LOG][%s %s] Opération : %d - Numéro 1 : %.2f - Numéro 2 : NULL - Résultat = %.2f", __DATE__, __HEURE__, choix, numéro1, résultat);
        }
      fclose(plus sommaire);

     printf(« Voulez-vous faire une autre opération ?\n");
     printf("1. Oui\n");
     printf("2. Non\n\n");
     scanf("%d", &makeOpération);
   }
    système("pause");
    retour 0;
}
