totalCompilation :
	g++ -Wall -c execution_programme.cpp -o executionProgramme.o;
	g++ -Wall -c gestion_fichiers.cpp -o gestionFichiers.o;
	g++ -Wall -c init_variables.cpp -o initVariables.o;
	g++ -Wall -c methode_brute.cpp -o methodeBrute.o;
	g++ -Wall -c methode_optimisee.cpp -o methodeOptimisee.o;
	g++ -Wall -c methode_aleatoire.cpp -o methodeAleatoire.o;
	g++ gestionFichiers.o initVariables.o methodeOptimisee.o methodeBrute.o executionProgramme.o methodeAleatoire.o -o LaGrilleMasquee.out;
creationExecutable :
	g++ gestionFichiers.o initVariables.o methodeOptimisee.o methodeBrute.o executionProgramme.o -o LaGrilleMasquee.out;
executionProgramme :
	g++ -Wall -c execution_programme.cpp -o executionProgramme.o
gestionFichiers :
	g++ -Wall -c gestion_fichiers.cpp -o gestionFichiers.o
initVariables :
	g++ -Wall -c init_variables.cpp -o initVariables.o
methodeAleatoire :
	g++ -Wall -c methode_aleatoire.cpp -o methodeAleatoire.o
methodeBrute :
	g++ -Wall -c methode_brute.cpp -o methodeBrute.o
methodeOptimisee :
	g++ -Wall -c methode_optimisee.cpp -o methodeOptimisee.o
clean :
	rm -f executionProgramme.o gestionFichiers.o initVariables.o methodeBrute.o methodeOptimisee.o LaGrilleMasquee.out
