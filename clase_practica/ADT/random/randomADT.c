#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "./randomADT.h"
#include "../../random.h"

struct number{
    int num;
    size_t count; // cuantas veces aparecio
};

struct randomCDT {
    struct number *vec;
    size_t dim;
    size_t cuanto; //cuantas veces aparecio mostFreq
    int mostFreq;
    unsigned char dist;
};

randomADT newRandomADT(unsigned char maxValue){
    if (maxValue == 0) return NULL;

    randomADT ans = malloc (sizeof(*ans));
    ans->vec = calloc (maxValue, sizeof(struct number));
    ans->dim = maxValue;
    ans->mostFreq = 0;
    ans->dist = 0;
    ans->cuanto = 0;

    return ans;
}

void newRandom(randomADT adt){
    int n; 
    //obtengo un numero random
    n = randInt(1, adt->dim); 
    //si no estaba, lo agrego y cuento como num dist
    if (adt->vec[n-1].num == 0){
        adt->vec[n - 1].num = n;
        adt->dist++;
    }
    adt->vec[n - 1].count++;

    if (adt->vec[n-1].count > adt->cuanto){
        adt->cuanto = adt->vec[n-1].count;
        adt->mostFreq = n;
    }
}

void newRandoms(randomADT adt, size_t qty){
    for (size_t i = 0; i < qty; i++){
        newRandom(adt);
    }
    return;
}

unsigned char numbers (const randomADT adt){
    return adt->dist;
}

int mostFrequent(const randomADT adt){
    // no se genero ninguno
    if (adt->dist == 0) return -1;
    return adt->mostFreq;
}

void freeRandomADT(randomADT adt){
    free(adt->vec);
    free(adt);
}