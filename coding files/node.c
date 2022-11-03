//
// Created by Julien Le ber on 21/10/2022.
//

#include "node.h"
p_node createNode(){
    //Créer un node, alloue de la mémoire a lui et a tout ses children et set tout ses childrens à "NULL"
    //A delete une fois que mathieu a finit generate tree
    p_node node = (p_node) malloc((sizeof (p_node)));
    for(int i =0;i<=max;i++){
        node->children[i] = (p_node) malloc((sizeof (p_node)));
        node->children[i] = NULL;
    }
    return node;
}
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
