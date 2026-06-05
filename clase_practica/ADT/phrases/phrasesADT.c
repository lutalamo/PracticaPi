#include "./phrasesADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BLOCK 10

struct claves {
    char * frase;
    size_t dim; // dimension de la frase
};

struct phrasesCDT {
    struct claves * keys;
    size_t size; //cuantas frases hay
    size_t keyFrom;
    size_t keyTo;
    size_t dimKey; //cuantas claves puede haber
};

// retorna 1 si key esta dentro del rango
static int rangoValido (size_t from, size_t to, size_t key){
    if (to - from > 0){
        if (key >= from && key <= to) return 1;
    }
    return 0;
}

phrasesADT newPhrasesADT (size_t from, size_t to){
    if (to < from) return NULL;

    phrasesADT ans = malloc (sizeof(*ans));
    ans->keyFrom = from;
    ans->keyTo = to;
    ans->dimKey = to - from + 1;
    ans->size = 0;
    ans->keys = calloc(ans->dimKey, sizeof(struct claves));
    
    return ans;
}

void freePhrases (phrasesADT ph){
    for (int i = 0; i < ph->dimKey; i++){
        free(ph->keys[i].frase);
    }
    free(ph->keys);
    free(ph);
}

static char * expandFrase (char * phActual, const char * phrase, size_t * dimActual, size_t dimFrase){
    while (phrase[*dimActual] != '\0'){
                if (*dimActual == dimFrase){
                    dimFrase += BLOCK;
                    phActual = realloc(phActual, dimFrase * sizeof(char));
                }
                phActual[*dimActual] = phrase[*dimActual];
                (*dimActual)++;
            }
    phActual = realloc(phActual, (*dimActual + 1) * sizeof(char));
    phActual[*dimActual] = '\0';
    return phActual;
}

int put (phrasesADT ph, size_t key, const char * phrase){
    if (!rangoValido(ph->keyFrom, ph->keyTo, key)) return 0;
    size_t idx = key - ph->keyFrom;

    size_t dimFrase = ph->keys[idx].dim;
    size_t dimActual = 0;

    char * phActual = ph->keys[idx].frase;

    if (dimFrase != 0){ //significa que ya habia una frase
        while (phActual[dimActual] != '\0' && phrase[dimActual] != '\0'){
            phActual[dimActual] = phrase[dimActual];
            dimActual++;
        }
        if (phrase[dimActual] == '\0') {
            phActual = realloc(ph->keys[idx].frase, (dimActual + 1) * sizeof(char));
            phActual[dimActual] = '\0';
            ph->keys[idx].frase = phActual;
            ph->keys[idx].dim = dimActual;
            return 1;
        } else {
            ph->keys[idx].frase = expandFrase(phActual, phrase, &dimActual, dimFrase);
            ph->keys[idx].dim = dimActual;
            return 1;
        }
    }
    ph->keys[idx].frase = expandFrase(phActual, phrase, &dimActual, dimFrase);
    ph->keys[idx].dim = dimActual;
    ph->size += 1;
    return 1;
}

char * get (const phrasesADT ph, size_t key){
    if (!rangoValido(ph->keyFrom, ph->keyTo, key)) return NULL; //rango invalido
    size_t idx = key - ph->keyFrom;
    if (ph->keys[idx].dim == 0) return NULL; // no hay frase guardada

    char * ans = malloc ((ph->keys[idx].dim + 1) * sizeof(char));
    strcpy(ans, ph->keys[idx].frase);
    return ans;
}

size_t size (phrasesADT ph){
    return ph->size;
}

char * concatAll (const phrasesADT ph){
    if (ph->size == 0) {
        char * ans = malloc(sizeof(char));
        ans[0] = '\0';
        return ans;
    }

    size_t dimAtual = 0;
    size_t dimNext = 0;
    char * ans = NULL;

    for (int i = 0; i < ph->dimKey; i++){
        if (ph->keys[i].dim != 0){ //signfica que hay una frase
            dimNext = ph->keys[i].dim;
            ans = realloc(ans, (dimAtual + dimNext + 1) * sizeof(char));
            strcpy(ans + dimAtual, ph->keys[i].frase);
            dimAtual += dimNext;
        }
    }
    return ans;
}

char * concat(const phrasesADT ph, size_t from, size_t to){
    int a = rangoValido(ph->keyFrom, ph->keyTo, from);
    int b = rangoValido(ph->keyFrom, ph->keyTo, to);
    if (!a || !b || to < from ) return NULL; // rango invalido 
    size_t idx_i = from - ph->keyFrom; // indice donde empieza 
    size_t idx_f = to - ph->keyFrom; // indice donde termina

    size_t dimAtual = 0;
    size_t dimNext = 0;
    char * ans = NULL;
    

    for (int i = idx_i; i <= idx_f; i++){
        if (ph->keys[i].dim != 0){ //signfica que hay una frase
            dimNext = ph->keys[i].dim;
            ans = realloc(ans, (dimAtual + dimNext + 1) * sizeof(char));
            strcpy(ans + dimAtual, ph->keys[i].frase);
            dimAtual += dimNext;
        }
    }
    if (ans == NULL){ // no habia frases en ese rango
        ans = malloc(sizeof(char));
        ans[0] = '\0';
        return ans;
    }
    return ans;
}