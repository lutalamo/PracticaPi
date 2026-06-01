#include <stdio.h>
#include "../getnum.h"

int main(void){

    int x = getint("Ingrese los segundos\n");
    int segundos;
    int minutos;
    int horas;

    horas = x / 3600;
    minutos = (x % 3600) / 60;
    segundos = x % 60;

    printf("Los segundos ingresados son equivalentes a %d:%d:%d\n", horas, minutos, segundos);

}