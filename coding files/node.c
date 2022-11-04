//
// Created by Julien Le ber on 21/10/2022.
//

#include "node.h"
// creation de formes flechies en dur

p_node createNode(){
    // Fonction qui permet de créer un noeud et lui alloue de la mémoire
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
    // Fonction qui permet de créer un mot et lui alloue de la mémoire
    p_mot nouv_mot=(p_mot) malloc((sizeof (p_mot)));
    for(int i =0;i<=30;i++) {
        nouv_mot->mot[i] = (p_mot) malloc((sizeof(p_mot)));
        nouv_mot->mot[i] = '\0';
    }
    return nouv_mot;
}

p_pronoms create_pronoms(){
    // Fonction qui permet de créer un pronom et lui alloue de la mémoire
    p_pronoms nouv_pronom=(p_pronoms) malloc((sizeof (p_pronoms)));
    for(int i =0;i<=6;i++) {
        nouv_pronom->pronoms[i] = (p_pronoms) malloc((sizeof(p_pronoms)));
        nouv_pronom->pronoms[i] = NULL;
    }
    return nouv_pronom;
}

p_determinants create_determinants(){
    // Fonction qui permet de créer un déterminant et lui alloue de la mémoire
    p_determinants det=(p_determinants) malloc((sizeof (p_determinants)));
    for(int i =0;i<=2;i++){
        for (int j=0;j<=3;j++){
            det->determinants[i][j] = (p_determinants) malloc((sizeof (p_determinants)));
            det->determinants[i][j] = NULL;
        }
    }
    return det;
}

// Création en dur de verbes (à supprimer plus tard)
p_node create_conjugaison_verbes(){
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

    return verbe;
}

p_node create_conjugaison_verbes2(){
    p_mot mot1=create_mot();
    strcpy(mot1->mot,"oublie");
    p_mot mot2=create_mot();
    strcpy(mot2->mot,"oublies");
    p_mot mot3=create_mot();
    strcpy(mot3->mot,"oublie");
    p_mot mot4=create_mot();
    strcpy(mot4->mot,"oublions");
    p_mot mot5=create_mot();
    strcpy(mot5->mot,"oubliez");
    p_mot mot6=create_mot();
    strcpy(mot6->mot,"oublient");
    p_mot mot7=create_mot();
    strcpy(mot7->mot,"oubliais");
    p_mot mot8=create_mot();
    strcpy(mot8->mot,"oubliais");
    p_mot mot9=create_mot();
    strcpy(mot9->mot,"oubliait");
    p_mot mot10=create_mot();
    strcpy(mot10->mot,"oubliions");
    p_mot mot11=create_mot();
    strcpy(mot11->mot,"oubliiez");
    p_mot mot12=create_mot();
    strcpy(mot12->mot,"oubliaient");
    p_mot mot13=create_mot();
    strcpy(mot13->mot,"oublie");
    p_mot mot14=create_mot();
    strcpy(mot14->mot,"oublies");
    p_mot mot15=create_mot();
    strcpy(mot15->mot,"oublie");
    p_mot mot16=create_mot();
    strcpy(mot16->mot,"oubliions");
    p_mot mot17=create_mot();
    strcpy(mot17->mot,"oubliiez");
    p_mot mot18=create_mot();
    strcpy(mot18->mot,"oubliient");

    p_node verbe = createNode();
    verbe->verbe_flechie[0][0]=mot1 , verbe->verbe_flechie[0][1]=mot2,verbe->verbe_flechie[0][2]=mot3,
    verbe->verbe_flechie[0][3]=mot4, verbe->verbe_flechie[0][4]=mot5, verbe->verbe_flechie[0][5]=mot6,

    verbe->verbe_flechie[1][0]=mot7 , verbe->verbe_flechie[1][1]=mot8,verbe->verbe_flechie[1][2]=mot9,
    verbe->verbe_flechie[1][3]=mot10, verbe->verbe_flechie[1][4]=mot11, verbe->verbe_flechie[1][5]=mot12,

    verbe->verbe_flechie[2][0]=mot13 , verbe->verbe_flechie[2][1]=mot14,verbe->verbe_flechie[2][2]=mot15,
    verbe->verbe_flechie[2][3]=mot16, verbe->verbe_flechie[2][4]=mot17, verbe->verbe_flechie[2][5]=mot18;

    return verbe;
}
// création de noms (à supprimer plus tard)
p_node create_conjugaison_noms(){
    p_mot mot1=create_mot();
    strcpy(mot1->mot,"ours");
    p_mot mot2=create_mot();
    strcpy(mot2->mot,"ours");

    p_node nom = createNode();
    nom->gender=1;
    nom->nom_flechies[0]=mot1; nom->nom_flechies[1]=mot2;

    return nom;
}
p_node create_conjugaison_noms2(){
    p_mot mot1=create_mot();
    strcpy(mot1->mot,"banane");
    p_mot mot2=create_mot();
    strcpy(mot2->mot,"bananes");

    p_node nom1 = createNode();
    nom1->gender=2;
    nom1->nom_flechies[0]=mot1; nom1->nom_flechies[1]=mot2;

    return nom1;
}

