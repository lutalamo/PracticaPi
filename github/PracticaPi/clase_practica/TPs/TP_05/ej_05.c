#include <stdio.h>
#include "../getnum.h"

double potencia(double base, int exp){
        double res = 1.0;
        while (exp > 0){
            if ( exp & 1 ){     // si el ultimo bit es uno, lo uso
                res *= base;
            }
            base *= base;       // actualizo la base la use o no
            exp >>= 1;          // corro a nivel de bit el exp. exp = exp/2
        }
        return res;
}
    // ejemplo 2 ^ 13 = 2 ^ (1101) opero el exponente a nivel de bits
    
                    
int main(){
    double b = getint("ingrese base: ");
    int e = getint("Ingrese exponente: ");

    double poten = potencia(b, e);
    printf("%g\n", poten);
}