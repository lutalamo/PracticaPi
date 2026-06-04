#ifndef LISTADT_H
#define LISTADT_H

typedef int* elemType;

typedef struct listCDT * listADT;

typedef int (* cmpFun)(elemType, elemType);

//crea un listADr
listADT newList(cmpFun cmp);

// retorna la cantidad de elementos de la lista
int sizeList (const listADT l);

// agrega un elem a la lista, devuelv1 si lo agrega, 0 si no
int addList (listADT l, elemType e);

//devuelve un elemento de la lista
elemType getList (const listADT l, unsigned idx);

//saca un elemento de la lista
int removeList (listADT l, elemType e);

//dice que si un elemento esta en la lista
int belongsList (const listADT l, elemType e);

#endif