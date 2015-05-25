#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "jeu.h"
#include "plantes.h"
#include "zombie.h"
#include "main.h"



int appel = 0; // permet de savoir si on appel principalJeu();
Uint32 vitesseZTimer = 0; //Timer
Uint32 timerApparition = 0; //permet de gérer l'apparition des vagues de zombie
Uint32 interval2Zombie = 0;
Uint32 timerBalle = 0;
int difficulte = 1; //influe sur l'arrivée des zombies
int nbZombie = 0; //nombre de zombie apparu au court d'une vague
int nbZombieMax = 0; //nombre de zombie pour une vague donné


//le texte
TTF_Font *police = NULL;
int argentActuel = NULL;
char argent[7];
char nbArgent[4];
SDL_Surface* txtArgent = NULL;
SDL_Surface* txtNbArgent = NULL;
SDL_Color color = { 0, 0, 0 };
int scoreActuel = NULL;
char score[12];
SDL_Surface* txtScore = NULL;

//les surface
SDL_Surface* fond = NULL;
SDL_Surface* bplante1 = NULL;
SDL_Surface* bplante2 = NULL;
SDL_Surface* bplante3 = NULL;
SDL_Surface* bplante4 = NULL;
SDL_Surface* bpelle = NULL;

SDL_Surface* bMenuJeu = NULL;

SDL_Surface* balle = NULL;

//SDL_Surface* plante[5][9]; //damier du jeu qui contindra les image des plantes

Plante *tabPlante[5][9];
Zombie *zombies[MAX_ZOMBIE];

//dim Bplante1
int wBplante1 = NULL;//dimention de l'image en x
int hBplante1 = NULL;//dimention de l'image en y
//dim Bplante2
int wBplante2 = NULL;//dimention de l'image en x
int hBplante2 = NULL;//dimention de l'image en y
//dim Bplante3
int wBplante3 = NULL;//dimention de l'image en x
int hBplante3 = NULL;//dimention de l'image en y
//dim Bplante4
int wBplante4 = NULL;//dimention de l'image en x
int hBplante4 = NULL;//dimention de l'image en y
//dim Bpelle
int wBpelle = NULL;//dimention de l'image en x
int hBpelle = NULL;//dimention de l'image en y

//dim bMenuJeu
int wBMenuJeu = NULL;//dimention de l'image en x
int hBMenuJeu = NULL;//dimention de l'image en y

int utilise = 0; //permet de savoir si on a cliqué sur le bouton d'une plante

int presence_zombie[] = {0,0,0,0,0}; //permet de savoir si il y a au moins un zombie sur la ligne i
//------------------------------------------------------------------------------------
void principalJeu(){
	vitesseZTimer = SDL_GetTicks();
	timerApparition = SDL_GetTicks();
	timerBalle = SDL_GetTicks();
	srand(time(NULL));
	appel = 1;
	argentActuel = 100;
	scoreActuel = 0;
	int i;
	int j;

	//on initialise le tableau avec que des 0±
	for (i=0; i<5; i++){
		for (j=0; j<9; j++){
			tabPlante[i][j]=NULL;
		}
	}
	/*
	zombies[0]=Zombie_relou(0);
	zombies[1]=Zombie_relou(HAUTEUR_CASE);
	zombies[2]=Zombie_relou(2*HAUTEUR_CASE);
	zombies[3]=Zombie_relou(3*HAUTEUR_CASE);
	zombies[4]=Zombie_relou(4*HAUTEUR_CASE);*/



}

