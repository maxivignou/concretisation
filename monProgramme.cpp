#include "maStructure.h"

int main() {
  std::string nom_depart = "bdd.txt",nom_fin = "resultat.txt";
  tableau T;
  ligne M;
  int taille;
  coeur_programme(nom_depart,nom_fin,T,M,taille);
  return 0;
}

