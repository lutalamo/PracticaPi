#include "./libraryADT.h"
#include <stddef.h>
#include <stdlib.h>
#include <sys/select.h>

#define BLOCK 5

struct books{
    char * title;
    size_t stock;
    struct books * next;
};

struct sucursal {
    struct books * first;
    struct books * iter;
    size_t dif_books;
    size_t total;
};

struct libraryCDT{
    struct sucursal * sucursales; // vector con las sucursales
    size_t cant;
    size_t dim;
};

libraryADT newLibrary(){
    libraryADT ans = calloc(0, sizeof(*ans));
    return ans;
}

struct sucursal * agrandaVector (struct sucursal *vec, size_t * dim, size_t idx){
    size_t newDim = *dim;
    while (idx >= newDim){
        newDim += BLOCK; 
    }
    vec = realloc(vec, newDim * sizeof(struct sucursal));

    for (size_t i = *dim; i < newDim; i++){
        vec[i].first = NULL;
        vec[i].iter = NULL;
        vec[i].dif_books = 0;
        vec[i].total = 0;
    }
    *dim = newDim;
    return vec;
}   


size_t addBook(libraryADT lib, size_t branch, const char *title, unsigned int stock){
    if (branch == 0 || branch % 10 != 0) return 0; 
    size_t idx = branch / 10 - 1;
    if (idx >= lib->dim){
        lib->sucursales = agrandaVector(lib->sucursales, &(lib->dim), idx);
    }
}