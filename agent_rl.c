#include "agent_rl.h"
#include "ressources.h"
#include "map.h"
#include <string.h>
#include <stdio.h>
# include "pack.h"

 //float q_table[4096][4] = {0};   // etat coder sur 12 bits, alors on a 2^12 = 4096 et 4 pour les quatres actions, tableaux avec les scores des actions en fonctions des etats 
const int MAP_INITIALE[HAUT][LARG]= { 
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

int get_state(pack *p ,int t[HAUT][LARG] , Ghost ghost[4]){
    int state = 0 ;
    int X = p->x ; 
    int Y = p->y ; 

    ///MUR
    if(t[Y-1 ][X] == 1 ) state |= (1<<0); // nord 
    if(t[Y+1] [X] == 1 ) state |= (1<<1); // sud 
    if(t[Y][X-1] == 1) state |= (1<<2) ;  // ouest
    if(t[Y][X+1] == 1 ) state |= (1<<3); // Est

    //Fantome le plus proche
    int dist_g = 999;
    int g_proche = 0;

    for(int i =0 ; i<4 ; i++){
        int d = abs(X - ghost[i].x) + abs(Y - ghost[i].y);
        if (d<dist_g){
            dist_g = d;
            g_proche = i ;
        } 
    }

    // poze du fantome : sur 4bit aussi 
    if(ghost[g_proche].y< Y ){ // au dessus (NORD)
        state|= (1<<4);
    }else if (ghost[g_proche].y> Y){// sud
        state|=(1<<5);
    }

    if(ghost[g_proche].x > X){ // il est a droite
        state|=(1<<6);
    }else if (ghost[g_proche].x < X){ // a guauche 
        state |= (1<<7); 
   }

    // Bits 8-11 : CIBLE PRIORITAIRE (Cerise > Big Gum > Gum)
    int target_x = X, target_y = Y, dist_target = 999;
    int types[] = {3, 2, 0}; // Priorités
    int found = 0;

    for(int k = 0; k < 3 && !found; k++) {
        for(int i = 0; i < HAUT; i++) {
            for(int j = 0; j < LARG; j++) {
                if(t[i][j] == types[k]) {
                    int d = abs(X - j) + abs(Y - i);
                    if(d < dist_target) {
                        dist_target = d;
                        target_x = j; target_y = i;
                        found = 1;
                    }
                }
            }
        }
    }

    if(found) {
        if(target_y < Y) state |= (1 << 8);
        if(target_y > Y) state |= (1 << 9);
        if(target_x < X) state |= (1 << 10);
        if(target_x > X) state |= (1 << 11);
    }

    return state ; 
}
/*
on utilise la fonction de bellman jsp quoi et on introduit les constantes suivantes : 
    α (Alpha) : Taux d'apprentissage (0.1). Détermine à quel point les nouvelles informations écrasent les anciennes.

    γ (Gamma) : Facteur de remise (0.9). Détermine l'importance des récompenses futures.

    ϵ (Epsilon) : Taux d'exploration. Probabilité de choisir une action au hasard.
    Q(s,a)←Q(s,a)+α[r+γ  maxQ(s',a)−Q(s,a)]
*/

float get_reward(pack *p, int t[HAUT][LARG], Ghost ghost[4], int old_vie, int old_score) {
    if (p->vie < old_vie) return -500.0f;
    int diff = p->point - old_score ; 
    if (diff >0) {

        if (diff >= 100){
            return (float)150.0f;
        }
        return 20.0f;
    }
    int cell = t[p->y][p->x];
    if (cell == 3) return 100.0f;  // Cerise
    if(cell == 4 ) return -2.0f ;

    // 4. PENALITE DE TEMPS : Pour chaque mouvement "vide"
    return -1.0f;
}


void update_q_table(QAgent *agent ,int s , int a , int s_next , float reward){
    float max_q_next = agent->q_table[s_next][0];
    for(int i =0; i<NOMBRE_ACTION ; i++){
        if(agent->q_table[s_next][i] > max_q_next){
            max_q_next = agent->q_table[s_next][i];
        }
    }

    float Q = agent->q_table[s][a];

    agent->q_table[s][a] = Q + agent->alpha* (reward + agent->gamma*max_q_next - Q); 
}

int choix_action(QAgent *agent , int state){
    float r = (float)rand() / (float)RAND_MAX;
    // rand() genere un nombre entier pseudo-aleatoir entre 0 et RAND_MAX
    if(r<agent->epsilon){
        return (rand()%NOMBRE_ACTION);
    }

    float best_q = agent->q_table[state][0] ; 
    int best_a = 0;
    for(int i= 0; i<NOMBRE_ACTION;i++ ){
        if(best_q < agent->q_table[state][i]){
            best_q =agent->q_table[state][i];
            best_a = i;
        }
    }
    return best_a;
}


char int_to_dir(int action) {
    if (action == 0) return 'h';
    if (action == 1) return 'b';
    if (action == 2) return 'g';
    if (action == 3) return 'd';
    return ' ';
}

void reset_env(pack *P, Ghost ghost[4], int *score, int *vie, int *compt) {
    memcpy(tab_2D, MAP_INITIALE, sizeof(tab_2D)) ;
    ghost[0] = initGhost(100);
    ghost[1] = initGhost(110);
    ghost[2] = initGhost(120);
    ghost[3] = initGhost(130);
    setFantome(&ghost[0],&ghost[1],&ghost[2],&ghost[3]);
    *P = init_pakuman(); 
    *score = 0;
    *vie = 3 ; 
    *compt = 0 ; 
}



void train(QAgent *agent , int epochs){
    pack p ; 
    Ghost ghost[4] ;
    int score, vie , compt ; 
    char df[4] = {'x' , 'x' , 'x' , 'x'};
    int ps[4] = {0,0,0,0}; 
    int total_score = 0 ;
    const int MAX_STEP = 2000;
    for (int e  = 0 ; e < epochs ; e++){
        reset_env(&p ,ghost ,&score ,&vie, &compt) ; 
        int s = get_state( &p, tab_2D , ghost);
        
        int steps= 0 ; 
        while (vie > 0 && steps<MAX_STEP)
        {
            int a = choix_action(agent , s); 
            char dir = int_to_dir(a);

            int s_old = score;
            int v_old = vie;

            char d = Deplacement_RL(&p,tab_2D,&score,&compt,dir);
            for(int i =0 ; i<4 ; i++ ){
                deplace_fantome_aleatoire(tab_2D, &ghost[i], &df[i], &ps[i]);
            }

            Death(&p, &ghost[0], &ghost[1], &ghost[2], &ghost[3], &vie , &score);
            UpdateTab(&p, &ghost[0], &ghost[1], &ghost[2], &ghost[3], tab_2D);
            
            int s_next = get_state(&p,tab_2D,ghost);
            float r = get_reward(&p , tab_2D , ghost, v_old ,s_old); 

            update_q_table(agent,s,a,s_next,r); 
            s = s_next;
            steps++ ;
        }
        total_score += score; 
        if (e % 100 == 0) {
            float progress = (float)e / epochs;
            int barWidth = 30;
            
            printf("\r[");
            int pos = barWidth * progress;
            for (int i = 0; i < barWidth; ++i) {
                if (i < pos) printf("=");
                else if (i == pos) printf(">");
                else printf(" ");
            }
            printf("] %d%% | Ep: %d | Eps: %.3f | Score Moy: %d", 
                   (int)(progress * 100), e, agent->epsilon, total_score / (e + 1));
            
            fflush(stdout); // Force l'affichage immédiat sur le terminal
        }
        
        //if (agent->epsilon > 0.05f) agent->epsilon *= 0.999f;


    }
}



//suite je savais pas faire donc je fais confiance au code de gemini (le boss ): En gros c'est pour charger la q table dans un fichier .dot puis pour pouvoir la charger apres dans le main 




void save_q_table(QAgent *agent, const char *filename) {
    FILE *fichier = fopen(filename, "wb"); // "wb" pour write binary
    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier pour sauvegarder.\n");
        return;
    }

    // On écrit tout le tableau d'un coup
    size_t elements_ecrits = fwrite(agent->q_table, sizeof(float), NOMBRE_ETAT * NOMBRE_ACTION, fichier);

    if (elements_ecrits == NOMBRE_ETAT * NOMBRE_ACTION) {
        printf("Intelligence sauvegardée avec succès dans %s.\n", filename);
    } else {
        printf("Erreur lors de l'écriture de la sauvegarde.\n");
    }

    fclose(fichier);
}

void load_q_table(QAgent *agent, const char *filename) {
    FILE *fichier = fopen(filename, "rb"); // "rb" pour read binary
    if (fichier == NULL) {
        printf("Aucune sauvegarde trouvée (%s). L'agent part de zéro.\n", filename);
        return;
    }

    // On lit le tableau complet
    size_t elements_lus = fread(agent->q_table, sizeof(float), NOMBRE_ETAT * NOMBRE_ACTION, fichier);

    if (elements_lus == NOMBRE_ETAT * NOMBRE_ACTION) {
        printf("Intelligence chargée avec succès depuis %s.\n", filename);
    } else {
        printf("Erreur : Le fichier de sauvegarde est corrompu ou incomplet.\n");
    }

    fclose(fichier);
}