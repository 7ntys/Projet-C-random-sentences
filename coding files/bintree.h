//
// Created by Julien Le ber on 21/10/2022.
//
#include "node.h"
#ifndef PROJET_C_RANDOM_SENTENCES_BINTREE_H
#define PROJET_C_RANDOM_SENTENCES_BINTREE_H
struct tree{
    p_node root;
    word type;
};typedef struct tree* t_tree;
p_node return_mot_tree(t_tree); //Return un node qui constitue une fin de mot a partir du tree de maniere aleatoire
#endif //PROJET_C_RANDOM_SENTENCES_BINTREE_H
