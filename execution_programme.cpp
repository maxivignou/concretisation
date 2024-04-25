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
        gestion_regroupement(T, taille, masque_aleatoire, somme_aleatoire);
        masque_modifie_aleatoire(T, masque_aleatoire, taille, somme_aleatoire, heure_depart);
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

int main() {
    srand(time(NULL));
    std::string nom_depart;
    std::cout << "Saisir le nom du fichier texte dans lequel on trouvera les donnees du tableau (ex : base_donnees.txt) : ";
    std::cin >> nom_depart;
    std::string nom_fin = "resultats_" + nom_depart;
    coeur_programme(nom_depart,nom_fin);
    return 0;
}
