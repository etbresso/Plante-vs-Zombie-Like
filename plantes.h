#ifndef plantes_H
#define plantes_H

typedef struct Plante Plante;
Plante* Plante_construct(int posx,int posy, int vie_plante, char* nom, char* tye);
//void Plante_destruct(Plante *p);
//boolean etat_z();
//void envoyerBalle();
void affichage(Plante *p);
int getPosx();
typedef struct Balle Balle;
Balle* Balle_construct(int pos_bx ,int pos_by);

 
#endif