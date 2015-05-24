#ifndef Jeu_H
#define Jeu_H
#define HAUTEUR_CASE 144
#define LARGEUR_CASE 128
#define DIAMETRE_BALLE 35
#define DIAMETRE_SOLEIL 60
#define LARGEUR_ZOMBIE 64
#define HAUTEUR_ZOMBIE 144
#define INTERVALLE_BALLE 650
#define INTERVALLE_SOLEIL 1600 
#define MAX_ZOMBIE 21
#define INTERVALLE_ZOMBIE 13000 //intervalle de temps entre l'apparition de 2 zombies d'une même vague
#define VITESSE_ZOMBIE 80 //plus elle est grande plus les zombies sont lent
#define INTER_2_VAGUES 80000  //intervalle de temps entre 2 vagues




typedef struct Balle Balle;
struct Balle{
	int pos_bx;
	int pos_by;
	SDL_Surface* imageBalle;
};

typedef struct Plante Plante;
struct Plante{
	int posx;
	int posy;
	int vie_plante;
	char* nom;
	int type;
	Balle *b1;
	Balle *b2;
	int dureeBalles;
	SDL_Surface* imagePlante;
};


typedef struct Zombie Zombie;
struct Zombie{
	int position_x;
	int position_y;
	int pv;
	int type;
	int pas;
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


void principalJeu();
void interfaceJeu();
int appelJeu();
void actualisationJeu(SDL_Surface* screen);
void quitterJeu();
void sourisJeu(int x,int y);
void posePlante(int i, int j);

#endif