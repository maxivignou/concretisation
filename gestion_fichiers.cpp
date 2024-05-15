#include "prototypes.h"

void creation_tableau_nul(tableau & T, int taille) {
    /*
     Objectif :
        On veut initialiser le tableau avec des valeurs nulles.
     Paramètres :
        T : tableau -> Ce paramètre est le tableau contenant les données.
        taille : int -> Ce paramètre indique la taille du tableau.
     Retour :
        Pas de retour, mais le paramètre T contient le tableau attendu.
     */
    
    T = new ligne[taille];
    
    for(int parcours_lignes = 0; parcours_lignes < taille; ++parcours_lignes) {
        T[parcours_lignes] = new int[taille];
        
        for(int parcours_colonnes = 0; parcours_colonnes < taille; ++parcours_colonnes) {
            T[parcours_lignes][parcours_colonnes] = 0;
        }
    }
}

void recup_donnees(std::string nom_fichier, tableau & T, int & taille) {
    /*
     Objectif :
        On veut récuperer les données de notre fichier texte.
     Paramètres :
        nom_fichier : std::string -> Ce paramètre contient le nom du fichier texte.
        T : tableau -> Ce paramètre est le tableau contenant les données.
        taille : int -> Ce paramètre indique la taille du tableau.
     Retour :
        Pas de retour, mais le paramètre T contient le tableau attendu, et le paramètre taille contient la taille du tableau.
     */

    std::ifstream fichier_texte;
    fichier_texte.open(nom_fichier);
    
    if (fichier_texte.is_open()) {
        int nb_lignes;
        fichier_texte >> taille >> nb_lignes;
        creation_tableau_nul(T, taille);
        int indice_ligne, indice_colonne, valeur;
        
        for (int parcours = 0; parcours < nb_lignes; ++parcours) {
            fichier_texte >> indice_ligne >> indice_colonne >> valeur;
            T[indice_ligne - 1][indice_colonne - 1] = valeur;
        }
    }
}


void renvoi_resultat(std::string nom_fichier, ligne & masque, int score, int taille) {
    /*
     Objectif :
        On veut renvoyer les résultats dans un fichier texte.
     Paramètres :
        nom_fichier : std::string -> Ce paramètre contient le nom du fichier texte.
        masque : ligne -> Ce paramètre contient le masque à renvoyer.
        score : int -> Ce paramètre contient le score maximum trouvé.
        taille : int -> Ce paramètre indique la taille du masque.
     Retour :
        Pas de retour, mais les résultats seront présents dans le fichier texte créé.
     */
    
    std::ofstream fichier_texte;
    fichier_texte.open(nom_fichier);
    
    if (fichier_texte.is_open()) {
        for (int parcours = 0; parcours < taille; ++parcours) {
            fichier_texte << masque[parcours];
        }
        
        fichier_texte << std::endl << score << std::endl;
    }
}
