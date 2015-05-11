#include <stdlib.h>
#include <stdio.h>
#include "plantes.h"
#include <SDL2/SDL.h>
#include "zombie.h"

typedef struct Balle Balle;
struct Balle{
	int pos_bx;
	int pos_by;
};

Balle* Balle_construct(int pos_bx ,int pos_by){
	Balle *res=malloc(sizeof(Balle));
	res->pos_bx=pos_bx;
	res->pos_by=pos_by;
	return res;
}

Plante* Plante_construct(int posx ,int posy,int vie_plante, char* nom, char* type){
	Plante *res=malloc(sizeof(Plante));
	res->posx=posx;
	res->posy=posy;
	res->vie_plante=vie_plante;
	res->nom=nom;
	res->type=type;
	res->imagePlante = NULL;
	return res;
}
/*
void Plante_destruct(Plante *p){
	free(p);
}

void envoyerBalle(Balle *b){

b->pos_bx=b->pos_bx+1;


}
void tuerZombie(Plante *p, zombie *z){
	while(z->posx_z!=p->posx && z->vie_zombie>0 && p->posy==z->posy_z){
	envoyerBalle();
}

void chargerBalle(){
	if(z->etatZombie==1 && posy_z==posy){
		balle = SDL_LoadBMP("images/rouge.bmp");
		SDL_Rect  rouge = { 144/2 - balle->w/2-8,128/2 - balle->h/2, 0, 0};
} 
}

void affichage(Plante *p){
	printf("%c(%d,%d,%d,%c)",p->type,p->posx,p->posy,p->vie_plante,p->nom);
}
void envoieSoleil(){
Plante *p;
if(p.type==soleil){
SDL_Surface* fond = NULL;
soleil = SDL_LoadBMP("images/soleil.bmp");
SDL_Rect  rouge = { 144/2 - soleil->w/2-8,128/2 - soleil->h/2, 0, 0};
} 
}
	SDL_Surface* fond = NULL;
	soleil = SDL_LoadBMP("images/soleil.bmp");
	SDL_Rect  rouge = { 144/2 - soleil->w/2-8,128/2 - soleil->h/2, 0, 0};
} 
*/