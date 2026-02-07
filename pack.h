

# include <stdio.h>
# include <stdlib.h>
# include <string.h> 
# include "ressources.h"

#ifndef PAKI
#define PAKI


typedef struct{
    int x ;
    int y ;
    int point ;
    int vie ;
    int etat;
}pack ; 





pack init_pakuman();
char Deplacement(pack *aDep, int t[HAUT][LARG], int *score, int *compt, char depPrec) ; 
// si dep = b =>  y = y+1 
// si dep = d => x = x+1

void Death(pack *P, Ghost *F1, Ghost *F2, Ghost *F3, Ghost *F4, int *nbVie, int *score);
// a verifier dans la boucle de jeu apres un appel de cette fonction si pakuman(goat) n'a pas plus de vie. 

int peut_aller(pack *paki , char dep , int t[HAUT][LARG]) ; 
void UpdateScore(pack *F, int *score, char dir);
void updateEtat(pack *F, char dir, int *c);
void respawnFantome(Ghost *F1, Ghost *F2, Ghost *F3, Ghost *F4);


char Deplacement_RL(pack *aDep, int t[HAUT][LARG], int *score, int *compt, char direction_ia);

#endif