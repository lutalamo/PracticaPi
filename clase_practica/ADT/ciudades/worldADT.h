#include <stdio.h>

typedef struct worldCDT * worldADT;
/* Inicializa un catálogo de ciudades */
worldADT newWorld(void);
/* Agrega una ciudad al catálogo, indicando la latitud real, la longitud real y su nombre
* Los valores posibles de latitud son [-90.0, 90.0], de recibir un valor por fuera del
* rango no hace nada.
* Se asegura que los nombres de las ciudades son reales, son nombres cortos
* Si una ciudad con ese nombre ya existe para el valor entero de la latitud, no hace nada
*/
void addCity(worldADT world, double trueLat, double trueLon, const char * city);
/* Retorna la cantidad de ciudades agregadas al catálogo */
size_t citiesCount(const worldADT world); /* NO IMPLEMENTAR */
/* Retorna la cantidad de ciudades ubicadas en el valor entero de una latitud
* (Por ejemplo si lat es 45 incluye las ciudades con latitudes reales en [45.0, 46.0))
* Si no hay ciudades para el valor entero de la latitud, retorna 0
*/
size_t citiesCountOnLat(const worldADT world, int lat);
typedef struct cityLatLon {
char * city;
double lat, lon;
} tCityLatLon;
/* Retorna un arreglo con todas las ciudades ubicadas en el valor entero de una latitud
* en orden alfabético por nombre y deja en #dim la cantidad de elementos
* (Por ejemplo si lat es 45 incluye las ciudades con latitudes reales en [45.0, 46.0))
*/
tCityLatLon * citiesOnLat(const worldADT world, int lat, size_t * dim); /* NO IMPLEMENTAR */
/* Funciones de iteración para poder consultar todas las ciudades ubicadas
* en el valor entero de una latitud en orden alfabético por nombre
* IMPORTANTE: Permitir utilizar estas funciones para distintas latitudes EN SIMULTANEO
* (ver ejemplo en programa de prueba)
* Aborta si cualquiera de las funciones es invocada con un #lat fuera del rango
* [-90.0, 90.0]
*/
void toBeginLat(worldADT world, int lat); /* NO IMPLEMENTAR */
int hasNextLat(const worldADT world, int lat); /* NO IMPLEMENTAR */
tCityLatLon nextLat(worldADT world, int lat); /* NO IMPLEMENTAR */
/* Libera todos los recursos utilizados por el TAD */
void freeWorld(worldADT world); /* NO IMPLEMENTAR */