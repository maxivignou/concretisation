#include "maStructure.h"

void maximum_aleatoire(tableau & T, int taille, ligne & meilleur_masque, int & meilleure_somme) {
    int quantite;
    if (taille < 1000) {
        quantite = 2500;
    } else {
        quantite = 0;
    }
    ligne masque_test = new int[taille];
    meilleure_somme = 0;
    for (int i = 0; i < quantite; ++i) {
        for (int j = 0; j < taille; ++j) {
            masque_test[j] = rand()%2;
        }
        int somme_test = somme_tableau(T, taille, M_test);
        if (somme_test > meilleure_somme) {
            copie(meilleur_masque, masque_test, taille);
            meilleure_somme = somme_test;
        }
    }
}
