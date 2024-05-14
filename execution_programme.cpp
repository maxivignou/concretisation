#include "maStructure.h"

void coeur_programme(std::string & fic_import, std::string & fic_export) { // Gestion du programme
    auto heure_depart = std::chrono::system_clock::now();
    tableau T;
    int taille;
    recup_donnees(fic_import,T,taille);
    ligne liste_sommes;
    creation_toutes_sommes(T,taille,liste_sommes);
    ligne masque_etude = new int[taille];
    ligne masque_aleatoire = new int[taille];
    for (int i = 0; i < taille; ++i) {
        masque_etude[i] = 1;
        masque_aleatoire[i] = 0;
    }
    int somme_etude, somme_aleatoire = -1;
    if (taille <= 25) {
        force_brute(T, taille, masque_etude, somme_etude);
    } else {
        if (taille <= 40) {
            application_masque_reccur(T, taille, liste_sommes, masque_etude, somme_etude);
            for (int i = 0; i < taille; ++i) {
                if (masque_etude[i] == 2) masque_etude[i] = 1;
            }
        } else {
            application_masque(T, taille, liste_sommes, masque_etude);
            somme_etude = somme_tableau(T, taille, masque_etude);
        }
        masque_modifie_aleatoire(T, masque_etude, taille, somme_etude, heure_depart, 0);
        //gestion_regroupement(T, taille, masque_aleatoire, somme_aleatoire, heure_depart);
        //masque_modifie_aleatoire(T, masque_aleatoire, taille, somme_aleatoire, heure_depart, 0);
    }
    if (somme_etude > somme_aleatoire) {
        renvoi_resultat(fic_export,masque_etude,somme_etude,taille);
    } else {
        renvoi_resultat(fic_export, masque_aleatoire, somme_aleatoire, taille);
    }
    for (int i = 0; i < taille; i++) {
        delete[] T[i];
    }
    delete[] T;
    delete[] masque_etude;
    delete[] masque_aleatoire;
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
