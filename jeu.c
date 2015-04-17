#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "jeu.h"

SDL_Surface* fond = NULL;
SDL_Surface* bplante1 = NULL;
int appel = 0;

void interface(SDL_Surface* screen){ //crée l'interface du jeu

	fond = SDL_LoadBMP( "images/fond.bmp" );
	
	bplante1 = SDL_LoadBMP("images/BPlante1.bmp");
    SDL_Rect dest = { 144/2 - bplante1->w/2-8,128/2 - bplante1->h/2, 0, 0}; 
	
	SDL_BlitSurface( fond, NULL, screen, NULL );
    SDL_BlitSurface( bplante1, NULL, screen, &dest );
}

int appelJeu(){
	return appel;
}

void quitter(){ //ferme les images appelées dans interface
	SDL_FreeSurface( bplante1 );
	SDL_FreeSurface( fond );
}

void jouer(){
	appel = 1;
}

