#include "maStructure.h"

void init_tableau(tableau & T, int taille) { // Initialisation du tableau avec des valeurs nulles
    T = new ligne[taille];
    for(int i = 0; i < taille; i++){
        T[i] = new int[taille];
        for(int j = 0; j < taille; j++){
            T[i][j] = 0;
        }
    }
}

void recup_donnees(std::string nom_fichier, tableau & T, int & taille) { // Création de la matrice carrée avec les données du fichier
  std::ifstream fichier_texte;
  fichier_texte.open(nom_fichier);
  if (fichier_texte.is_open()) {
    int nb_lignes;
    fichier_texte >> taille >> nb_lignes;
    init_tableau(T, taille);
    int indice_ligne, indice_colonne, valeur;
    for (int i = 0; i < nb_lignes; ++i) {
      fichier_texte >> indice_ligne >> indice_colonne >> valeur;
      T[indice_ligne - 1][indice_colonne - 1] = valeur;
    }
  }
}

int somme_colonne_ligne(tableau & T, int taille, int no_somme) { // Somme des valeurs dans la no_somme ligne et la no_somme colonne
    int Somme = 0;
    for (int i = 0; i < taille; i++) {
        Somme = Somme + T[i][no_somme] + T[no_somme][i]; 
    }
    Somme = Somme - T[no_somme][no_somme];
    return Somme;
}

void creation_toutes_sommes(tableau & T, int taille, ligne & L_S) { // Création de la liste contenant toutes les sommes
    L_S = new int[taille];
    for (int i = 0; i < taille; i++) {
        L_S[i] = somme_colonne_ligne(T,taille,i);
    }
}

int indice_min(ligne & L, int taille) { // Récupération de l'indice minimal de la liste
    int i_min = 0;
    for (int i = 1; i < taille; i++) {
        if (L[i] < L[i_min]) {
            i_min = i;
        }
    }
    return i_min;
}

void modifications_donnees(tableau & T, int taille, ligne & L_S, ligne & M, int no_modification) { // Modifications de toutes les données lorsqu'on appliquera un nouveau masque
    M[no_modification] = 0;
    for (int i = 0; i < taille; ++i) {
        L_S[i] -= T[i][no_modification];
        if (no_modification != i) {
            L_S[i] -= T[no_modification][i];
            L_S[no_modification] -= T[i][no_modification];
            L_S[no_modification] -= T[no_modification][i];
        }
    }
}

void application_masque(tableau & T, int taille, ligne & L_S, ligne & M) { // Création masque total en modifiant les données
    M = new int[taille];
    for (int i = 0; i < taille; ++i) {
        M[i] = 1;
    }
    int mini = indice_min(L_S, taille);
    while (L_S[mini] < 0) {
        modifications_donnees(T, taille, L_S, M, mini);
        mini = indice_min(L_S, taille);
    }
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

void renvoi_resultat(std::string nom_fichier, ligne & masque, int score, int taille) { // Création du fichier qui contient le masque et le score
    std::ofstream fichier_texte;
    fichier_texte.open(nom_fichier);
    if (fichier_texte.is_open()) {
        for (int i = 0; i < taille; ++i) {
            fichier_texte << masque[i];
        }
        fichier_texte << std::endl << score << std::endl;
    }
}

void coeur_programme(std::string & fic_import, std::string & fic_export, tableau & T, ligne & M, int & taille) { // Gestion du programme
    recup_donnees(fic_import,T,taille);
    ligne L_S;
    creation_toutes_sommes(T,taille,L_S);
    application_masque(T,taille,L_S,M);
    int S_T = somme_tableau(T,taille,M);
    renvoi_resultat(fic_export,M,S_T,taille);
    for (int i = 0; i < taille; i++) {
        delete[] T[i];
    }
    delete[] T;
    delete[] M;
    delete[] L_S;
}
