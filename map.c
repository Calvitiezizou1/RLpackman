#include "IOManager.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ressources.h"
#include "map.h"
#include "pack.h"
#include "ghosts.h"





int Xf, Yf;



int tab_2D[HAUT][LARG] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //0
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //5
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1}, //10
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 5, 5, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 5, 5, 5, 5, 5, 5, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 5, 5, 5, 5, 5, 5, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 5, 5, 5, 5, 5, 5, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1}, //15
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //20
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1}, //25
        {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //30
    };


void graphTab(SDL_Renderer* render){
    SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
    for(int x = 140; x<LARG*20+140; x+=20){
        SDL_RenderDrawLine(render, x, 0, x, HAUT*20);
    }
    for(int y = 0; y<HAUT*20; y+=20){
        SDL_RenderDrawLine(render, 0, y, LARG*20, y);
    }
};

int adapt_Tab(int t[HAUT][LARG], SDL_Renderer* render, pack P, Ghost F1, Ghost F2, Ghost F3, Ghost F4, char dep, char D1, char D2, char D3, char D4, int *nbVie, int score, int compt){
    if(P.etat == 0){
        renderTexture(fondGauche, render, 0, 0, 275, HAUT*20);
    }
    if(P.etat == 1){
        renderTexture(fondBonus, render, 0, 0, 275, HAUT*20);
    }
    if(*nbVie == 3){
        renderTexture(vie, render, 140, 255, 20, 20);
        renderTexture(vie, render, 170, 255, 20, 20);
        renderTexture(vie, render, 200, 255, 20, 20);
    }
    else if(*nbVie == 2){
        renderTexture(vie, render, 140, 255, 20, 20);
        renderTexture(vie, render, 170, 255, 20, 20);
    }
    else if(*nbVie == 1){
        renderTexture(vie, render, 140, 255, 20, 20);
    }

    char scoreStr[12];
    snprintf(scoreStr, sizeof(scoreStr), "%d", score);
    if(score<10){
        printText(120, 155, scoreStr, 30, 40, Police, Blanc, render);
    }
    else if(score>=10 && score<100){
        printText(105, 155, scoreStr, 60, 40, Police, Blanc, render);
    }
    else if(score>= 100 && score<1000){
        printText(90, 155, scoreStr, 90, 40, Police, Blanc, render);
    }
    else if(score>1000){
        printText(75, 155, scoreStr, 120, 40, Police, Blanc, render);
    }
    for(int i = 0; i<HAUT; i+=1){
        for(int j = 0; j<LARG; j+=1){
            if(t[i][j] == 1){
                renderTexture(mur, render, (j*20+275), (i*20), 20, 20);
            }
            else if(t[i][j] == 0){
                renderTexture(gum, render, j*20+275, i*20, 20, 20);
            }
            else if(t[i][j] == 2){
                renderTexture(bigGum, render, j*20+275, i*20, 20, 20);
            }
            else if(t[i][j] == 3){
                renderTexture(Cerise, render, j*20+275, i*20, 20, 20);
            }
            else if(t[i][j] == 50){
                if(P.etat == 1){
                    if(compt%90+1<15){
                        if(dep == 'h'){
                            renderTexture(pacManH, render, j*20+275, i*20, 20, 20);
                        }
                        else if(dep == 'b'){
                            renderTexture(pacManB, render, j*20+275, i*20, 20, 20);
                        }
                        else if(dep == 'g'){
                            renderTexture(pacManG, render, j*20+275, i*20, 20, 20);
                        }
                        else if(dep == 'd'){
                            renderTexture(pacManD, render, j*20+275, i*20, 20, 20);
                        }
                    }
                    else if(compt%90+1>15 && compt%90+1<30){
                        if(dep == 'h'){
                            renderTexture(pacOH, render, j*20+275, i*20, 20, 20);
                        }
                        else if(dep == 'b'){
                            renderTexture(pacOB, render, j*20+275, i*20, 20, 20);
                        }
                        else if(dep == 'g'){
                            renderTexture(pacOG, render, j*20+275, i*20, 20, 20);
                        }
                        else if(dep == 'd'){
                            renderTexture(pacOD, render, j*20+275, i*20, 20, 20);
                        }
                    }
                    else if(compt%90+1>30 && compt%90+1<45){
                        if(dep == 'h'){
                            renderTexture(pacFH, render, j*20+275, i*20, 20, 20);
                        }
                        else if(dep == 'b'){
                            renderTexture(pacFB, render, j*20+275, i*20, 20, 20);
                        }
                        else if(dep == 'g'){
                            renderTexture(pacFG, render, j*20+275, i*20, 20, 20);
                        }
                        else if(dep == 'd'){
                            renderTexture(pacFD, render, j*20+275, i*20, 20, 20);
                        }
                    }
                    else if(compt%90+1>45 && compt%90+1<60){
                        if(dep == 'h'){
                            renderTexture(pacBH, render, j*20+275, i*20, 20, 20);
                        }
                        else if(dep == 'b'){
                            renderTexture(pacBB, render, j*20+275, i*20, 20, 20);
                        }
                        else if(dep == 'g'){
                            renderTexture(pacBG, render, j*20+275, i*20, 20, 20);
                        }
                        else if(dep == 'd'){
                            renderTexture(pacBD, render, j*20+275, i*20, 20, 20);
                        }
                    }
                    else if(compt%90+1>60 && compt%90+1<75){
                        if(dep == 'h'){
                            renderTexture(pacVH, render, j*20+275, i*20, 20, 20);
                        }
                        else if(dep == 'b'){
                            renderTexture(pacVB, render, j*20+275, i*20, 20, 20);
                        }
                        else if(dep == 'g'){
                            renderTexture(pacVG, render, j*20+275, i*20, 20, 20);
                        }
                        else if(dep == 'd'){
                            renderTexture(pacVD, render, j*20+275, i*20, 20, 20);
                        }
                    }
                    else if(compt%90+1>75 && compt%90+1<90){
                        if(dep == 'h'){
                            renderTexture(pacRH, render, j*20+275, i*20, 20, 20);
                        }
                        else if(dep == 'b'){
                            renderTexture(pacRB, render, j*20+275, i*20, 20, 20);
                        }
                        else if(dep == 'g'){
                            renderTexture(pacRG, render, j*20+275, i*20, 20, 20);
                        }
                        else if(dep == 'd'){
                            renderTexture(pacRD, render, j*20+275, i*20, 20, 20);
                        }
                    }
                }
                else if(P.etat == 0){
                    if(dep == 'h'){
                        renderTexture(pacManH, render, j*20+275, i*20, 20, 20);
                    }
                    else if(dep == 'b'){
                        renderTexture(pacManB, render, j*20+275, i*20, 20, 20);
                    }
                    else if(dep == 'g'){
                        renderTexture(pacManG, render, j*20+275, i*20, 20, 20);
                    }
                    else if(dep == 'd'){
                        renderTexture(pacManD, render, j*20+275, i*20, 20, 20);
                }
                }
                    
            }
            else if(t[i][j] == 100 && F1.etat == 0){
                if(D1 == 'h' || D1 == 'x'){
                    renderTexture(ghost1H, render, j*20+275, i*20, 20, 20);
                }
                else if(D1 == 'b'){
                    renderTexture(ghost1B, render, j*20+275, i*20, 20, 20);
                }
                else if(D1 == 'g'){
                    renderTexture(ghost1G, render, j*20+275, i*20, 20, 20);
                }
                else if(D1 == 'd'){
                    renderTexture(ghost1D, render, j*20+275, i*20, 20, 20);
                }
            }
            else if(t[i][j] == 110 && F2.etat == 0){
                if(D2 == 'h' || D2 == 'x'){
                    renderTexture(ghost2H, render, j*20+275, i*20, 20, 20);
                }
                else if(D2 == 'b'){
                    renderTexture(ghost2B, render, j*20+275, i*20, 20, 20);
                }
                else if(D2 == 'g'){
                    renderTexture(ghost2G, render, j*20+275, i*20, 20, 20);
                }
                else if(D2 == 'd'){
                    renderTexture(ghost2D, render, j*20+275, i*20, 20, 20);
                }
            }
            else if(t[i][j] == 120 && F3.etat == 0){
                if(D3 == 'h' || D3 == 'x'){
                    renderTexture(ghost3H, render, j*20+275, i*20, 20, 20);
                }
                else if(D3 == 'b'){
                    renderTexture(ghost3B, render, j*20+275, i*20, 20, 20);
                }
                else if(D3 == 'g'){
                    renderTexture(ghost3G, render, j*20+275, i*20, 20, 20);
                }
                else if(D3 == 'd' && F4.etat == 0){
                    renderTexture(ghost3D, render, j*20+275, i*20, 20, 20);
                }
            }
            else if(t[i][j] == 130 && F4.etat == 0){
                if(D4 == 'h' || D4 == 'x'){
                    renderTexture(ghost4H, render, j*20+275, i*20, 20, 20);
                }
                else if(D4 == 'b'){
                    renderTexture(ghost4B, render, j*20+275, i*20, 20, 20);
                }
                else if(D4 == 'g'){
                    renderTexture(ghost4G, render, j*20+275, i*20, 20, 20);
                }
                else if(D4 == 'd'){
                    renderTexture(ghost4D, render, j*20+275, i*20, 20, 20);
                }
            }
            else if(t[i][j] == 100 && F1.etat == 1){
                if(D1 == 'h' || D1 == 'x'){
                    renderTexture(ghostDH, render, j*20+275, i*20, 20, 20);
                }
                else if(D1 == 'b'){
                    renderTexture(ghostDB, render, j*20+275, i*20, 20, 20);
                }
                else if(D1 == 'g'){
                    renderTexture(ghostDG, render, j*20+275, i*20, 20, 20);
                }
                else if(D1 == 'd'){
                    renderTexture(ghostDD, render, j*20+275, i*20, 20, 20);
                }
            }
            else if(t[i][j] == 110 && F2.etat == 1){
                if(D2 == 'h' || D2 == 'x'){
                    renderTexture(ghostDH, render, j*20+275, i*20, 20, 20);
                }
                else if(D2 == 'b'){
                    renderTexture(ghostDB, render, j*20+275, i*20, 20, 20);
                }
                else if(D2 == 'g'){
                    renderTexture(ghostDG, render, j*20+275, i*20, 20, 20);
                }
                else if(D2 == 'd'){
                    renderTexture(ghostDD, render, j*20+275, i*20, 20, 20);
                }
            }
            else if(t[i][j] == 120 && F3.etat == 1){
                if(D3 == 'h' || D3 == 'x'){
                    renderTexture(ghostDH, render, j*20+275, i*20, 20, 20);
                }
                else if(D3 == 'b'){
                    renderTexture(ghostDB, render, j*20+275, i*20, 20, 20);
                }
                else if(D3 == 'g'){
                    renderTexture(ghostDG, render, j*20+275, i*20, 20, 20);
                }
                else if(D3 == 'd' && F4.etat == 0){
                    renderTexture(ghostDD, render, j*20+275, i*20, 20, 20);
                }
            }
            else if(t[i][j] == 130 && F4.etat == 1){
                if(D4 == 'h' || D4 == 'x'){
                    renderTexture(ghostDH, render, j*20+275, i*20, 20, 20);
                }
                else if(D4 == 'b'){
                    renderTexture(ghostDB, render, j*20+275, i*20, 20, 20);
                }
                else if(D4 == 'g'){
                    renderTexture(ghostDG, render, j*20+275, i*20, 20, 20);
                }
                else if(D4 == 'd'){
                    renderTexture(ghostDD, render, j*20+275, i*20, 20, 20);
                }
            }
        }
    }
    if(P.etat == 1){
        SDL_Rect barre = {25, 330, (100-compt)*(2), 45}; 
        SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
        SDL_RenderFillRect(render, &barre);
    }
    return 1;
}

void setBonus(int t[HAUT][LARG]){
    int x1;int y1;
    for(int i = 0; i<4; i+=1){
        x1 = rand() % 28; y1 = rand() % 31;
        while(t[y1][x1] != 0){
            x1 = rand() % 28; y1 = rand() % 31;
        }
        t[y1][x1] = 2;
    }
    x1 = rand() % 28; y1 = rand() % 31;
    while(t[y1][x1] != 0){
        x1 = rand() % 28; y1 = rand() % 31;
    }
    t[y1][x1] = 3;
    
}
int estBigGum(int t[HAUT][LARG], int x, int y){
    if(t[y][x] == 2){
        return 1;
    }
    return 0;
}

int estCerise(int t[HAUT][LARG],int x, int y){
    if(t[y][x] == 3){
        return 1;
    }
    return 0;
}
void UpdateTab(pack *P, Ghost* F1, Ghost* F2, Ghost* F3, Ghost* F4, int t[HAUT][LARG]){
    t[F1->y][F1->x] = 100;
    t[F2->y][F2->x] = 110;
    t[F3->y][F3->x] = 120;
    t[F4->y][F4->x] = 130;

    t[P->y][P->x] = 50;
}