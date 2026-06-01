#include <stdio.h>
#include <math.h>
#include "../getnum.h"


int SumaDeDivisores(int n){
    int count = 0;

    for(int i=1; i <= n/2; i++){
        if (n % i == 0){
            count += i;
        }
    }
    return count; 
}
int numeroAmigos(int num1, int num2){
    int a = SumaDeDivisores(num1), b = SumaDeDivisores(num2);
    if(a == num2 && b == num1)
    return 1;
    return 0;
}

int main(){
    int x1 = getint("Escriba un numero:\n");
    int x2 = getint("Escriba un numero:\n");
    if(numeroAmigos(x1, x2))
        printf("%d y %d son numeros amigos\n", x1, x2);
    else    
        printf("%d y %d no son amigos\n", x1, x2);
    return 0;
}