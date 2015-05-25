#include <stdlib.h>
#include <stdio.h>
#include "plantes.h"
#include <SDL2/SDL_image.h>



Balle* Balle_construct(int pos_bx ,int pos_by, int type){
	Balle *res=malloc(sizeof(Balle));
	res->pos_bx=pos_bx;
	res->pos_by=pos_by;
	switch(type){
		case 0:
			res->imageBalle = IMG_Load("images/soleil.png");
			break;
		case 1:	
			res->imageBalle = IMG_Load("images/ball1.png");
			break;
		case 2:
			res->imageBalle = IMG_Load("images/ball2.png");
			break;
		default:
			res->imageBalle = NULL;
			break;		
	}
	return res;
}

void Balle_destruct(Balle *b){
	free(b);
}


Plante* Plante_construct(int posx ,int posy,int vie_plante, char* nom, int type){
	Plante *res=malloc(sizeof(Plante));
	res->posx=posx;
	res->posy=posy;
	res->vie_plante=vie_plante;
	res->nom=nom;
	res->type=type;
	
	if (type==0){
		res->dureeBalles=0;
	}else{
		res->dureeBalles=INTERVALLE_BALLE;
	}
	
	res->imagePlante = NULL;
	res->b1 = NULL;
	res->b2 = NULL;
	return res;
}

void Plante_destruct(Plante *p){
	if(p->b1 != NULL){
		free(p->b1);	
	}
	if(p->b2 != NULL){
		free(p->b2);	
	}
	free(p);
}

void envoyerBalle(Plante *p){
	
	if(p->b1 != NULL){
		(p->b1)->pos_bx+=4;
	}
	if(p->b2 != NULL){
		(p->b2)->pos_bx+=4;
	}
}

void chargerBalle(Plante *p){

		if(p->b1 == NULL && p->b2 == NULL && p->dureeBalles>INTERVALLE_BALLE){

			p->b1=Balle_construct(p->posx+93 ,p->posy+42, p->type);
			p->dureeBalles=0;

		}else if(p->b2 == NULL && p->dureeBalles>INTERVALLE_BALLE ){

			p->b2=Balle_construct(p->posx+93 ,p->posy+42, p->type);
			p->dureeBalles=0;

		}else if(p->b1 == NULL && p->dureeBalles>INTERVALLE_BALLE){

			p->b1=Balle_construct(p->posx+93 ,p->posy+42, p->type);
			p->dureeBalles=0;
		}
}

void chargerSoleil(Plante *p){
	if (p->b1 == NULL && p->dureeBalles>INTERVALLE_SOLEIL){
		p->b1 = Balle_construct(p->posx+LARGEUR_CASE-DIAMETRE_SOLEIL ,p->posy+HAUTEUR_CASE-DIAMETRE_SOLEIL, 0);
		p->dureeBalles=0;
	}
}




int degatBalle (Zombie *z, Balle *b, int type){


	if(	(z->position_y)/HAUTEUR_CASE==(b->pos_by)/HAUTEUR_CASE
		&& (b->pos_bx+DIAMETRE_BALLE)<(z->position_x+LARGEUR_ZOMBIE) 
		&& (b->pos_bx+DIAMETRE_BALLE)>(z->position_x+5)){

		//20% de chance de ralentir le zombie pour la plante de type 2
		if(type==2 && rand()%10<2 && z->pas>1){
			z->pas=z->pas-1;

			//Nouveau sprite
			SDL_FreeSurface(z->img);
			if (z->type==1){
				z->img=IMG_Load("images/zombie1Gel.png");
			}else if(z->type==2){
				z->img=IMG_Load("images/zombie2Gel.png");
			}else if(z->type==3){
				z->img=IMG_Load("images/zombie3Gel.png");
			}
			
		}
		z->pv-=1;
		return 1;

	}
	return 0;
}

