#include <stdio.h>
#include "./stackADT.h"
#define BLOCK 1

struct stackCDT {
    int * vec;
    size_t dim;
    compare cmp;
    size_t idx; // proximo a insertar
};

stackADT newStack (compare cmp){
    stackADT s = calloc(1, sizeof(struct stackCDT));
    s -> cmp = cmp;
    return s;
}

void freeStack (stackADT s){
    free(s -> vec);
    free(s);
}

int isEmpty (const stackADT s){
    return s -> idx == 0;
}

void push (stackADT s, elemType elem){
    if (s -> dim == s -> idx){
        s -> dim += BLOCK;
        s -> vec = realloc(s->vec, s -> dim * sizeof(s -> vec[0]));
    }
    s -> vec[s -> idx++] = elem;
}

elemType pop (stackADT s){
    if (isEmpty(s)){
        exit(1);
    }
    return s -> vec[--s->idx];
}

int belongs (const stackADT s, elemType elem){
    for (int i = 0; i < s->idx; i++){
        if (s -> cmp (s -> vec[i], elem) == 0){
            return 1;
        }
    }
    return 0;
}