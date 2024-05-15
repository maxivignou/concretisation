#include "prototypes.h"

int indice_minimum(ligne & liste_sommes, ligne & masque, int taille) {
    /*
     Objectif :
        On veut trouver l'indice du minimum de la liste.
     Paramètres :
        liste_sommes : ligne -> Ce paramètre contient les sommes du tableau.
        masque : ligne -> Ce paramètre contient le masque courant.
        taille : int -> Ce paramètre indique la taille du masque.
     Retour :
        Retourne un entier qui correspond à l'indice du minimum de la liste.
     */
    
    int i_min = -1; // Il s'agit du cas où tous les indices ne peuvent pas être modifiés par l'arbre de décision (cacher ou pas cacher).
    
    for (int parcours = 0; parcours < taille; ++parcours) {
        if ( (i_min < 0 or liste_sommes[parcours] < liste_sommes[i_min]) and masque[parcours] != 2) { // La valeur du masque peut être 2 lorsque l'arbre de décision ne veut pas cacher.
            i_min = parcours;
        }
    }
    
    return i_min;
}
    
void modifications_donnees(tableau & T, int taille, ligne & liste_sommes, ligne & masque, int indice_modification) {
    /*
     Objectif :
        On veut modifier les données avec le cache d'une ligne et d'une colonne.
     Paramètres :
        T : tableau -> Ce paramètre correspond au tableau sur lequel on applique le masque.
        taille : int -> Ce paramètre indique la taille du tableau et par conséquent du masque.
        liste_sommes : ligne -> Ce paramètre contient les sommes du tableau.
        masque : ligne -> Ce paramètre contient le masque courant.
        indice_modification : int -> Ce paramètre indique l'indice de la valeur modifiée dans le masque. 
     Retour :
        Pas de retour, mais les données seront modifiées.
     */
    
    for (int parcours = 0; parcours < taille; ++parcours) {
        if (masque[parcours] != 0) {
            liste_sommes[parcours] -= T[parcours][indice_modification];
            
            if (indice_modification != parcours) {
                liste_sommes[parcours] -= T[indice_modification][parcours];
                liste_sommes[indice_modification] -= T[parcours][indice_modification];
                liste_sommes[indice_modification] -= T[indice_modification][parcours];
            }
        }
    }
    
    masque[indice_modification] = 0;
}

void recherche_masque_efficacite(tableau & T, int taille, ligne & liste_sommes, ligne & masque) {
    /*
     Objectif :
        On veut obtenir le meilleur masque possible efficacement pour des tableaux de très grande taille.
     Paramètres :
        T : tableau -> Ce paramètre correspond au tableau sur lequel on applique le masque.
        taille : int -> Ce paramètre indique la taille du tableau et par conséquent du masque.
        liste_sommes : ligne -> Ce paramètre contient les sommes du tableau.
        masque : ligne -> Ce paramètre contient le masque en cours d'amélioration.
     Retour :
        Pas de retour, mais le paramètre masque contiendra le meilleur masque trouvé.
     */
    
    int indice_minimal = indice_minimum(liste_sommes, masque, taille);
    
    while (liste_sommes[indice_minimal] < 0) {
        modifications_donnees(T, taille, liste_sommes, masque, indice_minimal);
        indice_minimal = indice_minimum(liste_sommes, masque, taille);
    }
}

void recherche_masque_performance(tableau & T, int taille, ligne & liste_sommes, ligne & masque, int & score) {
    /*
     Objectif :
        On veut obtenir le meilleur masque possible pour des tableaux de grande taille.
     Paramètres :
        T : tableau -> Ce paramètre correspond au tableau sur lequel on applique le masque.
        taille : int -> Ce paramètre indique la taille du tableau et par conséquent du masque.
        liste_sommes : ligne -> Ce paramètre contient les sommes du tableau.
        masque : ligne -> Ce paramètre contient le masque en cours d'amélioration.
        score : int -> Ce paramètre contient le score en cours d'amélioration.
     Retour :
        Pas de retour, mais les paramètres masque et score contiendront les meilleurs résultats trouvés.
     */
    
    int indice_minimal = indice_minimum(liste_sommes, masque, taille);
    
    if (indice_minimal < 0) { // Il s'agit du cas où tous les indices ne peuvent pas être modifiés par l'arbre de décision (cacher ou pas cacher).
        score = -1;
    } else if (liste_sommes[indice_minimal] >= 0) { // Il s'agit du cas où la valeur minimale est positive, donc il ne faut pas la cacher.
        score = somme_tableau(T, taille, masque);
    } else {
        int score_cache, score_visible; // L'un des deux sera celui on l'on cache la valeur négative, l'autre sera celui où l'on laisse visible la valeur négative.
        ligne masque_cache, masque_visible, liste_sommes_cache, liste_sommes_visible;
        masque_cache = new int[taille];
        masque_visible = new int[taille];
        liste_sommes_cache = new int[taille];
        liste_sommes_visible = new int[taille];
        
        for (int parcours = 0; parcours < taille; ++parcours) {
            liste_sommes_cache[parcours] = liste_sommes[parcours];
            liste_sommes_visible[parcours] = liste_sommes[parcours];
            masque_cache[parcours] = masque[parcours];
            masque_visible[parcours] = masque[parcours];
        }
        
        masque_visible[indice_minimal] = 2;
        modifications_donnees(T, taille, liste_sommes_cache, masque_cache, indice_minimal);
        recherche_masque_performance(T, taille, liste_sommes_cache, masque_cache, score_cache);
        recherche_masque_performance(T, taille, liste_sommes_visible, masque_visible, score_visible);
        
        if (score_cache > score_visible) {
            masque = masque_cache;
            score = score_cache;
        } else {
            masque = masque_visible;
            score = score_visible;
        }
    }
}
