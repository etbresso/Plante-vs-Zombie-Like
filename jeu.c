#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "jeu.h"
#include "plantes.h"

int appel = 0; // permet de savoir si on appel principalJeu();

SDL_Surface* fond = NULL;
SDL_Surface* bplante1 = NULL;
SDL_Surface* bplante2 = NULL;
SDL_Surface* bplante3 = NULL;

SDL_Surface* balle = NULL;

SDL_Surface* plante[5][9]; //damier du jeu qui contindra les image des plantes

//Plante *plante[5][9];

//dim Bplante1
int wBplante1 = NULL;//dimention de l'image en x
int hBplante1 = NULL;//dimention de l'image en y
//dim Bplante2
int wBplante2 = NULL;//dimention de l'image en x
int hBplante2 = NULL;//dimention de l'image en y
//dim Bplante3
int wBplante3 = NULL;//dimention de l'image en x
int hBplante3 = NULL;//dimention de l'image en y

int utilise = 0; //permet de savoir si on a cliqué sur le bouton d'une plante

//------------------------------------------------------------------------------------
void principalJeu(){
	appel = 1;
	int i;
	int j;

	//on initialise le tableau avec que des 0±
	for (i=0; i<5; i++){
		for (j=0; j<5; j++){
			plante[i][j]=NULL;
		}
	}

}

void interfaceJeu(){ //crée l'interface du jeu

	fond = SDL_LoadBMP( "images/fond.bmp" );
	
	//Bouton plante1
	bplante1 = SDL_LoadBMP("images/BPlante1.bmp");
	wBplante1 = 128/2 - bplante1->w/2;
	hBplante1 = 144/2 - bplante1->h/2;

	//Bouton plante2
	bplante2 = SDL_LoadBMP("images/BPlante2.bmp");
	wBplante2 = 128/2 - bplante2->w/2;
	hBplante2 = 144/2 - bplante2->h/2 + 144;

	//Bouton plante3
	bplante3 = SDL_LoadBMP("images/BPlante3.bmp");
	wBplante3 = 128/2 - bplante3->w/2;
	hBplante3 = 144/2 - bplante3->h/2 + 288;

	balle = SDL_LoadBMP("images/rouge.bmp");

}

void actualisationJeu(SDL_Surface* screen){//actualise les positions
	//actualisation de la postion du fond
	SDL_BlitSurface( fond, NULL, screen, NULL );

	//Postion Bouton
	SDL_Rect dimBplante1 = { wBplante1,hBplante1, 0, 0}; //Position du bouton de la plante1
	SDL_BlitSurface( bplante1, NULL, screen, &dimBplante1 );//actualisation de la postion du Bouton de la plante1

	SDL_Rect dimBplante2 = { wBplante2,hBplante2, 0, 0}; //Position du bouton de la plante2
	SDL_BlitSurface( bplante2, NULL, screen, &dimBplante2 );//actualisation de la postion du Bouton de la plante2

	SDL_Rect dimBplante3 = { wBplante3,hBplante3, 0, 0}; //Position du bouton de la plante3
	SDL_BlitSurface( bplante3, NULL, screen, &dimBplante3 );//actualisation de la postion du Bouton de la plante3

	//balle
	SDL_Rect rouge = { 144/2 - balle->w/2-8,128/2 - balle->h/2, 0, 0};	
	SDL_BlitSurface( balle, NULL, screen, &rouge );

	int i;
	int j;

	for(i=0; i<5;i++){
		for (j=0;j<9;j++){
		SDL_Rect dimplante = { (j+1)*128,i*144, 0, 0}; //Position  de la plante
		SDL_BlitSurface( plante[i][j], NULL, screen, &dimplante );//actualisation de la postion de la plante
		}
	}

}

int appelJeu(){
	return appel;
}

void quitterJeu(){ //ferme les images appelées dans interface
	SDL_FreeSurface( bplante1 );
	SDL_FreeSurface( bplante2 );
	SDL_FreeSurface( bplante3 );

	int i = 0;
	int j = 0;

	for (i=0; i<5; i++){
		for (j=0; j<5; j++){
			SDL_FreeSurface(plante[i][j]);
		}
	}

	SDL_FreeSurface( fond );
}

