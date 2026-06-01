#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "./socialADT.h"

typedef struct node {
    char * id;
    size_t followers;
    struct node * next;
} TNode;

typedef TNode * influencerNode;

struct socialCDT {
    struct node * first;
};

socialADT newSocial (){
    socialADT new = malloc(sizeof(struct socialCDT));
    new->first = NULL;
    return new;
}

int addInfluencer(socialADT social, const char * id, size_t followers){
    influencerNode curr = social->first;
    influencerNode prev = NULL; 

    if (followers >= 1000){

        influencerNode newInfl = malloc(sizeof(TNode));
        newInfl->id = calloc(strlen(id)+1, sizeof(char));
        strcpy(newInfl->id, id);
        newInfl->followers = followers; 

        if (curr == NULL){  //todavia no hay influencers
            social->first = newInfl;
            newInfl->next = NULL;
            return 1;
        }
        
        while (curr != NULL && curr->followers < followers){
            prev = curr;
            curr = curr->next;
        }

        if (curr != NULL){

            if (prev == NULL){ //tengo que agregarlo primero
                newInfl->next = social->first;
                social->first = newInfl;
                return 1;
            }
            newInfl->next = prev->next; //engancho el nuevo en el curr
            prev->next = newInfl;   //el anterior lo engancho al nuevo
            return 1;
        }
        //si curr es NULL, es porque tengo que agregarlo al final de la lista
        prev->next = newInfl;
        newInfl->next = NULL;
        return 1;
    }
    return 0;
}


