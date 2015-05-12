#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "jeu.h"
#include "plantes.h"
#include "zombie.h"
#include "main.h"


int appel = 0; // permet de savoir si on appel principalJeu();
Uint32 vitesseZTimer = 0; //Timer

//le texte
TTF_Font *police = NULL;
int argentActuel = 25;
char argent[12];
SDL_Surface* txt = NULL;
SDL_Color color = { 0, 0, 0 };

//les surface
SDL_Surface* fond = NULL;
SDL_Surface* bplante1 = NULL;
SDL_Surface* bplante2 = NULL;
SDL_Surface* bplante3 = NULL;
SDL_Surface* bMenuJeu = NULL;

SDL_Surface* balle = NULL;

//SDL_Surface* plante[5][9]; //damier du jeu qui contindra les image des plantes

Plante *tabPlante[5][9];
Zombie *zombies[5];

//dim Bplante1
int wBplante1 = NULL;//dimention de l'image en x
int hBplante1 = NULL;//dimention de l'image en y
//dim Bplante2
int wBplante2 = NULL;//dimention de l'image en x
int hBplante2 = NULL;//dimention de l'image en y
//dim Bplante3
int wBplante3 = NULL;//dimention de l'image en x
int hBplante3 = NULL;//dimention de l'image en y
//dim bMenuJeu
int wBMenuJeu = NULL;//dimention de l'image en x
int hBMenuJeu = NULL;//dimention de l'image en y

int utilise = 0; //permet de savoir si on a cliqué sur le bouton d'une plante

//------------------------------------------------------------------------------------
void principalJeu(){
	vitesseZTimer = SDL_GetTicks();
	appel = 1;
	int i;
	int j;

	//on initialise le tableau avec que des 0±
	for (i=0; i<5; i++){
		for (j=0; j<9; j++){
			tabPlante[i][j]=NULL;
		}
	}

	zombies[0]=Zombie_base(0, 100);
	zombies[1]=Zombie_base(144, 100);
	zombies[2]=Zombie_base(2*144, 100);
	zombies[3]=Zombie_base(3*144, 100);
	zombies[4]=Zombie_base(4*144, 100);

}

void interfaceJeu(){ //crée l'interface du jeu

	fond = IMG_Load( "images/fond.bmp" );
	
	//Bouton plante1
	bplante1 = IMG_Load("images/plante1.png");
	wBplante1 = 128/2 - bplante1->w/2;
	hBplante1 = 144/2 - bplante1->h/2;

	//Bouton plante2
	bplante2 = IMG_Load("images/BPlante2.bmp");
	wBplante2 = 128/2 - bplante2->w/2;
	hBplante2 = 144/2 - bplante2->h/2 + 144;

	//Bouton plante3
	bplante3 = IMG_Load("images/BPlante3.bmp");
	wBplante3 = 128/2 - bplante3->w/2;
	hBplante3 = 144/2 - bplante3->h/2 + 288;

	bMenuJeu = IMG_Load("images/BMenuJeu.bmp");
	wBMenuJeu = 128/2 - bMenuJeu->w/2;
	hBMenuJeu = 144*3/4 - bMenuJeu->h/2 + 576;

	balle = IMG_Load("images/rouge.bmp");

	TTF_Init();
	police = TTF_OpenFont("Iron&Brine.ttf", 36);
	sprintf(argent, "Argent:  %d", argentActuel);
 	txt = TTF_RenderText_Solid(police, argent, color);

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

	SDL_Rect dimBMenuJeu = { wBMenuJeu,hBMenuJeu, 0, 0}; //Position du bouton de la plante3
	SDL_BlitSurface( bMenuJeu, NULL, screen, &dimBMenuJeu );//actualisation de la postion du Bouton de la plante3

	//balle
	//SDL_Rect rouge = { 144/2 - balle->w/2-8,128/2 - balle->h/2, 0, 0};	
	//SDL_BlitSurface( balle, NULL, screen, &rouge );

	//texte
	SDL_FreeSurface(txt);
	sprintf(argent, "Argent  %d", argentActuel);
 	txt = TTF_RenderText_Solid(police, argent, color);
	SDL_BlitSurface( txt, NULL, screen, NULL );

	int i;
	int j;

	for(i=0; i<5;i++){
		for (j=0;j<9;j++){
		SDL_Rect dimplante = { (j+1)*128,i*144, 0, 0}; //Position  de la plante
		if (tabPlante[i][j]!=NULL){
			SDL_BlitSurface( tabPlante[i][j]->imagePlante, NULL, screen, &dimplante );//actualisation de la postion de la plante
		}
		
		}
	}

	for(i=0;i<5;i++){ //dessine les zombies
		if(zombies[i]!=NULL){ //si le zombie n'est pas mort
			//printf("test1:%d\n test2:%d\n",zombies[i]->position_x/128,zombies[i]->position_y/144);
			if(tabPlante[zombies[i]->position_y/144][zombies[i]->position_x/128-1]!=NULL && vitesseZTimer+100<SDL_GetTicks()) {
				attaquerZ(tabPlante[zombies[i]->position_y/144][zombies[i]->position_x/128-1]);
				if(tabPlante[zombies[i]->position_y/144][zombies[i]->position_x/128-1]->vie_plante<0){
					SDL_FreeSurface( tabPlante[zombies[i]->position_y/144][zombies[i]->position_x/128-1]->imagePlante);
					tabPlante[zombies[i]->position_y/144][zombies[i]->position_x/128-1]=NULL;
				}
			}else if(vitesseZTimer+100<SDL_GetTicks()){
				avancerZ(zombies[i]);
			}
			SDL_Rect zombieTest = { zombies[i]->position_x,zombies[i]->position_y, 0, 0}; //Position  de la plante00
			SDL_BlitSurface( zombies[i]->img, NULL, screen, &zombieTest );//actualisation de la postion de la plante00
		}

	}
	if(vitesseZTimer+100<SDL_GetTicks()){
		vitesseZTimer=SDL_GetTicks();
	}	
			

}

