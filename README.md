# La Grille Masquée
## Le problème
On donne une matrice carrée de nombres positifs ou négatifs. L'objectif étant d'obtenir la plus grande somme possible.
Pour cela, on peut cacher certaines cases pour tenter de faire monter le score.
Cependant, il est important de respecter certaines règles :
* On ne peut pas cacher une case seule, il faut cacher toute une ligne.
* Lorsque l'on cache une ligne, on doit cacher la colonne associée. Par exemple, si l'on cache la première ligne, il faut cacher la première colonene.
## Liste des fichiers
1. maStructure.h : Fichier contenant les prototypes de toutes les fonctions
2. execution_programme.cpp : Fichier contenant les fonctions permettant d'exécuter le programme
3. gestion_fichiers.cpp : Fichier contenant les fonctions d'importation du tableau et d'exportation du masque
4. init_variables.cpp : Fichier contenant les fonctions permettant d'obtenir les sommes ligne-colonne du tableau
5. methode_brute.cpp : Fichier contenant les fonctions permettant d'obtenir le meilleur résultat par force brute
6. methode_optimisee.cpp : Fichier contenant les fonctions permettant d'obtenir un résultat assez proche du meilleur très rapidement
7. methode_aleatoire.cpp : Fichier contenant les fonctions permettant d'obtenir un résultat de manière totalement aléatoire
8. creation_bdd.cpp : Fichier déconnecté des autres, permettant de créer un fichier contenant les données d'un tableau
9. Makefile : Fichier de compilation
## Méthode d'installation et d'exécution pour Linux
### Première étape :
Télécharger le dossier ZIP
### Deuxième étape :
Extraire les fichiers du dossier ZIP
### Troisième étape :
Clic droit dans le dossier, puis **Ouvrir dans un terminal**.
### Quatrième étape :
Entrez dans le terminal la commande *make* et exécutez.
### Cinquième étape :
Récupérez sur le site web un fichier texte contenant les données du tableau, où créez votre fichier selon les conditions décrites ci-dessous, et déplacez le fichier texte dans le dossier contenant les autres fichiers.
### Sixième étape :
Entrez dans le terminal la commande *./LaGrilleMasquee.out **nom_fichier_texte_contenant_les_donnees_du_tableau** **nom_fichier_texte_contenant_les_resultats_(facultatif)*** et exécutez.
## Méthode d'installation et d'exécution pour un autre système que Linux
Pour l'instant, cette application n'est pas disponible hors de Linux.
## Création du fichier d'entrée contenant les données du tableau
### Première ligne :
La première ligne contient 2 nombres :
* Le premier nombre est la taille de la matrice carrée
* La deuxième ligne est le nombre de données sur les lignes suivantes
## Lignes suivantes :
Les lignes suivantes contiennent 3 nombres :
* Le premier nombre est le numéro de la ligne (compris entre 1 et la taille du tableau tous deux inclus)
* Le deuxième nombre est le numéro de la colonne (compris entre 1 et la taille du tableau tous deux inclus)
* Le troisième nombre est la valeur présente dans le tableau à la ligne et la colonne indiquée.
Afin d'éviter une surcharge du fichier, les valeurs nulles ne seront pas indiquées dans le fichier.
