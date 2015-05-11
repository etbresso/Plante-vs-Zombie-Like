
#include "zombie.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


//voir avec zack a riz
int nb_b=0;
int total=0;
//voir avec zack a riz

//zombie cool
zombie* zombie_cool(int y){
zombie *res=malloc(sizeof(zombie));
res->posx_z=10;
res->posy_z=y;
res->vie_zombie=10;
res->pas=1;
res->type_z=1;
return res;
}

//zombie normal
zombie* zombie_normal(int y){
zombie *res=malloc(sizeof(zombie));
res->posx_z=10;
res->posy_z=y;
res->vie_zombie=20;
res->pas=1;
res->type_z=2;
return res;
}

//zombie relou
zombieperch* zombie_relou(int y){
	zombieperch *res=malloc(sizeof(zombieperch));
	res->z.posx_z=10;
	res->z.posy_z=y;
	res->z.vie_zombie=30;
	res->z.pas=1;
	res->z.type_z=3;
	res->attaque_util=0;
	return res;
}

//plante normal const

/*

plante* Plante_construct(int posx ,int posy,int vie_plante, char* nom, char* type){
	plante *res2=malloc(sizeof(plante));
	res2->posx=posx;
	res2->posy=posy;
	res2->vie_plante=vie_plante;
	res2->nom=nom;
	res2->type=type;
	return res2;
}

*/

//const soleil
plante* plante_soleil(int posx ,int posy){
	plante *res2=malloc(sizeof(plante));
	res2->posx_p=posx;
	res2->posy_p=posy;
	res2->vie_plante=10;
	res2->type_p=1;
        res2->cout=10;
	return res2;
}

//plante tireuse
plante* plante_tireuse(int posx ,int posy){
	plante *res2=malloc(sizeof(plante));
	res2->posx_p=posx;
	res2->posy_p=posy;
	res2->vie_plante=10;
	res2->type_p=2;
        res2->cout=20;
	return res2;
}

//plante tireuse et ralentisseuse
plante* plante_tir_et_ral(int posx ,int posy){
	plante *res2=malloc(sizeof(plante));
	res2->posx_p=posx;
	res2->posy_p=posy;
	res2->vie_plante=10;
	res2->type_p=3;
	res2->cout=30;
	return res2;
}

//balles

balle* balle_normale(int posx,int posy)
{balle *res3=malloc(sizeof(balle));
res3->posx_b=posx;
res3->posy_b=posy;
res3->type_b=1;
res3->num_b=nb_b;
nb_b=nb_b+1;
return res3;}

balle* balle_dure(int posx,int posy)
{balle *res3=malloc(sizeof(balle));
res3->posx_b=posx;
res3->posy_b=posy;
res3->type_b=2;
res3->num_b=nb_b;
nb_b=nb_b+1;
return res3;
}

//fonctions get *******************************

