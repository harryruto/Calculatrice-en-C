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

  while(puissanceActuelle != puissance) {
    nombre1 = nombre1 * nombreDeDepart;
    puissanceActuelle++;
  }
   return nombre1;
}
