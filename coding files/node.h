//
// Created by Julien Le ber on 21/10/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "time.h"
#ifndef PROJET_C_RANDOM_SENTENCES_NODE_H
#define PROJET_C_RANDOM_SENTENCES_NODE_H
#define max 27
struct mot{
    char lyric[30];
};
typedef struct mot* p_mot;

struct pronoms{
    p_mot pronoms[6];
};
typedef struct pronoms* p_pronoms;

struct determinants{
    p_mot determinants[2][3];
};
typedef struct determinants* p_determinants;

struct node{
    //commmun part
    char c;
    char word[30];
    struct node* children[max];
    int sons;
    //Part Verb
    p_mot verbe_flechie[3][6];
    //Part nom
    p_mot nom_flechies[2];
    int gender;
    //Part adjective
    p_mot adjective_flechies[2][2];
    //Part adverb
    p_mot adverbe_flechies;
    int finite;
};
typedef struct node* p_node;

p_node createNode();
p_mot create_mot();
p_determinants create_determinants();
p_pronoms create_pronoms();
p_node create_conjugaison_verbes();
p_node create_conjugaison_verbes2();
p_node create_conjugaison_noms();
p_node create_conjugaison_noms2();
p_node create_conjugaison_adjectifs();
p_node create_conjugaison_adjectifs2();
p_node create_conjugaison_adverbe();
p_determinants create_conjugaison_determinants();
p_pronoms create_conjugaison_pronoms();
void conjuguer_modele1(p_node ,p_node , p_node , p_node , p_determinants );
void conjuguer_modele2(p_node ,p_node , p_node , p_node , p_node , p_determinants );
void conjuguer_modele3(p_pronoms , p_node , p_node , p_node , p_node , p_determinants);
int ask_int(int bot, int top);
#endif //PROJET_C_RANDOM_SENTENCES_NODE_H