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
int argentActuel = NULL;
char argent[12];
SDL_Surface* txtArgent = NULL;
SDL_Color color = { 0, 0, 0 };

int scoreActuel = NULL;
char score[12];
SDL_Surface* txtScore = NULL;

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

int presence_zombie[] = {0,0,0,0,0}; //permet de savoir si il y a au moins un zombie sur la ligne i
//------------------------------------------------------------------------------------
void principalJeu(){
	vitesseZTimer = SDL_GetTicks();
	appel = 1;
	argentActuel = 1000;
	scoreActuel =0;
	int i;
	int j;

	//on initialise le tableau avec que des 0±
	for (i=0; i<5; i++){
		for (j=0; j<9; j++){
			tabPlante[i][j]=NULL;
		}
	}

	zombies[0]=Zombie_base(HAUTEUR_CASE);
	zombies[1]=Zombie_base(HAUTEUR_CASE);
	zombies[2]=Zombie_base(2*HAUTEUR_CASE);
	zombies[3]=Zombie_base(3*HAUTEUR_CASE);
	zombies[4]=Zombie_base(4*HAUTEUR_CASE);

}

void interfaceJeu(){ //crée l'interface du jeu

	fond = IMG_Load( "images/fond.png" );
	
	//Bouton plante1
	bplante1 = IMG_Load("images/BPlante0.png");
	wBplante1 = LARGEUR_CASE/2 - bplante1->w/2;
	hBplante1 = HAUTEUR_CASE/2 - bplante1->h/2;

	//Bouton plante2
	bplante2 = IMG_Load("images/BPlante1.png");
	wBplante2 = LARGEUR_CASE/2 - bplante2->w/2;
	hBplante2 = HAUTEUR_CASE/2 - bplante2->h/2 + HAUTEUR_CASE;

	//Bouton plante3
	bplante3 = IMG_Load("images/BPlante2.png");
	wBplante3 = LARGEUR_CASE/2 - bplante3->w/2;
	hBplante3 = HAUTEUR_CASE/2 - bplante3->h/2 +288;

	bMenuJeu = IMG_Load("images/BMenuJeu.png");
	wBMenuJeu = LARGEUR_CASE/2 - bMenuJeu->w/2;
	hBMenuJeu = HAUTEUR_CASE*3/4 - bMenuJeu->h/2 + 576;

	


	TTF_Init();
	police = TTF_OpenFont("Iron&Brine.ttf", 36);
	sprintf(argent, "Argent:  %d", argentActuel);
 	txtArgent = TTF_RenderText_Solid(police, argent, color);

 	sprintf(argent, "Score  %d", scoreActuel);
 	txtScore = TTF_RenderText_Solid(police, score, color);
}


//charge la balle si necessaire et fait avancer celle déjà sur le terrain
void plante_attaque(Plante *p){
	chargerBalle(p);

	int i;
	for(i=0;i<5;i++){
		if(zombies[i]!=NULL){

			if (p->b1 != NULL){

				if(degatBalle(zombies[i],p->b1) || (p->b1)->pos_bx>9*LARGEUR_CASE){
					SDL_FreeSurface((p->b1)->imageBalle);
					Balle_destruct(p->b1);
					p->b1=NULL;
				}
			}
			if (p->b2 != NULL){
				if(degatBalle(zombies[i],p->b2)|| (p->b2)->pos_bx>9*LARGEUR_CASE){
					SDL_FreeSurface((p->b2)->imageBalle);
					Balle_destruct(p->b2);
					p->b2=NULL;
				}		
			}
		}

	}	
}

void gererSoleil(Plante *p){
	chargerSoleil(p);

	if (p->b1!=NULL && p->dureeBalles>INTERVALLE_SOLEIL/3){
		SDL_FreeSurface((p->b1)->imageBalle);
		Balle_destruct(p->b1);
		p->b1=NULL;
		
	}
}

