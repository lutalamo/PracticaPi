#include <stddef.h>
#include <stdio.h>
#include "./dictADT.h"
#include <string.h>
#include <ctype.h>
#define LETTERS ('z'-'a'+1)
#define BLOCK 10

typedef struct node {
    char * nombre; //
    size_t nombre_len;
    char * definicion;
    size_t def_len;
    struct node * next; //siguiente palabra
} palabra;

typedef struct wordList{
    palabra * current;
    palabra * first;
    size_t dim; // cuantas palabras hay con esa letra
}wordList;

struct dictCDT{
    wordList letras[LETTERS];
    size_t cant; //total de palabras
};

dictADT newDict(){
    dictADT ans = calloc (1, sizeof(*ans));    
    return ans;
}

static void freeWord(palabra * word){ // puntero, sino seria una copia
    free(word->nombre);
    free(word->definicion);
    free(word);
}

static void freeWordList (wordList * wl){
    palabra * current = wl->first;
    while (current != NULL){
        palabra * next = current->next;
        freeWord(current);
        current = next;
    }
}

void freeDict(dictADT dict){
    for (int i = 0; i < LETTERS; i++){
        freeWordList(&dict->letras[i]);
    }
    free(dict);
}

static char * concatenaDef (char * defActual, const char * newDef, size_t * len){
    int j = 0;
    for (int i = 0; newDef[i] != '\0'; i++){
        if (j % BLOCK == 0){
            defActual = realloc (defActual, j + BLOCK + 1);
        }
        defActual[j++] = newDef[i];
    }
    defActual[j] = '\0';
    *len = j;
    return defActual;
}

static palabra * addRec 
(palabra * first, const char * word, const char * deff, int *flag){
    int c;
    if (first == NULL || (c = (strcmp(word, first->nombre))) < 0) {
        palabra * aux = malloc(sizeof(palabra));
        aux->nombre_len = strlen(word);
        aux->nombre = malloc (aux->nombre_len + 1);
        aux->next=first;
        strcpy(aux->nombre, word);
        aux->def_len = 0;
        aux->definicion = concatenaDef(NULL, deff, &(aux->def_len));
        *flag = 1;
        return aux;
    }
    if (c == 0){            // sacar la suma del first->def_len
        first->definicion = concatenaDef(first->definicion, deff, &first->def_len);
    } else {
        first->next = addRec (first->next, word, deff, flag);
    }
    return first;
}

void addDefinition (dictADT dict, const char* word, const char* deff){
    int idx = tolower(word[0]) - 'a';
    int flag = 0;
    dict->letras[idx].first = addRec(dict->letras[idx].first, word, deff, &flag);
    dict->cant += flag;
}

char * getDeff (const dictADT dict, const char* word){
    //busco la pirmera letra de word y entro a esa lista 
    int c = tolower(*word) - 'a';

    palabra *aux = dict->letras[c].first;

    while (aux != NULL){
        int x = strcmp(word, aux->nombre);
        if (x == 0) return aux->definicion;
        if (x < 0) return NULL; //nos pasamos y no encontramos
        aux = aux->next;
    }
    return NULL;
}

char ** wordsBeginWith (const dictADT dict, char letter, size_t * dim){
    int c = tolower(letter) - 'a';
    wordList * wl = &dict->letras[c];
    if (wl->dim == 0) {
        *dim = 0;
        return NULL; // no hay palabras que empiezan con esa letra
    }

    char ** ans = malloc ((wl->dim + 1) * sizeof(*ans));

    palabra * aux = wl->first;
    int i=0;
    while (aux != NULL) {
        ans[i] = malloc((aux->nombre_len + 1) * sizeof(char));
        strcpy(ans[i], aux->nombre);
        aux = aux->next;
        i++;
    }
    *dim = i;
    return ans;
}

static void copyWords (palabra * first, char ** ans, size_t *i){
    palabra * aux = first;
    while (aux != NULL){
        ans[*i] = malloc (aux->nombre_len + 1);
        strcpy(ans[*i], aux->nombre);
        aux = aux->next;
        (*i)++;
    }
}

char ** words (const dictADT dict, size_t * dim){
    if (dict->cant == 0){
        *dim = 0;
        return NULL;
    }
    char ** ans = malloc(dict->cant * sizeof(*ans));

    int k = 0;
    for (int i = 0; i < LETTERS; i++){
        copyWords(dict->letras[i].first, ans, dim); 
    }
    return ans;
}