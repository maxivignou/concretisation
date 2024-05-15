#include "prototypes.h"

void masque_suivant(ligne & masque, int taille) {
    /*
     Objectif :
        On cherche un nouveau masque à tester. En faisant comme une addition en binaire, on obtient le masque suivant.
     Paramètres :
        masque : ligne -> Ce paramètre correspond au masque qui vient d'être testé, et qui contiendra le masque suivant.
        taille : int -> Ce paramètre indique la taille du masque.
     Retour :
        Pas de retour, mais le paramètre masque contient le masque obtenu par la fonction.
     */
    
    int parcours = 0;
    
    while ( (parcours < taille) and (masque[parcours] == 1) ) { // Il s'agit de gérer les éventuelles retenues
        masque[parcours] = 0;
        parcours += 1;
    }
    
    if (parcours != taille) {
        masque[parcours] = 1;
    }
}

void copie_masque(ligne & masque_recevant, ligne & masque_envoyant, int taille) {
    /*
     Objectif :
        On cherche à copier un masque. On copie alors élément par élément masque_envoyant dans masque_recevant.
     Paramètres :
        masque_recevant : ligne -> Ce paramètre correspond au masque qui recevra la copie.
        masque_envoyant : ligne -> Ce paramètre correspond au masque que l'on doit copier.
        taille : int -> Ce paramètre indique la taille du masque.
     Retour :
        Pas de retour, mais le paramètre masque_recevant contient le masque obtenu par la fonction.
     */
    
    for (int parcours = 0; parcours < taille; ++parcours) {
        masque_recevant[parcours] = masque_envoyant[parcours];
    }
}

void recherche_masque_brute(tableau & T, int taille, ligne & masque, int & somme) {
    /*
     Objectif :
        On veut obtenir le masque ayant la plus grande somme possible.
     Paramètres :
        T : tableau -> Ce paramètre est le tableau sur lequel on doit appliquer le masque.
        taille : int -> Ce paramètre indique la taille du tableau et par conséquent du masque.
        masque : ligne -> Ce paramètre correspond au meilleur masque possible.
        somme : int -> Ce paramètre correspond à la meilleure somme possible.
     Retour :
        Pas de retour, mais les paramètres masque et somme contiennent les résultats attendus.
     */
    
    masque = new int[taille];
    ligne masque_test = new int[taille];
    somme = 0;
    
    for (int parcours = 0; parcours < taille; ++parcours) { // Il s'agit d'initialiser les masques
        masque[parcours] = 0;
        masque_test[parcours] = 0;
    }
    
    for (int parcours = 0; parcours < std::pow(2, taille); ++parcours) {
        masque_suivant(masque_test, taille);
        int somme_test = somme_tableau(T, taille, masque_test);
        if (somme_test > somme) {
            somme = somme_test;
            copie_masque(masque, masque_test, taille);
        }
    }
}
