#include <stdio.h>
#include <math.h>
#include "../getnum.h"

int esPrimo (int);

int
main(){
    int x = getint("Escriba un numero:\n");
    printf("%d\n", esPrimo(x));
    return 0;
}

int esPrimo (int x) {
    int r = sqrt(x);
    int esprimo = 0;

    for (int d=2; d < r && !esprimo; d++){
        esprimo=((r % d == 0)? 1 : 0);
    }
    return esprimo;
}
