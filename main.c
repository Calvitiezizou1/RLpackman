#include "IOManager.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ressources.h"
#include "map.h"
#include "pack.h"
#include "game.h"
#include "ghosts.h"
#include "agent_rl.h"
#include <time.h>
#include <math.h>

SDL_Texture* bigGum = NULL;
SDL_Texture* Cerise = NULL;
SDL_Texture* gum = NULL;
SDL_Texture* mur = NULL;

SDL_Texture* ghost1D = NULL;
SDL_Texture* ghost1H = NULL;
SDL_Texture* ghost1G = NULL;
SDL_Texture* ghost1B = NULL;

SDL_Texture* ghost2D = NULL;
SDL_Texture* ghost2H = NULL;
SDL_Texture* ghost2G = NULL;
SDL_Texture* ghost2B = NULL;

SDL_Texture* ghost3D = NULL;
SDL_Texture* ghost3H = NULL;
SDL_Texture* ghost3G = NULL;
SDL_Texture* ghost3B = NULL;

SDL_Texture* ghost4D = NULL;
SDL_Texture* ghost4H = NULL;
SDL_Texture* ghost4G = NULL;
SDL_Texture* ghost4B = NULL;

SDL_Texture* pacManH = NULL;
SDL_Texture* pacManB = NULL;
SDL_Texture* pacManG = NULL;
SDL_Texture* pacManD = NULL;

SDL_Texture* pacBD = NULL;
SDL_Texture* pacBH = NULL;
SDL_Texture* pacBB = NULL;
SDL_Texture* pacBG = NULL;

SDL_Texture* pacFH = NULL;
SDL_Texture* pacFB = NULL;
SDL_Texture* pacFG = NULL;
SDL_Texture* pacFD = NULL;

SDL_Texture* pacVH = NULL;
SDL_Texture* pacVB = NULL;
SDL_Texture* pacVG = NULL;
SDL_Texture* pacVD = NULL;

SDL_Texture* pacRH = NULL;
SDL_Texture* pacRB = NULL;
SDL_Texture* pacRG = NULL;
SDL_Texture* pacRD = NULL;

SDL_Texture* pacOH = NULL;
SDL_Texture* pacOB = NULL;
SDL_Texture* pacOG = NULL;
SDL_Texture* pacOD = NULL;

SDL_Texture* ghostDH = NULL;
SDL_Texture* ghostDB = NULL;
SDL_Texture* ghostDG = NULL;
SDL_Texture* ghostDD = NULL;

SDL_Texture* fondGauche = NULL;
SDL_Texture* fondBonus = NULL;
SDL_Texture* vie = NULL;
SDL_Texture* gameOver = NULL;

SDL_Color Blanc;
SDL_Color Noir;
TTF_Font* Police;

char D_Pack = 'd';


