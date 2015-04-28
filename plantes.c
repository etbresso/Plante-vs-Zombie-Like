#include <stdlib.h>
#include <stdio.h>
#include "prototype.h"
#include <time.h>

typedef struct Plante Plante
struct Plante(
	int position_plante.x;
	int position_plante.y;
	int vie_plante;
	String nom;
);

Plante* Plante_construct(int x,int y, boolean vie_Plante, String nom){
Plante *res=malloc(sizeof(Plante));
res->x=x;
res->y=y;
res->vie_plante=vie_plante;
res->nom=nom;
}

void Plante_destruct(Plante *p){
free(p);
}

boolean etat_z(){
if(zombie==1) return true;
else return false;
}
// à définir dans zombie pour que je puisse l'utiliser

void envoyerBalle(){
//int sec=0;
}

}
void tuerZombie(){
while(position_plants!=position_zombie && etat_z==1 && ){
envoyerBalle();// méthode qui envoie la balle
}

void chargerBalle(){
if(etatZombie==1 && position_zombie.y==position_plants.y){
balle = SDL_LoadBMP("images/rouge.bmp");
SDL_Rect  rouge = { 144/2 - balle->w/2-8,128/2 - balle->h/2, 0, 0};
} 
}
void arreterBalle(){
}

}
