
#include "zombie.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int total=0;
//voir avec zack a riz

//zombie cool
zombie* zombie_cool(int y, int num){
zombie *res=malloc(sizeof(zombie));
res->x=10;
res->y=y;
res->vie_zombie=10;
res->pas=1;
res->type=1;
res->num=num;
total=total+1;
return res;
}

//zombie normal
zombie* zombie_normal(int y, int num){
zombie *res=malloc(sizeof(zombie));
res->x=10;
res->y=y;
res->vie_zombie=20;
res->pas=1;
res->type=2;
res->num=num;
total=total+1;
return res;
}

//zombie relou
zombie* zombie_relou(int y, int num){
zombie *res=malloc(sizeof(zombie));
res->x=10;
res->y=y;
res->vie_zombie=30;
res->pas=1;
res->type=3;
res->num=num;
total=total+1;
return res;
}


void zombie_kill(zombie *p)
{
free(p);// plz still use a free function:
}         // more extensible for future


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
int main(int argc, char *argv[])
{

zombie *test=zombie_cool(8,150);
zombie *test2=zombie_normal(13,151);
zombie *test3=zombie_relou(3,152);

printf("***********************************************\n");
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
