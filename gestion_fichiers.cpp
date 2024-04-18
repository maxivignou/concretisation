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
