#ifndef plantes_H
#define plantes_H
#include <SDL2/SDL.h>

typedef struct Balle Balle;
struct Balle{
	int pos_bx;
	int pos_by;
	SDL_Surface* imageBalle;
};

typedef struct Plante Plante;
struct Plante{
	int posx;
	int posy;
	int vie_plante;
	char* nom;
	char* type;
	SDL_Surface* imagePlante;
};

Plante* Plante_construct(int posx,int posy, int vie_plante, char* nom, char* type);
void Plante_destruct(Plante *p);


void affichage(Plante *p);
Balle* Balle_construct(int pos_bx ,int pos_by);
//void tuerZombie(Plante *p, Zombie *z);

 
#endif