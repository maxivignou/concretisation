#include "maStructure.h"

int somme_colonne_ligne(tableau & T, int taille, int no_somme) { // Somme des valeurs dans la no_somme ligne et la no_somme colonne
    int Somme = 0;
    for (int i = 0; i < taille; i++) {
        Somme = Somme + T[i][no_somme] + T[no_somme][i]; 
    }
    Somme = Somme - T[no_somme][no_somme];
    return Somme;
}

void creation_toutes_sommes(tableau & T, int taille, ligne & liste_sommes) { // Création de la liste contenant toutes les sommes
    liste_sommes = new int[taille];
    for (int i = 0; i < taille; i++) {
        liste_sommes[i] = somme_colonne_ligne(T,taille,i);
    }
}
