#include "IOManager.h"

#ifndef LARG

#define LARG 28
#define HAUT 31

extern int tab_2D[HAUT][LARG];

extern char df1, df2, df3, df4, D_Pack, depPack;
extern int Xf, Yf, Xb1, Yb1, Xb2, Yb2, Xb3, Yb3, Xb4, Yb4, p1, p2, p3, p4, NB_Vie, Score, compteurEtat, speedFantome;

extern SDL_Texture* bigGum;
extern SDL_Texture* Cerise;
extern SDL_Texture* gum;
extern SDL_Texture* mur;

extern SDL_Texture* ghost1D;
extern SDL_Texture* ghost1H;
extern SDL_Texture* ghost1G;
extern SDL_Texture* ghost1B;

extern SDL_Texture* ghost2D;
extern SDL_Texture* ghost2H;
extern SDL_Texture* ghost2G;
extern SDL_Texture* ghost2B;

extern SDL_Texture* ghost3D;
extern SDL_Texture* ghost3H;
extern SDL_Texture* ghost3G;
extern SDL_Texture* ghost3B;

extern SDL_Texture* ghost4D;
extern SDL_Texture* ghost4H;
extern SDL_Texture* ghost4G;
extern SDL_Texture* ghost4B;

extern SDL_Texture* pacManH;
extern SDL_Texture* pacManB;
extern SDL_Texture* pacManG;
extern SDL_Texture* pacManD;

extern SDL_Texture* pacBD;
extern SDL_Texture* pacBH;
extern SDL_Texture* pacBB;
extern SDL_Texture* pacBG;

extern SDL_Texture* pacFH;
extern SDL_Texture* pacFB;
extern SDL_Texture* pacFG;
extern SDL_Texture* pacFD;

extern SDL_Texture* pacVH;
extern SDL_Texture* pacVB;
extern SDL_Texture* pacVG;
extern SDL_Texture* pacVD;

extern SDL_Texture* pacRH;
extern SDL_Texture* pacRB;
extern SDL_Texture* pacRG;
extern SDL_Texture* pacRD;

extern SDL_Texture* pacOH;
extern SDL_Texture* pacOB;
extern SDL_Texture* pacOG;
extern SDL_Texture* pacOD;

extern SDL_Texture* ghostDH;
extern SDL_Texture* ghostDB;
extern SDL_Texture* ghostDG;
extern SDL_Texture* ghostDD;

extern SDL_Texture* fondGauche;
extern SDL_Texture* fondBonus;
extern SDL_Texture* vie;
extern SDL_Texture* gameOver;

extern SDL_Color Blanc;
extern SDL_Color Noir;
extern TTF_Font* Police;

struct GhostSt{
    char id;
    int compteur;
    int x;
    int y;
    int etat;
    int vitesse;
    int vision;
};
typedef struct GhostSt Ghost;

#endif