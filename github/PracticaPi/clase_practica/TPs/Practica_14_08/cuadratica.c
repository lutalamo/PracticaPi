#include <stdio.h>
#include <math.h>
#include "../getnum.h"

int
main(void){
    int numero_a = getint("Ingrese numero a:");
    int numero_b = getint("Ingrese numero b:");
    int numero_c = getint("Ingrese numero c:");

    int determinante = numero_b*numero_b - 4*numero_a*numero_c;

if (determinante >= 0){
    float x1 = (-numero_b + sqrt(determinante))/(2*numero_a);
    float x2 = (-numero_b - sqrt(determinante))/(2*numero_a);
    printf("El resultado de la cuadratica es: %f, %f\n", x1, x2);
}

    else {
        printf("No tiene raices reales\n");

}
return 0;
} 