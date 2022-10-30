//
// Created by Julien Le ber on 21/10/2022.
//
#include <stdio.h>
#include "bintree.h"
#include "node.h"
int main(){
    printf("Hello world");
    t_tree mytree = generate_void_tree();
    generate_small_tree(mytree);
    print_tree(mytree);
    return 0;
};