void sourisJeu(int x,int y){

	//clic sur les bouton
	if (x>wBplante1 && x<wBplante1+118 && y>hBplante1 && y<hBplante1+71 ){
		if (utilise == 0 || utilise == 2 || utilise == 3){
			bplante1 = SDL_LoadBMP("images/BPlante1Selc.bmp");
			bplante2 = SDL_LoadBMP("images/BPlante2.bmp");
			bplante3 = SDL_LoadBMP("images/BPlante3.bmp");
			utilise = 1;
		}
		else{
			bplante1 = SDL_LoadBMP("images/BPlante1.bmp");
			utilise = 0;
		}
	}

	if (x>wBplante2 && x<wBplante2+118 && y>hBplante2 && y<hBplante2+71 ){
		if (utilise == 0 || utilise == 1 || utilise == 3 ){
			bplante1 = SDL_LoadBMP("images/BPlante1.bmp");
			bplante2 = SDL_LoadBMP("images/BPlante2Selc.bmp");
			bplante3 = SDL_LoadBMP("images/BPlante3.bmp");
			utilise = 2;
		}
		else{
			bplante2 = SDL_LoadBMP("images/BPlante2.bmp");
			utilise = 0;
		}
	}

	if (x>wBplante3 && x<wBplante3+118 && y>hBplante3 && y<hBplante3+71 ){
			if (utilise == 0 || utilise == 1 || utilise == 2 ){
				bplante1 = SDL_LoadBMP("images/BPlante1.bmp");
				bplante2 = SDL_LoadBMP("images/BPlante2.bmp");
				bplante3 = SDL_LoadBMP("images/BPlante3Selc.bmp");
				utilise = 3;
			}
			else{
				bplante3 = SDL_LoadBMP("images/BPlante3.bmp");
				utilise = 0;
			}
		}


	//clic sur une zone de jeu

	// de plante[0][0] à plante[0][8]
	if(x>128 && x<256 && y>0 && y<144 && plante[0][0] == NULL){
		posePlante(0,0);
	}
	else if(x>256 && x<384 && y>0 && y<144 && plante[0][1] == NULL){
		posePlante(0,1);
	}
	else if(x>384 && x<512 && y>0 && y<144 && plante[0][2] == NULL){
		posePlante(0,2);
	}
	else if(x>512 && x<640 && y>0 && y<144 && plante[0][3] == NULL){
		posePlante(0,3);
	}
	else if(x>640 && x<768 && y>0 && y<144 && plante[0][4] == NULL){
		posePlante(0,4);
	}
	else if(x>768 && x<896 && y>0 && y<144 && plante[0][5] == NULL){
		posePlante(0,5);
	}
	else if(x>896 && x<1024 && y>0 && y<144 && plante[0][6] == NULL){
		posePlante(0,6);
	}
	else if(x>1024 && x<1152 && y>0 && y<144 && plante[0][7] == NULL){
		posePlante(0,7);
	}
	else if(x>1152 && x<1280 && y>0 && y<144 && plante[0][8] == NULL){
		posePlante(0,8);
	}

	// de plante[1][0] à plante[1][8]
	if(x>128 && x<256 && y>144 && y<288 && plante[1][0] == NULL){
		posePlante(1,0);
	}
	else if(x>256 && x<384 && y>144 && y<288 && plante[1][1] == NULL){
		posePlante(1,1);
	}
	else if(x>384 && x<512 && y>144 && y<288 && plante[1][2] == NULL){
		posePlante(1,2);
	}
	else if(x>512 && x<640 && y>144 && y<288 && plante[1][3] == NULL){
		posePlante(1,3);
	}
	else if(x>640 && x<768 && y>144 && y<288 && plante[1][4] == NULL){
		posePlante(1,4);
	}
	else if(x>768 && x<896 && y>144 && y<288 && plante[1][5] == NULL){
		posePlante(1,5);
	}
	else if(x>896 && x<1024 && y>144 && y<288 && plante[1][6] == NULL){
		posePlante(1,6);
	}
	else if(x>1024 && x<1152 && y>144 && y<288 && plante[1][7] == NULL){
		posePlante(1,7);
	}
	else if(x>1152 && x<1280 && y>144 && y<288 && plante[1][8] == NULL){
		posePlante(1,8);
	}

	// de plante[2][0] à plante[2][8]
	else if(x>128 && x<256 && y>288 && y<432 && plante[2][0] == NULL){
		posePlante(2,0);
	}
	else if(x>256 && x<384 && y>288 && y<432 && plante[2][1] == NULL){
		posePlante(2,1);
	}
	else if(x>384 && x<512 && y>288 && y<432 && plante[2][2] == NULL){
		posePlante(2,2);
	}
	else if(x>512 && x<640 && y>288 && y<432 && plante[2][3] == NULL){
		posePlante(2,3);
	}
	else if(x>640 && x<768 && y>288 && y<432 && plante[2][4] == NULL){
		posePlante(2,4);
	}
	else if(x>768 && x<896 && y>288 && y<432 && plante[2][5] == NULL){
		posePlante(2,5);
	}
	else if(x>896 && x<1024 && y>288 && y<432 && plante[2][6] == NULL){
		posePlante(2,6);
	}
	else if(x>1024 && x<1152 && y>288 && y<432 && plante[2][7] == NULL){
		posePlante(2,7);
	}
	else if(x>1152 && x<1280 && y>288 && y<432 && plante[2][8] == NULL){
		posePlante(2,8);
	}

	// de plante[3][0] à plante[3][8]
	else if(x>128 && x<256 && y>432 && y<576 && plante[3][0] == NULL){
		posePlante(3,0);
	}
	else if(x>256 && x<384 && y>432 && y<576 && plante[3][1] == NULL){
		posePlante(3,1);
	}
	else if(x>384 && x<512 && y>432 && y<576 && plante[3][2] == NULL){
		posePlante(3,2);
	}
	else if(x>512 && x<640 && y>432 && y<576 && plante[3][3] == NULL){
		posePlante(3,3);
	}
	else if(x>640 && x<768 && y>432 && y<576 && plante[3][4] == NULL){
		posePlante(3,4);
	}
	else if(x>768 && x<896 && y>432 && y<576 && plante[3][5] == NULL){
		posePlante(3,5);
	}
	else if(x>896 && x<1024 && y>432 && y<576 && plante[3][6] == NULL){
		posePlante(3,6);
	}
	else if(x>1024 && x<1152 && y>432 && y<576 && plante[3][7] == NULL){
		posePlante(3,7);
	}
	else if(x>1152 && x<1280 && y>432 && y<576 && plante[3][8] == NULL){
		posePlante(3,8);
	}

	// de plante[4][0] à plante[4][8]
	else if(x>128 && x<256 && y>576 && y<720 && plante[4][0] == NULL){
		posePlante(4,0);
	}
	else if(x>256 && x<384 && y>576 && y<720 && plante[4][1] == NULL){
		posePlante(4,1);
	}
	else if(x>384 && x<512 && y>576 && y<720 && plante[4][2] == NULL){
		posePlante(4,2);
	}
	else if(x>512 && x<640 && y>576 && y<720 && plante[4][3] == NULL){
		posePlante(4,3);
	}
	else if(x>640 && x<768 && y>576 && y<720 && plante[4][4] == NULL){
		posePlante(4,4);
	}
	else if(x>768 && x<896 && y>576 && y<720 && plante[4][5] == NULL){
		posePlante(4,5);
	}
	else if(x>896 && x<1024 && y>576 && y<720 && plante[4][6] == NULL){
		posePlante(4,6);
	}
	else if(x>1024 && x<1152 && y>576 && y<720 && plante[4][7] == NULL){
		posePlante(4,7);
	}
	else if(x>1152 && x<1280 && y>576 && y<720 && plante[4][8] == NULL){
		posePlante(4,8);
	}
}

void posePlante(int i, int j){
	if (utilise == 1){
		plante[i][j]= SDL_LoadBMP("images/Plante1.bmp"); //on charge l'image a mettre
	}
	else if (utilise == 2){
		plante[i][j] = SDL_LoadBMP("images/Plante2.bmp"); //on charge l'image a mettre
	}
	else if (utilise == 3){
		plante[i][j] = SDL_LoadBMP("images/Plante3.bmp"); //on charge l'image a mettre
	}
}