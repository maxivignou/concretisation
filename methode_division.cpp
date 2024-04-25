#include "maStructure.h"

void ajout_ligne_colonne(tableau & T, int & taille) {
    tableau T_grand = new ligne[taille + 1];
    for (int i = 0; i < taille + 1; ++i) {
        T_grand[i] = new int[taille + 1];
        for (int j = 0; j < taille; ++j) {
            T_grand[i][j] = T[i][j];
        }
        T_grand[i][taille] = 0;
    }
    T_grand[taille] = new int[taille + 1];
    for (int j = 0; j < taille + 1; ++j) {
        T_grand[taille][j] = 0;
    }
    for (int i = 0; i < taille; ++i) {
        delete[] T[i];
    }
    delete[] T;
    T = T_grand;
    taille += 1;
}
