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

//SDL_Surface* balle = NULL;

//SDL_Surface* plante[5][9]; //damier du jeu qui contindra les image des plantes

Plante *plante[5][9];

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

	/*balle = SDL_LoadBMP("images/rouge.bmp");
	SDL_Rect  rouge = { 144/2 - balle->w/2-8,128/2 - balle->h/2, 0, 0};	*/

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

	//Position Plante
	// de plante[0][0] à plante[0][8]
	
	/*SDL_Rect dimplante00 = { 128,0, 0, 0}; //Position  de la plante00
	SDL_BlitSurface( plante[0][0], NULL, screen, &dimplante00 );//actualisation de la postion de la plante00
	dimplante00.x=256;*/
	
	int i;
	int j;

	for(i=0; i<5;i++){
		for (j=0;j<9;j++){
		SDL_Rect dimplante = { (j+1)*128,i*144, 0, 0}; //Position  de la plante
		SDL_BlitSurface( plante[i][j], NULL, screen, &dimplante );//actualisation de la postion de la plante
		}
	}

	/*SDL_Rect dimplante01 = { 256,0, 0, 0}; 
	SDL_BlitSurface( plante[0][1], NULL, screen, &dimplante00 );
	SDL_Rect dimplante02 = { 384,0, 0, 0}; 
	SDL_BlitSurface( plante[0][2], NULL, screen, &dimplante02 );
	SDL_Rect dimplante03 = { 512,0, 0, 0}; 
	SDL_BlitSurface( plante[0][3], NULL, screen, &dimplante03 );
	SDL_Rect dimplante04 = { 640,0, 0, 0}; 
	SDL_BlitSurface( plante[0][4], NULL, screen, &dimplante04 );
	SDL_Rect dimplante05 = { 768,0, 0, 0}; 
	SDL_BlitSurface( plante[0][5], NULL, screen, &dimplante05 );
	SDL_Rect dimplante06 = { 896,0, 0, 0}; 
	SDL_BlitSurface( plante[0][6], NULL, screen, &dimplante06 );
	SDL_Rect dimplante07 = { 1024,0, 0, 0}; 
	SDL_BlitSurface( plante[0][7], NULL, screen, &dimplante07 );
	SDL_Rect dimplante08 = { 1152,0, 0, 0}; 
	SDL_BlitSurface( plante[0][8], NULL, screen, &dimplante08 );

	// de plante[1][0] à plante[1][8]
	SDL_Rect dimplante10 = { 128,144, 0, 0}; //Position  de la plante00
	SDL_BlitSurface( plante[1][0], NULL, screen, &dimplante10 );//actualisation de la postion de la plante00
	SDL_Rect dimplante11 = { 256,144, 0, 0}; 
	SDL_BlitSurface( plante[1][1], NULL, screen, &dimplante11 );
	SDL_Rect dimplante12 = { 384,144, 0, 0}; 
	SDL_BlitSurface( plante[1][2], NULL, screen, &dimplante12 );
	SDL_Rect dimplante13 = { 512,144, 0, 0}; 
	SDL_BlitSurface( plante[1][3], NULL, screen, &dimplante13 );
	SDL_Rect dimplante14 = { 640,144, 0, 0}; 
	SDL_BlitSurface( plante[1][4], NULL, screen, &dimplante14 );
	SDL_Rect dimplante15 = { 768,144, 0, 0}; 
	SDL_BlitSurface( plante[1][5], NULL, screen, &dimplante15 );
	SDL_Rect dimplante16 = { 896,144, 0, 0}; 
	SDL_BlitSurface( plante[1][6], NULL, screen, &dimplante16 );
	SDL_Rect dimplante17 = { 1024,144, 0, 0}; 
	SDL_BlitSurface( plante[1][7], NULL, screen, &dimplante17 );
	SDL_Rect dimplante18 = { 1152,144, 0, 0}; 
	SDL_BlitSurface( plante[1][8], NULL, screen, &dimplante18 );

	// de plante[2][0] à plante[2][8]
	SDL_Rect dimplante20 = { 128,288, 0, 0}; //Position  de la plante00
	SDL_BlitSurface( plante[2][0], NULL, screen, &dimplante20 );//actualisation de la postion de la plante00
	SDL_Rect dimplante21 = { 256,288, 0, 0}; 
	SDL_BlitSurface( plante[2][1], NULL, screen, &dimplante21 );
	SDL_Rect dimplante22 = { 384,288, 0, 0}; 
	SDL_BlitSurface( plante[2][2], NULL, screen, &dimplante22 );
	SDL_Rect dimplante23 = { 512,288, 0, 0}; 
	SDL_BlitSurface( plante[2][3], NULL, screen, &dimplante23 );
	SDL_Rect dimplante24 = { 640,288, 0, 0}; 
	SDL_BlitSurface( plante[2][4], NULL, screen, &dimplante24 );
	SDL_Rect dimplante25 = { 768,288, 0, 0}; 
	SDL_BlitSurface( plante[2][5], NULL, screen, &dimplante25 );
	SDL_Rect dimplante26 = { 896,288, 0, 0}; 
	SDL_BlitSurface( plante[2][6], NULL, screen, &dimplante26 );
	SDL_Rect dimplante27 = { 1024,288, 0, 0}; 
	SDL_BlitSurface( plante[2][7], NULL, screen, &dimplante27 );
	SDL_Rect dimplante28 = { 1152,288, 0, 0}; 
	SDL_BlitSurface( plante[2][8], NULL, screen, &dimplante28 );

	// de plante[3][0] à plante[3][8]
	SDL_Rect dimplante30 = { 128,432, 0, 0}; //Position  de la plante00
	SDL_BlitSurface( plante[3][0], NULL, screen, &dimplante30 );//actualisation de la postion de la plante00
	SDL_Rect dimplante31 = { 256,432, 0, 0}; 
	SDL_BlitSurface( plante[3][1], NULL, screen, &dimplante31 );
	SDL_Rect dimplante32 = { 384,432, 0, 0}; 
	SDL_BlitSurface( plante[3][2], NULL, screen, &dimplante32 );
	SDL_Rect dimplante33 = { 512,432, 0, 0}; 
	SDL_BlitSurface( plante[3][3], NULL, screen, &dimplante33 );
	SDL_Rect dimplante34 = { 640,432, 0, 0}; 
	SDL_BlitSurface( plante[3][4], NULL, screen, &dimplante34 );
	SDL_Rect dimplante35 = { 768,432, 0, 0}; 
	SDL_BlitSurface( plante[3][5], NULL, screen, &dimplante35 );
	SDL_Rect dimplante36 = { 896,432, 0, 0}; 
	SDL_BlitSurface( plante[3][6], NULL, screen, &dimplante36 );
	SDL_Rect dimplante37 = { 1024,432, 0, 0}; 
	SDL_BlitSurface( plante[3][7], NULL, screen, &dimplante37 );
	SDL_Rect dimplante38 = { 1152,432, 0, 0}; 
	SDL_BlitSurface( plante[3][8], NULL, screen, &dimplante38 );

	// de plante[4][0] à plante[4][8]
	SDL_Rect dimplante40 = { 128,576, 0, 0}; //Position  de la plante00
	SDL_BlitSurface( plante[4][0], NULL, screen, &dimplante40 );//actualisation de la postion de la plante00
	SDL_Rect dimplante41 = { 256,576, 0, 0}; 
	SDL_BlitSurface( plante[4][1], NULL, screen, &dimplante41 );
	SDL_Rect dimplante42 = { 384,576, 0, 0}; 
	SDL_BlitSurface( plante[4][2], NULL, screen, &dimplante42 );
	SDL_Rect dimplante43 = { 512,576, 0, 0}; 
	SDL_BlitSurface( plante[4][3], NULL, screen, &dimplante43 );
	SDL_Rect dimplante44 = { 640,576, 0, 0}; 
	SDL_BlitSurface( plante[4][4], NULL, screen, &dimplante44 );
	SDL_Rect dimplante45 = { 768,576, 0, 0}; 
	SDL_BlitSurface( plante[4][5], NULL, screen, &dimplante45 );
	SDL_Rect dimplante46 = { 896,576, 0, 0}; 
	SDL_BlitSurface( plante[4][6], NULL, screen, &dimplante46 );
	SDL_Rect dimplante47 = { 1024,576, 0, 0}; 
	SDL_BlitSurface( plante[4][7], NULL, screen, &dimplante47 );
	SDL_Rect dimplante48 = { 1152,576, 0, 0}; 
	SDL_BlitSurface( plante[4][8], NULL, screen, &dimplante48 );*/
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