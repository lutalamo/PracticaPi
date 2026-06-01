#include <stdio.h>
#include "../getnum.h"

float x;
float a;
int
main(void){
    x = getfloat("Elige el numero que quieras convertir\n");
    a = x * 3.6;
    printf("El numero %.2fm/s es %.2fKm/h\n", x, a);
}