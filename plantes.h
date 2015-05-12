#ifndef plantes_H
#define plantes_H
#include <SDL2/SDL.h>

typedef struct Balle Balle;
struct Balle{
	int pos_bx;
	int pos_by;
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
//boolean etat_z();
void envoyerBalle();
void affichage(Plante *p);
int getPosx();
Balle* Balle_construct(int pos_bx ,int pos_by);

 
#endif