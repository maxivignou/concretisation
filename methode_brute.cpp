#include "maStructure.h"

void ajoute_un(ligne & masque,int taille) {
    int i = 0;
    while ((i < taille) and (masque[i] == 1)) {
        masque[i] = 0;
        i += 1;
    }
    if (i != taille) masque[i] = 1;
}

void copie(ligne & masque_recevant, ligne & masque_envoyant, int taille) {
    for (int i = 0; i < taille; ++i) {
        masque_recevant[i] = masque_envoyant[i];
    }
}

void force_brute(tableau & T, int taille, ligne & meilleur_masque, int & meilleure_somme) {
    meilleur_masque = new int[taille];
    ligne masque_test = new int[taille];
    for (int i = 0; i < taille; ++i) {
        meilleur_masque[i] = 0;
        masque_test[i] = 0;
    }
    meilleure_somme = 0;
    for (int i = 0; i < std::pow(2, taille); ++i) {
        ajoute_un(masque_test, taille);
        int somme_test = somme_tableau(T, taille, masque_test);
        if (somme_test > meilleure_somme) {
            meilleure_somme = somme_test;
            copie(meilleur_masque, masque_test, taille);
        }
    }
}
