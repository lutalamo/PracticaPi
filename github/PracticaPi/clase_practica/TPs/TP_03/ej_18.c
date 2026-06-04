#include <stdio.h>
#include "../getnum.h"

int main(){
    int n = getint("Ingrese un numero positivo: ");
    int fact = 1;
    if ( n > 0 ){
    for (int i = 1; i <= n; i++){
        fact = fact * i;
    }
    printf("%d\n", fact);
    }
    else printf("Ingrese un valor postivo que no sea 0.\n");
}