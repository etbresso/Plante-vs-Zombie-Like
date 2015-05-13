
#include "zombie.h"
#include <SDL2/SDL.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>


//voir avec zack a riz
int nb_b=0;

//zombie normal
Zombie* Zombie_base(int y){
	Zombie *res=malloc(sizeof(Zombie));
	res->position_x=19*64;
	res->position_y=y;
	res->pv=100;
	res->img=IMG_Load("images/zombie_base1.png");
	return res;
}

//zombie cool
Zombie* zombie_cool(int y){
	Zombie *res=malloc(sizeof(Zombie));
	res->position_x=19*64;
	res->position_y=y;
	res->pv=75;
	res->img=IMG_Load("images/zombie_base1.png");
	return res;
}

//zombie relou
Zombieperch* zombie_relou(int y){
	Zombieperch *res=malloc(sizeof(Zombieperch));
	res->position_x=19*64;
	res->position_y=y;
	res->pv=150;
	res->img=IMG_Load("images/zombie_base1.png");
	res->attaque_util=0;
	return res;
}

void afficherZ(Zombie* z1){
	printf("Zombie z1\n" );
	printf("position x: %d\n",z1->position_x );
	printf("position y: %d\n",z1->position_y );
	printf("pv: %d\n",z1->pv );
}

//pour les zombieperch

void affichage_zombieperch(Zombieperch *p){
	printf("Zombie p\n" );
	printf("position x: %d\n",p->position_x );
	printf("position y: %d\n",p->position_y );
	printf("pv: %d\n",p->pv );
	printf("si-pouvoir-utilisé=%d\n",p->attaque_util);
	printf("\n");
}

void zombie_kill(Zombie *p){
	free(p);
}

void attaquerZ(Plante* p){
	printf("pv:%d\n",p->vie_plante);
	p->vie_plante-=1;
	printf("pv:%d\n",p->vie_plante);
}

void plante_attack_zombieperch(Zombieperch* per,Plante* p){
	if(per->attaque_util==0){
		per->attaque_util=1;
		per->position_x=-256;
		printf("saute");
	}
	else{
		printf("pv:%d\n",p->vie_plante);
		p->vie_plante-=1;
		printf("pv:%d\n",p->vie_plante);
	}

}

void avancerZ(Zombie* z1){
	z1->position_x=z1->position_x-1;
}
/*
void zombie_lose(Zombie *p){
	if(get_x_zombie(*p)==0){
		printf("tu as perdu bolosse !!");
	}else{
		printf("tu est encore en jeu !!");
	}
} 
*/