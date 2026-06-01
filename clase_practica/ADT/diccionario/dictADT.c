#include <stdio.h>
#include "./dictADT.h"
#include <string.h>
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
    dictADT ans = malloc (sizeof(*ans));
    
    for (int i = 0; i < LETTERS; i++){
        ans->letras[i].first = NULL;
        ans->letras[i].dim = 0;
    }
    ans->cant = 0;
    return ans;
}

void freeWord(palabra word){
    if (word.next == NULL) return;
    palabra aux = word;
    free(word);
    free
    
}

void freeWordList (wordList wordList){
    if (wordList.dim == 0) return;
    
}

void freeDict(dictADT dict){
    
    free(dict);
}

static char * concatenaDef (char * defActual, char * newDef, size_t * len){
    int j = 0;
    for (int i = 0; newDef[i] != '\0'; i++){
        if (j % BLOCK == 0){
            defActual = realloc (defActual, j + BLOCK + 1);
        }
        defActual[j++] = newDef[i];
    }
    defActual[j] = '\0';
    *len = j;
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

