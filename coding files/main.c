//
// Created by Julien Le ber on 21/10/2022.
//
#include <stdio.h>
#include "bintree.h"
#include "node.h"


int main(){
    printf("It runs \n\n");
    p_node verbe = create_conjugaison_verbes();
    p_node verbe2 = create_conjugaison_verbes2();
    p_node nom1 = create_conjugaison_noms();
    p_node nom2 = create_conjugaison_noms2();
    p_node adjectif = create_conjugaison_adjectifs();
    p_node adjectif2 = create_conjugaison_adjectifs2();
    p_node adverbe = create_conjugaison_adverbe();
    p_determinants det = create_conjugaison_determinants();
    p_pronoms pro = create_conjugaison_pronoms();
    int stop;
    do{
        int option;
        printf("Choississez un modèle de conjugaison parmi les suivants : \n\nModèle n°1 : nom - adjectif - verbe - nom\n\nModèle n°2 : nom - 'qui' - verbe - verbe - nom - adjectif\n\nModèle n°3 : verbe - adverbe - nom - adjectif \n\n");
        option = ask_int(1, 3);
        printf("\n\n");
        switch (option) {
            case 1: conjuguer_modele1(nom1,adjectif,verbe,nom2, det);
                break;
            case 2: conjuguer_modele2(nom2, verbe2, verbe, nom1, adjectif, det);
                break;
            case 3: conjuguer_modele3(pro, verbe2, adverbe, nom1, adjectif2, det);
                break;
            default : printf("Ce choix n'existe pas.\n");
        }
        printf("\n\n");
        printf("Do you want to continue ? \n\n0 - No\n1 - Yes\n\n");
        stop = ask_int(0, 1);
        printf("\n\n");
    }while(stop!=0);




    return 0;
}