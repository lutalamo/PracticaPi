#include "./bagADT.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    elemType elem;
    int count;
    struct node * next;
} TNode;

typedef TNode * TList;

struct bagCDT {
    TList first; //puntero al primer nodo
    unsigned int size;
};

bagADT newBag (){
    bagADT bag = malloc(sizeof(struct bagCDT));

    bag->first = NULL;
    bag->size = 0;
}

unsigned int add(bagADT bag, elemType elem){
    TList curr = bag->first;
    
    while (curr != NULL && compare(curr->elem, elem) != 0){
        curr = curr->next;
    }

    if (curr == NULL){ // no se encontro, lo agrego y devuelvo 1
        TList newNode = malloc(sizeof(TNode));
        newNode->elem = elem;
        newNode->count = 1;

        newNode->next = bag->first; //engancho el nuevo nodo al principio
        bag->first = newNode; 
        bag->size++;

        return 1;
    }
    else { // se encontro el elemento, aumento count
        curr->count++;
        return curr->count;
    }
}

unsigned int count(const bagADT bag, elemType elem){
    TList curr = bag->first;

    while (curr != NULL && compare(curr->elem, elem) != 0){
        curr = curr->next;
    }
    
    if (curr == NULL){ // no se encontro, no aparece
        return 0;
    }
    else {  // se encontro retorno cuantas veces esta
        return curr->count;
    }
}

unsigned int size(const bagADT bag){
    return bag->size; 
}

unsigned int delet(bagADT bag, elemType elem){
    TList curr = bag->first;
    TList prev = NULL;

    while (curr != NULL && compare(curr->elem, elem) != 0){
        prev = curr;
        curr = curr->next;
    }
    if (curr != NULL) {
        if (curr->count == 1){ //tengo que liberar y retornar 0

            if (prev == NULL){ //es el primer nodo
                bag->first = curr->next; //corro el primero nodo al siguiente
            }
            else {          //no era el primer nodo
                prev->next = curr->next; 
            }
            free(curr);
            bag->size--;
            return 0;
        }
        curr->count--;  // disminuyo en 1 la aparicion de ese elemento
        return curr->count;
    }
    return 0;   // si llegue aca, es porque curr = NULL, y no habia tal element
}

elemType mostPopular(bagADT bag){
    
    TList curr = bag->first;
    int mayor = curr->count;
    elemType popular = curr->elem;

    while (curr != NULL){
        if (curr->count > mayor){
            mayor = curr->count;
            popular = curr->elem;
        }
        curr = curr->next;
    }
    return popular;
}
