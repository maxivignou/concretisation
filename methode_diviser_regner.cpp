#include "prototypes.h"

int petit_diviseur(int n) {
    /*
     Objectif :
        On cherche un petit diviseur du nombre.
     Paramètres :
        n : int -> Ce paramètre est le nombre dont on cherche le diviseur.
     Retour :
        Retourne un entier qui correspond au petit diviseur trouvé ou 0 s'il n'a pas de petit diviseur.
     */
    
    if (n%2 == 0) return 2;
    else if (n%3 == 0) return 3;
    else if (n%5 == 0) return 5;
    else return 0; // Il s'agit du cas où on ne trouve pas de petit diviseur
}

void fusionne_cases(tableau & T_origine, int taille, tableau & T_diminue, int coef) {
    /*
     Objectif :
        On veut fusionner des cases du tableau pour diminuer sa taille.
     Paramètres :
        T_orinine : tableau -> Ce paramètre contient les données du tableau d'origine.
        taille : int -> Ce paramètre correspond à la taille du tableau.
        T_diminue : tableau -> Ce paramètre contient les données du tableau diminué.
        coef : int -> Ce paramètre contient le coefficient de diminution.
     Retour :
        Pas de retour, mais le paramètre T_diminue contiendra le tableau plus petit.
     */
    
    T_diminue = new ligne[taille / coef];
    
    for(int parcours_lignes = 0; parcours_lignes < taille / coef; ++parcours_lignes) {
        T_diminue[parcours_lignes] = new int[taille/coef];
        
        for(int parcours_colonnes = 0; parcours_colonnes < taille/coef; parcours_colonnes++) {
            for(int parcours_lignes_case = 0; parcours_lignes_case < coef; ++parcours_lignes_case) {
                for(int parcours_colonnes_case = 0; parcours_colonnes_case < coef; ++parcours_colonnes_case) { // Il s'agit de parcourir chaque groupe de cases.
                    T_diminue[parcours_lignes][parcours_colonnes] += T_origine[parcours_lignes*coef+parcours_lignes_case][parcours_colonnes*coef+parcours_colonnes_case];
                }
            }
        }
    }   
}

void extension_masque(ligne & masque, int taille, ligne & masque_grand, int coef) {
    /*
     Objectif :
        On veut étendre le masque obtenu sur le petit tableau.
     Paramètres :
        masque : ligne -> Ce paramètre contient le petit masque.
        taille : int -> Ce paramètre correspond à la taille du tableau.
        masque_grand : ligne -> Ce paramètre contient legrand masque.
        coef : int -> Ce paramètre contient le coefficient d'augmentation.
     Retour :
        Pas de retour, mais le paramètre masque_grand contiendra le masque recherché.
     */
    
    masque_grand = new int[taille*coef];
    
    for(int parcours = 0; parcours < taille; ++parcours) {
        for(int mulplicite = 0; mulplicite < coef; ++mulplicite) {
            masque_grand[parcours*coef+mulplicite] = masque[parcours];
        }
    }
}

void ajout_ligne_colonne(tableau & T, int & taille) {
    /*
     Objectif :
        On veut ajouter une ligne et une colonne au tableau.
     Paramètres :
        T : tableau -> Ce paramètre contient le tableau.
        taille : int -> Ce paramètre correspond à la taille du tableau.
     Retour :
        Pas de retour, mais le paramètre T contiendra le tableau aggrandi.
     */
    
    tableau T_grand = new ligne[taille + 1];
    
    for (int parcours_lignes = 0; parcours_lignes < taille + 1; ++parcours_lignes) {
        T_grand[parcours_lignes] = new int[taille + 1];
        
        for (int parcours_colonnes = 0; parcours_colonnes < taille; ++parcours_colonnes) {
            T_grand[parcours_lignes][parcours_colonnes] = T[parcours_lignes][parcours_colonnes];
        }
        
        T_grand[parcours_lignes][taille] = 0;
    }
    
    T_grand[taille] = new int[taille + 1];
    
    for (int parcours_colonnes = 0; parcours_colonnes < taille + 1; ++parcours_colonnes) {
        T_grand[taille][parcours_colonnes] = 0;
    }
    
    for (int parcours_lignes = 0; parcours_lignes < taille; ++parcours_lignes) {
        delete[] T[parcours_lignes];
    }
    
    delete[] T;
    T = T_grand;
    taille += 1;
}

void masque_modifie_aleatoire(tableau & T, ligne & masque, int taille, int & somme, heure heure_depart, int quantite) {
    /*
     Objectif :
        On veut trouver le meilleur masque aléatoirement.
     Paramètres :
        T : tableau -> Ce paramètre contient le tableau.
        masque : ligne -> Ce paramètre contient le meilleur masque.
        taille : int -> Ce paramètre correspond à la taille du tableau et du masque.
        somme : int -> Ce paramètre correspond à la meilleure somme trouvé aléatoirement.
        heure_depart : heure -> Ce paramètre correspond à l'heure du début du programme.
        quantite : int -> Ce paramètre correspond au nombre de tentatives qu'on pourra faire.
     Retour :
        Pas de retour, mais les paramètres masque et somme contiendront les meilleurs résultats.
     */
    
    ligne masque_test = new int[taille];
    heure heure_fin = std::chrono::system_clock::now();
    std::chrono::duration<double> difference_temps;
    int change;
    int faits = 0;
    
    do {
        for (int parcours = 0; parcours < taille; ++parcours) {
            change = rand()%taille;
            
            if (change < 2) {
                masque_test[parcours] = 1 - masque[parcours];
            } else {
                masque_test[parcours] = masque[parcours];
            }
        }
        
        int somme_test = somme_tableau(T, taille, masque_test);
        
        if (somme_test > somme) {
            copie_masque(masque, masque_test, taille);
            somme = somme_test;
        }
        
        heure_fin = std::chrono::system_clock::now();
        difference_temps = heure_fin - heure_depart;
        faits += 1;
        
    } while (difference_temps.count() < 58 and ((quantite > faits) or (quantite == 0)));
}

void recherche_masque_regroupement(tableau & T, int & taille, ligne & masque, int & somme, heure heure_depart) {
    /*
     Objectif :
        On veut trouver le meilleur masque en réduisant le tableau.
     Paramètres :
        T : tableau -> Ce paramètre contient le tableau.
        taille : int -> Ce paramètre correspond à la taille du tableau et du masque.
        masque : ligne -> Ce paramètre contient le meilleur masque.
        somme : int -> Ce paramètre correspond à la meilleure somme trouvé aléatoirement.
        heure_depart : heure -> Ce paramètre correspond à l'heure du début du programme.
     Retour :
        Pas de retour, mais les paramètres masque et somme contiendront les meilleurs résultats.
     */
    
    bool ajout = false;
    int coef = petit_diviseur(taille);
    
    if (coef == 0) {
        ajout_ligne_colonne(T, taille);
        coef = petit_diviseur(taille);
        ajout = true;
    }
    
    tableau T_petit;
    fusionne_cases(T, taille, T_petit, coef);
    int taille_petit = taille/coef;
    ligne masque_petit = new int[taille_petit];
    
    if (taille_petit >= 25) {
        recherche_masque_regroupement(T_petit, taille_petit, masque_petit, somme, heure_depart);
    } else {
        recherche_masque_brute(T_petit, taille_petit, masque_petit, somme);
    }
    
    extension_masque(masque_petit, taille_petit, masque, coef);
    masque_modifie_aleatoire(T, masque, taille, somme, heure_depart, 1000000);
    
    if (ajout) taille -= 1;
}
