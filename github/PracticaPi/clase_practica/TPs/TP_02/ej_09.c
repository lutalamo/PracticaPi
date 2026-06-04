#include <stdio.h>
#include "../getnum.h"

signed int x;
int a;

int main(void){
    x = getint("Ingrese un numero:\n");

    if (x != 0){
    a = x >> 1;
    printf("Su numero dividido 2 es %d\n", a);
    }
    return 0;
}