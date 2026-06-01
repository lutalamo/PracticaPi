#include <stdio.h>
#include <math.h>
#include "getnum.h"

int
main(){
    int num;
    int suma = 0;
        
        while( num = getchar()!= '.' );

        while( (num = getchar()) != '\n') {
            suma += num - '0';
        }
        printf("La suma de los decimales es %d\n", suma);
}
