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
void generate_small_tree(t_tree);   //Creer tree de test (a delete apres)
t_tree generate_void_tree();    //Alloue la memoire d'un tree (a delete apres)
p_node return_mot_tree(t_tree); //Return un node qui constitue une fin de mot a partir du tree de maniere aleatoire
void linker(p_node node ,int cpt);  //Fonction pour créer des nodes en chaines (a delete apres)
void search_word(word,t_tree);
#endif //PROJET_C_RANDOM_SENTENCES_BINTREE_H
