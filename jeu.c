#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "jeu.h"

int appel = 0;

SDL_Surface* fond = NULL;
SDL_Surface* bplante1 = NULL;

int wBplante1 = NULL;
int hBplante1 = NULL;

int utilise = 0;

void interfaceJeu(){ //crée l'interface du jeu

	fond = SDL_LoadBMP( "images/fond.bmp" );
	
	//Bouton plante1
	bplante1 = SDL_LoadBMP("images/BPlante1.bmp");
	wBplante1 = 144/2 - bplante1->w/2-8;
	hBplante1 = 128/2 - bplante1->h/2;

}

void actualisationJeu(SDL_Surface* screen){//actualise les positions
	//actualisation de la postion du fond
	SDL_BlitSurface( fond, NULL, screen, NULL );

	
	SDL_Rect dimBplante1 = { wBplante1,hBplante1, 0, 0}; //Position du bouton de la plante1
	SDL_BlitSurface( bplante1, NULL, screen, &dimBplante1 );//actualisation de la postion du Bouton de la plante1
}

int appelJeu(){
	return appel;
}

void quitterJeu(){ //ferme les images appelées dans interface
	SDL_FreeSurface( bplante1 );
	SDL_FreeSurface( fond );
}

void sourisJeu(int *x,int *y){

	if (*x>wBplante1 && *x<wBplante1+118 && *y>hBplante1 && *y<hBplante1+71 ){
		if (utilise == 0){
			bplante1 = SDL_LoadBMP("images/BPlante1Selc.bmp");
			utilise = 1;
		}
		else{
			bplante1 = SDL_LoadBMP("images/BPlante1.bmp");
			utilise = 0;
		}
	}
	//printf("%d \n", *x);
	//printf("%d \n", *y);

	//printf("%d \n", wBplante1);
	//printf("%d \n", hBplante1);
}

void principalJeu(){
	appel = 1;
}