//Remet à 0 toute les case du tableau
void presenceZombieInit(){
	int i;
	for(i=0; i<5;i++){
		presence_zombie[i]=0;
	}
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
	//SDL_Rect rouge = { HAUTEUR_CASE/2 - balle->w/2-8,LARGEUR_CASE/2 - balle->h/2, 0, 0};	
	//SDL_BlitSurface( balle, NULL, screen, &rouge );

	//texte
	SDL_FreeSurface(txtArgent);
	sprintf(argent, "Argent  %d", argentActuel);
 	txtArgent = TTF_RenderText_Solid(police, argent, color);
	SDL_BlitSurface( txtArgent, NULL, screen, NULL );

	SDL_FreeSurface(txtScore);
	sprintf(score, "Score  %d", scoreActuel);
 	txtScore = TTF_RenderText_Solid(police, score, color);
 	SDL_Rect dimScore = { 1100, 0, 0, 0}; //Position du score
	SDL_BlitSurface( txtScore, NULL, screen, &dimScore );

	int i;
	int j;

	//Boucle qui gère les zombies
	for(i=0;i<5;i++){ 



		if(zombies[i]!=NULL){ //si le zombie n'est pas mort

			if (zombies[i]->pv<0){
				scoreActuel = scoreActuel + 1;
				SDL_FreeSurface(zombies[i]->img);
				destructZombie(zombies[i]);
				zombies[i]=NULL;
			}else {
				presence_zombie[zombies[i]->position_y/HAUTEUR_CASE]=1;

				//Si il y a une plante attaquer, sinon avancer
				if(tabPlante[zombies[i]->position_y/HAUTEUR_CASE][zombies[i]->position_x/LARGEUR_CASE-1]!=NULL && vitesseZTimer+100<SDL_GetTicks()) {

					attaquerZ(tabPlante[zombies[i]->position_y/HAUTEUR_CASE][zombies[i]->position_x/LARGEUR_CASE-1]);

				}else if(vitesseZTimer+100<SDL_GetTicks()){
					avancerZ(zombies[i]);
				}

				SDL_Rect zombieTest = { zombies[i]->position_x,zombies[i]->position_y, 0, 0}; //Position  du zombie
				SDL_BlitSurface( zombies[i]->img, NULL, screen, &zombieTest );//actualisation de la postion du zombie
			}
		}
	}

	//Boucle qui gère les plantes
	for(i=0; i<5;i++){
		for (j=0;j<9;j++){
			Plante *tmp=tabPlante[i][j];

			if(tmp != NULL){
				//si la plante est morte on libère la mémoire sinon on attaque si necessaire et on la re-dessine
				if(tmp->vie_plante<0){

					SDL_FreeSurface(tmp->imagePlante);
					Plante_destruct(tmp);
							
					tabPlante[i][j]=NULL;
				}else {

					tmp->dureeBalles+=1;
					

					//creation de soleil ou balle 
					if (tmp->type==0){
						gererSoleil(tmp);
					}else {
						envoyerBalle(tmp);

						if(presence_zombie[i]==1){
							plante_attaque(tmp);
						}
					}

					SDL_Rect dimplante = { (j+1)*LARGEUR_CASE,i*HAUTEUR_CASE, 0, 0}; //Position  de la plante
					SDL_BlitSurface( tmp->imagePlante, NULL, screen, &dimplante );//re-dessine

					//Pour chaque plante on re-dessine les balle si il y en a
					if (tmp->b1 != NULL){
						SDL_Rect balle = { (tmp->b1)->pos_bx,(tmp->b1)->pos_by, 0, 0}; //Position  du zombie
						SDL_BlitSurface( (tmp->b1)->imageBalle, NULL, screen, &balle );//actualisation de la postion du zombie
					}
					if (tmp->b2 != NULL){
						SDL_Rect balle = { (tmp->b2)->pos_bx,(tmp->b2)->pos_by, 0, 0}; //Position  du zombie
						SDL_BlitSurface( (tmp->b2)->imageBalle, NULL, screen, &balle );//actualisation de la postion du zombie
					}

				}

			}

		}
	}


	presenceZombieInit();

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

    SDL_FreeSurface(txtArgent);
    SDL_FreeSurface(txtScore);

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
		if (utilise !=1){
			bplante1 = IMG_Load("images/BPlante1Selc.bmp");
			bplante2 = IMG_Load("images/BPlante1.png");
			bplante3 = IMG_Load("images/BPlante2.png");
			utilise = 1;
		}
		else{
			bplante1 = IMG_Load("images/BPlante0.png");
			utilise = 0;
		}
	}

	if (x>wBplante2 && x<wBplante2+118 && y>hBplante2 && y<hBplante2+71 ){
		if (utilise !=2 ){
			bplante1 = IMG_Load("images/BPlante0.png");
			bplante2 = IMG_Load("images/BPlante2Selc.png");
			bplante3 = IMG_Load("images/BPlante2.png");
			utilise = 2;
		}
		else{
			bplante2 = IMG_Load("images/BPlante1.png");
			utilise = 0;
		}
	}

	if (x>wBplante3 && x<wBplante3+118 && y>hBplante3 && y<hBplante3+71 ){
			if (utilise !=3){
				bplante1 = IMG_Load("images/BPlante0.png");
				bplante2 = IMG_Load("images/BPlante1.png");
				bplante3 = IMG_Load("images/BPlante3Selc.bmp");
				utilise = 3;
			}
			else{
				bplante3 = IMG_Load("images/BPlante2.png");
				utilise = 0;
			}
	}

	if (x>wBMenuJeu && x<wBMenuJeu+118 && y>hBMenuJeu && y<hBMenuJeu+71 ){
			quitterJeu();
			appel = 0;
			utilise = 0;
			interfaceMenu();
	}

	//clic sur une zone de jeu
	
	if(y/HAUTEUR_CASE>=0 && x/LARGEUR_CASE-1>=0 && tabPlante[y/HAUTEUR_CASE][x/LARGEUR_CASE-1]==NULL){
		posePlante(y/HAUTEUR_CASE,x/LARGEUR_CASE-1);
	}

	//clic sur un soleil
	else if(y/HAUTEUR_CASE>=0 && x/LARGEUR_CASE-1>=0 && tabPlante[y/HAUTEUR_CASE][x/LARGEUR_CASE-1]->type == 0 && tabPlante[y/HAUTEUR_CASE][x/LARGEUR_CASE-1]->b1 != NULL){
		argentActuel = argentActuel + 25;
		SDL_FreeSurface((tabPlante[y/HAUTEUR_CASE][x/LARGEUR_CASE-1]->b1)->imageBalle);
		Balle_destruct(tabPlante[y/HAUTEUR_CASE][x/LARGEUR_CASE-1]->b1);
		tabPlante[y/HAUTEUR_CASE][x/LARGEUR_CASE-1]->b1=NULL;
	}
}



void posePlante(int i, int j){
	if (utilise == 1  && argentActuel >= 50){
		tabPlante[i][j]=Plante_construct((j+1)*LARGEUR_CASE,i*HAUTEUR_CASE, 200, "nom1", 0);
		tabPlante[i][j]->imagePlante = IMG_Load("images/plante0.png"); //on charge l'image a mettre
		argentActuel = argentActuel - 50;
	}
	else if (utilise == 2 && argentActuel >= 100){
		tabPlante[i][j]=Plante_construct((j+1)*LARGEUR_CASE, i*HAUTEUR_CASE, 200, "nom2", 1);
		tabPlante[i][j]->imagePlante = IMG_Load("images/plante1.png"); //on charge l'image a mettre
		argentActuel = argentActuel - 100;
	}
	else if (utilise == 3 && argentActuel >= 125){
		tabPlante[i][j]=Plante_construct((j+1)*LARGEUR_CASE, i*HAUTEUR_CASE, 200, "nom3", 2);
		tabPlante[i][j]->imagePlante = IMG_Load("images/plante2.png"); //on charge l'image a mettre
		argentActuel = argentActuel - 125;
	}
}