//pour le zombie
/*
int get_vie_zombie(zombie p){
return p.vie_zombie;
}

int get_type_zombie(zombie p){
return p.type_z;
}

int get_x_zombie(zombie p){
return p.posx_z;
}

int get_y_zombie(zombie p){
return p.posy_z;
}

int get_pas_zombie(zombie p){
return p.pas;
}

//pour le zombieperch

int get_vie_zombieperch(zombieperch p){
return p.z.vie_zombie;
}

int get_type_zombieperch(zombieperch p){
return p.z.type_z;
}

int get_x_zombieperch(zombieperch p){
return p.z.posx_z;
}

int get_y_zombieperch(zombieperch p){
return p.z.posy_z;
}

int get_pas_zombieperch(zombieperch p){
return p.z.pas;
}

int get_util_att_spe(zombieperch p){
return p.attaque_util;
}

//pour la plante

int get_vie_plante(plante p){
return p.vie_plante;
}

int get_type_plante(plante p){
return p.type_p;
}

int get_x_plante(plante p){
return p.posx_p;
}

int get_y_plante(plante p){
return p.posy_p;
}

//pour les balles

int get_type_balle(balle p){
return p.type_b;
}

int get_x_balle(balle p){
return p.posx_b;
}

int get_y_balle(balle p){
return p.posy_b;
}

int get_num_balle(balle p){
return p.num_b;
}

// affichages*********************************

//pour les zombies

void affichage_zombie(zombie *p){

printf("x=%d\n",p->posx_z);
printf("y=%d\n",p->posy_z);
printf("vie_zombie=%d\n",p->vie_zombie);
printf("le type=%d\n",p->type_z);
printf("pas=%d\n",p->pas);
printf("\n");

}

//pour les zombieperch

void affichage_zombieperch(zombieperch *p){

printf("x=%d\n",p->z.posx_z);
printf("y=%d\n",p->z.posy_z);
printf("vie_zombie=%d\n",p->z.vie_zombie);
printf("le type=%d\n",p->z.type_z);
printf("pas=%d\n",p->z.pas);
printf("si-pouvoir-utilisé=%d\n",p->attaque_util);
printf("\n");

}

//pour les plantes


void affichage_plante(plante *p){

printf("x=%d\n",p->posx_p);
printf("y=%d\n",p->posy_p);
printf("vie_plante=%d\n",p->vie_plante);
printf("le type=%d\n",p->type_p);
printf("le cout=%d\n",p->cout);
printf("\n");

}

//pour les balles

void affichage_balle(balle *p){

printf("x=%d\n",p->posx_b);
printf("y=%d\n",p->posy_b);
printf("le type=%d\n",p->type_b);
printf("le num=%d\n",p->num_b);
printf("\n");
}

//fonctions pour éliminer une plante, un zombie ou une balle

void zombie_kill(zombie *p){
free(p);// plz still use a free function:
}         // more extensible for future

void plante_kill(plante *p){
free(p);
}

void balle_kill(balle *p){
free(p);
}

//attaquer une plante


void plante_attack_zombie(zombie* p,plante* p1)
{
	if(get_vie_plante(*p1)>0 && get_x_zombie(*p)==(get_x_plante(*p1)+2) && get_y_zombie(*p)==get_y_plante(*p1))
		{p1->vie_plante -= 1;}
	else{}
}


void plante_attack_zombieperch(zombieperch* p,plante* p1)
{
	if(get_vie_plante(*p1)>0 && get_x_zombieperch(*p)==(get_x_plante(*p1)+2) && get_y_zombieperch(*p)==get_y_plante(*p1))
		if(get_util_att_spe(*p)==0)
			{p->attaque_util=1;
			 p->z.posx_z=-128;
			}
		else {p1->vie_plante -= 1;}
	else{}
}



//attaquer un zombie

//si l'on attaque plus de 10 fois un zombie, on risque de supprimer apres avoir supprime le zombie cette case mémoire qui est vide ou affecté a d'autres programmes !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void zombie_attack(zombie* p){
	if(get_vie_zombie(*p)> 0)
		{p->vie_zombie -= 1;}
	else if(get_vie_zombie(*p)==0)
		{zombie_kill(p);}
	else{}
}
/
/*les plantes attaquent e produisant des balles si y a des zombies sur leur ligne, et ces balles attaquent lez zombies, puis une fois qu'elles touchent leur cible, disparaissent, envevant un pt de vie au zombie concerné et si ce zombie n'a plus de point de vie, il disparait aussi*/

void plante_attack_normal(zombie* z,plante* p){
	if(get_y_plante(*p) == get_y_zombie(*z) && get_type_plante(*p) == 2)
		{balle_normale((get_x_plante(*p)+5),get_y_plante(*p));}
	else{}
}


void plante_attack_dure(zombie* z,plante* p){
	if(get_y_plante(*p) == get_y_zombie(*z) && get_type_plante(*p) == 3)
		{balle_dure((get_x_plante(*p)+5),get_y_plante(*p));}
	else{}
}

void balle_normale_attack_zombie(balle* b,zombie* z){
	if(get_y_balle(*b) == get_y_zombie(*z) && get_type_balle(*b)==1 )
		{zombie_attack(z);
		balle_kill(b);}
	else{}
}


//ralentir la cadence du zombie
void balle_dure_attack_zombie(balle* b,zombie* z){
	if(get_y_balle(*b) == get_y_zombie(*z) && get_type_balle(*b)==2 )
		{zombie_attack(z);
		balle_kill(b);
		z->pas=(get_pas_zombie(*z)/2);}
	else{}
}


//2 fonctions void pour changer le pas du zombie quand il s'approche de la premiere fois d'une plante afin qu'il la franchisse, puis le pas devient normal une fois que ce zombie a franchi la plante



//
//128 pixels pour un carré (ou rectangle pour les intimes)
//void tuer_plante2(zombie *p, plante *p2)
//{if(get_x_plante(p2)=get_x_zombie(p)){p2->vie_plante -=1;}
//}

//fonctionnement du jeu

void zombie_move(zombie* p)
{p->posx_z -= get_pas_zombie(*p);}


void balle_move(balle* b)
{b->posx_b += 1;}


/*detruire tous les zombies a ajouter*/
void zombie_lose(zombie *p){
	if(get_x_zombie(*p)==0)
		{printf("tu as perdu bolosse !!");}
	else
		{printf("tu est encore en jeu !!");}
}
int get_vie(zombie p)
{return p.vie_zombie;}

int get_type(zombie p)
{return p.type;}

int get_x(zombie p)
{return p.x;}


