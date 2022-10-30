//
// Created by Julien Le ber on 21/10/2022.
//
#include <stdio.h>
#include <stdlib.h>
#ifndef PROJET_C_RANDOM_SENTENCES_NODE_H
#define PROJET_C_RANDOM_SENTENCES_NODE_H
#define max 27
struct node{
    //commmun part
    char c;
    struct node* children[max];
    int sons;
    //Part Verb
    char verbe_flechie[6][6];
    //Part nom
    char nom_flechies[2];
    int gender;
    //Part adjective
    char adjective_flechies[2][2];
    //Part adverb
};typedef struct node* p_node;
p_node createNode();
void print_node(p_node);
#endif //PROJET_C_RANDOM_SENTENCES_NODE_H