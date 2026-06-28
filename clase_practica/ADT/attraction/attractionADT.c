#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./attractionADT.h"

struct visitor{
    char * nombre;
    struct visitor * next;
};

struct cola{
    struct visitor * first;
    struct visitor * last;
    size_t esperando;
    size_t entraron;
};

struct attractionCDT{
    struct cola hour[24];
};

attractionADT newAttraction(){
    attractionADT ans = calloc (1, sizeof(*ans));
    return ans;
}

static int validHour(size_t hour){
    if (hour < 24) return 1;
    return 0;
}

char * rideVisitor(attractionADT att, size_t hour){
    if(!validHour(hour)) return NULL;
    if (att->hour[hour].esperando == 0) return NULL;

    struct visitor * primero = att->hour[hour].first;

    int dim = strlen(primero->nombre);
    char *ans = malloc(dim+1);
    strcpy(ans, primero->nombre);
    
    att->hour[hour].first = primero->next;
    if (att->hour[hour].first == NULL){
        att->hour[hour].last = NULL;
    }

    free(primero->nombre);
    free(primero);

    att->hour[hour].esperando--;
    att->hour[hour].entraron++;
    
    return ans;
}

char ** pendingVisitors(const attractionADT att, size_t hour, size_t * dim){
    if (!validHour(hour)) return NULL;
    if (att->hour[hour].esperando == 0) return NULL;

    *dim = att->hour[hour].esperando;
    char ** ans = malloc(*dim * sizeof(char *));

    struct visitor * curr = att->hour[hour].first;

    for (size_t i = 0; i < *dim; i++){
        ans[i] = malloc(strlen(curr->nombre) + 1);
        strcpy(ans[i], curr->nombre);
        curr = curr->next;
    }
    return ans;
}