#include "maStructure.h"

int indice_min(ligne & liste_sommes, int taille, ligne & masque) { // Récupération de l'indice minimal de la liste
    int i_min = -1;
    for (int i = 0; i < taille; i++) {
        if ((i_min < 0 or liste_sommes[i] < liste_sommes[i_min]) and masque[i] != 2) {
            i_min = i;
        }
    }
    return i_min;
}

void modifications_donnees(tableau & T, int taille, ligne & liste_sommes, ligne & masque, int no_modification) { // Modifications de toutes les données lorsqu'on appliquera un nouveau masque
    for (int i = 0; i < taille; ++i) {
        if (masque[i] != 0) {
            liste_sommes[i] -= T[i][no_modification];
            if (no_modification != i) {
                liste_sommes[i] -= T[no_modification][i];
                liste_sommes[no_modification] -= T[i][no_modification];
                liste_sommes[no_modification] -= T[no_modification][i];
            }
        }
    }
    masque[no_modification] = 0;
}

int somme_tableau(tableau & T, int taille, ligne & masque) { // Somme de toutes les valeurs du tableau
    int somme = 0;
    for (int i = 0; i < taille; i++) {
        if (masque[i] == 1) {
            for (int j = 0; j < taille; j++) {
                if (masque[j] == 1) {
                    somme += T[i][j];
                }
            }
        }
    }
    return somme;
}

void application_masque_reccur(tableau & T, int taille, ligne & liste_sommes, ligne & masque, int & score) { // Création masque total en modifiant les données
    int indice_mini = indice_min(liste_sommes, taille, masque);
    if (indice_mini < 0) {
        score = -1;
    } else if (liste_sommes[indice_mini] >= 0) {
        score = somme_tableau(T, taille, masque);
    } else {
        int score_1, score_2;
        ligne masque_1, masque_2, liste_sommes_1, liste_sommes_2;
        masque_1 = new int[taille];
        masque_2 = new int[taille];
        liste_sommes_1 = new int[taille];
        liste_sommes_2 = new int[taille];
        for (int i = 0; i < taille; ++i) {
            liste_sommes_1[i] = liste_sommes[i];
            liste_sommes_2[i] = liste_sommes[i];
            masque_1[i] = masque[i];
            masque_2[i] = masque[i];
        }
        masque_2[indice_mini] = 2;
        modifications_donnees(T, taille, liste_sommes_1, masque_1, indice_mini);
        application_masque_reccur(T, taille, liste_sommes_1, masque_1, score_1);
        application_masque_reccur(T, taille, liste_sommes_2, masque_2, score_2);
        if (score_1 > score_2) {
            masque = masque_1;
            score = score_1;
        } else {
            masque = masque;
            score = score_2;
        }
    }
}

void application_masque(tableau & T, int taille, ligne & liste_sommes, ligne & masque) { // Création masque total en modifiant les données
    int indice_mini = indice_min(liste_sommes, taille, masque);
    while (liste_sommes[indice_mini] < 0) {
        modifications_donnees(T, taille, liste_sommes, masque, indice_mini);
        indice_mini = indice_min(liste_sommes, taille, masque);
    }
}
