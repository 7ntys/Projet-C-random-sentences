//
// Created by Julien Le ber on 21/10/2022.
//
#include "bintree.h"

int monkey(word* mot){
    if (strcmp(mot->lyric,"none") != 0){
        return 1;
    }
    else{
        return 0;
    }
}




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
        printf("Tree vide");
        return NULL;
    }
}
void sample(t_tree mytree,int nbr){
    word* arr = (word*)malloc(nbr*sizeof (word));
    int cpt =0;
    printf("--\n\n");
    for(int i=0;i<nbr;i++){
        arr[i].iteration = 0;
    }
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
void conjuguer_modele1(l_tree all_tree, word** det){
    // Cette fonction à pour objectif de conjuguer en fonction du premier modèle
    srand(time(NULL));
    p_node nom1= (p_node)malloc(sizeof(struct node));

    nom1 = return_mot_tree(all_tree->name_tree);

    p_node nom2= (p_node)malloc(sizeof(struct node));
    nom2 = return_mot_tree(all_tree->name_tree);
    printf("nom1 = %s %s %s\n;",nom1->mot.lyric,nom1->nom_flechies[0]->lyric,nom1->nom_flechies[1]->lyric);
    printf("nom2 = %s %s %s\n;",nom2->mot.lyric,nom2->nom_flechies[0]->lyric,nom2->nom_flechies[1]->lyric);
    //Creer une fonction qui renvoie un adjectif aleatoire du tree
    p_node adjectif= (p_node)malloc(sizeof(struct node));
    adjectif = return_mot_tree(all_tree->adj_tree);

    //Creer une fonction qui renvoie un verbe aleatoire du tree
    p_node verbe = (p_node)malloc(sizeof(struct node));
    verbe = return_mot_tree(all_tree->verbe_tree);
    for (int i = 0;i < 2;i++){
        for(int j = 0;j < 2;j++) {
            printf("adj = %s %s \n;",adjectif->mot.lyric,adjectif->adjective_flechies[i][j]->lyric);

            //printf("verbe = %s %s \n;", verbe->mot.lyric, verbe->verbe_flechie[i][j]->lyric);
        }
    }

    int a = rand()%2; // nombre aléatoire permettant de savoir si le nom va être au singulier ou au pluriel
    while(strcmp(nom1->nom_flechies[a]->lyric,"none" ) == 0){
        nom1 = return_mot_tree(all_tree->name_tree);
    }
    int b = rand()%2; // nombre aléatoire pour savoir si le déterminant va être défini ou indéfini
    if (a==1){
        printf("%s ",det[b][2].lyric);
    }
    else if ((nom1->nom_flechies[a]->lyric[0]=='a' || nom1->nom_flechies[a]->lyric[0]=='e' || nom1->nom_flechies[a]->lyric[0]=='i' || nom1->nom_flechies[a]->lyric[0]=='o' || nom1->nom_flechies[a]->lyric[0]=='u' || nom1->nom_flechies[a]->lyric[0]=='y') && (b==0)){
        printf("l'"); // condition pour savoir si l'emploi de l'apostrophe est nécéssaire
    }
    else{
        printf("%s ",det[b][(nom1->gender)].lyric); // Conjugaison et affichage du déterminant en fonction du nom choisi
    }

    if (monkey(nom1->nom_flechies[a])) {
        printf("%s ", nom1->nom_flechies[a]); // Affichage du nom aléatoire choisi
    }
    else{
        printf("%s ",nom1->mot.lyric);
    }

    while(strcmp(adjectif->adjective_flechies[nom1->gender][a]->lyric,"none" ) == 0){
        adjectif = return_mot_tree(all_tree->adj_tree);
    }
    if (a==0){
        printf("%s ", adjectif->adjective_flechies[(nom1->gender)][a]); // conjugaison en genre et en nombre de l'adjectif
    }

    else {
        printf("%s ", adjectif->adjective_flechies[(nom1->gender)][a]); // conjugaison en genre et en nombre de l'adjectif

    }

    srand(time(NULL));
    int index =0;
    if(a==0){
        index =2;
    }
    else{
        index = 5;
    }
    int c = 0;
    int cpt=0;// nombre aléatoire permettant de choisir un temps aléatoire pour le verbe à conjuguer
    while (cpt == 0){
        for(int i=0;i<9;i++){
            if(strcmp(verbe->verbe_flechie[i][index]->lyric,"none") != 0){
                //printf("%s \n",verbe->verbe_flechie[i][index]);
                cpt=1;
                c=i;
            }
        }
        if(cpt==0){
            verbe = return_mot_tree(all_tree->verbe_tree);
        }
    }
    if (a==1){
        printf("%s ", verbe->verbe_flechie[c][5]); // conjugaison du verbe choisi
    }
    else {
        printf("%s ", verbe->verbe_flechie[c][2]); // conjugaison du verbe choisi
    }

    srand(time(NULL));
    int d = rand()%2; // nombre aléatoire permettant de savoir si le nom va être au singulier ou au pluriel
    while(strcmp(nom2->nom_flechies[d]->lyric,"none" ) == 0){
        nom2= return_mot_tree(all_tree->name_tree);
    }
    srand(time(NULL));
    int e =rand()%2; // nombre aléatoire permettant de savoir si le déterminant sera défini ou indéfini
    if (d==1){
        printf("%s ",det[e][2].lyric);
    }
    else if ((nom2->nom_flechies[d]->lyric[0]=='a' || nom2->nom_flechies[d]->lyric[0]=='e' || nom2->nom_flechies[d]->lyric[0]=='i' || nom2->nom_flechies[d]->lyric[0]=='o' || nom2->nom_flechies[d]->lyric[0]=='u' || nom2->nom_flechies[d]->lyric[0]=='y') && (e==0)){
        printf("l'");
    }
    else{
        printf("%s ",det[e][(nom2->gender)].lyric);
    }

    printf ("%s ", nom2->nom_flechies[d]);
    free(nom1);
    free(nom2);
    free(adjectif);
    free(verbe);

}

void conjuguer_modele2(l_tree all_tree, word** det){
    // Cette fonction permet de conjuguer en fonction du deuxième modèle
    srand(time(NULL));
    p_node nom1 = return_mot_tree(all_tree->name_tree);
    p_node nom2 = return_mot_tree(all_tree->name_tree);
    p_node verbe1 = return_mot_tree(all_tree->verbe_tree);
    p_node verbe2 = return_mot_tree(all_tree->verbe_tree);
    p_node adjectif = return_mot_tree(all_tree->adj_tree);
    int a = rand()%2; // nombre aléatoire permettant de savoir si le nom va être au singulier ou au pluriel
    int b =rand()%2; // nombre aléatoire permettant de savoir si le déterminant sera défini ou indéfini
    if (a==1){
        printf("%s ",det[b][2].lyric);
    }
    else if ((nom1->nom_flechies[a]->lyric[0]=='a' || nom1->nom_flechies[a]->lyric[0]=='e' || nom1->nom_flechies[a]->lyric[0]=='i' || nom1->nom_flechies[a]->lyric[0]=='o' || nom1->nom_flechies[a]->lyric[0]=='u' || nom1->nom_flechies[a]->lyric[0]=='y') && (b==0)){
        printf("l'"); // condition permettant de savoir si l'emploi d'une apostrophe est nécéssaire
    }
    else{
        printf("%s ",det[b][(nom1->gender)].lyric);
    }

    printf ("%s qui ", nom1->nom_flechies[a]);

    srand(time(NULL));
    int c = rand()%3; // selection d'un temps aléatoire pour le premier verbe
    if (a==1){
        printf("%s ", verbe1->verbe_flechie[c][5]);
    }
    else {
        printf("%s ", verbe1->verbe_flechie[c][2]);
    }


    int d = rand()%3; // selection d'un temps aléatoire pour le second verbe
    if (a==1){
        printf("%s ", verbe2->verbe_flechie[d][5]);
    }
    else {
        printf("%s ", verbe2->verbe_flechie[d][2]);
    }

    srand(time(NULL));
    int e = rand()%2; // nombre aléatoire pour savoir si le nom sera au singulier ou au pluriel
    srand(time(NULL));
    int f =rand()%2; // nombre aléatoire pour savoir si le déterminant sera défini ou non
    if (e==1){
        printf("%s ",det[f][2].lyric);
    }
    else if ((nom2->nom_flechies[e]->lyric[0]=='a' || nom2->nom_flechies[e]->lyric[0]=='e' || nom2->nom_flechies[e]->lyric[0]=='i' || nom2->nom_flechies[e]->lyric[0]=='o' || nom2->nom_flechies[e]->lyric[0]=='u' || nom2->nom_flechies[e]->lyric[0]=='y') && (f==0)){
        printf("l'");
    }
    else{
        printf("%s ",det[f][(nom2->gender)].lyric);
    }

    printf ("%s ", nom2->nom_flechies[e]);

    if (e==0){
        printf("%s ", adjectif->adjective_flechies[(nom2->gender)][e]); // conjugaison de l'adjectif en genre et en nombre
    }

    else {
        printf("%s ", adjectif->adjective_flechies[(nom2->gender)][e]); // conjugaison de ladjectif en genre et en nombre

    }

}

void conjuguer_modele3(word* pronom, l_tree all_tree, word** det){
    // Cette fonction permer de conjuguer en fonction du troisième modèle
    srand(time(NULL));
    p_node nom1 = return_mot_tree(all_tree->name_tree);
    p_node verbe = return_mot_tree(all_tree->verbe_tree);
    p_node adjectif = return_mot_tree(all_tree->adj_tree);
    p_node adverbe = return_mot_tree(all_tree->adv_tree);
    int a =rand()%6; // nombre aléatoire pour savoir à quelle personne sera conjugé le verbe
    srand(time(NULL));
    int b =rand()%3; // nombre aléatoire permettant de choisir un temps pour le verbe à conjuguer
    if (a==0){
        if (verbe->verbe_flechie[b][a]->lyric[0]=='a' || verbe->verbe_flechie[b][a]->lyric[0]=='e' || verbe->verbe_flechie[b][a]->lyric[0]=='i' || verbe->verbe_flechie[b][a]->lyric[0]=='o' || verbe->verbe_flechie[b][a]->lyric[0]=='u' || verbe->verbe_flechie[b][a]->lyric[0]=='y'){
            printf("j'%s ",verbe->verbe_flechie[b][a]); // condition pour savoir si l'emploi de l'apostrophe est nécessaire
        }
        else {
            printf("%s %s ",pronom[a].lyric,verbe->verbe_flechie[b][a]); // affichage du pronom personnel et du verbe
        }
    }
    else {
        printf("%s %s ",pronom[a].lyric,verbe->verbe_flechie[b][a]); // affichage du pronom personnel et du verbe
    }

    printf("%s ", adverbe->adverbe_flechie); // affichage de l'adverbe

    srand(time(NULL));
    int c = rand()%2;// nombre aléatoire pour savoir si le nom sera au singulier ou au pluriel
    int d =rand()%2;// nombre aléatoire pour savoir si le déterminant sera défini ou non
    if (c==1){
        printf("%s ",det[d][2].lyric);
    }
    else if ((nom1->nom_flechies[c]->lyric[0]=='a' || nom1->nom_flechies[c]->lyric[0]=='e' || nom1->nom_flechies[c]->lyric[0]=='i' || nom1->nom_flechies[c]->lyric[0]=='o' || nom1->nom_flechies[c]->lyric[0]=='u' || nom1->nom_flechies[c]->lyric[0]=='y') && (d==0)){
        printf("l'"); // condition pour savoir si l'emploi de l'apostrophe est nécessaire
    }
    else{
        printf("%s ",det[d][(nom1->gender)].lyric);
    }

    printf ("%s ", nom1->nom_flechies[c]);
    if (c==0){
        printf("%s ", adjectif->adjective_flechies[(nom1->gender)][c]);
    }

    else {
        printf("%s ", adjectif->adjective_flechies[(nom1->gender)][c]);

    }
}
