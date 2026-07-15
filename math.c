#include "math.h"

double addition(double nombre1, double nombre2) {
    return nombre1 + nombre2;
}

double soustraction(double nombre1, double nombre2) {
    return nombre1 - nombre2;
}

double multiplication(double nombre1, double nombre2) {
    return nombre1 * nombre2;
}

double division(double nombre1, double nombre2) {
    return nombre1 / nombre2;
}

double carre(double nombre1) {
    return nombre1 * nombre1;
}

double puissance(double nombre1, double puissance) {
  double nombreDeDepart = nombre1;
  double puissanceActuelle = 0;

  while(puissanceActuelle != puissance - 1) {
    puissanceActuelle++;
    nombre1 = nombre1 * nombreDeDepart;
}
   return nombre1;
}

double aireCR(double longueur, double largeur) {
 return longueur * largeur;
}

double aireT(double longueur, double largeur) {
 return longueur * largeur / 2;
}
