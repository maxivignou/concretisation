#include "maStructure.h"

void coeur_programme(std::string & fic_import, std::string & fic_export, tableau & T, ligne & M, int & taille) { // Gestion du programme
    recup_donnees(fic_import,T,taille);
    ligne L_S;
    creation_toutes_sommes(T,taille,L_S);
    M = new int[taille];
    for (int i = 0; i < taille; ++i) {
        M[i] = 1;
    }
    int S_T;
    if (taille <= 20) {
        force_brute(T, taille, M, S_T);
    } else {
        application_masque(T, taille, L_S, M, S_T);
        for (int i = 0; i < taille; ++i) {
            if (M[i] == 2) M[i] = 1;
        }
    }
    renvoi_resultat(fic_export,M,S_T,taille);
    for (int i = 0; i < taille; i++) {
        delete[] T[i];
    }
    delete[] T;
    delete[] M;
    delete[] L_S;
}

int main() {
  std::string nom_depart = "bdd.txt",nom_fin = "resultat.txt";
  tableau T;
  ligne M;
  int taille;
  coeur_programme(nom_depart,nom_fin,T,M,taille);
  return 0;
}

