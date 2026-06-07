#include <stdio.h>
#include <string.h>

char * strrchrRec (const char * s, int n){
    // voy hasta el final 
    if (*s == '\0') return NULL;
    
    char * aux = strrchrRec(s+1, n);

    if (aux != NULL) {
        return aux;
    }
    if (*s == n) return (char*)s;
    return NULL;
} 