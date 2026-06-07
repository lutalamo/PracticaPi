#include <ctype.h>


int bienFormado (char * s){
    if (*s == '\0') return 0;
    int aux = bienFormado(s+1);
    
    if (aux == 0) {
        if(isdigit(*s)) return *s - '0';
    }
    if (aux > 0){    
        if (isalpha(*s)) return aux - 1;
    }
    return -1;
}