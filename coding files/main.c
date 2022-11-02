//
// Created by Julien Le ber on 21/10/2022.
//
#include <stdio.h>
#include "bintree.h"
#include "node.h"
int main(){
    printf("Hello world");
    srand(time(NULL));
    t_tree mytree = generate_void_tree();
    generate_small_tree(mytree);
    printf("yeyy\n");
    printf("%c\n",mytree->root->children[0]->children[0]->children[0]->children[0]->children[1]->children[0]->c);
    printf("%s\n",mytree->root->children[0]->children[0]->children[0]->children[0]->children[1]->children[0]->nom_flechies[0].lyric);
    word arr[200];
    for(int i=0;i<200;i++){
        p_node mot;
        mot = return_mot_tree(mytree);
        printf("\n%s\n",mot->mot.lyric);
        arr[i] = mot->mot;
    }
    int array[5];
    array[0]= array[1] = array[2] =array[3]=array[4] =0;
    for(int i=0;i<200;i++){
        printf("\n %s",arr[i].lyric);
        if(strcmp(arr[i].lyric,"abbe") == 0){
            array[0] +=1;
        }
        else if(strcmp(arr[i].lyric,"abatage") == 0){
            array[1]+=1;
        }
        else if(strcmp(arr[i].lyric,"abatant") == 0){
            array[2] +=1;
        }
        else if(strcmp(arr[i].lyric,"abat") == 0){
            array[3] +=1;
        }
        else if(strcmp(arr[i].lyric,"abbesse") == 0){
            array[4] +=1;
        }
    }
    printf("\nabbe : %d ; abatage : %d ; abatant : %d ; abat : %d ; abbesse : %d", array[0],array[1],array[2],array[3],array[4]);
    return 0;
};