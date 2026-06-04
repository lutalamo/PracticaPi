// Dado un arreglo lineal de números reales, cuyo indicador de fin de elementos es cero, 
//escribir una función para obtener la mayor diferencia entre dos elementos consecutivos. (En no más de 5 líneas). 
// Tener en cuenta que los números pueden ser negativos. En caso de que el vector tenga un solo elemento deberá retornar como diferencia el valor cero.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int mayorDif(const int vec[]){
    int max = 0; 
    for (int i = 0; vec[i+1] != 0; i++){
        int dif = abs(vec[i] - vec[i+1]);
        if (dif > max) max = dif;
    }
    return max;
}
int main(){
    int a[5] = {2, -6, 8, 2, 0};
    printf("Mayor diferencia es: %d\n", mayorDif(a));
}