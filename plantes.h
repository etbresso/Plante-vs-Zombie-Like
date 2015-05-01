#ifndef plantes_H
#define plantes_H

typedef struct Plante Plante;
Plante* Plante_construct(int posx,int posy, int vie_plante, char* nom);
//void Plante_destruct(Plante *p);
//boolean etat_z();
//void envoyerBalle();
void affichage(Plante *p);
 
#endif