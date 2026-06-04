#ifndef VECTORADT_H
#define VECTORADT_H
#include <stdlib.h>

typedef struct vectorCDT * vectorADT;

// caso concreto, vector de enteros
typedef int elemType;

// construye un TAD de un vector
vectorADT newVector(void);

// Retorna la cantidad de elementos presentes en un vector
int elemCount(const vectorADT v);

//

#endif