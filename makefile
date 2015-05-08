
all: test

test: plantes.o main.o jeu.o
	gcc -o test plantes.o jeu.o main.o -Wall -lSDL2

plantes.o: plantes.c plantes.h
	gcc -o plantes.o -c plantes.c -Wall -lSDL2

jeu.o: jeu.c plantes.h
	gcc -o jeu.o -c jeu.c -Wall -lSDL2

main.o: main.c jeu.h
	gcc -o main.o -c main.c -Wall -lSDL2

clean:
	rm -rf *.o

mrproper: clean
	rm -rf test
