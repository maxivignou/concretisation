monExecutable : maStructure monProgramme
  g++ maStructure.o monProgramme.o \ -o monExecutable.exe
maStructure:
  g++ -Wall -c maStructure.cpp -o maStructure.o
monProgramme:
  g++ -Wall -c monProgramme.cpp -o monProgramme.o
clean:
  rm -f maStructue.o monProgramme.o \ monExecutable.exe
