# include "pack.h"
# include "ressources.h"

pack init_pakuman(){
    pack pakuman;
    pakuman.x = 1;
    pakuman.y = 1 ; 
    pakuman.point = 0 ; 
    pakuman.vie = 3 ;
    pakuman.etat = 0;
    return pakuman;
}
void UpdateScore(pack *F, int *score, char dir){
    if(dir == 'h'){
        if(tab_2D[F->y-1][F->x] == 0){
            *score+=10;
        }
        else if(tab_2D[F->y-1][F->x] == 3){
            *score +=100;
        }
    }
    else if(dir == 'b'){
        if(tab_2D[F->y+1][F->x] == 0){
            *score+=10;
        }
        else if(tab_2D[F->y+1][F->x] == 3){
            *score +=100;
        }
    }
    else if(dir == 'g'){
        if(tab_2D[F->y][F->x-1] == 0){
            *score+=10;
        }
        else if(tab_2D[F->y][F->x-1] == 3){
            *score +=100;
        }
    }
    else if(dir == 'd'){
        if(tab_2D[F->y][F->x+1] == 0){
            *score+=10;
        }
        else if(tab_2D[F->y][F->x+1] == 3){
            *score +=100;
        }
    }
}

void updateEtat(pack *F, char dir, int *c){
    if(*c>100){
        F->etat = 0;
    }
    if(dir == 'h' && tab_2D[F->y-1][F->x] == 2){
        F->etat = 1;
        *c = 0;
    }
    else if(dir == 'b' && tab_2D[F->y+1][F->x] == 2){
        F->etat = 1;
        *c = 0;
    }
    else if(dir == 'g' && tab_2D[F->y][F->x-1] == 2){
        F->etat = 1;
        *c = 0;
    }
    else if(dir == 'd' && tab_2D[F->y][F->x+1] == 2){
        F->etat = 1;
        *c = 0;
    }
} 

char Deplacement(pack *aDep, int t[HAUT][LARG], int *score, int *compt, char depPrec){
    char dep = processKeyboard();
    if(dep == ' '){
        dep = depPrec;
    }
    updateEtat(aDep, dep, compt);
    if(dep == 'h' && !(peut_aller(aDep, dep, tab_2D))){
        t[aDep->y][aDep->x] = 4;
        UpdateScore(aDep, score, dep);
        aDep->y-- ;
    }
    if(dep == 'b' && !(peut_aller(aDep, dep, tab_2D))){
        t[aDep->y][aDep->x] = 4;
        UpdateScore(aDep, score, dep);
        aDep->y ++ ; 

    }
    if(dep == 'd' && !(peut_aller(aDep, dep, tab_2D))){
        t[aDep->y][aDep->x] = 4;
        UpdateScore(aDep, score, dep);
        aDep->x ++;
    }
    if(dep=='g' && !(peut_aller(aDep, dep, tab_2D))){
        t[aDep->y][aDep->x] = 4;
        UpdateScore(aDep, score, dep);
        aDep->x-- ;
    }
    *compt +=1;
    return dep;
}

char Deplacement_RL(pack *aDep, int t[HAUT][LARG], int *score, int *compt, char action_ia) {
    
    char dep = action_ia; 

    updateEtat(aDep, dep, compt); //

    
    if(dep == 'h' && !(peut_aller(aDep, dep, t))){
        t[aDep->y][aDep->x] = 4; // Marque le passage
        UpdateScore(aDep, score, dep); //
        aDep->y-- ;
    }
    else if(dep == 'b' && !(peut_aller(aDep, dep, t))){
        t[aDep->y][aDep->x] = 4;
        UpdateScore(aDep, score, dep);
        aDep->y++ ; 
    }
    else if(dep == 'd' && !(peut_aller(aDep, dep, t))){
        t[aDep->y][aDep->x] = 4;
        UpdateScore(aDep, score, dep);
        aDep->x++;
    }
    else if(dep == 'g' && !(peut_aller(aDep, dep, t))){
        t[aDep->y][aDep->x] = 4;
        UpdateScore(aDep, score, dep);
        aDep->x-- ;
    }

    *compt += 1; //
    return dep;
}


