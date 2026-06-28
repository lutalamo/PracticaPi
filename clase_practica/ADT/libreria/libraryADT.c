#include "./libraryADT.h"
#include <stddef.h>
#include <stdlib.h>
#include <sys/select.h>
#include <string.h>

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

struct books * newBook (const char *title, unsigned int stock){
    struct books * newBook = malloc(sizeof(struct books));
    newBook->title = malloc(strlen(title) + 1);
    strcpy(newBook->title, title);
    newBook->next = NULL;
    newBook->stock = stock;
    return newBook;
}

size_t agregar (struct sucursal * suc, const char *title, unsigned int stock){
    struct books ** p = &suc->first;
    while (*p != NULL && strcmp((*p)->title, title) < 0){
        p = &(*p)->next;
    }
    if ((*p) != NULL && strcmp((*p)->title, title) == 0) {
        (*p)->stock += stock;
        suc->total += stock;
        return (*p)->stock;
    }
    else {
        struct books * aux = newBook(title, stock);
        aux->next = *p;
        *p = aux;
        suc->dif_books++;
        suc->total += stock;
        return aux->stock;
    }
}

//devuelve 1 si es valida, 0 si no
static int sucursalValida (const libraryADT lib, size_t branch, size_t *idx){
    if (branch == 0 || branch % 10 != 0) return 0; 
     *idx = branch / 10 - 1;
    return (*idx < lib->dim && lib->sucursales[*idx].first != NULL );
}

size_t addBook(libraryADT lib, size_t branch, const char *title, unsigned int stock){
    if (branch == 0 || branch % 10 != 0) return 0; 
    size_t idx = branch / 10 - 1;
    if (idx >= lib->dim){
        lib->sucursales = agrandaVector(lib->sucursales, &(lib->dim), idx);
    }
    return agregar(&lib->sucursales[idx], title, stock);    
}

size_t books(const libraryADT lib, size_t branch){
    size_t idx;
    if (!sucursalValida(lib, branch, &idx)) return 0;
    return lib->sucursales[idx].dif_books;
}

size_t stock(const libraryADT lib, size_t branch){
    size_t idx;
    if (!sucursalValida(lib, branch, &idx)) return 0;
    return lib->sucursales[idx].total;
}

void toBeginByBranch(libraryADT lib, size_t branch){
    size_t idx;
    if (!sucursalValida(lib, branch, &idx)) return;
    lib->sucursales[idx].iter = lib->sucursales[idx].first;
}