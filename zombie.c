
#include "zombie.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


//voir avec zack a riz
int nb_b=0;

//zombie normal
Zombie* Zombie_base(int y){
	Zombie *res=malloc(sizeof(Zombie));
	res->position_x=19*64;
	res->position_y=y;
	res->type=1;
	res->pv=10;
	res->pas=2;
	res->img=IMG_Load("images/zombie1.png");
	return res;
}

//zombie cool
Zombie* Zombie_cool(int y){
	Zombie *res=malloc(sizeof(Zombie));
	res->position_x=19*64;
	res->position_y=y;
	res->pas=2;
	res->type=2;
	res->pv=15;
	res->img=IMG_Load("images/zombie2.png");
	return res;
}

//zombie relou
Zombie* Zombie_relou(int y){
	Zombie *res=malloc(sizeof(Zombieperch));
	res->position_x=19*64;
	res->position_y=y;
	res->type=3;
	res->pv=20;
	res->pas=2;
	res->img=IMG_Load("images/zombie3.png");
	return res;
}


void afficherZ(Zombie* z1){
	printf("Zombie z1\n" );
	printf("position x: %d\n",z1->position_x );
	printf("position y: %d\n",z1->position_y );
	printf("pv: %d\n",z1->pv );
}

//pour les zombieperch
/*
void affichage_zombieperch(Zombieperch *p){
	printf("Zombie p\n" );
	printf("position x: %d\n",p->position_x );
	printf("position y: %d\n",p->position_y );
	printf("pv: %d\n",p->pv );
	printf("si-pouvoir-utilisé=%d\n",p->attaque_util);
	printf("\n");
}*/


void attaquerZ(Plante* p, Zombie *z){

	if(z->type==3){
		z->position_x= p->posx-1;
		z->type=2;
		SDL_FreeSurface(z->img);
		if(z->pas==1){
			z->img=IMG_Load("images/zombie2Gel.png");
		}else{
			z->img=IMG_Load("images/zombie2.png");
		}
		
	}
		if(p->type==3 && rand()%50<5){
			
			z->pv-=1;
		}
		p->vie_plante-=1;
}
	


/*
void plante_attack_zombieperch(Zombieperch* per,Plante* p){
	if(per->attaque_util==0){
		per->attaque_util=1;
		per->position_x=-256;
		printf("saute");
	}
	else{
		p->vie_plante-=1;
	}

}*/

void avancerZ(Zombie* z1){
	z1->position_x=z1->position_x-z1->pas;
}
void destructZombie(Zombie *z){
	free(z);
}
/*
void tesGameOver(Zombie *p){
	if(get_x_zombie(*p)<=128){
		printf("perdu !!");
	}
} 
*/