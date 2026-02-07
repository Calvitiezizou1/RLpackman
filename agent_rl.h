#ifndef AGENT_RL_H
#define AGENT_RL_H

#include <stdlib.h>

#define NOMBRE_ACTION 4
#define NOMBRE_ETAT 4096

#include "agent_rl.h"
#include "ressources.h"
#include "map.h"
#include <string.h>
#include <stdio.h>
# include "pack.h"
# include "ghosts.h"


typedef struct {
    float q_table[NOMBRE_ETAT][NOMBRE_ACTION];
    float epsilon ;
    float gamma ;
    float alpha;
}QAgent;



int get_state(pack *p ,int t[HAUT][LARG] , Ghost ghost[4]);
float get_reward(pack *p, int t[HAUT][LARG], Ghost ghost[4], int old_vie, int old_score) ;
void update_q_table(QAgent *agent ,int s , int a , int s_next , float reward);
int choix_action(QAgent *agent , int state);
char int_to_dir(int action) ;
void reset_env(pack *P, Ghost ghost[4], int *score, int *vie, int *compt);
void train(QAgent *agent , int epochs);
void save_q_table(QAgent *agent, const char *filename);
void load_q_table(QAgent *agent, const char *filename);

#endif
