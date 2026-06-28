#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "./worldADT.h"

struct city{
    char * city;
    double lat;
    double lon;
    struct city * next;
};

struct cityLat{
    struct city * first;
    struct city * iter;
    size_t count;
};

struct worldCDT{
    struct cityLat * ciudades; //181 posibles valores de latitud
    size_t cantidad;
};

worldADT newWorld(){
    worldADT ans = malloc(sizeof(*ans));
    ans->cantidad = 0;
    ans->ciudades = calloc(181, sizeof(struct cityLat));
    return ans;
}

static int validLat (double lat, int *ans){
    if (lat >= -90 && lat <= 90){
        *ans = (int)lat + 90;
        return 1;
    }
    return 0;
}

static struct city * newCity(double trueLat, double trueLon, const char *city){
    struct city *ans = malloc (sizeof(struct city));
    ans->city = malloc((strlen(city)+1) * sizeof(char));
    strcpy(ans->city, city);
    ans->lat = trueLat;
    ans->lon = trueLon;
    ans->next = NULL;

    return ans;
}

static int agrega (struct cityLat * ciudad, double trueLat, double trueLon, const char *city){
    struct city ** p = &ciudad->first;
    while (*p != NULL && strcmp((*p)->city, city) < 0){
        p = &(*p)->next;
    }
    if ((*p) != NULL && strcmp((*p)->city, city) == 0){
        return 0;
    }
    
    struct city * new = newCity(trueLat, trueLon, city);
    new->next = *p;
    *p = new;
    ciudad->count++;
    
    return 1;
}

void addCity(worldADT world, double trueLat, double trueLon, const char *city){
    int idx;
    if (!validLat(trueLat, &idx)) return;
    if (agrega(&world->ciudades[idx], trueLat, trueLon, city)){
        world->cantidad++;
    }
    return;
}

size_t citiesCount(const worldADT world){
    return world->cantidad;
}

size_t citiesCountOnLat(const worldADT world, int lat){
    int idx;
    if(!validLat(lat, &idx)) return 0;
    return world->ciudades[idx].count;
}