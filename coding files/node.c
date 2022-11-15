//
// Created by Julien Le ber on 21/10/2022.
//

#include "node.h"
#include "bintree.h"
#define MAX_LINE_LENGTH 100
// creation de formes flechies en dur

p_pronoms create_pronoms(){
    // Fonction qui permet de créer un pronom et lui alloue de la mémoire
    p_pronoms nouv_pronom=(p_pronoms) malloc((sizeof (struct pronoms)));
    for(int i =0;i<6;i++) {
        nouv_pronom->pronoms[i] = (p_pronoms) malloc((sizeof(struct pronoms)));
        nouv_pronom->pronoms[i] = NULL;
    }
    return nouv_pronom;
}

p_determinants create_determinants(){
    // Fonction qui permet de créer un déterminant et lui alloue de la mémoire
    p_determinants det=(p_determinants) malloc((sizeof (struct determinants)));
    for(int i =0;i<=2;i++){
        for (int j=0;j<=3;j++){
            det->determinants[i][j] = (p_determinants) malloc((sizeof (struct determinants)));
            det->determinants[i][j] = NULL;
        }
    }
    return det;
}
//Ok
// Création en dur de verbes (à supprimer plus tard)

// création de noms (à supprimer plus tard)

// création d'adjectifs (à supprimer plus tard)


// création d'un adverbe (à supprimer plus tard)


// Création et remplissage de la structure contenant les déterminants

p_determinants create_conjugaison_determinants(){
    p_mot mot1= (p_mot)malloc(sizeof(word));
    strcpy(mot1->lyric,"le");
    p_mot mot2=(p_mot)malloc(sizeof(word));
    strcpy(mot2->lyric,"la");
    p_mot mot3=(p_mot)malloc(sizeof(word));
    strcpy(mot3->lyric,"les");
    p_mot mot4=(p_mot)malloc(sizeof(word));
    strcpy(mot4->lyric,"un");
    p_mot mot5=(p_mot)malloc(sizeof(word));
    strcpy(mot5->lyric,"une");
    p_mot mot6=(p_mot)malloc(sizeof(word));
    strcpy(mot6->lyric,"des");

    p_determinants det = create_determinants();
    det->determinants[0][0]=mot1 , det->determinants[0][1]=mot2,det->determinants[0][2]=mot3,
    det->determinants[1][0]=mot4, det->determinants[1][1]=mot5, det->determinants[1][2]=mot6;

    return det;

}

// création et remplissage de la structure contenant les pronoms personnels
p_pronoms create_conjugaison_pronoms(){
    p_mot mot1=(p_mot)malloc(sizeof(word));
    strcpy(mot1->lyric,"je");
    p_mot mot2=(p_mot)malloc(sizeof(word));
    strcpy(mot2->lyric,"tu");
    p_mot mot3=(p_mot)malloc(sizeof(word));
    strcpy(mot3->lyric,"il");
    p_mot mot4=(p_mot)malloc(sizeof(word));
    strcpy(mot4->lyric,"nous");
    p_mot mot5=(p_mot)malloc(sizeof(word));
    strcpy(mot5->lyric,"vous");
    p_mot mot6=(p_mot)malloc(sizeof(word));
    strcpy(mot6->lyric,"ils");

    p_pronoms pronom = create_pronoms();
    pronom->pronoms[0]=mot1 , pronom->pronoms[1]=mot2,pronom->pronoms[2]=mot3,
    pronom->pronoms[3]=mot4, pronom->pronoms[4]=mot5, pronom->pronoms[5]=mot6;

    return pronom;

}




// Fonction qui permet de rendre le menu meilleur
// Verifie si le caractère rentré est un entier qui est compris entre les valeurs demandées
// Verifie aussi si le caratère n'est pas une lettre ou un mot
int ask_int(int bot, int top){
    {
        int var;
        int entry, c;
        do {
            do{
                printf("Donnez un nombre entre %d et %d : ",bot,top);
                entry= scanf("%d", &var);
                while ((c = getchar()) != '\n' && c != EOF);
            }while (entry != 1);
        }while (var > top || (var < bot));
        return var;
    }
}

