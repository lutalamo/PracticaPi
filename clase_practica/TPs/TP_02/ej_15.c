#include <stdio.h>
#include "../getnum.h"
#define MAYUS ('a' - 'A')

int
main(void){
    
    int c;
    while((c = getchar()) != EOF && c != '\n'){
        
        c = (c >= 'a' && c <= 'z') ? (c - MAYUS) : c;
        if(!(c >= 'A' && c <= 'Z')){
            printf("El caracter ingresado no es una minuscula\n");
        }
        else putchar(c);

    }
    
    putchar(c);
    
    return 0;
}   