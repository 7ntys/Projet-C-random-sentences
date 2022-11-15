//
// Created by Julien Le ber on 21/10/2022.
//
#include <stdio.h>
#include "bintree.h"
#include "node.h"


int main(){
    srand(time(NULL));
    l_tree all_tree = (l_tree)malloc(sizeof (struct list_tree));
    all_tree = generate_tree();
    strcpy(all_tree->adj_tree->type.lyric,"adjectif");
    //strcpy(a->type.lyric,"nom");
    p_node test;
    test = (p_node)malloc(sizeof (struct node));
    test = return_mot_tree(all_tree->adv_tree);
    //sample(all_tree->adv_tree,500);
    //sample(all_tree->name_tree,500);
    sample(all_tree->adj_tree,500);
    //sample(all_tree->verbe_tree,500);
    p_determinants det = create_conjugaison_determinants();
    p_pronoms pro = create_conjugaison_pronoms();
    int stop;
    do{
        int option;
        printf("Choississez un modèle de conjugaison parmi les suivants : \n\nModèle n°1 : nom - adjectif - verbe - nom\n\nModèle n°2 : nom - 'qui' - verbe - verbe - nom - adjectif\n\nModèle n°3 : verbe - adverbe - nom - adjectif \n\n");
        option = ask_int(1, 3);
        printf("\n\n");
        switch (option) {
            case 1: conjuguer_modele1(all_tree, det);
                break;
            case 2: conjuguer_modele2(all_tree, det);
                break;
            case 3: conjuguer_modele3(pro, all_tree, det);
                break;
            default : printf("Ce choix n'existe pas.\n");
        }
        printf("\n\n------------------------------------------------------------------------------\n\n");
        printf("Do you want to continue ? \n\n0 - No\n1 - Yes\n\n");
        stop = ask_int(0, 1);
        printf("\n\n------------------------------------------------------------------------------\n\n");
    }while(stop!=0);



    free(all_tree);
    free(test);

    return 0;
}