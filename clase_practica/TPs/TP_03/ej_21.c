#include <stdio.h>
#include "../getnum.h"

int main(){
    int original, invertido = 0, resto;
    int n = getint("Ingrese un numero entero: ");
    original = n;
    
    while (n != 0){
        resto = n % 10; // Ultimo digito
        invertido = invertido * 10 + resto;
        n /= 10;        // Elimino el utltimo digito
    }
    
    if (original == invertido){
        printf("El numero es capicua.\n");
    }
    else printf("No es capicua.\n");
    return 0;
}