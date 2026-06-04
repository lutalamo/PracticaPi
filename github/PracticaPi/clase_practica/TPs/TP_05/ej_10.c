#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "../getnum.h"

int mcd(int a, int b){
    int r;
    while (b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    int a = getint("Ingrese un numero: ");
    int b = getint("ingrese un numero: ");

    printf("%d\n", mcd(a, b));
}