int main(int argc, char *argv[]) {


    /*      TRAIN 

    srand(time(NULL));

    QAgent agent_pacman;
    agent_pacman.alpha = 0.1f;
    agent_pacman.gamma = 0.9f;
    agent_pacman.epsilon = 0.9f; 

    train(&agent_pacman, 100000); 


    save_q_table(&agent_pacman, "ia_pacman.dat");
*/
    QAgent agent_pacman;

    load_q_table(&agent_pacman, "ia_pacman.dat");

// IMPORTANT : On met epsilon à 0 pour que l'IA ne joue QUE ses meilleurs coups
    agent_pacman.epsilon = 0.0f; 

// On regroupe les fantômes dans un tableau pour get_state  
    Ghost ghosts[4];




    initSDL();
    initTTF();

    SDL_Window* fenetre = createWindow("Mon jeu", LARG*20+275, HAUT*20);
    SDL_Renderer* ren = createRenderer(fenetre);

    bigGum = loadTexture("./Im/bigGum.bmp", ren);
    Cerise = loadTexture("./Im/cherry.bmp", ren);
    gum = loadTexture("./Im/gum.bmp", ren);
    mur = loadTexture("./Im/wall.bmp", ren);

    ghost1D = loadTexture("./Im/ghost1_0.bmp", ren);
    ghost1H = loadTexture("./Im/ghost1_1.bmp", ren);
    ghost1G = loadTexture("./Im/ghost1_2.bmp", ren);
    ghost1B = loadTexture("./Im/ghost1_3.bmp", ren);

    ghost2D = loadTexture("./Im/ghost2_0.bmp", ren);
    ghost2H = loadTexture("./Im/ghost2_1.bmp", ren);
    ghost2G = loadTexture("./Im/ghost2_2.bmp", ren);
    ghost2B = loadTexture("./Im/ghost2_3.bmp", ren);

    ghost3D = loadTexture("./Im/ghost3_0.bmp", ren);
    ghost3H = loadTexture("./Im/ghost3_1.bmp", ren);
    ghost3G = loadTexture("./Im/ghost3_2.bmp", ren);
    ghost3B = loadTexture("./Im/ghost3_3.bmp", ren);

    ghost4D = loadTexture("./Im/ghost4_0.bmp", ren);
    ghost4H = loadTexture("./Im/ghost4_1.bmp", ren);
    ghost4G = loadTexture("./Im/ghost4_2.bmp", ren);
    ghost4B = loadTexture("./Im/ghost4_3.bmp", ren);
    
    pacManH = loadTexture("./Im/pakuman_1.bmp", ren);
    pacManB = loadTexture("./Im/pakuman_3.bmp", ren);
    pacManG = loadTexture("./Im/pakuman_2.bmp", ren);
    pacManD = loadTexture("./Im/pakuman_0.bmp", ren);

    ghostDH = loadTexture("./Im/GhostDH.bmp", ren);
    ghostDB = loadTexture("./Im/GhostDB.bmp", ren);
    ghostDG = loadTexture("./Im/GhostDG.bmp", ren);
    ghostDD = loadTexture("./Im/GhostDD.bmp", ren);
    
    pacBD = loadTexture("./Im/PacBD.bmp", ren);
    pacBH = loadTexture("./Im/PacBH.bmp", ren);
    pacBB = loadTexture("./Im/PacBB.bmp", ren);
    pacBG = loadTexture("./Im/PacBG.bmp", ren);

    pacFH = loadTexture("./Im/PacFH.bmp", ren);
    pacFB = loadTexture("./Im/PacFB.bmp", ren);
    pacFG = loadTexture("./Im/PacFG.bmp", ren);
    pacFD = loadTexture("./Im/PacFD.bmp", ren);

    pacVH = loadTexture("./Im/PacVH.bmp", ren);
    pacVB = loadTexture("./Im/PacVB.bmp", ren);
    pacVG = loadTexture("./Im/PacVG.bmp", ren);
    pacVD = loadTexture("./Im/PacVD.bmp", ren);

    pacRH = loadTexture("./Im/PacRH.bmp", ren);
    pacRB = loadTexture("./Im/PacRB.bmp", ren);
    pacRG = loadTexture("./Im/PacRG.bmp", ren);
    pacRD = loadTexture("./Im/PacRD.bmp", ren);

    pacOH = loadTexture("./Im/PacOH.bmp", ren);
    pacOB = loadTexture("./Im/PacOB.bmp", ren);
    pacOG = loadTexture("./Im/PacOG.bmp", ren);
    pacOD = loadTexture("./Im/PacOD.bmp", ren);

    fondGauche = loadTexture("./Im/Fond_Gauche.bmp", ren);
    fondBonus = loadTexture("./Im/EcranBonus.bmp", ren);
    vie = loadTexture("./Im/Vie.bmp", ren);
    gameOver = loadTexture("./Im/Game_Over.bmp", ren);
    char depPack = 'd';

    Police = createFont("DejaVuSans-Bold.ttf", 15);

    SDL_Color Blanc = {255, 255, 255, 255};
    SDL_Color Noir = {10, 10, 60, 255};
    
    srand(time(NULL));
    int speedFantome=4;
    char df1 ='x';
    char df2 = 'x';
    char df3 = 'x';
    char df4 = 'x';
    char previous;
    int p1 = 0;
    int p2 = 0;
    int p3 = 0;
    int p4 = 0;
    int NB_Vie = 3;
    int Score = 0;
    int compteurEtat = 10000;
    

    Ghost F_Rouge = initGhost(100);
    Ghost F_Rose = initGhost(110);
    Ghost F_Bleu = initGhost(120);
    Ghost F_Jaune = initGhost(130);
    pack PacMan = init_pakuman();

    setFantome(&F_Rouge, &F_Rose, &F_Bleu, &F_Jaune);
    setBonus(tab_2D);
    init_pakuman();
    while(NB_Vie!=0){
        SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
        clearRenderer(ren);
        depPack = Deplacement(&PacMan, tab_2D, &Score, &compteurEtat, depPack);


        // 1. Mettre à jour le tableau des fantômes pour l'IA
        ghosts[0] = F_Rouge; ghosts[1] = F_Rose; 
        ghosts[2] = F_Bleu;  ghosts[3] = F_Jaune;

    // 2. L'IA analyse la situation et choisit une action
        int s = get_state(&PacMan, tab_2D, &ghosts);
        int a = choix_action(&agent_pacman, s);
        char dir_ia = int_to_dir(a);

    // 3. Appliquer le déplacement
        Deplacement_RL(&PacMan, tab_2D, &Score, &compteurEtat, dir_ia);
        df1 = deplace_fantome(tab_2D, &PacMan, F_Rouge, &F_Rouge, &df1, &p1);
        df2 = deplace_fantome(tab_2D, &PacMan, F_Rose, &F_Rose, &df2, &p2);
        df3 = deplace_fantome(tab_2D, &PacMan, F_Bleu, &F_Bleu, &df3, &p3);
        df4 = deplace_fantome(tab_2D, &PacMan, F_Jaune, &F_Jaune, &df4, &p4);
        UpdateTab(&PacMan, &F_Rouge, &F_Rose, &F_Bleu, &F_Jaune, tab_2D);
        if(depPack != ' '){
            D_Pack = depPack;
        }
        Death(&PacMan, &F_Rouge, &F_Rose, &F_Bleu, &F_Jaune, &NB_Vie, &Score);
        adapt_Tab(tab_2D, ren, PacMan, F_Rouge, F_Rose, F_Bleu, F_Jaune, D_Pack, df1, df2, df3, df4, &NB_Vie, Score, compteurEtat);
        updateDisplay(ren);
        SDL_Delay(100);
    }
    clearRenderer(ren);
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
    char ScoreStr[12];
    snprintf(ScoreStr, sizeof(ScoreStr), "%d", Score);
    renderTexture(gameOver, ren, 0, 0, 835, 620);
    printText(360, 420, ScoreStr, 120, 60, Police, Noir, ren);
    updateDisplay(ren);
    SDL_Delay(10000);


    

}

/*
A FAIRE :
-Faire sortir les fantomes du spawn
-réussir a fixer la barre






*/