//
// Created by Julien Le ber on 21/10/2022.
//

#include "node.h"
p_node createNode(){
    p_node node = (p_node) malloc((sizeof (p_node)));
    for(int i =0;i<=max;i++){
        node->children[i] = (p_node) malloc((sizeof (p_node)));
        node->children[i] = NULL;
    }
    return node;
}
void print_node(p_node node){
    if(node!=NULL){
        printf(" %c ", node->c);
        for(int i =0;i<=max;i++){
            print_node(node->children[i]);
        }
        printf("->");
    }
    else{
        return;
    }
}