#include <stdio.h>

typedef struct node {
    int elem;
    struct node * tail;
} node; 

node *filtrar (node *curr, int ultimo){
    if (curr == NULL){
        return NULL;
    }

    if (curr->elem > ultimo){
        curr->tail = filtrar (curr->tail, curr->elem);
        return curr;
    }
    else {
        node * tmp = curr->tail;
        free(curr);
        return filtrar(tmp, ultimo);
    }
}