//
// Created by Julien Le ber on 21/10/2022.
//

#include "bintree.h"
void generate_small_tree(t_tree mytree){
    //abat	abat	Nom:Mas+SG
    //abatage	abatage	Nom:Mas+SG
    //abatant	abatant	Nom:Mas+SG
    //abbé	abbé	Nom:Mas+SG
    printf("\nit runs \n");
    strcpy(mytree->type.lyric,"nom");
    mytree->root->c = '/';
    linker(mytree->root,7);
    mytree->root->children[0]->c = 'a';
    mytree->root->children[0]->children[0]->c = 'b';
    mytree->root->children[0]->children[0]->sons =2;
    mytree->root->children[0]->children[0]->children[0]->c = 'a';
    mytree->root->children[0]->children[0]->children[0]->children[0]->c = 't';
    strcpy(mytree->root->children[0]->children[0]->children[0]->children[0]->mot.lyric , "abat");
    strcpy(mytree->root->children[0]->children[0]->children[0]->children[0]->nom_flechies[0].lyric,"abat");
    strcpy(mytree->root->children[0]->children[0]->children[0]->children[0]->nom_flechies[1].lyric,"abat");
    mytree->root->children[0]->children[0]->children[0]->children[0]->children[0]->c = 'a';
    mytree->root->children[0]->children[0]->children[0]->children[0]->children[0]->children[0]->c = 'g';
    mytree->root->children[0]->children[0]->children[0]->children[0]->children[0]->children[0]->children[0]->c = 'e';
    mytree->root->children[0]->children[0]->children[0]->children[0]->children[0]->children[0]->children[0]->sons=0;
    strcpy(mytree->root->children[0]->children[0]->children[0]->children[0]->children[0]->children[0]->children[0]->mot.lyric, "abatage");
    strcpy(mytree->root->children[0]->children[0]->children[0]->children[0]->children[0]->children[0]->children[0]->nom_flechies[0].lyric, "abatage");
    strcpy(mytree->root->children[0]->children[0]->children[0]->children[0]->children[0]->children[0]->children[0]->nom_flechies[1].lyric, "abatage");
    mytree->root->children[0]->children[0]->children[1]=createNode();
    mytree->root->children[0]->children[0]->children[1]->sons=1;
    mytree->root->children[0]->children[0]->sons=2;
    mytree->root->children[0]->children[0]->children[1]->children[0]=createNode();
    mytree->root->children[0]->children[0]->children[1]->children[0]->sons=1;
    mytree->root->children[0]->children[0]->children[1]->c = 'b';
    mytree->root->children[0]->children[0]->children[1]->children[0]->c = 'e';
    linker(mytree->root->children[0]->children[0]->children[1]->children[0],3);
    mytree->root->children[0]->children[0]->children[1]->children[0]->children[0]->c ='s';
    mytree->root->children[0]->children[0]->children[1]->children[0]->children[0]->children[0]->c ='s';
    mytree->root->children[0]->children[0]->children[1]->children[0]->children[0]->children[0]->children[0]->c ='e';
    mytree->root->children[0]->children[0]->children[1]->children[0]->children[0]->children[0]->children[0]->sons=0;
    strcpy(mytree->root->children[0]->children[0]->children[1]->children[0]->children[0]->children[0]->children[0]->nom_flechies[0].lyric,"abbesse");
    strcpy(mytree->root->children[0]->children[0]->children[1]->children[0]->children[0]->children[0]->children[0]->nom_flechies[1].lyric,"abbesse");
    strcpy(mytree->root->children[0]->children[0]->children[1]->children[0]->children[0]->children[0]->children[0]->mot.lyric,"abbesse");
    mytree->root->children[0]->children[0]->children[1]->children[0]->sons=1;
    strcpy(mytree->root->children[0]->children[0]->children[1]->children[0]->mot.lyric,"abbe");
    strcpy(mytree->root->children[0]->children[0]->children[1]->children[0]->nom_flechies[0].lyric,"abbe");
    strcpy(mytree->root->children[0]->children[0]->children[1]->children[0]->nom_flechies[1].lyric,"abbe");
    mytree->root->children[0]->children[0]->children[0]->children[0]->children[1] = createNode();
    mytree->root->children[0]->children[0]->children[0]->children[0]->sons=2;
    mytree->root->children[0]->children[0]->children[0]->children[0]->children[1]->sons=1;
    mytree->root->children[0]->children[0]->children[0]->children[0]->children[1]->c = 'n';
    mytree->root->children[0]->children[0]->children[0]->children[0]->children[1]->children[0] = createNode();
    mytree->root->children[0]->children[0]->children[0]->children[0]->children[1]->children[0]->sons=1;
    mytree->root->children[0]->children[0]->children[0]->children[0]->children[1]->children[0]->c = 't';
    mytree->root->children[0]->children[0]->children[0]->children[0]->children[1]->children[0]->sons = 0;
    strcpy(mytree->root->children[0]->children[0]->children[0]->children[0]->children[1]->children[0]->mot.lyric,"abatant");
    strcpy(mytree->root->children[0]->children[0]->children[0]->children[0]->children[1]->children[0]->nom_flechies[0].lyric,"abatant");
    strcpy(mytree->root->children[0]->children[0]->children[0]->children[0]->children[1]->children[0]->nom_flechies[1].lyric,"abatant");
    printf("its ok");
}
t_tree generate_void_tree(){
    t_tree mytree = (t_tree)malloc(sizeof (t_tree));
    mytree->root = createNode();
    return mytree;
}
p_node return_mot_tree(t_tree mytree){
    if(mytree->root != NULL){
        return return_mot_node(mytree->root->children[0], mytree->type);
    }
    else{
        return NULL;
    }
}
void linker(p_node node ,int cpt){
    if(cpt==0){
        return;
    }
    else{
        p_node temp = createNode();
        node->children[0] = temp;
        node->sons =1;
        linker(node->children[0],cpt-1);
        return;
    }
}