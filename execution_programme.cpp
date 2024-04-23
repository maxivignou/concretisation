#include "maStructure.h"

void coeur_programme(std::string & fic_import, std::string & fic_export, tableau & T, ligne & M, ligne & M_alea, int & taille) { // Gestion du programme
    recup_donnees(fic_import,T,taille);
    ligne liste_sommes;
    creation_toutes_sommes(T,taille,liste_sommes);
    M = new int[taille];
    M_alea = new int[taille];
    for (int i = 0; i < taille; ++i) {
        M[i] = 1;
        M_alea[i] = 0;
    }
    int somme_etude, somme_alea = -1;
    if (taille <= 25) {
        force_brute(T, taille, M, somme_etude);
    } else if (taille <= 40) {
        application_masque_reccur(T, taille, liste_sommes, M, somme_etude);
        std::cout << "Fin application masque" << std::endl;
        maximum_aleatoire(T, taille, M_alea, somme_alea);
        for (int i = 0; i < taille; ++i) {
            if (M[i] == 2) M[i] = 1;
        }
    } else {
        application_masque(T, taille, liste_sommes, M);
        somme_etude = somme_tableau(T, taille, M);
        std::cout << "Fin application masque" << std::endl;
        maximum_aleatoire(T, taille, M_alea, somme_alea);
        for (int i = 0; i < taille; ++i) {
            if (M[i] == 2) M[i] = 1;
        }
    }
    if (somme_etude > somme_alea) {
        renvoi_resultat(fic_export,M,somme_etude,taille);
    } else {
        renvoi_resultat(fic_export, M_alea, somme_alea, taille);
    }
    for (int i = 0; i < taille; i++) {
        delete[] T[i];
    }
    delete[] T;
    delete[] M;
    delete[] M_alea;
    delete[] liste_sommes;
}

int main() {
    srand(time(NULL));
    std::string nom_depart;
    std::cout << "Saisir le nom du fichier texte dans lequel on trouvera les donnees du tableau (ex : base_donnees.txt) : ";
    std::cin >> nom_depart;
    std::string nom_fin = "resultats_" + nom_depart;
    tableau T;
    ligne M, M_alea;
    int taille;
    coeur_programme(nom_depart,nom_fin,T,M, M_alea,taille);
    return 0;
}
