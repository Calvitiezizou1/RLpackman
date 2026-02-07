#include "IOManager.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ressources.h"
#include "pack.h"


#ifndef FANTOME
#define FANTOME
# define NBDEDEPMAX 100



void setFantome(Ghost* F1, Ghost* F2, Ghost* F3, Ghost* F4);
Ghost initGhost(char Id);
int Est_Mur(int x, int y, int t[HAUT][LARG]);
void actionFantome(int t[HAUT][LARG], Ghost* F, char dir, int *p);
char deplace_fantome(int t[HAUT][LARG], pack *P, Ghost F1, Ghost* F, char *D, int *p);
void deplace_fantome_aleatoire(int t[HAUT][LARG], Ghost* F, char *D, int *p);

typedef struct{
    int dist;
    int parentX;
    int parentY;
    int visite; //  ! booléen 
    int h ;
}NodeDijkstra ; 


char calculerCheminDijkstra(Ghost perso ,int destX , int destY, int t[HAUT][LARG] );


#endif