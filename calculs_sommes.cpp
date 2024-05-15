#include "prototypes.h"

int somme_tableau(tableau & T, int taille, ligne & masque) {
    /*
     Objectif :
        On veut calculer la somme du tableau en prennant en compte le masque.
     Paramètres :
        T : tableau -> Ce paramètre est le tableau sur lequel on doit appliquer le masque.
        taille : int -> Ce paramètre indique la taille du tableau et par conséquent du masque.
        masque : ligne -> Ce paramètre correspond au masque qu'on applique sur le tableau.
     Retour :
        Retourne un entier qui correspond à la somme du tableau avec le masque appliqué
     */
    
    int somme = 0;
    
    for (int parcours_lignes = 0; parcours_lignes < taille; ++parcours_lignes) {
        if (masque[parcours_lignes] == 1) {
            for (int parcours_colonnes = 0; parcours_colonnes < taille; ++parcours_colonnes) {
                if (masque[parcours_colonnes] == 1) {
                    somme += T[parcours_lignes][parcours_colonnes];
                }
            }
        }
    }
    
    return somme;
}

int somme_colonne_ligne(tableau & T, int taille, int numero_ligne_colonne) {
    /*
     Objectif :
        On veut calculer la somme des éléments d'une ligne et d'une colonne.
     Paramètres :
        T : tableau -> Ce paramètre est le tableau contenant les données.
        taille : int -> Ce paramètre indique la taille du tableau.
        numero_ligne_colonne : int -> Ce paramètre indique l'indice des éléments à sommer.
     Retour :
        Retourne un entier qui correspond à la somme des éléments de la ligne et de la colonne indiquées.
     */
    
    int somme = 0;
    
    for (int parcours = 0; parcours < taille; ++parcours) {
        somme += T[parcours][numero_ligne_colonne] + T[numero_ligne_colonne][parcours];
    }
    
    somme -= T[numero_ligne_colonne][numero_ligne_colonne]; // Il s'agit d'enlever la valeur comptée deux fois
    return somme;
}

void creation_toutes_sommes(tableau & T, int taille, ligne & liste_sommes) {
    /*
     Objectif :
        On veut créer la liste contenant toutes les sommes des couples lignes/colonnes.
     Paramètres :
        T : tableau -> Ce paramètre est le tableau contenant les données.
        taille : int -> Ce paramètre indique la taille du tableau.
        liste_sommes : ligne -> Ce paramètre contient toutes les sommes.
     Retour :
        Pas de retour, mais le paramètre liste_sommes contient la liste attendue.
     */
    
    liste_sommes = new int[taille];
    
    for (int parcours = 0; parcours < taille; ++parcours) {
        liste_sommes[parcours] = somme_colonne_ligne(T, taille, parcours);
    }
}
