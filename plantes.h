#ifndef plantes.c
#define plantes.h

typedef struct Plante Plante;
Plante* Plante_construct(int x,int y, boolean vie_Plante, String nom);
void Plante_destruct(Plante *p);
boolean etat_z();
void envoyerBalle();
 
#endif