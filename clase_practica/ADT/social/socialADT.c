#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "./socialADT.h"

struct related {
    char * rel;
    struct related * next;
};

struct person {
    char * nombre;
    struct related * firstRel;
};

struct socialCDT {
    struct person * personas;
    size_t dim; // capacidad total del vector
    size_t count; // cantidad de personas actual
};