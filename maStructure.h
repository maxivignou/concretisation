#pragma once
#include <iostream>
#include <fstream>
#include <string>

using ligne = int*;
using tableau = ligne*;

void init_tableau(tableau & T, int taille); // Initialisation du tableau avec des valeurs nulles

void recup_donnees(std::string nom_fichier, tableau & T, int & taille); // Création de la matrice carrée avec les données du fichier

int somme_colonne_ligne(tableau & T, int taille, int no_somme); // Somme des valeurs dans la no_somme ligne et la no_somme colonne

void creation_toutes_sommes(tableau & T, int taille, ligne & L_S); // Création de la liste contenant toutes les sommes

int indice_min(ligne & L, int taille, ligne & M); // Récupération de l'indice minimal de la liste

void modifications_donnees(tableau & T, int taille, ligne & L_S, ligne & M, int no_modification); // Modifications de toutes les données lorsqu'on appliquera un nouveau masque

void application_masque(tableau & T, int taille, ligne & L_S, ligne & M, int & score); // Création masque total en modifiant les données

int somme_tableau(tableau & T, int taille, ligne & M); // Somme de toutes les valeurs du tableau

void renvoi_resultat(std::string nom_fichier, ligne & masque, int score, int taille); // Création du fichier qui contient le masque et le score

void ajoute_un(ligne & L,int taille); // Ajouter 1 en binaire à un masque (unités à gauche)

void copie(ligne & LR, ligne & LE, int taille); // Copier une liste LE dans une liste LR

void force_brute(tableau & T, int taille, ligne & M_meilleur, int & S_meilleur); // Résoudre le problème par force brute

void maximum_aleatoire(tableau & T, int taille, ligne & M_alea, int & somme_alea); // Résoudre le problème par méthode aléatoire

void coeur_programme(std::string & fic_import, std::string & fic_export, tableau & T, ligne & M, int & taille); // Gestion du programme
