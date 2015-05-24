#ifndef plantes_H
#define plantes_H
#include <SDL2/SDL.h>
#include "jeu.h"

Plante* Plante_construct(int posx,int posy, int vie_plante, char* nom, int type);
void Plante_destruct(Plante *p);
void envoyerBalle(Plante *p);
void chargerBalle(Plante *p);
void affichage(Plante *p);
Balle* Balle_construct(int pos_bx ,int pos_by, int type);
void Balle_destruct(Balle *b);
int degatBalle (Zombie *z, Balle *b, int type);
void chargerSoleil(Plante *p);

 
#endif