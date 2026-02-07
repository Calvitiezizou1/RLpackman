#include "IOManager.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ressources.h"
#include <time.h>
#include "ghosts.h"
#include "map.h"

Ghost initGhost(char Id){
    Ghost G;
    G.id = Id;
    G.compteur=0;
    G.etat=0;
    G.vitesse=3;
    G.vision=7;
    return G;
}

void setFantome(Ghost* F1, Ghost* F2, Ghost* F3, Ghost* F4){

    F1->x = 11; F1->y = 15;
    F2->x = 12; F2->y = 14;
    F3->x = 13; F3->y = 15;
    F4->x = 14; F4->y = 14;
}

int Est_Mur(int x, int y, int t[HAUT][LARG]){
    if(t[y][x] == 1 ){
        return 1;
    }
    else{
        return 0;
    }
}
void actionFantome(int t[HAUT][LARG], Ghost* F, char dir, int *p){
        if(dir == 'h'){
            if(*p==2){
                    t[F->y][F->x] = 2;
                    *p=0;
            }
            else if(*p == 3){
                    t[F->y][F->x] = 3;
                    *p=0;
            }
            else if(*p == 0){
                    t[F->y][F->x] = 0;
                    *p=0;
            }
            else if(*p == 4){
                t[F->y][F->x] = 4;
                *p=0;
            }
            if(t[F->y-1][F->x] == 2){
                *p = 2;
                }
            else if(t[F->y-1][F->x] == 3){
                *p = 3;
            }
            else if(t[F->y-1][F->x] == 4){
            *p = 4;
            }
            F->y -= 1;
        }
        else if(dir =='b'){
            if(*p==2){
                t[F->y][F->x] = 2;
                *p=0;
                }
            else if(*p == 3){
                t[F->y][F->x] = 3;
                *p=0;
            }
            else if(*p ==0){
                t[F->y][F->x] = 0;
            }
            else if(*p == 4){
                t[F->y][F->x] = 4;
                *p=0;
            }
            if(t[F->y+1][F->x] == 2){
            *p = 2;
            }
            else if(t[F->y+1][F->x] == 3){
            *p = 3;
            }
            else if(t[F->y+1][F->x] == 4){
            *p = 4;
            }
            F->y += 1;
        }
        else if(dir =='g'){
            if(*p==2){
                t[F->y][F->x] = 2;
                *p=0;
            }
            else if(*p == 3){
                t[F->y][F->x] = 3;
                *p=0;
            }
            else if(*p == 0){
                t[F->y][F->x] = 0;
                *p=0;
            }
            else if(*p == 4){
                t[F->y][F->x] = 4;
                *p=0;
            }
            if(t[F->y][F->x-1] == 2){
            *p = 2;
            }
            else if(t[F->y][F->x-1] == 3){
            *p = 3;
            }
            else if(t[F->y][F->x-1] == 4){
            *p = 4;
            }
            F->x -= 1;
        }
        else if(dir =='d'){
            if(*p==2){
                t[F->y][F->x] = 2;
                *p=0;
            }
            else if(*p == 3){
                t[F->y][F->x] = 3;
                *p=0;
            }
            else if(*p == 0){
                t[F->y][F->x] = 0;
            }
            else if(*p == 4){
                t[F->y][F->x] = 4;
                *p=0;
            }
            if(t[F->y][F->x+1] == 2){
            *p = 2;
            }
            else if(t[F->y][F->x+1] == 3){
            *p = 3;
            }
            else if(t[F->y][F->x+1] == 4){
            *p = 4;
            }
            F->x += 1;
        }
}

char calculerCheminDijkstra(Ghost perso ,int destX , int destY, int t[HAUT][LARG] ){
    NodeDijkstra grille[HAUT][LARG];

    for(int i =0 ; i<HAUT; i++){
        for(int j = 0 ; j<LARG ; j++){
            grille[i][j].dist = 999 ;
            grille[i][j].parentX = -1 ; 
            grille[i][j].parentY = -1 ; 
            grille[i][j].visite = 0 ;
            grille[i][j].h = abs(i-destX) + abs(j-destY);
        }
    }

    int startx= perso.x;
    int starty = perso.y; 
    grille[starty][startx].dist = 0 ;
    

    for(int count = 0 ; count<HAUT*LARG ; count ++){

        int uX = -1, uY = -1 ; 
        int min =999 ;
        
        for(int i =0; i<HAUT ; i++){ // i -> ligne  ((y))
            for(int j =0 ; j < LARG ; j++){ // j -> colonne((x))
                int cout = grille[i][j].h + grille[i][j].dist;
                    if(!grille[i][j].visite && cout<min){
                    min = grille[i][j].dist;
                    uX = j ; 
                    uY = i ;
                }
            }
        }

        if(uX == -1 ) break ; 

        grille[uY][uX].visite =1;
        if(uX == destX && uY == destY) break;

        
        int dx[] = {0,0,-1,1};
        int dy[] = {1,-1,0,0};
        
        for(int k = 0 ; k < 4 ; k++){
            int vX = uX + dx[k];
            int vY = uY + dy[k];

            if(vX< 0 || vX>=LARG || vY < 0 || vY>= HAUT ){
                continue;
            }

            if (t[vY][vX] == 1) { 
                continue; 
            }

            if(!grille[vY][vX].visite && grille[uY][uX].dist+1 < grille[vY][vX].dist){
                grille[vY][vX].dist = grille[uY][uX].dist +1;
                grille[vY][vX].parentX = uX;
                grille[vY][vX].parentY = uY ;
            }


        }

    }

    if(grille[destY][destX].dist == 999) return ' ';

    int currX = destX;
    int currY = destY;
    

    while(1){
        int parX = grille[currY][currX].parentX;
        int parY = grille[currY][currX].parentY;

        if (parX == startx && parY == starty){
            if(currX>startx) return 'd';
            if(currY>starty) return 'b';
            if(currX<startx) return 'g';
            if(currY<starty) return 'h';
        }
        
        currX = parX ;
        currY = parY ;  
        
    }   

    return ' '; 
    
}

 




