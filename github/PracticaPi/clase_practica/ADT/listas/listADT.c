#include <stdio.h>
#include <stdlib.h>
#include "./listADT.h"

struct node {
    elemType elem;
    struct node * tail;
};
typedef struct node * TList;

struct listCDT {
    TList first; //primero elemento de la lista
    cmpFun cmp; //funcion que compara
};