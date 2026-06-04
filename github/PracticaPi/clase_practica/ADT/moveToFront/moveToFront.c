#include <stdlib.h>
#include "./moveToFront.h"

typedef struct node {
    elemType elem;
    struct node *next; 
} tNode;

struct moveToFrontCDT {
    int (*compare)(elemType, elemType);
    
    tNode *first; //primer elemento  
    tNode *last; //ultimo elemento

    tNode *it;  //indice iterativo

    size_t size; //cantidad de elementos
};

moveToFrontADT newMoveToFront (int (*compare) (elemType e1, elemType e2)){
    moveToFrontADT conj = calloc (1, sizeof(struct moveToFrontCDT));
    conj->compare = compare;
    return conj; 
}

void freeMoveToFront(moveToFrontADT m){
    free(m);
}

unsigned int add(moveToFrontADT m, elemType elem){
    if (m->first == NULL){
        tNode *aux = calloc(1, sizeof(tNode));
        aux->elem = elem;
        aux->next = NULL;

        m->first = aux;
        m->last = aux;

        m->size++;

        return 1;
    }

    tNode *curr = m->first;

    while (curr != NULL){
        if (m->compare(curr->elem, elem) == 0){
            return 0;
        }
        curr = curr->next;
    }

    tNode *new = calloc(1, sizeof(tNode));
    new->elem = elem;
    new->next = NULL;

    m->last->next = new;
    m->last = new;
    m->size++;

    return 1;
}

unsigned int size(moveToFrontADT moveToFront){
    return moveToFront->size;
}

void toBegin(moveToFrontADT moveToFront){
    moveToFront->it = moveToFront->first;
}

int hasNext(moveToFrontADT moveToFront){
    return moveToFront->it != NULL; 
}

elemType next(moveToFrontADT moveToFront){
    elemType e = moveToFront->it->elem;
    moveToFront->it = moveToFront->it->next;
    return e;
}

elemType * get(moveToFrontADT moveToFront, elemType elem){
    tNode *curr = moveToFront->first;
    tNode *prev = NULL;

    //busco el nodo
    while (curr != NULL && moveToFront->compare(curr->elem, elem) != 0){
        prev = curr;
        curr = curr->next;
    }

    //no lo encontre
    if (curr == NULL){
        retur NULL;
    }

    //encontre y muevo al frente (si no era primero)
    if (prev != NULL){
        prev->next = curr->next;

        if (curr == moveToFront->last){
            moveToFront->last = prev;
        }

        curr->next = moveToFront->first;
        moveToFront->first = curr; 
    }

    //devolver copia del elemento   
    elemType *res = malloc(sizeof(elemType));
    *res = curr->elem;

    return res;
}