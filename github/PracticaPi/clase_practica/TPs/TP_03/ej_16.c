/* Dado un número entero positivo, imprimir por salida estándar  el equivalente en base binaria. 
El rango de números a considerar puede estar acotado. */

#include <stdio.h>
#include <ctype.h>
#include "../getnum.h"

void print_bin(unsigned int n){
    if (n >= 2) print_bin(n >> 1);  /* divido por 2 a nivel de bits */
    putchar((n & 1)? '1' : '0');    /* comparo a n con 1 para agarrar el bit menos significativo 
                                        es como hacer un n%2 pero a nivel de bits */
}

int main(){
    int c;
    c = getint("Ingrese un numero: ");
    if ( c == 0 ){
        putchar('0');  
    }
    else {
        print_bin(c);
    }
        putchar('\n');
    
    return 0;
}