void respawnFantome(Ghost *F1, Ghost *F2, Ghost *F3, Ghost *F4){
    if(F1->x<16 && F1->y<15){
        tab_2D[F1->y][F1->x] = 0;
        F1->x = 11; F1->y = 15;
    }
    if(F2->x<16 && F2->y<15){
        tab_2D[F2->y][F2->x] = 0;
        F2->x = 12; F2->y = 14;
    }
    if(F3->x<16 && F3->y<15){
        tab_2D[F3->y][F3->x] = 0;
        F3->x = 13; F3->y = 15;
    }
    if(F4->x<16 && F4->y<15){
        tab_2D[F4->y][F4->x] = 0;
        F4->x = 14; F4->y = 14;
    }
}

void Death(pack *P, Ghost *F1, Ghost *F2, Ghost *F3, Ghost *F4, int *nbVie, int *score){
    if(P->etat == 0){
        if(P->x == F1->x && P->y == F1->y && F1->etat == 0){
            *nbVie-= 1;
            tab_2D[P->y][P->x] =0;
            P->x = 1;
            P->y = 1;
            respawnFantome(F1, F2, F3, F4);
        }
        else if(P->x == F2->x && P->y == F2->y && F2->etat == 0){
            *nbVie-= 1;
            tab_2D[P->y][P->x] =0;
            P->x = 1;
            P->y = 1;
            respawnFantome(F1, F2, F3, F4);
        }
        else if(P->x == F3->x && P->y == F3->y && F3->etat == 0){
            *nbVie-= 1;
            tab_2D[P->y][P->x] =0;
            P->x = 1;
            P->y = 1;
            respawnFantome(F1, F2, F3, F4);
        }
        else if(P->x == F4->x && P->y == F4->y && F4->etat == 0){
            *nbVie-= 1;
            tab_2D[P->y][P->x] =0;
            P->x = 1;
            P->y = 1;
            respawnFantome(F1, F2, F3, F4);
        }
    }
    else if(P->etat == 1){
        if(P->x == F1->x && P->y == F1->y && F1->etat == 0){
            F1->etat = 1;
            *score += 200;
        }
        else if(P->x == F2->x && P->y == F2->y && F2->etat == 0){
            F2->etat= 1;
            *score += 200;
        }
        else if(P->x == F3->x && P->y == F3->y && F3->etat == 0){
            F3->etat = 1;
            *score += 200;
        }
        else if(P->x == F4->x && P->y == F4->y && F4->etat == 0){
            F4->etat = 1;
            *score += 200;
        }
    }
}

int peut_aller(pack *paki , char dep , int t[HAUT][LARG]){ // fonction qui retourne 0 si paki peut suivre le deplacement dep et 1 si ne peut pas
    int res =0;
    int X = paki->x;
    int Y = paki->y;

    if (dep == 'h'){
        if(t[Y-1][X]==1){
            res = 1 ;
        }
    }
    if(dep== 'b'){
        if(t[Y +1][X]  == 1){
            res =1 ; 
        }
    }
    if(dep == 'd'){
        if(t[Y][X+1]== 1){
            res = 1 ; 
        }   
    }
    if(dep == 'g'){
        if(t[Y][X-1] == 1){
            res =1 ; 
        }
    }
    return res ; 
}


    // SDL_Texture* PacManD = loadTexture("./Im/pakuman_0.bmp", render);
    // SDL_Texture* PacMAnH = loadTexture("./Im/pakuman_1.bmp", render);
    // SDL_Texture* PacManG = loadTexture("./Im/pakuman_2.bmp", render);
    // SDL_Texture* PacManB = loadTexture("./Im/pakuman_3.bmp", render);