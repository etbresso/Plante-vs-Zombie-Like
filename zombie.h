

#ifndef zombie_h
#define zombie_h

int main();

typedef struct {int x; 
int y;
int vie_zombie;
int num;
int pas;
int type;
int total;} zombie;
zombie* zombie_cool(int y, int num);
zombie* zombie_normal(int y, int num);
zombie* zombie_relou(int y, int num);
void zombie_kill(zombie *p);
void zombie_attack(zombie* p);
int get_vie(zombie p);
int get_type(zombie p);
void zombie_move(zombie* p);
void zombie_lose(zombie *p);

#endif
