#include "maStructure.h"

void maximum_aleatoire(tableau & T, int taille, ligne & meilleur_masque, int & meilleure_somme, auto heure_depart) {
    ligne masque_test = new int[taille];
    meilleure_somme = 0;
    auto heure_fin;
    std::chrono::duration<double> difference_temps;
    do {
        for (int j = 0; j < taille; ++j) {
            masque_test[j] = rand()%2;
        }
        int somme_test = somme_tableau(T, taille, masque_test);
        if (somme_test > meilleure_somme) {
            copie(meilleur_masque, masque_test, taille);
            meilleure_somme = somme_test;
        }
        heure_fin = std::chrono::system_clock::now();
        difference_temps = heure_fin - heure_depart;
    } while (difference_temps.count() < 50);
}
