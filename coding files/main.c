
// Created by Julien Le ber on 21/10/2022.
//
#include <stdio.h>
#include "bintree.h"
#include "node.h"



int main(){
    srand(time(NULL));
    intro();
    l_tree all_tree = (l_tree)malloc(sizeof (struct list_tree));
    all_tree = generate_tree();
    strcpy(all_tree->adj_tree->type.lyric,"adjectif");
    strcpy(all_tree->name_tree->type.lyric,"nom");
    strcpy(all_tree->verbe_tree->type.lyric,"verbe");
    strcpy(all_tree->adv_tree->type.lyric,"adverbe");
    //strcpy(a->type.lyric,"nom");
    p_node test;
    test = (p_node)malloc(sizeof (struct node));
    test = return_mot_tree(all_tree->verbe_tree);
    //sample(all_tree->adv_tree,500);
    //sample(all_tree->name_tree,500);
    //sample(all_tree->adj_tree,50);
    //sample(all_tree->verbe_tree,50);
    word** det = create_conjugaison_determinants();
    word* pro = create_conjugaison_pronoms();

    printf("\n\n------------------------------------------------------------------------------\n\n");
    int stop;
    do{
        int option;

        printf("Choississez un modele de conjugaison parmi les suivants : \n\nModele numero 1 : nom - adjectif - verbe - nom\n\nModele numero2 : nom - 'qui' - verbe - verbe - nom - adjectif\n\nModele numero 3 : verbe - adverbe - nom - adjectif \n\nOption numero 4 : Chercher un mot dans le tree\n\n");
        option = ask_int(1, 4);
        printf("\n\n");
        switch (option) {
            case 1:conjuguer_modele1(all_tree, det);
                break;
            case 2: conjuguer_modele2(all_tree, det);
                break;
            case 3: conjuguer_modele3(pro, all_tree, det);
                break;
            case 4:
                printf("Entrez le mot que vous voulez : ");
                word searched_mot;
                scanf("%s",searched_mot.lyric);
                search_word(searched_mot,all_tree->name_tree);
                break;
            default : printf("Ce choix n'existe pas.\n");
        }
        printf("\n\n------------------------------------------------------------------------------\n\n");
        //conjuguer_modele2(all_tree, det);
        //conjuguer_modele3(pro, all_tree, det);
        printf("Voulez vous continuer ? \n\n0 - Non\n1 - Oui\n\n");
        stop = ask_int(0, 1);
        printf("\n\n------------------------------------------------------------------------------\n\n");
    }while(stop!=0);



    free(all_tree);
    free(test);
    free(det);
    free(pro);

    return 0;
}