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

struct list_tree{
    t_tree name_tree;
    t_tree adj_tree;
    t_tree verbe_tree;
    t_tree adv_tree;
};typedef struct list_tree* l_tree;
p_node return_mot_tree(t_tree); //Return un node qui constitue une fin de mot a partir du tree de maniere aleatoire
void conjuguer_modele1(l_tree all_tree, p_determinants det);
void conjuguer_modele2(l_tree all_tree, p_determinants det);
void conjuguer_modele3(p_pronoms pronom, l_tree all_tree, p_determinants det);
t_tree generate_void_tree();
l_tree generate_tree();
void sample(t_tree,int);
#endif //PROJET_C_RANDOM_SENTENCES_BINTREE_H
