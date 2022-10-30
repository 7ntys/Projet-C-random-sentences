//
// Created by Julien Le ber on 21/10/2022.
//

#include "bintree.h"
void generate_small_tree(t_tree mytree){
    //abat	abat	Nom:Mas+SG
    //abatage	abatage	Nom:Mas+SG
    //abatant	abatant	Nom:Mas+SG
    //abattoir	abattoir	Nom:Mas+SG
    //abbé	abbé	Nom:Mas+SG
    printf("\n it runs ");
    mytree->root->c =  '/';
    //create childrens
    p_node child_a = createNode();
    p_node child_b = createNode();
    p_node child_a_2 = createNode();
    p_node child_t = createNode();
    printf("pp");
    //Put the character
    child_a->c ='a';
    child_b->c = 'b';
    child_a_2->c = 'a';
    child_t->c = 't';
    //link childrens
    printf("%c", mytree->root->c);
    mytree->root->children[0] = child_a;
    //division abbé :
    p_node child_b_2, child_e_2, child_e_3;
    child_b_2 = createNode();
    child_e_2 = createNode();
    child_e_3 = createNode();
    child_b_2->c = 'b';
    child_e_2->c ='e';
    child_e_3->c ='e';
    child_b->children[1] = child_b_2;
    child_b_2->children[0] = child_e_2;
    child_e_2->children[0] = child_e_3;
    child_a->children[0] = child_b;
    child_b->children[0] = child_a_2;
    child_a_2->children[0] = child_t;
    //division of tree vers abatage
    p_node child_a_3 = createNode();
    child_a_3->c = 'a';
    child_t->children[0] = child_a_3;
    p_node child_g = createNode();
    child_g ->c= 'g';
    child_a_3->children[0] = child_g;
    p_node child_e = createNode();
    child_e->c ='e';
    child_g->children[0] = child_e;
    //division vers abatant
    p_node child_n = createNode();
    child_n->c = 'n';
    child_a_3->children[1] = child_n;
    p_node child_t_2 = createNode();
    child_t_2->c ='t';
    child_n->children[0] = child_t_2;
    //division vers abattoir
}
t_tree generate_void_tree(){
    t_tree mytree = (t_tree)malloc(sizeof (t_tree));
    mytree->root = createNode();
    return mytree;
}
void print_tree(t_tree mytree){
    print_node(mytree->root);
}
