#include <stdio.h>

int edad = 25;
float longitud = 185.654;
char  letra = 'Z';

int
main(void){
    printf("%-5i\n %10i\n %-10.2f\n %8d\n", edad, edad, longitud, letra);
}

