#include <stdio.h>
#include "../getnum.h"

int main(void){
    int lado = getint("Ingrese un numero:\n");
    for (int fila = 1; fila <= lado; fila++){
        for (int col = 1; col <= lado; col++){
            printf("*");
        }
            printf("\n");
    }
}