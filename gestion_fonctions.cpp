#include "prototypes.h"

void coeur_programme(std::string & fic_import, std::string & fic_export) {
    /*
     Objectif :
        On veut appeler toutes les fonctions pour faire fonctionner le programme.
     Paramètres :
        fic_import : std::string -> Ce paramètre contient le nom du fichier contenant les données.
        fic_export : std::string -> Ce paramètre contient le nom du fichier contenant les résultats.
     Retour :
        Pas de retour.
     */
    
    auto heure_depart = std::chrono::system_clock::now();
    tableau T;
    int taille, somme;
    recup_donnees(fic_import,T,taille);
    ligne liste_sommes;
    creation_toutes_sommes(T,taille,liste_sommes);
    ligne masque = new int[taille];
    
    for (int parcours = 0; parcours < taille; ++parcours) {
        masque[parcours] = 1;
    }
    
    if (taille <= 25) {
        recherche_masque_brute(T, taille, masque, somme);
    } else {
        if (taille <= 40) {
            recherche_masque_performance(T, taille, liste_sommes, masque, somme);
            for (int i = 0; i < taille; ++i) {
                if (masque[i] == 2) masque[i] = 1;
            }
        } else {
            recherche_masque_efficacite(T, taille, liste_sommes, masque);
            somme = somme_tableau(T, taille, masque);
        }
        masque_modifie_aleatoire(T, masque, taille, somme, heure_depart, 0);
        //gestion_regroupement(T, taille, masque_aleatoire, somme_aleatoire, heure_depart);
        //masque_modifie_aleatoire(T, masque_aleatoire, taille, somme_aleatoire, heure_depart, 0);
    }
    
    renvoi_resultat(fic_export, masque, somme, taille);
    
    for (int i = 0; i < taille; i++) {
        delete[] T[i];
    }
    
    delete[] T;
    delete[] masque;
    delete[] liste_sommes;
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    if (argc == 1) {
        std::cout << "Saisir une commande de la forme './LaGrilleMasquee.out nom_fichier_donnees_tableau.txt nom_fichier_resultats.txt'. Sachez que le 3ème paramètre est facultatif." << std::endl;
    } else {
        std::string nom_depart = argv[1];
        std::string nom_fin;
        if (argc == 2) {
            nom_fin = "resultats_" + nom_depart;
        } else {
            nom_fin = argv[2];
        }
        coeur_programme(nom_depart,nom_fin);
    }
    return 0;
}
