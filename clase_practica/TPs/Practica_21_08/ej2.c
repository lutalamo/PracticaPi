#include <stdio.h>
#include <math.h>

int esPrimo (unsigned int num){
    if (num <= 1) return 0; // negativos, 0 o 1 
    if (num == 2) return 1; // 2 es primo
    if (num % 2 == 0) return 0; // los pares mayores a 2 
    
    for (int i = 3; i * i <= num; i += 2){ 

        if (num % i == 0) return 0;
    }
        return 1; // si sale del for es porque no encontro un divisor
}

void cantPrimos(int n){
    for(int count=0, i=0; count<n; i++){
        if(esPrimo(i)){
            count++;
            printf("%d\n", i);
        }
    }
}

int  main(){


}