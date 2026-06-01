#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "../getnum.h"

int main(){
    int c;
    int hasOne = 0;
    unsigned int decimal = 0;
    int count = 0;
    while((c = getchar()) && (c == '0' || c == '1')){
        count++;
        if (count > 32){
            printf("El numero ingresado excede el limite permitido.\n");
            return 1; /* Sale del programa */
        }
        if ( c == '1') hasOne = 1;
        
        decimal = decimal * 2 + (c - '0'); 
        
    }
    if (!(hasOne)){
        printf("El numero ingresado no es un numero binario positivo valido\n");
    }
        printf("%d\n", decimal);

        return 0;
}
