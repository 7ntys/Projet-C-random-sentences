//
// Created by Julien Le ber on 21/10/2022.
//
#include <stdio.h>
#include "bintree.h"
#include "node.h"
int main(){
    srand(time(NULL));
    l_tree all_tree = generate_tree();
    //strcpy(a->type.lyric,"nom");
    p_node test;
    test = (p_node)malloc(sizeof (struct node));
    test = return_mot_tree(all_tree->adj_tree);
    printf("test essayer le mot là %s",test->mot.lyric);
    return 0;
};