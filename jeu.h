#ifndef Jeu_H
#define Jeu_H

void principalJeu();
void interfaceJeu();
int appelJeu();
void actualisationJeu(SDL_Surface* screen);
void quitterJeu();
void sourisJeu(int *x,int *y);
void posePlante(int i, int j);

#endif