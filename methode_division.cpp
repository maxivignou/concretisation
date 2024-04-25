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

int diviseur(int n) {
    if(n%2 == 0) return 2;
    else if(n%3 == 0) return 3;
    else if(n%5 == 0) return 5;
    else return 0;
}

void extension_masque(ligne & masque, int taille, ligne & masque_grand, int coef) {
    masque_grand = new int[taille*coef];
    for(int i = 0; i < taille; i++) {
        for(int j = 0; j < coef; j++) {
            masque_grand[i*coef+j] = masque[i];
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

void masque_modifie_aleatoire(tableau & T, ligne & meilleur_masque, int taille, int & meilleure_somme, heure heure_depart) {
    ligne masque_test = new int[taille];
    heure heure_fin = std::chrono::system_clock::now();
    std::chrono::duration<double> difference_temps;
    int change;
    do {
        for (int i = 0; i < taille; ++i) {
            change = rand()%4;
            if (change == 0) {
                masque_test[i] = 1 - meilleur_masque[i];
            } else {
                masque_test[i] = meilleur_masque[i];
            }
        }
        int somme_test = somme_tableau(T, taille, masque_test);
        if (somme_test > meilleure_somme) {
            copie(meilleur_masque, masque_test, taille);
            meilleure_somme = somme_test;
        }
        heure_fin = std::chrono::system_clock::now();
        difference_temps = heure_fin - heure_depart;
    } while (difference_temps.count() < 58);
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
    ligne masque_petit = new int[taille/coef];
    if (taille/coef > 25) {
        gestion_regroupement(T_petit, taille/coef, masque_petit);
    } else {
        force_brute(T_petit, taille/coef, masque_petit, somme);
    }
    extension_masque(masque_petit, taille/coef, masque, coef);
    if (ajout) taille -= 1;
}