// création d'adjectifs (à supprimer plus tard)
p_node create_conjugaison_adjectifs(){
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

    return adjectif;
}

p_node create_conjugaison_adjectifs2(){
    p_mot mot1=create_mot();
    strcpy(mot1->mot,"joli");
    p_mot mot2=create_mot();
    strcpy(mot2->mot,"jolis");
    p_mot mot3=create_mot();
    strcpy(mot3->mot,"jolie");
    p_mot mot4=create_mot();
    strcpy(mot4->mot,"jolies");

    p_node adjectif = createNode();
    adjectif->adjective_flechies[0][0]=mot1 , adjectif->adjective_flechies[0][1]=mot2,
    adjectif->adjective_flechies[1][0]=mot3 , adjectif->adjective_flechies[1][1]=mot4;

    return adjectif;
}

// création d'un adverbe (à supprimer plus tard)

p_node create_conjugaison_adverbe(){
    p_mot mot1=create_mot();
    strcpy(mot1->mot,"absolument");

    p_node adverbe = createNode();
    adverbe->adverbe_flechies[0]=mot1;

    return adverbe;
}

// Création et remplissage de la structure contenant les déterminants

p_node create_conjugaison_determinants(){
    p_mot mot1=create_mot();
    strcpy(mot1->mot,"le");
    p_mot mot2=create_mot();
    strcpy(mot2->mot,"la");
    p_mot mot3=create_mot();
    strcpy(mot3->mot,"les");
    p_mot mot4=create_mot();
    strcpy(mot4->mot,"un");
    p_mot mot5=create_mot();
    strcpy(mot5->mot,"une");
    p_mot mot6=create_mot();
    strcpy(mot6->mot,"des");

    p_determinants det = create_determinants();
    det->determinants[0][0]=mot1 , det->determinants[0][1]=mot2,det->determinants[0][2]=mot3,
    det->determinants[1][0]=mot4, det->determinants[1][1]=mot5, det->determinants[1][2]=mot6;

    return det;

}

// création et remplissage de la structure contenant les pronoms personnels
p_node create_conjugaison_pronoms(){
    p_mot mot1=create_mot();
    strcpy(mot1->mot,"je");
    p_mot mot2=create_mot();
    strcpy(mot2->mot,"tu");
    p_mot mot3=create_mot();
    strcpy(mot3->mot,"il");
    p_mot mot4=create_mot();
    strcpy(mot4->mot,"nous");
    p_mot mot5=create_mot();
    strcpy(mot5->mot,"vous");
    p_mot mot6=create_mot();
    strcpy(mot6->mot,"ils");

    p_pronoms pronom = create_pronoms();
    pronom->pronoms[0]=mot1 , pronom->pronoms[1]=mot2,pronom->pronoms[2]=mot3,
    pronom->pronoms[3]=mot4, pronom->pronoms[4]=mot5, pronom->pronoms[5]=mot6;

    return pronom;

}


