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

int somme_colonne_ligne(tableau & T, int taille, int no_somme); // Somme des valeurs dans la no_somme ligne et la no_somme colonne

void creation_toutes_sommes(tableau & T, int taille, ligne & L_S); // Création de la liste contenant toutes les sommes

int indice_min(ligne & L, int taille); // Récupération de l'indice minimal de la liste

void modifications_donnees(tableau & T, int taille, ligne & L_S, ligne & M, int no_modification); // Modifications de toutes les données lorsqu'on appliquera un nouveau masque

void application_masque(tableau & T, int taille, ligne & L_S, ligne & M); // Création masque total en modifiant les données

int somme_tableau(tableau & T, int taille, ligne & M); // Somme de toutes les valeurs du tableau

void renvoi_resultat(std::string nom_fichier, ligne & masque, int score); // Création du fichier qui contient le masque et le score

void coeur_programme(std::string & fic_import, std::string & fic_export, tableau & T, ligne & M, int & taille); // Gestion du programme
