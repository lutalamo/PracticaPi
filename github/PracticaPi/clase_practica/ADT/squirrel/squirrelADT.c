#include <stdio.h>
#include "./squirrelADT.h"

struct rows {
    size_t dimCols;
    
    size_t * count; //vector, cuantas ardillas hay
};

struct squirrelCensusCDT {
    size_t blockSize;
    struct rows * row;
    size_t dimRows;
};

static size_t indice (size_t dist, size_t size){
    return dist/size;
}

squirrelCensusADT newSquirrelCensus (size_t size){
    if (size == 0) return NULL;

    squirrelCensusADT newCensus = malloc(sizeof(*newCensus));
    newCensus->blockSize = size;
    newCensus->dimRows = 0;
    newCensus->row = NULL;

    return newCensus;
}

size_t countSquirrel (squirrelCensusADT ardilla, size_t yDist, size_t xDist){
    size_t yIdx = indice(yDist, ardilla->blockSize);
    size_t xIdx = indice(xDist, ardilla->blockSize);
    if (yIdx >= ardilla->dimRows){
        ardilla->row = realloc (ardilla->row, (yIdx + 1) * sizeof(*(ardilla->row)));
        for (int i = ardilla->dimRows; i <= yIdx; i++){
            ardilla->row[i].count = NULL;
            ardilla->row[i].dimCols = 0;
        }
        ardilla->dimRows = yIdx + 1; //actualizo la nueva dim
    }
    if (xIdx >= ardilla->row[yIdx].dimCols){
        ardilla->row[yIdx].count = realloc (ardilla->row[yIdx].count, (xIdx + 1) * sizeof(size_t));
        for (int i = ardilla->row[yIdx].dimCols; i <= xIdx; i++){
            ardilla->row[yIdx].count[i] = 0;
        }
        ardilla->row[yIdx].dimCols = xIdx + 1;
    }
    return ardilla->row[yIdx].count[xIdx] + 1;
}

size_t squirrelsInBlock (const squirrelCensusADT ardilla, size_t yDist, size_t xDist){
    size_t yIdx = indice(yDist, ardilla->blockSize);
    size_t xIdx = indice(xDist, ardilla->blockSize);

    if (yIdx >= ardilla->dimRows || xIdx >= ardilla->row[yIdx].dimCols) return 0;

    return ardilla->row[yIdx].count[xIdx];
}

void freeSquirrelCensus (squirrelCensusADT ardilla){
    for (int i = 0; i < ardilla->dimRows; i++){
        free(ardilla->row[i].count);
    }
    free(ardilla->row);
    free(ardilla);
}