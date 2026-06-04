#include <stdlib.h>
#include "./listADT.h"

typedef struct node {
    elemType elem;
    struct node *nextIns; //para recorrer
    struct node *nextAsc;
} tNode;

struct listCDT {
    tNode *firstIns; 
    tNode *firstAns;
    tNode *lastIns;

    int (*compare)(elemType, elemType); // criterio de orden

    tNode *itIns;   // iterador por inserccion
    tNode *itAsc;   // iterador por orden ascendente
};

listADT newList (int (*compare)(elemType e1, elemType e2)){
    listADT list = calloc(1, sizeof(struct listCDT));
    list->compare = compare;
    return list;
}

void add (listADT list, elemType elem){
    tNode *curr = list->firstAns;
    tNode *prev = NULL;

    while (curr );
}