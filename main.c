#include <stdio.h>
#include <stdlib.h>
#include "math.h"

int main() {
    int calcul = 0;
    double nombre1 = 0, nombre2 = 0, result = 0;

    printf("-- Calculatrice --\n");
    printf("Quel calcul voulez-vous effectuer ?\n");
    printf("- 1. Addition\n");
    printf("- 2. Soustraction\n");
    printf("- 3. Multiplication\n");
    printf("- 4. Division\n");
    printf("- 5. Carre\n");
    printf("- 6. Puissance\n");
    printf("- 7. Aire d'un carre / rectangle\n");
    printf("- 8. Aire d'un triangle\n\n");
    scanf("%d", &calcul);


    printf("Nombre 1:\n");
    scanf("%lf", &nombre1);
    if (calcul != 5) {
        printf("Nombre 2:\n");
        scanf("%lf", &nombre2);
    }


    switch(calcul) {
        case 1:
            result = addition(nombre1, nombre2);
            printf("%.2f + %.2f = %.2f\n", nombre1, nombre2, result);
            break;
        case 2:
            result = soustraction(nombre1, nombre2);
            printf("%.2f - %.2f = %.2f\n", nombre1, nombre2, result);
            break;
        case 3:
            result = multiplication(nombre1, nombre2);
            printf("%.2f x %.2f = %.2f\n", nombre1, nombre2, result);
            break;
        case 4:
            if (nombre2 != 0) {
                result = division(nombre1, nombre2);
                printf("%.2f : %.2f = %.2f\n", nombre1, nombre2, result);
            } else {
                printf("Erreur : Division par zero impossible !\n");
            }
            break;
        case 5:
            result = carre(nombre1);
            printf("Le carre de %.2f est %.2f\n", nombre1, result);
            break;
        case 6:
            result = puissance(nombre1, nombre2);
            printf("%.2f puissance %.2f = %.2f\n", nombre1, nombre2, result);
            break;
        case 7:
            result = aireCR(nombre1, nombre2);
            printf("L'aire de cette figure est %.2f\n", result);
            break;
        case 8:
            result = aireT(nombre1, nombre2);
            printf("L'aire de ce triangle est %.2f\n", result);
            break;
        default:
            printf("Choix invalide.\n");
            break;
    }

    system("pause");
    return 0;
}
