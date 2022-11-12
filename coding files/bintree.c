//
// Created by Julien Le ber on 21/10/2022.
//
#include "bintree.h"

t_tree generate_void_tree(){    //Créer un tree vide
    t_tree mytree = (t_tree)malloc(sizeof (struct tree));
    mytree->root = create_struct('/');
    return mytree;
}
p_node return_mot_tree(t_tree mytree){  //inite la recursion a partir du tree
    if(mytree->root != NULL){
        return return_mot_node(mytree->root, mytree->type);
    }
    else{
        return NULL;
    }
}
void sample(t_tree mytree,int nbr){
    word* arr = (word*)malloc(nbr*sizeof (word));
    int cpt =0;
    printf("--\n\n");
    for(int i=0;i<nbr;i++){
        p_node temp = (p_node)malloc(sizeof (struct node));
        temp = return_mot_tree(mytree);
        for(int j=0;j<nbr;j++){
            if(strcmp(arr[j].lyric,temp->mot.lyric) == 0){
                arr[j].iteration++;
                cpt=1;
            }
        }
        if(cpt==0){
            arr[i] = temp->mot;
            arr[i].iteration=1;
        }
        cpt = 0;
    }
    for(int i=0;i<nbr;i++){
        if(arr[i].iteration != 0){
            printf("%s : %d / ",arr[i].lyric,arr[i].iteration);
        }
    }
}