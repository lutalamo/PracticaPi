#include <stdio.h>
#include "../random.h"
#include "../getnum.h"

int main(){
    int a = getint("Ingrese valor 1: ");
    int b = getint("Ingrese valor 2: ");
    if (a < b){
        int c = randInt(a, b);
        printf("%d\n", c);
    }
    else {
    int c = randInt(b, a);
    printf("%d\n", c);
    }

}