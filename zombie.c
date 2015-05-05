
#include "zombie.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int total=0;

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


//int get_vie(zombie *p)
//{return p.vie_zombie;}

//int get_type()
//{return p.type;}

int zombie_attack(zombie *p)
{
if(p.vie_zombie > 0)
{p->vie_zombie -= 1;}
else{zombie_kill(p);}
}

//void zombie_relou_detour(zombie *p)
//{if(p.get_type == 3)
//{p->pas = 2;}
//else{}}
//
//void zombie_relou_normale(zombie *p)
//{if(
//
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

  return EXIT_SUCCESS;
}