void interfaceJeu(){ //crée l'interface du jeu

	fond = IMG_Load( "images/fond.png" );
	
	//Bouton plante1
	bplante1 = IMG_Load("images/BPlante0.png");
	wBplante1 = LARGEUR_CASE/2 - bplante1->w/2;
	hBplante1 = HAUTEUR_CASE/2 - bplante1->h/2+30;

	//Bouton plante2
	bplante2 = IMG_Load("images/BPlante1.png");
	wBplante2 = LARGEUR_CASE/2 - bplante2->w/2;
	hBplante2 = HAUTEUR_CASE/2 - bplante2->h/2 + HAUTEUR_CASE;

	//Bouton plante3
	bplante3 = IMG_Load("images/BPlante2.png");
	wBplante3 = LARGEUR_CASE/2 - bplante3->w/2;
	hBplante3 = HAUTEUR_CASE/2 - bplante3->h/2 +HAUTEUR_CASE+113;

	//Bouton plante4
	bplante4 = IMG_Load("images/BPlante3.png");
	wBplante4 = LARGEUR_CASE/2 - bplante4->w/2;
	hBplante4 = HAUTEUR_CASE/2 - bplante4->h/2 +HAUTEUR_CASE+2*113;

	//Bouton plante4
	bpelle = IMG_Load("images/BPelle.png");
	wBpelle = LARGEUR_CASE/2 - bpelle->w/2;
	hBpelle = HAUTEUR_CASE/2 - bpelle->h/2 +HAUTEUR_CASE+3*113;

	bMenuJeu = IMG_Load("images/BMenuJeu.png");
	wBMenuJeu = LARGEUR_CASE/2 - bMenuJeu->w/2;
	hBMenuJeu = HAUTEUR_CASE*3/4 - bMenuJeu->h/2 + 576;

	
	TTF_Init();
	police = TTF_OpenFont("Iron&Brine.ttf", 36);
	sprintf(argent, "Argent:");
 	txtArgent = TTF_RenderText_Solid(police, argent, color);

 	sprintf(nbArgent, "%d", argentActuel);
 	txtNbArgent = TTF_RenderText_Solid(police, nbArgent, color);

 	sprintf(argent, "Score  %d", scoreActuel);
 	txtScore = TTF_RenderText_Solid(police, score, color);
}