//si l'on attaque plus de 10 fois un zombie, on risque de supprimer apres avoir supprime le zombie cette case mémoire qui est vide ou affecté a d'autres programmes !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void zombie_attack(zombie* p)
{
if(get_vie(*p)> 0)
{p->vie_zombie -= 1;}
else if(get_vie(*p)==0){zombie_kill(p);}
else{}
}


//
//
//
//
//
//
//
//
//
//
void zombie_relou_detour(zombie *p)
{if(get_type(*p) == 3)
{p->pas += 1;}
else{}}
//
//void zombie_relou_normale(zombie *p, plante *p2)
//{if(p.x == (p2.x - 1))
//{p->pas = 1;}
//else{}}
//
//128 pixels pour un carré (ou rectangle pour les intimes)
//void tuer_plante2(zombie *p, plante *p2)
//{if(posx=x){p2->vie_plante -=1;}
//}
//
void zombie_move(zombie* p)
{p->x -= 1;}
//
void zombie_lose(zombie *p)
{if(get_x(*p)==0 || get_x(*p)<0){printf("tu as perdu bolosse !!");}
else{printf("tu est encore en jeu !!");}}

//
//
//

/*
int main(int argc, char *argv[])
{

printf("****************test général zombie*******************************\n");

zombie *test=zombie_cool(8);
zombie *test2=zombie_normal(13);
zombieperch *test3=zombie_relou(3);

printf("****************création de 3 types differents de zombies avec leur 3 constructeurs respectifs*******************************\n");
affichage_zombie(test);
affichage_zombie(test2);
affichage_zombieperch(test3);
printf("***********************************************\n");
affichage_zombie(test);
printf("******************test de la fonction attack qui enleve un point de vie a un zombie et qui sera réétulisé par la balle*****************************\n");
zombie_attack(test);
zombie_attack(test);

affichage_zombie(test);
printf("********************test de la fonction move pour faire bouger le zombie d'un pas (timer a mettre en plave après)***************************\n");
zombie_move(test);

affichage_zombie(test);
printf("*********************fonction pour voir si la partie est perdue ou pas (voir les param de la sdl avec Zack**************************\n");
zombie_lose(test);

affichage_zombie(test);

affichage_zombie(test2);




printf("*************test de la fonction changerdepas pour les zombies chiants (=2) et les zombies autres(=1)**********************************\n");


affichage_zombieperch(test3);

affichage_zombie(test2);


printf("*************test des plantes**********************************\n");

plante *testp=plante_soleil(10,15);
plante *testp2=plante_tireuse(11,14);
plante *testp3=plante_tir_et_ral(12,13);

affichage_plante(testp);
affichage_plante(testp2);
affichage_plante(testp3);

printf("*************attaque de la plante **********************************\n");

printf("*************test des balles**********************************\n");

balle *testb=balle_normale(25,25);
balle *testb2=balle_dure(23,23);

affichage_balle(testb);
affichage_balle(testb2);

printf("x=%d\n",test->x);
printf("y=%d\n",test->y);
printf("vie_zombie=%d\n",test->vie_zombie);
printf("num=%d\n",test->num);
printf("\n");
printf("x=%d\n",test2->x);
printf("y=%d\n",test2->y);
printf("vie_zombie=%d\n",test2->vie_zombie);
printf("num=%d\n",test2->num);
printf("\n");
printf("x=%d\n",test3->x);
printf("y=%d\n",test3->y);
printf("vie_zombie=%d\n",test3->vie_zombie);
printf("num=%d\n",test3->num);
printf("***********************************************\n");
printf("x=%d\n",test->x);
printf("y=%d\n",test->y);
printf("vie_zombie=%d\n",test->vie_zombie);
printf("num=%d\n",test->num);
printf("***********************************************\n");
printf("total=%d\n",total);
printf("***********************************************\n");
zombie_attack(test);
zombie_attack(test);

printf("x=%d\n",test->x);
printf("y=%d\n",test->y);
printf("vie_zombie=%d\n",test->vie_zombie);
printf("num=%d\n",test->num);
printf("***********************************************\n");
zombie_move(test);

printf("x=%d\n",test->x);
printf("y=%d\n",test->y);
printf("vie_zombie=%d\n",test->vie_zombie);
printf("num=%d\n",test->num);
printf("***********************************************\n");
zombie_lose(test);

printf("x=%d\n",test3->x);
printf("y=%d\n",test3->y);
printf("pas=%d\n",test3->pas);
printf("vie_zombie=%d\n",test3->vie_zombie);
printf("num=%d\n",test3->num);




printf("*************test de la fonction changerdepas**********************************\n");
zombie_relou_detour(test2);
printf("x=%d\n",test3->x);
printf("y=%d\n",test3->y);
printf("pas=%d\n",test3->pas);
printf("vie_zombie=%d\n",test3->vie_zombie);
printf("num=%d\n",test3->num);





  return EXIT_SUCCESS;
}
*/