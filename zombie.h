#ifndef zombie_h
#define zombie_h
#include <SDL2/SDL.h>
#include "plantes.h"

typedef struct Zombie Zombie;
struct Zombie{
	int position_x;
	int position_y;
	int pv;
	SDL_Surface* img;
};

typedef struct Zombieperch Zombieperch;
struct Zombieperch{
	int position_x;
	int position_y;
	int pv;
	SDL_Surface* img;
	int attaque_util;
};


Zombie* Zombie_base(int y);
Zombie* Zombie_cool(int y);
Zombieperch* zombie_relou(int y);
void affichage_zombieperch(Zombieperch *p);
void afficherZ(Zombie* z1);
void zombie_kill(Zombie *p);
void avancerZ(Zombie* z1);
void attaquerZ(Plante* p);
void plante_attack_zombieperch(Zombieperch* per,Plante* p);
void zombie_lose(Zombie *p);

#endif