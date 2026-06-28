#include <stdio.h>
#include <stdlib.h>
#include "./collectionADT.h"

struct elementos {
    elemType elem;
    struct elementos * next;
};

struct collectionCDT {
    struct elementos * first;
    int (*cmp)(elemType, elemType);
};

collectionADT newCollection (int (*cmp)(elemType, elemType)){
    collectionADT ans = calloc(1, sizeof(*ans));
    ans->cmp = cmp;
    return ans;
}   

collectionADT unionCollection(const collectionADT col1, const collectionADT col2){
    collectionADT ans = newCollection(col1->cmp);

    struct elementos * lis1 = col1->first;
    struct elementos * lis2 = col2->first;
    struct elementos ** p = &ans->first;

    while (lis1 != NULL && lis2 != NULL){
        int comp = ans->cmp(lis1->elem, lis2->elem);
        elemType e;
        if (comp < 0) {
            e = lis1->elem;
            lis1 = lis1->next;
        }
        else if (comp > 0){
            e = lis2->elem;
            lis2 = lis2->next;
        }
        else {
            e = lis1->elem;
            lis1 = lis1->next;
            lis2 = lis2->next;
        }

        *p = malloc (sizeof(struct elementos));
        (*p)->elem = e;
        (*p)->next = NULL; 
        p = &(*p)->next;
    }
    while (lis1 != NULL){
        elemType e;
        e = lis2->elem;

        *p = malloc (sizeof(struct elementos));
        (*p)->elem = e;
        (*p)->next = NULL; 
        p = &(*p)->next;
        lis2 = lis2->next;
    }
    while (lis2 != NULL){
        elemType e;
        e = lis1->elem;

        *p = malloc (sizeof(struct elementos));
        (*p)->elem = e;
        (*p)->next = NULL; 
        p = &(*p)->next;
        lis1 = lis1->next;
    }
    return ans;
}