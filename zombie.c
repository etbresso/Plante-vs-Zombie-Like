#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "zombie.h"
#include <SDL2/SDL_image.h>

Zombie* Zombie_base(int y, int pv){
	Zombie *res=malloc(sizeof(Zombie));
	res->position_x=19*64;
	res->position_y=y;
	res->pv=pv;
	res->img=IMG_Load("images/zombie_base1.png");
	return res;
}

void avancerZ(Zombie* z1){
	z1->position_x=z1->position_x-1;
}

void afficherZ(Zombie* z1){
	printf("Zombie z1\n" );
	printf("position x: %d\n",z1->position_x );
	printf("position y: %d\n",z1->position_y );
	printf("pv: %d\n",z1->pv );
}

void attaquerZ(Plante* p){
	printf("pv:%d\n",p->vie_plante);
	p->vie_plante-=1;
	printf("pv:%d\n",p->vie_plante);
}
