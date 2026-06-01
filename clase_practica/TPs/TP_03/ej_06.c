#include <stdio.h>

int 
main(void){
    enum Dia { LUN=0, MAR, MIE, JUE, VIE, SAB, DOM };

    enum Dia dia = LUN ; 

    printf("Hoy es ");
    switch (dia) {
        case LUN: puts("Lunes"); break;
        case MAR: puts("Martes"); break;
        case MIE: puts("Miercoles"); break;
        case JUE: puts("Jueves"); break;
        case VIE: puts("Viernes"); break;
        case SAB: puts("Sabado"); break;
        case DOM: puts("Domingo"); break;
    }
    return 0;
}