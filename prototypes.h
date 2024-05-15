#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <chrono>

using ligne = int*;
using tableau = ligne*;
using heure = std::chrono::time_point<std::chrono::_V2::system_clock, std::chrono::duration<long, std::ratio<1l, 1000000000l> > >;

void masque_suivant(ligne & masque, int taille);

void copie_masque(ligne & masque_recevant, ligne & masque_envoyant, int taille);

void recherche_masque_brute(tableau & T, int taille, ligne & masque, int & somme);

int indice_minimum(ligne & liste_sommes, ligne & masque, int taille);

void modifications_donnees(tableau & T, int taille, ligne & liste_sommes, ligne & masque, int indice_modification);

void recherche_masque_efficacite(tableau & T, int taille, ligne & liste_sommes, ligne & masque);

void recherche_masque_performance(tableau & T, int taille, ligne & liste_sommes, ligne & masque, int & score);

int petit_diviseur(int n);

void fusionne_cases(tableau & T_origine, int taille, tableau & T_diminue, int coef);

void extension_masque(ligne & masque, int taille, ligne & masque_grand, int coef);

void ajout_ligne_colonne(tableau & T, int & taille);

void masque_modifie_aleatoire(tableau & T, ligne & masque, int taille, int & somme, heure heure_depart, int quantite);

void recherche_masque_regroupement(tableau & T, int & taille, ligne & masque, int & somme, heure heure_depart);

void creation_tableau_nul(tableau & T, int taille);

void recup_donnees(std::string nom_fichier, tableau & T, int & taille);

void renvoi_resultat(std::string nom_fichier, ligne & masque, int score, int taille);

int somme_tableau(tableau & T, int taille, ligne & masque);

int somme_colonne_ligne(tableau & T, int taille, int numero_ligne_colonne);

void creation_toutes_sommes(tableau & T, int taille, ligne & liste_sommes);

void coeur_programme(std::string & fic_import, std::string & fic_export);