l_tree generate_tree() {
    l_tree all_tree;
    all_tree->name_tree = generate_void_tree();
    all_tree->adj_tree = generate_void_tree();
    all_tree->verbe_tree = generate_void_tree();
    all_tree->adv_tree = generate_void_tree();
    FILE *dico = fopen("dico.txt", "r");
    char line[MAX_LINE_LENGTH];
    if (dico == NULL) {
        return all_tree;
    }
    fgets(line, MAX_LINE_LENGTH, dico);
    int cpt = 0;
    int cpt2 = 0;
    while (cpt <= 300000){
        if(cpt2 >= 10000){
            cpt2 = 0;
            printf(" LINE ETUDIE : %s \n",line);
        }

        if (compare_two_char(line,"Nom:") == 1) { //Catch all line with "Nom:"

            int random = add_on_tree(all_tree->name_tree->root, line);

        }
        else if (compare_two_char(line,"Adj:") == 1) {
            //printf(" LINE D' ADJ : %s \n",line);
            int random = add_on_tree(all_tree->adj_tree->root, line);
        }
        else if (strstr(line,"Ver:")) {

            //printf(" LINE DE VERBE : %s \n",line);
            int random = add_on_tree(all_tree->verbe_tree->root, line);

        }
        else if (strstr(line,"\tAdv")) {
            //printf(" LINE D'ADV : %s",line);
            int random = add_on_tree(all_tree->adv_tree->root, line);
        }

        fgets(line, MAX_LINE_LENGTH, dico);
        cpt++;
        cpt2++;

    }
    fclose(dico);
    return all_tree;
}

