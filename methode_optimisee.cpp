#include "maStructure.h"

int indice_min(ligne & L, int taille, ligne & M) { // Récupération de l'indice minimal de la liste
    int i_min = -1;
    for (int i = 0; i < taille; i++) {
        if ((i_min < 0 or L[i] < L[i_min]) and M[i] != 2) {
            i_min = i;
        }
    }
    return i_min;
}

void modifications_donnees(tableau & T, int taille, ligne & liste_sommes, ligne & M, int no_modification) { // Modifications de toutes les données lorsqu'on appliquera un nouveau masque
    for (int i = 0; i < taille; ++i) {
        if (M[i] != 0) {
            liste_sommes[i] -= T[i][no_modification];
            if (no_modification != i) {
                liste_sommes[i] -= T[no_modification][i];
                liste_sommes[no_modification] -= T[i][no_modification];
                liste_sommes[no_modification] -= T[no_modification][i];
            }
        }
    }
    M[no_modification] = 0;
}

int somme_tableau(tableau & T, int taille, ligne & M) { // Somme de toutes les valeurs du tableau
    int Somme = 0;
    for (int i = 0; i < taille; i++) {
        if (M[i] == 1) {
            for (int j = 0; j < taille; j++) {
                if (M[j] == 1) {
                    Somme += T[i][j];
                }
            }
        }
    }
    return Somme;
}

void application_masque_reccur(tableau & T, int taille, ligne & liste_sommes, ligne & M, int & score) { // Création masque total en modifiant les données
    int mini = indice_min(liste_sommes, taille, M);
    if (mini < 0) {
        score = -1;
    } else if (liste_sommes[mini] >= 0) {
        score = somme_tableau(T, taille, M);
    } else {
        int score_1, score_2;
        ligne M1, M2, liste_sommes_1, liste_sommes_2;
        M1 = new int[taille];
        M2 = new int[taille];
        liste_sommes_1 = new int[taille];
        liste_sommes_2 = new int[taille];
        for (int i = 0; i < taille; ++i) {
            liste_sommes_1[i] = L_S[i];
            liste_sommes_2[i] = L_S[i];
            M1[i] = M[i];
            M2[i] = M[i];
        }
        M2[mini] = 2;
        modifications_donnees(T, taille, liste_sommes_1, M1, mini);
        application_masque_reccur(T, taille, liste_sommes_1, M1, score_1);
        application_masque_reccur(T, taille, liste_sommes_2, M2, score_2);
        if (score_1 > score_2) {
            M = M1;
            score = score_1;
        } else {
            M = M2;
            score = score_2;
        }
    }
}

void application_masque(tableau & T, int taille, ligne & liste_sommes, ligne & M) { // Création masque total en modifiant les données
    int mini = indice_min(liste_sommes, taille, M);
    while (liste_sommes[mini] < 0) {
        modifications_donnees(T, taille, liste_sommes, M, mini);
        mini = indice_min(liste_sommes, taille, M);
    }
}
