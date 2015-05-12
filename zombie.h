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


Zombie* Zombie_base(int y, int pv);
void avancerZ(Zombie* z1);
void attaquerZ(Plante* p);

#endif