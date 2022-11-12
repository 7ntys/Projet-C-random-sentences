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
    strcpy(mytree->root->children[0]->children[0]->children[0]->children[0]->nom_flechies[0].lyric,"abats");
    strcpy(mytree->root->children[0]->children[0]->children[0]->children[0]->nom_flechies[1].lyric,"abats");
    mytree->root->children[0]->children[0]->children[0]->children[0]->children[0]->c = 'a';
    mytree->root->children[0]->children[0]->children[0]->children[0]->children[0]->children[0]->c = 'g';
    mytree->root->children[0]->children[0]->children[0]->children[0]->children[0]->children[0]->children[0]->c = 'e';
    mytree->root->children[0]->children[0]->children[0]->children[0]->children[0]->children[0]->children[0]->sons=0;
    strcpy(mytree->root->children[0]->children[0]->children[0]->children[0]->children[0]->children[0]->children[0]->mot.lyric, "abatage");
    strcpy(mytree->root->children[0]->children[0]->children[0]->children[0]->children[0]->children[0]->children[0]->nom_flechies[0].lyric, "abatages");
    strcpy(mytree->root->children[0]->children[0]->children[0]->children[0]->children[0]->children[0]->children[0]->nom_flechies[1].lyric, "abatages");
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
    strcpy(mytree->root->children[0]->children[0]->children[1]->children[0]->children[0]->children[0]->children[0]->nom_flechies[0].lyric,"abbesses");
    strcpy(mytree->root->children[0]->children[0]->children[1]->children[0]->children[0]->children[0]->children[0]->nom_flechies[1].lyric,"abbesses");
    strcpy(mytree->root->children[0]->children[0]->children[1]->children[0]->children[0]->children[0]->children[0]->mot.lyric,"abbesse");
    mytree->root->children[0]->children[0]->children[1]->children[0]->sons=1;
    strcpy(mytree->root->children[0]->children[0]->children[1]->children[0]->mot.lyric,"abbe");
    strcpy(mytree->root->children[0]->children[0]->children[1]->children[0]->nom_flechies[0].lyric,"abbes");
    strcpy(mytree->root->children[0]->children[0]->children[1]->children[0]->nom_flechies[1].lyric,"abbes");
    mytree->root->children[0]->children[0]->children[0]->children[0]->children[1] = createNode();
    mytree->root->children[0]->children[0]->children[0]->children[0]->sons=2;
    mytree->root->children[0]->children[0]->children[0]->children[0]->children[1]->sons=1;
    mytree->root->children[0]->children[0]->children[0]->children[0]->children[1]->c = 'n';
    mytree->root->children[0]->children[0]->children[0]->children[0]->children[1]->children[0] = createNode();
    mytree->root->children[0]->children[0]->children[0]->children[0]->children[1]->children[0]->sons=1;
    mytree->root->children[0]->children[0]->children[0]->children[0]->children[1]->children[0]->c = 't';
    mytree->root->children[0]->children[0]->children[0]->children[0]->children[1]->children[0]->sons = 0;
    strcpy(mytree->root->children[0]->children[0]->children[0]->children[0]->children[1]->children[0]->mot.lyric,"abatant");
    strcpy(mytree->root->children[0]->children[0]->children[0]->children[0]->children[1]->children[0]->nom_flechies[0].lyric,"abatants");
    strcpy(mytree->root->children[0]->children[0]->children[0]->children[0]->children[1]->children[0]->nom_flechies[1].lyric,"abatants");
}
t_tree generate_void_tree(){    //Créer un tree vide
    t_tree mytree = (t_tree)malloc(sizeof (t_tree));
    mytree->root = createNode();
    return mytree;
}
int take_second_word(char line[]){
    int cpt = 0;
    while(line[cpt] != '\t'){
        cpt++;
    }
    return cpt+1;
}

int take_third_word(char line[]){
    int cpt = 0;
    while(line[cpt] != '\t'){
        cpt++;
    }
    cpt++;
    while(line[cpt] != '\t'){
        cpt++;
    }
    return cpt+1;
}
word concatenate_mot(char line[],int x){  //recupere le mot à l'infinitif
    int index_mot = 0;
    if (x == 1) {
        index_mot = take_second_word(line);
    }
    if(x == 2){
        index_mot = take_third_word(line);
    }
    word mot;
    int i=0;
    if (x != 2) {
        while (line[index_mot] != '\t') {
            mot.lyric[i] = line[index_mot];
            i++;
            index_mot++;
        }
    }
    else{
        while (line[index_mot] != '\0') {
            mot.lyric[i] = line[index_mot];
            i++;
            index_mot++;
        }
    }


    mot.lyric[i] = '\0';
    return mot;
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
    word inf;
    word forme;
    int found=0;
    while (cpt <= 30000){
        test = concatenate_mot(line,0);
        if (strcmp(test.lyric,word_searched.lyric) == 0) {
            found=1;
            inf = concatenate_mot(line,1);
            forme = concatenate_mot(line,2);
            break;
        }
        fgets(line, MAX_LINE_LENGTH, dico);
        cpt++;
    }
    if(found==0){
        printf("The word wasn't find in the dictionnary\n");
    }
    else{
        printf("We search %s/%s/%s\n",test.lyric,inf.lyric,forme.lyric);
        p_node node = (p_node) malloc(sizeof (struct node));
        node = searching(mytree->root,inf,0);
    }
    fclose(dico);
}
