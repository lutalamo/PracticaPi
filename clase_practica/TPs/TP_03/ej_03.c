#include <stdio.h>
#include "../getnum.h"

double calcularSalario (double ventas){
    
    double salario = 300.0;

    if (ventas <= 1000){
        return salario;
    }
    else if (ventas <= 2000){
        return salario + ventas*0.05; //aplico porcentaje
    }
    else if (ventas <= 4000){
        return salario + ventas*0.07;
    }
    else return salario + ventas*0.09; //ventas mas de 4000
}

int main(){
    
    double ventas;
    do{
        ventas = getdouble("Ingrese el total vendido: ");
    } while (ventas < 0);

    printf("El salario total es: $%.2f\n", calcularSalario(ventas));

    return 0;
}