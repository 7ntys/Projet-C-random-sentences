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
    char lyric[60];
    int iteration;
};
typedef struct mot* p_mot;
typedef struct mot word;


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
    word mot;
    struct node* children[max];
    int sons;
    //Part Verb
    word* verbe_flechie[11][6];
    //Part nom
    word* nom_flechies[2];
    int gender;
    //Part adjective
    word* adjective_flechies[2][2];
    //Part adverb
    word* adverbe_flechie;
};typedef struct node* p_node;

void intro();
void sleep(int);
p_node createNode();
p_mot create_mot();
p_determinants create_determinants();
p_pronoms create_pronoms();
word** create_conjugaison_determinants();
word* create_conjugaison_pronoms();
void fill_flechies(p_node node);

int ask_int(int bot, int top);

   

p_node return_mot_node(p_node, word);   //Return un node qui constitue une fin de mot a partir d'un node
int isempty(p_node,word);   //Verifie si le node contient des formes flechies ou non
int add_on_tree(p_node node1, char line[]);
int children_existence(p_node node1,char a);
int compare_two_char(char char1[],char char2[]);
int searching_place(p_node node1);
struct node * create_struct(char value);
p_node chain_add(p_node node, word mot,int index_mot,word typo,word fleche, word liste_typo[]);
word concatenate_mot(char line[],int x);
int take_second_word(char line[]);
int take_third_word(char line[]);
word* multiple_typo(word typo);
p_node searching(p_node node,word seached_mot,int index_mot);
#endif //PROJET_C_RANDOM_SENTENCES_NODE_H