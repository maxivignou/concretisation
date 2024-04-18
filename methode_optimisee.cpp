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

void modifications_donnees(tableau & T, int taille, ligne & L_S, ligne & M, int no_modification) { // Modifications de toutes les données lorsqu'on appliquera un nouveau masque
    for (int i = 0; i < taille; ++i) {
        if (M[i] != 0) {
            L_S[i] -= T[i][no_modification];
            if (no_modification != i) {
                L_S[i] -= T[no_modification][i];
                L_S[no_modification] -= T[i][no_modification];
                L_S[no_modification] -= T[no_modification][i];
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

void application_masque(tableau & T, int taille, ligne & L_S, ligne & M, int & score) { // Création masque total en modifiant les données
    int mini = indice_min(L_S, taille, M);
    if (mini < 0) {
        score = -1;
    }
    else if (L_S[mini] >= 0) {
        score = somme_tableau(T, taille, M);
    } else {
        int score_1, score_2;
        ligne M1, M2, L_S1, L_S2;
        M1 = new int[taille];
        M2 = new int[taille];
        L_S1 = new int[taille];
        L_S2 = new int[taille];
        for (int i = 0; i < taille; ++i) {
            L_S1[i] = L_S[i];
            L_S2[i] = L_S[i];
            M1[i] = M[i];
            M2[i] = M[i];
        }
        M2[mini] = 2;
        modifications_donnees(T, taille, L_S1, M1, mini);
        application_masque(T, taille, L_S1, M1, score_1);
        application_masque(T, taille, L_S2, M2, score_2);
        if (score_1 > score_2) {
            M = M1;
            score = score_1;
        } else {
            M = M2;
            score = score_2;
        }
    }
}
