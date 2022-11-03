//
// Created by Julien Le ber on 21/10/2022.
//
#include <stdio.h>
#include "bintree.h"
#include "node.h"
int main(){
    srand(time(NULL));
    t_tree mytree = generate_void_tree();
    generate_small_tree(mytree);
    word arr[200];
    for(int i=0;i<200;i++){
        p_node mot;
        mot = return_mot_tree(mytree);
        arr[i] = mot->mot;
    }
    int array[5];
    array[0]= array[1] = array[2] =array[3]=array[4] =0;
    for(int i=0;i<200;i++){
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