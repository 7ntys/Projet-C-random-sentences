//
// Created by Julien Le ber on 21/10/2022.
//
#include <stdio.h>
#include "bintree.h"
#include "node.h"
int main(){
    srand(time(NULL));
    t_tree a = generate_tree("Nom:");
    strcpy(a->type.lyric,"nom");
    p_node test;
    test = (p_node)malloc(sizeof (struct node));
    test = return_mot_tree(a);
    sample(a,500);
    return 0;
};