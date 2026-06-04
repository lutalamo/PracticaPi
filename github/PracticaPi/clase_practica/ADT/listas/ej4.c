#include <stdio.h>

typedef struct node {
    int elem;
    struct node * tail;
} TNode;

typedef TNode *TList;

TList addAll(TList lista1,  TList lista2) {
  if (lista2 == NULL)                             // Nada para agregar
     return lista1;
  if (lista1 == NULL || lista1->elem > lista2->elem) {
    TList aux = malloc(sizeof(TNode));
    aux->elem = lista2->elem;
    aux->tail = addAll(lista1, lista2->tail);
    return aux;
  }
  if (lista1->elem < lista2->elem)
     lista1->tail = addAll(lista1->tail, lista2);
  else
     lista1->tail = addAll(lista1->tail, lista2->tail);
  return lista1;
}