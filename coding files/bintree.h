//
// Created by Julien Le ber on 21/10/2022.
//
#include "node.h"
#ifndef PROJET_C_RANDOM_SENTENCES_BINTREE_H
#define PROJET_C_RANDOM_SENTENCES_BINTREE_H
struct tree{
    p_node root;
};typedef struct tree* t_tree;
void generate_small_tree(t_tree);
t_tree generate_void_tree();
void print_tree(t_tree);
#endif //PROJET_C_RANDOM_SENTENCES_BINTREE_H
