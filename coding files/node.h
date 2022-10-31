//
// Created by Julien Le ber on 21/10/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#ifndef PROJET_C_RANDOM_SENTENCES_NODE_H
#define PROJET_C_RANDOM_SENTENCES_NODE_H
#define max 27
struct mot{
    char mot[30];
};
typedef struct mot* p_mot;

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
    p_mot adverbe_flechies[1];
    int finite;
};
typedef struct node* p_node;

p_node createNode();
p_mot create_mot();
void create_conjugaison_verbes();
void create_conjugaison_noms();
void create_conjugaison_adjectifs();
void create_conjugaison_adverbe();
#endif //PROJET_C_RANDOM_SENTENCES_NODE_H