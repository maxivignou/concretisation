#include "maStructure.h"

void regroupe(tableau & T, int taille, tableau & T_petit, int coef) {
    T_petit = new ligne[taille/coef];
    for(int i = 0; i < taille/coef; i++) {
        T_petit[i] = new int[taille/coef];
        for(int j = 0; j < taille/coef; j++) {
            T_petit[i][j] = 0;
            for(int k = 0; k < coef; k++) {
                for(int l = 0; l < coef; l++) {
                    T_petit[i][j] += T[i*coef+k][j*coef+l];
                }
            }
        }
    }   
}

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

void gestion_regroupement(tableau & T, int & taille, ligne & masque, int & somme) {
    bool ajout = false;
    int coef = diviseur(taille);
    if (coef == 0) {
        ajout_ligne_colonne(T, taille);
        coef = diviseur(taille);
        ajout = true;
    }
    tableau T_petit;
    regroupe(T, taille, T_petit, coef);
    masque_petit = new int[taille/coef];
    if (taille/coef > 25) {
        gestion_regroupement(T_petit, taille/coef, masque_petit);
    } else {
        force_brute(T_petit, taille/coef, masque_petit, somme);
    }
    extension_masque(masque_petit, taille/coef, masque, coef);
    if (ajout) taille -= 1;
    // Force brute autour de ce masque...
}
