//
// Created by Julien Le ber on 21/10/2022.
//

#include "bintree.h"
#define MAX_LINE_LENGTH 100
void generate_small_tree(t_tree mytree){
    //abat	abat	Nom:Mas+SG
    //abatage	abatage	Nom:Mas+SG
    //abatant	abatant	Nom:Mas+SG
    //abbé	abbé	Nom:Mas+SG
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
}
t_tree generate_void_tree(){    //Créer un tree vide
    t_tree mytree = (t_tree)malloc(sizeof (t_tree));
    mytree->root = createNode();
    return mytree;
}
p_node return_mot_tree(t_tree mytree){  //inite la recursion a partir du tree
    if(mytree->root != NULL){
        return return_mot_node(mytree->root->children[0], mytree->type);
    }
    else{
        return NULL;
    }
}
void linker(p_node node ,int cpt){  //fonction pour créer des nodes en chaine
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
int compare_two_char(char char1[] ,char char2[] ){
    for(int a = 0; a < 150;a++){
        if(char1[a] == char2[0] && char1[a+1] == char2[1] && char1[a+2] == char2[2] && char1[a+3] == char2[3]) {
            return 1;
        }
        a++;
    }
    //printf("Rien trouve");
    return 0;
}

void search_word(word word_searched,t_tree mytree){
    FILE *dico = fopen("dico.txt", "r");
    char line[MAX_LINE_LENGTH];
    if (dico == NULL) {
        return;
    }
    fgets(line, MAX_LINE_LENGTH, dico);
    int cpt = 0;
    word test;
    while (cpt <= 30000){
        if (compare_two_char(line,word_searched.lyric) == 1) {
            printf("yes");
            int index = 0;
            char letter;
            char mot[MAX_LINE_LENGTH];
            char temp = '\t';
            while((letter = fgetc(dico)) != temp){
                mot[index++] = letter;
                printf("Lettre : %c\n",letter);
            }
            strcpy(test.lyric,mot);
        }
        fgets(line, MAX_LINE_LENGTH, dico);
        cpt++;
    }
    printf("Line =%s\n mot = %s\n",line,test.lyric);
    //printf("Fin generate tree");
    fclose(dico);
}