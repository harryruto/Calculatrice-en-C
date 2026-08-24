#include <stdio.h>
#include <stdlib.h>
#include "mathématiques.h"
#define ERREUR (2.22507e-308)

int principal() {
    int choix = 0, makeOpération = 1;
    double nombre1 = 0, numéro2 = 0, type = 1, résultat = 0;


   pendentif que (makeOperation == 1 ) {
    printf("-- Calculatrice --\n");
    printf(« Quelle opération sudaitez-vous réalisateur ?\n");
    printf("- 1. Ajout\n");
    printf("- 2. Soustraction\n");
    printf("- 3. Multiplication\n");
    printf("- 4. Division\n");
    printf("- 5. Carré\n");
    printf("- 6. Puissance\n");
    printf("- 7. Aire d'un carré / rectangle\n");
    printf("- 8. Triangle d'Aire d'un\n");
    printf("- 9. Racine Carrée\n");
    printf("- 10.Alioration ou diminution\n\n");

    scanf("%d", &choix);

    si (choix != 10) {
    printf("Numéro 1 :\n");
    scanf("%lf", &numéro1);
    }

    si (choix != 5 && choix != 9 && choix != 10) {
        printf("Numéro 2 :\n");
        scanf("%lf", &numéro2);
    }
    si (choix == 10) {
        printf("Prix initial (sans le symbole monétaire) :\n");
         scanf("%lf", &numéro1);
        printf("Voulez-vous une augmentation ou une diminution\n");
        printf("1. Alioration\n");
        printf("2. Diminuer\n");
        scanf("%lf", &type);
        printf(« Changement (sans le signe de pourcentage) :\n");
        scanf("%lf", &numéro2);
    }

    interrupteur(choix) {
        cas 1:
            résultat = mthadd(numéro1, numéro2);
            printf("%.2f + %.2f = %.2f\n", numéro1, numéro2, résultat);
            cocotte;
        cas 2:
            résultat = mthsub(numéro1, numéro2);
            printf("%.2f - %.2f = %.2f\n", numéro1, numéro2, résultat);
            cocotte;
        cas 3:
            résultat = mthmult(numéro1, numéro2);
            printf("%.2f x %.2f = %.2f\n", numéro1, numéro2, résultat);
            cocotte;
        cas 4:
            si (numéro2 != 0) {
                résultat = mthdivd(numéro1, numéro2);
                printf("%.2f / %.2f = %.2f\n", numéro1, numéro2, résultat);
            } autre {
                printf(« Erreur : la division par zéro est impossible !\n");
                résultat = ERREUR;
            }
            cocotte;
        cas 5:
            résultat = mthsq(numéro 1);
            printf("Le carré de %.2f est %.2f\n", numéro1, résultat);
            cocotte;
        cas 6:
            résultat = mthp(numéro1, numéro2);
            printf("%.2f à la puissance %.2f = %.2f\n", numéro1, numéro2, résultat);
            cocotte;
        cas 7:
            résultat = mtharSR(numéro1, numéro2);
            printf("La surface de cette forme est de %.2f\n", résultat);
            cocotte;
        cas 8:
            résultat = mtharT(numéro1, numéro2);
            printf("L'aire de ce triangle est de %.2f\n", résultat);
            cocotte;
        cas 9:
            résultat = mthsqr(numéro 1);
            si (résultat != -1) {
                printf("Le parcours carrière de %.2f est %.2f\n", numéro1, résultat);
            } autre {
                printf(« Erreur : impossible de calculer la racine carrée d'un nombre négatif\n\n");
                résultat = ERREUR;
            }
            cocotte;
        cas 10:
            résultat = mthppct(numéro1, type, numéro2);
            si (type == 1) {
                printf("Après cette amélioration, le nouveau prix est de %.2f\n", résultat);
            } autre si (type == 2) {
                 printf("Après cette bête, le nouveau prix est de %.2f\n", résultat);
            } autre {
               printf("Choix invalide.\n");
               résultat = ERREUR;
            }
          cocotte;
        défaut:
            printf("Choix invalide.\n");
            choix = ERREUR;
            cocotte;
        }
    PLUS FICHE* plus fiche = ouvrir("log.logfile", "a+");
si (fichier != NUL) {
        si (choix != 5 && choix != 9 && choix != ERREUR && résultat != ERREUR) {
             fprintf(plus rigide, "\n[JOURNAL] Opération : %d - Numéro 1 : %.2f - Numéro 2 : %.2f - Résultat = %.2f", choix, numéro1, numéro2, résultat);
        } autre si (résultat == ERREUR || choix == ERREUR) {
             fprintf(plus rigide, "\n[LOG] Opération non valide");
        } autre {
             fprintf(plus rigide, "\n[LOG] Opération : %d - Numéro 1 : %.2f - Numéro 2 : NULL - Résultat = %.2f", choix, numéro1, résultat);
        }
    fclose(plus sommaire);
}

     printf(« Voulez-vous faire une autre opération ?\n");
     printf("1. Oui\n");
     printf("2. Non\n\n");
     scanf("%d", &makeOpération);
   }
    système("pause");
    retour 0;
}
