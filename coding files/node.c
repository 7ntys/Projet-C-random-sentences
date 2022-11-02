//
// Created by Julien Le ber on 21/10/2022.
//
#include <stdio.h>
#include "node.h"
#include "bintree.h"
#define MAX_LINE_LENGTH 3000

int generate_tree(){
    struct tree name_tree;
    FILE    *dico = fopen("dico.txt", "r");
    char    line[MAX_LINE_LENGTH];
    char index[] = "Nom:";
    if(dico == NULL) {
        return 1;
    }

    while(fgets(line, MAX_LINE_LENGTH, dico)){
        if(compare_two_char(line,index) == 1){ //Catch all line with "Nom:"
            //printf(line);
            int random = add_on_tree(*name_tree.root,line);

        }

    }

    fclose(dico);
    return 0;

};
//
//Nom:
//    <
//    ->
//   *
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


int add_on_tree(struct node node1, char line[]){
    int a = 0;
    char temp = '\t';
    while(line[a] != temp){
        printf("%d",children_existence(node1,line[a]));
        if(children_existence(node1,line[a]) == 0){
            int index = searching_place(node1);
            node1.children[index] = create_struct(a);
            printf("%c",line[a]);
        }
        else{
            node1 = *node1.children[children_existence(node1,a)];
            printf("%c",line[a]);
        }
        a++;
        

    }
    return 0;

}

int children_existence(struct node node1,char a){
    for(int b=0;b <= 27;b++){
        if(node1.children[b]->c == a){
            printf("%c test",node1.children[b]->c);
            printf("ijitrdtrdrtjij");
            return b;
        }
    }
    printf("ijijij");
    return 0;


}

int searching_place(struct node node1){
    for(int b=0;b <= 27;b++){
        if(node1.children[b] == NULL){
            return b;
        }
    }
    return 0;

}

struct node * create_struct(char value){
    struct node *node1;
    node1->c = value;
    return node1;
}
