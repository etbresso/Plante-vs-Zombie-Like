#ifndef Jeu_H
#define Jeu_H
#define HAUTEUR_CASE 144
#define LARGEUR_CASE 128
#define DIAMETRE_BALLE 35
#define DIAMETRE_SOLEIL 60
#define LARGEUR_ZOMBIE 64
#define HAUTEUR_ZOMBIE 144
#define INTERVALLE_BALLE 650
#define INTERVALLE_SOLEIL 2000



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