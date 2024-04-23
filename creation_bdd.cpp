#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<fstream>

void random_renvoie(std::string nom_fichier, int taille) {
    srand(time(NULL));
    std::ofstream fic;
    fic.open(nom_fichier);
    if (fic.is_open()) {
        fic << taille << " " << taille * taille << std::endl;
        for (int i = 1; i <= taille; i++) {
            for (int j = 1; j <= taille; j++) {
                fic << i << " " << j << " " << (rand() % 101) - 50 << std::endl;
            }
        }
    }
}

int main() {
    std::string nom_fichier;
    int taille;
    std::cout << "Nom de fichier : ";
    std::cin >> nom_fichier;
    std::cout << "Taille du tableau : ";
    std::cin >> taille; 
    random_renvoie(nom_fichier,taille);
    return 0;
}
