#include <stdlib.h>
#include <stdio.h>
#include "plantes.h"


typedef struct Plante Plante;
struct Plante{
	int posx;
	int posy;
	int vie_plante;
	char* nom;
	char* type;
};

Plante* Plante_construct(int posx ,int posy,int vie_plante, char* nom){
Plante *res=malloc(sizeof(Plante));
res->posx=posx;
res->posy=posy;
res->vie_plante=vie_plante;
res->nom=nom;
return res;
}
/*
void Plante_destruct(Plante *p){
free(p);
}

//int etat_z(){
if(zombie==1) return true;
else return false;
}
// à définir dans zombie pour que je puisse l'utiliser

//void envoyerBalle(){
//int sec=0;
}

}
void tuerZombie(){
while(position_plants!=position_zombie && etat_z==1 && ){
envoyerBalle();// méthode qui envoie la balle
}

void chargerBalle(){
if(etatZombie==1 && position_zombie_y==posy){
balle = SDL_LoadBMP("images/rouge.bmp");
SDL_Rect  rouge = { 144/2 - balle->w/2-8,128/2 - balle->h/2, 0, 0};
} 

}

//void arreterBalle(){
}

int getPosx(){
return posx;
}

int getPosy(){
return posy;
}

void setPosx(int dx,Plante p){
int position_plante=dx;
}

void setPosy(int dy){
int posy=dy;
}

void affichage(Plante *p){
 printf("%d(%d,%d,%d)",p->nom,p->position_plante.x,p->position_plante.y,p->vie_plante));
}

}

*/