#ifndef zombie_h
#define zombie_h
#include <SDL2/SDL.h>
#include "jeu.h"



Zombie* Zombie_base(int y);
Zombie* Zombie_cool(int y);
Zombie* Zombie_relou(int y);
void destructZombie(Zombie *z);
//void affichage_zombieperch(Zombieperch *p);
void afficherZ(Zombie* z1);
void zombie_kill(Zombie *p);
void avancerZ(Zombie* z1);
void attaquerZ(Plante* p, Zombie *z);
//void plante_attack_zombieperch(Zombieperch* per,Plante* p);
void zombie_lose(Zombie *p);


#endif