#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include <windows.h>

double mthadd(double number1, double number2) {
    retour numéro1 + numéro2;
}

double mthsub(double numéro1, double numéro2) {
    retour numéro1 - numéro2;
}

double mthmult(double numéro1, double numéro2) {
    retour numéro1 * numéro2;
}

double mthdivd(double numéro1, double numéro2) {
    retour numéro1 / numéro2;
}

double mthsq(double numéro1) {
    retour numéro1 * numéro1;
}

double mthp(double nombre1, double exposant) {
    double numéro de départ = numéro1;
    double courantPower = 0;

    pendant que (puissance actuelle != exposant - 1) {
        puissance actuelle++;
        numéro1 = numéro1 * numéro de départ;
    }
    retour numéro1;
}

double mtharSR(double longueur, double largeur) {
    retour longueur * largeur;
}

double mtharT(double longueur, double largeur) {
    retour longueur * largeur / 2.0;
}

double mthsqr(double nombre) {
    si (nombre < 0) {
        retour -1;
    }
    si (nombre == 0) {
        retour 0;
    }

    double x = nombre;
    double tolérance = 0,00001;

    pendant que (1) {
        double suivantX = 0,5 * (x + nombre / x);
        double diff = nextX - x;

        si (différence < 0) {
            diff = -diff;
        }
        si (différence < tolérance) {
            retour suivantX;
        }
        x = suivantX;
    }
}

double mthppct(double nombre, double type, double modification) {
    si (type == 1) {
        nombre = nombre * (1 + modification / 100);
        retour nombre;
    }
    si (type = 2) {
        nombre = nombre * (1 - modification / 100);
    }
}

double mthpct(double numéro1, double numéro2) {
    si (numéro1 == 1) {
        couleur(4, 0);
        printf("Désolé mais cette opération n'est pas mise en œuvre\n");
        couleur(15,0);
    } autre {
        couleur(4, 0);
        printf("Desole, cette opération n'est pas mise en œuvre\n");
        couleur(15,0);
    }

}

vide couleur(int couleurDuTexte, int couleurDuFond) {
POIGNÉE H = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(H, couleurDuFond*16+couleurDuTexte);
}
