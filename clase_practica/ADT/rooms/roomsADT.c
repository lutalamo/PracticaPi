#include "./roomsADT.h"
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

struct asistente {
    char * nombre;
    struct asistente * next;
};

struct salas{
    struct asistente * first;
    struct asistente * iter;
    struct asistente * last;
    size_t esperando;
    size_t entraron;
};

struct roomsCDT{
    struct salas * sala;
    size_t dim; // max de salas
};

roomsADT newRooms(size_t maxRooms){
    if (maxRooms == 0) return NULL;

    roomsADT ans = malloc(sizeof(*ans));
    ans->sala = calloc(maxRooms, sizeof(struct salas));
    ans->dim = maxRooms;

    return ans;
}

static int reserva (struct salas * sala, const char * attendee){
    struct asistente * new = malloc(sizeof(struct asistente));
    new->nombre = malloc(strlen(attendee)+1);
    new->next = NULL;

    struct asistente **p = &sala->first;
    
    if (sala->first == NULL){

    }
}

void reserveRoom(roomsADT rooms, size_t roomNumber, const char *attendee){
    if (roomNumber == 0 || roomNumber >= rooms->dim) return;

    int idx = roomNumber - 1;

    
}