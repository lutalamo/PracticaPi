#include <stdio.h>
#include "../getnum.h"


int
main(void){
    

    int a = getint("Escribir el primer numero\n");
    
    int b = getint("Escribir el segundo numero\n");

            /* Con el while, podria hacer que lea solo numeros */
   
    int multiplicidad;
    if(a != 0){
        multiplicidad = b % a;
        (multiplicidad == 0) ? printf("El numero %d es multiplo de %d\n", b, a) : printf("%d no es multiplo de %d\n", b, a);
    }
    else {printf("No se puede dividir por 0\n");}
    
}
