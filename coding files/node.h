//
// Created by Julien Le ber on 21/10/2022.
//
#include <stdio.h>
#ifndef PROJET_C_RANDOM_SENTENCES_NODE_H
#define PROJET_C_RANDOM_SENTENCES_NODE_H
#define max 27
struct node{
    //commmun part
    char c;
    char word[30];
    struct node* children[max];
    int sons;
    //Part Verb
    struct mot* verbe_flechie[6][6];
    //Part nom
    struct mot* nom_flechies[2];
    int gender;
    //Part adjective
    struct mot* adjective_flechies[2][2];
    //Part adverb
    int finite;
};typedef struct node* p_node;
int add_on_tree(struct node node1, char line[]);
int generate_tree();
int children_existence(struct node node1,char a);
int compare_two_char(char char1[],char char2[]);
int searching_place(struct node node1);
struct node * create_struct(char value);
#endif //PROJET_C_RANDOM_SENTENCES_NODE_H