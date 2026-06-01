#include <stdio.h>
#include "../getnum.h"

int
main(void){
    
    int a = getint("Escriba un numero\n");
    int b = getint("Escriba otro numero\n");

    int suma = a + b;
    float promedio = suma / 2.0;

                printf("El promedio es %.2f\n", promedio);
               
                printf("La suma es: %d\n", suma);
    (a < b) ? printf("El menor es %d\n", a) : printf("El menor es %d\n", b);
    (a == b) ? printf("Son iguales\n") : printf("No son iguales\n");
}