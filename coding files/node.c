//
// Created by Julien Le ber on 21/10/2022.
//

#include "node.h"
// creation de formes flechies en dur

p_node createNode(){
    p_node node = (p_node) malloc((sizeof (p_node)));
    for(int i =0;i<=3;i++){
        for (int j=0;j<=6;j++){
            node->verbe_flechie[i][j] = (p_mot) malloc((sizeof (p_mot)));
            node->verbe_flechie[i][j] = NULL;
        }
    }
    for(int i =0;i<=2;i++){
        node->nom_flechies[i] =(p_mot) malloc((sizeof (p_mot)));
        node->nom_flechies[i] = NULL;
    }
    for(int i =0;i<=2;i++){
        for (int j=0;j<=2;j++){
            node->adjective_flechies[i][j] = (p_mot) malloc((sizeof (p_mot)));
            node->adjective_flechies[i][j] = NULL;
        }
    }

    return node;
}

p_mot create_mot(){
    p_mot nouv_mot=(p_mot) malloc((sizeof (p_mot)));
    for(int i =0;i<=30;i++) {
        nouv_mot->mot[i] = (p_mot) malloc((sizeof(p_mot)));
        nouv_mot->mot[i] = '\0';
    }
    return nouv_mot;
}


void create_conjugaison_verbes(){
    p_mot mot1=create_mot();
    strcpy(mot1->mot,"mange");
    p_mot mot2=create_mot();
    strcpy(mot2->mot,"manges");
    p_mot mot3=create_mot();
    strcpy(mot3->mot,"mange");
    p_mot mot4=create_mot();
    strcpy(mot4->mot,"mangeons");
    p_mot mot5=create_mot();
    strcpy(mot5->mot,"mangez");
    p_mot mot6=create_mot();
    strcpy(mot6->mot,"mangent");
    p_mot mot7=create_mot();
    strcpy(mot7->mot,"mangeais");
    p_mot mot8=create_mot();
    strcpy(mot8->mot,"mangeais");
    p_mot mot9=create_mot();
    strcpy(mot9->mot,"mangeait");
    p_mot mot10=create_mot();
    strcpy(mot10->mot,"mangions");
    p_mot mot11=create_mot();
    strcpy(mot11->mot,"mangiez");
    p_mot mot12=create_mot();
    strcpy(mot12->mot,"mangeaient");
    p_mot mot13=create_mot();
    strcpy(mot13->mot,"mange");
    p_mot mot14=create_mot();
    strcpy(mot14->mot,"manges");
    p_mot mot15=create_mot();
    strcpy(mot15->mot,"mange");
    p_mot mot16=create_mot();
    strcpy(mot16->mot,"mangions");
    p_mot mot17=create_mot();
    strcpy(mot17->mot,"mangiez");
    p_mot mot18=create_mot();
    strcpy(mot18->mot,"mangent");

    p_node verbe = createNode();
    verbe->verbe_flechie[0][0]=mot1 , verbe->verbe_flechie[0][1]=mot2,verbe->verbe_flechie[0][2]=mot3,
    verbe->verbe_flechie[0][3]=mot4, verbe->verbe_flechie[0][4]=mot5, verbe->verbe_flechie[0][5]=mot6,

    verbe->verbe_flechie[1][0]=mot7 , verbe->verbe_flechie[1][1]=mot8,verbe->verbe_flechie[1][2]=mot9,
    verbe->verbe_flechie[1][3]=mot10, verbe->verbe_flechie[1][4]=mot11, verbe->verbe_flechie[1][5]=mot12,

    verbe->verbe_flechie[2][0]=mot13 , verbe->verbe_flechie[2][1]=mot14,verbe->verbe_flechie[2][2]=mot15,
    verbe->verbe_flechie[2][3]=mot16, verbe->verbe_flechie[2][4]=mot17, verbe->verbe_flechie[2][5]=mot18;

    for (int i=1;i<=3;i++){
        for (int j=1;j<=6;j++){
            printf("%s ",verbe->verbe_flechie[i-1][j-1]);
        }
        printf("\n");
    }
    printf("\n");

}

void create_conjugaison_noms(){
    p_mot mot1=create_mot();
    strcpy(mot1->mot,"bateau");

    p_node nom = createNode();
    nom->nom_flechies[0]=mot1;

    printf("%s\n\n",nom->nom_flechies[0]);

}

void create_conjugaison_adjectifs(){
    p_mot mot1=create_mot();
    strcpy(mot1->mot,"petit");
    p_mot mot2=create_mot();
    strcpy(mot2->mot,"petits");
    p_mot mot3=create_mot();
    strcpy(mot3->mot,"petite");
    p_mot mot4=create_mot();
    strcpy(mot4->mot,"petites");

    p_node adjectif = createNode();
    adjectif->adjective_flechies[0][0]=mot1 , adjectif->adjective_flechies[0][1]=mot2,
    adjectif->adjective_flechies[1][0]=mot3 , adjectif->adjective_flechies[1][1]=mot4;

    for (int i=1;i<=2;i++){
        for (int j=1;j<=2;j++){
            printf("%s ",adjectif->adjective_flechies[i-1][j-1]);
        }
        printf("\n");
    }
    printf("\n");
}

void create_conjugaison_adverbe(){
    p_mot mot1=create_mot();
    strcpy(mot1->mot,"absolument");

    p_node adverbe = createNode();
    adverbe->adverbe_flechies[0]=mot1;

    printf("%s\n\n",adverbe->adverbe_flechies[0]);
}






