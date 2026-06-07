#include <stdio.h>

int sumMatch (int * v){
    if (*v < 0) return 0;

    int aux = sumMatch(v+1);

    if (aux == 0) return v[0];
    if (aux < 0) return aux;
    return aux - v[0];
}