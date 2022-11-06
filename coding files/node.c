//
// Created by Julien Le ber on 21/10/2022.
//

#include "node.h"
#include "bintree.h"
#define MAX_LINE_LENGTH 100

int generate_tree() {
    t_tree name_tree = generate_void_tree();
    FILE *dico = fopen("dico.txt", "r");
    char line[MAX_LINE_LENGTH];
    char index[] = "Nom:";
    if (dico == NULL) {
        return 1;
    }
    fgets(line, MAX_LINE_LENGTH, dico);
    int cpt = 0;
    while (cpt <= 30000){
        //printf("ca recommence encore et encore\n");
        //printf(" LINE ETUDIE : %s",line);
        if (compare_two_char(line, index) == 1) { //Catch all line with "Nom:"
            //int index = 0;
            //char letter;
            //char mot[MAX_LINE_LENGTH];
            //char temp = '\t';
            //while((letter = fgetc(dico)) != temp){
            //mot[index++] = letter;
            //printf("Lettre : %c\n",letter);
            //}
            int random = add_on_tree(name_tree->root, line);

        }
        fgets(line, MAX_LINE_LENGTH, dico);
        cpt++;

    }
    //printf("Fin generate tree");
    fclose(dico);
    printf("CONNARD\n");
    printf("TREE TEST : %s",name_tree->root->children[0]->mot.lyric);
    return 0;
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

int take_second_word(char line[]){
    int cpt = 0;
    while(line[cpt] != '\t'){
        cpt++;
    }
    return cpt+1;
}

int add_on_tree(p_node node1, char line[]){
    //line = Mot sous forme d'array ["B,o,n,j,o,u,r"]
    //appel de fonction pour décortiquer le mot présent dans line et le store dans un word
    word mot;
    mot = concatenate_mot(line);
    //printf("-M-\n");
    //appel de fonction par recursion qui créer en chaine les nodes du mot de word
    node1 = chain_add(node1,mot,0);
    //printf("fin add_on_tree\n");
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
    for (int  i = 0; i < max; i++){
        node1->children[i]= (p_node)malloc(sizeof(struct node));
        node1->children[i] = NULL;

    }
    return node1;
}

p_node chain_add(p_node node, word mot,int index_mot){
    if(mot.lyric[index_mot] == '\0'){
        strcpy(node->mot.lyric,mot.lyric);
        return node;
    }
    else{
        //printf("%c\n",mot.lyric[index_mot]);
        p_node temp = create_struct(mot.lyric[index_mot]);
        //printf("%c\n",temp->c);
        int index_node = children_existence(node,temp->c);
        if(index_node == -1){
            index_node = searching_place(node);
        }
        node->children[index_node] = temp;
        return chain_add(temp,mot,index_mot+1);
    }
}
word concatenate_mot(char line[]){
    int index_mot = take_second_word(line);
    word mot;
    int i=0;
    while(line[index_mot] != '\t'){
        mot.lyric[i] =line[index_mot];
        i++;
        index_mot++;
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
        int stop = rand() % 4;  // Coefficient pour decider si le mot s'arrete la ou non (à changer pour ameliorer le random)
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
        for (int i = 0; i <= 5; i++) {
            for(int j = 0 ; j<=5;j++){
                if (node->verbe_flechie[i][j].lyric[0] != '\0') {     //Le premier caractere est le caractere d'arret.
                    return 1;   //S'il ya une forme flechie return 1 : le verbe peut etre finit
                }
            }
        }
    }
    //partie nom : return 2
    else if(strcmp(type.lyric,"nom") == 0) {
        for (int i = 0; i <= 1; i++) {
            if(node->nom_flechies[i].lyric[0] != '\0'){
                return 2;
            }
        }
    }
    //partie adjectif : return 3
    else if(strcmp(type.lyric,"adjectif") == 0){
        for (int i = 0; i <= 1; i++) {
            for(int j = 0 ; j<=1;j++){
                if (node->adjective_flechies[i][j].lyric[0] != '\0') {     //Le premier caractere est le caractere d'arret.
                    return 3;   //S'il ya une forme flechie return 3 : l'adjectif peut etre finit
                }
            }
        }
    }
    //partie adverbe : return 4
    else if(strcmp(type.lyric,"adverbe") == 0) {
        if (node->adverbe_flechie.lyric[0] != '\0') {     //Le premier caractere est le caractere d'arret.
            return 4;   //S'il ya une forme flechie return 2 : le mot peut etre finit
        }
    }
    return 0;
}
