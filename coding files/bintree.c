//
// Created by Julien Le ber on 21/10/2022.
//
#include "node.h"
#include "bintree.h"

t_tree generate_void_tree(){    //Créer un tree vide
    t_tree mytree = (t_tree)malloc(sizeof (t_tree));
    mytree->root = create_struct('/');
    return mytree;
}