char deplace_fantome(int t[HAUT][LARG],pack *P, Ghost F1, Ghost* F, char *D, int *p){
    F->compteur+=1;
    if(F->compteur>F->vitesse){
        if(F->etat == 1){
            *D = calculerCheminDijkstra(F1, 14, 14, t);
            actionFantome(t, F, *D, p);
        }
        else if(F1.x>10 && F1.x<18 && F1.y>12 && F1.y<16){
            *D = calculerCheminDijkstra(F1, 14, 5, t);
            actionFantome(t, F, *D, p);
        }
        else if(abs(P->y - F->y)<= F->vision && abs(P->x-F->x)<= F->vision && P->etat == 0){
            *D = calculerCheminDijkstra(F1, P->x, P->y, t);
            actionFantome(t, F, *D, p);
        }
        else{
            if(*D == 'h' && Est_Mur(F->x+1, F->y, t) && Est_Mur(F->x-1, F->y, t) && !(Est_Mur(F->x, F->y+1, t))){
                *D = 'h';
                actionFantome(t, F, 'h', p);
            }
            else if(*D == 'b' && Est_Mur(F->x+1, F->y, t) && Est_Mur(F->x-1, F->y, t) && !(Est_Mur(F->x, F->y-1, t))){
                *D = 'b';
                actionFantome(t, F, 'b', p);
            }
            else if(*D == 'g' && Est_Mur(F->x, F->y+1, t) && Est_Mur(F->x, F->y-1, t) && !(Est_Mur(F->x-1, F->y, t))){
                *D = 'g';
                actionFantome(t, F, 'g', p);
            }
            else if(*D == 'd' && Est_Mur(F->x, F->y+1, t) && Est_Mur(F->x, F->y-1, t) && !(Est_Mur(F->x+11, F->y, t))){
                *D = 'd';
                actionFantome(t, F, 'd', p);
            }
            else if(Est_Mur(F->x+1, F->y, t) && Est_Mur(F->x-1, F->y, t) && Est_Mur(F->x, F->y+1, t) && !(Est_Mur(F->x, F->y -1, t))){
                *D = 'h';
                actionFantome(t, F, 'h', p);
            }
            else if(Est_Mur(F->x+1, F->y, t) && Est_Mur(F->x-1, F->y, t) && Est_Mur(F->x, F->y-1, t) && !(Est_Mur(F->x, F->y +1, t))){
                *D = 'b';
                actionFantome(t, F, 'b', p);
            }
            else if(Est_Mur(F->x+1, F->y, t) && Est_Mur(F->x, F->y-1, t) && Est_Mur(F->x, F->y+1, t) && !(Est_Mur(F->x-1, F->y, t))){
                *D = 'g';
                actionFantome(t, F, 'g', p);
            }
            else if(Est_Mur(F->x-1, F->y, t) && Est_Mur(F->x, F->y-1, t) && Est_Mur(F->x, F->y+1, t) && !(Est_Mur(F->x+1, F->y, t))){
                *D = 'd';
                actionFantome(t, F, 'd', p);
            }
            else{
                int a = 0;
                while(a<5){
                    int d = rand()%4;    
                    if(d == 0 && !(Est_Mur(F->x, F->y - 1, t)) && *D!='b'){ //HAUT
                        *D = 'h';
                        actionFantome(t, F, 'h', p);
                        a=11;
                    }
                    else if(d == 1 && !(Est_Mur(F->x, F->y + 1, t)) && *D!='h'){ //BAS
                        *D = 'b';
                        actionFantome(t, F, 'b', p);
                        a=11;
                    }
                    else if(d == 2 && !(Est_Mur(F->x - 1, F->y, t)) && *D!= 'd'){ //GAUCHE
                        *D = 'g';
                        actionFantome(t, F, 'g', p);
                        a=11;
                    }
                    else if(d == 3 && !(Est_Mur(F->x + 1, F->y, t)) && *D!= 'g'){ //DROITE
                        *D = 'd';
                        actionFantome(t, F, 'd', p);
                        a=11;
                    }
                    a+=1;
                }
            }
        }
        if(F->y ==14 && F->x == 14){
            F->etat = 0;
            if(F->vitesse>0){
                F->vitesse-=1;
                F->vision+=3;
            }
        }
        F->compteur = 0;
    }
    return *D;
}

void deplace_fantome_aleatoire(int t[HAUT][LARG], Ghost* F, char *D, int *p) {
    F->compteur++;
    
    if (F->compteur > F->vitesse) {
        char directions[] = {'h', 'b', 'g', 'd'};
        char valides[4];
        int nb_valides = 0;

        for (int i = 0; i < 4; i++) {
            int nextX = F->x;
            int nextY = F->y;

            if (directions[i] == 'h') nextY--;
            else if (directions[i] == 'b') nextY++;
            else if (directions[i] == 'g') nextX--;
            else if (directions[i] == 'd') nextX++;

            if (!Est_Mur(nextX, nextY, t)) {
                valides[nb_valides++] = directions[i];
            }
        }

        if (nb_valides > 0) {
            *D = valides[rand() % nb_valides];
            actionFantome(t, F, *D, p); // Met à jour la position et le contenu de la case
        }

        F->compteur = 0;
    }
}
