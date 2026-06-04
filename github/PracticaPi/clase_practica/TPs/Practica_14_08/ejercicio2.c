
#include <stdio.h>
#include <math.h>
#include "getnum.h"

int
main(void){
   int a = getint("Ingrese numero:\n");
   int modulo = a > 0 ? a : -a;

   int suma = 0;
   
   while (modulo != 0){
        suma += a % 10;
        a = a / 10;
   }
        printf("La suma de los digitos es %d\n", suma);

        return 0;

}