//charge la balle si necessaire et fait avancer celle déjà sur le terrain
void plante_attaque(Plante *p){
	if(p->type!=3){
		chargerBalle(p);

		int i;
		for(i=0;i<MAX_ZOMBIE;i++){
			if(zombies[i]!=NULL){

				if (p->b1 != NULL){

					if(degatBalle(zombies[i],p->b1, p->type) || (p->b1)->pos_bx>9*LARGEUR_CASE){
						SDL_FreeSurface((p->b1)->imageBalle);
						Balle_destruct(p->b1);
						p->b1=NULL;
					}
				}
				if (p->b2 != NULL){
					if(degatBalle(zombies[i],p->b2, p->type)|| (p->b2)->pos_bx>9*LARGEUR_CASE){
						SDL_FreeSurface((p->b2)->imageBalle);
						Balle_destruct(p->b2);
						p->b2=NULL;
					}		
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

//ajoute un zombie à la liste si il y a une case vide
void ajouterZombie(Zombie *z){
	int i=0,fait=0;
	while(i<MAX_ZOMBIE && fait==0){
		if(zombies[i]==NULL){
			zombies[i]=z;
			fait=1;
		}
		i++;
	}
}



Zombie *creationZombieAleatoire(int prcZombie1,int prcZombie2, int prcZombie3 ){
	int tirage, ligne;
	tirage=rand()%100+1;
	ligne=rand()%5;

	if(tirage>0 && tirage<=prcZombie1){
		return Zombie_base(ligne*HAUTEUR_CASE);
	}else if(tirage>prcZombie1 && tirage<=prcZombie2){
		return Zombie_cool(ligne*HAUTEUR_CASE);
	}else if(tirage>prcZombie2 && tirage<=prcZombie3){
		return Zombie_relou(ligne*HAUTEUR_CASE);
	}

	return Zombie_base(ligne*HAUTEUR_CASE);
}


Zombie *creationZombie(){

	Zombie *z;
	switch(difficulte){
		case 1:
			z=creationZombieAleatoire(100,101,102);
			break;
		case 2:
			z=creationZombieAleatoire(80,100,101);
			break;
		case 3:
			z=creationZombieAleatoire(70,95,100);
			break;
		case 4:
			z=creationZombieAleatoire(60,90,100);
			break;
		case 5:
			z=creationZombieAleatoire(50,80,100);
			break;
		case 6:
			z=creationZombieAleatoire(40,70,100);
			break;
		default:
			z=creationZombieAleatoire(20,60,100);
			break;
	}
	return z;
}


void nouveauZombie(){
	//si le nombre de zombie max de la vague n'est pas défini on le fait
	
	if (nbZombieMax==0){
		nbZombieMax=difficulte*(rand()%2+2);
	}
	//si l'intervalle de temps entre deux zombies est passé on crées le suivant
	if (interval2Zombie+INTERVALLE_ZOMBIE<SDL_GetTicks()){
		ajouterZombie(creationZombie());
		nbZombie++;
		interval2Zombie=SDL_GetTicks();
		

	}
	//si le nombre de zombie de la vague est atteint on rénitialise les variables
	if (nbZombie==nbZombieMax){
		nbZombie=0;
		nbZombieMax=0;
		timerApparition=SDL_GetTicks();
		difficulte++;

	}

}	


void actualisationJeu(SDL_Surface* screen){//actualise les positions

	int fini;

	//actualisation de la postion du fond
	SDL_BlitSurface( fond, NULL, screen, NULL );

	//Postion Bouton
	SDL_Rect dimBplante1 = { wBplante1,hBplante1, 0, 0}; //Position du bouton de la plante1
	SDL_BlitSurface( bplante1, NULL, screen, &dimBplante1 );//actualisation de la postion du Bouton de la plante1

	SDL_Rect dimBplante2 = { wBplante2,hBplante2, 0, 0}; //Position du bouton de la plante2
	SDL_BlitSurface( bplante2, NULL, screen, &dimBplante2 );//actualisation de la postion du Bouton de la plante2

	SDL_Rect dimBplante3 = { wBplante3,hBplante3, 0, 0}; //Position du bouton de la plante3
	SDL_BlitSurface( bplante3, NULL, screen, &dimBplante3 );//actualisation de la postion du Bouton de la plante3

	SDL_Rect dimBplante4 = { wBplante4,hBplante4, 0, 0}; //Position du bouton de la plante4
	SDL_BlitSurface( bplante4, NULL, screen, &dimBplante4 );//actualisation de la postion du Bouton de la plante4

	SDL_Rect dimBpelle = { wBpelle,hBpelle, 0, 0}; //Position du bouton de la pelle
	SDL_BlitSurface( bpelle, NULL, screen, &dimBpelle );//actualisation de la postion du Bouton de la pelle

	SDL_Rect dimBMenuJeu = { wBMenuJeu,hBMenuJeu, 0, 0}; //Position du bouton de la plante3
	SDL_BlitSurface( bMenuJeu, NULL, screen, &dimBMenuJeu );//actualisation de la postion du Bouton de la plante3

	//balle
	//SDL_Rect rouge = { HAUTEUR_CASE/2 - balle->w/2-8,LARGEUR_CASE/2 - balle->h/2, 0, 0};	
	//SDL_BlitSurface( balle, NULL, screen, &rouge );

	//texte
	SDL_FreeSurface(txtArgent);
	sprintf(argent, "Argent:");
 	txtArgent = TTF_RenderText_Solid(police, argent, color);
	SDL_BlitSurface( txtArgent, NULL, screen, NULL );

	SDL_FreeSurface(txtNbArgent);
	sprintf(nbArgent, "%d", argentActuel);
 	txtNbArgent = TTF_RenderText_Solid(police, nbArgent, color);
 	SDL_Rect dimNbArgent = { 0, 30, 0, 0}; //Position du score
	SDL_BlitSurface( txtNbArgent, NULL, screen, &dimNbArgent );

	SDL_FreeSurface(txtScore);
	sprintf(score, "Score  %d", scoreActuel);
 	txtScore = TTF_RenderText_Solid(police, score, color);
 	SDL_Rect dimScore = { 1100, 0, 0, 0}; //Position du score
	SDL_BlitSurface( txtScore, NULL, screen, &dimScore );

	int i;
	int j;

	//Boucle qui gère les zombies
	for(i=0;i<MAX_ZOMBIE;i++){ 



		if(zombies[i]!=NULL){ //si le zombie n'est pas mort

			if (zombies[i]->pv<0){
				scoreActuel=scoreActuel+zombies[i]->type;
				SDL_FreeSurface(zombies[i]->img);
				destructZombie(zombies[i]);
				zombies[i]=NULL;
			}else {
				presence_zombie[zombies[i]->position_y/HAUTEUR_CASE]=1;

				//Si il y a une plante attaquer, sinon avancer
				if(tabPlante[zombies[i]->position_y/HAUTEUR_CASE][zombies[i]->position_x/LARGEUR_CASE-1]!=NULL && vitesseZTimer+VITESSE_ZOMBIE<SDL_GetTicks()) {

					attaquerZ(tabPlante[zombies[i]->position_y/HAUTEUR_CASE][zombies[i]->position_x/LARGEUR_CASE-1], zombies[i]);

				}else if(vitesseZTimer+VITESSE_ZOMBIE<SDL_GetTicks()){
					avancerZ(zombies[i]);
				}

				//test si un zombie à passer la limite
				if (zombies[i]->position_x<LARGEUR_CASE){
					fini=1;
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
					tmp->dureeBalles+=(SDL_GetTicks()-timerBalle);
					printf("duree:%d\n", tmp->dureeBalles);
					printf("sdl:%d timer:%d res:%d\n", SDL_GetTicks(),timerBalle,(SDL_GetTicks()-timerBalle));
					
					

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
	timerBalle=SDL_GetTicks();
	//remet à jour la présence des zombies sur les lignes
	presenceZombieInit();

	if(vitesseZTimer+VITESSE_ZOMBIE<SDL_GetTicks()){
		vitesseZTimer=SDL_GetTicks();
	}	
	if(timerApparition+INTER_2_VAGUES<SDL_GetTicks()){
		nouveauZombie();
		
	}

	if(fini==1){
		quitterJeu();
		appel = 0;
		utilise = 0;
		interfaceMenu();
	}
			

}

int appelJeu(){
	return appel;
}

void quitterJeu(){ //ferme les images appelées dans interface
	SDL_FreeSurface( bplante1 );
	SDL_FreeSurface( bplante2 );
	SDL_FreeSurface( bplante3 );
	SDL_FreeSurface( bplante4 );
	SDL_FreeSurface( bpelle );
	SDL_FreeSurface( bMenuJeu );

	TTF_CloseFont(police);
    TTF_Quit();

    SDL_FreeSurface(txtArgent);
    SDL_FreeSurface(txtNbArgent);
    SDL_FreeSurface(txtScore);

	int i = 0;
	int j = 0;

	for (i=0; i<5; i++){
		for (j=0; j<9; j++){
			if(tabPlante[i][j]!=NULL){
				SDL_FreeSurface(tabPlante[i][j]->imagePlante);
				Plante_destruct(tabPlante[i][j]);
				tabPlante[i][j]=NULL;
			}
		}
	}

	for(i=0;i<MAX_ZOMBIE;i++){ 
		if(zombies[i]!=NULL){ //si le zombie n'est pas mort
				SDL_FreeSurface(zombies[i]->img);
				destructZombie(zombies[i]);
				zombies[i]=NULL;
		}
	}	
	SDL_FreeSurface( fond );
}

void sourisJeu(int x,int y){

	//clic sur les bouton
	if (x>wBplante1 && x<wBplante1+118 && y>hBplante1 && y<hBplante1+71 ){
		if (utilise !=1){
			bplante1 = IMG_Load("images/BPlante0Selec.png");
			bplante2 = IMG_Load("images/BPlante1.png");
			bplante3 = IMG_Load("images/BPlante2.png");
			bplante4 = IMG_Load("images/BPlante3.png");
			bpelle = IMG_Load("images/BPelle.png");
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
			bplante2 = IMG_Load("images/BPlante1Selec.png");
			bplante3 = IMG_Load("images/BPlante2.png");
			bplante4 = IMG_Load("images/BPlante3.png");
			bpelle = IMG_Load("images/BPelle.png");
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
				bplante3 = IMG_Load("images/BPlante2Selec.png");
				bplante4 = IMG_Load("images/BPlante3.png");
				bpelle = IMG_Load("images/BPelle.png");
				utilise = 3;
			}
			else{
				bplante3 = IMG_Load("images/BPlante2.png");
				utilise = 0;
			}
	}

	if (x>wBplante4 && x<wBplante4+118 && y>hBplante4 && y<hBplante4+71 ){
			if (utilise !=4){
				bplante1 = IMG_Load("images/BPlante0.png");
				bplante2 = IMG_Load("images/BPlante1.png");
				bplante3 = IMG_Load("images/BPlante2.png");
				bplante4 = IMG_Load("images/BPlante3Selc.png");
				bpelle = IMG_Load("images/BPelle.png");
				utilise = 4;
			}
			else{
				bplante4 = IMG_Load("images/BPlante3.png");
				utilise = 0;
			}
	}

	if (x>wBpelle && x<wBpelle+118 && y>hBpelle && y<hBpelle+71 ){
			if (utilise !=5){
				bplante1 = IMG_Load("images/BPlante0.png");
				bplante2 = IMG_Load("images/BPlante1.png");
				bplante3 = IMG_Load("images/BPlante2.png");
				bplante4 = IMG_Load("images/BPlante3.png");
				bpelle = IMG_Load("images/BPelleSelec.png");
				utilise = 5;
			}
			else{
				bpelle = IMG_Load("images/BPelle.png");
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
	else if(y/HAUTEUR_CASE>=0 && x/LARGEUR_CASE-1>=0 && tabPlante[y/HAUTEUR_CASE][x/LARGEUR_CASE-1]->b1 != NULL){
		argentActuel = argentActuel + 25;
		SDL_FreeSurface((tabPlante[y/HAUTEUR_CASE][x/LARGEUR_CASE-1]->b1)->imageBalle);
		Balle_destruct(tabPlante[y/HAUTEUR_CASE][x/LARGEUR_CASE-1]->b1);
		tabPlante[y/HAUTEUR_CASE][x/LARGEUR_CASE-1]->b1=NULL;
	}

	//pelle
	else if(y/HAUTEUR_CASE>=0 && x/LARGEUR_CASE-1>=0 && tabPlante[y/HAUTEUR_CASE][x/LARGEUR_CASE-1]!=NULL && utilise == 5 ){
			SDL_FreeSurface(tabPlante[y/HAUTEUR_CASE][x/LARGEUR_CASE-1]->imagePlante);
			Plante_destruct(tabPlante[y/HAUTEUR_CASE][x/LARGEUR_CASE-1]);
			tabPlante[y/HAUTEUR_CASE][x/LARGEUR_CASE-1]=NULL;
	}
}



void posePlante(int i, int j){
	if (utilise == 1  && argentActuel >= 50){
		tabPlante[i][j]=Plante_construct((j+1)*LARGEUR_CASE,i*HAUTEUR_CASE, 100, "nom1", 0);
		tabPlante[i][j]->imagePlante = IMG_Load("images/plante0.png"); //on charge l'image a mettre
		argentActuel = argentActuel - 50;
	}
	else if (utilise == 2 && argentActuel >= 100){
		tabPlante[i][j]=Plante_construct((j+1)*LARGEUR_CASE, i*HAUTEUR_CASE, 125, "nom2", 1);
		tabPlante[i][j]->imagePlante = IMG_Load("images/plante1.png"); //on charge l'image a mettre
		argentActuel = argentActuel - 100;
	}
	else if (utilise == 3 && argentActuel >= 125){
		tabPlante[i][j]=Plante_construct((j+1)*LARGEUR_CASE, i*HAUTEUR_CASE, 125, "nom3", 2);
		tabPlante[i][j]->imagePlante = IMG_Load("images/plante2.png"); //on charge l'image a mettre
		argentActuel = argentActuel - 125;
	}
	else if (utilise == 4 && argentActuel >= 75){
		tabPlante[i][j]=Plante_construct((j+1)*LARGEUR_CASE, i*HAUTEUR_CASE, 50, "nom4", 3); //il faut modifier le titre
		tabPlante[i][j]->imagePlante = IMG_Load("images/Plante3.png"); //on charge l'image a mettre
		argentActuel = argentActuel - 75;
	}
}