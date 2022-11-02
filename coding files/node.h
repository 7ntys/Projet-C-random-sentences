//
// Created by Julien Le ber on 21/10/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "string.h"
#ifndef PROJET_C_RANDOM_SENTENCES_NODE_H
#define PROJET_C_RANDOM_SENTENCES_NODE_H
#define max 27
struct mot{
    char lyric[30];
};typedef struct mot word;
struct node{
    //commmun part
    char c;
    word mot;
    struct node* children[max];
    int sons;
    //Part Verb
    word verbe_flechie[6][6];
    //Part nom
    word nom_flechies[2];
    int gender;
    //Part adjective
    word adjective_flechies[2][2];
    //Part adverb
    word adverbe_flechie;
};typedef struct node* p_node;
p_node createNode();    //Créer un node et alloue la mémoire (a delete apres)
p_node return_mot_node(p_node, word);   //Return un node qui constitue une fin de mot a partir d'un node
int isempty(p_node,word);   //Verifie si le node contient des formes flechies ou non
#endif //PROJET_C_RANDOM_SENTENCES_NODE_H