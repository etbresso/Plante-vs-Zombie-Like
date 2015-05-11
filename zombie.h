

#ifndef zombie_h
#define zombie_h

int main();

typedef struct {
int posx_z; 
int posy_z;
int vie_zombie;
int pas;
int type_z;
} zombie;


typedef struct {
zombie z;
int attaque_util;
} zombieperch;


typedef struct {
	int posx_p;
	int posy_p;
	int vie_plante;
	int type_p;
        int cout;
}plante;

typedef struct {
	int posx_b;
	int posy_b;
        int type_b;
        int num_b;
}balle;

/*typedef struct {
	int posx;
	int posy;
	int vie_plante;
	char* nom;
	char* type;
	SDL_Surface* imagePlante;
}plante;
*/






zombie* zombie_cool(int y);
zombie* zombie_normal(int y);
zombieperch* zombie_relou(int y);

int get_vie_zombie(zombie p);
int get_type_zombie(zombie p);
int get_x_zombie(zombie p);
int get_y_zombie(zombie p);
int get_pas_zombie(zombie p);

int get_vie_zombieperch(zombieperch p);
int get_type_zombieperch(zombieperch p);
int get_x_zombieperch(zombieperch p);
int get_y_zombieperch(zombieperch p);
int get_pas_zombieperch(zombieperch p);
int get_util_att_spe(zombieperch p);

void affichage_zombieperch(zombieperch *p);
void affichage_zombie(zombie *p);

/* ******************************************* */

plante* plante_soleil(int posx ,int posy);
plante* plante_tireuse(int posx ,int posy);
plante* plante_tir_et_ral(int posx ,int posy);

int get_vie_plante(plante p);
int get_type_plante(plante p);
int get_x_plante(plante p);
int get_y_plante(plante p);

void affichage_plante(plante *p);

/* ******************************************* */

balle* balle_normale(int posx,int posy);
balle* balle_dure(int posx,int posy);

int get_type_balle(balle p);
int get_x_balle(balle p);
int get_y_balle(balle p);
int get_num_balle(balle p);

void affichage_balle(balle *p);


/* ******************************************* */

void zombie_kill(zombie *p);
void plante_kill(plante *p);
void balle_kill(balle *p);


void zombie_attack(zombie* p);

void plante_attack_normal(zombie* z,plante* p);
void plante_attack_dure(zombie* z,plante* p);

void balle_normale_attack_zombie(balle* b,zombie* z);
void balle_dure_attack_zombie(balle* b,zombie* z);

void plante_attack_zombie(zombie* p,plante* p1);
void plante_attack_zombieperch(zombieperch* p,plante* p1);

void zombie_move(zombie* p);
void balle_move(balle* b);


void zombie_lose(zombie *p);


void zombie_attack(zombie* p);
int get_vie(zombie p);
int get_type(zombie p);
void zombie_move(zombie* p);
void zombie_lose(zombie *p);
#endif
