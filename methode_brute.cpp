#include "maStructure.h"

void ajoute_un(ligne & L,int taille) {
    int i = 0;
    while ((i < taille) and (L[i] == 1)) {
        L[i] = 0;
        i += 1;
    }
    if (i != taille) L[i] = 1;
}

void copie(ligne & LR, ligne & LE, int taille) {
    for (int i = 0; i < taille; ++i) {
        LR[i] = LE[i];
    }
}

void force_brute(tableau & T, int taille, ligne & M_meilleur, int & S_meilleur) {
    M_meilleur = new int[taille];
    ligne M_test = new int[taille];
    for (int i = 0; i < taille; ++i) {
        M_meilleur[i] = 0;
        M_test[i] = 0;
    }
    S_meilleur = 0;
    for (int i = 0; i < std::pow(2, taille); ++i) {
        ajoute_un(M_test, taille);
        int S_test = somme_tableau(T, taille, M_test);
        if (S_test > S_meilleur) {
            S_meilleur = S_test;
            copie(M_meilleur, M_test, taille);
        }
    }
}
