#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ghosts.h"

# include "pack.h"

#ifndef MAP

#define MAP


void graphTab(SDL_Renderer* render);
int adapt_Tab(int t[HAUT][LARG], SDL_Renderer* render, pack P, Ghost F1, Ghost F2, Ghost F3, Ghost F4, char dep, char D1, char D2, char D3, char D4, int *nbVie, int score, int compt);
void setBonus(int t[HAUT][LARG]);
int estBigGum(int t[HAUT][LARG], int x, int y);
int estCerise(int t[HAUT][LARG],int x, int y);
void UpdateTab(pack *P, Ghost* F1, Ghost* F2, Ghost* F3, Ghost* F4, int t[HAUT][LARG]);


#endif