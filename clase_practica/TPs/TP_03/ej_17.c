/* Escriba y ejecute un programa que imprima todos los múltiplos de 10 (10, 20, 30, 40, etc.)  
en no más de 5 líneas ¿Qué sucede cuando ejecuta este programa ?*/

#include <stdio.h>

int main(){
    for (long long int k = 1; k <= 1000000000000; k++){                  /* Bucle finito */
        printf("%lld\n", 10*k);
    }
}