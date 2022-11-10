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
    printf("JJJ");
    test = return_mot_tree(a);
    printf("okokok");
    printf("test essayer le mot là %c",test->c);
    return 0;
};