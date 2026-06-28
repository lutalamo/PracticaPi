#include <stdio.h>

typedef struct collectionCDT * collectionADT;
typedef char elemType;
/* Crea una nueva colección vacía */
collectionADT newCollection(int (*cmp)(elemType, elemType));
/* Agrega un elemento a la colección, si no estaba. No agrega elementos repetidos */
void addElement(collectionADT collection, elemType elem); /* NO IMPLEMENTAR */
/* Elimina un elemento de la colección, si no está no hace nada */
void removeElement(collectionADT collection, elemType elem); /* NO IMPLEMENTAR */
/* Retorna una nueva colección de elementos no repetidos con los elementos que
* están en cualquiera de las dos colecciones */
collectionADT unionCollection(const collectionADT col1, const collectionADT col2);
/* Retorna una nueva colección de elementos no repetidos con los elementos que
* estén en ambas colecciones */ /* NO IMPLEMENTAR */
collectionADT intersecCollection(const collectionADT col1, const collectionADT col2);
/* Retorna 1 si el elemento está en la colección, 0 si no está */
int belongs(const collectionADT collection, elemType elem); /* NO IMPLEMENTAR */
/* Libera los recursos utilizados por el TAD */
void freeCollection(collectionADT collection); /* NO IMPLEMENTAR */