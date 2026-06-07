#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BLOCK 10

typedef enum {DER=0, IZQ, ABA, ARR, I_AR, I_AB, D_AR, D_AB} Tdireccion;

 struct posicion {
	char * palabra;
	size_t fila;
	size_t columna;
	Tdireccion direccion;
};

int busquedaDireccion (int fils, int cols, const char * palabra, char sopa[][cols], size_t f, size_t c, int inc_f, int inc_c){
    int idx = 0;
    int i = f;
    int j = c;

    while (palabra[idx] != 0 && i >= 0 && i < fils && j >= 0 && j < cols && palabra[idx] == sopa[i][j]){
        i += inc_f;
        j += inc_c;
        idx++;
    }
    return palabra[idx] == 0;
}

struct posicion * buscarPalabra(unsigned int filas, unsigned int cols, const char *palabra, char sopa[][cols], size_t f, size_t c, struct posicion * res, size_t *idx) {
    static int vec_mov[][2]= { {0,1}, {0, -1}, {1,0}, {-1,0}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1} };
    for (int i=DER; i <= D_AB; i++) {
        if (busquedaDireccion(filas, cols, palabra, sopa, f, c, vec_mov[i][0], vec_mov[i][1])) {
            if ( *idx % BLOCK == 0)
                res = realloc( res, (*idx + BLOCK) * sizeof(*res));
            struct posicion aux = {palabra, f, c, i};
            res[*idx] = aux;
            (*idx)++;
        }
    }
    return res;

}

struct posicion * buscaLetra(unsigned int filas, unsigned int cols,  char sopa[][cols], const char *palabra, struct posicion * res, size_t *idx) {
    for (size_t i=0; i < filas; i++) {
        for (size_t j=0; j < cols; j++) {
            if ( sopa[i][j] == palabra[0]) {
                res = buscarPalabra(filas, cols, palabra, sopa, i, j, res, idx);
            }
        }
    }
    return res;
}

struct posicion * resolverSopa(unsigned int filas, unsigned int cols, char *diccionario[], char sopa[][cols]) {
    struct posicion * resp = NULL;
    size_t idx=0;

    for(int i=0; diccionario[i][0] != 0; i++) {
        resp = buscaLetra(filas, cols, sopa, diccionario[i], resp, &idx);
    }

    resp = realloc(resp, (idx + 1) * sizeof(struct posicion));

    resp[idx] = (struct posicion) {NULL,0,0,0};

    return resp;
}