int appelJeu(){
	return appel;
}

void quitterJeu(){ //ferme les images appelées dans interface
	SDL_FreeSurface( bplante1 );
	SDL_FreeSurface( bplante2 );
	SDL_FreeSurface( bplante3 );
	SDL_FreeSurface( bMenuJeu );

	TTF_CloseFont(police);
    TTF_Quit();

    SDL_FreeSurface(txt);

	int i = 0;
	int j = 0;

	for (i=0; i<5; i++){
		for (j=0; j<9; j++){
			if(tabPlante[i][j]!=NULL){
				SDL_FreeSurface(tabPlante[i][j]->imagePlante);
			}
		}
	}

	SDL_FreeSurface( fond );
}

void sourisJeu(int x,int y){

	//clic sur les bouton
	if (x>wBplante1 && x<wBplante1+118 && y>hBplante1 && y<hBplante1+71 ){
		if (utilise == 0 || utilise == 2 || utilise == 3){
			bplante1 = IMG_Load("images/BPlante1Selc.bmp");
			bplante2 = IMG_Load("images/BPlante2.bmp");
			bplante3 = IMG_Load("images/BPlante3.bmp");
			utilise = 1;
		}
		else{
			bplante1 = IMG_Load("images/plante1.png");
			utilise = 0;
		}
	}

	if (x>wBplante2 && x<wBplante2+118 && y>hBplante2 && y<hBplante2+71 ){
		if (utilise == 0 || utilise == 1 || utilise == 3 ){
			bplante1 = IMG_Load("images/plante1.png");
			bplante2 = IMG_Load("images/BPlante2Selc.bmp");
			bplante3 = IMG_Load("images/BPlante3.bmp");
			utilise = 2;
		}
		else{
			bplante2 = IMG_Load("images/BPlante2.bmp");
			utilise = 0;
		}
	}

	if (x>wBplante3 && x<wBplante3+118 && y>hBplante3 && y<hBplante3+71 ){
			if (utilise == 0 || utilise == 1 || utilise == 2 ){
				bplante1 = IMG_Load("images/plante1.png");
				bplante2 = IMG_Load("images/BPlante2.bmp");
				bplante3 = IMG_Load("images/BPlante3Selc.bmp");
				utilise = 3;
			}
			else{
				bplante3 = IMG_Load("images/BPlante3.bmp");
				utilise = 0;
			}
	}

	if (x>wBMenuJeu && x<wBMenuJeu+118 && y>hBMenuJeu && y<hBMenuJeu+71 ){
			quitterJeu();
			appel = 0;
			interfaceMenu();
	}

	//clic sur une zone de jeu
	
	if(y/144>=0 && x/128-1>=0 && tabPlante[y/144][x/128-1]==NULL){
		posePlante(y/144,x/128-1);
	}
}

void posePlante(int i, int j){
	if (utilise == 1){
		tabPlante[i][j]=Plante_construct(i*144,j*128, 200, "nom", "type");
		tabPlante[i][j]->imagePlante = IMG_Load("images/plante1.png"); //on charge l'image a mettre
		
	}
	else if (utilise == 2){
		tabPlante[i][j]=Plante_construct(i*144,j*128, 200, "nom", "type");
		tabPlante[i][j]->imagePlante = IMG_Load("images/Plante2.bmp"); //on charge l'image a mettre
	}
	else if (utilise == 3){
		tabPlante[i][j]=Plante_construct(i*144,j*128, 200, "nom", "type");
		tabPlante[i][j]->imagePlante = IMG_Load("images/Plante3.bmp"); //on charge l'image a mettre
	}
}