#include <stdio.h>
#include <ctype.h>
#include "../getnum.h"

int main(){
    int n = getint("Ingrese un numero entero: ");
    int count = 0;
    int copia = n;
    while (n){
        n &= (n - 1);       // Apago el 1 menos significativo
        count++;
    }
    printf("La cantidad de 1 de %d es: %d\n", copia, count);

}

// supongamos 13  = n = 1101
//              n - 1 = 1100
//          n & (n-1) = 1100        esto es lo que se hace en el while 