int compare_two_char(char char1[] ,char char2[]){
    for(int a = 0; a < 150;a++){
        if(char1[a] == char2[0] && char1[a+1] == char2[1] && char1[a+2] == char2[2] && char1[a+3] == char2[3]) {
            return 1;
        }


        a++;
        }
    //printf("Rien trouve");
    return 0;

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

int add_on_tree(p_node node1, char line[]){
    //line = Mot sous forme d'array ["B,o,n,j,o,u,r"]
    //appel de fonction pour décortiquer le mot présent dans line et le store dans un word
    word fleche;
    word mot;
    word typo;
    fleche = concatenate_mot(line,0);
    mot = concatenate_mot(line,1);
    typo = concatenate_mot(line,2);
    word* liste_typo = multiple_typo(typo);
    node1 = chain_add(node1,mot,0,typo,fleche,liste_typo);
    return 0;

}

int children_existence(p_node node1,char a){
    for(int b=0;b < max; b++){
        if (node1->children[b] != NULL) {
            //printf("children non nul \n");
            //printf("valeur de son children : %c\n",node1->children[b]->c);
            if (node1->children[b]->c == a) {  // Si la valeur d'un de ses fils est égale à "a"
                //printf("%d",b);
                return b;  //Retourne son index
            }
        }
    }
    return -1;

}

int searching_place(p_node node1){
    for(int b=0;b < max;b++){
        if(node1->children[b] == NULL){
            return b;
        }
    }
    return 0;

}

struct node * create_struct(char value){
    p_node node1;
    node1 = (p_node)malloc(sizeof(struct node));
    node1->c = value;
    node1->sons =0;
    for (int  i = 0; i < max; i++){
        node1->children[i]= (p_node)malloc(sizeof(struct node));
        node1->children[i] = NULL;
    }
    for (int i = 0;i <= 1;i++){
        node1->nom_flechies[i]= (word*)malloc(sizeof(struct mot));
        for (int j = 0;j <= 1;j++){
            node1->adjective_flechies[i][j]= (word*)malloc(sizeof(struct mot));
        }
    }
    for (int i = 0;i <= 10;i++){
        for (int j = 0;j <= 5;j++){
            node1->verbe_flechie[i][j] = (word*)malloc(sizeof(struct mot));
        }

    }
    node1->adverbe_flechie = (word*)malloc(sizeof(struct mot));



    return node1;
}

word* multiple_typo(word typo){
    word *temp = (word*)malloc(7*sizeof (struct mot));
    int index = 0;
    int dex = 0;
    for(int i = 0; i < 7; i++){
        strcpy(temp[i].lyric,"none");

    }
    for(int i = 4; i <= strlen(typo.lyric); i++){
        if(typo.lyric[i] == ':' || typo.lyric[i] == '\v' ){
            //printf(" ça passe là dedans");
            index++;
            dex=0;
            if(typo.lyric[i] == '\v'){
                return temp;
            }
        }
        else{
            temp[index].lyric[dex] =  typo.lyric[i];
            dex++;
      }
    }
    for(int i = 0; i < 7; i++){
        if (strcmp(temp[3].lyric,"none") != 0){
        }

    }

    return temp;


}

p_node chain_add(p_node node, word mot,int index_mot, word typo, word fleche, word liste_typo[]){
    if(mot.lyric[index_mot] == '\0'){    //Si le mot arrive à la fin :
        strcpy(node->mot.lyric,mot.lyric); // Mettre le mot en entier dans la structure de la node

        if(strstr(typo.lyric,":Nom")) {
            if (strstr(typo.lyric, ":Mas") != 0) {
                node->gender = 0; // HOMME

            }
            else if (strstr(typo.lyric, ":Fem") != 0) {
                node->gender = 1; // FEMME
            }
            else{
                node->gender = 2; // NON BINAIRE
            }
            if (strstr(typo.lyric, "+SG") != 0) {
                printf("Mot au singulier de la FF : %s \n", fleche);
                node->nom_flechies[0] = &fleche;
            } else {
                printf("Mot au pluriel de la FF : %s \n", fleche);
                node->nom_flechies[1] = &fleche;
            }
        }
        if(strstr(typo.lyric,":Adj")) {
            if (strstr(typo.lyric, ":Mas") != 0 || strstr(typo.lyric, ":InvGen") != 0 ) {
                if (strstr(typo.lyric, "+SG") != 0) {
                    strcpy(node->adjective_flechies[0][0]->lyric,fleche.lyric); //Mas+SG
                }
                else{
                    strcpy(node->adjective_flechies[1][0]->lyric,fleche.lyric); // Mas+PL
                }

            }
            else if (strstr(typo.lyric, ":Fem") != 0 || strstr(typo.lyric, ":InvGen") != 0 ) {
                if (strstr(typo.lyric, "+SG") != 0) {
                    strcpy(node->adjective_flechies[0][1]->lyric,fleche.lyric); //Fem+SG

                }
                else{
                    strcpy(node->adjective_flechies[1][1]->lyric,fleche.lyric); //Fem+PL

                }

            }

        }
        if(strstr(typo.lyric,"Ver:")) {
            //printf("ça passe ici \n");
            //printf("Liste typo de 0 : %s \n",liste_typo[0].lyric);
            int i = 0;
            while (strcmp(liste_typo[i].lyric,"none") != 0) {
                //printf("Liste typo : %s",liste_typo[i].lyric);
                int temps;
                if (strstr(liste_typo[i].lyric, ":Inf")) { temps = 0; }
                else if (strstr(liste_typo[i].lyric, ":IPSim")) { temps = 1; }
                else if (strstr(liste_typo[i].lyric, ":IImp")) { temps = 2; }
                else if (strstr(liste_typo[i].lyric, ":IPre")) { temps = 3; }
                else if (strstr(liste_typo[i].lyric, ":PPas")) { temps = 4; }
                else if (strstr(liste_typo[i].lyric, ":IFut")) { temps = 5; }
                else if (strstr(liste_typo[i].lyric, ":CPre")) { temps = 6; }
                else if (strstr(liste_typo[i].lyric, ":PPre")) { temps = 7; }
                else if (strstr(liste_typo[i].lyric, "SImp")) { temps = 8; }
                else if (strstr(liste_typo[i].lyric, ":SPre")) { temps = 9; }
                else if (strstr(liste_typo[i].lyric, ":Imp")) { temps = 10; }

                if (strstr(liste_typo[i].lyric, "+SG") != 0) {
                    if (strstr(liste_typo[i].lyric, "+P1") != 0) {
                        node->verbe_flechie[temps][0];
                    } else if (strstr(liste_typo[i].lyric, "+P2") != 0) {
                        node->verbe_flechie[temps][1];
                    } else if (strstr(liste_typo[i].lyric, "+P3") != 0) {
                        node->verbe_flechie[temps][2];
                    } else {
                        if (strstr(liste_typo[i].lyric, "+P1") != 0) {
                            node->verbe_flechie[temps][3];
                        } else if (strstr(liste_typo[i].lyric, "+P2") != 0) {
                            node->verbe_flechie[temps][4];
                        } else if (strstr(liste_typo[i].lyric, "+P3") != 0) {
                            node->verbe_flechie[temps][5];
                        }

                    }

                }

            i++;
            }
            //printf("-------FIN---------\n");
            return node;
        }
    }
    else{
        fill_flechies(node);

        int index_node = children_existence(node,mot.lyric[index_mot]); //
        if(index_node == -1){  // Pas trouver de fils avec la lettre
            node->sons++;
            p_node temp = create_struct(mot.lyric[index_mot]); // Créer une structure mot avec la valeur de la lettre

            index_node = searching_place(node); //chercher une place de libre dans l'array de ses fils
            node->children[index_node] = temp; //mettre la structure
        }
        return chain_add(node->children[index_node],mot,index_mot+1, typo,fleche,liste_typo);
    }
}
//
void fill_flechies(p_node node){
    for (int i = 0;i <= 1;i++){
        strcpy(node->nom_flechies[i]->lyric,"none");
        for (int j = 0;j <= 1;j++){
            strcpy(node->adjective_flechies[i][j]->lyric,"none");
        }
    }
    for (int i = 0;i <= 10;i++){
        for (int j = 0;j <= 5;j++){
            strcpy(node->verbe_flechie[i][j]->lyric,"none");
        }

    }
    strcpy(node->adverbe_flechie->lyric,"none");

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
//partie julien :
//
p_node return_mot_node(p_node node , word type){
    //Return le node d'un mot aléatoirement à partir du node donné
    if(isempty(node,type) != 0){     //Le mot contient-il des formes fléchie ?
        int random = (rand() % node->sons); // determine l'index du child si le mot ne s'arrete pas la
        int stop = rand() % 10;  // Coefficient pour decider si le mot s'arrete la ou non (à changer pour ameliorer le random)
        if(stop ==0){
            return node;    //le mot s'arrete la
        }
        else if(node->sons == 0) {   // le mot s'arrete la s'il n'a pas de sons (juste mesure de sécurité, normalement
            return node;        // c'est deja check avec isempty();
        }
        else{
            return return_mot_node(node->children[random],type); //On parcourt l'arbre par récursion
        }
    }
    else{
        if(node->sons != 0){    //Si le mot n'a pas de forme fléchie mais des sons, on choisit au hasard un sons
            int random = rand() % node->sons;
            return return_mot_node(node->children[random],type);
        }
        else{
            return node;     // S'il n'a pas de sons on arrete le mot
        }
    }
}

int isempty(p_node node , word type){
    //objectif de cette fonction : verifier si le node a une quelconque forme flechie
    //ce qui veux dire que l'on pourrait arreter le mot ici. Verifier pour chaque type
    //partie verb : return 1
    if(strcmp(type.lyric,"verbe") == 0){
        for (int i = 0; i <= 11; i++) {
            for(int j = 0 ; j<=5;j++){
                if (node->verbe_flechie[i][j]->lyric[0] != '\0') {     //Le premier caractere est le caractere d'arret.
                    return 1;   //S'il ya une forme flechie return 1 : le verbe peut etre finit
                }
            }
        }
    }
    //partie nom : return 2
    else if(strcmp(type.lyric,"nom") == 0) {
        for (int i = 0; i <= 1; i++) {
            if(node->nom_flechies[i]->lyric[0] != '\0'){
                return 2;
            }
        }
    }
    //partie adjectif : return 3
    else if(strcmp(type.lyric,"adjectif") == 0){
        printf("p\n");
        for (int i = 0; i <= 1; i++) {
            for(int j = 0 ; j<=1;j++){
                printf("MOT FINI MAIS AVANT: %s \n",node->adjective_flechies[i][j]->lyric);
                if (strcmp(node->adjective_flechies[i][j]->lyric,"none") != 0) {     //Le premier caractere est le caractere d'arret.
                    printf("MOT FINI : %s \n",node->adjective_flechies[i][j]->lyric);
                    return 3;   //S'il ya une forme flechie return 3 : l'adjectif peut etre finit
                }
            }
        }
    }
    //partie adverbe : return 4
    else if(strcmp(type.lyric,"adverbe") == 0) {
        if (node->adverbe_flechie->lyric[0] != '\0') {     //Le premier caractere est le caractere d'arret.
            return 4;   //S'il ya une forme flechie return 2 : le mot peut etre finit
        }
    }
    return 0;
}
