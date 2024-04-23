#include "maStructure.h"

void maximum_aleatoire(tableau & T, int taille, ligne & M_alea, int & somme_alea) {
    if (taille < ...) {
        int quantite = ...;
    } else if (taille < ...) {
        int quantite = ...;
    } else if (taille < ...) {
        int quantite = ...;
    } else {
        int quantite = 0;
    }
    ligne M_test = new int[taille];
    somme_alea = 0;
    for (int i = 0; i < quantite; ++i) {
        for (int j = 0; j < taille; ++j) {
            M_test[j] = rand()%2;
        }
        int somme_test = somme_tableau(T, taille, M_test);
        if (somme_test > somme_alea) {
            copie(M_alea, M_test, taille);
            somme_alea = somme_test;
        }
    }
}