void conjuguer_modele1(p_node nom1,p_node adjectif, p_node verbe, p_node nom2, p_determinants det){
    // Cette fonction à pour objectif de conjuguer en fonction du premier modèle
    srand(time(NULL));
    int a = rand()%2; // nombre aléatoire permettant de savoir si le nom va être au singulier ou au pluriel
    int b =rand()%2; // nombre aléatoir pour savoir si le déterminant va être défini ou indéfini
    if (a==1){
        printf("%s ",det->determinants[b][2]);
    }
    else if ((nom1->nom_flechies[a]->mot[0]=='a' || nom1->nom_flechies[a]->mot[0]=='e' || nom1->nom_flechies[a]->mot[0]=='i' || nom1->nom_flechies[a]->mot[0]=='o' || nom1->nom_flechies[a]->mot[0]=='u' || nom1->nom_flechies[a]->mot[0]=='y') && (b==0)){
        printf("l'"); // condition pour savoir si l'emploi de l'apostrophe est nécéssaire
    }
    else{
        printf("%s ",det->determinants[b][(nom1->gender)-1]); // Conjugaison et affichage du déterminant en fonction du nom choisi
    }

    printf ("%s ", nom1->nom_flechies[a]); // Affichage du nom aléatoire choisi


    if (a==0){
        printf("%s ", adjectif->adjective_flechies[(nom1->gender)-1][a]); // conjugaison en genre et en nombre de l'adjectif
    }

    else {
        printf("%s ", adjectif->adjective_flechies[(nom1->gender)-1][a]); // conjugaison en genre et en nombre de l'adjectif

    }

    srand(time(NULL));
    int c = rand()%3; // nombre aléatoire permettant de choisir un temps aléatoire pour le verbe à conjuguer
    if (a==1){
        printf("%s ", verbe->verbe_flechie[c][5]); // conjugaison du verbe choisi
    }
    else {
        printf("%s ", verbe->verbe_flechie[c][2]); // conjugaison du verbe choisi
    }

    srand(time(NULL));
    int d = rand()%2; // nombre aléatoire permettant de savoir si le nom va être au singulier ou au pluriel
    srand(time(NULL));
    int e =rand()%2; // nombre aléatoire permettant de savoir si le déterminant sera défini ou indéfini
    if (d==1){
        printf("%s ",det->determinants[e][2]);
    }
    else if ((nom2->nom_flechies[d]->mot[0]=='a' || nom2->nom_flechies[d]->mot[0]=='e' || nom2->nom_flechies[d]->mot[0]=='i' || nom2->nom_flechies[d]->mot[0]=='o' || nom2->nom_flechies[d]->mot[0]=='u' || nom2->nom_flechies[d]->mot[0]=='y') && (e==0)){
        printf("l'");
    }
    else{
        printf("%s ",det->determinants[e][(nom2->gender)-1]);
    }

    printf ("%s ", nom2->nom_flechies[d]);

}

