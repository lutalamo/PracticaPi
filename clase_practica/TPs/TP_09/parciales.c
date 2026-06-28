#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int head;
    struct node * tail;
} node;

typedef node * TList;

TList deleteAll (TList l, int value, int * count){
    if (l == NULL){
        *count = 0;
        return l;
    }

    l->tail = deleteAll(l->tail, value, count);

    if (l->head == value){
        (*count)++;
        TList aux = l->tail;
        free(l);
        return aux;
    }
    return l;
}