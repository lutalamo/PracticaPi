#include <stdio.h>
#include "./list.h"
#include <stdlib.h>
#include <ctype.h>

int size (List l){
    if (l == NULL) return 0;

    return 1 + size(l->tail);
}

List del (List l, int elem){
    if (l == NULL || l->head > elem){
        return l;
    }
    if (l->head == elem){
        List aux = l->tail;
        free(l);
        return aux;
    }
    l->tail = del(l->tail, elem);
    return l;
}

void freeList(List l){
    if (l == NULL){
        return;
    }
    freeList(l->tail);
    free(l);
}

int get (List l, size_t idx){
    // ERROR
    if (l == NULL){
        exit(1);
    }
    // Caso Base
    if (idx == 0) return l->head;
    // Recursion
    return get(l->tail, idx - 1);
}

// head y tail sirven para iterar sobre las listas de forma eficiente
int head (List l){
    if (l == NULL) exit(1);
    return l->head;
}

List tail (List l){
    if (l == NULL) exit (1);
    return l->tail;
}

int * toArray(List l){
    int dim = size(l);
    int *v = malloc(dim * sizeof(*v));

    for (int i = 0; i < dim; i++){
        v[i] = l->head;
        l = l->tail;
    }
    return v;
}

int countIf (const List l, int (*f)(int)){
    if (l == NULL) return 0;
    
    /* asumiendo que f retorna 1 para casos verdaderos
    return f(l->head) + countIf(l->tail, f);
    */

    if (f(l->head)){
        return 1 + countIf(l->tail, f);
    }
    return countIf(l->tail, f);
}

int reduce (List l, int (*f)(int, int), int base){
    if (l == NULL) return base;

    return f(l->head, reduce(l->tail, f, base));
}

void map (List l, int (*f)(int)){
    if (l == NULL) return;
    l->head = f(l->head);
    return map(l->tail, f);
}

List strToListUpper (const char *s){
    if (*s == '\0') {
        return NULL;
    }
    List l;
    if (isupper(*s)) {
        l = malloc(sizeof(*l));
        l->head = *s;
        l->tail = strToListUpper(s + 1);
        return l; 
    }
    return strToListUpper (s + 1);
}

List concatenarLista (List list1, List list2){
    if (list2 == NULL) return list1;
    if (list1 == NULL) {
        List aux = malloc(sizeof(*aux));
        aux->head = list2->head;
        aux->tail = concatenarLista(list1, list2->tail);
        return aux;
    }
    list1->tail = concatenarLista(list1->tail, list2);
    return list1;
}

List add (List l, int elem){
    
}