void conjuguer_modele2(p_node nom1,p_node verbe1, p_node verbe2, p_node nom2, p_node adjectif, p_determinants det){
    // Cette fonction permet de conjuguer en fonction du deuxième modèle
    srand(time(NULL));
    int a = rand()%2; // nombre aléatoire permettant de savoir si le nom va être au singulier ou au pluriel
    int b =rand()%2; // nombre aléatoire permettant de savoir si le déterminant sera défini ou indéfini
    if (a==1){
        printf("%s ",det->determinants[b][2]);
    }
    else if ((nom1->nom_flechies[a]->mot[0]=='a' || nom1->nom_flechies[a]->mot[0]=='e' || nom1->nom_flechies[a]->mot[0]=='i' || nom1->nom_flechies[a]->mot[0]=='o' || nom1->nom_flechies[a]->mot[0]=='u' || nom1->nom_flechies[a]->mot[0]=='y') && (b==0)){
        printf("l'"); // condition permettant de savoir si l'emploi d'une apostrophe est nécéssaire
    }
    else{
        printf("%s ",det->determinants[b][(nom1->gender)-1]);
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
        printf("%s ",det->determinants[f][2]);
    }
    else if ((nom2->nom_flechies[e]->mot[0]=='a' || nom2->nom_flechies[e]->mot[0]=='e' || nom2->nom_flechies[e]->mot[0]=='i' || nom2->nom_flechies[e]->mot[0]=='o' || nom2->nom_flechies[e]->mot[0]=='u' || nom2->nom_flechies[e]->mot[0]=='y') && (f==0)){
        printf("l'");
    }
    else{
        printf("%s ",det->determinants[f][(nom2->gender)-1]);
    }

    printf ("%s ", nom2->nom_flechies[e]);

    if (e==0){
        printf("%s ", adjectif->adjective_flechies[(nom2->gender)-1][e]); // conjugaison de l'adjectif en genre et en nombre
    }

    else {
        printf("%s ", adjectif->adjective_flechies[(nom2->gender)-1][e]); // conjugaison de ladjectif en genre et en nombre

    }

}

void conjuguer_modele3(p_pronoms pronom, p_node verbe, p_node adverbe, p_node nom1, p_node adjectif, p_determinants det){
    // Cette fonction permer de conjuguer en fonction du troisième modèle
    srand(time(NULL));
    int a =rand()%6; // nombre aléatoire pour savoir à quelle personne sera conjugé le verbe
    srand(time(NULL));
    int b =rand()%3; // nombre aléatoire permettant de choisir un temps pour le verbe à conjuguer
    if (a==0){
        if (verbe->verbe_flechie[b][a]->mot[0]=='a' || verbe->verbe_flechie[b][a]->mot[0]=='e' || verbe->verbe_flechie[b][a]->mot[0]=='i' || verbe->verbe_flechie[b][a]->mot[0]=='o' || verbe->verbe_flechie[b][a]->mot[0]=='u' || verbe->verbe_flechie[b][a]->mot[0]=='y'){
            printf("j'%s ",verbe->verbe_flechie[b][a]); // condition pour savoir si l'emploi de l'apostrophe est nécessaire
        }
        else {
            printf("%s %s ",pronom[a],verbe->verbe_flechie[b][a]); // affichage du pronom personnel et du verbe
        }
    }
    else {
        printf("%s %s ",pronom->pronoms[a],verbe->verbe_flechie[b][a]); // affichage du pronom personnel et du verbe
    }

    printf("%s ", adverbe->adverbe_flechies[0]); // affichage de l'adverbe

    srand(time(NULL));
    int c = rand()%2;// nombre aléatoire pour savoir si le nom sera au singulier ou au pluriel
    int d =rand()%2;// nombre aléatoire pour savoir si le déterminant sera défini ou non
    if (c==1){
        printf("%s ",det->determinants[d][2]);
    }
    else if ((nom1->nom_flechies[c]->mot[0]=='a' || nom1->nom_flechies[c]->mot[0]=='e' || nom1->nom_flechies[c]->mot[0]=='i' || nom1->nom_flechies[c]->mot[0]=='o' || nom1->nom_flechies[c]->mot[0]=='u' || nom1->nom_flechies[c]->mot[0]=='y') && (d==0)){
        printf("l'"); // condition pour savoir si l'emploi de l'apostrophe est nécessaire
    }
    else{
        printf("%s ",det->determinants[d][(nom1->gender)-1]);
    }

    printf ("%s ", nom1->nom_flechies[c]);
    if (c==0){
        printf("%s ", adjectif->adjective_flechies[(nom1->gender)-1][c]);
    }

    else {
        printf("%s ", adjectif->adjective_flechies[(nom1->gender)-1][c]);

    }
}






