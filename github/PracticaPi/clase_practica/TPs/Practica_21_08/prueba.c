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
int main(void){
    int n = getint("Ingrese un numero\n");
    printf("%d\n", SumaDeDivisores(n));
}