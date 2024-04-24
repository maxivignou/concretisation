#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

using ligne = int*;
using tableau = ligne*;

void init_tableau(tableau & T, int taille); // Initialisation du tableau avec des valeurs nulles

void recup_donnees(std::string nom_fichier, tableau & T, int & taille); // Création de la matrice carrée avec les données du fichier

int somme_colonne_ligne(tableau & T, int taille, int no_somme); // Somme des valeurs dans la no_somme ligne et la no_somme colonne

void creation_toutes_sommes(tableau & T, int taille, ligne & liste_sommes); // Création de la liste contenant toutes les sommes

int indice_min(ligne & liste_sommes, int taille, ligne & masque); // Récupération de l'indice minimal de la liste

void modifications_donnees(tableau & T, int taille, ligne & listes_sommes, ligne & masque, int no_modification); // Modifications de toutes les données lorsqu'on appliquera un nouveau masque

void application_masque_reccur(tableau & T, int taille, ligne & liste_sommes, ligne & masque, int & score); // Création masque total en modifiant les données

void application_masque(tableau & T, int taille, ligne & liste_sommes, ligne & masque);

int somme_tableau(tableau & T, int taille, ligne & masque); // Somme de toutes les valeurs du tableau

void renvoi_resultat(std::string nom_fichier, ligne & masque, int score, int taille); // Création du fichier qui contient le masque et le score

void ajoute_un(ligne & masque,int taille); // Ajouter 1 en binaire à un masque (unités à gauche)

void copie(ligne & masque_recevant, ligne & masque_envoyant, int taille); // Copier une liste LE dans une liste LR

void force_brute(tableau & T, int taille, ligne & meilleur_masque, int & meilleure_somme); // Résoudre le problème par force brute

void maximum_aleatoire(tableau & T, int taille, ligne & meilleur_masque, int & meilleure_somme, auto heure_depart); // Résoudre le problème par méthode aléatoire

void coeur_programme(std::string & fic_import, std::string & fic_export); // Gestion du programme
