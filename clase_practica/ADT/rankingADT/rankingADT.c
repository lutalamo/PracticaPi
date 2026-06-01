#include <stdio.h>
#include "./rankingADT.h"

struct rankingCDT {
    elemType * elem;    //array dinamico
    size_t size;        //tamanio actual del array
    compare cmp;        //funcion que compare
};

rankingADT newRanking (elemType elems[], size_t dim, compare cmp){
    rankingADT rank = calloc(1, sizeof(struct rankingCDT));
    rank -> size = dim;
    rank -> cmp = cmp;
    rank -> elem = calloc(dim, sizeof(elemType));

    for (int i=0; i<dim; i++){
        rank -> elem[i] = elems[i];
    }
    return rank;
}

void addRanking (rankingADT ranking, elemType elem){
    int pos = -1;

    for (size_t i=0; i<(ranking -> size); i++){
        if (ranking -> cmp(ranking->elem[i], elem) == 0){
            pos = i;
            break;
        }
    }

    if (pos == -1){
        ranking -> elem = realloc(ranking->elem, (ranking->size + 1) * sizeof(elemType));
        ranking -> elem[ranking->size++] = elem;
    }
    else if (pos > 0){
        elemType tmp = ranking->elem[pos-1];
        ranking -> elem[pos-1] = ranking -> elem[pos];
        ranking -> elem[pos] = tmp;
    }
}

size_t size (const rankingADT rank){
    return rank->size;
}

int getByRanking (rankingADT rank, size_t n, elemType *elem){
    if (n == 0 || n > rank->size){ //posicion invalida
        return 0;
    }

    *elem = rank->elem[n-1]; //guardo el elemento en *elem

    //sube un puesto
    if (n > 1){
        elemType tmp = rank->elem[n-2];
        rank->elem[n-2] = rank->elem[n-1];
        rank->elem[n-1] = tmp;
    }
    return 1;
}

elemType * getTopRanking (const rankingADT rank, size_t * top){
    if (*top == 0 || *top == rank->size){   //posicion invalida
        *top = 0;
        return NULL;
    }

    size_t cant = (*top > rank->size) ? rank->size : *top;
    *top = cant;    //actualizo *top para devolverlo 

    elemType * topRank = calloc(cant, sizeof(elemType));
    for (size_t i=0; i < cant; i++){
        topRank[i] = rank->elem[i];
    }

    return topRank;  //devuelvo el ranking
}

int contains (rankingADT rank, elemType elem){
    for (size_t i=0; i < rank->size; i++){
        if (rank->cmp (rank->elem[i], elem) == 0 ) {    //si esta en el primer puesto no sube
        
            if (i > 0) {
                elemType tmp = rank->elem[i-1];
                rank->elem[i-1] = rank->elem[i];
                rank->elem[i] = tmp;
            }
           return 1;
        }
    }
    return 0;
}

void downByRanking (rankingADT rank, size_t n){
    if (n == 0 || n >= rank->size){ /*nada que hacer*/ 
        return;
    }
    elemType tmp = rank->elem[n];
    rank->elem[n] = rank->elem[n-1];
    rank->elem[n-1] = tmp;
}

int position (const rankingADT rank, elemType elem){
    for (size_t i=0; i < rank->size; i++){
        if (rank->cmp(rank->elem[i], elem) == 0){
            return (int)(i+1); //posicion real en el rank
        }
    }
    return 0; //no esta en el ranking
}

void freeRanking (rankingADT rank){
    free(rank->elem);
    free(rank);
}