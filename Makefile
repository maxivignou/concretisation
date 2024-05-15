totalCompilation :
	g++ -Wall -c gestion_fonctions.cpp -o gestionFonctions.o;
	g++ -Wall -c gestion_fichiers.cpp -o gestionFichiers.o;
	g++ -Wall -c calculs_sommes.cpp -o calculsSommes.o;
	g++ -Wall -c methode_brute.cpp -o methodeBrute.o;
	g++ -Wall -c methode_somme_minimale.cpp -o methodeSommeMinimale.o;
	g++ -Wall -c methode_diviser_regner.cpp -o methodeDiviserRegner.o;
	g++ gestionFichiers.o calculsSommes.o methodeSommeMinimale.o methodeBrute.o methodeDiviserRegner.o gestionFonctions.o -o LaGrilleMasquee.out;
gestion_fonctions.cpp :
	g++ -Wall -c gestion_fonctions.cpp -o gestionFonctions.o;
gestion_fichiers.cpp :
	g++ -Wall -c gestion_fichiers.cpp -o gestionFichiers.o;
calculs_sommes.cpp :
	g++ -Wall -c calculs_sommes.cpp -o calculsSommes.o;
methode_brute.cpp :
	g++ -Wall -c methode_brute.cpp -o methodeBrute.o;
methode_somme_minimale.cpp :
	g++ -Wall -c methode_somme_minimale.cpp -o methodeSommeMinimale.o;
methode_diviser_regner.cpp :
	g++ -Wall -c methode_diviser_regner.cpp -o methodeDiviserRegner.o;
clean :
	rm -f gestionFichiers.o calculsSommes.o methodeSommeMinimale.o methodeBrute.o methodeDiviserRegner.o gestionFonctions.o LaGrilleMasquee.out;
